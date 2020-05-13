---
title: Classe CObList
ms.date: 11/04/2016
f1_keywords:
- CObList
- AFXCOLL/CObList
- AFXCOLL/CObList::CObList
- AFXCOLL/CObList::AddHead
- AFXCOLL/CObList::AddTail
- AFXCOLL/CObList::Find
- AFXCOLL/CObList::FindIndex
- AFXCOLL/CObList::GetAt
- AFXCOLL/CObList::GetCount
- AFXCOLL/CObList::GetHead
- AFXCOLL/CObList::GetHeadPosition
- AFXCOLL/CObList::GetNext
- AFXCOLL/CObList::GetPrev
- AFXCOLL/CObList::GetSize
- AFXCOLL/CObList::GetTail
- AFXCOLL/CObList::GetTailPosition
- AFXCOLL/CObList::InsertAfter
- AFXCOLL/CObList::InsertBefore
- AFXCOLL/CObList::IsEmpty
- AFXCOLL/CObList::RemoveAll
- AFXCOLL/CObList::RemoveAt
- AFXCOLL/CObList::RemoveHead
- AFXCOLL/CObList::RemoveTail
- AFXCOLL/CObList::SetAt
helpviewer_keywords:
- CObList [MFC], CObList
- CObList [MFC], AddHead
- CObList [MFC], AddTail
- CObList [MFC], Find
- CObList [MFC], FindIndex
- CObList [MFC], GetAt
- CObList [MFC], GetCount
- CObList [MFC], GetHead
- CObList [MFC], GetHeadPosition
- CObList [MFC], GetNext
- CObList [MFC], GetPrev
- CObList [MFC], GetSize
- CObList [MFC], GetTail
- CObList [MFC], GetTailPosition
- CObList [MFC], InsertAfter
- CObList [MFC], InsertBefore
- CObList [MFC], IsEmpty
- CObList [MFC], RemoveAll
- CObList [MFC], RemoveAt
- CObList [MFC], RemoveHead
- CObList [MFC], RemoveTail
- CObList [MFC], SetAt
ms.assetid: 80699c93-33d8-4f8b-b8cf-7b58aeab64ca
ms.openlocfilehash: f24965357e0b71f28ba39b82d045600e7e1a44e2
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749692"
---
# <a name="coblist-class"></a>Classe CObList

fSuporta listas ordenadas de `CObject` ponteiros não exclusivos acessíveis sequencialmente ou por valor de ponteiro.

## <a name="syntax"></a>Sintaxe

```
class CObList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObList::CObList](#coblist)|Constrói uma lista `CObject` vazia para ponteiros.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CObList::AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao cabeça da lista (faz uma nova cabeça).|
|[CObList::AddTail](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à cauda da lista (faz uma nova cauda).|
|[CObList::Encontrar](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CObList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CObList::GetAt](#getat)|Obtém o elemento em uma determinada posição.|
|[CObList::GetCount](#getcount)|Retorna o número de elementos nesta lista.|
|[CObList::GetHead](#gethead)|Retorna o elemento principal da lista (não pode estar vazio).|
|[CObList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento principal da lista.|
|[CObList::GetNext](#getnext)|Recebe o próximo elemento para iteração.|
|[CObList::GetPrev](#getprev)|Obtém o elemento anterior para iteração.|
|[CObList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|
|[CObList::GetTail](#gettail)|Retorna o elemento de cauda da lista (não pode estar vazio).|
|[CObList::GetTailPosition](#gettailposition)|Retorna a posição do elemento de cauda da lista.|
|[CObList::InserirApós](#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CObList::Inserirantes](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[CObList::IsEmpty](#isempty)|Testes para a condição de lista vazia (sem elementos).|
|[CObList::RemoveAll](#removeall)|Remove todos os elementos desta lista.|
|[CObList::RemoveAt](#removeat)|Remove um elemento desta lista, especificado por posição.|
|[CObList::RemoveHead](#removehead)|Remove o elemento da cabeça da lista.|
|[CObList::RemoveTail](#removetail)|Remove o elemento da cauda da lista.|
|[CObList::SetAt](#setat)|Define o elemento em uma determinada posição.|

## <a name="remarks"></a>Comentários

`CObList`listas se comportam como listas duplamente ligadas.

Uma variável do tipo POSIÇÃO é uma chave para a lista. Você pode usar uma variável POSITION tanto como um ativador para atravessar uma lista sequencialmente quanto como um marcador para manter um lugar. Uma posição não é o mesmo que um índice, no entanto.

A inserção do elemento é muito rápida na cabeça da lista, na cauda e em uma POSIÇÃO conhecida. Uma pesquisa seqüencial é necessária para procurar um elemento por valor ou índice. Essa pesquisa pode ser lenta se a lista for longa.

`CObList`incorpora a IMPLEMENT_SERIAL macro para apoiar a serialização e o dumping de seus elementos. Se uma `CObject` lista de ponteiros for armazenada em um arquivo, `Serialize` com um `CObject` operador de inserção sobrecarregado ou com a função de membro, cada elemento será serializado por sua vez.

Se você precisar de `CObject` um despejo de elementos individuais na lista, você deve definir a profundidade do contexto de despejo para 1 ou mais.

Quando `CObList` um objeto é excluído ou quando seus `CObject` elementos são removidos, apenas os ponteiros são removidos, não os objetos que eles referenciam.

Você pode derivar `CObList`suas próprias aulas de . Sua nova classe de lista, projetada para `CObject`manter ponteiros para objetos derivados, adiciona novos membros de dados e novas funções de membro. Observe que a lista resultante não é estritamente segura, pois permite a inserção de qualquer `CObject` ponteiro.

> [!NOTE]
> Você deve usar a [macro IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) na implementação de sua classe derivada se você pretende serializar a lista.

Para obter mais `CObList`informações sobre como usar, consulte o artigo [Coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CObList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll.h

## <a name="coblistaddhead"></a><a name="addhead"></a>CObList::AddHead

Adiciona um novo elemento ou lista de elementos ao chefe desta lista.

```
POSITION AddHead(CObject* newElement);
void AddHead(CObList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*Newelement*<br/>
O `CObject` ponteiro a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro `CObList` para outra lista. Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

A tabela a seguir mostra outras `CObList::AddHead`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSITION AddHead (vazio);** <strong>\*</strong> `newElement` **);**<br /><br /> **adicionar cabeça de efeito (CPtrList);** <strong>\*</strong> `pNewList` **);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSITION Addhead (const CString** `newElement` **&);**<br /><br /> **POSITION Addhead (LPCTSTR);** `newElement` **);**<br /><br /> **adicionar cabeça de efeito (CStringList);** <strong>\*</strong> `pNewList` **);**|

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#89](../../mfc/codesnippet/cpp/coblist-class_1.cpp)]

Os resultados deste programa são os seguintes:

```Output
AddHead example: A CObList with 2 elements
a CAge at $44A8 40
a CAge at $442A 21
```

## <a name="coblistaddtail"></a><a name="addtail"></a>CObList::AddTail

Adiciona um novo elemento ou lista de elementos à cauda desta lista.

```
POSITION AddTail(CObject* newElement);
void AddTail(CObList* pNewList);
```

### <a name="parameters"></a>Parâmetros

*Newelement*<br/>
O `CObject` ponteiro a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro `CObList` para outra lista. Os elementos em *pNewList* serão adicionados a esta lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor POSITION do elemento recém-inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

A tabela a seguir mostra outras `CObList::AddTail`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO AddTail (vazio);** <strong>\*</strong> `newElement` **);**<br /><br /> **void AddTail (CPtrList);** <strong>\*</strong> `pNewList` **);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSITION AddTail (const CString** `newElement` **&);**<br /><br /> **POSITION AddTail (LPCTSTR);** `newElement` **);**<br /><br /> **void AddTail (CStringList);** <strong>\*</strong> `pNewList` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#90](../../mfc/codesnippet/cpp/coblist-class_2.cpp)]

Os resultados deste programa são os seguintes:

```Output
AddTail example: A CObList with 2 elements
a CAge at $444A 21
a CAge at $4526 40
```

## <a name="coblistcoblist"></a><a name="coblist"></a>CObList::CObList

Constrói uma `CObject` lista de ponteiros vazias.

```
CObList(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
A granularidade de alocação de memória para estender a lista.

### <a name="remarks"></a>Comentários

À medida que a lista cresce, a memória é alocada em unidades de entradas *nBlockSize.* Se uma alocação `CMemoryException` de memória falhar, um será jogado.

A tabela a seguir mostra outras `CObList::CObList`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**CPtrList( INT_PTR** `nBlockSize` **= 10 );**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**CStringList( INT_PTR** `nBlockSize` **= 10 );**|

### <a name="example"></a>Exemplo

  Abaixo está uma `CObject`lista da `CAge` classe derivada usada em todos os exemplos de coleção:

[!code-cpp[NVC_MFCCollections#91](../../mfc/codesnippet/cpp/coblist-class_3.h)]

Abaixo está um `CObList` exemplo de uso do construtor:

[!code-cpp[NVC_MFCCollections#92](../../mfc/codesnippet/cpp/coblist-class_4.cpp)]

## <a name="coblistfind"></a><a name="find"></a>CObList::Encontrar

Pesquisa a lista sequencialmente para `CObject` encontrar o primeiro `CObject` ponteiro que corresponda ao ponteiro especificado.

```
POSITION Find(
    CObject* searchValue,
    POSITION startAfter = NULL) const;
```

### <a name="parameters"></a>Parâmetros

*searchValue*<br/>
O ponteiro do objeto a ser encontrado nesta lista.

*startAfter*<br/>
A posição inicial para a busca.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se o objeto não for encontrado.

### <a name="remarks"></a>Comentários

Observe que os valores do ponteiro são comparados, não o conteúdo dos objetos.

A tabela a seguir mostra outras `CObList::Find`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO Encontrar (vazio** <strong>\*</strong> `searchValue` **, POSIÇÃO** `startAfter` **= NULO ) const;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSIÇÃO Encontrar (LPCTSTR** `searchValue` **, POSIÇÃO** `startAfter` **= NULO ) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#93](../../mfc/codesnippet/cpp/coblist-class_5.cpp)]

## <a name="coblistfindindex"></a><a name="findindex"></a>CObList::FindIndex

Usa o valor do *nIndex* como um índice na lista.

```
POSITION FindIndex(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do elemento de lista a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULL se *nIndex* for muito grande. (O framework gera uma afirmação se *o nIndex* for negativo.)

### <a name="remarks"></a>Comentários

Ele inicia uma varredura seqüencial do chefe da lista, parando no *n*º elemento.

A tabela a seguir mostra outras `CObList::FindIndex`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSITION FindIndex (INT_PTR)** `nIndex` **const;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSITION FindIndex (INT_PTR)** `nIndex` **const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#94](../../mfc/codesnippet/cpp/coblist-class_6.cpp)]

## <a name="coblistgetat"></a><a name="getat"></a>CObList::GetAt

Uma variável do tipo POSIÇÃO é uma chave para a lista.

```
CObject*& GetAt(POSITION position);
const CObject*& GetAt(POSITION position) const;
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
Um valor DE POSIÇÃO `GetHeadPosition` retornado por uma chamada de função anterior ou `Find` membro.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. `GetAt`recupera o `CObject` ponteiro associado a uma determinada posição.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

A tabela a seguir mostra outras `CObList::GetAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**const\* void& GetAt (POSIÇÃO)** *position* **const;**<br /><br /> **vazio\*& GetAt (posição** *de* **posição);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**const CString& GetAt (posição de posição)** *position* **const;**<br /><br /> **CString& GetAt (posição** *de posição);* **);**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [FindIndex](#findindex).

## <a name="coblistgetcount"></a><a name="getcount"></a>CObList::GetCount

Obtém o número de elementos nesta lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro contendo a contagem de elementos.

A tabela a seguir mostra outras `CObList::GetCount`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**INT_PTR GetCount;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**INT_PTR GetCount;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#95](../../mfc/codesnippet/cpp/coblist-class_7.cpp)]

## <a name="coblistgethead"></a><a name="gethead"></a>CObList::GetHead

Obtém `CObject` o ponteiro que representa o elemento principal desta lista.

```
CObject*& GetHead();
const CObject*& GetHead() const;
```

### <a name="return-value"></a>Valor retornado

Se a lista for acessada `GetHead` através `CObject` de um ponteiro para a `const CObList`, então retorne um ponteiro. Isso permite que a função seja usada apenas no lado direito de uma declaração de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada `CObList`diretamente `GetHead` ou através de `CObject` um ponteiro para um , então retorne uma referência a um ponteiro. Isso permite que a função seja usada em ambos os lados de uma declaração de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras `CObList::GetHead`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**const\* vazio& GetHead; vazio\*& GetHead( );**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**const CString& GetHead; CString& GetHead( );**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

O exemplo a seguir `GetHead` ilustra o uso do lado esquerdo de uma declaração de atribuição.

[!code-cpp[NVC_MFCCollections#96](../../mfc/codesnippet/cpp/coblist-class_8.cpp)]

## <a name="coblistgetheadposition"></a><a name="getheadposition"></a>CObList::GetHeadPosition

Obtém a posição do elemento principal desta lista.

```
POSITION GetHeadPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

A tabela a seguir mostra outras `CObList::GetHeadPosition`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO GetHeadPosition;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSIÇÃO GetHeadPosition;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#97](../../mfc/codesnippet/cpp/coblist-class_9.cpp)]

## <a name="coblistgetnext"></a><a name="getnext"></a>CObList::GetNext

Obtém o elemento de lista identificado por `POSITION` *rPosition,* em seguida, define *rPosição* para o valor da próxima entrada na lista.

```
CObject*& GetNext(POSITION& rPosition);
const CObject* GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*Rposition*<br/>
Uma referência a um valor DE `GetNext` `GetHeadPosition`POSIÇÃO retornado por uma chamada de função anterior ou de outro membro.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você pode `GetNext` usar em um loop de iteração para `GetHeadPosition` frente `Find`se estabelecer a posição inicial com uma chamada para ou .

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o último da lista, então o novo valor de *rPosição* será definido como NULL.

É possível remover um elemento durante uma iteração. Veja o exemplo de [RemoveAt](#removeat).

> [!NOTE]
> A partir do MFC 8.0, a versão `const CObject*` const `const CObject*&`deste método mudou para retornar em vez de .  Essa mudança foi feita para colocar o compilador em conformidade com o padrão C++.

A tabela a seguir mostra outras `CObList::GetNext`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|`void*& GetNext( POSITION&` `rPosition` `);`<br /><br /> `const void* GetNext( POSITION&` `rPosition` `) const;`|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|`CString& GetNext( POSITION&` `rPosition` `);`<br /><br /> `const CString& GetNext( POSITION&` `rPosition` `) const;`|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#98](../../mfc/codesnippet/cpp/coblist-class_10.cpp)]

Os resultados deste programa são os seguintes:

```Output
a CAge at $479C 40
a CAge at $46C0 21
```

## <a name="coblistgetprev"></a><a name="getprev"></a>CObList::GetPrev

Obtém o elemento de lista identificado por *rPosition,* em seguida, define *rPosição* para o valor DE POSIÇÃO da entrada anterior na lista.

```
CObject*& GetPrev(POSITION& rPosition);
const CObject* GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*Rposition*<br/>
Uma referência a um valor DE `GetPrev` POSIÇÃO retornado por uma chamada de função anterior ou de outro membro.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você pode `GetPrev` usar em um loop de iteração reversa `GetTailPosition` `Find`se estabelecer a posição inicial com uma chamada para ou .

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

Se o elemento recuperado for o primeiro da lista, então o novo valor de *rPosition* será definido como NULL.

> [!NOTE]
> A partir do MFC 8.0, a versão `const CObject*` const `const CObject*&`deste método mudou para retornar em vez de .  Essa mudança foi feita para colocar o compilador em conformidade com o padrão C++.

A tabela a seguir mostra outras `CObList::GetPrev`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|`void*& GetPrev( POSITION&` `rPosition` `);`<br /><br /> `const void* GetPrev( POSITION&` `rPosition` `) const;`|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|`CString& GetPrev( POSITION&` `rPosition` `);`<br /><br /> `const CString& GetPrev( POSITION&` `rPosition` `) const;`|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#99](../../mfc/codesnippet/cpp/coblist-class_11.cpp)]

Os resultados deste programa são os seguintes:

```Output
a CAge at $421C 21
a CAge at $421C 40
```

## <a name="coblistgetsize"></a><a name="getsize"></a>CObList::GetSize

Retorna o número de elementos da lista.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens da lista.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos na lista.

A tabela a seguir mostra outras `CObList::GetSize`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**INT_PTR GetSize;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**INT_PTR GetSize;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#100](../../mfc/codesnippet/cpp/coblist-class_12.cpp)]

## <a name="coblistgettail"></a><a name="gettail"></a>CObList::GetTail

Obtém `CObject` o ponteiro que representa o elemento de cauda desta lista.

```
CObject*& GetTail();
const CObject*& GetTail() const;
```

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `GetTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras `CObList::GetTail`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**const\* vazio& GetTail; vazio\*& GetTail( );**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**const CString& GetTail; Cstring& GetTail;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#101](../../mfc/codesnippet/cpp/coblist-class_13.cpp)]

## <a name="coblistgettailposition"></a><a name="gettailposition"></a>CObList::GetTailPosition

Obtém a posição do elemento de cauda desta lista; **NULO** se a lista estiver vazia.

```
POSITION GetTailPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

A tabela a seguir mostra outras `CObList::GetTailPosition`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO GetTailPosition;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**POSIÇÃO GetTailPosition;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#102](../../mfc/codesnippet/cpp/coblist-class_14.cpp)]

## <a name="coblistinsertafter"></a><a name="insertafter"></a>CObList::InserirApós

Adiciona um elemento a esta lista após o elemento na posição especificada.

```
POSITION InsertAfter(
    POSITION position,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
Um valor de POSIÇÃO `GetNext`retornado `Find` por uma chamada de função anterior ou `GetPrev`membro.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta lista.

A tabela a seguir mostra outras `CObList::InsertAfter`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**Inserção de posiçãoApós (posição** *de posição,* **vazio);** <strong>\*</strong> `newElement` **);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**Inserção de posiçãoApós(posição de posição,** *position* **const CString&);** `newElement` **);**<br /><br /> **Inserção da posiçãoApós (posição** *de* **posição, LPCTSTR);** `newElement` **);**|

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que é o mesmo que o parâmetro de *posição.*

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#103](../../mfc/codesnippet/cpp/coblist-class_15.cpp)]

Os resultados deste programa são os seguintes:

```Output
InsertAfter example: A CObList with 3 elements
a CAge at $4A44 40
a CAge at $4A64 65
a CAge at $4968 21
```

## <a name="coblistinsertbefore"></a><a name="insertbefore"></a>CObList::Inserirantes

Adiciona um elemento a esta lista antes do elemento na posição especificada.

```
POSITION InsertBefore(
    POSITION position,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
Um valor de POSIÇÃO `GetNext`retornado `Find` por uma chamada de função anterior ou `GetPrev`membro.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração ou recuperação do ponteiro de objetos; NULO se a lista estiver vazia.

A tabela a seguir mostra outras `CObList::InsertBefore`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**Inserção da posiçãoAntes (posição** *de posição,* **vazio);** <strong>\*</strong> `newElement` **);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**Inserção da posiçãoAntes(** *posição de posição,* **const CString&);** `newElement` **);**<br /><br /> **Inserção da posiçãoAntes(posição** *de* **posição, LPCTSTR);** `newElement` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#104](../../mfc/codesnippet/cpp/coblist-class_16.cpp)]

Os resultados deste programa são os seguintes:

```Output
InsertBefore example: A CObList with 3 elements
a CAge at $4AE2 40
a CAge at $4B02 65
a CAge at $49E6 21
```

## <a name="coblistisempty"></a><a name="isempty"></a>CObList::IsEmpty

Indica se esta lista não contém elementos.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se esta lista estiver vazia; caso contrário, 0.

A tabela a seguir mostra outras `CObList::IsEmpty`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**BOOL IsEmpty( ) const;**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**BOOL IsEmpty( ) const;**|

### <a name="example"></a>Exemplo

  Veja o exemplo de [RemoveAll](#removeall).

## <a name="coblistremoveall"></a><a name="removeall"></a>CObList::RemoveAll

Remove todos os elementos desta lista `CObList` e libera a memória associada.

```cpp
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Nenhum erro é gerado se a lista já estiver vazia.

Quando você remove `CObList`elementos de um , você remove os ponteiros do objeto da lista. É sua responsabilidade excluir os objetos eles mesmos.

A tabela a seguir mostra outras `CObList::RemoveAll`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**void RemoveAll();**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**void RemoveAll();**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#105](../../mfc/codesnippet/cpp/coblist-class_17.cpp)]

## <a name="coblistremoveat"></a><a name="removeat"></a>CObList::RemoveAt

Remove o elemento especificado desta lista.

```cpp
void RemoveAt(POSITION position);
```

### <a name="parameters"></a>Parâmetros

*Posição*<br/>
A posição do elemento a ser removido da lista.

### <a name="remarks"></a>Comentários

Quando você remove um `CObList`elemento de um , você remove o ponteiro do objeto da lista. É sua responsabilidade excluir os objetos eles mesmos.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

A tabela a seguir mostra outras `CObList::RemoveAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**void RemoveAt (posição de** *posição);* **);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**void RemoveAt (posição de** *posição);* **);**|

### <a name="example"></a>Exemplo

  Tenha cuidado ao remover um elemento durante uma iteração da lista. O exemplo a seguir mostra uma técnica de remoção que garante um valor **de POSIÇÃO** válido para [GetNext](#getnext).

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#106](../../mfc/codesnippet/cpp/coblist-class_18.cpp)]

Os resultados deste programa são os seguintes:

`RemoveAt example: A CObList with 2 elements`

`a CAge at $4C1E 65`

`a CAge at $4B22 21`

## <a name="coblistremovehead"></a><a name="removehead"></a>CObList::RemoveHead

Remove o elemento da cabeça da lista e retorna um ponteiro para ele.

```
CObject* RemoveHead();
```

### <a name="return-value"></a>Valor retornado

O `CObject` ponteiro anteriormente no cabeça da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveHead`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras `CObList::RemoveHead`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**void\* RemoveHead ( );**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**Cabeça de remoção de cstring ( );**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#107](../../mfc/codesnippet/cpp/coblist-class_19.cpp)]

## <a name="coblistremovetail"></a><a name="removetail"></a>CObList::RemoveTail

Remove o elemento da cauda da lista e retorna um ponteiro para ele.

```
CObject* RemoveTail();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto que estava na cauda da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista `RemoveTail`não esteja vazia antes de ligar . Se a lista estiver vazia, a versão Debug da Biblioteca de Classes da Microsoft Foundation será afirmada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras `CObList::RemoveTail`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**void\* RemoveTail ( );**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**Cstring RemoveTail ( );**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#108](../../mfc/codesnippet/cpp/coblist-class_20.cpp)]

## <a name="coblistsetat"></a><a name="setat"></a>CObList::SetAt

Define o elemento em uma determinada posição.

```cpp
void SetAt(
    POSITION pos,
    CObject* newElement);
```

### <a name="parameters"></a>Parâmetros

*Pos*<br/>
A posição do elemento a ser definido.

*Newelement*<br/>
O `CObject` ponteiro a ser escrito na lista.

### <a name="remarks"></a>Comentários

Uma variável do tipo POSIÇÃO é uma chave para a lista. Não é o mesmo que um índice, e você não pode operar em um valor DE POSIÇÃO você mesmo. `SetAt`escreve `CObject` o ponteiro para a posição especificada na lista.

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

A tabela a seguir mostra outras `CObList::SetAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cptrlist](../../mfc/reference/cptrlist-class.md)|**void SetAt(POSITION,** `pos` **const CString** `newElement` **&);**|
|[Cstringlist](../../mfc/reference/cstringlist-class.md)|**void SetAt (POSIÇÃO,** `pos` **LPCTSTR);** `newElement` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList::CObList](#coblist) para obter `CAge` uma listagem da classe.

[!code-cpp[NVC_MFCCollections#109](../../mfc/codesnippet/cpp/coblist-class_21.cpp)]

Os resultados deste programa são os seguintes:

```Output
SetAt example: A CObList with 2 elements
a CAge at $4D98 40
a CAge at $4DB8 65
```

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStringList](../../mfc/reference/cstringlist-class.md)<br/>
[Classe CPtrList](../../mfc/reference/cptrlist-class.md)
