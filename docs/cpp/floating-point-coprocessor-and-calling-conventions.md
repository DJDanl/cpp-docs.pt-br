---
title: Coprocessador de ponto flutuante e convenções de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- floating-point numbers [C++]
- floating-point coprocessor
ms.assetid: 3cc6615a-b308-4cf7-9570-83e192a832b3
ms.openlocfilehash: 09358ee36da7e5a86c214789fa7fd0687e9b8825
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231189"
---
# <a name="floating-point-coprocessor-and-calling-conventions"></a>Coprocessador de ponto flutuante e convenções de chamada

Se você estiver escrevendo rotinas de assembly para o coprocessador de ponto flutuante, você deve preservar a palavra de controle de ponto flutuante e limpar a pilha do coprocessador, a menos que você esteja retornando um **`float`** **`double`** valor ou (que sua função deve retornar em St (0)).

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)
