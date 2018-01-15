---
title: Classe move_iterator | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- iterator/std::move_iterator
- iterator/std::move_iterator::iterator_type
- iterator/std::move_iterator::iterator_category
- iterator/std::move_iterator::value_type
- iterator/std::move_iterator::difference_type
- iterator/std::move_iterator::pointer
- iterator/std::move_iterator::reference
- iterator/std::move_iterator::base
dev_langs: C++
helpviewer_keywords:
- std::move_iterator [C++]
- std::move_iterator [C++], iterator_type
- std::move_iterator [C++], iterator_category
- std::move_iterator [C++], value_type
- std::move_iterator [C++], difference_type
- std::move_iterator [C++], pointer
- std::move_iterator [C++], reference
- std::move_iterator [C++], base
ms.assetid: a5e5cdd8-a264-4c6b-9f9c-68b0e8edaab7
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 54691a7d25e9229143e17476d5e0e09c6732e69e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="moveiterator-class"></a>Classe move_iterator
O modelo de classe `move_iterator` é um wrapper para um iterador. O move_iterator apresenta o mesmo comportamento do iterador que ele encapsula (armazena), exceto pelo fato de que transforma o operador de desreferência do iterador armazenado em uma referência rvalue, transformando uma cópia em um movimento. Para obter mais informações sobre rvalues, consulte [Declarador de referência Rvalue: &&](../cpp/rvalue-reference-declarator-amp-amp.md).  
  
## <a name="syntax"></a>Sintaxe  
```
class move_iterator;  
```
## <a name="remarks"></a>Comentários  
 A classe de modelo descreve um objeto que se comporta como um iterador, exceto quando desreferenciado. Ela armazena um iterador de acesso aleatório do tipo `Iterator`, acessado pela função membro `base()`. Todas as operações em um `move_iterator` são executadas diretamente no iterador armazenado, exceto pelo fato de que o resultado de `operator*` é implicitamente convertido em `value_type&&` para criar uma referência rvalue.  
  
 Um `move_iterator` pode ser capaz de operações que não são definidas pelo iterador encapsulado. Essas operações não devem ser usadas.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[move_iterator](#move_iterator)|O construtor para objetos do tipo `move_iterator`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[iterator_type](#iterator_type)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|  
|[iterator_category](#iterator_category)|Um sinônimo para a expressão `typename` mais longa do mesmo nome, `iterator_category` identifica as habilidades gerais do iterador.|  
|[value_type](#value_type)|Um sinônimo para a expressão `typename` mais longa do mesmo nome, `value_type` descreve de qual tipo são os elementos do iterador.|  
|[difference_type](#difference_type)|Um sinônimo para uma expressão `typename` mais longa do mesmo nome, `difference_type` descreve o tipo integral exigido para expressar valores de diferença entre elementos.|  
|[pointer](#pointer)|Um sinônimo para o parâmetro de modelo `RandomIterator`.|  
|[reference](#reference)|Um sinônimo para a referência `rvalue``value_type&&`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[base](#base)|A função membro retorna o iterador armazenado encapsulado por esse `move_iterator`.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[move_iterator::operator*](#op_star)|Retorna `(reference)*base().`|  
|[move_iterator::operator++](#op_add_add)|Incrementa o iterador armazenado. O comportamento exato depende do tipo de operação: pré-incremento ou pós-incremento.|  
|[move_iterator::operator--](#operator--)|Decrementa o iterador armazenado. O comportamento exato depende do tipo de operação: pré-decremento ou pós-decremento.|  
|[move_iterator::operator-&gt;](#operator-_gt)|Retorna `&**this`.|  
|[move_iterator::operator-](#operator-)|Retorna `move_iterator(*this) -=` subtraindo primeiro o valor do lado direito da posição atual.|  
|[move_iterator::operator[]](#op_at)|Retorna `(reference)*(*this + off)`. Permite especificar um deslocamento da base atual para obter o valor nessa posição.|  
|[move_iterator::operator+](#op_add)|Retorna `move_iterator(*this) +=` do valor. Permite adicionar um deslocamento à base para obter o valor nessa posição.|  
|[move_iterator::operator+=](#op_add_eq)|Adiciona o valor do lado direito ao iterador armazenado e retorna `*this`.|  
|[move_iterator::operator-=](#operator-_eq)|Subtrai o valor do lado direito do iterador armazenado e retorna `*this`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<iterator>  
  
 **Namespace:** std  
  
##  <a name="base"></a>  move_iterator::base  
 Retorna o iterador armazenado para este `move_iterator`.  
  
```
RandomIterator base() const;
```  
  
### <a name="remarks"></a>Comentários  
 A função membro retorna o iterador armazenado.  
  
##  <a name="difference_type"></a>  move_iterator::difference_type  
 O tipo `difference_type` é um `move_iterator` `typedef` com base em características do iterador `difference_type`e podem ser usados de maneira intercambiável com ele.  
  
```
typedef typename iterator_traits<RandomIterator>::difference_type difference_type;
```    
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::pointer`.  
  
##  <a name="iterator_category"></a>  move_iterator::iterator_category  
 O tipo `iterator_category` é um `move_iterator` `typedef` com base em características do iterador `iterator_category`e podem ser usados de maneira intercambiável com ele.  
  
```
typedef typename iterator_traits<RandomIterator>::iterator_category  iterator_category;
```    
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::iterator_category`.  
  
##  <a name="iterator_type"></a>  move_iterator::iterator_type  
 O tipo `iterator_type` é baseado no parâmetro de modelo `RandomIterator` para o modelo de classe `move_iterator` e pode ser usado alternadamente em seu lugar.  
  
```
typedef RandomIterator iterator_type;
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo do parâmetro de modelo `RandomIterator`.  
  
##  <a name="move_iterator"></a>  move_iterator::move_iterator  
 Constrói um iterador de movimentação. Usa o parâmetro como o iterador armazenado.  
  
```
move_iterator();
explicit move_iterator(RandomIterator right);
template <class Type>
move_iterator(const move_iterator<Type>& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 O iterador a ser usado como o iterador armazenado.  
  
### <a name="remarks"></a>Comentários  
 O primeiro construtor inicializa o iterador armazenado com o construtor padrão. Os construtores restantes inicializam o iterador armazenado com `base.base()`.  
  
##  <a name="op_add_eq"></a>  move_iterator::operator+=  
 Adiciona um deslocamento ao iterador armazenado, para que o iterador armazenado aponte para o elemento no novo local atual. O operador move então o novo elemento atual.  
  
```
move_iterator& operator+=(difference_type _Off);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Off`  
 Um deslocamento para adicionar à posição atual para determinar a nova posição atual.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o novo elemento atual.  
  
### <a name="remarks"></a>Comentários  
 O operador adiciona `_Off` ao iterador armazenado. Em seguida, retorna `*this`.  
  
##  <a name="move_iterator__operator-_eq"></a>  move_iterator::operator-=  
 Move entre um número especificado de elementos anteriores. Este operador subtrai um deslocamento do iterador armazenado.  
  
```
move_iterator& operator-=(difference_type _Off);
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O operador avalia `*this += -_Off`. Em seguida, retorna `*this`.  
  
##  <a name="op_add_add"></a>  move_iterator::operator++  
 Incrementa o iterador armazenado que pertence a este `move_iterator.`. O elemento atual é acessado pelo operador pós-incremento. O próximo elemento é acessado pelo operador pré-incremento.  
  
```
move_iterator& operator++();
move_iterator operator++(int);
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador (pré-incremento) incrementa o iterador armazenado. Em seguida, retorna `*this`.  
  
 O segundo operador (pós-incremento) faz uma cópia do `*this`, avalia `++*this`. E retorna a cópia.  
  
##  <a name="op_add"></a>  move_iterator::operator+  
 Retorna a posição do iterador avançada por qualquer número de elementos.  
  
```
move_iterator operator+(difference_type _Off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O operador retorna `move_iterator(*this) +=` `_Off`.  
  
##  <a name="op_at"></a>  move_iterator::operator[]  
 Permite o acesso de índice de matriz a elementos em uma série do `move iterator`.  
  
```
reference operator[](difference_type _Off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O operador retorna `(reference)*(*this + _Off)`.  
  
##  <a name="move_iterator__operator--"></a>  move_iterator::operator--  
 Os operadores de membro pré e pós-incremento realizam uma diminuição no iterador armazenado.  
  
```
move_iterator& operator--();
move_iterator operator--();
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O primeiro operador de membro (pré-decremento) diminui o iterador armazenado. Em seguida, retorna `*this`.  
  
 O segundo operador (pós-decremento) faz uma cópia do `*this`, avalia `--*this`. E retorna a cópia.  
  
##  <a name="move_iterator__operator-"></a>  move_iterator::operator-  
 Diminui o iterador armazenado e retorna o valor indicado.  
  
```
move_iterator operator-(difference_type _Off) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
### <a name="remarks"></a>Comentários  
 O operador retorna `move_iterator(*this) -= _Off`.  
  
##  <a name="op_star"></a>  move_iterator::operator*  
 Desreferencia o iterador armazenado e retorna o valor. Isso se comporta como um `rvalue reference` e realiza uma atribuição de movimentação. O operador transfere o elemento atual para fora do iterador de base. O elemento seguinte se torna o novo elemento atual.  
  
```
reference operator*() const;
```  
  
### <a name="remarks"></a>Comentários  
 O operador retorna `(reference)*base()`.  
  
##  <a name="move_iterator__operator-_gt"></a>  move_iterator::operator-&gt;  
 Como um normal `RandomIterator` `operator->`, ele fornece acesso para os campos que pertencem ao elemento atual.  
  
```
pointer operator->() const;
```  
  
### <a name="remarks"></a>Comentários  
 O operador retorna `&**this`.  
  
##  <a name="pointer"></a>  move_iterator::pointer  
 O tipo `pointer` é um `typedef` com base no iterador aleatório `RandomIterator` de `move_iterator` e pode ser usado alternadamente.  
  
```
typedef RandomIterator  pointer;
```    
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo de `RandomIterator`.  
  
##  <a name="reference"></a>  move_iterator::reference  
 O tipo `reference` é um `typedef` com base no `value_type&&` para `move_iterator` e pode ser usado alternadamente com `value_type&&`.  
  
```
typedef value_type&& reference;
```    
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para `value_type&&`, que é uma referência de rvalue.  
  
##  <a name="value_type"></a>  move_iterator::value_type  
 O tipo `value_type` é um `move_iterator` `typedef` com base em características do iterador `value_type`e podem ser usados de maneira intercambiável com ele.  
  
```
typedef typename iterator_traits<RandomIterator>::value_type   value_type;
```    
  
### <a name="remarks"></a>Comentários  
 O tipo é um sinônimo para a característica do iterador `typename iterator_traits<RandomIterator>::value_type`.  
  
## <a name="see-also"></a>Consulte também  
 [\<iterator>](../standard-library/iterator.md)   
 [Lvalues e Rvalues](../cpp/lvalues-and-rvalues-visual-cpp.md)   
 [Move Constructors and Move Assignment Operators (C++)](../cpp/move-constructors-and-move-assignment-operators-cpp.md)  (Operadores de construtores de movimento e de atribuição de movimento (C++))  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)




