---
title: Erro do compilador C2919 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2919
dev_langs:
- C++
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5d6ee01e32cd1855855fa6ac071af159be8bac0d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106825"
---
# <a name="compiler-error-c2919"></a>Erro do compilador C2919

'type': operadores não podem ser usados na superfície publicada de um tipo WinRT

O sistema de tipo de tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície publicada de um tipo. Isso ocorre porque nem todas as linguagens podem consumir funções de membro do operador. Você pode criar funções de membro que podem ser chamadas do código C++ na mesma unidade de compilação ou de classe do operador particular ou interno.

Para corrigir esse problema, remova a função de operador de membro da interface pública ou alterá-lo para uma função de membro nomeadas. Por exemplo, em vez de `operator==`, nomeie a função de membro `Equals`.