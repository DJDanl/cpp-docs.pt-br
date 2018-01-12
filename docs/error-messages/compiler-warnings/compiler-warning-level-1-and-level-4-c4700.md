---
title: "Compilador (nível 1 e nível 4) de aviso C4700 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4700
dev_langs: C++
helpviewer_keywords: C4700
ms.assetid: 2da0deb4-77dd-4b05-98d3-b78d74ac4ca7
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 14882157fd745c05f38943fae589636a486fd94d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-and-level-4-c4700"></a>Aviso C4700 (compilador) (nível 1 e nível 4)
variável local não inicializado 'name' usado  
  
 Você usou a variável local *nome* sem primeiro atribuindo um valor, que pode levar a resultados imprevisíveis.  
  
 O exemplo a seguir gera C4700:  
  
```  
// C4700.cpp  
// compile with: /W1  
int main() {  
   int i;  
   return i;   // C4700  
}  
```  
  
 Em [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) este é um aviso de nível 4.  O exemplo a seguir gera C4700:  
  
```  
// C4700b.cpp  
// compile with: /W4 /clr:safe /c  
using namespace System;  
int main() {  
   Int32^ bi;  
   return *bi;   // C4700  
}  
```