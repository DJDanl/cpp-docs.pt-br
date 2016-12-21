---
title: "Classe match_results | Microsoft Docs"
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
  - "std.tr1.match_results"
  - "match_results"
  - "std::tr1::match_results"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe match_results [TR1]"
ms.assetid: b504fdca-e5dd-429d-9960-6e27c9167fa6
caps.latest.revision: 16
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe match_results
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Contém uma seqüência de subcorrespondências.  
  
## Sintaxe  
  
```  
template<class BidIt,  
    class Alloc = allocator<typename iterator_traits<BidIt>::value_type> >  
    class match_results {  
public:  
    explicit match_results(const Alloc& alloc = Alloc());  
    match_results(const match_results& right);  
  
    match_results& operator=(const match_results& right);  
  
    difference_type position(size_type sub = 0) const;  
    difference_type length(size_type sub = 0) const;  
    string_type str(size_type sub = 0) const;  
    const_reference operator[](size_type n) const;  
  
    const_reference prefix() const;  
    const_reference suffix() const;  
    const_iterator begin() const;  
    const_iterator end() const;  
  
    template<class OutIt>  
        OutIt format(OutIt out,  
            const string_type& fmt, match_flag_type flags = format_default) const;  
    string_type format(const string_type& fmt,  
        match_flag_type flags = format_default) const;  
  
    allocator_type get_allocator() const;  
    void swap(const match_results& other) throw();  
  
    size_type size() const;  
    size_type max_size() const;  
    bool empty() const;  
  
    typedef sub_match<BidIt> value_type;  
    typedef const typename Alloc::const_reference const_reference;  
    typedef const_reference reference;  
    typedef T0 const_iterator;  
    typedef const_iterator iterator;  
    typedef typename iterator_traits<BidIt>::difference_type difference_type;  
    typedef typename Alloc::size_type size_type;  
    typedef Alloc allocator_type;  
    typedef typename iterator_traits<BidIt>::value_type char_type;  
    typedef basic_string<char_type> string_type;  
    };  
```  
  
#### Parâmetros  
 `BidIt`  
 O tipo de iterador para subcorrespondências.  
  
 `Alloc`  
 O tipo de um alocador para o gerenciamento de armazenamento.  
  
## Comentários  
 A classe de modelo descreve um objeto que controla uma sequência não modificável de elementos do tipo `sub_match<BidIt>` gerado por uma pesquisa de expressão regular. Cada elemento aponta para a subsequência que corresponde ao grupo de captura correspondente a esse elemento.  
  
## Requisitos  
 **Cabeçalho:** \< regex \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<regex\>](../standard-library/regex.md)