---
title: Classe CMFCRibbonColorButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::CMFCRibbonColorButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::AddColorsGroup
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::EnableAutomaticButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::EnableOtherButton
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetAutomaticColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColorBoxSize
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetColumns
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::GetHighlightedColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::RemoveAllColorGroups
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColor
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColorBoxSize
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColorName
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetColumns
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetDocumentColors
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::SetPalette
- AFXRIBBONCOLORBUTTON/CMFCRibbonColorButton::UpdateColor
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonColorButton class
ms.assetid: 6b4b4ee3-8cc0-41b4-a4eb-93e8847008e1
caps.latest.revision: 36
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
ms.openlocfilehash: 8cef76fd3518e1123cb9afd0c8cc2a39b2bff65c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribboncolorbutton-class"></a>Classe CMFCRibbonColorButton
O `CMFCRibbonColorButton` classe implementa um botão de cor que você pode adicionar a uma barra de faixa de opções. Botão de cor da faixa de opções exibe um menu suspenso que contém uma ou mais paletas de cores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonColorButton : public CMFCRibbonGallery  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonColorButton::CMFCRibbonColorButton](#cmfcribboncolorbutton)||  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonColorButton::AddColorsGroup](#addcolorsgroup)|Adiciona um grupo de cores para a área de cores normal.|  
|[CMFCRibbonColorButton::EnableAutomaticButton](#enableautomaticbutton)|Especifica se o **automáticas** botão é habilitado.|  
|[CMFCRibbonColorButton::EnableOtherButton](#enableotherbutton)|Permite que o **outros** botão.|  
|[CMFCRibbonColorButton::GetAutomaticColor](#getautomaticcolor)||  
|[CMFCRibbonColorButton::GetColor](#getcolor)|Retorna a cor selecionada atualmente.|  
|[CMFCRibbonColorButton::GetColorBoxSize](#getcolorboxsize)|Retorna o tamanho dos elementos da cor que aparecem na barra de cores.|  
|[CMFCRibbonColorButton::GetColumns](#getcolumns)||  
|[CMFCRibbonColorButton::GetHighlightedColor](#gethighlightedcolor)|Retorna a cor do elemento atualmente selecionado na paleta de cores pop-up.|  
|[CMFCRibbonColorButton::RemoveAllColorGroups](#removeallcolorgroups)|Remove todos os grupos de cores da área de cores normal.|  
|[CMFCRibbonColorButton::SetColor](#setcolor)|Seleciona uma cor da área de cores normal.|  
|[CMFCRibbonColorButton::SetColorBoxSize](#setcolorboxsize)|Define o tamanho de todos os elementos de cor que aparecem na barra de cores.|  
|[CMFCRibbonColorButton::SetColorName](#setcolorname)||  
|[CMFCRibbonColorButton::SetColumns](#setcolumns)||  
|[CMFCRibbonColorButton::SetDocumentColors](#setdocumentcolors)|Especifica uma lista de valores RGB para exibir na área de cor do documento.|  
|[CMFCRibbonColorButton::SetPalette](#setpalette)||  
|[CMFCRibbonColorButton::UpdateColor](#updatecolor)||  
  
## <a name="remarks"></a>Comentários  
 Botão de cor da faixa de opções exibe uma barra de cores quando um usuário pressiona ele. Por padrão, a barra de cores contém uma paleta de seleção de cor chamada área de cores normal. Opcionalmente, a barra de cores pode exibir um **automáticas** botão, que permite ao usuário selecionar uma cor padrão, e uma **outros** botão, que exibe uma paleta de cores pop-up que contém cores adicionais.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCRibbonColorButton` classe. O exemplo mostra como construir um `CMFCRibbonColorButton` de objeto, definir a imagem grande, habilitar o **automáticas** botão, habilite o **outros** botão, defina o número de colunas, defina o tamanho de todos os elementos de cor que aparecem na barra de cores, adicionar um grupo de cores para a área de cores normal e especificar uma lista de valores RGB para exibir na área de cor do documento. Este trecho de código é parte do [desenhar cliente de exemplo](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DrawClient n º&3;](../../mfc/reference/codesnippet/cpp/cmfcribboncolorbutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)  
  
 [CMFCRibbonColorButton](../../mfc/reference/cmfcribboncolorbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxribboncolorbutton.h  
  
##  <a name="addcolorsgroup"></a>CMFCRibbonColorButton::AddColorsGroup  
 Adiciona um grupo de cores para a área de cores normal.  
  
```  
void AddColorsGroup(
    LPCTSTR lpszName,  
    const CList<COLORREF,COLORREF>& lstColors,  
    BOOL bContiguousColumns=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome do grupo.  
  
 [in] `lstColors`  
 A lista de cores.  
  
 [in] `bContiguousColumns`  
 Controla como os itens de cor são exibidos no grupo. Se `TRUE`, os itens de cor são desenhados sem um espaçamento vertical. Se `FALSE`, os itens de cor são desenhados com um espaçamento vertical.  
  
### <a name="remarks"></a>Comentários  
 Use essa função para tornar a cor pop-up Exibir vários grupos de cores. Você pode controlar como as cores são exibidas no grupo.  
  
##  <a name="cmfcribboncolorbutton"></a>CMFCRibbonColorButton::CMFCRibbonColorButton  
 Constrói um objeto `CMFCRibbonColorButton`.  
  
```  
CMFCRibbonColorButton();

 
CMFCRibbonColorButton(
    UINT nID,  
    LPCTSTR lpszText,  
    int nSmallImageIndex,  
    COLORREF color = RGB(0, 0, 0));

 
CMFCRibbonColorButton(
    UINT nID,  
    LPCTSTR lpszText,  
    BOOL bSimpleButtonLook,  
    int nSmallImageIndex,  
    int nLargeImageIndex,  
    COLORREF color = RGB(0, 0, 0));
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 Especifica a ID de comando do comando a ser executada quando um usuário clica no botão.  
  
 [in] `lpszText`  
 Especifica o texto a ser exibido no botão.  
  
 [in] `nSmallImageIndex`  
 O índice baseado em zero da pequena imagem apareça no botão.  
  
 [in] `color`  
 A cor do botão (o padrão é preto).  
  
 [in] `bSimpleButtonLook`  
 Se `TRUE`, o botão é desenhado como um retângulo simples.  
  
 [in] `nLargeImageIndex`  
 O índice baseado em zero da imagem apareça no botão grande.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enableautomaticbutton"></a>CMFCRibbonColorButton::EnableAutomaticButton  
 Especifica se o **automáticas** botão é habilitado.  
  
```  
void EnableAutomaticButton(
    LPCTSTR lpszLabel,  
    COLORREF colorAutomatic,  
    BOOL bEnable=TRUE,  
    LPCTSTR lpszToolTip=NULL,  
    BOOL bOnTop=TRUE,  
    BOOL bDrawBorder=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 O rótulo para o **automáticas** botão.  
  
 [in] `colorAutomatic`  
 Um valor RGB que especifica o **automáticas** cor padrão do botão.  
  
 [in] `bEnable`  
 `TRUE`Se o **automáticas** botão é habilitado; `FALSE` se ele estiver desabilitado.  
  
 [in] `lpszToolTip`  
 A dica de ferramenta a **automáticas** botão.  
  
 [in] `bOnTop`  
 Especifica se o **automáticas** botão está no topo, antes da paleta de cores.  
  
 [in] `bDrawBorder`  
 `TRUE`Se o aplicativo desenha uma borda ao redor da barra de cores do botão de cor da faixa de opções. Na barra de cores exibe a cor selecionada atualmente. `FALSE`Se o aplicativo não desenha uma borda  
  
##  <a name="enableotherbutton"></a>CMFCRibbonColorButton::EnableOtherButton  
 Permite que o **outros** botão.  
  
```  
void EnableOtherButton(
    LPCTSTR lpszLabel,  
    LPCTSTR lpszToolTip=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszLabel`  
 O rótulo do botão.  
  
 `lpszToolTip`  
 O texto de dica de ferramenta para o **outros** botão.  
  
### <a name="remarks"></a>Comentários  
 O **outros** botão é o que é exibido abaixo do grupo de cores. Quando o usuário clica o **outros** botão, ele exibe uma caixa de diálogo de cor.  
  
##  <a name="getautomaticcolor"></a>CMFCRibbonColorButton::GetAutomaticColor  
 Recupera a cor atual do botão automático.  
  
```  
COLORREF GetAutomaticColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de cor RGB que representa a cor atual do botão automático.  
  
### <a name="remarks"></a>Comentários  
 A cor do botão automático é definida pelo `colorAutomatic` parâmetro passado para o `CMFCRibbonColorButton::EnableAutomaticButton` método.  
  
##  <a name="getcolor"></a>CMFCRibbonColorButton::GetColor  
 Retorna a cor selecionada atualmente.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor selecionada, clique no botão.  
  
##  <a name="getcolorboxsize"></a>CMFCRibbonColorButton::GetColorBoxSize  
 Retorna o tamanho dos elementos da cor que aparecem na barra de cores.  
  
```  
CSize GetColorBoxSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho dos botões de cor na paleta de cores da lista suspensa.  
  
##  <a name="getcolumns"></a>CMFCRibbonColorButton::GetColumns  
 Obtém o número de itens em uma linha da exibição de galeria do botão de cor da faixa de opções.  
  
```  
int GetColumns() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o número de ícones em cada linha.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethighlightedcolor"></a>CMFCRibbonColorButton::GetHighlightedColor  
 Retorna a cor do elemento atualmente selecionado na paleta de cores pop-up.  
  
```  
COLORREF GetHighlightedColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A cor do elemento atualmente selecionado na paleta de cores pop-up.  
  
##  <a name="removeallcolorgroups"></a>CMFCRibbonColorButton::RemoveAllColorGroups  
 Remove todos os grupos de cores da área de cores normal.  
  
```  
void RemoveAllColorGroups();
```  
  
##  <a name="setcolor"></a>CMFCRibbonColorButton::SetColor  
 Seleciona uma cor da área de cores normal.  
  
```  
void SetColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 Uma cor a ser definido.  
  
##  <a name="setcolorboxsize"></a>CMFCRibbonColorButton::SetColorBoxSize  
 Define o tamanho de todos os elementos de cor que aparecem na barra de cores.  
  
```  
void SetColorBoxSize(CSize sizeBox);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `sizeBox`  
 O novo tamanho dos botões de cor na paleta de cores.  
  
##  <a name="setcolorname"></a>CMFCRibbonColorButton::SetColorName  
 Define um novo nome para uma cor especificada.  
  
```  
static void __stdcall SetColorName(
    COLORREF color,  
    const CString& strName);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 O valor RGB de uma cor.  
  
 [in] `strName`  
 O novo nome para a cor especificada.  
  
### <a name="remarks"></a>Comentários  
 Porque chama `CMFCColorBar::SetColorName`, esse método altera o nome da cor especificada em todos os `CMFCColorBar` objetos em seu aplicativo.  
  
##  <a name="setcolumns"></a>CMFCRibbonColorButton::SetColumns  
 Define o número de colunas exibidas na tabela de cores é apresentada ao usuário durante o processo de seleção de cor do usuário.  
  
```  
void SetColumns(int nColumns);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nColumns`  
 O número de ícones de cor para exibir em cada linha.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setdocumentcolors"></a>CMFCRibbonColorButton::SetDocumentColors  
 Especifica uma lista de valores RGB para exibir na área de cor do documento.  
  
```  
void SetDocumentColors(
    LPCTSTR lpszLabel,  
    CList<COLORREF,COLORREF>& lstColors);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszLabel`  
 O texto a ser exibido com as cores do documento.  
  
 [in] `lstColors`  
 Uma referência a uma lista de valores RGB.  
  
##  <a name="setpalette"></a>CMFCRibbonColorButton::SetPalette  
 Especifica as cores padrão para exibir na tabela de cores exibe o botão de cor.  
  
```  
void SetPalette(CPalette* pPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pPalette`  
 Um ponteiro para uma paleta de cores.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="updatecolor"></a>CMFCRibbonColorButton::UpdateColor  
 Chamado pela estrutura quando o usuário seleciona uma cor da tabela de cores exibida quando o usuário clica no botão de cor.  
  
```  
void UpdateColor(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `color`  
 A cor selecionada pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCRibbonColorButton::UpdateColor` método altera a cor do botão selecionado atualmente e notifica seus pais, enviando uma `WM_COMMAND` de mensagem com um `BN_CLICKED` notificação padrão. Use o [CMFCRibbonColorButton::GetColor](#getcolor) método para recuperar a cor selecionada.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonGallery](../../mfc/reference/cmfcribbongallery-class.md)

