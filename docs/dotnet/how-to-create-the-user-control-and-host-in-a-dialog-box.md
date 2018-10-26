---
title: 'Como: criar o controle de usuário e o Host em uma caixa de diálogo | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], hosting a Windows Forms Control
- Windows Forms [C++], MFC support
ms.assetid: 03a53032-2f03-4fa2-b567-031615a26011
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 97dde9c90b3cf5c4c4e1e705a605dce98d755abb
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50072532"
---
# <a name="how-to-create-the-user-control-and-host-in-a-dialog-box"></a>Como criar o controle de usuário e hospedá-lo em uma caixa de diálogo

As etapas neste artigo pressupõem que você está criando uma caixa de diálogo com base em ([classe CDialog](../mfc/reference/cdialog-class.md)) project do Microsoft Foundation Classes (MFC), mas você também pode adicionar suporte para um controle dos Windows Forms a uma caixa de diálogo MFC existente.

### <a name="to-create-the-net-user-control"></a>Para criar o controle de usuário do .NET

1. Crie um projeto do Visual c# Windows Forms biblioteca de controle chamado `WindowsFormsControlLibrary1`.

   Sobre o **arquivo** menu, clique em **New** e, em seguida, clique em **projeto**. No **Visual c#** pasta e selecione **biblioteca de controle do Windows Forms**.

   Aceitar os `WindowsFormsControlLibrary1` nome do projeto, clicando em **Okey**.

   Por padrão, o nome do controle .NET será `UserControl1`.

1. Adicionar controles filho para `UserControl1`.

   No **caixa de ferramentas**, abra o **todos os Windows Forms** lista. Arraste uma **botão** o controle para o `UserControl1` superfície de design.

   Adicione também uma **caixa de texto** controle.

1. Na **Gerenciador de soluções**, clique duas vezes em **UserControl1.Designer.cs** para abri-lo para edição. Altere as declarações da caixa de texto e o botão a partir `private` para `public`.

1. Compile o projeto.

   No menu **Compilar**, clique em **Compilar Solução**.

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Crie um projeto de aplicativo do MFC.

   Sobre o **arquivo** menu, clique em **New** e, em seguida, clique em **projeto**. No **Visual C++** pasta e selecione **aplicativo MFC**.

   Na caixa **Nome**, digite `MFC01`. Altere a configuração de solução para **adicionar a solução**. Clique em **OK**.

   No **Assistente de aplicativo MFC**, para o tipo de aplicativo, selecione **caixa de diálogo com base em**. Aceite as configurações padrão restantes e clique em **concluir**. Isso cria um aplicativo do MFC que tem uma caixa de diálogo do MFC.

1. Adicione um controle de espaço reservado para a caixa de diálogo do MFC.

   Sobre o **modo de exibição** menu, clique em **exibição de recurso**. Na **exibição de recurso**, expanda o **caixa de diálogo** pasta e clique duas vezes em `IDD_MFC01_DIALOG`. O recurso de caixa de diálogo aparece no **Editor de recurso**.

   No **caixa de ferramentas**, abra o **Editor de caixa de diálogo** lista. Arraste uma **texto estático** controle para o recurso de caixa de diálogo. O **texto estático** controle servirá como um espaço reservado para o controle do .NET Windows Forms. Redimensione-o para aproximadamente o tamanho do controle do Windows Forms.

   No **propriedades** janela, altere o **ID** da **texto estático** o controle para `IDC_CTRL1` e altere o **TabStop** propriedade para **Verdadeira**.

1. Configure o projeto para o suporte de tempo de execução de linguagem comum (CLR).

   Na **Gerenciador de soluções**, clique com botão direito no nó de projeto MFC01 e, em seguida, clique em **propriedades**.

   No **páginas de propriedades** caixa de diálogo **propriedades de configuração**, selecione **geral**. No **padrões de projeto** seção, defina **suporte do Common Language Runtime** para **suporte a Common Language Runtime (/ clr)**.

   Sob **propriedades de configuração**, expanda **C/C++** e selecione o **geral** nó. Definir **formato de informações de depuração** à **programa (/Zi) do banco de dados**.

   Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** à **não (/ Gm-)**. Também defina **verificações básicas de tempo de execução** à **padrão**.

   Clique em **Okey** para aplicar as alterações.

1. Adicione uma referência ao controle .NET.

   Na **Gerenciador de soluções**, clique com botão direito no nó de projeto MFC01 e, em seguida, clique em **Add**, **referências**. Sobre o **página de propriedades**, clique em **adicionar nova referência**, selecione **WindowsFormsControlLibrary1** (sob o **projetos** guia) e clique em **Okey**. Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa será compilado. Ele também coloca uma cópia de WindowsFormsControlLibrary1.dll na pasta do projeto \MFC01\ para que o programa será executado.

1. Em Stdafx. h, localize esta linha:

    ```
    #endif // _AFX_NO_AFXCMN_SUPPORT
    ```

   Acima, adicione estas linhas:

    ```
    #include <afxwinforms.h>   // MFC Windows Forms support
    ```

1. Adicione código para criar o controle gerenciado.

   Primeiro, declare o controle gerenciado. Em MFC01Dlg.h, vá para a declaração da classe de caixa de diálogo e adicionar um membro de dados para o controle de usuário no escopo protegido, da seguinte maneira.

    ```
    class CMFC01Dlg : public CDialog
    {
       // ...
       // Data member for the .NET User Control:
       CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_ctrl1;
    ```

   Em seguida, fornece uma implementação para o controle gerenciado. Em MFC01Dlg.cpp, na caixa de diálogo Substituir da `CMFC01Dlg::DoDataExchange` que foi gerado pelo Assistente de aplicativo MFC (não `CAboutDlg::DoDataExchange`, que está no mesmo arquivo), adicione o seguinte código para criar o controle gerenciado e associá-lo com o suporte de local estático IDC_CTRL1.

    ```
    void CMFC01Dlg::DoDataExchange(CDataExchange* pDX)
    {
       CDialog::DoDataExchange(pDX);
       DDX_ManagedControl(pDX, IDC_CTRL1, m_ctrl1);
    }
    ```

1. Compile e execute o projeto.

   Na **Gerenciador de soluções**, clique com botão direito **MFC01** e, em seguida, clique em **Set as StartUp Project**.

   No menu **Compilar**, clique em **Compilar Solução**.

   Sobre o **Debug** menu, clique em **iniciar sem depuração**. A caixa de diálogo MFC deve exibir o controle Windows Forms.

## <a name="see-also"></a>Consulte também

[Hospedando um controle de usuário do Windows Form em uma caixa de diálogo do MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md)