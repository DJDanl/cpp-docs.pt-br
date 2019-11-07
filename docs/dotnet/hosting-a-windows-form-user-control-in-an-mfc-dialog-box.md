---
title: Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- hosting Windows Forms control [C++]
- Windows Forms [C++], MFC support
ms.assetid: 9f66ee52-b7cb-4ffd-8306-392a5da990d8
ms.openlocfilehash: 1a688870f4700e8e3b935245f2c9243f8d5aa823
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73704094"
---
# <a name="hosting-a-windows-form-user-control-in-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC

O MFC hospeda um controle de Windows Forms como um tipo especial de controle ActiveX e se comunica com o controle usando interfaces ActiveX e propriedades e métodos da classe <xref:System.Windows.Forms.Control>. É recomendável que você use .NET Framework Propriedades e métodos para operar no controle.

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/en-us/download/details.aspx?id=2113).

> [!NOTE]
>  Na versão atual, um objeto `CDialogBar` não pode hospedar Windows Forms controles.

## <a name="in-this-section"></a>Nesta seção

[Como criar o controle de usuário e o host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)

[Como: fazer a associação de dados campo DDX/DDV com Windows Forms](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md)

[Como coletar eventos do Windows Forms de classes C++ nativas](../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)

## <a name="reference"></a>Referência

&#124; Classe [CWinFormsControl](../mfc/reference/cwinformscontrol-class.md) classe [CDialog](../mfc/reference/cdialog-class.md) &#124; classe [CWnd](../mfc/reference/cwnd-class.md) &#124; <xref:System.Windows.Forms.Control>

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Diferenças de programação entre o Windows Forms e o MFC](../dotnet/windows-forms-mfc-programming-differences.md)<br/>
[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)<br/>
[Hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md)
