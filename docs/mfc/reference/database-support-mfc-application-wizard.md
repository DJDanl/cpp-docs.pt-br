---
title: "Suporte ao banco de dados, Assistente de Aplicativo MFC | Microsoft Docs"
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
  - "vc.appwiz.mfc.exe.database"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de aplicativo MFC, suporte a banco de dados"
ms.assetid: 9ddf4558-fd41-4ac7-8d9b-c93d9c68ab59
caps.latest.revision: 9
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte ao banco de dados, Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta página fornece as opções que permitem especificar o nível de suporte da base de dados \(mais uma fonte de dados, se necessário\) para o projeto.  
  
 **Suporte a banco de dados**  
 Define o nível de suporte da base de dados do projeto.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Nenhum**|Não fornece nenhum suporte da base de dados.  Esta é a opção padrão.|  
|**Arquivos de cabeçalho apenas**|Fornece o nível de suporte da base de dados do aplicativo.<br /><br /> <ul><li>Se você selecionar o suporte de ODBC em **Tipo de cliente**, o assistente de aplicativo MFC inclua em seu projeto o arquivo de cabeçalho. AFXDB.H.  Adiciona bibliotecas de vínculo, mas não cria nenhuma classes base de dados \- específica.  Você pode criar conjuntos de registros e usá\-los posteriormente para revisar e atualizar registros.</li><li>Se você selecionar o suporte do OLE DB em **Tipo de cliente**, os seguintes arquivos de cabeçalho são incluídos:<br /><br /> <ul><li>ATLBASE.H</li><li>AFXOLEDB.H</li><li>ATLPLUS.H</li></ul></li></ul>|  
|**Exibição do base de dados sem suporte do arquivo**|Inclui arquivos de cabeçalho da base de dados, bibliotecas de vínculo, uma exibição do registro e um conjunto de registros. \(Disponível apenas para aplicativos com a opção de **Document\/view architecture support** selecionada na página de [Tipo de aplicativo](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) .\) Esta opção não inclui suporte do documento mas nenhum suporte à serialização.  Se você optar por incluir uma exibição de base de dados, você deve especificar a origem dos dados.|  
|**Exibição do base de dados com suporte do arquivo**|Inclui arquivos de cabeçalho da base de dados, bibliotecas de vínculo, uma exibição do registro e um conjunto de registros. \(Disponível apenas para aplicativos com a opção de **Document\/view architecture support** selecionada na página de **Tipo de Aplicativo** .\) Essa opção oferece suporte à serialização do documento, que você pode usar, por exemplo, para atualizar um arquivo de perfil de usuário.  Os aplicativos de base de dados operam normalmente em uma base por registro em vez de em uma base de um Arquivo por vez e assim que não precisam a serialização.  No entanto, é possível ter um uso especial para a serialização.  Se você optar por incluir uma exibição de base de dados, você deve especificar a origem dos dados.|  
  
> [!NOTE]
>  Em **Database Support**, se você selecionar **Database view without file support** ou **Database view with file support**, a derivação da classe da exibição é diferente, dependendo de sua seleção de **Tipo de cliente** , como segue:  
  
-   Se você selecionar **ODBC** em **Tipo de cliente**, a classe de exibição de aplicativo é derivado de [CRecordView](../../mfc/reference/crecordview-class.md).  Esta classe é associada a [CRecordset](../Topic/CRecordset%20Class.md)\- a classe derivada, que o assistente de aplicativo MFC também cria para você.  Essa opção oferece um aplicativo de autenticação baseado na exibição do registro é usada para exibir e atualizar registros com seu conjunto de registros.  
  
-   Se você selecionar **OLE DB** em **Tipo de cliente**, a classe da exibição é derivado de [COleDBRecordView](../../mfc/reference/coledbrecordview-class.md), e é associada a [CTable](../../data/oledb/ctable-class.md) ou [CCommand](../../data/oledb/ccommand-class.md)\- classe derivada.  
  
 **Tipo de cliente**  
 Indica se o projeto usa classes de OLE DB ou ODBC.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**OLE DB**|Quando essa opção é selecionada, clicando no botão de **Fonte de dados** invoca o assistente de **Propriedades de associação de dados** para ajudá\-lo a criar uma conexão com uma fonte de dados OLE DB.|  
|**ODBC**|Quando essa opção é selecionada, clicando no botão de **Fonte de dados** invoca o assistente de **Selecionar Fonte de Dados** para ajudá\-lo a criar uma conexão com uma fonte de dados ODBC.|  
  
 **Fonte de dados**  
 Clique no botão de **Fonte de dados** para configurar uma fonte de dados usando o driver ou o provedor e o base de dados especificados.  Se você selecionou OLE DB na opção de **Tipo de cliente** , exibe esse botão a caixa de diálogo de **Propriedades de associação de dados** .  Se você selecionou ODBC na opção de **Tipo de cliente** , esse botão fornece a caixa de diálogo de **Selecionar Fonte de Dados** .  Essa opção estará disponível apenas se você optar por incluir uma exibição de base de dados em seu aplicativo.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Propriedades de associação de dados** \(OLE DB\)|Estabelece a fonte de dados especificada usando o provedor OLE DB especificado.  Você deve especificar o provedor OLE DB, o local dos dados, a fonte de dados, a ID de logon, e \(opcionalmente\) uma senha.  Para obter detalhes nesta caixa de diálogo, consulte **Fonte de dados** em [Assistente do consumidor de ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md).|  
|**Selecionar Fonte de Dados** \(ODBC\)|Estabelece a fonte de dados especificada usando o driver ODBC especificado.  Você deve selecionar um nome da fonte de dados para escolher uma tabela para a fonte de dados.  O assistente associa todas as colunas de tabela para variáveis de `CRecordset`\- classe derivada de membro.  Para obter detalhes nesta caixa de diálogo, consulte **Fonte de dados** em [Assistente do consumidor MFC ODBC](../../mfc/reference/mfc-odbc-consumer-wizard.md).|  
  
> [!NOTE]
>  Em versões anteriores, SHIFT\- clique no botão de **Fonte de dados** abriu uma caixa de diálogo abrir Arquivo para permitir que você selecione um arquivo de vínculo de dados \(.udl\).  Essa funcionalidade não tem mais suporte.  
  
 **Generate attributed database class**  
 Disponível para o cliente OLE DB apenas.  Especifica se as classes de base de dados do projeto gerado usam atributos.  
  
 **Bind all columns**  
 Disponível para o cliente ODBC só.  Especifica se todas as colunas na tabela selecionada estão associadas.  Se você selecionar essa caixa, todas as colunas são associadas; se você não selecionar essa caixa, nenhuma coluna é associada, e é preciso associá\-la manualmente na classe do conjunto de registros.  
  
 **Tipo**  
 Disponível para o cliente ODBC só.  Especifica se o conjunto de registros é um dynaset ou um instantâneo, como descrito na tabela a seguir.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Dynaset**|Especifica que o conjunto de registros é um dynaset.  Um dynaset é o resultado de uma consulta que fornece uma exibição indexada nos dados da base de dados consultado.  Um dynaset armazena em cachê apenas um índice completo aos dados originais e oferece o ganho de desempenho sobre um instantâneo.  Os pontos de índice diretamente para cada registro localizado no resultado de uma consulta e indica se um registro é removido.  Você também tem acesso às informações atualizadas nos registros consultados.|  
|Instantâneo|Especifica que o conjunto de registros é um instantâneo.  Um instantâneo é o resultado de uma consulta e é uma exibição em um base de dados ao certo ponto.  Registra todos localizado no resultado da consulta é armazenado em cachê, para que você não vir nenhuma alteração nos registros originais.|  
  
## Consulte também  
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)