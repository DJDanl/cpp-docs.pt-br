---
title: C2086 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2086
dev_langs:
- C++
helpviewer_keywords:
- C2086
ms.assetid: 4329bf72-90c8-444c-8524-4ef75e6b2139
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
ms.openlocfilehash: bd755665cb777ec0e9ed781bf1e95605ac1d227c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2086"></a>C2086 de erro do compilador
'identifier': redefinição  
  
 O identificador está definido mais de uma vez, ou uma declaração subsequente é diferente da anterior.  
  
 C2086 também pode ser o resultado de construção incremental de um assembly referenciado do c#. Recompile o assembly c# para resolver esse erro.  
  
 O exemplo a seguir gera C2086:  
  
```  
// C2086.cpp  
main() {  
  int a;  
  int a;   // C2086 not an error in ANSI C  
}  
```
