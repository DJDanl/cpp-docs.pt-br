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
ms.openlocfilehash: b56e9052533269ba62d248312f07ac16db71bf4a
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418534"
---
# <a name="cmapstringtoob-class"></a>Classe CMapStringToOb

Uma classe de coleção Dictionary que mapeia objetos `CString` exclusivos para ponteiros de `CObject`.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToOb : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMapStringToOb::CMapStringToOb](#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMapStringToOb:: GetCount](#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetHashTableSize](#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapStringToOb::GetNextAssoc](#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CMapStringToOb::GetSize](#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb:: GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToOb::HashKey](#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToOb::InitHashTable](#inithashtable)|Inicializa a tabela de hash.|
|[CMapStringToOb:: IsEmpty](#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapStringToOb:: Lookup](#lookup)|Pesquisa um ponteiro void com base na tecla de ponteiro void. O valor do ponteiro, não a entidade para a qual ele aponta, é usado para a comparação de teclas.|
|[CMapStringToOb:: LookupKey](#lookupkey)|Retorna uma referência à chave associada ao valor de chave especificado.|
|[CMapStringToOb:: RemoveAll](#removeall)|Remove todos os elementos deste mapa.|
|[CMapStringToOb::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToOb::SetAt](#setat)|Insere um elemento no mapa; Substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CMapStringToOb:: Operator \[ \]](#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt`.|

## <a name="remarks"></a>Comentários

Depois de inserir um `CString`- `CObject*` par (elemento) no mapa, você pode recuperar ou excluir com eficiência o par usando uma cadeia de caracteres ou um valor de `CString` como uma chave. Você também pode iterar em todos os elementos no mapa.

Uma variável do tipo POSITION é usada para acesso de entrada alternativo em todas as variações de mapa. Você pode usar uma posição para "lembrar" uma entrada e iterar por meio do mapa. Você pode imaginar que essa iteração é sequencial por valor de chave; Não é. A sequência de elementos recuperados é indeterminada.

A `CMapStringToOb` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por vez se um mapa é armazenado em um arquivo morto, com o operador de inserção sobrecarregada ( **<<** ) ou com a função de membro `Serialize`.

Se você precisar de um despejo de diagnóstico dos elementos individuais no mapa (o valor de `CString` e o conteúdo do `CObject`), deverá definir a profundidade do contexto de despejo como 1 ou maior.

Quando um objeto de `CMapStringToOb` é excluído ou quando seus elementos são removidos, os objetos `CString` e os ponteiros de `CObject` são removidos. Os objetos referenciados pelos ponteiros de `CObject` não são destruídos.

A derivação de classe de mapa é semelhante à derivação de lista. Consulte o artigo [coleções](../../mfc/collections.md) para obter uma ilustração da derivação de uma classe de lista de finalidade especial.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapStringToOb`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

##  <a name="cmapstringtoob"></a>CMapStringToOb::CMapStringToOb

Constrói um mapa `CString`para `CObject*` vazio.

```
CMapStringToOb(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>parâmetros

*nBlockSize*<br/>
Especifica a granularidade de alocação de memória para estender o mapa.

### <a name="remarks"></a>Comentários

À medida que o mapa cresce, a memória é alocada em unidades de entradas *nBlockSize* .

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb:: CMapStringToOb`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**CMapPtrToPtr (INT_PTR** `nBlockSize` **= 10);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**CMapPtrToWord (INT_PTR** `nBlockSize` **= 10);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**CMapStringToPtr (INT_PTR** `nBlockSize` **= 10);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CMapStringToString (INT_PTR** `nBlockSize` **= 10);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CMapWordToOb (INT_PTR** `nBlockSize` **= 10);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**MapWordToPtr (INT_PTR** `nBlockSize` **= 10);**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#63](../../mfc/codesnippet/cpp/cmapstringtoob-class_1.cpp)]

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

##  <a name="getcount"></a>CMapStringToOb:: GetCount

Determina quantos elementos estão no mapa.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos neste mapa.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::GetCount`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetCount () const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetCount () const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetCount () const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetCount () const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetCount () const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetCount () const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#64](../../mfc/codesnippet/cpp/cmapstringtoob-class_2.cpp)]

##  <a name="gethashtablesize"></a>CMapStringToOb::GetHashTableSize

Determina o número atual de elementos na tabela de hash.

```
UINT GetHashTableSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos na tabela de hash.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::GetHashTableSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT GetHashTableSize () const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**UINT GetHashTableSize () const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT GetHashTableSize () const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**UINT GetHashTableSize () const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**UINT GetHashTableSize () const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT GetHashTableSize () const;**|

##  <a name="getnextassoc"></a>CMapStringToOb::GetNextAssoc

Recupera o elemento Map em *rNextPosition*e atualiza *rNextPosition* para se referir ao próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rNextPosition,
    CString& rKey,
    CObject*& rValue) const;
```

### <a name="parameters"></a>parâmetros

*rNextPosition*<br/>
Especifica uma referência a um valor de posição retornado por uma chamada anterior `GetNextAssoc` ou `GetStartPosition`.

*rKey*<br/>
Especifica a chave retornada do elemento recuperado (uma cadeia de caracteres).

*rValue*<br/>
Especifica o valor retornado do elemento recuperado (um ponteiro de `CObject`). Consulte comentários para obter mais informações sobre esse parâmetro.

### <a name="remarks"></a>Comentários

Essa função é mais útil para iterar por todos os elementos no mapa. Observe que a sequência de posição não é necessariamente a mesma que a sequência de valor de chave.

Se o elemento recuperado for o último no mapa, o novo valor de *rNextPosition* será definido como NULL.

Para o parâmetro *rvalue* , certifique-se de converter o tipo de objeto em **CObject\*&** , que é o que o compilador requer, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCCollections#65](../../mfc/codesnippet/cpp/cmapstringtoob-class_3.cpp)]

Isso não é verdade de `GetNextAssoc` para mapas com base em modelos.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::GetNextAssoc`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void GetNextAssoc (POSITION &** *rNextPosition* **, void\*&** *rKey* **, void\*&** *rvalue* **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void GetNextAssoc (POSITION &** *rNextPosition* **, void\*&** *rKey* **, Word &** *rvalue* **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void GetNextAssoc (POSITION &** *rNextPosition* **, CString &** *rKey* **, void\*&** *rvalue* **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, CString &** *rKey* **, CString &** *rvalue* **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, WORD &** *rKey* **, CObject\*&** *rvalue* **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void GetNextAssoc (posição &** *rNextPosition* **, WORD &** *rKey* **, void\*&** *rvalue* **) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#66](../../mfc/codesnippet/cpp/cmapstringtoob-class_4.cpp)]

Os resultados desse programa são os seguintes:

```Output
Lisa : a CAge at $4724 11
Marge : a CAge at $47A8 35
Homer : a CAge at $4766 36
Bart : a CAge at $45D4 13
```

##  <a name="getsize"></a>CMapStringToOb::GetSize

Retorna o número de elementos do mapa.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no mapa.

### <a name="remarks"></a>Comentários

Chame esse método para recuperar o número de elementos no mapa.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::GetSize`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetSize () const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetSize () const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetSize () const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetSize () const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetSize () const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetSize () const;**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#67](../../mfc/codesnippet/cpp/cmapstringtoob-class_5.cpp)]

##  <a name="getstartposition"></a>CMapStringToOb:: GetStartPosition

Inicia uma iteração de mapa retornando um valor de posição que pode ser passado para uma chamada de `GetNextAssoc`.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que indica uma posição inicial para iterar o mapa; ou NULL se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; Portanto, o "primeiro elemento no mapa" não tem significância especial.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::GetStartPosition`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**Posicione GetStartPosition () const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Posicione GetStartPosition () const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Posicione GetStartPosition () const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Posicione GetStartPosition () const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Posicione GetStartPosition () const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Posicione GetStartPosition () const;**|

### <a name="example"></a>Exemplo

Consulte o exemplo de [CMapStringToOb:: GetNextAssoc](#getnextassoc).

##  <a name="hashkey"></a>CMapStringToOb::HashKey

Calcula o valor de hash de uma chave especificada.

```
UINT HashKey(LPCTSTR key) const;
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
A chave cujo valor de hash deve ser calculado.

### <a name="return-value"></a>Valor retornado

O valor de hash da chave

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::HashKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**HashKey uint (void** <strong>\*</strong> `key` **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**HashKey uint (void** <strong>\*</strong> `key` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Uint HashKey (LPCTSTR** `key` **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Uint HashKey (LPCTSTR** `key` **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Uint HashKey (WORD** `key` **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Uint HashKey (WORD** `key` **) const;**|

##  <a name="inithashtable"></a>CMapStringToOb::InitHashTable

Inicializa a tabela de hash.

```
void InitHashTable(
    UINT hashSize,
    BOOL bAllocNow = TRUE);
```

### <a name="parameters"></a>parâmetros

*hashSize*<br/>
Número de entradas na tabela de hash.

*bAllocNow*<br/>
Se for TRUE, alocará a tabela de hash na inicialização; caso contrário, a tabela será alocada quando necessário.

### <a name="remarks"></a>Comentários

Para obter o melhor desempenho, o tamanho da tabela de hash deve ser um número primo. Para minimizar as colisões, o tamanho deve ser aproximadamente 20% maior do que o maior conjunto de dados previsto.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::InitHashTable`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, bool** `bAllocNow` **= true);**|

##  <a name="isempty"></a>CMapStringToOb:: IsEmpty

Determina se o mapa está vazio.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se este mapa não contiver nenhum elemento; caso contrário, 0.

### <a name="example"></a>Exemplo

Consulte o exemplo de [RemoveAll](#removeall).

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras funções de membro que são semelhantes a **CMapStringToOb:: IsEmpty**.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL IsEmpty () const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**BOOL IsEmpty () const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL IsEmpty () const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**BOOL IsEmpty () const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**BOOL IsEmpty () const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL IsEmpty () const;**|

##  <a name="lookup"></a>CMapStringToOb:: Lookup

Retorna um ponteiro de `CObject` com base em um valor de `CString`.

```
BOOL Lookup(
    LPCTSTR key,
    CObject*& rValue) const;
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.

*rValue*<br/>
Especifica o valor retornado do elemento procurado.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o elemento foi encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lookup` usa um algoritmo de hash para localizar rapidamente o elemento Map com uma chave que corresponde exatamente (`CString` valor).

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::LookUp`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**Pesquisa BOOL (void** <strong>\*</strong> `key` **, void\*&** `rValue` **) const;**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Pesquisa BOOL (void** <strong>\*</strong> `key` **, palavra &** `rValue` **) const;**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Pesquisa BOOL (LPCTSTR** `key` **, void\*&** `rValue` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Consulta bool (LPCTSTR** `key` **, CString &** `rValue` **) const;**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Pesquisa BOOL (WORD** `key` **, CObject\*&** `rValue` **) const;**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Pesquisa BOOL (WORD** `key` **, void\*&** `rValue` **) const;**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#68](../../mfc/codesnippet/cpp/cmapstringtoob-class_6.cpp)]

##  <a name="lookupkey"></a>CMapStringToOb:: LookupKey

Retorna uma referência à chave associada ao valor de chave especificado.

```
BOOL LookupKey(
    LPCTSTR key,
    LPCTSTR& rKey) const;
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Especifica a chave de cadeia de caracteres que identifica o elemento a ser pesquisado.

*rKey*<br/>
A referência à chave associada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a chave foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

O uso de uma referência a uma chave não será seguro se for usado depois que o elemento associado tiver sido removido do mapa ou depois que o mapa tiver sido destruído.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb:: LookupKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Bool LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Bool LookupKey (LPCTSTR** `key` **, LPCTSTR &** `rKey` **) const;**|

##  <a name="operator_at"></a>CMapStringToOb:: operator []

Um substituto conveniente para a função membro `SetAt`.

```
CObject*& operator[ ](lpctstr key);
```

### <a name="return-value"></a>Valor retornado

Uma referência a um ponteiro para um objeto `CObject`; ou NULL se o mapa estiver vazio ou a *chave* estiver fora do intervalo.

### <a name="remarks"></a>Comentários

Portanto, ele pode ser usado somente no lado esquerdo de uma instrução de atribuição (um l-Value). Se não houver nenhum elemento de mapa com a chave especificada, um novo elemento será criado.

Não há nenhum "lado direito" (r-value) equivalente a esse operador porque há uma possibilidade de que uma chave não seja encontrada no mapa. Use a função membro `Lookup` para recuperação de elemento.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::operator []`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|<strong>void\*& operator\[] (void \*</strong> `key` **\);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Operador do WORD &\[] (void** <strong>\*</strong> `key` **\);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void\*& operator\[] (lpctstr** `key` **\);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**CString & operator\[] (lpctstr** `key` **\);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**CObject\*& operator\[] (palavra** `key` **\);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void\*& operator\[] (palavra** `key` **\);**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#72](../../mfc/codesnippet/cpp/cmapstringtoob-class_7.cpp)]

Os resultados desse programa são os seguintes:

```Output
Operator [] example: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $4A02 11
[Bart] = a CAge at $497E 13
```

##  <a name="removeall"></a>CMapStringToOb:: RemoveAll

Remove todos os elementos desse mapa e destrói os `CString` objetos de chave.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Os objetos `CObject` referenciados por cada chave não são destruídos. A função `RemoveAll` pode causar vazamentos de memória se você não garantir que os objetos de `CObject` referenciados sejam destruídos.

A função funcionará corretamente se o mapa já estiver vazio.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::RemoveAll`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void RemoveAll ();**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void RemoveAll ();**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void RemoveAll ();**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void RemoveAll ();**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void RemoveAll ();**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void RemoveAll ();**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#69](../../mfc/codesnippet/cpp/cmapstringtoob-class_8.cpp)]

##  <a name="removekey"></a>CMapStringToOb::RemoveKey

Pesquisa a entrada do mapa correspondente à chave fornecida; em seguida, se a chave for encontrada, o removerá a entrada.

```
BOOL RemoveKey(LPCTSTR key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Especifica a cadeia de caracteres usada para pesquisa de mapa.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a entrada foi encontrada e removida com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso pode causar vazamentos de memória se o objeto `CObject` não for excluído em outro lugar.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::RemoveKey`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**Bool RemoveKey (void** <strong>\*</strong> `key` **);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**Bool RemoveKey (void** <strong>\*</strong> `key` **);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**Bool RemoveKey (LPCTSTR** `key` **);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**Bool RemoveKey (LPCTSTR** `key` **);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**Bool RemoveKey (WORD** `key` **);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**Bool RemoveKey (WORD** `key` **);**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#70](../../mfc/codesnippet/cpp/cmapstringtoob-class_9.cpp)]

Os resultados desse programa são os seguintes:

```Output
RemoveKey example: A CMapStringToOb with 3 elements
[Marge] = a CAge at $49A0 35
[Homer] = a CAge at $495E 36
[Bart] = a CAge at $4634 13
```

##  <a name="setat"></a>CMapStringToOb::SetAt

O principal meio de inserir um elemento em um mapa.

```
void SetAt(
    LPCTSTR key,
    CObject* newValue);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Especifica a cadeia de caracteres que é a chave do novo elemento.

*newValue*<br/>
Especifica o ponteiro de `CObject` que é o valor do novo elemento.

### <a name="remarks"></a>Comentários

Primeiro, a chave é pesquisada. Se a chave for encontrada, o valor correspondente será alterado; caso contrário, um novo elemento chave-valor será criado.

A tabela a seguir mostra outras funções de membro que são semelhantes a `CMapStringToOb::SetAt`.

|Classe|Função membro|
|-----------|---------------------|
|[CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)|**void SetAt (void** <strong>\*</strong> `key` **, void** <strong>\*</strong> `newValue` **);**|
|[CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)|**void SetAt (void** <strong>\*</strong> `key` **, Word** `newValue` **);**|
|[CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)|**void SetAt (LPCTSTR** `key` **, void** <strong>\*</strong> `newValue` **);**|
|[CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)|**void SetAt (LPCTSTR** `key` **, LPCTSTR** `newValue` **);**|
|[CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)|**void SetAt (WORD** `key` **, CObject** <strong>\*</strong> `newValue` **);**|
|[CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)|**void SetAt (WORD** `key` **, void** <strong>\*</strong> `newValue` **);**|

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da classe `CAge` usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#71](../../mfc/codesnippet/cpp/cmapstringtoob-class_10.cpp)]

Os resultados desse programa são os seguintes:

```Output
before Lisa's birthday: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $493C 11
[Bart] = a CAge at $4654 13
after Lisa's birthday: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $49C0 12
[Bart] = a CAge at $4654 13
```

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CMapPtrToPtr](../../mfc/reference/cmapptrtoptr-class.md)<br/>
[Classe CMapPtrToWord](../../mfc/reference/cmapptrtoword-class.md)<br/>
[Classe CMapStringToPtr](../../mfc/reference/cmapstringtoptr-class.md)<br/>
[Classe CMapStringToString](../../mfc/reference/cmapstringtostring-class.md)<br/>
[Classe CMapWordToOb](../../mfc/reference/cmapwordtoob-class.md)<br/>
[Classe CMapWordToPtr](../../mfc/reference/cmapwordtoptr-class.md)
