#! /usr/bin/env racket
#lang racket

(define (factorial n)
  (if (zero? n)
      1
      (* n (factorial (sub1 n)))))

(define (main)
  (let ((n (string->number (read-line))))
    (display (factorial n))
    (newline)))

(main)
