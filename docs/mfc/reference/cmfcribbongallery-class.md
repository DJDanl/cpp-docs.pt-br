---
title: Classe CMFCRibbonGallery | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonGallery
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::CMFCRibbonGallery
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::AddGroup
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::AddSubItem
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::Clear
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::EnableMenuResize
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::EnableMenuSideBar
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetCompactSize
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetDroppedDown
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetGroupName
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetGroupOffset
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetIconsInRow
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetItemToolTip
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetLastSelectedItem
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetPaletteID
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetRegularSize
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::GetSelectedItem
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::HasMenu
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::IsButtonMode
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::IsMenuResizeEnabled
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::IsMenuResizeVertical
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::IsMenuSideBar
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::OnAfterChangeRect
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::OnDraw
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::OnEnable
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::OnRTLChanged
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::RedrawIcons
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::RemoveItemToolTips
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SelectItem
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetACCData
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetButtonMode
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetGroupName
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetIconsInRow
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetItemToolTip
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetPalette
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::SetPaletteID
- AFXRIBBONPALETTEGALLERY/CMFCRibbonGallery::OnDrawPaletteIcon
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonGallery class
ms.assetid: 9734c9c9-981c-4b3f-8c59-264fd41811b4
caps.latest.revision: 28
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
ms.openlocfilehash: c4eadb9820f2d7318131cc4d197dbe28d65491c0
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribbongallery-class"></a>Classe CMFCRibbonGallery
Galerias de faixa de opções de estilo do Office 2007 implementa.  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonGallery : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonGallery::CMFCRibbonGallery](#cmfcribbongallery)|Constrói e inicializa um objeto `CMFCRibbonGallery`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonGallery::AddGroup](#addgroup)|Adiciona um novo grupo na Galeria.|  
|[CMFCRibbonGallery::AddSubItem](#addsubitem)|Adiciona um novo item de menu ao menu suspenso.|  
|[CMFCRibbonGallery::Clear](#clear)|Limpa o conteúdo da Galeria.|  
|[CMFCRibbonGallery::EnableMenuResize](#enablemenuresize)|Habilita ou desabilita o redimensionamento do painel do menu.|  
|[CMFCRibbonGallery::EnableMenuSideBar](#enablemenusidebar)|Habilita ou desabilita a barra lateral à esquerda do menu pop-up.|  
|[CMFCRibbonGallery::GetCompactSize](#getcompactsize)|(Substitui [CMFCRibbonButton::GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|  
|[CMFCRibbonGallery::GetDroppedDown](#getdroppeddown)|(Substitui [CMFCRibbonBaseElement::GetDroppedDown](../../mfc/reference/cmfcribbonbaseelement-class.md#getdroppeddown).)|  
|[CMFCRibbonGallery::GetGroupName](#getgroupname)|Retorna o nome do grupo que está localizado no índice especificado.|  
|[CMFCRibbonGallery::GetGroupOffset](#getgroupoffset)||  
|[CMFCRibbonGallery::GetIconsInRow](#geticonsinrow)|Retorna o número de itens em uma linha da Galeria de faixa de opções.|  
|[CMFCRibbonGallery::GetItemToolTip](#getitemtooltip)|Retorna o texto de dica de ferramenta que está associado um item da Galeria.|  
|[CMFCRibbonGallery::GetLastSelectedItem](#getlastselecteditem)|Retorna o índice do último item na Galeria do que o usuário selecionado.|  
|[CMFCRibbonGallery::GetPaletteID](#getpaletteid)|Retorna a ID de comando da Galeria do atual.|  
|[CMFCRibbonGallery::GetRegularSize](#getregularsize)|(Substitui [CMFCRibbonButton::GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|  
|[CMFCRibbonGallery::GetSelectedItem](#getselecteditem)||  
|[CMFCRibbonGallery::HasMenu](#hasmenu)|(Substitui [CMFCRibbonButton::HasMenu](../../mfc/reference/cmfcribbonbutton-class.md#hasmenu).)|  
|[CMFCRibbonGallery::IsButtonMode](#isbuttonmode)|Especifica se a Galeria está contida em um botão da Galeria.|  
|[CMFCRibbonGallery::IsMenuResizeEnabled](#ismenuresizeenabled)|Especifica se o redimensionamento de menu está habilitado ou desabilitado.|  
|[CMFCRibbonGallery::IsMenuResizeVertical](#ismenuresizevertical)||  
|[CMFCRibbonGallery::IsMenuSideBar](#ismenusidebar)|Especifica se a barra lateral está habilitada ou desabilitada.|  
|[CMFCRibbonGallery::OnAfterChangeRect](#onafterchangerect)|(Substitui `CMFCRibbonButton::OnAfterChangeRect`.)|  
|[CMFCRibbonGallery::OnDraw](#ondraw)|(Substitui [CMFCRibbonButton::OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|  
|[CMFCRibbonGallery::OnEnable](#onenable)|(Substitui `CMFCRibbonBaseElement::OnEnable`.)|  
|[CMFCRibbonGallery::OnRTLChanged](#onrtlchanged)|(Substitui [CMFCRibbonBaseElement::OnRTLChanged](../../mfc/reference/cmfcribbonbaseelement-class.md#onrtlchanged).)|  
|[CMFCRibbonGallery::RedrawIcons](#redrawicons)|Redesenha a Galeria.|  
|[CMFCRibbonGallery::RemoveItemToolTips](#removeitemtooltips)|Remove todos os itens na Galeria de dicas de ferramentas.|  
|[CMFCRibbonGallery::SelectItem](#selectitem)||  
|[CMFCRibbonGallery::SetACCData](#setaccdata)|(Substitui [CMFCRibbonButton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|  
|[CMFCRibbonGallery::SetButtonMode](#setbuttonmode)|Especifica se deve exibir a Galeria de faixa de opções, como um botão de lista suspensa ou uma paleta diretamente na faixa de opções.|  
|[CMFCRibbonGallery::SetGroupName](#setgroupname)|Define o nome de um grupo.|  
|[CMFCRibbonGallery::SetIconsInRow](#seticonsinrow)|Define o número de itens por linha na Galeria.|  
|[CMFCRibbonGallery::SetItemToolTip](#setitemtooltip)|Define o texto de dica de ferramenta para um item da Galeria.|  
|[CMFCRibbonGallery::SetPalette](#setpalette)|Anexa uma paleta de uma galeria de faixa de opções.|  
|[CMFCRibbonGallery::SetPaletteID](#setpaletteid)|Define a ID de comando que é enviada na `WM_COMMAND` mensagem quando um item da Galeria foi selecionado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonGallery::OnDrawPaletteIcon](#ondrawpaletteicon)|Chamado pela estrutura quando um ícone de galeria é desenhado.|  
  
## <a name="remarks"></a>Comentários  
 Um botão de galeria se comporta exatamente como um botão de menu regular, exceto que ele exibe uma galeria quando um usuário abre. Quando você seleciona um item em uma galeria, o framework envia o `WM_COMMAND` mensagem com ID de comando do botão. Quando você manipula a mensagem, você deve chamar [CMFCRibbonGallery::GetLastSelectedItem](#getlastselecteditem) para determinar qual item selecionado da Galeria.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonGallery` classe para configurar um `CMFCRibbonGallery` objeto. O exemplo ilustra como especificar o número de itens por linha na galeria, habilitar o redimensionamento do painel do menu, a barra lateral à esquerda do menu pop-up e exibir a Galeria de faixa de opções como uma paleta diretamente na barra de faixa de opções. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient n º&6;](../../mfc/reference/codesnippet/cpp/cmfcribbongallery-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md) [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md) [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonPaletteGallery.h  
  
##  <a name="addgroup"></a>CMFCRibbonGallery::AddGroup  
 Adiciona um novo grupo na Galeria.  
  
```  
void AddGroup(
    LPCTSTR lpszGroupName,  
    UINT uiImagesPaletteResID,  
    int cxPaletteImage);

 
void AddGroup(
    LPCTSTR lpszGroupName,  
    CMFCToolBarImages& imagesGroup);

 
void AddGroup(
    LPCTSTR lpszGroupName,  
    int nIconsNum);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszGroupName`  
 Especifica o nome do grupo.  
  
 [in] `uiImagesPaletteResID`  
 Especifica a ID de lista de imagens que contém as imagens para o grupo de recursos.  
  
 [in] `cxPaletteImage`  
 Especifica a largura em pixels da imagem.  
  
 [in] `imagesGroup`  
 Uma referência à lista de imagens que contém imagens do grupo.  
  
 [in] `nIconsNum`  
 Especifica o número de ícones do grupo. Esse parâmetro deve ser especificado somente para personalizado (desenhados pelo proprietário) grupos.  
  
### <a name="remarks"></a>Comentários  
 Você pode dividir os itens em uma galeria de faixa de opções em vários grupos chamando este método. Cada grupo pode ter uma legenda.  
  
##  <a name="addsubitem"></a>CMFCRibbonGallery::AddSubItem  
 Adiciona um novo item de menu ao menu suspenso.  
  
```  
void AddSubItem(
    CMFCRibbonBaseElement* pSubItem,  
    int nIndex=-1,  
    BOOL bOnTop=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pSubItem`  
 Um ponteiro para o item a ser adicionado ao menu.  
  
 [in] `nIndex`  
 Especifica o índice com base em zero de um local de onde inserir o item.  
  
 [in] `bOnTop`  
 `TRUE`para especificar que o item deve ser inserido antes da Galeria de faixa de opções; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Você pode combinar galerias de pop-up com itens de menu pop-up ao chamar esse método. Itens de menu podem ser colocados antes ou depois da Galeria.  
  
 Para inserir o item antes da galeria, defina `bOnTop` para `TRUE`. Definir `bOnTop` para `FALSE` para inserir o item abaixo a Galeria.  
  
> [!NOTE]
>  O parâmetro `nIndex` Especifica o índice de inserção na parte superior da galeria e na parte inferior da Galeria. Por exemplo, se você precisa inserir um item para uma posição antes da galeria, defina `nIndex` para 1 e `bOnTop` para `TRUE`. Da mesma forma, se você precisa inserir um item para uma posição abaixo a Galeria, defina `nIndex` para 1 e `bOnTop` para `FALSE`.  
  
##  <a name="clear"></a>CMFCRibbonGallery::Clear  
 Limpa o conteúdo da Galeria.  
  
```  
virtual void Clear();
```  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para remover todo o conteúdo da Galeria de faixa de opções. Isso deve ser feito antes de anexar uma nova Galeria de faixa de opções ou conjunto de grupos na Galeria de faixa de opções.  
  
##  <a name="cmfcribbongallery"></a>CMFCRibbonGallery::CMFCRibbonGallery  
 Constrói e inicializa um [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md) objeto.  
  
```  
CMFCRibbonGallery (
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex,  
    int nLargeImageIndex,  
    CMFCToolBarImages& imagesPalette);

 
CMFCRibbonGallery (
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex,  
    int nLargeImageIndex,  
    UINT uiImagesPaletteResID=0,  
    int cxPaletteImage=0);

 
CMFCRibbonGallery (
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex,  
    int nLargeImageIndex,  
    CSize sizeIcon,  
    int nIconsNum,  
    BOOL bDefaultButtonStyle=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nID`  
 Especifica a ID de comando do comando a ser executada quando um usuário clica no botão.  
  
 `lpszText`  
 Especifica o texto a ser exibido no botão.  
  
 `nSmallImageIndex`  
 O índice baseado em zero da pequena imagem apareça no botão.  
  
 `nLargeImageIndex`  
 O índice baseado em zero da imagem apareça no botão grande.  
  
 `imagesPalette`  
 Uma referência para o [CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md) objeto que contém as imagens para aparecer na Galeria.  
  
 `uiImagesPaletteResID`  
 A ID de recurso da lista de imagens para exibir na Galeria.  
  
 `cxPaletteImage`  
 Especifica a largura em pixels da imagem na Galeria.  
  
 `sizeIcon`  
 Especifica o tamanho, em pixels da imagem de galeria.  
  
 `nIconsNum`  
 Especifica o número de ícones na Galeria.  
  
 `bDefaultButtonStyle`  
 Especifica se deve usar o padrão ou o estilo de botão de desenho proprietário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enablemenuresize"></a>CMFCRibbonGallery::EnableMenuResize  
 Habilita ou desabilita o redimensionamento do painel do menu.  
  
```  
void EnableMenuResize(
    BOOL bEnable = TRUE,  
    BOOL bVertcalOnly = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para ativar redimensionamento menu; Caso contrário, `FALSE`.  
  
 [in] `bVertcalOnly`  
 `TRUE`para especificar que a Galeria pode ser redimensionada apenas verticalmente; `FALSE` especificar que a Galeria pode ser redimensionada tanto vertical e horizontalmente.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para ativar ou desativar o redimensionamento de galeria de faixa de opções. Quando o redimensionamento é habilitado, a Galeria de faixa de opções exibe uma alça que um usuário pode usar para redimensioná-la.  
  
##  <a name="enablemenusidebar"></a>CMFCRibbonGallery::EnableMenuSideBar  
 Habilita ou desabilita a barra lateral à esquerda do menu pop-up.  
  
```  
void EnablMenuSideBar(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`para especificar que a barra lateral está ativada. Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método para ativar ou desativar a barra lateral de estilo do Office XP no lado esquerdo do menu.  
  
##  <a name="getcompactsize"></a>CMFCRibbonGallery::GetCompactSize  

  
```  
virtual CSize GetCompactSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdroppeddown"></a>CMFCRibbonGallery::GetDroppedDown  

  
```  
virtual CMFCRibbonBaseElement* GetDroppedDown();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getgroupname"></a>CMFCRibbonGallery::GetGroupName  
 Retorna o nome do grupo que está localizado no índice especificado.  
  
```  
LPCTSTR GetGroupName(int nGroupIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nGroupIndex`  
 Especifica o índice com base em zero para o grupo cujo nome você deseja recuperar.  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do grupo localizado no índice especificado. Passar um índice inválido resultará em uma declaração com falha.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getgroupoffset"></a>CMFCRibbonGallery::GetGroupOffset  

  
```  
virtual int GetGroupOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="geticonsinrow"></a>CMFCRibbonGallery::GetIconsInRow  
 Retorna o número de itens em uma linha da Galeria de faixa de opções.  
  
```  
int GetIconsInRow() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de itens em uma linha.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getitemtooltip"></a>CMFCRibbonGallery::GetItemToolTip  
 Retorna o texto de dica de ferramenta que está associado um item da Galeria.  
  
```  
LPCTSTR GetItemToolTip(int nItemIndex) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nItemIndex`  
 Especifica o índice baseado em zero do item para o qual recuperar o texto de dica de ferramenta.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a cadeia de caracteres de dica de ferramenta atribuído a um item da Galeria de faixa de opções. Ele pode ser `NULL` se nenhuma dica de ferramenta é atribuída a esse item.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getlastselecteditem"></a>CMFCRibbonGallery::GetLastSelectedItem  
 Retorna o índice do último item na Galeria de faixa de opções que o usuário selecionado.  
  
```  
static int GetLastSelectedItem(UINT uiCmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Especifica a ID do item de menu que abriu a Galeria de faixa de opções de comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Quando o usuário seleciona um item da Galeria de faixa de opções, a biblioteca envia o `WM_COMMAND` mensagem com ID de comando do botão de menu que abriu a Galeria de faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpaletteid"></a>CMFCRibbonGallery::GetPaletteID  
 Retorna a ID de comando da paleta atual.  
  
```  
int GetPaletteID() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A ID de comando da paleta selecionada no momento.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getregularsize"></a>CMFCRibbonGallery::GetRegularSize  

  
```  
virtual CSize GetRegularSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getselecteditem"></a>CMFCRibbonGallery::GetSelectedItem  

  
```  
int GetSelectedItem() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hasmenu"></a>CMFCRibbonGallery::HasMenu  

  
```  
virtual BOOL HasMenu() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isbuttonmode"></a>CMFCRibbonGallery::IsButtonMode  
 Especifica se a paleta está contida em um botão da Galeria.  
  
```  
BOOL IsButtonMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a paleta é exibida como um botão de menu suspenso; `FALSE` se for exibida a paleta diretamente na faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenuresizeenabled"></a>CMFCRibbonGallery::IsMenuResizeEnabled  
 Especifica se o redimensionamento de menu está habilitado.  
  
```  
BOOL IsMenuResizeEnabled() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se tiver sido habilitado o redimensionamento do menu; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenuresizevertical"></a>CMFCRibbonGallery::IsMenuResizeVertical  

  
```  
BOOL IsMenuResizeVertical() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ismenusidebar"></a>CMFCRibbonGallery::IsMenuSideBar  
 Especifica se a barra lateral está habilitada ou desabilitada.  
  
```  
BOOL IsMenuSideBar() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra lateral de estilo do Office XP é desenhada no lado esquerdo do menu pop-up; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onafterchangerect"></a>CMFCRibbonGallery::OnAfterChangeRect  

  
```  
virtual void OnAfterChangeRect(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>CMFCRibbonGallery::OnDraw  

  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawpaletteicon"></a>CMFCRibbonGallery::OnDrawPaletteIcon  
 Chamado pela estrutura quando um ícone de galeria é desenhado.  
  
```  
virtual void OnDrawPaletteIcon(
    CDC* pDC,  
    CRect rectIcon,  
    int nIconIndex,  
    CMFCRibbonGalleryIcon* pIcon,  
    COLORREF clrText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para o contexto de dispositivo que é usado para o desenho.  
  
 [in] `rectIcon`  
 Especifica o retângulo delimitador do ícone para desenhar.  
  
 [in] `nIconIndex`  
 Especifica o índice baseado em zero na lista de imagens de ícones da Galeria do ícone para desenhar.  
  
 [in] `pIcon`  
 Um ponteiro para o ícone que está sendo desenhado.  
  
 [in] `clrText`  
 Especifica a cor do texto do item para desenhar.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir esse método em uma classe derivada para personalizar a aparência de uma galeria de faixa de opções.  
  
##  <a name="onenable"></a>CMFCRibbonGallery::OnEnable  

  
```  
virtual void OnEnable(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrtlchanged"></a>CMFCRibbonGallery::OnRTLChanged  

  
```  
virtual void OnRTLChanged(BOOL bIsRTL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bIsRTL`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="redrawicons"></a>CMFCRibbonGallery::RedrawIcons  
 Redesenha a Galeria.  
  
```  
void RedrawIcons();
```  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para redesenhar a Galeria. Você deve chamar este método se você tiver alterado o conteúdo da galeria no tempo de execução.  
  
##  <a name="removeitemtooltips"></a>CMFCRibbonGallery::RemoveItemToolTips  
 Remove todos os itens na Galeria de dicas de ferramentas.  
  
```  
void RemoveItemToolTips();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="selectitem"></a>CMFCRibbonGallery::SelectItem  

  
```  
void SelectItem(int nItemIndex);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nItemIndex`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setaccdata"></a>CMFCRibbonGallery::SetACCData  
 Preenche especificado `CAccessibilityData` objeto usando dados de acessibilidade da Galeria de faixa de opções.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,   
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParent`  
 A janela pai da janela Galeria de faixa de opções.  
  
 [out] `data`  
 Um `CAccessibilityData` objeto que recebe os dados de acessibilidade da Galeria de faixa de opções.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 `TRUE` se o método for bem-sucedido; caso contrário, `FALSE`.  
  
##  <a name="setbuttonmode"></a>CMFCRibbonGallery::SetButtonMode  
 Determina se deve exibir a Galeria de faixa de opções, como um botão de lista suspensa ou uma paleta diretamente na faixa de opções.  
  
```  
void SetButtonMode(BOOL bSet=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 `TRUE`Para exibir a Galeria de faixa de opções como um botão de menu suspenso; `FALSE` para exibir o conteúdo da Galeria de faixa de opções diretamente na faixa de opções.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setgroupname"></a>CMFCRibbonGallery::SetGroupName  
 Define o nome de um grupo.  
  
```  
void SetGroupName(
    int nGroupIndex,  
    LPCTSTR lpszGroupName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nGroupIndex`  
 Especifica o índice com base em zero para o grupo para o qual o nome está sendo alterado.  
  
 [in] `lpszGroupName`  
 Especifica o novo nome para o grupo.  
  
### <a name="remarks"></a>Comentários  
 O grupo cujo nome está sendo alterado deve ter sido adicionado usando o [CMFCRibbonGallery::AddGroup](#addgroup) método.  
  
##  <a name="seticonsinrow"></a>CMFCRibbonGallery::SetIconsInRow  
 Especifica o número de itens por linha na Galeria.  
  
```  
void SetIconsInRow(int nIconsInRow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nIconsInRow`  
 Especifica o número de itens apareçam em cada linha da Galeria.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para especificar a largura da Galeria de faixa de opções.  
  
##  <a name="setitemtooltip"></a>CMFCRibbonGallery::SetItemToolTip  
 Define o texto de dica de ferramenta para um item da Galeria.  
  
```  
void SetItemToolTip(
    int nItemIndex,  
    LPCTSTR lpszToolTip);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nItemIndex`  
 O índice baseado em zero do item da paleta ao qual associar a dica de ferramenta.  
  
 [in] `lpszToolTip`  
 O texto exibido na dica de ferramenta.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpalette"></a>CMFCRibbonGallery::SetPalette  
 Anexa uma paleta de uma galeria de faixa de opções.  
  
```  
void SetPalette(CMFCToolBarImages& imagesPalette);

 
void SetPalette(
    UINT uiImagesPaletteResID,  
    int cxPaletteImage);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `imagesPalette`  
 Especifica a lista de imagens que contém os ícones apareçam na Galeria.  
  
 [in] `uiImagesPaletteResID`  
 Especifica a ID de recurso da lista de imagens que contém os ícones apareçam na Galeria.  
  
 [in] `cxPaletteImage`  
 Especifica a largura, em pixels, de uma imagem na Galeria.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpaletteid"></a>CMFCRibbonGallery::SetPaletteID  
 Define a ID do comando enviado no **WM_COMMAND** mensagem quando um usuário seleciona um item da Galeria.  
  
```  
void SetPaletteID(UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Especifica a ID de comando que é enviada no **WM_COMMAND** mensagem quando um usuário seleciona um item da Galeria.  
  
### <a name="remarks"></a>Comentários  
 Para determinar o item específico que um usuário selecionou da galeria, chame o [CMFCRibbonGallery::GetLastSelectedItem](#getlastselecteditem) método estático.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)   
 [Classe CMFCRibbonGalleryMenuButton](../../mfc/reference/cmfcribbongallerymenubutton-class.md)

