---
title: unaligned | Microsoft Docs
ms.custom: ''
ms.date: 03/09/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __unaligned_cpp
dev_langs:
- C++
helpviewer_keywords:
- __unaligned keyword [C++]
ms.assetid: 0cd83aad-1840-47e3-ad33-59bfcbe6375b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d73b082b9f41d03eb0b1a8c9fe772351ff4da91f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="unaligned"></a>__unaligned

**Específicos do Microsoft**. Quando você declara um ponteiro com o modificador `__unaligned`, o compilador presume que o ponteiro aborda os dados que não são alinhados. Consequentemente, o código apropriado de plataforma é gerado para manipular leituras não alinhadas e grava através do ponteiro.

## <a name="remarks"></a>Comentários

Esse modificador descreve o alinhamento dos dados endereçados pelo ponteiro; o ponteiro em si deve ser alinhado.

A necessidade do `__unaligned` palavra-chave varia por plataforma e o ambiente. Falha ao marcar dados adequadamente pode resultar em problemas desde penalidades de desempenho para falhas de hardware. O `__unaligned` modificador não é válido para o x86 de plataforma.

Para obter mais informações sobre alinhamento, consulte:

- [align](../cpp/align-cpp.md)

- [Operador __alignof](../cpp/alignof-operator.md)

- [pack](../preprocessor/pack.md)

- [/Zp (alinhamento de membro do struct)](../build/reference/zp-struct-member-alignment.md)

- [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md)

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)
