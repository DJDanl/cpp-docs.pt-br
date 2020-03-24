---
title: Acesso a dados no Visual C++
ms.date: 03/28/2017
helpviewer_keywords:
- Visual C++, data access applications
- databases [C++]
- OLE DB [C++], data access technologies
- data [C++], data access technologies
- data access [C++], class libraries for databases
ms.assetid: 95da6237-bbe2-480a-ae50-3a520051ceff
ms.openlocfilehash: a1645c1116daa66c578a6d6e697ab168e4006af9
ms.sourcegitcommit: eff68e4e82be292a5664616b16a526df3e9d1cda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80150947"
---
# <a name="data-access-in-visual-c"></a>Acesso a dados no Visual C++

Praticamente todos os produtos de banco de dados, SQL e NoSQL, fornecem uma interface para aplicativos nativos do C++. A interface padrão do setor é ODBC, que dá suporte para todos os principais produtos de Banco de Dados SQL e para muitos produtos NoSQL. Para produtos que não são da Microsoft, consulte o fornecedor para obter mais informações. Bibliotecas de terceiros com vários termos de licença também estão disponíveis.

Desde 2011, a Microsoft tem se alinhado com o ODBC como o padrão para aplicativos nativos para se conectar a bancos de dados do Microsoft SQL Server, tanto localmente quanto na nuvem. Para obter mais informações, consulte [Programação de acesso a dados \(MFC/ATL\)](data-access-programming-mfc-atl.md). As bibliotecas C++/CLI podem usar os drivers ODBC nativos ou ADO.NET. Para obter mais informações, consulte [Acesso a dados usando ADO.NET (C++/CLI)](../dotnet/data-access-using-adonet-cpp-cli.md) e [Accessing data in Visual Studio](https://docs.microsoft.com/visualstudio/data-tools/accessing-data-in-visual-studio) (Acesso a dados no Visual Studio).

## <a name="in-this-section"></a>Nesta seção

[Programação de Acesso a Dados (MFC/ATL)](data-access-programming-mfc-atl.md)<br/>
Descreve programação de acesso a dados herdados com Visual C++, em que a melhor maneira é usar uma das bibliotecas de classe, como a classe biblioteca ATL (Active Template Library) ou a biblioteca MFC (Microsoft Foundation Class), que simplificam o trabalho com as APIs do banco de dados.

[ODBC (conectividade de banco de dados aberto)](odbc/open-database-connectivity-odbc.md)<br/>
A biblioteca MFC (Microsoft Foundation Classes) fornece classes para programar com ODBC (Conectividade Aberta de Banco de Dados).

[Programação do OLE DB](oledb/ole-db-programming.md)<br/>
Uma interface principalmente herdada que ainda é necessária em alguns cenários, especialmente quando você está programando com relação a servidores vinculados.

## <a name="related-topics"></a>Tópicos Relacionados

[Conectar-se ao Banco de Dados SQL usando C e C++](/azure/sql-database/sql-database-develop-cplusplus-simple)<br/>
Conecte-se ao Banco de Dados SQL do Azure de aplicativos C ou C++.

[Biblioteca de Clientes do Armazenamento do Microsoft Azure para C++](https://github.com/Azure/azure-storage-cpp)<br/>
O [Armazenamento do Azure](/azure/storage/storage-introduction) é uma solução de armazenamento em nuvem para aplicativos modernos que dependem de durabilidade, disponibilidade e escalabilidade para atender às necessidades dos clientes. Conecte-se ao Armazenamento do Azure pelo C++ usando a Biblioteca de Cliente do Armazenamento do Azure para C++.

[ODBC Driver for SQL Server](/sql/connect/odbc/microsoft-odbc-driver-for-sql-server)<br/>
O driver ODBC mais recente fornece um eficiente acesso a dados para o Microsoft SQL Server e para o Banco de Dados SQL do Microsoft Azure para aplicativos baseados em C/C++. Ele dá suporte para recursos, incluindo o Always Encrypted, o Azure Active Directory e os Grupos de Disponibilidade AlwaysOn. Também está disponível para MacOS e Linux.

[Driver do OLE DB para SQL Server](/sql/connect/oledb/oledb-driver-for-sql-server)<br/>
O driver OLE DB mais recente é uma API (interface de programação de aplicativo) de acesso a dados autônoma que é compatível com Microsoft SQL Server e ao Banco de Dados SQL do Microsoft Azure.

[Central de Desenvolvedores do Microsoft Azure C e C++](https://azure.microsoft.com/develop/cpp/)<br/>
O Azure facilita o build de aplicativos do C++, com maior flexibilidade, escalabilidade e confiabilidade usando ferramentas que você adora.

[Como usar o Armazenamento de Blobs do C++](https://docs.microsoft.com/azure/storage/storage-c-plus-plus-how-to-use-blobs)<br/>
O Armazenamento de Blobs do Azure é um serviço que armazena dados não estruturados na nuvem como objetos/blobs. O Armazenamento de Blobs pode conter qualquer tipo de texto ou de dados binários, como um documento, um arquivo de mídia ou um instalador de aplicativo. O Armazenamento de Blobs também é chamado de armazenamento de objeto.

[Referência do programador ODBC](https://docs.microsoft.com/sql/odbc/reference/odbc-programmer-s-reference)<br/>
A interface ODBC é projetada para uso com a linguagem de programação C. O uso da interface ODBC abrange três áreas: instruções SQL, chamadas da função ODBC e programação em C.

## <a name="see-also"></a>Consulte também

[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)
