---
title: Classe CDWordArray
ms.date: 11/04/2016
f1_keywords:
- CDWordArray
- AFXCOLL/CDWordArray
- AFXCOLL/CDWordArray::CDWordArray
- AFXCOLL/CDWordArray::Add
- AFXCOLL/CDWordArray::Append
- AFXCOLL/CDWordArray::Copy
- AFXCOLL/CDWordArray::ElementAt
- AFXCOLL/CDWordArray::FreeExtra
- AFXCOLL/CDWordArray::GetAt
- AFXCOLL/CDWordArray::GetCount
- AFXCOLL/CDWordArray::GetData
- AFXCOLL/CDWordArray::GetSize
- AFXCOLL/CDWordArray::GetUpperBound
- AFXCOLL/CDWordArray::InsertAt
- AFXCOLL/CDWordArray::IsEmpty
- AFXCOLL/CDWordArray::RemoveAll
- AFXCOLL/CDWordArray::RemoveAt
- AFXCOLL/CDWordArray::SetAt
- AFXCOLL/CDWordArray::SetAtGrow
- AFXCOLL/CDWordArray::SetSize
helpviewer_keywords:
- CDWordArray [MFC], CDWordArray
- CDWordArray [MFC], Add
- CDWordArray [MFC], Append
- CDWordArray [MFC], Copy
- CDWordArray [MFC], ElementAt
- CDWordArray [MFC], FreeExtra
- CDWordArray [MFC], GetAt
- CDWordArray [MFC], GetCount
- CDWordArray [MFC], GetData
- CDWordArray [MFC], GetSize
- CDWordArray [MFC], GetUpperBound
- CDWordArray [MFC], InsertAt
- CDWordArray [MFC], IsEmpty
- CDWordArray [MFC], RemoveAll
- CDWordArray [MFC], RemoveAt
- CDWordArray [MFC], SetAt
- CDWordArray [MFC], SetAtGrow
- CDWordArray [MFC], SetSize
ms.assetid: 581be11e-ced6-47d1-8679-e0b8e7d99494
ms.openlocfilehash: f17caafd01bb5ddfa49afe378bfd79652149ebd8
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447343"
---
# <a name="cdwordarray-class"></a>Classe CDWordArray

Dá suporte a matrizes de doublewords de 32 bits.

## <a name="syntax"></a>Sintaxe

```
class CDWordArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro de `CDWordArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um ponteiro `CObject` como um parâmetro de função ou valor de retorno, substitua um `DWORD`.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`DWORD CDWordArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDWordArray::CDWordArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDWordArray:: Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CDWordArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CDWordArray:: copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CDWordArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária para o byte dentro da matriz.|
|[CDWordArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CDWordArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CDWordArray:: GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CDWordArray:: GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULO.|
|[CDWordArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CDWordArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CDWordArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CDWordArray:: IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CDWordArray:: RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CDWordArray:: RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CDWordArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CDWordArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CDWordArray:: SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDWordArray:: Operator \[ \]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

A `CDWordArray` incorpora a macro `IMPLEMENT_SERIAL` para suportar serialização e despejo de seus elementos. Se uma matriz de doublewords for armazenada em um arquivo morto, com o operador de inserção sobrecarregada ( **<<** ) ou com a função de membro `Serialize`, cada elemento será, por sua vez, serializado.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de depuração de saída de elementos individuais na matriz, você deve definir a profundidade do objeto `CDumpContext` como 1 ou maior.

Para obter mais informações sobre como usar `CDWordArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** afxcoll. h

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
