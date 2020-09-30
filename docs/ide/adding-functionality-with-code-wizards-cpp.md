---
title: Adicionando funcionalidade com assistentes de código (C++)
ms.date: 05/14/2019
helpviewer_keywords:
- code wizards [C++]
ms.assetid: 6afb7ef9-7056-423d-b244-91bb4236d1d7
ms.openlocfilehash: 651eac8c630636455dd1ffa04fdd02b71fa3cf62
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509705"
---
# <a name="adding-functionality-with-code-wizards-c"></a>Adicionando funcionalidade com assistentes de código (C++)

Depois de criar um projeto, você desejará alterar ou adicionar funcionalidades ao projeto. Essas tarefas incluem criação de classes, adição de novas variáveis e funções de membro e adição de métodos e propriedades de Automação. Os assistentes de código foram projetados para permitir que você faça tudo isso.

> [!NOTE]
> Os assistentes de código raramente usados a seguir são removidos no Visual Studio 2019. O suporte geral para ATL e MFC não é afetado pela remoção desses assistentes. O código de exemplo para essas tecnologias está arquivado em Microsoft Docs e no repositório GitHub VCSamples.

- Assistente de componente de COM+ 1.0 da ATL
- Assistente do componente Active Server Page da ATL
- Assistente de provedor OLE DB da ATL
- Assistente de página de propriedades da ATL
- Assistente de consumidor OLE DB da ATL
- Consumidor ODBC do MFC
- Classe MFC em Controle ActiveX
- Classe MFC em TypeLib.

> [!NOTE]
> Você pode adicionar manipuladores de mensagens e mapear mensagens para eles e substituir funções virtuais do MFC usando o [Assistente de classe do MFC](../mfc/reference/mfc-class-wizard.md).

## <a name="accessing-c-code-wizards"></a>Como acessar assistentes de código do C++

Há três locais em que você pode acessar os assistentes de código do C++:

- No menu **Projeto**, o comando **Adicionar Novo Item** permite que você abra a caixa de diálogo `Add New Item`, que ajuda você a adicionar novos arquivos ao projeto. O comando **Adicionar Classe** exibe a caixa de diálogo [Adicionar Classe](./adding-a-class-visual-cpp.md#add-class-dialog-box), que, por sua vez, abre assistentes para cada um dos tipos de classe que podem ser adicionados ao projeto. Para classes MFC, use o [Assistente de classe MFC](../mfc/reference/mfc-class-wizard.md). O comando **Adicionar Recurso** exibe a caixa de diálogo [Adicionar Recurso](../windows/how-to-create-a-resource-script-file.md), na qual você pode criar ou selecionar um recurso a ser adicionado ao projeto.

   Se você realçar uma classe ou uma interface no projeto em Modo de Exibição de Classe, o menu **Projeto** também exibirá os seguintes comandos:

  - **Implementar Interface** (somente em uma classe de controle)

  - **Adicionar função**

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
   |Gerenciador de Soluções|Os assistentes de código disponíveis no Gerenciador de Soluções dependem do local em que o foco do cursor está quando você clica com o botão direito do mouse em um item. Se a opção **Adicionar** não for exibida quando você clicar com o botão direito do mouse em um item, mova o cursor para um nível acima na árvore de desenvolvimento e tente novamente. Os assistentes de código sempre colocarão o código adicional no local apropriado na árvore de desenvolvimento, seja qual for a localização do cursor. Os assistentes de código disponíveis no Gerenciador de Soluções incluem:<br /><br />-Adicionar classe (abre a caixa de diálogo **Adicionar classe** que contém os novos assistentes de código).<br />- Adicionar Recurso (Novo, Importar ou Personalizado).<br />- Adicionar Referência Web.|
   |Exibição de Classe|Os assistentes de código disponíveis no Modo de Exibição de Classe dependem do local em que o foco do cursor está quando você clica com o botão direito do mouse em um item. Se a opção **Adicionar** não for exibida quando você clicar com o botão direito do mouse em um item, mova o cursor para um nível acima na árvore de classe e tente novamente. Os assistentes de código sempre colocarão o código adicional no local apropriado na árvore de desenvolvimento, seja qual for a localização do cursor. Os assistentes de código disponíveis no Modo de Exibição de Classe incluem:<br /><br />- [Adicionar Função de Membro](../ide/adding-a-member-function-visual-cpp.md).<br />- [Adicionar Variável de Membro](../ide/adding-a-member-variable-visual-cpp.md).<br />- [Adicionar Classe](../ide/adding-a-class-visual-cpp.md).<br />- [Implementar Interface](./implementing-an-interface-visual-cpp.md#implement-interface-wizard) (somente em uma classe de controle)<br />- [Adicionar ponto de conexão](./implementing-a-connection-point-visual-cpp.md#implement-connection-point-wizard) (somente classe ATL)<br />- [Adicionar Método](./adding-a-method-visual-cpp.md#add-method-wizard) (somente em uma interface)<br />- [Adicionar Propriedade](./adding-a-property-visual-cpp.md#names-add-property-wizard) (somente em uma interface)<br />- [Adicionar Evento](./adding-an-event-visual-cpp.md#add-event-wizard) (somente em uma classe de controle)<br /><br />A seleção de Adicionar Classe abre a caixa de diálogo **Adicionar Classe**, que fornece acesso a todos os novos assistentes de código de Adicionar Classe.|

## <a name="see-also"></a>Consulte também

[Substituindo uma função virtual](../ide/overriding-a-virtual-function-visual-cpp.md)<br>
[Navegar pela base de código C++ no Visual Studio](../ide/navigate-code-cpp.md)<br>
[Tipos de projeto do C++ no Visual Studio](../build/reference/visual-cpp-project-types.md)<br>
[Tipos de arquivo criados para projetos do Visual Studio C++](../build/reference/file-types-created-for-visual-cpp-projects.md)
