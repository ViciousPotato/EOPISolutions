(defn parity1
  [x]
  (if (= x 0)
    0
    (bit-xor
     (bit-and x 1)
     (parity1 (bit-shift-right x 1)))))

(println (parity1 8))