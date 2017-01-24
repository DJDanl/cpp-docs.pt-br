---
title: "Classe de CCommandLineInfo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CCommandLineInfo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "sinalizadores de aplicativo [C++]"
  - "argumento de argv"
  - "Classe de CCommandLineInfo"
  - "linha de comando, analisando"
  - "analisando, argumentos da linha de comando"
  - "código de inicialização, argumentos de linha de comando de análise"
ms.assetid: 3e313ddb-0a82-4991-87ac-a27feff4668c
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCommandLineInfo
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Auxílios em analisar a linha de comando na inicialização do aplicativo.  
  
## Sintaxe  
  
```  
class CCommandLineInfo : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCommandLineInfo::CCommandLineInfo](../Topic/CCommandLineInfo::CCommandLineInfo.md)|Constrói um objeto padrão de `CCommandLineInfo` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCommandLineInfo::ParseParam](../Topic/CCommandLineInfo::ParseParam.md)|Substitua esse retorno de chamada para analisar parâmetros individuais.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCommandLineInfo::m\_bRunAutomated](../Topic/CCommandLineInfo::m_bRunAutomated.md)|Indica que a opção de **\/Automation** de linha de comando foi encontrada.|  
|[CCommandLineInfo::m\_bRunEmbedded](../Topic/CCommandLineInfo::m_bRunEmbedded.md)|Indica que a opção de **\/Embedding** de linha de comando foi encontrada.|  
|[CCommandLineInfo::m\_bShowSplash](../Topic/CCommandLineInfo::m_bShowSplash.md)|Indica se uma tela inicial é exibida.|  
|[CCommandLineInfo::m\_nShellCommand](../Topic/CCommandLineInfo::m_nShellCommand.md)|Indica o comando do shell ser processado.|  
|[CCommandLineInfo::m\_strDriverName](../Topic/CCommandLineInfo::m_strDriverName.md)|Indica o nome do driver se o comando do shell é a cópia; se não vazio.|  
|[CCommandLineInfo::m\_strFileName](../Topic/CCommandLineInfo::m_strFileName.md)|Indica o nome de arquivo a ser aberto ou impresso; vazia se o comando do shell é novo ou DDE.|  
|[CCommandLineInfo::m\_strPortName](../Topic/CCommandLineInfo::m_strPortName.md)|Indica o nome da porta se o comando do shell é a cópia; se não vazio.|  
|[CCommandLineInfo::m\_strPrinterName](../Topic/CCommandLineInfo::m_strPrinterName.md)|Indica o nome de impressora se o comando do shell é a cópia; se não vazio.|  
|[CCommandLineInfo::m\_strRestartIdentifier](../Topic/CCommandLineInfo::m_strRestartIdentifier.md)|Indica o identificador exclusivo de configuração para o gerenciador de reinicialização se o gerenciador de reiniciar o aplicativo foi reiniciado.|  
  
## Comentários  
 Um aplicativo MFC normalmente irá criar uma instância local de essa classe na função de [InitInstance](../Topic/CWinApp::InitInstance.md) do seu objeto do aplicativo.  Este objeto é então passado a [CWinApp::ParseCommandLine](../Topic/CWinApp::ParseCommandLine.md), que chama repetidamente [ParseParam](../Topic/CCommandLineInfo::ParseParam.md) para preencher o objeto de `CCommandLineInfo` .  O objeto de `CCommandLineInfo` é então passado a [CWinApp::ProcessShellCommand](../Topic/CWinApp::ProcessShellCommand.md) para manipular os argumentos de linha de comando e sinalizadores.  
  
 Você pode usar esse objeto para encapsular as seguintes opções de linha de comando e parâmetros:  
  
|Argumento de linha de comando|Comando executado|  
|-----------------------------------|-----------------------|  
|*app*|Novo arquivo.|  
|Nome de arquivo*de app*|Arquivo aberto.|  
|Nome de arquivo**\/p***de app*|Arquivo de impressão para a impressora padrão.|  
|Porta do driver de impressora de nome de arquivo**\/pt***de app*|Arquivo de impressão para a impressora especificada.|  
|*app* **\/dde**|Inicie acima e espere o comando de DDE.|  
|*app* **\/Automation**|Inicie anterior como um servidor OLE de automação.|  
|*app* **\/Embedding**|Edição de Início até um item OLE inserido.|  
|*app* **\/Register**<br /><br /> *app* **\/Regserver**|Informa o aplicativo executar as tarefas do registro.|  
|*app* **\/Unregister**<br /><br /> *app* **\/Unregserver**|Informa o aplicativo executar as tarefas de un\- registro.|  
  
 Derive uma nova classe de `CCommandLineInfo` para manipular outros sinalizadores e valores de parâmetro.  Substituição [ParseParam](../Topic/CCommandLineInfo::ParseParam.md) para manipular os novos sinalizadores.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CCommandLineInfo`  
  
## Requisitos  
 **Cabeçalho:** afxwin.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [CWinApp::ParseCommandLine](../Topic/CWinApp::ParseCommandLine.md)   
 [CWinApp::ProcessShellCommand](../Topic/CWinApp::ProcessShellCommand.md)