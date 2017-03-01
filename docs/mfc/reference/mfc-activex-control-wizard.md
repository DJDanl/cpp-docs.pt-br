---
title: Assistente de controle ActiveX do MFC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.ctl.overview
dev_langs:
- C++
helpviewer_keywords:
- ActiveX controls [C++], MFC
- MFC ActiveX controls [C++], wizards
- OLE controls [C++], creating
- MFC ActiveX Control Wizard
- OLE controls [C++]
ms.assetid: f19d698c-bdc3-4c74-af97-3d6ccb441b75
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 734c8dfdef42a0de614e02197d8cefdf4adc1bf1
ms.lasthandoff: 02/25/2017

---
# <a name="mfc-activex-control-wizard"></a>Assistente de controle ActiveX MFC
Um controle ActiveX é um tipo específico de [servidor de automação](../../mfc/automation-servers.md); é um componente reutilizável. O aplicativo que hospeda o controle ActiveX é o [clientes de automação de](../../mfc/automation-clients.md) desse controle. Se seu objetivo é criar um componente reutilizável, em seguida, use este assistente para criar seu controle. Consulte [controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Como alternativa, você pode criar uma automação servidor MFC aplicativo usando o [MFC Application Wizard](../../mfc/reference/mfc-application-wizard.md).  
  
 Um controle ActiveX criado com esse assistente pode ter uma interface do usuário, ou pode ser invisível. Você pode indicar essa opção a [configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do assistente. Um controle timer é um exemplo de um controle ActiveX que você deseja ser invisível.  
  
 Controles ActiveX podem ter uma interface do usuário complexa. Alguns controles podem estar como forms encapsulado: um único controle que contém muitos campos, cada um controle do Windows no seu próprio direito. Por exemplo, um objeto de partes automático implementado como um controle ActiveX MFC pode apresentar uma interface de usuário de forma semelhante, por meio do qual os usuários pode ler e editar o número de peça, nome da parte e outras informações. Consulte [controles ActiveX MFC](../../mfc/mfc-activex-controls.md) para obter mais informações.  
  
 Se você precisar criar um contêiner para objetos ActiveX, consulte [criar um contêiner de controle ActiveX](../../mfc/reference/creating-an-mfc-activex-control-container.md).  
  
 O programa de starter MFC inclui arquivos de origem (. cpp) de C++, arquivos de recurso (. rc) e um arquivo de projeto (. vcxproj). O código gerado nesses arquivos inicial baseia-se no MFC.  
  
 A lista de exemplo a seguir mostra as tarefas e tipos de aprimoramentos para o seu controle ActiveX:  
  
-   [Otimização de um controle ActiveX](../../mfc/mfc-activex-controls-optimization.md)  
  
-   [Adicionando eventos de estoque a um controle ActiveX](../../mfc/mfc-activex-controls-adding-stock-events-to-an-activex-control.md)  
  
-   [Adicionando eventos personalizados](../../mfc/mfc-activex-controls-adding-custom-events.md)  
  
-   [Adicionando métodos de estoque](../../mfc/mfc-activex-controls-adding-stock-methods.md)  
  
-   [Adicionando métodos personalizados](../../mfc/mfc-activex-controls-adding-custom-methods.md)  
  
-   [Adicionando propriedades de estoque](../../mfc/mfc-activex-controls-adding-stock-properties.md)  
  
-   [Adicionando propriedades personalizadas](../../mfc/mfc-activex-controls-adding-custom-properties.md)  
  
-   [Programando controles ActiveX em um contêiner de controle ActiveX](../../mfc/programming-activex-controls-in-a-activex-control-container.md)  
  
## <a name="overview"></a>Visão Geral  
 Esta página do assistente descreve as configurações do aplicativo atual para o projeto de controle ActiveX MFC que você está criando. Por padrão, o assistente cria um projeto da seguinte maneira:  
  
-   O projeto padrão não gera arquivos de licença ou ajuda nenhum tempo de execução. Você pode alterar essas configurações padrão no [configurações do aplicativo](../../mfc/reference/application-settings-mfc-activex-control-wizard.md) página. Somente as seleções feitas nesta página do Assistente de controle ActiveX são refletidas **visão geral** página.  
  
-   O projeto inclui uma classe de controle e uma classe de página de propriedade, com base no nome do projeto. Você pode editar os nomes dos seus nomes de arquivo e projeto no [nomes de controle](../../mfc/reference/control-names-mfc-activex-control-wizard.md) página.  
  
-   O controle é baseado em nenhum controle existente do Windows, ativa quando ele se torna visível, tem uma interface do usuário e inclui uma **sobre** caixa de diálogo. Você pode alterar essas configurações padrão no [as configurações de controle](../../mfc/reference/control-settings-mfc-activex-control-wizard.md) página.  
  
## <a name="see-also"></a>Consulte também  
 [Criando e gerenciando projetos do Visual C++](../../ide/creating-and-managing-visual-cpp-projects.md)   
 [Tipos de projeto do Visual C++](../../ide/visual-cpp-project-types.md)   
 [Conceitos](../../atl/active-template-library-atl-concepts.md)


