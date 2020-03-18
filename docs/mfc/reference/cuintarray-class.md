---
title: Classe CUIntArray
ms.date: 11/04/2016
f1_keywords:
- CUIntArray
- AFXCOLL/CUIntArray
- AFXCOLL/CUIntArray::CUIntArray
- AFXCOLL/CUIntArray::Add
- AFXCOLL/CUIntArray::Append
- AFXCOLL/CUIntArray::Copy
- AFXCOLL/CUIntArray::ElementAt
- AFXCOLL/CUIntArray::FreeExtra
- AFXCOLL/CUIntArray::GetAt
- AFXCOLL/CUIntArray::GetCount
- AFXCOLL/CUIntArray::GetData
- AFXCOLL/CUIntArray::GetSize
- AFXCOLL/CUIntArray::GetUpperBound
- AFXCOLL/CUIntArray::InsertAt
- AFXCOLL/CUIntArray::IsEmpty
- AFXCOLL/CUIntArray::RemoveAll
- AFXCOLL/CUIntArray::RemoveAt
- AFXCOLL/CUIntArray::SetAt
- AFXCOLL/CUIntArray::SetAtGrow
- AFXCOLL/CUIntArray::SetSize
helpviewer_keywords:
- CUIntArray [MFC], CUIntArray
- CUIntArray [MFC], Add
- CUIntArray [MFC], Append
- CUIntArray [MFC], Copy
- CUIntArray [MFC], ElementAt
- CUIntArray [MFC], FreeExtra
- CUIntArray [MFC], GetAt
- CUIntArray [MFC], GetCount
- CUIntArray [MFC], GetData
- CUIntArray [MFC], GetSize
- CUIntArray [MFC], GetUpperBound
- CUIntArray [MFC], InsertAt
- CUIntArray [MFC], IsEmpty
- CUIntArray [MFC], RemoveAll
- CUIntArray [MFC], RemoveAt
- CUIntArray [MFC], SetAt
- CUIntArray [MFC], SetAtGrow
- CUIntArray [MFC], SetSize
ms.assetid: d71f3d8f-ef9f-4e48-9b69-7782c0e2ddf7
ms.openlocfilehash: 932062ec289a34cffcd929853233a0c7c81a7a72
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447547"
---
# <a name="cuintarray-class"></a>Classe CUIntArray

Dá suporte a matrizes de inteiros sem sinal.

## <a name="syntax"></a>Sintaxe

```
class CUIntArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro de `CUIntArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um ponteiro `CObject` como um parâmetro de função ou valor de retorno, substitua um UINT.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`UINT CUIntArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CUIntArray::CUIntArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CUIntArray:: Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CUIntArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CUIntArray:: copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CUIntArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CUIntArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CUIntArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CUIntArray:: GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CUIntArray:: GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULO.|
|[CUIntArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CUIntArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CUIntArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CUIntArray:: IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CUIntArray:: RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CUIntArray:: RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CUIntArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CUIntArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CUIntArray:: SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CUIntArray:: Operator \[ \]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Um inteiro sem sinal, ou UINT, é diferente de palavras e doublewords, pois o tamanho físico de um UINT pode mudar dependendo do ambiente operacional de destino. Um UINT tem o mesmo tamanho de um doubleword.

`CUIntArray` incorpora a macro [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic) para dar suporte ao tipo de tempo de execução e ao despejo para um objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) . Se você precisar de um despejo de elementos inteiros não assinados individuais, deverá definir a profundidade do contexto de despejo como 1 ou maior. Matrizes de inteiros não assinados não podem ser serializadas.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Para obter mais informações sobre como usar `CUIntArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CUIntArray`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
