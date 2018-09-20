---
title: 'Como: chamar propriedades e métodos dos formulários do Windows controlam | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 1d3f8dc2251dbfbcd8155b0edc512a9dc40bacc2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393393"
---
# <a name="how-to-call-properties-and-methods-of-the-windows-forms-control"></a>Como chamar propriedades e métodos do controle dos Windows Forms

Porque [CWinFormsView::GetControl](../mfc/reference/cwinformsview-class.md#getcontrol) retorna um ponteiro para <xref:System.Windows.Forms.Control?displayProperty=fullName>e não um ponteiro para `WindowsControlLibrary1::UserControl1`, é recomendável adicionar um membro do tipo de controle do usuário e inicializá-lo no [IView::OnInitialUpdate ](../mfc/reference/iview-interface.md#oninitialupdate). Agora você pode chamar métodos e propriedades usando `m_ViewControl`.

Este tópico pressupõe que você concluiu previamente [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: criar o controle de usuário e a exibição do Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Abra o aplicativo do MFC que você criou na [como: criar o controle de usuário e a exibição do Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

1. Adicione a seguinte linha à seção pública substituições do `CMFC02View` declaração em MFC02View.h de classe.

     `gcroot<WindowsFormsControlLibrary1::UserControl1 ^> m_ViewControl;`

1. Adicione uma substituição para OnInitialupdate.

     Exibição de **propriedades** janela (F4). Na **modo de exibição de classe** (CTRL + SHIFT + C), selecione a classe CMFC02View. No **propriedades** janela, selecione o ícone para substituições. Scoll para baixo na lista para OnInitialUpdate. Clique no menu suspenso lista e selecione \<Add >. No MFC02View.cpp. Verifique se que o corpo da função OnInitialUpdate é da seguinte maneira:

    ```
    CWinFormsView::OnInitialUpdate();
    m_ViewControl = safe_cast<WindowsFormsControlLibrary1::UserControl1 ^>(this->GetControl());
    m_ViewControl->textBox1->Text = gcnew System::String("hi");
    ```

1. Compile e execute o projeto.

     No menu **Compilar**, clique em **Compilar Solução**.

     Sobre o **Debug** menu, clique em **iniciar sem depuração**.

     Observe que a caixa de texto agora é inicializada.

## <a name="see-also"></a>Consulte também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)