---
title: "Funções de Bitmap cinza e pontilhado | Documentos do Microsoft"
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
- gray and dithered bitmap functions
ms.assetid: cb139a77-b85e-4504-9d93-24156ad77a41
caps.latest.revision: 13
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
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: b8b6f43917dfe211f477b3dde0c94323015d18b2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="gray-and-dithered-bitmap-functions"></a>Funções de bitmap cinza e pontilhado
**Funções de Bitmap cinza**  
  
 MFC fornece duas funções para oferecer um bitmap a aparência de um controle desabilitado.  
  
 ![Comparação de versões de ícone cinza e original](../../mfc/reference/media/vcgraybitmap.gif "vcgraybitmap")  
  
|||  
|-|-|  
|[AfxDrawGrayBitmap](#afxdrawgraybitmap)|Desenha uma versão cinza de um bitmap.|  
|[AfxGetGrayBitmap](#afxgetgraybitmap)|Copia uma versão cinza de um bitmap.|  
  
 **Funções de Bitmap pontilhado**  
  
 MFC também fornece duas funções para substituir o plano de fundo do bitmap com um padrão de pontilhado.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
|||  
|-|-|  
|[AfxDrawDitheredBitmap](#afxdrawditheredbitmap)|Desenha um bitmap com um plano de fundo pontilhado.|  
|[AfxGetDitheredBitmap](#afxgetditheredbitmap)|Copia um bitmap com um plano de fundo pontilhado.|  
  
##  <a name="afxdrawgraybitmap"></a>AfxDrawGrayBitmap  
 Desenha uma versão cinza de um bitmap.  
  
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
 [!code-cpp[NVC_MFCDocView&#191;](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_1.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  

##  <a name="afxgetgraybitmap"></a>AfxGetGrayBitmap  
 Copia uma versão cinza de um bitmap.  
  
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
 [!code-cpp[NVC_MFCDocView&#193;](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_2.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="afxdrawditheredbitmap"></a>AfxDrawDitheredBitmap  
 Desenha um bitmap, substituindo o plano de fundo com um padrão de pontilhado (Verificador).  
  
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
 A outra pontilhado cor, geralmente acinzentado (COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 O bitmap de origem é desenhado no controlador de domínio de destino com duas cores ( `cr1` e `cr2`) padrão quadriculado substitui o plano de fundo do bitmap. O plano de fundo do bitmap de origem é definido como o branco e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#190;](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_3.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  


##  <a name="afxgetditheredbitmap"></a>AfxGetDitheredBitmap  
 Copia um bitmap, substituindo o plano de fundo com um padrão de pontilhado (Verificador).  
  
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
 A outra pontilhado cor, geralmente acinzentado (COLOR_MENU).  
  
### <a name="remarks"></a>Comentários  
 O bitmap de origem é copiado para o bitmap de destino com duas cores ( `cr1` e `cr2`) padrão quadriculado substitui o plano de fundo do bitmap de origem. O plano de fundo do bitmap de origem é definido como o branco e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.  
  
 ![Comparação de versões de ícone pontilhado e original](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#192;](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_4.cpp)]  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

