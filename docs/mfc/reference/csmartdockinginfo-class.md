---
title: Classe CSmartDockingInfo
ms.date: 11/19/2018
f1_keywords:
- CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo
- AFXDOCKINGMANAGER/CSmartDockingInfo::CopyTo
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_bUseThemeColorInShading
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrBaseBackground
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneDest
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrToneSrc
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_clrTransparent
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_nCentralGroupOffset
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_sizeTotal
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerBmpResID
- AFXDOCKINGMANAGER/CSmartDockingInfo::m_uiMarkerLightBmpResID
helpviewer_keywords:
- CSmartDockingInfo [MFC], CopyTo
- CSmartDockingInfo [MFC], m_bUseThemeColorInShading
- CSmartDockingInfo [MFC], m_clrBaseBackground
- CSmartDockingInfo [MFC], m_clrToneDest
- CSmartDockingInfo [MFC], m_clrToneSrc
- CSmartDockingInfo [MFC], m_clrTransparent
- CSmartDockingInfo [MFC], m_nCentralGroupOffset
- CSmartDockingInfo [MFC], m_sizeTotal
- CSmartDockingInfo [MFC], m_uiMarkerBmpResID
- CSmartDockingInfo [MFC], m_uiMarkerLightBmpResID
ms.assetid: cab04f38-4bc1-4378-9337-c56fc87fbd68
ms.openlocfilehash: ebb5e75b5b298097cfce043bd83ec88ca0ab4030
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751299"
---
# <a name="csmartdockinginfo-class"></a>Classe CSmartDockingInfo

Define a aparência de marcadores de acoplamento inteligentes.

## <a name="syntax"></a>Sintaxe

```
class CSmartDockingInfo : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CSmartDockingInfo::CSmartDockingInfo`|Construtor padrão.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSmartDockingInfo::CopyTo](#copyto)|Copia os parâmetros atuais de informações de encaixe inteligente no objeto [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) fornecido.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CSmartDockingInfo::m_bUseThemeColorInShading](#m_busethemecolorinshading)|Especifica se deve usar a cor do tema atual quando a estrutura exibe marcadores de encaixe inteligentes.|
|[CSmartDockingInfo::m_clrBaseBackground](#m_clrbasebackground)|Especifica a cor de fundo base dos marcadores de encaixe inteligentes.|
|[CSmartDockingInfo::m_clrToneDest](#m_clrtonedest)|Especifica a cor que `m_clrToneSrc` substitui em bitmaps de marcador de encaixe inteligente.|
|[CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc)|Especifica a cor dos bitmaps do marcador de encaixe inteligente.|
|[CSmartDockingInfo::m_clrTransparent](#m_clrtransparent)|Especifica a cor dos bitmaps do marcador de encaixe inteligente quando eles são transparentes.|
|[CSmartDockingInfo::m_nCentralGroupOffset](#m_ncentralgroupoffset)|Especifica a compensação do grupo central de marcadores de encaixe inteligentes dos limites do retângulo do grupo central.|
|[CSmartDockingInfo::m_sizeTotal](#m_sizetotal)|Especifica o tamanho total de todos os marcadores de encaixe inteligentes em um grupo.|
|[CSmartDockingInfo::m_uiMarkerBmpResID](#m_uimarkerbmpresid)|Define os IDs de recursos dos bitmaps que a estrutura usa para marcadores de encaixe inteligentes que não são destacados.|
|[CSmartDockingInfo::m_uiMarkerLightBmpResID](#m_uimarkerlightbmpresid)|Define os IDs de recursos dos bitmaps que a estrutura usa para marcadores de encaixe inteligentes que são destacados.|

## <a name="remarks"></a>Comentários

A estrutura lida com marcadores de encaixe inteligentes internamente. A ilustração a seguir mostra os marcadores de acoplamento inteligentes padrão:

![Marcadores padrão para acoplamento inteligente](../../mfc/reference/media/nextsdmarkers.png "Marcadores padrão para acoplamento inteligente")

Nesta figura, a imagem à esquerda mostra um marcador de acoplamento inteligente do grupo central que não tem acoplamento a uma guia ativada. A imagem no meio mostra um marcador de encaixe inteligente de borda direita. A imagem à direita mostra um marcador de acoplamento inteligente do grupo central que tem acoplamento a uma guia ativada. O marcador de acoplamento inteligente do grupo central tem um bitmap principal e cinco bitmaps de marcador de encaixe inteligente.

Você pode personalizar os seguintes parâmetros de marcadores de encaixe inteligentes:

- Cor. Por exemplo, você pode substituir a cor azul dos marcadores na figura por qualquer cor definida pelo usuário.

- Cor da transparência.

- Deslocamento de um marcador de acoplamento inteligente no grupo central da borda do retângulo delimitador.

- O bitmap principal que representa o grupo central.

- Os bitmaps que representam os marcadores de acoplamento inteligentes regulares e destacados.

A ilustração a seguir mostra um exemplo de marcadores de encaixe inteligentes que foram personalizados:

![Marcadores personalizados para acoplamento inteligente](../../mfc/reference/media/nextsdmarkerscustom.png "Marcadores personalizados para acoplamento inteligente")

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxDockingManager.h

## <a name="csmartdockinginfocopyto"></a><a name="copyto"></a>CSmartDockingInfo::CopyTo

Copia os parâmetros de acoplamento inteligente atuais no objeto [CSmartDockingInfo](../../mfc/reference/csmartdockinginfo-class.md) fornecido.

```cpp
void CopyTo(CSmartDockingInfo& params);
```

### <a name="parameters"></a>Parâmetros

*params*<br/>
[fora] Um objeto `CSmartDockingInfo` de tipo que é preenchido com os parâmetros atuais de acoplamento inteligente.

## <a name="csmartdockinginfom_busethemecolorinshading"></a><a name="m_busethemecolorinshading"></a>CSmartDockingInfo::m_bUseThemeColorInShading

Especifica se deve usar a cor do tema atual quando a estrutura exibe marcadores de encaixe inteligentes.

```
BOOL m_bUseThemeColorInShading;
```

### <a name="remarks"></a>Comentários

Se TRUE, os marcadores são desenhados usando a cor do tema atual; caso contrário, os marcadores são desenhados com uma cor azul claro.

O valor padrão é FALSE.

## <a name="csmartdockinginfom_clrbasebackground"></a><a name="m_clrbasebackground"></a>CSmartDockingInfo::m_clrBaseBackground

Especifica a cor de fundo base dos marcadores de encaixe inteligentes.

```
COLORREF m_clrBaseBackground;
```

## <a name="csmartdockinginfom_clrtonedest"></a><a name="m_clrtonedest"></a>CSmartDockingInfo::m_clrToneDest

Especifica a cor que `m_clrToneSrc` substituirá em bitmaps de marcador de encaixe inteligente.

```
COLORREF m_clrToneDest;
```

### <a name="remarks"></a>Comentários

Defina este valor para alterar a cor dos bitmaps marcadores de forma programática. Por exemplo, se você quiser alterar a cor dos marcadores padrão fornecidos com a estrutura, defina esse valor para a cor desejada. Por padrão, [CSmartDockingInfo::m_clrToneSrc](#m_clrtonesrc) está definido como RGB (61, 123, 241) (uma cor azulada).

Para alterar a cor dos marcadores `m_clrToneDest` personalizados, você deve especificar ambos e `m_clrToneSrc`.

## <a name="csmartdockinginfom_clrtonesrc"></a><a name="m_clrtonesrc"></a>CSmartDockingInfo::m_clrToneSrc

Especifica a cor dos bitmaps do marcador de encaixe inteligente.

```
COLORREF m_clrToneSrc;
```

### <a name="remarks"></a>Comentários

Defina esse valor somente quando quiser substituir a cor de um bitmap personalizado por outra cor. Você não precisa definir esse valor se estiver alterando a cor de um marcador padrão (quadro fornecido).

Use `(COLORREF)-1` para deixar um membro do grupo de acoplamento inteligente vazio.

## <a name="csmartdockinginfom_clrtransparent"></a><a name="m_clrtransparent"></a>CSmartDockingInfo::m_clrTransparent

Especifica a cor dos bitmaps do marcador de encaixe inteligente quando eles são transparentes.

```
COLORREF m_clrTransparent;
```

### <a name="remarks"></a>Comentários

Você deve definir esse valor ao exibir marcadores personalizados e bitmaps personalizados no grupo de encaixe.

## <a name="csmartdockinginfom_ncentralgroupoffset"></a><a name="m_ncentralgroupoffset"></a>CSmartDockingInfo::m_nCentralGroupOffset

Especifica o deslocamento entre o grupo central de marcadores de encaixe inteligentes e os limites do retângulo do grupo central.

```
int m_nCentralGroupOffset;
```

### <a name="remarks"></a>Comentários

Especifique esse valor se quiser alterar a compensação padrão entre marcadores personalizados e os limites do grupo central de marcadores de encaixe inteligentes. O deslocamento padrão é de 5 pixels.

## <a name="csmartdockinginfom_sizetotal"></a><a name="m_sizetotal"></a>CSmartDockingInfo::m_sizeTotal

Especifica o tamanho total de um retângulo delimitador que inclui todos os marcadores de encaixe inteligentes no grupo central.

```
CSize m_sizeTotal;
```

### <a name="remarks"></a>Comentários

Definir `m_sizeTotal` para o tamanho do retângulo delimitador do marcador de grupo central. Você é obrigado a especificar esse valor se estiver usando bitmaps personalizados para marcadores.

## <a name="csmartdockinginfom_uimarkerbmpresid"></a><a name="m_uimarkerbmpresid"></a>CSmartDockingInfo::m_uiMarkerBmpResID

Define os IDs de recursos dos bitmaps usados para marcadores de encaixe inteligentepersonalizados não destacados.

```
UINT m_uiMarkerBmpResID[AFX_SD_MARKERS_NUM];
```

### <a name="remarks"></a>Comentários

Preencha esta matriz com os IDs de recursos dos bitmaps que representam os marcadores de encaixe inteligentes. AFX_SD_MARKERS_NUM atualmente é definido como 5. Você preenche a matriz da seguinte forma:

```cpp
params.m_uiMarkerBmpResID[0] = IDB_MARKER_LEFT;
params.m_uiMarkerBmpResID[1] = IDB_MARKER_RIGHT;
params.m_uiMarkerBmpResID[2] = IDB_MARKER_TOP;
params.m_uiMarkerBmpResID[3] = IDB_MARKER_BOTTOM;
params.m_uiMarkerBmpResID[4] = IDB_MARKER_CENTER;
```

## <a name="csmartdockinginfom_uimarkerlightbmpresid"></a><a name="m_uimarkerlightbmpresid"></a>CSmartDockingInfo::m_uiMarkerLightBmpResID

Define os IDs de recursos dos bitmaps usados para marcadores de encaixe inteligentes personalizados destacados.

```
UINT m_uiMarkerLightBmpResID[AFX_SD_MARKERS_NUM];
```

### <a name="remarks"></a>Comentários

Preencha esta matriz com os IDs de recursos dos bitmaps que representam os marcadores de encaixe inteligentes destacados. AFX_SD_MARKERS_NUM atualmente é definido como 5. Você preenche a matriz da seguinte forma:

```cpp
params.m_uiMarkerLightBmpResID[0] = IDB_MARKER_LEFT_LIGHT;
params.m_uiMarkerLightBmpResID[1] = IDB_MARKER_RIGHT_LIGHT;
params.m_uiMarkerLightBmpResID[2] = IDB_MARKER_TOP_LIGHT;
params.m_uiMarkerLightBmpResID[3] = IDB_MARKER_BOTTOM_LIGHT;
params.m_uiMarkerLightBmpResID[4] = IDB_MARKER_CENTER_LIGHT;
```

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)
