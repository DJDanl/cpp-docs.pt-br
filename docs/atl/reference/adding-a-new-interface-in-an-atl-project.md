---
title: Adicionando uma nova Interface em um projeto da ATL
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.ATL.interface
helpviewer_keywords:
- interfaces, adding to ATL objects
- Implement Interface ATL wizard
- controls [ATL], interfaces
- ATL projects, adding interfaces
ms.assetid: 7d34b023-2c6b-4155-aca3-d47a40968063
ms.openlocfilehash: 8bf0138f85929e06b67e9a2e294eda8a2f385e1a
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499377"
---
# <a name="adding-a-new-interface-in-an-atl-project"></a>Adicionando uma nova Interface em um projeto da ATL

Quando você adiciona uma interface ao seu objeto ou controle, você cria funções fragmentado para cada método nessa interface. No seu objeto ou controle, você pode adicionar apenas interfaces atualmente encontradas em uma biblioteca de tipos existente. Além disso, a classe na qual você adiciona a interface deve implementar a macro [BEGIN_COM_MAP](com-map-macros.md#begin_com_map) ou, se o projeto for atribuído, ele deverá ter o `coclass` atributo.

Você pode adicionar uma nova interface ao seu controle de uma das duas maneiras: manualmente ou usando assistentes de código no Modo de Exibição de Classe.

## <a name="to-use-code-wizards-in-class-view-to-add-an-interface-to-an-existing-object-or-control"></a>Para usar assistentes de código no Modo de Exibição de Classe para adicionar uma interface a um objeto ou controle existente

1. Em [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique com o botão direito do mouse no nome da classe de um controle. Por exemplo, um controle total ou controle composto ou qualquer outra classe de controle que implemente uma macro BEGIN_COM_MAP em seu arquivo de cabeçalho.

1. No menu de atalho, clique em **Adicionar**e, em seguida, clique em **implementar interface**.

1. Selecione as interfaces a serem implementadas no [Assistente de implementação de interface](../../ide/implementing-an-interface-visual-cpp.md#implement-interface-wizard). Se a interface não existir em nenhum typelib disponível, você deverá adicioná-la manualmente ao arquivo. idl.

## <a name="to-add-a-new-interface-manually"></a>Para adicionar uma nova interface manualmente

1. Adicione a definição da nova interface ao arquivo. idl.

1. Derive seu objeto ou controle da interface.

1. Crie um novo [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) para a interface ou, se o projeto for atribuído, adicione o `coclass` atributo.

1. Implemente métodos na interface.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do C++ no Visual Studio](../../build/reference/visual-cpp-project-types.md)<br/>
[Programação com o código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Conceitos básicos de objetos COM ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Configurações padrão do projeto do ATL](../../atl/reference/default-atl-project-configurations.md)
