---
title: C2780 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2780
dev_langs:
- C++
helpviewer_keywords:
- C2780
ms.assetid: 423793d8-a3b2-4f35-85f8-ae1d043e2b69
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8acea179c73b5a4821f2c13645b594c71413e426
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2780"></a>C2780 de erro do compilador
'declaração de ': espera argumentos de N - M fornecido  
  
 Um modelo de função tem muitos ou poucos argumentos.  
  
 O exemplo a seguir gera C2780 e mostra como corrigi-lo:  
  
```  
// C2780.cpp  
template<typename T>  
void f(T, T){}  
  
int main() {  
   f(1);  // C2780  
   // try the following line instead  
   // f(1,2);  
}  
```