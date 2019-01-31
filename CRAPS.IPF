:userdoc.
:prolog.
:title.Help
:eprolog.
:body.
 
.*************************************************************************
.* This is the main help panel
.*************************************************************************
:h1 res=10000.Las Vegas Craps - Help
:i1 id=main.Las Vegas Craps
:p.:hp8.Las Vegas Craps:ehp8. is an authentic rendition of a Las Vegas style craps
game.  While the primary purpose of this game is entertainment, it also
provides helpful assistance and recommended strategies.
:p.Craps is the most exciting of all casino games.  It offers the player the
opportunity to win, or lose, large sums of money very quickly.  There are over
twenty different bets available in the game of craps.  The craps table is
divided into three distinct sections.  The two end sections are where the
majority of the bets are made.  The middle area, contains bets known as
proposition, or center, bets.
:p.Craps is played by betting on the outcome of the rolling of two dice.  In
order to properly understand and participate in the game of craps, it is
important to know the possible outcomes when two dice are thrown.  There are
eleven possible outcomes in a roll of two dice (2, 3, 4, 5, 6, 7, 8, 9, 10,
11, and 12).  Certain numbers are more likely to be rolled than others.  The
chances of rolling a particular number are as follows:
:table cols='10 10'.
:row.
:c.Number
:c.Chance
:row.
:c.2 or 12
:c.1/36
:row.
:c.3 or 11
:c.2/36
:row.
:c.4 or 10
:c.3/36
:row.
:c.5 or 9
:c.4/36
:row.
:c.6 or 8
:c.5/36
:row.
:c.7
:c.6/36
:etable.
:p.Notice that the seven is the most common roll of all the possible rolls.
Notice, also, that there is a symmetry of combinations on either side of the
seven (ie.  the six and eight have the same odds, as do the four and ten).
The further a number is from seven, the less likely it will be rolled.  Based
on these chances of a number being rolled, the following odds can be derived:
:table cols='10 10'.
:row.
:c.Number
:c.Odds
:row.
:c.2 or 12
:c. 35 to 1
:row.
:c.3 or 11
:c. 17 to 1
:row.
:c.4 or 10
:c. 11 to 1
:row.
:c.5 or 9
:c.  8 to 1
:row.
:c.6 or 8
:c.6.2 to 1
:row.
:c.7
:c.  5 to 1
:etable.
:p.The casinos use these odds to their advantage in the game of craps.  When a
bet is won, it is typically paid off at an amount that is less than the true
odds of winning the bet.  All of the bets in the game favor the casino, or
house.  Some bets favor the house more than others.  The key to winning at the
game of craps is to play the bets that offer the lowest house advantage.
:p.Extensive help is available for every menu item and dialog box in the game.
The help information for each bet will contain the rules for that bet as well
as some recommended betting strategies.  All you need to do is select the
particular item that you want help for and press the F1 key.
:p.For more information on each of the menus on the action bar, double-click
on one of the following hilighted words (or press the Tab Key to select it and
press Enter).
:ul.
:li.:link reftype=hd res=1000.File:elink.
:li.:link reftype=hd res=2000.Bet:elink.
:li.:link reftype=hd res=3000.Options:elink.
:li.:link reftype=hd res=4000.Roll:elink.
:li.:link reftype=hd res=5000.Help:elink.
:eul.
 
.*************************************************************************
.* This is the help panel for the new dialog box
.*************************************************************************
:h1 res=11000.New Dialog - Help
:i2 refid=main.New Dialog
:p.The :hp2.New:ehp2. dialog is used to start a new game of craps.  It
contains the following items:
:dl tsize=2 break=all.
:dt.:hp2.How much:ehp2.
:dd.Enter the amount of money that you wish to borrow in order to begin
playing the game.  The money that you borrow is called a marker.  It will be
placed into your bank and you can then use it to bet with.  You will be
borrowing the money from :link reftype=hd res=30000.Guido:elink., the
casino's loan officer.  You can payoff your marker, or borrow more, at any
time, by selecting the
:link reftype=hd res=14000.Marker dialog:elink., located under
the :hp2.Options:ehp2. menu.
:dt.:hp2.OK:ehp2.
:dd.This button causes the current contents of the dialog to take effect.  The
dialog will then close and you may begin playing.
:dt.:hp2.Cancel:ehp2.
:dd.This button will close the dialog and ignore any changes that were made.
:dt.:hp2.Help:ehp2.
:dd.This button (or F1) causes this help information to be displayed.
:edl.
 
.*************************************************************************
.* This is the help panel for the product information dialog box
.*************************************************************************
:h1 res=12000.Product Information Dialog - Help
:i2 refid=main.Product Information Dialog
:p.The :hp2.Product information:ehp2. dialog displays copyright, author, and
version information for the :hp8.Las Vegas Craps:ehp8. game.
 
.*************************************************************************
.* This is the help panel for the settings dialog box
.*************************************************************************
:h1 res=13000.Settings Dialog - Help
:i2 refid=main.Settings Dialog
:p.The :hp2.Settings:ehp2. dialog allows you to make changes to some of the
:hp8.Las Vegas Craps:ehp8. game variables.
:dl tsize=2 break=all.
:dt.:hp2.Minimum bet:ehp2.
:dd.Allows you to set the table's minimum bet.  If you then attempt to place a
bet that is less than the minimum bet, a message will appear telling you why
you cannot place the bet.
:dt.:hp2.Maximum bet:ehp2.
:dd.Allows you to set the table's maximum bet.  If you then attempt to place a
bet that is greater than the maximum bet, a message will appear telling you
why you cannot place the bet.
:dt.:hp2.Default bet:ehp2.
:dd.Allows you to set the table's default bet.  The default bet amount is used
when placing any new bet, or when changing your
:link refid=marker reftype=fn.marker:elink..  The amount entered here will
appear automatically in the entry fields of the bet or marker dialog.  You
may choose to accept the amount, or change it.  The default bet must be less
than the maximum bet and greater than the minimum bet.
:dt.:hp2.Odds:ehp2.
:dd.Allows you to set the table's maximum allowable
:link reftype=hd res=30010.odds:elink..  The value you select here is the
multiple which will be used to calculate the maximum allowable odds.
:dt.:hp2.All bets ON during come out roll:ehp2.
:dd.This is used to determine whether or not you wish to have all bets ON
during the :link refid=comeout reftype=fn.come out roll:elink..  If a bet is
ON, it is considered in play.  If a bet is OFF, it is out of play.  A bet that
is in play can be won or lost.  A bet that is out of play cannot.  Certain
bets in the craps game are normally OFF during a come out roll unless you tell
the table operators that you wish the bets to be ON.  Checking this box turns
all bets ON during a come out roll.
:dt.:hp2.Automatically calculate maximum odds:ehp2.
:dd.This is used to determine whether or not you wish to have the game
automatically calculate the maximum allowable odds for a given bet.  If you
allow the game to calculate the maximum odds, the value will be placed into
the odds entry field as the default odds.  If you do not allow the game to
calculate the maximum allowable odds, the default bet will be used in the odds
entry field as the default odds.  You may choose to accept the amount, or
change it.  Checking this box turns on the automatic calculation of maximum
odds.
:dt.:hp2.Guido extracts money for marker payoff:ehp2.
:dd.This is used to determine whether of not
:link reftype=hd res=30000.Guido:elink.  should periodically take money from
your bank in order to pay off your marker.  Checking this box will allow Guido
to extract money for marker payoff.
:dt.:hp2.OK:ehp2.
:dd.This button causes the current contents of the dialog to take effect.  The
dialog will then close and you may begin playing.
:dt.:hp2.Cancel:ehp2.
:dd.This button will close the dialog and ignore any changes that were made.
:dt.:hp2.Defaults:ehp2.
:dd.This button will set all of the fields in the dialog to their default
settings.  These default settings will not actually take effect until you also
choose the OK button.
:dt.:hp2.Help:ehp2.
:dd.This button (or F1) causes this help information to be displayed.
:edl.
 
.*************************************************************************
.* This is the help panel for the marker dialog box
.*************************************************************************
:h1 res=14000.Marker Dialog - Help
:i2 refid=main.Marker Dialog
:p.The :hp2.Marker:ehp2. dialog allows you to make changes to your
:link refid=marker reftype=fn.marker:elink..  You can either borrow more
money, or pay back some of your current marker.  Your marker is held by
:link reftype=hd res=30000.Guido:elink., the casino's loan officer.
:p.Your current marker and bank account are displayed at the top of the
dialog.  When you pay back part of you marker, the money comes out of your
bank and your marker decreases.  When you borrow more, the money is added to
your bank and your marker increases.
:dl tsize=2 break=all.
:dt.:hp2.Pay back:ehp2.
:dd.Select this button if you want to pay back money.
:dt.:hp2.Borrow more:ehp2.
:dd.Select this button if you want to borrow more money.
:dt.:hp2.How much:ehp2.
:dd.Enter the amount that you wish to pay back or borrow.  The value that is
entered in the default bet field of the
:link reftype=hd res=13000.Settings dialog:elink. will be
automatically placed in the entry field.  You may choose to accept this
amount, or change it.  If you attempt to borrow more than the maximum
allowable marker, or try to pay back more than you have in your bank, a
message will appear telling you why you cannot make the change.
:dt.:hp2.OK:ehp2.
:dd.This button causes the current contents of the dialog to take effect.  The
dialog will then close and you may begin playing.
:dt.:hp2.Cancel:ehp2.
:dd.This button will close the dialog and ignore any changes that were made.
:dt.:hp2.Help:ehp2.
:dd.This button (or F1) causes this help information to be displayed.
:edl.
 
.*************************************************************************
.* This is the help panel for the bet dialog box
.*************************************************************************
:h1 res=15000.Bet Dialog - Help
:i2 refid=main.Bet Dialog
:p.The :hp2.Bet:ehp2. dialog is used to place the various bets in the
:hp8.Las Vegas Craps:ehp8. game.
:p.Your current bank account is displayed at the top of the dialog.  When you
place a bet, the money comes out of your bank.
:dl tsize=2 break=all.
:dt.:hp2.Bet:ehp2.
:dd.This field is used to either enter a new bet, or change an existing bet.
If the :link reftype=hd res=30020.rules:elink. of a bet do not allow it
to be changed, the bet field will not be selectable.  On a new bet, your
entire bank, or the value that is entered in the default bet field of the
:link reftype=hd res=13000.Settings dialog:elink., (whichever
is smaller) will be automatically placed in the entry field.  You may choose to
accept this amount, or change it.  If you attempt to bet more than the maximum
bet, less than the minimum bet, or more than you have in your bank, a message
will appear telling you why you cannot place the bet.
:dt.:hp2.Odds:ehp2.
:dd.This field is used to either enter new
:link reftype=hd res=30010.odds:elink., or change existing odds.  Odds are
only valid on certain bets and at certain points in the game.  If Odds are not
valid, or they cannot be changed, the odds field will not be selectable.  On
new odds, your entire bank, or the maximum allowable odds for the bet,
(whichever is smaller) will be automatically placed in the entry field.  If you
have turned off the automatic calculation of maximum odds, from within the
:link reftype=hd res=13000.Settings dialog:elink., then the
smaller of your bank and the value that is entered in the default bet field of
the Settings dialog will be automatically placed in the field.  You may choose
to accept this amount, or change it.  If you attempt to bet more than the
maximum bet, less than the minimum bet, or more than you have in your bank, a
message will appear telling you why you cannot place the odds.
:dt.:hp2.OK:ehp2.
:dd.This button causes the current contents of the dialog to take effect.  The
dialog will then close and you may begin playing.
:dt.:hp2.Cancel:ehp2.
:dd.This button will close the dialog and ignore any changes that were made.
:dt.:hp2.Help:ehp2.
:dd.This button (or F1) causes this help information to be displayed.
:edl.
:note.The maximum bet and the minimum bet can be set from within the
:link reftype=hd res=13000.Settings dialog:elink..
 
.*************************************************************************
.* This is the file pull down help panel
.*************************************************************************
:h1 res=1000.File Menu - Help
:i2 refid=main.File Menu
:p.The following commands are available from the :hp2.File:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=1100.New:elink.
:dd.Starts a new game.
:edl.
 
.*************************************************************************
.* This is the help panel for the new choice on the file menu
.*************************************************************************
:h1 res=1100.New - Help
:i2 refid=main.New
:p.The :hp2.New:ehp2. command displays the
:link reftype=hd res=11000.New dialog:elink., and allows you to begin
a new game.  :hp2.New:ehp2. must be chosen before the game can be played.
 
.*************************************************************************
.* This is the bet pull down help panel
.*************************************************************************
:h1 res=2000.Bet Menu - Help
:i2 refid=main.Bet Menu
:p.The following commands are available from the :hp2.Bet:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=2100.Line:elink.
:dd.Commands for placing line bets.
:dt.:link reftype=hd res=2200.Place:elink.
:dd.Commands for placing Place bets.
:dt.:link reftype=hd res=2300.Proposition:elink.
:dd.Commands for placing Proposition bets.
:dt.:link reftype=hd res=2400.Hardways:elink.
:dd.Commands for placing Hardways bets.
:dt.:link reftype=hd res=2500.Big six:elink.
:dd.Places the :hp2.Big six:ehp2. bet.
:dt.:link reftype=hd res=2600.Big eight:elink.
:dd.Places the :hp2.Big eight:ehp2. bet.
:dt.:link reftype=hd res=2700.Field:elink.
:dd.Places the :hp2.Field:ehp2. bet.
:edl.
 
.*************************************************************************
.* This is the help panel for the line choice on the bet menu
.*************************************************************************
:h1 res=2100.Line - Help
:i2 refid=main.Line
:p.The following commands are available from the :hp2.Line:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=2110.Pass line:elink.
:dd.Places a :hp2.Pass Line:ehp2. bet.
:dt.:link reftype=hd res=2120.Don't pass:elink.
:dd.Places a :hp2.Don't Pass:ehp2. bet.
:dt.:link reftype=hd res=2130.Come line:elink.
:dd.Places a :hp2.Come Line:ehp2. bet.
:dt.:link reftype=hd res=2140.Don't come:elink.
:dd.Places a :hp2.Don't Come:ehp2. bet.
:edl.
 
.*************************************************************************
.* This is the help panel for the pass choice on the bet menu
.*************************************************************************
:h1 res=2110.Pass line - Help
:p.The :hp2.Pass line:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to
place a :link reftype=hd res=30030.Pass Line bet:elink..
 
.*************************************************************************
.* This is the help panel for the don't pass choice on the bet menu
.*************************************************************************
:h1 res=2120.Don't Pass - Help
:i2 refid=main.Don't Pass
:p.The :hp2.Don't pass:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30031.Don't Pass bet:elink..
 
.*************************************************************************
.* This is the help panel for the come choice on the bet menu
.*************************************************************************
:h1 res=2130.Come line - Help
:i2 refid=main.Come line
:p.The :hp2.Come line:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30032.Come Line bet:elink..
 
.*************************************************************************
.* This is the help panel for the don't come choice on the bet menu
.*************************************************************************
:h1 res=2140.Don't Come - Help
:i2 refid=main.Don't Come
:p.The :hp2.Don't come:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30033.Don't Come bet:elink..
 
.*************************************************************************
.* This is the help panel for the place choice on the bet menu
.*************************************************************************
:h1 res=2200.Place - Help
:i2 refid=main.Place
:p.The following commands are available from the :hp2.Place:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=2210.Place four:elink.
:dd.Places a :hp2.Place Four:ehp2. bet.
:dt.:link reftype=hd res=2220.Place five:elink.
:dd.Places a :hp2.Place Five:ehp2. bet.
:dt.:link reftype=hd res=2230.Place six:elink.
:dd.Places a :hp2.Place Six:ehp2. bet.
:dt.:link reftype=hd res=2240.Place eight:elink.
:dd.Places a :hp2.Place Eight:ehp2. bet.
:dt.:link reftype=hd res=2250.Place nine:elink.
:dd.Places a :hp2.Place Nine:ehp2. bet.
:dt.:link reftype=hd res=2260.Place ten:elink.
:dd.Places a :hp2.Place Ten:ehp2. bet.
:edl.
 
.*************************************************************************
.* This is the help panel for the place four choice on the bet menu
.*************************************************************************
:h1 res=2210.Place four - Help
:i2 refid=main.Place four
:p.The :hp2.Place four:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30034.Place Four bet:elink..
 
.*************************************************************************
.* This is the help panel for the place five choice on the bet menu
.*************************************************************************
:h1 res=2220.Place five - Help
:i2 refid=main.Place five
:p.The :hp2.Place five:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30035.Place Five bet:elink..
 
.*************************************************************************
.* This is the help panel for the place six choice on the bet menu
.*************************************************************************
:h1 res=2230.Place six - Help
:i2 refid=main.Place six
:p.The :hp2.Place six:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30036.Place Six bet:elink..
 
.*************************************************************************
.* This is the help panel for the place eight choice on the bet menu
.*************************************************************************
:h1 res=2240.Place eight - Help
:i2 refid=main.Place eight
:p.The :hp2.Place eight:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30037.Place Eight bet:elink..
 
.*************************************************************************
.* This is the help panel for the place nine choice on the bet menu
.*************************************************************************
:h1 res=2250.Place nine - Help
:i2 refid=main.Place nine
:p.The :hp2.Place nine:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30038.Place Nine bet:elink..
 
.*************************************************************************
.* This is the help panel for the place ten choice on the bet menu
.*************************************************************************
:h1 res=2260.Place ten - Help
:i2 refid=main.Place ten
:p.The :hp2.Place ten:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30039.Place Ten bet:elink..
 
.*************************************************************************
.* This is the help panel for the proposition choice on the bet menu
.*************************************************************************
:h1 res=2300.Proposition - Help
:i2 refid=main.Proposition
:p.The following commands are available from the :hp2.Proposition:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=2310.Any seven:elink.
:dd.Places an :hp2.Any Seven:ehp2. bet.
:dt.:link reftype=hd res=2320.Any craps:elink.
:dd.Places an :hp2.Any Craps:ehp2. bet.
:dt.:link reftype=hd res=2340.Two:elink.
:dd.Places a :hp2.Two:ehp2. bet.
:dt.:link reftype=hd res=2330.Three:elink.
:dd.Places a :hp2.Three:ehp2. bet.
:dt.:link reftype=hd res=2360.Eleven:elink.
:dd.Places an :hp2.Eleven:ehp2. bet.
:dt.:link reftype=hd res=2350.Twelve:elink.
:dd.Places a :hp2.Twelve:ehp2. bet.
:edl.
 
.*************************************************************************
.* This is the help panel for the any seven choice on the bet menu
.*************************************************************************
:h1 res=2310.Any seven - Help
:i2 refid=main.Any seven
:p.The :hp2.Any seven:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
an :link reftype=hd res=30040.Any Seven bet:elink..
 
.*************************************************************************
.* This is the help panel for the any craps choice on the bet menu
.*************************************************************************
:h1 res=2320.Any craps - Help
:i2 refid=main.Any craps
:p.The :hp2.Any craps:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
an :link reftype=hd res=30041.Any Craps bet:elink..
 
.*************************************************************************
.* This is the help panel for the two the bet menu
.*************************************************************************
:h1 res=2340.Two - Help
:i2 refid=main.Two
:p.The :hp2.Two:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30042.Two bet:elink..
 
.*************************************************************************
.* This is the help panel for the three choice on the bet menu
.*************************************************************************
:h1 res=2330.Three - Help
:i2 refid=main.Three
:p.The :hp2.Three:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30043.Three bet:elink..
 
.*************************************************************************
.* This is the help panel for the eleven choice on the bet menu
.*************************************************************************
:h1 res=2360.Eleven - Help
:i2 refid=main.Eleven
:p.The :hp2.Eleven:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
an :link reftype=hd res=30044.Eleven bet:elink..
 
.*************************************************************************
.* This is the help panel for the twelve choice on the bet menu
.*************************************************************************
:h1 res=2350.Twelve - Help
:i2 refid=main.Twelve
:p.The :hp2.Twelve:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30045.Twelve bet:elink..
 
.*************************************************************************
.* This is the help panel for the hardways choice on the bet menu
.*************************************************************************
:h1 res=2400.Hardways - Help
:i2 refid=main.Hardways
:p.The following commands are available from the :hp2.Hardways:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=2440.Hard four:elink.
:dd.Places a :hp2.Hard Four:ehp2. bet.
:dt.:link reftype=hd res=2410.Hard six:elink.
:dd.Places a :hp2.Hard Six:ehp2. bet.
:dt.:link reftype=hd res=2430.Hard eight:elink.
:dd.Places a :hp2.Hard Eight:ehp2. bet.
:dt.:link reftype=hd res=2420.Hard ten:elink.
:dd.Places a :hp2.Hard Ten:ehp2. bet.
:edl.
 
.*************************************************************************
.* This is the help panel for the hard four choice on the bet menu
.*************************************************************************
:h1 res=2440.Hard four - Help
:i2 refid=main.Hard four
:p.The :hp2.Hard four:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30046.Hard Four bet:elink..
 
.*************************************************************************
.* This is the help panel for the hard six choice on the bet menu
.*************************************************************************
:h1 res=2410.Hard six - Help
:i2 refid=main.Hard six
:p.The :hp2.Hard six:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30047.Hard Six bet:elink..
 
.*************************************************************************
.* This is the help panel for the hard eight choice on the bet menu
.*************************************************************************
:h1 res=2430.Hard eight - Help
:i2 refid=main.Hard eight
:p.The :hp2.Hard eight:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30048.Hard Eight bet:elink..
 
.*************************************************************************
.* This is the help panel for the hard ten choice on the bet menu
.*************************************************************************
:h1 res=2420.Hard ten - Help
:i2 refid=main.Hard ten
:p.The :hp2.Hard ten:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30049.Hard Ten bet:elink..
 
.*************************************************************************
.* This is the help panel for the big six choice on the bet menu
.*************************************************************************
:h1 res=2500.Big six - Help
:i2 refid=main.Big six
:p.The :hp2.Big six:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30050.Big Six bet:elink..
 
.*************************************************************************
.* This is the help panel for the big eight choice on the bet menu
.*************************************************************************
:h1 res=2600.Big eight - Help
:i2 refid=main.Big eight
:p.The :hp2.Big eight:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30051.Big Eight bet:elink..
 
.*************************************************************************
.* This is the help panel for the field choice on the bet menu
.*************************************************************************
:h1 res=2700.Field - Help
:i2 refid=main.Field
:p.The :hp2.Field:ehp2. command displays the
:link reftype=hd res=15000.Bet dialog:elink., and allows you to place
a :link reftype=hd res=30052.Field bet:elink..
 
.*************************************************************************
.* This is the roll pull down help panel
.*************************************************************************
:h1 res=3000.Roll Menu - Help
:i2 refid=main.Roll Menu
:p.The following commands are available from the :hp2.Roll:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=3100.Roll:elink.
:dd.Rolls the dice.
:edl.
 
.*************************************************************************
.* This is the help panel for the roll choice on the roll menu
.*************************************************************************
:h1 res=3100.Roll - Help
:i2 refid=main.Roll
:p.The :hp2.Roll:ehp2. command causes the dice to be rolled.  After the dice
are rolled, each bet you have placed will be checked to see if it is a winner,
or loser.  When a bet is won or lost, a message will display which states how
much was won or lost.
:p.The dice can only be rolled if there is at least one bet down.
 
.*************************************************************************
.* This is the options pull down help panel
.*************************************************************************
:h1 res=4000.Options Menu - Help
:i2 refid=main.Options Menu
:p.The following commands are available from the :hp2.Options:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=4100.Marker:elink.
:dd.For paying off your debt or, borrowing more.
:dt.:link reftype=hd res=4200.Settings:elink.
:dd.For changing various user settings.
:edl.
 
.*************************************************************************
.* This is the help panel for the marker choice on the options menu
.*************************************************************************
:h1 res=4100.Marker - Help
:i2 refid=main.Marker
:p.The :hp2.Marker:ehp2. command displays the
:link reftype=hd res=14000.Marker dialog:elink., and allows you to
change (increase or decrease) your
:link refid=marker reftype=fn.marker:elink..
 
.*************************************************************************
.* This is the help panel for the settings choice on the options menu
.*************************************************************************
:h1 res=4200.Settings - Help
:i2 refid=main.Settings
:p.The :hp2.Settings:ehp2. command displays the
:link reftype=hd res=13000.Settings dialog:elink., and allows you
to change the game's settings.
 
.*************************************************************************
.* This is the Help pull down help panel
.*************************************************************************
:h1 res=5000.Help Menu - Help
:i2 refid=main.Help Menu
:p.The following commands are available from the :hp2.Help:ehp2. menu:
:dl break=all tsize=2.
:dt.:link reftype=hd res=16000.Help index:elink.
:dd.Displays an index of help topics.
:dt.:link reftype=hd res=17000.General help:elink.
:dd.Displays general help for :hp8.Las Vegas Craps:ehp8..
:dt.:link reftype=hd res=5300.Using help:elink.
:dd.Displays help on using the help facility.
:dt.:link reftype=hd res=5400.Product information:elink.
:dd.Displays the product information for :hp8.Las Vegas Craps:ehp8..
:edl.
 
.*************************************************************************
.* This is the help panel for the help index choice on the help menu
.*************************************************************************
:h1 res=16000.Help index - Help
:i2 refid=main.Help index
:p.The :hp2.Help index:ehp2. command will display an index of topics for the
:hp8.Las Vegas Craps:ehp8. game.
 
.*************************************************************************
.* This is the help panel for the general help choice on the help menu
.*************************************************************************
:h1 res=17000.General help - Help
:i2 refid=main.General help
:p.The :hp2.General help:ehp2. command will display general help on using the
:hp8.Las Vegas Craps:ehp8. game.
 
.*************************************************************************
.* This is the help panel for the using help choice on the help menu
.*************************************************************************
:h1 res=5300.Using help - Help
:i2 refid=main.Using help
:p.The :hp2.Using help:ehp2. command will display information on how to use
the help facility provided with the :hp8.Las Vegas Craps:ehp8. game.
 
.*************************************************************************
.* This is the help panel for the product information choice on the help
.* menu
.*************************************************************************
:h1 res=5400.Product information - Help
:i2 refid=main.Product information
:p.The :hp2.Product information:ehp2. command will display the
:link reftype=hd res=12000.Product information dialog:elink..
 
.*************************************************************************
.* This is the help panel for Guido the house loan officer
.*************************************************************************
:h1 res=30000.Guido - Help
:i2 refid=main.Guido
:p.:hp2.Guido:ehp2. is the casino's loan officer.  Guido, will be more
than happy to loan you money in order to play the game.  However, Guido is a
nervous man and will occasionally take some of your winnings to make sure
that your :link reftype=fn refid=marker.marker:elink. is eventually paid off.
:p.Two conditions must exist before Guido will take any of your money:
:ul.
:li.You must have won money on the last roll of the dice.
:li.Your bank must be larger than your marker.
:eul.
:p.Guido will never take more money than the amount you won on the last roll
of the dice.
:p.If you do not want Guido to take any of your money, you can turn the
feature off by using the
:link reftype=hd res=13000.Settings dialog:elink. located under
the :hp2.Options:ehp2. menu.
 
.*************************************************************************
.* This is the help panel for bet rules
.*************************************************************************
:h1 res=30020.Bet Rules - Help
:i2 refid=main.Bet Rules
:p.Select the particular bet that you would like more information on:
:ul compact.
:li.:link reftype=hd res=30030.Pass Line:elink.
:li.:link reftype=hd res=30031.Don't Pass:elink.
:li.:link reftype=hd res=30032.Come:elink.
:li.:link reftype=hd res=30033.Don't Come:elink.
:li.:link reftype=hd res=30010.Odds:elink.
:li.:link reftype=hd res=30034.Place Four:elink.
:li.:link reftype=hd res=30035.Place Five:elink.
:li.:link reftype=hd res=30036.Place Six:elink.
:li.:link reftype=hd res=30037.Place Eight:elink.
:li.:link reftype=hd res=30038.Place Nine:elink.
:li.:link reftype=hd res=30039.Place Ten:elink.
:li.:link reftype=hd res=30040.Any Seven:elink.
:li.:link reftype=hd res=30041.Any Craps:elink.
:li.:link reftype=hd res=30042.Two:elink.
:li.:link reftype=hd res=30043.Three:elink.
:li.:link reftype=hd res=30044.Eleven:elink.
:li.:link reftype=hd res=30045.Twelve:elink.
:li.:link reftype=hd res=30046.Hard Four:elink.
:li.:link reftype=hd res=30047.Hard Six:elink.
:li.:link reftype=hd res=30048.Hard Eight:elink.
:li.:link reftype=hd res=30049.Hard Ten:elink.
:li.:link reftype=hd res=30050.Big Six:elink.
:li.:link reftype=hd res=30051.Big Eight:elink.
:li.:link reftype=hd res=30052.Field:elink.
:eul.
 
.*************************************************************************
.* These are the Pass Line rules
.*************************************************************************
:h2 res=30030.Pass Line Rules - Help
:i2 refid=main.Pass Line Rules
:p.The :hp2.Pass Line:ehp2. bet is one of four bets known as line bets.  The
object of the Pass Line bet changes after the first roll of the dice.  The
first roll of the dice, after placing this bet, is referred to as the
:link refid=comeout reftype=fn.come out:elink. roll.  The object of the Pass
Line bet, on the come out roll, is to roll a seven or an eleven.  If you roll
a seven or eleven, you win.  If you roll a two, three, or twelve, you lose.
If any other number is rolled, that number becomes the
:link refid=point reftype=fn.point number:elink..  A place marker will then be
placed, on the table, over the number that corresponds to the point number.
:p.Once a point number is established, the object of the Pass Line bet is to
roll the point number before rolling a seven. If you roll the point number
first, you win.  If you roll a seven first, you lose.  If any other number is
rolled, it has no effect on this bet.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can only be made before a point number is established.  You must
have enough money in your bank to place the minimum bet.  The minimum bet is
set in the :link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed anytime before the point number is
established.  Once the point number has been established, the original bet can
no longer be changed or removed.  Once the point number has been established, a
Pass Line bet can be enhanced with an :link reftype=hd res=30010.odds:elink.
bet.  The odds bet is really a separate bet and it can be changed or removed at
any time.  Odds can only be placed after the point number is established.
:dt.:hp2.Odds of winning:ehp2.
:dd.The Pass Line bet has different odds of winning, depending on what the
point number is.  The following table gives the odds of winning for each
possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds of Winning
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:dt.:hp2.Payoff if won:ehp2.
:dd.The original Pass Line bet is paid off at even money regardless of the
point number.  If Odds were taken on the bet, the odds are paid off according
to the point number.  The following table gives the odds payoff for each
possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds Payoff
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:note.The odds of winning and the payoff are identical on the odds bet.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.4% advantage on a Pass Line bet with no odds.  This is
one of the lowest house advantages in the game.  Because the  house has no
advantage at all on the odds bet, if you back the Pass Line bet with odds, the
house advantage on the total bet drops to 0.8% with single odds and further to
0.6% when playing double odds.  As you can see, the house advantage drops
significantly when playing odds.  Also, the more odds that are taken, the lower
the house advantage drops.  Therefore, when playing the Pass Line, always bet
the maximum allowable odds.  When betting a sum of money on the Pass Line,
always put as much of that sum as possible on the odds.  Line bets backed by
odds are the best bets in the game.
:edl.
 
.*************************************************************************
.* These are the Don't Pass rules
.*************************************************************************
:h2 res=30031.Don't Pass Rules - Help
:i2 refid=main.Don't Pass Rules
:p.The :hp2.Don't Pass:ehp2. bet is one of four bets known as line bets.  The
object of the Don't Pass bet changes after the first roll of the dice.  The
first roll of the dice, after placing this bet, is referred to as the
:link refid=comeout reftype=fn.come out:elink.  roll.  The object of the Don't
Pass bet, on the come out roll, is to roll a two or a three.  If you roll a two
or three, you win.  If you roll a seven or eleven, you lose.  A roll of twelve
is considered a standoff, or push.  If any other number is rolled, that number
becomes the
:link refid=point reftype=fn.point number:elink..  A place marker will then be
placed, on the table, over the number that corresponds to the point number.
:p.Once a point number is established, the object of the Don't Pass bet is to
roll a seven before rolling the point number.  If you roll a seven first, you
win.  If you roll the point number first, you lose.  If any other number is
rolled, it has no effect on this bet.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can only be made before a point number is established.  You must
have enough money in your bank to place the minimum bet.  The minimum bet is
set in the :link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed anytime before the point number is
established.  Once the point number has been established, the original bet can
no longer be changed or removed.  Once the point number has been established, a
Don't Pass bet can be enhanced with an :link reftype=hd res=30010.odds:elink.
bet.  The odds bet is really a separate bet and it can be changed or removed at
any time.  Odds can only be placed after the point number is established.
:dt.:hp2.Odds of winning:ehp2.
:dd.The Don't Pass bet has different odds of winning, depending on what the
point number is.  The following table gives the odds of winning for each
possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds of Winning
:row.
:c.4 or 10
:c.1 to 2
:row.
:c.5 or 9
:c.2 to 3
:row.
:c.6 or 8
:c.5 to 6
:etable.
:dt.:hp2.Payoff if won:ehp2.
:dd.The original Don't Pass bet is paid off at even money regardless of the
point number.  If Odds were taken on the bet, the odds are paid off according
to the point number.  The following table gives the odds payoff for each
possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds Payoff
:row.
:c.4 or 10
:c.1 to 2
:row.
:c.5 or 9
:c.2 to 3
:row.
:c.6 or 8
:c.5 to 6
:etable.
:note.The odds of winning and the payoff are identical on the odds bet.  Also,
note that you will be paid off less than the actual bet.  This is because the
odds are actually in your favor on the Don't Pass bet.  This serves to even it
up for the house.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.4% advantage on a Don't Pass bet with no odds.  This is
one of the lowest house advantages in the game.  Because the house has no
advantage at all on the odds bet, if you back the Don't Pass bet with odds, the
house advantage on the total bet drops to 0.8% with single odds and further to
0.6% when playing double odds.  As you can see, the house advantage drops
significantly when playing odds.  Also, the more odds that are taken, the lower
the house advantage drops.  Therefore, when playing the Don't Pass, always bet
the maximum allowable odds.  When betting a sum of money on the Don't Pass,
always put as much of that sum as possible on the odds.  Line bets backed by
odds are the best bets in the game.
:edl.
 
.*************************************************************************
.* These are the Come Line rules
.*************************************************************************
:h2 res=30032.Come Line Rules - Help
:i2 refid=main.Come Line Rules
:p.The :hp2.Come Line:ehp2. bet is one of four bets known as line bets.  The
object of the Come Line bet changes after the first roll of the dice.  The
object of the Come Line bet, on the first out roll, is to roll a seven or an
eleven.  If you roll a seven or eleven, you win.  If you roll a two, three,
or twelve, you lose.  If any other number is rolled, that number becomes the
:link refid=point reftype=fn.come point number:elink..  Your bet will then be
placed, on the table, over the number that corresponds to the come point
number.
:p.Once a come point number is established, the object of the Come Line bet is to
roll the come point number before rolling a seven. If you roll the come point number
first, you win.  If you roll a seven first, you lose.  If any other number is
rolled, it has no effect on this bet.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can only be made before a come point number is established.  In
addition, you must have already placed either a
:link reftype=hd res=30030.Pass Line:elink. or a
:link reftype=hd res=30031.Don't Pass:elink. bet and have a point
number established.  You must have enough money in your bank to place the
minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed anytime before the come point number is
established.  Once the come point number has been established, the original bet can
no longer be changed or removed.  Once the come point number has been established, a
Come Line bet can be enhanced with an :link reftype=hd res=30010.odds:elink.
bet.  The odds bet is really a separate bet and it can be changed or removed at
any time.  Odds can only be placed after the come point number is established.
:dt.:hp2.Odds of winning:ehp2.
:dd.The Come Line bet has different odds of winning, depending on what the
come point number is.  The following table gives the odds of winning for each
possible come point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds of Winning
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:dt.:hp2.Payoff if won:ehp2.
:dd.The original Come Line bet is paid off at even money regardless of the
come point number.  If Odds were taken on the bet, the odds are paid off according
to the come point number.  The following table gives the odds payoff for each
possible come point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds Payoff
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:note.The odds of winning and the payoff are identical on the odds bet.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.4% advantage on a Come Line bet with no odds.  This is
one of the lowest house advantages in the game.  Because the  house has no
advantage at all on the odds bet, if you back the Come Line bet with odds, the
house advantage on the total bet drops to 0.8% with single odds and further to
0.6% when playing double odds.  As you can see, the house advantage drops
significantly when playing odds.  Also, the more odds that are taken, the lower
the house advantage drops.  Therefore, when playing the Come Line, always bet
the maximum allowable odds.  When betting a sum of money on the Come Line,
always put as much of that sum as possible on the odds.  Line bets backed by
odds are the best bets in the game.
:edl.
 
.*************************************************************************
.* These are the Don't Come rules
.*************************************************************************
:h2 res=30033.Don't Come Rules - Help
:i2 refid=main.Don't Come Rules
:p.The :hp2.Don't Come:ehp2. bet is one of four bets known as line bets.  The
object of the Don't Come bet changes after the first roll of the dice.  The
object of the Don't Come bet, on the first roll, is to roll a two or a three.
If you roll a two or three, you win.  If you roll a seven or eleven, you lose.
A roll of twelve is considered a standoff, or push.  If any other number is
rolled, that number becomes the
:link refid=point reftype=fn.come point number:elink..  Your bet will then be
placed, on the table, over the number that corresponds to the come point
number.
:p.Once a come point number is established, the object of the Don't Come bet is to
roll a seven before rolling the come point number.  If you roll a seven first, you
win.  If you roll the come point number first, you lose.  If any other number is
rolled, it has no effect on this bet.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can only be made before a come point number is established.  In
addition, you must have already placed either a
:link reftype=hd res=30030.Pass Line:elink. or a
:link reftype=hd res=30031.Don't Pass:elink. bet and have a point
number established.  You must have enough money in your bank to place the
minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed anytime before the come point number is
established.  Once the come point number has been established, the original bet can
no longer be changed or removed.  Once the come point number has been established, a
Don't Come bet can be enhanced with an :link reftype=hd res=30010.odds:elink.
bet.  The odds bet is really a separate bet and it can be changed or removed at
any time.  Odds can only be placed after the come point number is established.
:dt.:hp2.Odds of winning:ehp2.
:dd.The Don't Come bet has different odds of winning, depending on what the
come point number is.  The following table gives the odds of winning for each
possible come point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds of Winning
:row.
:c.4 or 10
:c.1 to 2
:row.
:c.5 or 9
:c.2 to 3
:row.
:c.6 or 8
:c.5 to 6
:etable.
:dt.:hp2.Payoff if won:ehp2.
:dd.The original Don't Come bet is paid off at even money regardless of the
come point number.  If Odds were taken on the bet, the odds are paid off according
to the come point number.  The following table gives the odds payoff for each
possible come point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds Payoff
:row.
:c.4 or 10
:c.1 to 2
:row.
:c.5 or 9
:c.2 to 3
:row.
:c.6 or 8
:c.5 to 6
:etable.
:note.The odds of winning and the payoff are identical on the odds bet.  Also,
note that you will be paid off less than the actual bet.  This is because the
odds are actually in your favor on the Don't Come bet.  This serves to even it
up for the house.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.4% advantage on a Don't Come bet with no odds.  This is
one of the lowest house advantages in the game.  Because the house has no
advantage at all on the odds bet, if you back the Don't Come bet with odds, the
house advantage on the total bet drops to 0.8% with single odds and further to
0.6% when playing double odds.  As you can see, the house advantage drops
significantly when playing odds.  Also, the more odds that are taken, the lower
the house advantage drops.  Therefore, when playing the Don't Come, always bet
the maximum allowable odds.  When betting a sum of money on the Don't Come,
always put as much of that sum as possible on the odds.  Line bets backed by
odds are the best bets in the game.
:edl.
 
.*************************************************************************
.* These are the Place Four rules
.*************************************************************************
:h2 res=30034.Place Four Rules - Help
:i2 refid=main.Place Four Rules
:p.The object of the :hp2.Place Four:ehp2. bet is to roll a four before rolling
a seven.  If you roll the four first, you win.  If you roll a seven first, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet
is typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.2 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.9 to 5
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 6.67% advantage on this bet.  You can get better odds on
other bets.  To get the full payoff from the place bet, make your bets in the
proper multiples.  On a Place Four bet, you should bet in multiples of five.
:edl.
 
.*************************************************************************
.* These are the Place Five rules
.*************************************************************************
:h2 res=30035.Place Five Rules - Help
:i2 refid=main.Place Five Rules
:p.The object of the :hp2.Place Five:ehp2. bet is to roll a five before rolling
a seven.  If you roll the five first, you win.  If you roll a seven first, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet
is typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.3 to 2
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 5
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 4.00% advantage on this bet.  You can get better odds on
other bets.  To get the full payoff from the place bet, make your bets in the
proper multiples.  On a Place Five bet, you should bet in multiples of five.
:edl.
 
.*************************************************************************
.* These are the Place Six rules
.*************************************************************************
:h2 res=30036.Place Six Rules - Help
:i2 refid=main.Place Six Rules
:p.The object of the :hp2.Place Six:ehp2. bet is to roll a six before rolling
a seven.  If you roll the six first, you win.  If you roll a seven first, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet
is typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.6 to 5
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 6
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.52% advantage on this bet.  This is a relatively low
house advantage and can be played.  However, the
:link reftype=hd res=2100.line:elink. bets offer an even lower
house advantage.  To get the full payoff from the place bet, make your bets in
the proper multiples.  On a Place Six bet, you should bet in multiples of
six.
:edl.
 
.*************************************************************************
.* These are the Place Eight rules
.*************************************************************************
:h2 res=30037.Place Eight Rules - Help
:i2 refid=main.Place Eight Rules
:p.The object of the :hp2.Place Eight:ehp2.  bet is to roll an eight before
rolling a seven.  If you roll the eight first, you win.  If you roll a seven
first, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet is
typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.6 to 5
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 6
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 1.52% advantage on this bet.  This is a relatively low
house advantage and can be played.  However, the
:link reftype=hd res=2100.line:elink. bets offer an even lower
house advantage.  To get the full payoff from the place bet, make your bets in
the proper multiples.  On a Place Eight bet, you should bet in multiples of
six.
:edl.
 
.*************************************************************************
.* These are the Place Nine rules
.*************************************************************************
:h2 res=30038.Place Nine Rules - Help
:i2 refid=main.Place Nine Rules
:p.The object of the :hp2.Place Nine:ehp2. bet is to roll a nine before rolling
a seven.  If you roll the nine first, you win.  If you roll a seven first, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet
is typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.3 to 2
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 5
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 4.00% advantage on this bet.  You can get better odds on
other bets.  To get the full payoff from the place bet, make your bets in the
proper multiples.  On a Place Nine bet, you should bet in multiples of five.
:edl.
 
.*************************************************************************
.* These are the Place Ten rules
.*************************************************************************
:h2 res=30039.Place Ten Rules - Help
:i2 refid=main.Place Ten Rules
:p.The object of the :hp2.Place Ten:ehp2. bet is to roll a ten before rolling a
seven.  If you roll the ten first, you win.  If you roll a seven first, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..  A place bet
is typically not working, or is off on the
:link refid=comeout reftype=fn.come out roll:elink..  You can request that the
place bets be on (working) on the come out roll by checking the box in the
settings dialog.
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.2 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.9 to 5
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 6.67% advantage on this bet.  You can get better odds on
other bets.  To get the full payoff from the place bet, make your bets in the
proper multiples.  On a Place Ten bet, you should bet in multiples of five.
:edl.
 
.*************************************************************************
.* These are the Any Seven rules
.*************************************************************************
:h2 res=30040.Any Seven Rules - Help
:i2 refid=main.Any Seven Rules
:p.The object of the :hp2.Any Seven:ehp2. bet is to roll a seven on the next
roll of the dice.  If the next roll of the dice is a seven, you win.  If the
next roll of the dice is not a seven, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.5 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.4 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 16.67% advantage on this bet.  This is one of the worst
bets a player can make.
:edl.
 
.*************************************************************************
.* These are the Any Craps rules
.*************************************************************************
:h2 res=30041.Any Craps Rules - Help
:i2 refid=main.Any Craps Rules
:p.The object of the :hp2.Any Craps:ehp2. bet is to roll a
:link refid=craps reftype=fn.crap:elink. number on the next roll of the dice.
If the next roll of the dice is a crap number, you win.  If the next roll of
the dice is not a crap number, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.8 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has an 11.1% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Two rules
.*************************************************************************
:h2 res=30042.Two Rules - Help
:i2 refid=main.Two Rules
:p.The object of the :hp2.Two:ehp2. bet is to roll a two on the next
roll of the dice.  If the next roll of the dice is a two, you win.  If the
next roll of the dice is not a two, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.35 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.30 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 13.69% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Three rules
.*************************************************************************
:h2 res=30043.Three Rules - Help
:i2 refid=main.Three Rules
:p.The object of the :hp2.Three:ehp2. bet is to roll a three on the next
roll of the dice.  If the next roll of the dice is a three, you win.  If the
next roll of the dice is not a three, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.17 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.15 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has an 11.1% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Eleven rules
.*************************************************************************
:h2 res=30044.Eleven Rules - Help
:i2 refid=main.Eleven Rules
:p.The object of the :hp2.Eleven:ehp2. bet is to roll an eleven on the next
roll of the dice.  If the next roll of the dice is an eleven, you win.  If the
next roll of the dice is not an eleven, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.17 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.15 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has an 11.1% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Twelve rules
.*************************************************************************
:h2 res=30045.Twelve Rules - Help
:i2 refid=main.Twelve Rules
:p.The object of the :hp2.Twelve:ehp2. bet is to roll a twelve on the next
roll of the dice.  If the next roll of the dice is a twelve, you win.  If the
next roll of the dice is not a twelve, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.35 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.30 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 13.69% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Hard Four rules
.*************************************************************************
:h2 res=30046.Hard Four Rules - Help
:i2 refid=main.Hard Four Rules
:p.The object of the :hp2.Hard Four:ehp2. bet is to roll a hard four (double
twos), before rolling a seven or an easy four (any roll of four besides double
twos). If you roll a hard four first, you win.  If you roll a seven or an easy
four first, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.8 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has an 11.1% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Hard Six rules
.*************************************************************************
:h2 res=30047.Hard Six Rules - Help
:i2 refid=main.Hard Six Rules
:p.The object of the :hp2.Hard Six:ehp2. bet is to roll a hard six (double
threes), before rolling a seven or an easy six (any roll of six besides double
threes).  If you roll a hard six first, you win.  If you roll a seven or an
easy six first, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.10 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.9 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 9.09% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Hard Eight rules
.*************************************************************************
:h2 res=30048.Hard Eight Rules - Help
:i2 refid=main.Hard Eight Rules
:p.The object of the :hp2.Hard Eight:ehp2. bet is to roll a hard eight (double
fours), before rolling a seven or an easy eight (any roll of eight besides
double fours).  If you roll a hard eight first, you win.  If you roll a seven
or an easy eight first, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.10 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.9 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 9.09% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Hard Ten rules
.*************************************************************************
:h2 res=30049.Hard Ten Rules - Help
:i2 refid=main.Hard Ten Rules
:p.The object of the :hp2.Hard Ten:ehp2. bet is to roll a hard ten (double
fives), before rolling a seven or an easy ten (any roll of ten besides double
fives).  If you roll a hard ten first, you win.  If you roll a seven or an easy
ten first, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.8 to 1
:dt.:hp2.Payoff if won:ehp2.
:dd.7 to 1
:dt.:hp2.Recommendation:ehp2.
:dd.The house has an 11.1% advantage on this bet.  This is an extremely high
house advantage.  Don't make this bet.
:edl.
 
.*************************************************************************
.* These are the Big Six rules
.*************************************************************************
:h2 res=30050.Big Six Rules - Help
:i2 refid=main.Big Six Rules
:p.The object of the :hp2.Big Six:ehp2. is to roll a six before a seven is
rolled.  If you roll the six first, you win.  If the seven comes up, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.6 to 5
:dt.:hp2.Payoff if won:ehp2.
:dd.Even Money
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 9.09% advantage on this bet.  This is a very high house
advantage.  A :li.:link reftype=hd res=30036.Place Six:elink. bet
can achieve the same results at a better payoff.
:edl.
 
.*************************************************************************
.* These are the Big Eight rules
.*************************************************************************
:h2 res=30051.Big Eight Rules - Help
:i2 refid=main.Big Eight Rules
:p.The object of the :hp2.Big Eight:ehp2. is to roll an eight before a seven
is rolled.  If you roll the eight first, you win.  If the seven comes up, you
lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.6 to 5
:dt.:hp2.Payoff if won:ehp2.
:dd.Even Money
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 9.09% advantage on this bet.  This is a very high house
advantage.  A :li.:link reftype=hd res=30037.Place Eight:elink.
bet can achieve the same results at a better payoff.
:edl.
 
.*************************************************************************
.* These are the Field rules
.*************************************************************************
:h2 res=30052.Field Rules - Help
:i2 refid=main.Field Rules
:p.The object of the :hp2.Field:ehp2. bet is to roll one of the
:link refid=field reftype=fn.field:elink. numbers.  If the next roll of the
dice is a field number, you win.  If the next roll of the dice is not a field
number, you lose.
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can be placed at anytime, provided you have enough money in your
bank to place the minimum bet.  The minimum bet is set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.20 to 19
:dt.:hp2.Payoff if won:ehp2.
:dd.This bet is paid off at even money unless a two or twelve is rolled.  A two
is paid at 2 to 1.  A twelve is paid a 3 to 1.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has a 2.7% advantage on this bet.  While this house advantage is
not the highest, there are several bets in the game that offer a much lower
house advantage.  This bet should be avoided.
:edl.
 
.*************************************************************************
.* This is the help panel for odds
.*************************************************************************
:h2 res=30010.Free Odds - Help
:i2 refid=main.Free Odds
:p.A :hp2.Free Odds:ehp2. bet, or just :hp1.Odds:ehp1. bet, is an extension
to the line bets.  This bet must always back an existing line bet.  An Odds
bet can be placed for every existing line bet.  While the Free Odds bet looks
like a way to simply increase your line bet, it is much more than that.  The
Free Odds bet is paid of at the true odds.  Thus, the house gets no advantage
on this bet.  The Free Odds bet serves to lower the overall house advantage
on the line bets.
:p.The amount you are allowed to bet on a Free Odds bet is usually limited to
some multiple of the line bet that it backs.  The most common multiples are
:hp1.single odds:ehp1. and :hp1.double odds:ehp1..  In a single odds game,
the Free Odds bet can only be as large as the line bet that it backs.  When
playing double odds, the Free Odds bet can be up to two times the line bet.
The odds multiple can be set in the
:link reftype=hd res=13000.Settings dialog:elink..
:dl tsize=2 break=all.
:dt.:hp2.Place:ehp2.
:dd.This bet can only be made as a backing bet to one of the line bets.
Therefore, you must have already placed one of the line bets, and the
corresponding point number must be established.  You must have enough money in
your bank to place the minimum bet.  The minimum bet is set in the :link
reftype=hd res=13000.Settings dialog:elink..
:dt.:hp2.Change/Remove:ehp2.
:dd.This bet may be changed or removed at anytime.
:dt.:hp2.Odds of winning:ehp2.
:dd.The Free Odds bet has different odds of winning, depending on what the
point number is.  The following table gives the odds of winning for each
possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds of Winning
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:dt.:hp2.Payoff if won:ehp2.
:dd.The Free Odds bet is paid off according to the point number.  The
following table gives the odds payoff for each possible point number.
:table cols='10 10'.
:row.
:c.Point Number
:c.Odds Payoff
:row.
:c.4 or 10
:c.2 to 1
:row.
:c.5 or 9
:c.3 to 2
:row.
:c.6 or 8
:c.6 to 5
:etable.
:note.The odds of winning and the payoff are identical on the Free Odds bet.
:dt.:hp2.Recommendation:ehp2.
:dd.The house has no advantage at all on a Free Odds bet.  This makes the
Free Odds bet the best bet in the game.  The overall house advantage for
line bets decreases as more money is bet on the Free Odds backing the line
bet.  For this reason, line bets should always be backed with the maximum
allowable Free Odds bet.
:edl.
 
.*************************************************************************
.* This is the help panel for come out roll
.*************************************************************************
:fn id=comeout.
:p.A come out roll is the first roll of the dice after placing a
:hp2.Pass Line:ehp2. or a :hp2.Don't Pass:ehp2. bet.
:efn.
 
.*************************************************************************
.* This is the help panel for marker
.*************************************************************************
:fn id=marker.
:p.A marker is a loan of money which is provided by the casino.
:efn.
 
.*************************************************************************
.* This is the help panel for crap numbers
.*************************************************************************
:fn id=craps.
:p.A crap number is a 2, 3, or 12.
:efn.
 
.*************************************************************************
.* This is the help panel for field numbers
.*************************************************************************
:fn id=field.
:p.A field number is a 2, 3, 4, 9, 10, 11, or 12.
:efn.
 
.*************************************************************************
.* This is the help panel a point number
.*************************************************************************
:fn id=point.
:p.The point number is the number that will, along with a roll of seven, decide
the outcome of the line bets.
:efn.
 
:euserdoc.
