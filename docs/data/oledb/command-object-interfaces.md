---
title: Interfaces de objeto do comando
ms.date: 10/24/2018
helpviewer_keywords:
- command object interfaces [C++]
- command objects [OLE DB]
- OLE DB [C++], command object interfaces
ms.assetid: dacff5ae-252c-4f20-9ad7-4e602cc48536
ms.openlocfilehash: 755c44cf8d0cb5bf5066197bfd0ead3e0f25e1f9
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59032395"
---
# <a name="command-object-interfaces"></a>Interfaces de objeto do comando

O objeto de comando usa o `IAccessor` interface para especificar associações de parâmetro. O consumidor chama `IAccessor::CreateAccessor`, passando uma matriz de `DBBINDING` estruturas. `DBBINDING` contém informações sobre as associações de coluna (por exemplo, tipo e comprimento). O provedor recebe as estruturas e determina como os dados devem ser transferidos e se as conversões são necessárias.

O `ICommandText` interface fornece uma maneira de especificar um comando de texto. O `ICommandProperties` interface manipula todas as propriedades de comando.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
