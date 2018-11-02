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
ms.openlocfilehash: 83ac810538bf189d026c0cb9b2a76ded49fdd86c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50499665"
---
# <a name="catlmap-class"></a>Classe CAtlMap

Essa classe fornece métodos para criar e gerenciar um objeto de mapa.

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

*KTraits*<br/>
O código usado para copiar ou mover elementos-chave. Ver [classe CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

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
|[Classe CAtlMap::CPair](#cpair_class)|Uma classe que contém os elementos de chave e valor.|

### <a name="cpair-data-members"></a>Membros de dados CPair

|Nome|Descrição|
|----------|-----------------|
|[CPair::m_key](#m_key)|O membro de dados armazenar o elemento-chave.|
|[CPair::m_value](#m_value)|O membro de dados armazenar o elemento de valor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::CAtlMap](#catlmap)|O construtor.|
|[CAtlMap:: ~ CAtlMap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::AssertValid](#assertvalid)|Chame esse método para fazer com que uma declaração, se o `CAtlMap` não é válido.|
|[CAtlMap::DisableAutoRehash](#disableautorehash)|Chame esse método para desabilitar refazendo automática do `CAtlMap` objeto.|
|[CAtlMap::EnableAutoRehash](#enableautorehash)|Chame esse método para habilitar refazendo automática do `CAtlMap` objeto.|
|[CAtlMap::GetAt](#getat)|Chame esse método para retornar o elemento em uma posição especificada no mapa.|
|[CAtlMap::GetCount](#getcount)|Chame esse método para recuperar o número de elementos no mapa.|
|[CAtlMap::GetHashTableSize](#gethashtablesize)|Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.|
|[CAtlMap::GetKeyAt](#getkeyat)|Chame esse método para recuperar a chave armazenada na posição determinada no `CAtlMap` objeto.|
|[CAtlMap::GetNext](#getnext)|Chame esse método para obter um ponteiro para o próximo elemento par armazenadas em do `CAtlMap` objeto.|
|[CAtlMap::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para a iteração.|
|[CAtlMap::GetNextKey](#getnextkey)|Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.|
|[CAtlMap::GetNextValue](#getnextvalue)|Chame esse método para obter o próximo valor da `CAtlMap` objeto.|
|[CAtlMap::GetStartPosition](#getstartposition)|Chame esse método para iniciar uma iteração de mapa.|
|[CAtlMap::GetValueAt](#getvalueat)|Chame esse método para recuperar o valor armazenado em uma posição especificada no `CAtlMap` objeto.|
|[CAtlMap::InitHashTable](#inithashtable)|Chame esse método para inicializar a tabela de hash.|
|[CAtlMap::IsEmpty](#isempty)|Chame esse método para testar se um objeto de mapa vazio.|
|[CAtlMap::Lookup](#lookup)|Chame esse método para pesquisar as chaves ou valores no `CAtlMap` objeto.|
|[CAtlMap::Rehash](#rehash)|Chame este método para rehash o `CAtlMap` objeto.|
|[CAtlMap::RemoveAll](#removeall)|Chame esse método para remover todos os elementos do `CAtlMap` objeto.|
|[CAtlMap::RemoveAtPos](#removeatpos)|Chame esse método para remover o elemento na posição determinada no `CAtlMap` objeto.|
|[CAtlMap::RemoveKey](#removekey)|Chame esse método para remover um elemento de `CAtlMap` objeto, de acordo com a chave.|
|[CAtlMap::SetAt](#setat)|Chame esse método para inserir um par de elementos no mapa.|
|[CAtlMap::SetOptimalLoad](#setoptimalload)|Chame esse método para definir a carga ideal do `CAtlMap` objeto.|
|[CAtlMap::SetValueAt](#setvalueat)|Chame esse método para alterar o valor armazenado em uma posição especificada no `CAtlMap` objeto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlMap::operator\[\]](catlmap-class.md#operator_at)|Substitui ou adiciona um novo elemento para o `CAtlMap`.|

## <a name="remarks"></a>Comentários

`CAtlMap` fornece suporte para uma matriz de mapeamento de qualquer tipo, gerenciando uma matriz não ordenada de elementos-chave e seus valores associados. Elementos (consistindo em uma chave e um valor) são armazenados usando um algoritmo de hash, permitindo que uma grande quantidade de dados sejam armazenados e recuperados com eficiência.

O *KTraits* e *VTraits* parâmetros são classes de características que contém qualquer código complementar necessário para copiar ou mover elementos.

Uma alternativa à `CAtlMap` é oferecido pelos [CRBMap](../../atl/reference/crbmap-class.md) classe. `CRBMap` também armazena pares chave/valor, mas exibe diferentes características de desempenho. O tempo necessário para inserir um item, pesquisar uma chave ou excluir uma chave de um `CRBMap` objeto é da ordem *log(n)*, onde *n* é o número de elementos. Para `CAtlMap`, todas essas operações normalmente levar um tempo constante, embora os cenários mais desfavoráveis possam ser da ordem *n*. Portanto, em um caso típico, `CAtlMap` é mais rápido.

A outra diferença entre `CRBMap` e `CAtlMap` se torna aparente quando a iteração através dos elementos armazenados. Em um `CRBMap`, os elementos são visitados em uma ordem classificada. Em um `CAtlMap`, os elementos não são ordenados e nenhuma ordem pode ser inferida.

Quando um pequeno número de elementos precisa ser armazenados, considere o uso de [CSimpleMap](../../atl/reference/csimplemap-class.md) classe em vez disso.

Para obter mais informações, consulte [Classes de coleção ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

##  <a name="assertvalid"></a>  CAtlMap::AssertValid

Chame esse método para fazer com que uma declaração, se o `CAtlMap` objeto não é válido.

```
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Em compilações de depuração, esse método fará com que uma declaração se o `CAtlMap` objeto não é válido.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="catlmap"></a>  CAtlMap::CAtlMap

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
O número de compartimentos fornece ponteiros para os elementos armazenados. Consulte comentários mais adiante neste tópico para obter uma explicação de compartimentos.

*fOptimalLoad*<br/>
A taxa de carga ideal.

*fLoThreshold*<br/>
O limite inferior para a taxa de carga.

*fHiThreshold*<br/>
O limite superior para a taxa de carga.

*nBlockSize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

`CAtlMap` referencia todos os seus elementos armazenados primeiro criando um índice usando um algoritmo de hash na chave. Esse índice faz referência a um "bin" que contém um ponteiro para os elementos armazenados. Se o compartimento já está em uso, uma lista vinculada é criada para acessar os elementos subsequentes. Como percorrer uma lista é mais lento do que acessar diretamente o elemento correto e, portanto, a estrutura do mapa deve equilibrar os requisitos de armazenamento em relação ao desempenho. Os parâmetros padrão foram escolhidos para dar bons resultados na maioria dos casos.

A taxa de carga é a proporção do número de compartimentos para o número de elementos armazenados no objeto de mapa. Quando a estrutura do mapa é recalculada, o *fOptimalLoad* valor do parâmetro será usado para calcular o número de compartimentos necessárias. Esse valor pode ser alterado usando o [CAtlMap::SetOptimalLoad](#setoptimalload) método.

O *fLoThreshold* parâmetro é o menor valor que a taxa de carga pode atingir antes `CAtlMap` recalculará o tamanho ideal do mapa.

O *fHiThreshold* parâmetro é o valor superior que a taxa de carga pode atingir antes do `CAtlMap` objeto recalculará o tamanho ideal do mapa.

Esse processo de recálculo (conhecido como refazendo o hash) está habilitado por padrão. Se você quiser desabilitar esse processo, talvez, quando inserir uma grande quantidade de dados ao mesmo tempo, chame o [CAtlMap::DisableAutoRehash](#disableautorehash) método. Reativá-la com o [CAtlMap::EnableAutoRehash](#enableautorehash) método.

O *nBlockSize* parâmetro é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

Antes de todos os dados podem ser armazenados, é necessário inicializar a tabela de hash com uma chamada para [CAtlMap::InitHashTable](#inithashtable).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#72](../../atl/codesnippet/cpp/catlmap-class_1.cpp)]

##  <a name="dtor"></a>  CAtlMap:: ~ CAtlMap

O destruidor.

```
~CAtlMap() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados.

##  <a name="cpair_class"></a>  Classe CAtlMap::CPair

Uma classe que contém os elementos de chave e valor.

```
class CPair : public __POSITION
```

### <a name="remarks"></a>Comentários

Essa classe é usada pelos métodos [CAtlMap::GetNext](#getnext) e [CAtlMap::Lookup](#lookup) para acessar os elementos de chave e o valor armazenados na estrutura de mapeamento.

##  <a name="disableautorehash"></a>  CAtlMap::DisableAutoRehash

Chame esse método para desabilitar refazendo automática do `CAtlMap` objeto.

```
void DisableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando refazendo automático está habilitado (que é o padrão), o número de compartimentos na tabela de hash será automaticamente recalculado se o valor de carga (a taxa do número de compartimentos para o número de elementos armazenados na matriz) excede o valor máximo ou mínimo especificado no momento em que o mapa foi criado.

`DisableAutoRehash` é mais útil quando um grande número de elementos será adicionado ao mapa de uma só vez. Em vez de disparar o processo rehashing toda vez que os limites são excedidos, é mais eficiente chamar `DisableAutoRehash`, adicione os elementos e, finalmente, chame [CAtlMap::EnableAutoRehash](#enableautorehash).

##  <a name="enableautorehash"></a>  CAtlMap::EnableAutoRehash

Chame esse método para habilitar refazendo automática do `CAtlMap` objeto.

```
void EnableAutoRehash() throw();
```

### <a name="remarks"></a>Comentários

Quando refazendo automático está habilitado (que é o padrão), o número de compartimentos na tabela de hash será automaticamente recalculado se o valor de carga (a taxa do número de compartimentos para o número de elementos armazenados na matriz) excede o valor máximo ou mínimo especificado no momento em que o mapa é criado.

`EnableAutoRefresh` é mais frequentemente usado após uma chamada para [CAtlMap::DisableAutoRehash](#disableautorehash).

##  <a name="getat"></a>  CAtlMap::GetAt

Chame esse método para retornar o elemento em uma posição especificada no mapa.

```
void GetAt(
    POSITION pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;

CPair* GetAt(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*key*<br/>
Parâmetro de modelo especificando o tipo de chave do mapa.

*value*<br/>
Parâmetro de modelo que especifica o tipo de valor do mapa.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o par atual de elementos de chave/valor armazenados no mapa.

### <a name="remarks"></a>Comentários

Em compilações de depuração, um erro de asserção ocorrerá se *pos* é igual a NULL.

##  <a name="getcount"></a>  CAtlMap::GetCount

Chame esse método para recuperar o número de elementos no mapa.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de elementos no objeto de mapa. Um único elemento é um par chave/valor.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="gethashtablesize"></a>  CAtlMap::GetHashTableSize

Chame esse método para determinar o número de compartimentos na tabela de hash do mapa.

```
UINT GetHashTableSize() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de compartimentos na tabela de hash. Ver [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

##  <a name="getkeyat"></a>  CAtlMap::GetKeyAt

Chame esse método para recuperar a chave armazenada na posição determinada no `CAtlMap` objeto.

```
const K& GetKeyAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a chave armazenada na posição determinada no `CAtlMap` objeto.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="getnext"></a>  CAtlMap::GetNext

Chame esse método para obter um ponteiro para o próximo elemento par armazenadas em do `CAtlMap` objeto.

```
CPair* GetNext(POSITION& pos) throw();
const CPair* GetNext(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o próximo par de elementos de chave/valor armazenados no mapa. O *pos* posição é atualizado após cada chamada. Se o elemento recuperado é o último no mapa, *pos* é definido como NULL.

##  <a name="getnextassoc"></a>  CAtlMap::GetNextAssoc

Obtém o próximo elemento para a iteração.

```
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*key*<br/>
Parâmetro de modelo especificando o tipo de chave do mapa.

*value*<br/>
Parâmetro de modelo que especifica o tipo de valor do mapa.

### <a name="remarks"></a>Comentários

O *pos* posição é atualizado após cada chamada. Se o elemento recuperado é o último no mapa, *pos* é definido como NULL.

##  <a name="getnextkey"></a>  CAtlMap::GetNextKey

Chame esse método para recuperar a próxima chave do `CAtlMap` objeto.

```
const K& GetNextKey(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para a próxima chave no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não existem mais entradas no mapa, o contador de posição é definido como NULL.

##  <a name="getnextvalue"></a>  CAtlMap::GetNextValue

Chame esse método para obter o próximo valor da `CAtlMap` objeto.

```
V& GetNextValue(POSITION& pos) throw();
const V& GetNextValue(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para o próximo valor no mapa.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não existem mais entradas no mapa, o contador de posição é definido como NULL.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="getstartposition"></a>  CAtlMap::GetStartPosition

Chame esse método para iniciar uma iteração de mapa.

```
POSITION GetStartPosition() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna que a posição inicial, ou nulo será retornado se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

Chamada para esse método para iniciar uma iteração de mapa, retornando uma posição de valor que pode ser passada para o `GetNextAssoc` método.

> [!NOTE]
>  A sequência de iteração não é previsível

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="getvalueat"></a>  CAtlMap::GetValueAt

Chame esse método para recuperar o valor armazenado em uma posição especificada no `CAtlMap` objeto.

```
V& GetValueAt(POSITION pos) throw();
const V& GetValueAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="return-value"></a>Valor de retorno

Retorna uma referência ao valor armazenado na posição determinada no `CAtlMap` objeto.

##  <a name="inithashtable"></a>  CAtlMap::InitHashTable

Chame esse método para inicializar a tabela de hash.

```
bool InitHashTable(
    UINT nBins,
    bool bAllocNow = true);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O número de compartimentos usado pela tabela de hash. Ver [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

*bAllocNow*<br/>
Uma indicação de sinalizador, quando a memória deve ser alocada.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em inicialização bem-sucedida, falso em caso de falha.

### <a name="remarks"></a>Comentários

`InitHashTable` deve ser chamado antes de todos os elementos são armazenados na tabela de hash.  Se esse método não for chamado explicitamente, ele será chamado automaticamente na primeira vez que um elemento é adicionado usando a contagem do compartimento especificada pelo `CAtlMap` construtor.  Caso contrário, o mapa será inicializado usando a nova contagem de bin especificada pelo *nBins* parâmetro.

Se o *bAllocNow* parâmetro for falso, a memória exigida pela tabela de hash não será alocada até que o primeiro é necessário. Isso pode ser útil se for certeza se o mapa será usado.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="isempty"></a>  CAtlMap::IsEmpty

Chame esse método para testar se um objeto de mapa vazio.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o mapa estiver vazio, FALSE caso contrário.

##  <a name="kinargtype"></a>  CAtlMap::KINARGTYPE

Tipo usado quando uma chave é passada como um argumento de entrada.

```
typedef KTraits::INARGTYPE KINARGTYPE;
```

##  <a name="koutargtype"></a>  CAtlMap::KOUTARGTYPE

Tipo usado quando uma chave é retornada como um argumento de saída.

```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```

##  <a name="lookup"></a>  CAtlMap::Lookup

Chame esse método para pesquisar as chaves ou valores no `CAtlMap` objeto.

```
bool Lookup(KINARGTYPE key, VOUTARGTYPE value) const;
const CPair* Lookup(KINARGTYPE key) const throw();
CPair* Lookup(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a chave que identifica o elemento a ser pesquisado.

*value*<br/>
Variável que recebe o valor pesquisado.

### <a name="return-value"></a>Valor de retorno

A primeira forma do método retornará true se a chave for encontrada, caso contrário, false. Os formulários de segundo e terceiro retornam um ponteiro para um [CPair](#cpair_class) que pode ser usado como uma posição para chamadas ao [CAtlMap::GetNext](#getnext) e assim por diante.

### <a name="remarks"></a>Comentários

`Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa que contém uma chave que corresponda exatamente o parâmetro de chave especificado.

##  <a name="operator_at"></a>  CAtlMap::operator \[\]

Substitui ou adiciona um novo elemento para o `CAtlMap`.

```
V& operator[](kinargtype key) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave do elemento para adicionar ou substituir.

### <a name="return-value"></a>Valor de retorno

Retorna uma referência para o valor associado com a chave especificada.

### <a name="example"></a>Exemplo

Se a chave já existir, o elemento é substituído. Se a chave não existir, um novo elemento será adicionado. Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="rehash"></a>  CAtlMap::Rehash

Chame este método para rehash o `CAtlMap` objeto.

```
void Rehash(UINT nBins = 0);
```

### <a name="parameters"></a>Parâmetros

*nBins*<br/>
O novo número de compartimentos para usar na tabela de hash. Ver [CAtlMap::CAtlMap](#catlmap) para obter uma explicação.

### <a name="remarks"></a>Comentários

Se *nBins* é 0, `CAtlMap` calcula um número razoável, com base no número de elementos no mapa e a configuração ideal de carga. Normalmente, o processo de rehashing é automático, mas se [CAtlMap::DisableAutoRehash](#disableautorehash) tiver sido chamado, esse método efetuará o redimensionamento necessário.

##  <a name="removeall"></a>  CAtlMap::RemoveAll

Chame esse método para remover todos os elementos do `CAtlMap` objeto.

```
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Limpa o `CAtlMap` objeto, liberando a memória usada para armazenar os elementos.

##  <a name="removeatpos"></a>  CAtlMap::RemoveAtPos

Chame esse método para remover o elemento na posição determinada no `CAtlMap` objeto.

```
void RemoveAtPos(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

### <a name="remarks"></a>Comentários

Remove o par chave/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A posição é referenciado por *pos* se torna inválido e, enquanto a posição de todos os outros elementos no mapa permanece válida, não necessariamente fazem reter a mesma ordem.

##  <a name="removekey"></a>  CAtlMap::RemoveKey

Chame esse método para remover um elemento de `CAtlMap` objeto, de acordo com a chave.

```
bool RemoveKey(KINARGTYPE key) throw();
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave correspondente para o par de elementos que você deseja remover.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se a chave é encontrada e removida, falso em caso de falha.

### <a name="example"></a>Exemplo

Veja o exemplo de [CAtlMap::CAtlMap](#catlmap).

##  <a name="setat"></a>  CAtlMap::SetAt

Chame esse método para inserir um par de elementos no mapa.

```
POSITION SetAt(
    KINARGTYPE key,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
O valor da chave para adicionar ao `CAtlMap` objeto.

*value*<br/>
O valor a ser adicionado para o `CAtlMap` objeto.

### <a name="return-value"></a>Valor de retorno

Retorna a posição do par chave/valor de elemento no `CAtlMap` objeto.

### <a name="remarks"></a>Comentários

`SetAt` substitui um elemento existente, se uma chave correspondente for encontrada. Se a chave não for encontrada, é criado um novo par chave/valor.

##  <a name="setoptimalload"></a>  CAtlMap::SetOptimalLoad

Chame esse método para definir a carga ideal do `CAtlMap` objeto.

```
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

Este método redefine o valor ideal de carga para o `CAtlMap` objeto. Ver [CAtlMap::CAtlMap](#catlmap) para uma discussão sobre os vários parâmetros. Se *bRehashNow* for true e o número de elementos está fora os valores mínimo e máximo, a tabela de hash é recalculada.

##  <a name="setvalueat"></a>  CAtlMap::SetValueAt

Chame esse método para alterar o valor armazenado em uma posição especificada no `CAtlMap` objeto.

```
void SetValueAt(
    POSITION pos,
    VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*POS*<br/>
O contador de posição, retornado por uma chamada anterior a [CAtlMap::GetNextAssoc](#getnextassoc) ou [CAtlMap::GetStartPosition](#getstartposition).

*value*<br/>
O valor a ser adicionado para o `CAtlMap` objeto.

### <a name="remarks"></a>Comentários

Altera o elemento de valor armazenado na posição determinada no `CAtlMap` objeto.

##  <a name="vinargtype"></a>  CAtlMap::VINARGTYPE

Tipo usado quando um valor é passado como um argumento de entrada.

```
typedef VTraits::INARGTYPE VINARGTYPE;
```

##  <a name="voutargtype"></a>  CAtlMap::VOUTARGTYPE

Tipo usado quando um valor é passado como um argumento de saída.

```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```

##  <a name="m_key"></a>  CAtlMap::CPair::m_key

O membro de dados armazenar o elemento-chave.

```
const K m_key;
```

### <a name="parameters"></a>Parâmetros

*K*<br/>
O tipo de elemento-chave.

##  <a name="m_value"></a>  CAtlMap::CPair::m_value

O membro de dados armazenar o elemento de valor.

```
V  m_value;
```

### <a name="parameters"></a>Parâmetros

*V*<br/>
O tipo de elemento de valor.

## <a name="see-also"></a>Consulte também

[Exemplo de letreiro](../../visual-cpp-samples.md)<br/>
[Exemplo de UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
