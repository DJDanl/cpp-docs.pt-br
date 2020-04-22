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
ms.openlocfilehash: 0e4ea8eef51431c100f5d3119d7f75e9673e276e
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748743"
---
# <a name="catllist-class"></a>Classe CAtlList

Esta classe fornece métodos para criar e gerenciar um objeto de lista.

## <a name="syntax"></a>Sintaxe

```
template<typename E, class ETraits = CElementTraits<E>>
class CAtlList
```

#### <a name="parameters"></a>Parâmetros

*E*<br/>
O tipo de elemento.

*Estreito*<br/>
O código usado para copiar ou mover elementos. Consulte [CElementTraits Class](../../atl/reference/celementtraits-class.md) para obter mais detalhes.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList::INARGTYPE](#inargtype)||

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList::CAtlList](#catllist)|O construtor.|
|[CAtlList::~CAtlList](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAtlList::AddHead](#addhead)|Chame este método para adicionar um elemento à cabeça da lista.|
|[CAtlList::AddHeadList](#addheadlist)|Chame este método para adicionar uma lista existente ao cabeça da lista.|
|[CAtlList::AddTail](#addtail)|Chame este método para adicionar um elemento à cauda desta lista.|
|[CAtlList::AddTailList](#addtaillist)|Chame este método para adicionar uma lista existente à cauda desta lista.|
|[CAtlList::AssertValid](#assertvalid)|Ligue para este método para confirmar se a lista é válida.|
|[CAtlList::Encontrar](#find)|Chame este método para pesquisar a lista para o elemento especificado.|
|[CAtlList::FindIndex](#findindex)|Chame este método para obter a posição de um elemento, dado um valor de índice.|
|[CAtlList::GetAt](#getat)|Chame este método para retornar o elemento em uma posição especificada na lista.|
|[CAtlList::GetCount](#getcount)|Chame este método para retornar o número de objetos na lista.|
|[CAtlList::GetHead](#gethead)|Chame este método para retornar o elemento no centro da lista.|
|[CAtlList::GetHeadPosition](#getheadposition)|Chame este método para obter a posição do chefe da lista.|
|[CAtlList::GetNext](#getnext)|Chame este método para retornar o próximo elemento da lista.|
|[CAtlList::GetPrev](#getprev)|Chame este método para retornar o elemento anterior da lista.|
|[CAtlList::GetTail](#gettail)|Chame este método para retornar o elemento na cauda da lista.|
|[CAtlList::GetTailPosition](#gettailposition)|Chame este método para obter a posição da cauda da lista.|
|[CAtlList::InsertAfter](#insertafter)|Chame este método para inserir um novo elemento na lista após a posição especificada.|
|[CAtlList::InsertBefore](#insertbefore)|Chame este método para inserir um novo elemento na lista antes da posição especificada.|
|[CAtlList::IsEmpty](#isempty)|Chame este método para determinar se a lista está vazia.|
|[CAtlList::MoveToHead](#movetohead)|Chame este método para mover o elemento especificado para a cabeça da lista.|
|[CAtlList::MoveToTail](#movetotail)|Chame este método para mover o elemento especificado para a cauda da lista.|
|[CAtlList::RemoveAll](#removeall)|Chame este método para remover todos os elementos da lista.|
|[CAtlList::RemoveAt](#removeat)|Chame este método para remover um único elemento da lista.|
|[CAtlList::RemoveHead](#removehead)|Chame este método para remover o elemento no centro da lista.|
|[CAtlList::RemoveHeadNoReturn](#removeheadnoreturn)|Chame este método para remover o elemento no centro da lista sem retornar um valor.|
|[CAtlList::RemoveTail](#removetail)|Chame este método para remover o elemento na cauda da lista.|
|[CAtlList::RemoveTailNoReturn](#removetailnoreturn)|Chame este método para remover o elemento na cauda da lista sem retornar um valor.|
|[CAtlList::SetAt](#setat)|Chame este método para definir o valor do elemento em uma determinada posição na lista.|
|[CAtlList::SwapElements](#swapelements)|Chame este método para trocar elementos na lista.|

## <a name="remarks"></a>Comentários

A `CAtlList` classe suporta listas ordenadas de objetos não únicos acessíveis sequencialmente ou por valor. `CAtlList`listas se comportam como listas duplamente ligadas. Cada lista tem uma cabeça e uma cauda, e novos elementos (ou listas em alguns casos) podem ser adicionados a ambos os extremidades da lista, ou inseridos antes ou depois de elementos específicos.

A maioria `CAtlList` dos métodos faz uso de um valor de posição. Este valor é usado pelos métodos para referenciar o local de memória real onde os elementos são armazenados, e não deve ser calculado ou previsto diretamente. Se for necessário acessar o elemento *n*th da lista, o método [CAtlList::FindIndex](#findindex) retornará o valor de posição correspondente para um determinado índice. Os métodos [CAtlList::GetNext](#getnext) e [CAtlList::GetPrev](#getprev) podem ser usados para iterar através dos objetos da lista.

Para obter mais informações sobre as classes de coleta disponíveis com atl, consulte [ATL Collection Classes](../../atl/atl-collection-classes.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcoll.h

## <a name="catllistaddhead"></a><a name="addhead"></a>CAtlList::AddHead

Chame este método para adicionar um elemento à cabeça da lista.

```
POSITION AddHead();
POSITION AddHead(INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O novo elemento.

### <a name="return-value"></a>Valor retornado

Retorna a posição do elemento recém-adicionado.

### <a name="remarks"></a>Comentários

Se a primeira versão for usada, um elemento vazio será criado usando seu construtor padrão, em vez de seu construtor de cópias.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#13](../../atl/codesnippet/cpp/catllist-class_1.cpp)]

## <a name="catllistaddheadlist"></a><a name="addheadlist"></a>CAtlList::AddHeadList

Chame este método para adicionar uma lista existente ao cabeça da lista.

```cpp
void AddHeadList(const CAtlList<E, ETraits>* plNew);
```

### <a name="parameters"></a>Parâmetros

*Plnew*<br/>
A lista a ser adicionada.

### <a name="remarks"></a>Comentários

A lista apontada pelo *plNew* é inserida no início da lista existente. Nas compilações de depuração, uma falha de afirmação ocorrerá se *plNew* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#14](../../atl/codesnippet/cpp/catllist-class_2.cpp)]

## <a name="catllistaddtail"></a><a name="addtail"></a>CAtlList::AddTail

Chame este método para adicionar um elemento à cauda desta lista.

```
POSITION AddTail();
POSITION AddTail(INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O elemento a ser adicionado.

### <a name="return-value"></a>Valor retornado

Retorna a POSIÇÃO do elemento recém-adicionado.

### <a name="remarks"></a>Comentários

Se a primeira versão for usada, um elemento vazio será criado usando seu construtor padrão, em vez de seu construtor de cópias. O elemento é adicionado ao final da lista, e agora se torna a cauda. Este método pode ser usado com uma lista vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#15](../../atl/codesnippet/cpp/catllist-class_3.cpp)]

## <a name="catllistaddtaillist"></a><a name="addtaillist"></a>CAtlList::AddTailList

Chame este método para adicionar uma lista existente à cauda desta lista.

```cpp
void AddTailList(const CAtlList<E, ETraits>* plNew);
```

### <a name="parameters"></a>Parâmetros

*Plnew*<br/>
A lista a ser adicionada.

### <a name="remarks"></a>Comentários

A lista apontada por *plNew* é inserida após o último elemento (se houver) no objeto da lista. O último elemento na lista *plNew* torna-se, portanto, a cauda. Nas compilações de depuração, uma falha de afirmação ocorrerá se *plNew* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#16](../../atl/codesnippet/cpp/catllist-class_4.cpp)]

## <a name="catllistassertvalid"></a><a name="assertvalid"></a>CAtlList::AssertValid

Ligue para este método para confirmar se a lista é válida.

```cpp
void AssertValid() const;
```

### <a name="remarks"></a>Comentários

Nas compilações de depuração, uma falha de afirmação ocorrerá se o objeto da lista não for válido. Para ser válido, uma lista vazia deve ter a cabeça e a cauda apontando para NULL, e uma lista que não está vazia deve ter a cabeça e a cauda apontando para endereços válidos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#17](../../atl/codesnippet/cpp/catllist-class_5.cpp)]

## <a name="catllistcatllist"></a><a name="catllist"></a>CAtlList::CAtlList

O construtor.

```
CAtlList(UINT nBlockSize = 10) throw();
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
O tamanho do bloco.

### <a name="remarks"></a>Comentários

O construtor do `CAtlList` objeto. O tamanho do bloco é uma medida da quantidade de memória alocada quando um novo elemento é necessário. Tamanhos de blocomaiores reduzem chamadas para rotinas de alocação de memória, mas usam mais recursos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#18](../../atl/codesnippet/cpp/catllist-class_6.cpp)]

## <a name="catllistcatllist"></a><a name="dtor"></a>CAtlList::~CAtlList

O destruidor.

```
~CAtlList() throw();
```

### <a name="remarks"></a>Comentários

Libera todos os recursos alocados, incluindo uma chamada para [CAtlList::RemoveAll](#removeall) para remover todos os elementos da lista.

Nas compilações de depuração, uma falha de afirmação ocorrerá `RemoveAll`se a lista ainda contiver alguns elementos após a chamada para .

## <a name="catllistfind"></a><a name="find"></a>CAtlList::Encontrar

Chame este método para pesquisar a lista para o elemento especificado.

```
POSITION Find(INARGTYPE element, POSITION posStartAfter = NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*Elemento*<br/>
O elemento encontrado na lista.

*posStartAfter*<br/>
A posição inicial para a busca. Se nenhum valor for especificado, a pesquisa começa com o elemento cabeça.

### <a name="return-value"></a>Valor retornado

Retorna o valor DE POSIÇÃO do elemento se encontrado, caso contrário retorna NULL.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, uma falha de afirmação ocorrerá se o objeto de lista não for válido ou se o valor *posStartAfter* estiver fora de alcance.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#19](../../atl/codesnippet/cpp/catllist-class_7.cpp)]

## <a name="catllistfindindex"></a><a name="findindex"></a>CAtlList::FindIndex

Chame este método para obter a posição de um elemento, dado um valor de índice.

```
POSITION FindIndex(size_t iElement) const throw();
```

### <a name="parameters"></a>Parâmetros

*Ielement*<br/>
O índice baseado em zero do elemento de lista necessário.

### <a name="return-value"></a>Valor retornado

Retorna o valor de POSIÇÃO correspondente ou NULL se *o iElement* estiver fora de alcance.

### <a name="remarks"></a>Comentários

Este método retorna a POSIÇÃO correspondente a um determinado valor de índice, permitindo o acesso ao *n*º elemento da lista.

Nas compilações de depuração, uma falha de afirmação ocorrerá se o objeto da lista não for válido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#20](../../atl/codesnippet/cpp/catllist-class_8.cpp)]

## <a name="catllistgetat"></a><a name="getat"></a>CAtlList::GetAt

Chame este método para retornar o elemento em uma posição especificada na lista.

```
E& GetAt(POSITION pos) throw();
const E& GetAt(POSITION pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor DE POSIÇÃO especificando um elemento específico.

### <a name="return-value"></a>Valor retornado

Uma referência ou cópia do elemento.

### <a name="remarks"></a>Comentários

Se a lista for `GetAt` **const,** retorne uma cópia do elemento. Isso permite que o método seja usado apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetAt` **for const,** retorne uma referência ao elemento. Isso permite que o método seja usado em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::FindIndex](#findindex).

## <a name="catllistgetcount"></a><a name="getcount"></a>CAtlList::GetCount

Chame este método para retornar o número de objetos na lista.

```
size_t GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos na lista.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::Find](#find).

## <a name="catllistgethead"></a><a name="gethead"></a>CAtlList::GetHead

Chame este método para retornar o elemento no centro da lista.

```
E& GetHead() throw();
const E& GetHead() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência ou uma cópia do elemento no centro da lista.

### <a name="remarks"></a>Comentários

Se a lista for `GetHead` **const,** retorne uma cópia do elemento na cabeça da lista. Isso permite que o método seja usado apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetHead` **for const,** retorne uma referência ao elemento na cabeça da lista. Isso permite que o método seja usado em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Nas compilações de depuração, uma falha de afirmação ocorrerá se o chefe da lista aponta para NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::AddHead](#addhead).

## <a name="catllistgetheadposition"></a><a name="getheadposition"></a>CAtlList::GetHeadPosition

Chame este método para obter a posição do chefe da lista.

```
POSITION GetHeadPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor DE POSIÇÃO correspondente ao elemento na cabeça da lista.

### <a name="remarks"></a>Comentários

Se a lista estiver vazia, o valor devolvido será NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#21](../../atl/codesnippet/cpp/catllist-class_9.cpp)]

## <a name="catllistgetnext"></a><a name="getnext"></a>CAtlList::GetNext

Chame este método para retornar o próximo elemento da lista.

```
E& GetNext(POSITION& pos) throw();
const E& GetNext(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Um valor DE POSIÇÃO, retornado `GetNext`por uma chamada anterior [para, CAtlList::GetHeadPosition,](#getheadposition)ou outro `CAtlList` método.

### <a name="return-value"></a>Valor retornado

Se a lista for `GetNext` **const,** retorne uma cópia do próximo elemento da lista. Isso permite que o método seja usado apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetNext` **for const,** retorne uma referência ao próximo elemento da lista. Isso permite que o método seja usado em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

O contador POSITION, *pos*, é atualizado para apontar para o próximo elemento da lista, ou NULL se não houver mais elementos. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::GetHeadPosition](#getheadposition).

## <a name="catllistgetprev"></a><a name="getprev"></a>CAtlList::GetPrev

Chame este método para retornar o elemento anterior da lista.

```
E& GetPrev(POSITION& pos) throw();
const E& GetPrev(POSITION& pos) const throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
Um valor DE POSIÇÃO, retornado `GetPrev`por uma chamada anterior para , `CAtlList` [CAtlList::GetTailPosition](#gettailposition)ou outro método.

### <a name="return-value"></a>Valor retornado

Se a lista for `GetPrev` **const,** retorne uma cópia de um elemento da lista. Isso permite que o método seja usado apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetPrev` **for const,** retorne uma referência a um elemento da lista. Isso permite que o método seja usado em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

O contador POSITION, *pos*, é atualizado para apontar para o elemento anterior na lista, ou NULL se não houver mais elementos. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::GetTailPosition](#gettailposition).

## <a name="catllistgettail"></a><a name="gettail"></a>CAtlList::GetTail

Chame este método para retornar o elemento na cauda da lista.

```
E& GetTail() throw();
const E& GetTail() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma referência ou uma cópia do elemento na cauda da lista.

### <a name="remarks"></a>Comentários

Se a lista for `GetTail` **const,** retorne uma cópia do elemento na cabeça da lista. Isso permite que o método seja usado apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetTail` **for const,** retorne uma referência ao elemento na cabeça da lista. Isso permite que o método seja usado em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

Nas compilações de depuração, uma falha de afirmação ocorrerá se a cauda da lista aponta para NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::AddTail](#addtail).

## <a name="catllistgettailposition"></a><a name="gettailposition"></a>CAtlList::GetTailPosition

Chame este método para obter a posição da cauda da lista.

```
POSITION GetTailPosition() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o valor DE POSIÇÃO correspondente ao elemento na cauda da lista.

### <a name="remarks"></a>Comentários

Se a lista estiver vazia, o valor devolvido será NULO.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#22](../../atl/codesnippet/cpp/catllist-class_10.cpp)]

## <a name="catllistinargtype"></a><a name="inargtype"></a>CAtlList::INARGTYPE

Digite usado quando um elemento é passado como um argumento de entrada.

```
typedef ETraits::INARGTYPE INARGTYPE;
```

## <a name="catllistinsertafter"></a><a name="insertafter"></a>CAtlList::InsertAfter

Chame este método para inserir um novo elemento na lista após a posição especificada.

```
POSITION InsertAfter(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor DE POSIÇÃO após o qual o novo elemento será inserido.

*Elemento*<br/>
O elemento a ser inserido.

### <a name="return-value"></a>Valor retornado

Retorna o valor DE POSIÇÃO do novo elemento.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista não for válida, se a inserção falhar ou se for feita uma tentativa de inserir o elemento após a cauda.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#23](../../atl/codesnippet/cpp/catllist-class_11.cpp)]

## <a name="catllistinsertbefore"></a><a name="insertbefore"></a>CAtlList::InsertBefore

Chame este método para inserir um novo elemento na lista antes da posição especificada.

```
POSITION InsertBefore(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O novo elemento será inserido na lista antes deste valor DE POSIÇÃO.

*Elemento*<br/>
O elemento a ser inserido.

### <a name="return-value"></a>Valor retornado

Retorna o valor DE POSIÇÃO do novo elemento.

### <a name="remarks"></a>Comentários

Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista não for válida, se a inserção falhar ou se for feita uma tentativa de inserir o elemento antes da cabeça.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#24](../../atl/codesnippet/cpp/catllist-class_12.cpp)]

## <a name="catllistisempty"></a><a name="isempty"></a>CAtlList::IsEmpty

Chame este método para determinar se a lista está vazia.

```
bool IsEmpty() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro se a lista não contiver objetos, caso contrário, falso.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#25](../../atl/codesnippet/cpp/catllist-class_13.cpp)]

## <a name="catllistmovetohead"></a><a name="movetohead"></a>CAtlList::MoveToHead

Chame este método para mover o elemento especificado para a cabeça da lista.

```cpp
void MoveToHead(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor de POSIÇÃO do elemento para mover.

### <a name="remarks"></a>Comentários

O elemento especificado é movido de sua posição atual para o chefe da lista. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#26](../../atl/codesnippet/cpp/catllist-class_14.cpp)]

## <a name="catllistmovetotail"></a><a name="movetotail"></a>CAtlList::MoveToTail

Chame este método para mover o elemento especificado para a cauda da lista.

```cpp
void MoveToTail(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor de POSIÇÃO do elemento para mover.

### <a name="remarks"></a>Comentários

O elemento especificado é movido de sua posição atual para a cauda da lista. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::MoveToHead](#movetohead).

## <a name="catllistremoveall"></a><a name="removeall"></a>CAtlList::RemoveAll

Chame este método para remover todos os elementos da lista.

```cpp
void RemoveAll() throw();
```

### <a name="remarks"></a>Comentários

Este método remove todos os elementos da lista e libera a memória alocada. Em compilações de desbugs, um ATLASSERT será levantado se todos os elementos não forem excluídos ou se a estrutura da lista estiver corrompida.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::IsEmpty](#isempty).

## <a name="catllistremoveat"></a><a name="removeat"></a>CAtlList::RemoveAt

Chame este método para remover um único elemento da lista.

```cpp
void RemoveAt(POSITION pos) throw();
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor de POSIÇÃO do elemento a ser removido.

### <a name="remarks"></a>Comentários

O elemento referenciado por *pos* é removido, e a memória é liberada. É aceitável usar `RemoveAt` para remover a cabeça ou a cauda da lista.

Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista não for válida ou se a remoção do elemento fizer com que a lista acesse a memória que não faz parte da estrutura da lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#27](../../atl/codesnippet/cpp/catllist-class_15.cpp)]

## <a name="catllistremovehead"></a><a name="removehead"></a>CAtlList::RemoveHead

Chame este método para remover o elemento no centro da lista.

```
E RemoveHead();
```

### <a name="return-value"></a>Valor retornado

Retorna o elemento no centro da lista.

### <a name="remarks"></a>Comentários

O elemento principal é excluído da lista e a memória é liberada. Uma cópia do elemento é devolvida. Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#28](../../atl/codesnippet/cpp/catllist-class_16.cpp)]

## <a name="catllistremoveheadnoreturn"></a><a name="removeheadnoreturn"></a>CAtlList::RemoveHeadNoReturn

Chame este método para remover o elemento no centro da lista sem retornar um valor.

```cpp
void RemoveHeadNoReturn() throw();
```

### <a name="remarks"></a>Comentários

O elemento principal é excluído da lista e a memória é liberada. Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista estiver vazia.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::IsEmpty](#isempty).

## <a name="catllistremovetail"></a><a name="removetail"></a>CAtlList::RemoveTail

Chame este método para remover o elemento na cauda da lista.

```
E RemoveTail();
```

### <a name="return-value"></a>Valor retornado

Retorna o elemento na cauda da lista.

### <a name="remarks"></a>Comentários

O elemento de cauda é excluído da lista e a memória é liberada. Uma cópia do elemento é devolvida. Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#29](../../atl/codesnippet/cpp/catllist-class_17.cpp)]

## <a name="catllistremovetailnoreturn"></a><a name="removetailnoreturn"></a>CAtlList::RemoveTailNoReturn

Chame este método para remover o elemento na cauda da lista sem retornar um valor.

```cpp
void RemoveTailNoReturn() throw();
```

### <a name="remarks"></a>Comentários

O elemento de cauda é excluído da lista e a memória é liberada. Nas compilações de depuração, uma falha de afirmação ocorrerá se a lista estiver vazia.

### <a name="example"></a>Exemplo

Veja o exemplo [de CAtlList::IsEmpty](#isempty).

## <a name="catllistsetat"></a><a name="setat"></a>CAtlList::SetAt

Chame este método para definir o valor do elemento em uma determinada posição na lista.

```cpp
void SetAt(POSITION pos, INARGTYPE element);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
O valor DE POSIÇÃO correspondente ao elemento a ser alterado.

*Elemento*<br/>
O novo valor do elemento.

### <a name="remarks"></a>Comentários

Substitui o valor existente pelo *elemento*. Nas compilações de depuração, uma falha de afirmação ocorrerá se *pos* for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#30](../../atl/codesnippet/cpp/catllist-class_18.cpp)]

## <a name="catllistswapelements"></a><a name="swapelements"></a>CAtlList::SwapElements

Chame este método para trocar elementos na lista.

```cpp
void SwapElements(POSITION pos1, POSITION pos2) throw();
```

### <a name="parameters"></a>Parâmetros

*pos1*<br/>
O primeiro valor de POSIÇÃO.

*pos2*<br/>
O segundo valor de POSIÇÃO.

### <a name="remarks"></a>Comentários

Troca os elementos nas duas posições especificadas. Nas compilações de depuração, uma falha de afirmação ocorrerá se qualquer valor de posição for igual a NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#31](../../atl/codesnippet/cpp/catllist-class_19.cpp)]

## <a name="see-also"></a>Confira também

[Classe CList](../../mfc/reference/clist-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
