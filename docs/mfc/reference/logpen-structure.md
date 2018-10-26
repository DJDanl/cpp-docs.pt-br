---
title: Estrutura LOGPEN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- LOGPEN
dev_langs:
- C++
helpviewer_keywords:
- LOGPEN structure [MFC]
ms.assetid: a89e8690-6b61-4af5-990c-7c82da24f3b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e0fa2a4b422a7bd1f36fc46837adec4136b693fb
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50064948"
---
# <a name="logpen-structure"></a>Estrutura LOGPEN

O `LOGPEN` estrutura define o estilo, a largura e a cor de uma caneta, um objeto de desenho usado para desenhar linhas e bordas. O [CPen::CreatePenIndirect](../../mfc/reference/cpen-class.md#createpenindirect) função usa o `LOGPEN` estrutura.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagLOGPEN {  /* lgpn */
    UINT lopnStyle;
    POINT lopnWidth;
    COLORREF lopnColor;
} LOGPEN;
```

#### <a name="parameters"></a>Parâmetros

*lopnStyle*<br/>
Especifica o tipo de caneta. Esse membro pode ser um dos seguintes valores:

- PS_SOLID cria uma caneta sólida.

- PS_DASH cria uma caneta tracejada. (Válido somente quando a largura da caneta é 1).

- PS_DOT cria uma caneta pontilhada. (Válido somente quando a largura da caneta é 1).

- PS_DASHDOT cria pontos e traços de caneta com alternadas. (Válido somente quando a largura da caneta é 1).

- PS_DASHDOTDOT cria uma caneta com traços alternados e dos pontos duplos. (Válido somente quando a largura da caneta é 1).

- PS_NULL cria uma caneta de nula.

- Funções que especificam um retângulo delimitador de saída de PS_INSIDEFRAME cria uma caneta que desenha uma linha dentro do quadro de formas fechadas produzida por GDI (por exemplo, o `Ellipse`, `Rectangle`, `RoundRect`, `Pie`, e `Chord` membro funções). Quando esse estilo é usado com o GDI funções que não especificam um retângulo delimitador de saída (por exemplo, o `LineTo` função de membro), a área de desenho da caneta não é limitada por um quadro.

   Se uma caneta tem o estilo PS_INSIDEFRAME e uma cor que não coincide com uma cor na tabela de cores lógicas, a caneta é desenhada com uma cor pontilhada. O estilo de caneta PS_SOLID não pode ser usado para criar uma caneta com uma cor pontilhada. O estilo PS_INSIDEFRAME é idêntico ao PS_SOLID se a largura da caneta é menor ou igual a 1.

   Diferente de quando o estilo PS_INSIDEFRAME é usado com objetos GDI produzidos por funções `Ellipse`, `Rectangle`, e `RoundRect`, a linha não pode ser completamente dentro do quadro especificado.

*lopnWidth*<br/>
Especifica a largura da caneta, em unidades lógicas. Se o `lopnWidth` membro é 0, a caneta é 1 pixel de largura em dispositivos de varredura independentemente do modo de mapeamento atual.

*lopnColor*<br/>
Especifica a cor da caneta.

## <a name="remarks"></a>Comentários

O `y` o valor a [ponto](../../mfc/reference/point-structure1.md) de estrutura para o `lopnWidth` membro não é usado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CPen::CreatePenIndirect](../../mfc/reference/cpen-class.md#createpenindirect)

