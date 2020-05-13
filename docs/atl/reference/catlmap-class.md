---
title: Classe CAtlMap
ms.date: 11/04/2016
f1_keywords:
- CAtlMap
- ATLCOLL/ATL::CAtlMap
- ATLCOLL/ATL::CAtlMap::KINARGTYPE
- ATLCOLL/ATL::CAtlMap::KOUTARGTYPE
- ATLCOLL/ATL::CAtlMap::VINARGTYPE
- ATLCOLL/ATL::CAtlMap::VOUTARGTYPE
- ATLCOLL/ATL::CPair::m_key
- ATLCOLL/ATL::CPair::m_value
- ATLCOLL/ATL::CAtlMap::CAtlMap
- ATLCOLL/ATL::CAtlMap::AssertValid
- ATLCOLL/ATL::CAtlMap::DisableAutoRehash
- ATLCOLL/ATL::CAtlMap::EnableAutoRehash
- ATLCOLL/ATL::CAtlMap::GetAt
- ATLCOLL/ATL::CAtlMap::GetCount
- ATLCOLL/ATL::CAtlMap::GetHashTableSize
- ATLCOLL/ATL::CAtlMap::GetKeyAt
- ATLCOLL/ATL::CAtlMap::GetNext
- ATLCOLL/ATL::CAtlMap::GetNextAssoc
- ATLCOLL/ATL::CAtlMap::GetNextKey
- ATLCOLL/ATL::CAtlMap::GetNextValue
- ATLCOLL/ATL::CAtlMap::GetStartPosition
- ATLCOLL/ATL::CAtlMap::GetValueAt
- ATLCOLL/ATL::CAtlMap::InitHashTable
- ATLCOLL/ATL::CAtlMap::IsEmpty
- ATLCOLL/ATL::CAtlMap::Lookup
- ATLCOLL/ATL::CAtlMap::Rehash
- ATLCOLL/ATL::CAtlMap::RemoveAll
- ATLCOLL/ATL::CAtlMap::RemoveAtPos
- ATLCOLL/ATL::CAtlMap::RemoveKey
- ATLCOLL/ATL::CAtlMap::SetAt
- ATLCOLL/ATL::CAtlMap::SetOptimalLoad
- ATLCOLL/ATL::CAtlMap::SetValueAt
helpviewer_keywords:
- CAtlMap class
ms.assetid: 5e2fe028-8e6d-4686-93df-1433d2080ec3
ms.openlocfilehash: b79e6cbd796569e6ba11c96158099de6c30b310a
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168053"
---
# <a name="catlmap-class"></a>Classe CAtlMap

Essa classe fornece métodos para criar e gerenciar um objeto de mapa.

## <a name="syntax"></a>Sintaxe

```cpp
template <typename K,
          typename V,
          class KTraits = CElementTraits<K>,
          class VTraits = CElementTraits<V>>
class CAtlMap
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
O tipo de elemento de chave.

*L*<br/>
O tipo de elemento de valor.

*KTraits*<br/>
O código usado para copiar ou mover os elementos principais. Consulte a [classe CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

*VTraits*<br/>
O código usado para copiar ou mover elementos de valor.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::KINARGTYPE](#kinargtype)|Tipo usado quando uma chave é passada como um argumento de entrada|
|[CAtlMap::KOUTARGTYPE](#koutargtype)|Tipo usado quando uma chave é retornada como um argumento de saída.|
|[CAtlMap::VINARGTYPE](#vinargtype)|Tipo usado quando um valor é passado como um argumento de entrada.|
|[CAtlMap::VOUTARGTYPE](#voutargtype)|Tipo usado quando um valor é passado como um argumento de saída.|

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe CAtlMap:: CPair](#cpair_class)|Uma classe que contém os elementos de chave e valor.|

### <a name="cpair-data-members"></a>Membros de dados do CPair

|Nome|Descrição|
|----------|-----------------|
|[CPair:: m_key](#m_key)|O membro de dados que armazena o elemento de chave.|
|[CPair:: m_value](#m_value)|O membro de dados que armazena o elemento de valor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::CAtlMap](#catlmap)|O construtor.|
|[CAtlMap:: ~ CAtlMap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::AssertValid](#assertvalid)|Chame esse método para causar um ASSERT se o `CAtlMap` não for válido.|
|[CAtlMap::D isableAutoRehash](#disableautorehash)|Chame esse método para desabilitar o `CAtlMap` rehash automático do objeto.|
|[CAtlMap::EnableAutoRehash](#enableautorehash)|Chame esse método para habilitar o `CAtlMap` rehash automático do objeto.|
|[CAtlMap::GetAt](#getat)|Chame esse método para retornar o elemento em uma posição especificada no mapa.|
|[CAtlMap:: GetCount](#getcount)|Chame esse método para recuperar o número de elementos no mapa.|
|[CAtlMap::GetHashTableSize](#gethashtablesize)|Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.|
|[CAtlMap::GetKeyAt](#getkeyat)|Chame esse método para recuperar a chave armazenada na posição especificada no `CAtlMap` objeto.|
|[CAtlMap:: GetNext](#getnext)|Chame esse método para obter um ponteiro para o próximo par de elementos armazenado no `CAtlMap` objeto.|
|[CAtlMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CAtlMap::GetNextKey](#getnextkey)|Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.|
|[CAtlMap:: GetNextValue](#getnextvalue)|Chame esse método para obter o próximo valor do `CAtlMap` objeto.|
|[CAtlMap:: GetStartPosition](#getstartposition)|Chame esse método para iniciar uma iteração de mapa.|
|[CAtlMap::GetValueAt](#getvalueat)|Chame esse método para recuperar o valor armazenado em uma determinada posição no `CAtlMap` objeto.|
|[CAtlMap::InitHashTable](#inithashtable)|Chame esse método para inicializar a tabela de hash.|
|[CAtlMap:: IsEmpty](#isempty)|Chame esse método para testar um objeto de mapa vazio.|
|[CAtlMap:: Lookup](#lookup)|Chame esse método para pesquisar chaves ou valores no `CAtlMap` objeto.|
|[CAtlMap:: rehash](#rehash)|Chame esse método para refazer o `CAtlMap` hash do objeto.|
|[CAtlMap:: RemoveAll](#removeall)|Chame esse método para remover todos os elementos do `CAtlMap` objeto.|
|[CAtlMap::RemoveAtPos](#removeatpos)|Chame esse método para remover o elemento na posição especificada no `CAtlMap` objeto.|
|[CAtlMap::RemoveKey](#removekey)|Chame esse método para remover um elemento do `CAtlMap` objeto, dada a chave.|
|[CAtlMap::SetAt](#setat)|Chame esse método para inserir um par de elementos no mapa.|
|[CAtlMap::SetOptimalLoad](#setoptimalload)|Chame esse método para definir a carga ideal do `CAtlMap` objeto.|
|[CAtlMap::SetValueAt](#setvalueat)|Chame esse método para alterar o valor armazenado em uma determinada posição no `CAtlMap` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CAtlMap::\[\]](catlmap-class.md#operator_at)|Substitui ou adiciona um novo elemento ao `CAtlMap`.|

## <a name="remarks"></a>Comentários

`CAtlMap`fornece suporte para uma matriz de mapeamento de qualquer tipo determinado, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados. Elementos (que consistem em uma chave e um valor) são armazenados usando um algoritmo de hash, permitindo que uma grande quantidade de dados seja armazenada e recuperada de forma eficiente.

Os parâmetros *KTraits* e *VTraits* são classes de características que contêm qualquer código suplementar necessário para copiar ou mover elementos.

Uma alternativa a `CAtlMap` é oferecida pela classe [CRBMap](../../atl/reference/crbmap-class.md) . `CRBMap`também armazena pares chave/valor, mas exibe características de desempenho diferentes. O tempo necessário para inserir um item, pesquisar uma chave ou excluir uma chave de um `CRBMap` objeto é de log de ordem *(n)*, em que *n* é o número de elementos. Para `CAtlMap`o, todas essas operações normalmente levam um tempo constante, embora os cenários de pior caso possam ser da ordem *n*. Portanto, em um caso típico, `CAtlMap` é mais rápido.

A outra diferença entre `CRBMap` e `CAtlMap` torna-se aparente ao iterar pelos elementos armazenados. Em um `CRBMap`, os elementos são visitados em uma ordem classificada. Em um `CAtlMap`, os elementos não são ordenados e nenhuma ordem pode ser inferida.

Quando um pequeno número de elementos precisar ser armazenado, considere usar a classe [CSimpleMap](../../atl/reference/csimplemap-class.md) em vez disso.

Para obter mais informações, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="catlmapassertvalid"></a><a name="assertvalid"></a>CAtlMap::AssertValid

Chame esse método para causar uma declaração se o `CAtlMap` objeto não for válido.

```cpp
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Em compilações de depuração, esse método causará uma `CAtlMap` declaração se o objeto não for válido.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapcatlmap"></a><a name="catlmap"></a>CAtlMap::CAtlMap

O construtor.

```cpp
CAtlMap(
    UINT nBins = 17,
    float fOptimalLoad = 0.75f,
    float fLoThreshold = 0.25f,
    float fHiThreshold = 2.25f,
    UINT nBlockSize = 10) throw ();
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O número de compartimentos que fornecem ponteiros para os elementos armazenados. Consulte os comentários mais adiante neste tópico para obter uma explicação dos compartimentos.

*fOptimalLoad*<br/>
A taxa de carga ideal.

*fLoThreshold*<br/>
O limite inferior para a taxa de carga.

*fHiThreshold*<br/>
O limite superior para a taxa de carga.

*nBlockSize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

`CAtlMap`faz referência a todos os seus elementos armazenados criando primeiro um índice usando um algoritmo de hash na chave. Esse índice faz referência a um "bin" que contém um ponteiro para os elementos armazenados. Se o bin já estiver em uso, uma lista vinculada será criada para acessar os elementos subsequentes. Percorrer uma lista é mais lento do que acessar diretamente o elemento correto e, portanto, a estrutura do mapa precisa balancear os requisitos de armazenamento em relação ao desempenho. Os parâmetros padrão foram escolhidos para fornecer bons resultados na maioria dos casos.

A taxa de carga é a taxa do número de compartimentos para o número de elementos armazenados no objeto de mapa. Quando a estrutura do mapa for recalculada, o valor do parâmetro *fOptimalLoad* será usado para calcular o número de compartimentos necessários. Esse valor pode ser alterado usando o método [CAtlMap:: SetOptimalLoad](#setoptimalload) .

O parâmetro *fLoThreshold* é o menor valor que a taxa de carga pode alcançar `CAtlMap` antes de recalcular o tamanho ideal do mapa.

O parâmetro *fHiThreshold* é o valor superior que a taxa de carga pode alcançar antes `CAtlMap` que o objeto recalcule o tamanho ideal do mapa.

Esse processo de recálculo (conhecido como rehash) é habilitado por padrão. Se você quiser desabilitar esse processo, talvez ao inserir muitos dados ao mesmo tempo, chame o método [CAtlMap::D isableautorehash](#disableautorehash) . Reative-o com o método [CAtlMap:: EnableAutoRehash](#enableautorehash) .

O parâmetro *nBlockSize* é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

Antes que qualquer dado possa ser armazenado, é necessário inicializar a tabela de hash com uma chamada para [CAtlMap:: InitHashTable](#inithashtable).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#72](../../atl/codesnippet/cpp/catlmap-class_1.cpp)]

## <a name="catlmapcatlmap"></a><a name="dtor"></a>CAtlMap:: ~ CAtlMap

O destruidor.

```cpp
~CAtlMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="catlmapcpair-class"></a><a name="cpair_class"></a>Classe CAtlMap:: CPair

Uma classe que contém os elementos de chave e valor.

```cpp
class CPair : public __POSITION
```

### <a name="remarks"></a>Comentários

Essa classe é usada pelos métodos [CAtlMap:: GetNext](#getnext) e [CAtlMap:: Lookup](#lookup) para acessar os elementos de chave e valor armazenados na estrutura de mapeamento.

## <a name="catlmapdisableautorehash"></a><a name="disableautorehash"></a>CAtlMap::D isableAutoRehash

Chame esse método para desabilitar o `CAtlMap` rehash automático do objeto.

```cpp
void DisableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando o rehash automático está habilitado (o que é por padrão), o número de compartimentos na tabela de hash será automaticamente recalculado se o valor de carga (a taxa do número de compartimentos para o número de elementos armazenados na matriz) exceder os valores máximos ou mínimos especificados no momento em que o mapa foi criado.

`DisableAutoRehash`é mais útil quando um grande número de elementos for adicionado ao mapa de uma vez. Em vez de disparar o processo de rehash sempre que os limites são excedidos, é mais eficiente chamar `DisableAutoRehash`, adicionar os elementos e, finalmente, chamar [CAtlMap:: EnableAutoRehash](#enableautorehash).

## <a name="catlmapenableautorehash"></a><a name="enableautorehash"></a>CAtlMap::EnableAutoRehash

Chame esse método para habilitar o `CAtlMap` rehash automático do objeto.

```cpp
void EnableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando o rehash automático está habilitado (o que é por padrão), o número de compartimentos na tabela de hash será automaticamente recalculado se o valor de carga (a taxa do número de compartimentos para o número de elementos armazenados na matriz) exceder os valores máximos ou mínimos especificados no momento em que o mapa for criado.

`EnableAutoRefresh`é usado com mais frequência após uma chamada para [CAtlMap::D isableautorehash](#disableautorehash).

## <a name="catlmapgetat"></a><a name="getat"></a>CAtlMap::GetAt

Chame esse método para retornar o elemento em uma posição especificada no mapa.

```cpp
void GetAt(
    POSITION pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;

CPair* GetAt(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

*chave*<br/>
Parâmetro de modelo que especifica o tipo da chave do mapa.

*value*<br/>
Parâmetro de modelo que especifica o tipo do valor do mapa.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o par atual de elementos de chave/valor armazenados no mapa.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá um erro de asserção se o *PDV* for igual a nulo.

## <a name="catlmapgetcount"></a><a name="getcount"></a>CAtlMap:: GetCount

Chame esse método para recuperar o número de elementos no mapa.

```cpp
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos no objeto de mapa. Um único elemento é um par chave/valor.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapgethashtablesize"></a><a name="gethashtablesize"></a>CAtlMap::GetHashTableSize

Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.

```cpp
UINT GetHashTableSize() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de compartimentos na tabela de hash. Consulte [CAtlMap:: CAtlMap](#catlmap) para obter uma explicação.

## <a name="catlmapgetkeyat"></a><a name="getkeyat"></a>CAtlMap::GetKeyAt

Chame esse método para recuperar a chave armazenada na posição especificada no `CAtlMap` objeto.

```cpp
const K& GetKeyAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência à chave armazenada na posição especificada no `CAtlMap` objeto.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapgetnext"></a><a name="getnext"></a>CAtlMap:: GetNext

Chame esse método para obter um ponteiro para o próximo par de elementos armazenado no `CAtlMap` objeto.

```cpp
CPair* GetNext(POSITION& pos) throw();
const CPair* GetNext(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo par de elementos de chave/valor armazenados no mapa. O contador de posição de *PDV* é atualizado após cada chamada. Se o elemento recuperado for o último no mapa, *pos* será definido como NULL.

## <a name="catlmapgetnextassoc"></a><a name="getnextassoc"></a>CAtlMap::GetNextAssoc

Obtém o próximo elemento para iteração.

```cpp
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

*chave*<br/>
Parâmetro de modelo que especifica o tipo da chave do mapa.

*value*<br/>
Parâmetro de modelo que especifica o tipo do valor do mapa.

### <a name="remarks"></a>Comentários

O contador de posição de *PDV* é atualizado após cada chamada. Se o elemento recuperado for o último no mapa, *pos* será definido como NULL.

## <a name="catlmapgetnextkey"></a><a name="getnextkey"></a>CAtlMap::GetNextKey

Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.

```cpp
const K& GetNextKey(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência à próxima chave no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas no mapa, o contador de posição será definido como nulo.

## <a name="catlmapgetnextvalue"></a><a name="getnextvalue"></a>CAtlMap:: GetNextValue

Chame esse método para obter o próximo valor do `CAtlMap` objeto.

```cpp
V& GetNextValue(POSITION& pos) throw();
const V& GetNextValue(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao próximo valor no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas no mapa, o contador de posição será definido como nulo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapgetstartposition"></a><a name="getstartposition"></a>CAtlMap:: GetStartPosition

Chame esse método para iniciar uma iteração de mapa.

```cpp
POSITION GetStartPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a posição inicial, ou NULL será retornado se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

Chame esse método para iniciar uma iteração de mapa retornando um valor de posição que pode ser `GetNextAssoc` passado para o método.

> [!NOTE]
> A sequência de iteração não é previsível

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapgetvalueat"></a><a name="getvalueat"></a>CAtlMap::GetValueAt

Chame esse método para recuperar o valor armazenado em uma determinada posição no `CAtlMap` objeto.

```cpp
V& GetValueAt(POSITION pos) throw();
const V& GetValueAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao valor armazenado na posição especificada no `CAtlMap` objeto.

## <a name="catlmapinithashtable"></a><a name="inithashtable"></a>CAtlMap::InitHashTable

Chame esse método para inicializar a tabela de hash.

```cpp
bool InitHashTable(
    UINT nBins,
    bool bAllocNow = true);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O número de compartimentos usados pela tabela de hash. Consulte [CAtlMap:: CAtlMap](#catlmap) para obter uma explicação.

*bAllocNow*<br/>
Uma indicação de sinalizador quando a memória deve ser alocada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE na inicialização bem-sucedida, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

`InitHashTable`deve ser chamado antes de qualquer elemento ser armazenado na tabela de hash.  Se esse método não for chamado explicitamente, ele será chamado automaticamente na primeira vez que um elemento for adicionado usando a contagem de compartimentos especificada `CAtlMap` pelo construtor.  Caso contrário, o mapa será inicializado usando a nova contagem de compartimentos especificada pelo parâmetro *nBins* .

Se o parâmetro *bAllocNow* for false, a memória exigida pela tabela de hash não será alocada até ser solicitada pela primeira vez. Isso pode ser útil se for incerto se o mapa será usado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapisempty"></a><a name="isempty"></a>CAtlMap:: IsEmpty

Chame esse método para testar um objeto de mapa vazio.

```cpp
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o mapa estiver vazio; caso contrário, FALSE.

## <a name="catlmapkinargtype"></a><a name="kinargtype"></a>CAtlMap::KINARGTYPE

Tipo usado quando uma chave é passada como um argumento de entrada.

```cpp
typedef KTraits::INARGTYPE KINARGTYPE;
```

## <a name="catlmapkoutargtype"></a><a name="koutargtype"></a>CAtlMap::KOUTARGTYPE

Tipo usado quando uma chave é retornada como um argumento de saída.

```cpp
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```

## <a name="catlmaplookup"></a><a name="lookup"></a>CAtlMap:: Lookup

Chame esse método para pesquisar chaves ou valores no `CAtlMap` objeto.

```cpp
bool Lookup(KINARGTYPE key, VOUTARGTYPE value) const;
const CPair* Lookup(KINARGTYPE key) const throw();
CPair* Lookup(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
Especifica a chave que identifica o elemento a ser pesquisado.

*value*<br/>
Variável que recebe o valor de pesquisa.

### <a name="return-value"></a>Valor retornado

A primeira forma do método retornará true se a chave for encontrada, caso contrário, false. O segundo e o terceiro formulários retornam um ponteiro para um [CPair](#cpair_class) que pode ser usado como uma posição para chamadas para [CAtlMap:: GetNext](#getnext) e assim por diante.

### <a name="remarks"></a>Comentários

`Lookup`usa um algoritmo de hash para localizar rapidamente o elemento Map que contém uma chave que corresponde exatamente ao parâmetro de chave fornecido.

## <a name="catlmapoperator-"></a><a name="operator_at"></a>Operador CAtlMap::\[\]

Substitui ou adiciona um novo elemento ao `CAtlMap`.

```cpp
V& operator[](kinargtype key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave do elemento a ser adicionado ou substituído.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao valor associado à chave especificada.

### <a name="example"></a>Exemplo

Se a chave já existir, o elemento será substituído. Se a chave não existir, um novo elemento será adicionado. Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmaprehash"></a><a name="rehash"></a>CAtlMap:: rehash

Chame esse método para refazer o `CAtlMap` hash do objeto.

```cpp
void Rehash(UINT nBins = 0);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O novo número de compartimentos a serem usados na tabela de hash. Consulte [CAtlMap:: CAtlMap](#catlmap) para obter uma explicação.

### <a name="remarks"></a>Comentários

Se *nBins* for 0, `CAtlMap` calculará um número razoável com base no número de elementos no mapa e na configuração de carga ideal. Normalmente, o processo de rehash é automático, mas se [CAtlMap::D isableautorehash](#disableautorehash) for chamado, esse método executará o redimensionamento necessário.

## <a name="catlmapremoveall"></a><a name="removeall"></a>CAtlMap:: RemoveAll

Chame esse método para remover todos os elementos do `CAtlMap` objeto.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Limpa o `CAtlMap` objeto, liberando a memória usada para armazenar os elementos.

## <a name="catlmapremoveatpos"></a><a name="removeatpos"></a>CAtlMap::RemoveAtPos

Chame esse método para remover o elemento na posição especificada no `CAtlMap` objeto.

```cpp
void RemoveAtPos(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

### <a name="remarks"></a>Comentários

Remove o par de chave/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A posição referenciada pelo *PDV* torna-se inválida e, embora a posição de quaisquer outros elementos no mapa permaneça válida, elas não retêm necessariamente a mesma ordem.

## <a name="catlmapremovekey"></a><a name="removekey"></a>CAtlMap::RemoveKey

Chame esse método para remover um elemento do `CAtlMap` objeto, dada a chave.

```cpp
bool RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave correspondente ao par de elementos que você deseja remover.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se a chave for encontrada e removida, FALSE em caso de falha.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlMap:: CAtlMap](#catlmap).

## <a name="catlmapsetat"></a><a name="setat"></a>CAtlMap::SetAt

Chame esse método para inserir um par de elementos no mapa.

```cpp
POSITION SetAt(
    KINARGTYPE key,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
O valor de chave a ser adicionado `CAtlMap` ao objeto.

*value*<br/>
O valor a ser adicionado ao `CAtlMap` objeto.

### <a name="return-value"></a>Valor retornado

Retorna a posição do par de elementos chave/valor no `CAtlMap` objeto.

### <a name="remarks"></a>Comentários

`SetAt`Substitui um elemento existente se uma chave correspondente for encontrada. Se a chave não for encontrada, um novo par chave/valor será criado.

## <a name="catlmapsetoptimalload"></a><a name="setoptimalload"></a>CAtlMap::SetOptimalLoad

Chame esse método para definir a carga ideal do `CAtlMap` objeto.

```cpp
void SetOptimalLoad(
    float fOptimalLoad,
    float fLoThreshold,
    float fHiThreshold,
    bool bRehashNow = false);
```

### <a name="parameters"></a>Parâmetros

*fOptimalLoad*<br/>
A taxa de carga ideal.

*fLoThreshold*<br/>
O limite inferior para a taxa de carga.

*fHiThreshold*<br/>
O limite superior para a taxa de carga.

*bRehashNow*<br/>
Sinalizador que indica se a tabela de hash deve ser recalculada.

### <a name="remarks"></a>Comentários

Esse método redefine o valor de carga ideal para o `CAtlMap` objeto. Consulte [CAtlMap:: CAtlMap](#catlmap) para obter uma discussão sobre os vários parâmetros. Se *bRehashNow* for true e o número de elementos estiver fora dos valores mínimo e máximo, a tabela de hash será recalculada.

## <a name="catlmapsetvalueat"></a><a name="setvalueat"></a>CAtlMap::SetValueAt

Chame esse método para alterar o valor armazenado em uma determinada posição no `CAtlMap` objeto.

```cpp
void SetValueAt(
    POSITION pos,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap:: GetNextAssoc](#getnextassoc) ou [CAtlMap:: GetStartPosition](#getstartposition).

*value*<br/>
O valor a ser adicionado ao `CAtlMap` objeto.

### <a name="remarks"></a>Comentários

Altera o elemento de valor armazenado na posição especificada no `CAtlMap` objeto.

## <a name="catlmapvinargtype"></a><a name="vinargtype"></a>CAtlMap::VINARGTYPE

Tipo usado quando um valor é passado como um argumento de entrada.

```cpp
typedef VTraits::INARGTYPE VINARGTYPE;
```

## <a name="catlmapvoutargtype"></a><a name="voutargtype"></a>CAtlMap::VOUTARGTYPE

Tipo usado quando um valor é passado como um argumento de saída.

```cpp
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```

## <a name="catlmapcpairm_key"></a><a name="m_key"></a>CAtlMap:: CPair:: m_key

O membro de dados que armazena o elemento de chave.

```cpp
const K m_key;
```

### <a name="parameters"></a>Parâmetros

*C*<br/>
O tipo de elemento de chave.

## <a name="catlmapcpairm_value"></a><a name="m_value"></a>CAtlMap:: CPair:: m_value

O membro de dados que armazena o elemento de valor.

```cpp
V  m_value;
```

### <a name="parameters"></a>Parâmetros

*L*<br/>
O tipo de elemento de valor.

## <a name="see-also"></a>Confira também

[Exemplo de letreiro](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
