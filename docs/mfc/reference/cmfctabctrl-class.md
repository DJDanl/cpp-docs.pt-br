---
title: Classe CMFCTabCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCTabCtrl
dev_langs:
- C++
helpviewer_keywords:
- CMFCTabCtrl::SwapTabs method
- CMFCTabCtrl constructor
- CMFCTabCtrl::MoveTab method
- CMFCTabCtrl::GetTabFromPoint method
- CMFCTabCtrl::PreTranslateMessage method
- CMFCTabCtrl::RecalcLayout method
- CMFCTabCtrl class
- CMFCTabCtrl::IsPtInTabArea method
ms.assetid: d441385d-2c72-4203-96fa-deae2273da35
caps.latest.revision: 33
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
ms.openlocfilehash: 595ff7fbcd55f3b756ce650e02b6247b898d7629
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctabctrl-class"></a>Classe CMFCTabCtrl
O `CMFCTabCtrl` classe fornece funcionalidade para um controle guia. O controle de guia exibe uma janela encaixável com guias de planas ou tridimensionais na sua parte superior ou inferior. As guias podem exibir texto e uma imagem e podem alterar a cor quando ativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCTabCtrl : public CMFCBaseTabCtrl  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCTabCtrl::CMFCTabCtrl`|Construtor padrão.|  
|`CMFCTabCtrl::~CMFCTabCtrl`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTabCtrl::ActivateMDITab](#activatemditab)|Exibe a guia especificada do controle de guia atual e define o foco nessa guia.|  
|[CMFCTabCtrl::AllowDestroyEmptyTabbedPane](#allowdestroyemptytabbedpane)||  
|[CMFCTabCtrl::AutoSizeWindow](#autosizewindow)|Especifica se a estrutura redimensionar a área cliente de todas as janelas de controle de guia quando um elemento de interface do usuário das alterações de controle de guia.|  
|[CMFCTabCtrl::CalcRectEdit](#calcrectedit)|Esvazia o tamanho da área da guia especificado. (Substitui `CMFCBaseTabCtrl::CalcRectEdit`.)|  
|[CMFCTabCtrl::Create](#create)|Cria o controle de guia e anexa-o para o `CMFCTabCtrl` objeto.|  
|`CMFCTabCtrl::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCTabCtrl::EnableActiveTabCloseButton](#enableactivetabclosebutton)|Mostra ou oculta o botão Fechar ( **X**) na guia ativa.|  
|[CMFCTabCtrl::EnableInPlaceEdit](#enableinplaceedit)|Habilita ou desabilita os rótulos da guia editável. (Substitui [CMFCBaseTabCtrl::EnableInPlaceEdit](../../mfc/reference/cmfcbasetabctrl-class.md#enableinplaceedit).)|  
|[CMFCTabCtrl::EnableTabDocumentsMenu](#enabletabdocumentsmenu)|Substitui os dois botões que percorrer as guias da janela com um botão que abre um menu de janelas com guias.|  
|[CMFCTabCtrl::EnsureVisible](#ensurevisible)|Garante que uma guia está visível.|  
|[CMFCTabCtrl::GetDocumentIcon](#getdocumenticon)|Recupera o símbolo associado uma guia em um menu pop-up de janelas com guias.|  
|[CMFCTabCtrl::GetFirstVisibleTabNum](#getfirstvisibletabnum)|Recupera o índice da primeira guia visível no controle guia atual.|  
|[CMFCTabCtrl::GetResizeMode](#getresizemode)|Recupera um valor que especifica como o controle de guia atual pode ser redimensionado.|  
|[CMFCTabCtrl::GetScrollBar](#getscrollbar)|Recupera um ponteiro para o objeto de barra de rolagem que está associado com o controle de guia.|  
|[CMFCTabCtrl::GetTabArea](#gettabarea)|Recupera o retângulo delimitador de área de rótulo de guias na parte superior ou inferior do controle guia. (Substitui [CMFCBaseTabCtrl::GetTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#gettabarea).)|  
|`CMFCTabCtrl::GetTabFromPoint`|Recupera a guia que contém um ponto específico. (Substitui [CMFCBaseTabCtrl::GetTabFromPoint](../../mfc/reference/cmfcbasetabctrl-class.md#gettabfrompoint).)|  
|[CMFCTabCtrl::GetTabMaxWidth](#gettabmaxwidth)|Recupera a largura máxima de uma guia.|  
|[CMFCTabCtrl::GetTabsHeight](#gettabsheight)|Recupera a altura da área de guias do controle guia atual.|  
|[CMFCTabCtrl::GetTabsRect](#gettabsrect)|Recupera um retângulo que circunda a área da guia do controle de guia atual. (Substitui [CMFCBaseTabCtrl::GetTabsRect](../../mfc/reference/cmfcbasetabctrl-class.md#gettabsrect).)|  
|`CMFCTabCtrl::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCTabCtrl::GetWndArea](#getwndarea)|Recupera o limite da área do cliente do controle de guia atual.|  
|[CMFCTabCtrl::HideActiveWindowHorzScrollBar](#hideactivewindowhorzscrollbar)|Oculta a barra de rolagem horizontal, se houver, da janela ativa.|  
|[CMFCTabCtrl::HideInactiveWindow](#hideinactivewindow)|Especifica se a estrutura é exibir janelas de controle de guia inativo.|  
|[CMFCTabCtrl::HideNoTabs](#hidenotabs)|Habilita ou desabilita a área da guia de desenho se não houver nenhum guias visíveis.|  
|[CMFCTabCtrl::HideSingleTab](#hidesingletab)|Habilita ou desabilita uma guia de desenho quando há uma única janela com guias. (Substitui [CMFCBaseTabCtrl::HideSingleTab](../../mfc/reference/cmfcbasetabctrl-class.md#hidesingletab).)|  
|[CMFCTabCtrl::IsActiveInMDITabGroup](#isactiveinmditabgroup)|Indica se a guia atual de um controle guia é a guia ativa em um grupo de guias de interface documentos múltiplos.|  
|[CMFCTabCtrl::IsActiveTabBoldFont](#isactivetabboldfont)|Indica se o texto da guia ativa é exibido utilizando uma fonte em negrito.|  
|[CMFCTabCtrl::IsActiveTabCloseButton](#isactivetabclosebutton)|Indica se o botão Fechar ( **X**) é exibido no canto superior direito da área da guia ou de uma guia ativa.|  
|[CMFCTabCtrl::IsDrawFrame](#isdrawframe)|Indica se a janela com guias desenha um retângulo de quadro em torno de painéis incorporados.|  
|[CMFCTabCtrl::IsFlatFrame](#isflatframe)|Indica se o quadro ao redor da área de guia é plana ou 3D.|  
|[CMFCTabCtrl::IsFlatTab](#isflattab)|Indica se a aparência das guias no controle guia atual é simples ou não.|  
|[CMFCTabCtrl::IsLeftRightRounded](#isleftrightrounded)|Indica se a aparência da esquerda e direita de uma guia no controle guia atual é arredondada.|  
|[CMFCTabCtrl::IsMDITabGroup](#ismditabgroup)|Indica se o controle de guia atual está contido na área do cliente de uma janela de interface de documentos múltiplos.|  
|[CMFCTabCtrl::IsOneNoteStyle](#isonenotestyle)|Indica se o controle de guia atual é exibido no estilo do Microsoft OneNote.|  
|`CMFCTabCtrl::IsPtInTabArea`|Determina se um ponto está dentro da área de guia. (Substitui [CMFCBaseTabCtrl::IsPtInTabArea](../../mfc/reference/cmfcbasetabctrl-class.md#isptintabarea).)|  
|[CMFCTabCtrl::IsSharedScroll](#issharedscroll)|Indica se o controle de guia atual tem uma barra de rolagem que pode rolar suas guias como um grupo.|  
|[CMFCTabCtrl::IsTabDocumentsMenu](#istabdocumentsmenu)|Indica se o controle de guia exibe botões de rolagem ou um botão que exibe um menu de janelas com guias.|  
|[CMFCTabCtrl::IsVS2005Style](#isvs2005style)|Indica se as guias são exibidas no estilo do Visual Studio .NET 2005.|  
|[CMFCTabCtrl::ModifyTabStyle](#modifytabstyle)|Especifica a aparência das guias no controle guia atual.|  
|`CMFCTabCtrl::MoveTab`|Move uma guia para outra posição da guia. (Substitui [CMFCBaseTabCtrl::MoveTab](../../mfc/reference/cmfcbasetabctrl-class.md#movetab).)|  
|[CMFCTabCtrl::OnDragEnter](#ondragenter)|Chamado pela estrutura quando o cursor é arrastado primeiro para a janela de controle de guia.|  
|[CMFCTabCtrl::OnDragOver](#ondragover)|Chamado pela estrutura durante uma operação de arrastar quando o mouse é movido sobre a janela de destino de soltar. (Substitui [CMFCBaseTabCtrl::OnDragOver](../../mfc/reference/cmfcbasetabctrl-class.md#ondragover).)|  
|[CMFCTabCtrl::OnShowTabDocumentsMenu](#onshowtabdocumentsmenu)|Exibe um menu pop-up de janelas com guias, aguarda até que o usuário seleciona uma guia e torna a guia selecionada na guia ativa.|  
|`CMFCTabCtrl::PreTranslateMessage`|Converte as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CMFCBaseTabCtrl::PreTranslateMessage](../../mfc/reference/cmfcbasetabctrl-class.md#pretranslatemessage).)|  
|`CMFCTabCtrl::RecalcLayout`|Recalcula o layout interno do controle guia. (Substitui [CMFCBaseTabCtrl::RecalcLayout](../../mfc/reference/cmfcbasetabctrl-class.md#recalclayout).)|  
|[CMFCTabCtrl::SetActiveInMDITabGroup](#setactiveinmditabgroup)|Define a guia atual de um controle guia como a guia ativa em um grupo de guias de interface documentos múltiplos.|  
|[CMFCTabCtrl::SetActiveTab](#setactivetab)|Ativa uma guia. (Substitui [CMFCBaseTabCtrl::SetActiveTab](../../mfc/reference/cmfcbasetabctrl-class.md#setactivetab).)|  
|[CMFCTabCtrl::SetActiveTabBoldFont](#setactivetabboldfont)|Habilita ou desabilita o uso de uma fonte em negrito nas guias ativos.|  
|[CMFCTabCtrl::SetDrawFrame](#setdrawframe)|Habilita ou desabilita o retângulo de quadro drawinga em torno de uma barra incorporado.|  
|[CMFCTabCtrl::SetFlatFrame](#setflatframe)|Especifica se deve desenhar um plano ou um quadro 3D ao redor da área da guia.|  
|[CMFCTabCtrl::SetImageList](#setimagelist)|Especifica uma lista de imagens. (Substitui [CMFCBaseTabCtrl::SetImageList](../../mfc/reference/cmfcbasetabctrl-class.md#setimagelist).)|  
|[CMFCTabCtrl::SetResizeMode](#setresizemode)|Especifica como o controle de guia atual pode ser redimensionado e, em seguida, exibe novamente o controle.|  
|[CMFCTabCtrl::SetTabMaxWidth](#settabmaxwidth)|Especifica a largura da guia máximo em uma janela com guias.|  
|[CMFCTabCtrl::StopResize](#stopresize)|Termina a operação de redimensionamento atual no controle guia.|  
|`CMFCTabCtrl::SwapTabs`|Alterna um par de guias. (Substitui [CMFCBaseTabCtrl::SwapTabs](../../mfc/reference/cmfcbasetabctrl-class.md#swaptabs).)|  
|[CMFCTabCtrl::SynchronizeScrollBar](#synchronizescrollbar)|Desenha uma barra de rolagem horizontal em um controle guia que exibe as guias de planos.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCTabCtrl::m_bEnableActivate](#m_benableactivate)|Impede que o modo ativo perde o foco quando uma nova guia é inserida e habilitada.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCTabCtrl` suporta:  
  
-   Guia estilos de controle que incluem 3D, simples e simples com uma barra de rolagem horizontal compartilhado.  
  
-   Guias localizadas na parte superior ou inferior da janela.  
  
-   Guias que exibem texto, imagens, ou texto e imagens.  
  
-   Guias que alteram a cor quando a guia estiver ativa.  
  
-   Alterações de tamanho de borda de guias ajustáveis.  
  
-   Janelas com guias destacáveis.  
  
 O `CMFCTabCtrl` classe pode ser usada com uma caixa de diálogo, mas é destinado para aplicativos que usam o encaixe controlam barras como [!INCLUDE[ofprexcel](../../mfc/reference/includes/ofprexcel_md.md)] e [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)]. Para obter mais informações, consulte [CDockablePane classe](../../mfc/reference/cdockablepane-class.md).  
  
 Siga estas etapas para adicionar um redimensionáveis, encaixe o controle de guia no seu aplicativo:  
  
1.  Criar uma instância de [CTabbedPane classe](../../mfc/reference/ctabbedpane-class.md).  
  
2.  Chamar [CDockablePane::Create](../../mfc/reference/cdockablepane-class.md#create).  
  
3.  Use [CBaseTabbedPane::AddTab](../../mfc/reference/cbasetabbedpane-class.md#addtab) ou [CMFCBaseTabCtrl::InsertTab](../../mfc/reference/cmfcbasetabctrl-class.md#inserttab) para adicionar novas guias.  
  
4.  Chamar [CBasePane::EnableDocking](../../mfc/reference/cbasepane-class.md#enabledocking) para que o controle de guia de encaixe atual pode encaixar a janela do quadro principal.  
  
5.  Chamar [CFrameWndEx::DockPane](../../mfc/reference/cframewndex-class.md#dockpane) para encaixar a janela com guias no quadro principal.  
  
 Para obter um exemplo de como criar uma janela com guias como uma barra de controle de encaixe, consulte [CTabbedPane classe](../../mfc/reference/ctabbedpane-class.md). Usar `CMFCTabCtrl` como um controle não integrada, crie um `CMFCTabCtrl` do objeto e, em seguida, chame [CMFCTabCtrl::Create](#create).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)  
  
 [CMFCTabCtrl](../../mfc/reference/cmfctabctrl-class.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCTabCtrl` classe para configurar um `CMFCTabCtrl` objeto. O exemplo explica como adicionar uma guia, mostrar o botão Fechar na guia ativa, ativar rótulos de guia editável e exibir um menu pop-up de rótulos de janela com guias. Este exemplo é parte do [amostra de coleta de estado](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StateCollection n º&1;](../../mfc/reference/codesnippet/cpp/cmfctabctrl-class_1.h)]  
[!code-cpp[NVC_MFC_StateCollection n º&3;](../../mfc/reference/codesnippet/cpp/cmfctabctrl-class_2.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtabctrl.h  
  
##  <a name="a-nameactivatemditaba--cmfctabctrlactivatemditab"></a><a name="activatemditab"></a>CMFCTabCtrl::ActivateMDITab  
 Exibe a guia especificada do controle de guia atual e define o foco nessa guia.  
  
```  
void ActivateMDITab(int nTab = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTab`  
 O índice com base em zero de uma guia para exibir ou -1 para especificar a guia ativa no momento.  
  
##  <a name="a-nameallowdestroyemptytabbedpanea--cmfctabctrlallowdestroyemptytabbedpane"></a><a name="allowdestroyemptytabbedpane"></a>CMFCTabCtrl::AllowDestroyEmptyTabbedPane  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL AllowDestroyEmptyTabbedPane() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameautosizewindowa--cmfctabctrlautosizewindow"></a><a name="autosizewindow"></a>CMFCTabCtrl::AutoSizeWindow  
 Especifica se a estrutura redimensionar a área cliente de todas as janelas de controle de guia quando um elemento de interface do usuário das alterações de controle de guia.  
  
```  
void AutoSizeWindow(BOOL bAutoSize = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAutoSize`  
 `TRUE`Para redimensionar automaticamente o windows de controle de guia. Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreatea--cmfctabctrlcreate"></a><a name="create"></a>CMFCTabCtrl::Create  
 Cria o controle de guia e anexa-o para o `CMFCTabCtrl` objeto.  
  
```  
BOOL Create(
    Style style,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID,  
    Location location=LOCATION_BOTTOM,  
    BOOL bCloseBtn=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `style`  
 O estilo do controle guia. Para obter mais informações, consulte Comentários.  
  
 [in] `rect`  
 Um retângulo que circunda o controle guia.  
  
 [in] `pParentWnd`  
 Um ponteiro para uma janela pai. Não deve ser `NULL`.  
  
 [in] `nID`  
 A ID do controle guia.  
  
 [in] `location`  
 O local das guias. O valor padrão é `LOCATION_BOTTOM`. Para obter mais informações, consulte Comentários.  
  
 [in] `bCloseBtn`  
 `TRUE`Para exibir um botão Fechar na guia. Caso contrário, `FALSE`. O valor padrão é `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir descreve os valores que você pode especificar para o `style` parâmetro.  
  
|Estilo|Descrição|  
|-----------|-----------------|  
|STYLE_3D|Cria um controle guia com uma aparência tridimensional.|  
|STYLE_FLAT|Cria um controle guia com guias de planos.|  
|STYLE_FLAT_SHARED_HORZ_SCROLL|Cria um controle guia com guias simples e uma barra de rolagem que pode rolar as guias se eles são cortados por uma janela pai.|  
|STYLE_3D_ONENOTE|Cria um controle de guia no estilo do Microsoft OneNote.|  
|STYLE_3D_VS2005|Cria um controle de guia no estilo do Microsoft Visual Studio 2005.|  
|STYLE_3D_ROUNDED|Cria um controle guia com cantos arredondados guias no estilo do Microsoft Visual Studio 2005.|  
|STYLE_3D_ROUNDED_SCROLL|Cria um controle guia com cantos arredondados guias e botões de rolagem no estilo do Microsoft Visual Studio 2005.|  
  
 A tabela a seguir lista os valores que você pode especificar para o `location` parâmetro.  
  
|Local|Descrição|  
|--------------|-----------------|  
|LOCATION_BOTTOM|Guias estão localizadas na parte inferior do controle guia.|  
|LOCATION_TOP|Guias estão localizadas na parte superior do controle guia.|  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CMFCTabCtrl` classe. Este exemplo é parte do [amostra de coleta de estado](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_StateCollection n º&1;](../../mfc/reference/codesnippet/cpp/cmfctabctrl-class_1.h)]  
[!code-cpp[NVC_MFC_StateCollection n º&2;](../../mfc/reference/codesnippet/cpp/cmfctabctrl-class_3.cpp)]  
  
##  <a name="a-namecalcrectedita--cmfctabctrlcalcrectedit"></a><a name="calcrectedit"></a>CMFCTabCtrl::CalcRectEdit  
 Esvazia o tamanho da área da guia especificado.  
  
```  
virtual void CalcRectEdit(CRect& rectEdit);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `rectEdit`  
 Um retângulo que especifica a área de uma guia.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado quando você alterar o rótulo de uma guia. Esse método esvazia os lados esquerdo e direito do retângulo especificado pela metade a altura da guia atual e esvazia a parte superior e inferior em uma unidade.  
  
##  <a name="a-nameenableactivetabclosebuttona--cmfctabctrlenableactivetabclosebutton"></a><a name="enableactivetabclosebutton"></a>CMFCTabCtrl::EnableActiveTabCloseButton  
 Mostra ou oculta o botão Fechar ( **X**) na guia ativa.  
  
```  
void EnableActiveTabCloseButton(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para exibir o botão Fechar na guia ativa. `FALSE` para exibir o botão Fechar no canto superior direito da área da guia. O valor padrão é `TRUE`.  
  
##  <a name="a-nameenableinplaceedita--cmfctabctrlenableinplaceedit"></a><a name="enableinplaceedit"></a>CMFCTabCtrl::EnableInPlaceEdit  
 Habilita ou desabilita os rótulos da guia editável.  
  
```  
virtual void EnableInPlaceEdit(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para ativar rótulos de guia editável; `FALSE` desativar rótulos guia editável.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenabletabdocumentsmenua--cmfctabctrlenabletabdocumentsmenu"></a><a name="enabletabdocumentsmenu"></a>CMFCTabCtrl::EnableTabDocumentsMenu  
 Alterna entre uma interface do usuário que usa dois botões para percorrer as guias da janela e uma interface que exibe um menu pop-up de janelas com guias.  
  
```  
void EnableTabDocumentsMenu(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para exibir um menu pop-up de rótulos de janela com guias; `FALSE` para exibir os botões de rolagem para frente e para trás. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica em uma etiqueta de guia, o framework exibe a janela com guias correspondente. Se o rótulo da guia estiver visível, a janela com guias será aberta sem alterar sua posição. Se o usuário seleciona um documento no menu pop-up e a janela com guias correspondente está fora da tela, a janela com guias torna-se a primeira guia.  
  
##  <a name="a-nameensurevisiblea--cmfctabctrlensurevisible"></a><a name="ensurevisible"></a>CMFCTabCtrl::EnsureVisible  
 Garante que uma guia está visível.  
  
```  
virtual BOOL EnsureVisible(int iTab);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iTab`  
 O índice com base em zero de uma guia.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se for bem-sucedida; `FALSE` se o `iTab` índice de parâmetro é inválido.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para garantir que a guia especificada está visível. O controle de guia rolará se for necessário.  
  
##  <a name="a-namegetdocumenticona--cmfctabctrlgetdocumenticon"></a><a name="getdocumenticon"></a>CMFCTabCtrl::GetDocumentIcon  
 Recupera a imagem que está associada uma guia em um menu pop-up de janelas com guias.  
  
```  
static HICON __stdcall GetDocumentIcon(UINT nCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nCmdID`  
 A ID de comando de uma guia em um menu pop-up de janelas com guias.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de uma imagem de bitmap.  
  
##  <a name="a-namegetfirstvisibletabnuma--cmfctabctrlgetfirstvisibletabnum"></a><a name="getfirstvisibletabnum"></a>CMFCTabCtrl::GetFirstVisibleTabNum  
 Recupera o índice da primeira guia visível no controle guia atual.  
  
```  
virtual int GetFirstVisibleTabNum() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O índice com base em zero de uma guia no controle guia.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente quando o controle de guia é exibido no estilo do Microsoft OneNote. Use o [CMFCTabCtrl::IsOneNoteStyle](#isonenotestyle) método para determinar o estilo.  
  
##  <a name="a-namegetresizemodea--cmfctabctrlgetresizemode"></a><a name="getresizemode"></a>CMFCTabCtrl::GetResizeMode  
 Recupera um valor que especifica como o controle de guia atual pode ser redimensionado.  
  
```  
ResizeMode GetResizeMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um do `CMFCTabCtrl::ResizeMode` valores de enumeração que especifica como o controle de guia pode ser redimensionado. Para obter uma lista dos valores possíveis, consulte a seção comentários a [CMFCTabCtrl::SetResizeMode](#setresizemode) método.  
  
##  <a name="a-namegetscrollbara--cmfctabctrlgetscrollbar"></a><a name="getscrollbar"></a>CMFCTabCtrl::GetScrollBar  
 Recupera um ponteiro para o objeto de barra de rolagem que está associado com o controle de guia.  
  
```  
CScrollBar* GetScrollBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto de barra de rolagem, ou `NULL` se o controle de tabulação não foi criado usando o `STYLE_FLAT_SHARED_HORZ_SCROLL` estilo.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para acessar a barra de rolagem incorporado do controle guia. Um objeto de barra de rolagem é criado somente quando o controle guia tem o `STYLE_FLAT_SHARED_HORZ_SCROLL` estilo.  
  
##  <a name="a-namegettabareaa--cmfctabctrlgettabarea"></a><a name="gettabarea"></a>CMFCTabCtrl::GetTabArea  
 Recupera o retângulo delimitador de área de rótulo de guias na parte superior ou inferior do controle guia.  
  
```  
void GetTabArea(
    CRect& rectTabAreaTop,  
    CRect& rectTabAreaBottom) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rectTabAreaTop`  
 Quando este método retorna, esta referência contém um retângulo que circunda a área de rótulo da guia superior. O retângulo é nas coordenadas do cliente. Essa referência é vazia não se existir nenhuma área de rótulo da guia na parte superior do controle guia.  
  
 [out] `rectTabAreaBottom`  
 Quando este método retorna, esta referência contém um retângulo que circunda a área rótulo da guia inferior. O retângulo é nas coordenadas do cliente. Essa referência é vazia não se existir nenhuma área de rótulo da guia na parte inferior do controle guia.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para determinar o tamanho e a posição da área da guia na janela com guias.  
  
##  <a name="a-namegettabmaxwidtha--cmfctabctrlgettabmaxwidth"></a><a name="gettabmaxwidth"></a>CMFCTabCtrl::GetTabMaxWidth  
 Recupera a largura máxima de uma guia.  
  
```  
int GetTabMaxWidth() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Largura máxima de uma guia, em pixels. Se o valor de retorno for 0, a largura da guia é ilimitada.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCTabCtrl::SetTabMaxWidth](#settabmaxwidth) método para definir a largura máxima de guia.  
  
##  <a name="a-namegettabsheighta--cmfctabctrlgettabsheight"></a><a name="gettabsheight"></a>CMFCTabCtrl::GetTabsHeight  
 Recupera a altura da área de guias do controle guia atual.  
  
```  
virtual int GetTabsHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura da área da guia se qualquer guia estiver visível, ou zero se a guia não estiver visível.  
  
##  <a name="a-namegettabsrecta--cmfctabctrlgettabsrect"></a><a name="gettabsrect"></a>CMFCTabCtrl::GetTabsRect  
 Recupera um retângulo que circunda a área da guia do controle de guia atual.  
  
```  
virtual void GetTabsRect(CRect& rect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rect`  
 Quando este método retorna, o `rect` parâmetro contém um retângulo que circunda a área da guia.  
  
##  <a name="a-namegetwndareaa--cmfctabctrlgetwndarea"></a><a name="getwndarea"></a>CMFCTabCtrl::GetWndArea  
 Recupera o limite da área do cliente do controle de guia atual.  
  
```  
void GetWndArea(CRect& rect) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `rect`  
 Quando este método retorna, este parâmetro contém um retângulo que circunda o controle de guia atual.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehideactivewindowhorzscrollbara--cmfctabctrlhideactivewindowhorzscrollbar"></a><a name="hideactivewindowhorzscrollbar"></a>CMFCTabCtrl::HideActiveWindowHorzScrollBar  
 Oculta a barra de rolagem horizontal, se houver, na janela ativa.  
  
```  
void HideActiveWindowHorzScrollBar();
```  
  
### <a name="remarks"></a>Comentários  
 Use esse método para impedir que o controle de guia piscar quando o usuário alterna entre as páginas de controle de guia.  
  
##  <a name="a-namehideinactivewindowa--cmfctabctrlhideinactivewindow"></a><a name="hideinactivewindow"></a>CMFCTabCtrl::HideInactiveWindow  
 Especifica se o framework exibe janelas de controle de guia inativo.  
  
```  
void HideInactiveWindow(BOOL bHide = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bHide`  
 `TRUE`para não exibir uma janela inativa. `FALSE` para exibir uma janela inativa. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehidenotabsa--cmfctabctrlhidenotabs"></a><a name="hidenotabs"></a>CMFCTabCtrl::HideNoTabs  
 Habilita ou desabilita o desenho de área da guia se não houver nenhum guias visíveis.  
  
```  
void HideNoTabs(BOOL bHide=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bHide`  
 `TRUE`Para habilitar a área da guia; de desenho `FALSE` para desabilitar o desenho. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehidesingletaba--cmfctabctrlhidesingletab"></a><a name="hidesingletab"></a>CMFCTabCtrl::HideSingleTab  
 Habilita ou desabilita o desenho de guia se houver uma única janela com guias.  
  
```  
virtual void HideSingleTab(BOOL bHide=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bHide`  
 `TRUE`Não desenhar uma guia para uma única janela com guias; `FALSE` para desenhar uma única guia. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisactiveinmditabgroupa--cmfctabctrlisactiveinmditabgroup"></a><a name="isactiveinmditabgroup"></a>CMFCTabCtrl::IsActiveInMDITabGroup  
 Indica se a guia atual de um controle guia é a guia ativa em um grupo de guias de interface de documentos múltiplos.  
  
```  
BOOL IsActiveInMDITabGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a guia atual de um controle guia é a guia ativa em um grupo de guias MDI; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode organizar várias janelas de documento em qualquer um dos grupos de guias verticais ou horizontais e reorganizar facilmente documentos do grupo de uma guia para outra.  
  
##  <a name="a-nameisactivetabboldfonta--cmfctabctrlisactivetabboldfont"></a><a name="isactivetabboldfont"></a>CMFCTabCtrl::IsActiveTabBoldFont  
 Indica se o texto da guia ativa é exibido utilizando uma fonte em negrito.  
  
```  
BOOL IsActiveTabBoldFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a guia ativa é exibida com a fonte em negrito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCTabCtrl::SetActiveTabBoldFont](#setactivetabboldfont) método para alterar a fonte da guia ativa.  
  
##  <a name="a-nameisactivetabclosebuttona--cmfctabctrlisactivetabclosebutton"></a><a name="isactivetabclosebutton"></a>CMFCTabCtrl::IsActiveTabCloseButton  
 Indica se o botão Fechar ( **X**) é exibida em uma guia ativa ou no canto superior direito da área da guia.  
  
```  
virtual BOOL IsActiveTabCloseButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão Fechar é exibido na guia ativa. `FALSE` se o botão Fechar é exibido no canto superior direito da área da guia.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisdrawframea--cmfctabctrlisdrawframe"></a><a name="isdrawframe"></a>CMFCTabCtrl::IsDrawFrame  
 Indica se a janela com guias desenha um retângulo de quadro em torno de painéis incorporados.  
  
```  
BOOL IsDrawFrame() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um quadro retângulo; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCTabCtrl::SetDrawFrame](#setdrawframe) método para habilitar ou desabilitar a desenhar um retângulo de quadro.  
  
##  <a name="a-nameisflatframea--cmfctabctrlisflatframe"></a><a name="isflatframe"></a>CMFCTabCtrl::IsFlatFrame  
 Indica se o quadro ao redor da área de guia é plana ou 3D.  
  
```  
BOOL IsFlatFrame() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o quadro ao redor da área de guia é simples; `FALSE` se o quadro estiver tridimensional.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCTabCtrl::SetFlatFrame](#setflatframe) método para alterar como o quadro é desenhado.  
  
##  <a name="a-nameisflattaba--cmfctabctrlisflattab"></a><a name="isflattab"></a>CMFCTabCtrl::IsFlatTab  
 Indica se a aparência das guias no controle guia atual é simples ou não.  
  
```  
virtual BOOL IsFlatTab() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a aparência das guias no controle guia atual é simples; Caso contrário, `FALSE`.  
  
##  <a name="a-nameisleftrightroundeda--cmfctabctrlisleftrightrounded"></a><a name="isleftrightrounded"></a>CMFCTabCtrl::IsLeftRightRounded  
 Indica se a aparência da esquerda e direita de uma guia no controle guia atual é arredondada.  
  
```  
virtual BOOL IsLeftRightRounded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se os lados de cada guia é arredondado; Caso contrário, `FALSE`.  
  
##  <a name="a-nameismditabgroupa--cmfctabctrlismditabgroup"></a><a name="ismditabgroup"></a>CMFCTabCtrl::IsMDITabGroup  
 Indica se o controle de guia atual está contido na área do cliente de uma janela de interface de documentos múltiplos.  
  
```  
virtual BOOL IsMDITabGroup() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle de guia atual está em uma janela de área de cliente MDI. Caso contrário, `FALSE`.  
  
##  <a name="a-nameisonenotestylea--cmfctabctrlisonenotestyle"></a><a name="isonenotestyle"></a>CMFCTabCtrl::IsOneNoteStyle  
 Indica se o controle de guia atual é exibido no estilo do Microsoft OneNote.  
  
```  
virtual BOOL IsOneNoteStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle de guia é exibido no estilo do Microsoft OneNote. Caso contrário, `FALSE`.  
  
##  <a name="a-nameissharedscrolla--cmfctabctrlissharedscroll"></a><a name="issharedscroll"></a>CMFCTabCtrl::IsSharedScroll  
 Indica se o controle de guia atual tem uma barra de rolagem que pode rolar suas guias como um grupo.  
  
```  
BOOL IsSharedScroll() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle da guia tem uma barra de rolagem compartilhado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método retorna `TRUE` se o `style` parâmetro o [CMFCTabCtrl::Create](#create) método é STYLE_FLAT_SHARED_HORZ_SCROLL.  
  
##  <a name="a-nameistabdocumentsmenua--cmfctabctrlistabdocumentsmenu"></a><a name="istabdocumentsmenu"></a>CMFCTabCtrl::IsTabDocumentsMenu  
 Indica se o controle de guia exibe botões de rolagem ou um botão que exibe um menu de janelas com guias.  
  
```  
BOOL IsTabDocumentsMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as janelas com guias estiverem usando um menu pop-up de rótulos de janela com guias; `FALSE` se janelas com guias estiverem usando botões de rolagem para frente e para trás.  
  
### <a name="remarks"></a>Comentários  
 Use o [CMFCTabCtrl::EnableTabDocumentsMenu](#enabletabdocumentsmenu) janelas com guias do método para especificar o método de rolagem.  
  
##  <a name="a-nameisvs2005stylea--cmfctabctrlisvs2005style"></a><a name="isvs2005style"></a>CMFCTabCtrl::IsVS2005Style  
 Indica se o guias são desenhadas usando o estilo do Visual Studio 2005.  
  
```  
virtual BOOL IsVS2005Style() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as guias são desenhadas usando o estilo do Visual Studio 2005; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use o `style` parâmetro o [CMFCTabCtrl::Create](#create) método para especificar como as guias são desenhadas.  
  
##  <a name="a-namembenableactivatea--cmfctabctrlmbenableactivate"></a><a name="m_benableactivate"></a>CMFCTabCtrl::m_bEnableActivate  
 Impede que o modo ativo perde o foco quando uma nova guia é inserida e habilitada.  
  
```  
static BOOL m_bEnableActivate;  
```  
  
### <a name="remarks"></a>Comentários  
 O foco normalmente é feito por uma nova janela com guias quando a guia é inserida e torna-se ativo. Definir o `CMFCTabCtrl::m_bEnableActivate` variável de membro para `FALSE` para manter o foco original. O valor padrão é `TRUE`.  
  
##  <a name="a-namemodifytabstylea--cmfctabctrlmodifytabstyle"></a><a name="modifytabstyle"></a>CMFCTabCtrl::ModifyTabStyle  
 Especifica a aparência das guias no controle guia atual.  
  
```  
BOOL ModifyTabStyle(Style style);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `style`  
 Um dos valores de enumeração que especifica a aparência do controle guia. Para obter mais informações, consulte a tabela em comentários.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 O valor de `style` parâmetro pode ser um dos seguintes `CMFCTabCtrl::Style` enumerações.  
  
|Nome|Descrição|  
|----------|-----------------|  
|STYLE_3D|Exibe as guias tridimensionais, retangulares com cantos arredondados.|  
|STYLE_3D_ONENOTE|Exibe as guias tridimensionais que tem um lado vertical e um lado diagonal e que tem cantos arredondados.|  
|STYLE_3D_ROUNDED|Exibe as guias tridimensionais que Inclinado laterais e cantos arredondados.|  
|STYLE_3D_ROUNDED_SCROLL|Exibe as guias tridimensionais que Inclinado laterais e cantos arredondados. Se houver mais guias que podem ser exibidos ao mesmo tempo, o framework exibe uma seta suspensa e um menu de guias para tornar ativa.|  
|STYLE_3D_SCROLLED|Exibe as guias tridimensionais, retangulares. Se houver mais guias que podem ser exibidos ao mesmo tempo, o framework exibe uma seta suspensa e um menu de guias para tornar ativa.|  
|STYLE_3D_VS2005|Exibe tridimensional, arredondado guias que têm um lado diagonal e um lado vertical.|  
|STYLE_FLAT|Exibe as guias bidimensionais que têm Inclinado lados esquerdo e direito.|  
|STYLE_FLAT_SHARED_HORZ_SCROLL|Exibe as guias bidimensionais. Se houver mais guias que podem ser exibidos ao mesmo tempo, o framework exibe setas de rolagem nas extremidades da área da guia.|  
  
##  <a name="a-nameondragentera--cmfctabctrlondragenter"></a><a name="ondragenter"></a>CMFCTabCtrl::OnDragEnter  
 Chamado pela estrutura durante uma operação de arrastar e soltar quando o cursor entra primeiro na janela do controle de guia atual.  
  
```  
virtual DROPEFFECT OnDragEnter(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDataObject`  
 Aponta para um objeto de dados que contém dados que o usuário arrasta.  
  
 [in] `dwKeyState`  
 Contém o estado das teclas modificadoras. Esse parâmetro é uma combinação bit a bit (OR) dos seguintes valores: `MK_CONTROL`, `MK_SHIFT`, `MK_ALT`, `MK_LBUTTON`, `MK_MBUTTON`, e `MK_RBUTTON`. Para obter mais informações, consulte o **parâmetros de mensagem** seção [sobre a entrada do Mouse](http://msdn.microsoft.com/library/windows/desktop/ms645601).  
  
 [in] `point`  
 Contém o local atual do cursor nas coordenadas do cliente.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `DROPEFFECT_NONE`, que significa que o local de destino não pode aceitar os dados.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para dar suporte a uma operação de arrastar e soltar. Substitui esse método para implementar seu próprio comportamento personalizado.  
  
 Por padrão, esse método chama apenas `CMFCTabCtrl::OnDragOver`, que sempre retorna `DROPEFFECT_NONE`.  
  
##  <a name="a-nameondragovera--cmfctabctrlondragover"></a><a name="ondragover"></a>CMFCTabCtrl::OnDragOver  
 Chamado pela estrutura durante uma operação de arrastar quando o mouse é movido sobre a janela de destino de soltar.  
  
```  
virtual DROPEFFECT OnDragOver(
    COleDataObject* pDataObject,  
    DWORD dwKeyState,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDataObject`  
 Ponteiro para uma [COleDataObject](../../mfc/reference/coledataobject-class.md) objeto que está sendo arrastado sobre o destino.  
  
 [in] `dwKeyState`  
 O estado das teclas modificadoras, que é uma combinação bit a bit (ou) de `MK_CONTROL`, `MK_SHIFT`, `MK_ALT`, `MK_LBUTTON`, `MK_MBUTTON`, e `MK_RBUTTON`. Para obter mais informações, consulte "Parâmetros de mensagem" em [sobre a entrada do Mouse](http://msdn.microsoft.com/library/windows/desktop/ms645601).  
  
 [in] `point`  
 A posição atual do mouse.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre `DROPEFFECT_NONE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método com sua implementação personalizada. Para obter mais informações, consulte o [CView::OnDragOver](../../mfc/reference/cview-class.md#ondragover) método.  
  
##  <a name="a-nameonshowtabdocumentsmenua--cmfctabctrlonshowtabdocumentsmenu"></a><a name="onshowtabdocumentsmenu"></a>CMFCTabCtrl::OnShowTabDocumentsMenu  
 Exibe um menu pop-up de janelas com guias, aguarda até que o usuário seleciona uma guia e torna a guia selecionada na guia ativa.  
  
```  
virtual void OnShowTabDocumentsMenu(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas onde exibir o menu pop-up.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetactiveinmditabgroupa--cmfctabctrlsetactiveinmditabgroup"></a><a name="setactiveinmditabgroup"></a>CMFCTabCtrl::SetActiveInMDITabGroup  
 Define a guia atual de um controle guia como a guia ativa em um grupo de guias de interface de documentos múltiplos.  
  
```  
void SetActiveInMDITabGroup(BOOL bActive);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bActive`  
 `TRUE`Para tornar a guia atual a guia ativa; `FALSE` para tornar a guia atual inativa.  
  
### <a name="remarks"></a>Comentários  
 Você pode organizar várias janelas de documento em qualquer um dos grupos de guias verticais ou horizontais e reorganizar facilmente documentos do grupo de uma guia para outra.  
  
##  <a name="a-namesetactivetaba--cmfctabctrlsetactivetab"></a><a name="setactivetab"></a>CMFCTabCtrl::SetActiveTab  
 Ativa uma guia.  
  
```  
virtual BOOL SetActiveTab(int iTab);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iTab`  
 Especifica o índice baseado em zero da guia para ativar.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a guia especificada tiver sido feita ativa; `FALSE` se especificado `iTab` o valor do parâmetro é inválido.  
  
### <a name="remarks"></a>Comentários  
 Esse método não envia o `AFX_WM_CHANGE_ACTIVE_TAB` notificação para a janela pai do controle guia.  
  
 O `SetActiveTab` método chama automaticamente o [CMFCTabCtrl::HideActiveWindowHorzScrollBar](#hideactivewindowhorzscrollbar) método para impedir que a tela pisque.  
  
##  <a name="a-namesetactivetabboldfonta--cmfctabctrlsetactivetabboldfont"></a><a name="setactivetabboldfont"></a>CMFCTabCtrl::SetActiveTabBoldFont  
 Habilita ou desabilita o uso de uma fonte em negrito nas guias ativos.  
  
```  
void SetActiveTabBoldFont(BOOL bIsBold=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsBold`  
 `TRUE`usar uma fonte em negrito para exibir o rótulo da guia ativa; `FALSE` para usar a fonte padrão para exibir o rótulo. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetdrawframea--cmfctabctrlsetdrawframe"></a><a name="setdrawframe"></a>CMFCTabCtrl::SetDrawFrame  
 Especifica se um quadro retângulo em torno de uma barra incorporada.  
  
```  
void SetDrawFrame(BOOL bDraw=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bDraw`  
 `TRUE`Para exibir um retângulo de quadro em torno de uma barra incorporado. Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetflatframea--cmfctabctrlsetflatframe"></a><a name="setflatframe"></a>CMFCTabCtrl::SetFlatFrame  
 Especifica se deve desenhar um plano ou um quadro 3D ao redor da área da guia.  
  
```  
void SetFlatFrame(
    BOOL bFlat=TRUE,  
    BOOL bRepaint=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bFlat`  
 `TRUE`Para desenhar um quadro simples (2D) ao redor da área da guia; `FALSE` para desenhar um quadro (3D) tridimensional. O valor padrão é `TRUE`.  
  
 [in] `bRepaint`  
 `TRUE`para redesenhar a janela imediatamente. Caso contrário, `FALSE`. O valor padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetimagelista--cmfctabctrlsetimagelist"></a><a name="setimagelist"></a>CMFCTabCtrl::SetImageList  
 Especifica uma lista de imagens.  
  
```  
virtual BOOL SetImageList(
    UINT uiID,  
    int cx=15,  
    COLORREF clrTransp=RGB(255, 0, 255));  
  
virtual BOOL SetImageList(HIMAGELIST hImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 A ID de um recurso de bitmap que contém a lista de imagens.  
  
 [in] `cx`  
 A largura de cada imagem, em pixels. O valor padrão é 15.  
  
 [in] `clrTransp`  
 A cor da imagem transparente. As partes da imagem que têm essa cor será transparentes. O valor padrão é o magenta de cor, RGB(255,0,255).  
  
 [in] `hImageList`  
 Um identificador para uma lista de imagem pré-carregada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedido. `FALSE`Se o controle de guia é criado usando um estilo simples ou se a primeira sobrecarga de método não é possível carregar o bitmap que é especificado pelo `uiID` parâmetro.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir uma lista de imagens para o controle de guia. As imagens na lista de imagens são exibidas ao lado do rótulo da guia. Esse método recalcula a altura da guia para que a guia é ajustada para conter a imagem e o texto.  
  
 Use o [CMFCBaseTabCtrl::AddTab](../../mfc/reference/cmfcbasetabctrl-class.md#addtab) método que é herdada pelo controle de guia para especificar o índice da imagem para exibir.  
  
##  <a name="a-namesetresizemodea--cmfctabctrlsetresizemode"></a><a name="setresizemode"></a>CMFCTabCtrl::SetResizeMode  
 Especifica como o controle de guia atual pode ser redimensionado e, em seguida, exibe novamente o controle.  
  
```  
void SetResizeMode(ResizeMode resizeMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `resizeMode`  
 Um do `CMFCTabCtrl::ResizeMode` valores de enumeração que especifica como o controle de guia pode ser redimensionado. Para obter uma lista dos valores possíveis, consulte a tabela em comentários.  
  
### <a name="remarks"></a>Comentários  
 O `resizeMode` parâmetro pode ser um dos seguintes `ResizeMode` valores de enumeração.  
  
|Nome|Descrição|  
|----------|-----------------|  
|RESIZE_NO|O controle de guia não pode ser redimensionado.|  
|RESIZE_VERT|O controle de guia pode ser redimensionado verticalmente, mas não na horizontal.|  
|RESIZE_HORIZ|O controle de guia pode ser redimensionado horizontalmente, mas não verticalmente.|  
  
##  <a name="a-namesettabmaxwidtha--cmfctabctrlsettabmaxwidth"></a><a name="settabmaxwidth"></a>CMFCTabCtrl::SetTabMaxWidth  
 Especifica a largura da guia máximo em uma janela com guias.  
  
```  
void SetTabMaxWidth(int nTabMaxWidth);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nTabMaxWidth`  
 A largura da guia máxima, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para limitar a largura de cada guia em uma janela com guias. Esse método é útil se o guias têm rótulos muito longos. O [CMFCTabCtrl](../../mfc/reference/cmfctabctrl-class.md) classe construtor inicializa a largura da guia máximo para 0, o que realmente significa que a largura não é limitada.  
  
##  <a name="a-namestopresizea--cmfctabctrlstopresize"></a><a name="stopresize"></a>CMFCTabCtrl::StopResize  
 Termina a operação de redimensionamento atual no controle guia.  
  
```  
void StopResize(BOOL bCancel);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bCancel`  
 `TRUE`para abandonar a operação de redimensionamento atual; `FALSE` ao concluir operação de redimensionamento do atual. Em ambos os casos, a estrutura para desenhar o retângulo de redimensionamento.  
  
##  <a name="a-namesynchronizescrollbara--cmfctabctrlsynchronizescrollbar"></a><a name="synchronizescrollbar"></a>CMFCTabCtrl::SynchronizeScrollBar  
 Desenha uma barra de rolagem horizontal em um controle guia que exibe as guias de planos.  
  
```  
BOOL SynchronizeScrollBar(SCROLLINFO* pScrollInfo = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `pScrollInfo`  
 Ponteiro para uma [SCROLLINFO](http://msdn.microsoft.com/library/windows/desktop/bb787537) estrutura ou `NULL`. Quando este método retorna, e se esse parâmetro não for `NULL`, a estrutura contém todos os parâmetros da barra de rolagem. O valor padrão é `NULL`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método afeta apenas um controle guia que exibe as guias de planos. A barra de rolagem influencia todas as guias ao mesmo tempo.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)   
 [Classe CMFCBaseTabCtrl](../../mfc/reference/cmfcbasetabctrl-class.md)

