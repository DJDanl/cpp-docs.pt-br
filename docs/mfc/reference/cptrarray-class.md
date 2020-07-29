---
title: Classe CPtrArray
ms.date: 11/04/2016
f1_keywords:
- CPtrArray
- AFXCOLL/CPtrArray
- AFXCOLL/CPtrArray::CPtrArray
- AFXCOLL/CPtrArray::Add
- AFXCOLL/CPtrArray::Append
- AFXCOLL/CPtrArray::Copy
- AFXCOLL/CPtrArray::ElementAt
- AFXCOLL/CPtrArray::FreeExtra
- AFXCOLL/CPtrArray::GetAt
- AFXCOLL/CPtrArray::GetCount
- AFXCOLL/CPtrArray::GetData
- AFXCOLL/CPtrArray::GetSize
- AFXCOLL/CPtrArray::GetUpperBound
- AFXCOLL/CPtrArray::InsertAt
- AFXCOLL/CPtrArray::IsEmpty
- AFXCOLL/CPtrArray::RemoveAll
- AFXCOLL/CPtrArray::RemoveAt
- AFXCOLL/CPtrArray::SetAt
- AFXCOLL/CPtrArray::SetAtGrow
- AFXCOLL/CPtrArray::SetSize
helpviewer_keywords:
- CPtrArray [MFC], CPtrArray
- CPtrArray [MFC], Add
- CPtrArray [MFC], Append
- CPtrArray [MFC], Copy
- CPtrArray [MFC], ElementAt
- CPtrArray [MFC], FreeExtra
- CPtrArray [MFC], GetAt
- CPtrArray [MFC], GetCount
- CPtrArray [MFC], GetData
- CPtrArray [MFC], GetSize
- CPtrArray [MFC], GetUpperBound
- CPtrArray [MFC], InsertAt
- CPtrArray [MFC], IsEmpty
- CPtrArray [MFC], RemoveAll
- CPtrArray [MFC], RemoveAt
- CPtrArray [MFC], SetAt
- CPtrArray [MFC], SetAtGrow
- CPtrArray [MFC], SetSize
ms.assetid: c23b87a3-bf84-49d6-a66b-61e999d0938a
ms.openlocfilehash: 5db9f69348e96fffc1aa6fdc88134d777eb5406d
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226848"
---
# <a name="cptrarray-class"></a>Classe CPtrArray

Dá suporte a matrizes de ponteiros void.

## <a name="syntax"></a>Sintaxe

```
class CPtrArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro do `CPtrArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um `CObject` ponteiro como um parâmetro de função ou valor de retorno, substitua um ponteiro para **`void`** .

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`void* CPtrArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CPtrArray::CPtrArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPtrArray:: Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CPtrArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CPtrArray:: copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CPtrArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CPtrArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CPtrArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CPtrArray:: GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CPtrArray:: GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser `NULL`.|
|[CPtrArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CPtrArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CPtrArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CPtrArray:: IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CPtrArray:: RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CPtrArray:: RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CPtrArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CPtrArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CPtrArray:: SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CPtrArray::\]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CPtrArray`incorpora a macro IMPLEMENT_DYNAMIC para dar suporte ao acesso de tipo em tempo de execução e despejo a um `CDumpContext` objeto. Se você precisar de um despejo de elementos de matriz de ponteiros individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior.

> [!NOTE]
> Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

As matrizes de ponteiro não podem ser serializadas.

Quando uma matriz de ponteiro é excluída ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que eles referenciam.

Para obter mais informações sobre como usar `CPtrArray` o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
