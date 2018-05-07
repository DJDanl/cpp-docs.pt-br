---
title: C2537 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2537
dev_langs:
- C++
helpviewer_keywords:
- C2537
ms.assetid: aee81d8e-300e-4a8b-b6c4-b3828398b34e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6100f77d3a1487bfa1eb12a78ac8187cec43fe64
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2537"></a>C2537 de erro do compilador
'especificador': especificação de vínculo inválida  
  
 Possíveis causas:  
  
1.  Não há suporte para o especificador de vinculação. Há suporte para apenas o especificador de ligação "C".  
  
2.  Ligação "C" é especificada mais de uma função em um conjunto de funções sobrecarregadas. Isso não é permitido.  
  
 O exemplo a seguir gera C2537:  
  
```  
// C2537.cpp  
// compile with: /c  
extern "c" void func();   // C2537  
extern "C" void func2();   // OK  
```