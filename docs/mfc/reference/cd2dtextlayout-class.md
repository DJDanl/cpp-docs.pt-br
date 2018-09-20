---
title: Classe CD2DTextLayout | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a699744955088ad49c0e701166cf368695354fac
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402194"
---
# <a name="cd2dtextlayout-class"></a>Classe CD2DTextLayout

Um wrapper para IDWriteTextLayout.

## <a name="syntax"></a>Sintaxe

```
class CD2DTextLayout : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextLayout::CD2DTextLayout](#cd2dtextlayout)|Constrói um objeto CD2DTextLayout.|
|[CD2DTextLayout:: ~ CD2DTextLayout](#cd2dtextlayout__~cd2dtextlayout)|O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextLayout::Create](#create)|Cria um CD2DTextLayout. (Substitui [CD2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DTextLayout::Destroy](#destroy)|Destrói um objeto CD2DTextLayout. (Substitui [CD2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DTextLayout::Get](#get)|Interface de IDWriteTextLayout retorna|
|[CD2DTextLayout::GetFontFamilyName](#getfontfamilyname)|Copia o nome de família de fonte do texto na posição especificada.|
|[CD2DTextLayout::GetLocaleName](#getlocalename)|Obtém o nome da localidade do texto na posição especificada.|
|[CD2DTextLayout::IsValid](#isvalid)|Verifica a validade de recurso (substitui [CD2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DTextLayout::ReCreate](#recreate)|Recria um CD2DTextLayout. (Substitui [CD2DResource::ReCreate](../../mfc/reference/cd2dresource-class.md#recreate).)|
|[CD2DTextLayout::SetFontFamilyName](#setfontfamilyname)|Nome de família de fonte terminada em nulo de conjuntos para o texto dentro de um intervalo de texto especificado|
|[CD2DTextLayout::SetLocaleName](#setlocalename)|Define o nome da localidade para o texto dentro de um intervalo de texto especificado|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextLayout::Operator IDWriteTextLayout *](#operator_idwritetextlayout_star)|Interface de IDWriteTextLayout retorna|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextLayout::m_pTextLayout](#m_ptextlayout)|Um ponteiro para um IDWriteTextLayout.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DTextLayout](../../mfc/reference/cd2dtextlayout-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

##  <a name="_dtorcd2dtextlayout"></a>  CD2DTextLayout:: ~ CD2DTextLayout

O destruidor. Chamado quando um objeto de layout de texto D2D está sendo destruído.

```
virtual ~CD2DTextLayout();
```

##  <a name="cd2dtextlayout"></a>  CD2DTextLayout::CD2DTextLayout

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
Um ponteiro para o destino de renderização.

*strText*<br/>
Um objeto CString que contém a cadeia de caracteres para criar um novo objeto CD2DTextLayout do.

*TextFormat*<br/>
Um objeto CString que contém o formato a ser aplicado à cadeia de caracteres.

*sizeMax*<br/>
O tamanho da caixa de layout.

*bAutoDestroy*<br/>
Indica se o objeto será destruído pelo proprietário (pParentTarget).

##  <a name="create"></a>  CD2DTextLayout::Create

Cria um CD2DTextLayout.

```
virtual HRESULT Create(CRenderTarget* */);
```

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="destroy"></a>  CD2DTextLayout::Destroy

Destrói um objeto CD2DTextLayout.

```
virtual void Destroy();
```

##  <a name="get"></a>  CD2DTextLayout::Get

Interface de IDWriteTextLayout retorna

```
IDWriteTextLayout* Get();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não foi inicializado.

##  <a name="getfontfamilyname"></a>  CD2DTextLayout::GetFontFamilyName

Copia o nome de família de fonte do texto na posição especificada.

```
CString GetFontFamilyName(
    UINT32 currentPosition,
    DWRITE_TEXT_RANGE* textRange = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*currentPosition*<br/>
A posição do texto para examinar.

*TextRange*<br/>
O intervalo de texto que tem o mesmo de formatação como o texto na posição especificada por currentPosition. Isso significa que a execução não tem a formatação exata como a posição especificada, incluindo mas não limitado ao nome de família da fonte.

### <a name="return-value"></a>Valor de retorno

Objeto de CString que contém o nome de família da fonte atual.

##  <a name="getlocalename"></a>  CD2DTextLayout::GetLocaleName

Obtém o nome da localidade do texto na posição especificada.

```
CString GetLocaleName(
    UINT32 currentPosition,
    DWRITE_TEXT_RANGE* textRange = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*currentPosition*<br/>
A posição do texto a ser inspecionado.

*TextRange*<br/>
O intervalo de texto que tem o mesmo de formatação como o texto na posição especificada por currentPosition. Isso significa que a execução não tem a formatação exata como a posição especificada, incluindo, mas sem limitação, o nome da localidade.

### <a name="return-value"></a>Valor de retorno

Objeto de CString que contém o nome da localidade atual.

##  <a name="isvalid"></a>  CD2DTextLayout::IsValid

Verificações de validade de recurso

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE se o recurso for válido. Caso contrário, FALSE.

##  <a name="m_ptextlayout"></a>  CD2DTextLayout::m_pTextLayout

Um ponteiro para um IDWriteTextLayout.

```
IDWriteTextLayout* m_pTextLayout;
```

##  <a name="operator_idwritetextlayout_star"></a>  CD2DTextLayout::Operator IDWriteTextLayout *

Interface de IDWriteTextLayout retorna

```
operator IDWriteTextLayout*();
```

### <a name="return-value"></a>Valor de retorno

Ponteiro para uma interface IDWriteTextLayout ou NULL se o objeto ainda não foi inicializado.

##  <a name="recreate"></a>  CD2DTextLayout::ReCreate

Recria um CD2DTextLayout.

```
virtual HRESULT ReCreate(CRenderTarget* */);
```

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="setfontfamilyname"></a>  CD2DTextLayout::SetFontFamilyName

Nome de família de fonte terminada em nulo de conjuntos para o texto dentro de um intervalo de texto especificado

```
BOOL SetFontFamilyName(
    LPCWSTR pwzFontFamilyName,
    DWRITE_TEXT_RANGE textRange);
```

### <a name="parameters"></a>Parâmetros

*pwzFontFamilyName*<br/>
O nome da família de fonte aplica-se para a cadeia de caracteres de texto inteiro dentro do intervalo especificado por textRange

*TextRange*<br/>
Intervalo de texto ao qual essa alteração se aplica

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE

##  <a name="setlocalename"></a>  CD2DTextLayout::SetLocaleName

Define o nome da localidade para o texto dentro de um intervalo de texto especificado

```
BOOL SetLocaleName(
    LPCWSTR pwzLocaleName,
    DWRITE_TEXT_RANGE textRange);
```

### <a name="parameters"></a>Parâmetros

*pwzLocaleName*<br/>
Uma cadeia de caracteres de nome de localidade terminada em nulo

*TextRange*<br/>
Intervalo de texto ao qual essa alteração se aplica

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, ele retornará TRUE. Caso contrário, retornará FALSE

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
