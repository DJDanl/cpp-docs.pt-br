---
title: Classe CMFCRibbonBar | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonBar
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonBar class
ms.assetid: a65d06fa-1a28-4cc0-8971-bc9d7c9198fe
caps.latest.revision: 41
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
ms.openlocfilehash: 48a7fbeb72257776d132785c985221b0e8148d72
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonbar-class"></a>Classe CMFCRibbonBar
O `CMFCRibbonBar` classe implementa uma barra de faixa de opções semelhante àquele utilizado no Office 2007.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonBar : public CPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonBar::CMFCRibbonBar`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonBar::ActivateContextCategory](#activatecontextcategory)|Ativa a uma categoria de contexto que já está visível.|  
|[CMFCRibbonBar::AddCategory](#addcategory)|Adiciona uma nova categoria de faixa de opções à faixa de opções.|  
|[CMFCRibbonBar::AddContextCategory](#addcontextcategory)|Adiciona uma categoria de contexto.|  
|[CMFCRibbonBar::AddMainCategory](#addmaincategory)|Adiciona uma nova categoria principal da faixa de opções.|  
|[CMFCRibbonBar::AddPrintPreviewCategory](#addprintpreviewcategory)||  
|[CMFCRibbonBar::AddQATOnlyCategory](#addqatonlycategory)||  
|[CMFCRibbonBar::AddToTabs](#addtotabs)|Adicione um elemento de faixa de opções à direita de uma barra de faixa de opções.|  
|[CMFCRibbonBar::CreateEx](#createex)|Cria uma barra de controle e anexa-o para o [CPane](../../mfc/reference/cpane-class.md) objeto. (Substitui [CPane::CreateEx](../../mfc/reference/cpane-class.md#createex).)|  
|[CMFCRibbonBar::Create](#create)|Cria um controle de barra de faixa de opções e a anexa a uma barra de faixa de opções.|  
|[CMFCRibbonBar::DeactivateKeyboardFocus](#deactivatekeyboardfocus)||  
|[CMFCRibbonBar::DrawMenuImage](#drawmenuimage)||  
|[CMFCRibbonBar::DWMCompositionChanged](#dwmcompositionchanged)||  
|[CMFCRibbonBar::EnableKeyTips](#enablekeytips)|Ativar ou desativar dicas de tecla para o controle da faixa de opções.|  
|[CMFCRibbonBar::EnablePrintPreview](#enableprintpreview)|Habilitar o **Visualizar impressão** guia.|  
|[CMFCRibbonBar::EnableToolTips](#enabletooltips)|Habilita ou desabilita as descrições de dica de ferramenta e dicas de ferramentas na barra de faixa de opções.|  
|[CMFCRibbonBar::FindByData](#findbydata)|Localize um elemento de faixa de opções usando dados que especifica um usuário.|  
|[CMFCRibbonBar::FindByID](#findbyid)|Localiza um elemento de faixa de opções com a id de comando especificado.|  
|[CMFCRibbonBar::FindCategoryIndexByData](#findcategoryindexbydata)|Localiza o índice da categoria de faixa de opções que contém os dados definidos pelo usuário.|  
|[CMFCRibbonBar::ForceRecalcLayout](#forcerecalclayout)||  
|[CMFCRibbonBar::GetActiveCategory](#getactivecategory)|Obtém um ponteiro para uma categoria ativa.|  
|[CMFCRibbonBar::GetCaptionHeight](#getcaptionheight)|Retorna a altura da legenda. (Substitui [CBasePane::GetCaptionHeight](../../mfc/reference/cbasepane-class.md#getcaptionheight).)|  
|[CMFCRibbonBar::GetCategory](#getcategory)|Obtém o ponteiro para uma categoria localizada em um índice especificado.|  
|[CMFCRibbonBar::GetCategoryCount](#getcategorycount)|Obtém o número de categorias de faixa de opções na barra de faixa de opções.|  
|[CMFCRibbonBar::GetCategoryHeight](#getcategoryheight)||  
|[CMFCRibbonBar::GetCategoryIndex](#getcategoryindex)|Retorna o índice de uma categoria de faixa de opções.|  
|[CMFCRibbonBar::GetContextName](#getcontextname)|Recupera o nome da legenda categoria contexto que você especificar usando uma ID.|  
|[CMFCRibbonBar::GetDroppedDown](#getdroppeddown)||  
|[CMFCRibbonBar::GetElementsByID](#getelementsbyid)|Obtém uma matriz que contém ponteiros para todos os elementos da faixa de opções que tem a ID especificada.|  
|[CMFCRibbonBar::GetApplicationButton](#getapplicationbutton)|Obtém um ponteiro para um botão da faixa de opções.|  
|[CMFCRibbonBar::GetFocused](#getfocused)|Retorna um elemento focalizado.|  
|[CMFCRibbonBar::GetHideFlags](#gethideflags)||  
|[CMFCRibbonBar::GetItemIDsList](#getitemidslist)||  
|[CMFCRibbonBar::GetKeyboardNavigationLevel](#getkeyboardnavigationlevel)||  
|[CMFCRibbonBar::GetKeyboardNavLevelCurrent](#getkeyboardnavlevelcurrent)||  
|[CMFCRibbonBar::GetKeyboardNavLevelParent](#getkeyboardnavlevelparent)||  
|[CMFCRibbonBar::GetMainCategory](#getmaincategory)|Retorna um ponteiro para a categoria de faixa de opções selecionada no momento.|  
|[CMFCRibbonBar::GetQATCommandsLocation](#getqatcommandslocation)||  
|[CMFCRibbonBar::GetQATDroppedDown](#getqatdroppeddown)||  
|[CMFCRibbonBar::GetQuickAccessCommands](#getquickaccesscommands)|Preenche uma lista que contém as IDs de comando de todos os elementos que aparecem na barra de ferramentas de acesso rápido.|  
|[CMFCRibbonBar::GetQuickAccessToolbarLocation](#getquickaccesstoolbarlocation)||  
|[CMFCRibbonBar::GetTabTrancateRatio](#gettabtrancateratio)||  
|[CMFCRibbonBar::GetTooltipFixedWidthLargeImage](#gettooltipfixedwidthlargeimage)||  
|[CMFCRibbonBar::GetTooltipFixedWidthRegular](#gettooltipfixedwidthregular)||  
|[CMFCRibbonBar::GetVisibleCategoryCount](#getvisiblecategorycount)||  
|[CMFCRibbonBar::HideAllContextCategories](#hideallcontextcategories)|Oculta todas as categorias que estão ativos e visíveis.|  
|[CMFCRibbonBar::HideKeyTips](#hidekeytips)||  
|[CMFCRibbonBar::HitTest](#hittest)|Localiza um ponteiro para o elemento de faixa de opções que está localizado no ponto especificado nas coordenadas do cliente da barra de faixa de opções.|  
|[CMFCRibbonBar::IsKeyTipEnabled](#iskeytipenabled)|Determina se as dicas de tela são habilitadas.|  
|[CMFCRibbonBar::IsMainRibbonBar](#ismainribbonbar)||  
|[CMFCRibbonBar::IsPrintPreviewEnabled](#isprintpreviewenabled)|Determina se o **Visualizar impressão** guia é habilitada.|  
|[CMFCRibbonBar::IsQATEmpty](#isqatempty)||  
|[CMFCRibbonBar::IsQuickAccessToolbarOnTop](#isquickaccesstoolbarontop)|Especifica se a barra de ferramentas de acesso rápido é localizada acima da barra de faixa de opções.|  
|[CMFCRibbonBar::IsReplaceFrameCaption](#isreplaceframecaption)|Determina se a barra de faixa de opções substitui a legenda do quadro principal ou adicionada abaixo da legenda do quadro.|  
|[CMFCRibbonBar::IsShowGroupBorder](#isshowgroupborder)||  
|[CMFCRibbonBar::IsToolTipDescrEnabled](#istooltipdescrenabled)|Determina se as descrições de dica de ferramenta estão habilitadas.|  
|[CMFCRibbonBar::IsToolTipEnabled](#istooltipenabled)|Determina se as dicas de ferramentas para a barra de faixa de opções estão habilitadas.|  
|[CMFCRibbonBar::IsTransparentCaption](#istransparentcaption)||  
|[CMFCRibbonBar::IsWindows7Look](#iswindows7look)|Indica se a faixa de opções tem a aparência do Windows 7-estilo (botão pequeno aplicativo retangular).|  
|[CMFCRibbonBar::LoadFromResource](#loadfromresource)|Sobrecarregado. Carrega uma barra de faixa de opções de recursos do aplicativo.|  
|[CMFCRibbonBar::OnClickButton](#onclickbutton)||  
|[CMFCRibbonBar::OnEditContextMenu](#oneditcontextmenu)||  
|[CMFCRibbonBar::OnRTLChanged](#onrtlchanged)|(Substitui `CPane::OnRTLChanged`.)|  
|[CMFCRibbonBar::OnSetAccData](#onsetaccdata)|(Substitui [CBasePane::OnSetAccData](../../mfc/reference/cbasepane-class.md#onsetaccdata).)|  
|[CMFCRibbonBar::OnShowRibbonContextMenu](#onshowribboncontextmenu)||  
|[CMFCRibbonBar::OnShowRibbonQATMenu](#onshowribbonqatmenu)||  
|[CMFCRibbonBar::OnSysKeyDown](#onsyskeydown)||  
|[CMFCRibbonBar::OnSysKeyUp](#onsyskeyup)||  
|[CMFCRibbonBar::PopTooltip](#poptooltip)||  
|[CMFCRibbonBar::PreTranslateMessage](#pretranslatemessage)|(Substitui `CBasePane::PreTranslateMessage`.)|  
|[CMFCRibbonBar::RecalcLayout](#recalclayout)|(Substitui [CPane::RecalcLayout](../../mfc/reference/cpane-class.md#recalclayout).)|  
|[CMFCRibbonBar::RemoveAllCategories](#removeallcategories)|Remove todas as categorias de faixa de opções da barra de faixa de opções.|  
|[CMFCRibbonBar::RemoveAllFromTabs](#removeallfromtabs)|Remove todos os elementos da faixa de opções da área da guia.|  
|[CMFCRibbonBar::RemoveCategory](#removecategory)|Remove a categoria de faixa de opções está localizada no índice especificado.|  
|[CMFCRibbonBar::SaveToXMLBuffer](#savetoxmlbuffer)|Salva a barra de faixa de opções para um buffer.|  
|[CMFCRibbonBar::SaveToXMLFile](#savetoxmlfile)|Salva a barra de faixa de opções no arquivo XML.|  
|[CMFCRibbonBar::SetActiveCategory](#setactivecategory)|Define uma categoria de faixa de opções especificadas para ativo.|  
|[CMFCRibbonBar::SetActiveMDIChild](#setactivemdichild)||  
|[CMFCRibbonBar::SetElementKeys](#setelementkeys)|Define as dicas de tela especificadas para todos os elementos da faixa de opções com a ID do comando especificado.|  
|[CMFCRibbonBar::SetApplicationButton](#setapplicationbutton)|Atribui um botão da faixa de opções de aplicativo para a barra de faixa de opções.|  
|[CMFCRibbonBar::SetKeyboardNavigationLevel](#setkeyboardnavigationlevel)||  
|[CMFCRibbonBar::SetMaximizeMode](#setmaximizemode)||  
|[CMFCRibbonBar::SetQuickAccessCommands](#setquickaccesscommands)|Adiciona um ou mais elementos de faixa de opções para a barra de ferramentas de acesso rápido.|  
|[CMFCRibbonBar::SetQuickAccessDefaultState](#setquickaccessdefaultstate)|Especifica o estado padrão da barra de ferramentas de acesso rápido.|  
|[CMFCRibbonBar::SetQuickAccessToolbarOnTop](#setquickaccesstoolbarontop)|Posiciona o rápido acesso da barra de ferramentas (QAT) acima ou abaixo da barra de faixa de opções.|  
|[CMFCRibbonBar::SetTooltipFixedWidth](#settooltipfixedwidth)||  
|[CMFCRibbonBar::SetWindows7Look](#setwindows7look)|Habilitar/desabilitar o Windows 7 aparência (botão pequeno aplicativo retangular) da faixa de opções|  
|[CMFCRibbonBar::ShowCategory](#showcategory)|Mostra ou oculta a categoria especificada da faixa de opções.|  
|[CMFCRibbonBar::ShowContextCategories](#showcontextcategories)|Mostra ou oculta as categorias de contexto com a ID especificada.|  
|[CMFCRibbonBar::ShowKeyTips](#showkeytips)||  
|[CMFCRibbonBar::ToggleMimimizeState](#togglemimimizestate)|Alterna entre os estados maximizadas e minimizados na barra de faixa de opções...|  
|[CMFCRibbonBar::TranslateChar](#translatechar)||  
  
## <a name="remarks"></a>Comentários  
 A Microsoft introduziu a faixa de opções Fluent do Office quando lançado simultaneamente o Microsoft Office 2007. Essa barra de faixa de opções não é apenas um novo controle. Representa um novo paradigma de interface do usuário. A faixa de opções é um painel que contém um conjunto de guias chamada categorias. Cada categoria é logicamente dividida em painéis de faixa de opções e cada painel pode conter vários controles e botões de comando.  
  
 Os elementos que aparecem em expansão de barra de faixa de opções e contrato fazer o melhor uso de espaço disponível. Por exemplo, se um painel de faixa de opções tem espaço suficiente para exibir seus elementos, ela se tornará um botão de menu que exibe subitens em um menu pop-up. A barra de faixa de opções se comporta como uma barra de controle estático (não flutuante) e pode ser encaixada na parte superior de um quadro.  
  
 Você pode usar o `CMFCRibbonStatusBar` classe para implementar uma barra de status semelhante àquela usada no Office 2007. Uma categoria de faixa de opções contém (e exibe) um grupo de [painéis da faixa de opções](../../mfc/reference/cmfcribbonpanel-class.md). Cada painel de faixa de opções contém um ou mais elementos de faixa de opções, que são derivados de [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md).  
  
 Para obter informações sobre como adicionar uma barra de faixa de opções ao seu aplicativo MFC existente, consulte [passo a passo: atualizando o aplicativo de rabisco MFC](../../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribbonbar.h  
  
##  <a name="a-nameactivatecontextcategorya--cmfcribbonbaractivatecontextcategory"></a><a name="activatecontextcategory"></a>CMFCRibbonBar::ActivateContextCategory  
 Ativa a uma categoria de contexto que já está visível.  
  
```  
BOOL ActivateContextCategory(UINT uiContextID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiContextID`  
 A ID da categoria de contexto.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se uma categoria de contexto com `uiContextID` for encontrado e ativado; caso contrário, `FALSE`.  
  
##  <a name="a-nameaddcategorya--cmfcribbonbaraddcategory"></a><a name="addcategory"></a>CMFCRibbonBar::AddCategory  
 Cria e inicializa uma nova categoria de faixa de opções para a barra de faixa de opções.  
  
```  
CMFCRibbonCategory* AddCategory(
    LPCTSTR lpszName,  
    UINT uiSmallImagesResID,  
    UINT uiLargeImagesResID,  
    CSize sizeSmallImage= CSize(16,
    16),  
    CSize sizeLargeImage= CSize(32,
    32),  
    int nInsertAt = -1,  
    CRuntimeClass* pRTI= NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Nome da categoria de faixa de opções.  
  
 [in] `uiSmallImagesResID`  
 ID de recurso da lista de imagens pequenas para a categoria de faixa de opções.  
  
 [in] `uiLargeImagesResID`  
 ID de recurso da lista de imagens grandes para a categoria de faixa de opções.  
  
 [in] `sizeSmallImage`  
 Especifica o tamanho das imagens pequenas para a categoria de faixa de opções.  
  
 [in] `sizeLargeImage`  
 Especifica o tamanho das imagens grandes para a categoria de faixa de opções.  
  
 [in] `nInsertAt`  
 Índice zero com base no local de categoria.  
  
 [in] `pRTI`  
 Ponteiro para uma [classe CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md) classe de tempo de execução para criar dinamicamente uma categoria de faixa de opções em tempo de execução.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova categoria de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se o `pRTI` parâmetro não for `NULL`, a nova categoria de faixa de opções é criada dinamicamente usando a classe de tempo de execução.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `AddCategory` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&5;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_1.cpp)]  
  
##  <a name="a-nameaddcontextcategorya--cmfcribbonbaraddcontextcategory"></a><a name="addcontextcategory"></a>CMFCRibbonBar::AddContextCategory  
 Cria e inicializa uma nova categoria de contexto para a barra de faixa de opções.  
  
```  
CMFCRibbonCategory* AddContextCategory(
    LPCTSTR lpszName,  
    LPCTSTR lpszContextName,  
    UINT uiContextID,  
    AFX_RibbonCategoryColor clrContext,  
    UINT uiSmallImagesResID,  
    UINT uiLargeImagesResID,  
    CSize sizeSmallImage = CSize(16,
    16),  
    CSize sizeLargeImage = CSize(32,
    32),  
    CRuntimeClass* pRTI = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Nome da categoria.  
  
 [in] `lpszContextName`  
 Nome da legenda categoria do contexto.  
  
 [in] `uiContextID`  
 ID do contexto.  
  
 [in] `clrContext`  
 Cor da legenda categoria do contexto.  
  
 [in] `uiSmallImagesResID`  
 ID de recursos da imagem pequena de uma categoria de contexto.  
  
 [in] `uiLargeImagesResID`  
 ID de recursos da imagem grande de uma categoria de contexto.  
  
 [in] `sizeSmallImage`  
 Tamanho de uma imagem pequena.  
  
 [in] `sizeLargeImage`  
 Tamanho de uma imagem grande.  
  
 [in] `pRTI`  
 Ponteiro para uma classe de tempo de execução.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a categoria recém-criado, ou `NULL` se o `CreateObject` método `pRTI` não é possível criar a categoria especificada.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para adicionar uma categoria de contexto. Categorias de contexto são um tipo especial de categoria que pode ser mostrado ou oculto em tempo de execução, dependendo do contexto atual do aplicativo. Por exemplo, quando o usuário seleciona um objeto, você pode exibir guias especiais com categorias de contexto que é usada para alterar o objeto selecionado.  
  
 A cor de uma categoria de contexto pode ser um dos seguintes valores:  
  
-   AFX_CategoryColor_None  
  
-   AFX_CategoryColor_Red  
  
-   AFX_CategoryColor_Orange  
  
-   AFX_CategoryColor_Yellow  
  
-   AFX_CategoryColor_Green  
  
-   AFX_CategoryColor_Blue  
  
-   AFX_CategoryColor_Indigo  
  
-   AFX_CategoryColor_Violet  
  
##  <a name="a-nameaddmaincategorya--cmfcribbonbaraddmaincategory"></a><a name="addmaincategory"></a>CMFCRibbonBar::AddMainCategory  
 Cria uma nova categoria principal da faixa de opções para a barra de faixa de opções.  
  
```  
CMFCRibbonMainPanel* AddMainCategory(
    LPCTSTR lpszName,  
    UINT uiSmallImagesResID,  
    UINT uiLargeImagesResID,  
    CSize sizeSmallImage = CSize(16,
    16),  
    CSize sizeLargeImage = CSize(32,
    32));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Nome da categoria principal da faixa de opções.  
  
 [in] `uiSmallImagesResID`  
 ID do recurso de imagens pequenas.  
  
 [in] `uiLargeImagesResID`  
 ID do recurso de imagens grandes.  
  
 [in] `sizeSmallImage`  
 O tamanho das imagens pequenas.  
  
 [in] `sizeLargeImage`  
 O tamanho das imagens grandes.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a nova categoria principal da faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Se já existe uma categoria principal da faixa de opções, ela é excluída.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `AddMainCategory` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&4;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_2.cpp)]  
  
##  <a name="a-nameaddprintpreviewcategorya--cmfcribbonbaraddprintpreviewcategory"></a><a name="addprintpreviewcategory"></a>CMFCRibbonBar::AddPrintPreviewCategory  
 Cria uma categoria de visualização de impressão na barra de faixa de opções.  
  
```  
CMFCRibbonCategory* AddPrintPreviewCategory();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova categoria de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Esse método cria uma categoria de faixa de opções e os controles que precisa para fornecer uma visualização de impressão.  
  
##  <a name="a-nameaddqatonlycategorya--cmfcribbonbaraddqatonlycategory"></a><a name="addqatonlycategory"></a>CMFCRibbonBar::AddQATOnlyCategory  
 Cria uma categoria de faixa de opções de ferramentas de acesso rápido.  
  
```  
CMFCRibbonCategory* AddQATOnlyCategory(
    LPCTSTR lpszName,  
    UINT uiSmallImagesResID,  
    CSize sizeSmallImage = CSize(16,
    16));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Nome da categoria.  
  
 [in] `uiSmallImagesResID`  
 ID de recurso da lista de imagens para a categoria.  
  
 [in] `sizeSmallImage`  
 Tamanho de imagens para elementos de faixa de opções na categoria.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova categoria se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 A categoria de faixa de opções de ferramentas de acesso rápido só é usada na caixa de diálogo de personalização da barra de ferramentas de acesso rápido.  
  
##  <a name="a-nameaddtotabsa--cmfcribbonbaraddtotabs"></a><a name="addtotabs"></a>CMFCRibbonBar::AddToTabs  
 Adiciona o elemento de faixa de opções especificadas para a linha de guias da barra de faixa de opções.  
  
```  
void AddToTabs(CMFCRibbonBaseElement* pElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pElement`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O elemento de faixa de opções é posicionado antes de quaisquer botões do sistema.  
  
##  <a name="a-namecmfcribbonbara--cmfcribbonbarcmfcribbonbar"></a><a name="cmfcribbonbar"></a>CMFCRibbonBar::CMFCRibbonBar  
 Constrói e inicializa um [CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) objeto.  
  
```  
CMFCRibbonBar(BOOL bReplaceFrameCaption = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bReplaceFrameCaption`  
 `TRUE`na barra de faixa de opções substituir a legenda da janela do quadro principal. `FALSE` para localizar a barra de faixa de opções sob a legenda da janela principal do quadro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namecreatea--cmfcribbonbarcreate"></a><a name="create"></a>CMFCRibbonBar::Create  
 Cria uma janela para a barra de faixa de opções.  
  
```  
BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,  
    UINT nID = AFX_IDW_RIBBON_BAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Ponteiro para a janela pai para a barra de faixa de opções.  
  
 [in] `dwStyle`  
 Uma combinação lógica de estilos para a nova janela.  
  
 [in] `nID`  
 ID da nova janela.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela foi criada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Create` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&1;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_3.cpp)]  
  
##  <a name="a-namecreateexa--cmfcribbonbarcreateex"></a><a name="createex"></a>CMFCRibbonBar::CreateEx  
 Cria uma janela para a barra de faixa de opções.  
  
```  
BOOL CreateEx(
    CWnd* pParentWnd,  
    DWORD dwCtrlStyle = 0,  
    DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,  
    UINT nID = AFX_IDW_RIBBON_BAR);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Ponteiro para a janela pai para a barra de faixa de opções.  
  
 [in] `dwCtrlStyle`  
 Este parâmetro não é usado.  
  
 [in] `dwStyle`  
 Uma combinação lógica de estilos para a nova janela.  
  
 [in] `nID`  
 ID da nova janela.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a janela foi criada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namedeactivatekeyboardfocusa--cmfcribbonbardeactivatekeyboardfocus"></a><a name="deactivatekeyboardfocus"></a>CMFCRibbonBar::DeactivateKeyboardFocus  
 Fecha todos os controles de dica de tela na barra de faixa de opções.  
  
```  
void DeactivateKeyboardFocus(BOOL bSetFocus = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSetFocus`  
 `TRUE`Para definir o foco para a janela pai da barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namedrawmenuimagea--cmfcribbonbardrawmenuimage"></a><a name="drawmenuimage"></a>CMFCRibbonBar::DrawMenuImage  
 Desenha a imagem de um botão de menu.  
  
```  
BOOL DrawMenuImage(
    CDC* pDC,  
    const CMFCToolBarMenuButton* pMenuItem,  
    const CRect& rectImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para o botão de menu.  
  
 [in] `pMenuItem`  
 Ponteiro para um botão de menu da barra de ferramentas.  
  
 [in] `rectImage`  
 O retângulo de exibição para um botão de menu.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a imagem foi desenhada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namedwmcompositionchangeda--cmfcribbonbardwmcompositionchanged"></a><a name="dwmcompositionchanged"></a>CMFCRibbonBar::DWMCompositionChanged  
 Ajusta a exibição da barra de faixa de opções quando a composição do Gerenciador de janelas da área de trabalho (DWM) está habilitada ou desabilitada.  
  
```  
virtual void DWMCompositionChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameenablekeytipsa--cmfcribbonbarenablekeytips"></a><a name="enablekeytips"></a>CMFCRibbonBar::EnableKeyTips  
 Habilita ou desabilita o recurso de dica de tela para a barra de faixa de opções.  
  
```  
void EnableKeyTips(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o recurso de dicas de tela; `FALSE` para desabilitar o recurso de dicas de tela.  
  
### <a name="remarks"></a>Comentários  
 Quando você habilita esse recurso, dicas de tecla são exibidas quando o usuário pressiona o botão ALT ou F10. Quando o usuário pressiona a tecla ALT, dicas de tecla são exibidas com um atraso de 200 milissegundos. Esse atraso permite atalhos para ser executado para que a tecla ALT pressionada não interferir com outras combinações que incluem a tecla ALT.  
  
##  <a name="a-nameenableprintpreviewa--cmfcribbonbarenableprintpreview"></a><a name="enableprintpreview"></a>CMFCRibbonBar::EnablePrintPreview  
 Habilita ou desabilita o **Visualizar impressão** recurso.  
  
```  
void EnablePrintPreview(BOOL bEnable = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o **Visualizar impressão** recurso; `FALSE` para desabilitar o **Visualizar impressão** recurso.  
  
### <a name="remarks"></a>Comentários  
 Se `bEnable` é `FALSE` e existe uma categoria de visualização de impressão, ele será excluído.  
  
 Por padrão o **Visualizar impressão** está ativado.  
  
##  <a name="a-nameenabletooltipsa--cmfcribbonbarenabletooltips"></a><a name="enabletooltips"></a>CMFCRibbonBar::EnableToolTips  
 Habilita ou desabilita as dicas de ferramenta e descrições de dica de ferramenta opcional na barra de faixa de opções.  
  
```  
void EnableToolTips(
    BOOL bEnable = TRUE,  
    BOOL bEnableDescr = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar dicas de ferramenta na barra de faixa de opções; `FALSE` para desativar as dicas de ferramentas na barra de faixa de opções.  
  
 [in] `bEnableDescr`  
 `TRUE`Para habilitar as descrições de dica de ferramenta na dica de ferramenta; `FALSE` desabilitar descrições de dica de ferramenta na dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 O `bEnable` parâmetro determina se as dicas de ferramenta são exibidas quando o mouse passa sobre um elemento de faixa de opções. O `bEnableDescr` parâmetro determina se o texto descritivo adicional aparece com o texto de dica de ferramenta.  
  
##  <a name="a-namefindbydataa--cmfcribbonbarfindbydata"></a><a name="findbydata"></a>CMFCRibbonBar::FindByData  
 Recupera um ponteiro para um elemento de faixa de opções, se os dados especificados e visibilidade.  
  
```  
CMFCRibbonBaseElement* FindByData(
    DWORD_PTR dwData,  
    BOOL bVisibleOnly = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Os dados associados a um elemento de faixa de opções.  
  
 [in] `bVisibleOnly`  
 `TRUE`para pesquisar elementos visíveis da faixa de opções. `FALSE` para pesquisar todos os elementos da faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento de faixa de opções, se os dados especificados e visibilidade; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Um elemento de faixa de opções é qualquer controle que você pode adicionar à faixa de opções, como um botão da faixa de opções, uma categoria de faixa de opções ou um controle deslizante de faixa de opções.  
  
##  <a name="a-namefindbyida--cmfcribbonbarfindbyid"></a><a name="findbyid"></a>CMFCRibbonBar::FindByID  
 Recupera um ponteiro para o elemento de faixa de opções que tem os valores de ID e pesquisa do comando especificado.  
  
```  
CMFCRibbonBaseElement* FindByID(
    UINT uiCmdID,  
    BOOL bVisibleOnly = TRUE,  
    BOOL bExcludeQAT = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 ID de comando para um elemento de faixa de opções.  
  
 [in] `bVisibleOnly`  
 `TRUE`para pesquisar elementos visíveis da faixa de opções. `FALSE` para pesquisar todos os elementos da faixa de opções.  
  
 [in] `bExcludeQAT`  
 `TRUE`Para excluir os elementos da barra de ferramentas de acesso rápido da pesquisa; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento de faixa de opções se ele tem os valores de ID e pesquisa de comando especificado. Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Um elemento de faixa de opções é qualquer controle da faixa de opções que pode ser adicionado à faixa de opções, como um botão da faixa de opções, uma categoria de faixa de opções ou um controle deslizante de faixa de opções.  
  
 Em geral, pode haver mais de um elemento de faixa de opções que tem a mesma ID de comando. Se você quiser obter ponteiros para todos os elementos da faixa de opções que usem uma ID de comando especificado, use o [CMFCRibbonBar::GetElementsByID](#getelementsbyid) método.  
  
##  <a name="a-namefindcategoryindexbydataa--cmfcribbonbarfindcategoryindexbydata"></a><a name="findcategoryindexbydata"></a>CMFCRibbonBar::FindCategoryIndexByData  
 Recupera o índice da categoria de faixa de opções que contém os dados especificados.  
  
```  
int FindCategoryIndexByData(DWORD dwData) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Os dados associados a uma categoria de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero de uma categoria de faixa de opções, se o método teve êxito; Caso contrário, retornará-1.  
  
##  <a name="a-nameforcerecalclayouta--cmfcribbonbarforcerecalclayout"></a><a name="forcerecalclayout"></a>CMFCRibbonBar::ForceRecalcLayout  
 Ajusta o layout de todos os itens na barra de faixa de opções e janela pai e redesenha a janela inteira.  
  
```  
void ForceRecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetactivecategorya--cmfcribbonbargetactivecategory"></a><a name="getactivecategory"></a>CMFCRibbonBar::GetActiveCategory  
 Recupera um ponteiro para a categoria de faixa de opções ativa.  
  
```  
CMFCRibbonCategory* GetActiveCategory() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a categoria de faixa de opções ativa; ou `NULL` se nenhuma categoria está ativa.  
  
### <a name="remarks"></a>Comentários  
 Uma categoria é ativa se ele tiver o foco. Por padrão, a categoria ativa é a primeira categoria no lado esquerdo da barra de faixa de opções.  
  
 A categoria principal é exibida quando o usuário pressiona o botão do aplicativo e não pode ser a categoria ativa.  
  
##  <a name="a-namegetapplicationbuttona--cmfcribbonbargetapplicationbutton"></a><a name="getapplicationbutton"></a>CMFCRibbonBar::GetApplicationButton  
 Recupera um ponteiro para o botão do aplicativo.  
  
```  
CMFCRibbonApplicationButton* GetApplicationButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o botão do aplicativo; ou `NULL` se o botão não tiver sido definido.  
  
##  <a name="a-namegetcaptionheighta--cmfcribbonbargetcaptionheight"></a><a name="getcaptionheight"></a>CMFCRibbonBar::GetCaptionHeight  
 Recupera a altura da área de legenda para a barra de faixa de opções.  
  
```  
int GetCaptionHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, da área de legenda para a barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetcategorya--cmfcribbonbargetcategory"></a><a name="getcategory"></a>CMFCRibbonBar::GetCategory  
 Recupera um ponteiro para a categoria de faixa de opções no índice especificado.  
  
```  
CMFCRibbonCategory* GetCategory(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice com base em zero de uma categoria de faixa de opções na lista de categorias de faixa de opções que está contida na barra de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a categoria de faixa de opções no índice especificado; Caso contrário, `NULL` se `nIndex` estava fora do intervalo.  
  
##  <a name="a-namegetcategorycounta--cmfcribbonbargetcategorycount"></a><a name="getcategorycount"></a>CMFCRibbonBar::GetCategoryCount  
 Recupera o número de categorias de faixa de opções na barra de faixa de opções.  
  
```  
int GetCategoryCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de categorias de faixa de opções na barra de faixa de opções.  
  
##  <a name="a-namegetcategoryheighta--cmfcribbonbargetcategoryheight"></a><a name="getcategoryheight"></a>CMFCRibbonBar::GetCategoryHeight  
 Recupera a altura da categoria.  
  
```  
int GetCategoryHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura da categoria.  
  
### <a name="remarks"></a>Comentários  
 A altura da categoria inclui a altura da guia categoria.  
  
##  <a name="a-namegetcategoryindexa--cmfcribbonbargetcategoryindex"></a><a name="getcategoryindex"></a>CMFCRibbonBar::GetCategoryIndex  
 Recupera o índice da categoria de faixa de opções especificadas.  
  
```  
int GetCategoryIndex(CMFCRibbonCategory* pCategory) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pCategory`  
 Ponteiro para uma categoria de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice baseado em zero de uma categoria de faixa de opções especificado por `pCategory`; ou -1 se não for encontrada na categoria de faixa de opções.  
  
##  <a name="a-namegetcontextnamea--cmfcribbonbargetcontextname"></a><a name="getcontextname"></a>CMFCRibbonBar::GetContextName  
 Recupera o nome da legenda categoria contexto especificado por um ID de contexto.  
  
```  
BOOL GetContextName(
    UINT uiContextID,  
    CString& strName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiContextID`  
 Uma ID de contexto da categoria de faixa de opções.  
  
 [out] `strName`  
 O nome de uma legenda de categoria de contexto.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito; Caso contrário, `FALSE` se `uiContextID` era zero ou a legenda da categoria de contexto não foi encontrada.  
  
##  <a name="a-namegetdroppeddowna--cmfcribbonbargetdroppeddown"></a><a name="getdroppeddown"></a>CMFCRibbonBar::GetDroppedDown  
 Recupera o elemento de faixa de opções está suspensa no momento.  
  
```  
virtual CMFCRibbonBaseElement* GetDroppedDown();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de faixa de opções está suspensa no momento; ou `NULL` se nenhum elemento de faixa de opções está suspensa no momento.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetelementsbyida--cmfcribbonbargetelementsbyid"></a><a name="getelementsbyid"></a>CMFCRibbonBar::GetElementsByID  
 Recupera uma matriz de ponteiros para todos os elementos da faixa de opções que têm uma ID de comando específico.  
  
```  
void GetElementsByID(
    UINT uiCmdID,  
    CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>& arButtons);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 ID de comando de um elemento de faixa de opções.  
  
 [out] `arButtons`  
 Uma matriz de ponteiros para os elementos da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Vários elementos de faixa de opções podem ter a mesma ID de comando porque alguns elementos da faixa de opções podem ser copiados na barra de ferramentas de acesso rápido.  
  
##  <a name="a-namegethideflagsa--cmfcribbonbargethideflags"></a><a name="gethideflags"></a>CMFCRibbonBar::GetHideFlags  
 Recupera os sinalizadores que indicam a quantidade da barra de faixa de opções está visível.  
  
```  
DWORD GetHideFlags() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os sinalizadores que indicam a quantidade da barra de faixa de opções está visível.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir lista as combinações possíveis de sinalizadores para o valor de retorno:  
  
 `AFX_RIBBONBAR_HIDE_ELEMENTS`  
 A barra de faixa de opções é minimizada verticalmente e somente os guias de categoria, botão principal e barra de ferramentas de acesso rápido são visíveis.  
  
 `AFX_RIBBONBAR_HIDE_ALL`  
 A largura da barra de faixa de opções é menor que a largura mínima e é completamente escondida.  
  
##  <a name="a-namegetitemidslista--cmfcribbonbargetitemidslist"></a><a name="getitemidslist"></a>CMFCRibbonBar::GetItemIDsList  
 Recupera as IDs de comando para o conjunto especificado de elementos da faixa de opções na barra de faixa de opções.  
  
```  
void GetItemIDsList(CList<UINT, UINT>& lstItems,  
    BOOL bHiddenOnly = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lstItems`  
 A lista de IDs de comando para os elementos da faixa de opções que estão contidos na barra de faixa de opções.  
  
 [in] `bHiddenOnly`  
 `TRUE`Para excluir os elementos da faixa de opções que são exibidos. `FALSE` para incluir todos os elementos da faixa de opções na barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetkeyboardnavigationlevela--cmfcribbonbargetkeyboardnavigationlevel"></a><a name="getkeyboardnavigationlevel"></a>CMFCRibbonBar::GetKeyboardNavigationLevel  
 Recupera o nível de navegação atual que o usuário pressiona as dicas de tela que estão contidas na barra de faixa de opções.  
  
```  
int GetKeyboardNavigationLevel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nível de navegação atual que o usuário pressiona as dicas de tela que estão contidas na barra de faixa de opções. A tabela a seguir lista os possíveis valores de retorno:  
  
 -1  
 Dicas de tela não são exibidas.  
  
 0  
 Dicas de tela são exibidas.  
  
 1  
 Usuário pressionou uma dica de tela exibida.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetkeyboardnavlevelcurrenta--cmfcribbonbargetkeyboardnavlevelcurrent"></a><a name="getkeyboardnavlevelcurrent"></a>CMFCRibbonBar::GetKeyboardNavLevelCurrent  
 Recupera o objeto atual de navegação de teclado na barra de faixa de opções.  
  
```  
CObject* GetKeyboardNavLevelCurrent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O objeto atual de navegação de teclado na barra de faixa de opções; Caso contrário, `NULL` se nenhum objeto atualmente exibir dicas de tela.  
  
### <a name="remarks"></a>Comentários  
 O objeto que está exibindo dicas de tela é o objeto de navegação do teclado atual.  
  
##  <a name="a-namegetkeyboardnavlevelparenta--cmfcribbonbargetkeyboardnavlevelparent"></a><a name="getkeyboardnavlevelparent"></a>CMFCRibbonBar::GetKeyboardNavLevelParent  
 Recupera o objeto pai de navegação de teclado na barra de faixa de opções.  
  
```  
CObject* GetKeyboardNavLevelParent() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Objeto pai de navegação de teclado na barra de faixa de opções; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário pressiona uma dica de tela na barra de faixa de opções, o objeto de navegação do teclado atual se torna o objeto de navegação de teclado do pai.  
  
##  <a name="a-namegetmaincategorya--cmfcribbonbargetmaincategory"></a><a name="getmaincategory"></a>CMFCRibbonBar::GetMainCategory  
 Recupera um ponteiro para a categoria principal da faixa de opções.  
  
```  
CMFCRibbonCategory* GetMainCategory() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a categoria principal da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 A categoria principal da faixa de opções contém o painel principal da faixa de opções.  
  
##  <a name="a-namegetqatcommandslocationa--cmfcribbonbargetqatcommandslocation"></a><a name="getqatcommandslocation"></a>CMFCRibbonBar::GetQATCommandsLocation  
 Recupera o retângulo de exibição para a seção de comandos da barra de ferramentas de acesso rápido.  
  
```  
CRect GetQATCommandsLocation() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo de exibição para a seção de comandos da barra de ferramentas de acesso rápido.  
  
### <a name="remarks"></a>Comentários  
 A seção comandos do retângulo de exibição não inclui o botão de personalização.  
  
##  <a name="a-namegetqatdroppeddowna--cmfcribbonbargetqatdroppeddown"></a><a name="getqatdroppeddown"></a>CMFCRibbonBar::GetQATDroppedDown  
 Recupera um ponteiro para o elemento de faixa de opções na barra de acesso rápido com o menu pop-up soltas.  
  
```  
CMFCRibbonBaseElement* GetQATDroppedDown();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o elemento de faixa de opções na barra de acesso rápido com o menu pop-up soltas.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetquickaccesscommandsa--cmfcribbonbargetquickaccesscommands"></a><a name="getquickaccesscommands"></a>CMFCRibbonBar::GetQuickAccessCommands  
 Recupera uma lista de IDs de comando para os elementos da faixa de opções na barra de ferramentas de acesso rápido.  
  
```  
void GetQuickAccessCommands(CList<UINT,UINT>& lstCommands);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lstCommands`  
 A lista de IDs de comando para os elementos da faixa de opções na barra de ferramentas de acesso rápido.  
  
### <a name="remarks"></a>Comentários  
 A lista não contém elementos da faixa de opções de separadores de controle.  
  
##  <a name="a-namegetquickaccesstoolbarlocationa--cmfcribbonbargetquickaccesstoolbarlocation"></a><a name="getquickaccesstoolbarlocation"></a>CMFCRibbonBar::GetQuickAccessToolbarLocation  
 Recupera o retângulo de exibição da barra de ferramentas de acesso rápido.  
  
```  
CRect GetQuickAccessToolbarLocation() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo de exibição da barra de ferramentas de acesso rápido.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegettabtrancateratioa--cmfcribbonbargettabtrancateratio"></a><a name="gettabtrancateratio"></a>CMFCRibbonBar::GetTabTrancateRatio  
 Recupera a redução de tamanho percentual na largura de exibição das guias de categoria.  
  
```  
int GetTabTrancateRatio() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O percentual de tamanho de redução a largura da exibição de guias de categoria.  
  
### <a name="remarks"></a>Comentários  
 Guias de categoria são reduzidos quando não há suficiente largura na barra de faixa de opções.  
  
##  <a name="a-namegettooltipfixedwidthlargeimagea--cmfcribbonbargettooltipfixedwidthlargeimage"></a><a name="gettooltipfixedwidthlargeimage"></a>CMFCRibbonBar::GetTooltipFixedWidthLargeImage  
 Recupera o tamanho grande de largura de dica de ferramenta para a barra de faixa de opções.  
  
```  
int GetTooltipFixedWidthLargeImage() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho grande de dica de ferramenta largura em pixels.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho grande de largura de dica de ferramenta é 0, a largura varia.  
  
##  <a name="a-namegettooltipfixedwidthregulara--cmfcribbonbargettooltipfixedwidthregular"></a><a name="gettooltipfixedwidthregular"></a>CMFCRibbonBar::GetTooltipFixedWidthRegular  
 Recupera o tamanho regular da largura de dica de ferramenta para a barra de faixa de opções.  
  
```  
int GetTooltipFixedWidthRegular() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho regular da dica de ferramenta largura em pixels.  
  
### <a name="remarks"></a>Comentários  
 Se o tamanho regular da largura da dica de ferramenta é 0, a largura varia.  
  
##  <a name="a-namegetvisiblecategorycounta--cmfcribbonbargetvisiblecategorycount"></a><a name="getvisiblecategorycount"></a>CMFCRibbonBar::GetVisibleCategoryCount  
 Recupera o número de categorias visíveis na barra de faixa de opções.  
  
```  
int GetVisibleCategoryCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de categorias visíveis na barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehideallcontextcategoriesa--cmfcribbonbarhideallcontextcategories"></a><a name="hideallcontextcategories"></a>CMFCRibbonBar::HideAllContextCategories  
 Oculta todas as categorias de contexto na barra de faixa de opções.  
  
```  
BOOL HideAllContextCategories();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria de pelo menos um contexto foi oculto; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se uma categoria de contexto estiver ativa, a categoria ativa é redefinida para a primeira categoria visível na lista de categorias.  
  
##  <a name="a-namehidekeytipsa--cmfcribbonbarhidekeytips"></a><a name="hidekeytips"></a>CMFCRibbonBar::HideKeyTips  
 Oculta todas as dicas de tela na barra de faixa de opções.  
  
```  
void HideKeyTips();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehittesta--cmfcribbonbarhittest"></a><a name="hittest"></a>CMFCRibbonBar::HitTest  
 Recupera um ponteiro para o elemento de faixa de opções especificado pelo local do ponto.  
  
```  
virtual CMFCRibbonBaseElement* HitTest(
    CPoint point,  
    BOOL bCheckActiveCategory= FALSE,  
    BOOL bCheckPanelCaption= FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 Local do ponto em coordenadas de barra de faixa de opções.  
  
 [in] `bCheckActiveCategory`  
 `TRUE`para pesquisar a categoria ativa; `FALSE` não para pesquisar a categoria ativa.  
  
 [in] `bCheckPanelCaption`  
 `TRUE`Para testar a legenda do painel da faixa de opções com o ponto localizado `FALSE` não para testar a legenda do painel da faixa de opções com o ponto localizado nele. Consulte a seção Comentários para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o elemento de faixa de opções, localizado no ponto especificado; Caso contrário, `NULL` se o ponto não estiver localizado em um elemento de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 A legenda do painel da faixa de opções com o ponto localizado em que ele não é testada, a menos que o `bCheckActiveCategory` parâmetro é `TRUE`.  
  
##  <a name="a-nameiskeytipenableda--cmfcribbonbariskeytipenabled"></a><a name="iskeytipenabled"></a>CMFCRibbonBar::IsKeyTipEnabled  
 Indica se o recurso de dicas de tela está habilitado.  
  
```  
BOOL IsKeyTipEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o recurso de dicas de tela estiver habilitado; Caso contrário, `FALSE`.  
  
##  <a name="a-nameismainribbonbara--cmfcribbonbarismainribbonbar"></a><a name="ismainribbonbar"></a>CMFCRibbonBar::IsMainRibbonBar  
 Indica se a barra de faixa de opções é a barra de faixa de opções primário.  
  
```  
virtual BOOL IsMainRibbonBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão esse método sempre retornará `TRUE`. Substitua este método para indicar se a barra de faixa de opções é a barra de faixa de opções primário.  
  
##  <a name="a-nameisprintpreviewenableda--cmfcribbonbarisprintpreviewenabled"></a><a name="isprintpreviewenabled"></a>CMFCRibbonBar::IsPrintPreviewEnabled  
 Indica se o **Visualizar impressão** está ativado.  
  
```  
BOOL IsPrintPreviewEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o **Visualizar impressão** recurso é habilitado; caso contrário `FALSE`.  
  
##  <a name="a-nameisqatemptya--cmfcribbonbarisqatempty"></a><a name="isqatempty"></a>CMFCRibbonBar::IsQATEmpty  
 Indica se a barra de ferramentas de acesso rápido contém botões de comando.  
  
```  
BOOL IsQATEmpty() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas de acesso rápido contém botões de comando; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisquickaccesstoolbarontopa--cmfcribbonbarisquickaccesstoolbarontop"></a><a name="isquickaccesstoolbarontop"></a>CMFCRibbonBar::IsQuickAccessToolbarOnTop  
 Indica se a barra de ferramentas de acesso rápido é localizada acima ou abaixo da barra de faixa de opções.  
  
```  
BOOL IsQuickAccessToolbarOnTop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de ferramentas de acesso rápido estiver localizada na barra de faixa de opções. `FALSE` se a barra de ferramentas de acesso rápido está localizada abaixo da barra de faixa de opções.  
  
##  <a name="a-nameisreplaceframecaptiona--cmfcribbonbarisreplaceframecaption"></a><a name="isreplaceframecaption"></a>CMFCRibbonBar::IsReplaceFrameCaption  
 Indica se a barra de faixa de opções substitui ou está sob a legenda da janela principal do quadro.  
  
```  
BOOL IsReplaceFrameCaption() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de faixa de opções substitui a legenda da janela do quadro principal. `FALSE` se a barra de faixa de opções está sob a legenda da janela principal do quadro.  
  
##  <a name="a-nameisshowgroupbordera--cmfcribbonbarisshowgroupborder"></a><a name="isshowgroupborder"></a>CMFCRibbonBar::IsShowGroupBorder  
 Indica se os grupos de botões localizados na barra de faixa de opções exibem uma borda de grupo.  
  
```  
virtual BOOL IsShowGroupBorder(CMFCRibbonButtonsGroup* pGroup) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pGroup`  
 Este parâmetro não é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Por padrão esse método sempre retornará `FALSE`. Substitua este método para indicar se os grupos de botões localizados na barra de faixa de opções exibem uma borda de grupo.  
  
##  <a name="a-nameistooltipdescrenableda--cmfcribbonbaristooltipdescrenabled"></a><a name="istooltipdescrenabled"></a>CMFCRibbonBar::IsToolTipDescrEnabled  
 Indica se as descrições de dica de ferramenta estão habilitadas.  
  
```  
BOOL IsToolTipDescrEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as descrições de dica de ferramenta estiverem habilitadas; `FALSE` se descrições de dica de ferramenta estão desabilitadas.  
  
### <a name="remarks"></a>Comentários  
 Descrições de dica de ferramenta são adicional texto descritivo exibido com o texto de dica de ferramenta.  
  
##  <a name="a-nameistooltipenableda--cmfcribbonbaristooltipenabled"></a><a name="istooltipenabled"></a>CMFCRibbonBar::IsToolTipEnabled  
 Indica se as dicas de ferramentas são habilitadas ou desabilitadas para a barra de faixa de opções.  
  
```  
BOOL IsToolTipEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as dicas de ferramentas estiverem habilitadas; `FALSE` se as dicas de ferramentas são desativadas.  
  
##  <a name="a-nameistransparentcaptiona--cmfcribbonbaristransparentcaption"></a><a name="istransparentcaption"></a>CMFCRibbonBar::IsTransparentCaption  
 Indica se a exibição está definida para o esquema de cores Windows Aero.  
  
```  
BOOL IsTransparentCaption() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o esquema de cores é o Windows Aero; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonclickbuttona--cmfcribbonbaronclickbutton"></a><a name="onclickbutton"></a>CMFCRibbonBar::OnClickButton  
 Esse método é mantido para compatibilidade com aplicativos existentes e não deve ser usado para o desenvolvimento de novo.  
  
```  
virtual void OnClickButton(
    CMFCRibbonButton* pButton,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para o botão que foi clicado.  
  
 [in] `point`  
 Este parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameoneditcontextmenua--cmfcribbonbaroneditcontextmenu"></a><a name="oneditcontextmenu"></a>CMFCRibbonBar::OnEditContextMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual void OnEditContextMenu(
    CMFCRibbonRichEditCtrl* pEdit,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pEdit`  
 [in] `point`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonrtlchangeda--cmfcribbonbaronrtlchanged"></a><a name="onrtlchanged"></a>CMFCRibbonBar::OnRTLChanged  
 Chamado pela estrutura quando o layout muda de direção.  
  
```  
virtual void OnRTLChanged(BOOL bIsRTL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsRTL`  
 `TRUE`Se o layout é da direita para esquerda; `FALSE` se o layout é à esquerda para a direita.  
  
### <a name="remarks"></a>Comentários  
 Esse método ajusta o layout de todos os controles na barra de faixa de opções para a nova direção do layout.  
  
##  <a name="a-nameonsetaccdataa--cmfcribbonbaronsetaccdata"></a><a name="onsetaccdata"></a>CMFCRibbonBar::OnSetAccData  
 Esse método é a estrutura interno e não se destina a ser chamado no código do usuário.  
  
```  
BOOL OnSetAccData(long lVal);
```  
  
### <a name="parameters"></a>Parâmetros  
 Longas`lVal`  
 O índice do objeto acessível.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se for bem-sucedida; Caso contrário, FALSE ou S_FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonshowribboncontextmenua--cmfcribbonbaronshowribboncontextmenu"></a><a name="onshowribboncontextmenu"></a>CMFCRibbonBar::OnShowRibbonContextMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowRibbonContextMenu(
    CWnd* pWnd,  
    int x,  
    int y,  
    CMFCRibbonBaseElement* pHit);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 [in] `x`  
 [in] `y`  
 [in] `pHit`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonshowribbonqatmenua--cmfcribbonbaronshowribbonqatmenu"></a><a name="onshowribbonqatmenu"></a>CMFCRibbonBar::OnShowRibbonQATMenu  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnShowRibbonQATMenu(
    CWnd* pWnd,  
    int x,  
    int y,  
    CMFCRibbonBaseElement* pHit);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 [in] `x`  
 [in] `y`  
 [in] `pHit`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonsyskeydowna--cmfcribbonbaronsyskeydown"></a><a name="onsyskeydown"></a>CMFCRibbonBar::OnSysKeyDown  
 Chamado pela estrutura quando o usuário pressiona a tecla F10 ou mantém pressionada a tecla ALT e, em seguida, pressionar outra chave.  
  
```  
BOOL OnSysKeyDown(
    CFrameWnd* pFrameWnd,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrameWnd`  
 Ponteiro para a janela de quadro principal do pai da barra de faixa de opções.  
  
 [in] `wParam`  
 Código de tecla virtual da chave que está sendo pressionado.  
  
 [in] `lParam`  
 Sinalizadores de estado do teclado quando foi pressionada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o evento de pressionamento de tecla foi processado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonsyskeyupa--cmfcribbonbaronsyskeyup"></a><a name="onsyskeyup"></a>CMFCRibbonBar::OnSysKeyUp  
 Chamado pela estrutura quando o usuário libera uma tecla que foi pressionada quando a tecla ALT foi pressionada, a tecla ALT ou a tecla F10.  
  
```  
BOOL OnSysKeyUp(
    CFrameWnd* pFrameWnd,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFrameWnd`  
 Ponteiro para a janela de quadro principal do pai da barra de faixa de opções.  
  
 [in] `wParam`  
 Código de tecla virtual da chave que está sendo lançada.  
  
 [in] `lParam`  
 Este parâmetro não é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o evento de pressionamento de tecla foi processado; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namepoptooltipa--cmfcribbonbarpoptooltip"></a><a name="poptooltip"></a>CMFCRibbonBar::PopTooltip  
 Remove uma dica de ferramenta do modo de exibição.  
  
```  
void PopTooltip();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namepretranslatemessagea--cmfcribbonbarpretranslatemessage"></a><a name="pretranslatemessage"></a>CMFCRibbonBar::PreTranslateMessage  
 Determina se a mensagem especificada será processada pela barra de faixa de opções.  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMsg`  
 Ponteiro para uma mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a mensagem foi processada pela barra de faixa de opções; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namerecalclayouta--cmfcribbonbarrecalclayout"></a><a name="recalclayout"></a>CMFCRibbonBar::RecalcLayout  
 Ajusta o layout de todos os controles na barra de faixa de opções.  
  
```  
virtual void RecalcLayout();
```  
  
### <a name="remarks"></a>Comentários  
 Após o ajuste de layout, a exibição da barra de faixa de opções é atualizada.  
  
##  <a name="a-nameremoveallcategoriesa--cmfcribbonbarremoveallcategories"></a><a name="removeallcategories"></a>CMFCRibbonBar::RemoveAllCategories  
 Exclui todas as categorias de faixa de opções da barra de faixa de opções.  
  
```  
void RemoveAllCategories();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método exclui todas as categorias de faixa de opções da memória e da lista de categorias.  
  
##  <a name="a-nameremoveallfromtabsa--cmfcribbonbarremoveallfromtabs"></a><a name="removeallfromtabs"></a>CMFCRibbonBar::RemoveAllFromTabs  
 Remove todos os elementos da faixa de opções da área da guia.  
  
```  
void RemoveAllFromTabs();
```  
  
### <a name="remarks"></a>Comentários  
 Use essa função se você deseja remover todos os elementos que você adicionou à área da guia usando [CMFCRibbonBar::AddToTabs](#addtotabs) método.  
  
##  <a name="a-nameremovecategorya--cmfcribbonbarremovecategory"></a><a name="removecategory"></a>CMFCRibbonBar::RemoveCategory  
 Exclui a categoria especificada da faixa de opções da barra de faixa de opções.  
  
```  
BOOL RemoveCategory(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice com base em zero de uma categoria na lista de categorias de faixa de opções que está contida na barra de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria de faixa de opções especificado foi excluída; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A categoria de faixa de opções especificado é excluída da memória e da lista de categorias.  
  
##  <a name="a-namesetactivecategorya--cmfcribbonbarsetactivecategory"></a><a name="setactivecategory"></a>CMFCRibbonBar::SetActiveCategory  
 Define a categoria de faixa de opções especificada como a categoria de ativa.  
  
```  
BOOL SetActiveCategory(
    CMFCRibbonCategory* pCategory,  
    BOOL bForceRestore= FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pCategory`  
 Uma categoria de faixa de opções que está contida na barra de faixa de opções.  
  
 [in] `bForceRestore`  
 `TRUE`para maximizar a barra de faixa de opções, se ele está minimizado. `FALSE` para exibir a categoria ativa em uma janela pop-up, se a barra de faixa de opções é minimizada.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria especificada foi definida como a categoria ativa; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A categoria principal da faixa de opções não pode ser a categoria ativa.  
  
 Se a categoria especificada pelo `pCategory` não é exibido, ele não pode ser definido como a categoria de ativa.  
  
##  <a name="a-namesetactivemdichilda--cmfcribbonbarsetactivemdichild"></a><a name="setactivemdichild"></a>CMFCRibbonBar::SetActiveMDIChild  
 Associa os botões de sistema na barra de faixa de opções que pertencem a uma janela filho de interface de documentos múltiplos (MDI) à janela filho MDI especificada.  
  
```  
void SetActiveMDIChild(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWnd`  
 Ponteiro para uma janela filho MDI.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetapplicationbuttona--cmfcribbonbarsetapplicationbutton"></a><a name="setapplicationbutton"></a>CMFCRibbonBar::SetApplicationButton  
 Atribui um botão da faixa de opções de aplicativo para a barra de faixa de opções.  
  
```  
void SetApplicationButton(
    CMFCRibbonApplicationButton* pButton,  
    CSize sizeButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para o botão de faixa de opções do aplicativo.  
  
 [in] `sizeButton`  
 O tamanho do botão de faixa de opções do aplicativo.  
  
### <a name="remarks"></a>Comentários  
 O botão faixa de opções do aplicativo é um grande botão arredondado localizado no canto superior esquerdo do controle de faixa de opções.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetApplicationButton` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&3;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_4.cpp)]  
  
##  <a name="a-namesetelementkeysa--cmfcribbonbarsetelementkeys"></a><a name="setelementkeys"></a>CMFCRibbonBar::SetElementKeys  
 Define as dicas de tela para todos os elementos da faixa de opções com a ID do comando especificado.  
  
```  
BOOL SetElementKeys(
    UINT uiCmdID,  
    LPCTSTR lpszKeys,  
    LPCTSTR lpszMenuKeys= NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 A ID de comando de um elemento de faixa de opções.  
  
 [in] `lpszKeys`  
 A dica de tela.  
  
 [in] `lpszMenuKeys`  
 A dica de tela do menu.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as dicas de tela do elemento de pelo menos uma faixa de opções são definidas; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A dica de tela do menu opcional é para elementos de faixa de opções com um botão de divisão que abre um menu pop-up.  
  
##  <a name="a-namesetkeyboardnavigationlevela--cmfcribbonbarsetkeyboardnavigationlevel"></a><a name="setkeyboardnavigationlevel"></a>CMFCRibbonBar::SetKeyboardNavigationLevel  
 Define o nível de navegação do teclado que o usuário pressiona as dicas de tela que estão contidas na barra de faixa de opções.  
  
```  
void SetKeyboardNavigationLevel(
    CObject* pLevel,  
    BOOL bSetFocus = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pLevel`  
 Ponteiro para o objeto de navegação do teclado atual.  
  
 [in] `bSetFocus`  
 `TRUE`Para definir o foco do teclado para a barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Navegação de teclado da barra de faixa de opções é iniciado quando o usuário pressiona a tecla ALT ou F10. O usuário seleciona o próximo nível de navegação pressionando uma dica de tela na barra de faixa de opções. O usuário pode retornar para o nível de navegação anterior pressionando a tecla escape.  
  
##  <a name="a-namesetmaximizemodea--cmfcribbonbarsetmaximizemode"></a><a name="setmaximizemode"></a>CMFCRibbonBar::SetMaximizeMode  
 Ajusta a faixa de opções da barra quando o tamanho da janela de uma janela filho de interface de documentos múltiplos (MDI) entra ou sai do estado maximizado.  
  
```  
void SetMaximizeMode(
    BOOL bMax,  
    CWnd* pWnd = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bMax`  
 `TRUE`Para exibir os botões de sistema para uma janela de filho MDI na barra de faixa de opções; `FALSE` para remover os botões de sistema para uma janela de filho MDI da barra de faixa de opções.  
  
 [in] `pWnd`  
 Ponteiro para a janela do quadro principal para a barra de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 A barra de faixa de opções exibe botões de sistema para uma janela de filho MDI na linha da guia quando um filho MDI é maximizada.  
  
##  <a name="a-namesetquickaccesscommandsa--cmfcribbonbarsetquickaccesscommands"></a><a name="setquickaccesscommands"></a>CMFCRibbonBar::SetQuickAccessCommands  
 Adiciona um ou mais elementos de faixa de opções para a barra de ferramentas de acesso rápido.  
  
```  
void SetQuickAccessCommands(
    const CList<UINT,UINT>& lstCommands,  
    BOOL bRecalcLayout=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lstCommands`  
 A lista de comandos a serem colocados na barra de ferramentas de acesso rápido.  
  
 [in] `bRecalcLayout`  
 `TRUE`Se deseja redesenhar a faixa de opções depois de adicionar os elementos da faixa de opções; `FALSE` caso contrário.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetQuickAccessCommands` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&8;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_5.cpp)]  
  
##  <a name="a-namesetquickaccessdefaultstatea--cmfcribbonbarsetquickaccessdefaultstate"></a><a name="setquickaccessdefaultstate"></a>CMFCRibbonBar::SetQuickAccessDefaultState  
 Define a barra de ferramentas de acesso rápido para o estado padrão.  
  
```  
void SetQuickAccessDefaultState(const CMFCRibbonQuickAccessToolBarDefaultState& state);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `state`  
 O estado padrão de barra de ferramentas de acesso rápido.  
  
### <a name="remarks"></a>Comentários  
 O estado da barra de ferramentas de acesso rápido inclui uma lista de comandos e sua visibilidade.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetQuickAccessDefaultState` método o `CMFCRibbonBar` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&9;](../../mfc/reference/codesnippet/cpp/cmfcribbonbar-class_6.cpp)]  
  
##  <a name="a-namesetquickaccesstoolbarontopa--cmfcribbonbarsetquickaccesstoolbarontop"></a><a name="setquickaccesstoolbarontop"></a>CMFCRibbonBar::SetQuickAccessToolbarOnTop  
 Posiciona a barra de ferramentas de acesso rápido acima ou abaixo da barra de faixa de opções.  
  
```  
void SetQuickAccessToolbarOnTop(BOOL bOnTop);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bOnTop`  
 `TRUE`para posicionar a barra de ferramentas de acesso rápido acima da barra de faixa de opções; `FALSE` para posicionar a barra de ferramentas de acesso rápido abaixo da barra de faixa de opções.  
  
##  <a name="a-namesettooltipfixedwidtha--cmfcribbonbarsettooltipfixedwidth"></a><a name="settooltipfixedwidth"></a>CMFCRibbonBar::SetTooltipFixedWidth  
 Define os tamanhos normais e grandes de larguras fixas para de barra de faixa de opções de dica de ferramenta.  
  
```  
void SetTooltipFixedWidth(
    int nWidthRegular,  
    int nWidthLargeImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nWidthRegular`  
 A largura, em pixels, de uma dica de ferramenta tamanho fixa regular.  
  
 [in] `nWidthLargeImage`  
 A largura, em pixels, de grande fixo dimensionada dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
 Definindo um parâmetro como 0 faz com que a largura correspondente variar.  
  
##  <a name="a-nameshowcategorya--cmfcribbonbarshowcategory"></a><a name="showcategory"></a>CMFCRibbonBar::ShowCategory  
 Mostra ou oculta a categoria especificada da faixa de opções.  
  
```  
void ShowCategory(
    int nIndex,  
    BOOL bShow=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice da categoria de faixa de opções.  
  
 [in] `bShow`  
 Se `TRUE`, mostrar a categoria de faixa de opções; caso contrário, ocultar a categoria de faixa de opções.  
  
##  <a name="a-nameshowcontextcategoriesa--cmfcribbonbarshowcontextcategories"></a><a name="showcontextcategories"></a>CMFCRibbonBar::ShowContextCategories  
 Mostra ou oculta as categorias de contexto com a ID especificada.  
  
```  
void ShowContextCategories(
    UINT uiContextID,  
    BOOL bShow=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiContextID`  
 A ID da categoria de contexto.  
  
 [in] `bShow`  
 Se `TRUE`, mostrar as categorias que tem a ID especificada; caso contrário, ocultar as categorias que tem a ID especificada.  
  
##  <a name="a-nameshowkeytipsa--cmfcribbonbarshowkeytips"></a><a name="showkeytips"></a>CMFCRibbonBar::ShowKeyTips  
 Mostra dicas de tela para cada elemento da faixa de opções na barra de faixa de opções.  
  
```  
void ShowKeyTips();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nametogglemimimizestatea--cmfcribbonbartogglemimimizestate"></a><a name="togglemimimizestate"></a>CMFCRibbonBar::ToggleMimimizeState  
 Alterna entre os estados maximizadas e minimizados na barra de faixa de opções.  
  
```  
void ToggleMimimizeState();
```  
  
### <a name="remarks"></a>Comentários  
 O problema de ortografia no nome do método é um problema conhecido.  
  
 No estado minimizado, o controle da faixa de opções está oculto e somente as guias são exibidas. Quando o usuário clica em uma guia, o controle da faixa de opções é exibido como uma janela pop-up. A janela é fechada quando o usuário clica fora ou executa um comando.  
  
##  <a name="a-nametranslatechara--cmfcribbonbartranslatechar"></a><a name="translatechar"></a>CMFCRibbonBar::TranslateChar  
 Determina se o código de caractere de pressionamento de tecla especificado é processado pela barra de faixa de opções.  
  
```  
virtual BOOL TranslateChar(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nChar`  
 Um código de caracteres de pressionamento de tecla do usuário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o código de caractere foi processado pela barra de faixa de opções; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O recurso de dicas de tela permite aos usuários navegar a barra de faixa de opções usando o teclado.  
  
##  <a name="a-namegetfocuseda--cmfcribbonbargetfocused"></a><a name="getfocused"></a>CMFCRibbonBar::GetFocused  
 Retorna um elemento focalizado.  
  
```  
virtual CMFCRibbonBaseElement* GetFocused();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento focalizado ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameiswindows7looka--cmfcribbonbariswindows7look"></a><a name="iswindows7look"></a>CMFCRibbonBar::IsWindows7Look  
 Indica se a faixa de opções tem o Windows 7 Pesquisar (botão pequeno aplicativo retangular).  
  
```  
BOOL IsWindows7Look() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a faixa de opções com o Windows 7 examinar; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameloadfromresourcea--cmfcribbonbarloadfromresource"></a><a name="loadfromresource"></a>CMFCRibbonBar::LoadFromResource  
 Sobrecarregado. Carrega uma barra de faixa de opções de recursos do aplicativo.  
  
```  
virtual BOOL LoadFromResource(
    UINT uiXMLResID,  
    LPCTSTR lpszResType = RT_RIBBON,  
    HINSTANCE hInstance = NULL);

 
virtual BOOL LoadFromResource(
    LPCTSTR lpszXMLResID,  
    LPCTSTR lpszResType = RT_RIBBON,  
    HINSTANCE hInstance = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `uiXMLResID`  
 Especifica o recurso de cadeia de caracteres de ID de XML com informações da barra de faixa de opções.  
  
 `lpszResType`  
 Especifica o tipo do recurso localizado em `uiXMLResID`.  
  
 `hInstance`  
 Identificador para o módulo cujo arquivo executável contém o recurso. Se `hInstance` é `NULL`, o sistema carrega o recurso do módulo que foi usado para criar o processo atual.  
  
 `lpszXMLResID`  
 Especifica a ID de recurso (na forma de cadeia de caracteres) com informações da barra de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a carga for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesavetoxmlbuffera--cmfcribbonbarsavetoxmlbuffer"></a><a name="savetoxmlbuffer"></a>CMFCRibbonBar::SaveToXMLBuffer  
 Salva a barra de faixa de opções para um buffer.  
  
```  
UINT SaveToXMLBuffer(LPBYTE* ppBuffer) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppBuffer`  
 Quando essa função retorna, `ppBuffer` aponta para um buffer alocado por esse método e contém informações da barra de faixa de opções em formato XML.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso bem-sucedido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesavetoxmlfilea--cmfcribbonbarsavetoxmlfile"></a><a name="savetoxmlfile"></a>CMFCRibbonBar::SaveToXMLFile  
 Salva a barra de faixa de opções para um arquivo XML.  
  
```  
BOOL SaveToXMLFile(LPCTSTR lpszFilePath) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFilePath`  
 Especifica o arquivo de saída.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso bem-sucedido; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetwindows7looka--cmfcribbonbarsetwindows7look"></a><a name="setwindows7look"></a>CMFCRibbonBar::SetWindows7Look  
 Habilita ou desabilita a aparência do Windows 7 (botão pequeno aplicativo retangular) para a faixa de opções.  
  
```  
void SetWindows7Look(
    BOOL bWindows7Look,  
    BOOL bRecalc = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bWindows7Look`  
 `TRUE`Define a aparência do Windows 7; `FALSE` caso contrário.  
  
 `bRecalc`  
 `TRUE`recalcula o layout de faixa de opções; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPane](../../mfc/reference/cpane-class.md)   
 [Classe de CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md)   
 [Classe CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)   
 [Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)   
 [Passo a passo: Atualizando o aplicativo de rabisco MFC](../../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)




