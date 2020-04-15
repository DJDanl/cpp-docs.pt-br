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
ms.openlocfilehash: 6c8bb41b82d1dca9235e1184c2152a61c07c8071
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377350"
---
# <a name="cmfctooltipctrl-class"></a>Classe CMFCToolTipCtrl

Uma implementação estendida da dica de ferramenta com base na [classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md). Uma dica de `CMFCToolTipCtrl` ferramenta baseada na classe pode exibir um ícone, um rótulo e uma descrição. Você pode personalizar sua aparência visual usando um preenchimento de gradiente, cores personalizadas de texto e borda, texto em negrito, cantos arredondados ou um estilo de balão.

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

## <a name="syntax"></a>Sintaxe

```cpp
class CMFCToolTipCtrl : public CToolTipCtrl
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCToolTipCtrl::CMFCToolTipCtrl`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolTipCtrl::GetIconSize](#geticonsize)|Retorna o tamanho de um ícone em uma dica de ferramenta.|
|[CMFCToolTipCtrl::GetParams](#getparams)|Retorna as configurações de exibição de uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawBorder](#ondrawborder)|Desenha a borda de uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawDescription](#ondrawdescription)||
|[CMFCToolTipCtrl::OnDrawIcon](#ondrawicon)|Exibe um ícone em uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnDrawLabel](#ondrawlabel)|Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.|
|[CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator)|Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.|
|[CMFCToolTipCtrl::OnFillBackground](#onfillbackground)|Preenche o plano de fundo da dica de ferramenta.|
|[CMFCToolTipCtrl::SetDescription](#setdescription)|Define a descrição a ser exibida pela dica da ferramenta.|
|[CMFCToolTipCtrl::SetSetConfigurWidth](#setfixedwidth)||
|[CMFCToolTipCtrl::SetHotRibbonButton](#sethotribbonbutton)||
|[CMFCToolTipCtrl::SetLocation](#setlocation)||
|[CMFCToolTipCtrl::SetParams](#setparams)|Especifica a aparência visual de uma `CMFCToolTipInfo` dica de ferramenta usando um objeto.|

## <a name="remarks"></a>Comentários

Use `CMFCToolTipCtrl` `CMFCToolTipInfo`objetos , e [CTooltipManager Class](../../mfc/reference/ctooltipmanager-class.md) juntos para implementar dicas de ferramentas personalizadas em seu aplicativo.

Por exemplo, para usar dicas de ferramentas no estilo balão, siga estas etapas:

1. Use o método [CWinAppEx Class](../../mfc/reference/cwinappex-class.md) para inicializar o gerenciador de dicas de ferramentas em seu aplicativo.

2. Crie `CMFCToolTipInfo` uma estrutura para especificar o estilo visual que você deseja:

    ```cpp
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

3. Use o método [CTooltipManager::SetTooltipParams](../../mfc/reference/ctooltipmanager-class.md#settooltipparams) para definir o estilo visual para todas as `CMFCToolTipInfo` dicas de ferramentas do aplicativo usando os estilos definidos no objeto:

    ```cpp
    theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
        RUNTIME_CLASS (CMFCToolTipCtrl), &params);
    ```

Você também pode derivar `CMFCToolTipCtrl` uma nova classe de para controlar o comportamento e a renderização da dica de ferramenta. Para especificar uma nova classe `CTooltipManager::SetTooltipParams` de controle de ponta de ferramenta, use o método:

```cpp
myApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
    RUNTIME_CLASS (CMyToolTipCtrl))
```

Para restaurar a classe de controle de ponta de ferramenta padrão e redefinir a aparência da `SetTooltipParams`dica de ferramenta para o seu estado padrão, especifique NULL nos parâmetros de informações de classe de tempo de execução e de informações de dica de ferramenta de:

```cpp
theApp.GetTooltipManager ()->SetTooltipParams (AFX_TOOLTIP_TYPE_ALL,
    NULL,
    NULL);
```

## <a name="example"></a>Exemplo

O exemplo a seguir `CMFCToolTipCtrl` demonstra como construir um objeto, definir a descrição que a dica de ferramenta exibe e definir a largura do controle da dica de ferramenta.

[!code-cpp[NVC_MFC_RibbonApp#41](../../mfc/reference/codesnippet/cpp/cmfctooltipctrl-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Ctooltipctrl](../../mfc/reference/ctooltipctrl-class.md)

[Cmfctooltipctrl](../../mfc/reference/cmfctooltipctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtooltipctrl.h

## <a name="cmfctooltipctrlcmfctooltipctrl"></a><a name="cmfctooltipctrl"></a>CMFCToolTipCtrl::CMFCToolTipCtrl

```cpp
CMFCToolTipCtrl(CMFCToolTipInfo* pParams = NULL);
```

### <a name="parameters"></a>Parâmetros

[em] *pParams*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfctooltipctrlgeticonsize"></a><a name="geticonsize"></a>CMFCToolTipCtrl::GetIconSize

Retorna o tamanho de um ícone em uma dica de ferramenta.

```cpp
virtual CSize GetIconSize();
```

### <a name="return-value"></a>Valor retornado

O tamanho do ícone, em pixels.

## <a name="cmfctooltipctrlgetparams"></a><a name="getparams"></a>CMFCToolTipCtrl::GetParams

Retorna as configurações de exibição de uma dica de ferramenta.

```cpp
const CMFCToolTipInfo& GetParams() const;
```

### <a name="return-value"></a>Valor retornado

As configurações atuais de exibição da dica de ferramenta, que são armazenadas em um objeto [CMFCToolTipInfo Class.](../../mfc/reference/cmfctooltipinfo-class.md)

## <a name="cmfctooltipctrlondrawborder"></a><a name="ondrawborder"></a>CMFCToolTipCtrl::OnDrawBorder

Desenha a borda de uma dica de ferramenta.

```cpp
virtual void OnDrawBorder(
    CDC* pDC,
    CRect rect,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] O retângulo delimitador da ponta da ferramenta.

*clrLine*<br/>
[em] Cor da borda.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada para personalizar a aparência da borda da ponta de ferramenta.

## <a name="cmfctooltipctrlondrawdescription"></a><a name="ondrawdescription"></a>CMFCToolTipCtrl::OnDrawDescription

```cpp
virtual CSize OnDrawDescription(
    CDC* pDC,
    CRect rect,
    BOOL bCalcOnly);
```

### <a name="parameters"></a>Parâmetros

[em] *pDC*<br/>
[em] *rect*<br/>
[em] *bCalcOnly*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfctooltipctrlondrawicon"></a><a name="ondrawicon"></a>CMFCToolTipCtrl::OnDrawIcon

Exibe um ícone em uma dica de ferramenta.

```cpp
virtual BOOL OnDrawIcon(
    CDC* pDC,
    CRect rectImage);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*rectImage*<br/>
[em] Coordenadas do ícone.

### <a name="return-value"></a>Valor retornado

VERDADE se o ícone foi desenhado. Caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Substituir este método em uma classe derivada para exibir um ícone personalizado. Você também deve substituir [CMFCToolTipCtrl::GetIconSize](#geticonsize) para habilitar a dica de ferramenta para calcular corretamente o layout do texto e da descrição.

## <a name="cmfctooltipctrlondrawlabel"></a><a name="ondrawlabel"></a>CMFCToolTipCtrl::OnDrawLabel

Desenha o rótulo de uma dica de ferramenta ou calcula o tamanho do rótulo.

```cpp
virtual CSize OnDrawLabel(
    CDC* pDC,
    CRect rect,
    BOOL bCalcOnly);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Retângulo delimitador da área da etiqueta.

*bCalcOnly*<br/>
[em] Se TRUE, o rótulo não será desenhado.

### <a name="return-value"></a>Valor retornado

Tamanho da etiqueta, em pixels.

### <a name="remarks"></a>Comentários

Anular este método em uma classe derivada se você quiser personalizar a aparência do rótulo de dica de ferramenta.

## <a name="cmfctooltipctrlondrawseparator"></a><a name="ondrawseparator"></a>CMFCToolTipCtrl::OnDrawSeparator

Desenha o separador entre o rótulo e a descrição em uma dica de ferramenta.

```cpp
virtual void OnDrawSeparator(
    CDC* pDC,
    int x1,
    int x2,
    int y);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*x1*<br/>
[em] Coordenada horizontal da extremidade esquerda do separador.

*x2*<br/>
[em] Coordenada horizontal da extremidade direita do separador.

*Y*<br/>
[em] Coordenada vertical do separador.

### <a name="remarks"></a>Comentários

A implementação padrão desenha uma linha do ponto (x1, y) ao ponto (x2, y).

Anular este método em uma classe derivada para personalizar a aparência do separador.

## <a name="cmfctooltipctrlonfillbackground"></a><a name="onfillbackground"></a>CMFCToolTipCtrl::OnFillBackground

Preenche o plano de fundo da dica de ferramenta.

```cpp
virtual void OnFillBackground(
    CDC* pDC,
    CRect rect,
    COLORREF& clrText,
    COLORREF& clrLine);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Um ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Especifica o retângulo delimitador da área a ser preenchida.

*clrText*<br/>
[em] Cor do primeiro plano da ponta da ferramenta.

*clrLine*<br/>
[em] Cor das bordas e a linha de limitador entre o rótulo e a descrição.

### <a name="remarks"></a>Comentários

A implementação padrão preenche o retângulo especificado por *rect* com a cor ou padrão especificado pela chamada mais recente para [CMFCToolTipCtrl::SetParams](#setparams).

Anular este método em uma classe derivada se você quiser personalizar a aparência da dica de ferramenta.

## <a name="cmfctooltipctrlsetdescription"></a><a name="setdescription"></a>CMFCToolTipCtrl::SetDescription

Define a descrição a ser exibida pela dica da ferramenta.

```cpp
virtual void SetDescription(const CString strDesrciption);
```

### <a name="parameters"></a>Parâmetros

*strDesrciption*<br/>
[em] Texto de descrição.

### <a name="remarks"></a>Comentários

O texto de descrição é exibido na ponta da ferramenta sob o separador.

## <a name="cmfctooltipctrlsetfixedwidth"></a><a name="setfixedwidth"></a>CMFCToolTipCtrl::SetSetConfigurWidth

```cpp
void SetFixedWidth(
    int nWidthRegular,
    int nWidthLargeImage);
```

### <a name="parameters"></a>Parâmetros

[em] *nWidthRegular*<br/>
[em] *nLarguragrandeImagem*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfctooltipctrlsethotribbonbutton"></a><a name="sethotribbonbutton"></a>CMFCToolTipCtrl::SetHotRibbonButton

```cpp
void SetHotRibbonButton(CMFCRibbonButton* pRibbonButton);
```

### <a name="parameters"></a>Parâmetros

[em] *botão pRibbon*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfctooltipctrlsetlocation"></a><a name="setlocation"></a>CMFCToolTipCtrl::SetLocation

```cpp
void SetLocation(CPoint pt);
```

### <a name="parameters"></a>Parâmetros

[em] *pt*<br/>

### <a name="remarks"></a>Comentários

## <a name="cmfctooltipctrlsetparams"></a><a name="setparams"></a>CMFCToolTipCtrl::SetParams

Especifica a aparência visual de uma dica de ferramenta usando um objeto [CMFCToolTipInfo Class.](../../mfc/reference/cmfctooltipinfo-class.md)

```cpp
void SetParams(CMFCToolTipInfo* pParams);
```

### <a name="parameters"></a>Parâmetros

*Pparams*<br/>
[em] Ponteiro para um objeto [CMFCToolTipInfo Class](../../mfc/reference/cmfctooltipinfo-class.md) que contém os parâmetros de exibição.

### <a name="remarks"></a>Comentários

Sempre que a dica de ferramenta é exibida, ela é desenhada usando as cores e estilos visuais que *pParams* especifica. O valor dos *pParams* é `m_Params`armazenado no membro protegido, que pode ser acessado por uma classe derivada que substitui [CMFCToolTipCtrl::OnDrawBorder](#ondrawborder), [CMFCToolTipCtrl::OnDrawIcon,](#ondrawicon) [CMFCToolTipCtrl::OnDrawLabel,](#ondrawlabel) [CMFCToolTipCtrl::OnDrawSeparator](#ondrawseparator)ou [CMFCToolTipCtrl::OnFillBackground](#onfillbackground) para manter a aparência especificada.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CToolTipCtrl](../../mfc/reference/ctooltipctrl-class.md)<br/>
[Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)<br/>
[Classe CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md)<br/>
[Classe Cwinappex](../../mfc/reference/cwinappex-class.md)
