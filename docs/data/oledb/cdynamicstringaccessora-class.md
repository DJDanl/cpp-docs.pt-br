---
title: Classe CDynamicStringAccessorA
ms.date: 11/04/2016
f1_keywords:
- CDynamicStringAccessorA
helpviewer_keywords:
- CDynamicStringAccessorA class
ms.assetid: ed0d9821-a655-41f1-a902-43c3042ac49c
ms.openlocfilehash: 3a0da9c779230fc1bf58bfa1d685623f844012c7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62231032"
---
# <a name="cdynamicstringaccessora-class"></a>Classe CDynamicStringAccessorA

Permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura subjacente).

## <a name="syntax"></a>Sintaxe

```cpp
typedef CDynamicStringAccessorT<CHAR, DBTYPE_STR> CDynamicStringAccessorA;
```

## <a name="remarks"></a>Comentários

Ambos solicitarem que o provedor de buscar todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres, mas `CDynamicStringAccessor` dados de cadeia de caracteres ANSI de solicitações.

`CDynamicStringAccessorA` herda `GetString` e `SetString` de `CDynamicStringAccessor`. Quando você usa esses métodos em uma `CDynamicStringAccessorA` objeto, `BaseType` é **CHAR**.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli.h

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)<br/>
