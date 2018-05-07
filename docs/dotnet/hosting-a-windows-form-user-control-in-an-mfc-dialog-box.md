---
title: Hospedando um Windows formam o controle de usuário em uma caixa de diálogo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- hosting Windows Forms control [C++]
- Windows Forms [C++], MFC support
ms.assetid: 9f66ee52-b7cb-4ffd-8306-392a5da990d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 291c0856e9d305e0b2b31c6bc233005b111592a9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="hosting-a-windows-form-user-control-in-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC
MFC hospeda um controle de formulários do Windows como um tipo especial de controle ActiveX e se comunica com o controle usando interfaces ActiveX e propriedades e métodos do <xref:System.Windows.Forms.Control> classe. É recomendável que você usar métodos e propriedades do .NET Framework para operar no controle.  
  
 Para um aplicativo de exemplo que mostra usado com MFC de formulários do Windows, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
> [!NOTE]
>  Na versão atual, um `CDialogBar` objeto não é possível hospedar controles de formulários do Windows.  
  
## <a name="in-this-section"></a>Nesta seção  
 [Como criar o controle de usuário e o host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)  
  
 [Como: fazer a associação de dados DDX/DDV aos Windows Forms](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md)  
  
 [Como coletar eventos do Windows Forms de classes C++ nativas](../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)  
  
## <a name="reference"></a>Referência  
 [Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md) &#124; [classe CDialog](../mfc/reference/cdialog-class.md) &#124; [classe CWnd](../mfc/reference/cwnd-class.md)&#124; <xref:System.Windows.Forms.Control>  
  
## <a name="see-also"></a>Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Diferenças de programação do Windows Forms/MFC](../dotnet/windows-forms-mfc-programming-differences.md)   
 [Hospedando um controle de usuário do Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)   
 [Hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md)