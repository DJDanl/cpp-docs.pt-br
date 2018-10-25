---
title: Classe CMapPtrToWord | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMapPtrToWord
- AFXCOLL/CMapPtrToWord
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
dev_langs:
- C++
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
ms.assetid: 4631c6b6-d49f-49d9-adc0-1e0491e32d7b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6abca6c0cc467e2609de62b3b945a550ffe35b7b
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50074144"
---
# <a name="cmapptrtoword-class"></a>Classe CMapPtrToWord

Dá suporte a mapas de palavras de 16 bits fechadas por ponteiros nulos.

## <a name="syntax"></a>Sintaxe

```
class CMapPtrToWord : public CObject
```

## <a name="members"></a>Membros

As funções membro da `CMapPtrToWord` são semelhantes às funções de membro da classe [CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CMapStringToOb` para obter a função específica de membro. Ao ver um `CObject` ponteiro como um parâmetro de função ou um valor de retorno, substitua o WORD. Onde quer que você vê uma `CString` ou um **const** ponteiro para **char** como um parâmetro de função ou um valor de retorno, substitua um ponteiro para **void**.

`BOOL CMapStringToOb::Lookup( const char* <key>, CObject*& <rValue> ) const;`

por exemplo, traduz para

`BOOL CMapPtrToWord::Lookup( const void* <key>, WORD& <rValue> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::CMapStringToOb](../../mfc/reference/cmapstringtoob-class.md#cmapstringtoob)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMapStringToOb::GetCount](../../mfc/reference/cmapstringtoob-class.md#getcount)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetHashTableSize](../../mfc/reference/cmapstringtoob-class.md#gethashtablesize)|Determina o número atual de elementos na tabela de hash.|
|[CMapStringToOb::GetNextAssoc](../../mfc/reference/cmapstringtoob-class.md#getnextassoc)|Obtém o próximo elemento para a iteração.|
|[CMapStringToOb::GetSize](../../mfc/reference/cmapstringtoob-class.md#getsize)|Retorna o número de elementos neste mapa.|
|[CMapStringToOb::GetStartPosition](../../mfc/reference/cmapstringtoob-class.md#getstartposition)|Retorna a posição do primeiro elemento.|
|[CMapStringToOb::HashKey](../../mfc/reference/cmapstringtoob-class.md#hashkey)|Calcula o valor de hash de uma chave especificada.|
|[CMapStringToOb::InitHashTable](../../mfc/reference/cmapstringtoob-class.md#inithashtable)|Inicializa a tabela de hash.|
|[CMapStringToOb::IsEmpty](../../mfc/reference/cmapstringtoob-class.md#isempty)|Testa a condição de mapa vazio (sem elementos).|
|[CMapStringToOb::Lookup](../../mfc/reference/cmapstringtoob-class.md#lookup)|Procura um ponteiro nulo na chave de ponteiro nulo. O valor do ponteiro, não a entidade a qual ele aponta, é usado para a comparação de chave.|
|[CMapStringToOb::LookupKey](../../mfc/reference/cmapstringtoob-class.md#lookupkey)|Retorna uma referência para a chave associada com o valor de chave especificado.|
|[CMapStringToOb::RemoveAll](../../mfc/reference/cmapstringtoob-class.md#removeall)|Remove todos os elementos a partir desse mapa.|
|[CMapStringToOb::RemoveKey](../../mfc/reference/cmapstringtoob-class.md#removekey)|Remove um elemento especificado por uma chave.|
|[CMapStringToOb::SetAt](../../mfc/reference/cmapstringtoob-class.md#setat)|Insere um elemento no mapa; substitui um elemento existente, se uma chave correspondente for encontrada.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[[CMapStringToOb::operator]](../../mfc/reference/cmapstringtoob-class.md#operator_at)|Insere um elemento no mapa — substituição do operador para `SetAt`.|

## <a name="remarks"></a>Comentários

`CMapWordToPtr` incorpora a macro IMPLEMENT_DYNAMIC para dar suporte a acesso de tipo de tempo de execução e despejo para um `CDumpContext` objeto. Se você precisar de um despejo de elementos do mapa individual, você deve definir a profundidade do contexto de despejo para 1 ou maior.

Mapas de ponteiro para o word não podem ser serializados.

Quando um `CMapPtrToWord` objeto é excluído, ou quando seus elementos forem removidos, os ponteiros e as palavras serão removidas. As entidades referenciadas por chave ponteiros não são removidas.

Para obter mais informações sobre `CMapPtrToWord`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CMapPtrToWord`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** & amp;lt;1}afxcoll.h

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

