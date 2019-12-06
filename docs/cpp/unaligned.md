---
title: __unaligned
ms.date: 12/17/2018
f1_keywords:
- __unaligned_cpp
- __unaligned
- _unaligned
helpviewer_keywords:
- __unaligned keyword [C++]
ms.assetid: 0cd83aad-1840-47e3-ad33-59bfcbe6375b
ms.openlocfilehash: 1090a0f3345f749a2afbd80566a9af7b9ea32d53
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857249"
---
# <a name="__unaligned"></a>__unaligned

**Específico da Microsoft**. Quando você declara um ponteiro com o modificador **__unaligned** , o compilador pressupõe que o ponteiro endereça os dados que não estão alinhados. Consequentemente, o código apropriado para a plataforma é gerado para lidar com leituras e gravações não alinhadas pelo ponteiro.

## <a name="remarks"></a>Comentários

Este modificador descreve o alinhamento dos dados endereçados pelo ponteiro; o ponteiro em si é considerado alinhado.

A necessidade da palavra-chave **__unaligned** varia de acordo com a plataforma e o ambiente. A falha na marcação dos dados de forma adequada pode resultar em problemas que variam de penalidades de desempenho a falhas de hardware. O modificador de **__unaligned** não é válido para a plataforma x86.

Para compatibilidade com versões anteriores, **_unaligned** é um sinônimo para **__unaligned** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

Para obter mais informações sobre alinhamento, consulte:

- [align](../cpp/align-cpp.md)

- [Operador __alignof](../cpp/alignof-operator.md)

- [pack](../preprocessor/pack.md)

- [/Zp (alinhamento de membro do struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento da estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment)

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)