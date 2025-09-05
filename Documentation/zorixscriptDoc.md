# heya'!, welcome to the zorixScript documentation! 👋<br>
*lets go through all the available functions, shall we?*<br>

# bind<br>
bind is the *MOST* important part of a zorixScript..<br>
it must be placed at the *VERY TOP* of each zorixScript with no fail, or else the script ⚠️ **WON'T WORK!** ⚠️!<br>

bind requires two arguments, "Type:" & "Id:"<br>
this is what "bind()" looks like in code!:<br>

bind(<br>
Type: "TextButton"<br>
Id: 2<br>
)<br>

bind basically tells the parser:<br>
"hey unc, i want you to instruct [X Binded Object]!!"<br>

and thats about it, now you can use the other functions! 🎊<br>

# setBackgroundColor<br>
setBackgroundColor is relatively self-explanatory, it sets the background color on *some* UI elements.<br>
it requires 3 un-labeled arguments that represent R/G/B values.<br>

this is what setBackgroundColor() looks like in code!:<br>

setBackgroundColor(<br>
255<br>
255<br>
255<br>
)<br>

the first value represents "R", second is "G", and third is "B".<br>

# But wait, whats up with the format?! 🤔<br>
The zorixscript parser is very simple, hence making it *VERY* picky in what formats work. the common rules are:<br>

> No indentation<br>
> Arguments *MUST* be passed in seperate lines<br>
> And other stuff i can't recall..<br>

okay lets resume..<br>

# setTextColor<br>
another self-explanatory one, this sets the text color on *some* UI elements!<br>
it requires 3 un-labeled arguments that represent R/G/B values.<br>

this is what setTextColor looks like in code!:<br>

setTextColor(<br>
0<br>
0<br>
0<br>
)<br>

the first value represents "R", second is "G", and third is "B".<br>

# setText<br>
this function sets (or changes) the text on *some* UI elements!<br>
it requires 1 un-labeled argument that represents a string!<br>

and here is what it looks like in code!:<br>

setText(<br>
"documentation text heh.."<br>
)<br>

# setPosition<br>
this sets (or changes) the position of *any* UI element.<br>
it requires 2 un-labeled arguments that represent X & Y values.<br>

here is the code example!:<br>

setPosition(<br>
50<br>
50<br>
)<br>

this sets the binded object to 50, 50 on the screen!<br>

# resize<br>
this resizes the size of *any* UI element.<br>
it requires 2 un-labeled arguments that represent W & H values.<br>

here is the code example!:<br>

resize(<br>
50<br>
50<br>
)<br>

this resizes the binded object to 50, 50 on the screen!<br>

---<br>

# EVENTS! <br>
Welcome to section 1.1 of the documentation, here you'll learn zorixScript Events!<br>

# onClick::(::) <br>
Typically event brackets are preceded with "::", this helps the parser diffrentiate from event blocks and plain blocks. <br>
onClick works on specific UI Elements (TextButton, ColorButton) <br>
here is the code example!:<br>

onClick::(

setBackgroundColor(<br>
0<br>
0<br>
0<br>
)<br>

resize(<br>
200<br>
50<br>
)<br>

setText(<br>
"Thank You!!"<br>
)<br>

setTextColor(<br>
255<br>
255<br>
255<br>
)<br>

setPosition(<br>
0<br>
0<br>
)<br>

::)<br>

this resizes the binded object to 200, 50. sets the text to "Thank You!!". sets the text color to WHITE(255,255,255). and sets the position to 0,0. all of this happens on click.<br>

---<br>

Congratulations, you finished this terribly-written documentation of zorixScript.. 🎊😮‍💨<br>
you can now use zorix without being terrible at it xx 🌺<br>
