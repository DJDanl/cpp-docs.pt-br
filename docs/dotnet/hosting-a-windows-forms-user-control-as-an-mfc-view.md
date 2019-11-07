---
title: Hospedando um controle de usuário dos Windows Forms como uma exibição MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms controls [C++], hosting as an MFC view
- hosting Windows Forms control [C++]
ms.assetid: 43c02ab4-1366-434c-a980-0b19326d6ea0
ms.openlocfilehash: 9eb157ecbc738e1d7a1c3022d5f156fb590e8f04
ms.sourcegitcommit: 45f1d889df633f0f7e4a8e813b46fa73c9858b81
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/06/2019
ms.locfileid: "73704120"
---
# <a name="hosting-a-windows-forms-user-control-as-an-mfc-view"></a>Hospedando um controle de usuário dos Windows Forms como uma exibição MFC

O MFC usa a classe CWinFormsView para hospedar um Windows Forms controle de usuário em uma exibição do MFC. Os modos de exibição do MFC Windows Forms são controles ActiveX. O controle de usuário é hospedado como um filho do modo de exibição nativo e ocupa toda a área do cliente da exibição nativa.

O resultado final é semelhante ao modelo usado pela [classe CFormView](../mfc/reference/cformview-class.md). Isso permite que você tire proveito do designer de Windows Forms e do tempo de execução para criar exibições baseadas em formulário sofisticadas.

Como as exibições do MFC Windows Forms são controles ActiveX, elas não têm as mesmas `hwnd` que as exibições do MFC. Além disso, eles não podem ser passados como um ponteiro para uma exibição [cvisualização](../mfc/reference/cview-class.md) . Em geral, use .NET Framework métodos para trabalhar com Windows Forms exibições e contar com menos no Win32.

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/en-us/download/details.aspx?id=2113).

## <a name="in-this-section"></a>Nesta seção

[Como criar o controle de usuário e o host em uma exibição de MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md)

[Como adicionar roteamento de comando ao controle do Windows Forms](../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)

[Como chamar propriedades e métodos do controle do Windows Forms](../dotnet/how-to-call-properties-and-methods-of-the-windows-forms-control.md)

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Como criar controles de composição](/dotnet/framework/winforms/controls/how-to-author-composite-controls)
