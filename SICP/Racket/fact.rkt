; recursive solution

(define (fact n)
  (if (= n 0)
    1
    (* n (fact (- n 1)))))

; iterative solution

(define (fact n)
  (define (fact-iter acc n)
    (if (= n 0)
        acc
        (fact-iter (* n acc) (- n 1))))
  (fact-iter 1 n))

; Algerithms + threading
;(require threading)
;
;(define (fact n)
;  (~> (range 1 (+ n 1))
;      (foldl * 1 _)))
;
;(fact 10)
