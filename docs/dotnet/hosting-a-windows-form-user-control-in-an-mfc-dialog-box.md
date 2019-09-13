---
title: Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- hosting Windows Forms control [C++]
- Windows Forms [C++], MFC support
ms.assetid: 9f66ee52-b7cb-4ffd-8306-392a5da990d8
ms.openlocfilehash: 22f2c5c6c162e459470f9babab66c61c096540ec
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "70311755"
---
# <a name="hosting-a-windows-form-user-control-in-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC

O MFC hospeda um controle de Windows Forms como um tipo especial de controle ActiveX e se comunica com o controle usando interfaces ActiveX e propriedades e métodos da <xref:System.Windows.Forms.Control> classe. É recomendável que você use .NET Framework Propriedades e métodos para operar no controle.

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

> [!NOTE]
>  Na versão atual, um `CDialogBar` objeto não pode hospedar Windows Forms controles.

## <a name="in-this-section"></a>Nesta seção

[Como: criar o controle de usuário e o host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)

[Como: Fazer associação de dados campo DDX/DDV com Windows Forms](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md)

[Como: coletar eventos do Windows Forms de classes C++ nativas](../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)

## <a name="reference"></a>Referência

[Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md) &#124; [Classe CDialog](../mfc/reference/cdialog-class.md) &#124; [classe CWnd](../mfc/reference/cwnd-class.md) &#124; <xref:System.Windows.Forms.Control>

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Diferenças de programação entre o Windows Forms e o MFC](../dotnet/windows-forms-mfc-programming-differences.md)<br/>
[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)<br/>
[Hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md)
