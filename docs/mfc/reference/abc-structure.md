---
title: Estrutura ABC
ms.date: 11/04/2016
f1_keywords:
- ABC
helpviewer_keywords:
- ABC structure [MFC]
ms.assetid: 32663839-c3b7-4f47-896c-b15329c96bc8
ms.openlocfilehash: f899a84ddbe5ca3ec3abd4dff135a585aa61eaa9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50549559"
---
# <a name="abc-structure"></a>Estrutura ABC

O `ABC` estrutura contém a largura de um caractere em uma fonte TrueType.

## <a name="syntax"></a>Sintaxe

```
typedef struct _ABC { /* abc */
    int abcA;
    UINT abcB;
    int abcC;
} ABC;
```

#### <a name="parameters"></a>Parâmetros

*abcA*<br/>
Especifica o espaçamento entre um caractere. O espaçamento de um é a distância para adicionar à posição atual antes de desenhar o glifo de caracteres.

*abcB*<br/>
Especifica o espaçamento de B do caractere. O espaçamento de B é a largura da parte desenhado de glifo de caracteres.

*abcC*<br/>
Especifica o espaçamento de C do caractere. O espaçamento de C é a distância para adicionar à posição atual para fornecer espaço em branco à direita do glifo de caracteres.

## <a name="remarks"></a>Comentários

A largura total de um caractere é a soma dos espaços de A, B e C. O r ou o espaço de C pode ser negativo para indicar underhangs ou overhangs.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDC::GetCharABCWidths](../../mfc/reference/cdc-class.md#getcharabcwidths)

