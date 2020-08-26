---
title: Classe CAtlArray
ms.date: 11/04/2016
f1_keywords:
- CAtlArray
- ATLCOLL/ATL::CAtlArray
- ATLCOLL/ATL::Add
- ATLCOLL/ATL::Append
- ATLCOLL/ATL::AssertValid
- ATLCOLL/ATL::Copy
- ATLCOLL/ATL::FreeExtra
- ATLCOLL/ATL::GetAt
- ATLCOLL/ATL::GetCount
- ATLCOLL/ATL::GetData
- ATLCOLL/ATL::InsertArrayAt
- ATLCOLL/ATL::InsertAt
- ATLCOLL/ATL::IsEmpty
- ATLCOLL/ATL::RemoveAll
- ATLCOLL/ATL::RemoveAt
- ATLCOLL/ATL::SetAt
- ATLCOLL/ATL::SetAtGrow
- ATLCOLL/ATL::SetCount
- ATLCOLL/ATL::INARGTYPE
- ATLCOLL/ATL::OUTARGTYPE
helpviewer_keywords:
- CAtlArray class
ms.assetid: 0b503aa8-2357-40af-a326-6654bf1da098
ms.openlocfilehash: c4a4cd509a5d3078c6587ba7b29179a68912a258
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833836"
---
# <a name="catlarray-class"></a>Classe CAtlArray

Essa classe implementa um objeto de matriz.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename E, class ETraits = CElementTraits<E>>
class CAtlArray
```

### <a name="parameters"></a>parâmetros

*Oriental*<br/>
O tipo de dados a serem armazenados na matriz.

*ETraits*<br/>
O código usado para copiar ou mover elementos.

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Função|Descrição|
|-|-|
|[Adicionar](#add)|Chame esse método para adicionar um elemento ao objeto de matriz.|
|[Append](#append)|Chame esse método para adicionar o conteúdo de uma matriz ao final de outra.|
|[AssertValid](#assertvalid)|Chame esse método para confirmar que o objeto de matriz é válido.|
|[CAtlArray](#catlarray)|O construtor.|
|[~ CAtlArray](#dtor)|O destruidor.|
|[Cópia](#copy)|Chame esse método para copiar os elementos de uma matriz para outra.|
|[FreeExtra](#freeextra)|Chame esse método para remover quaisquer elementos vazios da matriz.|
|[GetAt](#getat)|Chame esse método para recuperar um único elemento do objeto de matriz.|
|[GetCount](#getcount)|Chame esse método para retornar o número de elementos armazenados na matriz.|
|[GetData](#getdata)|Chame esse método para retornar um ponteiro para o primeiro elemento na matriz.|
|[InsertArrayAt](#insertarrayat)|Chame esse método para inserir uma matriz em outra.|
|[InsertAt](#insertat)|Chame esse método para inserir um novo elemento (ou várias cópias de um elemento) no objeto de matriz.|
|[IsEmpty](#isempty)|Chame esse método para testar se a matriz está vazia.|
|[RemoveAll](#removeall)|Chame esse método para remover todos os elementos do objeto de matriz.|
|[RemoveAt](#removeat)|Chame esse método para remover um ou mais elementos da matriz.|
|[SetAt](#setat)|Chame esse método para definir o valor de um elemento no objeto de matriz.|
|[SetAtGrow](#setatgrow)|Chame esse método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.|
|[Total](#setcount)|Chame esse método para definir o tamanho do objeto da matriz.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[ &#91;&#93;do operador ](#operator_at)|Chame esse operador para retornar uma referência a um elemento na matriz.|

### <a name="typedefs"></a>Typedefs

|Typedef|Descrição|
|-|-|
|[INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos à matriz.|
|[OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos da matriz.|

## <a name="remarks"></a>Comentários

`CAtlArray` fornece métodos para criar e gerenciar uma matriz de elementos de um tipo definido pelo usuário. Embora seja semelhante às matrizes padrão C, o `CAtlArray` objeto pode reduzir e aumentar dinamicamente conforme necessário. O índice de matriz sempre começa na posição 0, e o limite superior pode ser corrigido ou ter permissão para expandir à medida que novos elementos são adicionados.

Para matrizes com um pequeno número de elementos, a classe ATL [CSimpleArray](../../atl/reference/csimplearray-class.md) pode ser usada.

`CAtlArray` está fortemente relacionado à classe do MFC `CArray` e funcionará em um projeto do MFC, embora sem suporte de serialização.

Para obter mais informações, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="catlarrayadd"></a><a name="add"></a> CAtlArray:: Adicionar

Chame esse método para adicionar um elemento ao objeto de matriz.

```cpp
size_t Add(INARGTYPE element);
size_t Add();
```

### <a name="parameters"></a>parâmetros

*elementos*<br/>
O elemento a ser adicionado à matriz.

### <a name="return-value"></a>Valor Retornado

Retorna o índice do elemento adicionado.

### <a name="remarks"></a>Comentários

O novo elemento é adicionado ao final da matriz. Se nenhum elemento for fornecido, um elemento vazio será adicionado; ou seja, o tamanho da matriz é aumentado como se um elemento real fosse adicionado. Se a operação falhar, [AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow) será chamado com o argumento E_OUTOFMEMORY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#1](../../atl/codesnippet/cpp/catlarray-class_1.cpp)]

## <a name="catlarrayappend"></a><a name="append"></a> CAtlArray:: Append

Chame esse método para adicionar o conteúdo de uma matriz ao final de outra.

```cpp
size_t Append(const CAtlArray<E, ETraits>& aSrc);
```

### <a name="parameters"></a>parâmetros

*aSrc*<br/>
A matriz a ser acrescentada.

### <a name="return-value"></a>Valor Retornado

Retorna o índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

Os elementos na matriz fornecida são adicionados ao final da matriz existente. Se necessário, a memória será alocada para acomodar os novos elementos.

As matrizes devem ser do mesmo tipo e não é possível acrescentar uma matriz a ela mesma.

Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` argumento não for uma matriz válida ou se *ASRC* se referir ao mesmo objeto. Em builds de versão, argumentos inválidos podem levar a um comportamento imprevisível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#2](../../atl/codesnippet/cpp/catlarray-class_2.cpp)]

## <a name="catlarrayassertvalid"></a><a name="assertvalid"></a> CAtlArray::AssertValid

Chame esse método para confirmar que o objeto de matriz é válido.

```cpp
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Se o objeto de matriz não for válido, ATLASSERT gerará uma asserção. Esse método estará disponível somente se _DEBUG for definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#3](../../atl/codesnippet/cpp/catlarray-class_3.cpp)]

## <a name="catlarraycatlarray"></a><a name="catlarray"></a> CAtlArray::CAtlArray

O construtor.

```cpp
CAtlArray() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o objeto de matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#4](../../atl/codesnippet/cpp/catlarray-class_4.cpp)]

## <a name="catlarraycatlarray"></a><a name="dtor"></a> CAtlArray:: ~ CAtlArray

O destruidor.

```cpp
~CAtlArray() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos usados pelo objeto de matriz.

## <a name="catlarraycopy"></a><a name="copy"></a> CAtlArray:: copiar

Chame esse método para copiar os elementos de uma matriz para outra.

```cpp
void Copy(const CAtlArray<E, ETraits>& aSrc);
```

### <a name="parameters"></a>parâmetros

*aSrc*<br/>
A origem dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Chame esse método para substituir os elementos de uma matriz pelos elementos de outra matriz. Se necessário, a memória será alocada para acomodar os novos elementos. Não é possível copiar elementos de uma matriz para si mesmo.

Se o conteúdo existente da matriz for ser retido, use [CAtlArray:: Append](#append) em vez disso.

Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto existente não for válido ou se *ASRC* se referir ao mesmo objeto. Em builds de versão, argumentos inválidos podem levar a um comportamento imprevisível.

> [!NOTE]
> `CAtlArray::Copy` não oferece suporte a matrizes que consistem em elementos criados com a classe [CAutoPtr](../../atl/reference/cautoptr-class.md) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#5](../../atl/codesnippet/cpp/catlarray-class_5.cpp)]

## <a name="catlarrayfreeextra"></a><a name="freeextra"></a> CAtlArray::FreeExtra

Chame esse método para remover quaisquer elementos vazios da matriz.

```cpp
void FreeExtra() throw();
```

### <a name="remarks"></a>Comentários

Todos os elementos vazios são removidos, mas o tamanho e o limite superior da matriz permanecem inalterados.

Em compilações de depuração, um ATLASSERT será gerado se o objeto CAtlArray não for válido ou se a matriz exceder seu tamanho máximo.

## <a name="catlarraygetat"></a><a name="getat"></a> CAtlArray::GetAt

Chame esse método para recuperar um único elemento do objeto de matriz.

```cpp
const E& GetAt(size_t iElement) const throw();
E& GetAt(size_t iElement) throw();
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O valor de índice do elemento de matriz a ser retornado.

### <a name="return-value"></a>Valor Retornado

Retorna uma referência para o elemento de matriz necessário.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um ATLASSERT será gerado se *ielemento* exceder o número de elementos na matriz. Em compilações de versão, um argumento inválido pode levar a um comportamento imprevisível.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#6](../../atl/codesnippet/cpp/catlarray-class_6.cpp)]

## <a name="catlarraygetcount"></a><a name="getcount"></a> CAtlArray:: GetCount

Chame esse método para retornar o número de elementos armazenados na matriz.

```cpp
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de elementos armazenados na matriz.

### <a name="remarks"></a>Comentários

Como o primeiro elemento na matriz está na posição 0, o valor retornado por `GetCount` é sempre 1 maior que o maior índice.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlArray:: GetAt](#getat).

## <a name="catlarraygetdata"></a><a name="getdata"></a> CAtlArray:: GetData

Chame esse método para retornar um ponteiro para o primeiro elemento na matriz.

```cpp
E* GetData() throw();
const E* GetData() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna um ponteiro para o local da memória que armazena o primeiro elemento na matriz. Se nenhum elemento estiver disponível, NULL será retornado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#7](../../atl/codesnippet/cpp/catlarray-class_7.cpp)]

## <a name="catlarrayinargtype"></a><a name="inargtype"></a> CAtlArray::INARGTYPE

O tipo de dados a ser usado para adicionar elementos à matriz.

```cpp
typedef ETraits::INARGTYPE INARGTYPE;
```

## <a name="catlarrayinsertarrayat"></a><a name="insertarrayat"></a> CAtlArray::InsertArrayAt

Chame esse método para inserir uma matriz em outra.

```cpp
void InsertArrayAt(size_t iStart, const CAtlArray<E, ETraits>* paNew);
```

### <a name="parameters"></a>parâmetros

*isniciar*<br/>
O índice no qual a matriz deve ser inserida.

*paNew*<br/>
A matriz a ser inserida.

### <a name="remarks"></a>Comentários

Os elementos da matriz *paNew* são copiados para o objeto de matriz, começando no elemento *isniciar*. Os elementos de matriz existentes são movidos para evitar que sejam substituídos.

Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não for válido ou se o ponteiro *PANEW* for nulo ou inválido.

> [!NOTE]
> `CAtlArray::InsertArrayAt` não oferece suporte a matrizes que consistem em elementos criados com a classe [CAutoPtr](../../atl/reference/cautoptr-class.md) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#8](../../atl/codesnippet/cpp/catlarray-class_8.cpp)]

## <a name="catlarrayinsertat"></a><a name="insertat"></a> CAtlArray::InsertAt

Chame esse método para inserir um novo elemento (ou várias cópias de um elemento) no objeto de matriz.

```cpp
void InsertAt(size_t iElement, INARGTYPE element, size_t nCount = 1);
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O índice em que o elemento ou os elementos devem ser inseridos.

*elementos*<br/>
O valor do elemento ou dos elementos a serem inseridos.

*nCount*<br/>
O número de elementos a serem adicionados.

### <a name="remarks"></a>Comentários

Insere um ou mais elementos na matriz, começando no índice *ielemento*. Os elementos existentes são movidos para evitar que sejam substituídos.

Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto for inválido, o número de elementos a serem adicionados é zero ou o número combinado de elementos é muito grande para a matriz conter. Em compilações de varejo, passar parâmetros inválidos pode causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#9](../../atl/codesnippet/cpp/catlarray-class_9.cpp)]

## <a name="catlarrayisempty"></a><a name="isempty"></a> CAtlArray:: IsEmpty

Chame esse método para testar se a matriz está vazia.

```cpp
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna true se a matriz estiver vazia; caso contrário, false.

### <a name="remarks"></a>Comentários

A matriz será considerada vazia se não contiver nenhum elemento. Portanto, mesmo que a matriz contenha elementos vazios, ela não estará vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#10](../../atl/codesnippet/cpp/catlarray-class_10.cpp)]

## <a name="catlarrayoperator-"></a><a name="operator_at"></a> CAtlArray:: operator []

Chame esse operador para retornar uma referência a um elemento na matriz.

```cpp
E& operator[](size_t ielement) throw();
const E& operator[](size_t ielement) const throw();
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O valor de índice do elemento de matriz a ser retornado.

### <a name="return-value"></a>Valor Retornado

Retorna uma referência para o elemento de matriz necessário.

### <a name="remarks"></a>Comentários

Executa uma função semelhante a [CAtlArray:: GetAt](#getat). Ao contrário da classe MFC [CArray](../../mfc/reference/carray-class.md), esse operador não pode ser usado como um substituto para [CAtlArray:: SetAt](#setat).

Em compilações de depuração, um ATLASSERT será gerado se *ielemento* exceder o número total de elementos na matriz. Em compilações de varejo, um parâmetro inválido pode causar resultados imprevisíveis.

## <a name="catlarrayoutargtype"></a><a name="outargtype"></a> CAtlArray::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos da matriz.

```cpp
typedef ETraits::OUTARGTYPE OUTARGTYPE;
```

## <a name="catlarrayremoveall"></a><a name="removeall"></a> CAtlArray:: RemoveAll

Chame esse método para remover todos os elementos do objeto de matriz.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Remove todos os elementos do objeto de matriz.

Esse método chama [CAtlArray:: SetCount](#setcount) para redimensionar a matriz e, posteriormente, libera qualquer memória alocada.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlArray:: IsEmpty](#isempty).

## <a name="catlarrayremoveat"></a><a name="removeat"></a> CAtlArray:: RemoveAt

Chame esse método para remover um ou mais elementos da matriz.

```cpp
void RemoveAt(size_t iElement, size_t nCount = 1);
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O índice do primeiro elemento a ser removido.

*nCount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

Remove um ou mais elementos da matriz. Todos os elementos restantes são deslocados para baixo. O limite superior é diminuído, mas a memória não é liberada até que uma chamada para [CAtlArray:: FreeExtra](#freeextra) seja feita.

Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não for válido ou se o total combinado de *ielemento* e *nCount* exceder o número total de elementos na matriz. Em compilações de varejo, parâmetros inválidos podem causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#11](../../atl/codesnippet/cpp/catlarray-class_11.cpp)]

## <a name="catlarraysetat"></a><a name="setat"></a> CAtlArray::SetAt

Chame esse método para definir o valor de um elemento no objeto de matriz.

```cpp
void SetAt(size_t iElement, INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O índice que aponta para o elemento de matriz a ser definido.

*elementos*<br/>
O novo valor do elemento especificado.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um ATLASSERT será gerado se *ielemento* exceder o número de elementos na matriz. Em compilações de varejo, um parâmetro inválido pode resultar em resultados imprevisíveis.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlArray:: GetAt](#getat).

## <a name="catlarraysetcount"></a><a name="setcount"></a> CAtlArray:: SetCount

Chame esse método para definir o tamanho do objeto da matriz.

```cpp
bool SetCount(size_t nNewSize, int nGrowBy = - 1);
```

### <a name="parameters"></a>parâmetros

*nNewSize*<br/>
O tamanho necessário da matriz.

*nGrowBy*<br/>
Um valor usado para determinar o tamanho do buffer que será grande. Um valor de-1 faz com que um valor calculado internamente seja usado.

### <a name="return-value"></a>Valor Retornado

Retornará true se a matriz for redimensionada com êxito; caso contrário, false.

### <a name="remarks"></a>Comentários

O tamanho da matriz pode ser aumentado ou diminuído. Se for aumentado, elementos vazios adicionais serão adicionados à matriz. Se for reduzido, os elementos com os maiores índices serão excluídos e a memória será liberada.

Use este método para definir o tamanho da matriz antes de usá-la. Se `SetCount` não for usado, o processo de adição de elementos – e a alocação de memória subsequente executada – reduzirá o desempenho e fragmentará a memória.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlArray:: GetData](#getdata).

## <a name="catlarraysetatgrow"></a><a name="setatgrow"></a> CAtlArray::SetAtGrow

Chame esse método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.

```cpp
void SetAtGrow(size_t iElement, INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O índice que aponta para o elemento de matriz a ser definido.

*elementos*<br/>
O novo valor do elemento especificado.

### <a name="remarks"></a>Comentários

Substitui o valor do elemento apontado pelo índice. Se *ielemento* for maior que o tamanho atual da matriz, a matriz será aumentada automaticamente usando uma chamada para [CAtlArray:: SetCount](#setcount). Em compilações de depuração, um ATLASSERT será gerado se o `CAtlArray` objeto não for válido. Em compilações de varejo, parâmetros inválidos podem causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#12](../../atl/codesnippet/cpp/catlarray-class_12.cpp)]

## <a name="see-also"></a>Confira também

[Exemplo de MMXSwarm](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de DynamicConsumer](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de UpdatePV](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
