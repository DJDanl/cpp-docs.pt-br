---
title: Classe CAutoHideDockSite | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::CanAcceptPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::DockPane
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::GetAlignRect
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::RepositionPanes
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetLeft
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::SetOffsetRight
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::UnSetAutoHideMode
- AFXAUTOHIDEDOCKSITE/CAutoHideDockSite::m_nExtraSpace
dev_langs:
- C++
helpviewer_keywords:
- CAutoHideDockSite [MFC], CanAcceptPane
- CAutoHideDockSite [MFC], DockPane
- CAutoHideDockSite [MFC], GetAlignRect
- CAutoHideDockSite [MFC], RepositionPanes
- CAutoHideDockSite [MFC], SetOffsetLeft
- CAutoHideDockSite [MFC], SetOffsetRight
- CAutoHideDockSite [MFC], UnSetAutoHideMode
- CAutoHideDockSite [MFC], m_nExtraSpace
ms.assetid: 2a0f6bec-c369-4ab7-977d-564e7946ebad
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e8cc4e9158ae9ff2ef6fd4d48483aa5a75dd9617
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cautohidedocksite-class"></a>Classe CAutoHideDockSite
O `CAutoHideDockSite` estende o [CDockSite classe](../../mfc/reference/cdocksite-class.md) implementar ocultar automaticamente encaixar painéis.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAutoHideDockSite : public CDockSite  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CAutoHideDockSite::CAutoHideDockSite`|Constrói um objeto `CAutoHideDockSite`.|  
|`CAutoHideDockSite::~CAutoHideDockSite`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CAutoHideDockSite::AllowShowOnPaneMenu`|Indica se o `CAutoHideDockSite` é mostrado no menu do painel.|  
|[CAutoHideDockSite::CanAcceptPane](#canacceptpane)|Determina se um objeto de painel base é derivado de [CMFCAutoHideBar classe](../../mfc/reference/cmfcautohidebar-class.md).|  
|[CAutoHideDockSite::DockPane](#dockpane)|Encaixa um painel a esta `CAuotHideDockSite` objeto.|  
|[CAutoHideDockSite::GetAlignRect](#getalignrect)|Recupera o tamanho do site encaixe em coordenadas da tela.|  
|[CAutoHideDockSite::RepositionPanes](#repositionpanes)|Redesenha o painel no `CAutoHideDockSite` com as margens global e o espaçamento do botão.|  
|[CAutoHideDockSite::SetOffsetLeft](#setoffsetleft)|Define a margem no lado esquerdo da barra de encaixe.|  
|[CAutoHideDockSite::SetOffsetRight](#setoffsetright)|Define a margem no lado direito da barra de encaixe.|  
|[CAutoHideDockSite::UnSetAutoHideMode](#unsetautohidemode)|Chamadas [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos de `CAutoHideDockSite`.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CAutoHideDockSite::m_nExtraSpace](#m_nextraspace)|Define o tamanho do espaço entre as barras de ferramentas e a borda da barra de encaixe. Este espaço é medido a partir da borda esquerda ou a borda superior, dependendo do alinhamento para o espaço de encaixe.|  
  
## <a name="remarks"></a>Comentários  
 Quando você chama [CFrameWndEx::EnableAutoHidePanes](../../mfc/reference/cframewndex-class.md#enableautohidepanes), o framework cria automaticamente um `CAutoHideDockSite` objeto. Na maioria dos casos, você não deve ter que criar uma instância ou usar essa classe diretamente.  
  
 A barra de encaixe é a diferença entre o lado esquerdo do painel de encaixe e à esquerda do [CMFCAutoHideButton classe](../../mfc/reference/cmfcautohidebutton-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CDockSite](../../mfc/reference/cdocksite-class.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como recuperar um `CAutoHideDockSite` de objeto um `CMFCAutoHideBar` objeto e como definir as margens esquerdas e direita da barra de encaixe.  
  
 [!code-cpp[NVC_MFC_RibbonApp#29](../../mfc/reference/codesnippet/cpp/cautohidedocksite-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxautohidedocksite.h  
  
##  <a name="canacceptpane"></a>CAutoHideDockSite::CanAcceptPane  
 Determina se um painel de base é um [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) do objeto ou derivado de `CMFCAutoHideBar`.  
  
```  
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pBar`|O painel de base que a estrutura de teste.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se `pBar` é derivado de `CMFCAutoHideBar`; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Se um objeto de painel base é derivado de `CMFCAutoHideBar`, ele pode conter um `CAutoHideDockSite`.  
  
##  <a name="dockpane"></a>CAutoHideDockSite::DockPane  
 Encaixa um painel a esta [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) objeto.  
  
```  
virtual void DockPane(
    CPane* pWnd,  
    AFX_DOCK_METHOD dockMethod,  
    LPRECT lpRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pWnd`|O painel que se encaixa a estrutura.|  
|[in] `dockMethod`|Opções para o painel de encaixe.|  
|[in] `lpRect`|Um retângulo que especifica os limites para o painel encaixado.|  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não usa o parâmetro `dockMethod`, que é fornecido para uso futuro.  
  
 Se `lpRect` é `NULL`, o framework coloca o painel no local padrão no site de encaixe. Se o site de encaixe é horizontal, o local padrão é à esquerda do local de encaixe. Caso contrário, o local padrão é na parte superior do site de encaixe.  
  
##  <a name="getalignrect"></a>CAutoHideDockSite::GetAlignRect  
 Recupera o tamanho do site encaixe em coordenadas da tela.  
  
```  
void GetAlignRect(CRect& rect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `rect`|Uma referência a um retângulo. O método armazena o tamanho do site encaixe neste retângulo.|  
  
### <a name="remarks"></a>Comentários  
 O retângulo é ajustado para as margens de deslocamento para que eles não são incluídos.  
  
##  <a name="m_nextraspace"></a>CAutoHideDockSite::m_nExtraSpace  
 O tamanho do espaço entre as bordas do [CAutoHideDockSite classe](../../mfc/reference/cautohidedocksite-class.md) e [CMFCAutoHideBar classe](../../mfc/reference/cmfcautohidebar-class.md) objetos.  
  
```  
static int m_nExtraSpace;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando um `CMFCAutoHideBar` está encaixada em um `CAutoHideDockSite`, ela não deve ocupa o encaixe todo site. Essa variável global controla o espaço extra entre a borda esquerda ou superior do `CMFCAutoHideBar` e correspondente `CAutoHideDockSite` borda. Se a borda superior ou esquerda é usada depende do alinhamento atual.  
  
##  <a name="setoffsetleft"></a>CAutoHideDockSite::SetOffsetLeft  
 Define a margem no lado esquerdo da barra de encaixe.  
  
```  
void SetOffsetLeft(int nOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 O deslocamento de novo.  
  
### <a name="remarks"></a>Comentários  
 [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) objetos são posicionados na estaticamente o `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local do `CMFCAutoHideBar` objetos. O `SetOffsetLeft` método controla o espaçamento entre o lado esquerdo do mais à esquerda `CMFCAutoHideBar` e o lado esquerdo do `CAutoHideDockSite`.  
  
##  <a name="setoffsetright"></a>CAutoHideDockSite::SetOffsetRight  
 Define a margem no lado direito da barra de encaixe.  
  
```  
void SetOffsetRight(int nOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
 O deslocamento de novo.  
  
### <a name="remarks"></a>Comentários  
 [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) objetos são posicionados na estaticamente o `CAutoHideDockSite` objeto. Isso significa que o usuário não pode alterar manualmente o local do `CMFCAutoHideBar` objetos. O `SetOffsetRight` método controla o espaçamento entre o lado direito do mais à direita `CMFCAutoHideBar` e à direita do `CAutoHideDockSite`.  
  
##  <a name="repositionpanes"></a>CAutoHideDockSite::RepositionPanes  
 Redesenha os painéis no [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md).  
  
```  
virtual void RepositionPanes(CRect& rectNewClientArea);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `rectNewClientArea`|Um valor reservado.|  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão não usa `rectNewClientArea`. Ele redesenha os painéis com as margens de barra de ferramentas global e espaçamento do botão.  
  
##  <a name="unsetautohidemode"></a>CAutoHideDockSite::UnSetAutoHideMode  
 Chamadas [CMFCAutoHideBar::UnSetAutoHideMode](../../mfc/reference/cmfcautohidebar-class.md#unsetautohidemode) para objetos no site de encaixe.  
  
```  
void UnSetAutoHideMode(CMFCAutoHideBar* pAutoHideToolbar);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pAutoHideToolbar`|Um ponteiro para um [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md) painel objeto localizado no `CAutoHideDockSite`.|  
  
### <a name="remarks"></a>Comentários  
 Esse método de pesquisa para a linha que contém `pAutoHideToolbar`. Ele chama `CMFCAutoHideBar.UnSetAutoHideMode` para todos o `CMFCAutoHideBar` objetos nessa linha. Se `pAutoHideToolbar` não foi encontrado ou é `NULL`, este método chama `CMFCAutoHideBar.UnSetAutoHideMode` para todos os o `CMFCAutoHideBar` objetos o `CAutoHideDockSite`.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CDockSite](../../mfc/reference/cdocksite-class.md)
