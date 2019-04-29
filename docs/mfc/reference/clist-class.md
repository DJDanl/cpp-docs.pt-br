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
ms.openlocfilehash: 383222e4892bccc653f010ce4939bca23f2adc93
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62225289"
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
|[CList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o cabeçalho da lista (faz um novo cabeçalho).|
|[CList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) para a parte final da lista (faz uma cauda novo).|
|[CList::Find](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CList::GetAt](#getat)|Obtém o elemento na posição especificada.|
|[CList::GetCount](#getcount)|Retorna o número de elementos nesta lista.|
|[CList::GetHead](#gethead)|Retorna o elemento de cabeçalho da lista (não pode estar vazia).|
|[CList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento de cabeçalho da lista.|
|[CList::GetNext](#getnext)|Obtém o próximo elemento para a iteração.|
|[CList::GetPrev](#getprev)|Obtém o elemento anterior para a iteração.|
|[CList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|
|[CList::GetTail](#gettail)|Retorna o elemento final da lista (não pode estar vazia).|
|[CList::GetTailPosition](#gettailposition)|Retorna a posição do elemento da parte final da lista.|
|[CList::InsertAfter](#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CList::InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[CList::IsEmpty](#isempty)|Testa a condição de lista vazia (sem elementos).|
|[CList::RemoveAll](#removeall)|Remove todos os elementos dessa lista.|
|[CList::RemoveAt](#removeat)|Remove um elemento dessa lista, especificada pela posição.|
|[CList::RemoveHead](#removehead)|Remove o elemento do cabeçalho da lista.|
|[CList::RemoveTail](#removetail)|Remove o elemento do final da lista.|
|[CList::SetAt](#setat)|Define o elemento na posição especificada.|

#### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo de objeto armazenado na lista.

*ARG_TYPE*<br/>
Tipo usado para fazer referência a objetos armazenados na lista. Pode ser uma referência.

## <a name="remarks"></a>Comentários

`CList` listas se comportam como listas duplamente vinculada.

Uma variável do tipo de posição é uma chave para a lista. Você pode usar uma variável de posição como um iterador para percorrer uma lista sequencialmente e como um indicador para manter um lugar. Uma posição não é o mesmo que um índice, no entanto.

Inserção de elemento é muito rápida no início de lista, na parte final e na posição conhecida. Uma pesquisa sequencial é necessária para pesquisar um elemento por valor ou índice. Essa pesquisa pode ser lenta se a lista for longa.

Se você precisar de um despejo de elementos individuais na lista, você deve definir a profundidade do contexto de despejo para 1 ou maior.

Determinadas funções de membro dessa chamada de classe auxiliar global de funções que devem ser personalizadas para a maioria dos usos do `CList` classe. Ver [auxiliares da classe de coleção](../../mfc/reference/collection-class-helpers.md) na seção "Macros e Globals".

Para obter mais informações sobre como usar `CList`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#35](../../mfc/codesnippet/cpp/clist-class_1.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

##  <a name="addhead"></a>  CList::AddHead

Adiciona um novo elemento ou uma lista de elementos no cabeçalho dessa lista.

```
POSITION AddHead(ARG_TYPE newElement);
void AddHead(CList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento de lista (pode ser uma referência).

*newElement*<br/>
O novo elemento.

*pNewList*<br/>
Um ponteiro para uma outra `CList` lista. Os elementos na *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna o valor da posição do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#36](../../mfc/codesnippet/cpp/clist-class_2.cpp)]

##  <a name="addtail"></a>  CList::AddTail

Adiciona um novo elemento ou uma lista de elementos para a parte final desta lista.

```
POSITION AddTail(ARG_TYPE newElement);
void AddTail(CList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento de lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado a essa lista.

*pNewList*<br/>
Um ponteiro para uma outra `CList` lista. Os elementos na *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna o valor da posição do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#37](../../mfc/codesnippet/cpp/clist-class_3.cpp)]

##  <a name="clist"></a>  CList::CList

Constrói uma lista ordenada vazia.

```
CList(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
A granularidade de alocação de memória para estender a lista.

### <a name="remarks"></a>Comentários

À medida que a lista aumenta, a memória é alocada em unidades de *nBlockSize* entradas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#38](../../mfc/codesnippet/cpp/clist-class_4.cpp)]

##  <a name="find"></a>  CList::Find

Pesquisa a lista em sequência para localizar o primeiro elemento de correspondência especificado *searchValue*.

```
POSITION Find(
    ARG_TYPE searchValue,
    POSITION startAfter = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento de lista (pode ser uma referência).

*searchValue*<br/>
O valor a ser encontrado na lista.

*startAfter*<br/>
A posição inicial da pesquisa. Se nenhum valor for especificado, a pesquisa começa com o elemento principal.

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iteração ou recuperação de ponteiro de objeto; NULL se o objeto não for encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#39](../../mfc/codesnippet/cpp/clist-class_5.cpp)]

##  <a name="findindex"></a>  CList::FindIndex

Usa o valor de *nIndex* como um índice na lista.

```
POSITION FindIndex(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do elemento de lista a ser localizada.

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iteração ou recuperação de ponteiro de objeto; NULL se *nIndex* negativa ou muito grande.

### <a name="remarks"></a>Comentários

Iniciar uma verificação sequencial do início da lista, parando a *n*º elemento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#40](../../mfc/codesnippet/cpp/clist-class_6.cpp)]

##  <a name="getat"></a>  CList::GetAt

Obtém o elemento de lista em uma posição especificada.

```
TYPE& GetAt(POSITION position);
const TYPE& GetAt(POSITION position) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de objeto na lista.

*position*<br/>
A posição na lista do elemento a ser obtido.

### <a name="return-value"></a>Valor de retorno

Consulte a descrição do valor de retorno de `GetHead`.

### <a name="remarks"></a>Comentários

`GetAt` Retorna o elemento (ou uma referência ao elemento) associada a uma determinada posição. Não é o mesmo que um índice, e você não pode operar em um valor da posição que você mesmo. Uma variável do tipo de posição é uma chave para a lista.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CList::GetHeadPosition](#getheadposition).

##  <a name="getcount"></a>  CList::GetCount

Obtém o número de elementos nesta lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor inteiro que contém a contagem de elementos.

### <a name="remarks"></a>Comentários

Chamar esse método gerará o mesmo resultado que o [CList::GetSize](#getsize) método.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CList::RemoveHead](#removehead).

##  <a name="gethead"></a>  CList::GetHead

Obtém o elemento head (ou uma referência para o elemento head) dessa lista.

```
const TYPE& GetHead() const;

TYPE& GetHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de objeto na lista.

### <a name="return-value"></a>Valor de retorno

Se a lista estiver **const**, `GetHead` retorna uma cópia do elemento no início da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.

Se a lista não estiver **const**, `GetHead` retorna uma referência ao elemento no início da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#41](../../mfc/codesnippet/cpp/clist-class_7.cpp)]

##  <a name="getheadposition"></a>  CList::GetHeadPosition

Obtém a posição do elemento principal dessa lista.

```
POSITION GetHeadPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iteração ou recuperação de ponteiro de objeto; NULL se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#42](../../mfc/codesnippet/cpp/clist-class_8.cpp)]

##  <a name="getnext"></a>  CList::GetNext

Obtém o elemento de lista, identificado pelo *rPosition*, em seguida, define *rPosition* para o valor da posição da próxima entrada na lista.

```
TYPE& GetNext(POSITION& rPosition);
const TYPE& GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo que especifica o tipo dos elementos na lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma anterior `GetNext`, [GetHeadPosition](#getheadposition), ou outra chamada de função de membro.

### <a name="return-value"></a>Valor de retorno

Se a lista estiver **const**, `GetNext` retorna uma cópia de um elemento da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.

Se a lista não estiver **const**, `GetNext` retorna uma referência a um elemento da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você pode usar `GetNext` em um loop de iteração, se você estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou `Find`.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Se o elemento recuperado é o último na lista, em seguida, o novo valor da `rPosition` é definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#43](../../mfc/codesnippet/cpp/clist-class_9.cpp)]

##  <a name="getprev"></a>  CList::GetPrev

Obtém o elemento de lista, identificado pelo `rPosition`, em seguida, define `rPosition` para o valor da posição da entrada anterior na lista.

```
TYPE& GetPrev(POSITION& rPosition);
const TYPE& GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo que especifica o tipo dos elementos na lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma anterior `GetPrev` ou outra chamada de função de membro.

### <a name="return-value"></a>Valor de retorno

Se a lista estiver **const**, `GetPrev` retorna uma cópia do elemento no início da lista. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e protege a lista de modificação.

Se a lista não estiver **const**, `GetPrev` retorna uma referência a um elemento da lista. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você pode usar `GetPrev` em um loop de iteração inversa se a posição inicial com uma chamada para estabelecer `GetTailPosition` ou `Find`.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Se o elemento recuperado é o primeiro na lista, em seguida, o novo valor de *rPosition* é definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#44](../../mfc/codesnippet/cpp/clist-class_10.cpp)]

##  <a name="getsize"></a>  CList::GetSize

Retorna o número de elementos da lista.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens na lista.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos na lista.  Chamar esse método gerará o mesmo resultado que o [CList::GetCount](#getcount) método.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#45](../../mfc/codesnippet/cpp/clist-class_11.cpp)]

##  <a name="gettail"></a>  CList::GetTail

Obtém o `CObject` ponteiro que representa o elemento da parte final desta lista.

```
TYPE& GetTail();
const TYPE& GetTail() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos na lista.

### <a name="return-value"></a>Valor de retorno

Consulte a descrição do valor de retorno de [GetHead](../../mfc/reference/coblist-class.md#gethead).

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#46](../../mfc/codesnippet/cpp/clist-class_12.cpp)]

##  <a name="gettailposition"></a>  CList::GetTailPosition

Obtém a posição do elemento da parte final desta lista; NULL se a lista estiver vazia.

```
POSITION GetTailPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iteração ou recuperação de ponteiro de objeto; NULL se a lista estiver vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#47](../../mfc/codesnippet/cpp/clist-class_13.cpp)]

##  <a name="insertafter"></a>  CList::InsertAfter

Adiciona um elemento a essa lista após o elemento na posição especificada.

```
POSITION InsertAfter(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*position*<br/>
Um valor de posição retornado por uma anterior `GetNext`, `GetPrev`, ou `Find` chamada de função de membro.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elemento de lista.

*newElement*<br/>
O elemento a ser adicionado a essa lista.

### <a name="return-value"></a>Valor de retorno

Um valor de posição que pode ser usado para recuperação de elemento de iteração ou lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#48](../../mfc/codesnippet/cpp/clist-class_14.cpp)]

##  <a name="insertbefore"></a>  CList::InsertBefore

Adiciona um elemento a essa lista antes do elemento na posição especificada.

```
POSITION InsertBefore(POSITION position, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*position*<br/>
Um valor de posição retornado por uma anterior `GetNext`, `GetPrev`, ou `Find` chamada de função de membro.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento de lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado a essa lista.

### <a name="return-value"></a>Valor de retorno

Um valor de posição que pode ser usado para recuperação de elemento de iteração ou lista.

### <a name="remarks"></a>Comentários

Se *posição* for NULL, o elemento é inserido no início da lista.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#49](../../mfc/codesnippet/cpp/clist-class_15.cpp)]

##  <a name="isempty"></a>  CList::IsEmpty

Indica se esta lista não contiver elementos.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a lista estiver vazia; Caso contrário, 0.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#50](../../mfc/codesnippet/cpp/clist-class_16.cpp)]

##  <a name="removeall"></a>  CList::RemoveAll

Remove todos os elementos dessa lista e libera a memória associada.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Nenhum erro será gerado se a lista já está vazia.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#51](../../mfc/codesnippet/cpp/clist-class_17.cpp)]

##  <a name="removeat"></a>  CList::RemoveAt

Remove o elemento especificado dessa lista.

```
void RemoveAt(POSITION position);
```

### <a name="parameters"></a>Parâmetros

*position*<br/>
A posição do elemento a ser removido da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#52](../../mfc/codesnippet/cpp/clist-class_18.cpp)]

##  <a name="removehead"></a>  CList::RemoveHead

Remove o elemento do cabeçalho da lista e retorna um ponteiro para ele.

```
TYPE RemoveHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos na lista.

### <a name="return-value"></a>Valor de retorno

O elemento anteriormente no topo da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#53](../../mfc/codesnippet/cpp/clist-class_19.cpp)]

##  <a name="removetail"></a>  CList::RemoveTail

Remove o elemento do final da lista e retorna um ponteiro para ele.

```
TYPE RemoveTail();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos na lista.

### <a name="return-value"></a>Valor de retorno

O elemento que estava na parte final da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#54](../../mfc/codesnippet/cpp/clist-class_20.cpp)]

##  <a name="setat"></a>  CList::SetAt

Uma variável do tipo de posição é uma chave para a lista.

```
void SetAt(POSITION pos, ARG_TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
A posição do elemento a ser definido.

*ARG_TYPE*<br/>
Parâmetro de modelo que especifica o tipo do elemento de lista (pode ser uma referência).

*newElement*<br/>
O elemento a ser adicionado à lista.

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor da posição que você mesmo. `SetAt` grava o elemento para a posição especificada na lista.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#55](../../mfc/codesnippet/cpp/clist-class_21.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMap](../../mfc/reference/cmap-class.md)<br/>
[Classe CArray](../../mfc/reference/carray-class.md)
