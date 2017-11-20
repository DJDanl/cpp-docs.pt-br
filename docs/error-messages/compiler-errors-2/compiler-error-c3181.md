---
title: C3181 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3181
dev_langs: C++
helpviewer_keywords: C3181
ms.assetid: 5d450f8b-6cef-4452-a0c4-2076e967451d
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 84f725f64e22dc5da1736eb64696b03b0b7ea36a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3181"></a>C3181 de erro do compilador
'type': operando inválido para operador  
  
Um parâmetro inválido foi passado para o [typeid](../../windows/typeid-cpp-component-extensions.md) operador. O parâmetro deve ser um tipo gerenciado.  
  
Observe que o compilador usa aliases para tipos nativos mapeiam para tipos no common language runtime.  
  
O exemplo a seguir gera C3181:  
  
```  
// C3181a.cpp  
// compile with: /clr  
using namespace System;  
  
int main() {  
   Type ^pType1 = interior_ptr<int>::typeid;   // C3181  
   Type ^pType2 = int::typeid;   // OK  
}  
```  
