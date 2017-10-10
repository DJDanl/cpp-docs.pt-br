---
title: C2428 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2428
dev_langs:
- C++
helpviewer_keywords:
- C2428
ms.assetid: 74aa5714-e930-4f9e-9061-68ccce7f0d38
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: acc73e232e6e513df394875ec93cfa34911e2760
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2428"></a>C2428 de erro do compilador
'operação de ': não é permitido em operando do tipo 'bool'  
  
 Você não pode aplicar um operador de decremento para objetos do tipo `bool`.  
  
 O exemplo a seguir gera C2428:  
  
```  
// C2428.cpp  
void g(bool fFlag) {  
   --fFlag;   // C2428  
   fFlag--;   // C2428  
}  
```
