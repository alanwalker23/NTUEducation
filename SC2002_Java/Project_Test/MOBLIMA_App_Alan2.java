package MOBLIMA;

import java.nio.file.*;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.*;
import java.nio.file.*;
import java.io.*;

public class MOBLIMA_App {
	public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
		// read the file and create an array of movie objects
		Calender cal = new Calender();
		int choice = 1; // Menu option
		Date[] showtimes = { cal.setHHMM("14:00"), cal.setHHMM("17:00") };
		MovieList ML = new MovieList();
		Movie[] movies = ML.getMovies();
		Menu menu = new Menu();
		Cinema hall1 = new Cinema(0, showtimes);
		Cinema hall2 = new Cinema(1, showtimes);
		Cinema hall3 = new Cinema(2, showtimes);
		Cinema[] jurong_halls = { hall1, hall2, hall3 };
		Cineplex jurong_cineplex = new Cineplex("Jurong Cineplex", jurong_halls, "JP");
		Cinema hall4 = new Cinema(0, showtimes);
		Cinema hall5 = new Cinema(1, showtimes);
		Cinema hall6 = new Cinema(2, showtimes);
		Cinema[] woodlands_halls = { hall4, hall5, hall6 };
		Cineplex woodlands_cineplex = new Cineplex("Woodlands Cineplex", woodlands_halls, "WL");
		Cineplex[] allBranches = { jurong_cineplex, woodlands_cineplex };
		hall1.assignMovie(movies[5]);
		// hall1.addShowtimes("14:00");
		loadCineplexMovies(allBranches);

		outer: while (choice != 0) { // when choice = 0, will end the program
			menu.Homepage();
			System.out.print("Please enter choice: ");
			Scanner sc = new Scanner(System.in);

			boolean done = false;
			while (!done)
				try {
					choice = Integer.parseInt(sc.nextLine());
					done = true;
				} catch (NumberFormatException | InputMismatchException b) {
					System.out.println("Invalid Input! Please input a valid option! ");
					menu.Homepage();
				}
			int moviechoice = 0; // movie choice, indexed to the movies in array
			switch (choice) {
				case (1): // list Movie
					ML = new MovieList();
					ML.displayAll();
					System.out.println("Please select movie no. to view in detail or 0 to back");
					moviechoice = sc.nextInt() - 1;

					if (moviechoice < 0) // option
						break;
					else if (moviechoice > ML.getLength()) {
						System.out.println("Invalid option");
						break;
					} else
						ML.displayOne(movies[moviechoice].getMovieTitle());
					break;
				case (2): // Search Movie
					System.out.println("Enter movie name: ");
					String movieChoices = sc.next();
					System.out.printf("%s \n", searchMovie(movieChoices, allBranches));
					break;
				case (3): // buy movie option
					System.out.println("Please select a choice a movie to watch");
					ML.displayAllLessNotShowing();
					int choice3 = sc.nextInt() - 1; // index of movie
					String movieChoice = ML.getMovieName(choice3);// get movietitle of selectedmovie
					int movieIndex = 0; // variable to get the index of the movie
					for (int i = 0; i < ML.getLength(); i++) { // help to get the index of the movie
						if (movies[i].getMovieTitle().equals(movieChoice))
							movieIndex = i;
					}
					int choices = 1;

					while (choices != 0) {
						menu.BuyMenu();
						choices = sc.nextInt();
						String location = searchMovie(movieChoice, allBranches);
						Cinema hall = getHall(movieChoice, allBranches);
						if (choices == 1) // display movie details
						{
							ML.displayOne(movieChoice);
						} else if (choices == 2) // check seat availability
						{
							System.out.println("Showtimes: ");
							hall.displayShowtimes();
							System.out.println("Please select showtime: ");
							for (int i = 0; i < allBranches.length; i++) {
								if (allBranches[i].getLocation() == location)
									if (hall.getMovie() == movies[movieIndex])
										hall.showSeats();
							}
						} else if (choices == 3) { // buy tickets
							int i = 0;
							// hall.displayShowtimes();

							String[] seatids = bookSeat(hall);
							for (int a = 0; a < seatids.length; a++)
								System.out.printf("%s,", seatids[a]);
							System.out.println("Please enter email: ");
							sc.nextLine();
							String email = sc.nextLine();
							System.out.println("Please enter phone number: ");
							int PhoneNumber = sc.nextInt();
							System.out.println("How many students? ");
							int noOfStudent = sc.nextInt();
							System.out.println("How many senior citizens? ");
							int noOfSeniors = sc.nextInt();
							Movie_Goer bob = new Movie_Goer(PhoneNumber, email);
							for (i = 0; i < allBranches.length; i++) {
								if (allBranches[i].getLocation() == location)
									break;
							}
							String date = "2022-11-11";
							// Calender cal2 = new Calender();
							// cal2.setDate(date);
							// System.out.printf("%s",cal2.checkPH(date));
							int noOfStandard = seatids.length - noOfStudent - noOfSeniors;
							TransactionBooking tb = new TransactionBooking(movies[movieIndex], hall, allBranches[i],
									seatids, seatids.length, noOfStandard, noOfStudent, noOfSeniors, bob, date);
							// tb.storeTransaction();
							tb.createTickets();
							tb.printReceipt();
						}
					}
					break;
				case (4): // list top 5
					ML.rankbyAR();
					ML.rankbyTS();
					break;

				case (5): // view booking history
					TransactionStore TS = new TransactionStore();
					System.out.println("Please enter phone number: ");
					int personMobileNumber = sc.nextInt();
					TS.displayTransactions(personMobileNumber);
					break;
				case (6):
					System.out.print("Enter password: ");
					String password = sc.nextLine();
					if (password.equals("Admin123")) {
						adminOptions(allBranches);
					} else
						System.out.println("Invalid password.");
					break;
				case (0):
					break outer;
				default:
					System.out.println("Invalid input!");
					break;
			}
		}
	}

	public static void loadCineplexMovies(Cineplex[] cineplexes) {
		for (int i = 0; i < cineplexes.length; i++) {
			Movie[] cineplexMovies = cineplexes[i].getMovies();
		}
	}

	public static void displayAllMovies(Movie[] movielist) {
		if (movielist[0] != null) {
			for (int i = 0; i < movielist.length; i++) {
				System.out.printf("%s\n", movielist[i].movieTitle);
			}
		} else
			System.out.println("No movies added to system yet.");
	}

	public static String searchMovie(String input, Cineplex[] cineplexes) {
		if (cineplexes[0] != null) {
			for (int i = 0; i < cineplexes.length; i++) {
				Movie[] cineplexMovies = new Movie[cineplexes[i].getMovies().length];
				cineplexMovies = cineplexes[i].getMovies();
				for (int j = 0; j < cineplexMovies.length; j++) {
					if (cineplexMovies[j] != null) {
						if (cineplexMovies[j].getMovieTitle().equalsIgnoreCase(input)) {
							// System.out.println("Found at " + cineplexes[j].getLocation());
							return cineplexes[j].getLocation();
						}
					}
				}
			}
			return "No such movie in database.";
		} else
			return "No cineplex in database yet.";
	}

	public static Cinema getHall(String input, Cineplex[] cineplexes) {
		if (cineplexes[0] != null) {
			for (int i = 0; i < cineplexes.length; i++) {
				Movie[] cineplexMovies = new Movie[cineplexes[i].getMovies().length];
				cineplexMovies = cineplexes[i].getMovies();
				for (int j = 0; j < cineplexMovies.length; j++) {
					if (cineplexMovies[j] != null) {
						if (cineplexMovies[j].getMovieTitle().equalsIgnoreCase(input)) {
							System.out.println("Found at " + cineplexes[i].getLocation());
							return cineplexes[i].getHalls()[j];
						}
					}
				}
			}
			System.out.println("No such movie in database.");
		} else
			System.out.println("No cineplex in database yet.");
		return null;
	}

	public static String[] bookSeat(Cinema cine) {
		int z = 0, i = 0;
		// int[] seatids = new int[cine.EmptySeats()];
		int counter = 0;
		Scanner obj = new Scanner(System.in);
		Cinema_Seat[] chosenSeats = new Cinema_Seat[cine.EmptySeats()];
		String[] seatNames = new String[cine.EmptySeats()];
		System.out.println("Booking of seats, enter '-' to end");
		while (true) {
			System.out.print("Enter seat number: ");
			String input = obj.nextLine();

			// System.out.println("input is: " + input);
			if (input.charAt(0) == '-') {
				break;
			} else {
				Cinema_Seat seat = cine.findSeats(input);
				// seatids[counter] = seat.getSeatID();
				counter++;
				// System.out.println(seat.getSeatID());
				if (seat != null) {

					cine.reserveSeats(seat);
					chosenSeats[i] = seat;
					seatNames[i] = input;
					i++;
					z++;
				}
			}
		}
		z = 0;
		if (i != 0) {
			System.out.print("Chosen seats are: ");
			for (int j = 0; j < chosenSeats.length; j++) {
				if (chosenSeats[j] != null) {
					// System.out.printf("%d", chosenSeats[j].getSeatID());
					System.out.print(seatNames[j] + " ");
				}
			}
			cine.showSeats();
			System.out.print("Confirm booking (Y/N): ");
			String input = obj.nextLine();
			if (input.charAt(0) == 'N') {
				for (int j = 0; j < chosenSeats.length; j++) {
					if (chosenSeats[j] != null) {
						cine.unreserveSeats(chosenSeats[j]);
						z--;
					}
				}
				System.out.println("Bookings reversed.");
				cine.showSeats();
				System.out.print("Continue booking (Y/N): ");
				input = obj.nextLine();
				if (input.charAt(0) == 'Y') {
					bookSeat(cine);
				}
			}
		}
		String[] seatIDs = new String[counter]; // remove all the null from the array
		for (int a = 0; a < counter; a++) {
			seatIDs[a] = seatNames[a];
		}
		return seatIDs;
	}

	public static void adminOptions(Cineplex[] branches)
			throws IOException, FileNotFoundException {
		Scanner obj = new Scanner(System.in);
		MovieList ML = new MovieList();
		Menu menu = new Menu();
		outer: while (true) {
			System.out.println();
			menu.AdminMenu();
			System.out.print("Enter your choice: ");
			int choice = Integer.parseInt(obj.nextLine());
			switch (choice) {
				case 0:
					break outer;
				case 1: {
					inner: while (true) {
						System.out.println();
						menu.EditMovieMenu();
						System.out.print("Enter your choice: ");
						choice = Integer.parseInt(obj.nextLine());
						switch (choice) {
							case 0:
								break inner;
							case 1: {
								Movie[] movielist = ML.getMovies();
								Movie newMovie = new Movie(null, null, null, null, choice,
										null, null, choice, choice, null, null);
								System.out.println("/////   Enter new movie details   /////");
								System.out.print("Movie Title: ");
								String input = obj.nextLine();
								newMovie.movieTitle = input;
								System.out.print("Movie Synopsis: ");
								input = obj.nextLine();
								newMovie.Synopsis = input;
								System.out.print("Director name: ");
								input = obj.nextLine();
								newMovie.Director = input;
								System.out.print("Casts: ");
								input = obj.nextLine();
								newMovie.Casts = input;
								System.out.print("Duration: ");
								double data = Integer.parseInt(obj.nextLine());
								newMovie.Duration = data;
								System.out.print("Status: ");
								input = obj.nextLine();
								newMovie.Status = input;
								System.out.print("Type: ");
								input = obj.nextLine();
								newMovie.Type = input;
								System.out.print("Total Sales: ");
								data = Integer.parseInt(obj.nextLine());
								newMovie.totalSales = data;
								// Avg rating should be added based on ratings string
								// System.out.print("Average Rating: ");
								// input = obj.nextLine();
								// newMovie.movieTitle = input;
								System.out.print("Reviews: ");
								input = obj.nextLine();
								newMovie.Reviews = input;
								System.out.print("Ratings: ");
								input = obj.nextLine();
								newMovie.Ratings = input;
								newMovie.avgRating = newMovie.calculateAvgRating(newMovie.Ratings);
								ArrayList<Movie> arrayList = new ArrayList<Movie>(Arrays.asList(movielist));
								arrayList.add(newMovie);
								movielist = arrayList.toArray(movielist);
								newMovie.Create();
								// System.out.println("Movie added");
								displayAllMovies(movielist);
								break;
							}
							case 2: {
								System.out.println("/////   Edit movie details   /////");
								Movie[] movielist = ML.getMovies();
								for (int i = 0; i < movielist.length; i++) {
									System.out.printf("(%d) %s\n", i + 1, movielist[i].getMovieTitle());
								}
								System.out.println("(0) Exit editing movie");
								System.out.print("Select movie to edit: ");
								choice = Integer.parseInt(obj.nextLine()) - 1;
								if (choice == -1 || choice >= movielist.length)
									break;
								Movie selected = movielist[choice];
								selected.display();
								MovieEdit EditMovie = (MovieEdit) selected;
								menu.EditMovieDetails();
								System.out.print("Select option to edit: ");
								choice = Integer.parseInt(obj.nextLine());
								switch (choice) {
									case 0:
										break inner;
									case 1:
										System.out.print("New movie title: ");
										String input = obj.nextLine();
										EditMovie.setMovieTitle(input);
										break;
									case 2:
										System.out.print("New synopsis: ");
										input = obj.nextLine();
										EditMovie.setSynopsis(input);
										break;
									case 3:
										System.out.print("New director: ");
										input = obj.nextLine();
										EditMovie.setDirector(input);
										break;
									case 4:
										System.out.print("New casts: ");
										input = obj.nextLine();
										EditMovie.setCasts(input);
										break;
									case 5:
										System.out.print("New duration: ");
										double data = Integer.parseInt(obj.nextLine());
										EditMovie.setDuration(data);
										break;
									case 6:
										System.out.print("New status: ");
										input = obj.nextLine();
										EditMovie.setStatus(input);
										break;
									case 7:
										System.out.print("New type: ");
										input = obj.nextLine();
										EditMovie.setType(input);
										break;
									case 8:
										System.out.print("New total sales: ");
										input = obj.nextLine();
										EditMovie.settotalSales(Double.parseDouble(input));
										break;
									case 9:
										System.out.print("Updating average rating...");
										EditMovie.setavgRating(selected.calculateAvgRating(selected.Ratings));
										break;
									case 10:
										System.out.print("Edit review in progress");
										input = obj.nextLine();
										EditMovie.setReviews(input);
										break;
									case 11:
										System.out.print("Edit ratings in progress: ");
										input = obj.nextLine();
										EditMovie.setRatings(input);
										break;
									default:
										System.out.println("Invalid input.");
										break;
								}
								System.out.printf("Movie %s has been edited.\n", selected.getMovieTitle());
								break;
							}
							case 3: {
								// Remove movie listing
								Movie[] movielist = ML.getMovies();
								System.out.println("/////   Delete movie   /////");
								for (int i = 0; i < movielist.length; i++) {
									System.out.printf("(%d) %s\n", i + 1, movielist[i].getMovieTitle());
								}
								System.out.println("(0) Exit removing movie");
								System.out.print("Select movie to remove: ");
								choice = Integer.parseInt(obj.nextLine()) - 1;
								if (choice == -1 || choice >= movielist.length)
									break;
								Movie selected = movielist[choice];
								selected.display();
								System.out.println("Confirm delete? (Y/N): ");
								String input = obj.nextLine();
								if (input.charAt(0) == 'Y') {
									MovieEdit EditMovie = (MovieEdit) selected;
									EditMovie.setStatus("End of showing.");
								}
								break;
							}
							default:
								System.out.println("Invalid input.");
								break;
						}
					}
					break;
				}
				case 2: {
					Cineplex selectedCineplex = null;
					Cinema selectedCinema = null;
					inner: while (true) {
						System.out.println();
						menu.EditCinemaMenu();
						if (selectedCinema != null) {
							System.out.printf("---Current selected cinema %d at %s---\n",
									selectedCinema.getCinemaID(), selectedCineplex.getLocation());
							selectedCinema.displayShowtimes();
						} else {
							System.out.println("--- Select a Cinema first to begin ---\n");
						}
						System.out.print("Enter your choice: ");
						choice = Integer.parseInt(obj.nextLine());
						switch (choice) {
							case 0:
								break inner;
							case 1: {
								int count = 1;
								for (int i = 0; i < branches.length; i++) {
									System.out.printf("%s\n", branches[i].getLocation());
									for (int j = 0; j < branches[i].getHalls().length; j++) {
										System.out.printf("(%d) - Hall %d\n", count,
												branches[i].getHalls()[j].getCinemaID());
										count++;
									}
								}
								System.out.print("Select cinema: ");
								choice = Integer.parseInt(obj.nextLine());
								if (choice < count) {
									count = 1;
									for (int i = 0; i < branches.length; i++) {
										for (int j = 0; j < branches[i].getHalls().length; j++) {
											if (count == choice) {
												// System.out.println("Current is " + choice + count);
												selectedCineplex = branches[i];
												selectedCinema = branches[i].getHalls()[j];
												// System.out.println("CINEMA FOUND");
											}
											count++;
										}
									}
								} else
									System.out.println("Invalid option");
								break;
							}
							case 2: {
								System.out.print("Enter showtime in (Hour:Minutes) [E.g. 14:30]: ");
								String input = obj.nextLine();
								selectedCinema.addShowtimes(input);
								break;
							}
							case 3: {
								Date[] showtimes = selectedCinema.getShowtimes();
								selectedCinema.displayShowtimes();
								System.out.println("(0) Exit");
								System.out.print("Enter your choice: ");
								choice = Integer.parseInt(obj.nextLine()) - 1;
								if (choice != -1 && choice < showtimes.length) {
									System.out.print("Enter showtime in (Hour:Minutes) [E.g. 14:30]: ");
									String input = obj.nextLine();
									selectedCinema.editShowtimes(input, choice);
								}
								break;
							}
							case 4: {
								Date[] showtimes = selectedCinema.getShowtimes();
								selectedCinema.displayShowtimes();
								System.out.println("(0) Exit");
								System.out.print("Enter your choice: ");
								choice = Integer.parseInt(obj.nextLine()) - 1;
								if (choice != -1 && choice < showtimes.length) {
									selectedCinema.removeShowtimes(choice);
								}
								break;
							}
							case 5: {
								Movie[] movielist = ML.getMovies();
								for (int i = 0; i < movielist.length; i++) {
									System.out.printf("(%d) %s\n", i + 1, movielist[i].getMovieTitle());
								}
								System.out.print("Select movie to assign: ");
								choice = Integer.parseInt(obj.nextLine()) - 1;
								if (choice == -1 || choice >= movielist.length)
									break;
								Movie selection = movielist[choice];
								selectedCinema.assignMovie(selection);
								break;
							}
							default:
								System.out.println("Invalid input.");
								break;
						}
					}
				}
					break;
				case 3: {
					inner: while (true) {
						System.out.println();
						menu.EditSystemMenu();
						System.out.print("Enter your choice: ");
						choice = Integer.parseInt(obj.nextLine());
						switch (choice) {
							case 0:
								break inner;
							case 1: {
								innerinner: while (true) {
									double data;
									Price pricings = new Price();
									System.out.println();
									pricings.printPrices();
									menu.EditTicketPrice();
									System.out.print("Enter your choice: ");
									choice = Integer.parseInt(obj.nextLine());
									switch (choice) {
										case 0:
											break innerinner;
										case 1:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_PH(data);
											break;
										case 2:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_standard(data);
											break;
										case 3:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_seniorCitizen(data);
											break;
										case 4:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_student(data);
											break;
										case 5:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_normal(data);
											break;
										case 6:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_gold(data);
											break;
										case 7:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_platinum(data);
											break;
										case 8:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_PREVIEW(data);
											break;
										case 9:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_NOWSHOWING(data);
											break;
										case 10:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_twoD(data);
											break;
										case 11:
											System.out.print("Enter new pricing: ");
											data = Double.parseDouble(obj.nextLine());
											pricings.setPrice_threeD(data);
											break;
										default:
											System.out.println("Invalid input.");
											break;
									}
								}
								break;
							}
							case 2: {
								innerinner: while (true) {
									Calender newPH = new Calender();
									newPH.DisplayAll();
									System.out.println();
									System.out.println("Enter 0 to exit.");
									System.out.print("Enter new public holiday (YYYY-DD-MM): ");
									String input = obj.nextLine();
									if (input.charAt(0) == '0')
										break innerinner;
									newPH.setPublicHoliday(input);

								}
								break;
							}
							case 3: {
								innerinner: while (true) {
									System.out.println();
									ML.rankbyAR();
									ML.rankbyTS();
									menu.ToggleSystemMenu();
									System.out.print("Enter your choice: ");
									choice = Integer.parseInt(obj.nextLine());
									switch (choice) {
										case 0:
											break innerinner;
										case 1:
											ML.editRank("FALSE|FALSE");
											break;
										case 2:
											ML.editRank("FALSE|TRUE");
											break;
										case 3:
											ML.editRank("TRUE|FALSE");
											break;
										case 4:
											ML.editRank("TRUE|TRUE");
											break;
										default:
											System.out.println("Invalid input.");
											break;
									}
								}
								break;
							}
							default:
								System.out.println("Invalid input.");
								break;
						}
					}
				}
					break;
				default:
					break;
			}
		}
		System.out.println("Exiting admin menu...\n");
	}
}