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
ms.openlocfilehash: d6d05ac97846f55cf65d4010179b28d2b543ef66
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cdynamicstringaccessora-class"></a>Classe CDynamicStringAccessorA
Permite que você acesse uma fonte de dados quando você não possui conhecimento do esquema do banco de dados (estrutura subjacente).  
  
## <a name="syntax"></a>Sintaxe

```cpp
typedef CDynamicStringAccessorT<CHAR, DBTYPE_STR> CDynamicStringAccessorA;  
```  
  
## <a name="remarks"></a>Comentários  
 Ambos os solicitam que o provedor de buscar todos os dados acessados a partir do repositório de dados como dados de cadeia de caracteres, mas `CDynamicStringAccessor` dados de cadeia de caracteres ANSI de solicitações.  
  
 `CDynamicStringAccessorA` herda **GetString** e `SetString` de `CDynamicStringAccessor`. Quando você usa esses métodos em um `CDynamicStringAccessorA` objeto, ***BaseType*** é **CHAR**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho**: atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)   
 [Classe CAccessor](../../data/oledb/caccessor-class.md)   
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)   
 [Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)   
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)   
 [Classe CDynamicStringAccessor](../../data/oledb/cdynamicstringaccessor-class.md)