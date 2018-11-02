---
title: Hospedando um controle de usuário dos Windows Forms como uma exibição MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms controls [C++], hosting as an MFC view
- hosting Windows Forms control [C++]
ms.assetid: 43c02ab4-1366-434c-a980-0b19326d6ea0
ms.openlocfilehash: c041ae941858184245879ced972c19e6e998b677
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544554"
---
# <a name="hosting-a-windows-forms-user-control-as-an-mfc-view"></a>Hospedando um controle de usuário dos Windows Forms como uma exibição MFC

MFC usa a classe CWinFormsView para hospedar um controle de usuário do Windows Forms em uma exibição do MFC. Modos de exibição do MFC Windows Forms são controles ActiveX. O controle de usuário está hospedado como um filho do modo nativo e ocupa toda a área cliente do modo nativo.

O resultado final se parece com o modelo usado pelas [classe CFormView](../mfc/reference/cformview-class.md). Isso permite aproveitar o designer de formulários do Windows e o tempo de execução para criar modos de exibição avançados baseado em formulário.

Como os modos de exibição do MFC Windows Forms são controles ActiveX, eles não têm o mesmo `hwnd` como modos de exibição do MFC. Também não pode ser passados como um ponteiro para um [CView](../mfc/reference/cview-class.md) exibição. Em geral, use métodos do .NET Framework para trabalhar com modos de exibição de formulários do Windows e confiar menos no Win32.

Para um aplicativo de exemplo que mostra os formulários do Windows usado com o MFC, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

## <a name="in-this-section"></a>Nesta seção

[Como criar o controle de usuário e o host em uma exibição de MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md)

[Como adicionar roteamento de comando ao controle do Windows Forms](../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)

[Como chamar propriedades e métodos do controle do Windows Forms](../dotnet/how-to-call-properties-and-methods-of-the-windows-forms-control.md)

## <a name="see-also"></a>Consulte também

[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)<br/>
[Como criar controles de composição](/dotnet/framework/winforms/controls/how-to-author-composite-controls)