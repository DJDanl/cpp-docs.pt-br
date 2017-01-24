---
title: "ODBC e MFC | Microsoft Docs"
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
  - "conexões [C++], fonte de dados"
  - "conexões [C++], bancos de dados"
  - "fonte de dados [C++], conectando a"
  - "conexões de banco de dados [C++], Classes MFC ODBC"
  - "bancos de dados [C++], conectando a"
  - "MFC [C++], ODBC e"
  - "ODBC [C++], MFC"
ms.assetid: 98f02fd7-1235-437b-89a9-edfd0fc797f7
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ODBC e MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  Para usar as classes da base de dados de MFC para destinar uma plataforma do Win32 \(como o Windows NT\), você deve ter o driver ODBC apropriado para sua fonte de dados.  Alguns drivers são incluídos no Visual C\+\+; outros podem ser obtidos da Microsoft e de outros provedor.  Para obter mais informações, consulte [Lista de driver ODBC](../../data/odbc/odbc-driver-list.md).  
  
 Este tópico apresenta os conceitos principais das classes com base da base de dados \(MFC\) da biblioteca de classes do Microsoft e fornece uma visão geral de como as classes funcionam em conjunto.  Para obter mais informações sobre ODBC e MFC, consulte os seguintes tópicos:  
  
-   [Conectando\-se a uma fonte de dados](../../data/odbc/connecting-to-a-data-source.md)  
  
-   [Selecionando e manipular registros](../../data/odbc/selecting-and-manipulating-records.md)  
  
-   [Exibindo e manipulação de dados em um formulário](../Topic/Displaying%20and%20Manipulating%20Data%20in%20a%20Form.md)  
  
-   [Trabalhar com documentos e exibições](../../data/odbc/working-with-documents-and-views.md)  
  
-   [Acesso ao ODBC e SQL](../../data/odbc/access-to-odbc-and-sql.md)  
  
-   [Leitura adicionais sobre as classes MFC ODBC](../../data/odbc/further-reading-about-the-mfc-odbc-classes.md)  
  
 As classes da base de dados de MFC com base em ODBC são criadas para fornecer acesso a qualquer base de dados para que um driver ODBC está disponível.  Como as classes usam ODBC, o aplicativo pode acessar dados em diversos formatos de dados diferentes e configurações locais e remotas diferentes.  Você não precisa escrever o código maiúsculas de minúsculas para sistemas de gerenciamento diferentes \(DBMSs\) da base de dados do identificador.  Contanto que os usuários tenham um driver ODBC apropriado para os dados que deseja acessar, podem usar seu programa de manipulação de dados nas tabelas armazenadas lá.  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)