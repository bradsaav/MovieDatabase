[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9904252&assignment_repo_type=AssignmentRepo)

# Movie Recommender
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Adelric Low](https://github.com/AMinus24), [Bradly Saavedra](https://github.com/bradsaav), [Dion Ngo](https://github.com/dngo2401), and [Nathaniel Morales](https://github.com/nathanielmor)

## Project Description
> * This **project** is a movie database/recommender. The user will input movies that they have previously watched by adding them into a database of movies, and record the data of the movie. The user will need to find data from online to input the movie such as the movie name, genre, directors, and length. The user will also be able to select a movie in the database and view details such as the name, year, rating, genre, director, and the acting cast that other users or themselves have provided. The user is recommended movies based on different filtering systems allowing them to find recommendatiosn through their favorite actors/actresses, genres, or directors. They can also search to see if a specific movie is in our database.
>
> * This project is **interesting** to us because it seems like a practical application for movie watchers to decide on what they want to view next. 
>
> * We will **use** C++ to import a list of movies as well as other data such as ratings or acting cast. The user will be able to sort through this list based on desired parameters. The user will also enter information about the movies they have watched, which will be stored in their movies list. This list is used so the user can recall what movies they plan to watch for every execution of the program. An algorithm will ask the user what kind of movies they like abd would recommend movies of the categories that the user chooses.
>
> * The **inputs** of the project will be the movies and reviewa that the user inputs into their movie list. The outputs of the project should be a selection of movies that would be catered to the user as well as data on the user's previous visits.

> * This project will **primarily serve** as a searchable database of movies, a list of previously watched movies, and a recommendation tool.
 
## Class Diagram v4.0

![Class Diagram 4.0](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/UML%20Diagram%204.0.png)

## Class Diagram Description
> The Movie class creates a movie object. A movie contains a name, a year, genres, directors, and a cast. There exists a composition between CastList class and Movie class because a Movie has a unique CastList and the deletion of a Movie should delete the unique CastList that was generated with it.

 > The CastMember class is a simple class that is used to describe an Actor or Director object. All cast members, Actors and Directors, have a name and an age. The class CastList is a container class that is a vector of type CastMember. This is an aggregation association because CastMember can stand alone outside of the deletion of the list.

> The User class creates a user object. The User can write reviews, search movies, and add movies to a watchlist. The watchlist is an object of type Movie_List. There exists a composition between these two classes because the watchlist is unique to the User and the deletion of the User should permit the deletion of the Movie_List associated with it. There also exists another composition between the User and Review_List because the deletion of User should permit the deletion of the associated Reviews kept in their profile.

> The Review class creates a Review object. Review objects hold a name of the movie that the review is for, an int score of 1 to 5, and a review about the movie that the user writes providing their thoughts and opinions about any aspect of the movie.

> The DisplayRecommendations class sole purpose is to output Movies and suggest them as recommendations depending on what the user is looking for exactly. It can recommend movies by a specific genre, actor/actress, or director. There exists an association between itself and the Movie_List class for testing purposes only.

> The Review_List, Cast_List, and Movie_List are all classes that create List containers of either Movie, Review, or Cast_Member objects. They are just a vector of the aggregated associated objects.

## SOLID Class Diagram

![SOLID UML Diagram](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/SOLID%20UML%20Diagram.png)

## SOLID Class Diagram Explaination
> After reviewing our updated UML Diagram, we tried and applied SOLID principles to create a more improved and optimized version of our UML Diagram. The first principle we thought to apply was the S, the Single Responsibility Principle, where each class is responsible for only one thing. However, we believe that our current UML Diagram already succeeds in this category. For instance, the Movie class, Although the Movie class contains actors/actresses, directors, reviews and ratings, there exists specific classes for the data inside the Movie class that handle their own functions so one class does not hold more than it can handle. 

> As for the O, the Open Closed Principle, where a program only extends and does not accept any modifications. We noticed that we have multiple container classes that have the same function, and if we wanted to add another container class we would need to modify code in other classes to accept a new container. To fix this, we made an abstract List class that creates generalized functions to be implemented in more detail by the child classes. So, if we wanted to make a Genre_List class all we need to do is make it inherit from the abstract list and implement their own version of the inherited function, and the classes that use the list class do not need modification to use the Genre_List functions. 

> Applying this principle also works for D, the Dependency Inversion Principle, where high level modules should not depend on low level modules. This goes along with creating the List abstraction which is used as a tool in most other classes. For example, the Movie class uses the List abstraction and does not rely on specific details which would be provided during run-time. 

> As for the Interface Segregation Principle, we felt it was unnecessary for us to change what we had because all movies have the same characteristics and should not be separated. 

> The L, Liskov Substitution Principle, did not change our UML Diagram much because the child classes Director and Actor does exactly what its parent class Cast_Member can do.
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running our application
 > Starting Menu for User:
 > 
 ![Start Login](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/FirstInput.jpg)
 > Adding a movie that the user has watched to the database 
 > 
 ![Add Movie Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/AddMovieToDB.jpg)
 > Searching if a specific movie is in the database:
 > 
 ![Search Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/SearchInput.jpg)
 > Recommending movies based on selected criteria:
 > 
 ![Recommender Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/RecommenderPart.jpg)
 > Creating or loading review list:
 > 
 ![Review List Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/reviewlistmenu.jpg)
 > Creating or loading watch list:
 > 
 ![Recommender Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/watchlistmenu.jpg)
 > Viewing all movies:
 > 
 ![View All Movies Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/viewAllMovies.jpg)
 > Quitting Program:
 > 
 ![Quit Program Option](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/qExitsProgram.jpg)
 ## Installation/Usage
 
 > To install the application, run the git clone command and run "git clone --recursive https://github.com/cs100/final-project-team-of-people.git"
 > Once you have cloned the repository, open up your terminal and switch to the src directory by running "cd src". Now that we are in the src directory run    "cmake .", "make", and finally "./runProgram". The program will then ask you for a username, you can type any username you'd like. From there all you       have to do is follow the menu instructions to perform the actions you'd like.
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 > We tested our program using Google Test and validated our output through Main. We created test for most of our classes in order to validate all the        functions that return a value/object. We created multiple test suites for each of our classes and for all our functions we created unit tests to ensure that our functions were properly accessing and mutating variables using gtest assertions. For the functions that do not return anything, we tested their behavior by creating sample objects/variables and     validating whether the member variables were equivalent to the expected equality through "cout".
 
 ## Valgrind Run
 ![Valgrind run](https://github.com/cs100/final-project-team-of-people/blob/master/screenshots/ValgrindRun.jpg)
 
