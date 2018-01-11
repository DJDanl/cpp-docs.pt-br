---
title: Criando uma Interface COM (Visual C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.codewiz.com.creating.interfaces
dev_langs: C++
helpviewer_keywords: COM interfaces, creating
ms.assetid: 1be84d3c-6886-4d1e-8493-56c4d38a96d4
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e7b5820686c3e6f01c37cbf527d0e631e5bcc25c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-com-interface-visual-c"></a>Criando uma interface COM (Visual C++)
Visual C++ fornece modelos e assistentes para criar projetos que usam interfaces de definição de COM e dispinterfaces para seus objetos e classes de automação.  
  
 Você pode usar esses assistentes para executar as seguintes três tarefas comuns:  
  
-   [Adicionando suporte à ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md)  
  
     Adicionar suporte ATL para um aplicativo MFC, depois de criar um projeto MFC usando o [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) e, em seguida, executando o **adicionar o suporte ATL ao MFC** Assistente de código. Esse suporte só se aplica a objetos simples adicionados a um executável do MFC ou projeto DLL. Esses objetos ATL podem ter várias interfaces.  
  
-   [Criando um controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md)  
  
     Abra o [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar um controle ActiveX com um dispinterface e um mapa de evento definido no arquivo. idl e a classe de controle, respectivamente.  
  
-   [Adicionando um controle da ATL](../atl/reference/adding-an-atl-control.md)  
  
     Usar uma combinação da [Assistente de projeto de ATL](../atl/reference/atl-project-wizard.md) e [Assistente de controle ATL](../atl/reference/atl-control-wizard.md) para criar um controle ActiveX ATL.  
  
     Você também pode adicionar um controle ATL a um projeto para o qual você adicionou suporte ATL, conforme descrito acima. Além disso, se você selecionar **controle ATL** no **Adicionar classe** caixa de diálogo e você ainda não adicionou suporte ATL ao seu projeto MFC, o Visual Studio exibe uma caixa de diálogo Confirmar adicionar suporte ATL ao seu Projeto do MFC.  
  
     Este assistente gera fonte IDL e um mapa COM nas classes de projeto.  
  
 Uma vez que um projeto de ATL abrir, o [Adicionar classe](../ide/add-class-dialog-box.md) caixa de diálogo lhe dá a opção de modelos e assistentes adicionais para adicionar interfaces COM para seu projeto. Os assistentes a seguir permitem que você estabeleça uma ou mais interfaces para o objeto:  
  
-   [Assistente de componente de COM+ 1.0 da ATL](../atl/reference/atl-com-plus-1-0-component-wizard.md)  
  
-   [Assistente de objeto simples da ATL](../atl/reference/atl-simple-object-wizard.md)  
  
-   [Assistente do componente Active Server Page da ATL](../atl/reference/atl-active-server-page-component-wizard.md)  
  
-   [Assistente de Controle da ATL](../atl/reference/atl-control-wizard.md)  
  
 Além disso, você pode implementar novas interfaces do controle COM classe de controle do objeto no modo de exibição de classe e clicando em [implementar Interface](../ide/implement-interface-wizard.md).  
  
> [!NOTE]
>  O Visual Studio não fornece um Assistente para adicionar uma interface para um projeto. Você pode adicionar uma interface para um projeto de ATL ou para um [adicionar suporte ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) com a adição de um objeto simple usando o [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md). Como alternativa, abra o arquivo do projeto. idl e crie a interface digitando:  
  
```  
interface IMyInterface {  
};  
  
```  
  
 Consulte [implementando uma Interface](../ide/implementing-an-interface-visual-cpp.md) e [adicionando objetos e controles para um projeto de ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.  
  
 O Visual C++ fornece várias maneiras de exibir e [editar as interfaces COM](../ide/editing-a-com-interface.md) definidos para seus projetos. [Exibição de classe](http://msdn.microsoft.com/en-us/8d7430a9-3e33-454c-a9e1-a85e3d2db925) exibe ícones para qualquer interface ou dispinterface definido em um arquivo. idl em seu projeto C++.  
  
 Para classes de objeto com base em ATL COM, a exibição de classe lê o mapa COM na classe ATL para exibir a relação entre a classe ATL e interfaces que ele implementa.  
  
 No modo de exibição de classe e seus menus de atalho, você pode trabalhar com interfaces da seguinte maneira:  
  
-   Adicione objetos ATL para um aplicativo baseado em MFC.  
  
-   Adicione métodos, propriedades e eventos.  
  
-   Ir diretamente para o código de interface de um item clicando duas vezes no item.  
  
## <a name="see-also"></a>Consulte também  
 [Criando projetos de área de trabalho usando os assistentes de aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)