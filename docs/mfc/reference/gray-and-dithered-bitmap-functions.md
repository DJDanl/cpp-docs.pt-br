---
title: "Funções de Bitmap cinza e pontilhado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- AFXWIN/AfxDrawGrayBitmap
- AFXWIN/AfxGetGrayBitmap
- AFXWIN/AfxDrawDitheredBitmap
- AFXWIN/AfxGetDitheredBitmap
dev_langs:
- C++
helpviewer_keywords:
- gray and dithered bitmap functions [MFC]
ms.assetid: cb139a77-b85e-4504-9d93-24156ad77a41
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7f895fb22e4f4d2649cdec1e4c9925b69b013e49
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="gray-and-dithered-bitmap-functions"></a>Funções de bitmap cinza e pontilhado
**Funções de Bitmap cinza**  
  
 MFC fornece duas funções para conceder um bitmap a aparência de um controle desabilitado.  
  
 ![Comparação de versões de ícone cinza e original](../../mfc/reference/media/vcgraybitmap.gif "vcgraybitmap")  
  
|||  
|-|-|  
|[AfxDrawGrayBitmap](#afxdrawgraybitmap)|Desenha uma versão cinza um bitmap.|  
|[AfxGetGrayBitmap](#afxgetgraybitmap)|Copia uma versão cinza um bitmap.|  
  
 **Funções de Bitmap pontilhado**  
  
 MFC também fornece duas funções para substituir o plano de fundo do bitmap com um padrão de pontilhado.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
|||  
|-|-|  
|[AfxDrawDitheredBitmap](#afxdrawditheredbitmap)|Desenha um bitmap com um plano de fundo pontilhado.|  
|[AfxGetDitheredBitmap](#afxgetditheredbitmap)|Copia um bitmap com um plano de fundo pontilhado.|  
  
##  <a name="afxdrawgraybitmap"></a>AfxDrawGrayBitmap  
 Desenha uma versão cinza um bitmap.  
  
```   
void AFXAPI AfxDrawGrayBitmap(
    CDC* pDC,  
    int x,  
    int y,  
    const CBitmap& rSrc,  
    COLORREF crBackground); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o controlador de domínio de destino.  
  
 *x*  
 A destino coordenada x.  
  
 *y*  
 A destino coordenada y.  
  
 `rSrc`  
 O bitmap de origem.  
  
 `crBackground`  
 A nova cor de plano de fundo (normalmente cinza, como COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 Um bitmap com `AfxDrawGrayBitmap` terá a aparência de um controle desabilitado.  
  
 ![Comparação de versões de ícone cinza e original](../../mfc/reference/media/vcgraybitmap.gif "vcgraybitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#191](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_1.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  

##  <a name="afxgetgraybitmap"></a>AfxGetGrayBitmap  
 Copia uma versão cinza um bitmap.  
  
```   
void AFXAPI AfxGetGrayBitmap(
    const CBitmap& rSrc,  
    CBitmap* pDest,  
    COLORREF crBackground); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSrc`  
 O bitmap de origem.  
  
 `pDest`  
 O bitmap de destino.  
  
 `crBackground`  
 A nova cor de plano de fundo (normalmente cinza, como COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 Um bitmap copiado com `AfxGetGrayBitmap` terá a aparência de um controle desabilitado.  
  
 ![Comparação de versões de ícone cinza e original](../../mfc/reference/media/vcgraybitmap.gif "vcgraybitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#193](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_2.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="afxdrawditheredbitmap"></a>AfxDrawDitheredBitmap  
 Desenha um bitmap, substituindo seu plano de fundo com um padrão de pontilhado (checker).  
  
```   
void AFXAPI AfxDrawDitheredBitmap(
    CDC* pDC,  
    int x,  
    int y,  
    const CBitmap& rSrc,  
    COLORREF cr1  ,  
    COLORREF cr2); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDC`  
 Aponta para o controlador de domínio de destino.  
  
 *x*  
 A destino coordenada x.  
  
 *y*  
 A destino coordenada y.  
  
 `rSrc`  
 O bitmap de origem.  
  
 `cr1`  
 Uma das cores dois pontilhado, normalmente em branco.  
  
 `cr2`  
 O outros pontilhado cor, normalmente acinzentado (COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 O bitmap de origem é desenhado no controlador de domínio de destino com duas cores ( `cr1` e `cr2`) quadriculada padrão que substitui o plano de fundo do bitmap. O plano de fundo do bitmap de origem é definido como seus brancos e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#190](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  


##  <a name="afxgetditheredbitmap"></a>AfxGetDitheredBitmap  
 Copia um bitmap, substituindo seu plano de fundo com um padrão de pontilhado (checker).  
  
```   
void AFXAPI AfxGetDitheredBitmap(
    const CBitmap& rSrc,  
    CBitmap* pDest,  
    COLORREF cr1  ,  
    COLORREF cr2); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `rSrc`  
 O bitmap de origem.  
  
 `pDest`  
 O bitmap de destino.  
  
 `cr1`  
 Uma das cores dois pontilhado, normalmente em branco.  
  
 `cr2`  
 O outros pontilhado cor, normalmente acinzentado (COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 O bitmap de origem é copiado para o bitmap de destino com duas cores ( `cr1` e `cr2`) quadriculada padrão que substitui o plano de fundo do bitmap de origem. O plano de fundo do bitmap de origem é definido como seus brancos e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#192](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
