---
title: Classe CMapStringToOb
ms.date: 11/04/2016
f1_keywords:
- CMapStringToOb
- AFXCOLL/CMapStringToOb
- AFXCOLL/CMapStringToOb::CMapStringToOb
- AFXCOLL/CMapStringToOb::GetCount
- AFXCOLL/CMapStringToOb::GetHashTableSize
- AFXCOLL/CMapStringToOb::GetNextAssoc
- AFXCOLL/CMapStringToOb::GetSize
- AFXCOLL/CMapStringToOb::GetStartPosition
- AFXCOLL/CMapStringToOb::HashKey
- AFXCOLL/CMapStringToOb::InitHashTable
- AFXCOLL/CMapStringToOb::IsEmpty
- AFXCOLL/CMapStringToOb::Lookup
- AFXCOLL/CMapStringToOb::LookupKey
- AFXCOLL/CMapStringToOb::RemoveAll
- AFXCOLL/CMapStringToOb::RemoveKey
- AFXCOLL/CMapStringToOb::SetAt
helpviewer_keywords:
- CMapStringToOb [MFC], CMapStringToOb
- CMapStringToOb [MFC], GetCount
- CMapStringToOb [MFC], GetHashTableSize
- CMapStringToOb [MFC], GetNextAssoc
- CMapStringToOb [MFC], GetSize
- CMapStringToOb [MFC], GetStartPosition
- CMapStringToOb [MFC], HashKey
- CMapStringToOb [MFC], InitHashTable
- CMapStringToOb [MFC], IsEmpty
- CMapStringToOb [MFC], Lookup
- CMapStringToOb [MFC], LookupKey
- CMapStringToOb [MFC], RemoveAll
- CMapStringToOb [MFC], RemoveKey
- CMapStringToOb [MFC], SetAt
ms.assetid: 09653980-b885-4f3a-8594-0aeb7f94c601
ms.openlocfilehash: 75e9b49bca6b94595186e69a900a28fe5e38522c
ms.sourcegitcommit: 53f75afaf3c0b3ed481c5503357ed2b7b87aac6d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2018
ms.locfileid: "53657611"
---
# <a name="cmapstringtoob-class"></a>Classe CMapStringToOb

Uma classe de coleção de dicionário que mapeia exclusivo `CString` objetos à `CObject` ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToOb : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::CMapStringToOb](#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::GetCount](#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetHashTableSize](#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapStringToOb::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para a iteração.|
|[CMapStringToOb::GetSize](#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToOb::HashKey](#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToOb::InitHashTable](#inithashtable)|Inicializa a tabela de hash.|
|[CMapStringToOb::IsEmpty](#isempty)|Testa a condição de mapa vazio (sem elementos).|
|[CMapStringToOb::Lookup](#lookup)|Procura um ponteiro nulo na chave de ponteiro nulo. O valor do ponteiro, não a entidade a qual ele aponta, é usado para a comparação de chave.|
|[CMapStringToOb::LookupKey](#lookupkey)|Retorna uma referência para a chave associada com o valor de chave especificado.|
|[CMapStringToOb::RemoveAll](#removeall)|Remove todos os elementos a partir desse mapa.|
|[CMapStringToOb::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToOb::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::operator \[ \]](#operator_at)|Insere um elemento no mapa — substituição do operador para `SetAt`.|

## <a name="remarks"></a>Comentários

Depois que você inseriu uma `CString` -  `CObject*` par (elemento) no mapa, com eficiência você pode recuperar ou excluir o par usando uma cadeia de caracteres ou um `CString` valor como uma chave. Você também pode iterar sobre todos os elementos no mapa.

Uma variável do tipo de posição é usada para acesso de entrada alternativo em todas as variações de mapa. Você pode usar uma posição para uma entrada de "lembrar" e iterar o mapa. Você pode pensar que essa iteração é sequencial pelo valor de chave; não é. A sequência de elementos recuperados é indeterminada.

A `CMapStringToOb` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por sua vez, se um mapa é armazenado em um arquivo, com a inserção sobrecarregada ( **<<**) operador ou com o `Serialize` função de membro.

Se for necessário um despejo de diagnóstico dos elementos individuais no mapa (o `CString` valor e o `CObject` conteúdo), você deve definir a profundidade do contexto de despejo para 1 ou maior.

Quando um `CMapStringToOb` objeto é excluído, ou quando seus elementos são removidos, o `CString` objetos e o `CObject` ponteiros são removidos. Os objetos referenciados pela `CObject` ponteiros não são destruídos.

Derivação de classe de mapa é semelhante à derivação de lista. Consulte o artigo [coleções](../../mfc/collections.md) para obter uma ilustração da derivação de uma classe de lista de finalidade especial.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapStringToOb`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** & amp;lt;1}afxcoll.h

##  <a name="cmapstringtoob"></a>  CMapStringToOb::CMapStringToOb

Constrói um vazio `CString`- para - `CObject*` mapa.

```
CMapStringToOb(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*nBlockSize*<br/>
Especifica a granularidade de alocação de memória para estender o mapa.

### <a name="remarks"></a>Comentários

À medida que cresce o mapa, a memória é alocada em unidades de *nBlockSize* entradas.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb:: CMapStringToOb`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**CMapPtrToPtr( INT_PTR** `nBlockSize` **= 10 );**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**CMapPtrToWord( INT_PTR** `nBlockSize` **= 10 );**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**CMapStringToPtr( INT_PTR** `nBlockSize` **= 10 );**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CMapStringToString( INT_PTR** `nBlockSize` **= 10 );**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CMapWordToOb( INT_PTR** `nBlockSize` **= 10 );**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**MapWordToPtr( INT_PTR** `nBlockSize` **= 10 );**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#63](../../mfc/codesnippet/cpp/cmapstringtoob-class_1.cpp)]

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

##  <a name="getcount"></a>  CMapStringToOb::GetCount

Determina quantos elementos estão no mapa.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de elementos neste mapa.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetCount`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**() GetCount INT_PTR const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**() GetCount INT_PTR const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**() GetCount INT_PTR const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**() GetCount INT_PTR const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**() GetCount INT_PTR const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**() GetCount INT_PTR const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#64](../../mfc/codesnippet/cpp/cmapstringtoob-class_2.cpp)]

##  <a name="gethashtablesize"></a>  CMapStringToOb::GetHashTableSize

Determina o número atual de elementos na tabela de hash.

```
UINT GetHashTableSize() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna o número de elementos na tabela de hash.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetHashTableSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT (de) de GetHashTableSize const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**UINT (de) de GetHashTableSize const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT (de) de GetHashTableSize const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**UINT (de) de GetHashTableSize const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**UINT (de) de GetHashTableSize const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT (de) de GetHashTableSize const;**|

##  <a name="getnextassoc"></a>  CMapStringToOb::GetNextAssoc

Recupera o elemento de mapa na *rNextPosition*, em seguida, atualiza *rNextPosition* para referir-se para o próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rNextPosition,
    CString& rKey,
    CObject*& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*rNextPosition*<br/>
Especifica uma referência a um valor de posição retornado por uma anterior `GetNextAssoc` ou `GetStartPosition` chamar.

*rKey*<br/>
Especifica a chave retornada do elemento recuperado (uma cadeia de caracteres).

*rValue*<br/>
Especifica o valor retornado do elemento recuperado (um `CObject` ponteiro). Consulte os comentários para obter mais informações sobre esse parâmetro.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por meio de todos os elementos no mapa. Observe que a sequência de posição não é necessariamente o mesmo que a sequência de valor de chave.

Se o elemento recuperado é o último no mapa, em seguida, o novo valor de *rNextPosition* é definido como NULL.

Para o *rValue* parâmetro, certifique-se de converter seu tipo de objeto **CObject\*&**, que é o que exige que o compilador, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCCollections#65](../../mfc/codesnippet/cpp/cmapstringtoob-class_3.cpp)]

Isso não é verdadeiro `GetNextAssoc` para mapas com base em modelos.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetNextAssoc`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, void\* &**  *rKey* **, void\* &**  *rValue* **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, void\* &**  *rKey* **, palavra &** *rValue* **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, CString &** *rKey* **, void\* &**  *rValue* **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, CString &** *rKey* **, CString &** *rValue* **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, palavra &** *rKey* **, CObject\* &**  *rValue* **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, palavra &** *rKey* **, void\* &**  *rValue* **) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#66](../../mfc/codesnippet/cpp/cmapstringtoob-class_4.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
Lisa : a CAge at $4724 11
Marge : a CAge at $47A8 35
Homer : a CAge at $4766 36
Bart : a CAge at $45D4 13
```

##  <a name="getsize"></a>  CMapStringToOb::GetSize

Retorna o número de elementos do mapa.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de itens no mapa.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos no mapa.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**() GetSize INT_PTR const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**() GetSize INT_PTR const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**() GetSize INT_PTR const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**() GetSize INT_PTR const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**() GetSize INT_PTR const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**() GetSize INT_PTR const;**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#67](../../mfc/codesnippet/cpp/cmapstringtoob-class_5.cpp)]

##  <a name="getstartposition"></a>  CMapStringToOb::GetStartPosition

Inicia uma iteração de mapa, retornando um valor de posição que pode ser passado para um `GetNextAssoc` chamar.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de posição que indica uma posição inicial para iterar o mapa; ou nulo se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" tem nenhum significado especial.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::GetStartPosition`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**POSICIONAR GetStartPosition (de) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**POSICIONAR GetStartPosition (de) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**POSICIONAR GetStartPosition (de) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**POSICIONAR GetStartPosition (de) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**POSICIONAR GetStartPosition (de) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**POSICIONAR GetStartPosition (de) const;**|

### <a name="example"></a>Exemplo

Veja o exemplo de [CMapStringToOb::GetNextAssoc](#getnextassoc).

##  <a name="hashkey"></a>  CMapStringToOb::HashKey

Calcula o valor de hash de uma chave especificada.

```
UINT HashKey(LPCTSTR key) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
A chave cujo valor de hash é calculado.

### <a name="return-value"></a>Valor de retorno

Valor de hash da chave

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::HashKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT HashKey (void** <strong>\*</strong> `key` **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**UINT HashKey (void** <strong>\*</strong> `key` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**UINT HashKey (LPCTSTR** `key` **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT HashKey (LPCTSTR** `key` **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**UINT HashKey (WORD** `key` **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT HashKey (WORD** `key` **) const;**|

##  <a name="inithashtable"></a>  CMapStringToOb::InitHashTable

Inicializa a tabela de hash.

```
void InitHashTable(
    UINT hashSize,
    BOOL bAllocNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*hashSize*<br/>
Número de entradas na tabela de hash.

*bAllocNow*<br/>
Se for TRUE, aloca a tabela de hash na inicialização; Caso contrário, a tabela é alocada quando necessário.

### <a name="remarks"></a>Comentários

Para obter melhor desempenho, o tamanho da tabela de hash deve ser um número primo. Para minimizar colisões, deve ser o tamanho aproximadamente 20 por cento maior do que o maior conjunto de dados previsto.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::InitHashTable`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void InitHashTable( UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE );**|

##  <a name="isempty"></a>  CMapStringToOb::IsEmpty

Determina se o mapa estiver vazio.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se este mapa não contiver elementos; Caso contrário, 0.

### <a name="example"></a>Exemplo

Veja o exemplo de [RemoveAll](#removeall).

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outro membro funções que são semelhantes às **CMapStringToOb:: IsEmpty**.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL (de) de IsEmpty const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**BOOL (de) de IsEmpty const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL (de) de IsEmpty const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL (de) de IsEmpty const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**BOOL (de) de IsEmpty const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL (de) de IsEmpty const;**|

##  <a name="lookup"></a>  CMapStringToOb::Lookup

Retorna um `CObject` ponteiro com base em um `CString` valor.

```
BOOL Lookup(
    LPCTSTR key,
    CObject*& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.

*rValue*<br/>
Especifica o valor retornado do elemento pesquisado.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o elemento foi encontrado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lookup` usa um algoritmo de hash para localizar rapidamente o elemento do mapa com uma chave que corresponda exatamente ( `CString` valor).

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::LookUp`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**Pesquisa de BOOL (void** <strong>\*</strong> `key` **, void\* &**  `rValue` **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Pesquisa de BOOL (void** <strong>\*</strong> `key` **, palavra &** `rValue` **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Pesquisa de BOOL (LPCTSTR** `key` **, void\* &**  `rValue` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Pesquisa de BOOL (LPCTSTR** `key` **, CString &** `rValue` **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Pesquisa de BOOL (WORD** `key` **, CObject\* &**  `rValue` **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Pesquisa de BOOL (WORD** `key` **, void\* &**  `rValue` **) const;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#68](../../mfc/codesnippet/cpp/cmapstringtoob-class_6.cpp)]

##  <a name="lookupkey"></a>  CMapStringToOb::LookupKey

Retorna uma referência para a chave associada com o valor de chave especificado.

```
BOOL LookupKey(
    LPCTSTR key,
    LPCTSTR& rKey) const;
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.

*rKey*<br/>
A referência para a chave associada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a chave foi encontrada; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Usando uma referência a uma chave é seguro se usado depois que o elemento associado foi removido do mapa ou depois que o mapa foi destruído.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb:: LookupKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|

##  <a name="operator_at"></a>  [CMapStringToOb::operator]

Um substituto conveniente para o `SetAt` função de membro.

```
CObject*& operator[ ](lpctstr key);
```

### <a name="return-value"></a>Valor de retorno

Uma referência a um ponteiro para um `CObject` do objeto; ou nulo se o mapa estiver vazio ou *chave* está fora do intervalo.

### <a name="remarks"></a>Comentários

Portanto, ele pode ser usado apenas no lado esquerdo de uma instrução de atribuição (um l-value). Se não houver nenhum elemento do mapa com a chave especificada, um novo elemento é criado.

Não há nenhum "direita" (r-Value) equivalente ao operador porque não há uma possibilidade de que uma chave não pode ser encontrada no mapa. Use o `Lookup` a função de membro para a recuperação do elemento.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::operator []`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|<strong>void\*& operador\[] (void \*</strong>  `key`  **\);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Operador & palavra\[] (void** <strong>\*</strong> `key`  **\);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void\*& operador\[] (lpctstr** `key`  **\);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CString & operador\[] (lpctstr** `key`  **\);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CObject\*& operador\[] (word** `key`  **\);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void\*& operador\[] (word** `key`  **\);**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#72](../../mfc/codesnippet/cpp/cmapstringtoob-class_7.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
Operator [] example: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $4A02 11
[Bart] = a CAge at $497E 13
```

##  <a name="removeall"></a>  CMapStringToOb::RemoveAll

Remove todos os elementos a partir desse mapa e destrói o `CString` objetos de chave.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

O `CObject` objetos referenciados por cada chave não são destruídos. O `RemoveAll` função pode causar vazamentos de memória se você não garantem que referenciado `CObject` objetos são destruídos.

A função funciona corretamente se o mapa já estiver vazio.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::RemoveAll`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void (de) RemoveAll;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void (de) RemoveAll;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void (de) RemoveAll;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void (de) RemoveAll;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void (de) RemoveAll;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void (de) RemoveAll;**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#69](../../mfc/codesnippet/cpp/cmapstringtoob-class_8.cpp)]

##  <a name="removekey"></a>  CMapStringToOb::RemoveKey

Procura a entrada de mapa que corresponde à chave fornecida; em seguida, se a chave for encontrada, remove a entrada.

```
BOOL RemoveKey(LPCTSTR key);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a cadeia de caracteres usada para pesquisa de mapa.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a entrada tiver sido encontrada e removida com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso pode causar vazamentos de memória se o `CObject` objeto não é excluído em outro lugar.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::RemoveKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL RemoveKey (void** <strong>\*</strong> `key` **);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**BOOL RemoveKey (void** <strong>\*</strong> `key` **);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL RemoveKey (LPCTSTR** `key` **);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL RemoveKey (LPCTSTR** `key` **);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**BOOL RemoveKey (WORD** `key` **);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL RemoveKey (WORD** `key` **);**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#70](../../mfc/codesnippet/cpp/cmapstringtoob-class_9.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
RemoveKey example: A CMapStringToOb with 3 elements
[Marge] = a CAge at $49A0 35
[Homer] = a CAge at $495E 36
[Bart] = a CAge at $4634 13
```

##  <a name="setat"></a>  CMapStringToOb::SetAt

O principal meio inserir um elemento em um mapa.

```
void SetAt(
    LPCTSTR key,
    CObject* newValue);
```

### <a name="parameters"></a>Parâmetros

*key*<br/>
Especifica a cadeia de caracteres que é a chave do novo elemento.

*newValue*<br/>
Especifica o `CObject` ponteiro que é o valor do novo elemento.

### <a name="remarks"></a>Comentários

Em primeiro lugar, a chave é pesquisada. Se a chave for encontrada, então, o valor correspondente é alterado; Caso contrário, é criado um novo elemento de chave-valor.

A tabela a seguir mostra outro membro funções que são semelhantes às `CMapStringToOb::SetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void SetAt (void** <strong>\*</strong> `key` **, void** <strong>\*</strong> `newValue` **);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void SetAt (void** <strong>\*</strong> `key` **, WORD** `newValue` **);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void SetAt (LPCTSTR** `key` **, void** <strong>\*</strong> `newValue` **);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void SetAt (LPCTSTR** `key` **, LPCTSTR** `newValue` **);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void SetAt (WORD** `key` **, CObject** <strong>\*</strong> `newValue` **);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void SetAt (WORD** `key` **, void** <strong>\*</strong> `newValue` **);**|

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#71](../../mfc/codesnippet/cpp/cmapstringtoob-class_10.cpp)]

Os resultados desse programa são da seguinte maneira:

```Output
before Lisa's birthday: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $493C 11
[Bart] = a CAge at $4654 13
after Lisa's birthday: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $49C0 12
[Bart] = a CAge at $4654 13
```

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)<br/>
[Classe CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)<br/>
[Classe CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)<br/>
[Classe CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)<br/>
[Classe CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)<br/>
[Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)
