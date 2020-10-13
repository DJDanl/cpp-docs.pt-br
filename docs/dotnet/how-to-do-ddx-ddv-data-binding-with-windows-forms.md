---
title: 'Como: fazer a vinculação de dados DDX–DDV com o Windows Forms'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], hosting a Windows Forms Control
- Windows Forms [C++], MFC support
ms.assetid: b2957370-cf1f-4779-94ac-228cd393686c
ms.openlocfilehash: a0759eba1c55e72f2c0a99964b0b2d254df82a25
ms.sourcegitcommit: 43cee7a0d41a062661229043c2f7cbc6ace17fa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/13/2020
ms.locfileid: "92008316"
---
# <a name="how-to-do-ddxddv-data-binding-with-windows-forms"></a>Como fazer a associação de dados DDX/DDV aos Windows Forms

[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol) chama [CWinFormsControl:: CreateManagedControl](../mfc/reference/cwinformscontrol-class.md#createmanagedcontrol) para criar um controle que corresponda à ID de controle de recursos. Se você usar `DDX_ManagedControl` o para um `CWinFormsControl` controle (no código gerado pelo assistente), não deverá chamar `CreateManagedControl` explicitamente para o mesmo controle.

Chamada `DDX_ManagedControl` em [CWnd::D odataexchange](../mfc/reference/cwnd-class.md#dodataexchange) para criar controles de IDs de recurso. Para a troca de dados, você não precisa usar as funções campo DDX/DDV com controles Windows Forms. Em vez disso, você pode posicionar o código para acessar as propriedades do controle gerenciado no `DoDataExchange` método de sua classe de caixa de diálogo (ou exibição), como no exemplo a seguir.

O exemplo a seguir mostra como associar uma cadeia de caracteres C++ nativa a um controle de usuário do .NET.

## <a name="example-ddxddv-data-binding"></a>Exemplo: Associação de dados campo DDX/DDV

Veja a seguir um exemplo de associação de dados campo DDX/DDV de uma cadeia de caracteres MFC `m_str` com a propriedade definida pelo usuário `NameText` de um controle de usuário do .net.

O controle é criado quando [CDialog:: OnInitDialog](../mfc/reference/cdialog-class.md#oninitdialog) chama pela `CMyDlg::DoDataExchange` primeira vez, portanto, qualquer código que referencie `m_UserControl` deve vir após a `DDX_ManagedControl` chamada.

Você pode implementar esse código no aplicativo MFC01 criado em [como: criar o controle de usuário e o host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

Coloque o seguinte código na declaração de CMFC01Dlg:

```
class CMFC01Dlg : public CDialog
{
   CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_MyControl;
   CString m_str;
};
```

## <a name="example-implement-dodataexchange"></a>Exemplo: implemente DoDataExchange ()

Coloque o seguinte código na implementação de CMFC01Dlg:

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

## <a name="example-add-handler-method"></a>Exemplo: Adicionar método de manipulador

Agora, adicionaremos o método de manipulador para um clique no botão OK. Clique na guia **modo de exibição de recursos** . Em Modo de Exibição de Recursos, clique duas vezes em `IDD_MFC01_DIALOG` . O recurso de caixa de diálogo aparece no editor de recursos. Em seguida, clique duas vezes no botão OK.

Defina o manipulador da seguinte maneira.

```cpp
void CMFC01Dlg::OnBnClickedOk()
{
   AfxMessageBox(CString(m_MyControl.GetControl()->textBox1->Text));
   OnOK();
}
```

## <a name="example-set-the-textbox-text"></a>Exemplo: definir o texto de textBox

E adicione a seguinte linha à implementação de BOOL CMFC01Dlg:: OnInitDialog ().

```
m_MyControl.GetControl()->textBox1->Text = "hello";
```

Agora você pode compilar e executar o aplicativo. Observe que qualquer texto na caixa de texto será exibido em uma caixa de mensagem pop-up quando o aplicativo for fechado.

## <a name="see-also"></a>Veja também

[Classe CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)<br/>
[DDX_ManagedControl](../mfc/reference/standard-dialog-data-exchange-routines.md#ddx_managedcontrol)<br/>
[CWnd::D oDataExchange](../mfc/reference/cwnd-class.md#dodataexchange)
