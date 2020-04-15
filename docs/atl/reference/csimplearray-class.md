---
title: Classe CSimpleArray
ms.date: 11/04/2016
f1_keywords:
- CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray::CSimpleArray
- ATLSIMPCOLL/ATL::CSimpleArray::Add
- ATLSIMPCOLL/ATL::CSimpleArray::Find
- ATLSIMPCOLL/ATL::CSimpleArray::GetData
- ATLSIMPCOLL/ATL::CSimpleArray::GetSize
- ATLSIMPCOLL/ATL::CSimpleArray::Remove
- ATLSIMPCOLL/ATL::CSimpleArray::RemoveAll
- ATLSIMPCOLL/ATL::CSimpleArray::RemoveAt
- ATLSIMPCOLL/ATL::CSimpleArray::SetAtIndex
helpviewer_keywords:
- CSimpleArray class
ms.assetid: ee0c9f39-b61c-4c18-bc43-4eada21dca3a
ms.openlocfilehash: e45c9b3fd778aacd3a3e2d5d3696661afa0c6fb0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330899"
---
# <a name="csimplearray-class"></a>Classe CSimpleArray

Esta classe fornece métodos para gerenciar uma matriz simples.

## <a name="syntax"></a>Sintaxe

```
template <class T, class TEqual = CSimpleArrayEqualHelper<T>>
class CSimpleArray
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados a armazenar na matriz.

*TEqual*<br/>
Um objeto de característica, definindo o teste de igualdade para elementos do tipo *T*.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArray::CSimpleArray](#csimplearray)|O construtor para a matriz simples.|
|[CSimpleArray::~CSimpleArray](#dtor)|O destruidor para a matriz simples.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArray::Adicionar](#add)|Adiciona um novo elemento à matriz.|
|[CSimpleArray::Encontrar](#find)|Encontra um elemento na matriz.|
|[CSimpleArray::GetData](#getdata)|Retorna um ponteiro para os dados armazenados na matriz.|
|[CSimpleArray::GetSize](#getsize)|Retorna o número de elementos armazenados na matriz.|
|[CSimpleArray::Remove](#remove)|Remove um determinado elemento da matriz.|
|[CSimpleArray::RemoveAll](#removeall)|Remove todos os elementos da matriz.|
|[Csimplearray::removeat](#removeat)|Remove o elemento especificado da matriz.|
|[CSimpleArray::setatindex](#setatindex)|Define o elemento especificado na matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleArray::operador\[\]](#operator_at)|Recupera um elemento da matriz.|
|[CSimpleArray::operador =](#operator_eq)|Operador de atribuição.|

## <a name="remarks"></a>Comentários

`CSimpleArray`fornece métodos para criar e gerenciar uma `T`matriz simples, de qualquer tipo.

O parâmetro `TEqual` fornece um meio de definir uma função `T`de igualdade para dois elementos do tipo . Ao criar uma classe semelhante ao [CSimpleArrayEqualHelper,](../../atl/reference/csimplearrayequalhelper-class.md)é possível alterar o comportamento do teste de igualdade para qualquer matriz. Por exemplo, ao lidar com uma matriz de ponteiros, pode ser útil definir a igualdade dependendo dos valores que os ponteiros referenciam. A implementação padrão utiliza **o operador=()**.

Ambos `CSimpleArray` e [CSimpleMap](../../atl/reference/csimplemap-class.md) são projetados para um pequeno número de elementos. [CAtlArray](../../atl/reference/catlarray-class.md) e [CAtlMap](../../atl/reference/catlmap-class.md) devem ser usados quando a matriz contiver um grande número de elementos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#86](../../atl/codesnippet/cpp/csimplearray-class_1.cpp)]

## <a name="csimplearrayadd"></a><a name="add"></a>CSimpleArray::Adicionar

Adiciona um novo elemento à matriz.

```
BOOL Add(const T& t);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O elemento a ser adicionado à matriz.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o elemento for adicionado com sucesso à matriz, FALSE de outra forma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#87](../../atl/codesnippet/cpp/csimplearray-class_2.cpp)]

## <a name="csimplearraycsimplearray"></a><a name="csimplearray"></a>CSimpleArray::CSimpleArray

O construtor para o objeto de matriz.

```
CSimpleArray(const CSimpleArray<T, TEqual>& src);
CSimpleArray();
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
Um objeto `CSimpleArray` existente.

### <a name="remarks"></a>Comentários

Inicializa os membros de dados, `CSimpleArray` criando um novo objeto `CSimpleArray` vazio ou uma cópia de um objeto existente.

## <a name="csimplearraycsimplearray"></a><a name="dtor"></a>CSimpleArray::~CSimpleArray

O destruidor.

```
~CSimpleArray();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="csimplearrayfind"></a><a name="find"></a>CSimpleArray::Encontrar

Encontra um elemento na matriz.

```
int Find(const T& t) const;
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O elemento para a busca.

### <a name="return-value"></a>Valor retornado

Retorna o índice do elemento encontrado, ou -1 se o elemento não for encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#88](../../atl/codesnippet/cpp/csimplearray-class_3.cpp)]

## <a name="csimplearraygetdata"></a><a name="getdata"></a>CSimpleArray::GetData

Retorna um ponteiro para os dados armazenados na matriz.

```
T* GetData() const;
```

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para os dados na matriz.

## <a name="csimplearraygetsize"></a><a name="getsize"></a>CSimpleArray::GetSize

Retorna o número de elementos armazenados na matriz.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos armazenados na matriz.

## <a name="csimplearrayoperator-"></a><a name="operator_at"></a>CSimpleArray::operador\[\]

Recupera um elemento da matriz.

```
T& operator[](int nindex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice de elementos.

### <a name="return-value"></a>Valor retornado

Retorna o elemento da matriz referenciada por *nIndex*.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#89](../../atl/codesnippet/cpp/csimplearray-class_4.cpp)]

## <a name="csimplearrayoperator-"></a><a name="operator_eq"></a>CSimpleArray::operador =

Operador de atribuição.

```
CSimpleArray<T, TEqual>
& operator=(
    const CSimpleArray<T, TEqual>& src);
```

### <a name="parameters"></a>Parâmetros

*src*<br/>
A matriz a ser copiada.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `CSimpleArray` para o objeto atualizado.

### <a name="remarks"></a>Comentários

Copia todos os `CSimpleArray` elementos do objeto referenciado pelo *src* no objeto de matriz atual, substituindo todos os dados existentes.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#90](../../atl/codesnippet/cpp/csimplearray-class_5.cpp)]

## <a name="csimplearrayremove"></a><a name="remove"></a>CSimpleArray::Remove

Remove um determinado elemento da matriz.

```
BOOL Remove(const T& t);
```

### <a name="parameters"></a>Parâmetros

*t*<br/>
O elemento a ser removido da matriz.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o elemento for encontrado e removido, FALSO de outra forma.

### <a name="remarks"></a>Comentários

Quando um elemento é removido, os elementos restantes na matriz são renumerados para preencher o espaço vazio.

## <a name="csimplearrayremoveall"></a><a name="removeall"></a>CSimpleArray::RemoveAll

Remove todos os elementos da matriz.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Remove todos os elementos atualmente armazenados na matriz.

## <a name="csimplearrayremoveat"></a><a name="removeat"></a>Csimplearray::removeat

Remove o elemento especificado da matriz.

```
BOOL RemoveAtint nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Índice apontando para o elemento para remover.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o elemento foi removido, FALSO se o índice for inválido.

### <a name="remarks"></a>Comentários

Quando um elemento é removido, os elementos restantes na matriz são renumerados para preencher o espaço vazio.

## <a name="csimplearraysetatindex"></a><a name="setatindex"></a>CSimpleArray::setatindex

Defina o elemento especificado na matriz.

```
BOOL SetAtIndex(
    int nIndex,
    const T& t);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do elemento a mudar.

*t*<br/>
O valor a ser atribuído ao elemento especificado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido, FALSO se o índice não for válido.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
