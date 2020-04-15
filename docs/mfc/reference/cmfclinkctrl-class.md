---
title: Classe CMFCLinkCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCLinkCtrl
- AFXLINKCTRL/CMFCLinkCtrl
- AFXLINKCTRL/CMFCLinkCtrl::SetURL
- AFXLINKCTRL/CMFCLinkCtrl::SetURLPrefix
- AFXLINKCTRL/CMFCLinkCtrl::SizeToContent
- AFXLINKCTRL/CMFCLinkCtrl::OnDrawFocusRect
helpviewer_keywords:
- CMFCLinkCtrl [MFC], SetURL
- CMFCLinkCtrl [MFC], SetURLPrefix
- CMFCLinkCtrl [MFC], SizeToContent
- CMFCLinkCtrl [MFC], OnDrawFocusRect
ms.assetid: 80f3874d-7cc8-410e-9ff1-62a225f5034b
ms.openlocfilehash: 1ef4e390d88f81d738d2ee18be6ba02843633011
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374397"
---
# <a name="cmfclinkctrl-class"></a>Classe CMFCLinkCtrl

A `CMFCLinkCtrl` classe exibe um botão como um hiperlink e invoca o alvo do link quando o botão é clicado.

## <a name="syntax"></a>Sintaxe

```
class CMFCLinkCtrl : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCLinkCtrl::SetURL](#seturl)|Exibe uma URL especificada como o texto do botão.|
|[CMFCLinkCtrl::SetURLPrefix](#seturlprefix)|Define o protocolo implícito (por exemplo, "http:") da URL.|
|[CMFCLinkCtrl::SizeToContent](#sizetocontent)|Redimensiona o botão para conter o texto do botão ou o bitmap.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCLinkCtrl::OnDrawFocusRect](#ondrawfocusrect)|Chamado pela estrutura antes que o retângulo de foco do botão seja desenhado.|

## <a name="remarks"></a>Comentários

Quando você clica em um `CMFCLinkCtrl` botão derivado da classe, a estrutura passa a `ShellExecute` URL do botão como um parâmetro para o método. Em `ShellExecute` seguida, o método abre o alvo da URL.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCLinkCtrl` definir o tamanho de um objeto e `CMFCLinkCtrl` como definir uma url e uma dica de ferramenta em um objeto. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#9](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#10](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfcbutton](../../mfc/reference/cmfcbutton-class.md)

[Cmfclinkctrl](../../mfc/reference/cmfclinkctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlinkctrl.h

## <a name="cmfclinkctrlondrawfocusrect"></a><a name="ondrawfocusrect"></a>CMFCLinkCtrl::OnDrawFocusRect

Chamado pela estrutura antes que o retângulo de foco do botão seja desenhado.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[em] Um retângulo que limita o controle de link.

### <a name="remarks"></a>Comentários

Anular este método quando quiser usar seu próprio código para desenhar o retângulo de foco do botão.

## <a name="cmfclinkctrlseturl"></a><a name="seturl"></a>CMFCLinkCtrl::SetURL

Exibe uma URL especificada como o texto do botão.

```
void SetURL(LPCTSTR lpszURL);
```

### <a name="parameters"></a>Parâmetros

*Lpszurl*<br/>
[em] O texto do botão a ser exibido.

### <a name="remarks"></a>Comentários

## <a name="cmfclinkctrlseturlprefix"></a><a name="seturlprefix"></a>CMFCLinkCtrl::SetURLPrefix

Define o protocolo implícito (por exemplo, "http:") da URL.

```
void SetURLPrefix(LPCTSTR lpszPrefix);
```

### <a name="parameters"></a>Parâmetros

*lpszPrefix*<br/>
[em] O prefixo do protocolo URL.

### <a name="remarks"></a>Comentários

Use este método para definir o prefixo URL. O prefixo não é exibido no rosto do botão, mas você pode usá-lo para ajudar a navegar até o alvo da URL.

## <a name="cmfclinkctrlsizetocontent"></a><a name="sizetocontent"></a>CMFCLinkCtrl::SizeToContent

Redimensiona o botão para conter o texto do botão ou o bitmap.

```
virtual CSize SizeToContent(
    BOOL bVCenter=FALSE,
    BOOL bHCenter=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bVCenter*<br/>
[em] TRUE para centralizar o texto do botão e bitmap verticalmente entre a parte superior e inferior do controle de link; caso contrário, FALSE. O valor padrão é FALSE.

*bHCenter*<br/>
[em] TRUE para centralizar o texto do botão e o bitmap horizontalmente entre os lados esquerdo e direito do controle de link; caso contrário, FALSE. O valor padrão é FALSE.

### <a name="return-value"></a>Valor retornado

Um objeto [CSize](../../atl-mfc-shared/reference/csize-class.md) que contém o novo tamanho do controle de link.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CLinkCtrl](../../mfc/reference/clinkctrl-class.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)
