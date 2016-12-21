---
title: "TN048: escrevendo programas de instala&#231;&#227;o e administra&#231;&#227;o ODBC para aplicativos de banco de dados MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.odbc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instalando ODBC"
  - "MFC, aplicativos de banco de dados"
  - "ODBC, e MFC"
  - "ODBC, instalando"
  - "instalação, programas de instalação ODBC"
  - "TN048"
ms.assetid: d456cdd4-0513-4a51-80c0-9132b66115ce
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN048: escrevendo programas de instala&#231;&#227;o e administra&#231;&#227;o ODBC para aplicativos de banco de dados MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Os aplicativos que usam classes de base de dados de MFC precisarão um programa de instalação que instala componentes ODBC.  Também podem precisar de um programa de administração ODBC que recupera informações sobre os drivers disponíveis, para especificar drivers padrão e para configurar fontes de dados.  Essa observação descreve o uso de API do instalador ODBC gravar esses programas.  
  
##  <a name="_mfcnotes_writing_an_odbc_setup_program"></a> Escrever um programa de instalação do ODBC  
 Um aplicativo de base de dados de MFC requer o gerenciador de driver ODBC \(ODBC.DLL\) e drivers ODBC poder obter a fontes de dados.  Muitos drivers ODBC também exigem DLL adicionais de rede e de comunicação.  A maioria de envio dos drivers ODBC com um programa de instalação que instala os componentes necessários para ODBC.  Os desenvolvedores de aplicativos que usam classes de base de dados de MFC podem:  
  
-   Confie em programas de instalação para instalar componentes específicos de driver ODBC.  Isso não requer nenhum trabalho adicional na parte do desenvolvedor — você pode apenas redistribuir o programa de instalação do driver.  
  
-   Como alternativa, você pode escrever seu próprio programa de instalação do, que instalará o gerenciador de driver e o driver.  
  
 O instalador API ODBC pode ser usado para gravar programas de instalação específicas do aplicativo.  As funções API do instalador são implementadas pela DLL do instalador ODBC — ODBCINST.DLL no windows de 16 bits e ODBCCP32.DLL no Win32.  Um aplicativo pode chamar **SQLInstallODBC** na DLL do instalador, que instalará o gerenciador de driver ODBC, drivers ODBC, e todos os tradutores necessários.  Registra os drivers e os tradutores instalados no arquivo de ODBCINST.INI \(ou no Registro, em NT\).  **SQLInstallODBC** requer o caminho completo para o arquivo de ODBC.INF, que contém a lista de drivers a serem instalados e descreve os arquivos que compõem cada driver.  Também contém as informações similares sobre o gerenciador e os tradutores do driver.  Os arquivos de ODBC.INF normalmente são fornecidos por desenvolvedores de driver.  
  
 Um programa também pode instalar componentes individuais do ODBC.  Para instalar o gerenciador de driver, primeiro chama **SQLInstallDriverManager** de um programa na DLL do instalador para obter o diretório de destino para o gerenciador de driver.  Este normalmente é o diretório em que os DLL do windows residem.  O programa usar as informações \[na seção do gerenciador de driver ODBC\] do arquivo de ODBC.INF para copiar o gerenciador de driver e os arquivos relacionados no disco de instalação do a esse diretório.  Para instalar um driver individual, primeiro chama **SQLInstallDriver** de um programa na DLL do instalador para adicionar a especificação de driver para o arquivo de ODBCINST.INI \(ou Registro, em NT\).  **SQLInstallDriver** retorna o diretório de destino do driver — geralmente o diretório no qual as dlls do windows residem.  O programa usar as informações na seção do driver do arquivo de ODBC.INF para copiar a DLL do driver e os arquivos relacionados no disco de instalação do a esse diretório.  
  
 Para obter mais informações sobre ODBC.INF, ODBCINST.INI e como usar a API do instalador, consulte *Referência do programador* do ODBC SDK, capítulo 19, Instalando o software ODBC.  
  
##  <a name="_mfcnotes_writing_an_odbc_administrator"></a> Escrevendo um administrador ODBC  
 Um aplicativo de base de dados de MFC pode configurar fontes de dados ODBC em uma das duas maneiras, como segue:  
  
-   Use o administrador ODBC \(disponível como um programa ou como um item do painel de controle\).  
  
-   Crie seu próprio programa para configurar as fontes de dados.  
  
 Um programa que configura fontes de dados faz chamadas de função para a DLL do instalador.  A DLL do instalador chama uma DLL de configuração para configurar uma fonte de dados.  Há uma DLL de configuração para cada driver; pode ser o próprio DLL do driver, ou uma DLL separada.  A DLL de configuração solicita ao usuário para informações que o driver precisa se conectar à fonte de dados e o tradutor padrão, se tiver suporte.  Chama a DLL do instalador e as APIs do windows para registrar essas informações no arquivo de ODBC.INI \(ou no Registro\).  
  
 Para exibir uma caixa de diálogo com que um usuário pode adicionar, modificar, excluir e as fontes de dados, chamadas **SQLManageDataSources** de um programa na DLL do instalador.  Esta função é chamada quando a DLL do instalador é chamado do painel de controle.  Para adicionar, remover, modificar ou excluir uma fonte de dados, **SQLManageDataSources** chama **ConfigDSN** na DLL de configuração para o driver associado a essa fonte de dados.  Para adicionar diretamente, modificar, excluir ou fontes de dados, um programa chamar **SQLConfigDataSource** na DLL do instalador.  O programa passa o nome da fonte de dados e uma opção que especifica a ação a ser tomada.  **SQLConfigDataSource** chama **ConfigDSN** na DLL de configuração e transfira os argumentos de **SQLConfigDataSource**.  
  
 Para obter mais informações, consulte a *Referência do programador* do ODBC SDK, capítulo 23, a Referência de função da DLL de instalação, e capítulo 24, referência de função da DLL do instalador.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)