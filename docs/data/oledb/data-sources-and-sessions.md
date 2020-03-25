---
title: Origens de dados e sessões
ms.date: 11/19/2018
helpviewer_keywords:
- data sources [C++], OLE DB
- connections [C++], data source
- OLE DB consumer templates [C++], data sources
ms.assetid: 6ee52216-e082-4869-a1d6-ce561cfb76e5
ms.openlocfilehash: 0514f6a9285936c85608f08774c1d377fd72d6ab
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211049"
---
# <a name="data-sources-and-sessions"></a>Origens de dados e sessões

A figura a seguir mostra as classes que dão suporte à conexão e ao acesso a uma fonte de dados. Cada classe é baseada em uma implementação de componente de OLE DB padrão.

![Fonte de dados e classes de sessão](../../data/oledb/media/vcdatasourcesessionclasses.gif "Fonte de dados e classes de sessão") <br/>
Fonte de dados e classes de sessão

As classes são:

- [CDataSource](../../data/oledb/cdatasource-class.md) Essa classe instancia o objeto de fonte de dados, que cria e gerencia uma conexão com uma fonte de dados por meio de um provedor de OLE DB. A fonte de dados obtém informações como o endereço da fonte de dados e as informações de autenticação na forma de uma cadeia de conexão.

   Também vale a pena observar que a classe auxiliar [CEnumerator](../../data/oledb/cenumerator-class.md) é geralmente usada antes que qualquer conexão seja estabelecida para obter uma lista de provedores disponíveis registrados em um sistema. Isso permite que você selecione um provedor como uma fonte de dados. Por exemplo, a caixa de diálogo **Propriedades do link de dados** usa essa classe para popular a lista de provedores na guia **provedores** . Ele equivale à função `SQLBrowseConnect` ou `SQLDriverConnect`.

- [CSession](../../data/oledb/csession-class.md) Essa classe instancia o objeto Session, que representa uma única sessão de acesso à fonte de dados. No entanto, você pode criar várias sessões em uma fonte de dados. Para cada sessão, você pode criar conjuntos de linhas, comandos e outros objetos para acessar dados da fonte de dados. A sessão manipula transações.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)
