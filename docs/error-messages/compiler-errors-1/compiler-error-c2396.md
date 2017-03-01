---
title: C2396 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2396
dev_langs:
- C++
helpviewer_keywords:
- C2396
ms.assetid: 1b515ef6-7af4-400f-b4ed-564313ea15f6
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: abb0a9a56f5ffeea6a818ab5d3247fd18789df8c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2396"></a>C2396 de erro do compilador
' your_type::operator'type ': CLR ou WinRT functionnot de conversão definida pelo usuário válido. Deve converter de ou converta: ' t ^', ' t ^ %', ' t ^ < / ', onde T = 'your_type'  
  
 Uma função de conversão em um tempo de execução do Windows ou um tipo gerenciado não possui pelo menos um parâmetro cujo tipo é o mesmo que o tipo que contém a função de conversão.  
  
 O exemplo a seguir gera C2396 e mostra como corrigi-lo:  
  
```  
// C2396.cpp  
// compile with: /clr /c  
  
ref struct Y {  
   static operator int(char c);   // C2396  
  
   // OK  
   static operator int(Y^ hY);  
   // or  
   static operator Y^(char c);  
};  
```
