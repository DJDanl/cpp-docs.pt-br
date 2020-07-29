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
ms.openlocfilehash: 2ab94a44d08165ca6e8f394278e24d7c8d201398
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223493"
---
# <a name="__unaligned"></a>__unaligned

**Específico da Microsoft**. Quando você declara um ponteiro com o **`__unaligned`** modificador, o compilador pressupõe que o ponteiro endereça os dados que não estão alinhados. Consequentemente, o código apropriado para a plataforma é gerado para lidar com leituras e gravações não alinhadas pelo ponteiro.

## <a name="remarks"></a>Comentários

Este modificador descreve o alinhamento dos dados endereçados pelo ponteiro; o ponteiro em si é considerado alinhado.

A necessidade da **`__unaligned`** palavra-chave varia de acordo com a plataforma e o ambiente. A falha na marcação dos dados de forma adequada pode resultar em problemas que variam de penalidades de desempenho a falhas de hardware. O **`__unaligned`** modificador não é válido para a plataforma x86.

Para compatibilidade com versões anteriores, **`_unaligned`** é um sinônimo para **`__unaligned`** a menos que a opção do compilador [ `/Za` \( desabilite extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

Para obter mais informações sobre alinhamento, consulte:

- [`align`](../cpp/align-cpp.md)

- [`alignof`Operador](../cpp/alignof-operator.md)

- [`pack`](../preprocessor/pack.md)

- [`/Zp`(Alinhamento de Membro struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento da estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment)

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
