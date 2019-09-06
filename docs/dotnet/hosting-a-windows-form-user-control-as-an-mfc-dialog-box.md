---
title: Hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], hosting as MFC Dialog
- hosting Windows Forms control [C++]
ms.assetid: 0434a9d7-8b14-48e6-ad69-9ba9a684677a
ms.openlocfilehash: 96730cb3902674373e3e2429b7bc51cbbe257ff3
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "70311634"
---
# <a name="hosting-a-windows-form-user-control-as-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC

O MFC fornece a classe de modelo [CWinFormsDialog](../mfc/reference/cwinformsdialog-class.md) para que você possa hospedar um controle de<xref:System.Windows.Forms.UserControl>usuário Windows Forms () em uma caixa de diálogo modal ou do MFC sem janela. `CWinFormsDialog`é derivado da classe MFC [CDialog](../mfc/reference/cdialog-class.md), portanto, a caixa de diálogo pode ser iniciada como modal ou sem janela restrita.

O processo que `CWinFormsDialog` o usa para hospedar o controle de usuário é semelhante ao descrito em [hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md). No entanto, `CWinFormsDialog` o gerencia a inicialização e a hospedagem do controle de usuário para que ele não precise ser programado manualmente.

Para um aplicativo de exemplo que mostra Windows Forms usado com MFC, consulte [integração do MFC e do Windows Forms](https://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo host do MFC

1. Crie um projeto de aplicativo do MFC.

   No menu **arquivo** , selecione **novo**e, em seguida, clique em **projeto**. Na pasta **Visual C++**  , selecione **aplicativo MFC**.

   Na caixa **nome** , insira `MFC03` e altere a configuração da solução para **Adicionar à solução**. Clique em **OK**.

   No **Assistente de aplicativo do MFC**, aceite todos os padrões e clique em **concluir**. Isso cria um aplicativo MFC com uma interface de vários documentos.

1. Configure o projeto.

   Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó do projeto **MFC03** e escolha **Propriedades**. A caixa de diálogo **páginas de propriedades** é exibida.

   Na caixa de diálogo **páginas de propriedade** , no controle árvore de **Propriedades de configuração** , selecione **geral**e, em seguida, na seção **padrões do projeto** , defina **suporte ao Common Language Runtime** para suporte a **Common Language Runtime ( /CLR)** . Clique em **OK**.

1. Adicione uma referência ao controle .NET.

   Em **Gerenciador de soluções**, clique com o botão direito do mouse no nó do projeto **MFC03** e escolha **Adicionar**, **referências**. Na **página de propriedades**, clique em **Adicionar nova referência**, selecione WindowsControlLibrary1 (na guia **projetos** ) e clique em **OK**. Isso adiciona uma referência na forma de uma opção de compilador [/Fu](../build/reference/fu-name-forced-hash-using-file.md) para que o programa seja compilado; Ele também copia WindowsControlLibrary1. dll no `MFC03` diretório do projeto para que o programa seja executado.

1. Adicione `#include <afxwinforms.h>` a *PCH. h* (*stdafx. h* no Visual Studio 2017 e anteriores), no final das instruções existentes `#include` .

1. Adicione uma nova classe que subclasses `CDialog`.

   Clique com o botão direito do mouse no nome do projeto e adicione uma classe do MFC ( `CDialog`chamada CHostForWinForm) que subclasses. Como você não precisa do recurso caixa de diálogo, você pode excluir a ID do recurso (selecione **modo de exibição de recursos**, a pasta de **diálogo** e `IDD_HOSTFORWINFORM` excluir recurso.  Em seguida, remova todas as referências à ID no código.).

1. Substitua `CDialog` nos arquivos CHostForWinForm. h e CHostForWinForm. cpp por `CWinFormsDialog<WindowsControlLibrary1::UserControl1>`.

1. Chame DoModal na classe CHostForWinForm.

   Em MFC03. cpp, adicione `#include "HostForWinForm.h"`.

   Antes da instrução return na definição de CMFC03App:: InitInstance, adicione:

    ```cpp
    CHostForWinForm m_HostForWinForm;
    m_HostForWinForm.DoModal();
    ```

1. Compile e execute o projeto.

   No menu **Compilar**, clique em **Compilar Solução**.

   No menu **depurar** , clique em **Iniciar sem Depurar**.

   Em seguida, você adicionará o código para monitorar o estado de um controle no Windows Forms do aplicativo MFC.

1. Adicione um manipulador para OnInitDialog.

   Exibe a janela **Propriedades** (F4). Em **modo de exibição de classe**, selecione CHostForWinForm. Na janela **Propriedades** , selecione substituições e, na linha para OnInitDialog, clique na coluna esquerda e selecione \< Adicionar >. Isso adiciona a seguinte linha a CHostForWinForm. h:

    ```cpp
    virtual BOOL OnInitDialog();
    ```

1. Defina OnInitDialog (em CHostForWinForm. cpp) da seguinte maneira:

    ```cpp
    BOOL CHostForWinForm::OnInitDialog() {
       CWinFormsDialog<WindowsControlLibrary1::UserControl1>::OnInitDialog();
       GetControl()->button1->Click += MAKE_DELEGATE(System::EventHandler, OnButton1);
       return TRUE;
    }
    ```

1. Em seguida, adicione o manipulador OnButton1. Adicione as seguintes linhas à seção pública da classe CHostForWinForm em CHostForWinForm. h:

    ```cpp
    virtual void OnButton1( System::Object^ sender, System::EventArgs^ e );

    BEGIN_DELEGATE_MAP( CHostForWinForm )
       EVENT_DELEGATE_ENTRY( OnButton1, System::Object^, System::EventArgs^ );
    END_DELEGATE_MAP()
    ```

   Em CHostForWinForm. cpp, adicione esta definição:

    ```cpp
    void CHostForWinForm::OnButton1( System::Object^ sender, System::EventArgs^ e )
    {
       System::Windows::Forms::MessageBox::Show("test");
    }
    ```

1. Compile e execute o projeto. Quando você clica no botão, que está no formulário do Windows, o código no aplicativo MFC será executado.

    Em seguida, você adicionará o código para exibir a partir do código MFC o valor na caixa de texto no formulário do Windows.

1. Na seção pública da classe CHostForWinForm em CHostForWinForm. h, adicione a seguinte declaração:

    ```cpp
    CString m_sEditBoxOnWinForm;
    ```

1. Na definição de DoDataExchange em CHostForWinForm. cpp, adicione as três linhas a seguir ao final da função:

    ```cpp
    if (pDX->m_bSaveAndValidate)
       m_sEditBoxOnWinForm = CString( GetControl()->textBox1->Text);
    else
       GetControl()->textBox1->Text = gcnew System::String(m_sEditBoxOnWinForm);
    ```

1. Na definição de OnButton1 em CHostForWinForm. cpp, adicione as três linhas a seguir ao final da função:

    ```cpp
    this->UpdateData(TRUE);
    System::String ^ z = gcnew System::String(m_sEditBoxOnWinForm);
    System::Windows::Forms::MessageBox::Show(z);
    ```

1. Compile e execute o projeto.

## <a name="see-also"></a>Consulte também

<xref:System.Windows.Forms.UserControl?displayProperty=fullName>
[Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)
