package SC2002_Java.MOBLIMA;

import java.nio.file.*;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.*;
import java.io.*;
// import java.io.FileNotFoundException;
// import java.io.IOException;
// import java.util.Scanner;
// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.Calendar;
// import java.util.Date;

public class MOBLIMA_App_Alan {

	public static void main(String[] args) throws FileNotFoundException, IOException, ParseException {
		// Instantiating basic objects
		Calender cal = new Calender();
		int choice = 1; // Menu option
		Date[] showtimes = { cal.setHHMM("14:00"), cal.setHHMM("17:00") };
		MovieList ML = new MovieList();
		Movie[] movielist = ML.getMovies();
		Scanner obj = new Scanner(System.in);
		Menu menu = new Menu();
		Cinema hall1 = new Cinema(0, null);
		Cinema hall2 = new Cinema(1, null);
		Cinema hall3 = new Cinema(2, null);
		Cinema[] jurong_halls = { hall1, hall2, hall3 };
		Cineplex jurong_cineplex = new Cineplex("Jurong Cineplex", jurong_halls);
		Cinema hall4 = new Cinema(0, null);
		Cinema hall5 = new Cinema(1, null);
		Cinema hall6 = new Cinema(2, null);
		Cinema[] woodlands_halls = { hall4, hall5, hall6 };
		Cineplex woodlands_cineplex = new Cineplex("Woodlands Cineplex", woodlands_halls);
		Cineplex[] allBranches = { jurong_cineplex, woodlands_cineplex };
		hall1.assignMovie(movielist[5]);
		// loadCineplexMovies(allBranches);

		// Trying out basic objects and interactions
		// for (int i = 0; i < movielist.length; i++) {
		// System.out.println(movielist[i].getMovieTitle());
		// }
		// ArrayList<Movie> arrayList = new ArrayList<Movie>(Arrays.asList(movielist));
		// Movie spiderman = new Movie("Spiderman", "Action", null, null, 0, null, null,
		// 0, 0, null, null);
		// hall4.assignMovie(spiderman);
		// arrayList.add(spiderman);
		// movielist = arrayList.toArray(movielist);
		// Cinema found = searchMovie("spiderman", allBranches);
		// System.out.println(found.getCinemaID() + found.getMovie().movieTitle);
		// bookSeat(hall4);
		// Main App Portion

		outer: while (true) {
			menu.Homepage();
			System.out.print("Enter your choice: ");
			int input = Integer.parseInt(obj.nextLine());
			// String dummy = obj.next();
			switch (input) {
				case 0:
					break outer;
				case 1:
					displayAllMovies(movielist);
					break;
				case 2:
					System.out.print("Enter name of movie: ");
					// String search = String.(obj.nextLine());
					String search = obj.nextLine();
					// Was originally next
					searchMovie(search, allBranches);
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					System.out.print("Enter password: ");
					String password = obj.nextLine();
					if (password.equals("Admin123")) {
						adminOptions(allBranches);
					} else
						System.out.println("Invalid password.");
					break;
				default:
					System.out.println("Invalid input.");
					break;
			}
			System.out.println();
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

	public static Cinema searchMovie(String input, Cineplex[] cineplexes) {
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

	public static void bookSeat(Cinema cine) {
		int[] seatids = new int[cine.EmptySeats()];
		int counter = 0;
		Scanner obj = new Scanner(System.in);
		int i = 0;
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
				seatids[counter] = seat.getSeatID();
				counter++;
				if (seat != null) {
					cine.reserveSeats(seat);
					chosenSeats[i] = seat;
					seatNames[i] = input;
					i++;
				}
			}
		}
		if (i != 0) {
			System.out.print("Chosen seats are: ");
			for (int j = 0; j < chosenSeats.length; j++) {
				if (chosenSeats[j] != null) {
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
		for (int j = 0; j < seatids.length; j++) {
			if (seatids[j] != 0)
				System.out.println(seatids[j]);
		}
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
										EditMovie.setMovieTitle(input);
										break;
									case 7:
										System.out.print("New type: ");
										input = obj.nextLine();
										EditMovie.setMovieTitle(input);
										break;
									case 8:
										System.out.print("New total sales: ");
										input = obj.nextLine();
										EditMovie.setMovieTitle(input);
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
				case 3:
					inner: while (true) {
						System.out.println();
						menu.EditSystemMenu();
						System.out.print("Enter your choice: ");
						choice = Integer.parseInt(obj.nextLine());
						switch (choice) {
							case 0:
								break inner;
							case 1:
								break;
							case 2:
								break;
							case 3: {
								System.out.println("---Toggle movie rankings---");
								System.out.println("(1) Hide Ranking Top 5 by Total Sales");
								System.out.println("(2) Hide Ranking Top 5 by Average Rating");
								System.out.println("(0) Exit toggling");

							}
								break;
							default:
								break;
						}
						break;
					}
				default:
					break;
			}
		}
		System.out.println("Exiting admin menu...\n");
	}

}
