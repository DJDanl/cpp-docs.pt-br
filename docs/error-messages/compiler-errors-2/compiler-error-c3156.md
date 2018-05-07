---
title: C3156 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3156
dev_langs:
- C++
helpviewer_keywords:
- C3156
ms.assetid: 1876da78-b94e-4af7-9795-28f72b209b3e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9557043bac056435dd53b210359e7bb72b29b6d7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3156"></a>C3156 de erro do compilador
'class': você não pode ter uma definição de local de um serviço ou tipo de WinRT  
  
 Uma função não pode conter a definição ou declaração de gerenciada ou WinRT class, struct ou interface.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3156.  
  
```  
// C3156.cpp  
// compile with: /clr /c  
void f() {  
   ref class X {};   // C3156  
   ref class Y;   // C3156  
}  
```  
