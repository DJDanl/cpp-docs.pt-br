---
title: C2728 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2728
dev_langs:
- C++
helpviewer_keywords:
- C2728
ms.assetid: 65635f91-1cd1-46e4-9ad7-14726d0546af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e954ba38efc2e1ef7bc4b203c8b54876f7aae0ed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33234450"
---
# <a name="compiler-error-c2728"></a>C2728 de erro do compilador
'type': uma matriz nativa não pode conter este tipo  
  
 Sintaxe de criação de matriz foi usado para criar uma matriz de gerenciados ou objetos WinRT. Não é possível criar uma matriz de gerenciados ou objetos WinRT usando a sintaxe de matriz nativa.  
  
 Para obter mais informações, consulte [matriz](../../windows/arrays-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C2728 e mostra como corrigi-lo:  
  
```  
// C2728.cpp  
// compile with: /clr  
  
int main() {  
   int^ arr[5];   // C2728  
  
   // try the following line instead  
   array<int>^arr2;  
}  
```  
