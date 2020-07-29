---
title: Convenções de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- calling conventions
ms.assetid: 11b1e45c-8fd1-420b-bca0-a19e294c1d85
ms.openlocfilehash: d351ae064b8c9bdd0599a1d6981166371a62af58
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216603"
---
# <a name="calling-conventions"></a>Convenções de chamada

O compilador Visual C/C++ fornece várias convenções diferentes para chamar funções internas e externos. Entender essas abordagens diferentes pode ajudar a depurar seu programa e a vincular seu código a rotinas de linguagem de assembly.

Os tópicos neste assunto explicam as diferenças entre as convenções de chamada, como os argumentos são passados, e como os valores são retornados por funções. Também são abordadas chamadas de função naked, um recurso avançado que permite escrever seu próprio código de prólogo e epílogo.

Para obter informações sobre como chamar convenções para processadores x64, consulte [Convenção de chamada](../build/x64-calling-convention.md).

## <a name="topics-in-this-section"></a>Tópicos desta seção

- [Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md) ( **`__cdecl`** , **`__stdcall`** , **`__fastcall`** e outros)

- [Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)

- [Usando chamadas de função naked para escrever o código de prólogo/epílogo personalizado](../cpp/naked-function-calls.md)

- [Coprocessador de ponto flutuante e convenções de chamada](../cpp/floating-point-coprocessor-and-calling-conventions.md)

- [Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)

## <a name="see-also"></a>Confira também

[Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)
