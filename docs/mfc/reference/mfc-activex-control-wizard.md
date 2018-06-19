---
title: Assistente de controle ActiveX MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 45af43a98244e90f52075817fc9e17a905cbf065
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33375057"
---
# <a name="mfc-activex-control-wizard"></a>Assistente de controle ActiveX MFC
Um controle ActiveX é um tipo específico de [servidor de automação](../../mfc/automation-servers.md); é um componente reutilizável. O aplicativo que hospeda o controle ActiveX é o [clientes de automação](../../mfc/automation-clients.md) desse controle. Se seu objetivo é criar um componente reutilizável, em seguida, use este assistente para criar o controle. Consulte [controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Como alternativa, você pode criar uma automação MFC aplicativo server usando o [Assistente de aplicativo MFC](../../mfc/reference/mfc-application-wizard.md).  
  
 Um controle ActiveX criado com esse assistente pode ter uma interface do usuário, ou pode ser invisível. Você pode indicar que essa opção a [configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do assistente. Um controle de timer é um exemplo de um controle ActiveX que você deseja que seja invisível.  
  
 Controles ActiveX podem ter uma interface de usuário complexas. Alguns controles podem estar como formulários encapsulados: um único controle que contém muitos campos, cada um controle do Windows em seus próprios méritos. Por exemplo, um objeto de partes de auto implementado como um controle ActiveX MFC pode apresentar uma interface de usuário de forma semelhante, por meio do qual os usuários podem ler e editar o número de peça, nome de parte e outras informações. Consulte [controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Se você precisar criar um contêiner para objetos ActiveX, consulte [criar um contêiner de controle ActiveX](../../mfc/reference/creating-an-mfc-activex-control-container.md).  
  
 O programa de início do MFC inclui arquivos de origem (. cpp) C++, arquivos de recurso (. rc) e um arquivo de projeto (. vcxproj). O código gerado nesses arquivos de início é baseado em MFC.  
  
 A lista de exemplo a seguir mostra as tarefas e os tipos de aprimoramentos para o controle ActiveX:  
  
-   [Otimização de um controle ActiveX](../../mfc/mfc-activex-controls-optimization.md)  
  
-   [Adicionando eventos de estoque a um controle ActiveX](../../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md)  
  
-   [Adicionando eventos personalizados](../../mfc/mfc-activex-controls-adding-custom-events.md)  
  
-   [Adicionando métodos de estoque](../../mfc/mfc-activex-controls-adding-stock-methods.md)  
  
-   [Adicionando métodos personalizados](../../mfc/mfc-activex-controls-adding-custom-methods.md)  
  
-   [Adicionando propriedades de estoque](../../mfc/mfc-activex-controls-adding-stock-properties.md)  
  
-   [Adicionando propriedades personalizadas](../../mfc/mfc-activex-controls-adding-custom-properties.md)  
  
-   [Programando controles ActiveX em um contêiner de controle ActiveX](../../mfc/programming-activex-controls-in-a-activex-control-container.md)  
  
## <a name="overview"></a>Visão geral  
 Esta página do assistente descreve as configurações do aplicativo atual para o projeto de controle ActiveX MFC que você está criando. Por padrão, o assistente cria um projeto da seguinte maneira:  
  
-   O projeto padrão não gera arquivos de licença ou ajuda nenhum tempo de execução. Você pode alterar essas configurações padrão no [configurações de aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md) página. Somente as seleções feitas nesta página do Assistente de controle ActiveX são refletidas no **visão geral** página.  
  
-   O projeto inclui uma classe de controle e uma classe de página de propriedade, com base no nome do projeto. Você pode editar os nomes de seus nomes de arquivo e projeto no [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md) página.  
  
-   O controle é baseado em nenhum controle existente do Windows, ativa quando ele se torna visível, tem uma interface de usuário e inclui uma **sobre** caixa de diálogo. Você pode alterar essas configurações padrão no [configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e gerenciando projetos do Visual C++](../../ide/creating-and-managing-visual-cpp-projects.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)

