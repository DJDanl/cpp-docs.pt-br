---
title: Estrutura BITMAPINFO | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- BITMAPINFO
dev_langs:
- C++
helpviewer_keywords:
- BITMAPINFO structure
ms.assetid: a00caa49-e4df-419f-89a7-ab03c13a1b5b
caps.latest.revision: 15
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 5c247e5741140a91eacd0e6c53f3c86483265bc4
ms.lasthandoff: 02/25/2017

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
 `bmiHeader`  
 Especifica um [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376) estrutura que contém informações sobre as dimensões e formato de cor de um bitmap independente de dispositivo.  
  
 `bmiColors`  
 Especifica uma matriz de [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938) ou `DWORD` tipos de dados que definem as cores no bitmap.  
  
## <a name="remarks"></a>Comentários  
 Um bitmap independente de dispositivo consiste em duas partes distintas: uma `BITMAPINFO` estrutura que descreve as dimensões e as cores do bitmap e uma matriz de bytes que especificam os pixels no bitmap. Os bits na matriz são embalados juntas, mas cada linha de verificação deve ser preenchida com zeros para terminar em um `LONG` limite. Se a altura for positiva, a origem do bitmap é o canto inferior esquerdo. Se a altura for negativa, a origem é o canto superior esquerdo.  
  
 A *bitmap compactado* é um bitmap em que a matriz de bytes segue imediatamente o `BITMAPINFO` estrutura. Bitmaps compactados são referenciados por um único ponteiro.  
  
 Para obter mais informações sobre o `BITMAPINFO` estrutura e valores adequados para membros do `BITMAPINFOHEADER` e `RGBQUAD` estruturas, consulte os seguintes tópicos no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] documentação.  
  
- [Estrutura BITMAPINFO](http://msdn.microsoft.com/library/windows/desktop/dd183375)  
  
- [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376) estrutura  
  
- [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938) estrutura  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** wingdi  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CBrush::CreateDIBPatternBrush](../../mfc/reference/cbrush-class.md#createdibpatternbrush)   
 [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376)   
 [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938)


