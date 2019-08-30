---
title: Classe COleSafeArray
ms.date: 08/29/2019
f1_keywords:
- COleSafeArray
- AFXDISP/COleSafeArray
- AFXDISP/COleSafeArray::COleSafeArray
- AFXDISP/COleSafeArray::AccessData
- AFXDISP/COleSafeArray::AllocData
- AFXDISP/COleSafeArray::AllocDescriptor
- AFXDISP/COleSafeArray::Attach
- AFXDISP/COleSafeArray::Clear
- AFXDISP/COleSafeArray::Copy
- AFXDISP/COleSafeArray::Create
- AFXDISP/COleSafeArray::CreateOneDim
- AFXDISP/COleSafeArray::Destroy
- AFXDISP/COleSafeArray::DestroyData
- AFXDISP/COleSafeArray::DestroyDescriptor
- AFXDISP/COleSafeArray::Detach
- AFXDISP/COleSafeArray::GetByteArray
- AFXDISP/COleSafeArray::GetDim
- AFXDISP/COleSafeArray::GetElement
- AFXDISP/COleSafeArray::GetElemSize
- AFXDISP/COleSafeArray::GetLBound
- AFXDISP/COleSafeArray::GetOneDimSize
- AFXDISP/COleSafeArray::GetUBound
- AFXDISP/COleSafeArray::Lock
- AFXDISP/COleSafeArray::PtrOfIndex
- AFXDISP/COleSafeArray::PutElement
- AFXDISP/COleSafeArray::Redim
- AFXDISP/COleSafeArray::ResizeOneDim
- AFXDISP/COleSafeArray::UnaccessData
- AFXDISP/COleSafeArray::Unlock
helpviewer_keywords:
- COleSafeArray [MFC], COleSafeArray
- COleSafeArray [MFC], AccessData
- COleSafeArray [MFC], AllocData
- COleSafeArray [MFC], AllocDescriptor
- COleSafeArray [MFC], Attach
- COleSafeArray [MFC], Clear
- COleSafeArray [MFC], Copy
- COleSafeArray [MFC], Create
- COleSafeArray [MFC], CreateOneDim
- COleSafeArray [MFC], Destroy
- COleSafeArray [MFC], DestroyData
- COleSafeArray [MFC], DestroyDescriptor
- COleSafeArray [MFC], Detach
- COleSafeArray [MFC], GetByteArray
- COleSafeArray [MFC], GetDim
- COleSafeArray [MFC], GetElement
- COleSafeArray [MFC], GetElemSize
- COleSafeArray [MFC], GetLBound
- COleSafeArray [MFC], GetOneDimSize
- COleSafeArray [MFC], GetUBound
- COleSafeArray [MFC], Lock
- COleSafeArray [MFC], PtrOfIndex
- COleSafeArray [MFC], PutElement
- COleSafeArray [MFC], Redim
- COleSafeArray [MFC], ResizeOneDim
- COleSafeArray [MFC], UnaccessData
- COleSafeArray [MFC], Unlock
ms.assetid: f45a5224-5f48-40ec-9ddd-287ef9740150
ms.openlocfilehash: a0ce0fc03923806c9e044a7edae3178fd3429b76
ms.sourcegitcommit: e10a5feea193c249ddc5a6faba48e7c6d8784e73
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/30/2019
ms.locfileid: "70177398"
---
# <a name="colesafearray-class"></a>Classe COleSafeArray

Uma classe para trabalhar com matrizes de tipo e dimensão arbitrárias.

## <a name="syntax"></a>Sintaxe

```
class COleSafeArray : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleSafeArray::COleSafeArray](#colesafearray)|Constrói um objeto `COleSafeArray`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleSafeArray::AccessData](#accessdata)|Recupera um ponteiro para os dados da matriz.|
|[COleSafeArray::AllocData](#allocdata)|Aloca memória para a matriz.|
|[COleSafeArray::AllocDescriptor](#allocdescriptor)|Aloca memória para o descritor de matriz seguro.|
|[COleSafeArray::Attach](#attach)|Dá ao controle da matriz `VARIANT` existente para o `COleSafeArray` objeto.|
|[COleSafeArray::Clear](#clear)|Libera todos os dados no subjacente `VARIANT`.|
|[COleSafeArray::Copy](#copy)|Cria uma cópia de uma matriz existente.|
|[COleSafeArray::Create](#create)|Cria uma matriz segura.|
|[COleSafeArray::CreateOneDim](#createonedim)|Cria um objeto unidimensional `COleSafeArray` .|
|[COleSafeArray::Destroy](#destroy)|Destrói uma matriz existente.|
|[COleSafeArray::DestroyData](#destroydata)|Destrói dados em uma matriz segura.|
|[COleSafeArray::DestroyDescriptor](#destroydescriptor)|Destrói um descritor de uma matriz segura.|
|[COleSafeArray::Detach](#detach)|Desanexa a matriz variante do `COleSafeArray` objeto (para que os dados não sejam liberados).|
|[COleSafeArray::GetByteArray](#getbytearray)|Copia o conteúdo da matriz segura em um [CByteArray](../../mfc/reference/cbytearray-class.md).|
|[COleSafeArray::GetDim](#getdim)|Retorna o número de dimensões na matriz.|
|[COleSafeArray::GetElement](#getelement)|Recupera um único elemento da matriz segura.|
|[COleSafeArray::GetElemSize](#getelemsize)|Retorna o tamanho, em bytes, de um elemento em uma matriz segura.|
|[COleSafeArray::GetLBound](#getlbound)|Retorna o limite inferior de qualquer dimensão de uma matriz segura.|
|[COleSafeArray::GetOneDimSize](#getonedimsize)|Retorna o número de elementos no objeto unidimensional `COleSafeArray` .|
|[COleSafeArray::GetUBound](#getubound)|Retorna o limite superior de qualquer dimensão de uma matriz segura.|
|[COleSafeArray::Lock](#lock)|Incrementa a contagem de bloqueios de uma matriz e coloca um ponteiro nos dados da matriz no descritor de matriz.|
|[COleSafeArray::PtrOfIndex](#ptrofindex)|Retorna um ponteiro para o elemento indexado.|
|[COleSafeArray::PutElement](#putelement)|Atribui um único elemento à matriz.|
|[COleSafeArray::Redim](#redim)|Altera o limite menos significativo (mais à direita) de uma matriz segura.|
|[COleSafeArray::ResizeOneDim](#resizeonedim)|Altera o número de elementos em um objeto unidimensional `COleSafeArray` .|
|[COleSafeArray::UnaccessData](#unaccessdata)|Decrementa a contagem de bloqueios de uma matriz e invalida o ponteiro recuperado pelo `AccessData`.|
|[COleSafeArray::Unlock](#unlock)|Decrementa a contagem de bloqueios de uma matriz para que ela possa ser liberada ou redimensionada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador COleSafeArray:: Operator LPCVARIANT](#operator_lpcvariant)|Acessa a estrutura subjacente `VARIANT` `COleSafeArray` do objeto.|
|[Operador COleSafeArray:: Operator LPVARIANT](#operator_lpvariant)|Acessa a estrutura subjacente `VARIANT` `COleSafeArray` do objeto.|
|[COleSafeArray:: Operator =](#operator_eq)|Copia valores em um `COleSafeArray` objeto (`SAFEARRAY`, `VARIANT`, `COleVariant`ou `COleSafeArray` matriz).|
|[COleSafeArray:: Operator = =](#operator_eq_eq)|Compara duas matrizes Variant`SAFEARRAY`( `VARIANT`, `COleVariant`, ou `COleSafeArray` matrizes).|
|[Operador COleSafeArray::&lt;&lt;](#operator_lt_lt)|Gera o conteúdo de um `COleSafeArray` objeto para o contexto de despejo.|

## <a name="remarks"></a>Comentários

`COleSafeArray`deriva da estrutura OLE `VARIANT` . As funções `SAFEARRAY` de membro OLE estão disponíveis `COleSafeArray`por meio do, bem como um conjunto de funções de membro especificamente projetadas para matrizes unidimensionais de bytes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`COleSafeArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="accessdata"></a>  COleSafeArray::AccessData

Recupera um ponteiro para os dados da matriz.

```
void AccessData(void** ppvData);
```

### <a name="parameters"></a>Parâmetros

*ppvData*<br/>
Um ponteiro para um ponteiro para os dados da matriz.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#26](../../mfc/codesnippet/cpp/colesafearray-class_1.cpp)]

##  <a name="allocdata"></a>  COleSafeArray::AllocData

Aloca memória para uma matriz segura.

```
void AllocData();
```

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="allocdescriptor"></a>  COleSafeArray::AllocDescriptor

Aloca memória para o descritor de uma matriz segura.

```
void AllocDescriptor(DWORD dwDims);
```

### <a name="parameters"></a>Parâmetros

*dwDims*<br/>
Número de dimensões na matriz segura.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="attach"></a>COleSafeArray:: Attach

Fornece controle dos dados em uma matriz existente `VARIANT` para o `COleSafeArray` objeto.

```
void Attach(VARIANT& varSrc);
```

### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um objeto `VARIANT`. O parâmetro *varSrc* deve ter o VarType [VT_ARRAY](/windows/win32/api/wtypes/ne-wtypes-varenum).

### <a name="remarks"></a>Comentários

O tipo `VARIANT`da origem é definido como VT_EMPTY. Essa função limpa os dados da matriz atual, se houver.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleSafeArray:: AccessData](#accessdata).

##  <a name="clear"></a>COleSafeArray:: Clear

Limpa a matriz segura.

```
void Clear();
```

### <a name="remarks"></a>Comentários

A função limpa uma matriz segura definindo o `VARTYPE` do objeto como VT_EMPTY. O conteúdo atual é liberado e a matriz é liberada.

##  <a name="colesafearray"></a>  COleSafeArray::COleSafeArray

Constrói um objeto `COleSafeArray`.

```
COleSafeArray();

COleSafeArray(
    const SAFEARRAY& saSrc,
    VARTYPE vtSrc);

COleSafeArray(
    LPCSAFEARRAY pSrc,
    VARTYPE vtSrc);

COleSafeArray(const COleSafeArray& saSrc);
COleSafeArray(const VARIANT& varSrc);
COleSafeArray(LPCVARIANT pSrc);
COleSafeArray(const COleVariant& varSrc);
```

### <a name="parameters"></a>Parâmetros

*saSrc*<br/>
Um objeto `COleSafeArray` existente ou `SAFEARRAY` a ser copiado para o `COleSafeArray` novo objeto.

*vtSrc*<br/>
O VarType do novo `COleSafeArray` objeto.

*psaSrc*<br/>
Um ponteiro para um `SAFEARRAY` a ser copiado para o `COleSafeArray` novo objeto.

*varSrc*<br/>
Um objeto `VARIANT` existente `COleVariant` ou a ser copiado para o `COleSafeArray` novo objeto.

*pSrc*<br/>
Um ponteiro para um `VARIANT` objeto a ser copiado para o `COleSafeArray` novo objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleSafeArray` objetos. Se não houver nenhum parâmetro, um objeto `COleSafeArray` vazio será criado (VT_EMPTY). Se o `COleSafeArray` for copiado de outra matriz cujo VARTYPE é conhecido implicitamente ( `COleSafeArray`a `COleVariant`, ou `VARIANT`), o VarType da matriz de origem será retido e não precisará ser especificado. Se o `COleSafeArray` for copiado de outra matriz cujo VARTYPE não é conhecido`SAFEARRAY`(), o VarType deverá ser especificado no parâmetro *vtSrc* .

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="copy"></a>COleSafeArray:: copiar

Cria uma cópia de uma matriz segura existente.

```
void Copy(LPSAFEARRAY* ppsa);
```

### <a name="parameters"></a>Parâmetros

*ppsa*<br/>
Ponteiro para um local no qual retornar o novo descritor de matriz.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="create"></a>  COleSafeArray::Create

Aloca e inicializa os dados para a matriz.

```
void Create(
    VARTYPE vtSrc,
    DWORD dwDims,
    DWORD* rgElements);

void Create(
    VARTYPE vtSrc,
    DWORD dwDims,
    SAFEARRAYBOUND* rgsabounds);
```

### <a name="parameters"></a>Parâmetros

*vtSrc*<br/>
O tipo base da matriz (ou seja, o VARTYPE de cada elemento da matriz). O VARTYPE é restrito a um subconjunto dos tipos variantes. Nem o sinalizador VT_ARRAY nem o VT_BYREF pode ser definido. VT_EMPTY e VT_NULL não são tipos base válidos para a matriz. Todos os outros tipos são legais.

*dwDims*<br/>
Número de dimensões na matriz. Isso pode ser alterado depois que a matriz é criada com o [ReDim](#redim).

*rgElements*<br/>
Ponteiro para uma matriz do número de elementos para cada dimensão na matriz.

*rgsabounds*<br/>
Ponteiro para um vetor de limites (um para cada dimensão) a ser alocado para a matriz.

### <a name="remarks"></a>Comentários

Essa função limpará os dados da matriz atual, se necessário. Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#27](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]

##  <a name="createonedim"></a>  COleSafeArray::CreateOneDim

Cria um novo objeto unidimensional `COleSafeArray` .

```
void CreateOneDim(
    VARTYPE vtSrc,
    DWORD dwElements,
    const void* pvSrcData = NULL,
    long nLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*vtSrc*<br/>
O tipo base da matriz (ou seja, o VARTYPE de cada elemento da matriz).

*dwElements*<br/>
Número de elementos na matriz. Isso pode ser alterado depois que a matriz é criada com [ResizeOneDim](#resizeonedim).

*pvSrcData*<br/>
Ponteiro para os dados a serem copiados para a matriz.

*nLBound*<br/>
O limite inferior da matriz.

### <a name="remarks"></a>Comentários

A função aloca e inicializa os dados para a matriz, copiando os dados especificados se o ponteiro *pvSrcData* não for nulo.

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#28](../../mfc/codesnippet/cpp/colesafearray-class_3.cpp)]

##  <a name="destroy"></a>  COleSafeArray::Destroy

Destrói um descritor de matriz existente e todos os dados na matriz.

```
void Destroy();
```

### <a name="remarks"></a>Comentários

Se os objetos forem armazenados na matriz, cada objeto será liberado. Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="destroydata"></a>  COleSafeArray::DestroyData

Destrói todos os dados em uma matriz segura.

```
void DestroyData();
```

### <a name="remarks"></a>Comentários

Se os objetos forem armazenados na matriz, cada objeto será liberado. Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="destroydescriptor"></a>  COleSafeArray::DestroyDescriptor

Destrói um descritor de uma matriz segura.

```
void DestroyDescriptor();
```

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="detach"></a>  COleSafeArray::Detach

Desanexa os `VARIANT` dados `COleSafeArray` do objeto.

```
VARIANT Detach();
```

### <a name="return-value"></a>Valor de retorno

O valor `VARIANT` subjacente `COleSafeArray` no objeto.

### <a name="remarks"></a>Comentários

A função desanexa os dados em uma matriz segura definindo o VARTYPE do objeto como VT_EMPTY. É responsabilidade do chamador liberar a matriz chamando a função do Windows [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear).

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleSafeArray::P utelement](#putelement).

##  <a name="getbytearray"></a>  COleSafeArray::GetByteArray

Copia o conteúdo da matriz segura em um `CByteArray`.

```
void GetByteArray(CByteArray& bytes);
```

### <a name="parameters"></a>Parâmetros

*bytes*<br/>
Uma referência a um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) .

##  <a name="getdim"></a>  COleSafeArray::GetDim

Retorna o número de dimensões no `COleSafeArray` objeto.

```
DWORD GetDim();
```

### <a name="return-value"></a>Valor de retorno

O número de dimensões na matriz segura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#27](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]

##  <a name="getelement"></a>  COleSafeArray::GetElement

Recupera um único elemento da matriz segura.

```
void GetElement(
    long* rgIndices,
    void* pvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Ponteiro para uma matriz de índices para cada dimensão da matriz.

*pvData*<br/>
Ponteiro para o local para posicionar o elemento da matriz.

### <a name="remarks"></a>Comentários

Essa função chama automaticamente as funções `SafeArrayLock` do Windows e `SafeArrayUnlock` antes e depois da recuperação do elemento. Se o elemento de dados for uma cadeia de caracteres, um objeto ou uma variante, a função copiará o elemento da maneira correta. O parâmetro *pvData* deve apontar para um buffer grande o suficiente para conter o elemento.

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#29](../../mfc/codesnippet/cpp/colesafearray-class_4.cpp)]

##  <a name="getelemsize"></a>  COleSafeArray::GetElemSize

Recupera o tamanho de um elemento em um `COleSafeArray` objeto.

```
DWORD GetElemSize();
```

### <a name="return-value"></a>Valor de retorno

O tamanho, em bytes, dos elementos de uma matriz segura.

##  <a name="getlbound"></a>  COleSafeArray::GetLBound

Retorna o limite inferior de qualquer dimensão de um `COleSafeArray` objeto.

```
void GetLBound(
    DWORD dwDim,
    long* pLBound);
```

### <a name="parameters"></a>Parâmetros

*dwDim*<br/>
A dimensão de matriz para a qual obter o limite inferior.

*pLBound*<br/>
Ponteiro para o local para retornar o limite inferior.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#30](../../mfc/codesnippet/cpp/colesafearray-class_5.cpp)]

##  <a name="getonedimsize"></a>  COleSafeArray::GetOneDimSize

Retorna o número de elementos no objeto unidimensional `COleSafeArray` .

```
DWORD GetOneDimSize();
```

### <a name="return-value"></a>Valor de retorno

O número de elementos na matriz segura unidimensional.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleSafeArray:: CreateOneDim](#createonedim).

##  <a name="getubound"></a>  COleSafeArray::GetUBound

Retorna o limite superior de qualquer dimensão de uma matriz segura.

```
void GetUBound(
    DWORD dwDim,
    long* pUBound);
```

### <a name="parameters"></a>Parâmetros

*dwDim*<br/>
A dimensão de matriz para a qual obter o limite superior.

*pUBound*<br/>
Ponteiro para o local para retornar o limite superior.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#31](../../mfc/codesnippet/cpp/colesafearray-class_6.cpp)]

##  <a name="lock"></a>  COleSafeArray::Lock

Incrementa a contagem de bloqueios de uma matriz e coloca um ponteiro para os dados da matriz no descritor de matriz.

```
void Lock();
```

### <a name="remarks"></a>Comentários

Se houver erro, ele lançará um [COleException](../../mfc/reference/coleexception-class.md).

O ponteiro no descritor de matriz é válido `Unlock` até que seja chamado. As chamadas `Lock` para podem ser aninhadas; um número igual de `Unlock` chamadas para é necessário.

Uma matriz não pode ser excluída enquanto está bloqueada.

##  <a name="operator_lpcvariant"></a>Operador COleSafeArray:: Operator LPCVARIANT

Chame esse operador de conversão para acessar a `VARIANT` estrutura subjacente desse `COleSafeArray` objeto.

```
operator LPCVARIANT() const;
```

##  <a name="operator_lpvariant"></a>Operador COleSafeArray:: Operator LPVARIANT

Chame esse operador de conversão para acessar a `VARIANT` estrutura subjacente desse `COleSafeArray` objeto.

```
operator LPVARIANT();
```

### <a name="remarks"></a>Comentários

Observe que a alteração do valor na `VARIANT` estrutura acessada pelo ponteiro retornado por essa função alterará o valor `COleSafeArray` desse objeto.

##  <a name="operator_eq"></a>COleSafeArray:: Operator =

Esses operadores de atribuição sobrecarregados copiam o valor `COleSafeArray` de origem nesse objeto.

```
COleSafeArray& operator=(const COleSafeArray& saSrc);
COleSafeArray& operator=(const VARIANT& varSrc);
COleSafeArray& operator=(LPCVARIANT pSrc);
COleSafeArray& operator=(const COleVariant& varSrc);
```

### <a name="remarks"></a>Comentários

Segue uma breve descrição de cada operador:

- **Operator = (** *saSrc* **)** Copia um objeto `COleSafeArray` existente nesse objeto.

- **Operator = (** *varSrc* **)** Copia um existente `VARIANT` ou `COleVariant` uma matriz nesse objeto.

- **Operator = (** *pSrc* **)** Copia o `VARIANT` objeto de matriz acessado por *pSrc* nesse objeto.

##  <a name="operator_eq_eq"></a>COleSafeArray:: Operator = =

Esse operador compara duas matrizes`SAFEARRAY`( `VARIANT`, `COleVariant`, ou `COleSafeArray` matrizes) e retorna zero, se forem iguais; caso contrário, 0.

```
BOOL operator==(const SAFEARRAY& saSrc) const;  BOOL operator==(LPCSAFEARRAY pSrc) const;

BOOL operator==(const COleSafeArray& saSrc) const;  BOOL operator==(const VARIANT& varSrc) const;

BOOL operator==(LPCVARIANT pSrc) const;  BOOL operator==(const COleVariant& varSrc) const;
```

### <a name="remarks"></a>Comentários

Duas matrizes são iguais se tiverem um número igual de dimensões, tamanho igual em cada dimensão e valores de elemento iguais.

##  <a name="operator_lt_lt"></a>Operador COleSafeArray::&lt;&lt;

O `COleSafeArray` operador de inserção (< <) dá suporte ao despejo de diagnóstico `COleSafeArray` e ao armazenamento de um objeto em um arquivo morto.

```
CDumpContext& AFXAPI operator<<(
    CDumpContext& dc,
    COleSafeArray& saSrc);
```

##  <a name="ptrofindex"></a>COleSafeArray::P trOfIndex

Retorna um ponteiro para o elemento especificado pelos valores de índice.

```
void PtrOfIndex(
    long* rgIndices,
    void** ppvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Uma matriz de valores de índice que identificam um elemento da matriz. Todos os índices do elemento devem ser especificados.

*ppvData*<br/>
No retorno, o ponteiro para o elemento identificado pelos valores em *rgIndices*.

##  <a name="putelement"></a>  COleSafeArray::PutElement

Atribui um único elemento à matriz.

```
void PutElement(
    long* rgIndices,
    void* pvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Ponteiro para uma matriz de índices para cada dimensão da matriz.

*pvData*<br/>
Ponteiro para os dados a serem atribuídos à matriz. Os tipos de variante VT_DISPATCH, VT_UNKNOWN e VT_BSTR são ponteiros e não exigem outro nível de indireção.

### <a name="remarks"></a>Comentários

Essa função chama automaticamente as funções do Windows [SafeArrayLock](/windows/win32/api/oleauto/nf-oleauto-safearraylock) e [SafeArrayUnlock](/windows/win32/api/oleauto/nf-oleauto-safearrayunlock) antes e depois de atribuir o elemento. Se o elemento de dados for uma cadeia de caracteres, um objeto ou uma variante, a função o copiará corretamente e se o elemento existente for uma cadeia de caracteres, objeto ou variante, ele será limpo corretamente.

Observe que você pode ter vários bloqueios em uma matriz, de modo que você pode colocar elementos em uma matriz enquanto a matriz está bloqueada por outras operações.

Se houver erro, a função lançará um [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#32](../../mfc/codesnippet/cpp/colesafearray-class_7.cpp)]

##  <a name="redim"></a>  COleSafeArray::Redim

Altera o limite menos significativo (mais à direita) de uma matriz segura.

```
void Redim(SAFEARRAYBOUND* psaboundNew);
```

### <a name="parameters"></a>Parâmetros

*psaboundNew*<br/>
Ponteiro para uma nova estrutura associada à matriz segura que contém a nova matriz associada. Somente a dimensão menos significativa de uma matriz pode ser alterada.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

##  <a name="resizeonedim"></a>  COleSafeArray::ResizeOneDim

Altera o número de elementos em um objeto unidimensional `COleSafeArray` .

```
void ResizeOneDim(DWORD dwElements);
```

### <a name="parameters"></a>Parâmetros

*dwElements*<br/>
Número de elementos na matriz segura unidimensional.

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleSafeArray:: CreateOneDim](#createonedim).

##  <a name="unaccessdata"></a>  COleSafeArray::UnaccessData

Decrementa a contagem de bloqueios de uma matriz e invalida o ponteiro recuperado pelo `AccessData`.

```
void UnaccessData();
```

### <a name="remarks"></a>Comentários

Se houver erro, a função lançará um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [COleSafeArray:: AccessData](#accessdata).

##  <a name="unlock"></a>COleSafeArray:: desbloquear

Decrementa a contagem de bloqueios de uma matriz para que ela possa ser liberada ou redimensionada.

```
void Unlock();
```

### <a name="remarks"></a>Comentários

Essa função é chamada depois que o acesso aos dados em uma matriz é concluído. Se houver erro, ele lançará um [COleException](../../mfc/reference/coleexception-class.md).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleVariant](../../mfc/reference/colevariant-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
