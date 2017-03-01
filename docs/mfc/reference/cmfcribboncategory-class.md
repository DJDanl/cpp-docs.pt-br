---
title: Classe CMFCRibbonCategory | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonCategory
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonCategory class
ms.assetid: 99ba25b6-d060-4fdd-bfab-3c46c22981bb
caps.latest.revision: 38
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
ms.openlocfilehash: dccbaac6450985f0d5255a790d83f374b52f06f9
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribboncategory-class"></a>Classe de CMFCRibbonCategory
O `CMFCRibbonCategory` classe implementa uma guia faixa de opções que contém um grupo de [painéis da faixa de opções](../../mfc/reference/cmfcribbonpanel-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonCategory : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonCategory::CMFCRibbonCategory](#cmfcribboncategory)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonCategory::AddHidden](#addhidden)|Adiciona um elemento oculto na categoria de faixa de opções.|  
|[CMFCRibbonCategory::AddPanel](#addpanel)|Adiciona um novo painel à categoria de faixa de opções.|  
|[CMFCRibbonCategory::CopyFrom](#copyfrom)||  
|[CMFCRibbonCategory::FindByData](#findbydata)||  
|[CMFCRibbonCategory::FindByID](#findbyid)||  
|[CMFCRibbonCategory::FindPanelWithElem](#findpanelwithelem)||  
|[CMFCRibbonCategory::GetContextID](#getcontextid)|Retorna a ID do contexto da categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetData](#getdata)|Retorna os dados definidos pelo usuário que está associados com a categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetDroppedDown](#getdroppeddown)||  
|[CMFCRibbonCategory::GetElements](#getelements)||  
|[CMFCRibbonCategory::GetElementsByID](#getelementsbyid)||  
|[CMFCRibbonCategory::GetFirstVisibleElement](#getfirstvisibleelement)|Obtenha um primeiro elemento visível que pertencem à categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetFocused](#getfocused)|Retorna um elemento focalizado.|  
|[CMFCRibbonCategory::GetHighlighted](#gethighlighted)|Retorna um elemento realçado.|  
|[CMFCRibbonCategory::GetImageCount](#getimagecount)||  
|[CMFCRibbonCategory::GetImageSize](#getimagesize)||  
|[CMFCRibbonCategory::GetItemIDsList](#getitemidslist)||  
|[CMFCRibbonCategory::GetLastVisibleElement](#getlastvisibleelement)|Obter um último elemento visível que pertencem à categoria de faixa de opções|  
|[CMFCRibbonCategory::GetLargeImages](#getlargeimages)|Retorna uma referência à lista de imagens muito grandes que usa a categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetMaxHeight](#getmaxheight)||  
|[CMFCRibbonCategory::GetName](#getname)||  
|[CMFCRibbonCategory::GetPanel](#getpanel)|Retorna um ponteiro para o painel de faixa de opções está localizado no índice especificado.|  
|[CMFCRibbonCategory::GetPanelCount](#getpanelcount)|Retorna o número de painéis da faixa de opções na categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetPanelFromPoint](#getpanelfrompoint)||  
|[CMFCRibbonCategory::GetPanelIndex](#getpanelindex)|Retorna o índice do painel especificado da faixa de opções.|  
|[CMFCRibbonCategory::GetParentButton](#getparentbutton)||  
|[CMFCRibbonCategory::GetParentMenuBar](#getparentmenubar)||  
|[CMFCRibbonCategory::GetParentRibbonBar](#getparentribbonbar)||  
|[CMFCRibbonCategory::GetRect](#getrect)||  
|[CMFCRibbonCategory::GetSmallImages](#getsmallimages)|Retorna uma referência à lista de imagens pequenas que usa a categoria.|  
|[CMFCRibbonCategory::GetTabColor](#gettabcolor)|Retorna a cor atual da guia categoria de faixa de opções.|  
|[CMFCRibbonCategory::GetTabRect](#gettabrect)||  
|[CMFCRibbonCategory::GetTextTopLine](#gettexttopline)||  
|[CMFCRibbonCategory::GetVisibleElements](#getvisibleelements)|Obter todos os elementos visíveis que pertencem à categoria de faixa de opções.|  
|[CMFCRibbonCategory::HighlightPanel](#highlightpanel)||  
|[CMFCRibbonCategory::HitTest](#hittest)||  
|[CMFCRibbonCategory::HitTestEx](#hittestex)||  
|[CMFCRibbonCategory::HitTestScrollButtons](#hittestscrollbuttons)||  
|[CMFCRibbonCategory::IsActive](#isactive)||  
|[CMFCRibbonCategory::IsVisible](#isvisible)|Determina se a categoria de faixa de opções está visível.|  
|[CMFCRibbonCategory::IsWindows7Look](#iswindows7look)|Indica se a faixa de opções do pai tem a aparência do Windows 7-estilo (botão pequeno aplicativo retangular)|  
|[CMFCRibbonCategory::NotifyControlCommand](#notifycontrolcommand)||  
|[CMFCRibbonCategory::OnCancelMode](#oncancelmode)||  
|[CMFCRibbonCategory::OnDraw](#ondraw)||  
|[CMFCRibbonCategory::OnDrawImage](#ondrawimage)||  
|[CMFCRibbonCategory::OnDrawMenuBorder](#ondrawmenuborder)||  
|[CMFCRibbonCategory::OnKey](#onkey)|Chamado pela estrutura quando o usuário pressionar um botão do teclado.|  
|[CMFCRibbonCategory::OnLButtonDown](#onlbuttondown)||  
|[CMFCRibbonCategory::OnLButtonUp](#onlbuttonup)||  
|[CMFCRibbonCategory::OnMouseMove](#onmousemove)||  
|[CMFCRibbonCategory::OnRTLChanged](#onrtlchanged)||  
|[CMFCRibbonCategory::OnScrollHorz](#onscrollhorz)||  
|[CMFCRibbonCategory::OnUpdateCmdUI](#onupdatecmdui)||  
|[CMFCRibbonCategory::RecalcLayout](#recalclayout)||  
|[CMFCRibbonCategory::RemovePanel](#removepanel)||  
|[CMFCRibbonCategory::ReposPanels](#repospanels)||  
|[CMFCRibbonCategory::SetCollapseOrder](#setcollapseorder)|Define a ordem de recolhimento dos painéis da faixa de opções que estão presentes na categoria de faixa de opções.|  
|[CMFCRibbonCategory::SetData](#setdata)|Armazena os dados definidos pelo usuário na categoria de faixa de opções.|  
|[CMFCRibbonCategory::SetKeys](#setkeys)|Atribui uma dica de tela para a categoria de faixa de opções.|  
|[CMFCRibbonCategory::SetName](#setname)||  
|[CMFCRibbonCategory::SetTabColor](#settabcolor)|Define a cor da categoria de faixa de opções.|  
  
## <a name="remarks"></a>Comentários  
 Normalmente, você cria uma categoria de faixa de opções indiretamente chamando [CMFCRibbonBar::AddCategory](../../mfc/reference/cmfcribbonbar-class.md#addcategory), que retorna um ponteiro para a categoria de faixa de opções recém-criado. Adicionar painéis a categoria chamando [CMFCRibbonCategory::AddPanel](#addpanel).  
  
 O `CMFCRibbonTab` classe desenha categorias de faixa de opções. Ela é derivada de [CMFCRibbonBaseElement classe](../../mfc/reference/cmfcribbonbaseelement-class.md).  
  
 Este exemplo a seguir demonstra como criar uma categoria de faixa de opções e adicionar um painel a ela.  
  
 `// Create a new ribbon category and get a pointer to it`  
  
 `CMFCRibbonCategory* pCategory = m_wndRibbonBar.AddCategory`  
  
 `(_T("&Write"),           // Category name`  
  
 `IDB_WRITE,              // Category small images (16 x 16)`  
  
 `IDB_WRITE_LARGE);   // Category large images (32 x 32)`  
  
 `// Add a panel to the new category`  
  
 `CMFCRibbonPanel* pPanel = pCategory->AddPanel (`  
  
 `_T("Clipboard"),                       // Panel name`  
  
 `m_PanelIcons.ExtractIcon (0));  // Panel icon`  
  
 O diagrama a seguir mostra uma figura da categoria inicial do aplicativo de exemplo RibbonApp.  
  
 ![Imagem de CMFCRibbonCategory](../../mfc/reference/media/cmfcribboncategory.png "cmfcribboncategory")  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMFCRibbonCategory`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribboncategory.h  
  
##  <a name="a-nameaddhiddena--cmfcribboncategoryaddhidden"></a><a name="addhidden"></a>CMFCRibbonCategory::AddHidden  
 Adiciona o elemento de faixa de opções especificadas para a matriz de elementos de faixa de opções que são exibidos na caixa de diálogo de personalização.  
  
```  
void AddHidden(CMFCRibbonBaseElement* pElem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pElem`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Elementos de faixa de opções na caixa de diálogo de personalização são os comandos que você pode adicionar à barra de ferramentas de acesso rápido.  
  
##  <a name="a-nameaddpanela--cmfcribboncategoryaddpanel"></a><a name="addpanel"></a>CMFCRibbonCategory::AddPanel  
 Cria um painel de faixa de opções para a categoria de faixa de opções.  
  
```  
CMFCRibbonPanel* AddPanel(
    LPCTSTR lpszPanelName,  
    HICON hIcon = 0,  
    CRuntimeClass* pRTI = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszPanelName`  
 Ponteiro para o nome do novo painel de faixa de opções.  
  
 [in] `hIcon`  
 Identificador para o ícone padrão para o novo painel de faixa de opções.  
  
 [in] `pRTI`  
 Ponteiro para informações de classe de tempo de execução para um painel de faixa de opções personalizada.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o novo painel de faixa de opções, se o método teve êxito; Caso contrário, `NULL` se o painel não foi criado.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser criar um painel de faixa de opções personalizada, você deve especificar suas informações de classe de tempo de execução no `pRTI`. A classe do painel de faixa de opções personalizada deve ser derivada de `CMFCRibbonPanel` classe.  
  
 O ícone padrão para o painel de faixa de opções é exibido quando não há espaço suficiente para exibir os elementos da faixa de opções.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `AddPanel` método o `CMFCRibbonCategory` classe.  
  
 [!code-cpp[NVC_MFC_RibbonApp n º&10;](../../mfc/reference/codesnippet/cpp/cmfcribboncategory-class_1.cpp)]  
  
##  <a name="a-namecmfcribboncategorya--cmfcribboncategorycmfcribboncategory"></a><a name="cmfcribboncategory"></a>CMFCRibbonCategory::CMFCRibbonCategory  
 Constrói e inicializa um [CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md) objeto.  
  
```  
CMFCRibbonCategory(
    CMFCRibbonBar* pParenrRibbonBar,  
    LPCTSTR lpszName,  
    UINT uiSmallImagesResID,  
    UINT uiLargeImagesResID,  
    CSize sizeSmallImage = CSize(16,
    16),  
    CSize sizeLargeImage = CSize(32,
    32));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParenrRibbonBar`  
 Ponteiro para a barra de faixa de opções do pai da categoria de faixa de opções.  
  
 [in] `lpszName`  
 Nome da categoria de faixa de opções.  
  
 [in] `uiSmallImagesResID`  
 ID de recurso da lista de imagens para imagens pequenas que são usados por elementos de faixa de opções na categoria de faixa de opções.  
  
 [in] `uiLargeImagesResID`  
 ID de recurso da lista de imagens para imagens grandes que são usados por elementos de faixa de opções na categoria de faixa de opções.  
  
 [in] `sizeSmallImage`  
 Tamanho de imagens pequenas para elementos de faixa de opções na categoria de faixa de opções padrão.  
  
 [in] `sizeLargeImage`  
 Tamanho de imagens grandes para elementos de faixa de opções na categoria de faixa de opções padrão.  
  
##  <a name="a-namecopyfroma--cmfcribboncategorycopyfrom"></a><a name="copyfrom"></a>CMFCRibbonCategory::CopyFrom  
 Copia o estado especificado [CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md) atual [CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md) objeto.  
  
```  
virtual void CopyFrom(CMFCRibbonCategory& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
 A fonte `CMFCRibbonCategory` objeto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindbydataa--cmfcribboncategoryfindbydata"></a><a name="findbydata"></a>CMFCRibbonCategory::FindByData  
 Recupera o elemento de faixa de opções associado com os dados especificados.  
  
```  
CMFCRibbonBaseElement* FindByData(
    DWORD_PTR dwData,  
    BOOL bVisibleOnly = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Os dados associados a um elemento de faixa de opções.  
  
 [in] `bVisibleOnly`  
 `TRUE`para incluir elementos de faixa de opções de acesso rápido na pesquisa; `FALSE` para excluir os elementos da faixa de opções de acesso rápido na pesquisa.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindbyida--cmfcribboncategoryfindbyid"></a><a name="findbyid"></a>CMFCRibbonCategory::FindByID  
 Recupera o elemento de faixa de opções associado com a ID de comando especificado.  
  
```  
CMFCRibbonBaseElement* FindByID(
    UINT uiCmdID,  
    BOOL bVisibleOnly = TRUE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 ID de comando associada a um elemento de faixa de opções.  
  
 [in] `bVisibleOnly`  
 `TRUE`para incluir elementos de faixa de opções de acesso rápido na pesquisa; `FALSE` para excluir os elementos da faixa de opções de acesso rápido na pesquisa.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindpanelwithelema--cmfcribboncategoryfindpanelwithelem"></a><a name="findpanelwithelem"></a>CMFCRibbonCategory::FindPanelWithElem  
 Recupera o painel de faixa de opções que contém o elemento especificado da faixa de opções.  
  
```  
CMFCRibbonPanel* FindPanelWithElem(const CMFCRibbonBaseElement* pElement);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pElement`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um painel de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetcontextida--cmfcribboncategorygetcontextid"></a><a name="getcontextid"></a>CMFCRibbonCategory::GetContextID  
 Recupera a ID do contexto da categoria de faixa de opções.  
  
```  
UINT GetContextID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 ID do contexto da categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 A ID do contexto será 0 se a categoria de faixa de opções não é uma categoria de faixa de opções de contexto.  
  
##  <a name="a-namegetdataa--cmfcribboncategorygetdata"></a><a name="getdata"></a>CMFCRibbonCategory::GetData  
 Recupera os dados definidos pelo usuário que está associados com a categoria de faixa de opções.  
  
```  
DWORD_PTR GetData() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados definidos pelo usuário que está associados com a categoria de faixa de opções.  
  
##  <a name="a-namegetdroppeddowna--cmfcribboncategorygetdroppeddown"></a><a name="getdroppeddown"></a>CMFCRibbonCategory::GetDroppedDown  
 Recupera um ponteiro para o elemento de faixa de opções que atualmente possui o menu pop-up exibido.  
  
```  
CMFCRibbonBaseElement* GetDroppedDown();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetelementsa--cmfcribboncategorygetelements"></a><a name="getelements"></a>CMFCRibbonCategory::GetElements  
 Recupera todos os elementos da faixa de opções na categoria de faixa de opções.  
  
```  
void GetElements(
    CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `arElements`  
 Referência a um [CArray](../../mfc/reference/carray-class.md) de elementos da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Elementos de faixa de opções que são projetados para uso na barra de ferramentas de acesso rápido são incluídos na matriz.  
  
##  <a name="a-namegetelementsbyida--cmfcribboncategorygetelementsbyid"></a><a name="getelementsbyid"></a>CMFCRibbonCategory::GetElementsByID  
 Recupera todos os elementos da faixa de opções que estão associados com a ID do comando especificado.  
  
```  
void GetElementsByID(
    UINT uiCmdID,  
    CArray <CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 ID de comando associada a um elemento de faixa de opções.  
  
 [in, out] `arElements`  
 Referência a um [CArray](../../mfc/reference/carray-class.md) de elementos da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Elementos de faixa de opções que são projetados para uso na barra de ferramentas de acesso rápido são incluídos na matriz.  
  
##  <a name="a-namegetfirstvisibleelementa--cmfcribboncategorygetfirstvisibleelement"></a><a name="getfirstvisibleelement"></a>CMFCRibbonCategory::GetFirstVisibleElement  
 Recupera o primeiro elemento visível que pertence à categoria de faixa de opções.  
  
```  
CMFCRibbonBaseElement* GetFirstVisibleElement() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o primeiro elemento visível; pode ser `NULL` se a categoria não tem todos os elementos visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetfocuseda--cmfcribboncategorygetfocused"></a><a name="getfocused"></a>CMFCRibbonCategory::GetFocused  
 Retorna um elemento focalizado.  
  
```  
CMFCRibbonBaseElement* GetFocused();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento focalizado ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegethighlighteda--cmfcribboncategorygethighlighted"></a><a name="gethighlighted"></a>CMFCRibbonCategory::GetHighlighted  
 Retorna um elemento realçado.  
  
```  
CMFCRibbonBaseElement* GetHighlighted();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento realçado ou `NULL` se nenhum elemento é realçado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetimagecounta--cmfcribboncategorygetimagecount"></a><a name="getimagecount"></a>CMFCRibbonCategory::GetImageCount  
 Recupera o número de imagens na lista de imagens especificado contido na categoria de faixa de opções.  
  
```  
int GetImageCount(BOOL bIsLargeImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsLargeImage`  
 `TRUE`o número de imagens na lista de imagens grandes; `FALSE` para o número de imagens na lista imagem pequena.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de imagens na lista imagem especificada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetimagesizea--cmfcribboncategorygetimagesize"></a><a name="getimagesize"></a>CMFCRibbonCategory::GetImageSize  
 Recupera o tamanho de uma imagem na lista de imagens especificado contido na categoria de faixa de opções.  
  
```  
CSize GetImageSize(BOOL bIsLargeImage) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsLargeImage`  
 `TRUE`para o tamanho das imagens grandes; `FALSE` do tamanho das imagens pequenas.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho de uma imagem na lista de imagem especificada.  
  
### <a name="remarks"></a>Comentários  
 O tamanho recuperado inclui o fator de escala da imagem global.  
  
##  <a name="a-namegetitemidslista--cmfcribboncategorygetitemidslist"></a><a name="getitemidslist"></a>CMFCRibbonCategory::GetItemIDsList  
 Recupera as IDs de comando para os elementos da faixa de opções que estão contidos na categoria de faixa de opções.  
  
```  
void GetItemIDsList(
    CList<UINT, UINT>& lstItems,  
    BOOL bHiddenOnly = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lstItems`  
 A lista de IDs de comando para os elementos da faixa de opções na categoria de faixa de opções.  
  
 [in] `bHiddenOnly`  
 `TRUE`Para excluir os elementos de faixa de opções exibidos nos painéis da faixa de opções na categoria de faixa de opções; `FALSE` para incluir todos os elementos da faixa de opções na categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetlargeimagesa--cmfcribboncategorygetlargeimages"></a><a name="getlargeimages"></a>CMFCRibbonCategory::GetLargeImages  
 Recupera a lista de imagens muito grandes que estão contidos na categoria de faixa de opções.  
  
```  
CMFCToolBarImages& GetLargeImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A lista de imagens muito grandes que estão contidos na categoria de faixa de opções.  
  
##  <a name="a-namegetlastvisibleelementa--cmfcribboncategorygetlastvisibleelement"></a><a name="getlastvisibleelement"></a>CMFCRibbonCategory::GetLastVisibleElement  
 Recupera o último elemento visível que pertence à categoria de faixa de opções.  
  
```  
CMFCRibbonBaseElement* GetLastVisibleElement() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o último elemento visível; pode ser `NULL` se a categoria não tem todos os elementos visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetmaxheighta--cmfcribboncategorygetmaxheight"></a><a name="getmaxheight"></a>CMFCRibbonCategory::GetMaxHeight  
 Recupera a altura máxima dos painéis da faixa de opções que estão contidos na categoria de faixa de opções.  
  
```  
int GetMaxHeight(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para os painéis de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura máxima dos painéis da faixa de opções que estão contidos na categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O valor recuperado inclui a altura das margens superior e inferior para os painéis de faixa de opções.  
  
##  <a name="a-namegetnamea--cmfcribboncategorygetname"></a><a name="getname"></a>CMFCRibbonCategory::GetName  
 Recupera o nome da categoria de faixa de opções.  
  
```  
LPCTSTR GetName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome da categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetpanela--cmfcribboncategorygetpanel"></a><a name="getpanel"></a>CMFCRibbonCategory::GetPanel  
 Retorna um ponteiro para o painel de faixa de opções está localizado no índice especificado.  
  
```  
CMFCRibbonPanel* GetPanel(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O índice com base em zero de um painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o painel de faixa de opções está localizado no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção é lançada se `nIndex` está fora do intervalo.  
  
##  <a name="a-namegetpanelcounta--cmfcribboncategorygetpanelcount"></a><a name="getpanelcount"></a>CMFCRibbonCategory::GetPanelCount  
 Retorna o número de painéis da faixa de opções na categoria de faixa de opções.  
  
```  
int GetPanelCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de painéis da faixa de opções na categoria de faixa de opções.  
  
##  <a name="a-namegetpanelfrompointa--cmfcribboncategorygetpanelfrompoint"></a><a name="getpanelfrompoint"></a>CMFCRibbonCategory::GetPanelFromPoint  
 Recupera um ponteiro para um painel de faixa de opções se o ponto especificado está localizado dentro dele.  
  
```  
CMFCRibbonPanel* GetPanelFromPoint(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um painel de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Apenas os painéis de faixa de opções que estão contidos na categoria de faixa de opções são testados.  
  
##  <a name="a-namegetpanelindexa--cmfcribboncategorygetpanelindex"></a><a name="getpanelindex"></a>CMFCRibbonCategory::GetPanelIndex  
 Retorna o índice baseado em zero do painel especificado da faixa de opções.  
  
```  
int GetPanelIndex(const CMFCRibbonPanel* pPanel) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pPanel`  
 Ponteiro para um painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero do painel da faixa de opções especificado se o método teve êxito; Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
 Apenas os painéis de faixa de opções que estão contidos na categoria de faixa de opções são pesquisados.  
  
##  <a name="a-namegetparentbuttona--cmfcribboncategorygetparentbutton"></a><a name="getparentbutton"></a>CMFCRibbonCategory::GetParentButton  
 Recupera o elemento de faixa de opções do pai da categoria de faixa de opções.  
  
```  
CMFCRibbonBaseElement* GetParentButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o elemento de faixa de opções do pai, ou `NULL` se não houver nenhum elemento pai.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetparentmenubara--cmfcribboncategorygetparentmenubar"></a><a name="getparentmenubar"></a>CMFCRibbonCategory::GetParentMenuBar  
 Retorna um ponteiro para a barra de menus do pai do `CMFCRibbonCategory` objeto.  
  
```  
CMFCRibbonPanelMenuBar* GetParentMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o conteúdo da `m_pParentMenuBar` protegido membro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetparentribbonbara--cmfcribboncategorygetparentribbonbar"></a><a name="getparentribbonbar"></a>CMFCRibbonCategory::GetParentRibbonBar  
 Recupera a barra de faixa de opções do pai para a categoria de faixa de opções.  
  
```  
CMFCRibbonBar* GetParentRibbonBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para a barra de faixa de opções do pai para a categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecta--cmfcribboncategorygetrect"></a><a name="getrect"></a>CMFCRibbonCategory::GetRect  
 Recupera o retângulo de exibição para a categoria de faixa de opções.  
  
```  
CRect GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo de exibição para a categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O retângulo de exibição para a categoria de faixa de opções não inclui a guia de categoria.  
  
##  <a name="a-namegetsmallimagesa--cmfcribboncategorygetsmallimages"></a><a name="getsmallimages"></a>CMFCRibbonCategory::GetSmallImages  
 Recupera a lista de imagens pequenas que estão contidos na categoria de faixa de opções.  
  
```  
CMFCToolBarImages& GetSmallImages();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A lista de imagens pequenas que estão contidos na categoria de faixa de opções.  
  
##  <a name="a-namegettabcolora--cmfcribboncategorygettabcolor"></a><a name="gettabcolor"></a>CMFCRibbonCategory::GetTabColor  
 Retorna a cor atual da guia categoria de faixa de opções.  
  
```  
AFX_RibbonCategoryColor GetTabColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor atual da guia categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado pode ser um dos seguintes valores enumerados:  
  
-   AFX_CategoryColor_Red  
  
-   AFX_CategoryColor_Orange  
  
-   AFX_CategoryColor_Yellow  
  
-   AFX_CategoryColor_Green  
  
-   AFX_CategoryColor_Blue  
  
-   AFX_CategoryColor_Indigo  
  
-   AFX_CategoryColor_Violet  
  
##  <a name="a-namegettabrecta--cmfcribboncategorygettabrect"></a><a name="gettabrect"></a>CMFCRibbonCategory::GetTabRect  
 Recupera o retângulo de exibição para a guia de categoria de faixa de opções.  
  
```  
CRect GetTabRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo de exibição para a guia de categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegettexttoplinea--cmfcribboncategorygettexttopline"></a><a name="gettexttopline"></a>CMFCRibbonCategory::GetTextTopLine  
 Recupera o local vertical do texto em botões de faixa de opções na categoria de faixa de opções que exibem imagens grandes.  
  
```  
int GetTextTopLine() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O local vertical do texto, em pixels, botões de faixa de opções que exibem imagens grandes.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetvisibleelementsa--cmfcribboncategorygetvisibleelements"></a><a name="getvisibleelements"></a>CMFCRibbonCategory::GetVisibleElements  
 Recupera todos os elementos visíveis que pertencem à categoria de faixa de opções.  
  
```  
void GetVisibleElements(
    CArray <CMFCRibbonBaseElement*,  
    CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 `arElements`  
 Matriz de todos os elementos visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehighlightpanela--cmfcribboncategoryhighlightpanel"></a><a name="highlightpanel"></a>CMFCRibbonCategory::HighlightPanel  
 Realça o painel de faixa de opções especificadas.  
  
```  
CMFCRibbonPanel* HighlightPanel(
    CMFCRibbonPanel* pHLPanel,  
    CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pHLPanel`  
 Ponteiro para o painel de faixa de opções para realçar.  
  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o painel de faixa de opções realçado anteriormente; Caso contrário, `NULL` se nenhum painel de faixa de opções é realçado quando este método é chamado.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre como realçar um painel de faixa de opções, consulte [CMFCRibbonPanel::Highlight](../../mfc/reference/cmfcribbonpanel-class.md#highlight).  
  
##  <a name="a-namehittesta--cmfcribboncategoryhittest"></a><a name="hittest"></a>CMFCRibbonCategory::HitTest  
 Recupera um ponteiro para um elemento de faixa de opções, se o ponto especificado está localizado dentro dele.  
  
```  
CMFCRibbonBaseElement* HitTest(
    CPoint point,  
    BOOL bCheckPanelCaption = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro do mouse, em relação ao canto superior esquerdo da janela.  
  
 [in] `bCheckPanelCaption`  
 `TRUE`Para testar a legenda do painel de faixa de opções; `FALSE` para excluir a legenda do painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos na categoria de faixa de opções são testados.  
  
##  <a name="a-namehittestexa--cmfcribboncategoryhittestex"></a><a name="hittestex"></a>CMFCRibbonCategory::HitTestEx  
 Recupera o índice com base em zero de um elemento de faixa de opções se o ponto especificado está localizado dentro dele.  
  
```  
int HitTestEx(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro do mouse, em relação ao canto superior esquerdo da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice baseado em zero de um elemento de faixa de opções, se o método teve êxito; Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos na categoria de faixa de opções são testados.  
  
##  <a name="a-namehittestscrollbuttonsa--cmfcribboncategoryhittestscrollbuttons"></a><a name="hittestscrollbuttons"></a>CMFCRibbonCategory::HitTestScrollButtons  
 Se um ponto está dentro de botão de rolagem esquerda ou direita de uma categoria faixa de opções, retorna um ponteiro para esse botão.  
  
```  
CMFCRibbonBaseElement* HitTestScrollButtons(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 O ponto de teste.  
  
### <a name="return-value"></a>Valor de retorno  
 Se `point` cair dentro do retângulo delimitador de tanto à esquerda ou o botão de rolagem à direita da categoria de faixa de opções, retorna um ponteiro para aquele botão ou caso contrário, retornará `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameisactivea--cmfcribboncategoryisactive"></a><a name="isactive"></a>CMFCRibbonCategory::IsActive  
 Indica se a categoria de faixa de opções na categoria ativa na barra de faixa de opções.  
  
```  
BOOL IsActive() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria de faixa de opções é a categoria ativa; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A categoria de faixa de opções ativa exibe seus painéis de faixa de opções.  
  
##  <a name="a-nameisvisiblea--cmfcribboncategoryisvisible"></a><a name="isvisible"></a>CMFCRibbonCategory::IsVisible  
 Indica se a categoria de faixa de opções está visível.  
  
```  
BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria de faixa de opções é visível; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Categorias de faixa de opções que são visíveis exibem uma guia de categoria.  
  
##  <a name="a-nameiswindows7looka--cmfcribboncategoryiswindows7look"></a><a name="iswindows7look"></a>CMFCRibbonCategory::IsWindows7Look  
 Indica se a faixa de opções do pai tem o Windows 7 Pesquisar (botão pequeno aplicativo retangular).  
  
```  
BOOL IsWindows7Look() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a faixa de opções do pai com o Windows 7 examinar; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namenotifycontrolcommanda--cmfcribboncategorynotifycontrolcommand"></a><a name="notifycontrolcommand"></a>CMFCRibbonCategory::NotifyControlCommand  
 Fornece uma mensagem de comando WM_NOTIFY para todos os `CMFCRibbonPanel` elementos de `CMFCRibbonCategory` até que a mensagem é manipulada.  
  
```  
virtual BOOL NotifyControlCommand(
    BOOL bAccelerator,  
    int nNotifyCode,  
    WPARAM wParam,  
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bAccelerator`  
 `TRUE`Se esse comando proveniente de um acelerador, ou `FALSE` caso contrário.  
  
 [in] `nNotifyCode`  
 O código de notificação.  
  
 [in] `wParam`  
 O campo WPARAM da mensagem.  
  
 [in] `lParam`  
 O campo LPARAM da mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se a mensagem foi tratada, ou `FALSE` se não for.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameoncancelmodea--cmfcribboncategoryoncancelmode"></a><a name="oncancelmode"></a>CMFCRibbonCategory::OnCancelMode  
 Invoca modo Cancelar em todos os `CMFCRibbonPanel` elementos do `CMFCRibbonCategory`.  
  
```  
virtual void OnCancelMode();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawa--cmfcribboncategoryondraw"></a><a name="ondraw"></a>CMFCRibbonCategory::OnDraw  
 Chamado pela estrutura para desenhar a categoria de faixa de opções.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para a categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawimagea--cmfcribboncategoryondrawimage"></a><a name="ondrawimage"></a>CMFCRibbonCategory::OnDrawImage  
 Chamado pela estrutura para desenhar a imagem especificada na categoria de faixa de opções.  
  
```  
virtual BOOL OnDrawImage(
    CDC* pDC,  
    CRect rect,  
    CMFCRibbonBaseElement* pElement,  
    BOOL bIsLargeImage,  
    BOOL nImageIndex,  
    BOOL bCenter);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para a imagem.  
  
 [in] `rect`  
 Retângulo de exibição da imagem.  
  
 [in] `pElement`  
 Ponteiro para o elemento de faixa de opções que contém a imagem.  
  
 [in] `bIsLargeImage`  
 `TRUE`Se a imagem é o tamanho grande. `FALSE` se a imagem é o tamanho pequeno.  
  
 [in] `nImageIndex`  
 Índice baseado em zero da imagem na matriz de imagem que está contida na categoria de faixa de opções.  
  
 [in] `bCenter`  
 `TRUE`para centralizar a imagem no retângulo de exibição; `FALSE` para desenhar a imagem no canto superior esquerdo do retângulo de exibição.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o método teve êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameondrawmenubordera--cmfcribboncategoryondrawmenuborder"></a><a name="ondrawmenuborder"></a>CMFCRibbonCategory::OnDrawMenuBorder  
 Chamado pela estrutura para desenhar a borda de um menu pop-up.  
  
```  
virtual void OnDrawMenuBorder(
    CDC* pDC,  
    CMFCRibbonPanelMenuBar* pMenuBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Este parâmetro não é usado.  
  
 [in] `pMenuBar`  
 Este parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada. Substitua este método para desenhar a borda de um menu pop-up.  
  
##  <a name="a-nameonkeya--cmfcribboncategoryonkey"></a><a name="onkey"></a>CMFCRibbonCategory::OnKey  
 Chamado pela estrutura quando o usuário pressionar um botão do teclado.  
  
```  
virtual BOOL OnKey(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nChar`  
 O código de tecla virtual para a chave que o usuário pressionou.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonlbuttondowna--cmfcribboncategoryonlbuttondown"></a><a name="onlbuttondown"></a>CMFCRibbonCategory::OnLButtonDown  
 Chamado pela estrutura para recuperar o elemento de faixa de opções no ponto especificado quando o usuário pressiona o botão esquerdo do mouse.  
  
```  
virtual CMFCRibbonBaseElement* OnLButtonDown(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro do mouse, em relação ao canto superior esquerdo da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonlbuttonupa--cmfcribboncategoryonlbuttonup"></a><a name="onlbuttonup"></a>CMFCRibbonCategory::OnLButtonUp  
 Chamado pela estrutura quando o usuário libera o botão esquerdo do mouse e o ponteiro está sobre a categoria de faixa de opções.  
  
```  
virtual void OnLButtonUp(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonmousemovea--cmfcribboncategoryonmousemove"></a><a name="onmousemove"></a>CMFCRibbonCategory::OnMouseMove  
 Chamado pela estrutura quando o ponteiro passa sobre a barra de faixa de opções para atualizar a exibição de categoria de faixa de opções.  
  
```  
virtual void OnMouseMove(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonrtlchangeda--cmfcribboncategoryonrtlchanged"></a><a name="onrtlchanged"></a>CMFCRibbonCategory::OnRTLChanged  
 Chamado pela estrutura quando o layout muda de direção.  
  
```  
virtual void OnRTLChanged(BOOL bIsRTL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsRTL`  
 `TRUE`Se o layout é da direita para esquerda; `FALSE` se o layout é à esquerda para a direita.  
  
### <a name="remarks"></a>Comentários  
 Esse método ajusta o layout de todos os painéis de faixa de opções e elementos de faixa de opções que estão contidos na categoria de faixa de opções.  
  
##  <a name="a-nameonscrollhorza--cmfcribboncategoryonscrollhorz"></a><a name="onscrollhorz"></a>CMFCRibbonCategory::OnScrollHorz  
 Rola a categoria de faixa de opções na direção horizontal.  
  
```  
virtual BOOL OnScrollHorz(
    BOOL bScrollLeft,  
    int nScrollOffset = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bScrollLeft`  
 `TRUE`para rolar para a esquerda; `FALSE` para rolar para a direita.  
  
 [in] `nScrollOffset`  
 A distância de rolagem em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a categoria de faixa de opções é movido na direção horizontal; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonupdatecmduia--cmfcribboncategoryonupdatecmdui"></a><a name="onupdatecmdui"></a>CMFCRibbonCategory::OnUpdateCmdUI  
 Chamadas a `OnUpdateCmdUI` função de membro em cada um do `CMFCRibbonPanel` elementos do `CMFCRibbonCategory` para habilitar ou desabilitar os elementos de interface do usuário neles.  
  
```  
virtual void OnUpdateCmdUI(
    CMFCRibbonCmdUI* pCmdUI,  
    CFrameWnd* pTarget,  
    BOOL bDisableIfNoHndler);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pCmdUI`  
 Ponteiro para o `CMFCRibbonCmdUI` objeto que especifica quais elementos de interface do usuário deverão ser habilitados e que devem ser desabilitados.  
  
 [in] `pTarget`  
 Ponteiro para a janela que controla a ativação ou desativação dos elementos de interface do usuário.  
  
 [in] `bDisableIfNoHndler`  
 `TRUE`Para desabilitar o item de interface do usuário se nenhum manipulador é definido em um mapa da mensagem; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namerecalclayouta--cmfcribboncategoryrecalclayout"></a><a name="recalclayout"></a>CMFCRibbonCategory::RecalcLayout  
 Ajusta o layout de todos os controles na categoria de faixa de opções.  
  
```  
virtual void RecalcLayout(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para a categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameremovepanela--cmfcribboncategoryremovepanel"></a><a name="removepanel"></a>CMFCRibbonCategory::RemovePanel  
 Remove um painel de faixa de opções da categoria de faixa de opções.  
  
```cpp  
BOOL RemovePanel(
    int nIndex,  
    BOOL bDelete = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 O número de índice do painel para remover. Obtido chamando o [CMFCRibbonCategory::GetPanelIndex](#getpanelindex) método.  
  
 [in] `bDelete`  
 `TRUE`Para excluir o objeto do painel de memória. `FALSE` para remover o objeto do painel sem excluí-la.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` caso o método tenha sido bem-sucedido; do contrário, `FALSE`.  
  
##  <a name="a-namerepospanelsa--cmfcribboncategoryrepospanels"></a><a name="repospanels"></a>CMFCRibbonCategory::ReposPanels  
 Ajusta o layout de todos os controles em painéis da faixa de opções que estão contidos na categoria de faixa de opções.  
  
```  
virtual void ReposPanels(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para os painéis de faixa de opções que estão contidos na categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetcollapseordera--cmfcribboncategorysetcollapseorder"></a><a name="setcollapseorder"></a>CMFCRibbonCategory::SetCollapseOrder  
 Define a ordem na qual recolher os painéis de faixa de opções da categoria de faixa de opções.  
  
```  
void SetCollapseOrder(const CArray<int,int>& arCollapseOrder);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `arCollapseOrder`  
 Especifica a ordem de recolhimento. A matriz contém índices com base em zero de painéis da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 A biblioteca define a ordem de recolhimento. No entanto, você pode personalizar esse comportamento, fornecendo a categoria com a lista de índices que especifica a ordem de recolhimento.  
  
 Quando a categoria detecta que ele precisa recolher um painel de faixa de opções, ele procura o próximo elemento na lista especificada. Se a lista estiver vazia, ou você não especificou elementos suficientes, a categoria usa o algoritmo interno.  
  
 Por exemplo, a categoria tem três painéis da faixa de opções e pode ser recolhida várias vezes até que todos os painéis estiverem no estado recolhido totalmente. Você pode definir a ordem de recolher a seguir: 0, 0, 2, 2. Nesse caso, a categoria recolher o painel 0 duas vezes, o painel 2 duas vezes. O painel que possui o índice de 1 permanece expandido.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SetCollapseOrder` método o `CMFCRibbonCategory` classe. O exemplo mostra como criar uma matriz para a ordem de recolhimento e como definir a ordem de recolher à categoria de faixa de opções.  
  
 [!code-cpp[NVC_MFC_RibbonApp&13;](../../mfc/reference/codesnippet/cpp/cmfcribboncategory-class_2.cpp)]  
  
##  <a name="a-namesetdataa--cmfcribboncategorysetdata"></a><a name="setdata"></a>CMFCRibbonCategory::SetData  
 Define os dados definidos pelo usuário a serem associados à categoria de faixa de opções.  
  
```  
void SetData(DWORD_PTR dwData);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Os dados definidos pelo usuário.  
  
##  <a name="a-namesetkeysa--cmfcribboncategorysetkeys"></a><a name="setkeys"></a>CMFCRibbonCategory::SetKeys  
 Atribui uma dica de tela para a categoria de faixa de opções.  
  
```  
void SetKeys(LPCTSTR lpszKeys);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszKeys`  
 O texto de dica de tela.  
  
### <a name="remarks"></a>Comentários  
 Dicas de tela são exibidas quando o usuário pressiona a tecla Alt ou a tecla F10.  
  
##  <a name="a-namesetnamea--cmfcribboncategorysetname"></a><a name="setname"></a>CMFCRibbonCategory::SetName  
 Atribui um nome e uma dica de tela para a categoria de faixa de opções.  
  
```  
void SetName(LPCTSTR lpszName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome e a dica de tela da categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Para definir a dica de tela para a categoria de faixa de opções, acrescentar uma sequência de escape newline seguida pelos caracteres dica para `lpszName`.  
  
##  <a name="a-namesettabcolora--cmfcribboncategorysettabcolor"></a><a name="settabcolor"></a>CMFCRibbonCategory::SetTabColor  
 Define a cor da categoria de faixa de opções.  
  
```  
void SetTabColor(AFX_RibbonCategoryColor color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 Especifica a nova cor da categoria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Cor pode ser um dos seguintes valores:  
  
-   AFX_CategoryColor_None  
  
-   AFX_CategoryColor_Red  
  
-   AFX_CategoryColor_Orange  
  
-   AFX_CategoryColor_Yellow  
  
-   AFX_CategoryColor_Green  
  
-   AFX_CategoryColor_Blue  
  
-   AFX_CategoryColor_Indigo  
  
-   AFX_CategoryColor_Violet  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)

