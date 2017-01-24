---
title: "&lt;iosfwd&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::<iosfwd>"
  - "<iosfwd>"
  - "std.<iosfwd>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho iosfwd"
ms.assetid: 964442eb-17f1-43ef-a0e0-c5bb77f9c187
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;iosfwd&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Declara referências antecipadas a várias classes de modelo usadas em todo iostreams.  Todas essas classes de modelo são definidas em outros cabeçalhos padrão.  Você incluir este cabeçalho explicitamente somente quando precisar de uma de suas declarações, mas não a definição.  
  
## Sintaxe  
  
```  
  
#include <iosfwd>  
  
```  
  
## Typedefs  
  
```  
typedef T1 streamoff;  
typedef T2 streamsize;  
typedef fpos streampos;  
  
// wchar_t TYPE DEFINITIONS  
typedef basic_ios<char, char_traits<char> > ios;  
typedef basic_streambuf<char, char_traits<char> > streambuf;  
typedef basic_istream<char, char_traits<char> > istream;  
typedef basic_ostream<char, char_traits<char> > ostream;  
typedef basic_iostream<char, char_traits<char> > iostream;  
typedef basic_stringbuf<char, char_traits<char> > stringbuf;  
typedef basic_istringstream<char, char_traits<char> > istringstream;  
typedef basic_ostringstream<char, char_traits<char> > ostringstream;  
typedef basic_stringstream<char, char_traits<char> > stringstream;  
typedef basic_filebuf<char, char_traits<char> > filebuf;  
typedef basic_ifstream<char, char_traits<char> > ifstream;  
typedef basic_ofstream<char, char_traits<char> > ofstream;  
typedef basic_fstream<char, char_traits<char> > fstream;  
  
// wchar_t TYPE DEFINITIONS  
typedef basic_ios<wchar_t, char_traits<wchar_t> > wios;  
typedef basic_streambuf<wchar_t, char_traits<wchar_t> > wstreambuf;  
typedef basic_istream<wchar_t, char_traits<wchar_t> > wistream;  
typedef basic_ostream<wchar_t, char_traits<wchar_t> > wostream;  
typedef basic_iostream<wchar_t, char_traits<wchar_t> > wiostream;  
typedef basic_stringbuf<wchar_t, char_traits<wchar_t> > wstringbuf;  
typedef basic_istringstream<wchar_t, char_traits<wchar_t> > wistringstream;  
typedef basic_ostringstream<wchar_t, char_traits<wchar_t> > wostringstream;  
typedef basic_stringstream<wchar_t, char_traits<wchar_t> > wstringstream;  
typedef basic_filebuf<wchar_t, char_traits<wchar_t> > wfilebuf;  
typedef basic_ifstream<wchar_t, char_traits<wchar_t> > wifstream;  
typedef basic_ofstream<wchar_t, char_traits<wchar_t> > wofstream;  
typedef basic_fstream<wchar_t, char_traits<wchar_t> > wfstream;  
};  
```  
  
## Declarações\/classes antecipadas do modelo  
  
```  
template<class _Statetype>  
class fpos;  
  
template<class Elem>;  
class char_traits;  
  
class char_traits<char>;  
  
class char_traits<wchar_t>;  
  
template<class _Ty>  
class allocator;  
  
class ios_base;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_ios;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class istreambuf_iterator;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class ostreambuf_iterator;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_streambuf;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_istream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_ostream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_iostream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_stringbuf;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_istringstream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_ostringstream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_stringstream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_filebuf;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_ifstream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_ofstream;  
  
template<class Elem, class Tr = char_traits<Elem> >  
class basic_fstream;  
```  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)