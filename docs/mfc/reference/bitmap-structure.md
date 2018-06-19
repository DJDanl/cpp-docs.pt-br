---
title: Estrutura BITMAP | Microsoft Docs
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
ms.openlocfilehash: fa8bb4ab914b4e05eb21cfc45a243328d32bb6d8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33351631"
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
 Especifica o tipo de bitmap. Para bitmaps lógico, esse membro deve ser 0.  
  
 *bmWidth*  
 Especifica a largura de bitmap em pixels. A largura deve ser maior que 0.  
  
 *bmHeight*  
 Especifica a altura do bitmap em linhas de varredura. A altura deve ser maior que 0.  
  
 *bmWidthBytes*  
 Especifica o número de bytes em cada linha de varredura. Esse valor deve ser um número par, pois a interface gráfica de dispositivo (GDI) pressupõe que os valores de bit de um bitmap formam uma matriz de inteiros (2 bytes). Em outras palavras, **bmWidthBytes** \* 8 deve ser o próximo múltiplo de 16 maior que ou igual ao valor obtido quando o **bmWidth** membro é multiplicado pelo **bmBitsPixel**  membro.  
  
 *bmPlanes*  
 Especifica o número de planos de cores no bitmap.  
  
 *bmBitsPixel*  
 Especifica o número de bits de cor adjacentes em cada plano necessário para definir um pixel.  
  
 *bmBits*  
 Aponta para o local dos valores de bit do bitmap. O **bmBits** membro deve ser um ponteiro longo para uma matriz de valores de 1 byte.  
  
## <a name="remarks"></a>Comentários  
 Os formatos de bitmap usada atualmente são monocromática e cor. O bitmap monocromático usa um formato de 1 bit, o plano de 1. Cada exame é um múltiplo de 16 bits.  
  
 Verificações são organizadas da seguinte maneira para um bitmap monocromático da altura *n*:  
  
 `Scan 0`  
  
 `Scan 1`  
  
 `.`  
  
 `.`  
  
 `.`  
  
 `Scan n-2`  
  
 `Scan n-1`  
  
 Os pixels em um dispositivo monocromático são black ou em branco. Se o bit correspondente no bitmap for 1, o pixel é ativado (branco). Se o bit correspondente no bitmap for 0, o pixel está desativado (preto).  
  
 Todos os dispositivos oferecem suporte a bitmaps que têm o **RC_BITBLT** bit é definido **RASTERCAPS** índice da [CDC::GetDeviceCaps](../../mfc/reference/cdc-class.md#getdevicecaps) função de membro.  
  
 Cada dispositivo tem seu próprio formato de cor exclusiva. Para transferir um bitmap de um dispositivo para outro, use o [GetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd144879) e [SetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd162973) funções do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect)
