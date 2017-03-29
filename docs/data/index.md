---
layout: LandingPage
title: Acesso a dados no Visual C++
translationtype: Human Translation
ms.sourcegitcommit: f9e63f47a8df69b52a6a12688e84602981d20dae
ms.openlocfilehash: 807cf772d632f66f74a210985ff611fc31ee594a
ms.lasthandoff: 03/21/2017

---
# <a name="data-access-in-visual-c"></a>Acesso a dados no Visual C++

Praticamente todos os produtos de banco de dados, SQL e NoSQL, fornecem uma interface para aplicativos nativos do C++. A interface padrão do setor é ODBC, que dá suporte para todos os principais produtos de Banco de Dados SQL e para muitos produtos NoSQL. Para produtos que não são da Microsoft, consulte o fornecedor para obter mais informações. Bibliotecas de terceiros com vários termos de licença também estão disponíveis.

Desde 2011, a Microsoft tem se alinhado com o ODBC como o padrão para aplicativos nativos para se conectar a bancos de dados do Microsoft SQL Server, tanto localmente quanto na nuvem. Para obter mais informações, consulte [Programação de acesso a dados \(MFC/ATL\)](data-access-programming-mfc-atl.md). As bibliotecas C++/CLI podem usar os drivers ODBC nativos ou ADO.NET. Para obter mais informações, consulte [Acesso a dados usando ADO.NET (C++/CLI)](/dotnet/data-access-using-adonet-cpp-cli.md) e [Accessing data in Visual Studio](https://docs.microsoft.com/visualstudio/data-tools/accessing-data-in-visual-studio) (Acesso a dados no Visual Studio).

<ul class="panelContent cardsF">
<li>
        <a href="/azure/sql-database/sql-database-develop-cplusplus-simple">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/azure/media/index/SQLDatabase.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Conectar-se ao Banco de Dados SQL usando C e C++</h3>
                        <p>Conectar-se ao Banco de Dados SQL do Azure de aplicativos C ou C++</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="https://github.com/Azure/azure-storage-cpp">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/azure/media/index/Storage.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Biblioteca de cliente do Armazenamento do Microsoft Azure para C++</h3>
                        <p>O [Armazenamento do Azure](/azure/storage/storage-introduction) é uma solução de armazenamento em nuvem para aplicativos modernos que dependem de durabilidade, disponibilidade e escalabilidade para atender às necessidades dos clientes. Conecte-se ao Armazenamento do Azure pelo C++ usando a Biblioteca de Cliente do Armazenamento do Azure para C++.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="https://blogs.msdn.microsoft.com/sqlnativeclient/2016/08/01/announcing-the-odbc-driver-13-1-for-sql-server/">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/media/common/i_drivers.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Driver ODBC 13.1 para SQL Server – lançado para Windows</h3>
                        <p>O driver ODBC mais recente fornece acesso eficiente a dados para o Microsoft SQL Server 2016 e para o Banco de Dados SQL do Microsoft Azure para aplicativos baseados em C/C++. Ele dá suporte para recursos, incluindo o Always Encrypted, o Azure Active Directory e os Grupos de Disponibilidade AlwaysOn. Também está disponível para MacOS e Linux.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="https://msdn.microsoft.com/library/ms130892.aspx">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/media/common/i_api.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>SQL Server Native Client</h3>
                        <p>O SQL Server Native Client é uma API (Interface de Programação de Aplicativo) de acesso a dados autônoma, usada tanto para OLE DB quanto para ODBC, que dá suporte ao SQL Server 2005 por meio do SQL Server 2014. Aplicativos novos devem usar o Driver ODBC 13.1 para SQL Server.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="data-access-programming-mfc-atl.md">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/media/common/i_api.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Programação de acesso a dados</h3>
                        <p>Descreve programação de acesso a dados herdados com Visual C++, em que a melhor maneira é usar uma das bibliotecas de classe, como a classe biblioteca ATL (Active Template Library) ou a biblioteca MFC (Microsoft Foundation Class), que simplificam o trabalho com as APIs do banco de dados.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="odbc/open-database-connectivity-odbc.md">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/media/common/i_multi-connect.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Conectividade de banco de dados aberto (ODBC)</h3>
                        <p>A biblioteca MFC (Microsoft Foundation Classes) fornece classes para programar com ODBC (Conectividade Aberta de Banco de Dados).</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="oledb/ole-db-programming.md">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardImageOuter">
                        <div class="cardImage">
                            <img src="/media/common/i_generic-database.svg" alt="" />
                        </div>
                    </div>
                    <div class="cardText">
                        <h3>Programação de banco de dados OLE</h3>
                        <p>Fornece links para tópicos conceituais que discutem tecnologia de banco de dados OLE DB e biblioteca de modelos OLE DB. (O OLE DB não é recomendado para novos aplicativos, exceto em cenários que envolvem servidores vinculados.)</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    
</ul>

---

<h2>Referência</h2>

<ul class="panelContent cardsW">
 <li>
        <a href="https://azure.microsoft.com/develop/cpp/">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardText">
                        <h3>Microsoft Azure C e C++ Developer Center</h3>
                        <p>O Azure facilita o build de aplicativos do C++, com maior flexibilidade, escalabilidade e confiabilidade usando ferramentas que você adora.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="https://docs.microsoft.com/azure/storage/storage-c-plus-plus-how-to-use-blobs">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardText">
                        <h3>Como usar o Armazenamento de Blobs do C++</h3>
                        <p>O Armazenamento de Blobs do Azure é um serviço que armazena dados não estruturados na nuvem como objetos/blobs. O Armazenamento de Blobs pode armazenar qualquer tipo de texto ou dados binários, como um documento, um arquivo de mídia ou um instalador de aplicativo. O Armazenamento de Blobs também é conhecido como armazenamento de objeto.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <a href="https://docs.microsoft.com/sql/odbc/reference/odbc-programmer-s-reference">
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardText">
                        <h3>Referência do Programador de ODBC</h3>
                        <p>A interface ODBC é projetada para uso com a linguagem de programação C. O uso da interface ODBC abrange três áreas: instruções SQL, chamadas da função ODBC e programação em C.</p>
                    </div>
                </div>
            </div>
        </div>
        </a>
    </li>
    <li>
        <div class="cardSize">
            <div class="cardPadding">
                <div class="card">
                    <div class="cardText">
                        <h3><a href="https://www.microsoft.com/download/details.aspx?id=53339" title="Microsoft® ODBC Driver 13.1 for SQL Server® - Windows Download Page">Driver ODBC 13.1 para SQL Server</a></h3>
                        <p>O Microsoft ODBC Driver 13.1 para SQL Server é uma biblioteca de vínculo dinâmico (DLL) única que contém suporte em tempo de execução para aplicativos que usam APIs de código nativo para se conectar ao Microsoft SQL Server 2008, SQL Server 2008 R2, SQL Server 2012, SQL Server 2016, Analytics Platform System, Banco de Dados SQL e SQL Data Warehouse. Baixe o driver aqui.</p>
                    </div>
                </div>
            </div>
        </div>        
    </li>
    
</ul>
