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
- ATL.CAccessorRowset.CAccessorRowset
- ATL::CAccessorRowset::CAccessorRowset
- CAccessorRowset.Close
- CAccessorRowset::Close
- CAccessorRowset::FreeRecordMemory
- CAccessorRowset.FreeRecordMemory
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
ms.openlocfilehash: 42b7d385877d68db22ccaf6665e8043dbfe2ee44
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87233477"
---
# <a name="caccessorrowset-class"></a>Classe CAccessorRowset

Encapsula um conjunto de linhas e seus acessadores associados em uma única classe.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,
   template <typename T> class TRowset = CRowset>
class CAccessorRowset : public TAccessor, public TRowset<TAccessor>
```

### <a name="parameters"></a>parâmetros

*TAccessor*<br/>
Uma classe de acessador.

*TRowset*<br/>
Uma classe de conjunto de linhas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Associa](#bind)|Cria associações (usadas quando `bBind` é especificado como **`false`** em [CCommand:: Open](../../data/oledb/ccommand-open.md)).|
|[CAccessorRowset](#caccessorrowset)|Construtor.|
|[Fechar](#close)|Fecha o conjunto de linhas e todos os acessadores.|
|[FreeRecordMemory](#freerecordmemory)|Libera Todas as colunas no registro atual que precisam ser liberadas.|
|[GetColumnInfo](#getcolumninfo)|Implementa [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)).|

## <a name="remarks"></a>Comentários

`TAccessor`A classe gerencia o acessador. A classe *TRowset* gerencia o conjunto de linhas.

## <a name="caccessorrowsetbind"></a><a name="bind"></a>CAccessorRowset:: bind

Cria as associações se você tiver especificado `bBind` como **`false`** em [CCommand:: Open](../../data/oledb/ccommand-open.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Bind();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="caccessorrowsetcaccessorrowset"></a><a name="caccessorrowset"></a>CAccessorRowset::CAccessorRowset

Inicializa o objeto `CAccessorRowset`.

### <a name="syntax"></a>Sintaxe

```cpp
CAccessorRowset();
```

## <a name="caccessorrowsetclose"></a><a name="close"></a>CAccessorRowset:: fechar

Libera todos os acessadores ativos e o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Libera qualquer memória associada.

## <a name="caccessorrowsetfreerecordmemory"></a><a name="freerecordmemory"></a>CAccessorRowset::FreeRecordMemory

Libera Todas as colunas no registro atual que precisam ser liberadas.

### <a name="syntax"></a>Sintaxe

```cpp
void FreeRecordMemory();
```

## <a name="caccessorrowsetgetcolumninfo"></a><a name="getcolumninfo"></a>CAccessorRowset:: GetColumnInfo

Obtém informações de coluna do conjunto de linhas aberto.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetColumnInfo(DBORDINAL* pulColumns,
   DBCOLUMNINFO** ppColumnInfo,
   LPOLESTR* ppStrings) const;

HRESULT GetColumnInfo(DBORDINAL* pColumns,
   DBCOLUMNINFO** ppColumnInfo);
```

#### <a name="parameters"></a>parâmetros

Consulte [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O usuário deve liberar as informações da coluna retornada e o buffer de cadeia de caracteres. Use a segunda versão desse método quando você usar [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) e precisar substituir as associações.

Para obter mais informações, consulte [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
