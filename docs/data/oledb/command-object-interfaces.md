---
title: Interfaces de objeto de comando | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- command object interfaces [C++]
- command objects [OLE DB]
- OLE DB [C++], command object interfaces
ms.assetid: dacff5ae-252c-4f20-9ad7-4e602cc48536
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a26004edcd4b1e32bb7dd960ce927786296ef44b
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="command-object-interfaces"></a>Interfaces de objeto do comando
O objeto de comando usa o `IAccessor` interface para especificar associações de parâmetro. O consumidor chama `IAccessor::CreateAccessor`, passando uma matriz de `DBBINDING` estruturas. `DBBINDING` contém informações sobre as associações de coluna (por exemplo, comprimento e tipo). O provedor recebe as estruturas e determina como os dados devem ser transferidos e se as conversões são necessárias.  
  
 O `ICommandText` interface fornece uma maneira de especificar um comando de texto. O `ICommandProperties` interface trata todas as propriedades de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)