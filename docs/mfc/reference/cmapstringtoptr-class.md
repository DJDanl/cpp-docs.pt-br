---
title: Classe CMapStringToPtr
ms.date: 11/04/2016
f1_keywords:
- CMapStringToPtr
- AFXCOLL/CMapStringToPtr
- AFXCOLL/CMapStringToPtr::CMapStringToPtr
- AFXCOLL/CMapStringToPtr::GetCount
- AFXCOLL/CMapStringToPtr::GetHashTableSize
- AFXCOLL/CMapStringToPtr::GetNextAssoc
- AFXCOLL/CMapStringToPtr::GetSize
- AFXCOLL/CMapStringToPtr::GetStartPosition
- AFXCOLL/CMapStringToPtr::HashKey
- AFXCOLL/CMapStringToPtr::InitHashTable
- AFXCOLL/CMapStringToPtr::IsEmpty
- AFXCOLL/CMapStringToPtr::Lookup
- AFXCOLL/CMapStringToPtr::LookupKey
- AFXCOLL/CMapStringToPtr::RemoveAll
- AFXCOLL/CMapStringToPtr::RemoveKey
- AFXCOLL/CMapStringToPtr::SetAt
helpviewer_keywords:
- CMapStringToPtr [MFC], CMapStringToPtr
- CMapStringToPtr [MFC], GetCount
- CMapStringToPtr [MFC], GetHashTableSize
- CMapStringToPtr [MFC], GetNextAssoc
- CMapStringToPtr [MFC], GetSize
- CMapStringToPtr [MFC], GetStartPosition
- CMapStringToPtr [MFC], HashKey
- CMapStringToPtr [MFC], InitHashTable
- CMapStringToPtr [MFC], IsEmpty
- CMapStringToPtr [MFC], Lookup
- CMapStringToPtr [MFC], LookupKey
- CMapStringToPtr [MFC], RemoveAll
- CMapStringToPtr [MFC], RemoveKey
- CMapStringToPtr [MFC], SetAt
ms.assetid: 1ac11143-eb0a-4511-a662-2df0d1d9005b
ms.openlocfilehash: 26a606d5813a68b55d8fc555025ccef270a25766
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223012"
---
# <a name="cmapstringtoptr-class"></a>Classe CMapStringToPtr

Dá suporte a mapas de ponteiros void com chave por `CString` objetos.

## <a name="syntax"></a>Sintaxe

```
class CMapStringToPtr : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CMapStringToPtr` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vir um `CObject` ponteiro como um parâmetro de função ou valor de retorno, substitua um ponteiro para **`void`** .

`BOOL CMapStringToPtr::Lookup( LPCTSTR <key>, void*& <rValue> ) const;`

por exemplo, traduz para

`BOOL CMapStringToOb::Lookup( const char* <key>, CObject*& <rValue> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToPtr::CMapStringToPtr](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToPtr:: GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToPtr::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapStringToPtr::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CMapStringToPtr::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToPtr:: GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToPtr::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToPtr::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|
|[CMapStringToPtr:: IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapStringToPtr:: Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Pesquisa um ponteiro void com base na tecla de ponteiro void. O valor do ponteiro, não a entidade para a qual ele aponta, é usado para a comparação de teclas.|
|[CMapStringToPtr:: LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência à chave associada ao valor de chave especificado.|
|[CMapStringToPtr:: RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos deste mapa.|
|[CMapStringToPtr::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToPtr::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; Substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CMapStringToPtr::\]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt` .|

## <a name="remarks"></a>Comentários

`CMapStringToPtr`incorpora a macro IMPLEMENT_DYNAMIC para dar suporte ao acesso de tipo em tempo de execução e despejo a um `CDumpContext` objeto. Se você precisar de um despejo de elementos de mapa individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Mapas de cadeia de caracteres para ponteiro não podem ser serializados.

Quando um `CMapStringToPtr` objeto é excluído ou quando seus elementos são removidos, os `CString` objetos de chave e as palavras são removidos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapStringToPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
