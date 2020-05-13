---
title: Classe CStringArray
ms.date: 11/04/2016
f1_keywords:
- CStringArray
- AFXCOLL/CStringArray
- AFXCOLL/CStringArray::CStringArray
- AFXCOLL/CStringArray::Add
- AFXCOLL/CStringArray::Append
- AFXCOLL/CStringArray::Copy
- AFXCOLL/CStringArray::ElementAt
- AFXCOLL/CStringArray::FreeExtra
- AFXCOLL/CStringArray::GetAt
- AFXCOLL/CStringArray::GetCount
- AFXCOLL/CStringArray::GetData
- AFXCOLL/CStringArray::GetSize
- AFXCOLL/CStringArray::GetUpperBound
- AFXCOLL/CStringArray::InsertAt
- AFXCOLL/CStringArray::IsEmpty
- AFXCOLL/CStringArray::RemoveAll
- AFXCOLL/CStringArray::RemoveAt
- AFXCOLL/CStringArray::SetAt
- AFXCOLL/CStringArray::SetAtGrow
- AFXCOLL/CStringArray::SetSize
helpviewer_keywords:
- CStringArray [MFC], CStringArray
- CStringArray [MFC], Add
- CStringArray [MFC], Append
- CStringArray [MFC], Copy
- CStringArray [MFC], ElementAt
- CStringArray [MFC], FreeExtra
- CStringArray [MFC], GetAt
- CStringArray [MFC], GetCount
- CStringArray [MFC], GetData
- CStringArray [MFC], GetSize
- CStringArray [MFC], GetUpperBound
- CStringArray [MFC], InsertAt
- CStringArray [MFC], IsEmpty
- CStringArray [MFC], RemoveAll
- CStringArray [MFC], RemoveAt
- CStringArray [MFC], SetAt
- CStringArray [MFC], SetAtGrow
- CStringArray [MFC], SetSize
ms.assetid: 6c637e06-bba8-4c08-b0fc-cf8cb067ce34
ms.openlocfilehash: 96a272cbbb76b399ed7a3db6848ab3f74a615a38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365984"
---
# <a name="cstringarray-class"></a>Classe CStringArray

Suporta matrizes de objetos [CString.](../../atl-mfc-shared/using-cstring.md)

## <a name="syntax"></a>Sintaxe

```
class CStringArray : public CObject
```

## <a name="members"></a>Membros

As funções `CStringArray` do membro são semelhantes às funções de membro do [CObArray](../../mfc/reference/cobarray-class.md)de classe . Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Onde quer que `CObject` você veja um ponteiro como um valor de retorno, substitua um objeto [CString](../../atl-mfc-shared/using-cstring.md) (não um ponteiro [CString).](../../atl-mfc-shared/using-cstring.md) Ao ver um ponteiro de `CObject` como um parâmetro de função, substitua um `LPCTSTR`.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`CString CStringArray::GetAt( int <nIndex> ) const;`

e

`void SetAt( int <nIndex>, CObject* <newElement> )`

traduz para

`void SetAt( int <nIndex>, LPCTSTR <newElement> )`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CstringArray::CStringArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringArray::Adicionar](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CStringArray::Apêndice](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CstringArray::Copiar](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[Cstringarray::elementat](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[Cstringarray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[Cstringarray::getat](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[Cstringarray::GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CstringArray::GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser **NULO.**|
|[Cstringarray::getSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[Cstringarray::getupperbound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[Cstringarray::insertat](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[Cstringarray::IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[Cstringarray::removeall](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[Cstringarray::removeat](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[Cstringarray::setat](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[Cstringarray::Setatgrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CStringArray::SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CStringArray::operador \[\]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CStringArray`incorpora a IMPLEMENT_SERIAL macro para apoiar a serialização e o dumping de seus elementos. Se uma matriz de objetos `CString` for armazenada em um arquivo, com um operador de inserção sobrecarregado ou com a função de membro `Serialize`, cada elemento é serializado por vez.

> [!NOTE]
> Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se for necessário um despejo de elementos de cadeia de caracteres individuais na matriz, será necessário definir a profundidade do contexto do despejo para 1 ou maior.

Quando uma matriz `CString` é excluída ou quando seus elementos são removidos, a memória da cadeia de caracteres é liberada conforme adequado.

Para obter mais `CStringArray`informações sobre como usar, consulte o artigo [Coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CStringArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll.h

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
