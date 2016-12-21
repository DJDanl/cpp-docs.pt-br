---
title: "Como criar o controle de usu&#225;rio e hosped&#225;-lo em uma caixa de di&#225;logo | Microsoft Docs"
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
ms.assetid: 03a53032-2f03-4fa2-b567-031615a26011
caps.latest.revision: 29
caps.handback.revision: 29
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar o controle de usu&#225;rio e hosped&#225;-lo em uma caixa de di&#225;logo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As etapas neste artigo presumem que você está criando um projeto \([Classe de CDialog](../mfc/reference/cdialog-class.md)\) baseado em diálogo da Microsoft Foundation Classes \(MFC\), mas você também pode adicionar suporte para um controle de Windows Forms em uma caixa de diálogo MFC existente.  
  
### Criar o controle de usuário do .NET  
  
1.  Crie um projeto de Biblioteca de controle do Windows Forms do Visual C\# chamado `WindowsFormsControlLibrary1`.  
  
     No menu **Arquivo**, clique em **Novo** e em **Projeto**.  Na pasta **Visual C\#**, selecione **Biblioteca de Controle do Windows Forms**.  
  
     Aceite o nome do projeto de `WindowsFormsControlLibrary1` clicando em **OK**.  
  
     Por padrão, o nome do controle do .NET será `UserControl1`.  
  
2.  Adicionar controles filho ao `UserControl1`.  
  
     Na **Caixa de Ferramentas**, abra a lista **Todos os Windows Forms**.  Arraste um controle de **Botão** para a superfície de design do `UserControl1`.  
  
     Adicione também um controle de **Caixa de Texto**.  
  
3.  No **Gerenciador de Soluções**, clique duas vezes em **UserControl1.Designer.cs** para abri\-lo para edição.  Altere as declarações da Caixa de Texto e do Botão de `private` para `public`.  
  
4.  Crie o projeto.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
### Para criar o aplicativo de host do MFC  
  
1.  Criar um projeto de aplicativo do MFC.  
  
     No menu **Arquivo**, clique em **Novo** e em **Projeto**.  Na pasta **Visual C\+\+**, selecione **Aplicativo do MFC**.  
  
     Na caixa **Nome**, digite `MFC01`.  Altere a configuração de Solução para **Adicionar à Solução**.  Clique em **OK**.  
  
     No **Assistente para Aplicativo do MFC**, para o Tipo de Aplicativo, selecione **Baseado em caixa de diálogo**.  Aceite as configurações padrão restantes e clique em **Concluir**.  Isso cria um aplicativo do MFC que tem uma caixa de diálogo MFC.  
  
2.  Adicionar um controle de espaço reservado para a caixa de diálogo MFC.  
  
     No menu **Exibir**, clique em **Exibição de Recurso**.  No **Modo de Exibição de Recurso**, expanda a pasta **Caixa de Diálogo** e clique duas vezes em `IDD_MFC01_DIALOG`.  O recurso de caixa de diálogo aparece em **Editor de Recurso**.  
  
     Na **Caixa de Ferramentas**, abra a lista **Editor de Caixa de Diálogo**.  Arraste um controle **Texto Estático** para o recurso de caixa de diálogo.  O controle de **Texto estático** servirá como um espaço reservado para o controle de Windows Forms .NET.  Redimensione\-o para aproximadamente o tamanho do controle do Windows Forms.  
  
     Na janela **Propriedades**, altere a **ID** do controle **Texto Estático** para `IDC_CTRL1` e altere a propriedade **TabStop** para **Verdadeiro**.  
  
3.  Configure o projeto para o suporte do Common Language Runtime \(CLR\).  
  
     No **Gerenciador de Soluções**, clique com o botão direito no nó de projeto MFC01 e clique em **Propriedades**.  
  
     Na caixa de diálogo **Páginas de Propriedade**, em **Propriedades de Configuração**, selecione **Geral**.  Na seção **Padrões de Projeto** , defina **Suporte ao Common Language Runtime** como **Suporte a Common Language Runtime \(\/clr\)**.  
  
     Em **Propriedades de Configuração**, expanda **C\/C\+\+** e selecione o nó **Geral**.  Definir **Formato de Informação de Depuração** para **Banco de Dados do Programa \(\/Zi\)**.  
  
     Selecione o nó **Geração de Código**.  Definir **Habilita Recompilação Mínima** para **Não \(\/Gm\-\)**.  Também define as **Verificações básicas em tempo de execução** com **Padrão**.  
  
     Clique em **OK** para aplicar as alterações.  
  
4.  Adicione uma referência controle .NET.  
  
     No **Gerenciador de Soluções**, clique com o botão direito no nó de projeto MFC01 e, em seguida, clique em **Adicionar**, **Referências**.  Na **Página de Propriedades**, clique em **Adicionar Nova Referência**, selecione **WindowsFormsControlLibrary1** \(na guia **Projetos**\) e clique em **OK**.  Isso adiciona uma referência na forma de uma opção de compilador [\/FU](../build/reference/fu-name-forced-hash-using-file.md), de modo que o programa compilará.  Também coloca uma cópia de WindowsFormsControlLibrary1.dll na pasta \\MFC01\\ do projeto para que o programa seja executado.  
  
5.  Em Stdafx.h, localize esta linha:  
  
    ```  
    #endif // _AFX_NO_AFXCMN_SUPPORT   
    ```  
  
     Acima, adicione essas linhas:  
  
    ```  
    #include <afxwinforms.h>   // MFC Windows Forms support  
    ```  
  
6.  Adicionar código para criar o controle gerenciado.  
  
     Primeiro, declare o controle gerenciado.  Em MFC01Dlg.h, vá para a declaração de classe da caixa de diálogo e adicione um membro de dados para o controle de usuário no escopo Protegido, como a seguir.  
  
    ```  
    class CMFC01Dlg : public CDialog  
    {  
       // ...  
       // Data member for the .NET User Control:  
       CWinFormsControl<WindowsFormsControlLibrary1::UserControl1> m_ctrl1;  
    ```  
  
     Em seguida, forneça uma implementação para o controle gerenciado.  Em MFC01Dlg.cpp, a substituição da caixa de diálogo `CMFC01Dlg::DoDataExchange` gerada pelo assistente de Aplicativo MFC \(não `CAboutDlg::DoDataExchange`, que está no mesmo arquivo\), adicione o seguinte código para criar o controle gerenciado e associá\-lo com o suporte de local estático IDC\_CTRL1.  
  
    ```  
    void CMFC01Dlg::DoDataExchange(CDataExchange* pDX)  
    {  
       CDialog::DoDataExchange(pDX);  
       DDX_ManagedControl(pDX, IDC_CTRL1, m_ctrl1);  
    }  
    ```  
  
7.  Criar e executar o projeto.  
  
     No **Gerenciador de Soluções**, clique com o botão direito em **MFC01** e, em seguida, clique em **Definir como Projeto de Inicialização**.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     No menu **Depurar**, clique em **Iniciar sem depuração**.  A caixa de diálogo MFC deve exibir o controle Windows Forms.  
  
## Consulte também  
 [Hospedando um controle de usuário do Windows Form em uma caixa de diálogo MFC](../dotnet/hosting-a-windows-form-user-control-in-an-mfc-dialog-box.md)