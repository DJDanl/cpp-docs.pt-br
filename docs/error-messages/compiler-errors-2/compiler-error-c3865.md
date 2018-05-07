---
title: C3865 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3865
dev_langs:
- C++
helpviewer_keywords:
- C3865
ms.assetid: 9bc62bb0-4fb8-4856-a5cf-c7cb4029a596
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 99a872d4cf7ed285a0798461c77adf904cfa3e71
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3865"></a>C3865 de erro do compilador
'calling_convention': só pode ser usada em funções membro nativas  
  
 Uma convenção de chamada foi usada em uma função que foi a uma função global ou em uma função de membro gerenciado. A convenção de chamada só pode ser usada em uma função de membro (não gerenciado) nativo.  
  
 Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).  
  
 O exemplo a seguir gera C3865:  
  
```  
// C3865.cpp  
// compile with: /clr  
// processor: x86  
void __thiscall Func(){}   // C3865  
  
// OK  
struct MyType {  
   void __thiscall Func(){}  
};  
```