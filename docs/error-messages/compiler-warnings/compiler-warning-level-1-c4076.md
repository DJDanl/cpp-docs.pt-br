---
title: "Compilador (nível 1) de aviso C4076 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4076
dev_langs:
- C++
helpviewer_keywords:
- C4076
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7918ae093210c38bacfe89f0d4770eda2dee2e35
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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