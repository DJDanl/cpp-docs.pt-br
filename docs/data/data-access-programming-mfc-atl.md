---
title: "Programa&#231;&#227;o de acesso a dados (MFC/ATL) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dados [C++], tecnologias de acesso a dados"
  - "acesso a dados [C++], bibliotecas de classes para bancos de dados"
  - "bancos de dados [C++], MFC"
  - "MFC [C++], aplicativos de acesso a dados"
  - "OLE DB [C++], tecnologias de acesso a dados"
ms.assetid: def97b2c-b5a6-445f-afeb-308050fd4852
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Programa&#231;&#227;o de acesso a dados (MFC/ATL)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ fornece várias maneiras de trabalhar com bancos de dados.  A melhor maneira é usar uma das bibliotecas de classe, como a classe biblioteca ATL \(Active Template Library\) ou a biblioteca MFC \(Microsoft Foundation Class\), que simplificam o trabalho com os APIs do banco de dados.  
  
> [!NOTE]
>  Este tópico aborda as tecnologias mais antigas que podem ser usadas para programação do banco de dados no Visual C\+\+.  Para obter informações sobre a programação de acesso a dados usando Visual C\+\+ e o SQL Server 2005, consulte [Acesso a dados](../dotnet/data-access-using-adonet-cpp-cli.md), [Acessando dados no Visual Studio](../Topic/Accessing%20data%20in%20Visual%20Studio.md), e [Creating SQL Server 2005 Objects In Managed Code](http://msdn.microsoft.com/pt-br/5358a825-e19b-49aa-8214-674ce5fed1da).  
  
 As classes de biblioteca suportam os seguintes tipos de acesso a dados:  
  
-   ATL fornece modelos OLE DB e atributos de banco de dados.  
  
-   MFC fornece o ODBC \(Conectividade Aberta de Banco de Dados\) e um driver de ODBC.  
  
 Essas bibliotecas fornecem abstrações que simplificam o trabalho com bancos de dados, completo com velocidade, energia e a flexibilidade do C\+\+.  Elas integram o trabalho de acesso aos dados, com a estrutura de aplicativos da biblioteca.  
  
 Como alternativa, você pode chamar diretamente funções de API do banco de dados dos SDKs \(Software Development Kits\).  Para obter informações sobre como programar diretamente com funções de API COM, DAO, or ODBC, consulte o SDK COM, DAO SDK ou ODBC SDK.  
  
 Use o BD ATL OLE se você precisar acessar dados, independentemente da forma em que são armazenados.  Use as classes MFC ODBC quando não estiver usando bancos de dados Microsoft Jet \(.mdb\) e quiser trabalhar com a API ODBC para independência de fonte de dados completa.  Use as classes MFC DAO quando quiser trabalhar com bancos de dados Microsoft Jet \(. mdb\) ou com bancos de dados externos, como fontes de dados ODBC.  
  
> [!NOTE]
>  A Microsoft recomenda usando OLE DB ou ODBC para novos projetos.  DAO só deve ser usado na manutenção de aplicativos existentes.  
  
 Além de criar aplicativos de banco de dados autônomo, você também pode usar um banco de dados com eficiência em outros tipos de programas como um meio conveniente de armazenamento e recuperação.  
  
|Para saber mais a respeito|Consulte|  
|--------------------------------|--------------|  
|**Selecionando uma tecnologia de banco de dados**||  
|ODBC vs.  DAO|[Devo usar DAO ou ODBC?](../data/should-i-use-dao-or-odbc-q.md)|  
|Usando a base de dados de Conhecimento Microsoft para localizar artigos adicionais sobre tópicos de banco de dados gravados pelos engenheiros de suporte do produto|[Base de dados de conhecimento da Microsoft](../data/where-can-i-find-microsoft-knowledge-base-articles-on-database-topics-q.md)|  
|**Suporte a banco de dados ATL \(OLE DB\)**||  
|Programação de OLE DB \(tópicos conceituais\)|[Visão geral da programação de banco de dados OLE](../data/oledb/ole-db-programming-overview.md)|  
|Usando os modelos de consumidor OLE DB \(tópicos conceituais\)|[Modelos de consumidor de banco de dados OLE](../data/oledb/ole-db-consumer-templates-cpp.md)|  
|Atributos do consumidor OLE DB|[Atributos de consumidor de banco de dados OLE](../windows/ole-db-consumer-attributes.md)|  
|Usando modelos do provedor der OLE DB \(tópicos conceituais\)|[Modelos de provedor de banco de dados OLE](../data/oledb/ole-db-provider-templates-cpp.md)|  
|Adicionando um consumidor OLE DB a um projeto MFC|[Criando um consumidor de banco de dados OLE](../data/oledb/creating-an-ole-db-consumer.md)|  
|**Suporte a banco de dados MFC \(ODBC e DAO\)**||  
|O que são DAO e ODBC|[O que são DAO e ODBC?](../data/what-are-dao-and-odbc-q.md)|  
|Quando usar as classes de banco de dados MFC|[Quando devo usar as classes de banco de dados?](../data/when-should-i-use-the-database-classes-q.md)|  
|Saiba mais sobre o modelo de programação de banco de dados MFC|[O que é o modelo de programação de banco de dados MFC?](../data/what-is-the-mfc-database-programming-model-q.md).|  
|Escolha entre as classes MFC DAO e as classes MFC ODBC|[Devo usar DAO ou ODBC?](../data/should-i-use-dao-or-odbc-q.md).|  
|Você pode acessar fontes de dados com DAO e ODBC|[Quais origens de dados posso acessar com DAO e ODBC?](../data/what-data-sources-can-i-access-with-dao-and-odbc-q.md)|  
|Conectividade de banco de dados aberto \(ODBC\)|[ODBC e MFC](../data/odbc/odbc-and-mfc.md)|  
|Caso você chame APIs de DAO ou ODBC diretamente ao usar as classes|[Posso chamar DAO ou ODBC diretamente?](../data/can-i-call-dao-or-odbc-directly-q.md)|  
|Quais drivers ODBC são fornecidos|[Lista de drivers ODBC](../data/odbc/odbc-driver-list.md)|  
|Como o banco de dados classifica trabalho com a arquitetura de documentos e exibição do MFC|[MFC: usando classes de banco de dados com documentos e exibições](../data/mfc-using-database-classes-with-documents-and-views.md)|  
|Instalando suporte ao banco de dados MFC; quais drivers ODBC estão instalados no Visual C\+\+ por padrão e quais componentes de SDK ODBC e DAO estão instalados|[Instalando suporte do banco de dados MFC](../data/installing-mfc-database-support.md)|  
|**Controles de dados associados \(ADO e RDO\)**||  
|Escrevendo um programa que usa controles associados a dados|[Controles de dados associados \(ADO e RDO\)](../Topic/Data-Bound%20Controls%20\(ADO%20and%20RDO\).md)|  
|Associação de dados usando os controles ActiveX|[Controles ActiveX MFC: usando associação de dados em um controle ActiveX](../mfc/mfc-activex-controls-using-data-binding-in-an-activex-control.md)|  
|Distribuind controles ActiveX|[Controles ActiveX MFC: distribuindo controles ActiveX](../mfc/mfc-activex-controls-distributing-activex-controls.md)|  
  
## Consulte também  
 [Acesso a dados](../Topic/Data%20Access%20in%20Visual%20C++.md)