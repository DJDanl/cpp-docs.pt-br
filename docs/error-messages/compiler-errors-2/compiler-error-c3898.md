---
title: C3898 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3898
dev_langs: C++
helpviewer_keywords: C3898
ms.assetid: d9a90df6-87e4-4fe7-ab01-c226ee86bf10
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b961c7eb788d1938263025e442a3e336a8ce3567
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3898"></a>C3898 de erro do compilador
'var': membros de dados de tipo só podem ser membros de tipos gerenciados  
  
 Um [initonly](../../dotnet/initonly-cpp-cli.md) membro de dados foi declarado em uma classe nativo.  Um `initonly` membro de dados só pode ser declarado em uma classe CLR.  
  
 O exemplo a seguir gera C3898:  
  
```  
// C3898.cpp  
// compile with: /clr  
struct Y1 {  
   initonly  
   static int data_var = 9;   // C3898  
};  
```  
  
 Possível solução:  
  
```  
// C3898b.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   initonly  
   static int data_var = 9;  
};  
```