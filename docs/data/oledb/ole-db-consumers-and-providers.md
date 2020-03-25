---
title: Consumidores e provedores de banco de dados OLE
ms.date: 10/22/2018
helpviewer_keywords:
- OLE DB providers, OLE DB data architecture
- OLE DB providers
- OLE DB consumers, OLE DB data architecture
- OLE DB consumers
- OLE DB, data model
ms.assetid: 886cb39d-652b-4557-93f0-4b1b0754d8bc
ms.openlocfilehash: d57ded9d084971c3562fc7f22e6a1a12a4e3368d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210063"
---
# <a name="ole-db-consumers-and-providers"></a>Consumidores e provedores de banco de dados OLE

A arquitetura de OLE DB usa o modelo de consumidores e provedores. Um consumidor faz solicitações de dados. Um provedor responde a essas solicitações colocando dados em um formato tabular e retornando-os para o consumidor. Qualquer chamada que o consumidor pode fazer deve ser implementada no provedor.

Tecnicamente definido, um consumidor é qualquer código de sistema ou aplicativo (não necessariamente um componente OLE DB) que acesse dados por meio de interfaces OLE DB. As interfaces são implementadas em um provedor. Portanto, um provedor é qualquer componente de software que implementa OLE DB interfaces para encapsular o acesso aos dados e expô-los a outros objetos (ou seja, consumidores).

Para funções, um consumidor chama métodos em interfaces OLE DB; um provedor de OLE DB implementa as interfaces de OLE DB necessárias.

OLE DB evita os termos cliente e servidor, pois essas funções nem sempre fazem sentido, especialmente em uma situação de n camadas. Como um consumidor pode ser um componente em uma camada que atende a outro componente, para chamá-lo, um componente de cliente seria confuso. Além disso, um provedor às vezes atua mais como um driver de banco de dados do que um servidor.

## <a name="see-also"></a>Confira também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Visão geral da programação do OLE DB](../../data/oledb/ole-db-programming-overview.md)
