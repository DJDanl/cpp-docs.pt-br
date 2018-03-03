---
title: C2728 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2728
dev_langs:
- C++
helpviewer_keywords:
- C2728
ms.assetid: 65635f91-1cd1-46e4-9ad7-14726d0546af
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4574d3ffe02ea019a758f5b776279ea042e64697
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
