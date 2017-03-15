---
title: Classe CMFCRibbonPanel | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonPanel
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonPanel class
ms.assetid: 51d70749-1140-4386-b103-f14082049ba6
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
ms.openlocfilehash: 1f833e1fa59f733734da321718d5db73377fa4bd
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbonpanel-class"></a>Classe CMFCRibbonPanel
Implementa um painel que contém um conjunto de elementos da faixa de opções. Quando o painel é desenhado, ele exibe quantos elementos possível, dado o tamanho do painel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonPanel : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonPanel::CMFCRibbonPanel](#cmfcribbonpanel)|Constrói e inicializa um objeto `CMFCRibbonPanel`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonPanel::Add](#add)|Adiciona um elemento de faixa de opções no painel.|  
|[CMFCRibbonPanel::AddSeparator](#addseparator)|Adiciona um separador no painel de faixa de opções.|  
|[CMFCRibbonPanel::AddToolBar](#addtoolbar)|Adiciona uma barra de ferramentas no painel de faixa de opções.|  
|[CMFCRibbonPanel::FindByData](#findbydata)||  
|[CMFCRibbonPanel::FindByID](#findbyid)|Retorna um elemento identificado por uma ID de comando especificado.|  
|[CMFCRibbonPanel::GetCaptionHeight](#getcaptionheight)||  
|[CMFCRibbonPanel::GetCount](#getcount)|Retorna o número de elementos no painel de faixa de opções.|  
|[CMFCRibbonPanel::GetData](#getdata)|Retorna os dados definidos pelo usuário associados com o painel.|  
|[CMFCRibbonPanel::GetDefaultButton](#getdefaultbutton)||  
|[CMFCRibbonPanel::GetDroppedDown](#getdroppeddown)||  
|[CMFCRibbonPanel::GetElement](#getelement)|Retorna o elemento de faixa de opções, localizado em um índice especificado.|  
|[CMFCRibbonPanel::GetElements](#getelements)|Recupera todos os elementos que estão contidos no painel da faixa de opções.|  
|[CMFCRibbonPanel::GetElementsByID](#getelementsbyid)||  
|[CMFCRibbonPanel::GetFocused](#getfocused)|Retorna um elemento focalizado.|  
|[CMFCRibbonPanel::GetGalleryRect](#getgalleryrect)|Retorna um retângulo delimitador do elemento da Galeria.|  
|[CMFCRibbonPanel::GetHighlighted](#gethighlighted)||  
|[CMFCRibbonPanel::GetIndex](#getindex)||  
|[CMFCRibbonPanel::GetItemIDsList](#getitemidslist)||  
|[CMFCRibbonPanel::GetName](#getname)||  
|[CMFCRibbonPanel::GetParentButton](#getparentbutton)||  
|[CMFCRibbonPanel::GetParentCategory](#getparentcategory)|Retorna a categoria pai do painel da faixa de opções.|  
|[CMFCRibbonPanel::GetParentMenuBar](#getparentmenubar)||  
|[CMFCRibbonPanel::GetPreferedMenuLocation](#getpreferedmenulocation)||  
|[CMFCRibbonPanel::GetPressed](#getpressed)||  
|[CMFCRibbonPanel::GetRect](#getrect)||  
|[CMFCRibbonPanel::GetVisibleElements](#getvisibleelements)|Obtém uma matriz de elementos visíveis.|  
|[CMFCRibbonPanel::HasElement](#haselement)||  
|[CMFCRibbonPanel::HitTest](#hittest)||  
|[CMFCRibbonPanel::HitTestEx](#hittestex)||  
|[CMFCRibbonPanel::Insert](#insert)|Insere um elemento de faixa de opções na posição especificada.|  
|[CMFCRibbonPanel::InsertSeparator](#insertseparator)|Insere um separador na posição especificada.|  
|[CMFCRibbonPanel::IsCenterColumnVert](#iscentercolumnvert)|Especifica se todos os elementos do painel devem ser centralizados (alinhado) verticalmente, por coluna.|  
|[CMFCRibbonPanel::IsCollapsed](#iscollapsed)||  
|[CMFCRibbonPanel::IsHighlighted](#ishighlighted)||  
|[CMFCRibbonPanel::IsJustifyColumns](#isjustifycolumns)|Especifica se todas as colunas do painel têm a mesma largura.|  
|[CMFCRibbonPanel::IsMainPanel](#ismainpanel)||  
|[CMFCRibbonPanel::IsMenuMode](#ismenumode)||  
|[CMFCRibbonPanel::MakeGalleryItemVisible](#makegalleryitemvisible)|Rola a Galeria para tornar visível o elemento especificado da faixa de opções.|  
|[CMFCRibbonPanel::OnKey](#onkey)||  
|[CMFCRibbonPanel::RecalcWidths](#recalcwidths)||  
|[CMFCRibbonPanel::Remove](#remove)|Remove e, opcionalmente, exclui um elemento localizado no índice especificado.|  
|[CMFCRibbonPanel::RemoveAll](#removeall)|Remove todos os elementos do painel da faixa de opções.|  
|[CMFCRibbonPanel::Replace](#replace)|Substitui um elemento com o outro, com base nos valores de índice respectivo.|  
|[CMFCRibbonPanel::ReplaceByID](#replacebyid)|Substitui um elemento com outro com base em uma ID de comando especificado.|  
|[CMFCRibbonPanel::SetCenterColumnVert](#setcentercolumnvert)|Ordena o painel para alinhar elementos verticalmente, por coluna.|  
|[CMFCRibbonPanel::SetData](#setdata)|Associa dados definidos pelo usuário com o painel de faixa de opções.|  
|[CMFCRibbonPanel::SetElementMenu](#setelementmenu)|Atribui um menu pop-up para o elemento que tem a ID do comando especificado.|  
|[CMFCRibbonPanel::SetElementRTC](#setelementrtc)|Adiciona um elemento de faixa de opções especificado pelas informações de classe de tempo de execução fornecido ao painel da faixa de opções.|  
|[CMFCRibbonPanel::SetElementRTCByID](#setelementrtcbyid)|Adiciona um elemento de faixa de opções especificado pelas informações de classe de tempo de execução fornecido ao painel da faixa de opções.|  
|[CMFCRibbonPanel::SetFocused](#setfocused)|Define o foco para o elemento especificado da faixa de opções.|  
|[CMFCRibbonPanel::SetJustifyColumns](#setjustifycolumns)|Habilita ou desabilita a justificativa de coluna.|  
|[CMFCRibbonPanel::SetKeys](#setkeys)|Define o atalho de teclado que exibe o painel de faixa de opções.|  
|[CMFCRibbonPanel::ShowPopup](#showpopup)||  
  
## <a name="remarks"></a>Comentários  
 Painéis de faixa de opções são agrupamentos lógicos de tarefas relacionadas que você criar em categorias de faixa de opções. Como o tamanho das alterações de faixa de opções, o layout do painel ajusta automaticamente para exibir quantos elementos possível.  
  
 Você pode obter uma faixa de opções painéis que está contido em uma categoria de faixa de opções chamando o [CMFCRibbonCategory::GetPanel](../../mfc/reference/cmfcribboncategory-class.md#getpanel) método.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um `CMFCRibbonPanel` objeto usando vários métodos na `CMFCRibbonPanel` classe. O exemplo mostra como definir o atalho de teclado que exibe o painel de faixa de opções, alinhar os elementos no painel verticalmente por coluna e habilitar a justificativa de coluna. Este trecho de código é parte do [exemplo MS Office 2007 demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo n º&10;](../../mfc/reference/codesnippet/cpp/cmfcribbonpanel-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonPanel.h  
  
##  <a name="a-nameadda--cmfcribbonpaneladd"></a><a name="add"></a>CMFCRibbonPanel::Add  
 Acrescenta o elemento de faixa de opções especificadas para a matriz de elementos da faixa de opções que está contida no painel da faixa de opções.  
  
```  
virtual void Add(CMFCRibbonBaseElement* pElem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pElem`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameaddseparatora--cmfcribbonpaneladdseparator"></a><a name="addseparator"></a>CMFCRibbonPanel::AddSeparator  
 Adiciona um separador no painel de faixa de opções.  
  
```  
virtual void AddSeparator();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para adicionar um separador no painel de faixa de opções. O separador será adicionado ao lado do elemento de faixa de opções que foi adicionado pela chamada anterior a [CMFCRibbonPanel::Add](#add). Para inserir um separador em uma posição especificada, chame [CMFCRibbonPanel::InsertSeparator](#insertseparator).  
  
##  <a name="a-nameaddtoolbara--cmfcribbonpaneladdtoolbar"></a><a name="addtoolbar"></a>CMFCRibbonPanel::AddToolBar  
 Adiciona uma barra de ferramentas no painel de faixa de opções.  
  
```  
CMFCRibbonButtonsGroup* AddToolBar(
UINT uiToolbarResID,  
UINT uiColdResID = 0,  
UINT uiHotResID = 0,  
UINT uiDisabledResID = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiToolbarResID`  
 Especifica a ID de recurso da barra de ferramentas para adicionar.  
  
 [in] `uiColdResID`  
 Especifica a ID de recurso de imagens frio da barra de ferramentas.  
  
 [in] `uiHotResID`  
 Especifica a ID de recurso de imagens ativas da barra de ferramentas.  
  
 [in] `uiDisabledResID`  
 Especifica a ID de recurso de imagens desativado da barra de ferramentas.  
  
### <a name="return-value"></a>Valor de retorno  
 Chame esse método para adicionar uma barra de ferramentas no painel de faixa de opções. A barra de ferramentas será adicionada ao lado do elemento de faixa de opções adicionado por chamada anterior a [CMFCRibbonPanel::Add](#add).  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre barras de ferramentas, hot imagens, cold imagens e imagens desabilitadas, consulte [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md).  
  
##  <a name="a-namecmfcribbonpanela--cmfcribbonpanelcmfcribbonpanel"></a><a name="cmfcribbonpanel"></a>CMFCRibbonPanel::CMFCRibbonPanel  
 Constrói e inicializa um [CMFCRibbonPanel](../../mfc/reference/cmfcribbonpanel-class.md) objeto.  
  
```  
CMFCRibbonPanel(
LPCTSTR lpszName = NULL,  
HICON hIcon = NULL);  
  
CMFCRibbonPanel(CMFCRibbonGallery* pPaletteButton);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome do painel da faixa de opções.  
  
 [in] `hIcon`  
 Identificador para o ícone do botão padrão para o painel de faixa de opções.  
  
 [in] `pPaletteButton`  
 Ponteiro para uma galeria de faixa de opções do painel de faixa de opções.  
  
##  <a name="a-namefindbydataa--cmfcribbonpanelfindbydata"></a><a name="findbydata"></a>CMFCRibbonPanel::FindByData  
 Recupera o elemento de faixa de opções que está associado com os dados especificados.  
  
```  
CMFCRibbonBaseElement* FindByData(DWORD_PTR dwData) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Os dados associados a um elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namefindbyida--cmfcribbonpanelfindbyid"></a><a name="findbyid"></a>CMFCRibbonPanel::FindByID  
 Recupera o elemento de faixa de opções é identificado pela ID do comando especificado.  
  
```  
CMFCRibbonBaseElement* FindByID(UINT uiCmdID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 A ID de comando de um elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de faixa de opções é identificado pela ID de comando especificado; Caso contrário, `NULL` se nenhum elemento de faixa de opções é identificado com a ID de comando especificado.  
  
##  <a name="a-namegetcaptionheighta--cmfcribbonpanelgetcaptionheight"></a><a name="getcaptionheight"></a>CMFCRibbonPanel::GetCaptionHeight  
 Recupera a altura de uma legenda para o painel de faixa de opções.  
  
```  
int GetCaptionHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, de uma legenda para o painel de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetcounta--cmfcribbonpanelgetcount"></a><a name="getcount"></a>CMFCRibbonPanel::GetCount  
 Recupera o número de elementos da faixa de opções que estão contidos no painel da faixa de opções.  
  
```  
int GetCount() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de elementos da faixa de opções que estão contidos no painel da faixa de opções.  
  
##  <a name="a-namegetdataa--cmfcribbonpanelgetdata"></a><a name="getdata"></a>CMFCRibbonPanel::GetData  
 Retorna os dados definidos pelo usuário associados com o painel.  
  
```  
DWORD_PTR GetData() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os dados definidos pelo usuário associados com o painel.  
  
##  <a name="a-namegetdefaultbuttona--cmfcribbonpanelgetdefaultbutton"></a><a name="getdefaultbutton"></a>CMFCRibbonPanel::GetDefaultButton  
 Recupera o botão padrão para o painel de faixa de opções.  
  
```  
CMFCRibbonButton& GetDefaultButton();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O botão padrão para o painel de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O botão padrão é exibido quando um painel de faixa de opções tem espaço suficiente para exibir seus elementos de faixa de opções.  
  
##  <a name="a-namegetdroppeddowna--cmfcribbonpanelgetdroppeddown"></a><a name="getdroppeddown"></a>CMFCRibbonPanel::GetDroppedDown  
 Recupera um ponteiro para um elemento de faixa de opções se seu menu pop-up está aberta.  
  
```  
CMFCRibbonBaseElement* GetDroppedDown() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o elemento de faixa de opções com o menu pop-up soltas; Caso contrário, `NULL` se nenhum elemento de faixa de opções no menu pop-up soltas.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos no painel da faixa de opções são testados.  
  
##  <a name="a-namegetelementa--cmfcribbonpanelgetelement"></a><a name="getelement"></a>CMFCRibbonPanel::GetElement  
 Retorna o elemento de faixa de opções, localizado em um índice especificado.  
  
```  
CMFCRibbonBaseElement* GetElement(int nIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de base zero do elemento a ser recuperado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para o elemento de faixa de opções base localizado na posição `nIndex` no painel da faixa de opções, ou `NULL` se não houver nenhum elemento no índice especificado.  
  
##  <a name="a-namegetelementsa--cmfcribbonpanelgetelements"></a><a name="getelements"></a>CMFCRibbonPanel::GetElements  
 Recupera todos os elementos da faixa de opções que estão contidos no painel da faixa de opções.  
  
```  
void GetElements(CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `arElements`  
 Uma matriz para preencher com todos os elementos da faixa de opções que estão contidos no painel da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetelementsbyida--cmfcribbonpanelgetelementsbyid"></a><a name="getelementsbyid"></a>CMFCRibbonPanel::GetElementsByID  
 Adiciona os elementos da faixa de opções com a identificação de comando especificada na matriz especificada.  
  
```  
void GetElementsByID(
UINT uiCmdID,  
CArray<CMFCRibbonBaseElement*, CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 ID de comando para um elemento de faixa de opções.  
  
 [in] `arElements`  
 Matriz de elementos da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos no painel da faixa de opções são testados.  
  
##  <a name="a-namegethighlighteda--cmfcribbonpanelgethighlighted"></a><a name="gethighlighted"></a>CMFCRibbonPanel::GetHighlighted  
 Recupera o elemento de faixa de opções é realçado no painel da faixa de opções.  
  
```  
CMFCRibbonBaseElement* GetHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o elemento de faixa de opções é realçado no painel da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetindexa--cmfcribbonpanelgetindex"></a><a name="getindex"></a>CMFCRibbonPanel::GetIndex  
 Recupera o índice com base zero do elemento especificado da faixa de opções da matriz de elementos de faixa de opções que estão contidos no painel da faixa de opções.  
  
```  
virtual int GetIndex(CMFCRibbonBaseElement* pElem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pElem`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Índice com base zero do elemento especificado da faixa de opções, se o método teve êxito; Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetitemidslista--cmfcribbonpanelgetitemidslist"></a><a name="getitemidslist"></a>CMFCRibbonPanel::GetItemIDsList  
 Recupera as IDs de comando para todos os elementos da faixa de opções no painel da faixa de opções.  
  
```  
void GetItemIDsList(CList<UINT, UINT>& lstItems) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `lstItems`  
 A lista de IDs de comando para os elementos da faixa de opções que estão contidos no painel da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetnamea--cmfcribbonpanelgetname"></a><a name="getname"></a>CMFCRibbonPanel::GetName  
 Recupera o nome do painel da faixa de opções.  
  
```  
LPCTSTR GetName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do painel da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetparentbuttona--cmfcribbonpanelgetparentbutton"></a><a name="getparentbutton"></a>CMFCRibbonPanel::GetParentButton  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CMFCRibbonBaseElement* GetParentButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetparentcategorya--cmfcribbonpanelgetparentcategory"></a><a name="getparentcategory"></a>CMFCRibbonPanel::GetParentCategory  
 Retorna a categoria pai do painel da faixa de opções.  
  
```  
CMFCRibbonCategory* GetParentCategory() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a categoria de faixa de opções que contém este painel de faixa de opções.  
  
##  <a name="a-namegetparentmenubara--cmfcribbonpanelgetparentmenubar"></a><a name="getparentmenubar"></a>CMFCRibbonPanel::GetParentMenuBar  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CMFCRibbonPanelMenuBar* GetParentMenuBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetpreferedmenulocationa--cmfcribbonpanelgetpreferedmenulocation"></a><a name="getpreferedmenulocation"></a>CMFCRibbonPanel::GetPreferedMenuLocation  
 Recupera o retângulo de exibição preferencial do menu pop-up do painel da faixa de opções.  
  
```  
virtual BOOL GetPreferedMenuLocation(CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `rect`  
 Este parâmetro não é usado.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna `FALSE`. Substitua este método para recuperar o retângulo de exibição preferencial do menu pop-up do painel da faixa de opções.  
  
##  <a name="a-namegetpresseda--cmfcribbonpanelgetpressed"></a><a name="getpressed"></a>CMFCRibbonPanel::GetPressed  
 Recupera um ponteiro para um elemento de faixa de opções no painel da faixa de opções, se o usuário a pressionar atualmente.  
  
```  
CMFCRibbonBaseElement* GetPressed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento de faixa de opções, se o usuário pressionar atualmente Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetrecta--cmfcribbonpanelgetrect"></a><a name="getrect"></a>CMFCRibbonPanel::GetRect  
 Recupera o retângulo de exibição do painel de faixa de opções.  
  
```  
const CRect& GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo de exibição do painel de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehaselementa--cmfcribbonpanelhaselement"></a><a name="haselement"></a>CMFCRibbonPanel::HasElement  
 Indica se o painel de faixa de opções contém o elemento especificado da faixa de opções.  
  
```  
BOOL HasElement(const CMFCRibbonBaseElement* pElem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pElem`  
 Ponteiro para um elemento de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o painel de faixa de opções contém o elemento especificado da faixa de opções. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehighlighta--cmfcribbonpanelhighlight"></a><a name="highlight"></a>CMFCRibbonPanel::Highlight  
 Define a cor do realce do painel da faixa de opções selecionada e para o elemento de faixa de opções especificadas pelo ponto.  
  
```  
virtual void Highlight(
BOOL bHighlight,  
CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bHighlight`  
 `TRUE`para realçar o painel de faixa de opções; `FALSE` para realce o painel de faixa de opções.  
  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namehittesta--cmfcribbonpanelhittest"></a><a name="hittest"></a>CMFCRibbonPanel::HitTest  
 Recupera um elemento de faixa de opções, se o ponto especificado está localizado dentro dele.  
  
```  
virtual CMFCRibbonBaseElement* HitTest(
CPoint point,  
BOOL bCheckPanelCaption = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
 [in] `bCheckPanelCaption`  
 `TRUE`Para testar a legenda do painel de faixa de opções; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para um elemento de faixa de opções, se o ponto especificado for localizado Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos no painel da faixa de opções são testados.  
  
##  <a name="a-namehittestexa--cmfcribbonpanelhittestex"></a><a name="hittestex"></a>CMFCRibbonPanel::HitTestEx  
 Retorna o índice baseado em zero do elemento de faixa de opções que tem o ponto especificado nele localizados.  
  
```  
virtual int HitTestEx(CPoint point) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `point`  
 As coordenadas x e y do ponteiro, em relação ao canto superior esquerdo da janela.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice de base zero do elemento de faixa de opções que tem o ponto especificado localizado Caso contrário, retornará-1.  
  
### <a name="remarks"></a>Comentários  
 Apenas os elementos da faixa de opções que estão contidos no painel da faixa de opções são testados.  
  
##  <a name="a-nameinserta--cmfcribbonpanelinsert"></a><a name="insert"></a>CMFCRibbonPanel::Insert  
 Insere o elemento de faixa de opções especificadas na posição especificada na matriz de elementos da faixa de opções que está contida no painel da faixa de opções.  
  
```  
virtual BOOL Insert(
CMFCRibbonBaseElement* pElem,  
int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in, out] `pElem`  
 Ponteiro para um elemento de faixa de opções.  
  
 [in] `nIndex`  
 Valor com base em zero, variando de -1 para o número de elementos da faixa de opções que estão contidos na matriz.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o elemento de faixa de opções foi inserido com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de `nIndex` é -1, ou se `nIndex` é igual ao número de elementos da faixa de opções na matriz, o elemento especificado da faixa de opções é adicionado ao final da matriz. Se o valor de `nIndex` está fora do intervalo, o método falhará.  
  
##  <a name="a-nameinsertseparatora--cmfcribbonpanelinsertseparator"></a><a name="insertseparator"></a>CMFCRibbonPanel::InsertSeparator  
 Insere um separador na posição especificada.  
  
```  
virtual BOOL InsertSeparator(int nIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de base zero onde o separador é inserido.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o separador tiver sido inserido com êxito; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para inserir um separador na posição especificada por `nIndex`. Para inserir um separador ao lado do elemento de faixa de opções adicionado mais recentemente, chamada [CMFCRibbonPanel::AddSeparator](#addseparator).  
  
##  <a name="a-nameiscentercolumnverta--cmfcribbonpaneliscentercolumnvert"></a><a name="iscentercolumnvert"></a>CMFCRibbonPanel::IsCenterColumnVert  
 Indica se as posições verticais dos elementos da faixa de opções são centralizadas dentro do retângulo sua exibição.  
  
```  
BOOL IsCenterColumnVert() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`se posiciona vertical de elementos da faixa de opções são centralizados dentro de seu retângulo de exibição; Caso contrário, `FALSE`.  
  
##  <a name="a-nameiscollapseda--cmfcribbonpaneliscollapsed"></a><a name="iscollapsed"></a>CMFCRibbonPanel::IsCollapsed  
 Indica se o tamanho da exibição do painel de faixa de opções é minimizado na direção horizontal.  
  
```  
BOOL IsCollapsed() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o tamanho da exibição do painel de faixa de opções é minimizado na direção horizontal; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Quando um painel de faixa de opções é recolhido, ele exibe apenas o botão padrão, seu nome e uma seta suspensa.  
  
##  <a name="a-nameishighlighteda--cmfcribbonpanelishighlighted"></a><a name="ishighlighted"></a>CMFCRibbonPanel::IsHighlighted  
 Indica se a exibição do painel de faixa de opções é realçada.  
  
```  
BOOL IsHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a exibição do painel de faixa de opções é realçada; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A exibição de um painel de faixa de opções é realçada quando o ponteiro estiver sobre ela.  
  
##  <a name="a-nameisjustifycolumnsa--cmfcribbonpanelisjustifycolumns"></a><a name="isjustifycolumns"></a>CMFCRibbonPanel::IsJustifyColumns  
 Indica se as dimensões da exibição de elementos de faixa de opções que estão na mesma coluna no painel da faixa de opções são definidas com a mesma largura.  
  
```  
BOOL IsJustifyColumns() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se as dimensões da exibição de elementos da faixa de opções que estão na mesma coluna no painel da faixa de opções são definidas com a mesma largura; Caso contrário, `FALSE`.  
  
##  <a name="a-nameismainpanela--cmfcribbonpanelismainpanel"></a><a name="ismainpanel"></a>CMFCRibbonPanel::IsMainPanel  
 Indica se o painel de faixa de opções é o painel principal da faixa de opções.  
  
```  
virtual BOOL IsMainPanel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Esse método sempre retorna `FALSE`. Substitua este método para indicar se o painel de faixa de opções é o painel principal da faixa de opções.  
  
 O painel principal da faixa de opções é exibido quando o usuário seleciona o botão do aplicativo.  
  
##  <a name="a-nameismenumodea--cmfcribbonpanelismenumode"></a><a name="ismenumode"></a>CMFCRibbonPanel::IsMenuMode  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsMenuMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameonkeya--cmfcribbonpanelonkey"></a><a name="onkey"></a>CMFCRibbonPanel::OnKey  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL OnKey(UINT nChar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nChar`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namerecalcwidthsa--cmfcribbonpanelrecalcwidths"></a><a name="recalcwidths"></a>CMFCRibbonPanel::RecalcWidths  
 Recalcula a largura de cada configuração de layout de exibição do painel de faixa de opções.  
  
```  
virtual void RecalcWidths(
CDC* pDC,  
int nHeight);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para o painel de faixa de opções.  
  
 [in] `nHeight`  
 A altura do painel da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 Um painel de faixa de opções altera sua configuração de layout como as alterações de largura disponível.  
  
##  <a name="a-nameremovea--cmfcribbonpanelremove"></a><a name="remove"></a>CMFCRibbonPanel::Remove  
 Remove e, opcionalmente, exclui um elemento localizado no índice especificado.  
  
```  
BOOL Remove(
int nIndex,  
BOOL bDelete = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de base zero do elemento que é removido do painel de faixa de opções.  
  
 [in] `bDelete`  
 `TRUE`Para excluir o elemento que está sendo removido; Caso contrário, `FALSE`.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o elemento foi removido e excluído (se `bDelete` é `TRUE`); `FALSE` se o elemento não foi removido ou se não houver nenhum elemento de faixa de opções localizado em `nIndex`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para remover um elemento do painel da faixa de opções.  
  
##  <a name="a-nameremovealla--cmfcribbonpanelremoveall"></a><a name="removeall"></a>CMFCRibbonPanel::RemoveAll  
 Exclui todos os elementos da faixa de opções do painel de faixa de opções.  
  
```  
void RemoveAll();
```  
  
### <a name="remarks"></a>Comentários  
 Todos os elementos da faixa de opções são excluídos do painel da faixa de opções e destruídos.  
  
##  <a name="a-namereplacea--cmfcribbonpanelreplace"></a><a name="replace"></a>CMFCRibbonPanel::Replace  
 Substitui um elemento com outro com base em seu valor de índice.  
  
```  
BOOL Replace(
int nIndex,  
CMFCRibbonBaseElement* pElem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de base zero do elemento a ser substituído.  
  
 [in] [out]`pElem`  
 Um ponteiro válido para o elemento que substitui o elemento original.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o elemento de faixa de opções original foi substituído com êxito pelo novo elemento de faixa de opções; `FALSE` se o elemento de faixa de opções não foi substituído ou se não houver nenhum elemento no índice especificado.  
  
### <a name="remarks"></a>Comentários  
 Para substituir um elemento de faixa de opções por ID de comando, execute [CMFCRibbonPanel::ReplaceByID](#replacebyid).  
  
##  <a name="a-namereplacebyida--cmfcribbonpanelreplacebyid"></a><a name="replacebyid"></a>CMFCRibbonPanel::ReplaceByID  
 Substitui um elemento com outro com base em uma ID de comando especificado.  
  
```  
BOOL ReplaceByID(
UINT uiCmdID,  
CMFCRibbonBaseElement* pElem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Especifica a ID do elemento de comando para substituir.  
  
 [in] [out]`pElem`  
 Um ponteiro válido para o elemento que substituirá o elemento original.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o elemento de faixa de opções original foi substituído com êxito pelo novo elemento de faixa de opções; `FALSE` se o elemento de faixa de opções não foi substituído ou se realmente não existe nenhum elemento com a ID de comando especificado.  
  
### <a name="remarks"></a>Comentários  
 Para substituir um elemento de faixa de opções com base na posição, chame [CMFCRibbonPanel::Replace](#replace).  
  
##  <a name="a-namesetcentercolumnverta--cmfcribbonpanelsetcentercolumnvert"></a><a name="setcentercolumnvert"></a>CMFCRibbonPanel::SetCenterColumnVert  
 Habilita ou desabilita a centralização das posições dos elementos da faixa de opções o retângulo de exibição verticais.  
  
```  
void SetCenterColumnVert(BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 `TRUE`para centralizar as posições verticais dos elementos da faixa de opções no retângulo sua exibição; `FALSE` para desabilitar esse recurso.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namesetdataa--cmfcribbonpanelsetdata"></a><a name="setdata"></a>CMFCRibbonPanel::SetData  
 Associa dados definidos pelo usuário com o painel de faixa de opções.  
  
```  
void SetData(DWORD_PTR dwData);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dwData`  
 Especifica os dados definidos pelo usuário para definir.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para associar dados definidos pelo usuário com o painel de faixa de opções.  
  
##  <a name="a-namesetelementmenua--cmfcribbonpanelsetelementmenu"></a><a name="setelementmenu"></a>CMFCRibbonPanel::SetElementMenu  
 Atribui um menu pop-up para o elemento que tem a ID do comando especificado.  
  
```  
BOOL SetElementMenu(
UINT uiCmdID,  
HMENU hMenu,  
BOOL bIsDefautCommand = FALSE,  
BOOL bRightAlign = FALSE);

 
BOOL SetElementMenu(
UINT uiCmdID,  
UINT uiMenuResID,  
BOOL bIsDefautCommand = FALSE,  
BOOL bRightAlign = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Especifica a ID de comando do elemento de faixa de opções onde o menu é adicionado.  
  
 [in] `hMenu`  
 Especifica o identificador do menu do Windows para adicionar ao painel de faixa de opções.  
  
 [in] `bIsDefautCommand`  
 `TRUE`para especificar que o comando associado ao elemento de faixa de opções deve ser executado se o elemento de faixa de opções é clicado. Nesse caso, o menu só é aberto quando o usuário clica na seta ao lado do elemento de faixa de opções. `FALSE`para especificar que o comando associado ao elemento de faixa de opções não deve ser executado se o elemento de faixa de opções é clicado. Nesse caso, o menu pop-up será exibida, independentemente de onde o usuário clica no elemento.  
  
 [in] `bRightAlign`  
 `TRUE`para especificar que o menu pop-up é alinhado à direita; Caso contrário, `FALSE`.  
  
 [in] `uiMenuResID`  
 Especifica a ID de recurso do menu para adicionar ao painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o menu foi atribuído para o elemento de faixa de opções. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para atribuir um menu pop-up para o elemento de faixa de opções que tem a ID do comando especificado.  
  
##  <a name="a-namesetelementrtca--cmfcribbonpanelsetelementrtc"></a><a name="setelementrtc"></a>CMFCRibbonPanel::SetElementRTC  
 Adiciona o elemento de faixa de opções for especificado, as informações de classe de tempo de execução fornecido para o painel de faixa de opções.  
  
```  
CMFCRibbonBaseElement* SetElementRTC(
int nIndex,  
CRuntimeClass* pRTC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIndex`  
 Especifica o índice de base zero do elemento da faixa de opções para adicionar.  
  
 [in] [out]`pRTC`  
 Um ponteiro para as informações de classe de tempo de execução para o elemento de faixa de opções é adicionada ao painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de faixa de opções que foi criado usando as informações de classe de tempo de execução especificado.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser adicionar um elemento personalizado (por exemplo, um botão de cor) para o painel de faixa de opções, você deve especificar informações de classe de tempo de execução do elemento personalizado. A faixa de opções armazena essas informações, cria o elemento personalizado e substitui um elemento existente está localizado (identificado pelo) a ID do comando especificado. A faixa de opções, em seguida, retorna um ponteiro para o elemento recém-criado.  
  
##  <a name="a-namesetelementrtcbyida--cmfcribbonpanelsetelementrtcbyid"></a><a name="setelementrtcbyid"></a>CMFCRibbonPanel::SetElementRTCByID  
 Adiciona um elemento de faixa de opções for especificado, as informações de classe de tempo de execução fornecido para o painel de faixa de opções.  
  
```  
CMFCRibbonBaseElement* SetElementRTCByID(
UINT uiCmdID,  
CRuntimeClass* pRTC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Especifica a ID do elemento de faixa de opções de comando para adicionar.  
  
 [in] [out]`pRTC`  
 Um ponteiro para as informações de classe de tempo de execução associados ao elemento de faixa de opções é adicionado ao painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 O elemento de faixa de opções que foi criado usando as informações de classe de tempo de execução especificado.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser adicionar um elemento personalizado (por exemplo, um botão de cor) para o painel de faixa de opções, você deve especificar informações de classe de tempo de execução do elemento personalizado. A faixa de opções armazena essas informações, cria o elemento personalizado e substitui um elemento existente localizado pela ID do comando especificado. Em seguida, ele retorna um ponteiro para o elemento recém-criado.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como usar o `SetElementRTCByID` método:  
  
```  
 
// Load and add toolbar with standard buttons. This toolbar  
// should display a custom color button with id ID_CHAR_COLOR:  
 
pPanel->AddToolBar(IDR_MAINFRAME,
    IDB_MAINFRAME256);

CMFCRibbonColorButton* pColorButton = 
(CMFCRibbonColorButton*)pPanel->SetElementRTCByID(
ID_CHAR_COLOR,
    RUNTIME_CLASS (CMFCRibbonColorButton));

 
// SetElementRTCByID sets runtime class and returns a pointer  
// to the newly created custom button,
    which can be set up immediately:  
pColorButton->EnableAutomaticButton(_T("Automatic"),
    RGB (0,
    0,
    0));  
```  
  
##  <a name="a-namesetjustifycolumnsa--cmfcribbonpanelsetjustifycolumns"></a><a name="setjustifycolumns"></a>CMFCRibbonPanel::SetJustifyColumns  
 Habilita ou desabilita o ajuste da largura de elementos da faixa de opções na mesma coluna.  
  
```  
void SetJustifyColumns(BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 `TRUE`Para ajustar a largura dos elementos da faixa de opções na mesma coluna para a largura do maior elemento da faixa de opções da coluna; `FALSE` para desabilitar esse ajuste de largura.  
  
### <a name="remarks"></a>Comentários  
 Quando esse recurso está habilitado em um painel de faixa de opções, as larguras dos elementos da faixa de opções na mesma coluna são ajustadas para a largura do maior elemento da faixa de opções na mesma coluna.  
  
##  <a name="a-namesetkeysa--cmfcribbonpanelsetkeys"></a><a name="setkeys"></a>CMFCRibbonPanel::SetKeys  
 Define a dica de tela do botão padrão do painel de faixa de opções.  
  
```  
void SetKeys(LPCTSTR lpszKeys);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszKeys`  
 A dica de tela do botão padrão do painel de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O botão padrão é exibido quando um painel de faixa de opções tem espaço suficiente para exibir seus elementos de faixa de opções.  
  
##  <a name="a-nameshowpopupa--cmfcribbonpanelshowpopup"></a><a name="showpopup"></a>CMFCRibbonPanel::ShowPopup  
 Cria e exibe um menu pop-up do painel da faixa de opções.  
  
```  
CMFCRibbonPanelMenu* ShowPopup(CMFCRibbonDefaultPanelButton* pButton = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Ponteiro para o botão padrão para o painel de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para o menu pop-up do painel da faixa de opções, se o método teve êxito; Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
 O menu pop-up do painel da faixa de opções está disponível apenas quando a exibição do painel de faixa de opções é recolhida.  
  
##  <a name="a-namesetfocuseda--cmfcribbonpanelsetfocused"></a><a name="setfocused"></a>CMFCRibbonPanel::SetFocused  
 Define o foco para o elemento especificado da faixa de opções.  
  
```  
void SetFocused(CMFCRibbonBaseElement* pNewFocus);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pNewFocus`  
 Um ponteiro para um elemento de faixa de opções que recebe o foco.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemakegalleryitemvisiblea--cmfcribbonpanelmakegalleryitemvisible"></a><a name="makegalleryitemvisible"></a>CMFCRibbonPanel::MakeGalleryItemVisible  
 Rola a Galeria para tornar visível o elemento especificado da faixa de opções.  
  
```  
void MakeGalleryItemVisible(CMFCRibbonBaseElement* pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Um ponteiro para um elemento de faixa de opções para mostrar.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-nameiswindows7looka--cmfcribbonpaneliswindows7look"></a><a name="iswindows7look"></a>CMFCRibbonPanel::IsWindows7Look  
 Indica se a faixa de opções do pai tem o Windows 7 Pesquisar (botão pequeno aplicativo retangular).  
  
```  
BOOL IsWindows7Look() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a faixa de opções do pai com o Windows 7 examinar; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetvisibleelementsa--cmfcribbonpanelgetvisibleelements"></a><a name="getvisibleelements"></a>CMFCRibbonPanel::GetVisibleElements  
 Recupera uma matriz de elementos visíveis.  
  
```  
void GetVisibleElements(
CArray<CMFCRibbonBaseElement*,  
CMFCRibbonBaseElement*>& arElements);
```  
  
### <a name="parameters"></a>Parâmetros  
 `arElements`  
 Quando a função retornar, este parâmetro contém uma matriz de elementos visíveis.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetgalleryrecta--cmfcribbonpanelgetgalleryrect"></a><a name="getgalleryrect"></a>CMFCRibbonPanel::GetGalleryRect  
 Retorna um retângulo delimitador de um elemento de galeria.  
  
```  
CRect GetGalleryRect();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tamanho e posição do elemento Galeria dentro deste painel.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namegetfocuseda--cmfcribbonpanelgetfocused"></a><a name="getfocused"></a>CMFCRibbonPanel::GetFocused  
 Retorna um elemento focalizado.  
  
```  
CMFCRibbonBaseElement* GetFocused() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um elemento focalizado ou `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Classe de CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md)   
 [Classe CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

