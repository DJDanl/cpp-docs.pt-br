---
title: Classe CMFCLinkCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCLinkCtrl
- AFXLINKCTRL/CMFCLinkCtrl
- AFXLINKCTRL/CMFCLinkCtrl::SetURL
- AFXLINKCTRL/CMFCLinkCtrl::SetURLPrefix
- AFXLINKCTRL/CMFCLinkCtrl::SizeToContent
- AFXLINKCTRL/CMFCLinkCtrl::OnDrawFocusRect
dev_langs: C++
helpviewer_keywords:
- CMFCLinkCtrl [MFC], SetURL
- CMFCLinkCtrl [MFC], SetURLPrefix
- CMFCLinkCtrl [MFC], SizeToContent
- CMFCLinkCtrl [MFC], OnDrawFocusRect
ms.assetid: 80f3874d-7cc8-410e-9ff1-62a225f5034b
caps.latest.revision: "27"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 1105e69599b1741d79c20e4f0ceb362cfc8c15eb
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cmfclinkctrl-class"></a>Classe CMFCLinkCtrl
O `CMFCLinkCtrl` classe exibe um botão como um hiperlink e invoca o destino do link quando o botão é clicado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCLinkCtrl : public CMFCButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCLinkCtrl::SetURL](#seturl)|Exibe uma URL especificada como o texto do botão.|  
|[CMFCLinkCtrl::SetURLPrefix](#seturlprefix)|Define o protocolo implícita (por exemplo, "http:") da URL.|  
|[CMFCLinkCtrl::SizeToContent](#sizetocontent)|Redimensiona um botão para conter o texto do botão ou o bitmap.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCLinkCtrl::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo framework antes do retângulo de foco do botão é desenhado.|  
  
## <a name="remarks"></a>Comentários  
 Quando você clica em um botão que é derivado de `CMFCLinkCtrl` classe, o framework passa a URL do botão como um parâmetro para o `ShellExecute` método. Em seguida, o `ShellExecute` método abre o destino da URL.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como definir o tamanho de um `CMFCLinkCtrl` objeto e como definir uma url e uma dica de ferramenta em um `CMFCLinkCtrl` objeto. Este exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#9](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#10](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCButton](../../mfc/reference/cmfcbutton-class.md)  
  
 [CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxlinkctrl.h  
  
##  <a name="ondrawfocusrect"></a>CMFCLinkCtrl::OnDrawFocusRect  
 Chamado pelo framework antes do retângulo de foco do botão é desenhado.  
  
```  
virtual void OnDrawFocusRect(
    CDC* pDC,  
    const CRect& rectClient);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectClient`  
 Um retângulo que circunda o controle de link.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método quando quiser usar seu próprio código para desenhar o retângulo de foco do botão.  
  
##  <a name="seturl"></a>CMFCLinkCtrl::SetURL  
 Exibe uma URL especificada como o texto do botão.  
  
```  
void SetURL(LPCTSTR lpszURL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszURL`  
 O texto do botão para exibir.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="seturlprefix"></a>CMFCLinkCtrl::SetURLPrefix  
 Define o protocolo implícita (por exemplo, "http:") da URL.  
  
```  
void SetURLPrefix(LPCTSTR lpszPrefix);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszPrefix`  
 O prefixo do protocolo de URL.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir o prefixo de URL. O prefixo não é exibido na face do botão, mas você pode usá-lo para navegar até o destino da URL.  
  
##  <a name="sizetocontent"></a>CMFCLinkCtrl::SizeToContent  
 Redimensiona um botão para conter o texto do botão ou o bitmap.  
  
```  
virtual CSize SizeToContent(
    BOOL bVCenter=FALSE,  
    BOOL bHCenter=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bVCenter`  
 `TRUE`para centralizar o texto do botão e bitmap verticalmente entre as partes superior e inferior do controle link; Caso contrário, `FALSE`. O valor padrão é `FALSE`.  
  
 [in] `bHCenter`  
 `TRUE`para centralizar o texto do botão e bitmap horizontalmente entre os lados esquerdo e direito de controle de link; Caso contrário, `FALSE`. O valor padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o novo tamanho do controle de link.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CLinkCtrl](../../mfc/reference/clinkctrl-class.md)   
 [Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)
