---
title: "Compilador (nível 1) de aviso C4810 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4810
dev_langs:
- C++
helpviewer_keywords:
- C4810
ms.assetid: 39e2cae0-9c1c-4ac1-aaa0-5f661d06085b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 652aef44e86e1395ae9faa1d29d3ffe99473c76c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4810"></a>Compilador C4810 de aviso (nível 1)
valor de pragma Pack (show) o usuário = = n  
  
 Esse aviso é emitido quando você usa o **Mostrar** opção do [pacote](../../preprocessor/pack.md) pragma. *n*é o valor atual do pacote.  
  
 Por exemplo, o código a seguir mostra como o aviso C4810 funciona com o pragma pack:  
  
```  
// C4810.cpp  
// compile with: /W1 /LD  
// C4810 expected  
#pragma pack(show)  
#pragma pack(4)  
#pragma pack(show)  
```