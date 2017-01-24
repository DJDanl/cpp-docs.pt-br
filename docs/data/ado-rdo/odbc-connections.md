---
title: "Conex&#245;es ODBC | Microsoft Docs"
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
  - "Conexões ODBC, configurando"
  - "ODBC, conectividade"
ms.assetid: c9df2fa6-d9e2-4335-b885-724662968691
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conex&#245;es ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As conexões de ODBC são configuradas no Painel de Controle do sistema.  As conexões de ODBC podem ser feitas com qualquer fonte de dados para a qual um driver ODBC tenha sido instalado.  O Visual C\+\+ 6.0 ou mais recente fornece drivers para arquivos de texto, Access, FoxPro, Paradox, dBASE, Excel, SQL Server, e Oracle.  Ao criar uma conexão de ODBC, ela recebe automaticamente um nome da fonte de dados \(DSN\).  O DSN é usado subsequentemente para identificar conexões em controles de dados, como um controle de dados do ADO e um controle RemoteData do RDO.  
  
 **Conexões OLE DB** Não é necessário trabalho adicional para configurar uma conexão do OLE DB.  Por exemplo, se uma fonte de dados ODBC é criada, o provedor OLE DB para ODBC detecta\-a automaticamente.  
  
### Para configurar uma fonte de dados ODBC  
  
1.  Clique em **Iniciar**, clique em **Configurações** e em **Painel de Controle**.  
  
2.  No painel de controle, selecione ODBC de 32 bits \(Windows 95 ou 98\) ou ODBC \(Windows NT ou 2000\).  
  
3.  Clique na guia **DSN do Usuário** ou **DSN do Sistema**.  **O DSN do usuário** permite que você crie nomes de fonte de dados específicos do usuário e o **DSN de sistema** permite que você crie as fontes de dados disponíveis para todos os usuários.  
  
4.  Clique em **Adicionar** para exibir uma lista de drivers ODBC instalados localmente.  
  
5.  Selecione o driver correspondente ao tipo de método de acesso sequencial indexado \(ISAM\) ou o banco de dados ao qual você deseja se conectar e clique em **Concluir**.  
  
6.  Siga as instruções específicas do driver.  Após fechar, um DSN está disponível para uso.  
  
 Ao gerar um DSN para alguns tipos de driver de ODBC, você precisará saber o local do arquivo real.  Por exemplo, ao criar um acesso DSN, você precisará saber a localização do arquivo .mdb.  Além disso, você deve ter um nome de usuário e uma senha válidos.  Por exemplo, o nome de usuário do sistema para a maioria dos sistemas Access é *admin*.  
  
 Ao criar um DSN do [Oracle](../../data/ado-rdo/oracle-connections.md), você deve saber a cadeia de conexão do SQL\*Net.  
  
## Consulte também  
 [Criando conexões de banco de dados](../Topic/Creating%20Database%20Connections.md)