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
ms.openlocfilehash: ad4987422fd200faef141150908d4df0722f669a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366267"
---
# <a name="cstreamrowset-class"></a>Classe CStreamRowset

Usado em `CCommand` `CTable` uma declaração ou.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>
class CStreamRowset
```

### <a name="parameters"></a>Parâmetros

*Taccessor*<br/>
Uma aula de acessórios.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Cstreamrowset](#cstreamrowset)|Construtor. Instancia e inicializa `CStreamRowset` o objeto.|
|[Fechar](#close)|Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.|

## <a name="remarks"></a>Comentários

Use `CStreamRowset` em `CCommand` `CTable` sua ou declaração, por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/cpp/cstreamrowset-class_1.cpp)]

ou

[!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/cpp/cstreamrowset-class_2.cpp)]

`ICommand::Execute`retorna `ISequentialStream` um ponteiro, que `m_spStream`é armazenado em . Em seguida, `Read` use o método para recuperar os dados (seqüência unicode) no formato XML. Por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/cpp/cstreamrowset-class_3.cpp)]

O SQL Server 2000 executa a formatação XML e retornará todas as colunas e todas as linhas do conjunto de linhas como uma seqüência XML.

> [!NOTE]
> Este recurso funciona apenas com o SQL Server 2000.

## <a name="cstreamrowsetcstreamrowset"></a><a name="cstreamrowset"></a>CStreamRowset::CStreamRowset

Instancia e inicializa `CStreamRowset` o objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CStreamRowset();
```

## <a name="cstreamrowsetclose"></a><a name="close"></a>CStreamRowset::Fechar

Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumo OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
