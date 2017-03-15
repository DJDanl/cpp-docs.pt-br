---
title: C2673 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2673
dev_langs:
- C++
helpviewer_keywords:
- C2673
ms.assetid: 780230c0-619b-4a78-b01d-ff5886306741
caps.latest.revision: 8
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
ms.openlocfilehash: 58b8a9c1f39e17edd7359100d341a6da4b83ce82
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2673"></a>C2673 de erro do compilador
'function': funções globais não tem 'nesse' ponteiros  
  
 Uma função global tentou acessar `this`.  
  
 O exemplo a seguir gera C2673:  
  
```  
// C2673.cpp  
int main() {  
   this = 0;   // C2673  
}  
```
