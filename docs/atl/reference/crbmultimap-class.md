---
title: Classe CRBMultiMap
ms.date: 11/04/2016
f1_keywords:
- CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap::CRBMultiMap
- ATLCOLL/ATL::CRBMultiMap::FindFirstWithKey
- ATLCOLL/ATL::CRBMultiMap::GetNextValueWithKey
- ATLCOLL/ATL::CRBMultiMap::GetNextWithKey
- ATLCOLL/ATL::CRBMultiMap::Insert
- ATLCOLL/ATL::CRBMultiMap::RemoveKey
helpviewer_keywords:
- CRBMultiMap class
ms.assetid: 94d3ec0c-3e30-4ab7-a101-d8da4fb8add3
ms.openlocfilehash: 1e36bc267b3a539d2d1d4bf370b9cdc33828c760
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331430"
---
# <a name="crbmultimap-class"></a>Classe CRBMultiMap

Esta classe representa uma estrutura de mapeamento que permite que cada chave possa ser associada a mais de um valor, usando uma árvore binária Rubro-Negra.

## <a name="syntax"></a>Sintaxe

```
template<typename K,
         typename V,
         class KTraits = CElementTraits<K>,
         class VTraits = CElementTraits<V>>
class CRBMultiMap : public CRBTree<K, V, KTraits, VTraits>
```

#### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de elemento-chave.

*V*<br/>
O tipo de elemento de valor.

*Ktraits*<br/>
O código usado para copiar ou mover elementos-chave. Consulte [CElementTraits Class](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

*VTraits*<br/>
O código usado para copiar ou mover elementos de valor.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBMultiMap::CRBMultiMap](#crbmultimap)|O construtor.|
|[CRBMultiMap::~CRBMultimap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBMultimap::FindfirstWithKey](#findfirstwithkey)|Chame este método para encontrar a posição do primeiro elemento com uma determinada tecla.|
|[CRBMultimap::getNextValueWithKey](#getnextvaluewithkey)|Chame este método para obter o valor associado a uma determinada tecla e atualize o valor da posição.|
|[CRBMultimap::getnextwithkey](#getnextwithkey)|Chame este método para obter o elemento associado a uma determinada tecla e atualize o valor da posição.|
|[CRBMultiMap::Inserir](#insert)|Chame este método para inserir um par de elementos no mapa.|
|[CRBMultimap::removekey](#removekey)|Chame este método para remover todos os elementos de chave/valor para uma determinada chave.|

## <a name="remarks"></a>Comentários

`CRBMultiMap`fornece suporte para uma matriz de mapeamento de qualquer tipo, gerenciando uma matriz ordenada de elementos e valores-chave. Ao contrário da classe [CRBMap,](../../atl/reference/crbmap-class.md) cada tecla pode ser associada a mais de um valor.

Os elementos (que consistem em uma chave e um valor) são armazenados em uma estrutura de árvore binária, usando o método [CRBMultiMap::Insert.](#insert) Os elementos podem ser removidos usando o método [CRBMultiMap::RemoveKey,](#removekey) que exclui todos os elementos que correspondem à tecla dada.

Atravessar a árvore é possível com métodos como [CRBTree::GetHeadPosition](../../atl/reference/crbtree-class.md#getheadposition), [CRBTree::GetNext](../../atl/reference/crbtree-class.md#getnext)e [CRBTree:::GetNext](../../atl/reference/crbtree-class.md#getnextvalue). Acessar os valores potencialmente múltiplos por chave é possível usando os métodos [CRBMultiMap::FindFirstWithKey](#findfirstwithkey), [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey)e [CRBMultiMap::GetNextWithKey](#getnextwithkey) métodos. Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap) para obter uma ilustração disso na prática.

Os parâmetros *KTraits* e *VTraits* são classes de características que contêm qualquer código suplementar necessário para copiar ou mover elementos.

`CRBMultiMap`é derivado do [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo Rubro-Negro. Uma alternativa `CRBMultiMap` `CRBMap` e é oferecida pela classe [CAtlMap.](../../atl/reference/catlmap-class.md) Quando apenas um pequeno número de elementos precisar ser armazenado, considere usar a classe [CSimpleMap.](../../atl/reference/csimplemap-class.md)

Para uma discussão mais completa das várias classes de coleta e suas características e características de desempenho, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Crbtree](../../atl/reference/crbtree-class.md)

`CRBMultiMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="crbmultimapcrbmultimap"></a><a name="crbmultimap"></a>CRBMultiMap::CRBMultiMap

O construtor.

```
explicit CRBMultiMap(size_t nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O parâmetro *nBlockSize* é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de blocomaiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos. O padrão alocará espaço para 10 elementos de cada vez.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#85](../../atl/codesnippet/cpp/crbmultimap-class_1.cpp)]

## <a name="crbmultimapcrbmultimap"></a><a name="dtor"></a>CRBMultiMap::~CRBMultimap

O destruidor.

```
~CRBMultiMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

## <a name="crbmultimapfindfirstwithkey"></a><a name="findfirstwithkey"></a>CRBMultimap::FindfirstWithKey

Chame este método para encontrar a posição do primeiro elemento com uma determinada tecla.

```
POSITION FindFirstWithKey(KINARGTYPE key) const throw();
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a chave que identifica o elemento a ser encontrado.

### <a name="return-value"></a>Valor retornado

Retorna a POSIÇÃO do primeiro elemento chave/valor se a chave for encontrada, NULL de outra forma.

### <a name="remarks"></a>Comentários

Uma chave `CRBMultiMap` no pode ter um ou mais valores associados. Este método fornecerá o valor de posição do primeiro valor (que pode, de fato, ser o único valor) associado a essa chave específica. O valor de posição retornado pode ser usado com [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey) para obter o valor e atualizar a posição.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

## <a name="crbmultimapgetnextvaluewithkey"></a><a name="getnextvaluewithkey"></a>CRBMultimap::getNextValueWithKey

Chame este método para obter o valor associado a uma determinada chave e atualizar o valor da posição.

```
const V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor da posição, obtido com uma chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey)ou uma chamada anterior para `GetNextValueWithKey`.

*Chave*<br/>
Especifica a chave que identifica o elemento a ser encontrado.

### <a name="return-value"></a>Valor retornado

Retorna o par de elementos associado à tecla dada.

### <a name="remarks"></a>Comentários

O valor da posição é atualizado para apontar para o próximo valor associado à chave. Se não houver mais valores, o valor da posição será definido como NULL.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

## <a name="crbmultimapgetnextwithkey"></a><a name="getnextwithkey"></a>CRBMultimap::getnextwithkey

Chame este método para obter o elemento associado a uma determinada chave e atualizar o valor da posição.

```
const CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor da posição, obtido com uma chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey)ou uma chamada anterior para `GetNextWithKey`.

*Chave*<br/>
Especifica a chave que identifica o elemento a ser encontrado.

### <a name="return-value"></a>Valor retornado

Retorna o próximo elemento [CRBTree::CPair Class](crbtree-class.md#cpair_class) associado à tecla dada.

### <a name="remarks"></a>Comentários

O valor da posição é atualizado para apontar para o próximo valor associado à chave. Se não houver mais valores, o valor da posição será definido como NULL.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

## <a name="crbmultimapinsert"></a><a name="insert"></a>CRBMultiMap::Inserir

Chame este método para inserir um par de elementos no mapa.

```
POSITION Insert(KINARGTYPE key, VINARGTYPE value) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
O valor-chave a `CRBMultiMap` ser adicionado ao objeto.

*value*<br/>
O valor a `CRBMultiMap` ser adicionado ao objeto, associado à *chave*.

### <a name="return-value"></a>Valor retornado

Retorna a posição do par de `CRBMultiMap` elementos de chave/valor no objeto.

### <a name="remarks"></a>Comentários

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

## <a name="crbmultimapremovekey"></a><a name="removekey"></a>CRBMultimap::removekey

Chame este método para remover todos os elementos de chave/valor para uma determinada chave.

```
size_t RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a chave que identifica os elementos a serem excluídos.

### <a name="return-value"></a>Valor retornado

Retorna o número de valores associados à tecla dada.

### <a name="remarks"></a>Comentários

`RemoveKey`exclui todos os elementos de chave/valor que possuem uma chave que corresponde à *tecla*.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

## <a name="see-also"></a>Confira também

[Classe CRBTree](../../atl/reference/crbtree-class.md)<br/>
[Classe CAtlMap](../../atl/reference/catlmap-class.md)<br/>
[Classe CRBMap](../../atl/reference/crbmap-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
