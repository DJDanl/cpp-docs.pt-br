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
ms.openlocfilehash: 10e9975bac776429a38bfc707215a9465ce35c2e
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753765"
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
|[COleSafeArray::AllocDescriptor](#allocdescriptor)|Aloca a memória para o descritor da matriz segura.|
|[COleSafeArray::Anexar](#attach)|Dá o controle `VARIANT` da matriz `COleSafeArray` existente ao objeto.|
|[COleSafeArray::Clear](#clear)|Libera todos os dados `VARIANT`na parte subjacente.|
|[COleSafeArray::Cópia](#copy)|Cria uma cópia de uma matriz existente.|
|[COleSafeArray::Criar](#create)|Cria uma matriz segura.|
|[COleSafeArray::CreateOneDim](#createonedim)|Cria um objeto `COleSafeArray` unidimensional.|
|[COleSafeArray::Destroy](#destroy)|Destrói uma matriz existente.|
|[COleSafeArray::DestroyData](#destroydata)|Destrói dados em uma matriz segura.|
|[COleSafeArray::DestroyDescriptor](#destroydescriptor)|Destrói um descritor de uma matriz segura.|
|[COleSafeArray::Detach](#detach)|Destaca a matriz VARIANT `COleSafeArray` do objeto (para que os dados não sejam liberados).|
|[COleSafeArray::GetByteArray](#getbytearray)|Copia o conteúdo da matriz segura em um [CByteArray](../../mfc/reference/cbytearray-class.md).|
|[COleSafeArray::GetDim](#getdim)|Retorna o número de dimensões na matriz.|
|[COleSafeArray::GetElement](#getelement)|Recupera um único elemento da matriz segura.|
|[COleSafeArray::GetElemSize](#getelemsize)|Retorna o tamanho, em bytes, de um elemento em uma matriz segura.|
|[COleSafeArray::GetLBound](#getlbound)|Retorna o limite inferior para qualquer dimensão de uma matriz segura.|
|[COleSafeArray::GetOneDimSize](#getonedimsize)|Retorna o número de elementos `COleSafeArray` no objeto unidimensional.|
|[COleSafeArray::GetUBound](#getubound)|Retorna o limite superior para qualquer dimensão de uma matriz segura.|
|[COleSafeArray::Bloqueio](#lock)|Incrementa a contagem de bloqueio de uma matriz e coloca um ponteiro para os dados da matriz no descritor da matriz.|
|[COleSafeArray::PtrOfIndex](#ptrofindex)|Retorna um ponteiro para o elemento indexado.|
|[COleSafeArray::PutElement](#putelement)|Atribui um único elemento à matriz.|
|[COleSafeArray::Redim](#redim)|Altera o limite menos significativo (à direita) de uma matriz segura.|
|[COleSafeArray::RedimensiononeDim](#resizeonedim)|Altera o número de elementos `COleSafeArray` em um objeto unidimensional.|
|[COleSafeArray::UnaccessData](#unaccessdata)|Diminui a contagem de bloqueio de uma matriz e `AccessData`invalida o ponteiro recuperado por .|
|[COleSafeArray::Unlock](#unlock)|Decreta a contagem de bloqueios de uma matriz para que possa ser liberada ou redimensionada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleSafeArray::operador LPCVARIANT](#operator_lpcvariant)|Acessa a `VARIANT` estrutura `COleSafeArray` subjacente do objeto.|
|[COleSafeArray::operador LPVARIANT](#operator_lpvariant)|Acessa a `VARIANT` estrutura `COleSafeArray` subjacente do objeto.|
|[COleSafeArray::operador =](#operator_eq)|Copia valores `COleSafeArray` em`SAFEARRAY` `VARIANT`um `COleVariant`objeto `COleSafeArray` (, , ou matriz).|
|[COleSafeArray::operador ==](#operator_eq_eq)|Compara duas matrizes`SAFEARRAY` `VARIANT`variantes (, , `COleVariant`ou `COleSafeArray` matrizes).|
|[COleSafeArray::operador&lt;&lt;](#operator_lt_lt)|Produz o conteúdo `COleSafeArray` de um objeto para o contexto de despejo.|

## <a name="remarks"></a>Comentários

`COleSafeArray`deriva da estrutura `VARIANT` OLE. As funções do membro `SAFEARRAY` `COleSafeArray`OLE estão disponíveis através de , bem como um conjunto de funções de membros especificamente projetadas para matrizes unidimensionais de bytes.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`COleSafeArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="colesafearrayaccessdata"></a><a name="accessdata"></a>COleSafeArray::AccessData

Recupera um ponteiro para os dados da matriz.

```cpp
void AccessData(void** ppvData);
```

### <a name="parameters"></a>Parâmetros

*ppvData*<br/>
Um ponteiro para um ponteiro para os dados da matriz.

### <a name="remarks"></a>Comentários

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#26](../../mfc/codesnippet/cpp/colesafearray-class_1.cpp)]

## <a name="colesafearrayallocdata"></a><a name="allocdata"></a>COleSafeArray::AllocData

Aloca memória para uma matriz segura.

```cpp
void AllocData();
```

### <a name="remarks"></a>Comentários

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearrayallocdescriptor"></a><a name="allocdescriptor"></a>COleSafeArray::AllocDescriptor

Aloca memória para o descritor de uma matriz segura.

```cpp
void AllocDescriptor(DWORD dwDims);
```

### <a name="parameters"></a>Parâmetros

*dwDims*<br/>
Número de dimensões na matriz segura.

### <a name="remarks"></a>Comentários

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearrayattach"></a><a name="attach"></a>COleSafeArray::Anexar

Fornece o controle dos dados `VARIANT` em `COleSafeArray` uma matriz existente para o objeto.

```cpp
void Attach(VARIANT& varSrc);
```

### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto `VARIANT` . O parâmetro *varSrc* deve ter o VARType [VT_ARRAY](/windows/win32/api/wtypes/ne-wtypes-varenum).

### <a name="remarks"></a>Comentários

O `VARIANT`tipo de origem está definido como VT_EMPTY. Esta função limpa os dados do array atual, se houver.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleSafeArray::AccessData](#accessdata).

## <a name="colesafearrayclear"></a><a name="clear"></a>COleSafeArray::Clear

Limpa a matriz segura.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

A função limpa uma matriz `VARTYPE` segura definindo o objeto para VT_EMPTY. O conteúdo atual é liberado e a matriz é liberada.

## <a name="colesafearraycolesafearray"></a><a name="colesafearray"></a>COleSafeArray::COleSafeArray

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
Um objeto `COleSafeArray` existente `SAFEARRAY` ou a ser `COleSafeArray` copiado para o novo objeto.

*Vtsrc*<br/>
O VARTYPE do `COleSafeArray` novo objeto.

*psaSrc*<br/>
Um ponteiro `SAFEARRAY` para um a ser `COleSafeArray` copiado para o novo objeto.

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um objeto `VARIANT` `COleVariant` existente ou a ser `COleSafeArray` copiado para o novo objeto.

*Psrc*<br/>
Um ponteiro `VARIANT` para um objeto a `COleSafeArray` ser copiado para o novo objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam `COleSafeArray` novos objetos. Se não houver parâmetro, `COleSafeArray` um objeto vazio será criado (VT_EMPTY). Se `COleSafeArray` a matriz for copiada de outra matriz `COleSafeArray`cujo `COleVariant`VARTYPE seja conhecido implicitamente (a , ou `VARIANT`), o VARTYPE da matriz de origem será retido e não precisa ser especificado. Se `COleSafeArray` o for copiado de outra matriz`SAFEARRAY`cujo VARTYPE não é conhecido ( ), o VARTYPE deve ser especificado no parâmetro *vtSrc.*

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearraycopy"></a><a name="copy"></a>COleSafeArray::Cópia

Cria uma cópia de uma matriz de segurança existente.

```cpp
void Copy(LPSAFEARRAY* ppsa);
```

### <a name="parameters"></a>Parâmetros

*ppsa*<br/>
Ponteiro para um local no qual retornar o novo descritor de matriz.

### <a name="remarks"></a>Comentários

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearraycreate"></a><a name="create"></a>COleSafeArray::Criar

Aloca e inicializa os dados para a matriz.

```cpp
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

*Vtsrc*<br/>
O tipo base da matriz (ou seja, o VARTYPE de cada elemento da matriz). O VARTYPE é restrito a um subconjunto dos tipos de variantes. Nem a bandeira VT_ARRAY nem a VT_BYREF podem ser definidas. VT_EMPTY e VT_NULL não são tipos de base válidos para a matriz. Todos os outros tipos são legais.

*dwDims*<br/>
Número de dimensões na matriz. Isso pode ser alterado depois que a matriz for criada com [o Redim](#redim).

*rgElementos*<br/>
Ponteiro para uma matriz do número de elementos para cada dimensão na matriz.

*rgsabounds*<br/>
Ponteiro para um vetor de limites (um para cada dimensão) para alocar para a matriz.

### <a name="remarks"></a>Comentários

Esta função limpará os dados do array atual, se necessário. No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#27](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]

## <a name="colesafearraycreateonedim"></a><a name="createonedim"></a>COleSafeArray::CreateOneDim

Cria um novo `COleSafeArray` objeto unidimensional.

```cpp
void CreateOneDim(
    VARTYPE vtSrc,
    DWORD dwElements,
    const void* pvSrcData = NULL,
    long nLBound = 0);
```

### <a name="parameters"></a>Parâmetros

*Vtsrc*<br/>
O tipo base da matriz (ou seja, o VARTYPE de cada elemento da matriz).

*dwElements*<br/>
Número de elementos na matriz. Isso pode ser alterado depois que a matriz for criada com [ResizeOneDim](#resizeonedim).

*pvSrcData*<br/>
Ponteiro para os dados para copiar na matriz.

*nLBound*<br/>
O limite inferior da matriz.

### <a name="remarks"></a>Comentários

A função aloca e inicializa os dados para o array, copiando os dados especificados se o ponteiro *pvSrcData* não for NULL.

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#28](../../mfc/codesnippet/cpp/colesafearray-class_3.cpp)]

## <a name="colesafearraydestroy"></a><a name="destroy"></a>COleSafeArray::Destroy

Destrói um descritor de matriz existente e todos os dados da matriz.

```cpp
void Destroy();
```

### <a name="remarks"></a>Comentários

Se os objetos forem armazenados na matriz, cada objeto será liberado. No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearraydestroydata"></a><a name="destroydata"></a>COleSafeArray::DestroyData

Destrói todos os dados em uma matriz segura.

```cpp
void DestroyData();
```

### <a name="remarks"></a>Comentários

Se os objetos forem armazenados na matriz, cada objeto será liberado. No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearraydestroydescriptor"></a><a name="destroydescriptor"></a>COleSafeArray::DestroyDescriptor

Destrói um descritor de uma matriz segura.

```cpp
void DestroyDescriptor();
```

### <a name="remarks"></a>Comentários

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearraydetach"></a><a name="detach"></a>COleSafeArray::Detach

Destaca os `VARIANT` dados do `COleSafeArray` objeto.

```
VARIANT Detach();
```

### <a name="return-value"></a>Valor retornado

O valor `VARIANT` subjacente `COleSafeArray` no objeto.

### <a name="remarks"></a>Comentários

A função destaca os dados em uma matriz segura, definindo o VARTYPE do objeto para VT_EMPTY. É responsabilidade do chamador liberar a matriz chamando a função do Windows [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear).

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleSafeArray::PutElement](#putelement).

## <a name="colesafearraygetbytearray"></a><a name="getbytearray"></a>COleSafeArray::GetByteArray

Copia o conteúdo da matriz `CByteArray`segura em um .

```cpp
void GetByteArray(CByteArray& bytes);
```

### <a name="parameters"></a>Parâmetros

*Bytes*<br/>
Uma referência a um objeto [CByteArray.](../../mfc/reference/cbytearray-class.md)

## <a name="colesafearraygetdim"></a><a name="getdim"></a>COleSafeArray::GetDim

Retorna o número de `COleSafeArray` dimensões no objeto.

```
DWORD GetDim();
```

### <a name="return-value"></a>Valor retornado

O número de dimensões na matriz segura.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#27](../../mfc/codesnippet/cpp/colesafearray-class_2.cpp)]

## <a name="colesafearraygetelement"></a><a name="getelement"></a>COleSafeArray::GetElement

Recupera um único elemento da matriz segura.

```cpp
void GetElement(
    long* rgIndices,
    void* pvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Ponteiro para uma matriz de índices para cada dimensão da matriz.

*Pvdata*<br/>
Ponteiro para o local para colocar o elemento da matriz.

### <a name="remarks"></a>Comentários

Esta função chama automaticamente as `SafeArrayLock` `SafeArrayUnlock` funções do windows e antes e depois de recuperar o elemento. Se o elemento de dados for uma seqüência, objeto ou variante, a função copia o elemento da maneira correta. O parâmetro *pvData* deve apontar para um buffer grande o suficiente para conter o elemento.

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#29](../../mfc/codesnippet/cpp/colesafearray-class_4.cpp)]

## <a name="colesafearraygetelemsize"></a><a name="getelemsize"></a>COleSafeArray::GetElemSize

Recupera o tamanho de um `COleSafeArray` elemento em um objeto.

```
DWORD GetElemSize();
```

### <a name="return-value"></a>Valor retornado

O tamanho, em bytes, dos elementos de uma matriz segura.

## <a name="colesafearraygetlbound"></a><a name="getlbound"></a>COleSafeArray::GetLBound

Retorna o limite inferior para `COleSafeArray` qualquer dimensão de um objeto.

```cpp
void GetLBound(
    DWORD dwDim,
    long* pLBound);
```

### <a name="parameters"></a>Parâmetros

*dwDim*<br/>
A dimensão da matriz para a qual obter o limite inferior.

*pLBound*<br/>
Ponteiro para o local para retornar o limite inferior.

### <a name="remarks"></a>Comentários

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#30](../../mfc/codesnippet/cpp/colesafearray-class_5.cpp)]

## <a name="colesafearraygetonedimsize"></a><a name="getonedimsize"></a>COleSafeArray::GetOneDimSize

Retorna o número de elementos `COleSafeArray` no objeto unidimensional.

```
DWORD GetOneDimSize();
```

### <a name="return-value"></a>Valor retornado

O número de elementos na matriz segura unidimensional.

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleSafeArray::CreateOneDim](#createonedim).

## <a name="colesafearraygetubound"></a><a name="getubound"></a>COleSafeArray::GetUBound

Retorna o limite superior para qualquer dimensão de uma matriz segura.

```cpp
void GetUBound(
    DWORD dwDim,
    long* pUBound);
```

### <a name="parameters"></a>Parâmetros

*dwDim*<br/>
A dimensão da matriz para a qual obter o limite superior.

*pUBound*<br/>
Ponteiro para o local para retornar o limite superior.

### <a name="remarks"></a>Comentários

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#31](../../mfc/codesnippet/cpp/colesafearray-class_6.cpp)]

## <a name="colesafearraylock"></a><a name="lock"></a>COleSafeArray::Bloqueio

Incrementa a contagem de bloqueio de uma matriz e coloque um ponteiro para os dados da matriz no descritor da matriz.

```cpp
void Lock();
```

### <a name="remarks"></a>Comentários

No erro, ele lança um [COleException](../../mfc/reference/coleexception-class.md).

O ponteiro no descritor da `Unlock` matriz é válido até ser chamado. Chamadas `Lock` para ser aninhado; um número igual `Unlock` de chamadas são necessárias.

Uma matriz não pode ser excluída enquanto estiver bloqueada.

## <a name="colesafearrayoperator-lpcvariant"></a><a name="operator_lpcvariant"></a>COleSafeArray::operador LPCVARIANT

Chame este operador de fundição para acessar a estrutura subjacente `VARIANT` para este `COleSafeArray` objeto.

```
operator LPCVARIANT() const;
```

## <a name="colesafearrayoperator-lpvariant"></a><a name="operator_lpvariant"></a>COleSafeArray::operador LPVARIANT

Chame este operador de fundição para acessar a estrutura subjacente `VARIANT` para este `COleSafeArray` objeto.

```
operator LPVARIANT();
```

### <a name="remarks"></a>Comentários

Observe que alterar o `VARIANT` valor na estrutura acessada pelo ponteiro retornado por esta função mudará o valor deste `COleSafeArray` objeto.

## <a name="colesafearrayoperator-"></a><a name="operator_eq"></a>COleSafeArray::operador =

Esses operadores de atribuição sobrecarregados `COleSafeArray` copiam o valor de origem para este objeto.

```
COleSafeArray& operator=(const COleSafeArray& saSrc);
COleSafeArray& operator=(const VARIANT& varSrc);
COleSafeArray& operator=(LPCVARIANT pSrc);
COleSafeArray& operator=(const COleVariant& varSrc);
```

### <a name="remarks"></a>Comentários

Segue-se uma breve descrição de cada operador:

- operador *=(saSrc* **)** **operator =(** Copia um `COleSafeArray` objeto existente para este objeto.

- operador *=(varSrc* **operator =(** **)** Copia uma `VARIANT` matriz `COleVariant` existente ou existente neste objeto.

- operador *=(pSrc* **operator =(** **)** Copia `VARIANT` o objeto de matriz acessado por *pSrc* neste objeto.

## <a name="colesafearrayoperator-"></a><a name="operator_eq_eq"></a>COleSafeArray::operador ==

Este operador compara duas`SAFEARRAY` `VARIANT`matrizes (, , `COleVariant`ou `COleSafeArray` matrizes) e retorna não zero se forem iguais; caso contrário, 0.

```
BOOL operator==(const SAFEARRAY& saSrc) const;  BOOL operator==(LPCSAFEARRAY pSrc) const;

BOOL operator==(const COleSafeArray& saSrc) const;  BOOL operator==(const VARIANT& varSrc) const;

BOOL operator==(LPCVARIANT pSrc) const;  BOOL operator==(const COleVariant& varSrc) const;
```

### <a name="remarks"></a>Comentários

Duas matrizes são iguais se tiverem um número igual de dimensões, tamanho igual em cada dimensão e valores de elementoiguais.

## <a name="colesafearrayoperator-ltlt"></a><a name="operator_lt_lt"></a>COleSafeArray::operador&lt;&lt;

O `COleSafeArray` operador de inserção (<<) suporta `COleSafeArray` dumping diagnóstico e armazenamento de um objeto para um arquivo.

```
CDumpContext& AFXAPI operator<<(
    CDumpContext& dc,
    COleSafeArray& saSrc);
```

## <a name="colesafearrayptrofindex"></a><a name="ptrofindex"></a>COleSafeArray::PtrOfIndex

Retorna um ponteiro para o elemento especificado pelos valores de índice.

```cpp
void PtrOfIndex(
    long* rgIndices,
    void** ppvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Uma matriz de valores de índice que identificam um elemento da matriz. Todos os índices para o elemento devem ser especificados.

*ppvData*<br/>
No retorno, ponteiro para o elemento identificado pelos valores em *rgIndices*.

## <a name="colesafearrayputelement"></a><a name="putelement"></a>COleSafeArray::PutElement

Atribui um único elemento à matriz.

```cpp
void PutElement(
    long* rgIndices,
    void* pvData);
```

### <a name="parameters"></a>Parâmetros

*rgIndices*<br/>
Ponteiro para uma matriz de índices para cada dimensão da matriz.

*Pvdata*<br/>
Ponteiro para os dados para atribuir à matriz. VT_DISPATCH, VT_UNKNOWN e VT_BSTR tipos de variantes são ponteiros e não requerem outro nível de indireção.

### <a name="remarks"></a>Comentários

Esta função chama automaticamente as funções do Windows [SafeArrayLock](/windows/win32/api/oleauto/nf-oleauto-safearraylock) e [SafeArrayUnlock](/windows/win32/api/oleauto/nf-oleauto-safearrayunlock) antes e depois de atribuir o elemento. Se o elemento de dados for uma seqüência, objeto ou variante, a função o copia corretamente e, se o elemento existente for uma seqüência, objeto ou variante, ele será limpo corretamente.

Observe que você pode ter vários bloqueios em uma matriz, para que você possa colocar elementos em uma matriz enquanto a matriz é bloqueada por outras operações.

No erro, a função lança uma [CMemoryException](../../mfc/reference/cmemoryexception-class.md) ou [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCOleContainer#32](../../mfc/codesnippet/cpp/colesafearray-class_7.cpp)]

## <a name="colesafearrayredim"></a><a name="redim"></a>COleSafeArray::Redim

Altera o limite menos significativo (à direita) de uma matriz segura.

```cpp
void Redim(SAFEARRAYBOUND* psaboundNew);
```

### <a name="parameters"></a>Parâmetros

*psaboundNew*<br/>
Ponteiro para uma nova estrutura de matriz segura vinculada contendo a nova matriz vinculada. Apenas a dimensão menos significativa de uma matriz pode ser alterada.

### <a name="remarks"></a>Comentários

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

## <a name="colesafearrayresizeonedim"></a><a name="resizeonedim"></a>COleSafeArray::RedimensiononeDim

Altera o número de elementos `COleSafeArray` em um objeto unidimensional.

```cpp
void ResizeOneDim(DWORD dwElements);
```

### <a name="parameters"></a>Parâmetros

*dwElements*<br/>
Número de elementos na matriz segura unidimensional.

### <a name="remarks"></a>Comentários

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleSafeArray::CreateOneDim](#createonedim).

## <a name="colesafearrayunaccessdata"></a><a name="unaccessdata"></a>COleSafeArray::UnaccessData

Diminui a contagem de bloqueio de uma matriz e `AccessData`invalida o ponteiro recuperado por .

```cpp
void UnaccessData();
```

### <a name="remarks"></a>Comentários

No erro, a função lança um [COleException](../../mfc/reference/coleexception-class.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [COleSafeArray::AccessData](#accessdata).

## <a name="colesafearrayunlock"></a><a name="unlock"></a>COleSafeArray::Unlock

Decreta a contagem de bloqueios de uma matriz para que possa ser liberada ou redimensionada.

```cpp
void Unlock();
```

### <a name="remarks"></a>Comentários

Esta função é chamada após o acesso aos dados em uma matriz é concluída. No erro, ele lança um [COleException](../../mfc/reference/coleexception-class.md).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleVariant](../../mfc/reference/colevariant-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
