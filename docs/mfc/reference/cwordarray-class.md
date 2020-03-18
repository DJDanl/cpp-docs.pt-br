---
title: Classe CWordArray
ms.date: 09/07/2019
f1_keywords:
- CWordArray
- AFXCOLL/CWordArray
- AFXCOLL/CWordArray::CWordArray
- AFXCOLL/CWordArray::Add
- AFXCOLL/CWordArray::Append
- AFXCOLL/CWordArray::Copy
- AFXCOLL/CWordArray::ElementAt
- AFXCOLL/CWordArray::FreeExtra
- AFXCOLL/CWordArray::GetAt
- AFXCOLL/CWordArray::GetCount
- AFXCOLL/CWordArray::GetData
- AFXCOLL/CWordArray::GetSize
- AFXCOLL/CWordArray::GetUpperBound
- AFXCOLL/CWordArray::InsertAt
- AFXCOLL/CWordArray::IsEmpty
- AFXCOLL/CWordArray::RemoveAll
- AFXCOLL/CWordArray::RemoveAt
- AFXCOLL/CWordArray::SetAt
- AFXCOLL/CWordArray::SetAtGrow
- AFXCOLL/CWordArray::SetSize
helpviewer_keywords:
- CWordArray [MFC], CWordArray
- CWordArray [MFC], Add
- CWordArray [MFC], Append
- CWordArray [MFC], Copy
- CWordArray [MFC], ElementAt
- CWordArray [MFC], FreeExtra
- CWordArray [MFC], GetAt
- CWordArray [MFC], GetCount
- CWordArray [MFC], GetData
- CWordArray [MFC], GetSize
- CWordArray [MFC], GetUpperBound
- CWordArray [MFC], InsertAt
- CWordArray [MFC], IsEmpty
- CWordArray [MFC], RemoveAll
- CWordArray [MFC], RemoveAt
- CWordArray [MFC], SetAt
- CWordArray [MFC], SetAtGrow
- CWordArray [MFC], SetSize
ms.assetid: 2ba2c194-2c6c-40ff-9db4-e9dbe57e1f57
ms.openlocfilehash: 99484071c81ed6b766d3e4259d9fc88353b27ea3
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446231"
---
# <a name="cwordarray-class"></a>Classe CWordArray

Oferece suporte a matrizes de palavras de 16 bits.

## <a name="syntax"></a>Sintaxe

```
class CWordArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro de `CWordArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um ponteiro [CObject](../../mfc/reference/cobject-class.md) como um parâmetro de função ou valor de retorno, substitua uma palavra.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`WORD CWordArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CWordArray::CWordArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CWordArray:: Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CWordArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CWordArray:: copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CWordArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CWordArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CWordArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CWordArray:: GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CWordArray:: GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULO.|
|[CWordArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CWordArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CWordArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CWordArray:: IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CWordArray:: RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CWordArray:: RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CWordArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CWordArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CWordArray:: SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[Operador CWordArray::&#91;&#93;](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CWordArray` incorpora a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) para dar suporte à serialização e ao despejo de seus elementos. Se uma matriz de palavras for armazenada em um arquivo morto, com um operador de inserção sobrecarregado ou com a função de membro [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) , cada elemento será, por sua vez, serializado.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de um despejo de elementos individuais na matriz, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Para obter mais informações sobre como usar `CWordArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CWordArray`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Consulte também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
