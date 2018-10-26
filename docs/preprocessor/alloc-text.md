---
title: alloc_text | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.alloc_text
- alloc_text_CPP
dev_langs:
- C++
helpviewer_keywords:
- alloc_text pragma
- pragmas, alloc_text
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d131cee2194ba139fdb99d9c0fa7ae2c922fe84d
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073806"
---
# <a name="alloctext"></a>alloc_text
Nomeia a seção de código onde as definições de função especificadas devem residir. O pragma deve estar entre um declarador de função e a definição de função para as funções nomeadas.

## <a name="syntax"></a>Sintaxe

```
#pragma alloc_text( "
textsection
", function1, ... )
```

## <a name="remarks"></a>Comentários

O **alloc_text** pragma não trata funções de membro C++ ou funções sobrecarregadas. Ele é aplicável somente às funções declaradas com vinculação C — ou seja, as funções declaradas com o **extern "C"** especificação de vinculação. Se você tentar usar esse pragma em uma função com vinculação C++, um erro do compilador será gerado.

Desde a função usando endereçamento `__based` não for compatível, especificar locais de seção requer o uso do **alloc_text** pragma. O nome especificado por *textsection* deve ser colocado entre aspas duplas.

O **alloc_text** pragma deve aparecer após as declarações de qualquer uma das funções especificadas e antes das definições dessas funções.

Funções referenciadas em uma **alloc_text** pragma deve ser definido no mesmo módulo do pragma. Se isso não for feito e uma função indefinida for compilada posteriormente em uma seção de texto diferente, o erro poderá ou não ser detectado. Embora o programa seja executado corretamente no geral, a função não será alocada nas seções desejadas.

Outra limitação ao **alloc_text** são da seguinte maneira:

- Não pode ser usado dentro de uma função.

- Deve ser usado depois que a função é declarada, mas antes de a função ser definida.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)