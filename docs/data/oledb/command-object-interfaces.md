---
title: Interfaces de objeto de comando | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- command object interfaces [C++]
- command objects [OLE DB]
- OLE DB [C++], command object interfaces
ms.assetid: dacff5ae-252c-4f20-9ad7-4e602cc48536
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9c597cc30e23ffce2787eac6c13f6ba8c53f96c1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096113"
---
# <a name="command-object-interfaces"></a>Interfaces de objeto do comando
O objeto de comando usa o `IAccessor` interface para especificar associações de parâmetro. O consumidor chama `IAccessor::CreateAccessor`, passando uma matriz de `DBBINDING` estruturas. `DBBINDING` contém informações sobre as associações de coluna (por exemplo, comprimento e tipo). O provedor recebe as estruturas e determina como os dados devem ser transferidos e se as conversões são necessárias.  
  
 O `ICommandText` interface fornece uma maneira de especificar um comando de texto. O `ICommandProperties` interface trata todas as propriedades de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)