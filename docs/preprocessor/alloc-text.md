---
title: alloc_text (pragma)
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.alloc_text
- alloc_text_CPP
helpviewer_keywords:
- alloc_text pragma
- pragmas, alloc_text
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
ms.openlocfilehash: c638c2026a493453aeb5aff00ba6273efb5f184e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219437"
---
# <a name="alloc_text-pragma"></a>alloc_text (pragma)

Nomeia a seção de código onde as definições de função especificadas devem residir. O pragma deve estar entre um declarador de função e a definição de função para as funções nomeadas.

## <a name="syntax"></a>Sintaxe

> **#pragma alloc_text (** "*textseção*" **,** *function1* [**,** *function2* ...] **)**

## <a name="remarks"></a>Comentários

O **alloc_text** pragma não trata funções de membro do C++ ou funções sobrecarregadas. Ele é aplicável somente a funções declaradas com vínculo C — ou seja, funções declaradas com a especificação de vinculação **"C" externa** . Se você tentar usar esse pragma em uma função com vinculação C++, um erro do compilador será gerado.

Como **`__based`** não há suporte para o endereçamento de função usando, a especificação de locais de seção requer o uso do **alloc_text** pragma. O nome especificado por *textseção* deve ser colocado entre aspas duplas.

O **alloc_text** pragma deve aparecer após as declarações de qualquer uma das funções especificadas e antes das definições dessas funções.

As funções referenciadas em um **alloc_text** pragma devem ser definidas no mesmo módulo que o pragma. Caso contrário, se uma função indefinida for posteriormente compilada em uma seção de texto diferente, o erro poderá ou não ser detectado. Embora o programa seja executado corretamente no geral, a função não será alocada nas seções desejadas.

Outras limitações no **alloc_text** são as seguintes:

- Ele não pode ser usado dentro de uma função.

- Deve ser usado depois que a função é declarada, mas antes de a função ser definida.

## <a name="see-also"></a>Confira também

[Diretivas Pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
