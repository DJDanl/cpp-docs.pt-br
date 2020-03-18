---
title: Classe CStringlist
ms.date: 11/04/2016
f1_keywords:
- CStringList
- AFXCOLL/CStringList
- AFXCOLL/CStringList::CStringList
- AFXCOLL/CStringList::AddHead
- AFXCOLL/CStringList::AddTail
- AFXCOLL/CStringList::Find
- AFXCOLL/CStringList::FindIndex
- AFXCOLL/CStringList::GetAt
- AFXCOLL/CStringList::GetCount
- AFXCOLL/CStringList::GetHead
- AFXCOLL/CStringList::GetHeadPosition
- AFXCOLL/CStringList::GetNext
- AFXCOLL/CStringList::GetPrev
- AFXCOLL/CStringList::GetSize
- AFXCOLL/CStringList::GetTail
- AFXCOLL/CStringList::GetTailPosition
- AFXCOLL/CStringList::InsertAfter
- AFXCOLL/CStringList::InsertBefore
- AFXCOLL/CStringList::IsEmpty
- AFXCOLL/CStringList::RemoveAll
- AFXCOLL/CStringList::RemoveAt
- AFXCOLL/CStringList::RemoveHead
- AFXCOLL/CStringList::RemoveTail
- AFXCOLL/CStringList::SetAt
helpviewer_keywords:
- CStringList [MFC], CStringList
- CStringList [MFC], AddHead
- CStringList [MFC], AddTail
- CStringList [MFC], Find
- CStringList [MFC], FindIndex
- CStringList [MFC], GetAt
- CStringList [MFC], GetCount
- CStringList [MFC], GetHead
- CStringList [MFC], GetHeadPosition
- CStringList [MFC], GetNext
- CStringList [MFC], GetPrev
- CStringList [MFC], GetSize
- CStringList [MFC], GetTail
- CStringList [MFC], GetTailPosition
- CStringList [MFC], InsertAfter
- CStringList [MFC], InsertBefore
- CStringList [MFC], IsEmpty
- CStringList [MFC], RemoveAll
- CStringList [MFC], RemoveAt
- CStringList [MFC], RemoveHead
- CStringList [MFC], RemoveTail
- CStringList [MFC], SetAt
ms.assetid: 310a7edb-263c-4bd2-ac43-0bfbfddc5a33
ms.openlocfilehash: 9eb7a713fc02cd3e51135d1985a41688d4c885d9
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447552"
---
# <a name="cstringlist-class"></a>Classe CStringlist

Dá suporte a listas de objetos de `CString`.

## <a name="syntax"></a>Sintaxe

```
class CStringList : public CObject
```

## <a name="members"></a>Membros

As funções de membro de `CStringList` são semelhantes às funções de membro da classe [CObList](../../mfc/reference/coblist-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObList` para obter a função específica de membro. Sempre que você vir um ponteiro `CObject` como um valor de retorno, substitua um `CString` (não um ponteiro `CString`). Sempre que você vir um ponteiro `CObject` como um parâmetro de função, substitua um `LPCTSTR`.

`CObject*& CObList::GetHead() const;`

por exemplo, traduz para

`CString& CStringList::GetHead() const;`

e

`POSITION AddHead( CObject* <newElement> );`

traduz para

`POSITION AddHead( LPCTSTR <newElement> );`

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CStringlist:: CStringlist](../../mfc/reference/coblist-class.md#coblist)|Constrói uma lista vazia.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CStringlist:: AddHead](../../mfc/reference/coblist-class.md#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao início da lista (cria um novo cabeçalho).|
|[CStringlist:: addcaudal](../../mfc/reference/coblist-class.md#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à parte final da lista (cria uma nova cauda).|
|[CStringlist:: localizar](../../mfc/reference/coblist-class.md#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CStringlist:: FindIndex](../../mfc/reference/coblist-class.md#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CStringlist:: GetAt](../../mfc/reference/coblist-class.md#getat)|Obtém o elemento em uma determinada posição.|
|[CStringlist:: GetCount](../../mfc/reference/coblist-class.md#getcount)|Retorna o número de elementos nesta lista.|
|[CStringlist:: GetHead](../../mfc/reference/coblist-class.md#gethead)|Retorna o elemento head da lista (não pode estar vazio).|
|[CStringlist:: GetHeadPosition](../../mfc/reference/coblist-class.md#getheadposition)|Retorna a posição do elemento de cabeçalho da lista.|
|[CStringlist:: GetNext](../../mfc/reference/coblist-class.md#getnext)|Obtém o próximo elemento para iteração.|
|[CStringlist:: getantd](../../mfc/reference/coblist-class.md#getprev)|Obtém o elemento anterior para iteração.|
|[CStringlist:: GetSize](../../mfc/reference/coblist-class.md#getsize)|Retorna o número de elementos nesta lista.|
|[CStringlist:: getcaudal](../../mfc/reference/coblist-class.md#gettail)|Retorna o elemento tail da lista (não pode estar vazio).|
|[CStringlist:: GetTailPosition](../../mfc/reference/coblist-class.md#gettailposition)|Retorna a posição do elemento de cauda da lista.|
|[CStringlist:: InsertAfter](../../mfc/reference/coblist-class.md#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CStringlist:: InsertBefore](../../mfc/reference/coblist-class.md#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[CStringlist:: IsEmpty](../../mfc/reference/coblist-class.md#isempty)|Testes para a condição de lista vazia (sem elementos).|
|[CStringlist:: RemoveAll](../../mfc/reference/coblist-class.md#removeall)|Remove todos os elementos dessa lista.|
|[CStringlist:: RemoveAt](../../mfc/reference/coblist-class.md#removeat)|Remove um elemento desta lista, especificado pela posição.|
|[CStringlist:: RemoveHead](../../mfc/reference/coblist-class.md#removehead)|Remove o elemento do início da lista.|
|[CStringlist:: RemoveTail](../../mfc/reference/coblist-class.md#removetail)|Remove o elemento da parte final da lista.|
|[CStringlist:: SetAt](../../mfc/reference/coblist-class.md#setat)|Define o elemento em uma determinada posição.|

## <a name="remarks"></a>Comentários

Todas as comparações são feitas por valor, o que significa que os caracteres na cadeia de caracteres são comparados, em vez dos endereços das cadeias.

`CStringList` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e ao despejo de seus elementos. Se uma lista de objetos de `CString` for armazenada em um arquivo morto, com um operador de inserção sobrecarregado ou com a função de membro `Serialize`, cada elemento `CString` será serializado por vez.

Se você precisar de um despejo de elementos de `CString` individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Para obter mais informações sobre como usar `CStringList`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CStringList`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Consulte também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
