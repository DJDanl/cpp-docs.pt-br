---
title: Compilador aviso (níveis 1 e 4) C4115
ms.date: 11/04/2016
f1_keywords:
- C4115
helpviewer_keywords:
- C4115
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
ms.openlocfilehash: 20e44eba3b6f6079e6f37b7cf33fa530a996e829
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462953"
---
# <a name="compiler-warning-levels-1-and-4-c4115"></a>Compilador aviso (níveis 1 e 4) C4115

'type': definição de tipo entre parênteses nomeado

O símbolo fornecido é usado para definir uma estrutura, união ou tipo enumerado dentro de uma expressão entre parênteses. O escopo da definição pode ser inesperado.

Em uma chamada de função C, a definição tem escopo global. Em uma chamada de C++, a definição tem o mesmo escopo que a função que está sendo chamado.

Esse aviso também pode ser causado por declaradores dentro dos parênteses (como protótipos) que não são expressões entre parênteses.

Este é um aviso de nível 1 com programas do C++ e programas em C compilados com compatibilidade com ANSI (/Za). Caso contrário, ele é o nível 3.