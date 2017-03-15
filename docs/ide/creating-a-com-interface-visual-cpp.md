---
title: "Criando uma interface COM (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.codewiz.com.creating.interfaces"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interfaces COM, criando"
ms.assetid: 1be84d3c-6886-4d1e-8493-56c4d38a96d4
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando uma interface COM (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Visual C\+\+ fornece assistentes e modelos para criar projetos que usam interfaces de definição de COM e dispinterfaces para seus objetos COM e classes de automação.  
  
 Você pode usar esses assistentes para realizar três tarefas comuns a seguir:  
  
-   [Adicionar suporte ATL ao seu projeto MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md)  
  
     Adicionar suporte ATL para um aplicativo MFC depois de criar um projeto MFC usando o  [MFC Application Wizard](../Topic/MFC%20Application%20Wizard.md) e, em seguida, executando o  **Adicionar suporte a ATL ao MFC** Assistente de código.  Esse suporte só se aplica a objetos simples adicionados para um executável do MFC ou o projeto DLL.  Esses objetos ATL podem ter várias interfaces.  
  
-   [Criar um controle de ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control.md)  
  
     Abrir o  [Assistente de controle do MFC ActiveX](../mfc/reference/mfc-activex-control-wizard.md) para criar um controle de ActiveX com um dispinterface e um mapa de evento definido no arquivo. idl e a classe de controle, respectivamente.  
  
-   [Adicionando um controle ATL](../atl/reference/adding-an-atl-control.md)  
  
     Usar uma combinação da  [ATL Project Wizard](../Topic/ATL%20Project%20Wizard.md) e o  [ATL controle Wizard](../atl/reference/atl-control-wizard.md) para criar um controle ATL ActiveX.  
  
     Você também pode adicionar um controle ATL para um projeto MFC para o qual você adicionou suporte ATL, conforme descrito acima.  Além disso, se você selecionar  **Controle ATL** na  **Add Class**  caixa de diálogo e você ainda não adicionou suporte ATL ao seu projeto MFC, Visual Studio exibe uma caixa de diálogo confirmando a adicionar suporte ATL ao seu projeto MFC.  
  
     Este assistente gera fonte IDL e um mapa COM nas classes do projeto.  
  
 Uma vez que um projeto ATL abrir, o  [Add Class](../ide/add-class-dialog-box.md) caixa de diálogo oferece a opção de modelos e assistentes adicionais para adicionar as interfaces COM ao seu projeto.  Os assistentes a seguir permitem que você estabelecer uma ou mais interfaces para o objeto:  
  
-   [Assistente de componentes do ATL COM\+ 1.0](../atl/reference/atl-com-plus-1-0-component-wizard.md)  
  
-   [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md)  
  
-   [Assistente de componente de página do ATL Active Server](../atl/reference/atl-active-server-page-component-wizard.md)  
  
-   [Assistente de controle do ATL](../atl/reference/atl-control-wizard.md)  
  
 Além disso, você pode implementar novas interfaces em seu controle COM clicando com o botão direito na classe do objeto de controle no modo de exibição de classe e clicando em  [Implementar a Interface](../Topic/Implement%20Interface%20Wizard.md).  
  
> [!NOTE]
>  Visual Studio não fornece um Assistente para adicionar uma interface para um projeto.  Você pode adicionar uma interface para um projeto do ATL ou para um  [Adicionando o suporte ATL ao seu projeto de MFC](../mfc/reference/adding-atl-support-to-your-mfc-project.md) , adicionando um objeto simples usando o  [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md).  Como alternativa, abra o arquivo do projeto. idl e criar a interface digitando:  
  
```  
interface IMyInterface {  
};  
  
```  
  
 Consulte  [implementação de uma Interface](../ide/implementing-an-interface-visual-cpp.md) e  [adicionando objetos e controles a um projeto ATL](../atl/reference/adding-objects-and-controls-to-an-atl-project.md) para obter mais informações.  
  
 O Visual C\+\+ fornece várias maneiras de exibir e  [Editar as interfaces COM](../ide/editing-a-com-interface.md) definido para seus projetos.  [Exibição de classe](http://msdn.microsoft.com/pt-br/8d7430a9-3e33-454c-a9e1-a85e3d2db925) exibe ícones para qualquer interface ou um dispinterface definido em um arquivo. idl no seu projeto de C\+\+.  
  
 Para classes de objeto COM base em ATL, modo de exibição de classe lê o mapa COM na classe ATL para exibir a relação entre a classe ATL e quaisquer interfaces que ela implementa.  
  
 No modo de exibição de classe e seus menus de atalho, você pode trabalhar com interfaces da seguinte maneira:  
  
-   Adicione objetos ATL para um aplicativo baseado em MFC.  
  
-   Adicione métodos, propriedades e eventos.  
  
-   Ir diretamente ao código de interface de um item clicando duas vezes no item.  
  
## Consulte também  
 [Criando projetos para desktop com Assistentes de Aplicativo](../ide/creating-desktop-projects-by-using-application-wizards.md)   
 [Adicionando funcionalidade com assistentes de código](../ide/adding-functionality-with-code-wizards-cpp.md)