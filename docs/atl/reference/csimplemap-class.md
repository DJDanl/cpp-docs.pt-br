---
title: Classe CSimpleMap
ms.date: 11/04/2016
f1_keywords:
- CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap::_ArrayElementType
- ATLSIMPCOLL/ATL::CSimpleMap::_ArrayKeyType
- ATLSIMPCOLL/ATL::CSimpleMap::CSimpleMap
- ATLSIMPCOLL/ATL::CSimpleMap::Add
- ATLSIMPCOLL/ATL::CSimpleMap::FindKey
- ATLSIMPCOLL/ATL::CSimpleMap::FindVal
- ATLSIMPCOLL/ATL::CSimpleMap::GetKeyAt
- ATLSIMPCOLL/ATL::CSimpleMap::GetSize
- ATLSIMPCOLL/ATL::CSimpleMap::GetValueAt
- ATLSIMPCOLL/ATL::CSimpleMap::Lookup
- ATLSIMPCOLL/ATL::CSimpleMap::Remove
- ATLSIMPCOLL/ATL::CSimpleMap::RemoveAll
- ATLSIMPCOLL/ATL::CSimpleMap::RemoveAt
- ATLSIMPCOLL/ATL::CSimpleMap::ReverseLookup
- ATLSIMPCOLL/ATL::CSimpleMap::SetAt
- ATLSIMPCOLL/ATL::CSimpleMap::SetAtIndex
helpviewer_keywords:
- CSimpleMap class
ms.assetid: 61b06eb4-ae73-44b0-a305-0afb5a33e8b1
ms.openlocfilehash: eed41c2250728d257b6d303e79c3afd36a543dbb
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747646"
---
# <a name="csimplemap-class"></a>Classe CSimpleMap

Esta classe fornece suporte para uma matriz de mapeamento simples.

## <a name="syntax"></a>Sintaxe

```
template <class TKey, class TVal, class TEqual = CSimpleMapEqualHelper<TKey, TVal>>
class CSimpleMap
```

#### <a name="parameters"></a>Parâmetros

*TKey*<br/>
O tipo de elemento-chave.

*Tval*<br/>
O tipo de elemento de valor.

*TEqual*<br/>
Um objeto de característica, definindo o `T`teste de igualdade para elementos do tipo .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMap::_ArrayElementType](#_arrayelementtype)|Digite para o tipo de valor.|
|[CSimpleMap::_ArrayKeyType](#_arraykeytype)|Digite para o tipo de chave.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMap::CSimpleMap](#csimplemap)|O construtor.|
|[CSimpleMap::~CSimpleMap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CSimpleMap::Adicionar](#add)|Adiciona uma chave e valor associado à matriz do mapa.|
|[CSimpleMap::FindKey](#findkey)|Encontra uma chave específica.|
|[CSimpleMap::FindVal](#findval)|Encontra um valor específico.|
|[csimplemap::getkeyat](#getkeyat)|Recupera a chave especificada.|
|[CSimpleMap::GetSize](#getsize)|Retorna o número de entradas na matriz de mapeamento.|
|[csimplemap::getvalueat](#getvalueat)|Recupera o valor especificado.|
|[CSimpleMap::Lookup](#lookup)|Devolve o valor associado à tecla dada.|
|[CSimpleMap::Remove](#remove)|Remove uma chave e um valor correspondente.|
|[csimplemap::removeall](#removeall)|Remove todas as chaves e valores.|
|[CSimplemap::removeat](#removeat)|Remove uma chave específica e um valor de correspondência.|
|[CSimpleMap::ReverseLookup](#reverselookup)|Devolve a chave associada ao valor dado.|
|[CSimplemap::Setat](#setat)|Define o valor associado à tecla dada.|
|[csimplemap::setatindex](#setatindex)|Define a chave e o valor específicos.|

## <a name="remarks"></a>Comentários

`CSimpleMap`fornece suporte para uma matriz de `T`mapeamento simples de qualquer tipo, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados.

O parâmetro `TEqual` fornece um meio de definir uma função `T`de igualdade para dois elementos do tipo . Ao criar uma classe semelhante ao [CSimpleMapEqualHelper,](../../atl/reference/csimplemapequalhelper-class.md)é possível alterar o comportamento do teste de igualdade para qualquer matriz. Por exemplo, ao lidar com uma matriz de ponteiros, pode ser útil definir a igualdade dependendo dos valores que os ponteiros referenciam. A implementação padrão utiliza **o operador==()**.

Ambos `CSimpleMap` e [o CSimpleArray](../../atl/reference/csimplearray-class.md) são fornecidos para compatibilidade com versões ATL anteriores, e implementações de coleta mais completas e eficientes são fornecidas pelo [CAtlArray](../../atl/reference/catlarray-class.md) e [cAtlMap](../../atl/reference/catlmap-class.md).

Ao contrário de outras coleções de mapas em ATL e MFC, esta classe é implementada com uma matriz simples, e pesquisas de pesquisa requerem uma pesquisa linear. `CAtlMap`deve ser usado quando a matriz contém um grande número de elementos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpcoll.h

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#91](../../atl/codesnippet/cpp/csimplemap-class_1.cpp)]

## <a name="csimplemapadd"></a><a name="add"></a>CSimpleMap::Adicionar

Adiciona uma chave e valor associado à matriz do mapa.

```
BOOL Add(const TKey& key, const TVal& val);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave.

*Val*<br/>
O valor associado.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a chave e o valor foram adicionados com sucesso, FALSO de outra forma.

### <a name="remarks"></a>Comentários

Cada chave e o par de valores adicionados fazem com que a memória do conjunto de mapeamento seja liberada e realocada, a fim de garantir que os dados de cada um sejam sempre armazenados contíguamente. Ou seja, o segundo elemento-chave sempre segue diretamente o primeiro elemento-chave na memória e assim por diante.

## <a name="csimplemap_arrayelementtype"></a><a name="_arrayelementtype"></a>CSimpleMap::_ArrayElementType

Um typedef para o tipo de chave.

```
typedef TVal _ArrayElementType;
```

## <a name="csimplemap_arraykeytype"></a><a name="_arraykeytype"></a>CSimpleMap::_ArrayKeyType

Um typedef para o tipo de valor.

```
typedef TKey _ArrayKeyType;
```

## <a name="csimplemapcsimplemap"></a><a name="csimplemap"></a>CSimpleMap::CSimpleMap

O construtor.

```
CSimpleMap();
```

### <a name="remarks"></a>Comentários

Inicializa os membros dos dados.

## <a name="csimplemapcsimplemap"></a><a name="dtor"></a>CSimpleMap::~CSimpleMap

O destruidor.

```
~CSimpleMap();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="csimplemapfindkey"></a><a name="findkey"></a>CSimpleMap::FindKey

Encontra uma chave específica.

```
int FindKey(const TKey& key) const;
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave a ser pesquisada.

### <a name="return-value"></a>Valor retornado

Retorna o índice da chave se encontrado, caso contrário retorna -1.

## <a name="csimplemapfindval"></a><a name="findval"></a>CSimpleMap::FindVal

Encontra um valor específico.

```
int FindVal(const TVal& val) const;
```

### <a name="parameters"></a>Parâmetros

*Val*<br/>
O valor pelo qual pesquisar.

### <a name="return-value"></a>Valor retornado

Retorna o índice do valor se for encontrado, caso contrário retorna -1.

## <a name="csimplemapgetkeyat"></a><a name="getkeyat"></a>csimplemap::getkeyat

Recupera a chave no índice especificado.

```
TKey& GetKeyAt(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice da chave a ser retornada.

### <a name="return-value"></a>Valor retornado

Retorna a chave referenciada por *nIndex*.

### <a name="remarks"></a>Comentários

O índice aprovado pelo *nIndex* deve ser válido para que o valor de retorno seja significativo.

## <a name="csimplemapgetsize"></a><a name="getsize"></a>CSimpleMap::GetSize

Retorna o número de entradas na matriz de mapeamento.

```
int GetSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de entradas (uma chave e valor é uma entrada) na matriz de mapeamento.

## <a name="csimplemapgetvalueat"></a><a name="getvalueat"></a>csimplemap::getvalueat

Recupera o valor no índice específico.

```
TVal& GetValueAt(int nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice do valor a retorno.

### <a name="return-value"></a>Valor retornado

Retorna o valor referenciado pelo *nIndex*.

### <a name="remarks"></a>Comentários

O índice aprovado pelo *nIndex* deve ser válido para que o valor de retorno seja significativo.

## <a name="csimplemaplookup"></a><a name="lookup"></a>CSimpleMap::Lookup

Devolve o valor associado à tecla dada.

```
TVal Lookup(const TKey& key) const;
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave.

### <a name="return-value"></a>Valor retornado

Devolve o valor associado. Se nenhuma chave correspondente for encontrada, NULL é devolvido.

## <a name="csimplemapremove"></a><a name="remove"></a>CSimpleMap::Remove

Remove uma chave e um valor correspondente.

```
BOOL Remove(const TKey& key);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a chave e o valor correspondente forem removidos com sucesso, FALSO de outra forma.

## <a name="csimplemapremoveall"></a><a name="removeall"></a>csimplemap::removeall

Remove todas as chaves e valores.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Remove todas as chaves e valores do objeto da matriz de mapeamento.

## <a name="csimplemapremoveat"></a><a name="removeat"></a>CSimplemap::removeat

Remove uma chave e um valor associado no índice especificado.

```
BOOL RemoveAt(int nIndex);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice da chave e do valor associado para remover.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSE se o índice especificado for um índice inválido.

## <a name="csimplemapreverselookup"></a><a name="reverselookup"></a>CSimpleMap::ReverseLookup

Devolve a chave associada ao valor dado.

```
TKey ReverseLookup(const TVal& val) const;
```

### <a name="parameters"></a>Parâmetros

*Val*<br/>
O valor.

### <a name="return-value"></a>Valor retornado

Retorna a chave associada. Se nenhuma chave correspondente for encontrada, NULL é devolvido.

## <a name="csimplemapsetat"></a><a name="setat"></a>CSimplemap::Setat

Define o valor associado à tecla dada.

```
BOOL SetAt(const TKey& key, const TVal& val);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave.

*Val*<br/>
O novo valor a ser atribuído.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a chave foi encontrada e o valor foi alterado com sucesso, FALSO de outra forma.

## <a name="csimplemapsetatindex"></a><a name="setatindex"></a>csimplemap::setatindex

Defina a chave e o valor em um índice especificado.

```
BOOL SetAtIndex(
    int nIndex,
    const TKey& key,
    const TVal& val);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice, fazendo referência ao emparelhamento de tecla e valor para alterar.

*chave*<br/>
A nova chave.

*Val*<br/>
O novo valor.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se for bem sucedido, FALSO se o índice não for válido.

### <a name="remarks"></a>Comentários

Atualiza tanto a chave quanto o valor apontados pelo *nIndex*.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
