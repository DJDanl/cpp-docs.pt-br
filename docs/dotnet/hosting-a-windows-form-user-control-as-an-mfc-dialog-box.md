---
title: "Hospedando um Windows formam o controle de usuário como uma caixa de diálogo MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- Windows Forms [C++], hosting as MFC Dialog
- hosting Windows Forms control [C++]
ms.assetid: 0434a9d7-8b14-48e6-ad69-9ba9a684677a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7ad1d800619eb84a470dbc5e472e9191d13e8796
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hosting-a-windows-form-user-control-as-an-mfc-dialog-box"></a>Hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC
MFC fornece a classe de modelo [CWinFormsDialog](../mfc/reference/cwinformsdialog-class.md) para que você pode hospedar um controle de usuário do Windows Forms (<xref:System.Windows.Forms.UserControl>) em uma caixa de diálogo modal ou sem janela restrita do MFC. `CWinFormsDialog`é derivado da classe MFC [CDialog](../mfc/reference/cdialog-class.md), portanto, a caixa de diálogo pode ser iniciada como modal ou sem janela restrita.  
  
 O processo que `CWinFormsDialog` usa para hospedar o controle de usuário é semelhante ao descrito em [hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md). No entanto, `CWinFormsDialog` gerencia a inicialização e a hospedagem do controle de usuário para que ele não tem que ser programada manualmente.  
  
 Para um aplicativo de exemplo que mostra usado com MFC de formulários do Windows, consulte [MFC e integração de formulários do Windows](http://www.microsoft.com/downloads/details.aspx?FamilyID=987021bc-e575-4fe3-baa9-15aa50b0f599&displaylang=en).  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Crie um projeto de aplicativo do MFC.  
  
     Sobre o **arquivo** menu, selecione **novo**e, em seguida, clique em **projeto**. No **Visual C++** pasta, selecione **aplicativo MFC**.  
  
     No **nome** , digite `MFC03` e altere a configuração de solução para **adicionar à solução**. Clique em **Okey**.  
  
     No **Assistente de aplicativo MFC**, aceite todos os padrões e, em seguida, clique em **concluir**. Isso cria um aplicativo MFC com uma Interface de múltiplos documentos.  
  
2.  Configure o projeto.  
  
     Em **Solution Explorer**, com o botão direito do **MFC03** nó do projeto e escolha **propriedades**. O **páginas de propriedade** caixa de diálogo é exibida.  
  
     No **páginas de propriedade** na caixa a **propriedades de configuração** controle de árvore, selecione **geral**, em seguida, no **padrõesdoprojeto**seção, defina **suporte a Common Language Runtime** para **tempo de execução de linguagem comum suporte (/ clr)**. Clique em **OK**.  
  
3.  Adicione uma referência para o controle de .NET.  
  
     Em **Solution Explorer**, com o botão direito do **MFC03** nó do projeto e escolha **adicionar**, **referências**. No **página de propriedades**, clique em **adicionar nova referência**, selecione WindowsControlLibrary1 (sob o **projetos** guia) e clique em **Okey**. Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa será compilado; ele também copia WindowsControlLibrary1.dll para o `MFC03` diretório do projeto para que o programa será executado.  
  
4.  Adicionar `#include <afxwinforms.h>` para Stdafx. h, no final do existente `#include` instruções.  
  
5.  Adicionar uma nova classe que as subclasses `CDialog`.  
  
     Clique com o botão direito no nome do projeto e adicione uma classe do MFC (chamado CHostForWinForm) que as subclasses `CDialog`. Desde que você não precisar do recurso de caixa de diálogo, você pode excluir a ID de recurso (selecione o modo de exibição de recursos, expanda a pasta de caixa de diálogo e excluir recursos IDD_HOSTFORWINFORM.  Em seguida, remove quaisquer referências para a ID no código.).  
  
6.  Substituir `CDialog` em arquivos CHostForWinForm.h e CHostForWinForm.cpp com `CWinFormsDialog<WindowsControlLibrary1::UserControl1>`.  
  
7.  Chame DoModal na classe CHostForWinForm.  
  
     Em MFC03.cpp, adicione `#include "HostForWinForm.h"`.  
  
     Antes da instrução return na definição de CMFC03App::InitInstance, adicione:  
  
     `CHostForWinForm m_HostForWinForm;`  
  
     `m_HostForWinForm.DoModal();`  
  
8.  Compile e execute o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
     Em seguida, você adicionará código para monitorar o estado de um controle de formulários do Windows do aplicativo do MFC.  
  
9. Adicione um manipulador para OnInitDialog.  
  
     Exibição de **propriedades** janela (F4). Em **exibição de classe**, selecione CHostForWinForm. No **propriedades** janela, selecione substituições e na linha OnInitDialog, clique na coluna à esquerda e selecione \< Adicionar >. Isso adiciona a seguinte linha ao CHostForWinForm.h:  
  
    ```  
    virtual BOOL OnInitDialog();  
    ```  
  
10. Defina OnInitDialog (em CHostForWinForm.cpp) da seguinte maneira:  
  
    ```  
    BOOL CHostForWinForm::OnInitDialog() {  
       CWinFormsDialog<WindowsControlLibrary1::UserControl1>::OnInitDialog();  
       GetControl()->button1->Click += MAKE_DELEGATE(System::EventHandler, OnButton1);  
       return TRUE;  
    }  
    ```  
  
11. Em seguida, adicione o manipulador de OnButton1. Adicione as seguintes linhas para a seção pública da classe CHostForWinForm no CHostForWinForm.h:  
  
    ```  
    virtual void OnButton1( System::Object^ sender, System::EventArgs^ e );  
  
    BEGIN_DELEGATE_MAP( CHostForWinForm )  
       EVENT_DELEGATE_ENTRY( OnButton1, System::Object^, System::EventArgs^ );  
    END_DELEGATE_MAP()  
    ```  
  
     No CHostForWinForm.cpp, adicione essa definição:  
  
    ```  
    void CHostForWinForm::OnButton1( System::Object^ sender, System::EventArgs^ e )   
    {  
       System::Windows::Forms::MessageBox::Show("test");  
    }  
    ```  
  
12. Compile e execute o projeto. Quando você clica no botão, o que está em um formulário do Windows, o código do aplicativo do MFC será executado.  
  
     Em seguida, você adicionará código para exibir o valor do código MFC na caixa de texto no formulário do Windows.  
  
13. Na seção pública da classe CHostForWinForm no CHostForWinForm.h, adicione a declaração a seguir:  
  
    ```  
    CString m_sEditBoxOnWinForm;  
    ```  
  
14. Na definição de DoDataExchange em CHostForWinForm.cpp, adicione as seguintes três linhas ao final da função:  
  
    ```  
    if (pDX->m_bSaveAndValidate)  
       m_sEditBoxOnWinForm = CString( GetControl()->textBox1->Text);  
    else  
       GetControl()->textBox1->Text = gcnew System::String(m_sEditBoxOnWinForm);  
    ```  
  
15. Na definição de OnButton1 em CHostForWinForm.cpp, adicione as seguintes três linhas ao final da função:  
  
    ```  
    this->UpdateData(TRUE);  
    System::String ^ z = gcnew System::String(m_sEditBoxOnWinForm);  
    System::Windows::Forms::MessageBox::Show(z);  
    ```  
  
16. Compile e execute o projeto.  
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Windows.Forms.UserControl?displayProperty=fullName>   
 [Usando um controle de usuário do Windows Form no MFC](../dotnet/using-a-windows-form-user-control-in-mfc.md)