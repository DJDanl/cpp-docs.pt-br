---
title: C3898 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3898
dev_langs:
- C++
helpviewer_keywords:
- C3898
ms.assetid: d9a90df6-87e4-4fe7-ab01-c226ee86bf10
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: baeb6e97549bb55212d336e9f832152abaf7db68
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33270710"
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