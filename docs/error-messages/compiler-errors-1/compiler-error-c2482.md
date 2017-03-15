---
title: C2482 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2482
dev_langs:
- C++
helpviewer_keywords:
- C2482
ms.assetid: 98c87da2-625c-4cc2-9bf7-78d15921e779
caps.latest.revision: 9
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
ms.openlocfilehash: 6fe5215311dc41672379b1d62d5a24b9f4bb07b9
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2482"></a>C2482 de erro do compilador
'identifier': inicialização dinâmica de dados 'thread' não permitidos  
  
 Variáveis declaradas com o `thread` atributo não pode ser inicializado com uma expressão que requer avaliação do tempo de execução. Uma expressão estática é necessário para inicializar `thread` dados.  
  
 O exemplo a seguir gera C2482:  
  
```  
// C2482.cpp  
// compile with: /c  
#define Thread __declspec( thread )  
Thread int tls_i = tls_i;   // C2482  
  
int j = j;   // OK in C++; C error  
Thread int tls_i = sizeof( tls_i );   // Okay in C and C++  
```
