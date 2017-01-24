---
title: "Etapas para projetar um assistente | Microsoft Docs"
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
  - "assistentes personalizados, criando"
ms.assetid: dc22746b-99e3-4569-a8b4-b3d7cbabf8f2
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Etapas para projetar um assistente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar um Assistente para criar e configurar os arquivos de inicialização de projeto comum.  Como qualquer projeto, criando um assistente exige planejamento.  As etapas a seguir descrevem uma maneira de se familiarizar com o assistente personalizado do Visual C\+\+ e aplicá\-lo para seus próprios projetos.  
  
1.  Examine o  [amostras de assistente personalizado](http://msdn.microsoft.com/pt-br/6afa2143-062c-4a68-81ca-66cbf4b95261) incluído com o Visual Studio.  
  
2.  O fundamento para o tipo de projeto, que o assistente deve criar.  Como a construção de todos os aplicativos, esse processo pode ir através de mãos muitas e muitas iterações diferentes.  
  
3.  Crie seu projeto com o Visual C\+\+  [Assistente personalizada](../ide/creating-a-custom-wizard.md), a especificação de interface do usuário e opções de número de página.  
  
    > [!NOTE]
    >  Se você indicar sem interface do usuário \(ou seja, se você desmarcar  **interface do usuário**  na  [configurações de aplicativo, o assistente personalizado](../Topic/Application%20Settings,%20Custom%20Wizard.md) do assistente personalizada\), seu assistente define o parâmetro personalizado WIZARD\_UI \=**FALSE** e cria arquivos de modelo de projeto com nenhuma entrada do usuário e nenhum arquivo. htm.  Como resultado, você não especifica números de página.  Consulte  [O vsz \(projeto de controle\) do arquivo](../ide/dot-vsz-file-project-control.md) para obter mais informações.  
  
4.  [Examine o projeto básico](../ide/examining-the-basic-wizard-project.md) que o assistente personalizada criada para você.  
  
5.  Se seu assistente tem uma interface de usuário, execute o Assistente para  [saber mais sobre a mecânica do assistente personalizado](../Topic/Examining%20the%20Mechanics%20of%20a%20Wizard.md).  
  
6.  [Personalizar o assistente básico](../ide/customizing-your-wizard.md).  
  
7.  [Adicionar Ajuda contextual](../ide/providing-context-sensitive-help.md).  
  
8.  [Fornecer tratamento de erros](../ide/handling-errors-in-wizards.md) para o código de JScript e HTML.  
  
9. Compilar e testar o assistente.  
  
10. Depure seu assistente.  Consulte  [depuração de scripts e aplicativos da Web](../Topic/Debugging%20Web%20Applications%20and%20Script.md) para obter mais informações.  
  
    > [!NOTE]
    >  Quando você está depurando JScript, você não pode executar a depuração de modo misto com código nativo.  
  
## Consulte também  
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Assistente Personalizado](../ide/custom-wizard.md)   
 [Arquivos criados para o assistente](../ide/files-created-for-your-wizard.md)