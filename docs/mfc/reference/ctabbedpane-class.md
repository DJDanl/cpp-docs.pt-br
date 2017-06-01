---
title: Classe CTabbedPane | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CTabbedPane
- AFXTABBEDPANE/CTabbedPane
- AFXTABBEDPANE/CTabbedPane::DetachPane
- AFXTABBEDPANE/CTabbedPane::EnableTabAutoColor
- AFXTABBEDPANE/CTabbedPane::FloatTab
- AFXTABBEDPANE/CTabbedPane::GetTabArea
- AFXTABBEDPANE/CTabbedPane::GetTabWnd
- AFXTABBEDPANE/CTabbedPane::HasAutoHideMode
- AFXTABBEDPANE/CTabbedPane::IsTabLocationBottom
- AFXTABBEDPANE/CTabbedPane::ResetTabs
- AFXTABBEDPANE/CTabbedPane::SetTabAutoColors
- AFXTABBEDPANE/CTabbedPane::m_bTabsAlwaysTop
- AFXTABBEDPANE/CTabbedPane::m_pTabWndRTC
dev_langs:
- C++
helpviewer_keywords:
- CTabbedPane class
ms.assetid: f4dc5215-b789-4f2d-8c62-477aceda3578
caps.latest.revision: 27
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 70377d6be8ef4ec957c7270e501022107d4b093c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ctabbedpane-class"></a>Classe CTabbedPane
Implementa a funcionalidade de um painel com guias destacáveis.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CTabbedPane : public CBaseTabbedPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CTabbedPane::CTabbedPane`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabbedPane::DetachPane](#detachpane)|(Substitui [CBaseTabbedPane::DetachPane](../../mfc/reference/cbasetabbedpane-class.md#detachpane).)|  
|[CTabbedPane::EnableTabAutoColor](#enabletabautocolor)|Habilita ou desabilita a coloração automática das guias.|  
|[CTabbedPane::FloatTab](#floattab)|Flutua um painel, mas apenas se o painel estiver atualmente em uma guia destacáveis. (Substitui [CBaseTabbedPane::FloatTab](../../mfc/reference/cbasetabbedpane-class.md#floattab).)|  
|[CTabbedPane::GetTabArea](#gettabarea)|Retorna o tamanho e a posição da área de guia dentro da janela com guias.|  
|[CTabbedPane::GetTabWnd](#gettabwnd)||  
|[CTabbedPane::HasAutoHideMode](#hasautohidemode)|Determina se o painel com guias pode ser alternado para o modo de ocultar automaticamente. (Substitui [CBaseTabbedPane::HasAutoHideMode](../../mfc/reference/cbasetabbedpane-class.md#hasautohidemode).)|  
|[CTabbedPane::IsTabLocationBottom](#istablocationbottom)|Determina se as guias estão localizadas na parte inferior da janela.|  
|[CTabbedPane::ResetTabs](#resettabs)|Redefine todos os painéis com guias para o estado padrão.|  
|[CTabbedPane::SetTabAutoColors](#settabautocolors)|Define uma lista de cores personalizadas que podem ser usados quando o recurso de cor automática está habilitado.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CTabbedPane::m_bTabsAlwaysTop](#m_btabsalwaystop)|O local padrão para as guias no aplicativo.|  
|[CTabbedPane::m_pTabWndRTC](#m_ptabwndrtc)|Informações de classe de tempo de execução para um personalizado `CMFCTabCtrl`-objeto derivado.|  
  
## <a name="remarks"></a>Comentários  
 O framework cria automaticamente uma instância dessa classe quando um usuário anexar um painel para outro, apontando para a legenda do segundo painel. Todos os painéis com guias que são criados pela estrutura tem uma ID de -1.  
  
 Para especificar o guias normais em vez de guias de estilo do Outlook, passe o `AFX_CBRS_REGULAR_TABS` de estilo para o [CDockablePane::CreateEx](../../mfc/reference/cdockablepane-class.md#createex) método.  
  
 Se você criar um painel com guias com guias destacáveis, o painel pode ser destruído automaticamente pelo framework, portanto você não deve armazenar o ponteiro. Para obter um ponteiro para o painel com guias, chame o `CBasePane::GetParentTabbedPane` método.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, podemos criar um `CTabbedPane` objeto. Em seguida, usamos [CBaseTabbedPane::AddTab](../../mfc/reference/cbasetabbedpane-class.md#addtab) anexar guias adicionais.  
  
```  
CTabbedPane* pTabbededBar = new CTabbedPane (TRUE);

if (!pTabbededBar->Create (_T(""),
    this,
    CRect (0,
    0,
    200,
    200),  
    TRUE, 
 (UINT) -1,  
    WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS |  
    WS_CLIPCHILDREN | CBRS_LEFT |    
    CBRS_FLOAT_MULTI)) 
{  
    TRACE0("Failed to create Solution Explorer bar\n");

    return FALSE;      // fail to create  
}  
 
pTabbededBar->AddTab (&m_wndClassView);
pTabbededBar->AddTab (&m_wndResourceView);

pTabbededBar->AddTab (&m_wndFileView);
pTabbededBar->EnableDocking(CBRS_ALIGN_ANY);

DockPane(pTabbededBar);
```  
  
## <a name="example"></a>Exemplo  
 Outra maneira de criar um objeto da barra de controle com guias é usar [CDockablePane::AttachToTabWnd](../../mfc/reference/cdockablepane-class.md#attachtotabwnd). O `AttachToTabWnd` método cria dinamicamente um objeto de painel com guias usando informações de classe de tempo de execução definidas por [CDockablePane::SetTabbedPaneRTC](../../mfc/reference/cdockablepane-class.md#settabbedpanertc).  
  
 Neste exemplo, podemos criar um painel com guias dinamicamente, anexar duas guias e verifique a segunda guia não removível.  
  
```  
DockPane(&m_wndClassView);

CTabbedPane* pTabbedBar = NULL;  
m_wndResourceView.AttachToTabWnd (&m_wndClassView,
    DM_SHOW,
    TRUE,  
 (CDockablePane**) &pTabbedBar);

m_wndFileView.AttachToTabWnd (pTabbedBar,
    DM_SHOW,
    TRUE,  
 (CDockablePane**) &pTabbedBar);

pTabbedBar->GetUnderlyingWindow ()->EnableTabDetach (1,
    FALSE);
```  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../../mfc/reference/cdockablepane-class.md)  
  
 [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
 [CTabbedPane](../../mfc/reference/ctabbedpane-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxTabbedPane.h  
  
##  <a name="detachpane"></a>CTabbedPane::DetachPane  

  
```  
virtual BOOL DetachPane(
    CWnd* pBar,  
    BOOL bHide = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `bHide`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enabletabautocolor"></a>CTabbedPane::EnableTabAutoColor  
 Habilita ou desabilita a coloração automática das guias.  
  
```  
static void EnableTabAutoColor(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a coloração automática das guias; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método estático para habilitar ou desabilitar a coloração automática das guias em todos os painéis com guias no aplicativo. Quando esse recurso estiver habilitado, cada guia é preenchido por sua própria cor. Você pode encontrar a lista de cores que são usados para colorir as guias chamando o [CMFCBaseTabCtrl::GetAutoColors](../../mfc/reference/cmfcbasetabctrl-class.md#getautocolors) método.  
  
 Você pode especificar a lista de cores que será usado para guias chamando [CTabbedPane::SetTabAutoColors](#settabautocolors).  
  
 Por padrão, essa opção está desabilitada.  
  
##  <a name="floattab"></a>CTabbedPane::FloatTab  

  
```  
virtual BOOL FloatTab(
    CWnd* pBar,  
    int nTabID,  
    AFX_DOCK_METHOD dockMethod,  
    BOOL bHide = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 [in] `nTabID`  
 [in] `dockMethod`  
 [in] `bHide`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettabarea"></a>CTabbedPane::GetTabArea  
 Retorna o tamanho e a posição da área da guia na janela com guias.  
  
```  
virtual void GetTabArea(
    CRect& rectTabAreaTop,  
    CRect& rectTabAreaBottom) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectTabAreaTop`  
 Contém o tamanho e posição, em coordenadas de tela da área de guia superior.  
  
 [out] `rectTabAreaBottom`  
 Contém o tamanho e posição, em coordenadas de tela da área de guia inferior.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para determinar como encaixar um painel que um usuário está arrastando. Quando o usuário arrasta um painel na área do guia do painel de destino, o framework tentará adicioná-lo como uma nova guia do painel de destino. Caso contrário, ele tenta encaixar o painel no lado do painel de destino, o que envolve a criação de um novo contêiner de painel com um divisor de painel que separa os dois painéis.  
  
 Substitua esse método em um `CTabbedPane`-derivado da classe para alterar esse comportamento.  
  
##  <a name="gettabwnd"></a>CTabbedPane::GetTabWnd  

  
```  
CMFCTabCtrl* GetTabWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasautohidemode"></a>CTabbedPane::HasAutoHideMode  

  
```  
virtual BOOL HasAutoHideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="istablocationbottom"></a>CTabbedPane::IsTabLocationBottom  
 Determina se as guias estão localizadas na parte inferior da janela.  
  
```  
virtual BOOL IsTabLocationBottom() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a área da guia está localizada na parte inferior da janela com guias. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_btabsalwaystop"></a>CTabbedPane::m_bTabsAlwaysTop  
 O local padrão para as guias no aplicativo.  
  
```  
AFX_IMPORT_DATA static BOOL m_bTabsAlwaysTop;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina este membro estático como `TRUE` para forçar todas as guias no aplicativo a ser exibido na parte superior do painel com guias.  
  
 Você deve definir esse valor antes de um painel com guias foi criado.  
  
 O valor padrão é `FALSE`.  
  
##  <a name="m_ptabwndrtc"></a>CTabbedPane::m_pTabWndRTC  
 Informações de classe de tempo de execução para um personalizado `CMFCTabCtrl`-objeto derivado.  
  
```  
AFX_IMPORT_DATA static CRuntimeClass* m_pTabWndRTC;  
```  
  
### <a name="remarks"></a>Comentários  
 Definir essa variável de membro estático em um ponteiro para as informações de classe de tempo de execução de um `CMFCTabCtrl`-objeto derivado se você estiver usando uma janela com guias personalizada dentro de um painel com guias.  
  
##  <a name="resettabs"></a>CTabbedPane::ResetTabs  
 Redefine todos os painéis com guias para o estado padrão.  
  
```  
static void ResetTabs();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para retornar todos os painéis com guias para seu estado padrão. Quando chamado, esse método redefine o estado de cor automática de todos os painéis com guias e tamanhos de borda.  
  
##  <a name="settabautocolors"></a>CTabbedPane::SetTabAutoColors  
 Define uma lista de cores personalizadas que são usadas quando o recurso de cor automático está habilitado.  
  
```  
static void SetTabAutoColors(const CArray<COLORREF, COLORREF>& arColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `arColors`  
 Contém a matriz de cores para definir.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para personalizar a lista de cores que são usadas quando o recurso de cor automático está habilitado. Esta é uma função estática e afeta todas as guias painéis em seu aplicativo.  
  
 Use [CTabbedPane::EnableTabAutoColor](#enabletabautocolor) para habilitar ou desabilitar o recurso de cor automática.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)   
 [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)

