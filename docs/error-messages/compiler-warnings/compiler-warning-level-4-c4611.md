---
title: Aviso do compilador (nível 4) C4611
ms.date: 11/04/2016
f1_keywords:
- C4611
helpviewer_keywords:
- C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
ms.openlocfilehash: 2ce261b36344126d541a9b453c88f7f8289ecba0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87214328"
---
# <a name="compiler-warning-level-4-c4611"></a>Aviso do compilador (nível 4) C4611

a interação entre a "função" e a destruição de objetos do C++ não é portátil

Em algumas plataformas, as funções que incluem o **`catch`** podem não dar suporte à semântica de objeto C++ de destruição quando fora do escopo.

Para evitar um comportamento inesperado, evite usar o **`catch`** em funções que têm construtores e destruidores.

Este aviso é emitido apenas uma vez; consulte o [aviso de pragma](../../preprocessor/warning.md).
