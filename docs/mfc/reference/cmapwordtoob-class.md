---
title: Classe CMapWordToOb
ms.date: 11/04/2016
f1_keywords:
- CMapWordToOb
- AFXCOLL/CMapWordToOb
- AFXCOLL/CMapWordToOb::CMapWordToOb
- AFXCOLL/CMapWordToOb::GetCount
- AFXCOLL/CMapWordToOb::GetHashTableSize
- AFXCOLL/CMapWordToOb::GetNextAssoc
- AFXCOLL/CMapWordToOb::GetSize
- AFXCOLL/CMapWordToOb::GetStartPosition
- AFXCOLL/CMapWordToOb::HashKey
- AFXCOLL/CMapWordToOb::InitHashTable
- AFXCOLL/CMapWordToOb::IsEmpty
- AFXCOLL/CMapWordToOb::Lookup
- AFXCOLL/CMapWordToOb::LookupKey
- AFXCOLL/CMapWordToOb::RemoveAll
- AFXCOLL/CMapWordToOb::RemoveKey
- AFXCOLL/CMapWordToOb::SetAt
helpviewer_keywords:
- CMapWordToOb [MFC], CMapWordToOb
- CMapWordToOb [MFC], GetCount
- CMapWordToOb [MFC], GetHashTableSize
- CMapWordToOb [MFC], GetNextAssoc
- CMapWordToOb [MFC], GetSize
- CMapWordToOb [MFC], GetStartPosition
- CMapWordToOb [MFC], HashKey
- CMapWordToOb [MFC], InitHashTable
- CMapWordToOb [MFC], IsEmpty
- CMapWordToOb [MFC], Lookup
- CMapWordToOb [MFC], LookupKey
- CMapWordToOb [MFC], RemoveAll
- CMapWordToOb [MFC], RemoveKey
- CMapWordToOb [MFC], SetAt
ms.assetid: 9c9bcd76-456f-4cf9-b03c-dd28b49d5e4f
ms.openlocfilehash: f360760bb5c04400ed77ef49c5968f8e9e7a6e59
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222986"
---
# <a name="cmapwordtoob-class"></a>Classe CMapWordToOb

Dá suporte a mapas de `CObject` ponteiros digitados por palavras de 16 bits.

## <a name="syntax"></a>Sintaxe

```
class CMapWordToOb : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CMapWordToOb` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vir um `CString` ou um **`const`** ponteiro para **`char`** como um parâmetro de função ou valor de retorno, substitua Word.

`BOOL CMapWordToOb::Lookup( WORD <key>, CObject*& <rValue> ) const;`

por exemplo, traduz para

`BOOL CMapStringToOb::Lookup( const char* <key>, CObject*& <rValue> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapWordToOb::CMapWordToOb](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapWordToOb:: GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapWordToOb::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapWordToOb::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CMapWordToOb::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[CMapWordToOb:: GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapWordToOb::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapWordToOb::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|
|[CMapWordToOb:: IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapWordToOb:: Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Pesquisa um ponteiro void com base na tecla de ponteiro void. O valor do ponteiro, não a entidade para a qual ele aponta, é usado para a comparação de teclas.|
|[CMapWordToOb:: LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência à chave associada ao valor de chave especificado.|
|[CMapWordToOb:: RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos deste mapa.|
|[CMapWordToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[CMapWordToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; Substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CMapWordToOb::\]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt` .|

## <a name="remarks"></a>Comentários

`CMapWordToOb`incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e ao despejo de seus elementos. Cada elemento é serializado por vez se um mapa é armazenado em um arquivo morto, com o operador de inserção ( **<<** ) sobrecarregado ou com a `Serialize` função de membro.

Se você precisar de um despejo de elementos de palavra individuais `CObject` , deverá definir a profundidade do contexto de despejo como 1 ou maior.

Quando um `CMapWordToOb` objeto é excluído ou quando seus elementos são removidos, os `CObject` ponteiros são removidos. Os objetos referenciados pelos `CObject` ponteiros não são destruídos.

Para obter mais informações sobre `CMapWordToOb` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapWordToOb`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
