---
title: Criar uma interface COM
ms.date: 05/14/2019
helpviewer_keywords:
- COM interfaces, creating
- methods [C++], adding to COM interfaces
- COM interfaces, editing
- properties [C++], adding to COM interfaces
ms.assetid: 1be84d3c-6886-4d1e-8493-56c4d38a96d4
ms.openlocfilehash: 09ddc113450fadb208e4f8471bc9aacf596a53f1
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "66182606"
---
# <a name="create-a-com-interface"></a>Criar uma interface COM

O Visual Studio fornece assistentes e modelos para criar projetos que usam interfaces e dispinterfaces de definição COM para classes de automação e objetos COM.

Use esses assistentes para executar as três tarefas comuns a seguir:

- [Adicionar suporte à ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md).

  Adicione o suporte para ATL a um aplicativo MFC depois de criar um projeto MFC usando o [assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) e, em seguida, executando o assistente de código **Adicionar Suporte para ATL ao MFC**. Esse suporte só se aplica a objetos COM simples adicionados a um executável do MFC ou um projeto de DLL. Esses objetos ATL podem ter mais de uma interface.

- [Criar um controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md).

  Abra o [assistente de controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar um controle ActiveX com uma dispinterface e um mapa de evento definido no arquivo .idl, bem como a classe de controle, respectivamente.

- [Adicionar um controle da ATL](../atl/reference/adding-an-atl-control.md).

  Use uma combinação do [assistente de projeto ATL](../atl/reference/atl-project-wizard.md) e do [assistente de controle ATL](../atl/reference/atl-control-wizard.md) para criar um controle ActiveX da ATL.

  Adicione também um controle ATL a um projeto MFC ao qual você adicionou o suporte para ATL, conforme descrito acima. Além disso, se você selecionar **Controle ATL** na caixa de diálogo **Adicionar Classe** e ainda não tiver adicionado o suporte para ATL ao projeto MFC, o Visual Studio exibirá uma caixa de diálogo que confirma a adição do suporte para ATL ao projeto MFC.

  Esse assistente gera uma fonte IDL e um mapa COM nas classes do projeto.

Depois que um projeto ATL estiver aberto, a caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md) oferecerá a opção de assistentes e modelos adicionais para adicionar interfaces COM ao projeto. Os seguintes assistentes permitem que você estabeleça uma ou mais interfaces para o objeto:

- [Assistente de componente de COM+ 1.0 da ATL](../atl/reference/atl-com-plus-1-0-component-wizard.md)
- [Assistente de objeto simples da ATL](../atl/reference/atl-simple-object-wizard.md)
- [Assistente do componente Active Server Page da ATL](../atl/reference/atl-active-server-page-component-wizard.md)
- [Assistente de controle da ATL](../atl/reference/atl-control-wizard.md)

Além disso, você pode implementar novas interfaces no controle COM. Basta clicar com o botão direito do mouse na classe de controle do objeto em Modo de Exibição de Classe e escolher [Implementar Interface](../ide/implement-interface-wizard.md).

> [!NOTE]
> O Visual Studio não fornece um assistente para adicionar uma interface a um projeto. Adicione uma interface a um projeto ATL ou a um [Adicionar suporte para ATL ao projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) com a adição de um objeto simples usando o [assistente de objeto ATL simples](../atl/reference/atl-simple-object-wizard.md). Como alternativa, abra o arquivo .idl do projeto e crie a interface digitando:

```
interface IMyInterface {
};
```

Para obter mais informações, confira [Implementar uma interface](../ide/implementing-an-interface-visual-cpp.md) e [Adicionar objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md).

O Visual C++ fornece várias maneiras de exibir e [editar as interfaces COM](#edit-a-com-interface) definidas para seus projetos. O [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code) exibe ícones para qualquer interface ou dispinterface definida em um arquivo .idl no projeto do C++.

Para as classes de objeto COM baseadas na ATL, o Modo de Exibição de Classe lê o mapa COM na classe ATL para exibir a relação entre a classe ATL e as interfaces implementadas por ela.

No Modo de Exibição de Classe e em seus menus de atalho, você pode trabalhar com as interfaces da seguinte maneira:

- Adicionar objetos ATL a um aplicativo baseado no MFC.
- Adicionar métodos, propriedades e eventos.
- Ir diretamente para o código de interface de um item clicando duas vezes no item.

## <a name="in-this-section"></a>Nesta seção

- [Editar uma interface COM](#edit-a-com-interface)

## <a name="edit-a-com-interface"></a>Editar uma interface COM

Usando comandos do menu de atalho de Modo de Exibição de Classe, é possível definir novos métodos e novas propriedades para as interfaces COM nos projetos do Visual Studio C++. Na Caixa de Ferramentas, você também pode definir eventos para controles ActiveX.

Para classes de objeto COM baseadas em ATL e MFC, você pode editar a implementação da classe ao mesmo tempo que edita a interface.

> [!NOTE]
> Para as interfaces definidas fora da caixa de diálogo **Adicionar Classe**, o Visual C++ adiciona os métodos ou as propriedades ao arquivo .idl e adiciona stubs às classes que implementam métodos, mesmo quando as interfaces são adicionadas manualmente.

Os três assistentes a seguir ajudarão você a personalizar as interfaces existentes. Eles estão disponíveis em Modo de Exibição de Classe:

|Wizard|Tipo de projeto|
|------------|------------------|
|[Assistente de adição de propriedade](../ide/names-add-property-wizard.md)|Projetos ATL ou MFC que dão suporte à ATL. Clique com o botão direito do mouse na interface à qual deseja adicionar a propriedade.<br /><br />O Visual C++ detecta o tipo de projeto e modifica as opções do Assistente de Adição de Propriedade, se necessário:<br /><br />- Para dispinterfaces em projetos criados usando o [assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), a invocação do Assistente de Adição de Propriedade fornece opções específicas ao MFC.<br />- Para interfaces de controle ActiveX do MFC, o Assistente de Adição de Propriedade fornece uma lista de métodos e propriedades de estoque que você pode usar, conforme fornecido, ou personalizar para o controle.<br />- Para todas as outras interfaces, os Assistentes de Adição de Propriedade fornecem opções úteis na maioria das situações.|
|[Assistente de adição de método](../ide/add-method-wizard.md)|Projetos ATL ou MFC que dão suporte à ATL. Clique com o botão direito do mouse na interface à qual deseja adicionar o método.<br /><br />O Visual C++ detecta o tipo de projeto e modifica as opções do Assistente de Adição de Método, se necessário:<br /><br />- Para dispinterfaces em projetos criados usando o [assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md), a utilização do Assistente de Adição de Método fornece opções específicas ao MFC.<br />- Para interfaces de controle ActiveX do MFC, o Assistente de Adição de Método fornece uma lista de métodos e propriedades de estoque que você pode usar, conforme fornecido, ou personalizar para o controle.<br />- Para todas as outras interfaces, os assistentes de **Adição de Método** fornecem opções úteis na maioria das situações.|

Além disso, você pode implementar novas interfaces no controle COM. Basta clicar com o botão direito do mouse na classe de controle do objeto em Modo de Exibição de Classe e escolher [Implementar Interface](../ide/implement-interface-wizard.md).
