---
title: Classe CD2DTextFormat
ms.date: 03/27/2019
f1_keywords:
- CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat::CD2DTextFormat
- AFXRENDERTARGET/CD2DTextFormat::Create
- AFXRENDERTARGET/CD2DTextFormat::Destroy
- AFXRENDERTARGET/CD2DTextFormat::Get
- AFXRENDERTARGET/CD2DTextFormat::GetFontFamilyName
- AFXRENDERTARGET/CD2DTextFormat::GetLocaleName
- AFXRENDERTARGET/CD2DTextFormat::IsValid
- AFXRENDERTARGET/CD2DTextFormat::ReCreate
- AFXRENDERTARGET/CD2DTextFormat::m_pTextFormat
helpviewer_keywords:
- CD2DTextFormat [MFC], CD2DTextFormat
- CD2DTextFormat [MFC], Create
- CD2DTextFormat [MFC], Destroy
- CD2DTextFormat [MFC], Get
- CD2DTextFormat [MFC], GetFontFamilyName
- CD2DTextFormat [MFC], GetLocaleName
- CD2DTextFormat [MFC], IsValid
- CD2DTextFormat [MFC], ReCreate
- CD2DTextFormat [MFC], m_pTextFormat
ms.assetid: db194cec-9dae-4644-ab84-7c43b7164117
ms.openlocfilehash: f7310fd3ca2ac34df7cc1a99cd5527ea8ba709c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369040"
---
# <a name="cd2dtextformat-class"></a>Classe CD2DTextFormat

Um invólucro para IDWriteTextFormat.

## <a name="syntax"></a>Sintaxe

```
class CD2DTextFormat : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextFormat::CD2DTextFormat](#cd2dtextformat)|Constrói um objeto CD2DTextFormat.|
|[CD2DTextFormat::~CD2DTextFormat](#_dtorcd2dtextformat)|O destruidor. Chamado quando um objeto de formato de texto D2D está sendo destruído.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextFormat::Criar](#create)|Cria um CD2DTextFormat. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DTextFormat::Destroy](#destroy)|Destrói um objeto CD2DTextFormat. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DTextformat::Get](#get)|Retorna interface IDWriteTextFormat|
|[CD2DTextformat::GetFontFamilyName](#getfontfamilyname)|Recebe uma cópia do nome da família fonte.|
|[CD2DTextFormat::GetLocaleName](#getlocalename)|Recebe uma cópia do nome local.|
|[CD2DTextformat::isValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|
|[CD2DTextformat::Recriar](#recreate)|Recria um CD2DTextFormat. (Substitui [cd2DResource:ReCriar](../../mfc/reference/cd2dresource-class.md#recreate).)|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DFormato de texto:operador IDWriteTextFormat*](#operator_idwritetextformat_star)|Retorna interface IDWriteTextFormat|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DTextFormat::m_pTextFormat](#m_ptextformat)|Um ponteiro para um IDWriteTextFormat.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

[CD2DTextFormat](../../mfc/reference/cd2dtextformat-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dtextformatcd2dtextformat"></a><a name="_dtorcd2dtextformat"></a>CD2DTextFormat::~CD2DTextFormat

O destruidor. Chamado quando um objeto de formato de texto D2D está sendo destruído.

```
virtual ~CD2DTextFormat();
```

## <a name="cd2dtextformatcd2dtextformat"></a><a name="cd2dtextformat"></a>CD2DTextFormat::CD2DTextFormat

Constrói um objeto CD2DTextFormat.

```
CD2DTextFormat(
    CRenderTarget* pParentTarget,
    const CString& strFontFamilyName,
    FLOAT fontSize,
    DWRITE_FONT_WEIGHT fontWeight = DWRITE_FONT_WEIGHT_NORMAL,
    DWRITE_FONT_STYLE fontStyle = DWRITE_FONT_STYLE_NORMAL,
    DWRITE_FONT_STRETCH fontStretch = DWRITE_FONT_STRETCH_NORMAL,
    const CString& strFontLocale = _T(""),
    IDWriteFontCollection* pFontCollection = NULL,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*strFontFamilyName*<br/>
Um objeto CString que contém o nome da família de fontes.

*Fontsize*<br/>
O tamanho lógico da fonte em unidades DIP ("pixel independente do dispositivo"). Um DIPequals 1/96 polegadas.

*Fontweight*<br/>
Um valor que indica o peso da fonte para o objeto de texto.

*Fontstyle*<br/>
Um valor que indica o estilo de fonte para o objeto de texto.

*Fontstretch*<br/>
Um valor que indica o trecho da fonte para o objeto de texto.

*strFontLocale*<br/>
Um objeto CString que contém o nome local.

*pFontCollection*<br/>
Um ponteiro para um objeto de coleta de fontes. Quando isso é NULL, indica a coleta de fontes do sistema.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

## <a name="cd2dtextformatcreate"></a><a name="create"></a>CD2DTextFormat::Criar

Cria um CD2DTextFormat.

```
virtual HRESULT Create(CRenderTarget* */);
```

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dtextformatdestroy"></a><a name="destroy"></a>CD2DTextFormat::Destroy

Destrói um objeto CD2DTextFormat.

```
virtual void Destroy();
```

## <a name="cd2dtextformatget"></a><a name="get"></a>CD2DTextformat::Get

Retorna interface IDWriteTextFormat

```
IDWriteTextFormat* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface IDWriteTextFormat ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dtextformatgetfontfamilyname"></a><a name="getfontfamilyname"></a>CD2DTextformat::GetFontFamilyName

Recebe uma cópia do nome da família fonte.

```
CString GetFontFamilyName() const;
```

### <a name="return-value"></a>Valor retornado

Objeto CString que contém o nome atual da família da fonte.

## <a name="cd2dtextformatgetlocalename"></a><a name="getlocalename"></a>CD2DTextFormat::GetLocaleName

Recebe uma cópia do nome local.

```
CString GetLocaleName() const;
```

### <a name="return-value"></a>Valor retornado

Objeto CString que contém o nome local atual.

## <a name="cd2dtextformatisvalid"></a><a name="isvalid"></a>CD2DTextformat::isValid

Verifica a validade dos recursos

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dtextformatm_ptextformat"></a><a name="m_ptextformat"></a>CD2DTextFormat::m_pTextFormat

Um ponteiro para um IDWriteTextFormat.

```
IDWriteTextFormat* m_pTextFormat;
```

## <a name="cd2dtextformatoperator-idwritetextformat"></a><a name="operator_idwritetextformat_star"></a>CD2DFormato de texto:operador IDWriteTextFormat*

Retorna interface IDWriteTextFormat

```
operator IDWriteTextFormat*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface IDWriteTextFormat ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dtextformatrecreate"></a><a name="recreate"></a>CD2DTextformat::Recriar

Recria um CD2DTextFormat.

```
virtual HRESULT ReCreate(CRenderTarget* */);
```

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
