---
title: Adicionar uma classe de um controle ActiveX
ms.date: 11/08/2018
f1_keywords:
- vc.codewiz.class.axcontrol
helpviewer_keywords:
- ActiveX controls [C++], adding classes
- classes [C++], creating
- ActiveX Control Wizard
- add class from ActiveX control wizard [C++]
ms.assetid: 729fcb37-54b8-44d5-9b4e-50bb16e0eea4
ms.openlocfilehash: 1d91d98082a5c5d6d45bfa31e81c59e8925aa2c2
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694212"
---
# <a name="add-a-class-from-an-activex-control"></a>Adicionar uma classe de um controle ActiveX

Use este assistente para criar uma classe MFC por meio de uma interface em um controle ActiveX disponível. Adicione uma classe MFC a um [aplicativo MFC](../mfc/reference/creating-an-mfc-application.md), uma [DLL do MFC](../mfc/reference/creating-an-mfc-dll-project.md) ou um [controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md).

> [!WARNING]
> No Visual Studio 2017 versão 15.9, esse assistente de código foi preterido pela Microsoft e será removido em uma versão futura do Visual Studio. Este assistente é raramente usado. O suporte geral para ATL e MFC não é afetado pela remoção do assistente. Se você quiser compartilhar seus comentários sobre essa alteração, participe [desta pesquisa](https://www.surveymonkey.com/r/QDWKKCN). Seus comentários são importantes para nós.
<!-- Blank comment here to separate the warning and note. -->
> [!NOTE]
> Você não precisa criar seu projeto MFC com a Automação habilitada para adicionar uma classe por meio de um controle ActiveX.

Um controle ActiveX é um componente de software reutilizável baseado no COM (Component Object Model) que dá suporte a uma ampla variedade de funcionalidades OLE. Ele pode ser personalizado para atender às várias necessidades de software. É possível usar os controles ActiveX em contêineres comuns de controle ActiveX ou na Internet em páginas da World Wide Web.

**Para adicionar uma classe MFC por meio de um controle ActiveX:**

1. No **Gerenciador de Soluções** ou em [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome do projeto ao qual deseja adicionar a classe de controle ActiveX.

1. No menu de atalho, escolha **Adicionar** e, depois, **Adicionar classe**.

1. Na caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md), no painel **Modelos**, selecione **Classe MFC de controle ActiveX** e, em seguida, escolha **Abrir** para exibir a opção [Assistente para adicionar classe por meio de controle ActiveX](#add-class-from-activex-control-wizard).

No assistente, adicione mais de uma interface em um controle ActiveX. Você também pode criar classes por meio de mais de um controle ActiveX em uma única sessão do assistente.

Adicione classes por meio de controles ActiveX registrados no sistema ou de controles ActiveX localizados em arquivos de biblioteca de tipos (.tlb, .olb, .dll, .ocx ou .exe) sem primeiro registrá-los no sistema. Para obter mais informações sobre como registrar controles ActiveX, confira [Registrando controles OLE](../mfc/reference/registering-ole-controls.md).

O assistente cria uma classe MFC, derivada de [CWnd](../mfc/reference/cwnd-class.md) ou de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md), para cada interface adicionada por meio do controle ActiveX selecionado.

## <a name="in-this-section"></a>Nesta seção

- [Assistente para adicionar classe por meio de controle ActiveX](#add-class-from-activex-control-wizard)

## <a name="add-class-from-activex-control-wizard"></a>Assistente para adicionar classe por meio de controle ActiveX

Use este assistente para adicionar uma classe MFC por meio de um controle ActiveX disponível. O assistente cria uma classe para cada interface adicionada por meio do controle ActiveX selecionado.

- **Adicionar Classe por meio de**

  Especifica a localização da biblioteca de tipos com base na qual a classe é criada.

  |Opção|Descrição|
  |------------|-----------------|
  |**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Controles ActiveX disponíveis**.|
  |**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está armazenada em um arquivo. Forneça a localização do arquivo em **Localização**.|

- **Controles ActiveX disponíveis**

  Especifica os controles ActiveX atualmente registrados no sistema. Selecione um controle ActiveX nessa lista para exibir suas interfaces na lista **Interfaces**. Confira [Controles ActiveX MFC: distribuindo controles ActiveX](../mfc/mfc-activex-controls-distributing-activex-controls.md) para obter mais informações sobre como registrar controles ActiveX.

  Se você selecionar **Arquivo** em **Adicionar Classe por meio de**, essa caixa não ficará disponível para alteração.

- **Local**

  Especifica o local do controle ActiveX. Se você selecionar **Arquivo** em **Adicionar Classe por meio de**, poderá fornecer a localização do arquivo que guarda a biblioteca de tipos. Para procurar a localização do arquivo, selecione o botão de reticências.

  Se você selecionar **Registro** em **Adicionar Classe por meio de**, essa caixa não ficará disponível para alteração.

- **Interfaces**

  Especifica as interfaces no controle ActiveX. O assistente usa as interfaces da seleção atual em **Controles ActiveX disponíveis** ou usa as interfaces do arquivo de biblioteca de tipos especificado em **Localização**.

  |Botão de transferência|Descrição|
  |---------------------|-----------------|
  |**>**|Adiciona a interface atualmente selecionada na lista **Interfaces**. Não disponível se nenhuma interface estiver selecionada.|
  |**>>**|Adiciona todas as interfaces no controle ActiveX. O assistente usa as interfaces da seleção atual em **Controles ActiveX disponíveis** ou usa as interfaces do arquivo de biblioteca de tipos especificado em **Localização**.|
  |**\<**|Remove a classe atualmente selecionada na lista **Classes geradas**. Não disponível se nenhuma classe estiver atualmente selecionada na lista **Classes geradas**.|
  |**\<\<**|Remove todas as classes da lista **Classes geradas**. Não disponível se a lista **Classes geradas** estiver vazia.|

- **classes geradas**

  Especifica os nomes de classe a serem gerados com base nas interfaces adicionadas por meio do botão **>** ou **>>**. Você pode selecionar esta caixa para selecionar uma classe e, em seguida, usar as teclas para cima ou para baixo para rolar a lista. Quando você seleciona **Concluir**, pode exibir cada nome de classe gerado na caixa **Classe** e cada nome de arquivo gerado na caixa **arquivo .h**. Selecione apenas uma classe por vez nessa caixa.

  Para remover uma classe, selecione-a na lista e escolha **<**. Você não precisa selecionar uma classe na caixa **Classes geradas** para remover todas as classes. Selecionando **<<**, você remove todas as classes na caixa **Classes geradas**.

- **Class**

   Especifica o nome da classe selecionada na caixa **Classes geradas** adicionada pelo assistente quando você seleciona **Concluir**. É possível editar o nome na caixa **Classe**.

- **Arquivo .h**

  Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Selecione o botão de reticências para salvar o nome de arquivo na localização de sua escolha ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará na localização selecionada até que você selecione **Concluir** no assistente.

  O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente e, depois, **Concluir**, o assistente solicitará que você indique se deseja acrescentar a declaração de classe ao conteúdo do arquivo. Selecione **Sim** para acrescentar o arquivo; selecione **Não** para retornar ao assistente e especificar outro nome de arquivo.

- **Arquivo .cpp**

  Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome baseia-se no nome fornecido em **Classes geradas**. Selecione o botão de reticências para salvar o nome de arquivo na localização de sua escolha. O arquivo não é salvo na localização selecionada até que você selecione **Concluir** no assistente.

  O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente e, depois, **Concluir**, o assistente solicitará que você indique se deseja acrescentar a implementação de classe ao conteúdo do arquivo. Selecione **Sim** para acrescentar o arquivo; selecione **Não** para retornar ao assistente e especificar outro nome de arquivo.
