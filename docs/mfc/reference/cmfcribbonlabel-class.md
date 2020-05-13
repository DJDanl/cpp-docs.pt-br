---
title: Classe CMFCRibbonLabel
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel::CMFCRibbonLabel
- AFXRIBBONLABEL/CMFCRibbonLabel::SetACCData
helpviewer_keywords:
- CMFCRibbonLabel [MFC], CMFCRibbonLabel
- CMFCRibbonLabel [MFC], SetACCData
ms.assetid: 0346c891-83bf-4f20-b8a1-c84cf2aadced
ms.openlocfilehash: cd30e374441661368d3ea7abf5177424f8dffb3c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375132"
---
# <a name="cmfcribbonlabel-class"></a>Classe CMFCRibbonLabel

Implementa um rótulo de texto não clicável para uma fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonLabel : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CmFCRibbonLabel::CMFCRibbonLabel](#cmfcribbonlabel)|Constrói e inicializa `CMFCRibbonLabel` um objeto com a seqüência de texto especificada.|
|`CMFCRibbonLabel::~CMFCRibbonLabel`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonLabel::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonLabel::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CmFCRibbonLabel::SetACCData](#setaccdata)|Determina os dados de acessibilidade do elemento atual do rótulo da fita. (Substitui [cmfcribbonbutton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|

### <a name="remarks"></a>Comentários

Depois de criar um rótulo de fita, adicione-o a um painel chamando [CMFCRibbonPanel:::Adicionar](../../mfc/reference/cmfcribbonpanel-class.md#add).

Não é possível adicionar uma etiqueta de fita à barra de ferramentas de acesso rápido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[Rótulo CMFCRibbon](../../mfc/reference/cmfcribbonlabel-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonLabel.h

## <a name="cmfcribbonlabelcmfcribbonlabel"></a><a name="cmfcribbonlabel"></a>CmFCRibbonLabel::CMFCRibbonLabel

Constrói e inicializa um objeto [CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md) que exibe a seqüência de texto especificada.

```
CMFCRibbonLabel(
    LPCTSTR lpszText,
    BOOL bIsMultiLine = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[em] O texto a aparecer no rótulo.

*bIsMultiLine*<br/>
[em] TRUE para especificar que o rótulo é um rótulo multi-linha; caso contrário, FALSE.

## <a name="cmfcribbonlabelsetaccdata"></a><a name="setaccdata"></a>CmFCRibbonLabel::SetACCData

Determina os dados de acessibilidade do elemento atual do rótulo da fita.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
[em] Representa a janela pai da etiqueta de fita atual.

*dados*<br/>
[fora] Um objeto `CAccessibilityData` de tipo que é preenchido com os dados de acessibilidade do rótulo de fita atual.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o parâmetro *de dados* foi preenchido com sucesso com os dados de acessibilidade do rótulo de fita atual; caso contrário, FALSE.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
