# Data Structures Using C
Repo for programming examples and exercises for the book "Data Structure Using C" by Reema Thareja (2nd Edition)
<hr>

![alt text](https://github.com/CDKelly/data_structures_using_C/blob/master/images/data_structures_using_c_book_image.jpeg)

ISBN-13: 978-0198099307<br>
ISBN-10: 0198099304

## Emacs Setup

_Major mode_: CC mode<br>
_Minor modes_: [Highlight-Indent-Guides](https://github.com/DarthFennec/highlight-indent-guides), [Electric-Pair](https://www.emacswiki.org/emacs/ElectricPair), [Show-Paren](https://www.emacswiki.org/emacs/ShowParenMode)
<br>
<br>
_Tabs_: [`infer-indentation-style`](https://www.emacswiki.org/emacs/NoTabs), [Smart-Tabs](https://www.emacswiki.org/emacs/SmartTabs)
```
;; turn off tabs globally
;; but activate if the file I'm in uses tabs
;; if so, then rely off smarts-tab-mode
(setq-default indent-tabs-mode nil)

;; infer indentation style of file
(defun infer-indentation-style ()
  ;; if our source file uses tabs, we use tabs, if spaces spaces, and if
  ;; neither, we use the current indent-tabs-mode
  (let ((space-count (how-many "^  " (point-min) (point-max)))
        (tab-count (how-many "^\t" (point-min) (point-max))))
    (if (> space-count tab-count) (setq indent-tabs-mode nil))
    (if (> tab-count space-count) (setq indent-tabs-mode t))))

;; smart-tabs-mode
(autoload 'smart-tabs-mode "smart-tabs-mode"
   "Intelligently indent with tabs, align with spaces!")
 (autoload 'smart-tabs-mode-enable "smart-tabs-mode")
 (autoload 'smart-tabs-advice "smart-tabs-mode")
(autoload 'smart-tabs-insinuate "smart-tabs-mode")
(smart-tabs-insinuate 'c 'c++ 'java 'javascript 'python
		      'ruby)

;; indent entire buffer
(defun indent-buffer ()
      (interactive)
      (save-excursion
        (indent-region (point-min) (point-max) nil)))
```

_Compilation_:
```
(defun my-compile-v1()
  (interactive)
  (let* ((c-file (buffer-file-name (current-buffer)))
        (c-file-basename (file-name-base c-file))
        (compile-string (concat "gcc " c-file " -o " c-file-basename " && ./" c-file-basename))
        )
    (compile compile-string t)
    (switch-to-buffer "*compilation*")))
    
(global-set-key (kbd "<f6>") 'my-compile-v1)
```
The above code just builds a string to send to the `compile` function and then switches to the `*compilation*` buffer, which is in Comint mode. Comint essentially makes the `*compilation*` buffer interactive, which can allow me to enter stdin and navigate to the `next-error` in my C code (if need be).
