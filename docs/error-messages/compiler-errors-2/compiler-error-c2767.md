---
title: C2767 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2767
dev_langs:
- C++
helpviewer_keywords:
- C2767
ms.assetid: e8f84178-a160-4d71-a236-07e4fcc11e96
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5ac628d1e02c53b0ed0872873ef23ef708df982
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33234777"
---
# <a name="compiler-error-c2767"></a>C2767 de erro do compilador
gerenciado ou WinRTarray dimensão incompatibilidade: esperado argumentos de N - M fornecido  
  
 Um gerenciado ou declaração de matriz WinRT ill foi formada. Para obter mais informações, consulte [matriz](../../windows/arrays-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C2767 e mostra como corrigi-lo:  
  
```  
// C2767.cpp  
// compile with: /clr  
int main() {  
   array<int> ^p1 = new array<int>(2,3); // C2767  
   array<int> ^p2 = new array<int>(2);   // OK  
}  
```