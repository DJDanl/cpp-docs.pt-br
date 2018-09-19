---
title: Compilador aviso (nível 4) C4960 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4960
dev_langs:
- C++
helpviewer_keywords:
- C4960
ms.assetid: 3b4ed286-9e8d-46f1-af0c-00ba669693a9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ed6ba083017c84cd6af05b917ff8417b0394d7c2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085713"
---
# <a name="compiler-warning-level-4-c4960"></a>Compilador aviso (nível 4) C4960

'function' é muito grande para ser analisado

Ao usar [/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md), o compilador detectou um módulo de entrada com uma função maior do que 65.535 instruções. Tal função não está disponível para otimizações guiadas por perfil.

Para resolver este aviso, reduza o tamanho da função.