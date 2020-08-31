---
title: Classe CObArray
description: Referência de API para a `CObArray` `MFC` classe que armazena `CObject` ponteiros em uma matriz.
ms.date: 08/27/2020
f1_keywords:
- CObArray
- AFXCOLL/CObArray
- AFXCOLL/CObArray::CObArray
- AFXCOLL/CObArray::Add
- AFXCOLL/CObArray::Append
- AFXCOLL/CObArray::Copy
- AFXCOLL/CObArray::ElementAt
- AFXCOLL/CObArray::FreeExtra
- AFXCOLL/CObArray::GetAt
- AFXCOLL/CObArray::GetCount
- AFXCOLL/CObArray::GetData
- AFXCOLL/CObArray::GetSize
- AFXCOLL/CObArray::GetUpperBound
- AFXCOLL/CObArray::InsertAt
- AFXCOLL/CObArray::IsEmpty
- AFXCOLL/CObArray::RemoveAll
- AFXCOLL/CObArray::RemoveAt
- AFXCOLL/CObArray::SetAt
- AFXCOLL/CObArray::SetAtGrow
- AFXCOLL/CObArray::SetSize
helpviewer_keywords:
- CObArray [MFC], CObArray
- CObArray [MFC], Add
- CObArray [MFC], Append
- CObArray [MFC], Copy
- CObArray [MFC], ElementAt
- CObArray [MFC], FreeExtra
- CObArray [MFC], GetAt
- CObArray [MFC], GetCount
- CObArray [MFC], GetData
- CObArray [MFC], GetSize
- CObArray [MFC], GetUpperBound
- CObArray [MFC], InsertAt
- CObArray [MFC], IsEmpty
- CObArray [MFC], RemoveAll
- CObArray [MFC], RemoveAt
- CObArray [MFC], SetAt
- CObArray [MFC], SetAtGrow
- CObArray [MFC], SetSize
ms.assetid: 27894efd-2370-4776-9ed9-24a98492af17
ms.openlocfilehash: cbc1799a9634b3d8c09077b755b8a097289460fd
ms.sourcegitcommit: c8f1605354724a13566bc3b0fac3c5d98265f1d0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2020
ms.locfileid: "89062140"
---
# <a name="cobarray-class"></a>Classe CObArray

Dá suporte a matrizes de `CObject` ponteiros.

## <a name="syntax"></a>Syntax

```cpp
class CObArray : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::CObArray](#cobarray)|Constrói uma matriz vazia para `CObject` ponteiros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray:: Adicionar](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CObArray:: Append](#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray:: copiar](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CObArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CObArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CObArray:: GetCount](#getcount)|Obtém o número de elementos nesta matriz.|
|[CObArray:: GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser `NULL`.|
|[CObArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|
|[CObArray::GetUpperBound](#getupperbound)|Retorna o maior índice válido.|
|[CObArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CObArray:: IsEmpty](#isempty)|Determina se a matriz está vazia.|
|[CObArray:: RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|
|[CObArray:: RemoveAt](#removeat)|Remove um elemento a um índice específico.|
|[CObArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CObArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CObArray:: SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CObArray:: \]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Essas matrizes de objeto são semelhantes às matrizes C, mas podem ser reduzidas e aumentadas dinamicamente conforme necessário.

Os índices de matrizes sempre começam na posição 0. Você pode decidir se deseja corrigir o limite superior ou permitir que a matriz se expanda quando adicionar elementos após o limite atual. A memória é alocada de forma contígua para o limite superior, mesmo que alguns elementos sejam `NULL` .

No Win32, o tamanho de um `CObArray` objeto é limitado apenas à memória disponível.

Assim como acontece com uma matriz C, o tempo de acesso para um `CObArray` elemento indexado é constante e é independente do tamanho da matriz.

`CObArray` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e ao despejo de seus elementos. Se uma matriz de `CObject` ponteiros for armazenada em um arquivo morto, com o operador de inserção sobrecarregado ou com a `Serialize` função de membro, cada `CObject` elemento será, por sua vez, serializado junto com seu índice de matriz.

Se você precisar de um despejo de `CObject` elementos individuais em uma matriz, deverá definir a profundidade do `CDumpContext` objeto como 1 ou maior.

Quando um `CObArray` objeto é excluído ou quando seus elementos são removidos, somente os `CObject` ponteiros são removidos, não os objetos que eles referenciam.

> [!NOTE]
> Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

A derivação de classe de matriz é semelhante à derivação de lista. Para obter detalhes sobre a derivação de uma classe de lista de finalidade especial, consulte o artigo [coleções](../../mfc/collections.md).

> [!NOTE]
> Você deve usar a macro IMPLEMENT_SERIAL na implementação da classe derivada se pretender serializar a matriz.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CObArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="cobarrayadd"></a><a name="add"></a> CObArray:: Adicionar

Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.

```cpp
INT_PTR Add(CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*newElement*\
O `CObject` ponteiro a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor Retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Se [SetSize](#setsize) tiver sido usado com um valor de *nGrowBy* maior que 1, a memória extra poderá ser alocada. No entanto, o limite superior aumentará apenas em 1.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::Add` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`INT_PTR Add(BYTE newElement);`<br /><br />`throw(CMemoryException*);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`INT_PTR Add(DWORD newElement);`<br /><br />`throw(CMemoryException*);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`INT_PTR Add(void* newElement);`<br /><br />`throw(CMemoryException*);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`INT_PTR Add(LPCTSTR newElement); throw(CMemoryException*);`<br /><br />`INT_PTR Add(const CString& newElement);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`INT_PTR Add(UINT newElement);`<br /><br />`throw(CMemoryException*);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`INT_PTR Add(WORD newElement);`<br /><br />`throw(CMemoryException*);`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#75](../../mfc/codesnippet/cpp/cobarray-class_1.cpp)]

Os resultados desse programa são os seguintes:

```Output
Add example: A CObArray with 2 elements
[0] = a CAge at $442A 21
[1] = a CAge at $4468 40
```

## <a name="cobarrayappend"></a><a name="append"></a> CObArray:: Append

Chame essa função de membro para adicionar o conteúdo de outra matriz ao final da matriz especificada.

```cpp
INT_PTR Append(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*orig*\
Origem dos elementos a serem acrescentados à matriz.

### <a name="return-value"></a>Valor Retornado

O índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

As matrizes devem ser do mesmo tipo.

Se necessário, o `Append` pode alocar memória extra para acomodar os elementos acrescentados à matriz.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::Append` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`INT_PTR Append(const CByteArray& src);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`INT_PTR Append(const CDWordArray& src);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`INT_PTR Append(const CPtrArray& src);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`INT_PTR Append(const CStringArray& src);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`INT_PTR Append(const CUIntArray& src);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`INT_PTR Append(const CWordArray& src);`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#76](../../mfc/codesnippet/cpp/cobarray-class_2.cpp)]

## <a name="cobarraycopy"></a><a name="copy"></a> CObArray:: copiar

Chame essa função de membro para substituir os elementos da matriz especificada pelos elementos de outra matriz do mesmo tipo.

```cpp
void Copy(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*orig*\
Origem dos elementos a serem copiados para a matriz.

### <a name="remarks"></a>Comentários

`Copy` não libera memória. Se necessário, `Copy` o pode alocar memória extra para acomodar os elementos copiados para a matriz.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::Copy` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void Copy(const CByteArray& src);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void Copy(const CDWordArray& src);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void Copy(const CPtrArray& src);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void Copy(const CStringArray& src);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void Copy(const CUIntArray& src);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void Copy(const CWordArray& src);`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#77](../../mfc/codesnippet/cpp/cobarray-class_3.cpp)]

## <a name="cobarraycobarray"></a><a name="cobarray"></a> CObArray::CObArray

Constrói uma matriz de `CObject` ponteiros vazia.

```cpp
CObArray();
```

### <a name="remarks"></a>Comentários

A matriz aumenta um elemento por vez.

A tabela a seguir mostra outros construtores que são semelhantes a `CObArray::CObArray` .

|Classe|Construtor|
|-----------|-----------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`CByteArray();`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`CDWordArray();`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`CPtrArray();`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`CStringArray();`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`CUIntArray();`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`CWordArray();`|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#78](../../mfc/codesnippet/cpp/cobarray-class_4.cpp)]

## <a name="cobarrayelementat"></a><a name="elementat"></a> CObArray::ElementAt

Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.

```cpp
CObject*& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound` .

### <a name="return-value"></a>Valor Retornado

Uma referência a um `CObject` ponteiro.

### <a name="remarks"></a>Comentários

Ele é usado para implementar o operador de atribuição do lado esquerdo para matrizes. Essa é uma função avançada que deve ser usada apenas para implementar operadores de matriz especiais.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::ElementAt` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`BYTE& ElementAt(INT_PTR nIndex);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`DWORD& ElementAt(INT_PTR nIndex);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void*& ElementAt(INT_PTR nIndex);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`CString& ElementAt(INT_PTR nIndex);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`UINT& ElementAt(INT_PTR nIndex);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`WORD& ElementAt(INT_PTR nIndex);`|

### <a name="example"></a>Exemplo

Consulte o exemplo de [CObArray:: GetSize](#getsize).

## <a name="cobarrayfreeextra"></a><a name="freeextra"></a> CObArray::FreeExtra

Libera qualquer memória extra que foi alocada enquanto a matriz foi expandida.

```cpp
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Essa função não tem efeito sobre o tamanho ou limite superior da matriz.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::FreeExtra` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void FreeExtra();`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void FreeExtra();`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void FreeExtra();`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void FreeExtra();`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void FreeExtra();`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void FreeExtra();`|

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CObArray:: GetData](#getdata).

## <a name="cobarraygetat"></a><a name="getat"></a> CObArray::GetAt

Retorna o elemento de matriz no índice especificado.

```cpp
CObject* GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound` .

### <a name="return-value"></a>Valor Retornado

O `CObject` elemento de ponteiro atualmente neste índice.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Passar um valor negativo ou um valor maior que o valor retornado por resultará `GetUpperBound` em uma asserção com falha.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::GetAt` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`BYTE GetAt(INT_PTR nIndex) const;`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`DWORD GetAt(INT_PTR nIndex) const;`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void* GetAt(INT_PTR nIndex) const;`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`CString GetAt(INT_PTR nIndex) const;`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`UINT GetAt(INT_PTR nIndex) const;`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`WORD GetAt(INT_PTR nIndex) const;`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#79](../../mfc/codesnippet/cpp/cobarray-class_5.cpp)]

## <a name="cobarraygetcount"></a><a name="getcount"></a> CObArray:: GetCount

Retorna o número de elementos da matriz.

```cpp
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor Retornado

O número de itens na matriz.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos na matriz. Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::GetCount` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`INT_PTR GetCount() const;`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`INT_PTR GetCount() const;`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`INT_PTR GetCount() const;`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`INT_PTR GetCount() const;`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`INT_PTR GetCount() const;`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`INT_PTR GetCount() const;`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#80](../../mfc/codesnippet/cpp/cobarray-class_6.cpp)]

## <a name="cobarraygetdata"></a><a name="getdata"></a> CObArray:: GetData

Use essa função de membro para obter acesso direto aos elementos na matriz.

```cpp
const CObject** GetData() const;

CObject** GetData();
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para a matriz de `CObject` ponteiros.

### <a name="remarks"></a>Comentários

Se nenhum elemento estiver disponível, `GetData` o retornará um `NULL` valor.

Embora o acesso direto aos elementos de uma matriz possa ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao chamar `GetData` ; qualquer erro que você faça afeta diretamente os elementos da matriz.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::GetData` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`const BYTE* GetData() const; BYTE* GetData();`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`const DWORD* GetData() const; DWORD* GetData();`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`const void** GetData() const; void** GetData();`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`const CString* GetData() const; CString* GetData();`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`const UINT* GetData() const; UINT* GetData();`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`const WORD* GetData() const; WORD* GetData();`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#81](../../mfc/codesnippet/cpp/cobarray-class_7.cpp)]

## <a name="cobarraygetsize"></a><a name="getsize"></a> CObArray::GetSize

Retorna o tamanho da matriz.

```cpp
INT_PTR GetSize() const;
```

### <a name="remarks"></a>Comentários

Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::GetSize` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`INT_PTR GetSize() const;`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`INT_PTR GetSize() const;`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`INT_PTR GetSize() const;`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`INT_PTR GetSize() const;`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`INT_PTR GetSize() const;`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`INT_PTR GetSize() const;`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#82](../../mfc/codesnippet/cpp/cobarray-class_8.cpp)]

## <a name="cobarraygetupperbound"></a><a name="getupperbound"></a> CObArray::GetUpperBound

Retorna o limite superior atual desta matriz.

```cpp
INT_PTR GetUpperBound() const;
```

### <a name="return-value"></a>Valor Retornado

O índice do limite superior (baseado em zero).

### <a name="remarks"></a>Comentários

Como os índices de matriz são baseados em zero, essa função retorna um valor 1 menor que `GetSize` .

A condição `GetUpperBound() = -1` indica que a matriz não contém elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::GetUpperBound` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`INT_PTR GetUpperBound() const;`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`INT_PTR GetUpperBound() const;`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`INT_PTR GetUpperBound() const;`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`INT_PTR GetUpperBound() const;`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`INT_PTR GetUpperBound() const;`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`INT_PTR GetUpperBound() const;`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#83](../../mfc/codesnippet/cpp/cobarray-class_9.cpp)]

## <a name="cobarrayinsertat"></a><a name="insertat"></a> CObArray::InsertAt

Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.

```cpp
void InsertAt(
    INT_PTR nIndex,
    CObject* newElement,
    INT_PTR nCount = 1);

void InsertAt(
    INT_PTR nStartIndex,
    CObArray* pNewArray);
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice de inteiro que pode ser maior que o valor retornado por `GetUpperBound` .

*newElement*\
O `CObject` ponteiro a ser colocado nessa matriz. Um *newElement* de valor `NULL` é permitido.

*nCount*\
O número de vezes que esse elemento deve ser inserido (o padrão é 1).

*nStartIndex*\
Um índice de inteiro que pode ser maior que o valor retornado por `GetUpperBound` .

*pNewArray*\
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

A primeira versão de `InsertAt` insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz. No processo, ele muda (incrementando o índice) para o elemento existente nesse índice e muda todos os elementos acima dele para cima.

A segunda versão insere todos os elementos de outra `CObArray` coleção, começando na posição *nStartIndex* .

A `SetAt` função, por outro lado, substitui um elemento de matriz especificado e não altera os elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::InsertAt` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void InsertAt(INT_PTR nIndex, BYTE newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CByteArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void InsertAt(INT_PTR nIndex, DWORD newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CDWordArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void InsertAt(INT_PTR nIndex, void* newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CPtrArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void InsertAt(INT_PTR nIndex, LPCTSTR newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CStringArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void InsertAt(INT_PTR nIndex, UINT newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CUIntArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void InsertAt(INT_PTR nIndex, WORD newElement, int nCount = 1);`<br /><br />`throw(CMemoryException*);`<br /><br />`void InsertAt(INT_PTR nStartIndex, CWordArray* pNewArray);`<br /><br />`throw(CMemoryException*);`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#84](../../mfc/codesnippet/cpp/cobarray-class_10.cpp)]

Os resultados desse programa são os seguintes:

```Output
InsertAt example: A CObArray with 3 elements
[0] = a CAge at $45C8 21
[1] = a CAge at $4646 30
[2] = a CAge at $4606 40
```

## <a name="cobarrayisempty"></a><a name="isempty"></a> CObArray:: IsEmpty

Determina se a matriz está vazia.

```cpp
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor Retornado

Diferente de zero se a matriz estiver vazia; caso contrário, 0.

## <a name="cobarrayoperator--"></a><a name="operator_at"></a> CObArray:: operator []

Esses operadores de subscritor são um substituto conveniente para `SetAt` as `GetAt` funções e.

```cpp
CObject*& operator[](int_ptr nindex);
CObject* operator[](int_ptr nindex) const;
```

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **`const`** , pode ser usado na direita (r-value) ou na esquerda (l-Value) de uma instrução de atribuição. O segundo, chamado para **`const`** matrizes, pode ser usado somente à direita.

A versão de depuração da biblioteca é declarada se o subscrito (no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.

A tabela a seguir mostra outros operadores semelhantes ao `CObArray::operator []` .

|Classe|Operador|
|-----------|--------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`BYTE& operator [](INT_PTR nindex);`<br /><br />`BYTE operator [](INT_PTR nindex) const;`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`DWORD& operator [](INT_PTR nindex);`<br /><br />`DWORD operator [](INT_PTR nindex) const;`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void*& operator [](INT_PTR nindex);`<br /><br />`void* operator [](INT_PTR nindex) const;`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`CString& operator [](INT_PTR nindex);`<br /><br />`CString operator [](INT_PTR nindex) const;`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`UINT& operator [](INT_PTR nindex);`<br /><br />`UINT operator [](INT_PTR nindex) const;`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`WORD& operator [](INT_PTR nindex);`<br /><br />`WORD operator [](INT_PTR nindex) const;`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#88](../../mfc/codesnippet/cpp/cobarray-class_11.cpp)]

## <a name="cobarrayremoveall"></a><a name="removeall"></a> CObArray:: RemoveAll

Remove todos os ponteiros dessa matriz, mas, na verdade, não exclui os `CObject` objetos.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Se a matriz já estiver vazia, a função ainda funcionará.

A `RemoveAll` função libera toda a memória usada para o armazenamento de ponteiro.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::RemoveAll` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void RemoveAll();`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void RemoveAll();`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void RemoveAll();`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void RemoveAll();`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void RemoveAll();`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void RemoveAll();`|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#85](../../mfc/codesnippet/cpp/cobarray-class_12.cpp)]

## <a name="cobarrayremoveat"></a><a name="removeat"></a> CObArray:: RemoveAt

Remove um ou mais elementos que começam em um índice especificado em uma matriz.

```cpp
void RemoveAt(
    INT_PTR nIndex,
    INT_PTR nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound` .

*nCount*\
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

No processo, ele muda para baixo todos os elementos acima dos elemento (s) removidos. Ele diminui o limite superior da matriz, mas não libera memória.

Se você tentar remover mais elementos do que os contidos na matriz acima do ponto de remoção, a versão de depuração da biblioteca será declarada.

A `RemoveAt` função remove o `CObject` ponteiro da matriz, mas não exclui o objeto em si.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::RemoveAt` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void RemoveAt(INT_PTR nIndex, INT_PTR nCount = 1);`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#112](../../mfc/codesnippet/cpp/cobarray-class_13.cpp)]

Os resultados desse programa são os seguintes:

```Output
RemoveAt example: A CObArray with 1 elements
[0] = a CAge at $4606 40
```

## <a name="cobarraysetat"></a><a name="setat"></a> CObArray::SetAt

Define o elemento de matriz no índice especificado.

```cpp
void SetAt(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound` .

*newElement*\
O ponteiro de objeto a ser inserido nesta matriz. Um `NULL` valor é permitido.

### <a name="remarks"></a>Comentários

`SetAt` Não fará com que a matriz cresça. Use `SetAtGrow` se você quiser que a matriz cresça automaticamente.

Verifique se o valor do índice representa uma posição válida na matriz. Se estiver fora dos limites, a versão de depuração da biblioteca será declarada.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::SetAt` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void SetAt(INT_PTR nIndex, BYTE newElement);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void SetAt(INT_PTR nIndex, DWORD newElement);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void SetAt(INT_PTR nIndex, void* newElement);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void SetAt(INT_PTR nIndex, LPCTSTR newElement);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void SetAt(INT_PTR nIndex, UINT newElement);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void SetAt(INT_PTR nIndex, WORD newElement);`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#86](../../mfc/codesnippet/cpp/cobarray-class_14.cpp)]

Os resultados desse programa são os seguintes:

```Output
SetAt example: A CObArray with 2 elements
[0] = a CAge at $47E0 30
[1] = a CAge at $47A0 40
```

## <a name="cobarraysetatgrow"></a><a name="setatgrow"></a> CObArray::SetAtGrow

Define o elemento de matriz no índice especificado.

```cpp
void SetAtGrow(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*\
Um índice de inteiro maior ou igual a 0.

*newElement*\
O ponteiro de objeto a ser adicionado a esta matriz. Um `NULL` valor é permitido.

### <a name="remarks"></a>Comentários

A matriz aumenta automaticamente, se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::SetAtGrow` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void SetAtGrow(INT_PTR nIndex, BYTE newElement);`<br /><br />`throw(CMemoryException*);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void SetAtGrow(INT_PTR nIndex, DWORD newElement);`<br /><br />`throw(CMemoryException*);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void SetAtGrow(INT_PTR nIndex, void* newElement);`<br /><br />`throw( CMemoryException*);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void SetAtGrow(INT_PTR nIndex, LPCTSTR newElement);`<br /><br />`throw(CMemoryException*);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void SetAtGrow(INT_PTR nIndex, UINT newElement);`<br /><br />`throw(CMemoryException*);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void SetAtGrow(INT_PTR nIndex, WORD newElement);`<br /><br />`throw(CMemoryException*);`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#87](../../mfc/codesnippet/cpp/cobarray-class_15.cpp)]

Os resultados desse programa são os seguintes:

```Output
SetAtGrow example: A CObArray with 4 elements
[0] = a CAge at $47C0 21
[1] = a CAge at $4800 40
[2] = NULL
[3] = a CAge at $4840 65
```

## <a name="cobarraysetsize"></a><a name="setsize"></a> CObArray:: SetSize

Estabelece o tamanho de uma matriz vazia ou existente; aloca memória, se necessário.

```cpp
void SetSize(
    INT_PTR nNewSize,
    INT_PTR nGrowBy = -1);
```

### <a name="parameters"></a>Parâmetros

*nNewSize*\
O novo tamanho da matriz (número de elementos). Deve ser maior ou igual a 0.

*nGrowBy*\
O número mínimo de Slots de elemento a serem alocados se um aumento de tamanho for necessário.

### <a name="remarks"></a>Comentários

Se o novo tamanho for menor do que o tamanho antigo, a matriz será truncada e toda a memória não utilizada será liberada. Para obter eficiência, chame `SetSize` para definir o tamanho da matriz antes de usá-la. Isso impede a necessidade de realocar e copiar a matriz cada vez que um item é adicionado.

O parâmetro *nGrowBy* afeta a alocação de memória interna enquanto a matriz está crescendo. Seu uso nunca afeta o tamanho da matriz conforme relatado por `GetSize` e `GetUpperBound` .

Se o tamanho da matriz for aumentado, todos os ponteiros alocados recentemente `CObject *` serão definidos como `NULL` .

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObArray::SetSize` .

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|`void SetSize(INT_PTR nNewSize, int nGrowBy = -1);`<br /><br /> `throw(CMemoryException*);`|

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CObArray:: GetData](#getdata).

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)\
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)\
[Classe CStringArray](../../mfc/reference/cstringarray-class.md)\
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)\
[Classe CByteArray](../../mfc/reference/cbytearray-class.md)\
[Classe CWordArray](../../mfc/reference/cwordarray-class.md)\
[Classe CDWordArray](../../mfc/reference/cdwordarray-class.md)
