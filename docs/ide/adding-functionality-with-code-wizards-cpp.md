---
title: "Adicionando funcionalidade com assistentes de c&#243;digo | Microsoft Docs"
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
  - "vc.codewiz.classes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assistentes de classe [C++]"
  - "assistentes de código [C++]"
  - "projetos [C++], adicionando funcionalidade"
  - "Projetos Visual C++, adicionando funcionalidade"
  - "assistentes [C++], código"
ms.assetid: 6afb7ef9-7056-423d-b244-91bb4236d1d7
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando funcionalidade com assistentes de c&#243;digo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois de criar um projeto, você vai querer alterar ou adicionar a funcionalidade desse projeto.  Essas tarefas incluem a criação de novas classes, adicionando novas funções de membro e variáveis e a adição de automação métodos e propriedades.  Os assistentes de código são projetados para permitir que você faça tudo isso.  
  
> [!NOTE]
>  Agora você pode adicionar manipuladores de mensagens e mapear mensagens a eles e substituir funções virtuais do MFC usando o  [janela Propriedades do](../Topic/Properties%20Window.md).  
  
## Acessando os assistentes do Visual C\+\+ de código  
 Há três locais onde você pode acessar os assistentes de código do Visual C\+\+:  
  
-   Sobre o  **projeto** menu, o  **Add New Item** comando permite que você exibir o `Add New Item` caixa de diálogo que ajuda você a adicionar novos arquivos ao seu projeto.  O  **Add Class** comando exibe o  [Add Class](../ide/add-class-dialog-box.md) caixa de diálogo que abrir por sua vez assistentes para cada da classe tipos que você pode adicionar ao seu projeto.  O  **Add Resource** comando exibe o  [Add Resource](../Topic/Add%20Resource%20Dialog%20Box.md) caixa de diálogo, a partir do qual você pode criar ou selecionar um recurso para adicionar ao seu projeto.  
  
     Se você realçar uma classe ou uma interface em seu projeto no modo de exibição de classe, o  **projeto** menu exibe também os seguintes comandos:  
  
    -   **Implementar a Interface** \(a partir de uma classe de controle apenas\)  
  
    -   **Adicionar função**  
  
    -   **Adicionar variável**  
  
    -   **Adicionar ponto de conexão** \(somente para a classe ATL\)  
  
    -   **O método Add** \(a partir de uma interface somente\)  
  
    -   **Adicionar propriedade de** \(a partir de uma interface somente\)  
  
    -   **Adicionar evento** \(a partir de uma classe de controle apenas\)  
  
-   Em  **Solution Explorer**, o direito do mouse em qualquer pasta e em  **Add** partir do atalho menu permite que você adicionar arquivos novos ou existentes, mais pastas, itens, classes, recursos e referências ao projeto de Web.  
  
-   Do  [janela Class View](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clicando com o botão direito no nó apropriado e em  **Add** partir do atalho menu permite que você adicionar funções, variáveis, classes, propriedades, métodos, eventos, interfaces, pontos de conexão ou outro código ao seu projeto.  
  
    > [!NOTE]
    >  Visual Studio não fornece um Assistente para adicionar uma interface para um projeto.  Você pode adicionar uma interface para um projeto do ATL ou para um  [Adicionando o suporte ATL ao seu projeto de MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) , adicionando um objeto simples usando o  [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md).  Como alternativa, abra o arquivo do projeto. idl e criar a interface digitando:  
  
    ```  
    interface IMyInterface {  
    };  
  
    ```  
  
     Consulte  [implementação de uma Interface](../ide/implementing-an-interface-visual-cpp.md) e  [adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.  
  
    |Assistente de código de acesso do|Descrição|  
    |---------------------------------------|---------------|  
    |Adicionar novo item|Os assistentes de código de Add New Item adicionar arquivos de origem ao seu projeto.  Se necessário, os diretórios adicionais são criados para conter os arquivos em que o mecanismo de compilação do projeto espera encontrá\-los.  Os assistentes de código disponíveis no ícone Add Item incluem:<br /><br /> -   Adicione arquivos de origem do C\+\+ \(CPP,. h,. idl,. rc,. srf,. def,. rgs\).<br />-   Adicione arquivos de desenvolvimento da Web \(. HTML,. asp,. css,. xml\).<br />-   Adicione arquivos do utilitário e de recursos \(. bmp,. cur,. ico,. rct,. SQL,. txt\).<br /><br /> Geralmente, esses assistentes de código não solicitar qualquer informação mas adicionar um arquivo à sua árvore de desenvolvimento.  Você pode renomear o arquivo na janela de propriedade.|  
    |Gerenciador de SoluÃ§Ãµes|Os assistentes de código disponíveis no Solution Explorer dependem de onde o foco do cursor é quando o botão direito do mouse um item.  Se o  **Add** opção não aparece quando você clica um item, mova o cursor um nível acima na árvore de desenvolvimento e tente novamente.  Os assistentes de código sempre coloque o código adicional no local adequado na árvore de desenvolvimento, não importa onde o cursor estiver.  Os assistentes de código disponíveis no Solution Explorer incluem:<br /><br /> -   Adicionar classe \(abre o  **Add Class** caixa de diálogo contém os novos assistentes de código\).<br />-   Adicionar recurso \(novos, importação ou personalizado\).<br />-   Adicione referência da Web.|  
    |Modo de Exibição de Classe|Os assistentes de código disponíveis no modo de exibição de classe dependem de onde o foco do cursor é quando o botão direito do mouse clicar em um item.  Se o  **Add** opção não aparece quando o botão direito do mouse clicar em um item, mova o cursor um nível acima na árvore de classe e tente novamente.  Os assistentes de código sempre coloque o código adicional no local adequado na árvore de desenvolvimento, não importa onde o cursor estiver.  Os assistentes de código disponíveis no modo de exibição de classe incluem:<br /><br /> -   [Adicionar a função de membro](../ide/adding-a-member-function-visual-cpp.md).<br />-   [Adicionar a variável de membro](../ide/adding-a-member-variable-visual-cpp.md).<br />-   [Adicionar classe](../Topic/Adding%20a%20Class%20\(Visual%20C++\).md).<br />-   [Implementar a Interface](../Topic/Implement%20Interface%20Wizard.md) \(a partir de uma classe de controle apenas\)<br />-   [Adicionar ponto de conexão](../ide/implement-connection-point-wizard.md) \(somente para a classe ATL\)<br />-   [O método Add](../ide/add-method-wizard.md) \(a partir de uma interface somente\)<br />-   [Adicionar propriedade de](../ide/names-add-property-wizard.md) \(a partir de uma interface somente\)<br />-   [Adicionar evento](../ide/add-event-wizard.md) \(a partir de uma classe de controle apenas\)<br /><br /> A seleção de Add Class abre o  **Add Class** caixa de diálogo que fornece acesso a todos os novos Add Class código assistentes.|  
  
## Consulte também  
 [Substituindo uma função virtual](../Topic/Overriding%20a%20Virtual%20Function%20\(Visual%20C++\).md)   
 [Navegando na estrutura da classe](../ide/navigating-the-class-structure-visual-cpp.md)   
 [Criando projetos para desktop com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Tipos de projeto do Visual C\+\+](../ide/visual-cpp-project-types.md)   
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)