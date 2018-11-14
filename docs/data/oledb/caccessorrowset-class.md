---
title: Classe CAccessorRowset
ms.date: 11/04/2016
f1_keywords:
- CAccessorRowset
- ATL.CAccessorRowset
- ATL::CAccessorRowset
- CAccessorRowset.Bind
- CAccessorRowset::Bind
- CAccessorRowset::CAccessorRowset
- CAccessorRowset.CAccessorRowset
- CAccessorRowset
- ATL.CAccessorRowset.CAccessorRowset
- ATL::CAccessorRowset::CAccessorRowset
- CAccessorRowset.Close
- CAccessorRowset::Close
- CAccessorRowset::FreeRecordMemory
- CAccessorRowset.FreeRecordMemory
- FreeRecordMemory
- GetColumnInfo
- CAccessorRowset.GetColumnInfo
- CAccessorRowset::GetColumnInfo
helpviewer_keywords:
- CAccessorRowset class
- CAccessorRowset class, methods
- CAccessorRowset class, members
- Bind method
- CAccessorRowset class, constructor
- Close method
- FreeRecordMemory method
- GetColumnInfo method
ms.assetid: bd4f58ed-cebf-4d43-8985-1e5fcbf06953
ms.openlocfilehash: 6f870cf6c079786c49846bcf7c3010998ccdbe00
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556449"
---
# <a name="caccessorrowset-class"></a>Classe CAccessorRowset

Encapsula um conjunto de linhas e de seus acessadores associados em uma única classe.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,
   template <typename T> class TRowset = CRowset>
class CAccessorRowset : public TAccessor, public TRowset<TAccessor>
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Uma classe de acessador.

*TRowset*<br/>
Uma classe de conjunto de linhas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Associar](#bind)|Cria associações (usado quando `bBind` é especificado como **falsos** na [ccommand:: Open](../../data/oledb/ccommand-open.md)).|
|[CAccessorRowset](#caccessorrowset)|Construtor.|
|[Fechar](#close)|Fecha o conjunto de linhas e qualquer acessadores.|
|[FreeRecordMemory](#freerecordmemory)|Libera quaisquer colunas no registro atual que precise ser liberada.|
|[GetColumnInfo](#getcolumninfo)|Implementa [icolumnsinfo:: Getcolumninfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms722704(v=vs.85)).|

## <a name="remarks"></a>Comentários

Classe `TAccessor` gerencia o acessador. Classe *TRowset* gerencia o conjunto de linhas.

## <a name="bind"></a> Caccessorrowset:: Bind

Cria as associações, se você tiver especificado `bBind` como **falsos** na [ccommand:: Open](../../data/oledb/ccommand-open.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Bind();
```

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="caccessorrowset"></a> Caccessorrowset:: Caccessorrowset

Inicializa o objeto `CAccessorRowset`.

### <a name="syntax"></a>Sintaxe

```cpp
CAccessorRowset();
```

## <a name="close"></a> Caccessorrowset:: Close

Libera qualquer acessadores Active Directory e o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Libera qualquer memória associados.

## <a name="freerecordmemory"></a> Caccessorrowset:: Freerecordmemory

Libera quaisquer colunas no registro atual que precise ser liberada.

### <a name="syntax"></a>Sintaxe

```cpp
void FreeRecordMemory();
```

## <a name="getcolumninfo"></a> Caccessorrowset:: Getcolumninfo

Obtém informações de coluna do conjunto de linhas aberto.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetColumnInfo(DBORDINAL* pulColumns,
   DBCOLUMNINFO** ppColumnInfo,
   LPOLESTR* ppStrings) const;

HRESULT GetColumnInfo(DBORDINAL* pColumns,
   DBCOLUMNINFO** ppColumnInfo);
```

#### <a name="parameters"></a>Parâmetros

Ver [icolumnsinfo:: Getcolumninfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms722704(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O usuário deve liberar o buffer de cadeia de caracteres e informações de coluna retornada. Use a segunda versão desse método, quando você usa [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) e precisar substituir as associações.

Para obter mais informações, consulte [icolumnsinfo:: Getcolumninfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms722704(v=vs.85)) na *referência do programador DB OLE*.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)