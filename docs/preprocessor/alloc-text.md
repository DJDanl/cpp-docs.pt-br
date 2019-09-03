---
title: Pragma alloc_text
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.alloc_text
- alloc_text_CPP
helpviewer_keywords:
- alloc_text pragma
- pragmas, alloc_text
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
ms.openlocfilehash: 7ddb12b39e068dea42f7a47f7fd937424be43725
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216345"
---
# <a name="alloc_text-pragma"></a>Pragma alloc_text

Nomeia a seção de código onde as definições de função especificadas devem residir. O pragma deve estar entre um declarador de função e a definição de função para as funções nomeadas.

## <a name="syntax"></a>Sintaxe

> **#pragma alloc_text (** "*textsection*" **,** *function1* [ **,** *function2* ...] **)**

## <a name="remarks"></a>Comentários

O pragma de **alloc_text** não lida C++ com funções de membro nem com funções sobrecarregadas. Ele é aplicável somente a funções declaradas com vínculo C — ou seja, funções declaradas com a especificação de vinculação **"C" externa** . Se você tentar usar esse pragma em uma função com vinculação C++, um erro do compilador será gerado.

Como não há suporte `__based` para o endereçamento de função usando, a especificação de locais de seção requer o uso do pragma **alloc_text** . O nome especificado por *textseção* deve ser colocado entre aspas duplas.

O pragma **alloc_text** deve aparecer após as declarações de qualquer uma das funções especificadas e antes das definições dessas funções.

As funções referenciadas em um pragma **alloc_text** devem ser definidas no mesmo módulo que o pragma. Caso contrário, se uma função indefinida for posteriormente compilada em uma seção de texto diferente, o erro poderá ou não ser detectado. Embora o programa seja executado corretamente no geral, a função não será alocada nas seções desejadas.

Outras limitações no **alloc_text** são as seguintes:

- Ele não pode ser usado dentro de uma função.

- Deve ser usado depois que a função é declarada, mas antes de a função ser definida.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
