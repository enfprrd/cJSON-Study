JSON: {"a":[1,2], "b":{"c":3}}

root(Object)
  child -> a(Array, key="a")
            child -> 1(Number)
                      next -> 2(Number)
                      prev <- 2(Number)
            next -> b(Object, key="b")
                      child -> c(Number=3, key="c")
