---
title: Erro do compilador C2919
ms.date: 11/04/2016
f1_keywords:
- C2919
helpviewer_keywords:
- C2919
ms.assetid: 140a6db9-eb48-4c5e-84a7-a09d2653605b
ms.openlocfilehash: ab11226c8cc4629a265dd182d5f882f6b3be7e5d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160842"
---
# <a name="compiler-error-c2919"></a>Erro do compilador C2919

'type': Operadores não podem ser usados na superfície publicada de um tipo WinRT

O sistema de tipo de tempo de execução do Windows não oferece suporte a funções de membro do operador na superfície publicada de um tipo. Isso ocorre porque nem todas as linguagens podem consumir funções de membro do operador. Você pode criar funções de membro que podem ser chamadas do código C++ na mesma unidade de compilação ou de classe do operador particular ou interno.

Para corrigir esse problema, remova a função de operador de membro da interface pública ou alterá-lo para uma função de membro nomeadas. Por exemplo, em vez de `operator==`, nomeie a função de membro `Equals`.