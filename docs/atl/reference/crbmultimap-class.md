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
ms.openlocfilehash: 03a9639e8b0b3d11a414e5db0ce874d7ca8f2d45
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62278131"
---
# <a name="crbmultimap-class"></a>Classe CRBMultiMap

Essa classe representa uma estrutura de mapeamento que permite que cada chave pode ser associado a mais de um valor, usando uma árvore binária de vermelho / preto.

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

*KTraits*<br/>
O código usado para copiar ou mover elementos-chave. Ver [classe CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

*VTraits*<br/>
O código usado para copiar ou mover elementos de valor.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBMultiMap::CRBMultiMap](#crbmultimap)|O construtor.|
|[CRBMultiMap::~CRBMultiMap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBMultiMap::FindFirstWithKey](#findfirstwithkey)|Chame esse método para localizar a posição do primeiro elemento com uma determinada chave.|
|[CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey)|Chame esse método para obter o valor associado a uma determinada chave e atualize o valor da posição.|
|[CRBMultiMap::GetNextWithKey](#getnextwithkey)|Chame esse método para obter o elemento associado a uma determinada chave e atualize o valor da posição.|
|[CRBMultiMap::Insert](#insert)|Chame esse método para inserir um par de elementos no mapa.|
|[CRBMultiMap::RemoveKey](#removekey)|Chame esse método para remover todos os elementos de chave/valor para uma determinada chave.|

## <a name="remarks"></a>Comentários

`CRBMultiMap` fornece suporte para uma matriz de mapeamento de qualquer tipo, gerenciando uma matriz ordenada de elementos-chave e valores. Ao contrário do [CRBMap](../../atl/reference/crbmap-class.md) classe, cada chave pode ser associado a mais de um valor.

Elementos (consistindo em uma chave e um valor) são armazenados em uma árvore binária estrutura, usando o [CRBMultiMap::Insert](#insert) método. Elementos podem ser removidos usando o [CRBMultiMap::RemoveKey](#removekey) método, que exclui todos os elementos que correspondem a chave especificada.

Percorrer a árvore se tornou possível com métodos como [CRBTree::GetHeadPosition](../../atl/reference/crbtree-class.md#getheadposition), [CRBTree::GetNext](../../atl/reference/crbtree-class.md#getnext), e [CRBTree::GetNextValue](../../atl/reference/crbtree-class.md#getnextvalue). Acessando o potencialmente vários valores por chave é possível usar o [CRBMultiMap::FindFirstWithKey](#findfirstwithkey), [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey), e [CRBMultiMap::GetNextWithKey ](#getnextwithkey) métodos. Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap) para obter uma ilustração isso na prática.

O *KTraits* e *VTraits* parâmetros são classes de características que contém qualquer código complementar necessário para copiar ou mover elementos.

`CRBMultiMap` é derivado de [CRBTree](../../atl/reference/crbtree-class.md), que implementa uma árvore binária usando o algoritmo de vermelho / preto. Uma alternativa à `CRBMultiMap` e `CRBMap` é oferecida pela [CAtlMap](../../atl/reference/catlmap-class.md) classe. Quando apenas um pequeno número de elementos precisa ser armazenados, considere o uso de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe em vez disso.

Para obter uma discussão mais completa de várias classes de coleção e seus recursos e características de desempenho, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CRBTree](../../atl/reference/crbtree-class.md)

`CRBMultiMap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="crbmultimap"></a>  CRBMultiMap::CRBMultiMap

O construtor.

```
explicit CRBMultiMap(size_t nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O *nBlockSize* parâmetro é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos. O padrão será alocar espaço para 10 elementos por vez.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#85](../../atl/codesnippet/cpp/crbmultimap-class_1.cpp)]

##  <a name="dtor"></a>  CRBMultiMap::~CRBMultiMap

O destruidor.

```
~CRBMultiMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

##  <a name="findfirstwithkey"></a>  CRBMultiMap::FindFirstWithKey

Chame esse método para localizar a posição do primeiro elemento com uma determinada chave.

```
POSITION FindFirstWithKey(KINARGTYPE key) const throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a chave que identifica o elemento a ser localizada.

### <a name="return-value"></a>Valor de retorno

Se a chave for encontrada, NULL caso contrário, retorna a posição do primeiro elemento de chave/valor.

### <a name="remarks"></a>Comentários

Uma chave no `CRBMultiMap` pode ter um ou mais valores associados. Esse método fornecerá o valor da posição do primeiro valor (que, na verdade, talvez o único valor) associado a essa chave particular. O valor retornado da posição, em seguida, pode ser usado com [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey) para obter o valor e atualize a posição.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

##  <a name="getnextvaluewithkey"></a>  CRBMultiMap::GetNextValueWithKey

Chame esse método para obter o valor associado a uma determinada chave e atualize o valor da posição.

```
const V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
V& GetNextValueWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O valor da posição, obtido com a chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextWithKey](#getnextwithkey), ou uma chamada anterior a `GetNextValueWithKey`.

*key*<br/>
Especifica a chave que identifica o elemento a ser localizada.

### <a name="return-value"></a>Valor de retorno

Retorna o par de elemento associado com a chave especificada.

### <a name="remarks"></a>Comentários

O valor de posição é atualizado para apontar para o próximo valor associado à chave. Se não existem mais valores, o valor da posição é definido como NULL.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

##  <a name="getnextwithkey"></a>  CRBMultiMap::GetNextWithKey

Chame esse método para obter o elemento associado a uma determinada chave e atualize o valor da posição.

```
const CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) const throw();
CPair* GetNextWithKey(
    POSITION& pos,
    KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O valor da posição, obtido com a chamada para [CRBMultiMap::FindFirstWithKey](#findfirstwithkey) ou [CRBMultiMap::GetNextValueWithKey](#getnextvaluewithkey), ou uma chamada anterior a `GetNextWithKey`.

*key*<br/>
Especifica a chave que identifica o elemento a ser localizada.

### <a name="return-value"></a>Valor de retorno

Retorna o próximo [CRBTree::CPair classe](crbtree-class.md#cpair_class) elemento associado com a chave especificada.

### <a name="remarks"></a>Comentários

O valor de posição é atualizado para apontar para o próximo valor associado à chave. Se não existem mais valores, o valor da posição é definido como NULL.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

##  <a name="insert"></a>  CRBMultiMap::Insert

Chame esse método para inserir um par de elementos no mapa.

```
POSITION Insert(KINARGTYPE key, VINARGTYPE value) throw(...);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O valor da chave para adicionar ao `CRBMultiMap` objeto.

*value*<br/>
O valor a ser adicionado para o `CRBMultiMap` objeto, associado *chave*.

### <a name="return-value"></a>Valor de retorno

Retorna a posição do par chave/valor de elemento no `CRBMultiMap` objeto.

### <a name="remarks"></a>Comentários

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

##  <a name="removekey"></a>  CRBMultiMap::RemoveKey

Chame esse método para remover todos os elementos de chave/valor para uma determinada chave.

```
size_t RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a chave que identifica o elemento (s) a ser excluído.

### <a name="return-value"></a>Valor de retorno

Retorna o número de valores associados com a chave especificada.

### <a name="remarks"></a>Comentários

`RemoveKey` Exclui todos os elementos de chave/valor que têm uma chave que corresponda *chave*.

Consulte a documentação para a classe base [CRBTree](../../atl/reference/crbtree-class.md) para obter informações sobre os métodos disponíveis.

### <a name="example"></a>Exemplo

Veja o exemplo de [CRBMultiMap::CRBMultiMap](#crbmultimap).

## <a name="see-also"></a>Consulte também

[Classe CRBTree](../../atl/reference/crbtree-class.md)<br/>
[Classe CAtlMap](../../atl/reference/catlmap-class.md)<br/>
[Classe CRBMap](../../atl/reference/crbmap-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
