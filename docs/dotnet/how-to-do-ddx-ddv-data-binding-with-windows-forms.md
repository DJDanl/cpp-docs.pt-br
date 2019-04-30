---
title: 'Como: Fazer DDX – DDV vinculação de dados com Windows Forms'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], hosting a Windows Forms Control
- Windows Forms [C++], MFC support
ms.assetid: b2957370-cf1f-4779-94ac-228cd393686c
ms.openlocfilehash: 558c763fd18cd1569ff23435bf6156b3117f117d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387312"
---
# <a name="how-to-do-ddxddv-data-binding-with-windows-forms"></a>Como: Fazer DDX/DDV vinculação de dados com Windows Forms

[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol) chamadas [CWinFormsControl::CreateManagedControl](../mfc/reference/cwinformscontrol-class.md#createmanagedcontrol) para criar um controle que corresponda a ID de controle de recurso. Se você usar `DDX_ManagedControl` para um `CWinFormsControl` controle (no código gerado pelo Assistente), você não deve chamar `CreateManagedControl` explicitamente para o mesmo controle.

Chame `DDX_ManagedControl` na [CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) para criar controles de IDs de recurso. Troca de dados, você não precisa usar as funções DDX/DDV com controles de Windows Forms. Em vez disso, você pode colocar o código para acessar as propriedades do controle gerenciado no `DoDataExchange` método de sua classe de caixa de diálogo (ou exibição), como no exemplo a seguir.

O exemplo a seguir mostra como associar uma cadeia de caracteres do C++ nativa para um controle de usuário do .NET.

## <a name="example"></a>Exemplo

A seguir está um exemplo de associação de dados DDX/DDV de uma cadeia de caracteres MFC `m_str` com o definido pelo usuário `NameText` propriedade de um controle de usuário do .NET.

O controle é criado quando [CDialog::OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) chamadas `CMyDlg::DoDataExchange` pela primeira vez, portanto, qualquer código que referencia `m_UserControl` deve vir após o `DDX_ManagedControl` chamar.

Você pode implementar esse código no aplicativo MFC01 criado no [como: Criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

Coloque o seguinte código na declaração de CMFC01Dlg:

```
class CMFC01Dlg : public CDialog
{
   CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_MyControl;
   CString m_str;
};
```

## <a name="example"></a>Exemplo

Coloque o código a seguir na implementação de CMFC01Dlg:

```
void CMFC01Dlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   DDX_ManagedControl(pDX, IDC_CTRL1, m_MyControl);

   if (pDX->m_bSaveAndValidate) {
      m_str = m_MyControl->textBox1->Text;
   } else
   {
      m_MyControl->textBox1->Text = gcnew System::String(m_str);
   }
}
```

## <a name="example"></a>Exemplo

Agora, adicionaremos o método de manipulador para um clique no botão Okey. Clique o **exibição de recurso** guia. No modo de exibição de recursos, clique duas vezes em `IDD_MFC01_DIALOG`. O recurso de caixa de diálogo é exibida no Editor de recursos. Em seguida, clique duas vezes no botão Okey...

Defina o manipulador da seguinte maneira.

```
void CMFC01Dlg::OnBnClickedOk()
{
   AfxMessageBox(CString(m_MyControl.GetControl()->textBox1->Text));
   OnOK();
}
```

## <a name="example"></a>Exemplo

E adicione a seguinte linha à implementação de CMFC01Dlg::OnInitDialog() BOOL.

```
m_MyControl.GetControl()->textBox1->Text = "hello";
```

Agora você pode compilar e executar o aplicativo. Observe que qualquer texto na caixa de texto será exibido em uma caixa de mensagem pop-up quando o aplicativo é fechado.

## <a name="see-also"></a>Consulte também

[Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)<br/>
[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol)<br/>
[CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange)
