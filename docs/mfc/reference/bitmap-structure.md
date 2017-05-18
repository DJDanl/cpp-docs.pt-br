---
title: Estrutura de BITMAP | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- BITMAP
dev_langs:
- C++
helpviewer_keywords:
- BITMAP structure
ms.assetid: 05d33b4d-7232-4643-a108-87dda8ff5f22
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: cd7e63cfe9e7a0f2305ca5c3cd7c2571a080a718
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="bitmap-structure"></a>Estrutura BITMAP
O **BITMAP** estrutura define a altura, largura, formato de cor e valores dos bits de um bitmap lógico**.**  
  
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
 Especifica a largura do bitmap em pixels. A largura deve ser maior que 0.  
  
 *bmHeight*  
 Especifica a altura do bitmap em linhas de varredura. A altura deve ser maior que 0.  
  
 *bmWidthBytes*  
 Especifica o número de bytes em cada linha de varredura. Esse valor deve ser um número par, pois a interface gráfica de dispositivo (GDI) pressupõe que os valores de bit de um bitmap formam uma matriz de inteiros (2 bytes). Em outras palavras, **bmWidthBytes** \* 8 deve ser o próximo múltiplo de 16 maior ou igual ao valor obtido quando o **bmWidth** membro é multiplicado pelo **bmBitsPixel** membro.  
  
 *bmPlanes*  
 Especifica o número de planos de cores no bitmap.  
  
 *bmBitsPixel*  
 Especifica o número de bits de cor adjacentes em cada plano necessário para definir um pixel.  
  
 *bmBits*  
 Aponta para o local dos valores de bit do bitmap. O **bmBits** membro deve ser um ponteiro para uma matriz de valores de 1 byte long.  
  
## <a name="remarks"></a>Comentários  
 Os formatos de bitmap usado atualmente são monocromática e cor. O bitmap monocromático usa um formato de 1 bit, plano de 1. Cada digitalização é um múltiplo de 16 bits.  
  
 Verificações são organizadas da seguinte maneira para um bitmap monocromático da altura *n*:  
  
 `Scan 0`  
  
 `Scan 1`  
  
 `.`  
  
 `.`  
  
 `.`  
  
 `Scan n-2`  
  
 `Scan n-1`  
  
 Os pixels em um dispositivo monocromático são ambos preto ou branco. Se o bit correspondente no bitmap for 1, o pixel é ativado (branco). Se o bit correspondente no bitmap for 0, o pixel é desativado (preto).  
  
 Todos os dispositivos oferecem suporte a bitmaps que possuem o **RC_BITBLT** bit definido no **RASTERCAPS** índice da [CDC::GetDeviceCaps](../../mfc/reference/cdc-class.md#getdevicecaps) função de membro.  
  
 Cada dispositivo tem seu próprio formato de cor exclusiva. Para transferir um bitmap de um dispositivo para outro, use o [GetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd144879) e [SetDIBits](http://msdn.microsoft.com/library/windows/desktop/dd162973) funções do Windows.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBitmap::CreateBitmapIndirect](../../mfc/reference/cbitmap-class.md#createbitmapindirect)

