//This file was generated from UPPAAL 4.0.6 (rev. 2987), March 2007

/*

*/
A[] not deadlock

/*

*/
E<> E.green

/*

*/
E<> W.green

/*

*/
E<> S.green

/*

*/
E<> N.green

/*

*/
E<> E.Wait_WE

/*

*/
E<> W.Wait_WE

/*

*/
E<> S.Wait_NS

/*

*/
E<> N.Wait_NS

/*

*/
W.car -->W.green

/*

*/
S.car -->S.green

/*

*/
A[] not ((N.green or S.green) and (W.green or E.green))
