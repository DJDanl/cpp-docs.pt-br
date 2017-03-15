---
title: "Usando um controle de usu&#225;rio do Windows Form no MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Suporte do MFC [C++], Windows Forms"
  - "interoperabilidade [C++], Windows Forms em MFC"
  - "interoperabilidade [C++], MFC"
  - "interoperabilidade [C++], Windows Forms em MFC"
  - "interoperabilidade [C++], MFC"
  - "Suporte ao Windows Forms [C++], MFC"
ms.assetid: 63fb099b-1dff-469c-9e34-dab52e122fcd
caps.latest.revision: 19
caps.handback.revision: 19
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando um controle de usu&#225;rio do Windows Form no MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usando as classes de suporte do MFC Windows Forms, você pode hospedar controles de formulários do Windows em seus aplicativos do MFC como um controle ActiveX em caixas de diálogo do MFC ou modos de exibição. Além disso, os formulários do Windows Forms podem ser hospedados como caixas de diálogo do MFC.  
  
 As seções a seguir descrevem como:  
  
-   Hospede um controle de formulários do Windows em uma caixa de diálogo do MFC.  
  
-   Hospede um controle de usuário do Windows Forms como uma exibição MFC.  
  
-   Hospede um formulário do Windows Forms como uma caixa de diálogo do MFC.  
  
> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos vinculam dinamicamente a MFC (projetos no qual AFXDLL é definido).  
  
> [!NOTE]
>  Quando você compila seu aplicativo usando uma cópia privada (modificada) das interfaces de formulários do Windows MFC DLL (mfcmifc80), ele não será instalado no GAC, a menos que você substitua a chave da Microsoft com sua própria chave de fornecedor. Para obter mais informações sobre assinatura de assembly, consulte [programação com Assemblies](../Topic/Programming%20with%20Assemblies.md) e [Assemblies com nome forte (assinatura de Assembly) (C + + / CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).  
  
 Para aplicativos de exemplo usando o Windows Forms, consulte [BirthdayPicker exemplo: demonstra recursos do .NET Framework com o Windows Forms](http://msdn.microsoft.com/pt-br/ac932aed-5502-4667-be29-709bca435317), [exemplo de Calculadora: Calculadora do Windows Forms Pocket](http://msdn.microsoft.com/pt-br/2283b516-3b7e-45f2-80c4-fdcfb366ce25), e [Rabisco exemplo: aplicativo de desenho MDI](http://msdn.microsoft.com/pt-br/f025da3e-659b-4222-b991-554a1b8b2358).  
  
 Para um aplicativo de exemplo que mostra os formulários do Windows usado com o MFC, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
 Se seu aplicativo do MFC usa o Windows Forms, será necessário redistribuir mfcmifc90.dll com seu aplicativo. Para obter mais informações, consulte [Redistribuindo a biblioteca MFC](../ide/redistributing-the-mfc-library.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md)  
  
 [Hospedando um controle de usuário do Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)  
  
 [Hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../Topic/Hosting%20a%20Windows%20Form%20User%20Control%20as%20an%20MFC%20Dialog%20Box.md)  
  
## <a name="reference"></a>Referência  
 [Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)  
  
 [Classe CWinFormsDialog](../Topic/CWinFormsDialog%20Class.md)  
  
 [Classe CWinFormsView](../mfc/reference/cwinformsview-class.md)  
  
 [Interface ICommandSource](../mfc/reference/icommandsource-interface.md)  
  
 [Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)  
  
 [Interface ICommandUI](../mfc/reference/icommandui-interface.md)  
  
 [Interface IView](../Topic/IView%20Interface.md)  
  
 [CommandHandler](../Topic/CommandHandler%20Delegate.md)  
  
 [CommandUIHandler](../Topic/CommandUIHandler%20Delegate.md)  
  
 [DDX_ManagedControl](../Topic/DDX_ManagedControl.md)  
  
 [UICheckState](../Topic/UICheckState%20Enumeration.md)  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Windows Forms](../Topic/Windows%20Forms.md)  
  
 [Controles do Windows Forms](../Topic/Windows%20Forms%20Controls.md)  
  
 [Controles de usuário do ASP.NET](../Topic/ASP.NET%20User%20Controls.md)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos de Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Modos de exibição de formulário](../Topic/Form%20Views%20\(MFC\).md)