---
title: Classe CObArray
ms.date: 11/04/2016
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
ms.openlocfilehash: c19715f62704bfc97059421451929cbbec2506ce
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754464"
---
# <a name="cobarray-class"></a>Classe CObArray

Suporta matrizes `CObject` de ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CObArray : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::CObArray](#cobarray)|Constrói uma matriz `CObject` vazia para ponteiros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::Adicionar](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CObArray::Apêndice](#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::Copiar](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CObArray::FreeExtra](#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CObArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CObArray::GetCount](#getcount)|Obtém o número de elementos nesta matriz.|
|[CObArray::GetData](#getdata)|Permite acesso aos elementos na matriz. Pode ser NULL.|
|[CObArray::GetSize](#getsize)|Obtém o número de elementos nesta matriz.|
|[CObArray::GetUpperBound](#getupperbound)|Retorna o maior índice válido.|
|[CObArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CObArray::IsEmpty](#isempty)|Determina se a matriz está vazia.|
|[CObArray::RemoveAll](#removeall)|Remove todos os elementos dessa matriz.|
|[CObArray::RemoveAt](#removeat)|Remove um elemento a um índice específico.|
|[CObArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CObArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CObArray::SetSize](#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::operador \[\]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Essas matrizes de objetos são semelhantes às matrizes C, mas podem encolher dinamicamente e crescer conforme necessário.

Os índices de matriz sempre começam na posição 0. Você pode decidir se deve corrigir o limite superior ou permitir que a matriz se expanda quando você adicionar elementos além do limite atual. A memória é atribuída contíguamente ao limite superior, mesmo que alguns elementos sejam nulos.

Em Win32, o `CObArray` tamanho de um objeto é limitado apenas à memória disponível.

Como em uma matriz C, `CObArray` o tempo de acesso para um elemento indexado é constante e é independente do tamanho da matriz.

`CObArray`incorpora a IMPLEMENT_SERIAL macro para apoiar a serialização e o dumping de seus elementos. Se um `CObject` conjunto de ponteiros for armazenado em um arquivo, `Serialize` seja com `CObject` o operador de inserção sobrecarregado ou com a função de membro, cada elemento será, por sua vez, serializado juntamente com seu índice de matriz.

Se você precisar de `CObject` um despejo de elementos individuais `CDumpContext` em uma matriz, você deve definir a profundidade do objeto para 1 ou maior.

Quando `CObArray` um objeto é excluído ou quando seus `CObject` elementos são removidos, apenas os ponteiros são removidos, não os objetos que eles referenciam.

> [!NOTE]
> Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

A derivação da classe array é semelhante à derivação da lista. Para obter detalhes sobre a derivação de uma classe de lista de propósito especial, consulte o artigo [Coleções](../../mfc/collections.md).

> [!NOTE]
> Você deve usar a macro IMPLEMENT_SERIAL na implementação de sua classe derivada se você pretende serializar a matriz.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CObArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll.h

## <a name="cobarrayadd"></a><a name="add"></a>CObArray::Adicionar

Adiciona um novo elemento ao final de uma matriz, aumentando a matriz em 1.

```
INT_PTR Add(CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*Newelement*<br/>
O `CObject` ponteiro a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Se [setSize](#setsize) tiver sido usado com um valor *nGrowBy* maior que 1, então a memória extra pode ser alocada. No entanto, o limite superior aumentará apenas 1.

A tabela a seguir mostra outras `CObArray::Add`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**INT_PTR Add (BYTE);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR Add (DWORD);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**INT_PTR Add (vazio);** <strong>\*</strong> `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**INT_PTR Add (LPCTSTR);** `newElement` **throw\* (CMemoryException);**<br /><br /> **adicionar INT_PTR (const CString** `newElement` **&);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**INT_PTR Adicionar (UINT);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**INT_PTR Add (WORD);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#75](../../mfc/codesnippet/cpp/cobarray-class_1.cpp)]

Os resultados deste programa são os seguintes:

```Output
Add example: A CObArray with 2 elements
[0] = a CAge at $442A 21
[1] = a CAge at $4468 40
```

## <a name="cobarrayappend"></a><a name="append"></a>CObArray::Apêndice

Chame esta função de membro para adicionar o conteúdo de outra matriz ao final da matriz dada.

```
INT_PTR Append(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Fonte dos elementos a serem anexados à matriz.

### <a name="return-value"></a>Valor retornado

O índice do primeiro elemento anexado.

### <a name="remarks"></a>Comentários

As matrizes devem ser do mesmo tipo.

Se necessário, `Append` pode alocar memória extra para acomodar os elementos anexados à matriz.

A tabela a seguir mostra outras `CObArray::Append`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**INT_PTR Apêndice (const CByteArray&** *src);* **);**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR Apêndice (const CDWordArray&** *src);* **);**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**INT_PTR Apêndice (const CPtrArray&** *src);* **);**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**INT_PTR Apêndice (const CStringArray&** *src);* **);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**INT_PTR Apêndice (const CUIntArray&** *src);* **);**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**INT_PTR Apêndice (const CWordArray&** *src);* **);**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#76](../../mfc/codesnippet/cpp/cobarray-class_2.cpp)]

## <a name="cobarraycopy"></a><a name="copy"></a>CObArray::Copiar

Chame esta função de membro para substituir os elementos da matriz dada com os elementos de outra matriz do mesmo tipo.

```cpp
void Copy(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Fonte dos elementos a serem copiados para a matriz.

### <a name="remarks"></a>Comentários

`Copy`não libera a memória; no entanto, `Copy` se necessário, pode alocar memória extra para acomodar os elementos copiados para a matriz.

A tabela a seguir mostra outras `CObArray::Copy`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void Copy (const CByteArray&** *src);* **);**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void Copy (const CDWordArray&** *src);* **);**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void Copy (const CPtrArray&** *src);* **);**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void Copy (const CStringArray&** *src);* **);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void Copy (const CUIntArray&** *src);* **);**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void Copy (const CWordArray&** *src);* **);**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#77](../../mfc/codesnippet/cpp/cobarray-class_3.cpp)]

## <a name="cobarraycobarray"></a><a name="cobarray"></a>CObArray::CObArray

Constrói uma `CObject` matriz de ponteiros vazio.

```
CObArray();
```

### <a name="remarks"></a>Comentários

A matriz cresce um elemento de cada vez.

A tabela a seguir mostra outros `CObArray::CObArray`construtores que são semelhantes a .

|Classe|Construtor|
|-----------|-----------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**CByteArray;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**CDWordArray;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**CPtrArray;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**Cstringarray;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**CUIntArray;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**CWordArray;**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#78](../../mfc/codesnippet/cpp/cobarray-class_4.cpp)]

## <a name="cobarrayelementat"></a><a name="elementat"></a>CObArray::ElementAt

Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.

```
CObject*& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `GetUpperBound`ao valor devolvido por .

### <a name="return-value"></a>Valor retornado

Uma referência `CObject` a um ponteiro.

### <a name="remarks"></a>Comentários

Ele é usado para implementar o operador de atribuição do lado esquerdo para matrizes. Observe que esta é uma função avançada que deve ser usada apenas para implementar operadores de array especiais.

A tabela a seguir mostra outras `CObArray::ElementAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**BYTE& elementat(INT_PTR);** `nIndex` **);**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**DWORD& ElementAt (INT_PTR);** `nIndex` **);**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**vazio\*& ElementAt (INT_PTR);** `nIndex` **);**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**Cstring& ElementAt (INT_PTR);** `nIndex` **);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**UINT& elementat (INT_PTR);** `nIndex` **);**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**WORD& ElementAt(INT_PTR);** `nIndex` **);**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetSize](#getsize).

## <a name="cobarrayfreeextra"></a><a name="freeextra"></a>CObArray::FreeExtra

Libera qualquer memória extra que foi alocada enquanto a matriz foi cultivada.

```cpp
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Esta função não tem efeito sobre o tamanho ou o limite superior da matriz.

A tabela a seguir mostra outras `CObArray::FreeExtra`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void FreeExtra( );**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void FreeExtra( );**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void FreeExtra( );**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void FreeExtra( );**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void FreeExtra( );**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void FreeExtra( );**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetData](#getdata).

## <a name="cobarraygetat"></a><a name="getat"></a>CObArray::GetAt

Retorna o elemento matriz no índice especificado.

```
CObject* GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `GetUpperBound`ao valor devolvido por .

### <a name="return-value"></a>Valor retornado

O `CObject` elemento ponteiro atualmente neste índice.

### <a name="remarks"></a>Comentários

> [!NOTE]
> A aprovação de um valor negativo ou `GetUpperBound` um valor maior do que o valor devolvido resultará em uma afirmação falha.

A tabela a seguir mostra outras `CObArray::GetAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**BYTE GetAt (INT_PTR)** `nIndex` **const;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**DWORD GetAt (INT_PTR)** `nIndex` **const;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void\* GetAt (INT_PTR)** `nIndex` **const;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**CString GetAt (INT_PTR)** `nIndex` **const;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**UINT GetAt (INT_PTR)** `nIndex` **const;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**WORD GetAt (INT_PTR)** `nIndex` **const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#79](../../mfc/codesnippet/cpp/cobarray-class_5.cpp)]

## <a name="cobarraygetcount"></a><a name="getcount"></a>CObArray::GetCount

Retorna o número de elementos de matriz.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens na matriz.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos na matriz. Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice.

A tabela a seguir mostra outras `CObArray::GetCount`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**INT_PTR GetCount;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR GetCount;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**INT_PTR GetCount;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**INT_PTR GetCount;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**INT_PTR GetCount;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**INT_PTR GetCount;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#80](../../mfc/codesnippet/cpp/cobarray-class_6.cpp)]

## <a name="cobarraygetdata"></a><a name="getdata"></a>CObArray::GetData

Use esta função de membro para obter acesso direto aos elementos da matriz.

```
const CObject** GetData() const;

CObject** GetData();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para `CObject` a matriz de ponteiros.

### <a name="remarks"></a>Comentários

Se não houver `GetData` elementos disponíveis, retorna um valor nulo.

Embora o acesso direto aos elementos de uma matriz possa `GetData`ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao ligar; quaisquer erros que você comete afetam diretamente os elementos de sua matriz.

A tabela a seguir mostra outras `CObArray::GetData`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**const BYTE\* GetData; BYTE\* GetData;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**const DWORD\* GetData() const;DWORD\* GetData( );**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**const\* \* void GetData() const;void\* \* GetData;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**const CString\* GetData; Cstring\* GetData;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**const UINT\* GetData; UINT\* GetData;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**const\* WORD GetData( ) const; WORD\* GetData;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#81](../../mfc/codesnippet/cpp/cobarray-class_7.cpp)]

## <a name="cobarraygetsize"></a><a name="getsize"></a>CObArray::GetSize

Retorna o tamanho da matriz.

```
INT_PTR GetSize() const;
```

### <a name="remarks"></a>Comentários

Como os índices são baseados em zero, o tamanho é 1 maior que o maior índice.

A tabela a seguir mostra outras `CObArray::GetSize`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**INT_PTR GetSize;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR GetSize;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**INT_PTR GetSize;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**INT_PTR GetSize;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**INT_PTR GetSize;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**INT_PTR GetSize;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#82](../../mfc/codesnippet/cpp/cobarray-class_8.cpp)]

## <a name="cobarraygetupperbound"></a><a name="getupperbound"></a>CObArray::GetUpperBound

Retorna o limite superior atual desta matriz.

```
INT_PTR GetUpperBound() const;
```

### <a name="return-value"></a>Valor retornado

O índice do limite superior (baseado em zero).

### <a name="remarks"></a>Comentários

Como os índices de matriz são baseados em `GetSize`zero, essa função retorna um valor 1 menor que .

A `GetUpperBound( )` condição = -1 indica que a matriz não contém elementos.

A tabela a seguir mostra outras `CObArray::GetUpperBound`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**INT_PTR GetUpperBound;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR GetUpperBound;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**INT_PTR GetUpperBound;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**INT_PTR GetUpperBound;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**INT_PTR GetUpperBound;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**INT_PTR GetUpperBound;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#83](../../mfc/codesnippet/cpp/cobarray-class_9.cpp)]

## <a name="cobarrayinsertat"></a><a name="insertat"></a>CObArray::InsertAt

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

*nIndex*<br/>
Um índice inteiro que pode ser maior do `GetUpperBound`que o valor devolvido por .

*Newelement*<br/>
O `CObject` ponteiro a ser colocado nesta matriz. Um *novoElemento* de valor NULL é permitido.

*Ncount*<br/>
O número de vezes que este elemento deve ser inserido (padrão para 1).

*Nstartindex*<br/>
Um índice inteiro que pode ser maior do `GetUpperBound`que o valor devolvido por .

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

A primeira `InsertAt` versão de insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz. No processo, ele muda (incrementando o índice) o elemento existente neste índice, e muda todos os elementos acima dele.

A segunda versão insere `CObArray` todos os elementos de outra coleção, começando na posição *nStartIndex.*

A `SetAt` função, em contraste, substitui um elemento de matriz especificado e não desloca nenhum elemento.

A tabela a seguir mostra outras `CObArray::InsertAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**inserção vazioAt( INT_PTR** `nIndex` **, BYTE,** `newElement` **int** `nCount` **= 1 );**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **voidInsertAt(INT_PTR,** `nStartIndex` **CByteArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**inserção vazioAt(** `nIndex` **INT_PTR, DWORD,** `newElement` **int** `nCount` = 1 **);**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **vazioInsertAt(INT_PTR,** `nStartIndex` **CDWordArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**voidInsertAt( INT_PTR,** `nIndex` **vazio,** <strong>\*</strong> `newElement` **int** `nCount` = 1 **);**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **voidInsertAt(INT_PTR,** `nStartIndex` **CPtrArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**voidInsertAt(** `nIndex` **INT_PTR, LPCTSTR,** `newElement` **int** `nCount` = 1 **);**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **voidInsertAt(INT_PTR,** `nStartIndex` **CStringArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**voidInsertAt( INT_PTR** `nIndex` **, UINT** `newElement` , **int** `nCount` **= 1 );**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **voidInsertAt(INT_PTR,** `nStartIndex` **CUIntArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**inserção vazioAt( INT_PTR** `nIndex` **, WORD,** `newElement` **int** `nCount` **= 1 );**<br /><br /> **lançamento (CMemoryException);\***<br /><br /> **voidInsertAt (INT_PTR,** `nStartIndex` **CWordArray);** <strong>\*</strong> `pNewArray` **);**<br /><br /> **lançamento (CMemoryException);\***|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#84](../../mfc/codesnippet/cpp/cobarray-class_10.cpp)]

Os resultados deste programa são os seguintes:

```Output
InsertAt example: A CObArray with 3 elements
[0] = a CAge at $45C8 21
[1] = a CAge at $4646 30
[2] = a CAge at $4606 40
```

## <a name="cobarrayisempty"></a><a name="isempty"></a>CObArray::IsEmpty

Determina se a matriz está vazia.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a matriz estiver vazia; caso contrário, 0.

## <a name="cobarrayoperator--"></a><a name="operator_at"></a>CObArray::operador [ ]

Estes operadores subscritos são `SetAt` `GetAt` um substituto conveniente para as funções.

```
CObject*& operator[](int_ptr nindex);
CObject* operator[](int_ptr nindex) const;
```

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **const,** pode ser usado tanto à direita (r-valor) quanto à esquerda (l-valor) de uma declaração de atribuição. O segundo, chamado para **matrizes const,** pode ser usado apenas à direita.

A versão Debug da biblioteca afirma se o subscrito (no lado esquerdo ou direito de uma declaração de atribuição) estiver fora dos limites.

A tabela a seguir mostra outros `CObArray::operator []`operadores que são semelhantes a .

|Classe|Operador|
|-----------|--------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**Operador de& BYTE [](int_ptr;** `nindex` ** \)**<br /><br /> **Operador BYTE [](int_ptr** `nindex` ** \) const;**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**Operador de& DWORD [](int_ptr;** `nindex` ** \)**<br /><br /> **Operador dword [](int_ptr** `nindex` ** \) const;**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**operador\*& vazio [](int_ptr;** `nindex` ** \)**<br /><br /> **operador\* vazio [](int_ptr** `nindex` ** \) const;**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**Operador de& CString [](int_ptr;** `nindex` ** \)**<br /><br /> **Operador de CString [](int_ptr** `nindex` ** \) const;**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**Operador de& uint [](int_ptr;** `nindex` ** \)**<br /><br /> **Operador UINT [](int_ptr** `nindex` ** \) const;**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**Operador de& word [](int_ptr;** `nindex` ** \)**<br /><br /> **Operador de WORD [](int_ptr** `nindex` ** \) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#88](../../mfc/codesnippet/cpp/cobarray-class_11.cpp)]

## <a name="cobarrayremoveall"></a><a name="removeall"></a>CObArray::RemoveAll

Remove todos os ponteiros desta matriz, mas `CObject` não exclui os objetos.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Se a matriz já estiver vazia, a função ainda funciona.

A `RemoveAll` função libera toda a memória usada para armazenamento de ponteiros.

A tabela a seguir mostra outras `CObArray::RemoveAll`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void RemoveAll();**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void RemoveAll();**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void RemoveAll();**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void RemoveAll();**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void RemoveAll();**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void RemoveAll();**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#85](../../mfc/codesnippet/cpp/cobarray-class_12.cpp)]

## <a name="cobarrayremoveat"></a><a name="removeat"></a>CObArray::RemoveAt

Remove um ou mais elementos a partir de um índice especificado em uma matriz.

```cpp
void RemoveAt(
    INT_PTR nIndex,
    INT_PTR nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `GetUpperBound`ao valor devolvido por .

*Ncount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

No processo, ele desloca todos os elementos acima dos elementos removidos. Ele decreta o limite superior da matriz, mas não libera a memória.

Se você tentar remover mais elementos do que estão contidos na matriz acima do ponto de remoção, então a versão Debug da biblioteca afirma.

A `RemoveAt` função remove `CObject` o ponteiro da matriz, mas não exclui o objeto em si.

A tabela a seguir mostra outras `CObArray::RemoveAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** `nCount` = 1 **);**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** `nCount` = 1 **);**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** `nCount` = 1 **);**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** `nCount` = 1 **);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** `nCount` = 1 **);**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void RemoveAt( INT_PTR,** `nIndex` **INT_PTR** *nCount* = 1 **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#112](../../mfc/codesnippet/cpp/cobarray-class_13.cpp)]

Os resultados deste programa são os seguintes:

```Output
RemoveAt example: A CObArray with 1 elements
[0] = a CAge at $4606 40
```

## <a name="cobarraysetat"></a><a name="setat"></a>CObArray::SetAt

Define o elemento matriz no índice especificado.

```cpp
void SetAt(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `GetUpperBound`ao valor devolvido por .

*Newelement*<br/>
O ponteiro do objeto a ser inserido nesta matriz. Um valor NULA é permitido.

### <a name="remarks"></a>Comentários

`SetAt`não fará com que a matriz cresça. Use `SetAtGrow` se quiser que a matriz cresça automaticamente.

Você deve garantir que o valor do índice represente uma posição válida na matriz. Se estiver fora dos limites, então a versão Debug da biblioteca afirma.

A tabela a seguir mostra outras `CObArray::SetAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void SetAt (INT_PTR,** `nIndex` **BYTE);** `newElement` **);**|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void SetAt (INT_PTR,** `nIndex` **DWORD);** `newElement` **);**|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void SetAt(INT_PTR,** `nIndex` <strong>\*</strong> `newElement` **vazio);** **);**|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void SetAt (INT_PTR,** `nIndex` **LPCTSTR);** `newElement` **);**|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void Setat( INT_PTR** `nIndex` **, UINT);** `newElement` **);**|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void SetAt (INT_PTR** `nIndex` **, WORD);** `newElement` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#86](../../mfc/codesnippet/cpp/cobarray-class_14.cpp)]

Os resultados deste programa são os seguintes:

```Output
SetAt example: A CObArray with 2 elements
[0] = a CAge at $47E0 30
[1] = a CAge at $47A0 40
```

## <a name="cobarraysetatgrow"></a><a name="setatgrow"></a>CObArray::SetAtGrow

Define o elemento matriz no índice especificado.

```cpp
void SetAtGrow(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta matriz. Um valor NULA é permitido.

### <a name="remarks"></a>Comentários

A matriz cresce automaticamente se necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).

A tabela a seguir mostra outras `CObArray::SetAtGrow`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void SetAtGrow (INT_PTR,** `nIndex` **BYTE);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void SetAtGrow (INT_PTR,** `nIndex` **DWORD);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void SetAtGrow (INT_PTR,** `nIndex` <strong>\*</strong> `newElement` **vazio);** **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void SetAtGrow (INT_PTR,** `nIndex` **LPCTSTR);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void Setatgrow (INT_PTR** `nIndex` **, UINT);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void SetAtGrow (INT_PTR** `nIndex` **, WORD);** `newElement` **);**<br /><br /> **lançamento (CMemoryException);\***|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#87](../../mfc/codesnippet/cpp/cobarray-class_15.cpp)]

Os resultados deste programa são os seguintes:

```Output
SetAtGrow example: A CObArray with 4 elements
[0] = a CAge at $47C0 21
[1] = a CAge at $4800 40
[2] = NULL
[3] = a CAge at $4840 65
```

## <a name="cobarraysetsize"></a><a name="setsize"></a>CObArray::SetSize

Estabelece o tamanho de uma matriz vazia ou existente; aloca a memória, se necessário.

```cpp
void SetSize(
    INT_PTR nNewSize,
    INT_PTR nGrowBy = -1);
```

### <a name="parameters"></a>Parâmetros

*nNewSize*<br/>
O novo tamanho da matriz (número de elementos). Deve ser maior ou igual a 0.

*nGrowBy*<br/>
O número mínimo de slots de elemento para alocar se for necessário um aumento de tamanho.

### <a name="remarks"></a>Comentários

Se o novo tamanho for menor do que o tamanho antigo, então a matriz é truncada e toda a memória não utilizada é liberada. Para obter eficiência, ligue `SetSize` para definir o tamanho da matriz antes de usá-la. Isso evita a necessidade de realocar e copiar a matriz cada vez que um item é adicionado.

O parâmetro *nGrowBy* afeta a alocação de memória interna enquanto a matriz está crescendo. Seu uso nunca afeta o tamanho `GetSize` `GetUpperBound`da matriz como relatado por e .

Se o tamanho da matriz tiver crescido, todos os ponteiros **CObject** <strong>\*</strong> recém-alocados serão definidos como NULL.

A tabela a seguir mostra outras `CObArray::SetSize`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cbytearray](../../mfc/reference/cbytearray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|
|[Cdwordarray](../../mfc/reference/cdwordarray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|
|[Cptrarray](../../mfc/reference/cptrarray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|
|[Cstringarray](../../mfc/reference/cstringarray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|
|[Cuintarray](../../mfc/reference/cuintarray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|
|[Cwordarray](../../mfc/reference/cwordarray-class.md)|**void SetSize (INT_PTR,** `nNewSize` **int** `nGrowBy` **= -1 );**<br /><br /> **lançamento (CMemoryException);\***|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetData](#getdata).

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStringArray](../../mfc/reference/cstringarray-class.md)<br/>
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)<br/>
[Classe CByteArray](../../mfc/reference/cbytearray-class.md)<br/>
[Classe CWordArray](../../mfc/reference/cwordarray-class.md)<br/>
[Classe CDWordArray](../../mfc/reference/cdwordarray-class.md)
