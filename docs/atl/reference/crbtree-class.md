---
title: Classe CRBTree
ms.date: 11/04/2016
f1_keywords:
- CRBTree
- ATLCOLL/ATL::CRBTree
- ATLCOLL/ATL::CRBTree::KINARGTYPE
- ATLCOLL/ATL::CRBTree::KOUTARGTYPE
- ATLCOLL/ATL::CRBTree::VINARGTYPE
- ATLCOLL/ATL::CRBTree::VOUTARGTYPE
- ATLCOLL/ATL::CRBTree::FindFirstKeyAfter
- ATLCOLL/ATL::CRBTree::GetAt
- ATLCOLL/ATL::CRBTree::GetCount
- ATLCOLL/ATL::CRBTree::GetHeadPosition
- ATLCOLL/ATL::CRBTree::GetKeyAt
- ATLCOLL/ATL::CRBTree::GetNext
- ATLCOLL/ATL::CRBTree::GetNextAssoc
- ATLCOLL/ATL::CRBTree::GetNextKey
- ATLCOLL/ATL::CRBTree::GetNextValue
- ATLCOLL/ATL::CRBTree::GetPrev
- ATLCOLL/ATL::CRBTree::GetTailPosition
- ATLCOLL/ATL::CRBTree::GetValueAt
- ATLCOLL/ATL::CRBTree::IsEmpty
- ATLCOLL/ATL::CRBTree::RemoveAll
- ATLCOLL/ATL::CRBTree::RemoveAt
- ATLCOLL/ATL::CRBTree::SetValueAt
helpviewer_keywords:
- CRBTree class
ms.assetid: a1b1cb63-38e4-4fc2-bb28-f774d1721760
ms.openlocfilehash: 7b8e47b5cd0ac278711947abc867956333371be3
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833485"
---
# <a name="crbtree-class"></a>Classe CRBTree

Essa classe fornece métodos para criar e utilizar uma árvore vermelha preta.

## <a name="syntax"></a>Sintaxe

```
template <typename K,
          typename V,
          class KTraits = CElementTraits<K>,
          class VTraits = CElementTraits<V>>
class CRBTree
```

#### <a name="parameters"></a>parâmetros

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
|[CRBTree::KINARGTYPE](#kinargtype)|Tipo usado quando uma chave é passada como um argumento de entrada.|
|[CRBTree::KOUTARGTYPE](#koutargtype)|Tipo usado quando uma chave é retornada como um argumento de saída.|
|[CRBTree::VINARGTYPE](#vinargtype)|Tipo usado quando um valor é passado como um argumento de entrada.|
|[CRBTree::VOUTARGTYPE](#voutargtype)|Tipo usado quando um valor é passado como um argumento de saída.|

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[Classe CRBTree:: CPair](#cpair_class)|Uma classe que contém os elementos de chave e valor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBTree:: ~ CRBTree](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBTree::FindFirstKeyAfter](#findfirstkeyafter)|Chame esse método para localizar a posição do elemento que usa a próxima chave disponível.|
|[CRBTree::GetAt](#getat)|Chame esse método para obter o elemento em uma determinada posição na árvore.|
|[CRBTree:: GetCount](#getcount)|Chame esse método para obter o número de elementos na árvore.|
|[CRBTree::GetHeadPosition](#getheadposition)|Chame esse método para obter o valor da posição para o elemento no cabeçalho da árvore.|
|[CRBTree::GetKeyAt](#getkeyat)|Chame esse método para obter a chave de uma determinada posição na árvore.|
|[CRBTree:: GetNext](#getnext)|Chame esse método para obter um ponteiro para um elemento armazenado no `CRBTree` objeto e avançar a posição para o próximo elemento.|
|[CRBTree::GetNextAssoc](#getnextassoc)|Chame esse método para obter a chave e o valor de um elemento armazenado no mapa e avançar a posição para o próximo elemento.|
|[CRBTree::GetNextKey](#getnextkey)|Chame esse método para obter a chave de um elemento armazenado na árvore e avançar a posição para o próximo elemento.|
|[CRBTree:: GetNextValue](#getnextvalue)|Chame esse método para obter o valor de um elemento armazenado na árvore e avançar a posição para o próximo elemento.|
|[CRBTree:: getant](#getprev)|Chame esse método para obter um ponteiro para um elemento armazenado no `CRBTree` objeto e, em seguida, atualize a posição para o elemento anterior.|
|[CRBTree::GetTailPosition](#gettailposition)|Chame esse método para obter o valor da posição para o elemento na parte final da árvore.|
|[CRBTree::GetValueAt](#getvalueat)|Chame esse método para recuperar o valor armazenado em uma determinada posição no `CRBTree` objeto.|
|[CRBTree:: IsEmpty](#isempty)|Chame esse método para testar um objeto de árvore vazio.|
|[CRBTree:: RemoveAll](#removeall)|Chame esse método para remover todos os elementos do `CRBTree` objeto.|
|[CRBTree:: RemoveAt](#removeat)|Chame esse método para remover o elemento na posição especificada no `CRBTree` objeto.|
|[CRBTree::SetValueAt](#setvalueat)|Chame esse método para alterar o valor armazenado em uma determinada posição no `CRBTree` objeto.|

## <a name="remarks"></a>Comentários

Uma árvore vermelha-preta é uma árvore de pesquisa binária que usa um bit extra de informações por nó para garantir que ela permaneça "equilibrada", ou seja, a altura da árvore não cresça desproporcionalmente grande e afeta o desempenho.

Essa classe de modelo foi projetada para ser usada por [CRBMap](../../atl/reference/crbmap-class.md) e [CRBMultiMap](../../atl/reference/crbmultimap-class.md). A maior parte dos métodos que compõem essas classes derivadas é fornecida pelo `CRBTree` .

Para obter uma discussão mais completa sobre as várias classes de coleção e seus recursos e características de desempenho, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="crbtreecpair-class"></a><a name="cpair_class"></a> Classe CRBTree:: CPair

Uma classe que contém os elementos de chave e valor.

```
class CPair : public __POSITION
```

### <a name="remarks"></a>Comentários

Essa classe é usada pelos métodos [CRBTree:: GetAt](#getat), [CRBTree:: GetNext](#getnext)e [CRBTree:: getant](#getprev) para acessar os elementos de chave e valor armazenados na estrutura de árvore.

Os membros são os seguintes:

|Membro de dados|Descrição|
|-|-|
|`m_key`|O membro de dados que armazena o elemento de chave.|
|`m_value`|O membro de dados que armazena o elemento de valor.|

## <a name="crbtreecrbtree"></a><a name="dtor"></a> CRBTree:: ~ CRBTree

O destruidor.

```
~CRBTree() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CRBTree:: RemoveAll](#removeall) para excluir todos os elementos.

## <a name="crbtreefindfirstkeyafter"></a><a name="findfirstkeyafter"></a> CRBTree::FindFirstKeyAfter

Chame esse método para localizar a posição do elemento que usa a próxima chave disponível.

```
POSITION FindFirstKeyAfter(KINARGTYPE key) const throw();
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Um valor de chave.

### <a name="return-value"></a>Valor Retornado

Retorna o valor da posição do elemento que usa a próxima chave disponível. Se não houver mais elementos, NULL será retornado.

### <a name="remarks"></a>Comentários

Esse método facilita a passagem da árvore sem a necessidade de calcular os valores de posição com antecedência.

## <a name="crbtreegetat"></a><a name="getat"></a> CRBTree::GetAt

Chame esse método para obter o elemento em uma determinada posição na árvore.

```
CPair* GetAt(POSITION pos) throw();
const CPair* GetAt(POSITION pos) const throw();
void GetAt(POSITION pos, KOUTARGTYPE key, VOUTARGTYPE value) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor da posição.

*chave*<br/>
A variável que recebe a chave.

*value*<br/>
A variável que recebe o valor.

### <a name="return-value"></a>Valor Retornado

Os dois primeiros formulários retornam um ponteiro para um [CPair](#cpair_class). O terceiro formulário Obtém uma chave e um valor para a posição fornecida.

### <a name="remarks"></a>Comentários

O valor da posição pode ser determinado anteriormente com uma chamada para um método como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: GetTailPosition](#gettailposition).

Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

## <a name="crbtreegetcount"></a><a name="getcount"></a> CRBTree:: GetCount

Chame esse método para obter o número de elementos na árvore.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de elementos (cada par chave/valor é um elemento) armazenado na árvore.

## <a name="crbtreegetheadposition"></a><a name="getheadposition"></a> CRBTree::GetHeadPosition

Chame esse método para obter o valor da posição para o elemento no cabeçalho da árvore.

```
POSITION GetHeadPosition() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o valor da posição do elemento no início da árvore.

### <a name="remarks"></a>Comentários

O valor retornado por `GetHeadPosition` pode ser usado com métodos como [CRBTree:: GetKeyAt](#getkeyat) ou [CRBTree:: GetNext](#getnext) para percorrer a árvore e recuperar valores.

## <a name="crbtreegetkeyat"></a><a name="getkeyat"></a> CRBTree::GetKeyAt

Chame esse método para obter a chave de uma determinada posição na árvore.

```
const K& GetKeyAt(POSITION pos) const throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor da posição.

### <a name="return-value"></a>Valor Retornado

Retorna a chave armazenada na posição *pos* na árvore.

### <a name="remarks"></a>Comentários

Se o *PDV* não for um valor de posição válido, os resultados serão imprevisíveis. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

## <a name="crbtreegetnext"></a><a name="getnext"></a> CRBTree:: GetNext

Chame esse método para obter um ponteiro para um elemento armazenado no `CRBTree` objeto e avançar a posição para o próximo elemento.

```
const CPair* GetNext(POSITION& pos) const throw();
CPair* GetNext(POSITION& pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor Retornado

Retorna um ponteiro para o próximo valor [CPair](#cpair_class) na árvore.

### <a name="remarks"></a>Comentários

O contador de posição de *PDV* é atualizado após cada chamada. Se o elemento recuperado for o último na árvore, *pos* será definido como NULL.

## <a name="crbtreegetnextassoc"></a><a name="getnextassoc"></a> CRBTree::GetNextAssoc

Chame esse método para obter a chave e o valor de um elemento armazenado no mapa e avançar a posição para o próximo elemento.

```cpp
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

*chave*<br/>
Parâmetro de modelo que especifica o tipo da chave da árvore.

*value*<br/>
Parâmetro de modelo que especifica o tipo do valor da árvore.

### <a name="remarks"></a>Comentários

O contador de posição de *PDV* é atualizado após cada chamada. Se o elemento recuperado for o último na árvore, *pos* será definido como NULL.

## <a name="crbtreegetnextkey"></a><a name="getnextkey"></a> CRBTree::GetNextKey

Chame esse método para obter a chave de um elemento armazenado na árvore e avançar a posição para o próximo elemento.

```
const K& GetNextKey(POSITION& pos) const throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor Retornado

Retorna uma referência à próxima chave na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como nulo.

## <a name="crbtreegetnextvalue"></a><a name="getnextvalue"></a> CRBTree:: GetNextValue

Chame esse método para obter o valor de um elemento armazenado na árvore e avançar a posição para o próximo elemento.

```
const V& GetNextValue(POSITION& pos) const throw();
V& GetNextValue(POSITION& pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor Retornado

Retorna uma referência ao próximo valor na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como nulo.

## <a name="crbtreegetprev"></a><a name="getprev"></a> CRBTree:: getant

Chame esse método para obter um ponteiro para um elemento armazenado no `CRBTree` objeto e, em seguida, atualize a posição para o elemento anterior.

```
const CPair* GetPrev(POSITION& pos) const throw();
CPair* GetPrev(POSITION& pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor Retornado

Retorna um ponteiro para o valor [CPair](#cpair_class) anterior armazenado na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como nulo.

## <a name="crbtreegettailposition"></a><a name="gettailposition"></a> CRBTree::GetTailPosition

Chame esse método para obter o valor da posição para o elemento na parte final da árvore.

```
POSITION GetTailPosition() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o valor da posição do elemento na parte final da árvore.

### <a name="remarks"></a>Comentários

O valor retornado por `GetTailPosition` pode ser usado com métodos como [CRBTree:: GetKeyAt](#getkeyat) ou [CRBTree:: getanterior](#getprev) para atravessar a árvore e recuperar valores.

## <a name="crbtreegetvalueat"></a><a name="getvalueat"></a> CRBTree::GetValueAt

Chame esse método para recuperar o valor armazenado em uma determinada posição no `CRBTree` objeto.

```
const V& GetValueAt(POSITION pos) const throw();
V& GetValueAt(POSITION pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor Retornado

Retorna uma referência ao valor armazenado na posição especificada no `CRBTree` objeto.

## <a name="crbtreeisempty"></a><a name="isempty"></a> CRBTree:: IsEmpty

Chame esse método para testar um objeto de árvore vazio.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna TRUE se a árvore estiver vazia; caso contrário, FALSE.

## <a name="crbtreekinargtype"></a><a name="kinargtype"></a> CRBTree::KINARGTYPE

Tipo usado quando uma chave é passada como um argumento de entrada.

```
typedef KTraits::INARGTYPE KINARGTYPE;
```

## <a name="crbtreekoutargtype"></a><a name="koutargtype"></a> CRBTree::KOUTARGTYPE

Tipo usado quando uma chave é retornada como um argumento de saída.

```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```

## <a name="crbtreeremoveall"></a><a name="removeall"></a> CRBTree:: RemoveAll

Chame esse método para remover todos os elementos do `CRBTree` objeto.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Limpa o `CRBTree` objeto, liberando a memória usada para armazenar os elementos.

## <a name="crbtreeremoveat"></a><a name="removeat"></a> CRBTree:: RemoveAt

Chame esse método para remover o elemento na posição especificada no `CRBTree` objeto.

```cpp
void RemoveAt(POSITION pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

### <a name="remarks"></a>Comentários

Remove o par de chave/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A posição referenciada pelo *PDV* torna-se inválida e, embora a posição de quaisquer outros elementos na árvore permaneça válida, elas não retêm necessariamente a mesma ordem.

## <a name="crbtreesetvalueat"></a><a name="setvalueat"></a> CRBTree::SetValueAt

Chame esse método para alterar o valor armazenado em uma determinada posição no `CRBTree` objeto.

```cpp
void SetValueAt(POSITION pos, VINARGTYPE value);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O contador de posição, retornado por uma chamada anterior para métodos como [CRBTree:: GetHeadPosition](#getheadposition) ou [CRBTree:: FindFirstKeyAfter](#findfirstkeyafter).

*value*<br/>
O valor a ser adicionado ao `CRBTree` objeto.

### <a name="remarks"></a>Comentários

Altera o elemento de valor armazenado na posição especificada no `CRBTree` objeto.

## <a name="crbtreevinargtype"></a><a name="vinargtype"></a> CRBTree::VINARGTYPE

Tipo usado quando um valor é passado como um argumento de entrada.

```
typedef VTraits::INARGTYPE VINARGTYPE;
```

## <a name="crbtreevoutargtype"></a><a name="voutargtype"></a> CRBTree::VOUTARGTYPE

Tipo usado quando um valor é passado como um argumento de saída.

```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
