---
title: Hospedando um controle de usuário dos Windows Forms como uma exibição MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms controls [C++], hosting as an MFC view
- hosting Windows Forms control [C++]
ms.assetid: 43c02ab4-1366-434c-a980-0b19326d6ea0
ms.openlocfilehash: df193bae541aecf8416056c2b169f0079539d173
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "70311891"
---
# <a name="hosting-a-windows-forms-user-control-as-an-mfc-view"></a>Hospedando um controle de usuário dos Windows Forms como uma exibição MFC

O MFC usa a classe CWinFormsView para hospedar um Windows Forms controle de usuário em uma exibição do MFC. Os modos de exibição do MFC Windows Forms são controles ActiveX. O controle de usuário é hospedado como um filho do modo de exibição nativo e ocupa toda a área do cliente da exibição nativa.

O resultado final é semelhante ao modelo usado pela [classe CFormView](../mfc/reference/cformview-class.md). Isso permite que você tire proveito do designer de Windows Forms e do tempo de execução para criar exibições baseadas em formulário sofisticadas.

Como as exibições do MFC Windows Forms são controles ActiveX, elas não têm `hwnd` o mesmo que as exibições do MFC. Além disso, eles não podem ser passados como um ponteiro para uma exibição [cvisualização](../mfc/reference/cview-class.md) . Em geral, use .NET Framework métodos para trabalhar com Windows Forms exibições e contar com menos no Win32.

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

## <a name="in-this-section"></a>Nesta seção

[Como: criar o controle de usuário e o host em uma exibição de MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md)

[Como: adicionar roteamento de comando ao controle do Windows Forms](../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)

[Como: chamar propriedades e métodos do controle do Windows Forms](../dotnet/how-to-call-properties-and-methods-of-the-windows-forms-control.md)

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Como: Controles de composição de autor](/dotnet/framework/winforms/controls/how-to-author-composite-controls)
