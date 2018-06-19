---
title: Compilador aviso (nível 3) C4723 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4723
dev_langs:
- C++
helpviewer_keywords:
- C4723
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c5f91bbdc60ab1901c4afe4d5bea9f3258692ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33296608"
---
# <a name="compiler-warning-level-3-c4723"></a>Compilador C4723 de aviso (nível 3)
possível divisão por 0  
  
 O segundo operando em uma operação de divisão é avaliada como zero em tempo de compilação, fornecendo resultados indefinidos.  
  
 Esse aviso é emitido somente quando usar [/Og](../../build/reference/og-global-optimizations.md) ou uma opção de otimização que implica /Og.  
  
 O compilador pode ter gerado o operando zero.