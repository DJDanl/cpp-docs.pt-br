---
title: "Arquivos HTML | Microsoft Docs"
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
  - "assistentes personalizados, arquivos HTML"
  - "assistentes personalizados, interface do usuário"
  - "Arquivos  [C++], criado por Assistente Personalizado"
  - "Páginas HTML, interface do usuário para assistentes personalizados"
  - "interface do usuário para assistentes"
  - "assistentes [C++], interface do usuário para assistentes personalizados"
ms.assetid: 3b6ed080-6560-418b-b908-d84d71bdf145
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Arquivos HTML
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um assistente pode conter uma interface de usuário, que é uma interface HTML.  Juntamente com o default. htm, um assistente pode conter qualquer número de arquivos. htm, que é possível indicar no  **Número de páginas** caixa no  [Assistente personalizada](../ide/custom-wizard.md).  Cada arquivo. htm representa uma página HTML de seu assistente e a página HTML é acessível usando `Next` e  **novamente** botões, guias ou qualquer outro formato que você especifica em seu design do assistente.  
  
 O HTML contém:  
  
-   A marca de SÍMBOLO que identifica o padrão para opções definidas pelo usuário.  Símbolos são gravados na tabela de símbolos quando o usuário clica  **Concluir**, tais como:  
  
```  
<SYMBOL NAME='HEADER_FILE' VALUE='MyHeader.h' TYPE=text></SYMBOL>  
```  
  
 Na interface de usuário do assistente \(UI\), a caixa de texto identificada na tabela de símbolos, como "HEADER\_FILE" contém o texto padrão "MyHeader.h".  Você pode alterar esse valor no Assistente de interface do usuário, e o valor resultante é gravado para a tabela de símbolos do projeto, quando você clica em  **Concluir**, tais como:  
  
```  
<SYMBOL NAME='CHECKBOX1' TYPE=checkbox VALUE=false></SYMBOL>  
```  
  
 No Assistente de interface do usuário, a caixa de seleção identificada na tabela de símbolos, como "CHECKBOX1" está desmarcada por padrão.  Você pode marcar essa caixa na interface de usuário HTML e o valor resultante é gravado para a tabela de símbolos, quando você clica em  **Concluir**.  
  
 Cada arquivo. htm registra as seleções do usuário para a tabela de símbolos.  
  
-   Um inclusão para  [Common.js](../ide/customizing-cpp-wizards-with-common-jscript-functions.md), que contém comumente usados e úteis funções JScript e default. js.  
  
-   Referências a imagens do projeto para exibir em HTML.  
  
-   Texto em HTML e a formatação que personalizar a aparência da interface do usuário do Assistente  
  
-   Funções de JScript que acessar o modelo de objeto Assistente Visual C\+\+ para fornecer um comportamento personalizado do assistente.  Essas funções estão na seção da página HTML pontas \< SCRIPT LANGUAGE \= 'JSCRIPT' \>, conforme mostrado no exemplo a seguir.  
  
    > [!NOTE]
    >  Para acessar o assistente e modelos de objeto do ambiente de HTML, prepend o item de modelo de objeto com "Window. External".  
  
    ```  
    function InitDocument(document)  
    {  
       setDirection();  
  
       if (window.external.FindSymbol('DOCUMENT_FIRST_LOAD'))  
       {  
          // This function sets the default symbols based   
          // on the values specified in the SYMBOL tags above  
          //  
          window.external.SetDefaults(document);  
       }  
  
       // Load the document and initialize the controls   
       // with the appropriate symbol values  
       //  
       window.external.Load(document);  
    }  
    ```  
  
 Este é um Assistente de aplicativo do console de amostra:  
  
```  
<SYMBOL NAME='WIZARD_DIALOG_TITLE' TYPE=text VALUE='Console Application Wizard'></SYMBOL>  
  
<SYMBOL NAME='EMPTY_PROJECT' TYPE=checkbox VALUE=false></SYMBOL>  
<SYMBOL NAME='SUPPORT_ATL' TYPE=checkbox VALUE=false></SYMBOL>  
<SYMBOL NAME='SUPPORT_MFC' TYPE=checkbox VALUE=false></SYMBOL>  
```  
  
## Consulte também  
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)