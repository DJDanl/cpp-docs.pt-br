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
ms.openlocfilehash: bc43dcaf077bc97e3ff589a12bee6a8eac6aeed1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50608579"
---
# <a name="cmfclinkctrl-class"></a>Classe CMFCLinkCtrl

O `CMFCLinkCtrl` classe exibe um botão como um hiperlink e chama o destino do link quando o botão é clicado.

## <a name="syntax"></a>Sintaxe

```
class CMFCLinkCtrl : public CMFCButton
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCLinkCtrl::SetURL](#seturl)|Exibe uma URL especificada como o texto do botão.|
|[CMFCLinkCtrl::SetURLPrefix](#seturlprefix)|Define o protocolo implícito (por exemplo, "http:") da URL.|
|[CMFCLinkCtrl::SizeToContent](#sizetocontent)|Redimensiona o botão para conter o texto do botão ou um bitmap.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCLinkCtrl::OnDrawFocusRect](#ondrawfocusrect)|Chamado pelo framework antes do retângulo de foco do botão é desenhado.|

## <a name="remarks"></a>Comentários

Quando você clica em um botão que é derivado de `CMFCLinkCtrl` classe, o framework transmite a URL do botão como um parâmetro para o `ShellExecute` método. Em seguida, a `ShellExecute` método abre o destino da URL.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir o tamanho de um `CMFCLinkCtrl` objeto e como definir uma url e uma dica de ferramenta em um `CMFCLinkCtrl` objeto. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#9](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#10](../../mfc/reference/codesnippet/cpp/cmfclinkctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[CMFCButton](../../mfc/reference/cmfcbutton-class.md)

[CMFCLinkCtrl](../../mfc/reference/cmfclinkctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxlinkctrl.h

##  <a name="ondrawfocusrect"></a>  CMFCLinkCtrl::OnDrawFocusRect

Chamado pelo framework antes do retângulo de foco do botão é desenhado.

```
virtual void OnDrawFocusRect(
    CDC* pDC,
    const CRect& rectClient);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[in] Um ponteiro para um contexto de dispositivo.

*rectClient*<br/>
[in] Um retângulo que delimita o controle de link.

### <a name="remarks"></a>Comentários

Substitua este método quando quiser usar seu próprio código para desenhar o retângulo de foco do botão.

##  <a name="seturl"></a>  CMFCLinkCtrl::SetURL

Exibe uma URL especificada como o texto do botão.

```
void SetURL(LPCTSTR lpszURL);
```

### <a name="parameters"></a>Parâmetros

*lpszURL*<br/>
[in] O texto do botão para exibir.

### <a name="remarks"></a>Comentários

##  <a name="seturlprefix"></a>  CMFCLinkCtrl::SetURLPrefix

Define o protocolo implícito (por exemplo, "http:") da URL.

```
void SetURLPrefix(LPCTSTR lpszPrefix);
```

### <a name="parameters"></a>Parâmetros

*lpszPrefix*<br/>
[in] O prefixo do protocolo de URL.

### <a name="remarks"></a>Comentários

Use esse método para definir o prefixo de URL. O prefixo não é exibido na face do botão, mas você pode usá-lo para ajudar a navegar até o destino da URL.

##  <a name="sizetocontent"></a>  CMFCLinkCtrl::SizeToContent

Redimensiona o botão para conter o texto do botão ou um bitmap.

```
virtual CSize SizeToContent(
    BOOL bVCenter=FALSE,
    BOOL bHCenter=FALSE);
```

### <a name="parameters"></a>Parâmetros

*bVCenter*<br/>
[in] TRUE para centralizar o texto do botão e um bitmap na vertical entre a parte superior e inferior do controle de link; Caso contrário, FALSE. O valor padrão é FALSE.

*bHCenter*<br/>
[in] TRUE para centralizar o texto do botão e um bitmap horizontalmente entre os lados esquerdo e direito do controle de link; Caso contrário, FALSE. O valor padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

Um [CSize](../../atl-mfc-shared/reference/csize-class.md) objeto que contém o novo tamanho do controle de link.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CLinkCtrl](../../mfc/reference/clinkctrl-class.md)<br/>
[Classe CMFCButton](../../mfc/reference/cmfcbutton-class.md)
