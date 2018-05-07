---
title: C2147 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2147
dev_langs:
- C++
helpviewer_keywords:
- C2147
ms.assetid: d1adb3bf-7ece-4815-922c-ad7492fb6670
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 60047795428aad2da94b117882f351375fed4545
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2147"></a>C2147 de erro do compilador
Erro de sintaxe: 'Identificador' é uma palavra-chave new  
  
 Foi usado um identificador que agora é uma palavra reservada no idioma.  
  
 O exemplo a seguir gera C2147:  
  
```  
// C2147.cpp  
// compile with: /clr  
int main() {  
   int gcnew = 0;   // C2147  
   int i = 0;   // OK  
}  
```