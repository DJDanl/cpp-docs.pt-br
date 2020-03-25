---
title: Convenções de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- calling conventions
ms.assetid: 11b1e45c-8fd1-420b-bca0-a19e294c1d85
ms.openlocfilehash: 432cb1b6910db5ea735288edfbf6aa9e10f0a486
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190281"
---
# <a name="calling-conventions"></a>Convenções de chamada

O compilador Visual C/C++ fornece várias convenções diferentes para chamar funções internas e externos. Entender essas abordagens diferentes pode ajudar a depurar seu programa e a vincular seu código a rotinas de linguagem de assembly.

Os tópicos neste assunto explicam as diferenças entre as convenções de chamada, como os argumentos são passados, e como os valores são retornados por funções. Também são abordadas chamadas de função naked, um recurso avançado que permite escrever seu próprio código de prólogo e epílogo.

Para obter informações sobre como chamar convenções para processadores x64, consulte [Convenção de chamada](../build/x64-calling-convention.md).

## <a name="topics-in-this-section"></a>Tópicos desta seção

- [Passagem de argumentos e convenções de nomenclatura](../cpp/argument-passing-and-naming-conventions.md) (`__cdecl`, `__stdcall`, `__fastcall`e outros)

- [Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)

- [Usando chamadas de função Naked para escrever código prólogo/epílogo personalizado](../cpp/naked-function-calls.md)

- [Coprocessador de ponto flutuante e convenções de chamada](../cpp/floating-point-coprocessor-and-calling-conventions.md)

- [Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)

## <a name="see-also"></a>Confira também

[Modificadores específicos da Microsoft](../cpp/microsoft-specific-modifiers.md)
