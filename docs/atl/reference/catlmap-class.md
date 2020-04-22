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
ms.openlocfilehash: 8954eeae28f13fb50643646b41c032588ecc278f
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748660"
---
# <a name="catlmap-class"></a>Classe CAtlMap

Esta classe fornece métodos para criar e gerenciar um objeto de mapa.

## <a name="syntax"></a>Sintaxe

```
template <typename K,
          typename V,
          class KTraits = CElementTraits<K>,
          class VTraits = CElementTraits<V>>
class CAtlMap
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

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::KINARGTYPE](#kinargtype)|Digite usado quando uma chave é passada como um argumento de entrada|
|[CAtlMap::KOUTARGTYPE](#koutargtype)|Digite usado quando uma chave é devolvida como um argumento de saída.|
|[CAtlMap::VINARGTYPE](#vinargtype)|Digite usado quando um valor é passado como um argumento de entrada.|
|[CAtlMap::VOUTARGTYPE](#voutargtype)|Digite usado quando um valor é passado como um argumento de saída.|

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::CPair Class](#cpair_class)|Uma classe contendo os elementos chave e valor.|

### <a name="cpair-data-members"></a>Membros de dados cpair

|Nome|Descrição|
|----------|-----------------|
|[CPair::m_key](#m_key)|O membro de dados armazena ndo o elemento-chave.|
|[CPair::m_value](#m_value)|O membro de dados armazena ndo o elemento de valor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::CAtlMap](#catlmap)|O construtor.|
|[CAtlMap::~CAtlMap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::AssertValid](#assertvalid)|Chame este método para causar `CAtlMap` um ASSERT se o não for válido.|
|[CAtlMap::DisableAutoRehash](#disableautorehash)|Chame este método para desativar a reedição automática do `CAtlMap` objeto.|
|[CAtlMap::EnableAutoRehash](#enableautorehash)|Chame este método para ativar a `CAtlMap` reedição automática do objeto.|
|[CAtlMap::GetAt](#getat)|Chame este método para retornar o elemento em uma posição especificada no mapa.|
|[CAtlMap::GetCount](#getcount)|Chame este método para recuperar o número de elementos no mapa.|
|[CAtlMap::GetHashTableSize](#gethashtablesize)|Chame este método para determinar o número de caixas na tabela hash do mapa.|
|[CAtlMap::GetKeyAt](#getkeyat)|Chame este método para recuperar a chave `CAtlMap` armazenada na posição dada no objeto.|
|[CAtlMap::GetNext](#getnext)|Chame este método para obter um ponteiro para `CAtlMap` o próximo par de elementos armazenado no objeto.|
|[CAtlMap::GetNextAssoc](#getnextassoc)|Recebe o próximo elemento para iteração.|
|[CAtlMap::GetNextKey](#getnextkey)|Chame este método para recuperar `CAtlMap` a próxima chave do objeto.|
|[CAtlMap::GetNextValue](#getnextvalue)|Chame este método para obter `CAtlMap` o próximo valor do objeto.|
|[CAtlMap::GetStartPosition](#getstartposition)|Chame este método para iniciar uma iteração de mapa.|
|[CAtlMap::GetValueAt](#getvalueat)|Chame este método para recuperar o valor `CAtlMap` armazenado em uma determinada posição no objeto.|
|[CAtlMap::InitHashTable](#inithashtable)|Chame este método para inicializar a tabela hash.|
|[CAtlMap::IsEmpty](#isempty)|Chame este método para testar um objeto de mapa vazio.|
|[CAtlMap::Lookup](#lookup)|Chame este método para procurar chaves `CAtlMap` ou valores no objeto.|
|[CAtlMap::Rehash](#rehash)|Chame este método para `CAtlMap` refazer o objeto.|
|[CAtlMap::RemoveAll](#removeall)|Chame este método para remover `CAtlMap` todos os elementos do objeto.|
|[CAtlMap::RemoveAtPos](#removeatpos)|Chame este método para remover o elemento `CAtlMap` na posição dada no objeto.|
|[CAtlMap::RemoveKey](#removekey)|Chame este método para remover `CAtlMap` um elemento do objeto, dada a chave.|
|[CAtlMap::SetAt](#setat)|Chame este método para inserir um par de elementos no mapa.|
|[CAtlMap::SetOptimalLoad](#setoptimalload)|Chame este método para definir `CAtlMap` a carga ideal do objeto.|
|[CAtlMap::SetValueAt](#setvalueat)|Chame este método para alterar o valor `CAtlMap` armazenado em uma determinada posição no objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::operador\[\]](catlmap-class.md#operator_at)|Substitui ou adiciona um novo `CAtlMap`elemento ao .|

## <a name="remarks"></a>Comentários

`CAtlMap`fornece suporte para uma matriz de mapeamento de qualquer tipo, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados. Os elementos (que consistem em uma chave e um valor) são armazenados usando um algoritmo de hashing, permitindo que uma grande quantidade de dados seja armazenada e recuperada de forma eficiente.

Os parâmetros *KTraits* e *VTraits* são classes de características que contêm qualquer código suplementar necessário para copiar ou mover elementos.

Uma alternativa `CAtlMap` é oferecida pela classe [CRBMap.](../../atl/reference/crbmap-class.md) `CRBMap`também armazena pares de chaves/valor, mas exibe diferentes características de desempenho. O tempo necessário para inserir um item, procurar uma `CRBMap` chave ou excluir uma chave de um objeto é de *log de ordem(n)*, onde *n* é o número de elementos. Pois, `CAtlMap`todas essas operações normalmente levam um tempo constante, embora os piores cenários possam ser de ordem *n*. Portanto, em um caso `CAtlMap` típico, é mais rápido.

A outra `CRBMap` diferença `CAtlMap` entre e torna-se aparente ao iterar através dos elementos armazenados. Em `CRBMap`um , os elementos são visitados em uma ordem ordenada. Em `CAtlMap`um , os elementos não são ordenados, e nenhuma ordem pode ser inferida.

Quando um pequeno número de elementos precisar ser armazenado, considere usar a classe [CSimpleMap.](../../atl/reference/csimplemap-class.md)

Para obter mais informações, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="catlmapassertvalid"></a><a name="assertvalid"></a>CAtlMap::AssertValid

Chame este método para causar `CAtlMap` um ASSERT se o objeto não for válido.

```cpp
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Nas compilações de depuração, este `CAtlMap` método causará uma ASSERT se o objeto não for válido.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapcatlmap"></a><a name="catlmap"></a>CAtlMap::CAtlMap

O construtor.

```
CAtlMap(
    UINT nBins = 17,
    float fOptimalLoad = 0.75f,
    float fLoThreshold = 0.25f,
    float fHiThreshold = 2.25f,
    UINT nBlockSize = 10) throw ();
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O número de caixas que fornecem ponteiros para os elementos armazenados. Veja observações mais tarde neste tópico para uma explicação das lixeiras.

*fOptimalLoad*<br/>
A relação de carga ideal.

*fLoThreshold*<br/>
O limiar inferior para a relação de carga.

*fHiThreshold*<br/>
O limiar superior para a relação de carga.

*Nblocksize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

`CAtlMap`faz referência a todos os seus elementos armazenados, criando primeiro um índice usando um algoritmo de hashing na chave. Este índice faz referência a um "bin" que contém um ponteiro para os elementos armazenados. Se a lixeira já estiver em uso, uma lista vinculada será criada para acessar os elementos subseqüentes. Atravessar uma lista é mais lento do que acessar diretamente o elemento correto e, portanto, a estrutura do mapa precisa equilibrar os requisitos de armazenamento em relação ao desempenho. Os parâmetros padrão foram escolhidos para dar bons resultados na maioria dos casos.

A razão de carga é a razão entre o número de caixas e o número de elementos armazenados no objeto do mapa. Quando a estrutura do mapa for recalculada, o valor do parâmetro *fOptimalLoad* será usado para calcular o número de caixas necessárias. Esse valor pode ser alterado usando o método [CAtlMap::SetOptimalLoad.](#setoptimalload)

O parâmetro *fLoThreshold* é o valor mais baixo `CAtlMap` que a relação de carga pode alcançar antes de recalcular o tamanho ideal do mapa.

O parâmetro *fHiThreshold* é o valor superior que `CAtlMap` a razão de carga pode alcançar antes que o objeto recalcule o tamanho ideal do mapa.

Este processo de recálculo (conhecido como rehashing) é habilitado por padrão. Se você quiser desativar esse processo, talvez ao inserir muitos dados de uma só vez, ligue para o método [CAtlMap::DisableAutoRehash.](#disableautorehash) Reativá-lo com o método [CAtlMap::EnableAutoRehash.](#enableautorehash)

O parâmetro *nBlockSize* é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de blocomaiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

Antes que qualquer dado possa ser armazenado, é necessário inicializar a tabela hash com uma chamada para [CAtlMap::InitHashTable](#inithashtable).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#72](../../atl/codesnippet/cpp/catlmap-class_1.cpp)]

## <a name="catlmapcatlmap"></a><a name="dtor"></a>CAtlMap::~CAtlMap

O destruidor.

```
~CAtlMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

## <a name="catlmapcpair-class"></a><a name="cpair_class"></a>CAtlMap::CPair Class

Uma classe contendo os elementos chave e valor.

```
class CPair : public __POSITION
```

### <a name="remarks"></a>Comentários

Esta classe é usada pelos métodos [CAtlMap::GetNext](#getnext) e [CAtlMap::Lookup](#lookup) para acessar os elementos de valor e chave armazenados na estrutura de mapeamento.

## <a name="catlmapdisableautorehash"></a><a name="disableautorehash"></a>CAtlMap::DisableAutoRehash

Chame este método para desativar a reedição automática do `CAtlMap` objeto.

```cpp
void DisableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando o rehashing automático estiver ativado (o que é por padrão), o número de caixas na tabela hash será automaticamente recalculado se o valor da carga (a razão do número de bins ao número de elementos armazenados na matriz) exceder os valores máximos ou mínimos especificados no momento em que o mapa foi criado.

`DisableAutoRehash`é mais útil quando um grande número de elementos será adicionado ao mapa de uma só vez. Em vez de acionar o processo de rehashing toda vez `DisableAutoRehash`que os limites são excedidos, é mais eficiente chamar, adicionar os elementos e finalmente chamar [CAtlMap::EnableAutoRehash](#enableautorehash).

## <a name="catlmapenableautorehash"></a><a name="enableautorehash"></a>CAtlMap::EnableAutoRehash

Chame este método para ativar a `CAtlMap` reedição automática do objeto.

```cpp
void EnableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando o rehashing automático estiver ativado (o que é por padrão), o número de caixas na tabela hash será automaticamente recalculado se o valor da carga (a razão do número de bins ao número de elementos armazenados na matriz) exceder os valores máximos ou mínimos especificados no momento em que o mapa for criado.

`EnableAutoRefresh`é mais usado após uma chamada para [CAtlMap::DisableAutoRehash](#disableautorehash).

## <a name="catlmapgetat"></a><a name="getat"></a>CAtlMap::GetAt

Chame este método para retornar o elemento em uma posição especificada no mapa.

```cpp
void GetAt(
    POSITION pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;

CPair* GetAt(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*chave*<br/>
Parâmetro de modelo especificando o tipo da chave do mapa.

*value*<br/>
Parâmetro de modelo especificando o tipo de valor do mapa.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o par atual de elementos de chave/valor armazenados no mapa.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, um erro de afirmação ocorrerá se *pos* for igual a NULL.

## <a name="catlmapgetcount"></a><a name="getcount"></a>CAtlMap::GetCount

Chame este método para recuperar o número de elementos no mapa.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos no objeto do mapa. Um único elemento é um par de chave/valor.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapgethashtablesize"></a><a name="gethashtablesize"></a>CAtlMap::GetHashTableSize

Chame este método para determinar o número de caixas na tabela hash do mapa.

```
UINT GetHashTableSize() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de caixas na tabela hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

## <a name="catlmapgetkeyat"></a><a name="getkeyat"></a>CAtlMap::GetKeyAt

Chame este método para recuperar a chave `CAtlMap` armazenada na posição dada no objeto.

```
const K& GetKeyAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência à chave armazenada na `CAtlMap` posição dada no objeto.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapgetnext"></a><a name="getnext"></a>CAtlMap::GetNext

Chame este método para obter um ponteiro para `CAtlMap` o próximo par de elementos armazenado no objeto.

```
CPair* GetNext(POSITION& pos) throw();
const CPair* GetNext(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo par de elementos de chave/valor armazenados no mapa. O contador de posição *pos* é atualizado após cada chamada. Se o elemento recuperado for o último no mapa, *pos* será definido como NULL.

## <a name="catlmapgetnextassoc"></a><a name="getnextassoc"></a>CAtlMap::GetNextAssoc

Recebe o próximo elemento para iteração.

```cpp
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*chave*<br/>
Parâmetro de modelo especificando o tipo da chave do mapa.

*value*<br/>
Parâmetro de modelo especificando o tipo de valor do mapa.

### <a name="remarks"></a>Comentários

O contador de posição *pos* é atualizado após cada chamada. Se o elemento recuperado for o último no mapa, *pos* será definido como NULL.

## <a name="catlmapgetnextkey"></a><a name="getnextkey"></a>CAtlMap::GetNextKey

Chame este método para recuperar `CAtlMap` a próxima chave do objeto.

```
const K& GetNextKey(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência à próxima chave no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas no mapa, o contador de posição será definido como NULL.

## <a name="catlmapgetnextvalue"></a><a name="getnextvalue"></a>CAtlMap::GetNextValue

Chame este método para obter `CAtlMap` o próximo valor do objeto.

```
V& GetNextValue(POSITION& pos) throw();
const V& GetNextValue(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao próximo valor no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas no mapa, o contador de posição será definido como NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapgetstartposition"></a><a name="getstartposition"></a>CAtlMap::GetStartPosition

Chame este método para iniciar uma iteração de mapa.

```
POSITION GetStartPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a posição inicial, ou NULL é devolvido se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

Chame este método para iniciar uma iteração de mapa retornando `GetNextAssoc` um valor DE POSIÇÃO que pode ser passado para o método.

> [!NOTE]
> A seqüência de iteração não é previsível

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapgetvalueat"></a><a name="getvalueat"></a>CAtlMap::GetValueAt

Chame este método para recuperar o valor `CAtlMap` armazenado em uma determinada posição no objeto.

```
V& GetValueAt(POSITION pos) throw();
const V& GetValueAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao valor armazenado na `CAtlMap` posição dada no objeto.

## <a name="catlmapinithashtable"></a><a name="inithashtable"></a>CAtlMap::InitHashTable

Chame este método para inicializar a tabela hash.

```
bool InitHashTable(
    UINT nBins,
    bool bAllocNow = true);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O número de caixas usadas pela tabela hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

*bAllocNow*<br/>
Uma indicação de bandeira quando a memória deve ser alocada.

### <a name="return-value"></a>Valor retornado

Retorna TRUE na inicialização bem sucedida, FALSE on failure.

### <a name="remarks"></a>Comentários

`InitHashTable`deve ser chamado antes que quaisquer elementos sejam armazenados na tabela hash.  Se este método não for chamado explicitamente, ele será chamado automaticamente na primeira vez que `CAtlMap` um elemento for adicionado usando a contagem de binespecificada pelo construtor.  Caso contrário, o mapa será inicializado usando a nova contagem de binespecificada pelo parâmetro *nBins.*

Se o parâmetro *bAllocNow* for falso, a memória exigida pela tabela hash não será alocada até que seja necessária pela primeira vez. Isso pode ser útil se não for certo se o mapa será usado.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapisempty"></a><a name="isempty"></a>CAtlMap::IsEmpty

Chame este método para testar um objeto de mapa vazio.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o mapa estiver vazio, FALSO de outra forma.

## <a name="catlmapkinargtype"></a><a name="kinargtype"></a>CAtlMap::KINARGTYPE

Digite usado quando uma chave é passada como um argumento de entrada.

```
typedef KTraits::INARGTYPE KINARGTYPE;
```

## <a name="catlmapkoutargtype"></a><a name="koutargtype"></a>CAtlMap::KOUTARGTYPE

Digite usado quando uma chave é devolvida como um argumento de saída.

```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```

## <a name="catlmaplookup"></a><a name="lookup"></a>CAtlMap::Lookup

Chame este método para procurar chaves `CAtlMap` ou valores no objeto.

```
bool Lookup(KINARGTYPE key, VOUTARGTYPE value) const;
const CPair* Lookup(KINARGTYPE key) const throw();
CPair* Lookup(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
Especifica a chave que identifica o elemento a ser examinado.

*value*<br/>
Variável que recebe o valor de análise.

### <a name="return-value"></a>Valor retornado

A primeira forma do método retorna verdadeira se a chave for encontrada, caso contrário, falsa. O segundo e terceiro formulários retornam um ponteiro para um [CPair](#cpair_class) que pode ser usado como uma posição para chamadas para [CAtlMap::GetNext](#getnext) e assim por diante.

### <a name="remarks"></a>Comentários

`Lookup`usa um algoritmo de hashing para encontrar rapidamente o elemento do mapa contendo uma chave que corresponde exatamente ao parâmetro de chave dado.

## <a name="catlmapoperator-"></a><a name="operator_at"></a>CAtlMap::operador\[\]

Substitui ou adiciona um novo `CAtlMap`elemento ao .

```
V& operator[](kinargtype key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A chave do elemento para adicionar ou substituir.

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao valor associado à tecla dada.

### <a name="example"></a>Exemplo

Se a chave já existir, o elemento será substituído. Se a chave não existir, um novo elemento será adicionado. Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmaprehash"></a><a name="rehash"></a>CAtlMap::Rehash

Chame este método para `CAtlMap` refazer o objeto.

```cpp
void Rehash(UINT nBins = 0);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O novo número de caixas para usar na tabela hash. Consulte [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

### <a name="remarks"></a>Comentários

Se *nBins* for `CAtlMap` 0, calcula um número razoável com base no número de elementos no mapa e na configuração ideal de carga. Normalmente, o processo de rehashing é automático, mas se [O CAtlMap::DisívelAutoRehash](#disableautorehash) tiver sido chamado, este método executará o redimensionamento necessário.

## <a name="catlmapremoveall"></a><a name="removeall"></a>CAtlMap::RemoveAll

Chame este método para remover `CAtlMap` todos os elementos do objeto.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Limpa o `CAtlMap` objeto, liberando a memória usada para armazenar os elementos.

## <a name="catlmapremoveatpos"></a><a name="removeatpos"></a>CAtlMap::RemoveAtPos

Chame este método para remover o elemento `CAtlMap` na posição dada no objeto.

```cpp
void RemoveAtPos(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="remarks"></a>Comentários

Remove o par de chaves/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A POSIÇÃO referenciada por *pos* torna-se inválida, e embora a posição de quaisquer outros elementos no mapa permaneça válida, eles não necessariamente retêm a mesma ordem.

## <a name="catlmapremovekey"></a><a name="removekey"></a>CAtlMap::RemoveKey

Chame este método para remover `CAtlMap` um elemento do objeto, dada a chave.

```
bool RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
A tecla correspondente ao par de elementos que deseja remover.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a chave for encontrada e removida, FALSA por falha.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlMap::CAtlMap](#catlmap).

## <a name="catlmapsetat"></a><a name="setat"></a>CAtlMap::SetAt

Chame este método para inserir um par de elementos no mapa.

```
POSITION SetAt(
    KINARGTYPE key,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*chave*<br/>
O valor-chave a `CAtlMap` ser adicionado ao objeto.

*value*<br/>
O valor a `CAtlMap` ser adicionado ao objeto.

### <a name="return-value"></a>Valor retornado

Retorna a posição do par de `CAtlMap` elementos de chave/valor no objeto.

### <a name="remarks"></a>Comentários

`SetAt`substitui um elemento existente se uma chave correspondente for encontrada. Se a chave não for encontrada, um novo par de chaves/valor será criado.

## <a name="catlmapsetoptimalload"></a><a name="setoptimalload"></a>CAtlMap::SetOptimalLoad

Chame este método para definir `CAtlMap` a carga ideal do objeto.

```cpp
void SetOptimalLoad(
    float fOptimalLoad,
    float fLoThreshold,
    float fHiThreshold,
    bool bRehashNow = false);
```

### <a name="parameters"></a>Parâmetros

*fOptimalLoad*<br/>
A relação de carga ideal.

*fLoThreshold*<br/>
O limiar inferior para a relação de carga.

*fHiThreshold*<br/>
O limiar superior para a relação de carga.

*bRehashNow*<br/>
Sinalizar indicando se a tabela hash deve ser recalculada.

### <a name="remarks"></a>Comentários

Este método redefine o valor `CAtlMap` ideal de carga para o objeto. Consulte [CAtlMap::CAtlMap](#catlmap) para uma discussão sobre os vários parâmetros. Se *bRehashNow* for verdadeiro e o número de elementos estiver fora dos valores mínimo e máximo, a tabela hash será recalculada.

## <a name="catlmapsetvalueat"></a><a name="setvalueat"></a>CAtlMap::SetValueAt

Chame este método para alterar o valor `CAtlMap` armazenado em uma determinada posição no objeto.

```cpp
void SetValueAt(
    POSITION pos,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posição, retornado por uma chamada anterior para [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*value*<br/>
O valor a `CAtlMap` ser adicionado ao objeto.

### <a name="remarks"></a>Comentários

Altera o elemento de valor armazenado `CAtlMap` na posição dada no objeto.

## <a name="catlmapvinargtype"></a><a name="vinargtype"></a>CAtlMap::VINARGTYPE

Digite usado quando um valor é passado como um argumento de entrada.

```
typedef VTraits::INARGTYPE VINARGTYPE;
```

## <a name="catlmapvoutargtype"></a><a name="voutargtype"></a>CAtlMap::VOUTARGTYPE

Digite usado quando um valor é passado como um argumento de saída.

```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```

## <a name="catlmapcpairm_key"></a><a name="m_key"></a>CAtlMap::CPair::m_key

O membro de dados armazena ndo o elemento-chave.

```
const K m_key;
```

### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de elemento-chave.

## <a name="catlmapcpairm_value"></a><a name="m_value"></a>CAtlMap::CPair::m_value

O membro de dados armazena ndo o elemento de valor.

```
V  m_value;
```

### <a name="parameters"></a>Parâmetros

*V*<br/>
O tipo de elemento de valor.

## <a name="see-also"></a>Confira também

[Amostra de letreiro](../../overview/visual-cpp-samples.md)<br/>
[AtualizaçãofotoPV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
