---
title: "No&#231;&#245;es b&#225;sicas de ODBC | Microsoft Docs"
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
  - "Componentes ODBC"
  - "Componentes ODBC, componentes necessários"
  - "biblioteca de cursores ODBC [ODBC], Componentes ODBC"
  - "ODBC, sobre ODBC"
  - "ODBC, componentes"
ms.assetid: ec529702-0fb2-4754-b8de-d1efa8eca18f
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas de ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico apresenta os fundamentos de ODBC:  
  
-   [Como o ODBC funciona com base de dados de classificação](../../data/odbc/odbc-and-the-database-classes.md)  
  
-   [Como os drivers ODBC funcionam com Dynasets](../../data/odbc/odbc-driver-requirements-for-dynasets.md)  
  
-   [Os componentes ODBC precisará redistribuir com seus aplicativos](../../data/odbc/redistributing-odbc-components-to-your-customers.md)  
  
 Você também pode querer ler o tópico relacionado [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).  
  
> [!NOTE]
>  As fontes de dados ODBC são acessíveis por meio das classes MFC ODBC, como descrito neste tópico, ou as classes de \(DAO\) do objeto de acesso a dados de MFC.  
  
> [!NOTE]
>  As classes de MFC ODBC oferecem suporte ao Unicode e multithreading.  Para obter mais informações sobre o suporte de multithreading, consulte [Classes e threads ODBC](../Topic/ODBC%20Classes%20and%20Threads.md)  
  
 O ODBC é uma interface de nível de chamada que permite aplicativos para acessar dados em qualquer base de dados para que haja um driver ODBC.  Usando o ODBC, você poderá criar aplicativos de base de dados com acesso a qualquer base de dados para que o usuário final tenha um driver ODBC.  O fornece uma API ODBC permite que o aplicativo ser independentes do sistema de gerenciamento da base de dados de origem \(DBMS\).  
  
 O ODBC é a parte da base de dados da arquitetura aberta \(WOSA\) dos serviços do Microsoft Windows, que é uma interface que permite aplicativos de desktop baseados no Windows se conectar a vários ambientes de computação sem reescrever o aplicativo para cada plataforma.  
  
 Os seguintes são componentes ODBC:  
  
-   API ODBC  
  
     Uma biblioteca das chamadas de função, de um conjunto de códigos de erro, e uma sintaxe padrão de [SQL](../../data/odbc/sql.md) para acessar dados em DBMSs.  
  
-   Gerenciador de driver ODBC  
  
     Uma biblioteca de vínculo dinâmico \(Odbc32.dll\) que drivers da base de dados de ODBC das cargas em nome de um aplicativo.  Este DLL é transparente ao aplicativo.  
  
-   Drivers da base de dados de ODBC  
  
     Um ou mais DLL que processam chamadas de função ODBC para DBMSs específico.  Para obter uma lista de drivers fornecidos, consulte [Lista de driver ODBC](../../data/odbc/odbc-driver-list.md).  
  
-   [Biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)  
  
     Uma biblioteca de vínculo dinâmico \(Odbccr32.dll\) que reside entre o gerenciador de driver ODBC e drivers e trata a rolagem com os dados.  
  
-   [Administrador ODBC](../../data/odbc/odbc-administrator.md)  
  
     Uma ferramenta usada para configurar o DBMS para torná\-lo disponível como uma fonte de dados para um aplicativo.  
  
 Um aplicativo obtém a independência de DBMSs trabalhando em um driver ODBC gravado especificamente para o DBMS em vez de trabalhando diretamente com o DBMS.  O driver traduz as chamadas em comandos que o DBMS pode usar, simplificando o trabalho de desenvolvedor e tornando\-o disponível para uma ampla variedade de fontes de dados.  
  
 As classes de base de dados do oferecem suporte a qualquer fonte de dados para que você tenha um driver ODBC.  Isso pode, por exemplo, para incluir um base de dados relacional, um base de dados sequencial indexado \(ISAM\) de método de acesso, uma planilha do Microsoft Excel, ou um arquivo de texto.  Os drivers ODBC gerencia as conexões com a fonte de dados, e do SQL é usado para selecionar registros do base de dados.  
  
 Para obter uma lista de drivers ODBC incluídos nesta versão do Visual C\+\+ e para obter informações sobre como obter drivers adicionais, consulte [Lista de driver ODBC](../../data/odbc/odbc-driver-list.md).  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)