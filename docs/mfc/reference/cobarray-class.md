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
ms.openlocfilehash: 78d736b53a2febe4f4a026e3aaf9db14dd7f9c0b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392486"
---
# <a name="cobarray-class"></a>Classe CObArray

Dá suporte a matrizes de `CObject` ponteiros.

## <a name="syntax"></a>Sintaxe

```
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
|[CObArray::Add](#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CObArray::Append](#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::Copy](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
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
|[CObArray::operator \[ \]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Essas matrizes de objeto são semelhantes às matrizes do C, mas eles podem reduzir dinamicamente e cresça conforme necessário.

Índices de matriz sempre começam na posição 0. Você pode decidir se o limite superior de corrigir ou permitir que a matriz expandir quando você adiciona elementos após o limite atual. Memória é alocada contiguamente ao limite superior, mesmo que alguns elementos são nulos.

No Win32, o tamanho de um `CObArray` objeto é limitado somente a memória disponível.

Assim como acontece com uma matriz de C, o tempo de acesso para um `CObArray` elemento indexado é constante e é independente do tamanho da matriz.

`CObArray` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e despejo de seus elementos. Se uma matriz de `CObject` ponteiros é armazenada em um arquivo, com o operador de inserção sobrecarregado ou com o `Serialize` função de membro, cada `CObject` elemento é, por sua vez, serializado junto com seu índice de matriz.

Se você precisar de um despejo do indivíduo `CObject` elementos em uma matriz, você deve definir a profundidade do `CDumpContext` objeto a ser 1 ou maior.

Quando um `CObArray` objeto é excluído, ou quando seus elementos são removidos, somente o `CObject` ponteiros são removidos, não os objetos que fazem referência.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Derivação de classe de matriz é semelhante à derivação de lista. Para obter detalhes sobre a derivação de uma classe de lista de finalidade especial, consulte o artigo [coleções](../../mfc/collections.md).

> [!NOTE]
>  Você deve usar a macro IMPLEMENT_SERIAL na implementação de sua classe derivada se você deseja serializar a matriz.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CObArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** & amp;lt;1}afxcoll.h

##  <a name="add"></a>  CObArray::Add

Adiciona um novo elemento ao final de uma matriz, aumentando a matriz de 1.

```
INT_PTR Add(CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*newElement*<br/>
O `CObject` ponteiro a ser adicionado a essa matriz.

### <a name="return-value"></a>Valor de retorno

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Se [SetSize](#setsize) foi usado com um *nGrowBy* valor maior que 1, em seguida, memória extra pode ser alocada. No entanto, o limite superior terão um aumento de apenas 1.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Add`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**INT_PTR Add( BYTE** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR Add( DWORD** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**INT_PTR Add( void** <strong>\*</strong> `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**INT_PTR Add( LPCTSTR** `newElement` **); throw( CMemoryException\* );**<br /><br /> **INT_PTR Add(const CString&** `newElement` **);**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**INT_PTR Add( UINT** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**INT_PTR Add( WORD** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|

### <a name="example"></a>Exemplo

  Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#75](../../mfc/codesnippet/cpp/cobarray-class_1.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
Add example: A CObArray with 2 elements
[0] = a CAge at $442A 21
[1] = a CAge at $4468 40
```

##  <a name="append"></a>  CObArray::Append

Chame essa função de membro para adicionar o conteúdo de outra matriz até o final da matriz especificada.

```
INT_PTR Append(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Origem dos elementos a ser acrescentado à matriz.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

As matrizes devem ser do mesmo tipo.

Se necessário, `Append` pode alocar memória extra para acomodar os elementos acrescentados à matriz.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Append`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**Acrescentar INT_PTR (const CByteArray &** *src* **);**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**Acrescentar INT_PTR (const CDWordArray &** *src* **);**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**Acrescentar INT_PTR (const CPtrArray &** *src* **);**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**Acrescentar INT_PTR (const CStringArray &** *src* **);**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**Acrescentar INT_PTR (const CUIntArray &** *src* **);**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**Acrescentar INT_PTR (const CWordArray &** *src* **);**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#76](../../mfc/codesnippet/cpp/cobarray-class_2.cpp)]

##  <a name="copy"></a>  CObArray::Copy

Chame essa função de membro para substituir os elementos da matriz especificada com os elementos de outra matriz do mesmo tipo.

```
void Copy(const CObArray& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Origem dos elementos a serem copiados para a matriz.

### <a name="remarks"></a>Comentários

`Copy` não libera memória; No entanto, se necessário, `Copy` pode alocar memória extra para acomodar os elementos copiados para a matriz.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::Copy`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void Copy( const CByteArray&** *src* **);**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void Copy( const CDWordArray&** *src* **);**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void Copy( const CPtrArray&** *src* **);**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void Copy( const CStringArray&** *src* **);**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void Copy( const CUIntArray&** *src* **);**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void Copy( const CWordArray&** *src* **);**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#77](../../mfc/codesnippet/cpp/cobarray-class_3.cpp)]

##  <a name="cobarray"></a>  CObArray::CObArray

Constrói um vazio `CObject` matriz de ponteiro.

```
CObArray();
```

### <a name="remarks"></a>Comentários

A matriz aumenta um elemento por vez.

A tabela a seguir mostra outros construtores que são semelhantes aos `CObArray::CObArray`.

|Classe|Construtor|
|-----------|-----------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**CByteArray( );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**CDWordArray( );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**CPtrArray( );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**CStringArray( );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**CUIntArray( );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**CWordArray( );**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#78](../../mfc/codesnippet/cpp/cobarray-class_4.cpp)]

##  <a name="elementat"></a>  CObArray::ElementAt

Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.

```
CObject*& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.

### <a name="return-value"></a>Valor de retorno

Uma referência a um `CObject` ponteiro.

### <a name="remarks"></a>Comentários

Ele é usado para implementar o operador de atribuição do lado esquerdo para matrizes. Observe que se trata de uma função avançada que deve ser usada somente para implementar os operadores especiais de matriz.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::ElementAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**BYTE& ElementAt( INT_PTR** `nIndex` **);**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**DWORD& ElementAt( INT_PTR** `nIndex` **);**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\*& ElementAt( INT_PTR** `nIndex` **);**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**CString& ElementAt( INT_PTR** `nIndex` **);**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**UINT& ElementAt( INT_PTR** `nIndex` **);**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**WORD& ElementAt( INT_PTR** `nIndex` **);**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetSize](#getsize).

##  <a name="freeextra"></a>  CObArray::FreeExtra

Libera a memória extra que foi alocada enquanto a matriz foi aumentada.

```
void FreeExtra();
```

### <a name="remarks"></a>Comentários

Essa função não tem nenhum efeito sobre o tamanho ou o limite superior da matriz.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::FreeExtra`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void (de) FreeExtra;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void (de) FreeExtra;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void (de) FreeExtra;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void (de) FreeExtra;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void (de) FreeExtra;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void (de) FreeExtra;**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetData](#getdata).

##  <a name="getat"></a>  CObArray::GetAt

Retorna o elemento de matriz no índice especificado.

```
CObject* GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.

### <a name="return-value"></a>Valor de retorno

O `CObject` elemento ponteiro no momento, esse índice.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Passando um valor negativo ou um valor maior que o valor retornado por `GetUpperBound` resultará em uma declaração com falha.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**BYTE GetAt( INT_PTR** `nIndex` **) const;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**DWORD GetAt( INT_PTR** `nIndex` **) const;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\* GetAt( INT_PTR** `nIndex` **) const;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**CString GetAt( INT_PTR** `nIndex` **) const;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**UINT GetAt( INT_PTR** `nIndex` **) const;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**WORD GetAt( INT_PTR** `nIndex` **) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#79](../../mfc/codesnippet/cpp/cobarray-class_5.cpp)]

##  <a name="getcount"></a>  CObArray::GetCount

Retorna o número de elementos da matriz.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens na matriz.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos na matriz. Porque os índices são baseados em zero, o tamanho é maior que o maior índice de 1.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetCount`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**() GetCount INT_PTR const;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**() GetCount INT_PTR const;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**() GetCount INT_PTR const;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**() GetCount INT_PTR const;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**() GetCount INT_PTR const;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**() GetCount INT_PTR const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#80](../../mfc/codesnippet/cpp/cobarray-class_6.cpp)]

##  <a name="getdata"></a>  CObArray::GetData

Use essa função de membro para obter acesso direto aos elementos na matriz.

```
const CObject** GetData() const;

CObject** GetData();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para a matriz de `CObject` ponteiros.

### <a name="remarks"></a>Comentários

Se nenhum elemento estiverem disponível, `GetData` retorna um valor nulo.

Embora o acesso direto aos elementos de uma matriz pode ajudá-lo a trabalhar mais rapidamente, tenha cuidado ao chamar `GetData`; os erros que você fizer diretamente afetam os elementos da matriz.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetData`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**const BYTE\* GetData( ) const;BYTE\* GetData( );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**const DWORD\* GetData( ) const;DWORD\* GetData( );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**Const void\* \* (GetData) const; void\* \* GetData (de);**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**const CString\* GetData( ) const;CString\* GetData( );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**const UINT\* GetData( ) const;UINT\* GetData( );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**const WORD\* GetData( ) const;WORD\* GetData( );**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#81](../../mfc/codesnippet/cpp/cobarray-class_7.cpp)]

##  <a name="getsize"></a>  CObArray::GetSize

Retorna o tamanho da matriz.

```
INT_PTR GetSize() const;
```

### <a name="remarks"></a>Comentários

Uma vez que os índices são baseados em zero, o tamanho é maior que o maior índice de 1.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**INT_PTR GetSize( ) const;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR GetSize( ) const;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**INT_PTR GetSize( ) const;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**INT_PTR GetSize( ) const;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**INT_PTR GetSize( ) const;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**INT_PTR GetSize( ) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#82](../../mfc/codesnippet/cpp/cobarray-class_8.cpp)]

##  <a name="getupperbound"></a>  CObArray::GetUpperBound

Retorna o limite superior atual dessa matriz.

```
INT_PTR GetUpperBound() const;
```

### <a name="return-value"></a>Valor de retorno

O índice do limite superior (baseado em zero).

### <a name="remarks"></a>Comentários

Como os índices de matriz são com base em zero, essa função retorna um valor de 1 menor que `GetSize`.

A condição `GetUpperBound( )` = -1 indica que a matriz não contém elementos.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::GetUpperBound`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**INT_PTR GetUpperBound( ) const;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**INT_PTR GetUpperBound( ) const;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**INT_PTR GetUpperBound( ) const;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**INT_PTR GetUpperBound( ) const;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**INT_PTR GetUpperBound( ) const;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**INT_PTR GetUpperBound( ) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#83](../../mfc/codesnippet/cpp/cobarray-class_9.cpp)]

##  <a name="insertat"></a>  CObArray::InsertAt

Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.

```
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
Um índice de inteiro que pode ser maior que o valor retornado por `GetUpperBound`.

*newElement*<br/>
O `CObject` ponteiro a ser colocado nesta matriz. Um *newElement* de valor NULL é permitido.

*nCount*<br/>
O número de vezes que esse elemento deve ser inserido (o padrão é 1).

*nStartIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por `GetUpperBound`.

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a essa matriz.

### <a name="remarks"></a>Comentários

A primeira versão do `InsertAt` insere um elemento (ou várias cópias de um elemento) em um índice especificado em uma matriz. No processo, ele desloca-se (incrementando o índice) ao elemento existente neste índice e ele desloca-se todos os elementos acima dele.

A segunda versão insere todos os elementos de outro `CObArray` coleção, começando na *nStartIndex* posição.

O `SetAt` função, por outro lado, substitui um elemento da matriz especificada e não mudar todos os elementos.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::InsertAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, BYTE** `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CByteArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, DWORD** `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CDWordArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, void** <strong>\*</strong> `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CPtrArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, LPCTSTR** `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CStringArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, UINT** `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CUIntArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void InsertAt( INT_PTR** `nIndex` **, WORD** `newElement` **, int** `nCount` **= 1 );**<br /><br /> **throw( CMemoryException\* );**<br /><br /> **void InsertAt( INT_PTR** `nStartIndex` **, CWordArray** <strong>\*</strong> `pNewArray` **);**<br /><br /> **throw( CMemoryException\* );**|

### <a name="example"></a>Exemplo

  Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#84](../../mfc/codesnippet/cpp/cobarray-class_10.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
InsertAt example: A CObArray with 3 elements
[0] = a CAge at $45C8 21
[1] = a CAge at $4646 30
[2] = a CAge at $4606 40
```

##  <a name="isempty"></a>  CObArray::IsEmpty

Determina se a matriz está vazia.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a matriz está vazia. Caso contrário, 0.

##  <a name="operator_at"></a>  CObArray::operator [ ]

Esses operadores subscript são um substituto conveniente para o `SetAt` e `GetAt` funções.

```
CObject*& operator[](int_ptr nindex);
CObject* operator[](int_ptr nindex) const;
```

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não sejam **const**, pode ser usada em (r-Value) direita ou esquerda (l-value) de uma instrução de atribuição. A segunda chamada para **const** matrizes, podem ser usados somente no lado direito.

A versão de depuração da biblioteca declara se o subscrito (tanto no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.

A tabela a seguir mostra outros operadores que são semelhantes aos `CObArray::operator []`.

|Classe|Operador|
|-----------|--------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**[] Operador & bytes (int_ptr** `nindex`  **\);**<br /><br /> **BYTE [] de operador (int_ptr** `nindex`  **\) const;**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**DWORD& operator [](int_ptr** `nindex` **\);**<br /><br /> **DWORD operator [] (int_ptr** `nindex`  **\) const;**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void\*& operator [](int_ptr** `nindex` **\);**<br /><br /> **void\* operator [] (int_ptr** `nindex`  **\) const;**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**[] Operador & CString (int_ptr** `nindex`  **\);**<br /><br /> **CString operator [] (int_ptr** `nindex`  **\) const;**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**UINT& operator [](int_ptr** `nindex` **\);**<br /><br /> **UINT operator [] (int_ptr** `nindex`  **\) const;**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**[] Operador & palavra (int_ptr** `nindex`  **\);**<br /><br /> **WORD operator [] (int_ptr** `nindex`  **\) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#88](../../mfc/codesnippet/cpp/cobarray-class_11.cpp)]

##  <a name="removeall"></a>  CObArray::RemoveAll

Remove todos os ponteiros dessa matriz, mas não exclui o `CObject` objetos.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Se a matriz estiver vazia, a função ainda funciona.

O `RemoveAll` função libera toda a memória usada para o armazenamento de ponteiro.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::RemoveAll`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void RemoveAll( );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void RemoveAll( );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void RemoveAll( );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void RemoveAll( );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void RemoveAll( );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void RemoveAll( );**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#85](../../mfc/codesnippet/cpp/cobarray-class_12.cpp)]

##  <a name="removeat"></a>  CObArray::RemoveAt

Remove um ou mais elementos, começando em um índice especificado em uma matriz.

```
void RemoveAt(
    INT_PTR nIndex,
    INT_PTR nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.

*nCount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

O processo, ele muda para baixo de todos os elementos acima do elemento removido (s). Ele diminui a superior associado da matriz, mas não libera memória.

Se você tentar remover mais elementos que estão contidos na matriz acima do ponto de remoção, a versão de depuração da biblioteca de declarações.

O `RemoveAt` função remove o `CObject` ponteiro de matriz, mas ele não exclui o objeto em si.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::RemoveAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1 );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1 );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1 );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1 );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** `nCount` **= 1 );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void RemoveAt( INT_PTR** `nIndex` **, INT_PTR** *nCount* **= 1 );**|

### <a name="example"></a>Exemplo

  Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#112](../../mfc/codesnippet/cpp/cobarray-class_13.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
RemoveAt example: A CObArray with 1 elements
[0] = a CAge at $4606 40
```

##  <a name="setat"></a>  CObArray::SetAt

Define o elemento de matriz no índice especificado.

```
void SetAt(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `GetUpperBound`.

*newElement*<br/>
O ponteiro de objeto a ser inserido nesta matriz. Um valor NULL é permitido.

### <a name="remarks"></a>Comentários

`SetAt` não fará com que a matriz a crescer. Use `SetAtGrow` se você quiser que a matriz para crescer automaticamente.

Você deve garantir que seu valor de índice representa uma posição válida na matriz. Se ele está fora dos limites, a versão de depuração da biblioteca de declarações.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetAt( INT_PTR** `nIndex` **, BYTE** `newElement` **);**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetAt( INT_PTR** `nIndex` **, DWORD** `newElement` **);**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetAt( INT_PTR** `nIndex` **, void** <strong>\*</strong> `newElement` **);**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetAt( INT_PTR** `nIndex` **, LPCTSTR** `newElement` **);**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetAt( INT_PTR** `nIndex` **, UINT** `newElement` **);**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetAt( INT_PTR** `nIndex` **, WORD** `newElement` **);**|

### <a name="example"></a>Exemplo

  Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#86](../../mfc/codesnippet/cpp/cobarray-class_14.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
SetAt example: A CObArray with 2 elements
[0] = a CAge at $47E0 30
[1] = a CAge at $47A0 40
```

##  <a name="setatgrow"></a>  CObArray::SetAtGrow

Define o elemento de matriz no índice especificado.

```
void SetAtGrow(
    INT_PTR nIndex,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a essa matriz. Um valor NULL é permitido.

### <a name="remarks"></a>Comentários

A matriz aumenta automaticamente quando necessário (ou seja, o limite superior é ajustado para acomodar o novo elemento).

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetAtGrow`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, BYTE** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, DWORD** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, void** <strong>\*</strong> `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, LPCTSTR** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, UINT** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetAtGrow( INT_PTR** `nIndex` **, WORD** `newElement` **);**<br /><br /> **throw( CMemoryException\* );**|

### <a name="example"></a>Exemplo

  Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#87](../../mfc/codesnippet/cpp/cobarray-class_15.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
SetAtGrow example: A CObArray with 4 elements
[0] = a CAge at $47C0 21
[1] = a CAge at $4800 40
[2] = NULL
[3] = a CAge at $4840 65
```

##  <a name="setsize"></a>  CObArray::SetSize

Estabelece o tamanho de uma matriz vazia ou existente; aloca memória, se necessário.

```
void SetSize(
    INT_PTR nNewSize,
    INT_PTR nGrowBy = -1);
```

### <a name="parameters"></a>Parâmetros

*nNewSize*<br/>
O tamanho da matriz novo (número de elementos). Deve ser maior ou igual a 0.

*nGrowBy*<br/>
O número mínimo de slots de elemento para alocar se um aumento de tamanho é necessário.

### <a name="remarks"></a>Comentários

Se o novo tamanho for menor que o tamanho anterior, em seguida, a matriz será truncada e não utilizada toda a memória é liberada. Para obter eficiência, chame `SetSize` para definir o tamanho da matriz antes de usá-lo. Isso evita a necessidade de realocar e copiar a matriz cada vez que um item é adicionado.

O *nGrowBy* parâmetro afeta a alocação de memória interna enquanto a matriz está crescendo. Seu uso nunca afeta o tamanho da matriz, conforme relatado pelo `GetSize` e `GetUpperBound`.

Se o tamanho da matriz cresceu, todos os novos alocada **CObject** <strong>\*</strong> ponteiros são definidos como NULL.

A tabela a seguir mostra outro membro funções que são semelhantes às `CObArray::SetSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CByteArray](../../mfc/reference/cbytearray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|
|[CDWordArray](../../mfc/reference/cdwordarray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|
|[CPtrArray](../../mfc/reference/cptrarray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|
|[CStringArray](../../mfc/reference/cstringarray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|
|[CUIntArray](../../mfc/reference/cuintarray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|
|[CWordArray](../../mfc/reference/cwordarray-class.md)|**void SetSize( INT_PTR** `nNewSize` **, int** `nGrowBy` **= -1 );**<br /><br /> **throw( CMemoryException\* );**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [CObArray::GetData](#getdata).

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStringArray](../../mfc/reference/cstringarray-class.md)<br/>
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)<br/>
[Classe CByteArray](../../mfc/reference/cbytearray-class.md)<br/>
[Classe CWordArray](../../mfc/reference/cwordarray-class.md)<br/>
[Classe CDWordArray](../../mfc/reference/cdwordarray-class.md)
