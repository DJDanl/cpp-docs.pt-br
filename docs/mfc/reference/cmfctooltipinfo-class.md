---
title: Classe CMFCToolTipInfo
ms.date: 11/04/2016
f1_keywords:
- CMFCToolTipInfo
- AFXTOOLTIPCTRL/CMFCToolTipInfo
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bBalloonTooltip
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bBoldLabel
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawDescription
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawIcon
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bDrawSeparator
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bRoundedCorners
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_bVislManagerTheme
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrBorder
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrFill
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrFillGradient
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_clrText
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_nGradientAngle
- AFXTOOLTIPCTRL/CMFCToolTipInfo::m_nMaxDescrWidth
helpviewer_keywords:
- CMFCToolTipInfo [MFC], m_bBalloonTooltip
- CMFCToolTipInfo [MFC], m_bBoldLabel
- CMFCToolTipInfo [MFC], m_bDrawDescription
- CMFCToolTipInfo [MFC], m_bDrawIcon
- CMFCToolTipInfo [MFC], m_bDrawSeparator
- CMFCToolTipInfo [MFC], m_bRoundedCorners
- CMFCToolTipInfo [MFC], m_bVislManagerTheme
- CMFCToolTipInfo [MFC], m_clrBorder
- CMFCToolTipInfo [MFC], m_clrFill
- CMFCToolTipInfo [MFC], m_clrFillGradient
- CMFCToolTipInfo [MFC], m_clrText
- CMFCToolTipInfo [MFC], m_nGradientAngle
- CMFCToolTipInfo [MFC], m_nMaxDescrWidth
ms.assetid: f9d3d7f8-1f08-4342-a7b2-683860e5d2a5
ms.openlocfilehash: 000a2fd33928e59685efa6f145406542a4935819
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377331"
---
# <a name="cmfctooltipinfo-class"></a>Classe CMFCToolTipInfo

Armazena informações sobre a aparência visual das dicas de ferramentas.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolTipInfo
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolTipInfo::operador=](#operator_eq)||

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolTipInfo::m_bBalloonTooltip](#m_bballoontooltip)|Uma variável booleana que indica se a ponta da ferramenta tem uma aparência de balão.|
|[CMFCToolTipInfo::m_bBoldLabel](#m_bboldlabel)|Uma variável booleana que indica se os rótulos da dica de ferramenta são exibidos em uma fonte em negrito.|
|[CMFCToolTipInfo::m_bDrawDescription](#m_bdrawdescription)|Uma variável booleana que indica se a dica de ferramenta contém uma descrição.|
|[CMFCToolTipInfo::m_bDrawIcon](#m_bdrawicon)|Uma variável booleana que indica se a dica de ferramenta contém um ícone.|
|[CMFCToolTipInfo::m_bDrawSeparator](#m_bdrawseparator)|Uma variável booleana que indica se um separador é exibido entre a etiqueta da dica da ferramenta e a descrição da dica da ferramenta.|
|[CMFCToolTipInfo::m_bRoundedCorners](#m_broundedcorners)|Uma variável booleana que indica se a ponta da ferramenta tem cantos arredondados.|
|[CMFCToolTipInfo::m_bVislManagerTheme](#m_bvislmanagertheme)|Uma variável booleana que indica se a aparência da dica de ferramenta deve ser controlada por um gerenciador visual (ver [CMFCVisualManager Class](../../mfc/reference/cmfcvisualmanager-class.md)).|
|[CMFCToolTipInfo::m_clrBorder](#m_clrborder)|A cor da borda da ponta de ferramenta.|
|[CMFCToolTipInfo::m_clrFill](#m_clrfill)|A cor do fundo da dica de ferramenta.|
|[CMFCToolTipInfo::m_clrFillGradient](#m_clrfillgradient)|A cor do gradiente preenche a ponta da ferramenta.|
|[CMFCToolTipInfo::m_clrText](#m_clrtext)|A cor do texto na dica de ferramenta.|
|[CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle)|O ângulo do gradiente preenche a ponta da ferramenta.|
|[CMFCToolTipInfo::m_nMaxDescrWidth](#m_nmaxdescrwidth)|A largura máxima possível, em pixels, da descrição na dica de ferramenta.|

## <a name="remarks"></a>Comentários

Use [cmfctoolTipctrl](../../mfc/reference/cmfctooltipctrl-class.md) `CMFCToolTipInfo`class e [CTooltipManager Class](../../mfc/reference/ctooltipmanager-class.md) juntos para implementar dicas de ferramentas personalizadas em seu aplicativo. Para obter um exemplo de como usar essas classes de dica de ferramenta, consulte o tópico [CMFCToolTipCtrl Class.](../../mfc/reference/cmfctooltipctrl-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como definir os valores das várias variáveis de membros na `CMFCToolTipInfo` classe.

[!code-cpp[NVC_MFC_RibbonApp#42](../../mfc/reference/codesnippet/cpp/cmfctooltipinfo-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmfctooltipinfo](../../mfc/reference/cmfctooltipinfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtooltipctrl.h

## <a name="cmfctooltipinfom_bballoontooltip"></a><a name="m_bballoontooltip"></a>CMFCToolTipInfo::m_bBalloonTooltip

Especifica o estilo de exibição de todas as dicas de ferramentas.

```
BOOL m_bBalloonTooltip;
```

### <a name="remarks"></a>Comentários

TRUE indica que as pontas das ferramentas usam o estilo do balão, FALSE indica que as pontas das ferramentas usam o estilo retangular.

## <a name="cmfctooltipinfom_bboldlabel"></a><a name="m_bboldlabel"></a>CMFCToolTipInfo::m_bBoldLabel

Especifica se a fonte do texto da dica de ferramenta é negrito.

```
BOOL m_bBoldLabel;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir texto de dica de ferramenta com fonte em negrito ou FALSE para exibir rótulos de dica de ferramenta com fonte não negrito.

## <a name="cmfctooltipinfom_bdrawdescription"></a><a name="m_bdrawdescription"></a>CMFCToolTipInfo::m_bDrawDescription

Especifica se cada dica de ferramenta exibe o texto de descrição.

```
BOOL m_bDrawDescription;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir a descrição ou FALSE para ocultar a descrição. Você pode especificar a descrição em uma dica de ferramenta ligando para [CMFCToolTipCtrl::SetDescription](../../mfc/reference/cmfctooltipctrl-class.md#setdescription)

## <a name="cmfctooltipinfom_bdrawicon"></a><a name="m_bdrawicon"></a>CMFCToolTipInfo::m_bDrawIcon

Especifica se todas as dicas de ferramentas exibem ícones.

```
BOOL m_bDrawIcon;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir um ícone em cada dica de ferramenta ou FALSE para exibir dicas de ferramentas sem ícones.

## <a name="cmfctooltipinfom_bdrawseparator"></a><a name="m_bdrawseparator"></a>CMFCToolTipInfo::m_bDrawSeparator

Especifica se cada dica de ferramenta tem um separador entre seu rótulo e sua descrição.

```
BOOL m_bDrawSeparator;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir o separador entre o rótulo da dica da ferramenta e a descrição, ou FALSE para exibir dicas de ferramentas sem separador.

## <a name="cmfctooltipinfom_broundedcorners"></a><a name="m_broundedcorners"></a>CMFCToolTipInfo::m_bRoundedCorners

Especifica se todas as pontas das ferramentas têm cantos arredondados.

```
BOOL m_bRoundedCorners;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para exibir cantos arredondados nas pontas das ferramentas ou FALSE para exibir cantos retangulares nas pontas das ferramentas.

## <a name="cmfctooltipinfom_clrborder"></a><a name="m_clrborder"></a>CMFCToolTipInfo::m_clrBorder

Especifica a cor das bordas em todas as pontas das ferramentas.

```
COLORREF m_clrBorder;
```

## <a name="cmfctooltipinfom_clrfill"></a><a name="m_clrfill"></a>CMFCToolTipInfo::m_clrFill

Especifica a cor dos fundos da dica de ferramenta.

```
COLORREF m_clrFill;
```

### <a name="remarks"></a>Comentários

Se [CMFCToolTipInfo::m_clrFillGradient](#m_clrfillgradient) é -1, a `m_clrFill`cor de fundo da dica de ferramenta é . Caso contrário, `m_clrFill` especifica a cor do início do `m_clrFillGradient` gradiente e especifica a cor da extremidade do gradiente. [CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle) determina a direção do gradiente.

## <a name="cmfctooltipinfom_clrfillgradient"></a><a name="m_clrfillgradient"></a>CMFCToolTipInfo::m_clrFillGradient

Especifica a cor final para um fundo de gradiente para dicas de ferramentas.

```
COLORREF m_clrFillGradient;
```

### <a name="remarks"></a>Comentários

Se `m_clrFillGradient` for -1, não há gradiente. Caso contrário, a cor inicial do gradiente é especificada por [CMFCToolTipInfo::m_clrFill](#m_clrfill) e a cor de acabamento do gradiente é especificada por `m_clrFillGradient`. [CMFCToolTipInfo::m_nGradientAngle](#m_ngradientangle) determina a direção do gradiente.

## <a name="cmfctooltipinfom_clrtext"></a><a name="m_clrtext"></a>CMFCToolTipInfo::m_clrText

Especifica a cor do texto de todas as dicas de ferramentas.

```
COLORREF m_clrText;
```

## <a name="cmfctooltipinfom_ngradientangle"></a><a name="m_ngradientangle"></a>CMFCToolTipInfo::m_nGradientAngle

Especifica o ângulo no qual um gradiente é desenhado no fundo das pontas das ferramentas.

```
int m_nGradientAngle;
```

### <a name="remarks"></a>Comentários

`m_nGradientAngle`especifica o ângulo, em graus, de que o gradiente no fundo das pontas das ferramentas é deslocado da horizontal. Se `m_nGradientAngle` for 0, o gradiente é desenhado da esquerda para a direita. Se `m_nGradientAngle` estiver entre 1 e 360, o gradiente está girando no sentido horário por esse número de graus. Se `m_nGradientAngle` for -1, que é o valor padrão, o gradiente é desenhado de cima para baixo. Isso é o `m_nGradientAngle` mesmo que definir para 90.

[CMFCToolTipInfo::m_clrFill](#m_clrfill) `clrFill` especifica a cor do início do gradiente e [CMFCToolTipInfo:::m_clrFillGradient](#m_clrfillgradient) `clrFillGradient` especifica a cor do final do gradiente. Se `m_clrFillGradient` for -1, não há gradiente.

## <a name="cmfctooltipinfom_nmaxdescrwidth"></a><a name="m_nmaxdescrwidth"></a>CMFCToolTipInfo::m_nMaxDescrWidth

Especifica a largura máxima da descrição exibida em cada dica de ferramenta. Se a largura da descrição exceder o valor especificado, o texto será embrulhado.

```
int m_nMaxDescrWidth;
```

## <a name="cmfctooltipinfom_bvislmanagertheme"></a><a name="m_bvislmanagertheme"></a>CMFCToolTipInfo::m_bVislManagerTheme

Especifica se o gerenciador visual do aplicativo controla o aparecimento de todas as dicas de ferramentas.

```
BOOL m_bVislManagerTheme;
```

### <a name="remarks"></a>Comentários

Se `m_bVislManagerTheme` for VERDADE, cada dica de ferramenta solicita um novo [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) do gerenciador visual do aplicativo antes de aparecer na tela e usa os valores nesse objeto para determinar sua aparência. Os outros membros do seu [CMFCToolTipInfo](../../mfc/reference/cmfctooltipinfo-class.md) são ignorados.

## <a name="cmfctooltipinfooperator"></a><a name="operator_eq"></a>CMFCToolTipInfo::operador=

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
CMFCToolTipInfo& operator=(CMFCToolTipInfo& src);
```

### <a name="parameters"></a>Parâmetros

[em] *src*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CTooltipManager](../../mfc/reference/ctooltipmanager-class.md)<br/>
[Classe CMFCToolTipCtrl](../../mfc/reference/cmfctooltipctrl-class.md)
