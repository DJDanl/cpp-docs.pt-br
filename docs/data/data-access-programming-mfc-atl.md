---
title: Acesso a dados (MFC / ATL) de programação
ms.date: 11/16/2018
helpviewer_keywords:
- MFC [C++], data access applications
- databases [C++], MFC
- OLE DB [C++], data access technologies
- data [C++], data access technologies
- data access [C++], class libraries for databases
ms.assetid: def97b2c-b5a6-445f-afeb-308050fd4852
ms.openlocfilehash: e71e16bef29239e0c6a391b2d5e2129042cd52fa
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221849"
---
# <a name="data-access-programming-mfcatl"></a>Programação de acesso a dados (MFC/ATL)

Ao longo dos anos, o Visual C++ forneceu várias maneiras de trabalhar com bancos de dados. Em 2011 a Microsoft anunciou que ele está se adequando na conectividade aberta de banco de dados (ODBC) como a tecnologia preferencial para acessar produtos do SQL Server de código nativo. O ODBC é um padrão do setor e, ao usá-lo, você obtém o máximo de portabilidade de código em várias plataformas e fontes de dados. A maioria dos produtos de banco de dados SQL e muitos produtos NoSQL dão suporte ao ODBC. Você pode usar o ODBC diretamente, chamando as APIs de ODBC de nível inferior, ou você pode usar as classes wrapper de ODBC do MFC ou em uma biblioteca wrapper de C++ de terceiros.

A OLE DB é uma API de nível baixo e alto desempenho com base na especificação COM e só tem suporte no Windows. Use a OLE DB se seu programa estiver acessando [servidores vinculados](/sql/relational-databases/linked-servers/linked-servers-database-engine). A ATL fornece modelos de OLE DB que facilitam a criação de consumidores e provedores OLE DB personalizados. O provedor mais recente para o Microsoft SQL Server pode ser encontrado na documentação para o [Driver do OLE DB para SQL Server](/sql/connect/oledb/oledb-driver-for-sql-server).

## <a name="porting-data-applications"></a>Movimentando aplicativos de dados

Se seu aplicativo herdado usa OLE DB ou a interface ADO de nível mais alto para se conectar ao SQL Server, você deve considerar a migração para o versão mais recente [Driver do OLE DB para SQL Server](/sql/connect/oledb/oledb-driver-for-sql-server) para tirar proveito dos recursos mais recentes do SQL Server. Outra alternativa, se você não precisar de portabilidade de plataforma cruzada ou os recursos mais recentes do SQL Server, você pode, possivelmente, usar o Microsoft OLE DB Provider para ODBC (MSDASQL).  O MSDASQL permite que os aplicativos que são criados com base em OLE DB e ADO (que usa internamente OLEDB) acessem fontes de dados por meio de um driver ODBC. Assim como acontece com qualquer camada de translação, o MSDASQL pode afetar o desempenho do banco de dados. Você deve testar para determinar se o impacto é significativo para seu aplicativo. O MSDASQL é fornecido com o sistema operacional Windows e o Windows Server 2008 e Windows Vista SP1 são as primeira versões a incluir uma versão de 64 bits da tecnologia.

Se seu C++ aplicativo se conecta ao SQL Server ou banco de dados SQL Azure por meio de ODBC, ele deverá usar [o driver ODBC mais recente](/sql/connect/odbc/download-odbc-driver-for-sql-server).

Se você usa C++/CLI, você pode continuar a usar o ADO.NET como sempre. Para obter mais informações, consulte [Acesso a dados usando ADO.NET (C++/CLI)](../dotnet/data-access-using-adonet-cpp-cli.md) e [Acesso a dados no Visual Studio](/visualstudio/data-tools/accessing-data-in-visual-studio).

- Além das classes wrapper de ODBC, o MFC também fornece as classes wrapper de DAO (Objetos de Acesso a Dados) para se conectar aos bancos de dados do Access.  No entanto, o DAO está obsoleto. Qualquer código com base em CDaoDatabase ou CDaoRecordset deve ser atualizado.

Para obter mais informações sobre o histórico de tecnologias de acesso a dados no Microsoft Windows, consulte [Microsoft Data Access Components (Wikipédia)](https://en.wikipedia.org/wiki/Microsoft_Data_Access_Components).

## <a name="see-also"></a>Consulte também

[Acesso a dados](data-access-in-cpp.md)<br/>
[Microsoft ODBC (Open Database Connectivity)](/sql/odbc/microsoft-open-database-connectivity-odbc)<br/>
