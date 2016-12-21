---
title: "Hospedando um controle de usu&#225;rio dos Windows Forms como uma exibi&#231;&#227;o MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "Controles de Windows Forms [C++], hospedando como uma exibição MFC"
ms.assetid: 43c02ab4-1366-434c-a980-0b19326d6ea0
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Hospedando um controle de usu&#225;rio dos Windows Forms como uma exibi&#231;&#227;o MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O usa a classe de CWinFormsView para hospedar um controle de usuário do Windows Forms em uma exibição de MFC.  As exibições do Windows Forms MFC são controles ActiveX.  O controle de usuário é hospedado como um filho da exibição nativo e ocupa a área de exibição inteira do cliente nativo.  
  
 O resultado final é semelhante ao modelo usado por [Classe de CFormView](../mfc/reference/cformview-class.md).  Isso permite usufruir do Windows Forms designer e tempo de execução para criar exibições baseada em formulários detalhadas.  
  
 Como as exibições do Windows Forms MFC são controles ActiveX, mesmo que não têm `hwnd` exibições de MFC.  Também não podem ser passados como um ponteiro para uma exibição de [CView](../Topic/CView%20Class.md) .  Em geral, métodos do .NET Framework de uso a trabalhar com exibições do Windows Forms e a menos confiar no Win32.  
  
 Para obter um aplicativo de exemplo que mostre o Windows Forms usado com o MFC, consulte [MFC e integração do Windows Forms](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
## Nesta seção  
 [Como criar o controle de usuário e hospedar uma exibição MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md)  
  
 [Como adicionar roteamento de comando ao controle dos Windows Forms](../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)  
  
 [Como chamar propriedades e métodos do controle dos Windows Forms](../dotnet/how-to-call-properties-and-methods-of-the-windows-forms-control.md)  
  
## Consulte também  
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)   
 [Como criar controles compostos](../Topic/How%20to:%20Author%20Composite%20Controls.md)