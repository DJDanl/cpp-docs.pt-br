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
ms.openlocfilehash: 2fc3a3643c675394de555f1411030e278bcee775
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79416868"
---
# <a name="coblist-class"></a>Classe CObList

fSupports listas ordenadas de ponteiros de `CObject` não exclusivos acessíveis sequencialmente ou por valor de ponteiro.

## <a name="syntax"></a>Sintaxe

```
class CObList : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CObList::CObList](#coblist)|Constrói uma lista vazia para ponteiros de `CObject`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CObList:: AddHead](#addhead)|Adiciona um elemento (ou todos os elementos em outra lista) ao início da lista (cria um novo cabeçalho).|
|[CObList:: addcaudal](#addtail)|Adiciona um elemento (ou todos os elementos em outra lista) à parte final da lista (cria uma nova cauda).|
|[CObList:: find](#find)|Obtém a posição de um elemento especificado pelo valor do ponteiro.|
|[CObList::FindIndex](#findindex)|Obtém a posição de um elemento especificado por um índice baseado em zero.|
|[CObList::GetAt](#getat)|Obtém o elemento em uma determinada posição.|
|[CObList:: GetCount](#getcount)|Retorna o número de elementos nesta lista.|
|[CObList:: GetHead](#gethead)|Retorna o elemento head da lista (não pode estar vazio).|
|[CObList::GetHeadPosition](#getheadposition)|Retorna a posição do elemento de cabeçalho da lista.|
|[CObList:: GetNext](#getnext)|Obtém o próximo elemento para iteração.|
|[CObList:: getant](#getprev)|Obtém o elemento anterior para iteração.|
|[CObList::GetSize](#getsize)|Retorna o número de elementos nesta lista.|
|[CObList:: getcaudal](#gettail)|Retorna o elemento tail da lista (não pode estar vazio).|
|[CObList::GetTailPosition](#gettailposition)|Retorna a posição do elemento de cauda da lista.|
|[CObList:: InsertAfter](#insertafter)|Insere um novo elemento após uma determinada posição.|
|[CObList:: InsertBefore](#insertbefore)|Insere um novo elemento antes de uma determinada posição.|
|[CObList:: IsEmpty](#isempty)|Testes para a condição de lista vazia (sem elementos).|
|[CObList:: RemoveAll](#removeall)|Remove todos os elementos dessa lista.|
|[CObList:: RemoveAt](#removeat)|Remove um elemento desta lista, especificado pela posição.|
|[CObList::RemoveHead](#removehead)|Remove o elemento do início da lista.|
|[CObList::RemoveTail](#removetail)|Remove o elemento da parte final da lista.|
|[CObList::SetAt](#setat)|Define o elemento em uma determinada posição.|

## <a name="remarks"></a>Comentários

`CObList` listas se comportam como listas de links duplos.

Uma variável do tipo POSITION é uma chave para a lista. Você pode usar uma variável POSITION como um iterador para percorrer uma lista sequencialmente e como um indicador para manter um local. No entanto, uma posição não é igual a um índice.

A inserção de elemento é muito rápida no cabeçalho da lista, na parte final e em uma posição conhecida. Uma pesquisa sequencial é necessária para pesquisar um elemento por valor ou índice. Essa pesquisa poderá ser lenta se a lista for longa.

`CObList` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e ao despejo de seus elementos. Se uma lista de ponteiros de `CObject` for armazenada em um arquivo morto, com um operador de inserção sobrecarregado ou com a função de membro `Serialize`, cada elemento `CObject` será serializado por vez.

Se você precisar de um despejo de elementos de `CObject` individuais na lista, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Quando um objeto de `CObList` é excluído ou quando seus elementos são removidos, somente os ponteiros de `CObject` são removidos, não os objetos que eles referenciam.

Você pode derivar suas próprias classes de `CObList`. Sua nova classe List, projetada para conter ponteiros para objetos derivados de `CObject`, adiciona novos membros de dados e novas funções de membro. Observe que a lista resultante não é estritamente fortemente tipada, pois permite a inserção de qualquer ponteiro de `CObject`.

> [!NOTE]
>  Você deve usar a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) na implementação da classe derivada se pretender serializar a lista.

Para obter mais informações sobre como usar `CObList`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CObList`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

##  <a name="addhead"></a>CObList:: AddHead

Adiciona um novo elemento ou lista de elementos ao início dessa lista.

```
POSITION AddHead(CObject* newElement);
void AddHead(CObList* pNewList);
```

### <a name="parameters"></a>parâmetros

*newElement*<br/>
O ponteiro de `CObject` a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro para outra lista de `CObList`. Os elementos em *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor da posição do elemento recentemente inserido.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::AddHead`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Posição AddHead (void** <strong>\*</strong> `newElement` **);**<br /><br /> **void AddHead (CPtrList** <strong>\*</strong> `pNewList` **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Posição AddHead (Const CString &** `newElement` **);**<br /><br /> **Posição AddHead (LPCTSTR** `newElement` **);**<br /><br /> **void AddHead (cstringlist** <strong>\*</strong> `pNewList` **);**|

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#89](../../mfc/codesnippet/cpp/coblist-class_1.cpp)]

Os resultados desse programa são os seguintes:

```Output
AddHead example: A CObList with 2 elements
a CAge at $44A8 40
a CAge at $442A 21
```

##  <a name="addtail"></a>CObList:: addcaudal

Adiciona um novo elemento ou lista de elementos à parte final desta lista.

```
POSITION AddTail(CObject* newElement);
void AddTail(CObList* pNewList);
```

### <a name="parameters"></a>parâmetros

*newElement*<br/>
O ponteiro de `CObject` a ser adicionado a esta lista.

*pNewList*<br/>
Um ponteiro para outra lista de `CObList`. Os elementos em *pNewList* serão adicionados a essa lista.

### <a name="return-value"></a>Valor retornado

A primeira versão retorna o valor da posição do elemento recentemente inserido.

### <a name="remarks"></a>Comentários

A lista pode estar vazia antes da operação.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::AddTail`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Posicionar addcaudal (void** <strong>\*</strong> `newElement` **);**<br /><br /> **void Addcaudal (CPtrList** <strong>\*</strong> `pNewList` **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Posicionar Addcaudal (Const CString &** `newElement` **);**<br /><br /> **Posição Addcaudal (LPCTSTR** `newElement` **);**<br /><br /> **void Addcaudal (cstringlist** <strong>\*</strong> `pNewList` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#90](../../mfc/codesnippet/cpp/coblist-class_2.cpp)]

Os resultados desse programa são os seguintes:

```Output
AddTail example: A CObList with 2 elements
a CAge at $444A 21
a CAge at $4526 40
```

##  <a name="coblist"></a>CObList::CObList

Constrói uma lista de ponteiros `CObject` vazia.

```
CObList(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>parâmetros

*nBlockSize*<br/>
A granularidade de alocação de memória para estender a lista.

### <a name="remarks"></a>Comentários

À medida que a lista cresce, a memória é alocada em unidades de entradas *nBlockSize* . Se uma alocação de memória falhar, uma `CMemoryException` será lançada.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::CObList`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**CPtrList (INT_PTR** `nBlockSize` **= 10);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**CStringList (INT_PTR** `nBlockSize` **= 10);**|

### <a name="example"></a>Exemplo

  Abaixo está uma lista da classe derivada de `CObject``CAge` usada em todos os exemplos de coleção:

[!code-cpp[NVC_MFCCollections#91](../../mfc/codesnippet/cpp/coblist-class_3.h)]

Veja abaixo um exemplo de uso do construtor de `CObList`:

[!code-cpp[NVC_MFCCollections#92](../../mfc/codesnippet/cpp/coblist-class_4.cpp)]

##  <a name="find"></a>CObList:: find

Pesquisa a lista sequencialmente para localizar o primeiro ponteiro de `CObject` correspondente ao ponteiro de `CObject` especificado.

```
POSITION Find(
    CObject* searchValue,
    POSITION startAfter = NULL) const;
```

### <a name="parameters"></a>parâmetros

*searchValue*<br/>
O ponteiro de objeto a ser encontrado nesta lista.

*startAfter*<br/>
A posição inicial da pesquisa.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se o objeto não for encontrado.

### <a name="remarks"></a>Comentários

Observe que os valores de ponteiro são comparados, não o conteúdo dos objetos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::Find`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Localização da posição (void** <strong>\*</strong> `searchValue` **, posição** `startAfter` **= NULL) const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Find de posição (LPCTSTR** `searchValue` **, Position** `startAfter` **= NULL) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#93](../../mfc/codesnippet/cpp/coblist-class_5.cpp)]

##  <a name="findindex"></a>CObList::FindIndex

Usa o valor de *nIndex* como um índice na lista.

```
POSITION FindIndex(INT_PTR nIndex) const;
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
O índice de base zero do elemento de lista a ser encontrado.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se *nIndex* for muito grande. (A estrutura gera uma asserção se *nIndex* é negativo.)

### <a name="remarks"></a>Comentários

Ele inicia uma verificação sequencial do início da lista, parando no elemento *n*-ésimo.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::FindIndex`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Position FindIndex (INT_PTR** `nIndex` **) const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Position FindIndex (INT_PTR** `nIndex` **) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#94](../../mfc/codesnippet/cpp/coblist-class_6.cpp)]

##  <a name="getat"></a>CObList::GetAt

Uma variável do tipo POSITION é uma chave para a lista.

```
CObject*& GetAt(POSITION position);
const CObject*& GetAt(POSITION position) const;
```

### <a name="parameters"></a>parâmetros

*position*<br/>
Um valor de posição retornado por uma chamada de função membro de `GetHeadPosition` ou `Find` anterior.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Não é o mesmo que um índice, e você não pode operar em um valor de posição por conta própria. `GetAt` recupera o ponteiro de `CObject` associado a uma determinada posição.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**const void\*& GetAt (** *posição* da posição **) const;**<br /><br /> **void\*& GetAt (** *posição* da posição **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Const CString & GetAt (** *posição* da posição **) const;**<br /><br /> **CString & GetAt (** *posição* da posição **);**|

### <a name="example"></a>Exemplo

  Consulte o exemplo de [FindIndex](#findindex).

##  <a name="getcount"></a>CObList:: GetCount

Obtém o número de elementos nesta lista.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

Um valor inteiro que contém a contagem de elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetCount`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**INT_PTR GetCount () const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**INT_PTR GetCount () const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#95](../../mfc/codesnippet/cpp/coblist-class_7.cpp)]

##  <a name="gethead"></a>CObList:: GetHead

Obtém o ponteiro de `CObject` que representa o elemento de cabeçalho desta lista.

```
CObject*& GetHead();
const CObject*& GetHead() const;
```

### <a name="return-value"></a>Valor retornado

Se a lista for acessada por meio de um ponteiro para uma `const CObList`, `GetHead` retornará um ponteiro de `CObject`. Isso permite que a função seja usada somente no lado direito de uma instrução de atribuição e, portanto, protege a lista contra modificações.

Se a lista for acessada diretamente ou por meio de um ponteiro para uma `CObList`, `GetHead` retornará uma referência a um ponteiro `CObject`. Isso permite que a função seja usada em qualquer um dos lados de uma instrução de atribuição e, portanto, permite que as entradas da lista sejam modificadas.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `GetHead`. Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetHead`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**const void\*& constante GetHead (); void\*& GetHead ();**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Const CString & GetHead () const; CString & GetHead ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

O exemplo a seguir ilustra o uso de `GetHead` no lado esquerdo de uma instrução de atribuição.

[!code-cpp[NVC_MFCCollections#96](../../mfc/codesnippet/cpp/coblist-class_8.cpp)]

##  <a name="getheadposition"></a>CObList::GetHeadPosition

Obtém a posição do elemento de cabeçalho desta lista.

```
POSITION GetHeadPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetHeadPosition`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO GetHeadPosition () const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**POSIÇÃO GetHeadPosition () const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#97](../../mfc/codesnippet/cpp/coblist-class_9.cpp)]

##  <a name="getnext"></a>CObList:: GetNext

Obtém o elemento List identificado por *rPosition*e, em seguida, define *rPosition* como o valor `POSITION` da próxima entrada na lista.

```
CObject*& GetNext(POSITION& rPosition);
const CObject* GetNext(POSITION& rPosition) const;
```

### <a name="parameters"></a>parâmetros

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma `GetNext`anterior, `GetHeadPosition`ou outra chamada de função de membro.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você pode usar `GetNext` em um loop de iteração progressiva se estabelecer a posição inicial com uma chamada para `GetHeadPosition` ou `Find`.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

Se o elemento recuperado for o último na lista, o novo valor de *rPosition* será definido como NULL.

É possível remover um elemento durante uma iteração. Consulte o exemplo de [RemoveAt](#removeat).

> [!NOTE]
>  A partir do MFC 8,0, a versão const desse método foi alterada para retornar `const CObject*` em vez de `const CObject*&`.  Essa alteração foi feita para colocar o compilador em conformidade com o C++ padrão.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetNext`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|`void*& GetNext( POSITION&` `rPosition` `);`<br /><br /> `const void* GetNext( POSITION&` `rPosition` `) const;`|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|`CString& GetNext( POSITION&` `rPosition` `);`<br /><br /> `const CString& GetNext( POSITION&` `rPosition` `) const;`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#98](../../mfc/codesnippet/cpp/coblist-class_10.cpp)]

Os resultados desse programa são os seguintes:

```Output
a CAge at $479C 40
a CAge at $46C0 21
```

##  <a name="getprev"></a>CObList:: getant

Obtém o elemento List identificado por *rPosition*e, em seguida, define *rPosition* como o valor de posição da entrada anterior na lista.

```
CObject*& GetPrev(POSITION& rPosition);
const CObject* GetPrev(POSITION& rPosition) const;
```

### <a name="parameters"></a>parâmetros

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma `GetPrev` anterior ou outra chamada de função de membro.

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você pode usar `GetPrev` em um loop de iteração reversa se estabelecer a posição inicial com uma chamada para `GetTailPosition` ou `Find`.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

Se o elemento recuperado for o primeiro na lista, o novo valor de *rPosition* será definido como NULL.

> [!NOTE]
>  A partir do MFC 8,0, a versão const desse método foi alterada para retornar `const CObject*` em vez de `const CObject*&`.  Essa alteração foi feita para colocar o compilador em conformidade com o C++ padrão.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetPrev`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|`void*& GetPrev( POSITION&` `rPosition` `);`<br /><br /> `const void* GetPrev( POSITION&` `rPosition` `) const;`|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|`CString& GetPrev( POSITION&` `rPosition` `);`<br /><br /> `const CString& GetPrev( POSITION&` `rPosition` `) const;`|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#99](../../mfc/codesnippet/cpp/coblist-class_11.cpp)]

Os resultados desse programa são os seguintes:

```Output
a CAge at $421C 21
a CAge at $421C 40
```

##  <a name="getsize"></a>CObList::GetSize

Retorna o número de elementos da lista.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens da lista.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos na lista.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**INT_PTR GetSize () const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**INT_PTR GetSize () const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#100](../../mfc/codesnippet/cpp/coblist-class_12.cpp)]

##  <a name="gettail"></a>CObList:: getcaudal

Obtém o ponteiro de `CObject` que representa o elemento de cauda desta lista.

```
CObject*& GetTail();
const CObject*& GetTail() const;
```

### <a name="return-value"></a>Valor retornado

Consulte a descrição do valor de retorno para [GetHead](#gethead).

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `GetTail`. Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetTail`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**const void\*& getcauda () const; void\*& getcauda ();**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Const CString & getcauda () const; CString & getcauda ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#101](../../mfc/codesnippet/cpp/coblist-class_13.cpp)]

##  <a name="gettailposition"></a>CObList::GetTailPosition

Obtém a posição do elemento de cauda desta lista; **NULL** se a lista estiver vazia.

```
POSITION GetTailPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::GetTailPosition`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**POSIÇÃO GetTailPosition () const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**POSIÇÃO GetTailPosition () const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#102](../../mfc/codesnippet/cpp/coblist-class_14.cpp)]

##  <a name="insertafter"></a>CObList:: InsertAfter

Adiciona um elemento a essa lista após o elemento na posição especificada.

```
POSITION InsertAfter(
    POSITION position,
    CObject* newElement);
```

### <a name="parameters"></a>parâmetros

*position*<br/>
Um valor de posição retornado por uma chamada de função de membro `GetNext`, `GetPrev`ou `Find` anterior.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a esta lista.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::InsertAfter`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Posição InsertAfter (** *posição da* **posição, void** <strong>\*</strong> `newElement` **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Posição InsertAfter (** *posição* da posição **, Const CString &** `newElement` **);**<br /><br /> **Posição InsertAfter (** *posição da* posição **, LPCTSTR** `newElement` **);**|

### <a name="return-value"></a>Valor retornado

Um valor de posição que é o mesmo que o parâmetro de *posição* .

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#103](../../mfc/codesnippet/cpp/coblist-class_15.cpp)]

Os resultados desse programa são os seguintes:

```Output
InsertAfter example: A CObList with 3 elements
a CAge at $4A44 40
a CAge at $4A64 65
a CAge at $4968 21
```

##  <a name="insertbefore"></a>CObList:: InsertBefore

Adiciona um elemento a essa lista antes do elemento na posição especificada.

```
POSITION InsertBefore(
    POSITION position,
    CObject* newElement);
```

### <a name="parameters"></a>parâmetros

*position*<br/>
Um valor de posição retornado por uma chamada de função de membro `GetNext`, `GetPrev`ou `Find` anterior.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a esta lista.

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para a recuperação do ponteiro de objeto ou iteração; NULL se a lista estiver vazia.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::InsertBefore`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**Posição InsertBefore (** *posição* da posição **, void** <strong>\*</strong> `newElement` **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**Posição InsertBefore (** *posição* da posição **, Const CString &** `newElement` **);**<br /><br /> **Posição InsertBefore (** *posição* da posição **, LPCTSTR** `newElement` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#104](../../mfc/codesnippet/cpp/coblist-class_16.cpp)]

Os resultados desse programa são os seguintes:

```Output
InsertBefore example: A CObList with 3 elements
a CAge at $4AE2 40
a CAge at $4B02 65
a CAge at $49E6 21
```

##  <a name="isempty"></a>CObList:: IsEmpty

Indica se esta lista não contém elementos.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se esta lista estiver vazia; caso contrário, 0.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::IsEmpty`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**BOOL IsEmpty () const;**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**BOOL IsEmpty () const;**|

### <a name="example"></a>Exemplo

  Consulte o exemplo de [RemoveAll](#removeall).

##  <a name="removeall"></a>CObList:: RemoveAll

Remove todos os elementos dessa lista e libera a memória `CObList` associada.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Nenhum erro será gerado se a lista já estiver vazia.

Quando você remove elementos de um `CObList`, você remove os ponteiros de objeto da lista. É sua responsabilidade excluir os próprios objetos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::RemoveAll`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**void RemoveAll ();**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**void RemoveAll ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#105](../../mfc/codesnippet/cpp/coblist-class_17.cpp)]

##  <a name="removeat"></a>CObList:: RemoveAt

Remove o elemento especificado desta lista.

```
void RemoveAt(POSITION position);
```

### <a name="parameters"></a>parâmetros

*position*<br/>
A posição do elemento a ser removido da lista.

### <a name="remarks"></a>Comentários

Ao remover um elemento de um `CObList`, você remove o ponteiro do objeto da lista. É sua responsabilidade excluir os próprios objetos.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::RemoveAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**void RemoveAt (** *posição* da posição **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**void RemoveAt (** *posição* da posição **);**|

### <a name="example"></a>Exemplo

  Tenha cuidado ao remover um elemento durante uma iteração de lista. O exemplo a seguir mostra uma técnica de remoção que garante um valor de **posição** válido para [GetNext](#getnext).

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#106](../../mfc/codesnippet/cpp/coblist-class_18.cpp)]

Os resultados desse programa são os seguintes:

`RemoveAt example: A CObList with 2 elements`

`a CAge at $4C1E 65`

`a CAge at $4B22 21`

##  <a name="removehead"></a>CObList::RemoveHead

Remove o elemento da cabeça da lista e retorna um ponteiro para ele.

```
CObject* RemoveHead();
```

### <a name="return-value"></a>Valor retornado

O ponteiro de `CObject` anteriormente no início da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `RemoveHead`. Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::RemoveHead`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**void\* RemoveHead ();**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**CString RemoveHead ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#107](../../mfc/codesnippet/cpp/coblist-class_19.cpp)]

##  <a name="removetail"></a>CObList::RemoveTail

Remove o elemento da parte final da lista e retorna um ponteiro para ele.

```
CObject* RemoveTail();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto que estava na parte final da lista.

### <a name="remarks"></a>Comentários

Você deve garantir que a lista não esteja vazia antes de chamar `RemoveTail`. Se a lista estiver vazia, a versão de depuração do biblioteca MFC será declarada. Use [IsEmpty](#isempty) para verificar se a lista contém elementos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::RemoveTail`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**void\* RemoveTail ();**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**CString RemoveTail ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#108](../../mfc/codesnippet/cpp/coblist-class_20.cpp)]

##  <a name="setat"></a>CObList::SetAt

Define o elemento em uma determinada posição.

```
void SetAt(
    POSITION pos,
    CObject* newElement);
```

### <a name="parameters"></a>parâmetros

*pos*<br/>
A posição do elemento a ser definido.

*newElement*<br/>
O ponteiro de `CObject` a ser gravado na lista.

### <a name="remarks"></a>Comentários

Uma variável do tipo POSITION é uma chave para a lista. Não é o mesmo que um índice, e você não pode operar em um valor de posição por conta própria. `SetAt` grava o ponteiro de `CObject` na posição especificada na lista.

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CObList::SetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CPtrList](../../mfc/reference/cptrlist-class.md)|**void SetAt (POSITION** `pos` **, const CString &** `newElement` **);**|
|[CStringlist](../../mfc/reference/cstringlist-class.md)|**void SetAt (posição** `pos` **, LPCTSTR** `newElement` **);**|

### <a name="example"></a>Exemplo

  Consulte [CObList:: CObList](#coblist) para obter uma lista da classe `CAge`.

[!code-cpp[NVC_MFCCollections#109](../../mfc/codesnippet/cpp/coblist-class_21.cpp)]

Os resultados desse programa são os seguintes:

```Output
SetAt example: A CObList with 2 elements
a CAge at $4D98 40
a CAge at $4DB8 65
```

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CStringList](../../mfc/reference/cstringlist-class.md)<br/>
[Classe de CPtrList](../../mfc/reference/cptrlist-class.md)
