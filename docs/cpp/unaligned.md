---
title: unaligned | Microsoft Docs
ms.custom: ''
ms.date: 10/10/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __unaligned_cpp
- __unaligned
- _unaligned
dev_langs:
- C++
helpviewer_keywords:
- __unaligned keyword [C++]
ms.assetid: 0cd83aad-1840-47e3-ad33-59bfcbe6375b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 444bc3372b22676cacb3ee89b9c0ad92000cedcc
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49161210"
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

- [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md)

## <a name="see-also"></a>Consulte também

[Palavras-chave](../cpp/keywords-cpp.md)