---
title: "Como blocos Catch são avaliados (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- try-catch keyword [C++], catchable types
- catch keyword [C++], types of catch handlers
- C++ exception handling, catch handlers
- exception handling, catching and deleting exceptions
- types [C++], exception handling
ms.assetid: 202dbf07-8ace-4b3b-b3ae-4b45c275e0b4
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 1098529effb3a15d8f6260ed7167c5553b226857
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="how-catch-blocks-are-evaluated-c"></a>Como blocos catch são avaliados (C++)
O C++ permite lançar exceções de qualquer tipo, embora seja recomendável lançar os tipos derivados de std::exception. Uma exceção de C++ pode ser capturada por um **catch** manipulador que especifica o mesmo tipo, como a exceção lançada, ou por um manipulador que pode capturar qualquer tipo de exceção.  
  
 Se o tipo de exceção lançada for uma classe, que também tenha uma classe base (ou classes), ela pode ser capturada pelos manipuladores que aceitam classes base do tipo da exceção, bem como por referências às bases do tipo da exceção. Observe que, quando uma exceção é capturada por uma referência, ela é associada ao objeto de exceção lançado real; caso contrário, é uma cópia (bem semelhante a um argumento para uma função).  
  
 Quando uma exceção for lançada, podem ser detectado pelos seguintes tipos de **catch** manipuladores:  
  
-   Um manipulador que pode aceitar qualquer tipo (usando a sintaxe de reticências).  
  
-   Um manipulador que aceita o mesmo tipo que o objeto de exceção; porque é uma cópia, **const** e `volatile` modificadores são ignorados.  
  
-   Um manipulador que aceita uma referência para mesmo tipo do objeto de exceção.  
  
-   Um manipulador que aceita uma referência a um **const** ou `volatile` formulário do mesmo tipo do objeto de exceção.  
  
-   Um manipulador que aceita uma classe base do mesmo tipo do objeto de exceção; como é uma cópia **const** e `volatile` modificadores são ignorados. O **catch** manipulador para uma classe base não deve preceder o **catch** manipulador para a classe derivada.  
  
-   Um manipulador que aceita uma referência a uma classe base do mesmo tipo do objeto de exceção.  
  
-   Um manipulador que aceita uma referência a um **const** ou `volatile` forma de uma classe base do mesmo tipo do objeto de exceção.  
  
-   Um manipulador que aceita um ponteiro no qual um objeto de ponteiro gerado pode ser convertido pelas regras padrão de conversão de ponteiro.  
  
 A ordem na qual **catch** manipuladores aparecem é importante, porque manipuladores para um determinado **tente** bloco são examinados em ordem de sua aparência. Por exemplo, é um erro para colocar o manipulador de uma classe base antes do manipulador de uma classe derivada. Depois de encontrar uma correspondência **catch** manipulador foi encontrado, manipuladores subsequentes não são examinadas. Como resultado, uma elipse **catch** manipulador deve ser o último manipulador para seus **tente** bloco. Por exemplo:  
  
```  
// ...  
try  
{  
    // ...  
}  
catch( ... )  
{  
    // Handle exception here.  
}  
// Error: the next two handlers are never examined.  
catch( const char * str )  
{  
    cout << "Caught exception: " << str << endl;  
}  
catch( CExcptClass E )  
{  
    // Handle CExcptClass exception here.  
}  
```  
  
 Neste exemplo, no botão de reticências **catch** manipulador é o único manipulador é examinado.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)
