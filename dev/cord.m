% simple stuff with cords to check out how Mercury compiles
% things
% Its a bit opaque due to use of macros everywhere. Possibly a
% bit simpler than what we will have because everything is a
% word in size, or multiple words, and indices are used to get
% offsets within chunks of memory, rather than using structs
% with fields.  Not clear how we can do it nicely if we run
% out of tag bits - want to avoid two levels of pointers, want
% to avoid unions (if sizes are significantly different) so we
% want tag + other fields, but access to tag must be uniform
% for all of the data constructors.  Maybe use sub-optimal
% soln - its not likely to come up often!

:- module cord.
:- interface.
:- import_module int.

:- type cord(T)
    --->    nil
    ;       leaf(T)
    ;       branch(cord(T), cord(T)).

:- pred n(cord(int)::out) is det.
:- pred l(int::in, cord(int)::out) is det.
:- pred b(cord(int)::in, cord(int)::in, cord(int)::out) is det.
:- pred d(cord(int)::in, int::out) is det.
:- implementation.

n(nil).

l(I, leaf(I)).

b(C1, C2, branch(C1, C2)).

d(nil, 42).
d(leaf(I), I).
d(branch(_, C2), I) :- d(C2, I).
