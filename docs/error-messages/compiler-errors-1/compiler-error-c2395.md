---
title: C2395 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2395
dev_langs:
- C++
helpviewer_keywords:
- C2395
ms.assetid: 2d9e3b28-8c2c-4f41-a57f-61ef88fc2af0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 411a8d62de801591ff6a90a7bf74f3b2cfe67c7a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2395"></a>C2395 de erro do compilador
' your_type::operator'op ': CLR ou WinRT operador não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ', ' t %', ' t &', ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'  
  
 Um operador em um tempo de execução do Windows ou um tipo gerenciado não tem pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.  
  
 O exemplo a seguir gera C2395 e mostra como corrigi-lo:  
  
```  
// C2395.cpp  
// compile with: /clr /c  
value struct V {  
   static V operator *(int i, char c);   // C2395  
  
   // OK  
   static V operator *(V v, char c);  
   // or  
   static V operator *(int i, V& rv);  
};  
```