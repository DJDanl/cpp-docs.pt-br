---
title: Compilador (nível 2) do aviso C4056 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4056
dev_langs:
- C++
helpviewer_keywords:
- C4056
ms.assetid: a3c3a9b8-ec30-452d-96cb-3694adcce789
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6bf5a5855d0b4291105826679e2ae81ed6d69e5f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-2-c4056"></a>Compilador C4056 de aviso (nível 2)
Estouro em aritmética de constante de ponto de flutuante  
  
 Aritmética de constante de ponto flutuante gera um resultado que excede o valor máximo permitido.  
  
 Esse aviso pode ser causado por otimizações de compilador executadas durante a aritmética de constante. Você pode ignorar com segurança este aviso se ela desaparece quando você desativar a otimização ([/Od](../../build/reference/od-disable-debug.md)).  
  
 O exemplo a seguir gera C4056:  
  
```  
// C4056.cpp  
// compile with: /W2 /LD  
#pragma warning (default : 4056)  
float fp_val = 1.0e300 * 1.0e300;   // C4056  
```