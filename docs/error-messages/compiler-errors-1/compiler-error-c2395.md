---
title: C2395 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2395
dev_langs:
- C++
helpviewer_keywords:
- C2395
ms.assetid: 2d9e3b28-8c2c-4f41-a57f-61ef88fc2af0
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 62ea1fb0e013f46785e08c4cf2c1711338ac4c6a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2395"></a>C2395 de erro do compilador
' your_type::operator'op ': operador CLR ou WinRT não é válido. Pelo menos um parâmetro deve ser dos seguintes tipos: ' t ', ' t %', ' t < / ', ' t ^', ' t ^ %', ' t ^ < / ', onde T = 'your_type'  
  
 Um operador em um tempo de execução do Windows ou um tipo gerenciado não possui pelo menos um parâmetro cujo tipo é o mesmo que o tipo do valor de retorno do operador.  
  
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
