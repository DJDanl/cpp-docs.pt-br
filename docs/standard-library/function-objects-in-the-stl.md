---
title: "Objetos de função na Biblioteca Padrão C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- functors
- C++ Standard Library, functors
- C++ Standard Library, function objects
- function objects
ms.assetid: 85f8a735-2c7b-4f10-9c4d-95c666ec4192
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 3928493eeb4aa09511b3e58d27383c7a480d06ad
ms.lasthandoff: 02/25/2017

---
# <a name="function-objects-in-the-c-standard-library"></a>Objetos de função na Biblioteca Padrão C++
Um *objeto de função* ou *functor*, é qualquer tipo que implementa operator(). Esse operador é conhecido como *operador de chamada* ou, às vezes, *operador de aplicativo*. A Biblioteca Padrão C++ usa objetos de função principalmente como critérios de classificação para contêineres e em algoritmos.  
  
 Objetos de função fornecem duas vantagens principais com relação a uma chamada de função direta. A primeira é que um objeto de função pode conter o estado. A segunda é que um objeto de função é um tipo e, portanto, pode ser usado como um parâmetro de modelo.  
  
## <a name="creating-a-function-object"></a>Criando um objeto de função  
 Para criar um objeto de função, crie um tipo e implemente operator(), como:  
  
class Functor  
   {  
   public:  
   int operator()(int a, int b)  
   {  
   return a <b;  
   }  
   };  
  
 A última linha da função `main` mostra como chamar o objeto de função. Essa chamada é semelhante a uma chamada para uma função, mas na verdade está chamando o operator() do tipo Functor. É dessa semelhança entre chamar um objeto de função e uma função que surgiu o termo objeto de função.  
  
## <a name="function-objects-and-containers"></a>Contêineres e objetos de função  
 A Biblioteca Padrão C++ contém vários objetos de função no arquivo de cabeçalho [\<functional>](../standard-library/functional.md). Um uso desses objetos de função é como critério de classificação para contêineres. Por exemplo, o contêiner `set` é declarado da seguinte maneira:  
  
```  
template <class Key,  
    class Traits=less<Key>,  
    class Allocator=allocator<Key>>  
class set  
```  
  
 O segundo argumento de modelo é o objeto de função `less`. Esse objeto de função retorna `true` se o primeiro parâmetro passado para ele for menor que o segundo parâmetro passado. Como alguns contêineres classificam seus elementos, o contêiner precisa de uma forma de comparar dois elementos e isso é feito usando o objeto de função. Você pode definir seus próprios critérios de classificação para contêineres criando um objeto de função e especificando-o na lista de modelos para o contêiner.  
  
## <a name="function-objects-and-algorithms"></a>Algoritmos e objetos de função  
 Outro uso dos objetos funcionais é em algoritmos. Por exemplo, o algoritmo `remove_if` é declarado da seguinte maneira:  
  
```  
template <class ForwardIterator, class Predicate>  
ForwardIterator remove_if(
    ForwardIterator first,  
    ForwardIterator last,  
    Predicate pred);
```  
  
 O último argumento para `remove_if` é um objeto de função que retorna um valor booliano (um *predicado*). Se o resultado do objeto de função for `true`, o elemento será removido do contêiner que está sendo acessado pelos iteradores ` first` e ` last`. Você pode usar qualquer um dos objetos de função declarados no cabeçalho [\<functional>](../standard-library/functional.md) para o argumento ` pred` ou pode criar seus próprios objetos.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)


