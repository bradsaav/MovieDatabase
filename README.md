[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9904252&assignment_repo_type=AssignmentRepo)

# Movie Recommender
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Adelric Low](https://github.com/AMinus24), [Bradly Saavedra](https://github.com/bradsaav), [Dion Ngo](https://github.com/dngo2401), and [Nathaniel Morales](https://github.com/nathanielmor)

## Project Description
> * This **project** is a movie database/recommender. The user will input the movies that they have previously watched by searching through a database of movies, and record the rating of the movie. The user will also be able to select a movie in the database and view details such as the overall rating from other users or the acting cast. Based on the movies that the user has watched as well as their rating, the movie recommender will present a selection of movies that may be a good fit for the user.
>
> * This project is **interesting** to us because it seems like a practical application for movie watchers to decide on what they want to view next. 
>
> * We will **use** C++ to import a list of movies as well as other data such as ratings or acting cast. The user will be able to sort through this list based on desired parameters. The user will also enter information about the movies they have watched, which will be stored in their movies list. This list is used to calculate potential movies that would be recommended to the user. An algorithm will read the list and calculate an average value of features, weighing the movie less if the user rated the movie poorly. Based on this average, the algorithm will return movies which are closest to the user’s average.  If we decide on implementing a GUI, we can utilize a GUI library to program it.
>
> * The **inputs** of the project will be the movies and the ratings that the user inputs into their movie list. The outputs of the project should be a selection of movies that would be catered to the user as well as statistics about the user’s movie history.

> * This project will **primarily serve** as a searchable database of movies, a list of previously watched movies, and a recommendation tool.
 
## Class Diagram

![Class Diagram 3.0](https://github.com/cs100/final-project-team-of-people/blob/master/UML%20Diagram%203.0.png)

## Class Diagram Description
> The Movie class creates a movie object. A movie contains a name, a year, genres, directors, and a cast. There exists a composition between CastList class and Movie class because a Movie has a unique CastList and the deletion of a Movie should delete the unique CastList that was generated with it.

 > The CastMember class is a simple class that is used to describe an Actor or Director object. All cast members, Actors and Directors, have a name and an age. The class CastList is a container class that is a vector of type CastMember. This is an aggregation association because CastMember can stand alone outside of the deletion of the list.

> The User class creates a user object. The User can write reviews, search movies, and add movies to a watchlist. The watchlist is an object of type Movie_List. There exists a composition between these two classes because the watchlist is unique to the User and the deletion of the User should permit the deletion of the Movie_List associated with it. There also exists another composition between the User and Review_List because the deletion of User should permit the deletion of the associated Reviews kept in their profile.

> The Review class creates a Review object. Review objects hold a name of the movie that the review is for, an int score of 1 to 5, and a review about the movie that the user writes providing their thoughts and opinions about any aspect of the movie.

> The DisplayRecommendations class sole purpose is to output Movies and suggest them as recommendations depending on what the user is looking for exactly. It can recommend movies by a specific genre, actor/actress, or director. There exists an association between itself and the Movie_List class for testing purposes only.

> The Review_List, Cast_List, and Movie_List are all classes that create List containers of either Movie, Review, or Cast_Member objects. They are just a vector of the aggregated associated objects.

## SOLID Class Diagram

![SOLID UML Diagram](https://github.com/cs100/final-project-team-of-people/blob/master/SOLID%20UML%20Diagram.png)

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
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
