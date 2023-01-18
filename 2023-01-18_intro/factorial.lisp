#! /usr/local/bin/clisp
(defun factorial (n)
    (if (= n 0)
	1
	(* n (factorial (1- n)))))
(defun main ()
    (let ((n (read)))
      (print (factorial n))))

(main)
