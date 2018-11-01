---
title: Estrutura NCCALCSIZE_PARAMS
ms.date: 11/04/2016
f1_keywords:
- NCCALCSIZE_PARAMS
helpviewer_keywords:
- NCCALCSIZE_PARAMS structure [MFC]
ms.assetid: 3424cd9f-806a-4089-82fb-414187589edf
ms.openlocfilehash: 3dbe1fcdb941a94876dd95a0eed86d6f4a3e15c6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50443765"
---
# <a name="nccalcsizeparams-structure"></a>Estrutura NCCALCSIZE_PARAMS

O `NCCALCSIZE_PARAMS` estrutura contém informações que um aplicativo pode usar ao processar a mensagem WM_NCCALCSIZE para calcular o tamanho, posição e conteúdo válido da área de cliente de uma janela.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagNCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
} NCCALCSIZE_PARAMS;
```

#### <a name="parameters"></a>Parâmetros

*rgrc*<br/>
Especifica uma matriz de retângulos. O primeiro contém as novas coordenadas de uma janela que tenha sido movida ou redimensionada. O segundo contém as coordenadas da janela antes que ela foi movida ou redimensionada. A terceira contém as coordenadas da área de cliente de uma janela antes que ela foi movida ou redimensionada. Se a janela é uma janela filho, as coordenadas são em relação à área de cliente da janela pai. Se a janela é uma janela de nível superior, as coordenadas são em relação à tela.

*lppos*<br/>
Aponta para um [WINDOWPOS](../../mfc/reference/windowpos-structure1.md) estrutura que contém os valores de tamanho e posição especificados na operação que causou a janela a ser movida ou redimensionada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnNcCalcSize](../../mfc/reference/cwnd-class.md#onnccalcsize)

