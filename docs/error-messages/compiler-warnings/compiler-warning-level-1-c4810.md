---
title: Compilador (nível 1) de aviso C4810 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4810
dev_langs:
- C++
helpviewer_keywords:
- C4810
ms.assetid: 39e2cae0-9c1c-4ac1-aaa0-5f661d06085b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7a803a219520519f91605971d6fd515746cabb37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33283332"
---
# <a name="compiler-warning-level-1-c4810"></a>Compilador C4810 de aviso (nível 1)
valor de pragma Pack (show) o usuário = = n  
  
 Esse aviso é emitido quando você usa o **Mostrar** opção do [pacote](../../preprocessor/pack.md) pragma. *n* é o valor atual do pacote.  
  
 Por exemplo, o código a seguir mostra como o aviso C4810 funciona com o pragma pack:  
  
```  
// C4810.cpp  
// compile with: /W1 /LD  
// C4810 expected  
#pragma pack(show)  
#pragma pack(4)  
#pragma pack(show)  
```