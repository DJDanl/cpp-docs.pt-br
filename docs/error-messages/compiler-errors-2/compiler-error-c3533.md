---
title: C3533 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3533
dev_langs:
- C++
helpviewer_keywords:
- C3533
ms.assetid: a68b1ba5-466e-4190-a1a4-505ccfe548b7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: faaf53d08512559b86c95148bc93e7b3367d2b01
ms.sourcegitcommit: 3bb7c1c0ceeb8012418e2fff9ae5a7db0fff3877
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2018
---
# <a name="compiler-error-c3533"></a>C3533 de erro do compilador
'type': um parâmetro não pode ter um tipo que contém 'auto'  
  
 Um parâmetro de método ou o modelo não pode ser declarado com a `auto` palavra-chave se o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção de compilador está em vigor.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Remover o `auto` palavra-chave da declaração de parâmetro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3533 porque ele declara um parâmetro de função com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.  
  
```  
// C3533a.cpp  
// Compile with /Zc:auto  
void f(auto j) {} // C3533  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3533 no modo C + + 14 porque ele declara um parâmetro de modelo com o `auto` palavra-chave e ele é compilado com **/ZC: auto**. (Em C++ 17, esta é uma definição válida de um modelo de classe com um parâmetro único modelo sem tipo cujo tipo é deduzido.)
  
```  
// C3533b.cpp  
// Compile with /Zc:auto  
template<auto T> class C {}; // C3533  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)
