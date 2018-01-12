---
title: C2153 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2153
dev_langs: C++
helpviewer_keywords: C2153
ms.assetid: cfc50cb7-9a0f-4b5b-879a-d419c99f7be1
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1c766d2ef62f22bcdc61c23790d70fa3f09b490c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2153"></a>C2153 de erro do compilador
Constantes hexadecimais devem ter pelo menos um dígito hexadecimal  
  
 Constantes hexadecimais 0 x, 0x e \x não são válidos. Pelo menos um dígito hexadecimal deve seguir x ou X.  
  
 O exemplo a seguir gera C2153:  
  
```  
// C2153.cpp  
int main() {  
   int a= 0x;    // C2153  
   int b= 0xA;   // OK  
}  
```