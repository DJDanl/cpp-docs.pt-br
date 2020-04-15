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
ms.openlocfilehash: 56c9db9d1a7bcd7fe2a2647d8b1339d223c4b66b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331237"
---
# <a name="crbtree-class"></a>Classe CRBTree

Esta classe fornece métodos para criar e utilizar uma árvore Rubro-Negra.

## <a name="syntax"></a>Sintaxe

```
template <typename K,
          typename V,
          class KTraits = CElementTraits<K>,
          class VTraits = CElementTraits<V>>
class CRBTree
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
|[CRBTree::KINARGTYPE](#kinargtype)|Digite usado quando uma chave é passada como um argumento de entrada.|
|[CRBTree::KOUTARGTYPE](#koutargtype)|Digite usado quando uma chave é devolvida como um argumento de saída.|
|[CRBTree::VINARGTYPE](#vinargtype)|Digite usado quando um valor é passado como um argumento de entrada.|
|[CRBTree::VOUTARGTYPE](#voutargtype)|Digite usado quando um valor é passado como um argumento de saída.|

### <a name="public-classes"></a>Classes públicas

|Nome|Descrição|
|----------|-----------------|
|[CRBTree:::CPair Class](#cpair_class)|Uma classe contendo os elementos chave e valor.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBTree:::~CRBTree](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRBtree::FindFirstKeyAfter](#findfirstkeyafter)|Chame este método para encontrar a posição do elemento que usa a próxima tecla disponível.|
|[CRBtree::Getat](#getat)|Chame este método para obter o elemento em uma determinada posição na árvore.|
|[CRBTree::GetCount](#getcount)|Chame este método para obter o número de elementos na árvore.|
|[CRBTree:::GetHeadPosition](#getheadposition)|Chame este método para obter o valor de posição para o elemento na cabeça da árvore.|
|[CRBtree::Getkeyat](#getkeyat)|Chame este método para obter a chave de uma determinada posição na árvore.|
|[CRBTree::GetNext](#getnext)|Chame este método para obter um ponteiro `CRBTree` para um elemento armazenado no objeto e avançar a posição para o próximo elemento.|
|[CRBTree::GetNextAssoc](#getnextassoc)|Chame este método para obter a chave e o valor de um elemento armazenado no mapa e avançar a posição para o próximo elemento.|
|[CRBtree::GetNextKey](#getnextkey)|Chame este método para obter a chave de um elemento armazenado na árvore e avançar a posição para o próximo elemento.|
|[CRBTree::GetNextValue](#getnextvalue)|Chame este método para obter o valor de um elemento armazenado na árvore e avançar a posição para o próximo elemento.|
|[CRBTree:::GetPrev](#getprev)|Chame este método para obter um ponteiro `CRBTree` para um elemento armazenado no objeto e, em seguida, atualize a posição para o elemento anterior.|
|[CRBTree:::GetTailPosition](#gettailposition)|Chame este método para obter o valor de posição para o elemento na cauda da árvore.|
|[CRBtree::GetValueAt](#getvalueat)|Chame este método para recuperar o valor `CRBTree` armazenado em uma determinada posição no objeto.|
|[CRBTree:::IsEmpty](#isempty)|Chame este método para testar um objeto de árvore vazio.|
|[CRBTree:::RemoveAll](#removeall)|Chame este método para remover `CRBTree` todos os elementos do objeto.|
|[CRBtree:::removeat](#removeat)|Chame este método para remover o elemento `CRBTree` na posição dada no objeto.|
|[CRBtree::setvalueat](#setvalueat)|Chame este método para alterar o valor `CRBTree` armazenado em uma determinada posição no objeto.|

## <a name="remarks"></a>Comentários

Uma árvore Rubro-Negra é uma árvore de pesquisa binária que usa um pouco extra de informação por nó para garantir que ela permaneça "equilibrada", ou seja, a altura da árvore não cresça desproporcionalmente grande e afete o desempenho.

Esta classe de modelo foi projetada para ser usada pelo [CRBMap](../../atl/reference/crbmap-class.md) e [pelo CRBMultiMap](../../atl/reference/crbmultimap-class.md). A maior parte dos métodos que compõem essas `CRBTree`classes derivadas são fornecidas por .

Para uma discussão mais completa das várias classes de coleta e suas características e características de desempenho, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="crbtreecpair-class"></a><a name="cpair_class"></a>CRBTree:::CPair Class

Uma classe contendo os elementos chave e valor.

```
class CPair : public __POSITION
```

### <a name="remarks"></a>Comentários

Essa classe é usada pelos métodos [CRBTree:::GetAt](#getat), [CRBTree::GetNext](#getnext)e [CRBTree::GetPrev](#getprev) para acessar os elementos de valor e chave armazenados na estrutura da árvore.

Os membros são os seguintes:

|||
|-|-|
|`m_key`|O membro de dados armazena ndo o elemento-chave.|
|`m_value`|O membro de dados armazena ndo o elemento de valor.|

## <a name="crbtreecrbtree"></a><a name="dtor"></a>CRBTree:::~CRBTree

O destruidor.

```
~CRBTree() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados. Chama [CRBTree::RemoveAll](#removeall) para excluir todos os elementos.

## <a name="crbtreefindfirstkeyafter"></a><a name="findfirstkeyafter"></a>CRBtree::FindFirstKeyAfter

Chame este método para encontrar a posição do elemento que usa a próxima tecla disponível.

```
POSITION FindFirstKeyAfter(KINARGTYPE key) const throw();
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Um valor de chave.

### <a name="return-value"></a>Valor retornado

Retorna o valor de posição do elemento que usa a próxima tecla disponível. Se não houver mais elementos, NULL é devolvido.

### <a name="remarks"></a>Comentários

Este método facilita a travessia da árvore sem ter que calcular os valores de posição antecipadamente.

## <a name="crbtreegetat"></a><a name="getat"></a>CRBtree::Getat

Chame este método para obter o elemento em uma determinada posição na árvore.

```
CPair* GetAt(POSITION pos) throw();
const CPair* GetAt(POSITION pos) const throw();
void GetAt(POSITION pos, KOUTARGTYPE key, VOUTARGTYPE value) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor da posição.

*Chave*<br/>
A variável que recebe a chave.

*value*<br/>
A variável que recebe o valor.

### <a name="return-value"></a>Valor retornado

As duas primeiras formas retornam um ponteiro para um [CPair](#cpair_class). A terceira forma obtém uma chave e um valor para a posição dada.

### <a name="remarks"></a>Comentários

O valor da posição pode ser previamente determinado com uma chamada para um método como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::GetTailPosition](#gettailposition).

Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

## <a name="crbtreegetcount"></a><a name="getcount"></a>CRBTree::GetCount

Chame este método para obter o número de elementos na árvore.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos (cada par de tecla/valor é um elemento) armazenado na árvore.

## <a name="crbtreegetheadposition"></a><a name="getheadposition"></a>CRBTree:::GetHeadPosition

Chame este método para obter o valor de posição para o elemento na cabeça da árvore.

```
POSITION GetHeadPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor de posição para o elemento na cabeça da árvore.

### <a name="remarks"></a>Comentários

O valor devolvido `GetHeadPosition` pode ser usado com métodos como [CRBTree::GetKeyAt](#getkeyat) ou [CRBTree::GetNext](#getnext) para atravessar a árvore e recuperar valores.

## <a name="crbtreegetkeyat"></a><a name="getkeyat"></a>CRBtree::Getkeyat

Chame este método para obter a chave de uma determinada posição na árvore.

```
const K& GetKeyAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor da posição.

### <a name="return-value"></a>Valor retornado

Retorna a chave armazenada na posição *pos* na árvore.

### <a name="remarks"></a>Comentários

Se *pos* não é um valor de posição válido, os resultados são imprevisíveis. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

## <a name="crbtreegetnext"></a><a name="getnext"></a>CRBTree::GetNext

Chame este método para obter um ponteiro `CRBTree` para um elemento armazenado no objeto e avançar a posição para o próximo elemento.

```
const CPair* GetNext(POSITION& pos) const throw();
CPair* GetNext(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o próximo valor [CPair](#cpair_class) na árvore.

### <a name="remarks"></a>Comentários

O contador de posição *pos* é atualizado após cada chamada. Se o elemento recuperado for o último na árvore, *pos* será definido como NULL.

## <a name="crbtreegetnextassoc"></a><a name="getnextassoc"></a>CRBTree::GetNextAssoc

Chame este método para obter a chave e o valor de um elemento armazenado no mapa e avançar a posição para o próximo elemento.

```
void GetNextAssoc(
    POSITION& pos,
    KOUTARGTYPE key,
    VOUTARGTYPE value) const;
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

*Chave*<br/>
Parâmetro de modelo especificando o tipo de chave da árvore.

*value*<br/>
Parâmetro de modelo especificando o tipo de valor da árvore.

### <a name="remarks"></a>Comentários

O contador de posição *pos* é atualizado após cada chamada. Se o elemento recuperado for o último na árvore, *pos* será definido como NULL.

## <a name="crbtreegetnextkey"></a><a name="getnextkey"></a>CRBtree::GetNextKey

Chame este método para obter a chave de um elemento armazenado na árvore e avançar a posição para o próximo elemento.

```
const K& GetNextKey(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor retornado

Retorna uma referência à próxima chave na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como NULL.

## <a name="crbtreegetnextvalue"></a><a name="getnextvalue"></a>CRBTree::GetNextValue

Chame este método para obter o valor de um elemento armazenado na árvore e avançar a posição para o próximo elemento.

```
const V& GetNextValue(POSITION& pos) const throw();
V& GetNextValue(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao próximo valor na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como NULL.

## <a name="crbtreegetprev"></a><a name="getprev"></a>CRBTree:::GetPrev

Chame este método para obter um ponteiro `CRBTree` para um elemento armazenado no objeto e, em seguida, atualize a posição para o elemento anterior.

```
const CPair* GetPrev(POSITION& pos) const throw();
CPair* GetPrev(POSITION& pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o valor [CPair](#cpair_class) anterior armazenado na árvore.

### <a name="remarks"></a>Comentários

Atualiza o contador de posição atual, *pos*. Se não houver mais entradas na árvore, o contador de posição será definido como NULL.

## <a name="crbtreegettailposition"></a><a name="gettailposition"></a>CRBTree:::GetTailPosition

Chame este método para obter o valor de posição para o elemento na cauda da árvore.

```
POSITION GetTailPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor de posição para o elemento na cauda da árvore.

### <a name="remarks"></a>Comentários

O valor devolvido `GetTailPosition` pode ser usado com métodos como [CRBTree::GetKeyAt](#getkeyat) ou [CRBTree::GetPrev](#getprev) para atravessar a árvore e recuperar valores.

## <a name="crbtreegetvalueat"></a><a name="getvalueat"></a>CRBtree::GetValueAt

Chame este método para recuperar o valor `CRBTree` armazenado em uma determinada posição no objeto.

```
const V& GetValueAt(POSITION pos) const throw();
V& GetValueAt(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="return-value"></a>Valor retornado

Retorna uma referência ao valor armazenado na `CRBTree` posição dada no objeto.

## <a name="crbtreeisempty"></a><a name="isempty"></a>CRBTree:::IsEmpty

Chame este método para testar um objeto de árvore vazio.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se a árvore estiver vazia, FALSA de outra forma.

## <a name="crbtreekinargtype"></a><a name="kinargtype"></a>CRBTree::KINARGTYPE

Digite usado quando uma chave é passada como um argumento de entrada.

```
typedef KTraits::INARGTYPE KINARGTYPE;
```

## <a name="crbtreekoutargtype"></a><a name="koutargtype"></a>CRBTree::KOUTARGTYPE

Digite usado quando uma chave é devolvida como um argumento de saída.

```
typedef KTraits::OUTARGTYPE KOUTARGTYPE;
```

## <a name="crbtreeremoveall"></a><a name="removeall"></a>CRBTree:::RemoveAll

Chame este método para remover `CRBTree` todos os elementos do objeto.

```
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Limpa o `CRBTree` objeto, liberando a memória usada para armazenar os elementos.

## <a name="crbtreeremoveat"></a><a name="removeat"></a>CRBtree:::removeat

Chame este método para remover o elemento `CRBTree` na posição dada no objeto.

```
void RemoveAt(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

### <a name="remarks"></a>Comentários

Remove o par de chaves/valor armazenado na posição especificada. A memória usada para armazenar o elemento é liberada. A POSIÇÃO referenciada por *pos* torna-se inválida, e embora a posição de quaisquer outros elementos na árvore permaneça válida, eles não necessariamente retêm a mesma ordem.

## <a name="crbtreesetvalueat"></a><a name="setvalueat"></a>CRBtree::setvalueat

Chame este método para alterar o valor `CRBTree` armazenado em uma determinada posição no objeto.

```
void SetValueAt(POSITION pos, VINARGTYPE value);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O contador de posições, retornado por uma chamada anterior para métodos como [CRBTree::GetHeadPosition](#getheadposition) ou [CRBTree::FindFirstKeyAfter](#findfirstkeyafter).

*value*<br/>
O valor a `CRBTree` ser adicionado ao objeto.

### <a name="remarks"></a>Comentários

Altera o elemento de valor armazenado `CRBTree` na posição dada no objeto.

## <a name="crbtreevinargtype"></a><a name="vinargtype"></a>CRBTree::VINARGTYPE

Digite usado quando um valor é passado como um argumento de entrada.

```
typedef VTraits::INARGTYPE VINARGTYPE;
```

## <a name="crbtreevoutargtype"></a><a name="voutargtype"></a>CRBTree::VOUTARGTYPE

Digite usado quando um valor é passado como um argumento de saída.

```
typedef VTraits::OUTARGTYPE VOUTARGTYPE;
```

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
