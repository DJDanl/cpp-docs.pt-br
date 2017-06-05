---
title: Classe CMFCAutoHideButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCAutoHideButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::BringToTop
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::Create
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetAlignment
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetAutoHideWindow
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetParentToolBar
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetRect
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetSize
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::GetTextSize
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::HighlightButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsActive
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsHighlighted
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsHorizontal
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsTop
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::IsVisible
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::Move
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnDraw
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnDrawBorder
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::OnFillBackground
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ReplacePane
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ShowAttachedWindow
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::ShowButton
- AFXAUTOHIDEBUTTON/CMFCAutoHideButton::UnSetAutoHideMode
dev_langs:
- C++
helpviewer_keywords:
- CMFCAutoHideButton class
ms.assetid: c80e6b8b-25ca-4d12-9d27-457731028ab0
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: f25072b4362b6add1682ce50fc5ee21cc065637a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcautohidebutton-class"></a>Classe CMFCAutoHideButton
Um botão que exibe ou oculta uma [CDockablePane classe](../../mfc/reference/cdockablepane-class.md) que é configurado para ocultar.  

 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]    
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCAutoHideButton : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAutoHideButton::BringToTop](#bringtotop)||  
|[CMFCAutoHideButton::Create](#create)|Cria e inicializa o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetAlignment](#getalignment)|Recupera o alinhamento do botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetAutoHideWindow](#getautohidewindow)|Retorna o [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto associado com o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetParentToolBar](#getparenttoolbar)||  
|[CMFCAutoHideButton::GetRect](#getrect)||  
|[CMFCAutoHideButton::GetSize](#getsize)|Determina o tamanho do botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::GetTextSize](#gettextsize)|Retorna o tamanho do rótulo do texto do botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::HighlightButton](#highlightbutton)|Destaques automaticamente o botão Ocultar.|  
|[CMFCAutoHideButton::IsActive](#isactive)|Indica se o botão Ocultar automaticamente está ativo.|  
|[CMFCAutoHideButton::IsHighlighted](#ishighlighted)|Retorna o estado do botão Ocultar automaticamente de realce.|  
|[CMFCAutoHideButton::IsHorizontal](#ishorizontal)|Determina se o botão Ocultar automaticamente é horizontal ou vertical.|  
|[CMFCAutoHideButton::IsTop](#istop)||  
|[CMFCAutoHideButton::IsVisible](#isvisible)|Indica se o botão estiver visível.|  
|[CMFCAutoHideButton::Move](#move)||  
|[CMFCAutoHideButton::OnDraw](#ondraw)|O framework chama esse método quando ele se baseia no botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::OnDrawBorder](#ondrawborder)|O framework chama esse método quando ele desenha a borda de um botão de ocultar automaticamente.|  
|[CMFCAutoHideButton::OnFillBackground](#onfillbackground)|O framework chama esse método quando ele é preenchido o plano de fundo de um botão de ocultar automaticamente.|  
|[CMFCAutoHideButton::ReplacePane](#replacepane)||  
|[CMFCAutoHideButton::ShowAttachedWindow](#showattachedwindow)|Mostra ou oculta associado [CDockablePane classe](../../mfc/reference/cdockablepane-class.md).|  
|[CMFCAutoHideButton::ShowButton](#showbutton)|Mostra ou oculta o botão Ocultar automaticamente.|  
|[CMFCAutoHideButton::UnSetAutoHideMode](#unsetautohidemode)||  
  
## <a name="remarks"></a>Comentários  
 Na criação, o `CMFCAutoHideButton` objeto está anexado a um [CDockablePane classe](../../mfc/reference/cdockablepane-class.md). O `CDockablePane` objeto é ocultado ou exibido conforme o usuário interage com o `CMFCAutoHideButton` objeto.  
  
 Por padrão, o framework cria automaticamente um `CMFCAutoHideButton` quando o usuário ativa de ocultar automaticamente. A estrutura pode criar um elemento de uma classe de interface do usuário personalizada em vez do `CMFCAutoHideButton` classe. Para especificar qual classe da interface do usuário personalizada deve usar a estrutura, defina a variável de membro estático `CMFCAutoHideBar::m_pAutoHideButtonRTS` igual a classe de interface do usuário personalizada. Por padrão, essa variável é definida como `CMFCAutoHideButton`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCAutoHideButton` de objeto e usar vários métodos no `CMFCAutoHideButton` classe. O exemplo mostra como inicializar um `CMFCAutoHideButton` objeto usando seu `Create` método, Mostrar associado `CDockablePane` classe e mostrar o botão Ocultar automaticamente.  
  
 [!code-cpp[32 NVC_MFC_RibbonApp](../../mfc/reference/codesnippet/cpp/cmfcautohidebutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CMFCAutoHideButton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxautohidebutton.h  
  
##  <a name="bringtotop"></a>CMFCAutoHideButton::BringToTop  

  
```  
void BringToTop();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="create"></a>CMFCAutoHideButton::Create  
 Cria e inicializa um botão Ocultar automaticamente.  
  
```  
virtual BOOL Create(
    CMFCAutoHideBar* pParentBar,  
    CDockablePane* pAutoHideWnd,  
    DWORD dwAlignment);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pParentBar`  
 Um ponteiro para a barra de ferramentas do pai.  
  
 [in] `pAutoHideWnd`  
 Um ponteiro para um [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto. Esse botão Ocultar automaticamente oculta e mostra que `CDockablePane`.  
  
 [in] `dwAlignment`  
 Um valor que especifica o alinhamento do botão com a janela do quadro principal.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Quando você cria um `CMFCAutoHideButton` do objeto, você deve associar o botão Ocultar automaticamente um determinado `CDockablePane`. O usuário pode usar o botão Ocultar automaticamente para ocultar e mostrar associado `CDockablePane`.  
  
 O `dwAlignment` parâmetro indica onde o botão Ocultar automaticamente reside no aplicativo. O parâmetro pode ser qualquer um dos seguintes valores:  
  
- `CBRS_ALIGN_LEFT`  
  
- `CBRS_ALIGN_RIGHT`  
  
- `CBRS_ALIGN_TOP`  
  
- `CBRS_ALIGN_BOTTOM`  
  
##  <a name="getalignment"></a>CMFCAutoHideButton::GetAlignment  
 Recupera o alinhamento do botão Ocultar automaticamente.  
  
```  
DWORD GetAlignment() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `DWORD` valor que contém o alinhamento atual do botão Ocultar automaticamente.  
  
### <a name="remarks"></a>Comentários  
 O alinhamento do botão Ocultar automaticamente indica onde o botão reside no aplicativo. Ele pode ser qualquer um dos seguintes valores:  
  
- `CBRS_ALIGN_LEFT`  
  
- `CBRS_ALIGN_RIGHT`  
  
- `CRBS_ALIGN_TOP`  
  
- `CBRS_ALIGN_BOTTOM`  
  
##  <a name="getautohidewindow"></a>CMFCAutoHideButton::GetAutoHideWindow  
 Retorna o [CDockablePane](../../mfc/reference/cdockablepane-class.md) objeto associado com o botão Ocultar automaticamente.  
  
```  
CDockablePane* GetAutoHideWindow() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro associados `CDockablePane` objeto.  
  
### <a name="remarks"></a>Comentários  
 Para associar um botão de ocultar automaticamente com um `CDockablePane`, passar o `CDockablePane` como um parâmetro para o [CMFCAutoHideButton::Create](#create) método.  
  
##  <a name="getparenttoolbar"></a>CMFCAutoHideButton::GetParentToolBar  

  
```  
CMFCAutoHideBar* GetParentToolBar();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getrect"></a>CMFCAutoHideButton::GetRect  

  
```  
CRect GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsize"></a>CMFCAutoHideButton::GetSize  
 Determina o tamanho do botão Ocultar automaticamente.  
  
```  
CSize GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CSize` objeto que contém o tamanho do botão.  
  
### <a name="remarks"></a>Comentários  
 O tamanho calculado inclui o tamanho da borda do botão Ocultar automaticamente.  
  
##  <a name="gettextsize"></a>CMFCAutoHideButton::GetTextSize  
 Retorna o tamanho do rótulo do texto do botão Ocultar automaticamente.  
  
```  
virtual CSize GetTextSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o tamanho do texto do botão Ocultar automaticamente.  
  
##  <a name="isactive"></a>CMFCAutoHideButton::IsActive  
 Indica se o botão Ocultar automaticamente está ativo.  
  
```  
BOOL IsActive() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão Ocultar automaticamente estiver ativo; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Um botão Ocultar automaticamente está ativo quando associado [CDockablePane classe](../../mfc/reference/cdockablepane-class.md) janela é mostrada.  
  
##  <a name="ishorizontal"></a>CMFCAutoHideButton::IsHorizontal  
 Determina se o botão Ocultar automaticamente é horizontal ou vertical.  
  
```  
BOOL IsHorizontal() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o botão é horizontal; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A estrutura define a orientação de um [CMFCAutoHideButton](../../mfc/reference/cmfcautohidebutton-class.md) objeto quando você criá-lo.  Você pode controlar a orientação usando o `dwAlignment` parâmetro o [CMFCAutoHideButton::Create](#create) método.  
  
##  <a name="istop"></a>CMFCAutoHideButton::IsTop  

  
```  
BOOL IsTop() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="isvisible"></a>CMFCAutoHideButton::IsVisible  
 Indica se o botão Ocultar automaticamente está visível.  
  
```  
virtual BOOL IsVisible() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o botão estiver visível; `FALSE` caso contrário.  
  
##  <a name="ondraw"></a>CMFCAutoHideButton::OnDraw  
 O framework chama esse método quando ele se baseia no botão Ocultar automaticamente.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser personalizar a aparência dos botões de ocultar automaticamente em seu aplicativo, crie uma nova classe derivada de `CMFCAutoHideButton`. Em sua classe derivada, substitua este método.  
  
##  <a name="ondrawborder"></a>CMFCAutoHideButton::OnDrawBorder  
 O framework chama esse método quando ele desenha a borda de um botão de ocultar automaticamente.  
  
```  
virtual void OnDrawBorder(
    CDC* pDC,  
    CRect rectBounds,  
    CRect rectBorderSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rectBounds`  
 O retângulo delimitador do botão Ocultar automaticamente.  
  
 [in] `rectBorderSize`  
 A espessura da borda de cada lado do botão Ocultar automaticamente.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser personalizar a borda de cada botão Ocultar automaticamente em seu aplicativo, crie uma nova classe que deriva de `CMFCAutoHideButton`. Em sua classe derivada, substitua este método.  
  
##  <a name="onfillbackground"></a>CMFCAutoHideButton::OnFillBackground  
 O framework chama esse método quando ele é preenchido o plano de fundo de um botão de ocultar automaticamente.  
  
```  
virtual void OnFillBackground(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 O retângulo delimitador do botão Ocultar automaticamente.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser personalizar o plano de fundo para botões de ocultar automaticamente em seu aplicativo, crie uma nova classe que deriva de `CMFCAutoHideButton`. Em sua classe derivada, substitua este método.  
  
##  <a name="showattachedwindow"></a>CMFCAutoHideButton::ShowAttachedWindow  
 Mostra ou oculta associado [CDockablePane classe](../../mfc/reference/cdockablepane-class.md).  
  
```  
void ShowAttachedWindow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Um valor booleano que especifica se esse método mostra o arquivo `CDockablePane`.  
  
##  <a name="showbutton"></a>CMFCAutoHideButton::ShowButton  
 Mostra ou oculta o botão Ocultar automaticamente.  
  
```  
virtual void ShowButton(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bShow`  
 Um valor booleano que especifica se deve mostrar o botão Ocultar automaticamente.  
  
##  <a name="move"></a>CMFCAutoHideButton::Move  

  
```  
void Move(int nOffset);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nOffset`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="replacepane"></a>CMFCAutoHideButton::ReplacePane  

  
```  
void ReplacePane(CDockablePane* pNewBar);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pNewBar`  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="unsetautohidemode"></a>CMFCAutoHideButton::UnSetAutoHideMode  
 Desabilite o modo de ocultar automaticamente.  
  
```  
virtual void UnSetAutoHideMode(CDockablePane* pFirstBarInGroup);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pFirstBarInGroup`  
 Um ponteiro para a primeira barra no grupo.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="highlightbutton"></a>CMFCAutoHideButton::HighlightButton  
 Realça o botão Ocultar automaticamente.  
  
```  
virtual void HighlightButton(BOOL bHighlight);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bHighlight`  
 Especifica o novo AutoOcultar estado do botão. `TRUE`indica que o botão é realçado, `FALSE` indica que o botão não esteja realçado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ishighlighted"></a>CMFCAutoHideButton::IsHighlighted  
 Retorna o estado de realce do botão Ocultar automaticamente.  
  
```  
virtual BOOL IsHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o botão Ocultar automaticamente é realçada; caso contrário `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCAutoHideBar](../../mfc/reference/cmfcautohidebar-class.md)   
 [Classe CAutoHideDockSite](../../mfc/reference/cautohidedocksite-class.md)

