---
title: C3273 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3273
dev_langs:
- C++
helpviewer_keywords:
- C3273
ms.assetid: 1d2ce9d9-222b-4cab-94e2-d2c1a9f5ebe0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 81f238c905b5a3257ef15da311c95efdfcac5c9f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33244700"
---
# <a name="compiler-error-c3273"></a>C3273 de erro do compilador
Finally não pode ser usado em um bloco de exceção no código não gerenciado.  
  
 O exemplo a seguir gera C3273:  
  
```  
// C3273.cpp  
// compile with: /GX  
int main()  
{     
   try  
   {  
   }  
   catch (int)  
   {  
   }  
   __finally   // C3273, remove __finally clause  
   {  
   }  
}  
```