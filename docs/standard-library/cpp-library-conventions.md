---
title: "Convenções da biblioteca C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- C++ Standard Library, conventions
- classes [C++]
- functions [C++], library naming conventions
- naming conventions [C++], C++ Standard Library
- conventions [C++], C++ Standard Library
- function names [C++]
- coding conventions, C++ Standard Library
- naming conventions [C++], C++ library
ms.assetid: bf41b79a-2d53-4f46-8d05-779358335146
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 55d3959b12b1b1a25a6c4b5c65fce59db57cf838
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="c-library-conventions"></a>Convenções da Biblioteca C++
A biblioteca C++ obedece às mesmas convenções da Biblioteca C Padrão, além de mais algumas descritas aqui.  
  
 Uma implementação tem determinada latitude em como ela declara tipos e funções na biblioteca C++:  
  
-   Os nomes de funções na biblioteca C Padrão podem ter uma vinculação extern #"C++" ou extern "C". Inclua o cabeçalho do C Padrão apropriado em vez de declarar uma entidade de biblioteca embutida.  
  
-   O nome de uma função de membro em uma classe de biblioteca pode ter assinaturas de função adicionais além daquelas listadas neste documento. Você pode ter certeza de que uma chamada da função descrita aqui se comporta como esperado, mas não é possível usar de forma confiável o endereço de uma função de membro da biblioteca. (O tipo pode não ser o esperado.)  
  
-   Uma classe de biblioteca pode ter classes base (não virtuais) não documentadas. Uma classe documentada como derivada de outra classe pode, na verdade, ser derivada dessa classe por meio de outras classes não documentadas.  
  
-   Um tipo definido como sinônimo de algum tipo inteiro pode ser igual a um dos vários tipos inteiros diferentes.  
  
-   Um tipo de bitmask pode ser implementado como um tipo inteiro ou uma enumeração. Em ambos os casos, é possível executar operações bit a bit (como `AND` e `OR`) nos valores do mesmo tipo de bitmask. Os elementos `A` e `B` de um tipo de bitmask são valores diferentes de zero, como `A` & `B` é zero.  
  
-   Uma função de biblioteca que não tem uma especificação de exceção pode gerar uma exceção arbitrária, a menos que sua definição claramente restrinja essa possibilidade.  
  
 Por outro lado, há algumas restrições:  
  
-   A Biblioteca C Padrão não usa macros de mascaramento. Somente assinaturas de função específicas são reservadas, não os nomes das funções em si.  
  
-   O nome de uma função de biblioteca fora de uma classe não terá assinaturas de função adicionais não documentadas. É possível usar seu endereço de forma confiável.  
  
-   Classes base e funções de membro descritas como virtuais certamente são virtuais, enquanto aquelas descritas como não virtuais certamente não são virtuais.  
  
-   Dois tipos definidos pela biblioteca C++ sempre são diferentes, a menos que este documento explicitamente sugira o contrário.  
  
-   As funções fornecidas pela biblioteca, incluindo as versões padrão das funções substituíveis, podem gerar *no máximo* as exceções listadas em qualquer especificação de exceção. Nenhum destruidor fornecido pela biblioteca gera exceções. As funções na Biblioteca C Padrão podem propagar uma exceção, como ocorre quando `qsort` chama uma função de comparação que gera uma exceção, mas, de outro modo, elas não geram exceções.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


