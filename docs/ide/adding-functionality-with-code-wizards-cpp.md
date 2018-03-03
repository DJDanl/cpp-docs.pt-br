---
title: "Adicionando funcionalidade com assistentes de código (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.classes
dev_langs:
- C++
helpviewer_keywords:
- code wizards [C++]
- wizards [C++], code
- Visual C++ projects, adding functionality
- projects [C++], adding functionality
- class wizards [C++]
ms.assetid: 6afb7ef9-7056-423d-b244-91bb4236d1d7
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c27aeb10a58c828b6503ce96ddaadf138c258f27
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="adding-functionality-with-code-wizards-c"></a>Adicionando funcionalidade com assistentes de código (C++)
Depois de criar um projeto, você deve alterar ou adicionar a funcionalidade do projeto. Essas tarefas incluem a criação de novas classes, adicionando novas funções de membro e variáveis e a adição de automação métodos e propriedades. Os assistentes de código são projetados para permitir que você a fazer tudo isso.  
  
> [!NOTE]
>  Agora você pode adicionar manipuladores de mensagens e mapear as mensagens a elas e substituir MFC funções virtuais usando o [janela propriedades](/visualstudio/ide/reference/properties-window).  
  
## <a name="accessing-visual-c-code-wizards"></a>Acessando os assistentes de código do Visual C++  
 Há três locais onde você pode acessar os assistentes de código do Visual C++:  
  
-   No **projeto** menu, o **Adicionar Novo Item** comando permite que você abrir o `Add New Item` caixa de diálogo que ajuda a adicionar novos arquivos ao seu projeto. O **Adicionar classe** comando exibe o [Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo, que por sua vez abrir assistentes para cada classe de tipos que você pode adicionar ao seu projeto. O **adicionar recurso** comando exibe o [adicionar recurso](../windows/add-resource-dialog-box.md) caixa de diálogo, na qual você pode criar ou selecionar um recurso para adicionar ao seu projeto.  
  
     Se você realçar uma classe ou uma interface em seu projeto no modo de exibição de classe, o **projeto** menu também exibe os seguintes comandos:  
  
    -   **Implementar Interface** (de uma controle somente para a classe)  
  
    -   **Adicionar função**  
  
    -   **Adicionar variável**  
  
    -   **Adicionar ponto de Conexão** (somente para a classe ATL)  
  
    -   **O método Add** (de uma interface somente)  
  
    -   **Adicionar propriedade** (de uma interface somente)  
  
    -   **Adicionar evento** (de uma controle somente para a classe)  
  
-   Em **Solution Explorer**, clicando duas vezes qualquer pasta e clicando em **adicionar** partir do atalho menu permite que você adicione arquivos novos ou existentes, mais pastas, itens, classes, recursos e referências da Web para o projeto.  
  
-   Do [janela modo de exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925), clicando duas vezes no nó apropriado e clicando em **adicionar** partir do atalho menu permite que você adicione funções, variáveis, classes, propriedades, métodos, eventos, interfaces, pontos de conexão, ou outro código ao seu projeto.  
  
    > [!NOTE]
    >  O Visual Studio não fornece um Assistente para adicionar uma interface para um projeto. Você pode adicionar uma interface para um projeto de ATL ou para um [adicionar suporte ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) com a adição de um objeto simple usando o [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md). Como alternativa, abra o arquivo do projeto. idl e crie a interface digitando:  
  
    ```  
    interface IMyInterface {  
    };  
  
    ```  
  
     Consulte [implementando uma Interface](../ide/implementing-an-interface-visual-cpp.md) e [adicionando objetos e controles para um projeto de ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.  
  
    |Assistente de código de acesso do|Descrição|  
    |-----------------------------|-----------------|  
    |Adicionar Novo Item|Os assistentes de código Adicionar Novo Item adicionam arquivos de origem ao seu projeto. Se necessário, os diretórios adicionais são criados para conter os arquivos em que o mecanismo de compilação de projeto espera encontrá-los. Assistentes de código disponíveis pelo ícone do Item adicionar incluem:<br /><br /> -Adicione arquivos de origem do C++ (. cpp,. h,. idl, RC,. srf,. def,. rgs).<br />-Adicione arquivos de desenvolvimento da Web (. HTML,. asp,. CSS,. xml).<br />-Adicione o utilitário e arquivos de recursos (. bmp,. cur,. ico,. rct,. SQL,. txt).<br /><br /> Esses assistentes de código geralmente não solicitar para todas as informações, mas adicionar um arquivo para a árvore de desenvolvimento. Você pode renomear o arquivo na janela Propriedades.|  
    |Gerenciador de Soluções|Os assistentes de código disponíveis no Gerenciador de soluções dependem de onde o foco do cursor é um item de contexto. Se o **adicionar** opção não será exibida quando você clica um item, em seguida, mova o cursor um nível acima na árvore de desenvolvimento e tente novamente. Os assistentes de código sempre colocar o código adicional no local adequado na árvore de desenvolvimento, não importa onde está o cursor. Assistentes de código disponíveis no Gerenciador de soluções incluem:<br /><br /> -Adicionar classe (abre o **Adicionar classe** caixa de diálogo que contém os novos assistentes de código).<br />-Adicionar o recurso (novos e importação ou personalizado).<br />-Adicione referência da Web.|  
    |Exibição de Classe|Os assistentes de código disponíveis no modo de exibição de classe dependem de onde o foco do cursor é quando o botão direito em um item. Se o **adicionar** opção não será exibida quando o botão direito em um item, em seguida, mova o cursor um nível acima na árvore de classe e tente novamente. Os assistentes de código sempre colocar o código adicional no local adequado na árvore de desenvolvimento, não importa onde está o cursor. Assistentes de código disponíveis no modo de exibição de classe incluem:<br /><br /> -   [Adicionar função de membro](../ide/adding-a-member-function-visual-cpp.md).<br />-   [Adicione a variável de membro](../ide/adding-a-member-variable-visual-cpp.md).<br />-   [Adicionar classe](../ide/adding-a-class-visual-cpp.md).<br />-   [Implementar Interface](../ide/implement-interface-wizard.md) (de uma controle somente para a classe)<br />-   [Adicionar ponto de Conexão](../ide/implement-connection-point-wizard.md) (somente para a classe ATL)<br />-   [O método Add](../ide/add-method-wizard.md) (de uma interface somente)<br />-   [Adicionar propriedade](../ide/names-add-property-wizard.md) (de uma interface somente)<br />-   [Adicionar evento](../ide/add-event-wizard.md) (de uma controle somente para a classe)<br /><br /> A seleção de Adicionar classe abre o **Adicionar classe** caixa de diálogo que fornece acesso a todos os novos Adicionar classe assistentes de código.|  
  
## <a name="see-also"></a>Consulte também  
 [Substituindo uma função Virtual](../ide/overriding-a-virtual-function-visual-cpp.md)   
 [Navegando na estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)   
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)   
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)