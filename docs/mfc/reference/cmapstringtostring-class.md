---
title: Classe CMapStringToString
ms.date: 11/04/2016
f1_keywords:
- CMapStringToString
- AFXCOLL/CMapStringToString
- AFXCOLL/CMapStringToString::CPair
- AFXCOLL/CMapStringToString::CMapStringToString
- AFXCOLL/CMapStringToString::GetCount
- AFXCOLL/CMapStringToString::GetHashTableSize
- AFXCOLL/CMapStringToString::GetNextAssoc
- AFXCOLL/CMapStringToString::GetSize
- AFXCOLL/CMapStringToString::GetStartPosition
- AFXCOLL/CMapStringToString::HashKey
- AFXCOLL/CMapStringToString::InitHashTable
- AFXCOLL/CMapStringToString::IsEmpty
- AFXCOLL/CMapStringToString::Lookup
- AFXCOLL/CMapStringToString::LookupKey
- AFXCOLL/CMapStringToString::PGetFirstAssoc
- AFXCOLL/CMapStringToString::PGetNextAssoc
- AFXCOLL/CMapStringToString::PLookup
- AFXCOLL/CMapStringToString::RemoveAll
- AFXCOLL/CMapStringToString::RemoveKey
- AFXCOLL/CMapStringToString::SetAt
helpviewer_keywords:
- CMapStringToString [MFC], CPair
- CMapStringToString [MFC], CMapStringToString
- CMapStringToString [MFC], GetCount
- CMapStringToString [MFC], GetHashTableSize
- CMapStringToString [MFC], GetNextAssoc
- CMapStringToString [MFC], GetSize
- CMapStringToString [MFC], GetStartPosition
- CMapStringToString [MFC], HashKey
- CMapStringToString [MFC], InitHashTable
- CMapStringToString [MFC], IsEmpty
- CMapStringToString [MFC], Lookup
- CMapStringToString [MFC], LookupKey
- CMapStringToString [MFC], PGetFirstAssoc
- CMapStringToString [MFC], PGetNextAssoc
- CMapStringToString [MFC], PLookup
- CMapStringToString [MFC], RemoveAll
- CMapStringToString [MFC], RemoveKey
- CMapStringToString [MFC], SetAt
ms.assetid: b45794c2-fe6b-4edb-a8ca-faa03b57b4a8
ms.openlocfilehash: 28422c26ba2ca77657bfcf166592d2bc69169891
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222999"
---
# <a name="cmapstringtostring-class"></a>Classe CMapStringToString

Dá suporte a mapas de `CString` objetos com chave por `CString` objetos.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToString : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CMapStringToString` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vir um `CObject` ponteiro como um valor de retorno ou parâmetro de função "output", substitua um ponteiro para **`char`** . Sempre que você vir um `CObject` ponteiro como um parâmetro de função de "entrada", substitua um ponteiro para **`char`** .

`BOOL CMapStringToString::Lookup(LPCTSTR<key>, CString&<rValue>) const;`

por exemplo, traduz para

`BOOL CMapStringToOb::Lookup(const char*<key>, CObject*&<rValue>) const;`

### <a name="public-structures"></a>Estruturas públicas

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToString::CPair](#cpair)|Uma estrutura aninhada que contém um valor de chave e o valor do objeto de cadeia de caracteres associado.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToString::CMapStringToString](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToString:: GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToString::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapStringToString::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CMapStringToString::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToString:: GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToString::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToString::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|
|[CMapStringToString:: IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapStringToString:: Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Pesquisa um ponteiro void com base na tecla de ponteiro void. O valor do ponteiro, não a entidade para a qual ele aponta, é usado para a comparação de teclas.|
|[CMapStringToString:: LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência à chave associada ao valor de chave especificado.|
|[CMapStringToString::P GetFirstAssoc](#pgetfirstassoc)|Obtém um ponteiro para o primeiro `CString` no mapa.|
|[CMapStringToString::P GetNextAssoc](#pgetnextassoc)|Obtém um ponteiro para o próximo `CString` para iteração.|
|[CMapStringToString: pesquisa de:P](#plookup)|Retorna um ponteiro para um `CString` cujo valor corresponde ao valor especificado.|
|[CMapStringToString:: RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos deste mapa.|
|[CMapStringToString::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToString::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; Substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CMapStringToString::\]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt` .|

## <a name="remarks"></a>Comentários

A `CMapStringToString` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Cada elemento é serializado por vez se um mapa é armazenado em um arquivo morto, com o operador de inserção ( **<<** ) sobrecarregado ou com a `Serialize` função de membro.

Se você precisar de um despejo de `CString` -  `CString` elementos individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Quando um `CMapStringToString` objeto é excluído ou quando seus elementos são removidos, os `CString` objetos são removidos conforme apropriado.

Para obter mais informações sobre `CMapStringToString` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapStringToString`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="cmapstringtostringcpair"></a><a name="cpair"></a>CMapStringToString::CPair

Contém um valor de chave e o valor do objeto de cadeia de caracteres associado.

### <a name="remarks"></a>Comentários

Esta é uma estrutura aninhada dentro da classe [CMapStringToString](../../mfc/reference/cmapstringtostring-class.md).

A estrutura é composta de dois campos:

- `key`O valor real do tipo de chave.

- `value`O valor do objeto associado.

Ele é usado para armazenar os valores de retorno de [CMapStringToString::P Lookup](#plookup), [CMapStringToString::P getfirstassoc](#pgetfirstassoc)e [CMapStringToString::P GetNextAssoc](#pgetnextassoc).

### <a name="example"></a>Exemplo

  Para obter um exemplo de uso, consulte o exemplo de [CMapStringToString::P Lookup](#plookup).

## <a name="cmapstringtostringpgetfirstassoc"></a><a name="pgetfirstassoc"></a>CMapStringToString::P GetFirstAssoc

Retorna a primeira entrada do objeto de mapa.

```
const CPair* PGetFirstAssoc() const;

CPair* PGetFirstAssoc();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a primeira entrada no mapa; consulte [CMapStringToString:: CPair](#cpair). Se o mapa estiver vazio, o valor será NULL.

### <a name="remarks"></a>Comentários

Chame essa função para retornar um ponteiro do primeiro elemento no objeto de mapa.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#73](../../mfc/codesnippet/cpp/cmapstringtostring-class_1.cpp)]

## <a name="cmapstringtostringpgetnextassoc"></a><a name="pgetnextassoc"></a>CMapStringToString::P GetNextAssoc

Recupera o elemento MAP apontado por *pAssocRec*.

```
const CPair *PGetNextAssoc(const CPair* pAssoc) const;

CPair *PGetNextAssoc(const CPair* pAssoc);
```

### <a name="parameters"></a>parâmetros

*pAssoc*<br/>
Aponta para uma entrada de mapa retornada por uma chamada [PGetNextAssoc](#pgetnextassoc) ou [PGetFirstAssoc](#pgetfirstassoc) anterior.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a próxima entrada no mapa; consulte [CMapStringToString:: CPair](#cpair). Se o elemento for o último no mapa, o valor será NULL.

### <a name="remarks"></a>Comentários

Chame esse método para iterar em todos os elementos no mapa. Recupere o primeiro elemento com uma chamada para `PGetFirstAssoc` e, em seguida, itere pelo mapa com chamadas sucessivas para `PGetNextAssoc` .

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CMapStringToString::P getfirstassoc](#pgetfirstassoc).

## <a name="cmapstringtostringplookup"></a><a name="plookup"></a>CMapStringToString: pesquisa de:P

Pesquisa o valor mapeado para uma determinada chave.

```
const CPair* PLookup(LPCTSTR key) const;

CPair* PLookup(LPCTSTR key);
```

### <a name="parameters"></a>parâmetros

*chave*<br/>
Um ponteiro para a chave do elemento a ser procurado.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a chave especificada.

### <a name="remarks"></a>Comentários

Chame esse método para pesquisar um elemento de mapa com uma chave que corresponda exatamente à chave especificada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCollections#74](../../mfc/codesnippet/cpp/cmapstringtostring-class_2.cpp)]

## <a name="see-also"></a>Confira também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
