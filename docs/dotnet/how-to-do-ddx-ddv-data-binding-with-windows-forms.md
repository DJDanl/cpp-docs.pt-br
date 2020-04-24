---
title: Como fazer a vinculação de dados DDX–DDV com o Windows Forms
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], hosting a Windows Forms Control
- Windows Forms [C++], MFC support
ms.assetid: b2957370-cf1f-4779-94ac-228cd393686c
ms.openlocfilehash: 31629a4db2559112ba49f5c069b08de7abdfc2db
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754354"
---
# <a name="how-to-do-ddxddv-data-binding-with-windows-forms"></a>Como fazer a associação de dados DDX/DDV aos Windows Forms

[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol) chama [CWinFormsControl::CreateManagedControl](../mfc/reference/cwinformscontrol-class.md#createmanagedcontrol) para criar um controle que corresponda ao ID de controle de recursos. Se você `DDX_ManagedControl` usar `CWinFormsControl` para um controle (em código `CreateManagedControl` gerado pelo assistente), você não deve chamar explicitamente para o mesmo controle.

Ligue `DDX_ManagedControl` [para CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) para criar controles a partir de IDs de recursos. Para a troca de dados, você não precisa usar as funções DDX/DDV com controles do Windows Forms. Em vez disso, você pode colocar código para `DoDataExchange` acessar as propriedades do controle gerenciado no método de sua classe de diálogo (ou visualização), como no exemplo a seguir.

O exemplo a seguir mostra como vincular uma seqüência c++ nativa a um controle de usuário .NET.

## <a name="example"></a>Exemplo

A seguir, um exemplo da vinculação de dados DDX/DDV de uma seqüência `m_str` de MFC com a propriedade definida pelo `NameText` usuário de um controle de usuário .NET.

O controle é criado quando [o CDialog::OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) é chamado `CMyDlg::DoDataExchange` pela `m_UserControl` primeira vez, `DDX_ManagedControl` portanto, qualquer código que as referências devem vir após a chamada.

Você pode implementar esse código no aplicativo MFC01 que você criou em [Como: Criar o Controle do Usuário e hospedar em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

Coloque o seguinte código na declaração de CMFC01Dlg:

```
class CMFC01Dlg : public CDialog
{
   CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_MyControl;
   CString m_str;
};
```

## <a name="example"></a>Exemplo

Coloque o seguinte código na implementação do CMFC01Dlg:

```cpp
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

Agora vamos adicionar o método handler para um clique no botão OK. Clique na **guia 'Exibir recursos'.** Na exibição de recursos, clique duas vezes em `IDD_MFC01_DIALOG`. O recurso de diálogo é exibido no Resource Editor. Em seguida, clique duas vezes no botão OK..

Defina o manipulador da seguinte forma.

```cpp
void CMFC01Dlg::OnBnClickedOk()
{
   AfxMessageBox(CString(m_MyControl.GetControl()->textBox1->Text));
   OnOK();
}
```

## <a name="example"></a>Exemplo

E adicione a seguinte linha à implementação do BOOL CMFC01Dlg::OnInitDialog().

```
m_MyControl.GetControl()->textBox1->Text = "hello";
```

Agora você pode compilar e executar o aplicativo. Observe que qualquer texto na caixa de texto será exibido em uma caixa de mensagens pop-up quando o aplicativo fechar.

## <a name="see-also"></a>Confira também

[Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)<br/>
[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol)<br/>
[CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange)
