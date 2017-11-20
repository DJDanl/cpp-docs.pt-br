---
title: "Como: criar o controle de usuário e o Host em uma caixa de diálogo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- MFC [C++], hosting a Windows Forms Control
- Windows Forms [C++], MFC support
ms.assetid: 03a53032-2f03-4fa2-b567-031615a26011
caps.latest.revision: "29"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cf0372029a6f6f3c2e2d3030d9e04ddcf6483f14
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-create-the-user-control-and-host-in-a-dialog-box"></a>Como criar o controle de usuário e hospedá-lo em uma caixa de diálogo
As etapas neste artigo presumem que você está criando uma caixa de diálogo com base em ([classe CDialog](../mfc/reference/cdialog-class.md)) projeto Microsoft Foundation Classes (MFC), mas você também pode adicionar suporte para um controle de formulários do Windows para uma caixa de diálogo MFC existente.  
  
### <a name="to-create-the-net-user-control"></a>Ao criar o controle de usuário do .NET  
  
1.  Crie um projeto do Visual c# Windows Forms biblioteca de controle chamado `WindowsFormsControlLibrary1`.  
  
     Sobre o **arquivo** menu, clique em **novo** e, em seguida, clique em **projeto**. No **Visual C#** pasta, selecione **biblioteca de controle de formulários do Windows**.  
  
     Aceitar o `WindowsFormsControlLibrary1` nome do projeto, clicando em **Okey**.  
  
     Por padrão, o nome do controle .NET será `UserControl1`.  
  
2.  Adicionar controles filho a `UserControl1`.  
  
     No **caixa de ferramentas**, abra o **todos os Windows Forms** lista. Arraste um **botão** o controle para o `UserControl1` superfície de design.  
  
     Também adicionar uma **TextBox** controle.  
  
3.  Em **Solution Explorer**, clique duas vezes em **UserControl1.Designer.cs** para abri-lo para edição. Alterar as declarações de caixa de texto e o botão de `private` para `public`.  
  
4.  Compile o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Crie um projeto de aplicativo do MFC.  
  
     Sobre o **arquivo** menu, clique em **novo** e, em seguida, clique em **projeto**. No **Visual C++** pasta, selecione **aplicativo MFC**.  
  
     Na caixa **Nome**, digite `MFC01`. Altere a configuração de solução para **adicionar à solução**. Clique em **OK**.  
  
     No **Assistente de aplicativo MFC**, para o tipo de aplicativo, selecione **caixa de diálogo com base em**. Aceite as configurações padrão restantes e clique em **concluir**. Isso cria um aplicativo MFC que tenha uma caixa de diálogo do MFC.  
  
2.  Adicione um controle de espaço reservado para a caixa de diálogo do MFC.  
  
     Sobre o **exibição** menu, clique em **exibição de recursos**. Em **exibição recursos**, expanda o **diálogo** pasta e clique duas vezes em `IDD_MFC01_DIALOG`. O recurso de caixa de diálogo é exibida no **Editor de recurso**.  
  
     No **caixa de ferramentas**, abra o **Editor de caixa de diálogo** lista. Arraste um **texto estático** controle para o recurso de caixa de diálogo. O **texto estático** controle servirá como um espaço reservado para o controle de formulários do Windows .NET. Redimensione-a aproximadamente ao tamanho do controle de formulários do Windows.  
  
     No **propriedades** janela, altere o **ID** do **texto estático** controle `IDC_CTRL1` e alterar o **TabStop** propriedade para **True**.  
  
3.  Configure o projeto para suporte a Common Language Runtime (CLR).  
  
     Em **Solution Explorer**, com o botão direito no nó do projeto MFC01 e, em seguida, clique em **propriedades**.  
  
     No **páginas de propriedade** caixa de diálogo **propriedades de configuração**, selecione **geral**. No **padrões do projeto** seção, defina **suporte a Common Language Runtime** para **tempo de execução de linguagem comum suporte (/ clr)**.  
  
     Em **propriedades de configuração**, expanda **C/C++** e selecione o **geral** nó. Definir **formato de informações de depuração** para **(/Zi) do banco de dados de programa**.  
  
     Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** para **não (/ Gm-)**. Também definir **verificações de tempo de execução básico** para **padrão**.  
  
     Clique em **Okey** para aplicar as alterações.  
  
4.  Adicione uma referência para o controle de .NET.  
  
     Em **Solution Explorer**, com o botão direito no nó do projeto MFC01 e, em seguida, clique em **adicionar**, **referências**. No **página de propriedades**, clique em **adicionar nova referência**, selecione **WindowsFormsControlLibrary1** (sob o **projetos** guia) e clique em **Okey**. Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa será compilado. Ele também coloca uma cópia do WindowsFormsControlLibrary1.dll na pasta do projeto \MFC01\ para que o programa será executado.  
  
5.  Em Stdafx. h, encontre esta linha:  
  
    ```  
    #endif // _AFX_NO_AFXCMN_SUPPORT   
    ```  
  
     Acima dele, adicione estas linhas:  
  
    ```  
    #include <afxwinforms.h>   // MFC Windows Forms support  
    ```  
  
6.  Adicione código para criar o controle gerenciado.  
  
     Primeiro, declare o controle gerenciado. Em MFC01Dlg.h, vá para a declaração da classe de caixa de diálogo e adicionar um membro de dados para o controle de usuário no escopo de protegido, da seguinte maneira.  
  
    ```  
    class CMFC01Dlg : public CDialog  
    {  
       // ...  
       // Data member for the .NET User Control:  
       CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_ctrl1;  
    ```  
  
     Em seguida, forneça uma implementação do controle gerenciado. Em MFC01Dlg.cpp, na caixa de diálogo Substituir de `CMFC01Dlg::DoDataExchange` que foi gerado pelo Assistente de aplicativo MFC (não `CAboutDlg::DoDataExchange`, que está no mesmo arquivo), adicione o seguinte código para criar o controle gerenciado e associá-lo com o estático de espaço reservado IDC_CTRL1.  
  
    ```  
    void CMFC01Dlg::DoDataExchange(CDataExchange* pDX)  
    {  
       CDialog::DoDataExchange(pDX);  
       DDX_ManagedControl(pDX, IDC_CTRL1, m_ctrl1);  
    }  
    ```  
  
7.  Compile e execute o projeto.  
  
     Em **Solution Explorer**, clique com botão direito **MFC01** e, em seguida, clique em **definir como projeto de inicialização**.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     Sobre o **depurar** menu, clique em **iniciar sem depuração**. A caixa de diálogo MFC deve exibir o controle de formulários do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md)