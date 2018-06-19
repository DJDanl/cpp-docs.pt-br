---
title: Compilador aviso (nível 3) C4390 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4390
dev_langs:
- C++
helpviewer_keywords:
- C4390
ms.assetid: c95c2f1b-9bce-4b1f-a80c-565d4cde0b1e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d052a1fa6124aa1518cddec00566e14668fe111d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33290082"
---
# <a name="compiler-warning-level-3-c4390"></a>Compilador C4390 de aviso (nível 3)
';': vazio instrução controlada encontrada; Isso é a intenção?  
  
 Um ponto e vírgula foi encontrado após uma instrução de controle que não contém instruções.  
  
 Se você obtiver C4390 devido a uma macro, você deve usar o [aviso](../../preprocessor/warning.md) pragma desabilitar C4390 no módulo que contém a macro.  
  
 O exemplo a seguir gera C4390:  
  
```  
// C4390.cpp  
// compile with: /W3  
int main() {  
   int i = 0;  
   if (i);   // C4390  
      i++;  
}  
```