---
title: Acesso a dados no Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 03/28/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- Visual C++, data access applications
- databases [C++]
- OLE DB [C++], data access technologies
- data [C++], data access technologies
- data access [C++], class libraries for databases
ms.assetid: 95da6237-bbe2-480a-ae50-3a520051ceff
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9bae9c7d8e50ca12767e5baed436912f04daafd9
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="data-access-in-visual-c"></a>Acesso a dados no Visual C++

Praticamente todos os produtos de banco de dados, SQL e NoSQL, fornecem uma interface para aplicativos nativos do C++. A interface padrão do setor é ODBC, que dá suporte para todos os principais produtos de Banco de Dados SQL e para muitos produtos NoSQL. Para produtos que não são da Microsoft, consulte o fornecedor para obter mais informações. Bibliotecas de terceiros com vários termos de licença também estão disponíveis.

Desde 2011, a Microsoft tem se alinhado com o ODBC como o padrão para aplicativos nativos para se conectar a bancos de dados do Microsoft SQL Server, tanto localmente quanto na nuvem. Para obter mais informações, consulte [Programação de acesso a dados \(MFC/ATL\)](data-access-programming-mfc-atl.md). As bibliotecas C++/CLI podem usar os drivers ODBC nativos ou ADO.NET. Para obter mais informações, consulte [Acesso a dados usando ADO.NET (C++/CLI)](/dotnet/data-access-using-adonet-cpp-cli.md) e [Accessing data in Visual Studio](https://docs.microsoft.com/visualstudio/data-tools/accessing-data-in-visual-studio) (Acesso a dados no Visual Studio).

## <a name="in-this-section"></a>Nesta seção
[Programação de acesso de dados (MFC/ATL)](data-access-programming-mfc-atl.md) programação com o Visual C++, onde é o modo preferido usar uma das bibliotecas de classe, como a biblioteca de classe de modelo ativa (ATL) ou a biblioteca Microsoft Foundation Class (MFC), de acesso de dados herdados descreve que simplificam a trabalhar com os APIs do banco de dados.

[Abra o banco de dados ODBC (conectividade)](odbc/open-database-connectivity-odbc.md) biblioteca o Microsoft Foundation Classes (MFC) fornece classes para programação com conectividade aberta de banco de dados (ODBC).

[OLE DB de programação](oledb/ole-db-programming.md) servidores vinculados de uma interface principalmente herdada que ainda é necessária em alguns cenários, especialmente quando você estiver programando contra.

## <a name="related-topics"></a>Tópicos relacionados
[Conectar-se ao banco de dados SQL usando C e C++](/azure/sql-database/sql-database-develop-cplusplus-simple) conectar ao banco de dados do SQL Azure de aplicativos C ou C++.

[Biblioteca de cliente de armazenamento do Microsoft Azure para C++](https://github.com/Azure/azure-storage-cpp)
[armazenamento do Azure](/azure/storage/storage-introduction) é uma solução de armazenamento de nuvem para aplicativos modernos que dependem de durabilidade, disponibilidade e escalabilidade para atender às necessidades do seu clientes. Conecte-se ao Armazenamento do Azure pelo C++ usando a Biblioteca de Cliente do Armazenamento do Azure para C++.

[ODBC Driver 13.1 para SQL Server - Windows lançado](https://blogs.msdn.microsoft.com/sqlnativeclient/2016/08/01/announcing-the-odbc-driver-13-1-for-sql-server) o driver de ODBC fornece acesso eficiente a dados para o Microsoft SQL Server 2016 Microsoft Azure SQL Database para aplicativos baseados em C/C++. Fornece suporte para recursos, incluindo sempre criptografado, Active Directory do Azure e grupos de disponibilidade AlwaysOn. Também está disponível para MacOS e Linux.     
 
[SQL Server Native Client](https://msdn.microsoft.com/library/ms130892.aspx) SQL Server Native Client é uma dados autônoma acesso aplicativo interface de programação (API) usada para OLE DB e ODBC, que oferece suporte ao SQL Server 2005 por meio do SQL Server 2014. Aplicativos novos devem usar o Driver ODBC 13.1 para SQL Server.

[Microsoft Azure C e C++ Developer Center](https://azure.microsoft.com/develop/cpp/) Azure facilita a criação de aplicativos do C++ com maior flexibilidade, escalabilidade e confiabilidade usando as ferramentas que você adora.    

[Como usar o armazenamento de Blob de C++](https://docs.microsoft.com/azure/storage/storage-c-plus-plus-how-to-use-blobs) armazenamento de BLOBs do Azure é um serviço que armazena dados não estruturados na nuvem como objetos/blobs. O Armazenamento de Blobs pode armazenar qualquer tipo de texto ou dados binários, como um documento, um arquivo de mídia ou um instalador de aplicativo. O Armazenamento de Blobs também é conhecido como armazenamento de objeto.

[Referência do programador de ODBC](https://docs.microsoft.com/sql/odbc/reference/odbc-programmer-s-reference) interface o ODBC foi projetado para uso com a linguagem de programação C. O uso da interface ODBC abrange três áreas: instruções SQL, chamadas da função ODBC e programação em C.

## <a name="see-also"></a>Consulte também
[Visual C++](../visual-cpp-in-visual-studio.md)
