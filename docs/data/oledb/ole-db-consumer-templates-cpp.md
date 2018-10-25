---
title: Modelos de consumidor do OLE DB (C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/22/2018
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- databases [C++], OLE DB templates
- OLE DB consumers [C++], data access
- OLE DB consumer templates [C++]
- databases [C++], consumers
ms.assetid: d3e42612-0bc0-4d65-9c32-0e8a7b219e82
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 71c8c6d84bf4ee92d74a0b4cb68c9e8abc545a22
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50069887"
---
# <a name="ole-db-consumer-templates-c"></a>Modelos de consumidor de banco de dados OLE (C++)

O OLE DB modelos de consumidor dão suporte a especificação de versão 2.6 do OLE DB. (O OLE DB modelos de consumidor são testados no OLE DB 2.6, mas não oferecem suporte a todas as interfaces na especificação.) Os modelos de consumidor minimizar a quantidade de código que você deve escrever para implementar um consumidor OLE DB. Os modelos fornecem:

- Acesso fácil aos recursos de OLE DB e integração fácil com ATL e MFC.

- Um modelo de associação fácil para os parâmetros de banco de dados e colunas.

- Tipos de dados de C/C++ nativos para programação de OLE DB.

Para usar os modelos OLE DB, você deve estar familiarizado com modelos de C++, COM e as interfaces do OLE DB. Se você não estiver familiarizado com o OLE DB, consulte [referência do programador DB OLE](/previous-versions/windows/desktop/ms718124).

Os modelos OLE DB oferecer suporte a modelo de objeto OLE DB existente em vez de adicionar um novo modelo de objeto. As classes de camada superior de OLE DB modelos de consumidor em paralelo os componentes definidos na especificação do OLE DB. O design dos modelos de consumidor de banco de dados OLE inclui recursos avançados como vários acessadores em um conjunto de linhas. O uso de modelos e herança múltipla torna a biblioteca de pequeno e flexível.

## <a name="how-ole-db-consumers-access-data"></a>Como os consumidores do OLE DB acessam dados

Os consumidores usam vários tipos de objetos, que são descritos nos tópicos a seguir:

- [Fontes de dados e sessões](../../data/oledb/data-sources-and-sessions.md)

- [Acessadores e conjuntos de linhas](../../data/oledb/accessors-and-rowsets.md)

- [Comandos e tabelas](../../data/oledb/commands-and-tables.md)

- [Registros de usuário](../../data/oledb/user-records.md)

Antes do consumidor faz alguma coisa, você primeiro selecionar um provedor OLE DB que é apropriado para o tipo de banco de dados que você precisa de acesso (por exemplo, SQL, Oracle, ODBC e MSDS). Para fazer isso, você normalmente usa um enumerador (consulte [CEnumerator](../../data/oledb/cenumerator-class.md) conforme mencionado na [fontes de dados e sessões](../../data/oledb/data-sources-and-sessions.md)).

O [o objeto de fonte de dados](../../data/oledb/data-sources-and-sessions.md) fornece as informações de conexão necessárias para se conectar à fonte de dados que você selecionou. O objeto de fonte de dados também contém informações de autenticação (como nomes de logon e senhas), que são usadas para dar aos usuários permissão para acessar a fonte de dados. O objeto de fonte de dados faz uma conexão ao banco de dados e, em seguida, cria um ou mais objetos de sessão. Cada [objeto de sessão](../../data/oledb/data-sources-and-sessions.md) gerencia seus próprio interações com o banco de dados (ou seja, consultar e recuperar dados) e executa essas transações, independentemente de outras sessões existentes.

A sessão cria os objetos de conjunto de linhas e de comando. O [objeto de comando](../../data/oledb/commands-and-tables.md) permite que os usuários interajam com o banco de dados, por exemplo, usando comandos SQL. O [objeto do conjunto de linhas](../../data/oledb/accessors-and-rowsets.md) é um conjunto de dados por meio do qual você pode navegar e na qual é possível [atualizar, excluir e inserir linhas](../../data/oledb/updating-rowsets.md).

Um consumidor OLE DB associa colunas nas tabelas de banco de dados com variáveis locais; Para fazer isso, ele usa um [acessador](../../data/oledb/accessors-and-rowsets.md), que contém um mapa de como os dados são armazenados dentro do consumidor. O mapa consiste em um conjunto de associações entre colunas da tabela e buffers de locais (variáveis) no aplicativo de consumidor.

Um conceito importante ao trabalhar com os consumidores é que você declare duas classes em um consumidor: o [classe de comando (ou tabela)](../../data/oledb/commands-and-tables.md) e o [classe de registro de usuário](../../data/oledb/user-records.md). Você pode acessar o conjunto de linhas por meio da classe de comando (ou tabela), que herda de uma classe de acessador e uma classe de conjunto de linhas. A classe de registro de usuário contém o mapa de associação do conjunto de linhas descrito anteriormente.

Para mais informações, consulte os seguintes tópicos:

- [Criando um consumidor do OLE DB](../../data/oledb/creating-an-ole-db-consumer.md)

- [Cenários comuns de OLE DB consumidor (exemplos)](../../data/oledb/working-with-ole-db-consumer-templates.md)

## <a name="see-also"></a>Consulte também

[Programação do OLE DB](../../data/oledb/ole-db-programming.md)<br/>
[Acesso a dados](../data-access-in-cpp.md)<br/>
[Documentação do SDK do OLE DB](/previous-versions/windows/desktop/ms722784)<br/>
[Referência do programador do OLE DB](/previous-versions/windows/desktop/ms713643)