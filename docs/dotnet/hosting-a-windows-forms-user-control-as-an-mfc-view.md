---
title: Hospedar um Windows Forms de controle de usuário como uma exibição MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms controls [C++], hosting as an MFC view
- hosting Windows Forms control [C++]
ms.assetid: 43c02ab4-1366-434c-a980-0b19326d6ea0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: bf9e54b3e2808a232bc13052c885a341cb51297f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hosting-a-windows-forms-user-control-as-an-mfc-view"></a>Hospedando um controle de usuário dos Windows Forms como uma exibição MFC
MFC usa a classe CWinFormsView para hospedar um controle de usuário do Windows Forms em uma exibição MFC. Modos de exibição de formulários do Windows MFC são controles ActiveX. O controle de usuário é hospedado como um filho do modo nativo e ocupa toda a área cliente do modo nativo.  
  
 O resultado final se parece com o modelo usado pelo [CFormView classe](../mfc/reference/cformview-class.md). Isso permite aproveitar o designer de formulários do Windows e o tempo de execução para criar exibições avançadas baseado em formulário.  
  
 Como os modos de exibição de formulários do Windows MFC são controles ActiveX, eles não têm o mesmo `hwnd` como modos de exibição do MFC. Também não pode ser passados como um ponteiro para um [CView](../mfc/reference/cview-class.md) exibição. Em geral, use métodos do .NET Framework para trabalhar com exibições de formulários do Windows e confiar menos no Win32.  
  
 Para um aplicativo de exemplo que mostra usado com MFC de formulários do Windows, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Como criar o controle de usuário e o host em uma exibição de MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md)  
  
 [Como adicionar roteamento de comando ao controle do Windows Forms](../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)  
  
 [Como chamar propriedades e métodos do controle do Windows Forms](../dotnet/how-to-call-properties-and-methods-of-the-windows-forms-control.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Como criar controles de composição](/dotnet/framework/winforms/controls/how-to-author-composite-controls)