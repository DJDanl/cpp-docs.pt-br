---
title: Classe CAtlList
ms.date: 11/04/2016
f1_keywords:
- CAtlList
- ATLCOLL/ATL::CAtlList
- ATLCOLL/ATL::CAtlList::INARGTYPE
- ATLCOLL/ATL::CAtlList::CAtlList
- ATLCOLL/ATL::CAtlList::AddHead
- ATLCOLL/ATL::CAtlList::AddHeadList
- ATLCOLL/ATL::CAtlList::AddTail
- ATLCOLL/ATL::CAtlList::AddTailList
- ATLCOLL/ATL::CAtlList::AssertValid
- ATLCOLL/ATL::CAtlList::Find
- ATLCOLL/ATL::CAtlList::FindIndex
- ATLCOLL/ATL::CAtlList::GetAt
- ATLCOLL/ATL::CAtlList::GetCount
- ATLCOLL/ATL::CAtlList::GetHead
- ATLCOLL/ATL::CAtlList::GetHeadPosition
- ATLCOLL/ATL::CAtlList::GetNext
- ATLCOLL/ATL::CAtlList::GetPrev
- ATLCOLL/ATL::CAtlList::GetTail
- ATLCOLL/ATL::CAtlList::GetTailPosition
- ATLCOLL/ATL::CAtlList::InsertAfter
- ATLCOLL/ATL::CAtlList::InsertBefore
- ATLCOLL/ATL::CAtlList::IsEmpty
- ATLCOLL/ATL::CAtlList::MoveToHead
- ATLCOLL/ATL::CAtlList::MoveToTail
- ATLCOLL/ATL::CAtlList::RemoveAll
- ATLCOLL/ATL::CAtlList::RemoveAt
- ATLCOLL/ATL::CAtlList::RemoveHead
- ATLCOLL/ATL::CAtlList::RemoveHeadNoReturn
- ATLCOLL/ATL::CAtlList::RemoveTail
- ATLCOLL/ATL::CAtlList::RemoveTailNoReturn
- ATLCOLL/ATL::CAtlList::SetAt
- ATLCOLL/ATL::CAtlList::SwapElements
helpviewer_keywords:
- CAtlList class
ms.assetid: 09e98053-64b2-4efa-99ab-d0542caaf981
ms.openlocfilehash: 15830a30e8236a13f3911d1b84d3727d3246fc0b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226666"
---
# <a name="catllist-class"></a>Classe CAtlList

Essa classe fornece métodos para criar e gerenciar um objeto de lista.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename E, class ETraits = CElementTraits<E>>
class CAtlList
```

### <a name="parameters"></a>parâmetros

*Oriental*<br/>
O tipo de elemento.

*ETraits*<br/>
O código usado para copiar ou mover elementos. Consulte a [classe CElementTraits](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList::INARGTYPE](#inargtype)||

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList::CAtlList](#catllist)|O construtor.|
|[CAtlList:: ~ CAtlList](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList:: AddHead](#addhead)|Chame esse método para adicionar um elemento à cabeça da lista.|
|[CAtlList:: addheadlist](#addheadlist)|Chame esse método para adicionar uma lista existente ao início da lista.|
|[CAtlList:: addcaudal](#addtail)|Chame esse método para adicionar um elemento à parte final desta lista.|
|[CAtlList:: addcaudal](#addtaillist)|Chame esse método para adicionar uma lista existente à parte final desta lista.|
|[CAtlList::AssertValid](#assertvalid)|Chame esse método para confirmar se a lista é válida.|
|[CAtlList:: find](#find)|Chame esse método para pesquisar a lista para o elemento especificado.|
|[CAtlList::FindIndex](#findindex)|Chame esse método para obter a posição de um elemento, dado um valor de índice.|
|[CAtlList::GetAt](#getat)|Chame esse método para retornar o elemento em uma posição especificada na lista.|
|[CAtlList:: GetCount](#getcount)|Chame esse método para retornar o número de objetos na lista.|
|[CAtlList:: GetHead](#gethead)|Chame esse método para retornar o elemento no cabeçalho da lista.|
|[CAtlList::GetHeadPosition](#getheadposition)|Chame esse método para obter a posição do cabeçalho da lista.|
|[CAtlList:: GetNext](#getnext)|Chame esse método para retornar o próximo elemento da lista.|
|[CAtlList:: getant](#getprev)|Chame esse método para retornar o elemento anterior da lista.|
|[CAtlList:: getcaudal](#gettail)|Chame esse método para retornar o elemento na parte final da lista.|
|[CAtlList::GetTailPosition](#gettailposition)|Chame esse método para obter a posição da parte final da lista.|
|[CAtlList:: InsertAfter](#insertafter)|Chame esse método para inserir um novo elemento na lista após a posição especificada.|
|[CAtlList:: InsertBefore](#insertbefore)|Chame esse método para inserir um novo elemento na lista antes da posição especificada.|
|[CAtlList:: IsEmpty](#isempty)|Chame esse método para determinar se a lista está vazia.|
|[CAtlList::MoveToHead](#movetohead)|Chame esse método para mover o elemento especificado para o cabeçalho da lista.|
|[CAtlList::MoveToTail](#movetotail)|Chame esse método para mover o elemento especificado para a parte final da lista.|
|[CAtlList:: RemoveAll](#removeall)|Chame esse método para remover todos os elementos da lista.|
|[CAtlList:: RemoveAt](#removeat)|Chame esse método para remover um único elemento da lista.|
|[CAtlList::RemoveHead](#removehead)|Chame esse método para remover o elemento no cabeçalho da lista.|
|[CAtlList::RemoveHeadNoReturn](#removeheadnoreturn)|Chame esse método para remover o elemento no cabeçalho da lista sem retornar um valor.|
|[CAtlList::RemoveTail](#removetail)|Chame esse método para remover o elemento na parte final da lista.|
|[CAtlList::RemoveTailNoReturn](#removetailnoreturn)|Chame esse método para remover o elemento na parte final da lista sem retornar um valor.|
|[CAtlList::SetAt](#setat)|Chame esse método para definir o valor do elemento em uma determinada posição na lista.|
|[CAtlList::SwapElements](#swapelements)|Chame esse método para alternar elementos na lista.|

## <a name="remarks"></a>Comentários

A `CAtlList` classe dá suporte a listas ordenadas de objetos não exclusivos acessíveis sequencialmente ou por valor. `CAtlList`as listas se comportam como listas vinculadas duplas. Cada lista tem um cabeçalho e uma parte final, e novos elementos (ou listas em alguns casos) podem ser adicionados a qualquer fim da lista ou inseridos antes ou depois de elementos específicos.

A maioria dos `CAtlList` métodos faz uso de um valor de posição. Esse valor é usado pelos métodos para referenciar o local da memória real em que os elementos são armazenados e não devem ser calculados ou previstos diretamente. Se for necessário acessar o elemento *n*-ésimo na lista, o método [CAtlList:: FindIndex](#findindex) retornará o valor de posição correspondente para um determinado índice. Os métodos [CAtlList:: GetNext](#getnext) e [CAtlList:: getant](#getprev) podem ser usados para iterar pelos objetos na lista.

Para obter mais informações sobre as classes de coleção disponíveis com ATL, consulte [classes de coleção do ATL](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll. h

## <a name="catllistaddhead"></a><a name="addhead"></a>CAtlList:: AddHead

Chame esse método para adicionar um elemento à cabeça da lista.

```cpp
POSITION AddHead();
POSITION AddHead(INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*elementos*<br/>
O novo elemento.

### <a name="return-value"></a>Valor retornado

Retorna a posição do elemento recém-adicionado.

### <a name="remarks"></a>Comentários

Se a primeira versão for usada, um elemento vazio será criado usando seu construtor padrão, em vez de seu construtor de cópia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#13](../../atl/codesnippet/cpp/catllist-class_1.cpp)]

## <a name="catllistaddheadlist"></a><a name="addheadlist"></a>CAtlList:: addheadlist

Chame esse método para adicionar uma lista existente ao início da lista.

```cpp
void AddHeadList(const CAtlList<E, ETraits>* plNew);
```

### <a name="parameters"></a>parâmetros

*plNew*<br/>
A lista a ser adicionada.

### <a name="remarks"></a>Comentários

A lista apontada por *plNew* é inserida no início da lista existente. Em compilações de depuração, ocorrerá uma falha de asserção se *plNew* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#14](../../atl/codesnippet/cpp/catllist-class_2.cpp)]

## <a name="catllistaddtail"></a><a name="addtail"></a>CAtlList:: addcaudal

Chame esse método para adicionar um elemento à parte final desta lista.

```cpp
POSITION AddTail();
POSITION AddTail(INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*elementos*<br/>
O elemento a ser adicionado.

### <a name="return-value"></a>Valor retornado

Retorna a posição do elemento recém-adicionado.

### <a name="remarks"></a>Comentários

Se a primeira versão for usada, um elemento vazio será criado usando seu construtor padrão, em vez de seu construtor de cópia. O elemento é adicionado ao final da lista e, portanto, agora se torna o final. Esse método pode ser usado com uma lista vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#15](../../atl/codesnippet/cpp/catllist-class_3.cpp)]

## <a name="catllistaddtaillist"></a><a name="addtaillist"></a>CAtlList:: addcaudal

Chame esse método para adicionar uma lista existente à parte final desta lista.

```cpp
void AddTailList(const CAtlList<E, ETraits>* plNew);
```

### <a name="parameters"></a>parâmetros

*plNew*<br/>
A lista a ser adicionada.

### <a name="remarks"></a>Comentários

A lista apontada por *plNew* é inserida após o último elemento (se houver) no objeto de lista. O último elemento na lista *plNew* , portanto, se torna a parte final. Em compilações de depuração, ocorrerá uma falha de asserção se *plNew* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#16](../../atl/codesnippet/cpp/catllist-class_4.cpp)]

## <a name="catllistassertvalid"></a><a name="assertvalid"></a>CAtlList::AssertValid

Chame esse método para confirmar se a lista é válida.

```cpp
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá uma falha de asserção se o objeto de lista não for válido. Para ser válido, uma lista vazia deve ter o cabeçalho e a parte final apontando para NULL, e uma lista que não está vazia deve ter o cabeçalho e a parte final apontando para endereços válidos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#17](../../atl/codesnippet/cpp/catllist-class_5.cpp)]

## <a name="catllistcatllist"></a><a name="catllist"></a>CAtlList::CAtlList

O construtor.

```cpp
CAtlList(UINT nBlockSize = 10) throw();
```

### <a name="parameters"></a>parâmetros

*nBlockSize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O construtor do `CAtlList` objeto. O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de bloco maiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#18](../../atl/codesnippet/cpp/catllist-class_6.cpp)]

## <a name="catllistcatllist"></a><a name="dtor"></a>CAtlList:: ~ CAtlList

O destruidor.

```cpp
~CAtlList() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, incluindo uma chamada para [CAtlList:: RemoveAll](#removeall) para remover todos os elementos da lista.

Em compilações de depuração, ocorrerá uma falha de asserção se a lista ainda contiver alguns elementos após a chamada para `RemoveAll` .

## <a name="catllistfind"></a><a name="find"></a>CAtlList:: find

Chame esse método para pesquisar a lista para o elemento especificado.

```cpp
POSITION Find(INARGTYPE element, POSITION posStartAfter = NULL) const throw();
```

### <a name="parameters"></a>parâmetros

*elementos*<br/>
O elemento a ser encontrado na lista.

*posStartAfter*<br/>
A posição inicial da pesquisa. Se nenhum valor for especificado, a pesquisa começará com o elemento head.

### <a name="return-value"></a>Valor retornado

Retorna o valor de posição do elemento, se encontrado; caso contrário, retorna NULL.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá uma falha de asserção se o objeto de lista não for válido ou se o valor de *posStartAfter* estiver fora do intervalo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#19](../../atl/codesnippet/cpp/catllist-class_7.cpp)]

## <a name="catllistfindindex"></a><a name="findindex"></a>CAtlList::FindIndex

Chame esse método para obter a posição de um elemento, dado um valor de índice.

```cpp
POSITION FindIndex(size_t iElement) const throw();
```

### <a name="parameters"></a>parâmetros

*ielemento*<br/>
O índice de base zero do elemento de lista necessário.

### <a name="return-value"></a>Valor retornado

Retorna o valor da posição correspondente ou NULL se *ielemento* estiver fora do intervalo.

### <a name="remarks"></a>Comentários

Esse método retorna a posição correspondente a um determinado valor de índice, permitindo o acesso ao elemento *n*-ésimo na lista.

Em compilações de depuração, ocorrerá uma falha de asserção se o objeto de lista não for válido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#20](../../atl/codesnippet/cpp/catllist-class_8.cpp)]

## <a name="catllistgetat"></a><a name="getat"></a>CAtlList::GetAt

Chame esse método para retornar o elemento em uma posição especificada na lista.

```cpp
E& GetAt(POSITION pos) throw();
const E& GetAt(POSITION pos) const throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição que especifica um determinado elemento.

### <a name="return-value"></a>Valor retornado

Uma referência a, ou cópia do elemento.

### <a name="remarks"></a>Comentários

Se a lista for **`const`** , `GetAt` retornará uma cópia do elemento. Isso permite que o método seja usado somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetAt` retornará uma referência ao elemento. Isso permite que o método seja usado em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: FindIndex](#findindex).

## <a name="catllistgetcount"></a><a name="getcount"></a>CAtlList:: GetCount

Chame esse método para retornar o número de objetos na lista.

```cpp
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos na lista.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: find](#find).

## <a name="catllistgethead"></a><a name="gethead"></a>CAtlList:: GetHead

Chame esse método para retornar o elemento no cabeçalho da lista.

```cpp
E& GetHead() throw();
const E& GetHead() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência a, ou uma cópia do, do elemento no cabeçalho da lista.

### <a name="remarks"></a>Comentários

Se a lista for **`const`** , `GetHead` retornará uma cópia do elemento no cabeçalho da lista. Isso permite que o método seja usado somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetHead` retornará uma referência ao elemento no cabeçalho da lista. Isso permite que o método seja usado em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Em compilações de depuração, ocorrerá uma falha de asserção se o cabeçalho da lista apontar para NULL.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: AddHead](#addhead).

## <a name="catllistgetheadposition"></a><a name="getheadposition"></a>CAtlList::GetHeadPosition

Chame esse método para obter a posição do cabeçalho da lista.

```cpp
POSITION GetHeadPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da posição correspondente ao elemento no cabeçalho da lista.

### <a name="remarks"></a>Comentários

Se a lista estiver vazia, o valor retornado será NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#21](../../atl/codesnippet/cpp/catllist-class_9.cpp)]

## <a name="catllistgetnext"></a><a name="getnext"></a>CAtlList:: GetNext

Chame esse método para retornar o próximo elemento da lista.

```cpp
E& GetNext(POSITION& pos) throw();
const E& GetNext(POSITION& pos) const throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Um valor de posição, retornado por uma chamada anterior para `GetNext` , [CAtlList:: GetHeadPosition](#getheadposition)ou outro `CAtlList` método.

### <a name="return-value"></a>Valor retornado

Se a lista for **`const`** , `GetNext` retornará uma cópia do próximo elemento da lista. Isso permite que o método seja usado somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetNext` retornará uma referência ao próximo elemento da lista. Isso permite que o método seja usado em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

O contador de posição, *pos*, é atualizado para apontar para o próximo elemento na lista, ou NULL se não houver mais elementos. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: GetHeadPosition](#getheadposition).

## <a name="catllistgetprev"></a><a name="getprev"></a>CAtlList:: getant

Chame esse método para retornar o elemento anterior da lista.

```cpp
E& GetPrev(POSITION& pos) throw();
const E& GetPrev(POSITION& pos) const throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
Um valor de posição, retornado por uma chamada anterior para `GetPrev` , [CAtlList:: GetTailPosition](#gettailposition)ou outro `CAtlList` método.

### <a name="return-value"></a>Valor retornado

Se a lista for **`const`** , `GetPrev` retornará uma cópia de um elemento da lista. Isso permite que o método seja usado somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetPrev` retornará uma referência a um elemento da lista. Isso permite que o método seja usado em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

O contador de posição, *pos*, é atualizado para apontar para o elemento anterior na lista, ou NULL se não houver mais elementos. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: GetTailPosition](#gettailposition).

## <a name="catllistgettail"></a><a name="gettail"></a>CAtlList:: getcaudal

Chame esse método para retornar o elemento na parte final da lista.

```cpp
E& GetTail() throw();
const E& GetTail() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência a, ou uma cópia do, do elemento na parte final da lista.

### <a name="remarks"></a>Comentários

Se a lista for **`const`** , `GetTail` retornará uma cópia do elemento no cabeçalho da lista. Isso permite que o método seja usado somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetTail` retornará uma referência ao elemento no cabeçalho da lista. Isso permite que o método seja usado em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Em compilações de depuração, ocorrerá uma falha de asserção se a parte final da lista apontar para NULL.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: addcauda](#addtail).

## <a name="catllistgettailposition"></a><a name="gettailposition"></a>CAtlList::GetTailPosition

Chame esse método para obter a posição da parte final da lista.

```cpp
POSITION GetTailPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor da posição correspondente ao elemento na parte final da lista.

### <a name="remarks"></a>Comentários

Se a lista estiver vazia, o valor retornado será NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#22](../../atl/codesnippet/cpp/catllist-class_10.cpp)]

## <a name="catllistinargtype"></a><a name="inargtype"></a>CAtlList::INARGTYPE

Tipo usado quando um elemento é passado como um argumento de entrada.

```cpp
typedef ETraits::INARGTYPE INARGTYPE;
```

## <a name="catllistinsertafter"></a><a name="insertafter"></a>CAtlList:: InsertAfter

Chame esse método para inserir um novo elemento na lista após a posição especificada.

```cpp
POSITION InsertAfter(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição após o qual o novo elemento será inserido.

*elementos*<br/>
O elemento a ser inserido.

### <a name="return-value"></a>Valor retornado

Retorna o valor da posição do novo elemento.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá uma falha de asserção se a lista não for válida, se a inserção falhar ou se for feita uma tentativa de inserir o elemento após a parte final.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#23](../../atl/codesnippet/cpp/catllist-class_11.cpp)]

## <a name="catllistinsertbefore"></a><a name="insertbefore"></a>CAtlList:: InsertBefore

Chame esse método para inserir um novo elemento na lista antes da posição especificada.

```cpp
POSITION InsertBefore(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O novo elemento será inserido na lista antes desse valor de posição.

*elementos*<br/>
O elemento a ser inserido.

### <a name="return-value"></a>Valor retornado

Retorna o valor da posição do novo elemento.

### <a name="remarks"></a>Comentários

Em compilações de depuração, ocorrerá uma falha de asserção se a lista não for válida, se a inserção falhar ou se for feita uma tentativa de inserir o elemento antes do cabeçalho.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#24](../../atl/codesnippet/cpp/catllist-class_12.cpp)]

## <a name="catllistisempty"></a><a name="isempty"></a>CAtlList:: IsEmpty

Chame esse método para determinar se a lista está vazia.

```cpp
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retornará true se a lista não contiver nenhum objeto, caso contrário, false.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#25](../../atl/codesnippet/cpp/catllist-class_13.cpp)]

## <a name="catllistmovetohead"></a><a name="movetohead"></a>CAtlList::MoveToHead

Chame esse método para mover o elemento especificado para o cabeçalho da lista.

```cpp
void MoveToHead(POSITION pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição do elemento a ser movido.

### <a name="remarks"></a>Comentários

O elemento especificado é movido de sua posição atual para o início da lista. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#26](../../atl/codesnippet/cpp/catllist-class_14.cpp)]

## <a name="catllistmovetotail"></a><a name="movetotail"></a>CAtlList::MoveToTail

Chame esse método para mover o elemento especificado para a parte final da lista.

```cpp
void MoveToTail(POSITION pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição do elemento a ser movido.

### <a name="remarks"></a>Comentários

O elemento especificado é movido de sua posição atual para a parte final da lista. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: MoveToHead](#movetohead).

## <a name="catllistremoveall"></a><a name="removeall"></a>CAtlList:: RemoveAll

Chame esse método para remover todos os elementos da lista.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Esse método remove todos os elementos da lista e libera a memória alocada. Em compilações de debugs, um ATLASSERT será gerado se todos os elementos não forem excluídos ou se a estrutura da lista ficar corrompida.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: IsEmpty](#isempty).

## <a name="catllistremoveat"></a><a name="removeat"></a>CAtlList:: RemoveAt

Chame esse método para remover um único elemento da lista.

```cpp
void RemoveAt(POSITION pos) throw();
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição do elemento a ser removido.

### <a name="remarks"></a>Comentários

O elemento referenciado pelo *PDV* é removido e a memória é liberada. É aceitável usar `RemoveAt` para remover o cabeçalho ou a parte final da lista.

Em compilações de depuração, ocorrerá uma falha de asserção se a lista não for válida ou se a remoção do elemento fizer com que a lista acesse a memória que não faz parte da estrutura da lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#27](../../atl/codesnippet/cpp/catllist-class_15.cpp)]

## <a name="catllistremovehead"></a><a name="removehead"></a>CAtlList::RemoveHead

Chame esse método para remover o elemento no cabeçalho da lista.

```cpp
E RemoveHead();
```

### <a name="return-value"></a>Valor retornado

Retorna o elemento no cabeçalho da lista.

### <a name="remarks"></a>Comentários

O elemento Head é excluído da lista e a memória é liberada. Uma cópia do elemento é retornada. Em compilações de depuração, ocorrerá uma falha de asserção se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#28](../../atl/codesnippet/cpp/catllist-class_16.cpp)]

## <a name="catllistremoveheadnoreturn"></a><a name="removeheadnoreturn"></a>CAtlList::RemoveHeadNoReturn

Chame esse método para remover o elemento no cabeçalho da lista sem retornar um valor.

```cpp
void RemoveHeadNoReturn() throw();
```

### <a name="remarks"></a>Comentários

O elemento Head é excluído da lista e a memória é liberada. Em compilações de depuração, ocorrerá uma falha de asserção se a lista estiver vazia.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: IsEmpty](#isempty).

## <a name="catllistremovetail"></a><a name="removetail"></a>CAtlList::RemoveTail

Chame esse método para remover o elemento na parte final da lista.

```cpp
E RemoveTail();
```

### <a name="return-value"></a>Valor retornado

Retorna o elemento na parte final da lista.

### <a name="remarks"></a>Comentários

O elemento tail é excluído da lista e a memória é liberada. Uma cópia do elemento é retornada. Em compilações de depuração, ocorrerá uma falha de asserção se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#29](../../atl/codesnippet/cpp/catllist-class_17.cpp)]

## <a name="catllistremovetailnoreturn"></a><a name="removetailnoreturn"></a>CAtlList::RemoveTailNoReturn

Chame esse método para remover o elemento na parte final da lista sem retornar um valor.

```cpp
void RemoveTailNoReturn() throw();
```

### <a name="remarks"></a>Comentários

O elemento tail é excluído da lista e a memória é liberada. Em compilações de depuração, ocorrerá uma falha de asserção se a lista estiver vazia.

### <a name="example"></a>Exemplo

Consulte o exemplo de [CAtlList:: IsEmpty](#isempty).

## <a name="catllistsetat"></a><a name="setat"></a>CAtlList::SetAt

Chame esse método para definir o valor do elemento em uma determinada posição na lista.

```cpp
void SetAt(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
O valor de posição correspondente ao elemento a ser alterado.

*elementos*<br/>
O novo valor do elemento.

### <a name="remarks"></a>Comentários

Substitui o valor existente pelo *elemento*. Em compilações de depuração, ocorrerá uma falha de asserção se o *PDV* for igual a nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#30](../../atl/codesnippet/cpp/catllist-class_18.cpp)]

## <a name="catllistswapelements"></a><a name="swapelements"></a>CAtlList::SwapElements

Chame esse método para alternar elementos na lista.

```cpp
void SwapElements(POSITION pos1, POSITION pos2) throw();
```

### <a name="parameters"></a>parâmetros

*pos1*<br/>
O valor da primeira posição.

*pos2*<br/>
O segundo valor da posição.

### <a name="remarks"></a>Comentários

Permuta os elementos nas duas posições especificadas. Em compilações de depuração, ocorrerá uma falha de asserção se o valor da posição for igual a nulo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#31](../../atl/codesnippet/cpp/catllist-class_19.cpp)]

## <a name="see-also"></a>Confira também

[Classe CList](../../mfc/reference/clist-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
