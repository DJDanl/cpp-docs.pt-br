---
title: Classe CMDITabInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMDITabInfo
- AFXMDICLIENTAREAWND/CMDITabInfo
- AFXMDICLIENTAREAWND/CMDITabInfo::Serialize
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bAutoColor
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bDocumentMenu
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bEnableTabSwap
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bFlatFrame
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabCloseButton
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabCustomTooltips
- AFXMDICLIENTAREAWND/CMDITabInfo::m_bTabIcons
- AFXMDICLIENTAREAWND/CMDITabInfo::m_nTabBorderSize
- AFXMDICLIENTAREAWND/CMDITabInfo::m_style
- AFXMDICLIENTAREAWND/CMDITabInfo::m_tabLocation
dev_langs:
- C++
helpviewer_keywords:
- CMDITabInfo [MFC], Serialize
- CMDITabInfo [MFC], m_bAutoColor
- CMDITabInfo [MFC], m_bDocumentMenu
- CMDITabInfo [MFC], m_bEnableTabSwap
- CMDITabInfo [MFC], m_bFlatFrame
- CMDITabInfo [MFC], m_bTabCloseButton
- CMDITabInfo [MFC], m_bTabCustomTooltips
- CMDITabInfo [MFC], m_bTabIcons
- CMDITabInfo [MFC], m_nTabBorderSize
- CMDITabInfo [MFC], m_style
- CMDITabInfo [MFC], m_tabLocation
ms.assetid: 988ae1b7-4f7f-4239-b88f-7e28b3291c5e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b95706603c8fe8a8f53be8cd0db405cd649271f2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmditabinfo-class"></a>Classe CMDITabInfo
O `CMDITabInfo` classe é usada para passar parâmetros para [CMDIFrameWndEx::EnableMDITabbedGroups](../../mfc/reference/cmdiframewndex-class.md#enablemditabbedgroups) método. Conjunto de membros dessa classe para controlar o comportamento de MDI grupos com guias.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMDITabInfo   
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMDITabInfo::CMDITabInfo`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDITabInfo::Serialize](#serialize)|Lê ou grava este objeto de ou para um arquivo morto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMDITabInfo::m_bActiveTabCloseButton;](#m_bactivetabclosebutton_)|Especifica se um **fechar** botão é exibido no rótulo da guia ativa.|  
|[CMDITabInfo::m_bAutoColor](#m_bautocolor)|Especifica se a cor das guias MDI.|  
|[CMDITabInfo::m_bDocumentMenu](#m_bdocumentmenu)|Especifica se o grupo de guias exibe um menu pop-up que mostra uma lista de documentos abertos ou exibe os botões de rolagem.|  
|[CMDITabInfo::m_bEnableTabSwap](#m_benabletabswap)|Especifica se o usuário pode trocar as posições das guias arrastando.|  
|[CMDITabInfo::m_bFlatFrame](#m_bflatframe)|Especifica se as guias têm um quadro simples.|  
|[CMDITabInfo::m_bTabCloseButton](#m_btabclosebutton)|Especifica se o rótulo de cada guia exibe uma **fechar** botão.|  
|[CMDITabInfo::m_bTabCustomTooltips](#m_btabcustomtooltips)|Especifica se as dicas de ferramenta personalizadas estão habilitadas.|  
|[CMDITabInfo::m_bTabIcons](#m_btabicons)|Especifica se deseja exibir ícones em guias MDI.|  
|[CMDITabInfo::m_nTabBorderSize](#m_ntabbordersize)|Especifica o tamanho da borda de cada janela de guia.|  
|[CMDITabInfo::m_style](#m_style)|Especifica o estilo dos rótulos de guia.|  
|[CMDITabInfo::m_tabLocation](#m_tablocation)|Especifica se os rótulos de guias estão localizados na parte superior ou inferior da página.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe especifica os parâmetros dos grupos de guia MDI que cria a estrutura.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como definir os valores das variáveis de membro de vários em `CMDITabInfo` classe.  
  
 [!code-cpp[NVC_MFC_MDITab#1](../../mfc/reference/codesnippet/cpp/cmditabinfo-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMDITabInfo](../../mfc/reference/cmditabinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmdiclientareawnd.h  
  
##  <a name="m_bactivetabclosebutton_"></a>  CMDITabInfo::m_bActiveTabCloseButton;  
 Especifica se um **fechar** botão é exibido no rótulo da guia ativa.  
  
```  
BOOL m_bActiveTabCloseButton;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, o rótulo da guia active exibirá um **fechar** botão. O **fechar** botão será removido do canto superior direito da área da guia. Caso contrário, o rótulo da guia ativa não exibirá um **fechar** botão. O **fechar** botão será exibido no canto superior direito da área da guia.  
  
##  <a name="m_bautocolor"></a>  CMDITabInfo::m_bAutoColor  
 Especifica se cada guia MDI tem sua própria cor.  
  
```  
BOOL m_bAutoColor;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, cada guia terá sua própria cor. O conjunto de cores é gerenciado pela biblioteca do MFC. Caso contrário, as guias são exibidas em branco. O valor padrão é `FALSE`.  
  
##  <a name="m_bdocumentmenu"></a>  CMDITabInfo::m_bDocumentMenu  
 Especifica se cada guia exibe um menu pop-up que mostra uma lista de documentos abertos na borda direita da área da guia.  
  
```  
BOOL m_bDocumentMenu;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, o windows de cada guia exibe um menu pop-up que mostra uma lista de documentos abertos na borda direita da área de guia; Caso contrário, a janela de guia exibe botões de rolagem na borda direita da área da guia. O valor padrão é `FALSE`.  
  
##  <a name="m_benabletabswap"></a>  CMDITabInfo::m_bEnableTabSwap  
 Especifica se o usuário pode trocar as posições das guias arrastando.  
  
```  
BOOL m_bEnableTabSwap;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, o usuário pode alterar as posições de guias arrastando as guias. Caso contrário, o usuário não pode alterar as posições de guias. O valor padrão é `TRUE`.  
  
##  <a name="m_bflatframe"></a>  CMDITabInfo::m_bFlatFrame  
 Especifica se cada janela de guia tem um quadro simples.  
  
```  
BOOL m_bFlatFrame;  
```  
  
##  <a name="m_btabclosebutton"></a>  CMDITabInfo::m_bTabCloseButton  
 Especifica se cada janela de guia exibe uma **fechar** botão.  
  
```  
BOOL m_bTabCloseButton;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, cada janela de guia exibe o **fechar** botão no canto direito da guia. Caso contrário, o **fechar** botão não é exibido. O valor padrão é `TRUE`.  
  
##  <a name="m_btabcustomtooltips"></a>  CMDITabInfo::m_bTabCustomTooltips  
 Especifica se as guias exibem dicas de ferramenta.  
  
```  
BOOL m_bTabCustomTooltips;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, o aplicativo envia uma `AFX_WM_ON_GET_TAB_TOOLTIP` mensagem para o quadro principal. Você pode manipular esta mensagem usando o `ON_REGISTERED_MESSAGE` macro.  
  
##  <a name="m_btabicons"></a>  CMDITabInfo::m_bTabIcons  
 Especifica se deseja exibir ícones em guias MDI.  
  
```  
BOOL m_bTabIcons;  
```  
  
### <a name="remarks"></a>Comentários  
 Se `TRUE`, ícones são exibidos em cada guia MDI. Caso contrário, os ícones não são exibidos nas guias. O valor padrão é `FALSE`.  
  
##  <a name="m_ntabbordersize"></a>  CMDITabInfo::m_nTabBorderSize  
 Especifica o tamanho da borda, em pixels, de cada janela de guia.  
  
```  
int m_nTabBorderSize;  
```  
  
### <a name="remarks"></a>Comentários  
 [CMFCVisualManager::GetMDITabsBordersSize](../../mfc/reference/cmfcvisualmanager-class.md#getmditabsborderssize) retorna o valor padrão.  
  
##  <a name="m_style"></a>  CMDITabInfo::m_style  
 Especifica o estilo dos rótulos de guia.  
  
```  
CMFCTabCtrl::Style m_style  
```  
  
### <a name="remarks"></a>Comentários  
 Especifique um dos seguintes estilos para os rótulos do guia:  
  
 `STYLE_3D`  
 Estilo 3D.  
  
 `STYLE_3D_ONENOTE`  
 Microsoft OneNote estilo.  
  
 `STYLE_3D_VS2005`  
 Estilo do Microsoft Visual Studio 2005.  
  
 `STYLE_3D_SCROLLED`  
 Estilo 3D com rótulos de guia do retângulo.  
  
 `STYLE_FLAT_SHARED_HORZ_SCROLL`  
 Estilo simples com a barra de rolagem horizontal compartilhado.  
  
 `STYLE_3D_ROUNDED_SCROLL`  
 Estilo 3D com rótulos de guia round.  
  
##  <a name="m_tablocation"></a>  CMDITabInfo::m_tabLocation  
 Especifica se os rótulos de guias estão localizados na parte superior ou inferior da página.  
  
```  
CMFCTabCtrl::Location m_tabLocation;  
```  
  
### <a name="remarks"></a>Comentários  
 Se aplicam às guias um dos sinalizadores de local a seguir:  
  
-   LOCATION_BOTTOM: os rótulos de guias estão localizados na parte inferior da página.  
  
-   LOCATION_TOP: os rótulos de guias estão localizados na parte superior da página  
  
##  <a name="serialize"></a>  CMDITabInfo::Serialize  
 Lê ou grava este objeto a partir de um arquivo ou para um arquivo.  
  
```  
void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ar`  
 Um [classe CArchive](../../mfc/reference/carchive-class.md) objeto a ser serializado.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CMDIFrameWndEx](../../mfc/reference/cmdiframewndex-class.md)   
 [Grupos com guias MDI](../../mfc/mdi-tabbed-groups.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
