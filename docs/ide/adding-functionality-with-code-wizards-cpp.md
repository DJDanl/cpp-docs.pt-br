---
title: Adicionando funcionalidade com assistentes de código (C++)
ms.date: 10/03/2018
f1_keywords:
- vc.codewiz.classes
helpviewer_keywords:
- code wizards [C++]
- wizards [C++], code
- Visual C++ projects, adding functionality
- projects [C++], adding functionality
- class wizards [C++]
ms.assetid: 6afb7ef9-7056-423d-b244-91bb4236d1d7
ms.openlocfilehash: 87c46be17c20bf9d592dd2b5c537897fa629e9c2
ms.sourcegitcommit: 9e85c2e029d06b4c1c69837437468718b4d54908
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2019
ms.locfileid: "57822568"
---
# <a name="adding-functionality-with-code-wizards-c"></a>Adicionando funcionalidade com assistentes de código (C++)

Depois de criar um projeto, você desejará alterar ou adicionar funcionalidades ao projeto. Essas tarefas incluem criação de classes, adição de novas variáveis e funções de membro e adição de métodos e propriedades de Automação. Os assistentes de código foram projetados para permitir que você faça tudo isso.

> [!WARNING]
> Vários assistentes de código do ATL e do MFC foram preteridos e serão removidos em uma versão futura do Visual Studio. Esses assistentes são usados raramente. O suporte geral para ATL e MFC não é afetado pela remoção desses assistentes. Se você quiser compartilhar seus comentários sobre essa alteração, participe [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Seus comentários são importantes para nós.

> [!NOTE]
>  Agora você pode adicionar manipuladores de mensagens e mapear as mensagens para eles e substituir funções virtuais MFC usando a [janela Propriedades](/visualstudio/ide/reference/properties-window).

## <a name="accessing-visual-c-code-wizards"></a>Acessando os assistentes de código do Visual C++

Há três locais em que você pode acessar os assistentes de código do Visual C++:

- No menu **Projeto**, o comando **Adicionar Novo Item** permite que você abra a caixa de diálogo `Add New Item`, que ajuda você a adicionar novos arquivos ao projeto. O comando **Adicionar Classe** exibe a caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md), que, por sua vez, abre assistentes para cada um dos tipos de classe que podem ser adicionados ao projeto. O comando **Adicionar Recurso** exibe a caixa de diálogo [Adicionar Recurso](../windows/add-resource-dialog-box.md), na qual você pode criar ou selecionar um recurso a ser adicionado ao projeto.

   Se você realçar uma classe ou uma interface no projeto em Modo de Exibição de Classe, o menu **Projeto** também exibirá os seguintes comandos:

   - **Implementar Interface** (somente em uma classe de controle)

   - **Adicionar Função**

   - **Adicionar Variável**

   - **Adicionar Ponto de Conexão** (somente classe ATL)

   - **Adicionar Método** (somente em uma interface)

   - **Adicionar Propriedade** (somente em uma interface)

   - **Adicionar Evento** (somente em uma classe de controle)

- No **Gerenciador de Soluções**, se você clicar com o botão direito do mouse em qualquer pasta e clicar em **Adicionar** no menu de atalho, poderá adicionar arquivos novos ou existentes, mais pastas, itens, classes, recursos e referências Web ao projeto.

- Na [janela Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), se você clicar com o botão direito do mouse no nó apropriado e clicar em **Adicionar** no menu de atalho, poderá adicionar funções, variáveis, classes, propriedades, métodos, eventos, interfaces, pontos de conexão ou outro código ao projeto.

   > [!NOTE]
   > O Visual Studio não fornece um assistente para adicionar uma interface a um projeto. Adicione uma interface a um projeto ATL ou a um [Adicionando Suporte para ATL ao Projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) com a adição de um objeto simples usando o [Assistente de Objeto ATL Simples](../atl/reference/atl-simple-object-wizard.md). Como alternativa, abra o arquivo .idl do projeto e crie a interface digitando:

    ```IDL
    interface IMyInterface {
    };
    ```

   Confira [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md) e [Adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.

   |Acessar o assistente de código em|Descrição|
   |-----------------------------|-----------------|
   |Adicionar Novo Item|Os assistentes de código de Adicionar Novo Item adicionam arquivos de origem ao projeto. Se necessário, diretórios adicionais serão criados para conter os arquivos quando o mecanismo de build do projeto esperar encontrá-los. Os assistentes de código disponíveis no ícone Adicionar Item incluem:<br /><br />- Adicionar arquivos de origem do C++ (.cpp, .h, .idl, .rc, .srf, .def, .rgs).<br />- Adicionar arquivos de desenvolvimento para a Web (.html, .asp, .css, .xml).<br />- Adicionar arquivos de utilitário e de recurso (.bmp, .cur, .ico, .rct, .sql, .txt).<br /><br />Em geral, esses assistentes de código não solicitam informações, mas adicionam um arquivo à árvore de desenvolvimento. Você pode renomear o arquivo na janela de propriedades.|
   |Gerenciador de Soluções|Os assistentes de código disponíveis no Gerenciador de Soluções dependem do local em que o foco do cursor está quando você clica com o botão direito do mouse em um item. Se a opção **Adicionar** não for exibida quando você clicar com o botão direito do mouse em um item, mova o cursor para um nível acima na árvore de desenvolvimento e tente novamente. Os assistentes de código sempre colocarão o código adicional no local apropriado na árvore de desenvolvimento, seja qual for a localização do cursor. Os assistentes de código disponíveis no Gerenciador de Soluções incluem:<br /><br />- Adicionar Classe (abre a caixa de diálogo **Adicionar Classe** que contém os novos assistentes de código).<br />- Adicionar Recurso (Novo, Importar ou Personalizado).<br />- Adicionar Referência Web.|
   |Exibição de Classe|Os assistentes de código disponíveis no Modo de Exibição de Classe dependem do local em que o foco do cursor está quando você clica com o botão direito do mouse em um item. Se a opção **Adicionar** não for exibida quando você clicar com o botão direito do mouse em um item, mova o cursor para um nível acima na árvore de classe e tente novamente. Os assistentes de código sempre colocarão o código adicional no local apropriado na árvore de desenvolvimento, seja qual for a localização do cursor. Os assistentes de código disponíveis no Modo de Exibição de Classe incluem:<br /><br />- [Adicionar Função de Membro](../ide/adding-a-member-function-visual-cpp.md).<br />- [Adicionar Variável de Membro](../ide/adding-a-member-variable-visual-cpp.md).<br />- [Adicionar Classe](../ide/adding-a-class-visual-cpp.md).<br />- [Implementar Interface](../ide/implement-interface-wizard.md) (somente em uma classe de controle)<br />- [Adicionar Ponto de Conexão](../ide/implement-connection-point-wizard.md) (somente classe ATL)<br />- [Adicionar Método](../ide/add-method-wizard.md) (somente em uma interface)<br />- [Adicionar Propriedade](../ide/names-add-property-wizard.md) (somente em uma interface)<br />- [Adicionar Evento](../ide/add-event-wizard.md) (somente em uma classe de controle)<br /><br />A seleção de Adicionar Classe abre a caixa de diálogo **Adicionar Classe**, que fornece acesso a todos os novos assistentes de código de Adicionar Classe.|

## <a name="see-also"></a>Consulte também

[Substituindo uma função virtual](../ide/overriding-a-virtual-function-visual-cpp.md)<br>
[Navegando pela estrutura de classe](../ide/navigating-the-class-structure-visual-cpp.md)<br>
[Tipos de projeto do Visual C++](../build/reference/visual-cpp-project-types.md)<br>
[Tipos de arquivo criados para projetos do Visual C++](../build/reference/file-types-created-for-visual-cpp-projects.md)
