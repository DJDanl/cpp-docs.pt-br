---
title: C2054 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2054
dev_langs:
- C++
helpviewer_keywords:
- C2054
ms.assetid: 37f7c612-0d7d-4728-9e67-ac4160555f48
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cfb6d7bf69885d2ac5bf59947ea9f2f70c797003
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33170369"
---
# <a name="compiler-error-c2054"></a>C2054 de erro do compilador
esperado ' (' a seguir 'Identificador'  
  
 O identificador de função é usado em um contexto que requer parênteses à direita.  
  
 Esse erro pode ser causado omitindo um sinal de igual (=) em uma inicialização complexo.  
  
 O exemplo a seguir gera C2054:  
  
```  
// C2054.c  
int array1[] { 1, 2, 3 };   // C2054, missing =  
```  
  
 Possível solução:  
  
```  
// C2054b.c  
int main() {  
   int array2[] = { 1, 2, 3 };  
}  
```