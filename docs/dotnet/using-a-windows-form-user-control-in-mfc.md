---
title: "Controle de usuário usando um Windows do formulário em MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- interoperability [C++], Windows Forms in MFC
- interoperability [C++], MFC
- interop [C++], Windows Forms in MFC
- interop [C++], MFC
- Windows Forms [C++], MFC support
ms.assetid: 63fb099b-1dff-469c-9e34-dab52e122fcd
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e836730942b3293ff8adc6aa7f8c75f4d2376cc1
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="using-a-windows-form-user-control-in-mfc"></a>Usando um controle de usuário do Windows Form no MFC
Usando as classes de suporte do MFC Windows Forms, é possível hospedar controles de formulários do Windows em seus aplicativos MFC como um controle ActiveX em caixas de diálogo do MFC ou modos de exibição. Além disso, os formulários do Windows forms podem ser hospedados como caixas de diálogo do MFC.  
  
 As seções a seguir descrevem como:  
  
-   Hospede um controle de formulários do Windows em uma caixa de diálogo do MFC.  
  
-   Hospede um controle de usuário do Windows Forms como uma exibição MFC.  
  
-   Hospede um formulário do Windows Forms como uma caixa de diálogo do MFC.  
  
> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos que vincular dinamicamente a MFC (projetos no qual AFXDLL é definido).  
  
> [!NOTE]
>  Quando você criar seu aplicativo usando uma cópia privada (modificada) das interfaces de formulários do Windows MFC DLL (mfcmifc80), ele não será instalado no GAC, a menos que você substitua a chave da Microsoft com sua própria chave de fornecedor. Para obter mais informações sobre assinatura de assembly, consulte [programação com Assemblies](/dotnet/framework/app-domains/programming-with-assemblies) e [Assemblies com nome forte (assinatura de Assembly) (C + + CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).  
  
 Para aplicativos de exemplo usando o Windows Forms, consulte [BirthdayPicker exemplo: demonstra recursos do .NET Framework com o Windows Forms](http://msdn.microsoft.com/en-us/ac932aed-5502-4667-be29-709bca435317), [Calculadora de exemplo: Calculadora do Windows Forms Pocket](http://msdn.microsoft.com/en-us/2283b516-3b7e-45f2-80c4-fdcfb366ce25)e [ Rabisco exemplo: Aplicativo de desenho MDI](http://msdn.microsoft.com/en-us/f025da3e-659b-4222-b991-554a1b8b2358).  
  
 Para um aplicativo de exemplo que mostra usado com MFC de formulários do Windows, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
 Se o aplicativo do MFC usar formulários do Windows, você precisa redistribuir mfcmifc90.dll com seu aplicativo. Para obter mais informações, consulte [redistribuindo a biblioteca do MFC](../ide/redistributing-the-mfc-library.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md)  
  
 [Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)  
  
 [Hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md)  
  
## <a name="reference"></a>Referência  
 [Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)  
  
 [Classe CWinFormsDialog](../mfc/reference/cwinformsdialog-class.md)  
  
 [Classe CWinFormsView](../mfc/reference/cwinformsview-class.md)  
  
 [Interface ICommandSource](../mfc/reference/icommandsource-interface.md)  
  
 [Interface ICommandTarget](../mfc/reference/icommandtarget-interface.md)  
  
 [Interface ICommandUI](../mfc/reference/icommandui-interface.md)  
  
 [Interface IView](../mfc/reference/iview-interface.md)  
  
 [CommandHandler](../atl/commandhandler.md)  
  
 [DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol)  
  
 [UICheckState](../mfc/reference/uicheckstate-enumeration.md)  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Windows Forms](/dotnet/framework/winforms/index)  
  
 [Controles dos Windows Forms](/dotnet/framework/winforms/controls/index)  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)   
 [Modos de exibição de formulário](../mfc/form-views-mfc.md)