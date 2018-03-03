---
title: "Compilador (nível 1) de aviso C4566 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4566
dev_langs:
- C++
helpviewer_keywords:
- C4566
ms.assetid: 65f40730-e86f-447c-b37b-16caadcfe311
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 22a53aae49f025c8d05beb3b491288e5c82345a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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