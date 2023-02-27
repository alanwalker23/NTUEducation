package MOBLIMA;

import java.util.Date;
import java.util.Calendar;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;
import java.util.ArrayList;
import java.util.List;

public class Calender {
	private int DayOfWeek;
	private Date date;
	private Calendar cal = Calendar.getInstance();
	private Date[] ph = new Date[10];

	public void setPublicHoliday(String date) throws IOException {
		FileWriter fstream = new FileWriter("src/PublicHoliday.txt", true);
		BufferedWriter out = new BufferedWriter(fstream);

		String append = date;
		out.write(append);
		out.newLine();

		// close buffer writer
		out.close();

		System.out.println("PH added ");
	}

	SimpleDateFormat dateFormatter = new SimpleDateFormat("yyyy-MM-dd");
	SimpleDateFormat hhmm = new SimpleDateFormat("HH:MM");

	public Date getdate() { // get date now
		return this.date;
	}

	public Date setDate(String d) throws ParseException { // set the date
		date = dateFormatter.parse(d);
		return date;
	}

	public Date setHHMM(String d) throws ParseException {

		date = hhmm.parse(d);
		return date;
	}

	public int getDayOfWeek(Date date) { // sun = 1
		// cal.setTime(date);
		DayOfWeek = cal.get(Calendar.DAY_OF_WEEK);
		return DayOfWeek;
	}

	public void unsetPublicHoliday(String date) throws IOException {
		File inputFile = new File("src/PublicHoliday.txt");
		File tempFile = new File("src/TempFile.txt");

		BufferedReader reader = new BufferedReader(new FileReader(inputFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

		String line;
		String lineToRemove = null;

		while ((line = reader.readLine()) != null) {
			if (date.equals(line)) {
				lineToRemove = reader.readLine();
				break;
			}
		}
		if (line == null)
			return;
		String currentLine;

		while ((currentLine = reader.readLine()) != null) {
			// trim newline when comparing with lineToRemove
			String trimmedLine = currentLine.trim();
			if (trimmedLine.equals(lineToRemove))
				continue;
			writer.write(currentLine + System.getProperty("line.separator"));
		}
		writer.close();
		reader.close();
		boolean successful = tempFile.renameTo(inputFile);

		System.out.println("PH removed");

	}

	public boolean checkPH(String date) throws IOException {
		FileReader fstream = new FileReader("src/PublicHoliday.txt");
		BufferedReader br = new BufferedReader(fstream);
		String line;
		while ((line = br.readLine()) != null) {
			if (line.equals(date))
				return true;
		}
		return false;

	}
}
