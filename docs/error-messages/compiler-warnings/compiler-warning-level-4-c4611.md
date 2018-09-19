---
title: Compilador aviso (nível 4) C4611 | Microsoft Docs
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
ms.openlocfilehash: 723976dc8b7085ede9b3157445ff3026de6fc4b9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091043"
---
# <a name="compiler-warning-level-4-c4611"></a>Compilador aviso (nível 4) C4611

interação entre 'function' e a destruição de objeto de C++ é não portátil

Em algumas plataformas, funções, que incluem **catch** pode não oferecer suporte a semântica de objeto C++ de destruição quando estiver fora do escopo.

Para evitar comportamento inesperado, evite usar **catch** em funções que têm construtores e destruidores.

Esse aviso é emitido somente uma vez. ver [aviso pragma](../../preprocessor/warning.md).