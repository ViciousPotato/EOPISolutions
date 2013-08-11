-module(parity).
-export([parity1/1]).

parity1(0) -> 0;
parity1(X) -> (X band 1) bxor parity1(X bsr 1).

main([String]) ->
	io:format("~B~n", parity1(8)).
