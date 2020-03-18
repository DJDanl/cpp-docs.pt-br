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
ms.openlocfilehash: 4a0e67ff1e800ff0f838b863eaaf839d4456ed82
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441082"
---
# <a name="cstreamrowset-class"></a>Classe CStreamRowset

Usado em uma declaração de `CCommand` ou `CTable`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CAccessorBase>
class CStreamRowset
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Uma classe de acessador.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>{1&gt;Métodos&lt;1}

|||
|-|-|
|[CStreamRowset](#cstreamrowset)|Construtor. Cria uma instância e inicializa o objeto `CStreamRowset`.|
|[Fechar](#close)|Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.|

## <a name="remarks"></a>Comentários

Use `CStreamRowset` em sua declaração de `CCommand` ou `CTable`, por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#11](../../data/oledb/codesnippet/cpp/cstreamrowset-class_1.cpp)]

ou

[!code-cpp[NVC_OLEDB_Consumer#12](../../data/oledb/codesnippet/cpp/cstreamrowset-class_2.cpp)]

`ICommand::Execute` retorna um ponteiro de `ISequentialStream`, que é armazenado em `m_spStream`. Em seguida, você usa o método `Read` para recuperar os dados (cadeia de caracteres Unicode) no formato XML. Por exemplo:

[!code-cpp[NVC_OLEDB_Consumer#13](../../data/oledb/codesnippet/cpp/cstreamrowset-class_3.cpp)]

SQL Server 2000 executa a formatação XML e retornará todas as colunas e todas as linhas do conjunto de linhas como uma cadeia de caracteres XML.

> [!NOTE]
>  Este recurso funciona apenas com SQL Server 2000.

## <a name="cstreamrowset"></a>CStreamRowset::CStreamRowset

Cria uma instância e inicializa o objeto `CStreamRowset`.

### <a name="syntax"></a>Sintaxe

```cpp
CStreamRowset();
```

## <a name="close"></a>CStreamRowset:: fechar

Libera o ponteiro de interface [ISequentialStream](/previous-versions/windows/desktop/ms718035(v=vs.85)) na classe.

### <a name="syntax"></a>Sintaxe

```cpp
void Close();
```

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)