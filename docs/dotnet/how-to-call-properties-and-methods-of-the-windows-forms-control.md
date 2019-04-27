---
title: 'Como: Controlam chamar propriedades e métodos dos formulários do Windows'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- method calls, Windows Forms
- calling methods, Windows Forms control
- calling properties, Windows Forms control
- Windows Forms controls [C++], methods
- calling properties
- Windows Forms controls [C++], properties
ms.assetid: 6e647d8a-fdaa-4aa1-b3fe-04f15cff8eb3
ms.openlocfilehash: 61b565839b3f3c24670819fdcf2dde558e3461ac
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152797"
---
# <a name="how-to-call-properties-and-methods-of-the-windows-forms-control"></a>Como: Controlam chamar propriedades e métodos dos formulários do Windows

Porque [CWinFormsView::GetControl](../mfc/reference/cwinformsview-class.md#getcontrol) retorna um ponteiro para <xref:System.Windows.Forms.Control?displayProperty=fullName>e não um ponteiro para `WindowsControlLibrary1::UserControl1`, é recomendável adicionar um membro do tipo de controle do usuário e inicializá-lo no [IView::OnInitialUpdate ](../mfc/reference/iview-interface.md#oninitialupdate). Agora você pode chamar métodos e propriedades usando `m_ViewControl`.

Este tópico pressupõe que você concluiu previamente [como: Criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md) e [como: Criar o modo de exibição de controle de usuário e o Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Abra o aplicativo do MFC que você criou na [como: Criar o modo de exibição de controle de usuário e o Host MDI](../dotnet/how-to-create-the-user-control-and-host-mdi-view.md).

1. Adicione a seguinte linha à seção pública substituições do `CMFC02View` declaração em MFC02View.h de classe.

   `gcroot<WindowsFormsControlLibrary1::UserControl1 ^> m_ViewControl;`

1. Adicione uma substituição para OnInitialupdate.

   Exibição de **propriedades** janela (F4). Na **modo de exibição de classe** (CTRL + SHIFT + C), selecione a classe CMFC02View. No **propriedades** janela, selecione o ícone para substituições. Scoll para baixo na lista para OnInitialUpdate. Clique no menu suspenso lista e selecione \<Add >. In MFC02View.cpp. Verifique se que o corpo da função OnInitialUpdate é da seguinte maneira:

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
