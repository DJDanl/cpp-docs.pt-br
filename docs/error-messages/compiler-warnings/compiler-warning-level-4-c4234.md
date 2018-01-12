---
title: "Compilador (nível 4) de aviso C4234 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4234
dev_langs: C++
helpviewer_keywords: C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 68f4b2c3b51caf5e0438c2ead293823885b73157
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4234"></a>Compilador C4234 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' reservada para uso futuro  
  
 O compilador ainda não implementa a palavra-chave que você usou.  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema do aviso de nível 4, C4234  
  
```  
#pragma warning(2:4234)  
```  
  
 no arquivo de código fonte.