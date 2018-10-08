---
title: Adicionando uma nova Interface em um projeto ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.appwiz.ATL.interface
dev_langs:
- C++
helpviewer_keywords:
- interfaces, adding to ATL objects
- Implement Interface ATL wizard
- controls [ATL], interfaces
- ATL projects, adding interfaces
ms.assetid: 7d34b023-2c6b-4155-aca3-d47a40968063
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fec98fd785f5e99875c5f73b13ce1082c16add2b
ms.sourcegitcommit: 997e6b7d336cddb388bb6e9e56527725fcaa0624
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/08/2018
ms.locfileid: "48861753"
---
# <a name="adding-a-new-interface-in-an-atl-project"></a>Adicionando uma nova Interface em um projeto ATL

Quando você adiciona uma interface para o objeto ou controle, você criar funções de oculto-out para cada método nessa interface. Em seu objeto ou controle, você pode adicionar somente as interfaces atualmente encontradas em uma biblioteca de tipo existente. Além disso, a classe em que você adicionar a interface deve implementar o [BEGIN_COM_MAP](com-map-macros.md#begin_com_map) macro ou, se o projeto for atribuído, ele deve ter o `coclass` atributo.

Você pode adicionar uma nova interface para seu controle em uma das duas maneiras: manualmente ou usando os assistentes de código no modo de exibição de classe.

## <a name="to-use-code-wizards-in-class-view-to-add-an-interface-to-an-existing-object-or-control"></a>Usar assistentes de código no modo de exibição de classe para adicionar uma interface para um objeto existente ou um controle

1. Na [modo de exibição de classe](/visualstudio/ide/viewing-the-structure-of-code), clique no nome de classe de um controle. Por exemplo, um controle total ou controle de composição ou qualquer outra classe de controle que implementa uma macro BEGIN_COM_MAP em seu arquivo de cabeçalho.

1. No menu de atalho, clique em **Add**e, em seguida, clique em **implementar Interface**.

1. Selecione as interfaces para implementar o [implementar Interface de assistente](../../ide/implement-interface-wizard.md). Se a interface não existir em qualquer typelib disponível, em seguida, adicione-manualmente ao arquivo. idl.

## <a name="to-add-a-new-interface-manually"></a>Para adicionar uma nova interface manualmente

1. Adicione a definição da sua nova interface para o arquivo. idl.

1. Derive seu objeto ou o controle da interface.

1. Criar um novo [COM_INTERFACE_ENTRY](com-interface-entry-macros.md#com_interface_entry) para a interface ou, se o projeto for atribuído, adicione o `coclass` atributo.

1. Implementar métodos na interface.

## <a name="see-also"></a>Consulte também

[Assistente de Projeto da ATL](../../atl/reference/atl-project-wizard.md)<br/>
[Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)<br/>
[Criando projetos para área de trabalho com Assistentes de Aplicativo](../../ide/creating-desktop-projects-by-using-application-wizards.md)<br/>
[Programando com código de tempo de execução C e da ATL](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Configurações de projeto padrão da ATL](../../atl/reference/default-atl-project-configurations.md)
