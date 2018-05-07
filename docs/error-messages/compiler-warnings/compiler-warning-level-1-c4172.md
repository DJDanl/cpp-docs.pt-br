---
title: Compilador (nível 1) de aviso C4172 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4172
dev_langs:
- C++
helpviewer_keywords:
- C4172
ms.assetid: a8d2bf65-d8b1-4fe3-8340-a223d7e7fde6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 746442638820d0c81144611a678996dc4c8483b0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4172"></a>Compilador C4172 de aviso (nível 1)
retornando o endereço da variável local ou temporário  
  
 Uma função retorna o endereço de um objeto temporário ou variável local. Variáveis locais e objetos temporários são destruídos quando uma função retorna, para que o endereço retornado não é válido.  
  
 Recrie a função de forma que ele não retorna o endereço de um objeto local.  
  
 O exemplo a seguir gera C4172:  
  
```  
// C4172.cpp  
// compile with: /W1 /LD  
float f = 10;  
  
const double& bar() {  
// try the following line instead  
// const float& bar() {  
   return f;   // C4172  
}  
```