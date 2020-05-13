---
title: Classe CMFCToolBarInfo
ms.date: 11/04/2016
f1_keywords:
- CMFCToolBarInfo
- AFXTOOLBAR/CMFCToolBarInfo
- AFXTOOLBAR/CMFCToolBarInfo::m_uiColdResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiHotResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeColdResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiLargeHotResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiMenuDisabledResID
- AFXTOOLBAR/CMFCToolBarInfo::m_uiMenuResID
helpviewer_keywords:
- CMFCToolBarInfo [MFC], m_uiColdResID
- CMFCToolBarInfo [MFC], m_uiDisabledResID
- CMFCToolBarInfo [MFC], m_uiHotResID
- CMFCToolBarInfo [MFC], m_uiLargeColdResID
- CMFCToolBarInfo [MFC], m_uiLargeDisabledResID
- CMFCToolBarInfo [MFC], m_uiLargeHotResID
- CMFCToolBarInfo [MFC], m_uiMenuDisabledResID
- CMFCToolBarInfo [MFC], m_uiMenuResID
ms.assetid: 6dc84482-eaaa-491f-aa5d-dd7a57886b46
ms.openlocfilehash: 593d1665751f7322fc2a9cee307620df88d46876
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376189"
---
# <a name="cmfctoolbarinfo-class"></a>Classe CMFCToolBarInfo

Contém os IDs de recursos de imagens da barra de ferramentas em vários estados. `CMFCToolBarInfo`é uma classe auxiliar que é usada como parâmetro do método [CMFCToolBar::LoadToolBarEx.](../../mfc/reference/cmfctoolbar-class.md#loadtoolbarex)

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarInfo
```

## <a name="members"></a>Membros

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarInfo::m_uiColdResID](#m_uicoldresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens regulares (frias) da barra de ferramentas.|
|[CMFCToolBarInfo::m_uiDisabledResID](#m_uidisabledresid)|ID de recursos do bitmap da barra de ferramentas que contém imagens de barra de ferramentas desativadas.|
|[CMFCToolBarInfo::m_uiHotResID](#m_uihotresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens selecionadas (hot) da barra de ferramentas.|
|[CMFCToolBarInfo::m_uiLargeColdResID](#m_uilargecoldresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens grandes e regulares da barra de ferramentas.|
|[CMFCToolBarInfo::m_uiLargeDisabledResID](#m_uilargedisabledresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens grandes e desativadas da barra de ferramentas.|
|[CMFCToolBarInfo::m_uiLargeHotResID](#m_uilargehotresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens grandes e selecionadas da barra de ferramentas.|
|[CMFCToolBarInfo::m_uiMenuDisabledResID](#m_uimenudisabledresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens de menu desativadas.|
|[CMFCToolBarInfo::m_uiMenuResID](#m_uimenuresid)|ID de recurso do bitmap da barra de ferramentas que contém imagens do menu.|

## <a name="remarks"></a>Comentários

Um bitmap de barra de ferramentas completo consiste em pequenas imagens de barra de ferramentas (botões) de um tamanho fixo. Cada ID de recurso `CMFCToolBarInfo` armazenado em um objeto é um bitmap que contém um conjunto completo de imagens da barra de ferramentas em um único estado (por exemplo, imagens selecionadas, desativadas, grandes ou de menu).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cmfctoolbarinfo](../../mfc/reference/cmfctoolbarinfo-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbar.h

## <a name="cmfctoolbarinfom_uicoldresid"></a><a name="m_uicoldresid"></a>CMFCToolBarInfo::m_uiColdResID

Especifica um ID de recurso para todas as imagens de botão regulares de uma barra de ferramentas.

```
UINT m_uiColdResID;
```

## <a name="cmfctoolbarinfom_uidisabledresid"></a><a name="m_uidisabledresid"></a>CMFCToolBarInfo::m_uiDisabledResID

Especifica um ID de recurso para as imagens indisponíveis de um botão de uma barra de ferramentas.

```
UINT m_uiDisabledResID;
```

## <a name="cmfctoolbarinfom_uihotresid"></a><a name="m_uihotresid"></a>CMFCToolBarInfo::m_uiHotResID

Especifica um ID de recurso para todas as imagens de botão destacadas de uma barra de ferramentas.

```
UINT m_uiHotResID
```

## <a name="cmfctoolbarinfom_uilargecoldresid"></a><a name="m_uilargecoldresid"></a>CMFCToolBarInfo::m_uiLargeColdResID

Especifica um ID de recurso para todas as grandes imagens regulares de botões de uma barra de ferramentas.

```
UINT m_uiLargeColdResID
```

## <a name="cmfctoolbarinfom_uilargedisabledresid"></a><a name="m_uilargedisabledresid"></a>CMFCToolBarInfo::m_uiLargeDisabledResID

Especifica um ID de recurso para todas as imagens de botão desativadas de grande porte de uma barra de ferramentas.

```
UINT m_uiLargeDisabledResID;
```

## <a name="cmfctoolbarinfom_uilargehotresid"></a><a name="m_uilargehotresid"></a>CMFCToolBarInfo::m_uiLargeHotResID

Especifica um ID de recurso para todas as grandes imagens destacadas de uma barra de ferramentas.

```
UINT m_uiLargeHotResID;
```

## <a name="cmfctoolbarinfom_uimenudisabledresid"></a><a name="m_uimenudisabledresid"></a>CMFCToolBarInfo::m_uiMenuDisabledResID

Especifica um ID de recurso para as imagens indisponíveis de comando de uma barra de ferramentas.

```
UINT m_uiMenuDisabledResID;
```

## <a name="cmfctoolbarinfom_uimenuresid"></a><a name="m_uimenuresid"></a>CMFCToolBarInfo::m_uiMenuResID

Especifica um ID de recurso para todas as imagens regulares do item do menu de uma barra de ferramentas.

```
UINT m_uiMenuResID;
```

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)
