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
ms.openlocfilehash: 85168af654d3d63e06559486b464938b7fd90ad3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321567"
---
# <a name="catlarray-class"></a>Classe CAtlArray

Esta classe implementa um objeto de matriz.

## <a name="syntax"></a>Sintaxe

```
template<typename E, class ETraits = CElementTraits<E>>
class CAtlArray
```

#### <a name="parameters"></a>Parâmetros

*E*<br/>
O tipo de dados a serem armazenados na matriz.

*Estreito*<br/>
O código usado para copiar ou mover elementos.

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Adicionar](#add)|Chame este método para adicionar um elemento ao objeto da matriz.|
|[Acrescentar](#append)|Chame este método para adicionar o conteúdo de uma matriz ao final de outra.|
|[Assertvalid](#assertvalid)|Chame este método para confirmar se o objeto de matriz é válido.|
|[Catlarray](#catlarray)|O construtor.|
|[~CAtlArray](#dtor)|O destruidor.|
|[Cópia](#copy)|Chame este método para copiar os elementos de uma matriz para outra.|
|[Freeextra](#freeextra)|Chame este método para remover quaisquer elementos vazios da matriz.|
|[Getat](#getat)|Chame este método para recuperar um único elemento do objeto de matriz.|
|[GetCount](#getcount)|Chame este método para retornar o número de elementos armazenados na matriz.|
|[GetData](#getdata)|Chame este método para retornar um ponteiro para o primeiro elemento na matriz.|
|[InsertArrayAt](#insertarrayat)|Chame este método para inserir uma matriz em outra.|
|[Insertat](#insertat)|Chame este método para inserir um novo elemento (ou várias cópias de um elemento) no objeto da matriz.|
|[IsEmpty](#isempty)|Chame este método para testar se a matriz está vazia.|
|[Removeall](#removeall)|Chame este método para remover todos os elementos do objeto da matriz.|
|[RemoveAt](#removeat)|Chame este método para remover um ou mais elementos da matriz.|
|[Setat](#setat)|Chame este método para definir o valor de um elemento no objeto da matriz.|
|[Setatgrow](#setatgrow)|Chame este método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.|
|[Setcount](#setcount)|Chame este método para definir o tamanho do objeto da matriz.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador &#91;&#93;](#operator_at)|Ligue para este operador para retornar uma referência a um elemento na matriz.|

### <a name="typedefs"></a>Typedefs

|||
|-|-|
|[INARGTYPE](#inargtype)|O tipo de dados a ser usado para adicionar elementos à matriz.|
|[OUTARGTYPE](#outargtype)|O tipo de dados a ser usado para recuperar elementos da matriz.|

## <a name="remarks"></a>Comentários

`CAtlArray`fornece métodos para criar e gerenciar uma matriz de elementos de um tipo definido pelo usuário. Embora semelhante às matrizes `CAtlArray` C padrão, o objeto pode encolher dinamicamente e crescer conforme necessário. O índice de matriz sempre começa na posição 0, e o limite superior pode ser corrigido, ou permitido expandir à medida que novos elementos são adicionados.

Para matrizes com um pequeno número de elementos, o [CSimpleArray](../../atl/reference/csimplearray-class.md) classe ATL pode ser usado.

`CAtlArray`está intimamente relacionado com a `CArray` classe do MFC e trabalhará em um projeto de MFC, embora sem suporte de serialização.

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="catlarrayadd"></a><a name="add"></a>CAtlArray::Adicionar

Chame este método para adicionar um elemento ao objeto da matriz.

```
size_t Add(INARGTYPE element);
size_t Add();
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O elemento a ser adicionado à matriz.

### <a name="return-value"></a>Valor retornado

Retorna o índice do elemento adicionado.

### <a name="remarks"></a>Comentários

O novo elemento é adicionado ao final da matriz. Se nenhum elemento for fornecido, um elemento vazio será adicionado; ou seja, a matriz é aumentada em tamanho como se um elemento real tenha sido adicionado. Se a operação falhar, [o AtlThrow](debugging-and-error-reporting-global-functions.md#atlthrow) é chamado com o argumento E_OUTOFMEMORY.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#1](../../atl/codesnippet/cpp/catlarray-class_1.cpp)]

## <a name="catlarrayappend"></a><a name="append"></a>CAtlArray::Apêndice

Chame este método para adicionar o conteúdo de uma matriz ao final de outra.

```
size_t Append(const CAtlArray<E, ETraits>& aSrc);
```

### <a name="parameters"></a>Parâmetros

*aSrc*<br/>
A matriz para anexar.

### <a name="return-value"></a>Valor retornado

Retorna o índice do primeiro elemento anexado.

### <a name="remarks"></a>Comentários

Os elementos na matriz fornecida são adicionados ao final da matriz existente. Se necessário, a memória será alocada para acomodar os novos elementos.

As matrizes devem ser do mesmo tipo, e não é possível anexar uma matriz a si mesma.

Nas compilações de depuração, um ATLASSERT será levantado se o `CAtlArray` argumento não for uma matriz válida ou se *aSrc* se referir ao mesmo objeto. Nas compilações de lançamento, argumentos inválidos podem levar a comportamentos imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#2](../../atl/codesnippet/cpp/catlarray-class_2.cpp)]

## <a name="catlarrayassertvalid"></a><a name="assertvalid"></a>CAtlArray::AssertValid

Chame este método para confirmar se o objeto de matriz é válido.

```
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Se o objeto de matriz não for válido, o ATLASSERT lançará uma afirmação. Este método só está disponível se _DEBUG for definido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#3](../../atl/codesnippet/cpp/catlarray-class_3.cpp)]

## <a name="catlarraycatlarray"></a><a name="catlarray"></a>CAtlArray::CAtlArray

O construtor.

```
CAtlArray() throw();
```

### <a name="remarks"></a>Comentários

Inicializa o objeto da matriz.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#4](../../atl/codesnippet/cpp/catlarray-class_4.cpp)]

## <a name="catlarraycatlarray"></a><a name="dtor"></a>CAtlArray::~CAtlArray

O destruidor.

```
~CAtlArray() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos usados pelo objeto de matriz.

## <a name="catlarraycopy"></a><a name="copy"></a>CAtlArray::Cópia

Chame este método para copiar os elementos de uma matriz para outra.

```
void Copy(const CAtlArray<E, ETraits>& aSrc);
```

### <a name="parameters"></a>Parâmetros

*aSrc*<br/>
A fonte dos elementos para copiar para uma matriz.

### <a name="remarks"></a>Comentários

Chame este método para substituir elementos de uma matriz com os elementos de outra matriz. Se necessário, a memória será alocada para acomodar os novos elementos. Não é possível copiar elementos de uma matriz para si mesmo.

Se o conteúdo existente da matriz for retido, use [CAtlArray::Apêndice](#append) em vez disso.

Nas compilações de depuração, um ATLASSERT `CAtlArray` será levantado se o objeto existente não for válido ou se *o aSrc* se referir ao mesmo objeto. Nas compilações de lançamento, argumentos inválidos podem levar a comportamentos imprevisíveis.

> [!NOTE]
> `CAtlArray::Copy`não suporta matrizes constituídas por elementos criados com a classe [CAutoPtr.](../../atl/reference/cautoptr-class.md)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#5](../../atl/codesnippet/cpp/catlarray-class_5.cpp)]

## <a name="catlarrayfreeextra"></a><a name="freeextra"></a>CAtlArray::FreeExtra

Chame este método para remover quaisquer elementos vazios da matriz.

```
void FreeExtra() throw();
```

### <a name="remarks"></a>Comentários

Quaisquer elementos vazios são removidos, mas o tamanho e o limite superior da matriz permanecem inalterados.

Nas compilações de depuração, um ATLASSERT será levantado se o objeto CAtlArray não for válido ou se a matriz exceder seu tamanho máximo.

## <a name="catlarraygetat"></a><a name="getat"></a>CAtlArray::GetAt

Chame este método para recuperar um único elemento do objeto de matriz.

```
const E& GetAt(size_t iElement) const throw();
E& GetAt(size_t iElement) throw();
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O valor do índice do elemento matriz para retornar.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao elemento de matriz necessário.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um ATLASSERT será levantado se *o iElement* exceder o número de elementos na matriz. Nas compilações de lançamento, um argumento inválido pode levar a comportamentos imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#6](../../atl/codesnippet/cpp/catlarray-class_6.cpp)]

## <a name="catlarraygetcount"></a><a name="getcount"></a>CAtlArray::GetCount

Chame este método para retornar o número de elementos armazenados na matriz.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos armazenados na matriz.

### <a name="remarks"></a>Comentários

Como o primeiro elemento da matriz está na posição `GetCount` 0, o valor devolvido é sempre 1 maior que o maior índice.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlArray::GetAt](#getat).

## <a name="catlarraygetdata"></a><a name="getdata"></a>CAtlArray::GetData

Chame este método para retornar um ponteiro para o primeiro elemento na matriz.

```
E* GetData() throw();
const E* GetData() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o local de memória armazenando o primeiro elemento na matriz. Se não houver elementos disponíveis, NULL é devolvido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#7](../../atl/codesnippet/cpp/catlarray-class_7.cpp)]

## <a name="catlarrayinargtype"></a><a name="inargtype"></a>CAtlArray::INARGTYPE

O tipo de dados a ser usado para adicionar elementos à matriz.

```
typedef ETraits::INARGTYPE INARGTYPE;
```

## <a name="catlarrayinsertarrayat"></a><a name="insertarrayat"></a>CAtlArray::InsertArrayAt

Chame este método para inserir uma matriz em outra.

```
void InsertArrayAt(size_t iStart, const CAtlArray<E, ETraits>* paNew);
```

### <a name="parameters"></a>Parâmetros

*Istart*<br/>
O índice no qual a matriz deve ser inserida.

*paNovo*<br/>
A matriz a ser inserida.

### <a name="remarks"></a>Comentários

Os elementos da matriz *paNovo* são copiados para o objeto da matriz, começando pelo elemento *iStart*. Os elementos de matriz existentes são movidos para evitar serem substituídos.

Nas compilações de depuração, um ATLASSERT será levantado se o `CAtlArray` objeto não for válido ou se o ponteiro *paNovo* for NULO ou inválido.

> [!NOTE]
> `CAtlArray::InsertArrayAt`não suporta matrizes constituídas por elementos criados com a classe [CAutoPtr.](../../atl/reference/cautoptr-class.md)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#8](../../atl/codesnippet/cpp/catlarray-class_8.cpp)]

## <a name="catlarrayinsertat"></a><a name="insertat"></a>CAtlArray::InsertAt

Chame este método para inserir um novo elemento (ou várias cópias de um elemento) no objeto da matriz.

```
void InsertAt(size_t iElement, INARGTYPE element, size_t nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O índice onde o elemento ou elementos devem ser inseridos.

*Elemento*<br/>
O valor do elemento ou elementos a serem inseridos.

*Ncount*<br/>
O número de elementos a serem adicionados.

### <a name="remarks"></a>Comentários

Insere um ou mais elementos na matriz, começando pelo index *iElement*. Os elementos existentes são movidos para evitar serem substituídos.

Nas compilações de depuração, um ATLASSERT será levantado se o `CAtlArray` objeto for inválido, o número de elementos a serem adicionados é zero ou o número combinado de elementos é muito grande para a matriz conter. Nas compilações de varejo, passar parâmetros inválidos pode causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#9](../../atl/codesnippet/cpp/catlarray-class_9.cpp)]

## <a name="catlarrayisempty"></a><a name="isempty"></a>CAtlArray::IsEmpty

Chame este método para testar se a matriz está vazia.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a matriz estiver vazia, falsa de outra forma.

### <a name="remarks"></a>Comentários

Diz-se que a matriz está vazia se não contiver elementos. Portanto, mesmo que a matriz contenha elementos vazios, não está vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#10](../../atl/codesnippet/cpp/catlarray-class_10.cpp)]

## <a name="catlarrayoperator-"></a><a name="operator_at"></a>CAtlArray::operador []

Ligue para este operador para retornar uma referência a um elemento na matriz.

```
E& operator[](size_t ielement) throw();
const E& operator[](size_t ielement) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O valor do índice do elemento matriz para retornar.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao elemento de matriz necessário.

### <a name="remarks"></a>Comentários

Executa uma função semelhante ao [CAtlArray::GetAt](#getat). Ao contrário do [CArray](../../mfc/reference/carray-class.md)classe MFC, este operador não pode ser usado como um substituto para [CAtlArray::SetAt](#setat).

Nas compilações de depuração, um ATLASSERT será levantado se *o iElement* exceder o número total de elementos na matriz. Nas construções de varejo, um parâmetro inválido pode causar resultados imprevisíveis.

## <a name="catlarrayoutargtype"></a><a name="outargtype"></a>CAtlArray::OUTARGTYPE

O tipo de dados a ser usado para recuperar elementos da matriz.

```
typedef ETraits::OUTARGTYPE OUTARGTYPE;
```

## <a name="catlarrayremoveall"></a><a name="removeall"></a>CAtlArray::RemoveAll

Chame este método para remover todos os elementos do objeto da matriz.

```
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Remove todos os elementos do objeto da matriz.

Este método chama [CAtlArray::SetCount](#setcount) para redimensionar a matriz e, posteriormente, libera qualquer memória alocada.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlArray::IsEmpty](#isempty).

## <a name="catlarrayremoveat"></a><a name="removeat"></a>CAtlArray::RemoveAt

Chame este método para remover um ou mais elementos da matriz.

```
void RemoveAt(size_t iElement, size_t nCount = 1);
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O índice do primeiro elemento a remover.

*Ncount*<br/>
O número de elementos a serem removidos.

### <a name="remarks"></a>Comentários

Remove um ou mais elementos da matriz. Todos os elementos restantes são deslocados para baixo. O limite superior é decretado, mas a memória não é liberada até que uma chamada para [CAtlArray::FreeExtra](#freeextra) seja feita.

Nas compilações de depuração, um ATLASSERT será levantado se o `CAtlArray` objeto não for válido ou se o total combinado de *iElement* e *nCount* exceder o número total de elementos na matriz. Nas compilações de varejo, parâmetros inválidos podem causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#11](../../atl/codesnippet/cpp/catlarray-class_11.cpp)]

## <a name="catlarraysetat"></a><a name="setat"></a>CAtlArray::SetAt

Chame este método para definir o valor de um elemento no objeto da matriz.

```
void SetAt(size_t iElement, INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O índice apontando para o elemento matriz a definir.

*Elemento*<br/>
O novo valor do elemento especificado.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um ATLASSERT será levantado se *o iElement* exceder o número de elementos na matriz. Nas construções de varejo, um parâmetro inválido pode resultar em resultados imprevisíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlArray::GetAt](#getat).

## <a name="catlarraysetcount"></a><a name="setcount"></a>CAtlArray::SetCount

Chame este método para definir o tamanho do objeto da matriz.

```
bool SetCount(size_t nNewSize, int nGrowBy = - 1);
```

### <a name="parameters"></a>Parâmetros

*nNewSize*<br/>
O tamanho necessário da matriz.

*nGrowBy*<br/>
Um valor usado para determinar o tamanho para fazer o buffer. Um valor de -1 faz com que um valor calculado internamente seja usado.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a matriz for redimensionada com sucesso, falsa de outra forma.

### <a name="remarks"></a>Comentários

A matriz pode ser aumentada ou diminuída de tamanho. Se aumentado, elementos vazios extras são adicionados à matriz. Se diminuído, os elementos com os maiores índices serão excluídos e a memória liberada.

Use este método para definir o tamanho da matriz antes de usá-lo. Se `SetCount` não for usado, o processo de adição de elementos — e a alocação de memória subsequente realizada — reduzirá o desempenho e a memória fragmentada.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlArray::GetData](#getdata).

## <a name="catlarraysetatgrow"></a><a name="setatgrow"></a>CAtlArray::SetAtGrow

Chame este método para definir o valor de um elemento no objeto de matriz, expandindo a matriz conforme necessário.

```
void SetAtGrow(size_t iElement, INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O índice apontando para o elemento matriz a definir.

*Elemento*<br/>
O novo valor do elemento especificado.

### <a name="remarks"></a>Comentários

Substitui o valor do elemento apontado pelo índice. Se *o iElement* for maior do que o tamanho atual da matriz, a matriz será aumentada automaticamente usando uma chamada para [CAtlArray::SetCount](#setcount). Nas compilações de depuração, um ATLASSERT será levantado se o `CAtlArray` objeto não for válido. Nas compilações de varejo, parâmetros inválidos podem causar resultados imprevisíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#12](../../atl/codesnippet/cpp/catlarray-class_12.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MMXSwarm](../../overview/visual-cpp-samples.md)<br/>
[Amostra dinâmica do consumidor](../../overview/visual-cpp-samples.md)<br/>
[AtualizaçãofotoPV](../../overview/visual-cpp-samples.md)<br/>
[Amostra de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
