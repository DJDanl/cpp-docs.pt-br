---
title: C2396 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 20eca11d402265bbc81d61a8079ae9975cceef67
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2396"></a>C2396 de erro do compilador
' your_type::operator'type ': CLR ou WinRT functionnot de conversão definida pelo usuário válido. Deve converter de ou converter em: ' t ^', ' t ^ %', ' t ^ &', onde T = 'your_type'  
  
 Uma função de conversão em um tempo de execução do Windows ou um tipo gerenciado não tem pelo menos um parâmetro cujo tipo é o mesmo que o tipo que contém a função de conversão.  
  
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
