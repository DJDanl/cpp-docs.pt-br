---
title: Consumidores do OLE DB e provedores | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 170f45a3581846dc588abf06aec170d66aa0d545
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ole-db-consumers-and-providers"></a>Consumidores e provedores de banco de dados OLE
A arquitetura OLE DB usa o modelo de consumidores e provedores. Um consumidor faz solicitações de dados. Um provedor responde a essas solicitações colocando os dados em um formato tabular e retorná-lo para o consumidor. Qualquer chamada que o consumidor pode fazer deve ser implementada no provedor.  
  
 Tecnicamente definido, um consumidor é qualquer aplicativo ou sistema código (não necessariamente um componente de banco de dados OLE) que acessa dados por meio das interfaces do OLE DB. As interfaces são implementadas em um provedor. Assim, um provedor é qualquer componente de software que implementa as interfaces do OLE DB para encapsular o acesso a dados e expô-lo a outros objetos (ou seja, os consumidores).  
  
 Em termos de funções, um consumidor chama métodos em interfaces de OLE DB; um provedor OLE DB implementa as interfaces necessárias do OLE DB.  
  
 OLE DB evita termos de cliente e servidor, porque essas funções não sempre faz sentido, especialmente em uma situação de n camadas. Como um consumidor pode ser um componente em uma camada que serve a outro componente, para chamá-lo em um cliente de componente seria confuso. Além disso, um provedor, às vezes, age mais como um driver de banco de dados de um servidor.  
  
## <a name="see-also"></a>Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)