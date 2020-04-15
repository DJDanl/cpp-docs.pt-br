---
title: Classe CList
ms.date: 11/04/2016
f1_keywords:
- CList
- AFXTEMPL/CList
- AFXTEMPL/CList::CList
- AFXTEMPL/CList::AddHead
- AFXTEMPL/CList::AddTail
- AFXTEMPL/CList::Find
- AFXTEMPL/CList::FindIndex
- AFXTEMPL/CList::GetAt
- AFXTEMPL/CList::GetCount
- AFXTEMPL/CList::GetHead
- AFXTEMPL/CList::GetHeadPosition
- AFXTEMPL/CList::GetNext
- AFXTEMPL/CList::GetPrev
- AFXTEMPL/CList::GetSize
- AFXTEMPL/CList::GetTail
- AFXTEMPL/CList::GetTailPosition
- AFXTEMPL/CList::InsertAfter
- AFXTEMPL/CList::InsertBefore
- AFXTEMPL/CList::IsEmpty
- AFXTEMPL/CList::RemoveAll
- AFXTEMPL/CList::RemoveAt
- AFXTEMPL/CList::RemoveHead
- AFXTEMPL/CList::RemoveTail
- AFXTEMPL/CList::SetAt
helpviewer_keywords:
- CList [MFC], CList
- CList [MFC], AddHead
- CList [MFC], AddTail
- CList [MFC], Find
- CList [MFC], FindIndex
- CList [MFC], GetAt
- CList [MFC], GetCount
- CList [MFC], GetHead
- CList [MFC], GetHeadPosition
- CList [MFC], GetNext
- CList [MFC], GetPrev
- CList [MFC], GetSize
- CList [MFC], GetTail
- CList [MFC], GetTailPosition
- CList [MFC], InsertAfter
- CList [MFC], InsertBefore
- CList [MFC], IsEmpty
- CList [MFC], RemoveAll
- CList [MFC], RemoveAt
- CList [MFC], RemoveHead
- CList [MFC], RemoveTail
- CList [MFC], SetAt
ms.assetid: 6f6273c3-c8f6-47f5-ac2a-0a950379ae5d
ms.openlocfilehash: 253cf12033af497115ad600e457630ae834cc69c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372241"
---
# <a name="clist-class"></a>Classe CList

Suporta listas ordenadas de objetos não únicos acessíveis sequencialmente ou por valor.

## <a name="syntax"></a>Sintaxe

```
template<class TYPE, class ARG_TYPE = const TYPE&>
class CList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Lista de c::CList](#clist)|Constrói uma lista vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CList::Addhead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao cabeça da lista (faz uma nova cabeça).|
|[CList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à cauda da lista (faz uma nova cauda).|
|[CList::Encontrar](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CList::Getat](#getat)|Obtém o elemento em uma determinada posição.|
|[CList::GetCount](#getcount)|Retorna o número de elementos nesta lista.|
|[CList::Gethead](#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|
|[CList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento principal da lista.|
|[CList::GetNext](#getnext)|Recebe o próximo elemento para iteração.|
|[CList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|
|[CList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|
|[CList::GetTail](#gettail)|Retorna o elemento de cauda da lista (não pode estar vazio).|
|[CList::GetTailPosition](#gettailposition)|Retorna a posição do elemento de cauda da lista.|
|[Lista de c::inserirApós](#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CList::InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[Lista de C::IsEmpty](#isempty)|Testes para a condição de lista vazia (sem elementos).|
|[Lista de C::RemoveAll](#removeall)|Remove todos os elementos desta lista.|
|[CList::removeat](#removeat)|Remove um elemento desta lista, especificado por posição.|
|[Lista de c::cabeça de remoção](#removehead)|Remove o elemento da cabeça da lista.|
|[CList::RemoveTail](#removetail)|Remove o elemento da cauda da lista.|
|[CList::Setat](#setat)|Define o elemento em uma determinada posição.|

#### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo de objeto armazenado na lista.

*Arg_type*<br/>
Tipo usado para referenciar objetos armazenados na lista. Pode ser uma referência.

## <a name="remarks"></a>Comentários

`CList`listas se comportam como listas duplamente ligadas.

Uma variável do tipo POSIÇÃO é uma chave para a lista. Você pode usar uma variável POSITION como um ativador para atravessar uma lista sequencialmente e como um marcador para manter um lugar. Uma posição não é o mesmo que um índice, no entanto.

A inserção do elemento é muito rápida na cabeça da lista, na cauda e em uma POSIÇÃO conhecida. Uma pesquisa seqüencial é necessária para procurar um elemento por valor ou índice. Essa pesquisa pode ser lenta se a lista for longa.

Se você precisar de um despejo de elementos individuais na lista, você deve definir a profundidade do contexto de despejo para 1 ou mais.

Certas funções de membros desta classe chamam funções de ajudante global `CList` que devem ser personalizadas para a maioria dos usos da classe. Consulte [Os Ajudantes de Classe de Coleção](../../mfc/reference/collection-class-helpers.md) na seção "Macros e Globals".

Para obter mais `CList`informações sobre como usar, consulte o artigo [Coleções](../../mfc/collections.md).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#35](../../mfc/codesnippet/cpp/clist-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="clistaddhead"></a><a name="addhead"></a>CList::Addhead

Adiciona um novo elemento ou lista de elementos ao chefe desta lista.

```
POSITION AddHead(ARG_TYPE newElement);
void AddHead(CList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista (pode ser uma referência).

*Newelement*<br/>
O novo elemento.

*pNewList*<br/>
Um ponteiro `CList` para outra lista. Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#36](../../mfc/codesnippet/cpp/clist-class_2.cpp)]

## <a name="clistaddtail"></a><a name="addtail"></a>CList::AddTail

Adiciona um novo elemento ou lista de elementos à cauda desta lista.

```
POSITION AddTail(ARG_TYPE newElement);
void AddTail(CList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista (pode ser uma referência).

*Newelement*<br/>
O elemento a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro `CList` para outra lista. Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#37](../../mfc/codesnippet/cpp/clist-class_3.cpp)]

## <a name="clistclist"></a><a name="clist"></a>Lista de c::CList

Constrói uma lista vazia.

```
CList(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
A granularidade de alocação de memória para estender a lista.

### <a name="remarks"></a>Comentários

À medida que a lista cresce, a memória é alocada em unidades de entradas *nBlockSize.*

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#38](../../mfc/codesnippet/cpp/clist-class_4.cpp)]

## <a name="clistfind"></a><a name="find"></a>CList::Encontrar

Pesquisa a lista sequencialmente para encontrar o primeiro elemento que corresponda ao *searchValue*especificado .

```
POSITION Find(
    ARG_TYPE searchValue,
    POSITION startAfter = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista (pode ser uma referência).

*searchValue*<br/>
O valor a ser encontrado na lista.

*startAfter*<br/>
A posição inicial para a busca. Se nenhum valor for especificado, a pesquisa começa com o elemento cabeça.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se o objeto não for encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#39](../../mfc/codesnippet/cpp/clist-class_5.cpp)]

## <a name="clistfindindex"></a><a name="findindex"></a>CList::FindIndex

Usa o valor do *nIndex* como um índice na lista.

```
POSITION FindIndex(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do elemento de lista a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULL se *nIndex* for negativo ou muito grande.

### <a name="remarks"></a>Comentários

Ele inicia uma varredura seqüencial do chefe da lista, parando no *n*º elemento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#40](../../mfc/codesnippet/cpp/clist-class_6.cpp)]

## <a name="clistgetat"></a><a name="getat"></a>CList::Getat

Obtém o elemento da lista em uma determinada posição.

```
TYPE& GetAt(POSITION position);
const TYPE& GetAt(POSITION position) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de objeto na lista.

*Posição*<br/>
A posição na lista do elemento a obter.

### <a name="return-value"></a>Valor retornado

Consulte a descrição `GetHead`do valor de retorno para .

### <a name="remarks"></a>Comentários

`GetAt`retorna o elemento (ou uma referência ao elemento) associado a uma determinada posição. Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. Uma variável do tipo POSIÇÃO é uma chave para a lista.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CList::GetHeadPosition](#getheadposition).

## <a name="clistgetcount"></a><a name="getcount"></a>CList::GetCount

Obtém o número de elementos nesta lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro contendo a contagem de elementos.

### <a name="remarks"></a>Comentários

Chamar este método gerará o mesmo resultado que o método [CList::GetSize.](#getsize)

### <a name="example"></a>Exemplo

  Veja o exemplo de [CList::RemoveHead](#removehead).

## <a name="clistgethead"></a><a name="gethead"></a>CList::Gethead

Obtém o elemento cabeça (ou uma referência ao elemento principal) desta lista.

```
const TYPE& GetHead() const;

TYPE& GetHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de objeto na lista.

### <a name="return-value"></a>Valor retornado

Se a lista for `GetHead` **const,** retorne uma cópia do elemento na cabeça da lista. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetHead` **for const,** retorne uma referência ao elemento na cabeça da lista. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#41](../../mfc/codesnippet/cpp/clist-class_7.cpp)]

## <a name="clistgetheadposition"></a><a name="getheadposition"></a>CList::GetHeadPosition

Obtém a posição do elemento principal desta lista.

```
POSITION GetHeadPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#42](../../mfc/codesnippet/cpp/clist-class_8.cpp)]

## <a name="clistgetnext"></a><a name="getnext"></a>CList::GetNext

Obtém o elemento de lista identificado por *rPosition,* em seguida, define *rPosição* para o valor DE POSIÇÃO da próxima entrada na lista.

```
TYPE& GetNext(POSITION& rPosition);
const TYPE& GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos da lista.

*Rposition*<br/>
Uma referência a um valor DE `GetNext`POSIÇÃO retornado por uma chamada anterior , [GetHeadPosition](#getheadposition)ou outra função de membro.

### <a name="return-value"></a>Valor retornado

Se a lista for `GetNext` **const,** retorne uma cópia de um elemento da lista. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetNext` **for const,** retorne uma referência a um elemento da lista. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode `GetNext` usar em um loop de iteração para `GetHeadPosition` frente `Find`se estabelecer a posição inicial com uma chamada para ou .

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o último da lista, então o novo valor de `rPosition` será definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#43](../../mfc/codesnippet/cpp/clist-class_9.cpp)]

## <a name="clistgetprev"></a><a name="getprev"></a>CList::GetPrev

Obtém o elemento `rPosition`de `rPosition` lista identificado por , em seguida, define para o valor DE POSIÇÃO da entrada anterior na lista.

```
TYPE& GetPrev(POSITION& rPosition);
const TYPE& GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos da lista.

*Rposition*<br/>
Uma referência a um valor DE `GetPrev` POSIÇÃO retornado por uma chamada de função anterior ou de outro membro.

### <a name="return-value"></a>Valor retornado

Se a lista for `GetPrev` **const,** retorne uma cópia do elemento na cabeça da lista. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e protege a lista contra modificações.

Se a lista não `GetPrev` **for const,** retorne uma referência a um elemento da lista. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode `GetPrev` usar em um loop de iteração reversa `GetTailPosition` `Find`se estabelecer a posição inicial com uma chamada para ou .

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o primeiro da lista, então o novo valor de *rPosition* será definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#44](../../mfc/codesnippet/cpp/clist-class_10.cpp)]

## <a name="clistgetsize"></a><a name="getsize"></a>CList::GetSize

Retorna o número de elementos da lista.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens da lista.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos na lista.  Chamar este método gerará o mesmo resultado que o método [CList::GetCount.](#getcount)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#45](../../mfc/codesnippet/cpp/clist-class_11.cpp)]

## <a name="clistgettail"></a><a name="gettail"></a>CList::GetTail

Obtém `CObject` o ponteiro que representa o elemento de cauda desta lista.

```
TYPE& GetTail();
const TYPE& GetTail() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](../../mfc/reference/coblist-class.md#gethead).

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#46](../../mfc/codesnippet/cpp/clist-class_12.cpp)]

## <a name="clistgettailposition"></a><a name="gettailposition"></a>CList::GetTailPosition

Obtém a posição do elemento de cauda desta lista; NULO se a lista estiver vazia.

```
POSITION GetTailPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#47](../../mfc/codesnippet/cpp/clist-class_13.cpp)]

## <a name="clistinsertafter"></a><a name="insertafter"></a>Lista de c::inserirApós

Adiciona um elemento a esta lista após o elemento na posição especificada.

```
POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
Um valor de POSIÇÃO `GetNext`retornado `Find` por uma chamada de função anterior ou `GetPrev`membro.

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista.

*Newelement*<br/>
O elemento a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação de elementos de lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#48](../../mfc/codesnippet/cpp/clist-class_14.cpp)]

## <a name="clistinsertbefore"></a><a name="insertbefore"></a>CList::InsertBefore

Adiciona um elemento a esta lista antes do elemento na posição especificada.

```
POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
Um valor de POSIÇÃO `GetNext`retornado `Find` por uma chamada de função anterior ou `GetPrev`membro.

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista (pode ser uma referência).

*Newelement*<br/>
O elemento a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação de elementos de lista.

### <a name="remarks"></a>Comentários

Se *a posição* for NULA, o elemento será inserido na cabeça da lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#49](../../mfc/codesnippet/cpp/clist-class_15.cpp)]

## <a name="clistisempty"></a><a name="isempty"></a>Lista de C::IsEmpty

Indica se esta lista não contém elementos.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se esta lista estiver vazia; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#50](../../mfc/codesnippet/cpp/clist-class_16.cpp)]

## <a name="clistremoveall"></a><a name="removeall"></a>Lista de C::RemoveAll

Remove todos os elementos desta lista e libera a memória associada.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Nenhum erro é gerado se a lista já estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#51](../../mfc/codesnippet/cpp/clist-class_17.cpp)]

## <a name="clistremoveat"></a><a name="removeat"></a>CList::removeat

Remove o elemento especificado desta lista.

```
void RemoveAt(POSITION position);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
A posição do elemento a ser removido da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#52](../../mfc/codesnippet/cpp/clist-class_18.cpp)]

## <a name="clistremovehead"></a><a name="removehead"></a>Lista de c::cabeça de remoção

Remove o elemento da cabeça da lista e retorna um ponteiro para ele.

```
TYPE RemoveHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

O elemento anteriormente no centro da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#53](../../mfc/codesnippet/cpp/clist-class_19.cpp)]

## <a name="clistremovetail"></a><a name="removetail"></a>CList::RemoveTail

Remove o elemento da cauda da lista e retorna um ponteiro para ele.

```
TYPE RemoveTail();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

O elemento que estava na cauda da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#54](../../mfc/codesnippet/cpp/clist-class_20.cpp)]

## <a name="clistsetat"></a><a name="setat"></a>CList::Setat

Uma variável do tipo POSIÇÃO é uma chave para a lista.

```
void SetAt(POSITION pos, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
A posição do elemento a ser definido.

*Arg_type*<br/>
Parâmetro de modelo especificando o tipo do elemento da lista (pode ser uma referência).

*Newelement*<br/>
O elemento a ser adicionado à lista.

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. `SetAt`escreve o elemento para a posição especificada na lista.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#55](../../mfc/codesnippet/cpp/clist-class_21.cpp)]

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMap](../../mfc/reference/cmap-class.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)
