---
title: "Como chamar propriedades e m&#233;todos do controle dos Windows Forms | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "chamando métodos, Controle de Windows Forms"
  - "chamando propriedades"
  - "chamando propriedades, Controle de Windows Forms"
  - "chamadas de método, Windows Forms"
  - "Controles de Windows Forms [C++], métodos"
  - "Controles de Windows Forms [C++], propriedades"
ms.assetid: 6e647d8a-fdaa-4aa1-b3fe-04f15cff8eb3
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como chamar propriedades e m&#233;todos do controle dos Windows Forms
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como [CWinFormsView::GetControl](../Topic/CWinFormsView::GetControl.md) retorna um ponteiro para <xref:System.Windows.Forms.Control?displayProperty=fullName>, e não um ponteiro para `WindowsControlLibrary1::UserControl1`, é aconselhável adicionar um membro do tipo de controle de usuário e para inicializá\-lo em [IView::OnInitialUpdate](../Topic/IView::OnInitialUpdate.md).  Agora você pode chamar métodos e propriedades usando `m_ViewControl`.  
  
 Este tópico pressupõe que você completou anteriormente [Como criar o controle de usuário e hospedá\-lo em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [Como criar o controle de usuário e hospedar uma exibição MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
### Para criar o aplicativo de host do MFC  
  
1.  Abra o aplicativo do MFC que você criou no [Como criar o controle de usuário e hospedar uma exibição MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
2.  Adicione a seguinte linha na seção pública das substituições de declaração de classe de `CMFC02View` em MFC02View.h.  
  
     `gcroot<WindowsFormsControlLibrary1::UserControl1 ^> m_ViewControl;`  
  
3.  Adicionar uma substituição para OnInitialupdate.  
  
     Exibir a janela de **Propriedades** \(F4\).  Em **Modo de Exibição de Classe** \(CTRL\+SHIFT\+C\), selecione a classe de CMFC02View.  Na janela de **Propriedades** , selecione o ícone para substituições.  Role para baixo na lista OnInitialUpdate.  Clique na lista suspensa e selecione \<adicionar\>.  Em MFC02View.cpp verifique se o corpo da função de OnInitialUpdate é a seguinte:  
  
    ```  
    CWinFormsView::OnInitialUpdate();  
    m_ViewControl = safe_cast<WindowsFormsControlLibrary1::UserControl1 ^>(this->GetControl());  
    m_ViewControl->textBox1->Text = gcnew System::String("hi");  
    ```  
  
4.  Criar e executar o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     No menu **Depurar**, clique em **Iniciar sem depuração**.  
  
     Observe que a caixa de texto é inicializada agora.  
  
## Consulte também  
 [Hospedando um controle de usuário dos Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)