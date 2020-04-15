---
title: Classe CMFCFilterChunkValueImpl
ms.date: 11/04/2016
f1_keywords:
- CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl
- AFXWIN/CMFCFilterChunkValueImpl::Clear
- AFXWIN/CMFCFilterChunkValueImpl::CopyChunk
- AFXWIN/CMFCFilterChunkValueImpl::CopyFrom
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkGUID
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkPID
- AFXWIN/CMFCFilterChunkValueImpl::GetChunkType
- AFXWIN/CMFCFilterChunkValueImpl::GetString
- AFXWIN/CMFCFilterChunkValueImpl::GetValue
- AFXWIN/CMFCFilterChunkValueImpl::GetValueNoAlloc
- AFXWIN/CMFCFilterChunkValueImpl::IsValid
- AFXWIN/CMFCFilterChunkValueImpl::SetBoolValue
- AFXWIN/CMFCFilterChunkValueImpl::SetDwordValue
- AFXWIN/CMFCFilterChunkValueImpl::SetFileTimeValue
- AFXWIN/CMFCFilterChunkValueImpl::SetInt64Value
- AFXWIN/CMFCFilterChunkValueImpl::SetIntValue
- AFXWIN/CMFCFilterChunkValueImpl::SetLongValue
- AFXWIN/CMFCFilterChunkValueImpl::SetSystemTimeValue
- AFXWIN/CMFCFilterChunkValueImpl::SetTextValue
- AFXWIN/CMFCFilterChunkValueImpl::SetChunk
helpviewer_keywords:
- CMFCFilterChunkValueImpl [MFC], CMFCFilterChunkValueImpl
- CMFCFilterChunkValueImpl [MFC], Clear
- CMFCFilterChunkValueImpl [MFC], CopyChunk
- CMFCFilterChunkValueImpl [MFC], CopyFrom
- CMFCFilterChunkValueImpl [MFC], GetChunkGUID
- CMFCFilterChunkValueImpl [MFC], GetChunkPID
- CMFCFilterChunkValueImpl [MFC], GetChunkType
- CMFCFilterChunkValueImpl [MFC], GetString
- CMFCFilterChunkValueImpl [MFC], GetValue
- CMFCFilterChunkValueImpl [MFC], GetValueNoAlloc
- CMFCFilterChunkValueImpl [MFC], IsValid
- CMFCFilterChunkValueImpl [MFC], SetBoolValue
- CMFCFilterChunkValueImpl [MFC], SetDwordValue
- CMFCFilterChunkValueImpl [MFC], SetFileTimeValue
- CMFCFilterChunkValueImpl [MFC], SetInt64Value
- CMFCFilterChunkValueImpl [MFC], SetIntValue
- CMFCFilterChunkValueImpl [MFC], SetLongValue
- CMFCFilterChunkValueImpl [MFC], SetSystemTimeValue
- CMFCFilterChunkValueImpl [MFC], SetTextValue
- CMFCFilterChunkValueImpl [MFC], SetChunk
ms.assetid: 3c833f23-5b88-4d08-9e09-ca6a8aec88bf
ms.openlocfilehash: 2c90a873033516710077d31c8bb8af5fb5172ca6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367504"
---
# <a name="cmfcfilterchunkvalueimpl-class"></a>Classe CMFCFilterChunkValueImpl

Esta é uma classe que simplifica a lógica do par de valores de pedaço e propriedade.

## <a name="syntax"></a>Sintaxe

```
class CMFCFilterChunkValueImpl : public ATL::IFilterChunkValue;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCFilterChunkValueImpl::~CMFCFilterChunkValueImpl](#_dtorcmfcfilterchunkvalueimpl)|Destrói o objeto.|
|[CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl](#cmfcfilterchunkvalueimpl)|Constrói o objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCFilterChunkValueImpl::Clear](#clear)|Limpa o ChunkValue.|
|[CMFCFilterChunkValueImpl::CopyChunk](#copychunk)|Copia este pedaço para uma estrutura descrevendo as características de um pedaço.|
|[CMFCFilterChunkValueImpl::CopyFrom](#copyfrom)|Inicializa esse valor de pedaço do outro valor.|
|[CMFCFilterChunkValueImpl::GetChunkGUID](#getchunkguid)|Recupera o pedaço GUID.|
|[CMFCFilterChunkValueImpl::GetChunkPID](#getchunkpid)|Recupera o pid de bloco (id de propriedade).|
|[CMFCFilterChunkValueImpl::GetChunkType](#getchunktype)|Fica do tipo pedaço.|
|[CMFCFilterChunkValueImpl::GetString](#getstring)|Recupera o valor da seqüência.|
|[CMFCFilterChunkValueImpl:GetValue](#getvalue)|Recupera o valor como uma variante de propação alocada.|
|[CMFCFilterChunkValueImpl::GetValueNoAlloc](#getvaluenoalloc)|Retorna valor não alocado (valor interno).|
|[CMFCFilterChunkValueImpl:IsValid](#isvalid)|Verifica se esse valor de propriedade é válido ou não.|
|[CMFCFilterChunkValueImpl::SetBoolValue](#setboolvalue)|Sobrecarregado. Define a propriedade por chave para um booleano.|
|[CMFCFilterChunkValueImpl::SetDwordValue](#setdwordvalue)|Define a propriedade por chave para um DWORD.|
|[CMFCFilterChunkValueImpl::SetFileTimeValue](#setfiletimevalue)|Define a propriedade por chave para um tempo de arquivo.|
|[CMFCFilterChunkValueImpl::SetInt64Value](#setint64value)|Define a propriedade por chave para um int64.|
|[CMFCFilterChunkValueImpl::SetIntValue](#setintvalue)|Define a propriedade por chave para um int.|
|[CMFCFilterChunkValueImpl::SetLongValue](#setlongvalue)|Define a propriedade por chave para um LONG.|
|[CMFCFilterChunkValueImpl::SetSystemTimeValue](#setsystemtimevalue)|Define a propriedade por chave para um SystemTime.|
|[CMFCFilterChunkValueImpl::SetTextValue](#settextvalue)|Define a propriedade por chave para uma seqüência unicode.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCFilterChunkValueImpl::SetChunk](#setchunk)|Uma função auxiliar que define as propriedades comuns do pedaço.|

## <a name="remarks"></a>Comentários

Para usar, basta criar uma classe CMFCFilterChunkValueImpl do tipo certo

Exemplo:

CMFCFilterChunkValueIl chunk;

hr = pedaço. SetBoolValue (PKEY_IsAttachment, verdade);

ou

hr = pedaço. SetFileTimeValue(PKEY_ItemDate, ftLastModified);

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ATL::IFilterChunkValue`

[CMFCFilterChunkValueImpl](../../mfc/reference/cmfcfilterchunkvalueimpl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cmfcfilterchunkvalueimplclear"></a><a name="clear"></a>CMFCFilterChunkValueImpl::Clear

Limpa o ChunkValue.

```
void Clear();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplcmfcfilterchunkvalueimpl"></a><a name="cmfcfilterchunkvalueimpl"></a>CMFCFilterChunkValueImpl::CMFCFilterChunkValueImpl

Constrói o objeto.

```
CMFCFilterChunkValueImpl();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplcmfcfilterchunkvalueimpl"></a><a name="_dtorcmfcfilterchunkvalueimpl"></a>CMFCFilterChunkValueImpl::~CMFCFilterChunkValueImpl

Destrói o objeto.

```
virtual ~CMFCFilterChunkValueImpl();
```

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplcopychunk"></a><a name="copychunk"></a>CMFCFilterChunkValueImpl::CopyChunk

Copia este pedaço para uma estrutura descrevendo as características de um pedaço.

```
HRESULT CopyChunk(STAT_CHUNK* pStatChunk);
```

### <a name="parameters"></a>Parâmetros

*pStatChunk*<br/>
Um ponteiro para o valor de destino descrevendo as características do pedaço.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplcopyfrom"></a><a name="copyfrom"></a>CMFCFilterChunkValueImpl::CopyFrom

Inicializa esse valor de pedaço do outro valor.

```
void CopyFrom (IFilterChunkValue* pValue);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Especifica o valor de origem a ser copiado.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetchunkguid"></a><a name="getchunkguid"></a>CMFCFilterChunkValueImpl::GetChunkGUID

Recupera o pedaço GUID.

```
REFGUID GetChunkGUID() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência a um GUID identificando o pedaço.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetchunkpid"></a><a name="getchunkpid"></a>CMFCFilterChunkValueImpl::GetChunkPID

Recupera o pid de bloco (id de propriedade).

```
DWORD GetChunkPID() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DWORD contendo o ID de propriedade.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetchunktype"></a><a name="getchunktype"></a>CMFCFilterChunkValueImpl::GetChunkType

Recupera o tipo de pedaço.

```
CHUNKSTATE GetChunkType() const;
```

### <a name="return-value"></a>Valor retornado

Um valor enumerado CHUNKSTATE, que especifica se o pedaço atual é uma propriedade do tipo texto ou uma propriedade do tipo valor.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetstring"></a><a name="getstring"></a>CMFCFilterChunkValueImpl::GetString

Recupera o valor da seqüência.

```
CString &GetString();
```

### <a name="return-value"></a>Valor retornado

Uma seqüência contendo o valor do pedaço.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetvalue"></a><a name="getvalue"></a>CMFCFilterChunkValueImpl:GetValue

Recupera o valor como uma variante de propação alocada.

```
HRESULT GetValue(PROPVARIANT** ppPropVariant);
```

### <a name="parameters"></a>Parâmetros

*ppPropVariant*<br/>
Quando a função retorna, este parâmetro contém o valor do pedaço.

### <a name="return-value"></a>Valor retornado

S_OK se propvariant foi alocado com sucesso e o valor do pedaço foi copiado com sucesso para *ppPropVariant*; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplgetvaluenoalloc"></a><a name="getvaluenoalloc"></a>CMFCFilterChunkValueImpl::GetValueNoAlloc

Retorna o valor não alocado (valor interno).

```
PROPVARIANT GetValueNoAlloc ();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor atual do pedaço.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplisvalid"></a><a name="isvalid"></a>CMFCFilterChunkValueImpl:IsValid

Verifica se esse valor de propriedade é válido ou não.

```
BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o valor do pedaço atual for válido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetboolvalue"></a><a name="setboolvalue"></a>CMFCFilterChunkValueImpl::SetBoolValue

Sobrecarregado. Define a propriedade por chave para um booleano.

```
HRESULT SetBoolValue(
    REFPROPERTYKEY pkey,
    BOOL bVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);

HRESULT SetBoolValue(
    REFPROPERTYKEY pkey,
    VARIANT_BOOL bVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*bVal*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetchunk"></a><a name="setchunk"></a>CMFCFilterChunkValueImpl::SetChunk

Uma função auxiliar que define as propriedades comuns do pedaço.

```
HRESULT SetChunk(
    REFPROPERTYKEY pkey,
    CHUNKSTATE chunkType=CHUNK_VALUE,
    LCID locale=0,
    DWORD cwcLenSource=0,
    DWORD cwcStartSource=0,
    CHUNK_BREAKTYPE chunkBreakType=CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; código de erro de outra forma.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetdwordvalue"></a><a name="setdwordvalue"></a>CMFCFilterChunkValueImpl::SetDwordValue

Defina a propriedade por chave para um DWORD.

```
HRESULT SetDwordValue(
    REFPROPERTYKEY pkey,
    DWORD dwVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*dwVal*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetfiletimevalue"></a><a name="setfiletimevalue"></a>CMFCFilterChunkValueImpl::SetFileTimeValue

Defina a propriedade por chave para um tempo de arquivo.

```
HRESULT SetFileTimeValue(
    REFPROPERTYKEY pkey,
    FILETIME dtVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*dtVal*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetint64value"></a><a name="setint64value"></a>CMFCFilterChunkValueImpl::SetInt64Value

Defina a propriedade por chave para um int64.

```
HRESULT SetInt64Value(
    REFPROPERTYKEY pkey,
    __int64 nVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*nVal*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetintvalue"></a><a name="setintvalue"></a>CMFCFilterChunkValueImpl::SetIntValue

Defina a propriedade por chave para um int.

```
HRESULT SetIntValue(
    REFPROPERTYKEY pkey,
    int nVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*nVal*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetlongvalue"></a><a name="setlongvalue"></a>CMFCFilterChunkValueImpl::SetLongValue

Defina a propriedade por chave para um LONG.

```
HRESULT SetLongValue(
    REFPROPERTYKEY pkey,
    long lVal,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*Val*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsetsystemtimevalue"></a><a name="setsystemtimevalue"></a>CMFCFilterChunkValueImpl::SetSystemTimeValue

Define a propriedade por chave para um SystemTime.

```
HRESULT SetSystemTimeValue(
    REFPROPERTYKEY pkey,
    const SYSTEMTIME& systemTime,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale=0,
    DWORD cwcLenSource=0,
    DWORD cwcStartSource=0,
    CHUNK_BREAKTYPE chunkBreakType=CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*Systemtime*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cmfcfilterchunkvalueimplsettextvalue"></a><a name="settextvalue"></a>CMFCFilterChunkValueImpl::SetTextValue

Define a propriedade por chave para uma seqüência unicode.

```
HRESULT SetTextValue(
    REFPROPERTYKEY pkey,
    LPCTSTR pszValue,
    CHUNKSTATE chunkType = CHUNK_VALUE,
    LCID locale = 0,
    DWORD cwcLenSource = 0,
    DWORD cwcStartSource = 0,
    CHUNK_BREAKTYPE chunkBreakType = CHUNK_NO_BREAK);
```

### <a name="parameters"></a>Parâmetros

*Pkey*<br/>
Especifica uma chave de propriedade.

*Pszvalue*<br/>
Especifica o valor do pedaço a ser definido.

*chunkType*<br/>
Os sinalizadores indicam se esse pedaço contém um tipo de texto ou uma propriedade do tipo valor. Os valores da bandeira são retirados da enumeração CHUNKSTATE.

*Localidade*<br/>
A linguagem e a sublinguagem associadas a um pedaço de texto. O local de bloco é usado por indexadores de documentos para executar a quebra de texto adequada. Se o pedaço não for do tipo de texto nem de um tipo de valor com VT_LPWSTR, VT_LPSTR ou VT_BSTR, este campo será ignorado.

*cwcLenSource*<br/>
O comprimento dos caracteres do texto de origem do qual o pedaço atual foi derivado. Um valor zero significa correspondência caractere por caractere entre o texto-origem e o texto derivado. Um valor não zero significa que não existe tal correspondência direta.

*cwcStartSource*<br/>
O deslocamento a partir do qual o texto de origem para um pedaço derivado começa no pedaço de origem.

*chunkBreakType*<br/>
O tipo de quebra que separa o pedaço anterior do pedaço atual. Os valores são da enumeração CHUNK_BREAKTYPE.

### <a name="return-value"></a>Valor retornado

S_OK se for bem sucedido; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
