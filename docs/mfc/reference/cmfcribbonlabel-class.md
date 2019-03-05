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
ms.openlocfilehash: b79d6191d2deb0a295e81da1150cc7b38fd81232
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283452"
---
# <a name="cmfcribbonlabel-class"></a>Classe CMFCRibbonLabel

Implementa um rótulo de texto não clicável para uma faixa de opções.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonLabel : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonLabel::CMFCRibbonLabel](#cmfcribbonlabel)|Constrói e inicializa um `CMFCRibbonLabel` objeto com a cadeia de caracteres de texto especificado.|
|`CMFCRibbonLabel::~CMFCRibbonLabel`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonLabel::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|`CMFCRibbonLabel::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCRibbonLabel::SetACCData](#setaccdata)|Determina os dados de acessibilidade para o elemento de rótulo da faixa de opções atual. (Substitui [CMFCRibbonButton::SetACCData](../../mfc/reference/cmfcribbonbutton-class.md#setaccdata).)|

### <a name="remarks"></a>Comentários

Depois de criar um rótulo de faixa de opções, adicioná-lo a um painel chamando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

Você não pode adicionar um rótulo de faixa de opções na barra de ferramentas de acesso rápido.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonLabel.h

##  <a name="cmfcribbonlabel"></a>  CMFCRibbonLabel::CMFCRibbonLabel

Constrói e inicializa um [CMFCRibbonLabel](../../mfc/reference/cmfcribbonlabel-class.md) objeto que exibe a cadeia de caracteres de texto especificado.

```
CMFCRibbonLabel(
    LPCTSTR lpszText,
    BOOL bIsMultiLine = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[in] O texto a ser exibido no rótulo.

*bIsMultiLine*<br/>
[in] TRUE para especificar que o rótulo é um rótulo de várias linha; Caso contrário, FALSE.

##  <a name="setaccdata"></a>  CMFCRibbonLabel::SetACCData

Determina os dados de acessibilidade para o elemento de rótulo da faixa de opções atual.

```
virtual BOOL SetACCData(
    CWnd* pParent,
    CAccessibilityData& data);
```

### <a name="parameters"></a>Parâmetros

*pParent*<br/>
[in] Representa a janela pai do rótulo da faixa de opções atual.

*data*<br/>
[out] Um objeto do tipo `CAccessibilityData` que é preenchida com os dados de acessibilidade do rótulo da faixa de opções atual.

### <a name="return-value"></a>Valor de retorno

TRUE se o *dados* parâmetro estava com êxito preenchida com os dados de acessibilidade do rótulo da faixa de opções atual; caso contrário, FALSE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)
