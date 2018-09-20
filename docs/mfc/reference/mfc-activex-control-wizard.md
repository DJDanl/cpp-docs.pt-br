---
title: Assistente de controle ActiveX do MFC | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfc.ctl.overview
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [MFC], MFC
- MFC ActiveX controls [MFC], wizards
- OLE controls [MFC], creating
- MFC ActiveX Control Wizard
- OLE controls [MFC]
ms.assetid: f19d698c-bdc3-4c74-af97-3d6ccb441b75
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ccf2da630c72962ee3e74badc250de5cce5f14e2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46407147"
---
# <a name="mfc-activex-control-wizard"></a>Assistente de controle ActiveX MFC

Um controle ActiveX é um tipo específico de [servidor de automação](../../mfc/automation-servers.md); é um componente reutilizável. O aplicativo que hospeda o controle ActiveX é o [cliente de automação](../../mfc/automation-clients.md) desse controle. Se sua meta é criar um componente reutilizável, em seguida, use este assistente para criar seu controle. Ver [controles ActiveX do MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem as ActiveX, consulte [controles ActiveX](../activex-controls.md).

Como alternativa, você pode criar uma automação MFC aplicativo server usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md).

Um controle ActiveX criado com esse assistente pode ter uma interface do usuário, ou pode ser invisível. Você pode indicar essa opção na [configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do assistente. Um controle timer é um exemplo de um controle ActiveX que você gostaria de ser invisível.

Controles ActiveX podem ter uma interface do usuário complexa. Alguns controles podem ser como formulários encapsulados: um único controle que contém muitos campos, cada um controle do Windows em seus próprios méritos. Por exemplo, um objeto de partes de automático implementado como um controle ActiveX do MFC pode apresentar uma interface do usuário de forma semelhante por meio do qual os usuários pode ler e editar o número de peça, nome da parte e outras informações. Ver [controles ActiveX do MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.

Se você precisar criar um contêiner para objetos ActiveX, consulte [criar um contêiner de controle ActiveX](../../mfc/reference/creating-an-mfc-activex-control-container.md).

O programa de início do MFC inclui arquivos de origem (. cpp) C++, arquivos de recurso (. rc) e um arquivo de projeto (. vcxproj). O código gerado nesses arquivos starter baseia-se no MFC.

A lista de exemplo a seguir mostra as tarefas e tipos de aprimoramentos para o seu controle ActiveX:

- [Otimizando a um controle ActiveX](../../mfc/mfc-activex-controls-optimization.md)

- [Adicionando eventos de estoque a um controle ActiveX](../../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md)

- [Adicionando eventos personalizados](../../mfc/mfc-activex-controls-adding-custom-events.md)

- [Adicionando métodos de estoque](../../mfc/mfc-activex-controls-adding-stock-methods.md)

- [Adicionando métodos personalizados](../../mfc/mfc-activex-controls-adding-custom-methods.md)

- [Adicionando propriedades de estoque](../../mfc/mfc-activex-controls-adding-stock-properties.md)

- [Adicionando propriedades personalizadas](../../mfc/mfc-activex-controls-adding-custom-properties.md)

- [Programando controles ActiveX em um contêiner de controle ActiveX](../../mfc/programming-activex-controls-in-a-activex-control-container.md)

## <a name="overview"></a>Visão geral

Esta página do assistente descreve as configurações do aplicativo atual para o projeto de controle ActiveX do MFC que você está criando. Por padrão, o assistente cria um projeto da seguinte maneira:

- O projeto padrão não gera nenhum arquivo de licença ou a Ajuda de tempo de execução. Você pode alterar essas configurações padrão na [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md) página. Somente as seleções feitas nesta página do Assistente de controle ActiveX são refletidas na **visão geral** página.

- O projeto inclui uma classe de controle e uma classe de página de propriedade, com base no nome do projeto. Você pode editar os nomes dos seus nomes de arquivo e projeto na [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md) página.

- O controle se baseia em nenhum controle existente do Windows, é ativado quando ele se torna visível, tem uma interface do usuário e inclui um **sobre** caixa de diálogo. Você pode alterar essas configurações padrão na [configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página.

## <a name="see-also"></a>Consulte também

[Criando e gerenciando projetos do Visual C++](../../ide/creating-and-managing-visual-cpp-projects.md)<br/>
[Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)<br/>
[Conceitos](../../atl/active-template-library-atl-concepts.md)

