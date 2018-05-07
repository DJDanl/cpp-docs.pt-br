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
ms.openlocfilehash: f184f0459e7ec2251d6ff34e2ee76559fe0dea42
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3533"></a>C3533 de erro do compilador
'type': um parâmetro não pode ter um tipo que contém 'auto'  
  
 Um parâmetro de método ou o modelo não pode ser declarado com a `auto` palavra-chave se o padrão [/ZC: auto](../../build/reference/zc-auto-deduce-variable-type.md) opção de compilador está em vigor.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Remover o `auto` palavra-chave da declaração de parâmetro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque ele declara um parâmetro de função com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.  
  
```  
// C3533a.cpp  
// Compile with /Zc:auto  
void f(auto j){} // C3533  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir produz C3535 porque ele declara um parâmetro de modelo com o `auto` palavra-chave e ele é compilado com **/ZC: auto**.  
  
```  
// C3533b.cpp  
// Compile with /Zc:auto  
template<auto T> class C{}; // C3533  
```  
  
## <a name="see-also"></a>Consulte também  
 [palavra-chave auto](../../cpp/auto-keyword.md)   
 [/Zc:auto (deduzir tipo de variável)](../../build/reference/zc-auto-deduce-variable-type.md)