---
title: Estrutura BITMAP
ms.date: 11/04/2016
f1_keywords:
- BITMAP
helpviewer_keywords:
- BITMAP structure [MFC]
ms.assetid: 05d33b4d-7232-4643-a108-87dda8ff5f22
ms.openlocfilehash: 1a1079ea0b032f5d28995dc0e3b15b5ba6d16376
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50576079"
---
# <a name="bitmap-structure"></a>Estrutura BITMAP

O **BITMAP** estrutura define a altura, largura, formato de cor e valores de bit de um bitmap lógico **.**

## <a name="syntax"></a>Sintaxe

```
typedef struct tagBITMAP {  /* bm */
    int bmType;
    int bmWidth;
    int bmHeight;
    int bmWidthBytes;
    BYTE bmPlanes;
    BYTE bmBitsPixel;
    LPVOID bmBits;
} BITMAP;
```

#### <a name="parameters"></a>Parâmetros

*bmType*<br/>
Especifica o tipo de bitmap. Para bitmaps de lógica, esse membro deve ser 0.

*bmWidth*<br/>
Especifica a largura do bitmap em pixels. A largura deve ser maior que 0.

*bmHeight*<br/>
Especifica a altura do bitmap em linhas de varredura. A altura deve ser maior que 0.

*bmWidthBytes*<br/>
Especifica o número de bytes em cada linha de varredura. Esse valor deve ser um número par, pois a graphics device interface (GDI) pressupõe que os valores de bit de um bitmap formam uma matriz de valores de (2 bytes) de inteiros. Em outras palavras, *bmWidthBytes* \* 8 deve ser o próximo múltiplo de 16 maior que ou igual ao valor obtido quando o *bmWidth* membro é multiplicado pela *bmBitsPixel*  membro.

*bmPlanes*<br/>
Especifica o número de planos de cores no bitmap.

*bmBitsPixel*<br/>
Especifica o número de bits adjacentes de cor em cada plano necessário para definir um pixel.

*bmBits*<br/>
Aponta para o local dos valores de bit do bitmap. O *bmBits* membro deve ser um ponteiro longo para uma matriz de valores de 1 byte.

## <a name="remarks"></a>Comentários

Os formatos de bitmap usada atualmente são monocromática e cor. O bitmap monocromático usa um formato de 1 bit, o plano de 1. Cada exame é um múltiplo de 16 bits.

Verificações são organizadas da seguinte maneira para um bitmap monocromático da altura *n*:

```
Scan 0
Scan 1
.
.
.
Scan n-2
Scan n-1
```

Os pixels em um dispositivo monocromático são ambos preto ou branco. Se o bit correspondente no bitmap é 1, o pixel é ativado (branco). Se o bit correspondente no bitmap for 0, o pixel é desativado (preto).

Todos os dispositivos dão suporte a bitmaps que possuem o conjunto de bits de RC_BITBLT no índice de RASTERCAPS a [CDC::GetDeviceCaps](../../mfc/reference/cdc-class.md#getdevicecaps) função de membro.

Cada dispositivo tem seu próprio formato de cor exclusiva. Para transferir um bitmap de um dispositivo para outro, use o [GetDIBits](/windows/desktop/api/wingdi/nf-wingdi-getdibits) e [SetDIBits](/windows/desktop/api/wingdi/nf-wingdi-setdibits) funções do Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** wingdi

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect)
