(TeX-add-style-hook
 "equations"
 (lambda ()
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "amsmath"))
 :latex)

