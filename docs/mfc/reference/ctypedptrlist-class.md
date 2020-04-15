---
title: Classe CTypedPtrList
ms.date: 11/04/2016
f1_keywords:
- CTypedPtrList
- AFXTEMPL/CTypedPtrList
- AFXTEMPL/CTypedPtrList::AddHead
- AFXTEMPL/CTypedPtrList::AddTail
- AFXTEMPL/CTypedPtrList::GetAt
- AFXTEMPL/CTypedPtrList::GetHead
- AFXTEMPL/CTypedPtrList::GetNext
- AFXTEMPL/CTypedPtrList::GetPrev
- AFXTEMPL/CTypedPtrList::GetTail
- AFXTEMPL/CTypedPtrList::RemoveHead
- AFXTEMPL/CTypedPtrList::RemoveTail
- AFXTEMPL/CTypedPtrList::SetAt
helpviewer_keywords:
- CTypedPtrList [MFC], AddHead
- CTypedPtrList [MFC], AddTail
- CTypedPtrList [MFC], GetAt
- CTypedPtrList [MFC], GetHead
- CTypedPtrList [MFC], GetNext
- CTypedPtrList [MFC], GetPrev
- CTypedPtrList [MFC], GetTail
- CTypedPtrList [MFC], RemoveHead
- CTypedPtrList [MFC], RemoveTail
- CTypedPtrList [MFC], SetAt
ms.assetid: c273096e-1756-4340-864b-4a08b674a65e
ms.openlocfilehash: 40dbfb822e71309e9675aba14d46d333ffa4ee06
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373273"
---
# <a name="ctypedptrlist-class"></a>Classe CTypedPtrList

Fornece um "invólucro" seguro `CPtrList`para objetos de classe .

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class TYPE>
class CTypedPtrList : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Classe base da classe de ponteiro digitado; deve ser uma classe `CObList` `CPtrList`de lista de ponteiros (ou ).

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrLista::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao cabeça da lista (faz uma nova cabeça).|
|[CTypedPtrList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à cauda da lista (faz uma nova cauda).|
|[CTypedPtrList::GetAt](#getat)|Obtém o elemento em uma determinada posição.|
|[CTypedPtrList::GetHead](#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|
|[CTypedPtrList::GetNext](#getnext)|Recebe o próximo elemento para iteração.|
|[CTypedPtrList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|
|[CTypedPtrList::GetTail](#gettail)|Retorna o elemento de cauda da lista (não pode estar vazio).|
|[CTypedPtrLista::Cabeça de remoção](#removehead)|Remove o elemento da cabeça da lista.|
|[CTypedPtrLista::RemoveTail](#removetail)|Remove o elemento da cauda da lista.|
|[CTypedPtrList::SetAt](#setat)|Define o elemento em uma determinada posição.|

## <a name="remarks"></a>Comentários

Quando você `CTypedPtrList` usa `CObList` `CPtrList`em vez de ou , o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiros incompatíveis.

Além disso, `CTypedPtrList` o invólucro executa grande parte `CObList` `CPtrList`do casting que seria necessário se você usou ou .

Como `CTypedPtrList` todas as funções são inline, o uso deste modelo não afeta significativamente o tamanho ou a velocidade do seu código.

Listas derivadas `CObList` podem ser serializadas, `CPtrList` mas aquelas derivadas não podem.

Quando `CTypedPtrList` um objeto é excluído ou quando seus elementos são removidos, apenas os ponteiros são removidos, não as entidades que eles referenciam.

Para obter mais `CTypedPtrList`informações sobre o uso, consulte os artigos Coleções e Classes [Baseadas](../../mfc/collections.md) [em Modelos](../../mfc/template-based-classes.md).

## <a name="example"></a>Exemplo

Este exemplo cria `CTypedPtrList`uma instância de , adiciona um objeto, serializa a lista em disco e, em seguida, exclui o objeto:

[!code-cpp[NVC_MFCCollections#110](../../mfc/codesnippet/cpp/ctypedptrlist-class_1.cpp)]

[!code-cpp[NVC_MFCCollections#111](../../mfc/codesnippet/cpp/ctypedptrlist-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`_CTypedPtrList`

`CTypedPtrList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="ctypedptrlistaddhead"></a><a name="addhead"></a>CTypedPtrLista::AddHead

Esta função `BASE_CLASS`de membro chama **::AddHead**.

```
POSITION AddHead(TYPE newElement);
void AddHead(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta lista. Um valor NULA é permitido.

*Base_class*<br/>
Classe base da classe de ponteiro digitado; deve ser uma classe de lista de ponteiros [(CObList](../../mfc/reference/coblist-class.md) ou [CPtrList).](../../mfc/reference/cptrlist-class.md)

*pNewList*<br/>
Um ponteiro para outro objeto [CTypedPtrList.](../../mfc/reference/ctypedptrlist-class.md) Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A primeira versão adiciona um novo elemento antes do chefe da lista. A segunda versão adiciona outra lista de elementos antes da cabeça.

## <a name="ctypedptrlistaddtail"></a><a name="addtail"></a>CTypedPtrList::AddTail

Esta função `BASE_CLASS`de membro chama **::AddTail**.

```
POSITION AddTail(TYPE newElement);
void AddTail(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta lista. Um valor NULA é permitido.

*Base_class*<br/>
Classe base da classe de ponteiro digitado; deve ser uma classe de lista de ponteiros [(CObList](../../mfc/reference/coblist-class.md) ou [CPtrList).](../../mfc/reference/cptrlist-class.md)

*pNewList*<br/>
Um ponteiro para outro objeto [CTypedPtrList.](../../mfc/reference/ctypedptrlist-class.md) Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A primeira versão adiciona um novo elemento após a cauda da lista. A segunda versão adiciona outra lista de elementos após a cauda da lista.

## <a name="ctypedptrlistgetat"></a><a name="getat"></a>CTypedPtrList::GetAt

Uma variável do tipo POSIÇÃO é uma chave para a lista.

```
TYPE& GetAt(POSITION position);
TYPE GetAt(POSITION position) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na lista.

*Posição*<br/>
Um valor DE POSIÇÃO `GetHeadPosition` retornado por uma chamada de função anterior ou `Find` membro.

### <a name="return-value"></a>Valor retornado

Se a lista for acessada através de um ponteiro para a, `const CTypedPtrList`então `GetAt` retorne um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CTypedPtrList`diretamente `GetAt` ou através de um ponteiro para um , então retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. `GetAt`recupera o `CObject` ponteiro associado a uma determinada posição.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Esta função inline `BASE_CLASS` **chama::GetAt**.

## <a name="ctypedptrlistgethead"></a><a name="gethead"></a>CTypedPtrList::GetHead

Obtém o ponteiro que representa o elemento principal desta lista.

```
TYPE& GetHead();
TYPE GetHead() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na lista.

### <a name="return-value"></a>Valor retornado

Se a lista for acessada através de um ponteiro para a, `const CTypedPtrList`então `GetHead` retorne um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CTypedPtrList`diretamente `GetHead` ou através de um ponteiro para um , então retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

## <a name="ctypedptrlistgetnext"></a><a name="getnext"></a>CTypedPtrList::GetNext

Obtém o elemento de lista identificado por *rPosition,* em seguida, define *rPosição* para o valor DE POSIÇÃO da próxima entrada na lista.

```
TYPE& GetNext(POSITION& rPosition);
TYPE GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos contidos nesta lista.

*Rposition*<br/>
Uma referência a um valor DE `GetNext` `GetHeadPosition`POSIÇÃO retornado por uma chamada de função anterior ou de outro membro.

### <a name="return-value"></a>Valor retornado

Se a lista for acessada através de um ponteiro para a, `const CTypedPtrList`então `GetNext` retorne um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CTypedPtrList`diretamente `GetNext` ou através de um ponteiro para um , então retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode `GetNext` usar em um loop de iteração para `GetHeadPosition` frente se estabelecer a posição inicial com uma chamada para ou [CPtrList::Encontrar](../../mfc/reference/coblist-class.md#find).

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o último da lista, então o novo valor de *rPosição* será definido como NULL.

É possível remover um elemento durante uma iteração. Veja o exemplo de [CObList::RemoveAt](../../mfc/reference/coblist-class.md#removeat).

## <a name="ctypedptrlistgetprev"></a><a name="getprev"></a>CTypedPtrList::GetPrev

Obtém o elemento de lista identificado por *rPosition,* em seguida, define *rPosição* para o valor DE POSIÇÃO da entrada anterior na lista.

```
TYPE& GetPrev(POSITION& rPosition);
TYPE GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos contidos nesta lista.

*Rposition*<br/>
Uma referência a um valor DE `GetPrev` POSIÇÃO retornado por uma chamada de função anterior ou de outro membro.

### <a name="return-value"></a>Valor retornado

Se a lista for acessada através de um ponteiro para a, `const CTypedPtrList`então `GetPrev` retorne um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CTypedPtrList`diretamente `GetPrev` ou através de um ponteiro para um , então retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você pode `GetPrev` usar em um loop de iteração reversa `GetTailPosition` `Find`se estabelecer a posição inicial com uma chamada para ou .

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o primeiro da lista, então o novo valor de *rPosition* será definido como NULL.

## <a name="ctypedptrlistgettail"></a><a name="gettail"></a>CTypedPtrList::GetTail

Obtém o ponteiro que representa o elemento principal desta lista.

```
TYPE& GetTail();
TYPE GetTail() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na lista.

### <a name="return-value"></a>Valor retornado

Se a lista for acessada através de um ponteiro para a, `const CTypedPtrList`então `GetTail` retorne um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CTypedPtrList`diretamente `GetTail` ou através de um ponteiro para um , então retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *TYPE*. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

## <a name="ctypedptrlistremovehead"></a><a name="removehead"></a>CTypedPtrLista::Cabeça de remoção

Remove o elemento da cabeça da lista e devolve-o.

```
TYPE RemoveHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na lista.

### <a name="return-value"></a>Valor retornado

O ponteiro anteriormente no cabeça da lista. Este ponteiro é do tipo especificado pelo parâmetro modelo *TYPE*.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

## <a name="ctypedptrlistremovetail"></a><a name="removetail"></a>CTypedPtrLista::RemoveTail

Remove o elemento da cauda da lista e devolve-o.

```
TYPE RemoveTail();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na lista.

### <a name="return-value"></a>Valor retornado

O ponteiro anteriormente na cauda da lista. Este ponteiro é do tipo especificado pelo parâmetro modelo *TYPE*.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

## <a name="ctypedptrlistsetat"></a><a name="setat"></a>CTypedPtrList::SetAt

Esta função `BASE_CLASS`de membro chama **::SetAt**.

```
void SetAt(POSITION pos, TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
A posição do elemento a ser definido.

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*Newelement*<br/>
O ponteiro do objeto a ser escrito na lista.

### <a name="remarks"></a>Comentários

Uma variável do tipo POSIÇÃO é uma chave para a lista. Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. `SetAt`escreve o ponteiro do objeto para a posição especificada na lista.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Para obter observações mais detalhadas, consulte [CObList::SetAt](../../mfc/reference/coblist-class.md#setat).

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPtrList](../../mfc/reference/cptrlist-class.md)<br/>
[Classe CObList](../../mfc/reference/coblist-class.md)
