---
title: Estrutura BITMAPINFO | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- BITMAPINFO
dev_langs:
- C++
helpviewer_keywords:
- BITMAPINFO structure [MFC]
ms.assetid: a00caa49-e4df-419f-89a7-ab03c13a1b5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0bc5adbb62e70a012d9dff4f9a390a46476aaa36
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43200250"
---
# <a name="bitmapinfo-structure"></a>Estrutura BITMAPINFO
O `BITMAPINFO` estrutura define as dimensões e as informações de cores para um bitmap independente de dispositivo do Windows (DIB).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
typedef struct tagBITMAPINFO {  
    BITMAPINFOHEADER bmiHeader;  
    RGBQUAD bmiColors[1];  
} BITMAPINFO;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *bmiHeader*  
 Especifica um [BITMAPINFOHEADER](https://msdn.microsoft.com/library/windows/desktop/dd183376) estrutura que contém informações sobre as dimensões e formato de cor de um bitmap independente de dispositivo.  
  
 *bmiColors*  
 Especifica uma matriz de [RGBQUAD](/windows/desktop/api/wingdi/ns-wingdi-tagrgbquad) ou tipos de dados DWORD que definem as cores no bitmap.  
  
## <a name="remarks"></a>Comentários  
 Um bitmap independente de dispositivo consiste em duas partes distintas: um `BITMAPINFO` estrutura que descreve as dimensões e as cores do bitmap e uma matriz de bytes que especifica os pixels no bitmap. Os bits na matriz são empacotados juntas, mas cada linha de verificação deve ser preenchida com zeros para terminar em um **longo** limites. Se a altura for positiva, a origem do bitmap é o canto inferior esquerdo. Se a altura for negativa, a origem é o canto superior esquerdo.  
  
 Um *bitmap compactada* é um bitmap no qual a matriz de bytes segue imediatamente o `BITMAPINFO` estrutura. Bitmaps compactados são referenciados por um único ponteiro.  
  
 Para obter mais informações sobre o `BITMAPINFO` estruturar e valores adequados para os membros de `BITMAPINFOHEADER` e `RGBQUAD` estruturas, consulte os seguintes tópicos na documentação do SDK do Windows.  
  
- [Estrutura BITMAPINFO](/windows/desktop/api/wingdi/ns-wingdi-tagbitmapinfo)  
  
- [BITMAPINFOHEADER](https://msdn.microsoft.com/library/windows/desktop/dd183376) estrutura  
  
- [RGBQUAD](/windows/desktop/api/wingdi/ns-wingdi-tagrgbquad) estrutura  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBrush::CreateDIBPatternBrush](../../mfc/reference/cbrush-class.md#createdibpatternbrush)   
 [BITMAPINFOHEADER](https://msdn.microsoft.com/library/windows/desktop/dd183376)   
 [RGBQUAD](/windows/desktop/api/wingdi/ns-wingdi-tagrgbquad)

