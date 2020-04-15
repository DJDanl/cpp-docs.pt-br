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
ms.openlocfilehash: 12de7bd72f643f08cebf948634703172d6725ce6
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370111"
---
# <a name="cmapstringtoob-class"></a>Classe CMapStringToOb

Uma classe de coleção `CString` de `CObject` dicionários que mapeia objetos únicos para ponteiros.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToOb : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb:CMapStringToOb](#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::GetCount](#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetHashTableSize](#gethashtablesize)|Determina o número atual de elementos na tabela hash.|
|[CMapStringToOb::GetNextAssoc](#getnextassoc)|Recebe o próximo elemento para iteração.|
|[CMapStringToOb::GetSize](#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetStartPosition](#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToOb::HashKey](#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToOb::InitHashTable](#inithashtable)|Inicializa a tabela hash.|
|[CMapStringToOb::IsEmpty](#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapStringToOb::Lookup](#lookup)|Olha para um ponteiro vazio com base na tecla void pointer. O valor do ponteiro, não a entidade que ele aponta, é usado para a comparação de chaves.|
|[CMapStringToOb::LookupKey](#lookupkey)|Retorna uma referência à chave associada ao valor-chave especificado.|
|[CMapStringToOb::RemoveAll](#removeall)|Remove todos os elementos deste mapa.|
|[CMapStringToOb::RemoveKey](#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToOb::SetAt](#setat)|Insere um elemento no mapa; substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::operador \[\]](#operator_at)|Insere um elemento no mapa `SetAt`— substituição do operador para .|

## <a name="remarks"></a>Comentários

Depois de inserir `CString` -  `CObject*` um par (elemento) no mapa, você pode recuperar ou excluir `CString` eficientemente o par usando uma seqüência ou um valor como chave. Você também pode iterar sobre todos os elementos do mapa.

Uma variável do tipo POSITION é usada para acesso alternativo de entrada em todas as variações do mapa. Você pode usar uma POSIÇÃO para "lembrar" uma entrada e iterar através do mapa. Você pode pensar que essa iteração é sequencial por valor-chave; não é. A seqüência de elementos recuperados é indeterminada.

A `CMapStringToOb` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado, por sua vez, se um mapa **<<** for armazenado em `Serialize` um arquivo, seja com o operador de inserção sobrecarregada ( ) ou com a função de membro.

Se você precisar de um despejo diagnóstico dos `CString` elementos `CObject` individuais no mapa (o valor e o conteúdo), você deve definir a profundidade do contexto de despejo para 1 ou maior.

Quando `CMapStringToOb` um objeto é excluído ou quando seus `CString` elementos `CObject` são removidos, os objetos e os ponteiros são removidos. Os objetos referenciados pelos `CObject` ponteiros não são destruídos.

A derivação da classe de mapa é semelhante à derivação de lista. Consulte o artigo [Coleções](../../mfc/collections.md) para obter uma ilustração da derivação de uma classe de lista de propósito especial.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CMapStringToOb`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll.h

## <a name="cmapstringtoobcmapstringtoob"></a><a name="cmapstringtoob"></a>CMapStringToOb:CMapStringToOb

Constrói um `CString` `CObject*` mapa vazio.

```
CMapStringToOb(INT_PTR nBlockSize = 10);
```

### <a name="parameters"></a>Parâmetros

*Nblocksize*<br/>
Especifica a granularidade de alocação de memória para estender o mapa.

### <a name="remarks"></a>Comentários

À medida que o mapa cresce, a memória é alocada em unidades de entradas *nBlockSize.*

A tabela a seguir mostra outras `CMapStringToOb:: CMapStringToOb`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**CMapPtrToPtr ( INT_PTR** `nBlockSize` **= 10 );**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**CMapPtrToWord( INT_PTR** `nBlockSize` **= 10 );**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**CMapStringToPtr ( INT_PTR** `nBlockSize` **= 10 );**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**CmapStringToString ( INT_PTR** `nBlockSize` **= 10 );**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**CMapWordToOb (INT_PTR** `nBlockSize` **= 10);**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**MapWordToPtr ( INT_PTR** `nBlockSize` **= 10 );**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#63](../../mfc/codesnippet/cpp/cmapstringtoob-class_1.cpp)]

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

## <a name="cmapstringtoobgetcount"></a><a name="getcount"></a>CMapStringToOb::GetCount

Determina quantos elementos estão no mapa.

```
INT_PTR GetCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de elementos neste mapa.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras `CMapStringToOb::GetCount`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetCount;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetCount;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetCount;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetCount;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetCount;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetCount;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#64](../../mfc/codesnippet/cpp/cmapstringtoob-class_2.cpp)]

## <a name="cmapstringtoobgethashtablesize"></a><a name="gethashtablesize"></a>CMapStringToOb::GetHashTableSize

Determina o número atual de elementos na tabela hash.

```
UINT GetHashTableSize() const;
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos na tabela hash.

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras `CMapStringToOb::GetHashTableSize`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT GetHashTableSize( ) const;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**UINT GetHashTableSize( ) const;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT GetHashTableSize( ) const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**UINT GetHashTableSize( ) const;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**UINT GetHashTableSize( ) const;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT GetHashTableSize( ) const;**|

## <a name="cmapstringtoobgetnextassoc"></a><a name="getnextassoc"></a>CMapStringToOb::GetNextAssoc

Recupera o elemento mapa em *rNextPosition,* em seguida, atualiza *rNextPosition* para se referir ao próximo elemento no mapa.

```
void GetNextAssoc(
    POSITION& rNextPosition,
    CString& rKey,
    CObject*& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Rnextposition*<br/>
Especifica uma referência a um valor DE `GetNextAssoc` `GetStartPosition` POSIÇÃO retornado por uma chamada anterior ou chamada.

*Rkey*<br/>
Especifica a chave retornada do elemento recuperado (uma seqüência).

*Rvalue*<br/>
Especifica o valor retornado do elemento `CObject` recuperado (um ponteiro). Veja observações para obter mais informações sobre este parâmetro.

### <a name="remarks"></a>Comentários

Esta função é mais útil para iterar através de todos os elementos do mapa. Observe que a seqüência de posição não é necessariamente a mesma da seqüência de valor-chave.

Se o elemento recuperado for o último no mapa, então o novo valor de *rNextPosition* será definido como NULL.

Para o parâmetro *rValue,* certifique-se de lançar seu tipo de objeto para **\*CObject**, que é o que o compilador requer, como mostrado no exemplo a seguir:

[!code-cpp[NVC_MFCCollections#65](../../mfc/codesnippet/cpp/cmapstringtoob-class_3.cpp)]

Isso não é `GetNextAssoc` verdade para mapas baseados em modelos.

A tabela a seguir mostra outras `CMapStringToOb::GetNextAssoc`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**vazio GetNextAssoc (POSITION&** *rNextPosition,* **\* void** *rKey* , **void\* ** *rValue)* **const;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**vazio GetNextAssoc (POSITION&** *rNextPosition,* **void\* ** *rKey* , WORD **&** *rValue)* **const;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**vazio GetNextAssoc (POSITION&** *rNextPosition,* **CString&** *rKey* **, void\* ** *rValue)* **const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**vazio GetNextAssoc (POSITION&** *rNextPosition,* **CString&** *rKey,* **CString&** *rValue)* **const;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**vazio GetNextAssoc (POSITION&** *rNextPosition,* **WORD&** *rKey* **, CObject\* ** *rValue)* **const;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**vazio GetNextAssoc (POSIÇÃO&** *rNextPosition,* **WORD&** *rKey* **, void\* ** *rValue)* **const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#66](../../mfc/codesnippet/cpp/cmapstringtoob-class_4.cpp)]

Os resultados deste programa são os seguintes:

```Output
Lisa : a CAge at $4724 11
Marge : a CAge at $47A8 35
Homer : a CAge at $4766 36
Bart : a CAge at $45D4 13
```

## <a name="cmapstringtoobgetsize"></a><a name="getsize"></a>CMapStringToOb::GetSize

Retorna o número de elementos do mapa.

```
INT_PTR GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de itens no mapa.

### <a name="remarks"></a>Comentários

Chame este método para recuperar o número de elementos no mapa.

A tabela a seguir mostra outras `CMapStringToOb::GetSize`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**INT_PTR GetSize;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**INT_PTR GetSize;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**INT_PTR GetSize;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**INT_PTR GetSize;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**INT_PTR GetSize;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**INT_PTR GetSize;**|

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#67](../../mfc/codesnippet/cpp/cmapstringtoob-class_5.cpp)]

## <a name="cmapstringtoobgetstartposition"></a><a name="getstartposition"></a>CMapStringToOb::GetStartPosition

Inicia uma iteração de mapa retornando um valor `GetNextAssoc` DE POSIÇÃO que pode ser passado para uma chamada.

```
POSITION GetStartPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que indique uma posição inicial para iterar o mapa; ou NULO se o mapa estiver vazio.

### <a name="remarks"></a>Comentários

A sequência de iteração não é previsível; portanto, o "primeiro elemento no mapa" não tem significado especial.

A tabela a seguir mostra outras `CMapStringToOb::GetStartPosition`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**POSIÇÃO GetStartPosition;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**POSIÇÃO GetStartPosition;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**POSIÇÃO GetStartPosition;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**POSIÇÃO GetStartPosition;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**POSIÇÃO GetStartPosition;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**POSIÇÃO GetStartPosition;**|

### <a name="example"></a>Exemplo

Veja o exemplo de [CMapStringToOb::GetNextAssoc](#getnextassoc).

## <a name="cmapstringtoobhashkey"></a><a name="hashkey"></a>CMapStringToOb::HashKey

Calcula o valor de hash de uma chave especificada.

```
UINT HashKey(LPCTSTR key) const;
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
A chave cujo valor de hash deve ser calculado.

### <a name="return-value"></a>Valor retornado

O valor de hash da Chave

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras `CMapStringToOb::HashKey`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**UINT HashKey (vazio)** <strong>\*</strong> `key` **const;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**UINT HashKey (vazio)** <strong>\*</strong> `key` **const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**UINT HashKey (LPCTSTR)** `key` **const;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**UINT HashKey (LPCTSTR)** `key` **const;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**UINT HashKey (WORD)** `key` **const;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**UINT HashKey (WORD)** `key` **const;**|

## <a name="cmapstringtoobinithashtable"></a><a name="inithashtable"></a>CMapStringToOb::InitHashTable

Inicializa a tabela hash.

```
void InitHashTable(
    UINT hashSize,
    BOOL bAllocNow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Hashsize*<br/>
Número de entradas na tabela hash.

*bAllocNow*<br/>
Se TRUE, alocaa a tabela hash após a inicialização; caso contrário, a tabela é alocada quando necessário.

### <a name="remarks"></a>Comentários

Para o melhor desempenho, o tamanho da tabela hash deve ser um número primo. Para minimizar as colisões, o tamanho deve ser cerca de 20% maior do que o maior conjunto de dados previsto.

A tabela a seguir mostra outras `CMapStringToOb::InitHashTable`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**void InitHashTable (UINT** `hashSize` **, BOOL** `bAllocNow` **= TRUE);**|

## <a name="cmapstringtoobisempty"></a><a name="isempty"></a>CMapStringToOb::IsEmpty

Determina se o mapa está vazio.

```
BOOL IsEmpty() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se este mapa não contiver elementos; caso contrário, 0.

### <a name="example"></a>Exemplo

Veja o exemplo de [RemoveAll](#removeall).

### <a name="remarks"></a>Comentários

A tabela a seguir mostra outras funções de membro semelhantes a **CMapStringToOb:: IsEmpty**.

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL IsEmpty( ) const;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**BOOL IsEmpty( ) const;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**BOOL IsEmpty( ) const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**BOOL IsEmpty( ) const;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**BOOL IsEmpty( ) const;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL IsEmpty( ) const;**|

## <a name="cmapstringtooblookup"></a><a name="lookup"></a>CMapStringToOb::Lookup

Retorna `CObject` um ponteiro `CString` com base em um valor.

```
BOOL Lookup(
    LPCTSTR key,
    CObject*& rValue) const;
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a tecla string que identifica o elemento a ser examinado.

*Rvalue*<br/>
Especifica o valor retornado do elemento de análise.

### <a name="return-value"></a>Valor retornado

Não zero se o elemento foi encontrado; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Lookup`usa um algoritmo de hashing para encontrar rapidamente o `CString` elemento do mapa com uma chave que corresponde exatamente (valor).

A tabela a seguir mostra outras `CMapStringToOb::LookUp`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**Bool Lookup (vazio,** <strong>\*</strong> `key` **\* vazio)** `rValue` **const;**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**Bool Lookup (vazio** <strong>\*</strong> `key` **, WORD&)** `rValue` **const;**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**Bool Lookup (LPCTSTR** `key` **,\* void** `rValue` ) **const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**Bool Lookup (LPCTSTR** `key` **, CString&)** `rValue` **const;**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**Bool Lookup (WORD** `key` **\* , CObject)** `rValue` **const;**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**Bool Lookup (WORD** `key` **,\* void)** `rValue` **const;**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#68](../../mfc/codesnippet/cpp/cmapstringtoob-class_6.cpp)]

## <a name="cmapstringtooblookupkey"></a><a name="lookupkey"></a>CMapStringToOb::LookupKey

Retorna uma referência à chave associada ao valor-chave especificado.

```
BOOL LookupKey(
    LPCTSTR key,
    LPCTSTR& rKey) const;
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a tecla string que identifica o elemento a ser examinado.

*Rkey*<br/>
A referência à chave associada.

### <a name="return-value"></a>Valor retornado

Não zero se a chave foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

O uso de uma referência a uma chave é inseguro se usado depois que o elemento associado foi removido do mapa ou depois que o mapa foi destruído.

A tabela a seguir mostra outras `CMapStringToOb:: LookupKey`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**Bool LookupKey (LPCTSTR,** `key` **LPCTSTR&)** `rKey` **const;**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**Bool LookupKey (LPCTSTR,** `key` **LPCTSTR&)** `rKey` **const;**|

## <a name="cmapstringtooboperator--"></a><a name="operator_at"></a>CMapStringToOb::operador [ ]

Um substituto conveniente `SetAt` para a função do membro.

```
CObject*& operator[ ](lpctstr key);
```

### <a name="return-value"></a>Valor retornado

Uma referência a um `CObject` ponteiro para um objeto; ou NULL se o mapa estiver vazio ou *a chave* estiver fora de alcance.

### <a name="remarks"></a>Comentários

Assim, ele só pode ser usado no lado esquerdo de uma declaração de atribuição (um valor l). Se não houver nenhum elemento de mapa com a chave especificada, então um novo elemento será criado.

Não há "lado direito" (valor r) equivalente a este operador porque existe a possibilidade de que uma chave não possa ser encontrada no mapa. Use `Lookup` a função membro para recuperação de elementos.

A tabela a seguir mostra outras `CMapStringToOb::operator []`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|<strong>vazio\* operador\[& \* ](vazio;</strong> `key` ** \)**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**Word&\[operador ](vazio;** <strong>\*</strong> `key` ** \)**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**vazio\* operador\[& ](lpctstr;** `key` ** \)**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**Operador de\[& de CString ](lpctstr;** `key` ** \)**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**Operador\* de\[& CObject ](palavra;** `key` ** \)**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**anular\* operador\[& ](palavra;** `key` ** \)**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#72](../../mfc/codesnippet/cpp/cmapstringtoob-class_7.cpp)]

Os resultados deste programa são os seguintes:

```Output
Operator [] example: A CMapStringToOb with 2 elements
[Lisa] = a CAge at $4A02 11
[Bart] = a CAge at $497E 13
```

## <a name="cmapstringtoobremoveall"></a><a name="removeall"></a>CMapStringToOb::RemoveAll

Remove todos os elementos deste mapa `CString` e destrói os objetos-chave.

```
void RemoveAll();
```

### <a name="remarks"></a>Comentários

Os `CObject` objetos referenciados por cada chave não são destruídos. A `RemoveAll` função pode causar vazamentos de memória `CObject` se você não garantir que os objetos referenciados sejam destruídos.

A função funciona corretamente se o mapa já estiver vazio.

A tabela a seguir mostra outras `CMapStringToOb::RemoveAll`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**void RemoveAll();**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**void RemoveAll();**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**void RemoveAll();**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**void RemoveAll();**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**void RemoveAll();**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**void RemoveAll();**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#69](../../mfc/codesnippet/cpp/cmapstringtoob-class_8.cpp)]

## <a name="cmapstringtoobremovekey"></a><a name="removekey"></a>CMapStringToOb::RemoveKey

Procura a entrada do mapa correspondente à chave fornecida; em seguida, se a chave for encontrada, removerá a entrada.

```
BOOL RemoveKey(LPCTSTR key);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a seqüência usada para procurar o mapa.

### <a name="return-value"></a>Valor retornado

Não zero se a entrada foi encontrada e removida com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Isso pode causar vazamentos de memória se o `CObject` objeto não for excluído em outro lugar.

A tabela a seguir mostra outras `CMapStringToOb::RemoveKey`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**BOOL RemoveKey (vazio);** <strong>\*</strong> `key` **);**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**BOOL RemoveKey (vazio);** <strong>\*</strong> `key` **);**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**Bool Removekey (LPCTSTR);** `key` **);**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**Bool Removekey (LPCTSTR);** `key` **);**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**BOOL RemoveKey (WORD);** `key` **);**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**BOOL RemoveKey (WORD);** `key` **);**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#70](../../mfc/codesnippet/cpp/cmapstringtoob-class_9.cpp)]

Os resultados deste programa são os seguintes:

```Output
RemoveKey example: A CMapStringToOb with 3 elements
[Marge] = a CAge at $49A0 35
[Homer] = a CAge at $495E 36
[Bart] = a CAge at $4634 13
```

## <a name="cmapstringtoobsetat"></a><a name="setat"></a>CMapStringToOb::SetAt

O principal significa inserir um elemento em um mapa.

```
void SetAt(
    LPCTSTR key,
    CObject* newValue);
```

### <a name="parameters"></a>Parâmetros

*Chave*<br/>
Especifica a string que é a chave do novo elemento.

*newValue*<br/>
Especifica o `CObject` ponteiro que é o valor do novo elemento.

### <a name="remarks"></a>Comentários

Primeiro, a chave é examinada para cima. Se a chave for encontrada, o valor correspondente será alterado; caso contrário, um novo elemento de valor-chave é criado.

A tabela a seguir mostra outras `CMapStringToOb::SetAt`funções de membro semelhantes a .

|Classe|Função membro|
|-----------|---------------------|
|[Cmapptrtoptr](../../mfc/reference/cmapptrtoptr-class.md)|**void SetAt (vazio,** <strong>\*</strong> `key` <strong>\*</strong> `newValue` **vazio);** **);**|
|[Cmapptrtoword](../../mfc/reference/cmapptrtoword-class.md)|**void SetAt (vazio** <strong>\*</strong> `key` **, WORD);** `newValue` **);**|
|[Cmapstringtoptr](../../mfc/reference/cmapstringtoptr-class.md)|**void SetAt (LPCTSTR,** `key` <strong>\*</strong> `newValue` **vazio);** **);**|
|[Cmapstringtostring](../../mfc/reference/cmapstringtostring-class.md)|**void SetAt (LPCTSTR,** `key` **LPCTSTR);** `newValue` **);**|
|[Cmapwordtoob](../../mfc/reference/cmapwordtoob-class.md)|**void SetAt (WORD** `key` **, CObject);** <strong>\*</strong> `newValue` **);**|
|[Cmapwordtoptr](../../mfc/reference/cmapwordtoptr-class.md)|**void SetAt (WORD,** `key` <strong>\*</strong> `newValue` **void);** **);**|

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem da classe usada em todos os exemplos de coleção.

[!code-cpp[NVC_MFCCollections#71](../../mfc/codesnippet/cpp/cmapstringtoob-class_10.cpp)]

Os resultados deste programa são os seguintes:

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
