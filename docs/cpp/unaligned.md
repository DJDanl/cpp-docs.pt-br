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
ms.openlocfilehash: 8eb1b93aa55601125600b6c69d9bff3d9ca43aa3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62244110"
---
# <a name="unaligned"></a>__unaligned

**Específico da Microsoft**. Quando você declara um ponteiro com o **unaligned** modificador, o compilador pressupõe que o ponteiro aborda os dados que não estão alinhados. Consequentemente, o código de plataforma apropriada é gerado para lidar com leituras não alinhadas e grava através do ponteiro.

## <a name="remarks"></a>Comentários

Esse modificador descreve o alinhamento dos dados resolvidos pelo ponteiro; o ponteiro em si é considerado alinhado.

A necessidade do **unaligned** palavra-chave varia por plataforma e o ambiente. Falha ao marcar os dados adequadamente pode resultar em problemas, desde as penalidades de desempenho para falhas de hardware. O **unaligned** modificador não é válido para o x86 de plataforma.

Para compatibilidade com versões anteriores, **_unaligned** é um sinônimo de **unaligned** , a menos que a opção de compilador [/Za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) é especificado.

Para obter mais informações sobre alinhamento, consulte:

- [align](../cpp/align-cpp.md)

- [Operador __alignof](../cpp/alignof-operator.md)

- [pack](../preprocessor/pack.md)

- [/Zp (alinhamento de membro do struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento da estrutura](../build/x64-software-conventions.md#examples-of-structure-alignment)

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)