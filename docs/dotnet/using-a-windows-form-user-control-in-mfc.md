---
title: Usando um controle de usuário do Windows Form no MFC
ms.date: 01/08/2018
helpviewer_keywords:
- MFC [C++], Windows Forms support
- interoperability [C++], Windows Forms in MFC
- interoperability [C++], MFC
- interop [C++], Windows Forms in MFC
- interop [C++], MFC
- Windows Forms [C++], MFC support
ms.assetid: 63fb099b-1dff-469c-9e34-dab52e122fcd
ms.openlocfilehash: efabbf84778d925ec1de03f5f4ea0ca09185bd81
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70926053"
---
# <a name="using-a-windows-form-user-control-in-mfc"></a>Usando um controle de usuário do Windows Form no MFC

Usando as classes de suporte do MFC Windows Forms, você pode hospedar Windows Forms controles em seus aplicativos MFC como um controle ActiveX nas caixas de diálogo ou exibições do MFC. Além disso, Windows Forms formulários podem ser hospedados como caixas de diálogo MFC.

As seções a seguir descrevem como:

- Hospede um controle de Windows Forms em uma caixa de diálogo MFC.

- Hospede um Windows Forms controle de usuário como uma exibição do MFC.

- Hospede um formulário de Windows Forms como uma caixa de diálogo MFC.

> [!NOTE]
> A integração do MFC Windows Forms funciona apenas em projetos que se vinculam dinamicamente ao MFC `_AFXDLL` (projetos em que o está definido).

> [!NOTE]
> Quando você cria seu aplicativo usando uma cópia privada (modificada) da DLL de interfaces Windows Forms MFC (mfcmifc80. dll), ela não será instalada no GAC, a menos que você substitua a chave da Microsoft por sua própria chave de fornecedor. Para obter mais informações sobre assinatura de assembly, consulte [programação com assemblies](/dotnet/framework/app-domains/programming-with-assemblies) e [assemblies de nome forte (assinaturaC++de assembly) (/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).

Se seu aplicativo MFC usa Windows Forms, você precisa redistribuir o mfcmifc80. dll com seu aplicativo. Para obter mais informações, consulte [Redistribuindo a biblioteca do MFC](../windows/redistributing-the-mfc-library.md).

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

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Exibições de formulário](../mfc/form-views-mfc.md)
