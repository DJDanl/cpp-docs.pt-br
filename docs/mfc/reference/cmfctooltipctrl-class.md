---
title: Classe CMFCToolTipCtrl
ms.date: 11/04/2016
f1_keywords:
- CMFCToolTipCtrl
- AFXTOOLTIPCTRL/CMFCToolTipCtrl
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::GetIconSize
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::GetParams
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawBorder
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawDescription
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawIcon
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawLabel
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnDrawSeparator
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::OnFillBackground
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetDescription
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetFixedWidth
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetHotRibbonButton
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetLocation
- AFXTOOLTIPCTRL/CMFCToolTipCtrl::SetParams
helpviewer_keywords:
- CMFCToolTipCtrl [MFC], GetIconSize
- CMFCToolTipCtrl [MFC], GetParams
- CMFCToolTipCtrl [MFC], OnDrawBorder
- CMFCToolTipCtrl [MFC], OnDrawDescription
- CMFCToolTipCtrl [MFC], OnDrawIcon
- CMFCToolTipCtrl [MFC], OnDrawLabel
- CMFCToolTipCtrl [MFC], OnDrawSeparator
- CMFCToolTipCtrl [MFC], OnFillBackground
- CMFCToolTipCtrl [MFC], SetDescription
- CMFCToolTipCtrl [MFC], SetFixedWidth
- CMFCToolTipCtrl [MFC], SetHotRibbonButton
- CMFCToolTipCtrl [MFC], SetLocation
- CMFCToolTipCtrl [MFC], SetParams
ms.assetid: 9fbfcfb1-a8ab-417f-ae29-9a9ca85ee58f
ms.openlocfilehash: aecd03371f0dfd4b4af5886bea6c6202c40b5236
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445551"
---
# <a name="cmfctooltipctrl-class"></a>Classe CMFCToolTipCtrl

Uma implementação de dica de ferramenta estendida com base na [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md). Uma dica de ferramenta baseada na classe `CMFCToolTipCtrl` pode exibir um ícone, um rótulo e uma descrição. Você pode personalizar sua aparência visual usando um preenchimento gradiente, texto personalizado e cores de borda, texto em negrito, cantos arredondados ou um estilo de balão.

Para obter mais detalhes, consulte o código-fonte localizado no **VC\\atlmfc\\src\\pasta MFC** da sua instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolTipCtrl : public CToolTipCtrl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`CMFCToolTipCtrl::CMFCToolTipCtrl`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CMFCToolTipCtrl:: getíconesize](#geticonsize)|Retorna o tamanho de um ícone em uma dica de ferramenta.|
|[CMFCToolTipCtrl:: getParams](#getparams)|Retorna as configurações de exibição de uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawBorder](#ondrawborder)|Desenha a borda de uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawDescription](#ondrawdescription)||
|[CMFCToolTipCtrl::OnDrawIcon](#ondrawicon)|Exibe um ícone em uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawLabel](#ondrawlabel)|Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.|
|[CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator)|Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnFillBackground](#onfillbackground)|Preenche o plano de fundo da dica de ferramenta.|
|[CMFCToolTipCtrl:: SetDescription](#setdescription)|Define a descrição a ser exibida pela dica de ferramenta.|
|[CMFCToolTipCtrl::SetFixedWidth](#setfixedwidth)||
|[CMFCToolTipCtrl::SetHotRibbonButton](#sethotribbonbutton)||
|[CMFCToolTipCtrl:: SetLocation](#setlocation)||
|[CMFCToolTipCtrl:: SetParams](#setparams)|Especifica a aparência visual de uma dica de ferramenta usando um objeto `CMFCToolTipInfo`.|

## <a name="remarks"></a>Comentários

Use objetos de classe `CMFCToolTipCtrl`, `CMFCToolTipInfo`e [CTooltipManager](../../mfc/reference/ctooltipmanager-class.md) juntos para implementar dicas de ferramenta personalizadas em seu aplicativo.

Por exemplo, para usar dicas de ferramenta de estilo de balão, siga estas etapas:

1. Use o método de [classe CWinAppEx](../../mfc/reference/cwinappex-class.md) para inicializar o Gerenciador de dica de ferramenta em seu aplicativo.

2. Crie uma estrutura de `CMFCToolTipInfo` para especificar o estilo visual que você deseja:

```
CMFCToolTipInfo params;
params.m_bBoldLabel = FALSE;
params.m_bDrawDescription = FALSE;
params.m_bDrawIcon = FALSE;
params.m_bRoundedCorners = TRUE;
params.m_bDrawSeparator = FALSE;
if (m_bCustomColors)
{
    params.m_clrFill = RGB (255, 255, 255);
    params.m_clrFillGradient = RGB (228, 228, 240);
    params.m_clrText = RGB (61, 83, 80);
    params.m_clrBorder = RGB (144, 149, 168);

}
```

3. Use o método [CTooltipManager:: SetTooltipParams](../../mfc/reference/ctooltipmanager-class.md#settooltipparams) para definir o estilo visual de todas as dicas de ferramenta no aplicativo usando os estilos definidos no objeto `CMFCToolTipInfo`:

```
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
    RUNTIME_CLASS (CMFCToolTipCtrl), &params);
```

Você também pode derivar uma nova classe de `CMFCToolTipCtrl` para controlar o comportamento e a renderização da dica de ferramenta. Para especificar uma nova classe de controle ToolTip, use o método `CTooltipManager::SetTooltipParams`:

```
myApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
    RUNTIME_CLASS (CMyToolTipCtrl))
```

Para restaurar a classe de controle de dica de ferramenta padrão e redefinir a aparência da dica de ferramenta para seu estado padrão, especifique NULL na classe de tempo de execução e nos parâmetros de informações de dica de ferramenta de `SetTooltipParams`:

```
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
    NULL,
    NULL);
```

## <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo a seguir demonstra como construir um objeto `CMFCToolTipCtrl`, definir a descrição que a dica de ferramenta exibe e definir a largura do controle ToolTip.

[!code-cpp[NVC_MFC_RibbonApp#41](../../mfc/reference/codesnippet/cpp/cmfctooltipctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)

[CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxtooltipctrl. h

##  <a name="cmfctooltipctrl"></a>CMFCToolTipCtrl::CMFCToolTipCtrl

```
CMFCToolTipCtrl(CMFCToolTipInfo* pParams = NULL);
```

### <a name="parameters"></a>Parâmetros

no *pParams*<br/>

### <a name="remarks"></a>Comentários

##  <a name="geticonsize"></a>CMFCToolTipCtrl:: getíconesize

Retorna o tamanho de um ícone em uma dica de ferramenta.

```
virtual CSize GetIconSize();
```

### <a name="return-value"></a>Valor retornado

O tamanho do ícone, em pixels.

##  <a name="getparams"></a>CMFCToolTipCtrl:: getParams

Retorna as configurações de exibição de uma dica de ferramenta.

```
const CMFCToolTipInfo& GetParams() const;
```

### <a name="return-value"></a>Valor retornado

As configurações de exibição da dica de ferramenta atual, que são armazenadas em um objeto de [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) .

##  <a name="ondrawborder"></a>CMFCToolTipCtrl::OnDrawBorder

Desenha a borda de uma dica de ferramenta.

```
virtual void OnDrawBorder(
    CDC* pDC,
    CRect rect,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Ponteiro para um contexto de dispositivo.

*Rect*<br/>
no O retângulo delimitador da dica de ferramenta.

*clrLine*<br/>
no Cor da borda.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para personalizar a aparência da borda da dica de ferramenta.

##  <a name="ondrawdescription"></a>CMFCToolTipCtrl::OnDrawDescription

```
virtual CSize OnDrawDescription(
    CDC* pDC,
    CRect rect,
    BOOL bCalcOnly);
```

### <a name="parameters"></a>Parâmetros

no *PDC*<br/>
no *Rect*<br/>
no *bCalcOnly*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

##  <a name="ondrawicon"></a>CMFCToolTipCtrl::OnDrawIcon

Exibe um ícone em uma dica de ferramenta.

```
virtual BOOL OnDrawIcon(
    CDC* pDC,
    CRect rectImage);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*rectImage*<br/>
no Coordenadas do ícone.

### <a name="return-value"></a>Valor retornado

TRUE se o ícone foi desenhado. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para exibir um ícone personalizado. Você também deve substituir [CMFCToolTipCtrl:: getícones](#geticonsize) para habilitar a dica de ferramenta para calcular corretamente o layout do texto e da descrição.

##  <a name="ondrawlabel"></a>CMFCToolTipCtrl::OnDrawLabel

Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.

```
virtual CSize OnDrawLabel(
    CDC* pDC,
    CRect rect,
    BOOL bCalcOnly);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
no Retângulo delimitador da área do rótulo.

*bCalcOnly*<br/>
no Se for TRUE, o rótulo não será desenhado.

### <a name="return-value"></a>Valor retornado

Tamanho do rótulo, em pixels.

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada se desejar personalizar a aparência do rótulo da dica de ferramenta.

##  <a name="ondrawseparator"></a>CMFCToolTipCtrl::OnDrawSeparator

Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.

```
virtual void OnDrawSeparator(
    CDC* pDC,
    int x1,
    int x2,
    int y);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*X1*<br/>
no Coordenada horizontal da extremidade esquerda do separador.

*X2*<br/>
no Coordenada horizontal da extremidade direita do separador.

*Y*<br/>
no Coordenada vertical do separador.

### <a name="remarks"></a>Comentários

A implementação padrão desenha uma linha do ponto (x1, y) até o ponto (x2, y).

Substitua esse método em uma classe derivada para personalizar a aparência do separador.

##  <a name="onfillbackground"></a>CMFCToolTipCtrl::OnFillBackground

Preenche o plano de fundo da dica de ferramenta.

```
virtual void OnFillBackground(
    CDC* pDC,
    CRect rect,
    COLORREF& clrText,
    COLORREF& clrLine);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
no Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
no Especifica o retângulo delimitador da área a ser preenchida.

*clrText*<br/>
no Cor do primeiro plano da dica de ferramenta.

*clrLine*<br/>
no Cor das bordas e a linha do delimitador entre rótulo e descrição.

### <a name="remarks"></a>Comentários

A implementação padrão preenche o retângulo especificado por *Rect* com a cor ou o padrão especificado pela chamada mais recente para [CMFCToolTipCtrl:: SetParams](#setparams).

Substitua esse método em uma classe derivada se desejar personalizar a aparência da dica de ferramenta.

##  <a name="setdescription"></a>CMFCToolTipCtrl:: SetDescription

Define a descrição a ser exibida pela dica de ferramenta.

```
virtual void SetDescription(const CString strDesrciption);
```

### <a name="parameters"></a>Parâmetros

*strDesrciption*<br/>
no Texto de descrição.

### <a name="remarks"></a>Comentários

O texto de descrição é exibido na dica de ferramenta sob o separador.

##  <a name="setfixedwidth"></a>CMFCToolTipCtrl::SetFixedWidth

```
void SetFixedWidth(
    int nWidthRegular,
    int nWidthLargeImage);
```

### <a name="parameters"></a>Parâmetros

no *nWidthRegular*<br/>
no *nWidthLargeImage*<br/>

### <a name="remarks"></a>Comentários

##  <a name="sethotribbonbutton"></a>CMFCToolTipCtrl::SetHotRibbonButton

```
void SetHotRibbonButton(CMFCRibbonButton* pRibbonButton);
```

### <a name="parameters"></a>Parâmetros

no *pRibbonButton*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setlocation"></a>CMFCToolTipCtrl:: SetLocation

```
void SetLocation(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

no *pt*<br/>

### <a name="remarks"></a>Comentários

##  <a name="setparams"></a>CMFCToolTipCtrl:: SetParams

Especifica a aparência visual de uma dica de ferramenta usando um objeto de [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) .

```
void SetParams(CMFCToolTipInfo* pParams);
```

### <a name="parameters"></a>Parâmetros

*pParams*<br/>
no Ponteiro para um objeto de [Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) que contém os parâmetros de exibição.

### <a name="remarks"></a>Comentários

Sempre que a dica de ferramenta é exibida, ela é desenhada usando as cores e os estilos visuais que o *pParams* especifica. O valor de *pParams* é armazenado no membro protegido `m_Params`, que pode ser acessado por uma classe derivada que substitui [CMFCToolTipCtrl:: OnDrawBorder](#ondrawborder), [CMFCToolTipCtrl:: OnDrawIcon](#ondrawicon), [CMFCToolTipCtrl:: OnDrawLabel](#ondrawlabel), [CMFCToolTipCtrl:: OnDrawSeparator](#ondrawseparator)ou [CMFCToolTipCtrl:: OnFillBackground](#onfillbackground) para manter a aparência especificada.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)<br/>
[Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)<br/>
[Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)<br/>
[Classe CWinAppEx](../../mfc/reference/cwinappex-class.md)
