---
title: Modelos de consumidor OLE DB (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- databases [C++], OLE DB templates
- OLE DB consumers [C++], data access
- OLE DB consumer templates [C++]
- databases [C++], consumers
ms.assetid: d3e42612-0bc0-4d65-9c32-0e8a7b219e82
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: a38c2edeffbdd2c37e69ce0886c24ca0d2f0b68a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="ole-db-consumer-templates-c"></a>Modelos de consumidor de banco de dados OLE (C++)
O OLE DB modelos de consumidor suporte à especificação de versão 2.6 do OLE DB. (Os modelos de consumidor de banco de dados OLE são testados em relação a 2.6 do OLE DB, mas não oferecem suporte a todas as interfaces na especificação.) Os modelos de consumidor minimizar a quantidade de código que você deve escrever para implementar um consumidor OLE DB. Os modelos fornecem:  
  
-   Fácil acesso a recursos do OLE DB e integração fácil com ATL e MFC.  
  
-   Um modelo de associação fácil para os parâmetros de banco de dados e colunas.  
  
-   Tipos de dados de C/C++ nativo para programação de OLE DB.  
  
 Para usar os modelos OLE DB, você deve estar familiarizado com as interfaces OLE DB, COM e modelos do C++. Se você não estiver familiarizado com o OLE DB, consulte [referência do programador de DB OLE](https://msdn.microsoft.com/en-us/library/ms718124.aspx).  
  
 Os modelos OLE DB oferecer suporte a modelo de objeto do OLE DB existente em vez de adicionar um novo modelo de objeto. As classes de camada superior de modelos OLE DB consumidor paralela componentes definidos na especificação do OLE DB. O design dos modelos de consumidor de banco de dados OLE inclui recursos avançados, como vários acessadores em um conjunto de linhas. O uso de modelos e várias heranças torna a biblioteca de pequeno e flexível.  
  
## <a name="how-ole-db-consumers-access-data"></a>Como acessam os dados consumidores do OLE DB  
 Os consumidores usam vários tipos de objetos, que são descritos nos tópicos a seguir:  
  
-   [Fontes de dados e sessões](../../data/oledb/data-sources-and-sessions.md)  
  
-   [Acessadores e conjuntos de linhas](../../data/oledb/accessors-and-rowsets.md)  
  
-   [Comandos e tabelas](../../data/oledb/commands-and-tables.md)  
  
-   [Registros de usuário](../../data/oledb/user-records.md)  
  
 Antes do consumidor não fizer nada, você primeiro selecionar um provedor OLE DB que é apropriado para o tipo de banco de dados que você precisa de acesso (por exemplo, SQL, Oracle, ODBC e MSDS). Para fazer isso, você normalmente usa um enumerador (consulte [CEnumerator](../../data/oledb/cenumerator-class.md) conforme mencionado em [fontes de dados e sessões](../../data/oledb/data-sources-and-sessions.md)).  
  
 O [o objeto de fonte de dados](../../data/oledb/data-sources-and-sessions.md) fornece as informações de conexão necessárias para se conectar à fonte de dados que você selecionou. O objeto de fonte de dados também contém informações de autenticação (como nomes de logon e senhas), que são usadas para dar aos usuários permissão para acessar a fonte de dados. O objeto de fonte de dados faz uma conexão ao banco de dados e, em seguida, cria um ou mais objetos de sessão. Cada [objeto de sessão](../../data/oledb/data-sources-and-sessions.md) gerencia suas próprias interações com o banco de dados (ou seja, consultar e recuperar dados) e executa essas transações, independentemente de outras sessões existentes.  
  
 A sessão cria os objetos de conjunto de linhas e comando. O [o objeto de comando](../../data/oledb/commands-and-tables.md) permite que os usuários interajam com o banco de dados, por exemplo, usando comandos SQL. O [objeto rowset](../../data/oledb/accessors-and-rowsets.md) é um conjunto de dados por meio do qual você pode navegar e no qual você pode [atualizar, excluir e inserir linhas](../../data/oledb/updating-rowsets.md).  
  
 Um consumidor OLE DB associa as colunas nas tabelas de banco de dados com variáveis locais; Para fazer isso, ele usa um [acessador](../../data/oledb/accessors-and-rowsets.md), que contém um mapa de como os dados são armazenados dentro de consumidor. O mapa consiste em um conjunto de associações entre colunas de tabelas e buffers de locais (variáveis) no aplicativo do consumidor.  
  
 Um conceito importante ao trabalhar com os consumidores é que você declare duas classes em um consumidor: o [classe comando (ou tabela)](../../data/oledb/commands-and-tables.md) e [classe de registro de usuário](../../data/oledb/user-records.md). Você pode acessar o conjunto de linhas por meio da classe de comando (ou tabela), que herda de uma classe de acessador e uma classe de conjunto de linhas. A classe de registro de usuário contém o mapa de associação do conjunto de linhas descrito anteriormente.  
  
 Para mais informações, consulte os seguintes tópicos:  
  
-   [Criando um consumidor do OLE DB](../../data/oledb/creating-an-ole-db-consumer.md)  
  
-   [Cenários comuns de OLE DB consumidor (exemplos)](../../data/oledb/working-with-ole-db-consumer-templates.md)  
  
## <a name="see-also"></a>Consulte também  
 [Programação de banco de dados OLE](../../data/oledb/ole-db-programming.md)   
 [Acesso a dados](../data-access-in-cpp.md)   
 [Documentação do SDK do OLE DB](https://msdn.microsoft.com/en-us/library/ms722784.aspx)   
 [Referência do programador de OLE DB](https://msdn.microsoft.com/en-us/library/ms713643.aspx)