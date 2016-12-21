---
title: "Classe move_iterator | Microsoft Docs"
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
  - "std.move_iterator"
  - "move_iterator"
  - "iterator/std::move_iterator"
  - "std::move_iterator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe move_iterator"
ms.assetid: a5e5cdd8-a264-4c6b-9f9c-68b0e8edaab7
caps.latest.revision: 20
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe move_iterator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O modelo de classe `move_iterator` é um wrapper para um iterador.  O move\_iterator apresenta o mesmo comportamento do iterador que ele encapsula \(armazena\), exceto pelo fato de que transforma o operador de desreferência do iterador armazenado em uma referência rvalue, transformando uma cópia em um movimento.  Para obter mais informações sobre rvalues, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## Sintaxe  
  
```  
template<class Iterator>  
    class move_iterator {  
public:  
    typedef Iterator iterator_type;  
    typedef typename      
        iterator_traits<Iterator>::iterator_category  
            iterator_category;  
    typedef typename iterator_traits<Iterator>::value_type  
        value_type;  
    typedef typename iterator_traits<Iterator>::difference_type  
        difference_type;  
    typedef Iterator  
        pointer;  
    typedef value_type&&  
        reference;  
  
    move_iterator();  
    explicit move_iterator (Iterator right);  
    template<class Type>  
        move_iterator (const move_iterator<Type>& right);  
    template <class Type>   
        move_iterator& operator=(const move_iterator<Type>& right);  
  
    iterator_type base () const;  
    reference operator* () const;  
    pointer operator-> () const;  
  
    move_iterator& operator++ ();  
    move_iterator operator++ (int);  
    move_iterator& operator-- ();  
    move_iterator operator-- (int);  
  
    move_iterator& operator+= (difference_type off);  
    move_iterator operator+ (difference_type off) const;  
    move_iterator& operator-= (difference_type off);  
    move_iterator operator- (difference_type off) const;  
    reference operator[] (difference_type off) const;  
    };  
```  
  
## Comentários  
 A classe de modelo descreve um objeto que se comporta como um iterador, exceto quando desreferenciado.  Ela armazena um iterador de acesso aleatório do tipo `Iterator`, acessado pela função membro `base``()`.  Todas as operações em um `move_iterator` são executadas diretamente no iterador armazenado, exceto pelo fato de que o resultado de `operator*` é implicitamente convertido em `value_type&&` para criar uma referência rvalue.  
  
 Um `move_iterator` pode ser capaz de operações que não são definidas pelo iterador encapsulado.  Essas operações não devem ser usadas.  
  
### Construtores  
  
|||  
|-|-|  
|[move\_iterator](../Topic/move_iterator::move_iterator.md)|O construtor para objetos do tipo `move_iterator`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[move\_iterator::iterator\_type](../Topic/move_iterator::iterator_type.md)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|  
|[move\_iterator::iterator\_category](../Topic/move_iterator::iterator_category.md)|Um sinônimo para a expressão `typename` mais longa do mesmo nome, `iterator_category` identifica as habilidades gerais do iterador.|  
|[move\_iterator::value\_type](../Topic/move_iterator::value_type.md)|Um sinônimo para a expressão `typename` mais longa do mesmo nome, `value_type` descreve de qual tipo são os elementos do iterador.|  
|[move\_iterator::difference\_type](../Topic/move_iterator::difference_type.md)|Um sinônimo para uma expressão `typename` mais longa do mesmo nome, `difference_type` descreve o tipo integral exigido para expressar valores de diferença entre elementos.|  
|[move\_iterator::pointer](../Topic/move_iterator::pointer.md)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|  
|[move\_iterator::reference](../Topic/move_iterator::reference.md)|Um sinônimo para a referência `rvalue` `value_type&&`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[move\_iterator::base](../Topic/move_iterator::base.md)|A função membro retorna o iterador armazenado encapsulado por esse `move_iterator`.|  
  
### Operadores  
  
|||  
|-|-|  
|[move\_iterator::operator\*](../Topic/move_iterator::operator*.md)|Retorna `(reference)*``base``().`|  
|[move\_iterator::operator\+\+](../Topic/move_iterator::operator++.md)|Incrementa o iterador armazenado.  O comportamento exato depende do tipo de operação: pré\-incremento ou pós\-incremento.|  
|[move\_iterator::operator\-\-](../Topic/move_iterator::operator--.md)|Decrementa o iterador armazenado.  O comportamento exato depende do tipo de operação: pré\-decremento ou pós\-decremento.|  
|[move\_iterator::operator\-\>](../Topic/move_iterator::operator-%3E.md)|Retorna `&**this`.|  
|[move\_iterator::operator\-](../Topic/move_iterator::operator-.md)|Retorna `move_iterator(*this) -=` subtraindo primeiro o valor do lado direito da posição atual.|  
|[move\_iterator::operator](../Topic/move_iterator::operator.md)|Retorna `(reference)*(*this + off)`.  Permite especificar um deslocamento da base atual para obter o valor nessa posição.|  
|[move\_iterator::operator\+](../Topic/move_iterator::operator+.md)|Retorna `move_iterator(*this) +=` do valor.  Permite adicionar um deslocamento à base para obter o valor nessa posição.|  
|[move\_iterator::operator\+\=](../Topic/move_iterator::operator+=.md)|Adiciona o valor do lado direito ao iterador armazenado e retorna `*this`.|  
|[move\_iterator::operator\-\=](../Topic/move_iterator::operator-=.md)|Subtrai o valor do lado direito do iterador armazenado e retorna `*this`.|  
  
## Requisitos  
 **Cabeçalho:** \<iterator\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<iterator\>](../standard-library/iterator.md)   
 [Lvalues e Rvalues](../Topic/Lvalues%20and%20Rvalues%20\(Visual%20C++\).md)   
 [Operadores de construtores de movimento e de atribuição de movimento \(C\+\+\)](../Topic/Move%20Constructors%20and%20Move%20Assignment%20Operators%20\(C++\).md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)