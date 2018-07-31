---
title: Fontes de dados e sessões | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- data sources [C++], OLE DB
- connections [C++], data source
- OLE DB consumer templates [C++], data sources
ms.assetid: 6ee52216-e082-4869-a1d6-ce561cfb76e5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: dfa91db63aaf0266fa6fef7c0b07210575dc70d8
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39339822"
---
# <a name="data-sources-and-sessions"></a>Origens de dados e sessões
A figura a seguir mostra as classes que dão suporte à conexão e acessar uma fonte de dados. Cada classe baseia-se em uma implementação padrão de componente do OLE DB.  
  
 ![Classes de dados de origem e de sessão](../../data/oledb/media/vcdatasourcesessionclasses.gif "vcdatasourcesessionclasses")  
Fonte de dados e Classes de sessão  
  
 As classes são:  
  
-   [CDataSource](../../data/oledb/cdatasource-class.md) essa classe instancia o objeto de fonte de dados, que cria e gerencia uma conexão a uma fonte de dados por meio de um provedor OLE DB. A fonte de dados usa informações de como as informações de autenticação e o endereço da fonte de dados na forma de uma cadeia de caracteres de conexão.  
  
     Também vale a pena observar que a classe auxiliar [CEnumerator](../../data/oledb/cenumerator-class.md) geralmente é usada antes que qualquer conexão seja estabelecida para obter uma lista de provedores disponíveis registrado em um sistema. Isso permite que você selecione um provedor como uma fonte de dados. Por exemplo, o **propriedades de vínculo de dados** caixa de diálogo usa essa classe para preencher a lista de provedores na **provedores** guia. É equivalente a `SQLBrowseConnect` ou `SQLDriverConnect` função.  
  
-   [CSession](../../data/oledb/csession-class.md) essa classe cria uma instância do objeto de sessão, que representa uma sessão de acesso único à fonte de dados. No entanto, você pode criar várias sessões em uma fonte de dados. Para cada sessão, você pode criar conjuntos de linhas, comandos e outros objetos para acessar dados da fonte de dados. A sessão lida com transações.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)