---
title: Compilador (nível 4) de aviso C4611 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4611
dev_langs:
- C++
helpviewer_keywords:
- C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5946c10b5e0e0e7e08f1ee37c77120896937adb1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4611"></a>Compilador C4611 de aviso (nível 4)
interação entre 'function' e destruição de objeto C++ é não portátil  
  
 Em algumas plataformas, funções que incluam **catch** pode não oferecer suporte a semântica de objeto C++ de destruição quando estiver fora do escopo.  
  
 Para evitar um comportamento inesperado, evite usar **catch** em funções que tenham construtores e destruidores.  
  
 Esse aviso é emitido somente uma vez; consulte [aviso de pragma](../../preprocessor/warning.md).