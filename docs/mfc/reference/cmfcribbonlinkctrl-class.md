---
title: Classe CMFCRibbonLinkCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonLinkCtrl
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::CMFCRibbonLinkCtrl
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::CopyFrom
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::GetCompactSize
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::GetLink
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::GetRegularSize
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::GetToolTipText
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::IsDrawTooltipImage
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::OnDraw
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::OnDrawMenuImage
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::OnMouseMove
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::OnSetIcon
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::OpenLink
- AFXRIBBONLINKCTRL/CMFCRibbonLinkCtrl::SetLink
helpviewer_keywords:
- CMFCRibbonLinkCtrl [MFC], CMFCRibbonLinkCtrl
- CMFCRibbonLinkCtrl [MFC], CopyFrom
- CMFCRibbonLinkCtrl [MFC], GetCompactSize
- CMFCRibbonLinkCtrl [MFC], GetLink
- CMFCRibbonLinkCtrl [MFC], GetRegularSize
- CMFCRibbonLinkCtrl [MFC], GetToolTipText
- CMFCRibbonLinkCtrl [MFC], IsDrawTooltipImage
- CMFCRibbonLinkCtrl [MFC], OnDraw
- CMFCRibbonLinkCtrl [MFC], OnDrawMenuImage
- CMFCRibbonLinkCtrl [MFC], OnMouseMove
- CMFCRibbonLinkCtrl [MFC], OnSetIcon
- CMFCRibbonLinkCtrl [MFC], OpenLink
- CMFCRibbonLinkCtrl [MFC], SetLink
ms.assetid: 77ae1941-e0ab-4a9d-911e-1752d34c079b
ms.openlocfilehash: bc13cf29fd9fed9f91221f00d4b605b3d9c3506f
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58772391"
---
# <a name="cmfcribbonlinkctrl-class"></a>Classe CMFCRibbonLinkCtrl

Implementa um hiperlink que está posicionado em uma faixa de opções. O hiperlink abre uma página da Web quando você clica nele.
Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonLinkCtrl : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonLinkCtrl::CMFCRibbonLinkCtrl](#cmfcribbonlinkctrl)|Constrói e inicializa um objeto `CMFCRibbonLinkCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonLinkCtrl::CopyFrom](#copyfrom)|(Substitui `CMFCRibbonButton::CopyFrom`.)|
|[CMFCRibbonLinkCtrl::GetCompactSize](#getcompactsize)|(Substitui [CMFCRibbonButton::GetCompactSize](../../mfc/reference/cmfcribbonbutton-class.md#getcompactsize).)|
|[CMFCRibbonLinkCtrl::GetLink](#getlink)|Retorna o valor do hiperlink.|
|[CMFCRibbonLinkCtrl::GetRegularSize](#getregularsize)|(Substitui [CMFCRibbonButton::GetRegularSize](../../mfc/reference/cmfcribbonbutton-class.md#getregularsize).)|
|[CMFCRibbonLinkCtrl::GetToolTipText](#gettooltiptext)|(Substitui [CMFCRibbonButton::GetToolTipText](../../mfc/reference/cmfcribbonbutton-class.md#gettooltiptext).)|
|[CMFCRibbonLinkCtrl::IsDrawTooltipImage](#isdrawtooltipimage)|(Substitui `CMFCRibbonButton::IsDrawTooltipImage`.)|
|[CMFCRibbonLinkCtrl::OnDraw](#ondraw)|(Substitui [CMFCRibbonButton::OnDraw](../../mfc/reference/cmfcribbonbutton-class.md#ondraw).)|
|[CMFCRibbonLinkCtrl::OnDrawMenuImage](#ondrawmenuimage)|(Substitui [CMFCRibbonBaseElement::OnDrawMenuImage](../../mfc/reference/cmfcribbonbaseelement-class.md#ondrawmenuimage).)|
|[CMFCRibbonLinkCtrl::OnMouseMove](#onmousemove)|(Substitui `CMFCRibbonButton::OnMouseMove`.)|
|[CMFCRibbonLinkCtrl::OnSetIcon](#onseticon)||
|[CMFCRibbonLinkCtrl::OpenLink](#openlink)|Abre a página da Web especificada no hiperlink.|
|[CMFCRibbonLinkCtrl::SetLink](#setlink)|Define o valor do hiperlink.|

## <a name="remarks"></a>Comentários

Depois de criar um hiperlink, adicioná-lo a um painel chamando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md) [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md) [CMFCRibbonLinkCtrl](../../mfc/reference/cmfcribbonlinkctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonLinkCtrl.h

##  <a name="cmfcribbonlinkctrl"></a>  CMFCRibbonLinkCtrl::CMFCRibbonLinkCtrl

Constrói e inicializa um [CMFCRibbonLinkCtrl](../../mfc/reference/cmfcribbonlinkctrl-class.md) objeto.

```
CMFCRibbonLinkCtrl(
    UINT nID,
    LPCTSTR lpszText,
    LPCTSTR lpszLink);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[in] Especifica a ID de comando do comando que é executado quando o controle de link é clicado.

*lpszText*<br/>
[in] Especifica o rótulo a ser exibido no controle de link.

*lpszLink*<br/>
[in] Especifica o hiperlink associado ao controle de link.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o construtor do `CMFCRibbonLinkCtrl` classe. Este trecho de código é parte do [exemplo de Gadgets de faixa de opções](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_RibbonGadgets#1](../../mfc/reference/codesnippet/cpp/cmfcribbonlinkctrl-class_1.cpp)]

##  <a name="copyfrom"></a>  CMFCRibbonLinkCtrl::CopyFrom

```
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```

### <a name="parameters"></a>Parâmetros

[in] *src*<br/>

### <a name="remarks"></a>Comentários

##  <a name="getcompactsize"></a>  CMFCRibbonLinkCtrl::GetCompactSize

```
virtual CSize GetCompactSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getlink"></a>  CMFCRibbonLinkCtrl::GetLink

Retorna o valor do hiperlink.

```
LPCTSTR GetLink() const;
```

### <a name="return-value"></a>Valor de retorno

O valor atual do hiperlink.

### <a name="remarks"></a>Comentários

##  <a name="getregularsize"></a>  CMFCRibbonLinkCtrl::GetRegularSize

```
virtual CSize GetRegularSize(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="gettooltiptext"></a>  CMFCRibbonLinkCtrl::GetToolTipText

```
virtual CString GetToolTipText() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ondrawmenuimage"></a>  CMFCRibbonLinkCtrl::OnDrawMenuImage

```
virtual BOOL OnDrawMenuImage(CDC*, CRect);
```

### <a name="parameters"></a>Parâmetros

[in] *CDC&#42;*<br/>
[in] *CRect*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="isdrawtooltipimage"></a>  CMFCRibbonLinkCtrl::IsDrawTooltipImage

```
virtual BOOL IsDrawTooltipImage() const;
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="ondraw"></a>  CMFCRibbonLinkCtrl::OnDraw

```
virtual void OnDraw(CDC* pDC);
```

### <a name="parameters"></a>Parâmetros

[in] *pDC*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onmousemove"></a>  CMFCRibbonLinkCtrl::OnMouseMove

```
virtual void OnMouseMove(CPoint point);
```

### <a name="parameters"></a>Parâmetros

[in] *point*<br/>

### <a name="remarks"></a>Comentários

##  <a name="onseticon"></a>  CMFCRibbonLinkCtrl::OnSetIcon

```
virtual void OnSetIcon();
```

### <a name="remarks"></a>Comentários

##  <a name="openlink"></a>  CMFCRibbonLinkCtrl::OpenLink

Abre a página da Web especificada no hiperlink.

```
BOOL OpenLink();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a página da Web associada foi aberta com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Abre uma página da Web usando o hiperlink associado a `CMFCRibbonLinkCtrl` objeto.

##  <a name="setlink"></a>  CMFCRibbonLinkCtrl::SetLink

Define o valor do hiperlink.

```
void SetLink(LPCTSTR lpszLink);
```

### <a name="parameters"></a>Parâmetros

*lpszLink*<br/>
[in] Especifica o texto do hiperlink.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
