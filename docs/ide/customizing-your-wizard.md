---
title: "Personalizando o assistente | Microsoft Docs"
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
  - "assistentes personalizados"
  - "assistentes personalizados, criando em projetos do Visual C++"
ms.assetid: a3ff1c81-3eef-41e7-a6bc-2f98e4bf423f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Personalizando o assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você deve considerar as seguintes tarefas comuns, como você personalizar o assistente que você criou com o  [Assistente personalizada](../Topic/Application%20Settings,%20Custom%20Wizard.md).  
  
-   No arquivo vsz, especifique os parâmetros personalizados necessários para seu assistente funcione.  Consulte  [O vsz \(projeto de controle\) do arquivo](../ide/dot-vsz-file-project-control.md) e  [Predefinidos símbolos de assistente personalizada](../ide/custom-parameters-in-the-wizard-dot-vsz-file.md) para obter mais informações.  
  
     Se você localizar o Assistente para vários idiomas, adicione esses parâmetros de idioma no arquivo vsz.  Consulte  [a localização de um Assistente para vários idiomas](../ide/localizing-a-wizard-to-multiple-languages.md) para obter mais informações.  
  
-   Personalizar o  [arquivos de modelo](../ide/template-files.md) \(e  [Templates.inf](../Topic/Templates.inf%20File.md)\) para especificar as diretivas para seleções do usuário.  
  
-   Personalizar o  [arquivo default. js](../ide/jscript-file.md) para especificar um tratamento especial adicional para seu assistente.  Você pode escrever suas próprias funções, e você pode usar funções oferecidas por  [Common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md).  
  
-   Ícones de design e outras imagens que usará a interface do usuário HTML.  
  
-   Projete a interface do usuário HTML.  
  
-   Adicione símbolos para a tabela de símbolos HTML para coincidir com os botões, controles, caixas de texto e outros elementos que usa o seu assistente.  
  
     A seguir mostra um excerto do HTML fornecido pelo assistente personalizada:  
  
    ```  
    <SYMBOL NAME="WIZARD_DIALOG_TITLE" TYPE=text VALUE="MyCustomWiz">  
          </SYMBOL>  
    <SYMBOL NAME="SAMPLE_CHECKBOX" TYPE=checkbox VALUE=true>  
          </SYMBOL>  
    ```  
  
     Este assistente, intitulado MyCustomWiz, exibe uma caixa de seleção é selecionada por padrão.  
  
-   Na seção marcada como `<SCRIPT LANGUAGE="JSCRIPT">` em arquivos HTML, adicionar chamadas de função JScript e acessar o modelo de objeto Visual Studio para personalizar o comportamento do seu assistente.  Você deve chamar essas funções usando `window.external`, da seguinte forma:  
  
    ```  
    window.external.AddSymbol("MAIN_FRAME_DEFAULT_STYLES", true);  
    window.external.AddSymbol("MAIN_FRAME_STYLE_FLAGS", "");  
    ```  
  
    > [!NOTE]
    >  Os métodos, propriedades e eventos expostos por meio de [Automation and Extensibility for Visual Studio](../Topic/Automation%20and%20Extensibility%20for%20Visual%20Studio.md),  [Modelo de código do Visual C\+\+](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b),  [O modelo de projeto](http://msdn.microsoft.com/pt-br/06c1bbd9-4c79-4f97-ad6d-2b1dea8ecd1f), e  [Assistente de modelo](http://msdn.microsoft.com/pt-br/159395ac-33c7-47bf-ad42-4e1435ddc758) permitem gerenciar programaticamente a todos os aspectos do projeto do assistente, desde a criação até a compilação, tanto no JScript de JScript como arquivos. htm.  
  
-   Se necessário, personalize o  [o arquivo de .vsdir](../Topic/Adding%20Wizards%20to%20the%20Add%20Item%20and%20New%20Project%20Dialog%20Boxes%20by%20Using%20.Vsdir%20Files.md), permitindo que as informações sobre o arquivo vsz e todos os outros modelos ser entendidas pelo shell.  Por exemplo, indicar que a identificação de recurso de ícone, sinalizadores, localizadas nomes e assim por diante.  
  
-   Crie arquivos. htm e arquivos de modelo em todos os idiomas para os quais seu assistente deve ser localizada.  Para adicioná\-los para os diretórios do projeto apropriado.  
  
-   [Fornecer ajuda contextual](../ide/providing-context-sensitive-help.md) do assistente.  
  
## Consulte também  
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Etapas para projetar um assistente](../ide/steps-to-designing-a-wizard.md)   
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Fornecendo ajuda contextual](../ide/providing-context-sensitive-help.md)   
 [Identificando erros em assistentes](../ide/handling-errors-in-wizards.md)