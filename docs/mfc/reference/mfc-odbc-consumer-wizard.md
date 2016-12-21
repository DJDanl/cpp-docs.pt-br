---
title: "Assistente de consumidor ODBC MFC | Microsoft Docs"
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
  - "vc.codewiz.class.mfc.consumer.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de consumidor ODBC MFC"
  - "assistentes [MFC]"
ms.assetid: f64a890b-a252-4887-88a1-782a7cd4ff3d
caps.latest.revision: 7
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente de consumidor ODBC MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Resumo dos “resultados da pesquisa” de inserção aqui.  
  
 Esse assistente configura de uma classe do conjunto de registros ODBC e associações de dados necessárias para acessar a fonte de dados especificada.  
  
## Lista UIElement  
 **Fonte de dados**  
 O botão de **Fonte de dados** permite configurar a fonte de dados especificada usando o driver ODBC especificado.  Para obter mais informações sobre os arquivos de fonte de dados \(DSN\), consulte [Fontes de dados de Arquivo](https://msdn.microsoft.com/en-us/library/ms715401.aspx) no ODBC SDK.  A caixa de diálogo de **Selecionar Fonte de Dados** tem duas guias:  
  
-   guia de**Fonte de dados de Arquivo** : A caixa de **Examinar** especifica o diretório no qual o para selecionar os arquivos a serem usados como fontes de dados.  O padrão é \\Arquivos de programas\\Common Files\\ODBC\\Data Sources.  As fontes de dados do arquivo existente \(arquivos de .dsn\) são exibidos na caixa de listagem principal.  Você pode configurar as fontes de dados antecedência que usam o guia de **DSN de Arquivo** em [Administrador de fonte de dados ODBC](https://msdn.microsoft.com/en-us/library/ms714024.aspx), ou criar novos usando essa caixa de diálogo.  
  
     Para criar uma fonte de dados do novo arquivo dessa caixa de diálogo, clique em `New` para especificar um nome de DSN; a caixa de diálogo de **Criar nova fonte de dados** é exibida.  Na caixa de diálogo de **Criar nova fonte de dados** , selecione um driver apropriado e clique `Next`; clique **Procurar**, e selecione o nome do arquivo a ser usado como uma fonte de dados \(é necessário selecionar “todos os arquivos” para exibir arquivos de não DSN, como arquivos .xls\); clique `Next`, e clique em **Concluir**. \(Se você selecionou um arquivo de configuração do DSN não, será exibida uma caixa de diálogo específicas de driver, como “a configuração ODBC o Microsoft Excel,” que o converterá o arquivo em um DSN.\)  
  
    > [!NOTE]
    >  Você também pode criar uma fonte de dados do novo arquivo que usa com antecedência o administrador de fonte de dados ODBC.  No menu de **Iniciar** , de **Configurações**selecione, de **Painel de Controle**, de **Ferramentas Administrativas**, de **Data Sources \(ODBC\)**e, depois de **Administrador de fonte de dados ODBC**.  
  
     A caixa de **Nome da fonte** permite que você especifique um nome para a fonte de dados do arquivo.  Você deve garantir que o nome de um DSN termine com a extensão de arquivo apropriado, como .xls para arquivos do Excel ou .mdb para acessar arquivos.  
  
     Para obter mais informações sobre como DSNs, consulte [Fontes de dados de Arquivo](https://msdn.microsoft.com/en-us/library/ms715401.aspx) no ODBC SDK.  
  
-   Guia de**Machine Data Source** : Essa guia lista fontes de dados de sistema e usuário.  As fontes de dados de usuários são específicas a um usuário neste computador.  As fontes de dados do sistema podem ser usadas por todos os usuários neste computador ou pelo sistema em um serviço.  Consulte [Fontes de dados do computador](https://msdn.microsoft.com/en-us/library/ms710952.aspx) no ODBC SDK  
  
 Para obter mais informações sobre as fontes de dados ODBC, consulte [Fontes de dados](https://msdn.microsoft.com/en-us/library/ms711688.aspx) no ODBC SDK.  
  
 Clique em **OK** a conclusão.  A caixa de diálogo de **Selecionar Objeto do Banco de Dados** é exibida.  Essa caixa de diálogo, selecione a tabela ou exibição que o consumidor usará.  Observe que você pode selecionar várias exibições e tabelas com a tecla de controle ao clicar em itens.  
  
 **Class**  
 O nome da classe do consumidor, por padrão com base no nome da fonte de dados do arquivo ou do computador que você selecionou.  
  
 **arquivo .h**  
 O nome do arquivo de cabeçalho da classe do consumidor, por padrão com base no nome da fonte de dados do arquivo ou do computador que você selecionou.  
  
 **arquivo .cpp**  
 O nome do arquivo de implementação da classe do consumidor, por padrão com base no nome da fonte de dados do arquivo ou do computador que você selecionou.  
  
 **Tipo**  
 Especifica se o conjunto de registros é um dynaset \(padrão\) ou um instantâneo.  
  
-   **Dynaset**: Especifica que o conjunto de registros é um dynaset.  Um dynaset é o resultado de uma consulta que fornece uma exibição indexada nos dados da base de dados consultado.  Um dynaset armazena em cachê apenas um índice completo aos dados originais e oferece o ganho de desempenho sobre um instantâneo.  Os pontos de índice diretamente para cada registro localizado no resultado de uma consulta e indica se um registro é removido.  Você também tem acesso às informações atualizadas nos registros consultados.  Esse é o padrão.  
  
-   **Instantâneo**: Especifica que o conjunto de registros é um instantâneo.  Um instantâneo é o resultado de uma consulta e é uma exibição em um base de dados ao certo ponto.  Registra todos localizado no resultado da consulta é armazenado em cachê, para que você não vir nenhuma alteração nos registros originais.  
  
 **Associar todas as colunas**  
 Especifica se todas as colunas na tabela selecionada estão associadas.  Se você selecionar essa caixa \(padrão\), todas as colunas são associadas; se você não selecionar essa caixa, nenhuma coluna é associada, e é preciso associá\-la manualmente na classe do conjunto de registros.  
  
## Consulte também  
 [Consumidor ODBC do MFC](../../mfc/reference/adding-an-mfc-odbc-consumer.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)