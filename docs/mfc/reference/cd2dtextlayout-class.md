---
title: Classe CD2DTextLayout
ms.date: 03/27/2019
f1_keywords:
- CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout::CD2DTextLayout
- AFXRENDERTARGET/CD2DTextLayout::Create
- AFXRENDERTARGET/CD2DTextLayout::Destroy
- AFXRENDERTARGET/CD2DTextLayout::Get
- AFXRENDERTARGET/CD2DTextLayout::GetFontFamilyName
- AFXRENDERTARGET/CD2DTextLayout::GetLocaleName
- AFXRENDERTARGET/CD2DTextLayout::IsValid
- AFXRENDERTARGET/CD2DTextLayout::ReCreate
- AFXRENDERTARGET/CD2DTextLayout::SetFontFamilyName
- AFXRENDERTARGET/CD2DTextLayout::SetLocaleName
- AFXRENDERTARGET/CD2DTextLayout::m_pTextLayout
helpviewer_keywords:
- CD2DTextLayout [MFC], CD2DTextLayout
- CD2DTextLayout [MFC], Create
- CD2DTextLayout [MFC], Destroy
- CD2DTextLayout [MFC], Get
- CD2DTextLayout [MFC], GetFontFamilyName
- CD2DTextLayout [MFC], GetLocaleName
- CD2DTextLayout [MFC], IsValid
- CD2DTextLayout [MFC], ReCreate
- CD2DTextLayout [MFC], SetFontFamilyName
- CD2DTextLayout [MFC], SetLocaleName
- CD2DTextLayout [MFC], m_pTextLayout
ms.assetid: 724bd13c-f2ef-4e55-a775-8cb04b7b7908
ms.openlocfilehash: 9be4c1134e2f82ceb3af31cbeb1a7d55f4071777
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369032"
---
# <a name="cd2dtextlayout-class"></a>Classe CD2DTextLayout

Um invólucro para IDWriteTextLayout.

## <a name="syntax"></a>Sintaxe

```
class CD2DTextLayout : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextlayout::CD2DTextlayout](#cd2dtextlayout)|Constrói um objeto CD2DTextLayout.|
|[CD2DTextlayout:~CD2DTextlayout](#_dtorcd2dtextlayout)|O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextlayout::Criar](#create)|Cria um CD2DTextLayout. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DTextLayout::Destroy](#destroy)|Destrói um objeto CD2DTextLayout. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DTextlayout::Obter](#get)|Retorna interface IDWriteTextLayout|
|[CD2DTextlayout::GetFontFamilyName](#getfontfamilyname)|Copia o nome da família da fonte do texto na posição especificada.|
|[CD2DTextLayout::GetLocaleName](#getlocalename)|Obtém o nome local do texto na posição especificada.|
|[CD2DTextlayout::isValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DTextlayout::Recriar](#recreate)|Recria um CD2DTextLayout. (Substitui [cd2DResource:ReCriar](../../mfc/reference/cd2dresource-class.md#recreate).)|
|[CD2DTextlayout::SetFontFamilyName](#setfontfamilyname)|Define o nome da família da fonte com término nulo para texto dentro de um intervalo de texto especificado|
|[CD2DTextLayout::SetLocaleName](#setlocalename)|Define o nome local para texto dentro de um intervalo de texto especificado|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DEsquema de texto:iDDGravaçãodetextoLayout de texto*](#operator_idwritetextlayout_star)|Retorna interface IDWriteTextLayout|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextLayout::m_pTextLayout](#m_ptextlayout)|Um ponteiro para um IDWriteTextLayout.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DTextlayout](../../mfc/reference/cd2dtextlayout-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dtextlayoutcd2dtextlayout"></a><a name="_dtorcd2dtextlayout"></a>CD2DTextlayout:~CD2DTextlayout

O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.

```
virtual ~CD2DTextLayout();
```

## <a name="cd2dtextlayoutcd2dtextlayout"></a><a name="cd2dtextlayout"></a>CD2DTextlayout::CD2DTextlayout

Constrói um objeto CD2DTextLayout.

```
CD2DTextLayout(
    CRenderTarget* pParentTarget,
    const CString& strText,
    CD2DTextFormat& textFormat,
    const CD2DSizeF& sizeMax,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*strText*<br/>
Um objeto CString que contém a seqüência de string para criar um novo objeto CD2DTextLayout a partir de.

*textFormat*<br/>
Um objeto CString que contém o formato a ser aplicado à seqüência de string.

*tamanhoMax*<br/>
O tamanho da caixa de layout.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dtextlayoutcreate"></a><a name="create"></a>CD2DTextlayout::Criar

Cria um CD2DTextLayout.

```
virtual HRESULT Create(CRenderTarget* */);
```

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dtextlayoutdestroy"></a><a name="destroy"></a>CD2DTextLayout::Destroy

Destrói um objeto CD2DTextLayout.

```
virtual void Destroy();
```

## <a name="cd2dtextlayoutget"></a><a name="get"></a>CD2DTextlayout::Obter

Retorna interface IDWriteTextLayout

```
IDWriteTextLayout* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dtextlayoutgetfontfamilyname"></a><a name="getfontfamilyname"></a>CD2DTextlayout::GetFontFamilyName

Copia o nome da família da fonte do texto na posição especificada.

```
CString GetFontFamilyName(
    UINT32 currentPosition,
    DWRITE_TEXT_RANGE* textRange = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*Currentposition*<br/>
A posição do texto a ser examinada.

*Textrange*<br/>
O intervalo de texto que tem a mesma formatação do texto na posição especificada pela atualPosition. Isso significa que a execução tem a formatação exata como a posição especificada, incluindo, mas não se limitando ao nome da família da fonte.

### <a name="return-value"></a>Valor retornado

Objeto CString que contém o nome atual da família da fonte.

## <a name="cd2dtextlayoutgetlocalename"></a><a name="getlocalename"></a>CD2DTextLayout::GetLocaleName

Obtém o nome local do texto na posição especificada.

```
CString GetLocaleName(
    UINT32 currentPosition,
    DWRITE_TEXT_RANGE* textRange = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*Currentposition*<br/>
A posição do texto para inspecionar.

*Textrange*<br/>
O intervalo de texto que tem a mesma formatação do texto na posição especificada pela atualPosition. Isso significa que a execução tem a formatação exata como a posição especificada, incluindo, mas não se limitando ao nome local.

### <a name="return-value"></a>Valor retornado

Objeto CString que contém o nome local atual.

## <a name="cd2dtextlayoutisvalid"></a><a name="isvalid"></a>CD2DTextlayout::isValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dtextlayoutm_ptextlayout"></a><a name="m_ptextlayout"></a>CD2DTextLayout::m_pTextLayout

Um ponteiro para um IDWriteTextLayout.

```
IDWriteTextLayout* m_pTextLayout;
```

## <a name="cd2dtextlayoutoperator-idwritetextlayout"></a><a name="operator_idwritetextlayout_star"></a>CD2DEsquema de texto:iDDGravaçãodetextoLayout de texto*

Retorna interface IDWriteTextLayout

```
operator IDWriteTextLayout*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dtextlayoutrecreate"></a><a name="recreate"></a>CD2DTextlayout::Recriar

Recria um CD2DTextLayout.

```
virtual HRESULT ReCreate(CRenderTarget* */);
```

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dtextlayoutsetfontfamilyname"></a><a name="setfontfamilyname"></a>CD2DTextlayout::SetFontFamilyName

Define o nome da família da fonte com término nulo para texto dentro de um intervalo de texto especificado

```
BOOL SetFontFamilyName(
    LPCWSTR pwzFontFamilyName,
    DWRITE_TEXT_RANGE textRange);
```

### <a name="parameters"></a>Parâmetros

*pwzFontFamilyName*<br/>
O nome da família da fonte que se aplica a toda a seqüência de texto dentro do intervalo especificado por textRange

*Textrange*<br/>
Faixa de texto à qual essa alteração se aplica

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO

## <a name="cd2dtextlayoutsetlocalename"></a><a name="setlocalename"></a>CD2DTextLayout::SetLocaleName

Define o nome local para texto dentro de um intervalo de texto especificado

```
BOOL SetLocaleName(
    LPCWSTR pwzLocaleName,
    DWRITE_TEXT_RANGE textRange);
```

### <a name="parameters"></a>Parâmetros

*pwzLocaleName*<br/>
Uma seqüência de nomes locais com término nulo

*Textrange*<br/>
Faixa de texto à qual essa alteração se aplica

### <a name="return-value"></a>Valor retornado

Se o método for bem sucedido, ele retorna TRUE. Caso contrário, ele retorna FALSO

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
