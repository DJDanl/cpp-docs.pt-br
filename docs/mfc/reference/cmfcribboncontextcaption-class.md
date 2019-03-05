---
title: Classe CMFCRibbonContextCaption
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonContextCaption
- AFXRIBBONBAR/CMFCRibbonContextCaption
- AFXRIBBONBAR/CMFCRibbonContextCaption::GetColor
- AFXRIBBONBAR/CMFCRibbonContextCaption::GetRightTabX
helpviewer_keywords:
- CMFCRibbonContextCaption [MFC], GetColor
- CMFCRibbonContextCaption [MFC], GetRightTabX
ms.assetid: cce2c0a2-8370-4266-997e-f8d0eeb3d616
ms.openlocfilehash: 26cc509db55bc95688123a7c6e673dcfc87c975b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57262396"
---
# <a name="cmfcribboncontextcaption-class"></a>Classe CMFCRibbonContextCaption

Implementa uma legenda colorida exibida na parte superior de uma categoria de faixa de opções ou uma categoria de contexto.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonContextCaption : public CMFCRibbonButton
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonContextCaption::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonContextCaption::GetColor](#getcolor)|Retorna a cor da legenda.|
|[CMFCRibbonContextCaption::GetRightTabX](#getrighttabx)||
|`CMFCRibbonContextCaption::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|

## <a name="remarks"></a>Comentários

Essa classe não pode ser instanciada diretamente. O [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) classe usa esta classe internamente para adicionar cores a categorias de faixa de opções.

Para definir a cor para as categorias de faixa de opções, chame [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor). Para definir a cor para as categorias de contexto, chame [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonContextCaption](../../mfc/reference/cmfcribboncontextcaption-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxribbonbar. H

##  <a name="getcolor"></a>  CMFCRibbonContextCaption::GetColor

Retorna a cor do plano de fundo da legenda.

```
AFX_RibbonCategoryColor GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

O valor retornado pode ser um dos seguintes valores enumerados:

- `AFX_CategoryColor_None`

- `AFX_CategoryColor_Red`

- `AFX_CategoryColor_Orange`

- `AFX_CategoryColor_Yellow`

- `AFX_CategoryColor_Green`

- `AFX_CategoryColor_Blue`

- `AFX_CategoryColor_Indigo`

- `AFX_CategoryColor_Violet`

### <a name="remarks"></a>Comentários

A cor da legenda pode ser definida chamando [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor) ou [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).

##  <a name="getrighttabx"></a>  CMFCRibbonContextCaption::GetRightTabX

Recupera a posição da borda direita da guia de faixa de opções da categoria.

```
int GetRightTabX() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o valor de X à direita do retângulo delimitador do `CMFCRibbonCategory` guia de faixa de opções do objeto ou um valor de -1 se a guia é truncada.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)<br/>
[Classe CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md)<br/>
[Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
