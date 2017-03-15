---
title: "Redistribuindo componentes ODBC para os clientes | Microsoft Docs"
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
  - "componentes [C++]"
  - "componentes [C++], distribuindo"
  - "componentes [C++], redistribuindo"
  - "Administrador ODBC"
  - "Componentes ODBC, redistribuindo"
  - "ODBC, distribuindo componentes"
ms.assetid: 17b065b4-a307-4b89-99ac-d05831cfab87
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Redistribuindo componentes ODBC para os clientes
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Se você inserir a funcionalidade de programas do administrador de ODBC em seu aplicativo, você deve também distribuir aos usuários os arquivos que executam esses programas.  Esses arquivos de ODBC residem no diretório \\OS\\System do CD\-ROM do Visual C\+\+.  O arquivo de Redistrb.wri e o contrato de licença no mesmo diretório contém uma lista de arquivos do ODBC que você pode redistribuir.  
  
 Consulte a documentação para todos os drivers ODBC que você planejar para enviar.  É necessário determinar quais DLL e outros arquivos a ser enviado.  
  
 Você também deve ler [Instalando o suporte da base de dados](../../data/installing-database-support-mfc-atl.md) para obter informações sobre os componentes e dos drivers ODBC e ler [Redistribuindo controles](../Topic/Redistributing%20Controls.md), que explica como redistribuir controles ActiveX.  
  
 Além disso, você precisa incluir na maioria dos casos outro arquivo.  O Odbccr32.dll é a biblioteca de cursores ODBC.  Essa biblioteca fornece a drivers de nível 1 o recurso de rolagem para frente e para trás.  O também fornece a capacidade de suporte a instantâneos.  Para obter mais informações sobre a biblioteca de cursores ODBC, consulte [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md).  
  
 Os tópicos a seguir fornecem mais informações sobre como usar ODBC com as classes da base de dados:  
  
-   [ODBC: A biblioteca de cursores ODBC](../../data/odbc/odbc-the-odbc-cursor-library.md)  
  
-   [ODBC: Configurando uma fonte de dados ODBC](../../data/odbc/odbc-configuring-an-odbc-data-source.md)  
  
-   [ODBC: A API ODBC chamada diretamente de funções](../../data/odbc/odbc-calling-odbc-api-functions-directly.md)  
  
## Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)   
 [Administrador ODBC](../../data/odbc/odbc-administrator.md)