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
ms.openlocfilehash: 7ba85445e3aba1df853d7d3666c92fdabdfa3970
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87182870"
---
# <a name="clist-class"></a>Classe CList

Dá suporte a listas ordenadas de objetos não exclusivos acessíveis sequencialmente ou por valor.

## <a name="syntax"></a>Sintaxe

```
template<class TYPE, class ARG_TYPE = const TYPE&>
class CList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CList::CList](#clist)|Constrói uma lista ordenada vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CList:: AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao início da lista (cria um novo cabeçalho).|
|[CList:: addcaudal](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à parte final da lista (cria uma nova cauda).|
|[CList:: find](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CList::GetAt](#getat)|Obtém o elemento em uma determinada posição.|
|[CList:: GetCount](#getcount)|Retorna o número de elementos nesta lista.|
|[CList:: GetHead](#gethead)|Retorna o elemento head da lista (não pode estar vazio).|
|[CList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento de cabeçalho da lista.|
|[CList:: GetNext](#getnext)|Obtém o próximo elemento para iteração.|
|[CList:: getant](#getprev)|Obtém o elemento anterior para iteração.|
|[CList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|
|[CList:: getcaudal](#gettail)|Retorna o elemento tail da lista (não pode estar vazio).|
|[CList::GetTailPosition](#gettailposition)|Retorna a posição do elemento de cauda da lista.|
|[CList:: InsertAfter](#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CList:: InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[CList:: IsEmpty](#isempty)|Testes para a condição de lista vazia (sem elementos).|
|[CList:: RemoveAll](#removeall)|Remove todos os elementos dessa lista.|
|[CList:: RemoveAt](#removeat)|Remove um elemento desta lista, especificado pela posição.|
|[CList::RemoveHead](#removehead)|Remove o elemento do início da lista.|
|[CList::RemoveTail](#removetail)|Remove o elemento da parte final da lista.|
|[CList::SetAt](#setat)|Define o elemento em uma determinada posição.|

#### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Tipo de objeto armazenado na lista.

*ARG_TYPE*<br/>
Tipo usado para referenciar objetos armazenados na lista. Pode ser uma referência.

## <a name="remarks"></a>Comentários

`CList`as listas se comportam como listas de links duplos.

Uma variável do tipo POSITION é uma chave para a lista. Você pode usar uma variável POSITION como um iterador para percorrer uma lista sequencialmente e como um indicador para manter um local. No entanto, uma posição não é igual a um índice.

A inserção de elemento é muito rápida no cabeçalho da lista, na parte final e em uma posição conhecida. Uma pesquisa sequencial é necessária para pesquisar um elemento por valor ou índice. Essa pesquisa poderá ser lenta se a lista for longa.

Se você precisar de um despejo de elementos individuais na lista, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Determinadas funções de membro dessa classe chamam funções auxiliares globais que devem ser personalizadas para a maioria dos usos da `CList` classe. Consulte [auxiliares de classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção "macros e globais".

Para obter mais informações sobre como usar `CList` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#35](../../mfc/codesnippet/cpp/clist-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl. h

## <a name="clistaddhead"></a><a name="addhead"></a>CList:: AddHead

Adiciona um novo elemento ou lista de elementos ao início dessa lista.

```
POSITION AddHead(ARG_TYPE newElement);
void AddHead(CList* pNewList);
```

### <a name="parameters"></a>parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista (pode ser uma referência).

*newElement*<br/>
O novo elemento.

*pNewList*<br/>
Um ponteiro para outra `CList` lista. Os elementos em *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor da posição do elemento recentemente inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#36](../../mfc/codesnippet/cpp/clist-class_2.cpp)]

## <a name="clistaddtail"></a><a name="addtail"></a>CList:: addcaudal

Adiciona um novo elemento ou lista de elementos à parte final desta lista.

```
POSITION AddTail(ARG_TYPE newElement);
void AddTail(CList* pNewList);
```

### <a name="parameters"></a>parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro para outra `CList` lista. Os elementos em *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor da posição do elemento recentemente inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#37](../../mfc/codesnippet/cpp/clist-class_3.cpp)]

## <a name="clistclist"></a><a name="clist"></a>CList::CList

Constrói uma lista ordenada vazia.

```
CList(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>parâmetros

*nBlockSize*<br/>
A granularidade de alocação de memória para estender a lista.

### <a name="remarks"></a>Comentários

À medida que a lista cresce, a memória é alocada em unidades de entradas *nBlockSize* .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#38](../../mfc/codesnippet/cpp/clist-class_4.cpp)]

## <a name="clistfind"></a><a name="find"></a>CList:: find

Pesquisa a lista sequencialmente para localizar o primeiro elemento que corresponde ao *searchValue*especificado.

```
POSITION Find(
    ARG_TYPE searchValue,
    POSITION startAfter = NULL) const;
```

### <a name="parameters"></a>parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista (pode ser uma referência).

*searchValue*<br/>
O valor a ser encontrado na lista.

*startAfter*<br/>
A posição inicial da pesquisa. Se nenhum valor for especificado, a pesquisa começará com o elemento head.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se o objeto não for encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#39](../../mfc/codesnippet/cpp/clist-class_5.cpp)]

## <a name="clistfindindex"></a><a name="findindex"></a>CList::FindIndex

Usa o valor de *nIndex* como um índice na lista.

```
POSITION FindIndex(INT_PTR nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do elemento de lista a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se *nIndex* for negativo ou muito grande.

### <a name="remarks"></a>Comentários

Ele inicia uma verificação sequencial do início da lista, parando no elemento *n*-ésimo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#40](../../mfc/codesnippet/cpp/clist-class_6.cpp)]

## <a name="clistgetat"></a><a name="getat"></a>CList::GetAt

Obtém o elemento da lista em uma determinada posição.

```
TYPE& GetAt(POSITION position);
const TYPE& GetAt(POSITION position) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de objeto na lista.

*propostas*<br/>
A posição na lista do elemento a ser obtido.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para `GetHead` .

### <a name="remarks"></a>Comentários

`GetAt`Retorna o elemento (ou uma referência ao elemento) associado a uma determinada posição. Não é o mesmo que um índice, e você não pode operar em um valor de posição por conta própria. Uma variável do tipo POSITION é uma chave para a lista.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CList:: GetHeadPosition](#getheadposition).

## <a name="clistgetcount"></a><a name="getcount"></a>CList:: GetCount

Obtém o número de elementos nesta lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro que contém a contagem de elementos.

### <a name="remarks"></a>Comentários

Chamar esse método irá gerar o mesmo resultado que o método [CList:: GetSize](#getsize) .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CList:: RemoveHead](#removehead).

## <a name="clistgethead"></a><a name="gethead"></a>CList:: GetHead

Obtém o elemento head (ou uma referência ao elemento head) dessa lista.

```
const TYPE& GetHead() const;

TYPE& GetHead();
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de objeto na lista.

### <a name="return-value"></a>Valor retornado

Se a lista for **`const`** , `GetHead` retornará uma cópia do elemento no cabeçalho da lista. Isso permite que a função seja usada somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetHead` retornará uma referência ao elemento no cabeçalho da lista. Isso permite que a função seja usada em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `GetHead` . Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#41](../../mfc/codesnippet/cpp/clist-class_7.cpp)]

## <a name="clistgetheadposition"></a><a name="getheadposition"></a>CList::GetHeadPosition

Obtém a posição do elemento de cabeçalho desta lista.

```
POSITION GetHeadPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#42](../../mfc/codesnippet/cpp/clist-class_8.cpp)]

## <a name="clistgetnext"></a><a name="getnext"></a>CList:: GetNext

Obtém o elemento List identificado por *rPosition*e, em seguida, define *rPosition* como o valor de posição da próxima entrada na lista.

```
TYPE& GetNext(POSITION& rPosition);
const TYPE& GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos na lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma `GetNext` chamada de função de membro anterior, [GetHeadPosition](#getheadposition)ou outra.

### <a name="return-value"></a>Valor retornado

Se a lista for **`const`** , `GetNext` retornará uma cópia de um elemento da lista. Isso permite que a função seja usada somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetNext` retornará uma referência a um elemento da lista. Isso permite que a função seja usada em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode usar `GetNext` em um loop de iteração progressiva se estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou `Find` .

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

Se o elemento recuperado for o último na lista, o novo valor de `rPosition` será definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#43](../../mfc/codesnippet/cpp/clist-class_9.cpp)]

## <a name="clistgetprev"></a><a name="getprev"></a>CList:: getant

Obtém o elemento da lista identificado por `rPosition` e, em seguida, define `rPosition` como o valor de posição da entrada anterior na lista.

```
TYPE& GetPrev(POSITION& rPosition);
const TYPE& GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo dos elementos na lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma `GetPrev` chamada de função de membro anterior ou outra.

### <a name="return-value"></a>Valor retornado

Se a lista for **`const`** , `GetPrev` retornará uma cópia do elemento no cabeçalho da lista. Isso permite que a função seja usada somente no lado direito de uma instrução de atribuição e protege a lista contra modificações.

Se a lista não for **`const`** , `GetPrev` retornará uma referência a um elemento da lista. Isso permite que a função seja usada em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode usar `GetPrev` em um loop de iteração reversa se estabelecer a posição inicial com uma chamada para `GetTailPosition` ou `Find` .

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

Se o elemento recuperado for o primeiro na lista, o novo valor de *rPosition* será definido como NULL.

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

Chame esse método para recuperar o número de elementos na lista.  Chamar esse método irá gerar o mesmo resultado que o método [CList:: GetCount](#getcount) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#45](../../mfc/codesnippet/cpp/clist-class_11.cpp)]

## <a name="clistgettail"></a><a name="gettail"></a>CList:: getcaudal

Obtém o `CObject` ponteiro que representa o elemento de cauda desta lista.

```
TYPE& GetTail();
const TYPE& GetTail() const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](../../mfc/reference/coblist-class.md#gethead).

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `GetTail` . Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#46](../../mfc/codesnippet/cpp/clist-class_12.cpp)]

## <a name="clistgettailposition"></a><a name="gettailposition"></a>CList::GetTailPosition

Obtém a posição do elemento de cauda desta lista; NULL se a lista estiver vazia.

```
POSITION GetTailPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#47](../../mfc/codesnippet/cpp/clist-class_13.cpp)]

## <a name="clistinsertafter"></a><a name="insertafter"></a>CList:: InsertAfter

Adiciona um elemento a essa lista após o elemento na posição especificada.

```
POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*propostas*<br/>
Um valor de posição retornado por uma `GetNext` `GetPrev` chamada de função de membro, ou anterior `Find` .

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista.

*newElement*<br/>
O elemento a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para recuperação de elemento de lista ou iteração.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#48](../../mfc/codesnippet/cpp/clist-class_14.cpp)]

## <a name="clistinsertbefore"></a><a name="insertbefore"></a>CList:: InsertBefore

Adiciona um elemento a essa lista antes do elemento na posição especificada.

```
POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*propostas*<br/>
Um valor de posição retornado por uma `GetNext` `GetPrev` chamada de função de membro, ou anterior `Find` .

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para recuperação de elemento de lista ou iteração.

### <a name="remarks"></a>Comentários

Se *Position* for NULL, o elemento será inserido no cabeçalho da lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#49](../../mfc/codesnippet/cpp/clist-class_15.cpp)]

## <a name="clistisempty"></a><a name="isempty"></a>CList:: IsEmpty

Indica se esta lista não contém elementos.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se esta lista estiver vazia; caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#50](../../mfc/codesnippet/cpp/clist-class_16.cpp)]

## <a name="clistremoveall"></a><a name="removeall"></a>CList:: RemoveAll

Remove todos os elementos dessa lista e libera a memória associada.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Nenhum erro será gerado se a lista já estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#51](../../mfc/codesnippet/cpp/clist-class_17.cpp)]

## <a name="clistremoveat"></a><a name="removeat"></a>CList:: RemoveAt

Remove o elemento especificado desta lista.

```cpp
void RemoveAt(POSITION position);
```

### <a name="parameters"></a>parâmetros

*propostas*<br/>
A posição do elemento a ser removido da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#52](../../mfc/codesnippet/cpp/clist-class_18.cpp)]

## <a name="clistremovehead"></a><a name="removehead"></a>CList::RemoveHead

Remove o elemento da cabeça da lista e retorna um ponteiro para ele.

```
TYPE RemoveHead();
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

O elemento anteriormente no início da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `RemoveHead` . Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#53](../../mfc/codesnippet/cpp/clist-class_19.cpp)]

## <a name="clistremovetail"></a><a name="removetail"></a>CList::RemoveTail

Remove o elemento da parte final da lista e retorna um ponteiro para ele.

```
TYPE RemoveTail();
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos na lista.

### <a name="return-value"></a>Valor retornado

O elemento que estava na parte final da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `RemoveTail` . Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#54](../../mfc/codesnippet/cpp/clist-class_20.cpp)]

## <a name="clistsetat"></a><a name="setat"></a>CList::SetAt

Uma variável do tipo POSITION é uma chave para a lista.

```cpp
void SetAt(POSITION pos, ARG_TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
A posição do elemento a ser definido.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento da lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado à lista.

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor de posição por conta própria. `SetAt`grava o elemento na posição especificada na lista.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#55](../../mfc/codesnippet/cpp/clist-class_21.cpp)]

## <a name="see-also"></a>Confira também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe de CMap](../../mfc/reference/cmap-class.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)
