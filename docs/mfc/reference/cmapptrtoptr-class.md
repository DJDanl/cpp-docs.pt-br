---
title: Classe CMapPtrToPtr
ms.date: 11/04/2016
f1_keywords:
- CMapPtrToPtr
- AFXCOLL/CMapPtrToPtr
- AFXCOLL/CMapPtrToPtr::CMapPtrToPtr
- AFXCOLL/CMapPtrToPtr::GetCount
- AFXCOLL/CMapPtrToPtr::GetHashTableSize
- AFXCOLL/CMapPtrToPtr::GetNextAssoc
- AFXCOLL/CMapPtrToPtr::GetSize
- AFXCOLL/CMapPtrToPtr::GetStartPosition
- AFXCOLL/CMapPtrToPtr::HashKey
- AFXCOLL/CMapPtrToPtr::InitHashTable
- AFXCOLL/CMapPtrToPtr::IsEmpty
- AFXCOLL/CMapPtrToPtr::Lookup
- AFXCOLL/CMapPtrToPtr::LookupKey
- AFXCOLL/CMapPtrToPtr::RemoveAll
- AFXCOLL/CMapPtrToPtr::RemoveKey
- AFXCOLL/CMapPtrToPtr::SetAt
helpviewer_keywords:
- CMapPtrToPtr [MFC], CMapPtrToPtr
- CMapPtrToPtr [MFC], GetCount
- CMapPtrToPtr [MFC], GetHashTableSize
- CMapPtrToPtr [MFC], GetNextAssoc
- CMapPtrToPtr [MFC], GetSize
- CMapPtrToPtr [MFC], GetStartPosition
- CMapPtrToPtr [MFC], HashKey
- CMapPtrToPtr [MFC], InitHashTable
- CMapPtrToPtr [MFC], IsEmpty
- CMapPtrToPtr [MFC], Lookup
- CMapPtrToPtr [MFC], LookupKey
- CMapPtrToPtr [MFC], RemoveAll
- CMapPtrToPtr [MFC], RemoveKey
- CMapPtrToPtr [MFC], SetAt
ms.assetid: 23cbbaec-9d64-48f2-92ae-5e24fa64b926
ms.openlocfilehash: f8fc69007d35927daaa7128de1bc0ceb0b44c746
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223038"
---
# <a name="cmapptrtoptr-class"></a>Classe CMapPtrToPtr

Dá suporte a mapas de ponteiros void codificados por ponteiros void.

## <a name="syntax"></a>Sintaxe

```
class CMapPtrToPtr : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CMapPtrToPtr` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Sempre que você vir um `CObject` ponteiro como um parâmetro de função ou valor de retorno, substitua um ponteiro para **`void`** . Sempre que você vir um `CString` ou um **`const`** ponteiro para **`char`** como um parâmetro de função ou valor de retorno, substitua um ponteiro para **`void`** .

`BOOL CMapPtrToPtr::Lookup( void* <key>, void*& <rValue> ) const;`

por exemplo, traduz para

`BOOL CMapStringToOb::Lookup( const char* <key>, CObject*& <rValue> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapPtrToPtr::CMapPtrToPtr](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapPtrToPtr:: GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapPtrToPtr::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapPtrToPtr::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento para iteração.|
|[CMapPtrToPtr::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[CMapPtrToPtr:: GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapPtrToPtr::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapPtrToPtr::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|
|[CMapPtrToPtr:: IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testes para a condição de mapa vazio (sem elementos).|
|[CMapPtrToPtr:: Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Pesquisa um ponteiro void com base na tecla de ponteiro void. O valor do ponteiro, não a entidade para a qual ele aponta, é usado para a comparação de teclas.|
|[CMapPtrToPtr:: LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência à chave associada ao valor de chave especificado.|
|[CMapPtrToPtr:: RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos deste mapa.|
|[CMapPtrToPtr::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[CMapPtrToPtr::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; Substitui um elemento existente se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CMapPtrToPtr::\]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição de operador para `SetAt` .|

## <a name="remarks"></a>Comentários

`CMapPtrToPtr`incorpora a macro IMPLEMENT_DYNAMIC para dar suporte ao acesso de tipo em tempo de execução e despejo a um `CDumpContext` objeto. Se você precisar de um despejo de elementos de mapa individuais (valores de ponteiro), deverá definir a profundidade do contexto de despejo como 1 ou maior.

Mapas de ponteiro para ponteiro não podem ser serializados.

Quando um `CMapPtrToPtr` objeto é excluído ou quando seus elementos são removidos, somente os ponteiros são removidos, e não as entidades que eles referenciam.

Para obter mais informações sobre `CMapPtrToPtr` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapPtrToPtr`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
