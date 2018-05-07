---
title: C2803 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2803
dev_langs:
- C++
helpviewer_keywords:
- C2803
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 51cf2a8b38a86fcd97ab693b3853fe25527a0bb3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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