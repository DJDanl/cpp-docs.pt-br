---
title: "Hospedando um controle de usu&#225;rio do Windows Form em uma caixa de di&#225;logo MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "hospedando controle do Windows Forms [C++]"
  - "MFC [C++], suporte ao Windows Forms"
  - "Windows Forms [C++], Suporte MFC"
ms.assetid: 9f66ee52-b7cb-4ffd-8306-392a5da990d8
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Hospedando um controle de usu&#225;rio do Windows Form em uma caixa de di&#225;logo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O MFC hospeda um controle do Windows Forms como um tipo especial de controle ActiveX e se comunica com o controle ActiveX, usando as interfaces e as propriedades e os métodos da classe de <xref:System.Windows.Forms.Control> .  Recomendamos que você use as propriedades e os métodos do.NET Framework para operar no controle.  
  
 Para obter um aplicativo de exemplo que mostre o Windows Forms usado com o MFC, consulte [MFC e integração do Windows Forms](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
> [!NOTE]
>  Na versão atual, um objeto de `CDialogBar` não pode hospedar controles do Windows Forms.  
  
## Nesta seção  
 [Como criar o controle de usuário e hospedá\-lo em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)  
  
 [Como fazer a associação de dados DDX\/DDV aos Windows Forms](../dotnet/how-to-do-ddx-ddv-data-binding-with-windows-forms.md)  
  
 [Como coletar eventos dos Windows Forms a partir de classes C\+\+ nativas](../Topic/How%20to:%20Sink%20Windows%20Forms%20Events%20from%20Native%20C++%20Classes.md)  
  
## Referência  
 [Classe de CWinFormsControl](../mfc/reference/cwinformscontrol-class.md) &#124; [Classe de CDialog](../mfc/reference/cdialog-class.md) &#124; [CWnd Class](../Topic/CWnd%20Class.md) &#124; <xref:System.Windows.Forms.Control>  
  
## Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Windows Forms\/diferenças de programação MFC](../dotnet/windows-forms-mfc-programming-differences.md)   
 [Hospedando um controle de usuário dos Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)   
 [Hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC](../Topic/Hosting%20a%20Windows%20Form%20User%20Control%20as%20an%20MFC%20Dialog%20Box.md)