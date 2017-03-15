---
title: C2383 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2383
dev_langs:
- C++
helpviewer_keywords:
- C2383
ms.assetid: 6696221d-879c-477a-a0f3-a6edc15fd3d7
caps.latest.revision: 11
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
ms.openlocfilehash: 4eaca29e4d07cb31067f5dd664420c851450e1dc
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2383"></a>C2383 de erro do compilador
'symbol': argumentos padrão não são permitidos nesse símbolo  
  
 O compilador C++ não permite argumentos padrão em ponteiros para funções.  
  
 Esse código foi aceita pelo compilador da versão anterior, mas agora retorna um erro. Para o código que funciona em todas as versões do Visual C++, não atribua um valor padrão para um argumento de ponteiro de função.  
  
 A linha a seguir gera C2383:  
  
```  
// C2383.cpp  
// compile with: /c   
void (*pf)(int = 0);   // C2383  
void (*pf)(int);   // OK  
```
