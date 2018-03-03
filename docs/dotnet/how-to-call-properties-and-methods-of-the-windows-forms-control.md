---
title: "Como: chamar propriedades e métodos do Windows Forms de controle | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs:
- C++
helpviewer_keywords:
- method calls, Windows Forms
- calling methods, Windows Forms control
- calling properties, Windows Forms control
- Windows Forms controls [C++], methods
- calling properties
- Windows Forms controls [C++], properties
ms.assetid: 6e647d8a-fdaa-4aa1-b3fe-04f15cff8eb3
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: eebbc955a0b44b686986e5bd1e753ec8809a3a1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-call-properties-and-methods-of-the-windows-forms-control"></a>Como chamar propriedades e métodos do controle dos Windows Forms
Porque [CWinFormsView::GetControl](../mfc/reference/cwinformsview-class.md#getcontrol) retorna um ponteiro para <xref:System.Windows.Forms.Control?displayProperty=fullName>e não um ponteiro para `WindowsControlLibrary1::UserControl1`, é recomendável adicionar um membro do tipo de controle do usuário e inicializá-lo em [IView::OnInitialUpdate ](../mfc/reference/iview-interface.md#oninitialupdate). Agora você pode chamar métodos e propriedades usando `m_ViewControl`.  
  
 Este tópico pressupõe que você concluiu anteriormente [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Abra o aplicativo do MFC criado na [como: criar o controle de usuário e uma exibição MDI Host](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).  
  
2.  Adicione a seguinte linha à seção pública substituições de `CMFC02View` declaração em MFC02View.h de classe.  
  
     `gcroot<WindowsFormsControlLibrary1::UserControl1 ^> m_ViewControl;`  
  
3.  Adicione uma substituição para OnInitialupdate.  
  
     Exibição de **propriedades** janela (F4). Em **exibição de classe** (CTRL + SHIFT + C), selecione a classe CMFC02View. No **propriedades** janela, selecione o ícone de substituições. Scoll para baixo na lista para OnInitialUpdate. Clique na lista suspensa lista e selecione \<Adicionar >. Em MFC02View.cpp. Verifique se que o corpo da função OnInitialUpdate é da seguinte maneira:  
  
    ```  
    CWinFormsView::OnInitialUpdate();  
    m_ViewControl = safe_cast<WindowsFormsControlLibrary1::UserControl1 ^>(this->GetControl());  
    m_ViewControl->textBox1->Text = gcnew System::String("hi");  
    ```  
  
4.  Compile e execute o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
     Observe que a caixa de texto agora é inicializada.  
  
## <a name="see-also"></a>Consulte também  
 [Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)