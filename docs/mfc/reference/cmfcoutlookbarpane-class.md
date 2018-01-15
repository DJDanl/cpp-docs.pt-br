---
title: Classe CMFCOutlookBarPane | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCOutlookBarPane
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::AddButton
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::CanBeAttached
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::ClearAll
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::Create
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::EnablePageScrollMode
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::GetRegularColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::IsBackgroundTexture
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::IsDrawShadedHighlight
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::RemoveButton
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetBackColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetBackImage
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetDefaultState
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetExtraSpace
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetTextColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::SetTransparentColor
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::EnableContextMenuItems
- AFXOUTLOOKBARPANE/CMFCOutlookBarPane::RemoveAllButtons
dev_langs: C++
helpviewer_keywords:
- CMFCOutlookBarPane [MFC], AddButton
- CMFCOutlookBarPane [MFC], CanBeAttached
- CMFCOutlookBarPane [MFC], ClearAll
- CMFCOutlookBarPane [MFC], Create
- CMFCOutlookBarPane [MFC], EnablePageScrollMode
- CMFCOutlookBarPane [MFC], GetRegularColor
- CMFCOutlookBarPane [MFC], IsBackgroundTexture
- CMFCOutlookBarPane [MFC], IsDrawShadedHighlight
- CMFCOutlookBarPane [MFC], RemoveButton
- CMFCOutlookBarPane [MFC], SetBackColor
- CMFCOutlookBarPane [MFC], SetBackImage
- CMFCOutlookBarPane [MFC], SetDefaultState
- CMFCOutlookBarPane [MFC], SetExtraSpace
- CMFCOutlookBarPane [MFC], SetTextColor
- CMFCOutlookBarPane [MFC], SetTransparentColor
- CMFCOutlookBarPane [MFC], EnableContextMenuItems
- CMFCOutlookBarPane [MFC], RemoveAllButtons
ms.assetid: 094e2ef3-a118-487e-a4cc-27626108fe08
caps.latest.revision: "30"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 59eb92e44a26577866a797243f3a32d53b854365
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcoutlookbarpane-class"></a>Classe CMFCOutlookBarPane
[!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
 Um controle derivado de [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) que podem ser inseridos em uma barra do Outlook ( [CMFCOutlookBar classe](../../mfc/reference/cmfcoutlookbar-class.md)). Painel da barra do Outlook contém uma coluna de botões grandes. O usuário pode rolar a lista de botões para cima e se ele for maior que o painel. Quando o usuário desanexa um painel da barra Outlook da barra do Outlook, ele pode float ou encaixar na janela do quadro principal.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCOutlookBarPane : public CMFCToolBar  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCOutlookBarPane::CMFCOutlookBarPane`|Construtor padrão.|  
|`CMFCOutlookBarPane::~CMFCOutlookBarPane`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCOutlookBarPane::AddButton](#addbutton)|Adiciona um botão no painel de barra do Outlook.|  
|[CMFCOutlookBarPane::CanBeAttached](#canbeattached)|Determina se o painel pode ser encaixado outra janela do painel ou quadro. (Substitui [CBasePane::CanBeAttached](../../mfc/reference/cbasepane-class.md#canbeattached).)|  
|`CMFCOutlookBarPane::CanBeRestored`|Determina se o sistema pode restaurar uma barra de ferramentas para seu estado original após a personalização. (Substitui [CMFCToolBar::CanBeRestored](../../mfc/reference/cmfctoolbar-class.md#canberestored).)|  
|[CMFCOutlookBarPane::ClearAll](#clearall)|Libera os recursos usados por imagens no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::Create](#create)|Cria um painel da barra do Outlook.|  
|`CMFCOutlookBarPane::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCOutlookBarPane::Dock`|Chamado pelo framework para encaixar o painel da barra do Outlook. (Substitui `CPane::Dock`.)|  
|[CMFCOutlookBarPane::EnablePageScrollMode](#enablepagescrollmode)|Especifica se as setas de rolagem no painel da barra do Outlook Avançar a lista de botões de página ou botão.|  
|[CMFCOutlookBarPane::GetRegularColor](#getregularcolor)|Retorna a cor de texto normal (não selecionado) do painel da barra do Outlook.|  
|`CMFCOutlookBarPane::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCOutlookBarPane::IsBackgroundTexture](#isbackgroundtexture)|Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.|  
|`CMFCOutlookBarPane::IsChangeState`|Determina se um painel flutuante que pode ser encaixado. (Substitui `CPane::IsChangeState`.)|  
|[CMFCOutlookBarPane::IsDrawShadedHighlight](#isdrawshadedhighlight)|Determina se a borda do botão é sombreada quando um botão é realçado e uma imagem de plano de fundo é exibida.|  
|`CMFCOutlookBarPane::OnBeforeFloat`|Chamado pelo framework quando um painel está prestes a float. (Substitui [CPane::OnBeforeFloat](../../mfc/reference/cpane-class.md#onbeforefloat).)|  
|[CMFCOutlookBarPane::RemoveButton](#removebutton)|Remove o botão que tem uma ID de comando especificado.|  
|`CMFCOutlookBarPane::RestoreOriginalstate`|Restaura o estado original de uma barra de ferramentas. (Substitui [CMFCToolBar::RestoreOriginalState](../../mfc/reference/cmfctoolbar-class.md#restoreoriginalstate).)|  
|[CMFCOutlookBarPane::SetBackColor](#setbackcolor)|Define a cor de plano de fundo.|  
|[CMFCOutlookBarPane::SetBackImage](#setbackimage)|Define a imagem de plano de fundo.|  
|[CMFCOutlookBarPane::SetDefaultState](#setdefaultstate)|Redefine o painel da barra do Outlook para o conjunto original de botões.|  
|[CMFCOutlookBarPane::SetExtraSpace](#setextraspace)|Define o número de pixels de preenchimento usado em torno de botões no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::SetTextColor](#settextcolor)|Define as cores de texto normal e realçado no painel da barra do Outlook.|  
|[CMFCOutlookBarPane::SetTransparentColor](#settransparentcolor)|Define a cor transparente para o painel da barra do Outlook.|  
|`CMFCOutlookBarPane::SmartUpdate`|Usada internamente para atualizar a barra do Outlook. (Substitui `CMFCToolBar::SmartUpdate`.)|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCOutlookBarPane::EnableContextMenuItems](#enablecontextmenuitems)|Especifica quais itens de menu de atalho são exibidos no modo de personalização.|  
|[CMFCOutlookBarPane::RemoveAllButtons](#removeallbuttons)|Remove todos os botões do painel da barra do Outlook. (Substitui [CMFCToolBar::RemoveAllButtons](../../mfc/reference/cmfctoolbar-class.md#removeallbuttons).)|  
  
## <a name="remarks"></a>Comentários  
 Para obter informações sobre como implementar uma barra do Outlook, consulte [CMFCOutlookBar classe](../../mfc/reference/cmfcoutlookbar-class.md).  
  
 Para obter um exemplo de uma barra do Outlook, consulte o projeto de exemplo OutlookDemo.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos para o `CMFCOutlookBarPane` classe. O exemplo mostra como criar um painel de barra do Outlook, habilitar o modo de rolagem de página, encaixe e definir a cor de plano de fundo da barra do Outlook. Este trecho de código é parte do [exemplo Outlook várias exibições](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_OutlookMultiViews#3](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_1.h)]  
[!code-cpp[NVC_MFC_OutlookMultiViews#4](../../mfc/reference/codesnippet/cpp/cmfcoutlookbarpane-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCBaseToolBar](../../mfc/reference/cmfcbasetoolbar-class.md)  
  
 [CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)  
  
 [CMFCOutlookBarPane](../../mfc/reference/cmfcoutlookbarpane-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxoutlookbarpane.h  
  
##  <a name="addbutton"></a>CMFCOutlookBarPane::AddButton  
 Adiciona um botão no painel de barra do Outlook.  
  
```  
BOOL AddButton(
    UINT uiImage,  
    LPCTSTR lpszLabel,  
    UINT iIdCommand,  
    int iInsertAt=-1);

 
BOOL AddButton(
    UINT uiImage,  
    UINT uiLabel,  
    UINT iIdCommand,  
    int iInsertAt=-1);

 
BOOL AddButton(
    LPCTSTR szBmpFileName,  
    LPCTSTR szLabel,  
    UINT iIdCommand,  
    int iInsertAt=-1);

 
BOOL AddButton(
    HBITMAP hBmp,  
    LPCTSTR lpszLabel,  
    UINT iIdCommand,  
    int iInsertAt=-1);

 
BOOL AddButton(
    HICON hIcon,  
    LPCTSTR lpszLabel,  
    UINT iIdCommand,  
    int iInsertAt=-1,  
    BOOL bAlphaBlend=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiImage`  
 Especifica o identificador do recurso de um bitmap.  
  
 [in] `lpszLabel`  
 Especifica o texto do botão.  
  
 [in] `iIdCommand`  
 Especifica a identificação. do controle de botão  
  
 [in] `iInsertAt`  
 Especifica o índice de base zero na página da barra do outlook no qual inserir o botão.  
  
 [in] `uiLabel`  
 Uma ID de recurso de cadeia de caracteres.  
  
 [in] `szBmpFileName`  
 Especifica o nome do arquivo de imagem de disco para carregar.  
  
 [in] `szLabel`  
 Especifica o texto do botão.  
  
 [in] `hBmp`  
 Um identificador para o bitmap do botão.  
  
 [in] `hIcon`  
 Um identificador para o ícone dos botões.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se um botão foi adicionado com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para inserir um novo botão página da barra uma. Imagem do botão pode ser carregada a partir dos recursos de aplicativo ou de um arquivo de disco.  
  
 Se a ID de página especificado pelo `uiPageID` é -1, o botão é inserido na primeira página.  
  
 Se o índice especificado pelo `iInsertAt` é -1, o botão é adicionado ao final da página.  
  
##  <a name="canbeattached"></a>CMFCOutlookBarPane::CanBeAttached  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL CanBeAttached() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="clearall"></a>CMFCOutlookBarPane::ClearAll  
 Libera os recursos usados por imagens no painel da barra do Outlook.  
  
```  
void ClearAll();
```  
  
### <a name="remarks"></a>Comentários  
 Este método chama diretamente [CMFCToolBarImages::Clear](../../mfc/reference/cmfctoolbarimages-class.md#clear), que é chamado em imagens que são usadas pelo painel da barra do Outlook.  
  
##  <a name="create"></a>CMFCOutlookBarPane::Create  
 Cria um painel da barra do Outlook.  
  
```  
virtual BOOL Create(
    CWnd* pParentWnd,  
    DWORD dwStyle=AFX_DEFAULT_TOOLBAR_STYLE,  
    UINT uiID=(UINT)-1,  
    DWORD dwControlBarStyle=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentWnd`  
 Especifica a janela pai do controle de painel de barra do Outlook. Não deve ser `NULL`.  
  
 [in] `dwStyle`  
 O estilo da janela.  Para obter uma lista de estilos de janela, consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).  
  
 [in] `uiID`  
 A ID do controle. Deve ser exclusivo para habilitar o salvamento do estado do controle.  
  
 [in] `dwControlBarStyle`  
 Especifica os estilos especiais que definem o comportamento do controle de painel barra Outlook quando ela é desanexada da barra do Outlook.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Para construir um `CMFCOutlookBarPane` do objeto, primeiro chame o construtor e, em seguida, chamar `Create`, que cria o controle do painel da barra do Outlook e anexa-o para o `CMFCOutlookBarPane` objeto.  
  
 Para obter mais informações sobre `dwControlBarStyle` consulte [CBasePane::CreateEx](../../mfc/reference/cbasepane-class.md#createex).  
  
##  <a name="enablecontextmenuitems"></a>CMFCOutlookBarPane::EnableContextMenuItems  
 Especifica quais itens de menu de atalho são exibidos no modo de personalização.  
  
```  
virtual BOOL EnableContextMenuItems(
    CMFCToolBarButton* pButton,  
    CMenu* pPopup);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para um botão de barra de ferramentas que um usuário clicou.  
  
 [in] `pPopup`  
 Um ponteiro para o menu de atalho.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o menu de atalho deve ser exibido; caso contrário `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para modificar o menu de atalho padrão do framework que exibe a estrutura no modo de personalização.  
  
 A implementação padrão verifica o modo de personalização ( [CMFCToolBar::IsCustomizeMode](../../mfc/reference/cmfctoolbar-class.md#iscustomizemode)) e se ele está definido como `TRUE`, desabilita todos os itens de menu de atalho exceto **excluir**. Em seguida, ela apenas transmite os parâmetros de entrada para `CMFCToolBar::EnableContextMenuItems`.  
  
> [!NOTE]
> *Menu de contexto* é um sinônimo para o menu de atalho.  
  
##  <a name="enablepagescrollmode"></a>CMFCOutlookBarPane::EnablePageScrollMode  
 Especifica se as setas de rolagem no painel da barra do Outlook Avançar a lista de botões de página por página, ou pelo botão.  
  
```  
void EnablePageScrollMode(BOOL bPageScroll=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bPageScroll`  
 Se `TRUE`, habilite o modo de rolagem de página. Se `FALSE`, desabilite o modo de rolagem de página.  
  
##  <a name="getregularcolor"></a>CMFCOutlookBarPane::GetRegularColor  
 Retorna o regular (ou seja, não selecionadas) cor do texto do painel da barra do Outlook.  
  
```  
DECLARE_MESSAGE_MAPCOLORREF GetRegularColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do texto como um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Use [CMFCOutlookBarPane::SetTextColor](#settextcolor) para definir a cor do texto (regulares e selecionado) da barra do Outlook. Você pode obter a cor de texto padrão chamando o [GetSysColor](http://msdn.microsoft.com/library/windows/desktop/ms724371) funcionar com o `COLOR_WINDOW` índice.  
  
##  <a name="isbackgroundtexture"></a>CMFCOutlookBarPane::IsBackgroundTexture  
 Determina se há uma imagem de plano de fundo carregada para o painel da barra do Outlook.  
  
```  
BOOL IsBackgroundTexture() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se não houver imagem de plano de fundo para exibir; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode adicionar uma imagem de plano de fundo chamando [CMFCOutlookBarPane::SetBackImage](#setbackimage) função.  
  
 Se não houver nenhuma imagem de plano de fundo, o plano de fundo é pintado com uma cor especificada usando [CMFCOutlookBarPane::SetBackColor](#setbackcolor).  
  
##  <a name="isdrawshadedhighlight"></a>CMFCOutlookBarPane::IsDrawShadedHighlight  
 Determina se a borda do botão é sombreada quando um botão é realçado e uma imagem de plano de fundo é exibida.  
  
```  
BOOL IsDrawShadedHighlight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as bordas do botão são sombreadas; Caso contrário, `FALSE`.  
  
##  <a name="removeallbuttons"></a>CMFCOutlookBarPane::RemoveAllButtons  
 Remove todos os botões do painel da barra do Outlook.  
  
```  
virtual void RemoveAllButtons();
```  
  
##  <a name="removebutton"></a>CMFCOutlookBarPane::RemoveButton  
 Remove o botão que tem uma ID de comando especificado.  
  
```  
BOOL RemoveButton(UINT iIdCommand);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIdCommand`  
 Especifica a ID de um botão de comando para remover.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão foi removido com êxito; `FALSE` se a ID de comando especificado não é válida.  
  
##  <a name="setbackcolor"></a>CMFCOutlookBarPane::SetBackColor  
 Define a cor de plano de fundo da barra do Outlook.  
  
```  
void SetBackColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 Especifica a nova cor do plano de fundo.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir a cor de plano de fundo atual para a barra do Outlook. A cor de plano de fundo é usada somente se não houver nenhuma imagem de plano de fundo.  
  
##  <a name="setbackimage"></a>CMFCOutlookBarPane::SetBackImage  
 Define a imagem de plano de fundo.  
  
```  
void SetBackImage(UINT uiImageID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiImageID`  
 Especifica a ID de recurso de imagem.  
  
### <a name="remarks"></a>Comentários  
 Chame este método para definir o Outlook imagem de plano de fundo da barra. A lista de imagens de plano de fundo é gerenciada pelo embedded [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md) objeto.  
  
##  <a name="setdefaultstate"></a>CMFCOutlookBarPane::SetDefaultState  
 Redefine o painel da barra do Outlook para o conjunto original de botões.  
  
```  
void SetDefaultState();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método restaura os botões da barra do Outlook para o conjunto original. Esse método é como `CMFCOutlookBarPane::RestoreOriginalstate`, exceto que ela não dispare uma atualização do painel da barra do Outlook.  
  
##  <a name="setextraspace"></a>CMFCOutlookBarPane::SetExtraSpace  
 Define o número de pixels de preenchimento usado em torno de botões no painel da barra do Outlook.  
  
```  
void SetExtraSpace()  
```  
  
##  <a name="settextcolor"></a>CMFCOutlookBarPane::SetTextColor  
 Define as cores de texto normal e realçado no painel da barra do Outlook.  
  
```  
void SetTextColor(
    COLORREF clrRegText,  
    COLORREF clrSelText=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `clrRegText`  
 Especifica a nova cor do texto não selecionado.  
  
 [in] `clrSelText`  
 Especifica a nova cor do texto selecionado.  
  
##  <a name="settransparentcolor"></a>CMFCOutlookBarPane::SetTransparentColor  
 Define a cor transparente para o painel da barra do Outlook.  
  
```  
void SetTransparentColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Especifica a nova cor transparente.  
  
### <a name="remarks"></a>Comentários  
 A cor transparente é necessária para exibir imagens transparentes. Qualquer ocorrência desta cor em uma imagem é pintada com a cor de plano de fundo em vez disso.  Não há nenhuma combinação de imagens de plano de fundo e do primeiro plano.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCOutlookBar](../../mfc/reference/cmfcoutlookbar-class.md)   
 [Classe CMFCOutlookBarTabCtrl](../../mfc/reference/cmfcoutlookbartabctrl-class.md)
