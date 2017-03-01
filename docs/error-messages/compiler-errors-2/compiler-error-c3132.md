---
title: C3132 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3132
dev_langs:
- C++
helpviewer_keywords:
- C3132
ms.assetid: d54a3d12-336a-4ed0-ad4e-43cddac33b5e
caps.latest.revision: 10
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
ms.openlocfilehash: e02dfeabf72e1500ad0a2855839dc5b00b1367dd
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3132"></a>C3132 de erro do compilador
'parâmetro de função': matrizes de parâmetros só podem ser aplicadas a um argumento formal do tipo 'matriz unidimensional gerenciado'  
  
 O [ParamArray](https://msdn.microsoft.com/en-us/library/system.paramarrayattribute.aspx) atributo foi aplicado a um parâmetro que não era uma matriz de dimensão única.  
  
 O exemplo a seguir gera C3132:  
  
```  
// C3132.cpp  
// compile with: /clr /c  
using namespace System;  
void f( [ParamArray] Int32[,] );   // C3132  
void g( [ParamArray] Int32[] );   // C3132  
  
void h( [ParamArray] array<Char ^> ^ MyArray );   // OK  
  
```
