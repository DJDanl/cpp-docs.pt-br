---
title: C3120 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3120
dev_langs:
- C++
helpviewer_keywords:
- C3120
ms.assetid: 9b6b210f-9948-4517-a4cc-b4aaadebde68
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f52809bca6ddc4672e8206822071f91c62c7009e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3120"></a>C3120 de erro do compilador
'nome_do_método': métodos de interface não podem levar a uma lista de argumentos variáveis  
  
 Um método de interface não pode levar a uma lista de argumentos variável. Por exemplo, a seguinte definição de interface gera C3120:  
  
```  
// C3120.cpp  
__interface A {  
int X(int i, ...);    // C3120  
};  
  
int main(void) { return(0); }  
```