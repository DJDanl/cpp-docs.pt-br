---
title: Criando uma interface COM (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.com.creating.interfaces
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces, creating
ms.assetid: 1be84d3c-6886-4d1e-8493-56c4d38a96d4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c31dfc72e6d552cacd46f3e0b49aedc18bf4c7f2
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43683307"
---
# <a name="creating-a-com-interface-visual-c"></a>Criando uma interface COM (Visual C++)
O Visual C++ fornece assistentes e modelos para criar projetos que usam interfaces e dispinterfaces de definição COM para classes de automação e objetos COM.  
  
 Use esses assistentes para executar as três seguintes tarefas comuns:  
  
-   [Adicionando suporte à ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md)  
  
     Adicione o suporte para ATL a um aplicativo MFC depois de criar um projeto MFC usando o [Assistente de Aplicativo MFC](../mfc/reference/mfc-application-wizard.md) e, em seguida, executando o assistente de código **Adicionar Suporte para ATL ao MFC**. Esse suporte só se aplica a objetos COM simples adicionados a um executável do MFC ou um projeto de DLL. Esses objetos ATL podem ter várias interfaces.  
  
-   [Criando um controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md)  
  
     Abra o [Assistente de Controle ActiveX do MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar um controle ActiveX com uma dispinterface e um mapa de evento definido no arquivo .idl, bem como a classe de controle, respectivamente.  
  
-   [Adicionando um controle da ATL](../atl/reference/adding-an-atl-control.md)  
  
     Use uma combinação do [Assistente de Projeto ATL](../atl/reference/atl-project-wizard.md) e do [Assistente de Controle ATL](../atl/reference/atl-control-wizard.md) para criar um controle ActiveX da ATL.  
  
     Adicione também um controle ATL a um projeto MFC ao qual você adicionou o suporte para ATL, conforme descrito acima. Além disso, se você selecionar **Controle ATL** na caixa de diálogo **Adicionar Classe** e ainda não tiver adicionado o suporte para ATL ao projeto MFC, o Visual Studio exibirá uma caixa de diálogo que confirmará a adição do suporte para ATL ao projeto MFC.  
  
     Esse assistente gera uma fonte IDL e um mapa COM nas classes do projeto.  
  
 Depois que um projeto ATL estiver aberto, a caixa de diálogo [Adicionar Classe](../ide/add-class-dialog-box.md) oferecerá a opção de assistentes e modelos adicionais para adicionar interfaces COM ao projeto. Os seguintes assistentes permitem que você estabeleça uma ou mais interfaces para o objeto:  
  
-   [Assistente de componente de COM+ 1.0 da ATL](../atl/reference/atl-com-plus-1-0-component-wizard.md)  
  
-   [Assistente de objeto simples da ATL](../atl/reference/atl-simple-object-wizard.md)  
  
-   [Assistente do componente Active Server Page da ATL](../atl/reference/atl-active-server-page-component-wizard.md)  
  
-   [Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md)  
  
 Além disso, você pode implementar novas interfaces no controle COM clicando com o botão direito do mouse na classe de controle do objeto em Modo de Exibição de Classe e clicando em [Implementar Interface](../ide/implement-interface-wizard.md).  
  
> [!NOTE]
>  O Visual Studio não fornece um assistente para adicionar uma interface a um projeto. Adicione uma interface a um projeto ATL ou a um [Adicionando Suporte para ATL ao Projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) com a adição de um objeto simples usando o [Assistente de Objeto ATL Simples](../atl/reference/atl-simple-object-wizard.md). Como alternativa, abra o arquivo .idl do projeto e crie a interface digitando:  
  
```  
interface IMyInterface {  
};  
  
```  
  
 Confira [Implementando uma interface](../ide/implementing-an-interface-visual-cpp.md) e [Adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.  
  
 O Visual C++ fornece várias maneiras de exibir e [editar as interfaces COM](../ide/editing-a-com-interface.md) definidas para seus projetos. O [Modo de Exibição de Classe](/visualstudio/ide/viewing-the-structure-of-code) exibe ícones para qualquer interface ou dispinterface definida em um arquivo .idl no projeto do C++.  
  
 Para as classes de objeto COM baseadas na ATL, o Modo de Exibição de Classe lê o mapa COM na classe ATL para exibir a relação entre a classe ATL e as interfaces implementadas por ela.  
  
 No Modo de Exibição de Classe e em seus menus de atalho, você pode trabalhar com as interfaces da seguinte maneira:  
  
-   Adicionar objetos ATL a um aplicativo baseado no MFC.  
  
-   Adicionar métodos, propriedades e eventos.  
  
-   Ir diretamente para o código de interface de um item clicando duas vezes no item.  
  
## <a name="see-also"></a>Consulte também  
 [Criando projetos da área de trabalho com assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)