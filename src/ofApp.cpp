#include "ofApp.h"


void ofApp::setup() {

	mainSmall.load("Dongle-Regular.ttf", 18);
	mainBig.load("Dongle-Regular.ttf", 25);
	mainBigger.load("Dongle-Bold.ttf", 35);
	logoBig.load("Dongle-Bold.ttf", 30);
	mainBigBold.load("Dongle-Light.ttf", 18); //This sets the fonts.

	btn1.set(20, 50, 150, 50); //This sets the buttons.
	btn2.set(20, 150, 150, 50);
	btn3.set(20, 250, 150, 50);
	btn4.set(20, 350, 150, 50);
	btn5.set(20, 450, 150, 50);
	btn6.set(20, 550, 150, 50);
	btn7.set(20, 650, 150, 50);
	result.set(300, 50, 700, 700);

	loadData();
}

string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " ");

	for (int i = 0; i < words.size(); i++) {
		string wrd = words[i];

		if (i > 0) {
			tempString += " ";
		}
		tempString += wrd;

		int stringwidth = mainSmall.stringWidth(tempString);

		if (stringwidth >= width) {
			typeWrapped += "\n";
			tempString = wrd;
		}
		else if (i > 0) {
			typeWrapped += " ";
		}
		typeWrapped += wrd;
	}
	return typeWrapped;
}

void ofApp::loadData() {
	data.open(ofToDataPath("sampleTweets1.csv"));
	if (data.is_open()) {
		while (!data.eof()) {

			getline(data, dateTimeHolder, ',');
			getline(data, ignore, 'b');
			tweetcount++; //This will count all the tweets in the file
			getline(data, tweetHolder);

			tweetHolder1.push_back(dateTimeHolder);
			tweetHolder2.push_back(tweetHolder);
		}
		cout << "The number of tweets are: " << tweetcount << endl; //This will output the total amount of tweets in the csv file.
		tweetHolder1.erase(tweetHolder1.begin());
		data.close();
	}
	else { //If the file is not found, this will be shown in the console.
		cout << "The File Was Not Found." << endl;
	}
}

void ofApp::draw() {
	ofBackground(0, 0, 255);
	ofSetColor(255);
	ofDrawRectangle(btn1);
	ofDrawRectangle(btn2);
	ofDrawRectangle(btn3);
	ofDrawRectangle(btn4);
	ofDrawRectangle(btn5);
	ofDrawRectangle(btn6);
	ofDrawRectangle(btn7);
	ofDrawRectangle(result);
	ofSetColor(255);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Paris", 35, 75);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Dreamworks", 35, 175);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Uber", 35, 275);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Money", 35, 375);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Politics", 35, 475);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Games", 35, 575);
	ofSetColor(0, 0, 0);
	mainBig.drawString("Music", 35, 675);
	ofSetColor(0, 0, 0);
	mainBig.drawString(count, 35, 430); //All of this is for my UI Design.
	int i = 340, j = 70, k = 350, l = 100; 

	for (int a = 0; a < searched_tweets.size(); a++) {
		mainSmall.drawString(date_of_tweets_searched[a], i, j);
		j += 82;

		string newText = wrapString(searched_tweets[a], 650);

		mainSmall.drawString(newText, k, l);
		l += 80;
	}
}

void ofApp::mousePressed(int x, int y, int button) {
	if (btn1.inside(x, y)) { //When A user clicks a button, this will show.
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Paris") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the paris button and will show all tweets related to paris.
	}
	if (btn2.inside(x, y)) {
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Dreamworks") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the Dreamworks button and will show all tweets related to dreamworks.
	}
	if (btn3.inside(x, y)) {
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Uber") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the uber button and will show all tweets related to uber.
	}
	if (btn4.inside(x, y)) {
		counter = 0;
		searched_tweets.clear();
		count.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Money") != string::npos) {
				counter += 1;
				count = to_string(counter); //This will show all the amount of tweets related to money
			}
		}
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Money") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the money button and will show all tweets related to money.
	}
	if (btn5.inside(x, y)) {
		counter = 0;
		searched_tweets.clear();
		count.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Politics") != string::npos) {
				counter += 1;
				count = to_string(counter); //This will show all the amount of tweets related to politics
			}
		}
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Politics") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the politics button and will show all tweets related to politics.
	}
	if (btn6.inside(x, y)) {
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Games") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the games button and will show all tweets related to games.
	}
	if (btn7.inside(x, y)) {
		searched_tweets.clear();
		for (int i = 0; i < tweetHolder2.size(); i++) {
			string str1 = tweetHolder2[i];
			if (str1.find("Music") != string::npos) {
				searched_tweets.push_back(tweetHolder2[i]);
				date_of_tweets_searched.push_back(tweetHolder1[i]);
			}
		} //This is for the music button and will show all tweets related to music.
	}
}

	