---
title: Classe CDockablePane | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDockablePane
- AFXDOCKABLEPANE/CDockablePane
- AFXDOCKABLEPANE/CDockablePane::CDockablePane
- AFXDOCKABLEPANE/CDockablePane::AttachToTabWnd
- AFXDOCKABLEPANE/CDockablePane::CalcFixedLayout
- AFXDOCKABLEPANE/CDockablePane::CanAcceptMiniFrame
- AFXDOCKABLEPANE/CDockablePane::CanAcceptPane
- AFXDOCKABLEPANE/CDockablePane::CanAutoHide
- AFXDOCKABLEPANE/CDockablePane::CanBeAttached
- AFXDOCKABLEPANE/CDockablePane::ConvertToTabbedDocument
- AFXDOCKABLEPANE/CDockablePane::CopyState
- AFXDOCKABLEPANE/CDockablePane::Create
- AFXDOCKABLEPANE/CDockablePane::CreateDefaultPaneDivider
- AFXDOCKABLEPANE/CDockablePane::CreateEx
- AFXDOCKABLEPANE/CDockablePane::CreateTabbedPane
- AFXDOCKABLEPANE/CDockablePane::DockPaneContainer
- AFXDOCKABLEPANE/CDockablePane::DockPaneStandard
- AFXDOCKABLEPANE/CDockablePane::DockToRecentPos
- AFXDOCKABLEPANE/CDockablePane::DockToWindow
- AFXDOCKABLEPANE/CDockablePane::EnableAutohideAll
- AFXDOCKABLEPANE/CDockablePane::EnableGripper
- AFXDOCKABLEPANE/CDockablePane::GetAHRestoredRect
- AFXDOCKABLEPANE/CDockablePane::GetAHSlideMode
- AFXDOCKABLEPANE/CDockablePane::GetCaptionHeight
- AFXDOCKABLEPANE/CDockablePane::GetDefaultPaneDivider
- AFXDOCKABLEPANE/CDockablePane::GetDockingStatus
- AFXDOCKABLEPANE/CDockablePane::GetDragSensitivity
- AFXDOCKABLEPANE/CDockablePane::GetLastPercentInPaneContainer
- AFXDOCKABLEPANE/CDockablePane::GetTabArea
- AFXDOCKABLEPANE/CDockablePane::GetTabbedPaneRTC
- AFXDOCKABLEPANE/CDockablePane::HasAutoHideMode
- AFXDOCKABLEPANE/CDockablePane::HitTest
- AFXDOCKABLEPANE/CDockablePane::IsAutohideAllEnabled
- AFXDOCKABLEPANE/CDockablePane::IsAutoHideMode
- AFXDOCKABLEPANE/CDockablePane::IsDocked
- AFXDOCKABLEPANE/CDockablePane::IsHideInAutoHideMode
- AFXDOCKABLEPANE/CDockablePane::IsInFloatingMultiPaneFrameWnd
- AFXDOCKABLEPANE/CDockablePane::IsResizable
- AFXDOCKABLEPANE/CDockablePane::IsTabLocationBottom
- AFXDOCKABLEPANE/CDockablePane::IsTracked
- AFXDOCKABLEPANE/CDockablePane::IsVisible
- AFXDOCKABLEPANE/CDockablePane::OnAfterChangeParent
- AFXDOCKABLEPANE/CDockablePane::OnAfterDockFromMiniFrame
- AFXDOCKABLEPANE/CDockablePane::OnBeforeChangeParent
- AFXDOCKABLEPANE/CDockablePane::OnBeforeFloat
- AFXDOCKABLEPANE/CDockablePane::RemoveFromDefaultPaneDividier
- AFXDOCKABLEPANE/CDockablePane::ReplacePane
- AFXDOCKABLEPANE/CDockablePane::RestoreDefaultPaneDivider
- AFXDOCKABLEPANE/CDockablePane::SetAutoHideMode
- AFXDOCKABLEPANE/CDockablePane::SetAutoHideParents
- AFXDOCKABLEPANE/CDockablePane::SetLastPercentInPaneContainer
- AFXDOCKABLEPANE/CDockablePane::SetRestoredDefaultPaneDivider
- AFXDOCKABLEPANE/CDockablePane::SetTabbedPaneRTC
- AFXDOCKABLEPANE/CDockablePane::ShowPane
- AFXDOCKABLEPANE/CDockablePane::Slide
- AFXDOCKABLEPANE/CDockablePane::ToggleAutoHide
- AFXDOCKABLEPANE/CDockablePane::UndockPane
- AFXDOCKABLEPANE/CDockablePane::CheckAutoHideCondition
- AFXDOCKABLEPANE/CDockablePane::CheckStopSlideCondition
- AFXDOCKABLEPANE/CDockablePane::DrawCaption
- AFXDOCKABLEPANE/CDockablePane::OnPressButtons
- AFXDOCKABLEPANE/CDockablePane::OnSlide
- AFXDOCKABLEPANE/CDockablePane::m_bDisableAnimation
- AFXDOCKABLEPANE/CDockablePane::m_bHideInAutoHideMode
- AFXDOCKABLEPANE/CDockablePane::m_nSlideSteps
dev_langs:
- C++
helpviewer_keywords:
- CDockablePane class
ms.assetid: e2495f4c-765f-48f9-a2e2-e45e47608d91
caps.latest.revision: 34
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
ms.openlocfilehash: dea1f1ce66c0e9bedbe83109ab62055a4af2ebce
ms.lasthandoff: 02/25/2017

---
# <a name="cdockablepane-class"></a>Classe CDockablePane
Implementa um painel que pode ser encaixado em um site de encaixe ou incluído em um painel com guias.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDockablePane : public CPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockablePane::CDockablePane](#cdockablepane)|Constrói e inicializa um objeto `CDockablePane`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockablePane::AttachToTabWnd](#attachtotabwnd)|Anexa um painel para outro painel. Isso cria um painel com guias.|  
|[CDockablePane::CalcFixedLayout](#calcfixedlayout)|Retorna o tamanho do retângulo de painel.|  
|[CDockablePane::CanAcceptMiniFrame](#canacceptminiframe)|Determina se o quadro mini especificado pode ser encaixado ao painel.|  
|[CDockablePane::CanAcceptPane](#canacceptpane)|Determina se outro painel pode ser encaixado para o painel atual.|  
|[CDockablePane::CanAutoHide](#canautohide)|Determina se o painel oferece suporte ao modo de ocultar automaticamente. (Substitui [CBasePane::CanAutoHide](../../mfc/reference/cbasepane-class.md#canautohide).)|  
|[CDockablePane::CanBeAttached](#canbeattached)|Determina se o painel atual pode ser encaixado para outro painel.|  
|[CDockablePane::ConvertToTabbedDocument](#converttotabbeddocument)|Converte um ou mais painéis encaixáveis documentos MDI com guias.|  
|[CDockablePane::CopyState](#copystate)|Copia o estado de um painel acoplável.|  
|[CDockablePane::Create](#create)|Cria o controle do Windows e anexa-o para o `CDockablePane` objeto.|  
|[CDockablePane::CreateDefaultPaneDivider](#createdefaultpanedivider)|Cria um divisor padrão para o painel de como ele está sendo encaixado em uma janela de quadro.|  
|[CDockablePane::CreateEx](#createex)|Cria o controle do Windows e anexa-o para o `CDockablePane` objeto.|  
|[CDockablePane::CreateTabbedPane](#createtabbedpane)|Cria um painel com guias do painel atual.|  
|[CDockablePane::DockPaneContainer](#dockpanecontainer)|Encaixa um contêiner para o painel.|  
|[CDockablePane::DockPaneStandard](#dockpanestandard)|Encaixa um painel usando a estrutura de tópicos de encaixe (padrão).|  
|`CDockablePane::DockToFrameWindow`|Usado internamente. Para encaixar um painel, use [CPane::DockPane](../../mfc/reference/cpane-class.md#dockpane) ou [CDockablePane::DockToWindow](#docktowindow).|  
|[CDockablePane::DockToRecentPos](#docktorecentpos)|Encaixa um painel para sua posição de encaixe recente armazenada.|  
|[CDockablePane::DockToWindow](#docktowindow)|Encaixa um painel de encaixe para outro painel de encaixe.|  
|[CDockablePane::EnableAutohideAll](#enableautohideall)|Habilita ou desabilita o modo de ocultar automaticamente para esse painel junto com outros painéis no contêiner.|  
|[CDockablePane::EnableGripper](#enablegripper)|Mostra ou oculta a legenda (garra).|  
|[CDockablePane::GetAHRestoredRect](#getahrestoredrect)|Especifica a posição do painel quando visível no modo de ocultar automaticamente.|  
|[CDockablePane::GetAHSlideMode](#getahslidemode)|Recupera o modo de slide de ocultar automaticamente para o painel.|  
|`CDockablePane::GetAutoHideButton`|Usado internamente.|  
|`CDockablePane::GetAutoHideToolBar`|Usado internamente.|  
|[CDockablePane::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda do atual.|  
|[CDockablePane::GetDefaultPaneDivider](#getdefaultpanedivider)|Retorna o divisor de painéis padrão para o contêiner do painel.|  
|[CDockablePane::GetDockingStatus](#getdockingstatus)|Determina a capacidade de um painel encaixado com base no local do ponteiro fornecido.|  
|[CDockablePane::GetDragSensitivity](#getdragsensitivity)|Retorna a sensibilidade de arrastar de um painel de encaixe.|  
|[CDockablePane::GetLastPercentInPaneContainer](#getlastpercentinpanecontainer)|Recupera a porcentagem de espaço que ocupa um painel dentro do seu contêiner.|  
|[CDockablePane::GetTabArea](#gettabarea)|Recupera a área da guia do painel.|  
|[CDockablePane::GetTabbedPaneRTC](#gettabbedpanertc)|Retorna as informações de classe de tempo de execução sobre uma janela com guias que é criada quando outro painel encaixa ao painel atual.|  
|[CDockablePane::HasAutoHideMode](#hasautohidemode)|Especifica se um painel de encaixe pode ser alternado para o modo de ocultar automaticamente.|  
|[CDockablePane::HitTest](#hittest)|Especifica o local específico em um painel onde o usuário clica em um mouse.|  
|`CDockablePane::IsAccessibilityCompatible`|Usado internamente.|  
|[CDockablePane::IsAutohideAllEnabled](#isautohideallenabled)|Indica se o painel de encaixe e todos os outros painéis no contêiner podem ser colocados no modo de ocultar automaticamente.|  
|[CDockablePane::IsAutoHideMode](#isautohidemode)|Determina se um painel está no modo de ocultar automaticamente.|  
|`CDockablePane::IsChangeState`|Usado internamente.|  
|[CDockablePane::IsDocked](#isdocked)|Determina se o painel atual está encaixado.|  
|[CDockablePane::IsHideInAutoHideMode](#ishideinautohidemode)|Determina o comportamento de um painel que está no modo de ocultar automaticamente, se ele é exibido (ou oculto) chamando `ShowPane`.|  
|[CDockablePane::IsInFloatingMultiPaneFrameWnd](#isinfloatingmultipaneframewnd)|Especifica se o painel em uma janela de quadro de vários painéis.|  
|[CDockablePane::IsResizable](#isresizable)|Especifica se o painel é redimensionável.|  
|[CDockablePane::IsTabLocationBottom](#istablocationbottom)|Especifica se o guias estão localizadas na parte superior ou inferior do painel.|  
|[CDockablePane::IsTracked](#istracked)|Especifica se um painel está sendo arrastado pelo usuário.|  
|[CDockablePane::IsVisible](#isvisible)|Determina se o painel atual está visível.|  
|[CDockablePane::LoadState](http://msdn.microsoft.com/en-us/96110136-4f46-4764-8a76-3b4abaf77917)|Usado internamente.|  
|[CDockablePane::OnAfterChangeParent](#onafterchangeparent)|Chamado pela estrutura quando o pai de um painel é alterado. (Substitui [CPane::OnAfterChangeParent](../../mfc/reference/cpane-class.md#onafterchangeparent).)|  
|[CDockablePane::OnAfterDockFromMiniFrame](#onafterdockfromminiframe)|Chamado pela estrutura quando uma barra de encaixe flutuante se encaixa em uma janela do quadro.|  
|[CDockablePane::OnBeforeChangeParent](#onbeforechangeparent)|Chamado pela estrutura quando o pai do painel está prestes a ser alterada. (Substitui [CPane::OnBeforeChangeParent](../../mfc/reference/cpane-class.md#onbeforechangeparent).)|  
|[CDockablePane::OnBeforeFloat](#onbeforefloat)|Chamado pela estrutura quando um painel está prestes a float. (Substitui [CPane::OnBeforeFloat](../../mfc/reference/cpane-class.md#onbeforefloat).)|  
|[CDockablePane::RemoveFromDefaultPaneDividier](#removefromdefaultpanedividier)|O framework chama esse método quando um painel está sendo desencaixado.|  
|[CDockablePane::ReplacePane](#replacepane)|Substitui o painel com um painel especificado.|  
|[CDockablePane::RestoreDefaultPaneDivider](#restoredefaultpanedivider)|O framework chama esse método como um painel é desserializado para restaurar o divisor de painel padrão.|  
|`CDockablePane::SaveState`|Usado internamente.|  
|`CDockablePane::Serialize`|Serializa o painel. (Substitui `CBasePane::Serialize`.)|  
|[CDockablePane::SetAutoHideMode](#setautohidemode)|Alterna o painel de encaixe entre visível e o modo de ocultar automaticamente.|  
|[CDockablePane::SetAutoHideParents](#setautohideparents)|Define o botão Ocultar automaticamente e ocultar automaticamente a barra de ferramentas do painel.|  
|`CDockablePane::SetDefaultPaneDivider`|Usado internamente.|  
|[CDockablePane::SetLastPercentInPaneContainer](#setlastpercentinpanecontainer)|Define a porcentagem de espaço que ocupa um painel dentro do seu contêiner.|  
|`CDockablePane::SetResizeMode`|Usado internamente.|  
|[CDockablePane::SetRestoredDefaultPaneDivider](#setrestoreddefaultpanedivider)|Define o divisor de painel padrão restaurada.|  
|[CDockablePane::SetTabbedPaneRTC](#settabbedpanertc)|Define as informações de classe de tempo de execução para uma janela com guias que é criada quando dois painéis encaixe juntos.|  
|[CDockablePane::ShowPane](#showpane)|Mostra ou oculta um painel.|  
|[CDockablePane::Slide](#slide)|Mostra ou oculta um painel com uma animação deslizante que exibe apenas quando o painel está no modo de ocultar automaticamente.|  
|[CDockablePane::ToggleAutoHide](#toggleautohide)|Modo de ocultar automaticamente alterna. (Substitui [CPane::ToggleAutoHide](../../mfc/reference/cpane-class.md#toggleautohide) .)|  
|[CDockablePane::UndockPane](#undockpane)|Desencaixa um painel da janela principal do quadro ou um contêiner de janela miniframe.|  
|`CDockablePane::UnSetAutoHideMode`|Usado internamente. Para definir o modo de ocultar automaticamente, use [CDockablePane::SetAutoHideMode](#setautohidemode)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockablePane::CheckAutoHideCondition](#checkautohidecondition)|Determina se o painel de encaixe está oculto (no modo de ocultar automaticamente).|  
|[CDockablePane::CheckStopSlideCondition](#checkstopslidecondition)|Determina quando um painel de encaixe de ocultação automática deve parar deslizante.|  
|[CDockablePane::DrawCaption](#drawcaption)|Desenha a legenda encaixe do painel (garra).|  
|[CDockablePane::OnPressButtons](#onpressbuttons)|Chamado quando o usuário pressionar um botão legenda que o `AFX_HTCLOSE` e `AFX_HTMAXBUTTON` botões.|  
|[CDockablePane::OnSlide](#onslide)|Chamado pela estrutura para renderizar o efeito de slide ocultar automaticamente quando o painel é mostrado ou oculto.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDockablePane::m_bDisableAnimation](#m_bdisableanimation)|Especifica se a animação de ocultação automática do painel acoplável está desabilitada.|  
|[CDockablePane::m_bHideInAutoHideMode](#m_bhideinautohidemode)|Determina o comportamento do painel quando o painel está no modo de ocultar automaticamente.|  
|[CDockablePane::m_nSlideSteps](#m_nslidesteps)|Especifica a velocidade da animação do painel quando ele está sendo mostrado ou oculto quando no modo de ocultar automaticamente.|  
  
## <a name="remarks"></a>Comentários  
 `CDockablePane`implementa a seguinte funcionalidade:  
  
-   Encaixar um painel para uma janela de quadro principal.  
  
-   Alternar um painel para o modo de ocultar automaticamente.  
  
-   Anexando um painel para uma janela com guias.  
  
-   Flutuante um painel em uma janela miniframe.  
  
-   Encaixar um painel para outro painel flutuante em uma janela miniframe.  
  
-   Redimensionar um painel.  
  
-   Carregar e salvar o estado de um painel de encaixe.  
  
    > [!NOTE]
    >  As informações de estado é salvo no registro do Windows.  
  
-   Criando um painel com ou sem uma legenda. A legenda pode ter um rótulo de texto e ele pode ser preenchido com uma cor de gradiente.  
  
-   Arrastando um painel ao exibir o conteúdo do painel  
  
-   Arrastando um painel ao exibir um retângulo de arrastar.  
  
 Para usar um painel de encaixe em seu aplicativo, derive sua classe do painel do `CDockablePane` classe. Ou incorporar o objeto derivado para o objeto de janela do quadro principal ou em um objeto de janela que controla a instância do painel. Em seguida, chame o [CDockablePane::Create](#create) método ou o [CDockablePane::CreateEx](#createex) método ao processar o `WM_CREATE` mensagem na janela do quadro principal. Finalmente, defina o objeto de painel chamando [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking), [CBasePane::DockPane](../../mfc/reference/cbasepane-class.md#dockpane), ou [CDockablePane::AttachToTabWnd](#attachtotabwnd).  
  
## <a name="customization-tips"></a>Dicas de personalização  
 As dicas a seguir se aplicam a `CDockablePane` objetos:  
  
-   Se você chamar [CDockablePane::AttachToTabWnd](#attachtotabwnd) para dois painéis encaixáveis, não com guias, um ponteiro para uma janela com guias será retornado o `ppTabbedControlBar` parâmetro. Você pode continuar a adicionar guias na janela com guias usando esse parâmetro.  
  
-   O tipo de painel com guias que é criado pela [CDockablePane::AttachToTabWnd](#attachtotabwnd) é determinado pelo `CDockablePane` objeto o `pTabControlBarAttachTo` parâmetro. Você pode chamar [CDockablePane::SetTabbedPaneRTC](#settabbedpanertc) para definir o tipo de painel com guias que o `CDockablePane` será criado. O tipo padrão é determinado pelo `dwTabbedStyle` de [CDockablePane::Create](#create) quando você cria o `CDockablePane`. Se `dwTabbedStyle` é o tipo padrão é de AFX_CBRS_OUTLOOK_TABS [CMFCOutlookBar classe](../../mfc/reference/cmfcoutlookbar-class.md); se `dwTabbedStyle` é o tipo padrão é de AFX_CBRS_REGULAR_TABS [CTabbedPane classe](../../mfc/reference/ctabbedpane-class.md).  
  
-   Se você deseja encaixar um painel acoplável para outro, chame o [CDockablePane::DockToWindow](#docktowindow) método. O painel original deve ser encaixado em algum lugar antes de chamar esse método.  
  
-   A variável de membro [CDockablePane::m_bHideInAutoHideMode](#m_bhideinautohidemode) controles como o comportamento dos painéis encaixáveis Auto Ocultar modo quando você chama [CDockablePane::ShowPane](#showpane). Se essa variável de membro é definido como `TRUE`, painéis encaixáveis e seus botões de ocultar automaticamente ficará oculta. Caso contrário, eles serão slide e sair.  
  
-   Você pode desativar a animação de ocultar automaticamente definindo a [CDockablePane::m_bDisableAnimation](#m_bdisableanimation) variável de membro para `TRUE`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um `CDockablePane` objeto usando vários métodos na `CDockablePane` classe. O exemplo ilustra como habilitar a ocultar automaticamente todos os recursos para o painel acoplável, a legenda ou garra, habilitar o modo de ocultar automaticamente, mostrar o painel e animar um painel que está no modo de ocultar automaticamente. Este trecho de código é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#27;](../../mfc/codesnippet/cpp/cdockablepane-class_1.cpp)]  
[!code-cpp[NVC_MFC_VisualStudioDemo&#28;](../../mfc/codesnippet/cpp/cdockablepane-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CDockablePane](../../mfc/reference/cdockablepane-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDockablePane.h  
  
##  <a name="attachtotabwnd"></a>CDockablePane::AttachToTabWnd  
 Anexa o painel atual para um painel de destino, criando um painel com guias.  
  
```  
virtual CDockablePane* AttachToTabWnd(
    CDockablePane* pTabControlBarAttachTo,  
    AFX_DOCK_METHOD dockMethod,  
    BOOL bSetActive= TRUE,  
    CDockablePane** ppTabbedControlBar = NULL);  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out]`pTabControlBarAttachTo`  
 Especifica que liga o painel atual ao painel de destino. O painel de destino deve ser um painel acoplável.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe.  
  
 [in] `bSetActive`  
 `TRUE`Para ativar o painel com guias após a operação de anexação. Caso contrário, `FALSE`.  
  
 [out] `ppTabbedControlBar`  
 Contém o painel com guias que resulta da operação de anexação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o painel atual, se não for um painel com guias; Caso contrário, um ponteiro para o painel com guias que resulta da operação de anexação. O valor de retorno é `NULL` se o painel atual não pode ser anexado, ou se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel acoplável anexa a outro painel usando esse método, ocorre o seguinte:  
  
1.  As verificações de estrutura se o painel de destino `pTabControlBarAttachTo` é uma expressão de encaixe painel ou se ela é derivada de [CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md).  
  
2.  Se o painel de destino é um painel com guias, o framework adiciona o painel atual a ele como uma guia.  
  
3.  Se o painel de destino é um painel de encaixe comum, o framework cria um painel com guias.  
  
    -   O framework chama `pTabControlBarAttachTo->CreateTabbedPane`. O estilo do novo painel com guias depende do `m_pTabbedControlBarRTC` membro. Por padrão, esse membro é definido como a classe de tempo de execução do [CTabbedPane](../../mfc/reference/ctabbedpane-class.md). Se você passar o `AFX_CBRS_OUTLOOK_TABS` de estilo como o `dwTabbedStyle` parâmetro para o [CDockablePane::Create](#create) método, o objeto de classe de tempo de execução é definido como a classe de tempo de execução do [CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md). Você pode alterar esse membro a qualquer momento para alterar o estilo do painel de novo.  
  
    -   Quando esse método cria um painel com guias, o framework substitui o ponteiro para `pTabControlBarAttachTo` (se o painel estiver encaixado ou flutuante em uma janela de múltiplas miniframe) com um ponteiro para o novo painel com guias.  
  
    -   Adiciona a estrutura de `pTabControlBarAttachTo` para o painel com guias, como a primeira guia. O framework, em seguida, adiciona o painel atual como uma segunda guia.  
  
4.  Se o painel atual é derivado de `CBaseTabbedPane`, todas as suas guias são movidas para `pTabControlBarAttachTo` e o painel atual é destruído. Portanto, tenha cuidado ao chamar esse método, pois um ponteiro para o painel atual pode ser inválido quando o método retorna.  
  
 Se você anexar um painel para outro quando estiver criando um layout de encaixe, defina `dockMethod` para `DM_SHOW`.  
  
 Você deve encaixar o painel primeiro antes de anexar outro painel para ele.  
  
##  <a name="calcfixedlayout"></a>CDockablePane::CalcFixedLayout  
 Retorna o tamanho do retângulo de painel.  
  
```  
virtual CSize CalcFixedLayout(
    BOOL bStretch,  
    BOOL bHorz);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bStretch`  
 Não usado.  
  
 [in] `bHorz`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que contém o tamanho do retângulo de painel.  
  
##  <a name="canacceptminiframe"></a>CDockablePane::CanAcceptMiniFrame  
 Determina se miniquadro especificado pode ser encaixado ao painel.  
  
```  
virtual BOOL CanAcceptMiniFrame(CPaneFrameWnd* pMiniFrame) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMiniFrame`  
 Ponteiro para uma `CPaneFrameWnd` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se `pMiniFrame` podem ser encaixados no painel; caso contrário, `FALSE`.  
  
##  <a name="canacceptpane"></a>CDockablePane::CanAcceptPane  
 Determina se outro painel pode ser encaixado para o painel atual.  
  
```  
virtual BOOL CanAcceptPane(const CBasePane* pBar) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBar`  
 Especifica o painel para encaixar o painel atual.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel especificado pode ser encaixado para esse painel; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método antes de um painel é encaixado para o painel atual.  
  
 Substitua essa função em uma classe derivada para ativar ou desativar encaixe para um painel específico.  
  
 Por padrão, esse método retorna `TRUE` se `pBar` ou seu pai é do tipo `CDockablePane`.  
  
##  <a name="canautohide"></a>CDockablePane::CanAutoHide  
 Determina se o painel pode ocultar automaticamente.  
  
```  
virtual BOOL CanAutoHide() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel pode ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 `CDockablePane::CanAutoHide`Retorna `FALSE` em qualquer uma das seguintes situações:  
  
-   O painel não tem nenhum pai.  
  
-   O Gerenciador de encaixe não permite painéis para ocultar automaticamente.  
  
-   O painel não é encaixado.  
  
##  <a name="canbeattached"></a>CDockablePane::CanBeAttached  
 Determina se o painel atual pode ser encaixado para outro painel.  
  
```  
virtual BOOL CanBeAttached() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável pode ser encaixado para outro painel ou a janela do quadro principal; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retornará `TRUE`. Substitua esse método em uma classe derivada para ativar ou desativar encaixe sem chamar [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking).  
  
##  <a name="cdockablepane"></a>CDockablePane::CDockablePane  
 Constrói e inicializa um [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto.  
  
```  
CDockablePane();
```  
  
### <a name="remarks"></a>Comentários  
 Depois que você construir um objeto de painel acoplável, chame [CDockablePane::Create](#create) ou [CDockablePane::CreateEx](#createex) para criá-lo.  
  
##  <a name="converttotabbeddocument"></a>CDockablePane::ConvertToTabbedDocument  
 Converte um ou mais painéis encaixáveis documentos MDI com guias.  
  
```  
virtual void ConvertToTabbedDocument(BOOL bActiveTabOnly = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bActiveTabOnly`  
 Quando você converte um `CTabbedPane`, especifique `TRUE` para converter apenas a guia ativa. Especifique `FALSE` para converter todas as guias no painel.  
  
##  <a name="checkautohidecondition"></a>CDockablePane::CheckAutoHideCondition  
 Determina se o painel de encaixe está oculto (também conhecido como modo de ocultar automaticamente).  
  
```  
virtual BOOL CheckAutoHideCondition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a condição de ocultar é atendida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa um temporizador para verificar periodicamente se deseja ocultar um painel acoplável ocultar automaticamente. O método retorna `TRUE` quando o painel não estiver ativo, o painel não está sendo redimensionado e não é o ponteiro do mouse sobre o painel.  
  
 Se todas as condições anteriores forem atendidas, a estrutura chama [CDockablePane::Slide](#slide) para ocultar o painel.  
  
##  <a name="checkstopslidecondition"></a>CDockablePane::CheckStopSlideCondition  
 Determina quando um painel de encaixe AutoOcultar deve parar deslizante.  
  
```  
virtual BOOL CheckStopSlideCondition(BOOL bDirection);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDirection`  
 `TRUE`Se o painel estiver visível; `FALSE` se o painel está oculto.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a condição de parada for atendida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel acoplável é definido para o modo de ocultar automaticamente, a estrutura usa efeitos deslizantes para mostrar ou ocultar o painel. O framework chama essa função quando o painel é deslizante. `CheckStopSlideCondition`Retorna `TRUE` quando o painel é totalmente visível ou quando ela é totalmente oculta.  
  
 Substitua esse método em uma classe derivada implementar efeitos AutoOcultar personalizado.  
  
##  <a name="copystate"></a>CDockablePane::CopyState  
 Copia o estado de um painel acoplável.  
  
```  
virtual void CopyState(CDockablePane* pOrgBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pOrgBar`  
 Um ponteiro para um painel acoplável.  
  
### <a name="remarks"></a>Comentários  
 `CDockablePane::CopyState`Copia o estado do `pOrgBar` para o painel atual chamando os métodos a seguir:  
  
- [CPane::CopyState](../../mfc/reference/cpane-class.md#copystate)  
  
- [CDockablePane::GetAHRestoredRect](#getahrestoredrect)  
  
- [CDockablePane::GetAHSlideMode](#getahslidemode)  
  
- [CDockablePane::GetLastPercentInPaneContainer](#getlastpercentinpanecontainer)  
  
- [CDockablePane::IsAutohideAllEnabled](#isautohideallenabled)  
  
##  <a name="create"></a>CDockablePane::Create  
 Cria o controle do Windows e anexa-o para o [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszCaption,  
    CWnd* pParentWnd,  
    const RECT& rect,  
    BOOL bHasGripper,  
    UINT nID,  
    DWORD dwStyle,  
    DWORD dwTabbedStyle = AFX_CBRS_REGULAR_TABS,  
    DWORD dwControlBarStyle = AFX_DEFAULT_DOCKING_PANE_STYLE,  
    CCreateContext* pContext = NULL);

 
virtual BOOL Create(
    LPCTSTR lpszWindowName,  
    CWnd* pParentWnd,  
    CSize sizeDefault,  
    BOOL bHasGripper,  
    UINT nID,  
    DWORD dwStyle = WS_CHILD|WS_VISIBLE|CBRS_TOP|CBRS_HIDE_INPLACE,  
    DWORD dwTabbedStyle = AFX_CBRS_REGULAR_TABS,  
    DWORD dwControlBarStyle = AFX_DEFAULT_DOCKING_PANE_STYLE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszCaption`  
 Especifica o nome da janela.  
  
 [in] [out]`pParentWnd`  
 Especifica a janela pai.  
  
 [in] `rect`  
 Especifica o tamanho e a posição da janela, em coordenadas do cliente de `pParentWnd`.  
  
 [in] `bHasGripper`  
 `TRUE`para criar o painel com uma legenda; Caso contrário, `FALSE`.  
  
 [in] `nID`  
 Especifica a identificação da janela filho. Esse valor deve ser exclusivo, se você deseja salvar o estado de encaixe para este painel de encaixe.  
  
 [in] `dwStyle`  
 Especifica os atributos de estilo da janela.  
  
 [in] `dwTabbedStyle`  
 Especifica o estilo com guias de uma janela com guias que é criado quando o usuário arrasta um painel na legenda deste painel.  
  
 [in] `dwControlBarStyle`  
 Especifica os atributos de estilo adicionais.  
  
 [in] [out]`pContext`  
 Especifica o contexto de criação da janela.  
  
 [in] `lpszWindowName`  
 Especifica o nome da janela.  
  
 [in] `sizeDefault`  
 Especifica o tamanho da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável é criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Cria um painel do Windows e anexa-o para o `CDockablePane` objeto.  
  
 Se o `dwStyle` estilo da janela tem o `CBRS_FLOAT_MULTI` sinalizador, a janela miniframe pode flutuar com outros painéis na janela miniframe. Por padrão, painéis de encaixe podem apenas ser flutuantes individualmente.  
  
 Se o `dwTabbedStyle` parâmetro tem o `AFX_CBRS_OUTLOOK_TABS` sinalizador especificado, o painel cria painéis do Outlook-style com guias quando outro painel é anexado a esse painel usando o [CDockablePane::AttachToTabWnd](#attachtotabwnd) método. Por padrão, os painéis encaixáveis criam painéis com guias regulares do tipo [CTabbedPane](../../mfc/reference/ctabbedpane-class.md).  
  
##  <a name="createdefaultpanedivider"></a>CDockablePane::CreateDefaultPaneDivider  
 Cria um divisor padrão para o painel de como ele está sendo encaixado em uma janela de quadro.  
  
```  
static CPaneDivider* __stdcall CreateDefaultPaneDivider(
    DWORD dwAlignment,  
    CWnd* pParent,  
    CRuntimeClass* pSliderRTC = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwAlignment`  
 Especifica o lado do quadro principal ao qual o painel está encaixado. Se `dwAlignment` contém o `CBRS_ALIGN_LEFT` ou `CBRS_ALIGN_RIGHT` sinalizador, esse método cria uma vertical ( `CPaneDivider::SS_VERT`) divisor; caso contrário, esse método cria um horizontal ( `CPaneDivider::SS_HORZ`) divisor.  
  
 [in] `pParent`  
 Ponteiro para o quadro principal.  
  
 [in] `pSliderRTC`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Esse método retorna um ponteiro para o divisor recém-criado, ou `NULL` se houver falha na criação do divisor.  
  
### <a name="remarks"></a>Comentários  
 `dwAlignment`pode ser qualquer um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`CBRS_ALIGN_TOP`|O painel está sendo encaixado na parte superior da área do cliente de uma janela de quadro.|  
|`CBRS_ALIGN_BOTTOM`|O painel está sendo encaixado na parte inferior da área do cliente de uma janela de quadro.|  
|`CBRS_ALIGN_LEFT`|O painel está sendo encaixado à esquerda da área do cliente de uma janela de quadro.|  
|`CBRS_ALIGN_RIGHT`|O painel é sendo encaixado à direita da área do cliente de uma janela de quadro.|  
  
##  <a name="createex"></a>CDockablePane::CreateEx  
 Cria o controle do Windows e anexa-o para o [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwStyleEx,  
    LPCTSTR lpszCaption,  
    CWnd* pParentWnd,  
    const RECT& rect,  
    BOOL bHasGripper,  
    UINT nID,  
    DWORD dwStyle,  
    DWORD dwTabbedStyle = AFX_CBRS_REGULAR_TABS,  
    DWORD dwControlBarStyle = AFX_DEFAULT_DOCKING_PANE_STYLE,  
    CCreateContext* pContext = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwStyleEx`  
 Especifica os atributos de estilo estendido para a nova janela.  
  
 [in] `lpszCaption`  
 Especifica o nome da janela.  
  
 [in] [out]`pParentWnd`  
 Especifica a janela pai.  
  
 [in] `rect`  
 Especifica o tamanho e a posição da janela, em coordenadas do cliente de `pParentWnd`.  
  
 [in] `bHasGripper`  
 `TRUE`para criar o painel com uma legenda; Caso contrário, `FALSE`.  
  
 [in] `nID`  
 Especifica a identificação da janela filho. Esse valor deve ser exclusivo, se você deseja salvar o estado de encaixe para este painel de encaixe.  
  
 [in] `dwStyle`  
 Especifica os atributos de estilo da janela.  
  
 [in] `dwTabbedStyle`  
 Especifica o estilo com guias de uma janela com guias que é criado quando o usuário arrasta um painel na legenda deste painel.  
  
 [in] `dwControlBarStyle`  
 Especifica os atributos de estilo adicionais.  
  
 [in] [out]`pContext`  
 Especifica o contexto de criação da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável é criado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Cria um painel do Windows e anexa-o para o `CDockablePane` objeto.  
  
 Se o `dwStyle` estilo da janela tem o `CBRS_FLOAT_MULTI` sinalizador, a janela miniframe pode flutuar com outros painéis na janela miniframe. Por padrão, painéis de encaixe podem apenas ser flutuantes individualmente.  
  
 Se o `dwTabbedStyle` parâmetro tem o `AFX_CBRS_OUTLOOK_TABS` sinalizador especificado, o painel cria painéis do Outlook-style com guias quando outro painel é anexado a esse painel usando o [CDockablePane::AttachToTabWnd](#attachtotabwnd) método. Por padrão, os painéis encaixáveis criam painéis com guias regulares do tipo [CTabbedPane](../../mfc/reference/ctabbedpane-class.md).  
  
##  <a name="createtabbedpane"></a>CDockablePane::CreateTabbedPane  
 Cria um painel com guias do painel atual.  
  
```  
virtual CTabbedPane* CreateTabbedPane();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O novo painel com guias ou `NULL` se a operação de criação falha.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando ele cria um painel com guias para substituir esse painel. Para obter mais informações, consulte [CDockablePane::AttachToTabWnd](#attachtotabwnd).  
  
 Substituir esse método em uma classe derivada para personalizar painéis como com guias são criados e inicializados.  
  
 Painel com guias é criado de acordo com as informações de classe de tempo de execução armazenadas na `m_pTabbedControlBarRTC` membro, que é inicializado, o [CDockablePane::CreateEx](#createex) método.  
  
##  <a name="dockpanecontainer"></a>CDockablePane::DockPaneContainer  
 Encaixa um contêiner para o painel.  
  
```  
virtual BOOL DockPaneContainer(
    CPaneContainerManager& barContainerManager,  
    DWORD dwAlignment,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `barContainerManager`  
 Uma referência ao Gerenciador de contêiner do contêiner que está sendo encaixado.  
  
 [in] `dwAlignment`  
 `DWORD`que especifica o lado do painel ao qual o contêiner está sendo encaixado.  
  
 [in] `dockMethod`  
 Não usado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o contêiner foi encaixado com êxito para o painel; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 `dwAlignment`pode ser qualquer um dos seguintes valores:  
  
|Valor|Descrição|  
|-----------|-----------------|  
|`CBRS_ALIGN_TOP`|O contêiner está sendo encaixado na parte superior do painel.|  
|`CBRS_ALIGN_BOTTOM`|O contêiner está sendo encaixado na parte inferior do painel.|  
|`CBRS_ALIGN_LEFT`|O contêiner está sendo encaixado à esquerda do painel.|  
|`CBRS_ALIGN_RIGHT`|O contêiner está sendo encaixado à direita do painel.|  
  
##  <a name="dockpanestandard"></a>CDockablePane::DockPaneStandard  
 Encaixa um painel usando a estrutura de tópicos de encaixe (padrão).  
  
```  
virtual CPane* DockPaneStandard(BOOL& bWasDocked);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bWasDocked`  
 Quando o método retorna, esse valor contém `TRUE` se o painel com êxito encaixado; caso contrário, ele contém `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o painel foi encaixado em uma janela com guias, ou se uma janela com guias foi criada como resultado de encaixe, esse método retorna um ponteiro para a janela com guias. Se o painel tenha sido encaixada com êxito, esse método retorna o `this` ponteiro. Se encaixe falhado, esse método retornará `NULL`.  
  
##  <a name="docktorecentpos"></a>CDockablePane::DockToRecentPos  
 Encaixa um painel para sua posição de encaixe armazenada.  
  
```  
BOOL CDockablePane::DockToRecentPos();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel está encaixado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Painéis encaixáveis armazenam informações recentes de encaixe em uma [CRecentDockSiteInfo](../../mfc/reference/crecentdocksiteinfo-class.md) objeto.  
  
##  <a name="docktowindow"></a>CDockablePane::DockToWindow  
 Encaixa um painel de encaixe para outro painel de encaixe.  
  
```  
virtual BOOL DockToWindow(
    CDockablePane* pTargetWindow,  
    DWORD dwAlignment,  
    LPCRECT lpRect = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] [out]`pTargetWindow`  
 Especifica o painel acoplável para encaixar esse painel.  
  
 [in] `dwAlignment`  
 Especifica o alinhamento de encaixe do painel. Pode ser um dos CBRS_ALIGN_LEFT, CBRS_ALIGN_TOP, CBRS_ALIGN_RIGHT, CBRS_ALIGN_BOTTOM ou CBRS_ALIGN_ANY. (Definido em afxres.h).  
  
 [in] `lpRect`  
 Especifica o retângulo de encaixe do painel.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel foi encaixado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para encaixar um painel para outro painel com o alinhamento especificado por `dwAlignment`.  
  
##  <a name="drawcaption"></a>CDockablePane::DrawCaption  
 Desenha a legenda (também chamada de garra) de um painel de encaixe.  
  
```  
virtual void DrawCaption(
    CDC* pDC,  
    CRect rectCaption);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Representa o contexto de dispositivo usado para o desenho.  
  
 [in] `rectCaption`  
 Especifica o retângulo delimitador da legenda do painel.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para desenhar a legenda de um painel acoplável.  
  
 Substitua esse método em uma classe derivada para personalizar a aparência da legenda.  
  
##  <a name="enableautohideall"></a>CDockablePane::EnableAutohideAll  
 Habilita ou desabilita o modo de ocultar automaticamente para esse painel e para outros painéis no contêiner.  
  
```  
void EnableAutohideAll(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a ocultar automaticamente todos os recursos para o painel acoplável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando um usuário mantém o `Ctrl` chave e clica no botão de pin para alternar de um painel para o modo de ocultar automaticamente, todos os outros painéis no mesmo contêiner também são alternados para o modo de ocultar automaticamente.  
  
 Chamar esse método com `bEnable` definida como `FALSE` para desabilitar esse recurso para um determinado painel.  
  
##  <a name="enablegripper"></a>CDockablePane::EnableGripper  
 Mostra ou oculta a legenda (também chamada de garra).  
  
```  
virtual void EnableGripper(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar a legenda; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando o framework cria painéis encaixáveis, eles não têm o **WS_STYLE** estilo da janela, mesmo se especificado. Isso significa que a legenda do painel é uma área não cliente que é controlada pela estrutura, mas essa área difere de legenda da janela padrão.  
  
 Você pode mostrar ou ocultar a legenda a qualquer momento. O framework oculta a legenda quando um painel é adicionado como uma guia para uma janela com guias ou quando um painel é flutuante em uma janela miniframe.  
  
##  <a name="getahrestoredrect"></a>CDockablePane::GetAHRestoredRect  
 Especifica a posição do painel no modo de ocultar automaticamente.  
  
```  
CRect GetAHRestoredRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que contém a posição do painel quando ele estiver no modo de ocultar automaticamente.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getahslidemode"></a>CDockablePane::GetAHSlideMode  
 Recupera o modo de slide de ocultar automaticamente para o painel.  
  
```  
virtual UINT GetAHSlideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `UINT` que especifica o modo de slide de ocultar automaticamente para o painel. O valor de retorno pode ser `AFX_AHSM_MOVE` ou `AFX_AHSM_STRETCH`, mas a implementação usa apenas `AFX_AHSM_MOVE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcaptionheight"></a>CDockablePane::GetCaptionHeight  
 Retorna a altura, em pixels, da legenda do atual.  
  
```  
virtual int GetCaptionHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura da legenda, em pixels.  
  
### <a name="remarks"></a>Comentários  
 A altura da legenda é 0 se a legenda ocultos pelo [CDockablePane::EnableGripper](#enablegripper) método, ou se o painel não tem uma legenda.  
  
##  <a name="getdefaultpanedivider"></a>CDockablePane::GetDefaultPaneDivider  
 Retorna o divisor de painéis padrão para o contêiner do painel.  
  
```  
CPaneDivider* GetDefaultPaneDivider() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Válido [CPaneDivider](../../mfc/reference/cpanedivider-class.md) objeto se o painel acoplável é encaixado à janela principal do quadro, ou `NULL` se o painel encaixável não é encaixado ou se ele estiver flutuando.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre os divisores de painel, consulte [CPaneDivider classe](../../mfc/reference/cpanedivider-class.md).  
  
##  <a name="getdockingstatus"></a>CDockablePane::GetDockingStatus  
 Determina a capacidade de um painel encaixado com base no local do ponteiro fornecido.  
  
```  
virtual AFX_CS_STATUS GetDockingStatus(
    CPoint pt,  
    int nSensitivity);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pt`  
 O local do ponteiro em coordenadas de tela.  
  
 [in] `nSensitivity`  
 A distância, em pixels, da borda de um retângulo o ponteiro deve estar Ativar encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos valores de status a seguir:  
  
|Valor `AFX_CS_STATUS`|Significado|  
|---------------------------|-------------|  
|`CS_NOTHING`|O ponteiro não está em um site de encaixe. A estrutura não encaixar o painel.|  
|`CS_DOCK_IMMEDIATELY`|O ponteiro estiver localizado em um site de encaixe em modo imediato (o painel usa o `DT_IMMEDIATE` modo de encaixe). O framework encaixa o painel imediatamente.|  
|`CS_DELAY_DOCK`|O ponteiro está sobre um site de encaixe outro painel de encaixe ou uma borda do quadro principal. O framework encaixa o painel após um atraso. Consulte a seção de comentários para obter mais informações sobre esse atraso.|  
|`CS_DELAY_DOCK_TO_TAB`|O ponteiro estiver localizado em um site de encaixe que faz com que o painel seja encaixado em uma janela com guias. Isso ocorre quando o ponteiro estiver localizado pela legenda de outro painel de encaixe ou a área da guia de um painel com guias.|  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para manipular o encaixe de um painel flutuante.  
  
 Para barras flutuantes ou encaixando painéis que usam o `DT_IMMEDIATE` encaixe modo, o framework atrasa o comando de encaixe para permitir que o usuário mover a janela da área de cliente do quadro principal antes de encaixe ocorre. O tempo de atraso é medido em milissegundos e é controlado pelo [CDockingManager::m_nTimeOutBeforeToolBarDock](../../mfc/reference/cdockingmanager-class.md#m_ntimeoutbeforetoolbardock) membro de dados... O valor padrão de [CDockingManager::m_nTimeOutBeforeToolBarDock](../../mfc/reference/cdockingmanager-class.md#m_ntimeoutbeforetoolbardock) é 200. Esse comportamento emula o comportamento de encaixe da [!INCLUDE[ofprword](../../mfc/reference/includes/ofprword_md.md)] 2007.  
  
 Para o atraso de estados de encaixe ( `CS_DELAY_DOCK` e `CS_DELAY_DOCK_TO_TAB`), a estrutura não executa encaixe até que o usuário solta o botão do mouse. Se usar um painel de `DT_STANDARD` encaixe modo, o framework exibe um retângulo no local de encaixe projetado. Se usar um painel de `DT_SMART` encaixe modo, o framework exibe marcadores de encaixe inteligente e retângulos semitransparentes no local de encaixe projetado. Para especificar o modo de encaixe para o painel, chame o [CBasePane::SetDockingMode](../../mfc/reference/cbasepane-class.md#setdockingmode) método. Para obter mais informações sobre o encaixe inteligentes, consulte [CDockingManager::GetSmartDockingParams](../../mfc/reference/cdockingmanager-class.md#getsmartdockingparams).  
  
##  <a name="getdragsensitivity"></a>CDockablePane::GetDragSensitivity  
 Retorna a sensibilidade de arrastar de um painel de encaixe.  
  
```  
static const CSize& GetDragSensitivity();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém a largura e altura em pixels, de um retângulo centralizado em um ponto de arrastar. A operação de arrastar não começa até que o ponteiro do mouse é movido para fora desse retângulo.  
  
##  <a name="getlastpercentinpanecontainer"></a>CDockablePane::GetLastPercentInPaneContainer  
 Recupera a porcentagem de espaço que ocupa um painel em seu contêiner ( [CPaneContainer classe](../../mfc/reference/cpanecontainer-class.md)).  
  
```  
int GetLastPercentInPaneContainer() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `int` que especifica a porcentagem de espaço que o painel ocupa em seu contêiner.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado quando o contêiner ajusta seu layout.  
  
##  <a name="gettabarea"></a>CDockablePane::GetTabArea  
 Recupera a área da guia do painel.  
  
```  
virtual void GetTabArea(
    CRect& rectTabAreaTop,  
    CRect& rectTabAreaBottom) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectTabAreaTop`  
 `GetTabArea`preenche essa variável com a área da guia se guias estão localizadas na parte superior do painel. Se o guias estão localizadas na parte inferior do painel, essa variável é preenchida com um retângulo vazio.  
  
 [in] `rectTabAreaBottom`  
 `GetTabArea`preenche essa variável com a área da guia se guias estão localizadas na parte inferior do painel. Se o guias estão localizadas na parte superior do painel, essa variável é preenchida com um retângulo vazio.  
  
### <a name="remarks"></a>Comentários  
 Esse método é usado somente em classes derivadas de `CDockablePane` e guias. Para obter mais informações, consulte [CTabbedPane::GetTabArea](../../mfc/reference/ctabbedpane-class.md#gettabarea) e [CMFCOutlookBar::GetTabArea](../../mfc/reference/cmfcoutlookbar-class.md#gettabarea).  
  
##  <a name="gettabbedpanertc"></a>CDockablePane::GetTabbedPaneRTC  
 Retorna as informações de classe de tempo de execução sobre uma janela com guias que é criada quando outro painel encaixa ao painel atual.  
  
```  
CRuntimeClass* GetTabbedPaneRTC() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 As informações de classe de tempo de execução para o painel acoplável.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para recuperar as informações de classe de tempo de execução para painéis com guias que são criados dinamicamente. Isso pode ocorrer quando um usuário arrasta um painel para a legenda do outro painel, ou se você chamar o [CDockablePane::AttachToTabWnd](#attachtotabwnd) método para criar programaticamente um painel com guias de dois painéis encaixáveis.  
  
 Você pode definir as informações de classe de tempo de execução chamando o [CDockablePane::SetTabbedPaneRTC](#settabbedpanertc) método.  
  
##  <a name="hasautohidemode"></a>CDockablePane::HasAutoHideMode  
 Especifica se um painel de encaixe pode ser alternado para o modo de ocultar automaticamente.  
  
```  
virtual BOOL HasAutoHideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável pode ser alternado para o modo de ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para desabilitar o modo de ocultar automaticamente para um painel acoplável específico.  
  
##  <a name="hittest"></a>CDockablePane::HitTest  
 Especifica o local em um painel onde o usuário clica em um mouse.  
  
```  
virtual int HitTest(
    CPoint point,  
    BOOL bDetectCaption = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Especifica o ponto de teste.  
  
 [in] `bDetectCaption`  
 `TRUE`Se `HTCAPTION` deve ser retornado se o ponto está na legenda do painel; caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um dos seguintes valores:  
  
- `HTNOWHERE`Se `point` não está no painel acoplável.  
  
- `HTCLIENT`Se `point` está na área do cliente do painel acoplável.  
  
- `HTCAPTION`Se `point` está na área de legenda do painel acoplável.  
  
- `AFX_HTCLOSE`Se `point` está no botão Fechar.  
  
- `HTMAXBUTTON`Se `point` estiver no botão pin.  
  
##  <a name="isautohideallenabled"></a>CDockablePane::IsAutohideAllEnabled  
 Indica se o painel de encaixe e todos os outros painéis no contêiner podem ser alternados para o modo de ocultar automaticamente.  
  
```  
virtual BOOL IsAutohideAllEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel encaixável e todos os outros painéis no contêiner, podem ser alternados para o modo de ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Um usuário habilita o modo de ocultar automaticamente, clicando no botão de pin encaixe ao mesmo tempo mantendo a **Ctrl** chave  
  
 Para habilitar ou desabilitar esse comportamento, chame o [CDockablePane::EnableAutohideAll](#enableautohideall) método.  
  
##  <a name="isautohidemode"></a>CDockablePane::IsAutoHideMode  
 Determina se um painel está no modo de ocultar automaticamente.  
  
```  
virtual BOOL IsAutoHideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável estiver no modo de ocultar automaticamente. Caso contrário, `FALSE`.  
  
##  <a name="isdocked"></a>CDockablePane::IsDocked  
 Determina se o painel atual está encaixado.  
  
```  
virtual BOOL IsDocked() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel encaixável não pertence a uma janela miniframe ou se ele estiver flutuando em uma janela miniframe com outro painel. `FALSE`Se o painel é um filho de uma janela miniframe e não outros painéis que pertencem à janela miniframe.  
  
### <a name="remarks"></a>Comentários  
 Para determinar se o painel está encaixado na janela do quadro principal, chame [CDockablePane::GetDefaultPaneDivider](#getdefaultpanedivider). Se o método retorna um ponteiro não-NULL, o painel é encaixado na janela principal do quadro.  
  
##  <a name="ishideinautohidemode"></a>CDockablePane::IsHideInAutoHideMode  
 Determina o comportamento de um painel que está no modo de ocultar automaticamente, se ele é exibido (ou oculto) chamando [CDockablePane::ShowPane](#showpane).  
  
```  
virtual BOOL IsHideInAutoHideMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável deve ficar oculto quando no modo de ocultar automaticamente; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel acoplável está no modo de ocultar automaticamente, ela tem um comportamento diferente quando você chama `ShowPane` para ocultar ou mostrar o painel. Esse comportamento é controlado pelo membro estático [CDockablePane::m_bHideInAutoHideMode](#m_bhideinautohidemode). Se este membro é `TRUE`, painel encaixável e sua barra de ferramentas de ocultar automaticamente relacionados ou botão Ocultar automaticamente é ocultada ou exibida ao chamar `ShowPane`. Caso contrário, o painel acoplável é ativado ou desativado e sua barra de ferramentas relacionados AutoOcultar ou botão Ocultar automaticamente está sempre visível.  
  
 Substitua esse método em uma classe derivada para alterar o comportamento padrão para painéis individuais.  
  
 O valor padrão para `m_bHideInAutoHideMode` é `FALSE`.  
  
##  <a name="isinfloatingmultipaneframewnd"></a>CDockablePane::IsInFloatingMultiPaneFrameWnd  
 Especifica se o painel estiver em uma janela de quadro de vários painéis ( [CMultiPaneFrameWnd classe](../../mfc/reference/cmultipaneframewnd-class.md)).  
  
```  
virtual BOOL IsInFloatingMultiPaneFrameWnd() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel estiver em uma janela de quadro de vários painéis; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isresizable"></a>CDockablePane::IsResizable  
 Especifica se o painel é redimensionável.  
  
```  
virtual BOOL IsResizable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel estiver redimensionável; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os painéis encaixáveis são redimensionáveis. Para evitar o redimensionamento, substituir esse método em uma classe derivada e retornar `FALSE`. Observe que uma `FALSE` valor leva a uma falha na `ASSERT` na [CPane::DockPane](../../mfc/reference/cpane-class.md#dockpane). Use [CDockingManager::AddPane](../../mfc/reference/cdockingmanager-class.md#addpane) em vez disso, para encaixar um painel dentro de um quadro principal.  
  
 Painéis que não podem ser redimensionadas podem nenhuma flutuação nem entrar no modo de ocultar automaticamente e sempre estão localizados na borda externa do quadro principal.  
  
##  <a name="istablocationbottom"></a>CDockablePane::IsTabLocationBottom  
 Especifica se o guias estão localizadas na parte superior ou inferior do painel.  
  
```  
virtual BOOL IsTabLocationBottom() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o guias estão localizadas na parte inferior do painel. `FALSE` se guias estão localizadas na parte superior do painel.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [CTabbedPane::IsTabLocationBottom](../../mfc/reference/ctabbedpane-class.md#istablocationbottom).  
  
##  <a name="istracked"></a>CDockablePane::IsTracked  
 Especifica se um painel está sendo movido pelo usuário.  
  
```  
BOOL IsTracked() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel estiver sendo movido; Caso contrário, `FALSE`.  
  
##  <a name="isvisible"></a>CDockablePane::IsVisible  
 Determina se o painel atual está visível.  
  
```  
virtual BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel acoplável estiver visível; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para determinar se um painel acoplável está visível. Você pode usar esse método em vez de chamar [CWnd::IsWindowVisible](../../mfc/reference/cwnd-class.md#iswindowvisible) ou testando o `WS_VISIBLE` estilo. O estado de visibilidade retornado depende se o modo de ocultar automaticamente está habilitado ou desabilitado e o valor de [CDockablePane::IsHideInAutoHideMode](#ishideinautohidemode) propriedade.  
  
 Se o painel acoplável estiver no modo de ocultar automaticamente e `IsHideInAutoHideMode` retorna `FALSE` o estado de visibilidade é sempre `FALSE`.  
  
 Se o painel acoplável estiver no modo de ocultar automaticamente e `IsHideInAutoHideMode` retorna `TRUE` o estado de visibilidade depende do estado de visibilidade da barra de ferramentas AutoOcultar relacionados.  
  
 Se o painel encaixável não estiver no modo de ocultar automaticamente, o estado de visibilidade é determinado pelo [CBasePane::IsVisible](../../mfc/reference/cbasepane-class.md#isvisible) método.  
  
##  <a name="m_bdisableanimation"></a>CDockablePane::m_bDisableAnimation  
 Especifica se a animação de ocultar automaticamente do painel acoplável está desabilitada.  
  
```  
AFX_IMPORT_DATA static BOOL m_bDisableAnimation;  
```  
  
##  <a name="m_bhideinautohidemode"></a>CDockablePane::m_bHideInAutoHideMode  
 Determina o comportamento do painel quando o painel está no modo de ocultar automaticamente.  
  
```  
AFX_IMPORT_DATA static BOOL m_bHideInAutoHideMode;  
```  
  
### <a name="remarks"></a>Comentários  
 Esse valor afeta todos os painéis de encaixe no aplicativo.  
  
 Se você definir esse membro como `TRUE`, painéis encaixáveis ocultas ou mostradas com seus botões e barras de ferramentas AutoOcultar relacionados ao chamar [CDockablePane::ShowPane](#showpane).  
  
 Se você definir esse membro como `FALSE`, painéis encaixáveis estão ativadas ou desativadas quando você chama [CDockablePane::ShowPane](#showpane).  
  
##  <a name="m_nslidesteps"></a>CDockablePane::m_nSlideSteps  
 Especifica a velocidade da animação do painel quando ele estiver no modo de ocultar automaticamente.  
  
```  
AFX_IMPORT_DATA static int m_nSlideSteps;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter um efeito de animação mais rápido, diminua esse valor. Para obter um efeito de animação mais lento, aumente esse valor.  
  
##  <a name="onafterchangeparent"></a>CDockablePane::OnAfterChangeParent  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnAfterChangeParent(CWnd* pWndOldParent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndOldParent`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onafterdockfromminiframe"></a>CDockablePane::OnAfterDockFromMiniFrame  
 Chamado pela estrutura quando uma barra de encaixe flutuante se encaixa em uma janela do quadro.  
  
```  
virtual void OnAfterDockFromMiniFrame();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada.  
  
##  <a name="onbeforechangeparent"></a>CDockablePane::OnBeforeChangeParent  
 O framework chama esse método antes de alterar o pai do painel.  
  
```  
virtual void OnBeforeChangeParent(
    CWnd* pWndNewParent,  
    BOOL bDelay = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndNewParent`  
 Um ponteiro para a nova janela pai.  
  
 [in] `bDelay`  
 `BOOL`que especifica se deve atrasar o recálculo do layout do encaixe se o painel estiver desencaixado. Para obter mais informações, consulte [CDockablePane::UndockPane](#undockpane).  
  
### <a name="remarks"></a>Comentários  
 Se o painel estiver encaixado e o novo pai não permitir encaixe, esse método desencaixa o painel.  
  
 Se o painel está sendo convertido em um documento com guias, este método armazena a posição de encaixe recente. A estrutura usa a posição de encaixe recente para restaurar a posição do painel quando ele é convertido para um estado encaixado.  
  
##  <a name="onbeforefloat"></a>CDockablePane::OnBeforeFloat  
 A estrutura chama esse método antes de um painel faz a transição para o estado flutuante.  
  
```  
virtual BOOL OnBeforeFloat(
    CRect& rectFloat,  
    AFX_DOCK_METHOD dockMethod);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectFloat`  
 Especifica a posição e o tamanho do painel quando está no estado flutuante.  
  
 [in] `dockMethod`  
 Especifica o método de encaixe. Consulte [CPane::DockPane](../../mfc/reference/cpane-class.md#dockpane) para obter uma lista de valores possíveis.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel pode ser flutuante; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado pela estrutura quando um painel está prestes a float. Você pode substituir esse método em uma classe derivada se você quiser executar qualquer processamento antes que o painel flutua.  
  
##  <a name="onpressbuttons"></a>CDockablePane::OnPressButtons  
 Chamado quando o usuário pressionar um botão legenda que o `AFX_HTCLOSE` e `AFX_HTMAXBUTTON` botões.  
  
```  
virtual void OnPressButtons(UINT nHit);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nHit`  
 Este parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
 Se você adicionar um botão personalizado para a legenda de um painel acoplável, substitui esse método para receber notificações quando um usuário pressiona o botão.  
  
##  <a name="onslide"></a>CDockablePane::OnSlide  
 Chamado pela estrutura para animar o painel quando ele estiver no modo de ocultar automaticamente.  
  
```  
virtual void OnSlide(BOOL bSlideOut);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSlideOut`  
 `TRUE`para mostrar o painel; `FALSE` para ocultar o painel.  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada implementar efeitos AutoOcultar personalizado.  
  
##  <a name="removefromdefaultpanedividier"></a>CDockablePane::RemoveFromDefaultPaneDividier  
 O framework chama esse método quando um painel está sendo desencaixado.  
  
```  
void RemoveFromDefaultPaneDividier();
```  
  
### <a name="remarks"></a>Comentários  
 Este método define o divisor de painéis padrão `NULL` e remove o painel do seu contêiner.  
  
##  <a name="replacepane"></a>CDockablePane::ReplacePane  
 Substitui o painel com um painel especificado.  
  
```  
BOOL ReplacePane(
    CDockablePane* pBarToReplaceWith,  
    AFX_DOCK_METHOD dockMethod,  
    BOOL bRegisterWithFrame = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pBarToReplaceWith`  
 Um ponteiro para um painel acoplável.  
  
 [in] `dockMethod`  
 Não usado.  
  
 [in] `bRegisterWithFrame`  
 Se `TRUE`, o novo painel está registrado com o Gerenciador de encaixe do pai do painel antigo. O novo painel é inserido no índice do painel anterior na lista de painéis que é mantida pelo Gerenciador de encaixe.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a substituição for bem-sucedida; Caso contrário, `FALSE`.  
  
##  <a name="restoredefaultpanedivider"></a>CDockablePane::RestoreDefaultPaneDivider  
 Quando um painel é desserializado, o framework chama esse método para restaurar o divisor de painel padrão.  
  
```  
void RestoreDefaultPaneDivider();
```  
  
### <a name="remarks"></a>Comentários  
 O divisor de painéis padrão restaurada substitui o divisor de painéis padrão atual, se ele existir.  
  
##  <a name="setautohidemode"></a>CDockablePane::SetAutoHideMode  
 Alterna o painel de encaixe entre visível e o modo de ocultar automaticamente.  
  
```  
virtual CMFCAutoHideBar* SetAutoHideMode(
    BOOL bMode,  
    DWORD dwAlignment,  
    CMFCAutoHideBar* pCurrAutoHideBar = NULL,  
    BOOL bUseTimer = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMode`  
 `TRUE`Para habilitar o modo de ocultar automaticamente; `FALSE` para habilitar o modo de encaixe regular.  
  
 [in] `dwAlignment`  
 Especifica o alinhamento do painel de ocultar automaticamente para criar.  
  
 [in] [out]`pCurrAutoHideBar`  
 Um ponteiro para a barra de ferramentas de ocultar automaticamente atual. Pode ser `NULL`.  
  
 [in] `bUseTimer`  
 Especifica se deseja usar o efeito de ocultar automaticamente quando o usuário alterna o painel para o modo de ocultar automaticamente ou ocultar o painel imediatamente.  
  
### <a name="return-value"></a>Valor de retorno  
 Ocultar automaticamente barra de ferramentas que foi criada como resultado de alternar para o modo de ocultar automaticamente, ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método quando um usuário clica no botão de pin para alternar o painel acoplável para o modo de ocultar automaticamente ou para o modo normal de encaixe.  
  
 Chame esse método para alternar programaticamente um painel acoplável para o modo de ocultar automaticamente. O painel deve ser encaixado à janela principal do quadro ( [CDockablePane::GetDefaultPaneDivider](#getdefaultpanedivider) deve retornar um ponteiro válido para o [CPaneDivider](../../mfc/reference/cpanedivider-class.md)).  
  
##  <a name="setautohideparents"></a>CDockablePane::SetAutoHideParents  
 Define o botão Ocultar automaticamente e ocultar automaticamente a barra de ferramentas do painel.  
  
```  
void SetAutoHideParents(
    CMFCAutoHideBar* pToolBar,  
    CMFCAutoHideButton* pBtn);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pToolBar`  
 Ponteiro para uma barra de ferramentas de ocultar automaticamente.  
  
 [in] `pBtn`  
 Ponteiro para um botão de ocultar automaticamente.  
  
##  <a name="setlastpercentinpanecontainer"></a>CDockablePane::SetLastPercentInPaneContainer  
 Define a porcentagem de espaço que ocupa um painel em seu contêiner.  
  
```  
void SetLastPercentInPaneContainer(int n);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `n`  
 Um `int` que especifica a porcentagem de espaço que o painel ocupa em seu contêiner.  
  
### <a name="remarks"></a>Comentários  
 O framework ajusta o painel para usar o novo valor quando o layout é recalculado.  
  
##  <a name="setrestoreddefaultpanedivider"></a>CDockablePane::SetRestoredDefaultPaneDivider  
 Define o divisor de painel padrão restaurada.  
  
```  
void SetRestoredDefaultPaneDivider(HWND hRestoredSlider);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hRestoredSlider`  
 Um identificador para um divisor de painel (controle deslizante).  
  
### <a name="remarks"></a>Comentários  
 Um divisor de painel padrão restaurada é obtido quando um painel é desserializado. Para obter mais informações, consulte [CDockablePane::RestoreDefaultPaneDivider](#restoredefaultpanedivider).  
  
##  <a name="settabbedpanertc"></a>CDockablePane::SetTabbedPaneRTC  
 Define as informações de classe de tempo de execução para uma janela com guias que é criada quando dois painéis encaixe juntos.  
  
```  
void SetTabbedPaneRTC(CRuntimeClass* pRTC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pRTC`  
 As informações de classe de tempo de execução para o painel com guias.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para definir as informações de classe de tempo de execução para painéis com guias que são criados dinamicamente. Isso pode ocorrer quando um usuário arrasta um painel para a legenda do outro painel, ou se você chamar o [CDockablePane::AttachToTabWnd](#attachtotabwnd) método para criar programaticamente um painel com guias de dois painéis encaixáveis.  
  
 A classe de tempo de execução padrão é definida de acordo com o `dwTabbedStyle` parâmetro do [CDockablePane::Create](#create) e [CDockablePane::CreateEx](#createex). Para personalizar os novos painéis com guias, derive a classe de uma das seguintes classes:  
  
- [Classe CBaseTabbedPane](../../mfc/reference/cbasetabbedpane-class.md)  
  
- [Classe CTabbedPane](../../mfc/reference/ctabbedpane-class.md)  
  
- [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md).  
  
 Em seguida, chame esse método com o ponteiro para suas informações de classe de tempo de execução.  
  
##  <a name="showpane"></a>CDockablePane::ShowPane  
 Mostra ou oculta um painel.  
  
```  
virtual void ShowPane(
    BOOL bShow,  
    BOOL bDelay,  
    BOOL bActivate);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 `TRUE`para mostrar o painel; `FALSE` para ocultar o painel.  
  
 [in] `bDelay`  
 `TRUE`Para atrasar a ajustar o layout de encaixe; `FALSE` para ajustar o layout de encaixe imediatamente.  
  
 [in] `bActivate`  
 `TRUE`Para ativar o painel quando exibido; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chamar esse método em vez do [CWnd::ShowWindow](../../mfc/reference/cwnd-class.md#showwindow) quando mostrando ou ocultando painéis encaixáveis.  
  
##  <a name="slide"></a>CDockablePane::Slide  
 Anima um painel que está no modo de ocultar automaticamente.  
  
```  
virtual void Slide(
    BOOL bSlideOut,  
    BOOL bUseTimer = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSlideOut`  
 `TRUE`para mostrar o painel; `FALSE` para ocultar o painel.  
  
 [in] `bUseTimer`  
 `TRUE`para mostrar ou ocultar o painel com o efeito de ocultar automaticamente; `FALSE` para mostrar ou ocultar o painel imediatamente.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para animar um painel que está no modo de ocultar automaticamente.  
  
 Esse método usa o `CDockablePane::m_nSlideDefaultTimeOut` valor para determinar o tempo limite para o efeito de slide. O valor padrão para o tempo limite é 1. Se você personalizar o algoritmo de ocultar automaticamente, modifique esse membro para alterar o tempo limite.  
  
##  <a name="toggleautohide"></a>CDockablePane::ToggleAutoHide  
 Alterna o painel entre sempre visível e o modo de ocultar automaticamente.  
  
```  
virtual void ToggleAutoHide();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método alterna o modo de ocultar automaticamente para o painel chamando [CDockablePane::SetAutoHideMode](#setautohidemode).  
  
##  <a name="undockpane"></a>CDockablePane::UndockPane  
 Desencaixa um painel da janela principal do quadro ou um contêiner de janela miniframe.  
  
```  
virtual void UndockPane(BOOL bDelay = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDelay`  
 `TRUE`Para atrasar a calcular o layout de encaixe; `FALSE` para recalcular o layout de encaixe imediatamente.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para desencaixar um painel da janela de quadro principal ou de um contêiner de janela de múltiplas miniframe (um painel flutuante em uma janela única miniframe com outros painéis).  
  
 Você deve desencaixar um painel antes de executar qualquer operação externa que não é executada pelo [CDockingManager](../../mfc/reference/cdockingmanager-class.md). Por exemplo, você deverá desencaixar um painel para movê-lo programaticamente de um local para outro.  
  
 O framework desencaixa automaticamente painéis antes que eles são destruídos.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPane](../../mfc/reference/cpane-class.md)

