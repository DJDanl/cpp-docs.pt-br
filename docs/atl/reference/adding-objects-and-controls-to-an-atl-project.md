---
title: Como adicionar objetos e controles a um projeto ATL
ms.date: 05/09/2019
f1_keywords:
- vc.appwiz.ATL.controls
helpviewer_keywords:
- ATL projects, adding objects
- wizards [C++], ATL projects
- ATL projects, adding controls
- controls [ATL], adding to projects
- objects [C++], adding to ATL projects
- ATL Control Wizard
ms.assetid: c0adcbd0-07fe-4c55-a8fd-8c2c65ecdaad
ms.openlocfilehash: b1bf4f85ccf7a0bb2d77bfb96c512349f581f193
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832445"
---
# <a name="adding-objects-and-controls-to-an-atl-project"></a>Como adicionar objetos e controles a um projeto ATL

> [!NOTE]
> O Assistente de componente de COM+ 1.0 da ATL, o Assistente de consumidor OLE DB da ATL e o Assistente do componente Active Server Page da ATL não estão disponíveis no Visual Studio 2019 e posterior.

É possível usar um dos assistentes de código da ATL para adicionar um objeto ou um controle aos seus projetos baseados em ATL ou em MFC. Para cada objeto COM ou controle adicionado, o assistente gera arquivos .cpp e .h, além de um arquivo .rgs para suporte a Registro baseado em script. Os assistentes de código da ATL a seguir estão disponíveis no Visual Studio:

- [Objeto ATL Simples](../../atl/reference/atl-simple-object-wizard.md)
- [Caixa de Diálogo da ATL](../../atl/reference/atl-dialog-wizard.md)
- [Controle da ATL](../../atl/reference/atl-control-wizard.md)
- [Página de Propriedades da ATL](../../atl/reference/atl-property-page-wizard.md)
- [Componente Active Server Page da ATL](../../atl/reference/atl-active-server-page-component-wizard.md)
- [Consumidor OLE DB da ATL](../../atl/reference/atl-ole-db-consumer-wizard.md)
- [Adicionar Suporte para ATL ao MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md)
- [Assistente de componente de COM+ 1.0 da ATL](../../atl/reference/atl-com-plus-1-0-component-wizard.md)
- [Provedor OLE DB da ATL](../../atl/reference/atl-ole-db-provider-wizard.md)

> [!NOTE]
> Antes de adicionar um objeto da ATL ao seu projeto, você deve examinar os detalhes e os requisitos do objeto em seus tópicos de Ajuda relacionados.

## <a name="to-add-an-object-or-a-control-using-the-atl-control-wizard"></a>Para adicionar um objeto ou um controle usando o Assistente de Controle da ATL

1. No **Gerenciador de Soluções**, clique com o botão direito do mouse no nó do projeto e em **Adicionar** no menu de atalho. Clique em **Adicionar Classe**.

   A caixa de diálogo [Adicionar Classe](../../ide/add-class-dialog-box.md) é exibida.

1. Com a pasta **ATL** selecionada no painel **Categorias**, selecione um objeto a ser inserido do painel **Modelos**. Clique em **Abrir**. O assistente de código do objeto selecionado é exibido.

   > [!NOTE]
   > Se você deseja adicionar um objeto da ATL a um projeto do MFC, é necessário adicionar suporte para ATL ao projeto existente. É possível fazer isso seguindo as instruções em [Como adicionar suporte para ATL ao seu projeto do MFC](../../mfc/reference/adding-atl-support-to-your-mfc-project.md).

   Ou se você tentar adicionar um objeto da ATL ao seu projeto do MFC sem adicionar o suporte à ATL anteriormente, o Visual Studio solicitará que você especifique se deseja que o suporte para ATL seja adicionado ao seu projeto. Clique em **Sim** para adicionar o suporte para ATL ao projeto e abra o assistente da ATL selecionado.

## <a name="see-also"></a>Confira também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do C++ no Visual Studio](../../build/reference/visual-cpp-project-types.md)<br/>
[Conceitos básicos de objetos COM ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Programação com o código de tempo de execução ATL e C](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Configurações padrão do projeto do ATL](../../atl/reference/default-atl-project-configurations.md)
