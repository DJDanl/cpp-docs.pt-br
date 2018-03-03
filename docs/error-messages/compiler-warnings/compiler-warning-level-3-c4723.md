---
title: "Compilador aviso (nível 3) C4723 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4723
dev_langs:
- C++
helpviewer_keywords:
- C4723
ms.assetid: 07669d14-3fd8-4a43-94bc-b61c50e58460
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b24d189f33bd566e0fc734754cae69730b58201d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4723"></a>Compilador C4723 de aviso (nível 3)
possível divisão por 0  
  
 O segundo operando em uma operação de divisão é avaliada como zero em tempo de compilação, fornecendo resultados indefinidos.  
  
 Esse aviso é emitido somente quando usar [/Og](../../build/reference/og-global-optimizations.md) ou uma opção de otimização que implica /Og.  
  
 O compilador pode ter gerado o operando zero.