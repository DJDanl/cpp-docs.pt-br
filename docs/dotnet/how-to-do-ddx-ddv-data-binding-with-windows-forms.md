---
title: "Como fazer a associa&#231;&#227;o de dados DDX/DDV aos Windows Forms | Microsoft Docs"
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
  - "MFC [C++], hospedando um Controle do Windows Forms"
  - "Windows Forms [C++], Suporte MFC"
ms.assetid: b2957370-cf1f-4779-94ac-228cd393686c
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como fazer a associa&#231;&#227;o de dados DDX/DDV aos Windows Forms
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[DDX\_ManagedControl](../Topic/DDX_ManagedControl.md) chama [CWinFormsControl::CreateManagedControl](../Topic/CWinFormsControl::CreateManagedControl.md) para criar um controle que corresponde à ID do recurso de controle  Se você usar `DDX_ManagedControl` para um controle de `CWinFormsControl` \(no código script MDX\), você não deve chamar explicitamente `CreateManagedControl` para o mesmo controle.  
  
 Chame `DDX_ManagedControl` em [CWnd::DoDataExchange](../Topic/CWnd::DoDataExchange.md) para criar o controla os IDs de recursos.  Para troca de dados, você não precisa usar as funções de DDX\/DDV com controles do Windows Forms.  Em vez disso, você pode colocar o código para acessar as propriedades do controle gerenciado pelo método de `DoDataExchange` da sua classe da caixa de diálogo \(ou exibição\), como no exemplo a seguir.  
  
 O exemplo a seguir mostra como associar uma cadeia de caracteres do C\+\+ nativo para um controle de usuário do .NET.  
  
## Exemplo  
 O seguinte é um exemplo de associação de dados de DDX\/DDV de uma cadeia de caracteres `m_str` MFC com a propriedade definida pelo usuário de `NameText` de um controle de usuário do .NET.  
  
 O controle é criado quando [CDialog::OnInitDialog](../Topic/CDialog::OnInitDialog.md) chama `CMyDlg::DoDataExchange` pela primeira vez, de modo que qualquer código que faz referência `m_UserControl` deve vir depois da chamada de `DDX_ManagedControl` .  
  
 Você pode implementar esse código no aplicativo que MFC01 você criou em [Como criar o controle de usuário e hospedá\-lo em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).  
  
 Coloque o código a seguir na declaração de CMFC01Dlg:  
  
```  
class CMFC01Dlg : public CDialog  
{  
   CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_MyControl;  
   CString m_str;  
};  
```  
  
## Exemplo  
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
  
## Exemplo  
 Agora adicionaremos o método do manipulador para um clique no botão OK.  Clique na guia de **Modo de Exibição de Recurso** .  Na exibição de recursos, clique duas vezes em `IDD_MFC01_DIALOG`.  O recurso de caixa de diálogo aparece em Editor de Recurso.  Fazer vezes no botão OK.  
  
 Define o manipulador da seguinte maneira.  
  
```  
void CMFC01Dlg::OnBnClickedOk()  
{  
   AfxMessageBox(CString(m_MyControl.GetControl()->textBox1->Text));  
   OnOK();  
}  
```  
  
## Exemplo  
 E adicione a seguinte linha para a implementação de BOOL CMFC01Dlg::OnInitDialog\(\).  
  
```  
m_MyControl.GetControl()->textBox1->Text = "hello";  
```  
  
 Agora já é possível compilar e executar o aplicativo.  Observe que todo o texto na caixa de texto será exibido em uma caixa de mensagem pop\-up quando o aplicativo fechar.  
  
## Consulte também  
 [Classe de CWinFormsControl](../mfc/reference/cwinformscontrol-class.md)   
 [DDX\_ManagedControl](../Topic/DDX_ManagedControl.md)   
 [CWnd::DoDataExchange](../Topic/CWnd::DoDataExchange.md)