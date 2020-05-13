---
title: Classe CRBMap
ms.date: 11/04/2016
f1_keywords:
- CRBMap
- ATLCOLL/ATL::CRBMap
- ATLCOLL/ATL::CRBMap::CRBMap
- ATLCOLL/ATL::CRBMap::Lookup
- ATLCOLL/ATL::CRBMap::RemoveKey
- ATLCOLL/ATL::CRBMap::SetAt
helpviewer_keywords:
- CRBMap class
ms.assetid: 658e94dc-e835-4356-aed1-1513e1f66969
ms.openlocfilehash: 9e367ccc875eedf63e4f47018598662af2dfcf7d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331393"
---
# <a name="crbmap-class"></a>Classe CRBMap

Esta classe representa uma estrutura de mapeamento, usando uma árvore binária Rubro-Negra.

## <a name="syntax"></a>Sintaxe

```
template <typename K,
          typename V,
          class KTraits = CElementTraits<K>,
          class VTraits = CElementTraits<V>>
class CRBMap : public CRBTree<K, V, KTraits, VTraits>
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
|[Mapa do CRB::MAPA DO CRB](#crbmap)|O construtor.|
|[Mapa do CRB::~MAPA DO CRB](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBMap:::Lookup](#lookup)|Chame este método para procurar chaves `CRBMap` ou valores no objeto.|
|[CRBMap::RemoveKey](#removekey)|Chame este método para remover `CRBMap` um elemento do objeto, dada a chave.|
|[CRBMap::Setat](#setat)|Chame este método para inserir um par de elementos no mapa.|

## <a name="remarks"></a>Comentários

`CRBMap`fornece suporte para uma matriz de mapeamento de qualquer tipo, gerenciando uma matriz ordenada de elementos-chave e seus valores associados. Cada tecla pode ter apenas um valor associado. Os elementos (que consistem em uma chave e um valor) são armazenados em uma estrutura de árvore binária, usando o método [CRBMap::SetAt.](#setat) Os elementos podem ser removidos usando o método [CRBMap::RemoveKey,](#removekey) que exclui o elemento com o valor-chave dado.

Atravessar a árvore é possível com métodos como [CRBTree::GetHeadPosition](../../atl/reference/crbtree-class.md#getheadposition), [CRBTree::GetNext](../../atl/reference/crbtree-class.md#getnext)e [CRBTree:::GetNext](../../atl/reference/crbtree-class.md#getnextvalue).

Os parâmetros *KTraits* e *VTraits* são classes de características que contêm qualquer código suplementar necessário para copiar ou mover elementos.

`CRBMap`é derivado do [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo Rubro-Negro. [CRBMultiMap](../../atl/reference/crbmultimap-class.md) é uma variação que permite múltiplos valores para cada chave. Ele também é derivado `CRBTree`, e assim compartilha `CRBMap`muitas características com .

Uma alternativa `CRBMap` para `CRBMultiMap` ambos e é oferecida pela classe [CAtlMap.](../../atl/reference/catlmap-class.md) Quando apenas um pequeno número de elementos precisar ser armazenado, considere usar a classe [CSimpleMap.](../../atl/reference/csimplemap-class.md)

Para uma discussão mais completa das várias classes de coleta e suas características e características de desempenho, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Crbtree](../../atl/reference/crbtree-class.md)

`CRBMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="crbmapcrbmap"></a><a name="crbmap"></a>Mapa do CRB::MAPA DO CRB

O construtor.

```
explicit CRBMap(size_t nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O parâmetro *nBlockSize* é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de blocomaiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos. O padrão alocará espaço para 10 elementos de cada vez.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#81](../../atl/codesnippet/cpp/crbmap-class_1.cpp)]

## <a name="crbmapcrbmap"></a><a name="dtor"></a>Mapa do CRB::~MAPA DO CRB

O destruidor.

```
~CRBMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

## <a name="crbmaplookup"></a><a name="lookup"></a>CRBMap:::Lookup

Chame este método para procurar chaves `CRBMap` ou valores no objeto.

```
bool Lookup(KINARGTYPE key, VOUTARGTYPE value) const throw(...);
const CPair* Lookup(KINARGTYPE key) const throw();
CPair* Lookup(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a chave que identifica o elemento a ser examinado.

*value*<br/>
Variável que recebe o valor de análise.

### <a name="return-value"></a>Valor retornado

A primeira forma do método retorna verdadeira se a chave for encontrada, caso contrário, falsa. A segunda e terceira formas retornam um ponteiro para um [CPair](crbtree-class.md#cpair_class).

### <a name="remarks"></a>Comentários

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#82](../../atl/codesnippet/cpp/crbmap-class_2.cpp)]

## <a name="crbmapremovekey"></a><a name="removekey"></a>CRBMap::RemoveKey

Chame este método para remover `CRBMap` um elemento do objeto, dada a chave.

```
bool RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
A tecla correspondente ao par de elementos que deseja remover.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a chave for encontrada e removida, falsa na falha.

### <a name="remarks"></a>Comentários

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#83](../../atl/codesnippet/cpp/crbmap-class_3.cpp)]

## <a name="crbmapsetat"></a><a name="setat"></a>CRBMap::Setat

Chame este método para inserir um par de elementos no mapa.

```
POSITION SetAt(
    KINARGTYPE key,
    VINARGTYPE value) throw(...);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
O valor-chave a `CRBMap` ser adicionado ao objeto.

*value*<br/>
O valor a `CRBMap` ser adicionado ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna a posição do par de `CRBMap` elementos de chave/valor no objeto.

### <a name="remarks"></a>Comentários

`SetAt`substitui um elemento existente se uma chave correspondente for encontrada. Se a chave não for encontrada, um novo par de chaves/valor será criado.

Consulte a documentação da classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os outros métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#84](../../atl/codesnippet/cpp/crbmap-class_4.cpp)]

## <a name="see-also"></a>Confira também

[Classe CRBTree](../../atl/reference/crbtree-class.md)<br/>
[Classe CAtlMap](../../atl/reference/catlmap-class.md)<br/>
[Classe CRBMultiMap](../../atl/reference/crbmultimap-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
