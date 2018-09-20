---
title: Hospedando um Windows formam o controle de usuário como uma caixa de diálogo do MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], hosting as MFC Dialog
- hosting Windows Forms control [C++]
ms.assetid: 0434a9d7-8b14-48e6-ad69-9ba9a684677a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 2355a5341259978e402ecc6f8de5c684c9435e3a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46433056"
---
# <a name="hosting-a-windows-form-user-control-as-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC

O MFC fornece a classe de modelo [CWinFormsDialog](../mfc/reference/cwinformsdialog-class.md) para que você possa hospedar um controle de usuário do Windows Forms (<xref:System.Windows.Forms.UserControl>) em uma caixa de diálogo modal ou sem-modo do MFC. `CWinFormsDialog` é derivado da classe do MFC [CDialog](../mfc/reference/cdialog-class.md), portanto, a caixa de diálogo pode ser iniciada como modal ou sem janela restrita.

O processo que `CWinFormsDialog` usa para hospedar o controle de usuário é semelhante ao descrito em [hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md). No entanto, `CWinFormsDialog` gerencia a inicialização e a hospedagem do controle de usuário para que ele não tem de ser programado manualmente.

Para um aplicativo de exemplo que mostra os formulários do Windows usado com o MFC, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Crie um projeto de aplicativo do MFC.

     Sobre o **arquivo** menu, selecione **New**e, em seguida, clique em **projeto**. No **Visual C++** pasta e selecione **aplicativo MFC**.

     No **nome** , digite `MFC03` e altere a configuração de solução para **adicionar à solução**. Clique em **Okey**.

     No **Assistente de aplicativo MFC**, aceite todos os padrões e, em seguida, clique em **concluir**. Isso cria um aplicativo MFC com uma Interface de documentos múltiplos.

1. Configure o projeto.

     No **Gerenciador de soluções**, clique com botão direito do **MFC03** nó do projeto e escolha **propriedades**. O **páginas de propriedade** caixa de diálogo é exibida.

     No **páginas de propriedades** na caixa a **propriedades de configuração** controle de árvore, selecione **geral**, em seguida, no **padrõesdeprojeto**seção, defina **suporte a Common Language Runtime** para **suporte a Common Language Runtime (/ clr)**. Clique em **OK**.

1. Adicione uma referência ao controle .NET.

     Na **Gerenciador de soluções**, clique com botão direito do **MFC03** nó do projeto e escolha **adicionar**, **referências**. No **página de propriedades**, clique em **adicionar nova referência**, selecione WindowsControlLibrary1 (sob o **projetos** guia) e clique em **Okey**. Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa compilará; também copia WindowsControlLibrary1.dll para o `MFC03` diretório do projeto para que o programa será executado.

1. Adicione `#include <afxwinforms.h>` a Stdafx. h, no final da existente `#include` instruções.

1. Adicione uma nova classe que pode efetuar subclasses `CDialog`.

     Clique com o botão direito no nome do projeto e adicionar uma classe MFC (chamada CHostForWinForm) que pode efetuar subclasses `CDialog`. Uma vez que você não precisar do recurso de caixa de diálogo, você pode excluir a ID de recurso (selecione o modo de exibição de recursos, expanda a pasta de caixa de diálogo e exclua o recurso IDD_HOSTFORWINFORM.  Em seguida, remova todas as referências à ID no código.).

1. Substitua `CDialog` nos arquivos chostforwinform. H e chostforwinform. cpp com `CWinFormsDialog<WindowsControlLibrary1::UserControl1>`.

1. Chame DoModal na classe CHostForWinForm.

     Em MFC03.cpp, adicione `#include "HostForWinForm.h"`.

     Antes da instrução return na definição de CMFC03App::InitInstance, adicione:

    ```cpp
    CHostForWinForm m_HostForWinForm;
    m_HostForWinForm.DoModal();
    ```

1. Compile e execute o projeto.

     No menu **Compilar**, clique em **Compilar Solução**.

     Sobre o **Debug** menu, clique em **iniciar sem depuração**.

     Em seguida, você adicionará código para monitorar o estado de um controle nos formulários do Windows do aplicativo do MFC.

9. Adicione um manipulador para OnInitDialog.

     Exibição de **propriedades** janela (F4). Na **modo de exibição de classe**, selecione CHostForWinForm. No **propriedades** janela, selecione substituições e na linha para OnInitDialog, clique na coluna à esquerda e selecione \< Add >. Isso adiciona a seguinte linha a chostforwinform. H:

    ```cpp
    virtual BOOL OnInitDialog();
    ```

10. Defina OnInitDialog (em chostforwinform. cpp) da seguinte maneira:

    ```
    BOOL CHostForWinForm::OnInitDialog() {
       CWinFormsDialog<WindowsControlLibrary1::UserControl1>::OnInitDialog();
       GetControl()->button1->Click += MAKE_DELEGATE(System::EventHandler, OnButton1);
       return TRUE;
    }
    ```

11. Em seguida, adicione o manipulador OnButton1. Adicione as seguintes linhas para a seção pública da classe CHostForWinForm em chostforwinform. H:

    ```
    virtual void OnButton1( System::Object^ sender, System::EventArgs^ e );

    BEGIN_DELEGATE_MAP( CHostForWinForm )
       EVENT_DELEGATE_ENTRY( OnButton1, System::Object^, System::EventArgs^ );
    END_DELEGATE_MAP()
    ```

     Em chostforwinform. cpp, adicione esta definição:

    ```
    void CHostForWinForm::OnButton1( System::Object^ sender, System::EventArgs^ e )
    {
       System::Windows::Forms::MessageBox::Show("test");
    }
    ```

12. Compile e execute o projeto. Quando você clica no botão, o que está no formulário do Windows, o código no aplicativo MFC será executado.

     Em seguida, você adicionará código para exibir o valor do código do MFC na caixa de texto do formulário do Windows.

13. Na seção pública da classe CHostForWinForm em chostforwinform. H, adicione a seguinte declaração:

    ```
    CString m_sEditBoxOnWinForm;
    ```

14. Na definição de DoDataExchange em chostforwinform. cpp, adicione as seguintes três linhas ao final da função:

    ```
    if (pDX->m_bSaveAndValidate)
       m_sEditBoxOnWinForm = CString( GetControl()->textBox1->Text);
    else
       GetControl()->textBox1->Text = gcnew System::String(m_sEditBoxOnWinForm);
    ```

15. Na definição de OnButton1 em chostforwinform. cpp, adicione as seguintes três linhas ao final da função:

    ```
    this->UpdateData(TRUE);
    System::String ^ z = gcnew System::String(m_sEditBoxOnWinForm);
    System::Windows::Forms::MessageBox::Show(z);
    ```

16. Compile e execute o projeto.

## <a name="see-also"></a>Consulte também

<xref:System.Windows.Forms.UserControl?displayProperty=fullName>
[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)