---
title: Compilador (nível 1) de aviso C4817 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4817
dev_langs:
- C++
helpviewer_keywords:
- C4817
ms.assetid: a68f5486-6940-4934-9f93-bfd4d71f92a9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa1dfa3cf0e63e319198cd9394f194864f87eacf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33286182"
---
# <a name="compiler-warning-level-1-c4817"></a>Compilador C4817 de aviso (nível 1)
'member': uso inválido de '.' para acessar este membro; compilador substituiu por '->'  
  
 O operador de acesso de membro incorreto foi usado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4817.  
  
```  
// C4817.cpp  
// compile with: /clr /W1  
using namespace System;  
int main() {  
   array<Int32> ^ a = gcnew array<Int32>(100);  
   Console::WriteLine( a.Length );   // C4817  
   Console::WriteLine( a->Length );   // OK  
}  
```  
