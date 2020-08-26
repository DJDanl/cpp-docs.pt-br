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
ms.openlocfilehash: 304dfe0e026a9fbba899c1ef17c06cf1baf1529b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841045"
---
# <a name="cstreamrowset-class"></a>Classe CStreamRowset

Usado em uma `CCommand` `CTable` declaração ou.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>
class CStreamRowset
```

### <a name="parameters"></a>parâmetros

*TAccessor*<br/>
Uma classe de acessador.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[CStreamRowset](#cstreamrowset)|Construtor. Cria uma instância e inicializa o `CStreamRowset` objeto.|
|[Fechar](#close)|Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.|

## <a name="remarks"></a>Comentários

Use `CStreamRowset` em sua `CCommand` `CTable` declaração ou, por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/cpp/cstreamrowset-class_1.cpp)]

ou

[!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/cpp/cstreamrowset-class_2.cpp)]

`ICommand::Execute` Retorna um `ISequentialStream` ponteiro, que é armazenado em `m_spStream` . Em seguida, você usa o `Read` método para recuperar os dados (cadeia de caracteres Unicode) no formato XML. Por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/cpp/cstreamrowset-class_3.cpp)]

SQL Server 2000 executa a formatação XML e retornará todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.

> [!NOTE]
> Este recurso funciona apenas com SQL Server 2000.

## <a name="cstreamrowsetcstreamrowset"></a><a name="cstreamrowset"></a> CStreamRowset::CStreamRowset

Cria uma instância e inicializa o `CStreamRowset` objeto.

### <a name="syntax"></a>Sintaxe

```cpp
CStreamRowset();
```

## <a name="cstreamrowsetclose"></a><a name="close"></a> CStreamRowset:: fechar

Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
