---
title: C2803 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2803
dev_langs:
- C++
helpviewer_keywords:
- C2803
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: efa9efa2dc204d302f69d873c0199d4431efccb1
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c2803"></a>C2803 de erro do compilador
'operador operator' deve ter pelo menos um parâmetro formal de tipo de classe  
  
 O operador sobrecarregado não tem um parâmetro de tipo de classe.  
  
 Você precisa passar pelo menos um parâmetro por referência (sem usar ponteiros, mas referencia) ou por valor para ser capaz de gravar "um < b" (um de classe de tipo A e b).  
  
 Se ambos os parâmetros são ponteiros será uma comparação pura de endereços do ponteiro e não usará a conversão definida pelo usuário.  
  
 O exemplo a seguir gera C2803:  
  
```  
// C2803.cpp  
// compile with: /c  
class A{};  
bool operator< (const A *left, const A *right);   // C2803  
// try the following line instead  
// bool operator< (const A& left, const A& right);  
```
