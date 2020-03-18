---
title: Classe CByteArray
ms.date: 11/04/2016
f1_keywords:
- CByteArray
- AFXCOLL/CByteArray
- AFXCOLL/CByteArray::CByteArray
- AFXCOLL/CByteArray::Add
- AFXCOLL/CByteArray::Append
- AFXCOLL/CByteArray::Copy
- AFXCOLL/CByteArray::ElementAt
- AFXCOLL/CByteArray::FreeExtra
- AFXCOLL/CByteArray::GetAt
- AFXCOLL/CByteArray::GetCount
- AFXCOLL/CByteArray::GetData
- AFXCOLL/CByteArray::GetSize
- AFXCOLL/CByteArray::GetUpperBound
- AFXCOLL/CByteArray::InsertAt
- AFXCOLL/CByteArray::IsEmpty
- AFXCOLL/CByteArray::RemoveAll
- AFXCOLL/CByteArray::RemoveAt
- AFXCOLL/CByteArray::SetAt
- AFXCOLL/CByteArray::SetAtGrow
- AFXCOLL/CByteArray::SetSize
helpviewer_keywords:
- CByteArray [MFC], CByteArray
- CByteArray [MFC], Add
- CByteArray [MFC], Append
- CByteArray [MFC], Copy
- CByteArray [MFC], ElementAt
- CByteArray [MFC], FreeExtra
- CByteArray [MFC], GetAt
- CByteArray [MFC], GetCount
- CByteArray [MFC], GetData
- CByteArray [MFC], GetSize
- CByteArray [MFC], GetUpperBound
- CByteArray [MFC], InsertAt
- CByteArray [MFC], IsEmpty
- CByteArray [MFC], RemoveAll
- CByteArray [MFC], RemoveAt
- CByteArray [MFC], SetAt
- CByteArray [MFC], SetAtGrow
- CByteArray [MFC], SetSize
ms.assetid: 53d4a512-657c-4187-9609-e3f5339a78e0
ms.openlocfilehash: 2453e7c040b9101f9c3a3b018e274b16e76ebea7
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446357"
---
# <a name="cbytearray-class"></a>Classe CByteArray

Dá suporte a matrizes dinâmicas de bytes.

## <a name="syntax"></a>Sintaxe

```
class CByteArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro de `CByteArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um ponteiro `CObject` como um parâmetro de função ou valor de retorno, substitua um BYTE.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`BYTE CByteArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CByteArray::CByteArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CByteArray:: Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CByteArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CByteArray:: copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CByteArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária para o byte dentro da matriz.|
|[CByteArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CByteArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CByteArray:: GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CByteArray:: GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULO.|
|[CByteArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CByteArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CByteArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CByteArray:: IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CByteArray:: RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CByteArray:: RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CByteArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CByteArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CByteArray:: SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CByteArray:: Operator \[ \]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CByteArray` incorpora a macro IMPLEMENT_SERIAL para dar suporte à serialização e ao despejo de seus elementos. Se uma matriz de bytes for armazenada em um arquivo morto, com o operador de inserção sobrecarregada ( **<<** ) ou com a função de membro `Serialize`, cada elemento será, por sua vez, serializado.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de depuração de saída de elementos individuais na matriz, você deve definir a profundidade do objeto `CDumpContext` como 1 ou maior.

Para obter mais informações sobre como usar `CByteArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CByteArray`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
