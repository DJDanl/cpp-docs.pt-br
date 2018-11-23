---
title: Implementar uma interface
ms.date: 11/12/2018
f1_keywords:
- vc.codewiz.impl.interface.overview
helpviewer_keywords:
- interfaces, implementing
- implement interface wizard [C++]
ms.assetid: 72f8731b-7e36-45db-8b10-7ef211a773cd
ms.openlocfilehash: 8e166f806d247cd93ff0f471360d749fa95e430b
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51692895"
---
# <a name="implement-an-interface"></a>Implementar uma interface

Para implementar uma interface, você precisa ter criado um projeto como um aplicativo ATL COM ou como um aplicativo MFC que contém suporte para ATL. Use o [assistente de projeto ATL](../atl/reference/atl-project-wizard.md) para criar um aplicativo ATL ou [Adicionar um objeto ATL ao aplicativo MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) para implementar o suporte à ATL para um aplicativo MFC.

Depois de criar o projeto, para implementar uma interface, adicione primeiro um objeto ATL. Confira [Adicionar objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter uma lista de assistentes que adicionam objetos ao projeto ATL.

> [!NOTE]
> O assistente não dá suporte a caixas de diálogo da ATL, serviços Web XML que usam a ATL, objetos de desempenho ou contadores de desempenho.

Se você [adicionar um controle da ATL](../atl/reference/adding-an-atl-control.md), poderá especificar se deseja implementar interfaces padrão. As interfaces padrão são listadas na página [Interfaces](../atl/reference/interfaces-atl-control-wizard.md) do assistente e definidas em atlcom.h.

Depois de adicionar o objeto ou o controle, implemente outras interfaces, localizadas em qualquer biblioteca de tipos disponível, usando o Assistente para Implementação de Interface.

Caso esteja adicionando uma nova interface, adicione-a manualmente ao arquivo .idl do projeto. Para obter mais informações, confira [Adicionar uma nova interface a um projeto ATL](../atl/reference/adding-a-new-interface-in-an-atl-project.md).

**Para implementar uma interface:**

1. Em Modo de Exibição de Classe, clique com o botão direito do mouse no nome da classe do objeto ATL.

1. Selecione **Adicionar** no menu de atalho e, em seguida, selecione **Implementar Interface** para exibir o [assistente para implementação de interface](#implement-interface-wizard).

1. Selecione as interfaces a serem implementadas nas bibliotecas de tipos apropriadas e selecione **Concluir**.

1. No Modo de Exibição de Classe, expanda o nó Bases e Interfaces para ver a interface que implementou. Em seguida, expanda o nó da interface para ver as propriedades, métodos e eventos disponíveis.

   > [!NOTE]
   > Use também o [Pesquisador de Objetos](/visualstudio/ide/viewing-the-structure-of-code) para examinar os membros da interface.

## <a name="in-this-section"></a>Nesta seção

- [Assistente de implementação de interface](#implement-interface-wizard)

## <a name="implement-interface-wizard"></a>Assistente de implementação de interface

Este assistente implementa uma interface para um objeto COM. As implementações de muitas interfaces estão incluídas nas bibliotecas COM disponíveis no Visual Studio e no Windows. Uma implementação de interface é associada a um objeto quando uma instância do objeto é criada. Ela também informa os serviços que o objeto oferece.

Para ver uma discussão sobre interfaces e implementações, confira [Interfaces e implementações de interface](/windows/desktop/com/interfaces-and-interface-implementations) no SDK do Windows.

- **Implementar interface de**

  Especifica o local da biblioteca de tipos, com base na qual a interface é criada.

  |Opção|Descrição|
  |------------|-----------------|
  |**Projeto**|A biblioteca de tipos faz parte do projeto.|
  |**Registry**|A biblioteca de tipos é registrada no sistema. As bibliotecas de tipos registradas são listadas em **Bibliotecas de tipos disponíveis**.|
  |**Arquivo**|A biblioteca de tipos não está necessariamente registrada no sistema, mas está guardada em um arquivo. Forneça a localização do arquivo em **Localização**.|

- **Bibliotecas de tipos disponíveis**

  Exibe as bibliotecas de tipos disponíveis que guardam as definições de interface que você pode implementar. Se você escolher **Arquivo** em **Implementar interface de**, essa caixa não ficará disponível para alteração.

- **Local**

  Exibe o local da biblioteca de tipos atualmente selecionada na lista **Bibliotecas de tipos disponíveis**. Se você tiver selecionado **Arquivo** em **Implementar interface de**, selecione o botão de reticências para localizar um arquivo que guarda a biblioteca de tipos a ser usada.

- **Interfaces**

  Exibe as interfaces cujas definições estão guardadas na biblioteca de tipos atualmente selecionada na caixa **Bibliotecas de tipos disponíveis**.

  > [!NOTE]
  > As interfaces que têm o mesmo nome daquelas já implementadas pelo objeto selecionado não são exibidas na caixa **Interfaces**.

  |Botão de transferência|Descrição|
  |---------------------|-----------------|
  |**>**|Adiciona à lista **Implementar interfaces** o nome da interface atualmente selecionado na lista **Interfaces**.|
  |**>>**|Adiciona à lista **Implementar interfaces** todos os nomes de interfaces disponíveis na lista **Interfaces**.|
  |**\<**|Remove o nome da interface atualmente selecionado na lista **Implementar interfaces**.|
  |**\<\<**|Remove todos os nomes de interfaces atualmente relacionados na lista **Implementar interfaces**.|

- **Implementar Interfaces**

  Exibe os nomes das interfaces selecionadas para implementação no objeto.

  > [!NOTE]
  > Se você incluir mais de uma interface derivada de `IDispatch` ou se tentar implementar uma interface derivada de outra interface que já está na classe, precisará desfazer a ambiguidade das entradas COM_MAP. Para obter mais informações, confira [COM_INTERFACE_ENTRY2](../atl/reference/com-interface-entry-macros.md#com_interface_entry2).
