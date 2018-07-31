---
title: Classe CDynamicStringAccessorA | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CDynamicStringAccessorA
dev_langs:
- C++
helpviewer_keywords:
- CDynamicStringAccessorA class
ms.assetid: ed0d9821-a655-41f1-a902-43c3042ac49c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e56f71a427fda2444992cc0ed2c3b6166993af1d
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39341017"
---
# <a name="cdynamicstringaccessora-class"></a>Classe CDynamicStringAccessorA
Permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura subjacente).  
  
## <a name="syntax"></a>Sintaxe

```cpp
typedef CDynamicStringAccessorT<CHAR, DBTYPE_STR> CDynamicStringAccessorA;  
```  
  
## <a name="remarks"></a>Comentários  
 Ambos solicitarem que o provedor de buscar todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres, mas `CDynamicStringAccessor` dados de cadeia de caracteres ANSI de solicitações.  
  
 `CDynamicStringAccessorA` herda `GetString` e `SetString` de `CDynamicStringAccessor`. Quando você usa esses métodos em uma `CDynamicStringAccessorA` objeto, ***BaseType*** é **CHAR**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)