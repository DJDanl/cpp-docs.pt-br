---
title: Compilador (nível 1) de aviso C4076 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4076
dev_langs:
- C++
helpviewer_keywords:
- C4076
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1cfa28469e099dbf2b6bd43213073c304d0b2894
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275467"
---
# <a name="compiler-warning-level-1-c4076"></a>Compilador C4076 de aviso (nível 1)
'typemod': não pode ser usado com o tipo 'typename'  
  
 Um modificador de tipo, se ela é **assinado** ou `unsigned`, não pode ser usado com um tipo não inteiro. ***typemod*** é ignorado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4076:  
  
```  
// C4076.cpp  
// compile with: /W1 /LD  
unsigned double x;   // C4076  
```