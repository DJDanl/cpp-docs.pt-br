---
title: C3417 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3417
dev_langs:
- C++
helpviewer_keywords:
- C3417
ms.assetid: 3e7869ea-8948-42fb-ba30-6ccafe499c35
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9b83c3b6cf5697ca2e52f9f8ad6afdc2754edd4f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33256412"
---
# <a name="compiler-error-c3417"></a>C3417 de erro do compilador
'member': tipos de valor não podem conter funções de membro especiais definidas pelo usuário  
  
 Tipos de valor não podem conter funções como um construtor de instância padrão, destruidor ou Construtor de cópia.  
  
 O exemplo a seguir gera C3517:  
  
```  
// C3417.cpp  
// compile with: /clr /c  
value class VC {  
   VC(){}   // C3417  
  
   // OK  
   static VC(){}  
   VC(int i){}  
};  
```