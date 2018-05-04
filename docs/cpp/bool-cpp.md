---
title: bool (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- bool_cpp
- __BOOL_DEFINED
dev_langs:
- C++
helpviewer_keywords:
- bool keyword [C++]
- __BOOL_DEFINED macro
ms.assetid: 9abed3f2-d21c-4eb4-97c5-716342e613d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2af648b2b93d2d01eaf66f5b642b6514063577d6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="bool-c"></a>bool (C++)

Essa palavra-chave é um tipo interno. Uma variável desse tipo pode ter valores [true](../cpp/true-cpp.md) e [false](../cpp/false-cpp.md). As expressões condicionais têm o tipo `bool` e, sendo assim, têm valores do tipo `bool`. Por exemplo, `i!=0` agora tem **true** ou **false** dependendo do valor de `i`.  

**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de um prefixo ou sufixo de incremento ou decremento operador não pode ser do tipo **bool**. Em outras palavras, dada uma variável **b** do tipo **bool**, essas expressões não são permitidas:

```cpp
    b++;
    ++b;
    b--;
    --b;
```
  
Os valores **true** e **false** tem a seguinte relação:  
  
```cpp  
!false == true  
!true == false  
```  
  
Na instrução a seguir:  
  
```cpp  
if (condexpr1) statement1;   
```  
  
Se `condexpr1` é **true**, `statement1` sempre é executada; se `condexpr1` é **false**, `statement1` nunca será executado.  
  
Quando um prefixo ou sufixo **++** operador é aplicado a uma variável do tipo **bool**, a variável é definida como **true**. 
**Visual Studio 2017 versão posterior e 15,3**: operador + + para **bool** foi removida do idioma e não é mais suportada.

O prefixo ou sufixo **--** operador não pode ser aplicado a uma variável desse tipo.  
  
 O **bool** tipo participa promoções integrais. Um r do tipo **bool** pode ser convertido em um r do tipo **int**, com **false** se torna zero e **true** se tornando um. Como um tipo distinto, **bool** participa na resolução de sobrecarga.  
  
## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Tipos fundamentais](../cpp/fundamental-types-cpp.md)<br/>
