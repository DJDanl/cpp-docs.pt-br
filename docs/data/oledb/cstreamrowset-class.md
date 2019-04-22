---
title: Classe CStreamRowset
ms.date: 11/04/2016
f1_keywords:
- ATL::CStreamRowset<TAccessor>
- ATL::CStreamRowset
- CStreamRowset
- ATL.CStreamRowset<TAccessor>
- ATL.CStreamRowset
- CStreamRowset::CStreamRowset
- CStreamRowset.CStreamRowset
- ATL.CStreamRowset.CStreamRowset
- ATL::CStreamRowset::CStreamRowset
- CStreamRowset
- CStreamRowset<TAccessor>::CStreamRowset
- ATL::CStreamRowset<TAccessor>::CStreamRowset
- CStreamRowset<TAccessor>.Close
- ATL.CStreamRowset<TAccessor>.Close
- CStreamRowset::Close
- CStreamRowset<TAccessor>::Close
- ATL::CStreamRowset::Close
- ATL.CStreamRowset.Close
- ATL::CStreamRowset<TAccessor>::Close
- CStreamRowset.Close
helpviewer_keywords:
- CStreamRowset class
- CStreamRowset class, constructor
- Close method
ms.assetid: a106e953-a38a-464e-8ea5-28963d9e4811
ms.openlocfilehash: b566ddab89d2198e3f6b24eb9a20c60747749d1a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59022574"
---
# <a name="cstreamrowset-class"></a>Classe CStreamRowset

Usado em uma `CCommand` ou `CTable` declaração.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>
class CStreamRowset
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Uma classe de acessador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CStreamRowset](#cstreamrowset)|Construtor. Cria uma instância e inicializa o `CStreamRowset` objeto.|
|[Fechar](#close)|Versões do [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) ponteiro de interface na classe.|

## <a name="remarks"></a>Comentários

Use `CStreamRowset` em seu `CCommand` ou `CTable` declaração, por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/cpp/cstreamrowset-class_1.cpp)]

ou

[!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/cpp/cstreamrowset-class_2.cpp)]

`ICommand::Execute` Retorna um `ISequentialStream` ponteiro, que é armazenado em `m_spStream`. Você, em seguida, usar o `Read` método para recuperar os dados (cadeia de caracteres Unicode) em formato XML. Por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/cpp/cstreamrowset-class_3.cpp)]

SQL Server 2000 executa o formatação de XML e retornará todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.

> [!NOTE]
>  Esse recurso funciona apenas com o SQL Server 2000.

## <a name="cstreamrowset"></a> CStreamRowset::CStreamRowset

Cria uma instância e inicializa o `CStreamRowset` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CStreamRowset();
```

## <a name="close"></a> CStreamRowset::Close

Versões do [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) ponteiro de interface na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)