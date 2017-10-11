---
title: bool (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: f2437d831ae155f916b69cc6b35d3b586be9819e
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bool-c"></a>bool (C++)
Essa palavra-chave é um tipo interno. Uma variável desse tipo pode ter valores [true](../cpp/true-cpp.md) e [false](../cpp/false-cpp.md). As expressões condicionais têm o tipo `bool` e, sendo assim, têm valores do tipo `bool`. Por exemplo, `i!=0` agora tem **true** ou **false** dependendo do valor de `i`.  

**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): O operando de um prefixo ou sufixo de incremento ou decremento operador não pode ser do tipo `bool`. 
  
 Os valores **true** e **false** tem a seguinte relação:  
  
```  
!false == true  
!true == false  
```  
  
 Na instrução a seguir:  
  
```  
if (condexpr1) statement1;   
```  
  
 Se `condexpr1` é **true**, `statement1` sempre é executada; se `condexpr1` é **false**, `statement1` nunca será executado.  
  
 Quando um prefixo ou sufixo `++` operador é aplicado a uma variável do tipo `bool`, a variável é definida como **true**. 
**Visual Studio 2017 versão posterior e 15,3**: operador + + para bool foi removida do idioma e não é mais suportada.

O operador `--` de sufixo ou prefixo não pode ser aplicado a uma variável desse tipo.  
  
 O tipo `bool` participa de promoções de integral. Um r do tipo `bool` pode ser convertido em um r do tipo `int`, com **false** se torna zero e **true** se tornando um. Como um tipo diferente, `bool` participa da resolução de sobrecarga.  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)
