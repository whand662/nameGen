import java.util.Random;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class NameGen{

  private String path1, path2, path3, path4;

  private static ArrayList<String> firstBank;
  private static ArrayList<String> lastBank;
  private static ArrayList<String> placeBank;
  private static ArrayList<String> teamBank;

  Random rand;

  public NameGen(){
    rand = new Random();
    path1 = "./nameGen/res/first.txt";
    path2 = "./nameGen/res/last.txt";
    path3 = "./nameGen/res/team.txt";
    path4 = "./nameGen/res/place.txt";
    populate();
  }

  public NameGen(String inDirectory){
    rand = new Random();
    path1 = inDirectory + "first.txt";
    path2 = inDirectory + "last.txt";
    path3 = inDirectory + "team.txt";
    path4 = inDirectory + "place.txt";
    populate();
  }

  private void populate(){
    if(firstBank != null){
      //Already loaded
      return;
    }

    firstBank = new ArrayList<String>();
    lastBank = new ArrayList<String>();
    placeBank = new ArrayList<String>();
    teamBank = new ArrayList<String>();

    try{
      BufferedReader inFile1 = new BufferedReader(new FileReader(path1));
      BufferedReader inFile2 = new BufferedReader(new FileReader(path2));
      BufferedReader inFile3 = new BufferedReader(new FileReader(path3));
      BufferedReader inFile4 = new BufferedReader(new FileReader(path4));
      String temp = "";

      if (inFile1.ready()) {
        while ((temp = inFile1.readLine()) != null) {
          firstBank.add(temp);
        }
          inFile1.close();
      } else {
        System.out.println("Unable to open input file");
      }

      if (inFile2.ready()) {
        while ((temp = inFile2.readLine()) != null) {
          lastBank.add(temp);
        }
          inFile2.close();
      } else {
        System.out.println("Unable to open input file");
      }

      if (inFile3.ready()) {
        while ((temp = inFile3.readLine()) != null) {
          teamBank.add(temp);
        }
          inFile3.close();
      } else {
        System.out.println("Unable to open input file");
      }

      if (inFile4.ready()) {
        while ((temp = inFile4.readLine()) != null) {
          placeBank.add(temp);
        }
          inFile4.close();
      } else {
        System.out.println("Unable to open input file");
      }
    }catch(IOException e){
      e.printStackTrace();
    }

    firstBank.trimToSize();
    lastBank.trimToSize();
    teamBank.trimToSize();
    placeBank.trimToSize();
  }

  public String genFirst(){
    int temp = rand.nextInt(firstBank.size());
    return firstBank.get(temp);
  }

  public String genLast(){
    int temp = rand.nextInt(lastBank.size());
    return lastBank.get(temp);
  }

  public String genFull(){
    return genFirst() + " " + genLast();
  }

  public String genPlace(){
    int temp = rand.nextInt(placeBank.size());
    return placeBank.get(temp);
  }

  public String genTeam(boolean withPlace){
    int temp = rand.nextInt(teamBank.size());
    String hold = teamBank.get(temp);
    if (withPlace) {
      return genPlace() + " " + hold;
    } else {
      return hold;
    }
  }

}
