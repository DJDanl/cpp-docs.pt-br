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
ms.openlocfilehash: 77c4eebae6ede5d74e24421cc4d3951c78e08777
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79447276"
---
# <a name="caccessorrowset-class"></a>Classe CAccessorRowset

Encapsula um conjunto de linhas e seus acessadores associados em uma única classe.

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

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[Associar](#bind)|Cria associações (usadas quando `bBind` é especificado como **false** em [CCommand:: Open](../../data/oledb/ccommand-open.md)).|
|[CAccessorRowset](#caccessorrowset)|Construtor.|
|[Fechar](#close)|Fecha o conjunto de linhas e todos os acessadores.|
|[FreeRecordMemory](#freerecordmemory)|Libera Todas as colunas no registro atual que precisam ser liberadas.|
|[GetColumnInfo](#getcolumninfo)|Implementa [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)).|

## <a name="remarks"></a>Comentários

A classe `TAccessor` gerencia o acessador. A classe *TRowset* gerencia o conjunto de linhas.

## <a name="bind"></a>CAccessorRowset:: bind

Cria as associações se você especificou `bBind` como **false** em [CCommand:: Open](../../data/oledb/ccommand-open.md).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Bind();
```

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="caccessorrowset"></a>CAccessorRowset::CAccessorRowset

Inicializa o objeto `CAccessorRowset`.

### <a name="syntax"></a>Sintaxe

```cpp
CAccessorRowset();
```

## <a name="close"></a>CAccessorRowset:: fechar

Libera todos os acessadores ativos e o conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

### <a name="remarks"></a>Comentários

Libera qualquer memória associada.

## <a name="freerecordmemory"></a>CAccessorRowset::FreeRecordMemory

Libera Todas as colunas no registro atual que precisam ser liberadas.

### <a name="syntax"></a>Sintaxe

```cpp
void FreeRecordMemory();
```

## <a name="getcolumninfo"></a>CAccessorRowset:: GetColumnInfo

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

Consulte [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

O usuário deve liberar as informações da coluna retornada e o buffer de cadeia de caracteres. Use a segunda versão desse método quando você usar [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) e precisar substituir as associações.

Para obter mais informações, consulte [IColumnsInfo:: GetColumnInfo](/previous-versions/windows/desktop/ms722704\(v=vs.85\)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)