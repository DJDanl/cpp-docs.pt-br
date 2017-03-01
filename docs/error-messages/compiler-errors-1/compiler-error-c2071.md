---
title: C2071 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2071
dev_langs:
- C++
helpviewer_keywords:
- C2071
ms.assetid: f8c09255-a5c4-47e3-8089-3d875ae43cc5
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
ms.openlocfilehash: e0ee59dd73a2d53dcfc4299b6855182bace015ee
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2071"></a>C2071 de erro do compilador
"identificador": classe de armazenamento inválido  
  
 `identifier`foi declarado com inválido [classe de armazenamento](../../c-language/c-storage-classes.md). Esse erro pode ser causado quando mais de uma classe de armazenamento for especificada para um identificador ou quando a definição for incompatível com a declaração de classe de armazenamento.  
  
 Para corrigir esse problema, entender a classe de armazenamento pretendida do identificador — por exemplo, `static` ou `extern`— e corrija a declaração para corresponder.  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071.cpp  
// compile with: /c  
struct C {  
   extern int i;   // C2071  
};  
struct D {  
   int i;   // OK, no extern on an automatic  
};  
```  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071_b.cpp  
// compile with: /c  
typedef int x(int i) { return i; }   // C2071  
typedef int (x)(int);   // OK, no local definition in typedef  
```
