---
title: Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- hosting Windows Forms control [C++]
- Windows Forms [C++], MFC support
ms.assetid: 9f66ee52-b7cb-4ffd-8306-392a5da990d8
ms.openlocfilehash: 2704e04df3792edfee6c39f597fcbe71b6ce51b4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374495"
---
# <a name="hosting-a-windows-form-user-control-in-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC

O MFC hospeda um controle do Windows Forms como um tipo especial de controle ActiveX e <xref:System.Windows.Forms.Control> se comunica com o controle usando interfaces ActiveX e propriedades e métodos da classe. Recomendamos que você use propriedades e métodos do .NET Framework para operar no controle.

Para obter um aplicativo de exemplo que mostra os Formulários do Windows usados com o MFC, consulte [a integração de formulários MFC e Windows](https://www.microsoft.com/download/details.aspx?id=2113).

> [!NOTE]
> Na versão atual, `CDialogBar` um objeto não pode hospedar controles do Windows Forms.

## <a name="in-this-section"></a>Nesta seção

[Como criar o controle de usuário e hospedá-lo em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)

[Como: Fazer a vinculação de dados DDX/DDV com formulários do Windows](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md)

[Como coletar eventos dos Windows Forms a partir de classes C++ nativas](../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)

## <a name="reference"></a>Referência

[CWinFormsControlClass](../mfc/reference/cwinformscontrol-class.md) &#124; [CDialog Class](../mfc/reference/cdialog-class.md) &#124; [CWnd Class](../mfc/reference/cwnd-class.md) &#124;<xref:System.Windows.Forms.Control>

## <a name="see-also"></a>Confira também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Diferenças de programação do Windows Forms/MFC](../dotnet/windows-forms-mfc-programming-differences.md)<br/>
[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)<br/>
[Hospedando um controle de usuário do formulário do Windows como uma caixa de diálogo MFC](../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md)
