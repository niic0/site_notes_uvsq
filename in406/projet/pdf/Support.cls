\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{Support}
\LoadClass[twoside, a4paper, 12pt]{article}

\newcommand{\headlinecolor}{\normalcolor}
\renewcommand{\familydefault}{\sfdefault}


\DeclareOption{onecolumn}{\OptionNotUsed}
\DeclareOption{green}{\renewcommand{\headlinecolor}{\color{green}}}
\DeclareOption{red}{\renewcommand{\headlinecolor}{\color{slcolor}}}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions\relax


\usepackage[dvipsnames]{xcolor}
\usepackage{booktabs}
\usepackage{ marvosym }
\usepackage{amsmath}

\RequirePackage{tikz}
\RequirePackage{kantlipsum}
\RequirePackage{lipsum}
\RequirePackage{amsfonts, amssymb, bm}
\RequirePackage{setspace}
\RequirePackage{url}
\RequirePackage{graphicx}
\RequirePackage{adjustbox}
\RequirePackage{wrapfig}
\RequirePackage{caption}
\RequirePackage{subcaption}

%Packages
\RequirePackage[percent]{overpic}
\RequirePackage[figuresright]{rotating}
\RequirePackage{pdfpages}
\RequirePackage{pdflscape}
\RequirePackage{siunitx}
\RequirePackage{xfrac}
\RequirePackage{asymptote}
\RequirePackage{mathrsfs}
\RequirePackage{afterpage}
\RequirePackage{changepage}
\RequirePackage{needspace, blindtext, changepage, setspace, float, placeins}
\RequirePackage[symbol, bottom]{footmisc}

\RequirePackage{appendix}
\RequirePackage{emptypage}
\RequirePackage{etoolbox}




%Titre présentation
\title{%
\vspace{-3.5em}

\begin{minipage}[l]{0.8\textwidth}
\textbf{\Large \myTitle}\\
\vspace{-0.5em}
\end{minipage}\hspace*{0.5cm}
\begin{minipage}[r]{0.155\textwidth}\vskip 0.5em
\hfill\includegraphics[width=\linewidth]{logo-UVSQ-2020-RVB (1).pdf}\\
\end{minipage}
%
}

\author{
\vspace{-2em}



\textbf{\MyAuthor$^{}$
    }\\
    \small{$^{}$\MyDepartment}
}

\RequirePackage{titling}
\pretitle{
  \vskip 1.5em
    \huge\bfseries
    \begin{flushleft}
}
\posttitle{%
  \end{flushleft}%
  }
\RequirePackage{microtype}
\newcommand{\myTitle}{Title}
\newcommand{\MyAuthor}{John J. Smith}
\newcommand{\MyDepartment}{Department}
\newcommand{\ID}{1234567}

\preauthor{%
    \vspace{0em}
    \begin{flushleft}
    \vspace{0.0em}\Large
}


%Alignement num étudiant date
\postauthor{%
    \end{flushleft}%
    \vskip 0em
    \vspace{0em}
    \textls[10]{N° : \ID}
    \vspace{-0.8em} %change distance from
}

% réglage date
\predate{
\hfill\begin{minipage}[t]{0.3\textwidth}\begin{flushright}\textls[10]{}
{\end{flushright}\end{minipage}}}

\ExplSyntaxOff

\RequirePackage[bookmarks, hidelinks]{hyperref}
\hypersetup{
    colorlinks=true,
    linkcolor=azure,
    filecolor=magenta,      
    urlcolor=azure,
    citecolor=azure,
    hypertexnames=true
}

% Marge
\RequirePackage[includeheadfoot,top=0.5in, bottom=0.5in, 
    left=1in, right=1in, headheight=15pt]{geometry} %chnaged to 15 for size 12pt font



\setlength{\columnsep}{10mm} %Column spacing

%Style
 \RequirePackage[compact]{titlesec}
    \titlespacing{\section}{2pt}{2ex}{2ex}
    \titlespacing{\subsection}{1.5pt}{1.5ex}{1.5ex}
    \titlespacing{\subsubsection}{1pt}{1ex}{1ex}

\RequirePackage{titlesec, blindtext, color, tipa}
\newcommand{\hsp}{\hspace{20pt}}

\usetikzlibrary{positioning}
\RequirePackage[absolute,overlay]{textpos}


%Code 
\RequirePackage{listings}

\RequirePackage[utf8]{inputenc}
\DeclareUnicodeCharacter{394}{$\Delta$}
\DeclareUnicodeCharacter{3008}{$\langle$}
\DeclareUnicodeCharacter{3009}{$\rangle$}


\definecolor{codegreen}{rgb}{0,0.6,0}
\definecolor{codegray}{rgb}{0.5,0.5,0.5}
\definecolor{codepurple}{rgb}{0.58,0,0.82}
\definecolor{backcolour}{rgb}{0.95,0.95,0.92}

\lstdefinestyle{mystyle}{
    backgroundcolor=\color{backcolour},   
    commentstyle=\color{codegreen},
    keywordstyle=\color{magenta},
    numberstyle=\tiny\color{codegray},
    stringstyle=\color{codepurple},
    basicstyle=\ttfamily\footnotesize,
    breakatwhitespace=false,         
    breaklines=true,                 
    captionpos=b,                    
    keepspaces=true,                 
    numbers=left,                    
    numbersep=5pt,                  
    showspaces=false,                
    showstringspaces=false,
    showtabs=false,                  
    tabsize=2
}
\lstset{style=mystyle}
