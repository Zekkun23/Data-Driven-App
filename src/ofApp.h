#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

public:
	void setup();
	void draw();
	void loadData();
	string ofApp::wrapString(string text, int width);

	//Everything here is just initializing variables.
	void mousePressed(int x, int y, int button);
	vector <string> searched_tweets, tweetHolder1, tweetHolder2, date_of_tweets_searched;
	string dateTimeHolder, ignore, tweetHolder, text, count, str3;
	ifstream data;
	int tweetcount, moneycount, counter;

	ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, result;
	ofTrueTypeFont mainSmall, mainBig, mainBigger, logoBig, mainBigBold;
	ofImage backgroundImg, logoImg, searchBarImg, refreshImg, instructionsImg;
};
