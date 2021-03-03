

# Habit Tracker
updated 01/05/21

This is the beginning of the backend code to implement a Habit Tracker app which allows\
users to easily track habits and customize the habits they want to track.

Here is why I am building this program:\
I have used various habit tracking software in the past to track my habits and it has been too difficult for me.\
I am a VERY lazy user of these apps and do not like clicking around on my phone everytime I want\
to update one of my habits. From July 2020 to March 2021 I have been using a word document to\
track my habits. This word document has been in this format:\
Date\
Weekday\ 
Wrkt \ 
Bedtime/wake up\ 
Study csci\

and the list goes on like this. I copy and paste the prompts I listed above\
to track my habits for subsequent days. The problem that I have with this is that I dont like\
having to click the next line each time I am done updating the habit information for that day\
and when I say "click" I mean I don't like literally having to move my finger and tap the line below. \
For example if I am typing in data for "Date:" on my mobile device I have to click to the right of\
"Date:" and then type in "month/day". To enter data for the next line I have to move my finger and\
click to the right of "Weekday:" and then type in "<weekday>". To enter data for the next line\
I have to move my finger and click to the right of "Wrkt:" ... you get the picture.\ 
So, to save myself the monotany of having to click every time I want to enter new data for a habit that\
I want to track, I am creating this Habit Tracker Program to automate this task.\
  
With this program, I want my commandline to prompt me to enter data in a specific format for each\
habit I want to track, then when I click "enter" I will not have to click, I will just get prompted\
to enter the data for the next habit I am wanting to track\

future iterations of this program is to have an implemented mobile application that can automate this\
process and be compatable with purely voice when the user is submitting data for the daily habits\
they want to track.\


accountabilityReader purpose is to take in a primer.txt file with format: 

Date: Date \
Weekday: name\
Wrkt: YOrN\
Bedtime/wake up: sleep\
Chapters of bible read: YOrN, Amount\
Study csci: YOrN, Amount\
Therapy work: YOrN, name, Amount\
Meditation: YOrN, name \
Full body stretching: YOrN\
Connection: YOrN, Amount\
Journaling: YOrN, Amount\
videogames: YOrN, Amount\
Expression: YOrN, Amount\
Caffeine: Amount

This primer file is used to "prime" the program to take in "record.txt", that contains "Tracks" 
(activities and things that user wants to track), file with the similar pattern of the Tracks and TrackMetrics in the primer.txt. 
A Track object is the string to the left of the ":" and the
TrackMetric(s) is what is on the right side of the ":"

i.e Caffeine is the "Track" and the Amount is the "TrackMetric"

Date: 1/4\
Weekday: mon\
Wrkt: y strength\
Bedtime/wake up: 1-9 \
Study csci: y class\
Therapy work: n\
Meditation: y 20 mins breath\
Full body stretching: y 2x\
Connection: y call maur, call jason, meeting \
Journaling: y\
videogames: y chess 20 min\
Expression: y singing\
Caffeine: 200 mg\
Sugar: waffles, mommas chocolate

The above from "Date: .... Sugar:" is one "Day" object. A week is made up of seven Day objects.
The goal of this program is to use the record.txt file to create Day objects within a Week object and 
display the contents of that week. In the above case it would be how much sugar the user had that week, how many times they worked out etc

As of 01/05/21 The program takes in the primer.txt file and creates a skeloton of empty day objects to be filled in by the record.txt file.

