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
ms.openlocfilehash: 756ef5043468f614c6ab3ac64598d62b29b2dc41
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57286017"
---
# <a name="ctypedptrlist-class"></a>Classe CTypedPtrList

Fornece um "wrapper" de tipo seguro para objetos da classe `CPtrList`.

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class TYPE>
class CTypedPtrList : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Classe base da classe de lista de ponteiro tipado; deve ser uma classe de lista de ponteiro ( `CObList` ou `CPtrList`).

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) para o cabeçalho da lista (faz um novo cabeçalho).|
|[CTypedPtrList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) para a parte final da lista (faz uma cauda novo).|
|[CTypedPtrList::GetAt](#getat)|Obtém o elemento na posição especificada.|
|[CTypedPtrList::GetHead](#gethead)|Retorna o elemento de cabeçalho da lista (não pode estar vazia).|
|[CTypedPtrList::GetNext](#getnext)|Obtém o próximo elemento para a iteração.|
|[CTypedPtrList::GetPrev](#getprev)|Obtém o elemento anterior para a iteração.|
|[CTypedPtrList::GetTail](#gettail)|Retorna o elemento final da lista (não pode estar vazia).|
|[CTypedPtrList::RemoveHead](#removehead)|Remove o elemento do cabeçalho da lista.|
|[CTypedPtrList::RemoveTail](#removetail)|Remove o elemento do final da lista.|
|[CTypedPtrList::SetAt](#setat)|Define o elemento na posição especificada.|

## <a name="remarks"></a>Comentários

Quando você usa `CTypedPtrList` em vez de `CObList` ou `CPtrList`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.

Além disso, o `CTypedPtrList` wrapper executa muito da conversão que seria necessária se você usou `CObList` ou `CPtrList`.

Porque todos os `CTypedPtrList` funções são embutidos, uso deste modelo não afeta significativamente o tamanho ou velocidade do seu código.

Listas derivam `CObList` pode ser serializada, mas aquelas derivadas `CPtrList` não é possível.

Quando um `CTypedPtrList` objeto é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que fazem referência.

Para obter mais informações sobre como usar `CTypedPtrList`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).

## <a name="example"></a>Exemplo

Este exemplo cria uma instância de `CTypedPtrList`, adiciona um objeto, serializa a lista para o disco e, em seguida, exclui o objeto:

[!code-cpp[NVC_MFCCollections#110](../../mfc/codesnippet/cpp/ctypedptrlist-class_1.cpp)]

[!code-cpp[NVC_MFCCollections#111](../../mfc/codesnippet/cpp/ctypedptrlist-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`_CTypedPtrList`

`CTypedPtrList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

##  <a name="addhead"></a>  CTypedPtrList::AddHead

Essa função membro chama `BASE_CLASS` **:: AddHead**.

```
POSITION AddHead(TYPE newElement);
void AddHead(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a essa lista. Um valor NULL é permitido.

*BASE_CLASS*<br/>
Classe base da classe de lista de ponteiro tipado; deve ser uma classe de lista de ponteiro ( [CObList](../../mfc/reference/coblist-class.md) ou [CPtrList](../../mfc/reference/cptrlist-class.md)).

*pNewList*<br/>
Um ponteiro para outro [CTypedPtrList](../../mfc/reference/ctypedptrlist-class.md) objeto. Os elementos na *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna o valor da posição do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A primeira versão adiciona um novo elemento antes do cabeçalho da lista. A segunda versão adiciona outra lista de elementos antes do cabeçalho.

##  <a name="addtail"></a>  CTypedPtrList::AddTail

Essa função membro chama `BASE_CLASS` **:: AddTail**.

```
POSITION AddTail(TYPE newElement);
void AddTail(CTypedPtrList<BASE_CLASS, TYPE>* pNewList);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a essa lista. Um valor NULL é permitido.

*BASE_CLASS*<br/>
Classe base da classe de lista de ponteiro tipado; deve ser uma classe de lista de ponteiro ( [CObList](../../mfc/reference/coblist-class.md) ou [CPtrList](../../mfc/reference/cptrlist-class.md)).

*pNewList*<br/>
Um ponteiro para outro [CTypedPtrList](../../mfc/reference/ctypedptrlist-class.md) objeto. Os elementos na *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor de retorno

A primeira versão retorna o valor da posição do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A primeira versão adiciona um novo elemento após o final da lista. A segunda versão adiciona outra lista de elementos após o final da lista.

##  <a name="getat"></a>  CTypedPtrList::GetAt

Uma variável do tipo de posição é uma chave para a lista.

```
TYPE& GetAt(POSITION position);
TYPE GetAt(POSITION position) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos armazenados na lista.

*position*<br/>
Um valor de posição retornado por uma anterior `GetHeadPosition` ou `Find` chamada de função de membro.

### <a name="return-value"></a>Valor de retorno

Se a lista é acessada por meio de um ponteiro para um `const CTypedPtrList`, em seguida, `GetAt` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.

Se a lista for acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetAt` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor da posição que você mesmo. `GetAt` recupera o `CObject` ponteiro associado a uma determinada posição.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Essa função embutida chama `BASE_CLASS` **:: GetAt**.

##  <a name="gethead"></a>  CTypedPtrList::GetHead

Obtém o ponteiro que representa o elemento principal dessa lista.

```
TYPE& GetHead();
TYPE GetHead() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos armazenados na lista.

### <a name="return-value"></a>Valor de retorno

Se a lista é acessada por meio de um ponteiro para um `const CTypedPtrList`, em seguida, `GetHead` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.

Se a lista for acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetHead` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

##  <a name="getnext"></a>  CTypedPtrList::GetNext

Obtém o elemento de lista, identificado pelo *rPosition*, em seguida, define *rPosition* para o valor da posição da próxima entrada na lista.

```
TYPE& GetNext(POSITION& rPosition);
TYPE GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos contidos nessa lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma anterior `GetNext`, `GetHeadPosition`, ou outra chamada de função de membro.

### <a name="return-value"></a>Valor de retorno

Se a lista é acessada por meio de um ponteiro para um `const CTypedPtrList`, em seguida, `GetNext` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.

Se a lista for acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetNext` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você pode usar `GetNext` em um loop de iteração, se você estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou [CPtrList::Find](../../mfc/reference/coblist-class.md#find).

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Se o elemento recuperado é o último na lista, em seguida, o novo valor da *rPosition* é definido como NULL.

É possível remover um elemento durante uma iteração. Veja o exemplo de [CObList::RemoveAt](../../mfc/reference/coblist-class.md#removeat).

##  <a name="getprev"></a>  CTypedPtrList::GetPrev

Obtém o elemento de lista, identificado pelo *rPosition*, em seguida, define *rPosition* para o valor da posição da entrada anterior na lista.

```
TYPE& GetPrev(POSITION& rPosition);
TYPE GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos contidos nessa lista.

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma anterior `GetPrev` ou outra chamada de função de membro.

### <a name="return-value"></a>Valor de retorno

Se a lista é acessada por meio de um ponteiro para um `const CTypedPtrList`, em seguida, `GetPrev` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.

Se a lista for acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetPrev` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você pode usar `GetPrev` em um loop de iteração inversa se a posição inicial com uma chamada para estabelecer `GetTailPosition` ou `Find`.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Se o elemento recuperado é o primeiro na lista, em seguida, o novo valor de *rPosition* é definido como NULL.

##  <a name="gettail"></a>  CTypedPtrList::GetTail

Obtém o ponteiro que representa o elemento principal dessa lista.

```
TYPE& GetTail();
TYPE GetTail() const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos armazenados na lista.

### <a name="return-value"></a>Valor de retorno

Se a lista é acessada por meio de um ponteiro para um `const CTypedPtrList`, em seguida, `GetTail` retorna um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usada apenas no lado direito de uma instrução de atribuição e, portanto, protege a lista de modificação.

Se a lista for acessada diretamente ou através de um ponteiro para um `CTypedPtrList`, em seguida, `GetTail` retorna uma referência a um ponteiro do tipo especificado pelo parâmetro de modelo *tipo*. Isso permite que a função a ser usado em ambos os lados de uma instrução de atribuição e, portanto, permite que as entradas da lista a ser modificado.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

##  <a name="removehead"></a>  CTypedPtrList::RemoveHead

Remove o elemento do cabeçalho da lista e o retorna.

```
TYPE RemoveHead();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos armazenados na lista.

### <a name="return-value"></a>Valor de retorno

O ponteiro anteriormente no topo da lista. Esse ponteiro é do tipo especificado pelo parâmetro de modelo *tipo*.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

##  <a name="removetail"></a>  CTypedPtrList::RemoveTail

Remove o elemento do final da lista e o retorna.

```
TYPE RemoveTail();
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo dos elementos armazenados na lista.

### <a name="return-value"></a>Valor de retorno

O ponteiro anteriormente na parte final da lista. Esse ponteiro é do tipo especificado pelo parâmetro de modelo *tipo*.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não estiver vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração da biblioteca de classes Microsoft Foundation declara. Use [IsEmpty](../../mfc/reference/coblist-class.md#isempty) para verificar se a lista contém elementos.

##  <a name="setat"></a>  CTypedPtrList::SetAt

Essa função membro chama `BASE_CLASS` **:: SetAt**.

```
void SetAt(POSITION pos, TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*pos*<br/>
A posição do elemento a ser definido.

*TIPO*<br/>
Tipo dos elementos armazenados na lista de classe base.

*newElement*<br/>
O ponteiro de objeto a ser gravado para a lista.

### <a name="remarks"></a>Comentários

Uma variável do tipo de posição é uma chave para a lista. Não é o mesmo que um índice, e você não pode operar em um valor da posição que você mesmo. `SetAt` grava o ponteiro de objeto para a posição especificada na lista.

Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.

Para obter comentários mais detalhadas, consulte [CObList::SetAt](../../mfc/reference/coblist-class.md#setat).

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe de CPtrList](../../mfc/reference/cptrlist-class.md)<br/>
[Classe CObList](../../mfc/reference/coblist-class.md)
