---
title: Compilador (nível 1) de aviso C4566 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4566
dev_langs:
- C++
helpviewer_keywords:
- C4566
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e8044df3a37e54585f7f3b495b99314e258934f1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33284219"
---
# <a name="compiler-warning-level-1-c4566"></a>Compilador C4566 de aviso (nível 1)
caractere representado por nome de caractere universal 'char' não pode ser representado na página de código atual (página)  
  
 Nem todos os caracteres Unicode podem ser representado na página de código ANSI atual.  
  
 Cadeias de caracteres estreitas (caracteres de um byte) são convertidas em caracteres multibyte enquanto não são de cadeias de caracteres amplas (caracteres de dois bytes).  
  
 O exemplo a seguir gera C4566:  
  
```  
// C4566.cpp  
// compile with: /W1  
int main() {  
   char c1 = '\u03a0';   // C4566  
   char c2 = '\u0642';   // C4566  
  
   wchar_t c3 = L'\u03a0';   // OK  
   wchar_t c4 = L'\u0642';   // OK  
}  
```