---
title: "Compilador aviso (nível 3) C4357 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4357
dev_langs:
- C++
helpviewer_keywords:
- C4357
ms.assetid: 9259c633-3c02-4900-b94a-2d8d366d61cd
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
ms.openlocfilehash: 1337d3861e6cb73bd4a7c44b77dbe2ef1e539d91
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4357"></a>Compilador C4357 de aviso (nível 3)
argumento de matriz de parâmetro na lista de argumentos formais para delegar 'del' ignorado ao gerar 'function'  
  
 O `ParamArray` atributo foi ignorado, e `function`não pode ser chamado com argumentos de variável.  
  
 O exemplo a seguir gera C4357:  
  
```  
// C4357.cpp  
// compile with: /clr /W3 /c  
using namespace System;  
public delegate void f(int i, ... array<Object^>^ varargs);   // C4357  
  
public delegate void g(int i, array<Object^>^ varargs);   // OK  
```
