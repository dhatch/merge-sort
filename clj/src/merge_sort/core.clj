(ns merge-sort.core
  (:gen-class))

(defn seq-merge [left right]
  (loop [left left
         right right
         result (transient [])]
  (cond
    (and (empty? left) (empty? right)) result
    (empty? right) (recur (rest left) right (conj! result (first left)))
    (empty? left) (recur left (rest right) (conj! result (first right)))
    (< (first left) (first right))
      (recur (rest left) right (conj! result (first left)))
    :else
      (recur left (rest right) (conj! result (first right))))))

(defn msort [values]
  (let [split (/ (count values) 2)
        left (take split values)
        right (drop split values)]
    (if (and (<= (count left) 1) (<= (count right) 1))
      (seq-merge left right)
      (seq-merge (msort left) (msort right)))))

(defn to-int [values]
  (map #(Integer/parseInt %) values))

(defn -main
  [& args]
  (do
    (doseq [v (msort (to-int args))] (printf "%d " v))
    (printf "\n")))
