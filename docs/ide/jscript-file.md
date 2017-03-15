---
title: "Arquivo JScript | Microsoft Docs"
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
  - "Método AddConfig"
  - "Método AddFilesToCustomProj"
  - "Método AddFilters"
  - "Arquivo Common.js"
  - "Método CreateCustomInfFile"
  - "Método CreateCustomProject"
  - "assistentes personalizados, acessando modelo de objeto de assistente"
  - "assistentes personalizados, Arquivo JScript"
  - "depuração [JScript], habilitando a depuração de script"
  - "depuração [JScript], Arquivos JScript"
  - "depurando script"
  - "depurando script, habilitando a depuração de script"
  - "Arquivo Default.js"
  - "Método DelFile"
  - "Arquivos  [C++], criado por Assistente Personalizado"
  - "Método GetTargetName"
  - "Arquivos JScript"
  - "Método OnFinish"
  - "Método PchSettings"
ms.assetid: 7841a09e-2dd2-4f1a-a13a-39ac53f24315
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivo JScript
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O  [Assistente personalizada](../ide/custom-wizard.md) acessa o mecanismo de script e cria um arquivo de JScript chamado Default. js para cada projeto.  Ele também inclui  [Common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md).  Esses arquivos contêm as funções de JScript que fornecem acesso aos modelos de objeto de Visual Studio e Visual C\+\+ para personalizar um assistente.  \(Consulte  [projetar um assistente](../ide/designing-a-wizard.md) para obter uma lista desses modelos.\) Você pode adicionar suas próprias funções para o Assistente para arquivo do projeto default. js.  Para acessar propriedades e métodos no modelo de objeto do assistente ou o modelo de ambiente em um arquivo de JScript, prepend o item de modelo de objeto com o "Assistente." e "dte.", respectivamente.  
  
 Por exemplo:  
  
```  
function CreateCustomProject(strProjectName, strProjectPath)  
{  
   try  
   {  
      var strProjTemplatePath = wizard.FindSymbol('PROJECT_TEMPLATE_PATH');  
var strProjTemplate = '';  
      strProjTemplate = strProjTemplatePath + '\\default.vcproj';  
  
      var Solution = dte.Solution;  
      var strSolutionName = "";  
      if (wizard.FindSymbol("CLOSE_SOLUTION"))  
...  
```  
  
 Quando você clica em  **Concluir** na  [Assistente personalizada](../ide/custom-wizard.md), o assistente carrega o arquivo default. js na pasta arquivos de Script no Solution Explorer.  Este arquivo de JScript cria projetos e processa os modelos e os adiciona à solução quando um usuário clica em  **Concluir** em seu assistente.  
  
 Por padrão, o arquivo do projeto default. js inclui as seguintes funções:  
  
|Nome da função|Descrição|  
|--------------------|---------------|  
|**AddConfig**|Adiciona as configurações do projeto.  Você pode fornecer as configurações do compilador e vinculador.|  
|**AddFilesToCustomProj**|Quando o usuário clica  **Concluir**, adiciona os arquivos especificados para o projeto.|  
|**AddFilters**|Quando o usuário clica  **Concluir**, adiciona os filtros de origem especificado para o projeto.|  
|**CreateCustomProject**|Quando o usuário clica  **Concluir**, o projeto é criado no local especificado.|  
|**CreateCustomInfFile**|Cria o projeto  [arquivo de Templates.inf](../Topic/Templates.inf%20File.md).|  
|**DelFile**|Exclui o arquivo especificado.|  
|**GetTargetName**|Obter o nome do arquivo especificado.|  
|**OnFinish**|Chamado pelo assistente, quando o usuário clica  **Concluir** para criar o projeto, adicionar arquivos e filtros, processar modelos e definir a configuração.|  
|**PchSettings**|Define as configurações de cabeçalho pré\-compilado.  Consulte  [SetCommonPchSettings](../ide/setcommonpchsettings.md) na referência de Common.js para obter mais informações.|  
  
 Cada assistente tem um arquivo default. js exclusivo, o que inclui comentários TODO para ajudá\-lo a identificar onde você deve personalizar o arquivo.  
  
 O Visual C\+\+ também inclui  [Common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md), um arquivo compartilhado entre todos os assistentes e incluídos no seu projeto do assistente.  Você pode utilizar as funções em Common.js.  
  
> [!NOTE]
>  Common.js contém descrições de cada função e seus parâmetros.  Consulte os comentários em Common.js para obter mais informações.  
  
 Se você possui funções que você deseja compartilhar entre seus projetos do assistente, você pode adicioná\-los para Common.js.  Criar sua própria versão do Common.js e salve\-o em um caminho comum e em seguida, defina o SCRIPT\_COMMON\_PATH para esse caminho no seu  [arquivo vsz](../ide/dot-vsz-file-project-control.md).  
  
> [!NOTE]
>  Os assistentes incluídos com o Visual C\+\+ utilizar as funções de JScript em Common.js.  Se você alterar essas funções, os assistentes do Visual C\+\+ podem comportar\-se inesperadamente.  
  
 Para obter mais informações sobre JScript, consulte [Writing, Compiling, and Debugging JScript Code](http://msdn.microsoft.com/pt-br/13e57e7d-4867-4555-b9e4-fc24aa75e628).  
  
## Depuração de Script  
 Para depurar um script em arquivos de html do assistente, você deve ativar a depuração de script.  
  
#### Para habilitar a depuração de script  
  
1.  No Internet Explorer, clique na  **Ferramentas** menu e escolha  **Opções da Internet**.  
  
2.  Clique na guia **Avançado**.  
  
3.  Sob o  **a navegação** categoria, limpar o  **Desativar depuração de scripts** caixa de seleção.  
  
 Isso também permitirá que o common.js e default. js aparecerão na  **Running Documents** janela quando você clica no botão Concluir o assistente.  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)