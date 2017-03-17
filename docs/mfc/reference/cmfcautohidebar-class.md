---
title: Classe CMFCAutoHideBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar::CMFCAutoHideBar
- AFXAUTOHIDEBAR/CMFCAutoHideBar::AddAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::AllowShowOnPaneMenu
- AFXAUTOHIDEBAR/CMFCAutoHideBar::CalcFixedLayout
- AFXAUTOHIDEBAR/CMFCAutoHideBar::Create
- AFXAUTOHIDEBAR/CMFCAutoHideBar::GetFirstAHWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::GetVisibleCount
- AFXAUTOHIDEBAR/CMFCAutoHideBar::OnShowControlBarMenu
- AFXAUTOHIDEBAR/CMFCAutoHideBar::RemoveAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::SetActiveInGroup
- AFXAUTOHIDEBAR/CMFCAutoHideBar::SetRecentVisibleState
- AFXAUTOHIDEBAR/CMFCAutoHideBar::ShowAutoHideWindow
- AFXAUTOHIDEBAR/CMFCAutoHideBar::StretchPane
- AFXAUTOHIDEBAR/CMFCAutoHideBar::UnSetAutoHideMode
- AFXAUTOHIDEBAR/CMFCAutoHideBar::UpdateVisibleState
- AFXAUTOHIDEBAR/CMFCAutoHideBar::m_nShowAHWndDelay
dev_langs:
- C++
helpviewer_keywords:
- CMFCAutoHideToolBar class
ms.assetid: 54c8d84f-de64-4efd-8a47-3ea0ade40a70
caps.latest.revision: 35
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: db15fc9fa3925230e372b6e13368f455dcfbb1a9
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcautohidebar-class"></a>Classe CMFCAutoHideBar
O `CMFCAutoHideBar` é uma classe ferramentas especiais que implementa o recurso de ocultar automaticamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCAutoHideBar : public CPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAutoHideBar::CMFCAutoHideBar](#cmfcautohidebar)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAutoHideBar::AddAutoHideWindow](#addautohidewindow)||  
|[CMFCAutoHideBar::AllowShowOnPaneMenu](#allowshowonpanemenu)|(Substitui `CPane::AllowShowOnPaneMenu`.)|  
|[CMFCAutoHideBar::CalcFixedLayout](#calcfixedlayout)|(Substitui [CBasePane::CalcFixedLayout](../../mfc/reference/cbasepane-class.md#calcfixedlayout).)|  
|[CMFCAutoHideBar::Create](#create)|Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto. (Substitui [CPane::Create](../../mfc/reference/cpane-class.md#create).)|  
|[CMFCAutoHideBar::GetFirstAHWindow](#getfirstahwindow)||  
|[CMFCAutoHideBar::GetVisibleCount](#getvisiblecount)||  
|[CMFCAutoHideBar::OnShowControlBarMenu](#onshowcontrolbarmenu)|Chamado pela estrutura quando um menu Painel especial está prestes a ser exibido. (Substitui [CPane::OnShowControlBarMenu](../../mfc/reference/cpane-class.md#onshowcontrolbarmenu).)|  
|[CMFCAutoHideBar::RemoveAutoHideWindow](#removeautohidewindow)||  
|[CMFCAutoHideBar::SetActiveInGroup](#setactiveingroup)|(Substitui [CPane::SetActiveInGroup](../../mfc/reference/cpane-class.md#setactiveingroup).)|  
|[CMFCAutoHideBar::SetRecentVisibleState](#setrecentvisiblestate)||  
|[CMFCAutoHideBar::ShowAutoHideWindow](#showautohidewindow)||  
|[CMFCAutoHideBar::StretchPane](#stretchpane)|Expande um painel vertical ou horizontalmente. (Substitui [CBasePane::StretchPane](../../mfc/reference/cbasepane-class.md#stretchpane).)|  
|[CMFCAutoHideBar::UnSetAutoHideMode](#unsetautohidemode)||  
|[CMFCAutoHideBar::UpdateVisibleState](#updatevisiblestate)||  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAutoHideBar::m_nShowAHWndDelay](#m_nshowahwnddelay)|O tempo de espera entre o momento em que o usuário coloca o cursor do mouse sobre um [CMFCAutoHideButton classe](../../mfc/reference/cmfcautohidebutton-class.md) e o momento em que a estrutura mostra a janela associada.|  
  
## <a name="remarks"></a>Comentários  
 Quando o usuário alterna um painel de encaixe para o modo de ocultar automaticamente, o framework cria automaticamente uma `CMFCAutoHideBar` objeto. Ele também cria o necessário [CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md) e [CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md) objetos. Cada `CAutoHideDockSite` objeto está associado um indivíduo `CMFCAutoHideButton`.  
  
 O `CMFCAutoHideBar` classe implementa a exibição de um `CAutoHideDockSite` quando o mouse do usuário passa sobre uma `CMFCAutoHideButton`. Quando a barra de ferramentas recebe uma mensagem WM_MOUSEMOVE, `CMFCAutoHideBar` inicia um cronômetro. Quando o temporizador é concluído, ele envia a barra de ferramentas uma notificação de evento WM_TIMER. A barra de ferramentas manipula esse evento, verificando se o ponteiro do mouse é posicionado sobre o botão Ocultar automaticamente mesmo que ele foi posicionado sobre quando o timer é iniciado. Se for, o arquivo `CAutoHideDockSite` é exibida.  
  
 Você pode controlar o comprimento do intervalo do temporizador, definindo `m_nShowAHWndDelay`. O valor padrão é 400 ms.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCAutoHideBar` e usa seu `GetDockSiteRow` método.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#26;](../../mfc/reference/codesnippet/cpp/cmfcautohidebar-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxautohidebar.h  
  
##  <a name="addautohidewindow"></a>CMFCAutoHideBar::AddAutoHideWindow  
 Adiciona a funcionalidade um `CDockablePane` janela que permite ocultar automaticamente.  
  
```  
CMFCAutoHideButton* AddAutoHideWindow(
    CDockablePane* pAutoHideWnd,  
    DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pAutoHideWnd`  
 A janela que você deseja ocultar.  
  
 [in] `dwAlignment`  
 Um valor que especifica o alinhamento do botão Ocultar automaticamente com a janela do aplicativo.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 O `dwAlignment` parâmetro indica onde o botão Ocultar automaticamente reside no aplicativo. O parâmetro pode ser qualquer um dos seguintes valores:  
  
- `CBRS_ALIGN_LEFT`  
  
- `CBRS_ALIGN_RIGHT`  
  
- `CBRS_ALIGN_TOP`  
  
- `CBRS_ALIGN_BOTTOM`  
  
##  <a name="allowshowonpanemenu"></a>CMFCAutoHideBar::AllowShowOnPaneMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL AllowShowOnPaneMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="calcfixedlayout"></a>CMFCAutoHideBar::CalcFixedLayout  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bStretch`  
 [in] `bHorz`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cmfcautohidebar"></a>CMFCAutoHideBar::CMFCAutoHideBar  
 Constrói um objeto CMFCAutoHideBar.  
  
```  
CMFCAutoHideBar();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="create"></a>CMFCAutoHideBar::Create  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL Create(
    LPCTSTR lpszClassName,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    DWORD dwControlBarStyle = AFX_DEFAULT_PANE_STYLE,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszClassName`  
 [in] `dwStyle`  
 [in] `rect`  
 [in] `pParentWnd`  
 [in] `nID`  
 [in] `dwControlBarStyle`  
 [in] `pContext`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getfirstahwindow"></a>CMFCAutoHideBar::GetFirstAHWindow  
 Retorna um ponteiro para a primeira janela de ocultar automaticamente no aplicativo.  
  
```  
CDockablePane* GetFirstAHWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A primeira janela de ocultar automaticamente no aplicativo, ou NULL se não houver um.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getvisiblecount"></a>CMFCAutoHideBar::GetVisibleCount  
 Obtém o número de botões de ocultar automaticamente visíveis.  
  
```  
int GetVisibleCount();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de botões de ocultar automaticamente visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_nshowahwnddelay"></a>CMFCAutoHideBar::m_nShowAHWndDelay  
 O tempo de espera entre o momento em que o usuário coloca o cursor do mouse sobre um [CMFCAutoHideButton classe](../../mfc/reference/cmfcautohidebutton-class.md) e o momento em que a estrutura mostra a janela associada.  
  
```  
int CMFCAutoHideBar::m_nShowAHWndDelay = 400;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário coloca o cursor do mouse sobre um `CMFCAutoHideButton`, há um pequeno atraso antes da estrutura exibe a janela associada. Esse parâmetro determina o comprimento desse atraso em milissegundos.  
  
##  <a name="onshowcontrolbarmenu"></a>CMFCAutoHideBar::OnShowControlBarMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowControlBarMenu(CPoint);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `CPoint`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removeautohidewindow"></a>CMFCAutoHideBar::RemoveAutoHideWindow  
 Remove e destrói a janela de ocultar automaticamente.  
  
```  
    BOOL RemoveAutoHideWindow(CDockablePane* pAutoHideWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 CDockablePane *`pAutoHideWnd`  
 A janela de ocultar automaticamente para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setactiveingroup"></a>CMFCAutoHideBar::SetActiveInGroup  
 Sinaliza uma barra de ocultar automaticamente como ativa.  
  
```  
virtual void SetActiveInGroup(BOOL bActive);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] BOOL`bActive`  
 TRUE para definir como ativo; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CPane::SetActiveInGroup](../../mfc/reference/cpane-class.md#setactiveingroup).  
  
##  <a name="setrecentvisiblestate"></a>CMFCAutoHideBar::SetRecentVisibleState  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
void SetRecentVisibleState(BOOL bState);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bState`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="showautohidewindow"></a>CMFCAutoHideBar::ShowAutoHideWindow  
 Mostra a janela de ocultar automaticamente.  
  
```  
BOOL ShowAutoHideWindow(
        CDockablePane* pAutoHideWnd,  
        BOOL bShow,  
        BOOL bDelay);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] CDockablePane *`pAutoHideWnd`  
 [in] BOOL`bShow`  
 VERDADEIRO para mostrar a janela.  
  
 [in] BOOL`bDelay`  
 Este parâmetro é ignorado.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="stretchpane"></a>CMFCAutoHideBar::StretchPane  
 Redimensiona a barra de ocultar automaticamente em seu estado recolhido para ajustar o `CMFCAutoHideButton` objeto.  
  
```  
virtual CSize StretchPane(
    int nLength,   
    BOOL bVert);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nLength`  
 O valor é usado na implementação base. Em implementações derivadas, use esse valor para indicar o tamanho do painel redimensionado.  
  
 [in] `bVert`  
 O valor é usado na implementação base. Em implementações derivadas, use `TRUE` para manipular o caso em que a barra de ocultação automática é recolhida verticalmente, e `FALSE` para o caso em que a barra de ocultação automática é recolhida horizontalmente.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho resultante do painel redimensionado.  
  
### <a name="remarks"></a>Comentários  
 Classes derivadas podem substituir esse método para personalizar o comportamento.  
  
##  <a name="unsetautohidemode"></a>CMFCAutoHideBar::UnSetAutoHideMode  
 Desativa oculta automaticamente modo para um grupo de barras de ocultar automaticamente.  
  
```  
void UnSetAutoHideMode(CDockablePane* pFirstBarInGroup)  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] pFirstBarInGroup  
 Um ponteiro para a primeira barra de ocultar automaticamente no grupo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="updatevisiblestate"></a>CMFCAutoHideBar::UpdateVisibleState  
 Chamado pela estrutura quando a barra de ocultar automaticamente precisa ser redesenhado.  
  
```  
void UpdateVisibleState();
```  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPane](../../mfc/reference/cpane-class.md)   
 [Classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md)   
 [Classe CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md)

