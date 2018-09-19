---
title: Acesso a dados no Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 03/28/2017
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Visual C++, data access applications
- databases [C++]
- OLE DB [C++], data access technologies
- data [C++], data access technologies
- data access [C++], class libraries for databases
ms.assetid: 95da6237-bbe2-480a-ae50-3a520051ceff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c8e2fc86d15472bd4ab63e472df99bb69393b386
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46060298"
---
# <a name="data-access-in-visual-c"></a>Acesso a dados no Visual C++

Praticamente todos os produtos de banco de dados, SQL e NoSQL, fornecem uma interface para aplicativos nativos do C++. A interface padrão do setor é ODBC, que dá suporte para todos os principais produtos de Banco de Dados SQL e para muitos produtos NoSQL. Para produtos que não são da Microsoft, consulte o fornecedor para obter mais informações. Bibliotecas de terceiros com vários termos de licença também estão disponíveis.

Desde 2011, a Microsoft tem se alinhado com o ODBC como o padrão para aplicativos nativos para se conectar a bancos de dados do Microsoft SQL Server, tanto localmente quanto na nuvem. Para obter mais informações, consulte [Programação de acesso a dados \(MFC/ATL\)](data-access-programming-mfc-atl.md). As bibliotecas C++/CLI podem usar os drivers ODBC nativos ou ADO.NET. Para obter mais informações, consulte [Acesso a dados usando ADO.NET (C++/CLI)](/dotnet/data-access-using-adonet-cpp-cli.md) e [Accessing data in Visual Studio](https://docs.microsoft.com/visualstudio/data-tools/accessing-data-in-visual-studio) (Acesso a dados no Visual Studio).

## <a name="in-this-section"></a>Nesta seção

[Acesso a dados (MFC/ATL) de programação](data-access-programming-mfc-atl.md)<br/>
Descreve programação de acesso a dados herdados com Visual C++, em que a melhor maneira é usar uma das bibliotecas de classe, como a classe biblioteca ATL (Active Template Library) ou a biblioteca MFC (Microsoft Foundation Class), que simplificam o trabalho com as APIs do banco de dados.

[ODBC (conectividade de banco de dados aberto)](odbc/open-database-connectivity-odbc.md)<br/>
A biblioteca MFC (Microsoft Foundation Classes) fornece classes para programar com ODBC (Conectividade Aberta de Banco de Dados).

[Programação do OLE DB](oledb/ole-db-programming.md)<br/>
Uma interface principalmente herdada que ainda é necessário em alguns cenários, especialmente quando você estiver programando em servidores vinculados.

## <a name="related-topics"></a>Tópicos relacionados

[Conectar-se ao banco de dados SQL usando C e C++](/azure/sql-database/sql-database-develop-cplusplus-simple)<br/>
Conecte-se ao banco de dados SQL de aplicativos C ou C++.

[Biblioteca de cliente de armazenamento do Microsoft Azure para C++](https://github.com/Azure/azure-storage-cpp)<br/>
O [Armazenamento do Azure](/azure/storage/storage-introduction) é uma solução de armazenamento em nuvem para aplicativos modernos que dependem de durabilidade, disponibilidade e escalabilidade para atender às necessidades dos clientes. Conecte-se ao Armazenamento do Azure pelo C++ usando a Biblioteca de Cliente do Armazenamento do Azure para C++.

[Driver ODBC 13.1 para SQL Server - Windows lançado](https://blogs.msdn.microsoft.com/sqlnativeclient/2016/08/01/announcing-the-odbc-driver-13-1-for-sql-server)<br/>
O driver ODBC mais recente fornece acesso eficiente a dados para o Microsoft SQL Server 2016 e para o Banco de Dados SQL do Microsoft Azure para aplicativos baseados em C/C++. Fornece suporte para recursos, incluindo sempre criptografado, Active Directory do Azure e grupos de disponibilidade AlwaysOn. Também está disponível para MacOS e Linux.     
 
[SQL Server Native Client](/sql/relational-databases/native-client/sql-server-native-client-programming)<br/>
O SQL Server Native Client é uma API (Interface de Programação de Aplicativo) de acesso a dados autônoma, usada tanto para OLE DB quanto para ODBC, que dá suporte ao SQL Server 2005 por meio do SQL Server 2014. Aplicativos novos devem usar o Driver ODBC 13.1 para SQL Server.

[Microsoft Azure C e C++ Developer Center](https://azure.microsoft.com/develop/cpp/)<br/>
O Azure facilita o build de aplicativos do C++, com maior flexibilidade, escalabilidade e confiabilidade usando ferramentas que você adora.    

[Como usar o armazenamento de BLOBs do C++](https://docs.microsoft.com/azure/storage/storage-c-plus-plus-how-to-use-blobs)<br/>
O Armazenamento de Blobs do Azure é um serviço que armazena dados não estruturados na nuvem como objetos/blobs. O Armazenamento de Blobs pode armazenar qualquer tipo de texto ou dados binários, como um documento, um arquivo de mídia ou um instalador de aplicativo. O Armazenamento de Blobs também é conhecido como armazenamento de objeto.

[ Referência do programador de ODBC](https://docs.microsoft.com/sql/odbc/reference/odbc-programmer-s-reference)<br/>
A interface ODBC é projetada para uso com a linguagem de programação C. O uso da interface ODBC abrange três áreas: instruções SQL, chamadas da função ODBC e programação em C.

## <a name="see-also"></a>Consulte também

[Visual C++](../visual-cpp-in-visual-studio.md)
