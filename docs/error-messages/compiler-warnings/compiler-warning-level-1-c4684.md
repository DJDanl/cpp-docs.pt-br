---
title: "Compilador (nível 1) de aviso C4684 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4684
dev_langs: C++
helpviewer_keywords: C4684
ms.assetid: e95f1a83-2784-4b05-ae94-12148e056e26
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 39b75bf873ed2c3c89bcc6fd3fda2df1695ef1b2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4684"></a>Compilador C4684 de aviso (nível 1)
'attribute': aviso!! atributo pode causar a geração de código inválido: use com cuidado  
  
 Você usou um atributo que normalmente não deve ser usado.  
  
 O exemplo a seguir gera C4684:  
  
```  
// C4684.cpp  
// compile with: /W1 /LD  
 [module(name="xx")]; // C4684 expected  
[no_injected_text];  
```