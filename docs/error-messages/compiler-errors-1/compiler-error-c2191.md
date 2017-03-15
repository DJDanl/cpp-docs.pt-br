---
title: C2191 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2191
dev_langs:
- C++
helpviewer_keywords:
- C2191
ms.assetid: 051b8350-e5de-4f51-ab6e-96d32366bcef
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
ms.openlocfilehash: 930b2b489edca0f9aef3a1b7f663100b1cb10bf7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2191"></a>C2191 de erro do compilador
segunda lista de parâmetros mais longa que a primeira  
  
 Uma função C foi declarada uma segunda vez com uma lista mais longa do parâmetro. C não oferece suporte a funções sobrecarregadas.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2191:  
  
```  
// C2191.c  
// compile with: /Za /c  
void func( int );  
void func( int, float );   // C2191 different parameter list  
void func2( int, float );   // OK  
```
