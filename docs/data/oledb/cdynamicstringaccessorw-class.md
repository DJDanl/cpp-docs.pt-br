---
title: Classe CDynamicStringAccessorW | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicStringAccessorW
dev_langs:
- C++
helpviewer_keywords:
- CDynamicStringAccessorW class
ms.assetid: 9b7fd5cc-3a9b-4b57-b907-f1e35de2c98f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 16f4725013d11eb27e4c6669403942cf171032ac
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43220068"
---
# <a name="cdynamicstringaccessorw-class"></a>Classe CDynamicStringAccessorW

Permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura subjacente).

## <a name="syntax"></a>Sintaxe

```cpp
typedef CDynamicStringAccessorT<WCHAR, DBTYPE_WSTR> CDynamicStringAccessorW;
```

## <a name="remarks"></a>Comentários

Ambos solicitarem que o provedor de buscar todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres, mas `CDynamicStringAccessor` solicita dados de cadeia de caracteres Unicode.

`CDynamicStringAccessorW` herda `GetString` e `SetString` de `CDynamicStringAccessor`. Quando você usa esses métodos em uma `CDynamicStringAccessorW` objeto, `BaseType` é **WCHAR**.

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
