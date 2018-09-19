---
title: Estrutura de BITMAP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- BITMAP
dev_langs:
- C++
helpviewer_keywords:
- BITMAP structure [MFC]
ms.assetid: 05d33b4d-7232-4643-a108-87dda8ff5f22
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 56e93bf1485cefed9a44e0e6260358650ab8b296
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032582"
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
 *bmType*  
 Especifica o tipo de bitmap. Para bitmaps de lógica, esse membro deve ser 0.  
  
 *bmWidth*  
 Especifica a largura do bitmap em pixels. A largura deve ser maior que 0.  
  
 *bmHeight*  
 Especifica a altura do bitmap em linhas de varredura. A altura deve ser maior que 0.  
  
 *bmWidthBytes*  
 Especifica o número de bytes em cada linha de varredura. Esse valor deve ser um número par, pois a graphics device interface (GDI) pressupõe que os valores de bit de um bitmap formam uma matriz de valores de (2 bytes) de inteiros. Em outras palavras, *bmWidthBytes* \* 8 deve ser o próximo múltiplo de 16 maior que ou igual ao valor obtido quando o *bmWidth* membro é multiplicado pela *bmBitsPixel*  membro.  
  
 *bmPlanes*  
 Especifica o número de planos de cores no bitmap.  
  
 *bmBitsPixel*  
 Especifica o número de bits adjacentes de cor em cada plano necessário para definir um pixel.  
  
 *bmBits*  
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
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect)
