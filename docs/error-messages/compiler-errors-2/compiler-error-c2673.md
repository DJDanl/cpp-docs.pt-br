---
title: C2673 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2673
dev_langs:
- C++
helpviewer_keywords:
- C2673
ms.assetid: 780230c0-619b-4a78-b01d-ff5886306741
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d5d819a5e0e9cc7fb5acffdd2c476d05ceb23fec
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33230561"
---
# <a name="compiler-error-c2673"></a>C2673 de erro do compilador
'function': funções globais não possuem ponteiros 'this'  
  
 Uma função global tentou acessar `this`.  
  
 O exemplo a seguir gera C2673:  
  
```  
// C2673.cpp  
int main() {  
   this = 0;   // C2673  
}  
```