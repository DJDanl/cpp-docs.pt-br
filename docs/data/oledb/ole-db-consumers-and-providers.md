---
title: Os consumidores do OLE DB e provedores | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, OLE DB data architecture
- OLE DB providers
- OLE DB consumers, OLE DB data architecture
- OLE DB consumers
- OLE DB, data model
ms.assetid: 886cb39d-652b-4557-93f0-4b1b0754d8bc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3a6290c923b5aa4b54a71bda5f0617d1b3acc8db
ms.sourcegitcommit: c045c3a7e9f2c7e3e0de5b7f9513e41d8b6d19b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2018
ms.locfileid: "49989860"
---
# <a name="ole-db-consumers-and-providers"></a>Consumidores e provedores de banco de dados OLE

Arquitetura do OLE DB usa o modelo de consumidores e provedores. Um consumidor faz as solicitações de dados. Um provedor responde a essas solicitações colocando dados em um formato tabular e retorná-lo para o consumidor. Qualquer chamada que o consumidor pode fazer deve ser implementada no provedor.  
  
Um consumidor definidas tecnicamente, é qualquer aplicativo ou sistema de código (não necessariamente um componente de banco de dados OLE) que acessa dados por meio de interfaces do OLE DB. As interfaces são implementadas em um provedor. Portanto, um provedor é qualquer componente de software que implementa as interfaces OLE DB para encapsular o acesso aos dados e expô-lo a outros objetos (ou seja, os consumidores).  
  
Para funções, um consumidor chama métodos em interfaces de OLE DB; um provedor OLE DB implementa as interfaces de OLE DB necessárias.  
  
OLE DB evita termos de cliente e servidor, porque essas funções sempre não fazem sentido, especialmente em uma situação de n camadas. Como um consumidor pode ser um componente em uma camada que serve a outro componente, para chamá-lo um cliente componente seria confuso. Além disso, um provedor, às vezes, atua mais como um driver de banco de dados que um servidor.  
  
## <a name="see-also"></a>Consulte também  

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)