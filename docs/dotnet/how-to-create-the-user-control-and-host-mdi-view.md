---
title: "Como criar o controle de usu&#225;rio e hospedar uma exibi&#231;&#227;o MDI | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
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
  - "MFC [C++], Controles de Windows Forms"
  - "Windows Forms [C++], Suporte MFC"
ms.assetid: 625b5821-f923-4701-aca0-c1a4ceca4f63
caps.latest.revision: 25
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como criar o controle de usu&#225;rio e hospedar uma exibi&#231;&#227;o MDI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As etapas a seguir mostram como criar um controle de usuário do .NET Framework, criar o controle de usuário em uma biblioteca de classe do controle \(especificamente, um projeto da Biblioteca de Controles do Windows\) e compilar o projeto em um assembly.  O controle pode, então, ser consumido de um aplicativo do MFC que usa classes derivadas de [Classe de CView](../Topic/CView%20Class.md) e de [Classe de CWinFormsView](../mfc/reference/cwinformsview-class.md).  
  
 Para obter informações sobre como criar um controle de usuário do Windows Forms e criar uma biblioteca de classes de controle, consulte [Como criar controles de usuário](../Topic/How%20to:%20Author%20Composite%20Controls.md).  
  
> [!NOTE]
>  Em alguns casos, os controles do Windows Forms, como um controle de Grade de terceiros, podem não se comportar confiavelmente quando hospedados em um aplicativo MFC.  Uma solução recomendada é colocar um controle de usuário do Windows Forms no aplicativo MFC e colocar o controle de grade de terceiros dentro do controle de usuário.  
  
 Este procedimento presume que você criou um projeto da Biblioteca de Controles do Windows Forms denominado WindowsFormsControlLibrary1, de acordo com o procedimento descrito em [Como criar o controle de usuário e hospedá\-lo em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).  
  
### Para criar o aplicativo de host do MFC  
  
1.  Criar um projeto de aplicativo do MFC.  
  
     No menu **Arquivo**, selecione **Novo** e clique em **Projeto**.  Na pasta **Visual C\+\+**, selecione **Aplicativo do MFC**.  
  
     Na caixa **Nome**, insira `MFC02` e altere a configuração de **Solução** para **Adicionar à Solução**.  Clique em **OK**.  
  
     No **Assistente para Aplicativo do MFC**, aceite todos os padrões e clique em **Concluir**.  Isso cria um aplicativo do MFC com uma Interface de Documentos Múltiplos.  
  
2.  Configure o projeto para o suporte do Common Language Runtime \(CLR\).  
  
     No **Gerenciador de Soluções**, clique com o botão direito no nó de projeto `MFC01` e selecione **Propriedades** no menu de contexto.  A caixa de diálogo **Páginas de Propriedades** é exibida.  
  
     Em **Propriedades de Configuração**, selecione **Geral**.  Na seção **Padrões de Projeto** , defina **Suporte ao Common Language Runtime** como **Suporte a Common Language Runtime \(\/clr\)**.  
  
     Em **Propriedades de Configuração**, expanda **C\/C\+\+** e clique no nó **Geral**.  Definir **Formato de Informação de Depuração** para **Banco de Dados do Programa \(\/Zi\)**.  
  
     Clique no nó **Geração de Código**.  Definir **Habilita Recompilação Mínima** para **Não \(\/Gm\-\)**.  Também define as **Verificações básicas em tempo de execução** com **Padrão**.  
  
     Clique em **OK** para aplicar suas alterações.  
  
3.  Em stdafx.h, adicione a seguinte linha:  
  
    ```  
    #using <System.Windows.Forms.dll>  
    ```  
  
4.  Adicione uma referência controle .NET.  
  
     No **Gerenciador de Soluções**, clique com o botão direito no nó de projeto `MFC02` e selecione **Adicionar**, **Referências**.  Na **Página de Propriedades**, clique em **Adicionar Nova Referência**, selecione WindowsFormsControlLibrary1 \(na guia de **Projetos**\) e clique **OK**.  Isso adiciona uma referência na forma de uma opção de compilador [\/FU](../build/reference/fu-name-forced-hash-using-file.md), de modo que o programa compilará; também copia WindowsFormsControlLibrary1.dll para o diretório do projeto `MFC02`, de modo que o programa será executado.  
  
5.  Em stdafx.h, localize esta linha:  
  
    ```  
    #endif // _AFX_NO_AFXCMN_SUPPORT   
    ```  
  
     Acima, adicione essas linhas:  
  
    ```  
    #include <afxwinforms.h>   // MFC Windows Forms support  
    ```  
  
6.  Modifique a classe de visualização para que herde de [CWinFormsView](../mfc/reference/cwinformsview-class.md).  
  
     Em MFC02View.h, substitua [CView](../Topic/CView%20Class.md) com [CWinFormsView](../mfc/reference/cwinformsview-class.md) de modo que o código apareça da seguinte maneira:  
  
    ```  
    class CMFC02View : public CWinFormsView  
    {  
    };  
    ```  
  
     Se você deseja adicionar exibições adicionais ao seu aplicativo MDI, precisará chamar [CWinApp::AddDocTemplate](../Topic/CWinApp::AddDocTemplate.md) para cada modo de exibição criado.  
  
7.  Modifique o arquivo MFC02View.cpp para alterar CView para CWinFormsView no mapa de macro e mensagem IMPLEMENT\_DYNCREATE e substitua o construtor vazio existente pelo construtor mostrado abaixo:  
  
    ```  
    IMPLEMENT_DYNCREATE(CMFC02View, CWinFormsView)  
  
    CMFC02View::CMFC02View(): CWinFormsView(WindowsFormsControlLibrary1::UserControl1::typeid)   
    {  
    }  
    BEGIN_MESSAGE_MAP(CMFC02View, CWinFormsView)  
    //leave existing body as is  
    END_MESSAGE_MAP()  
    ```  
  
8.  Criar e executar o projeto.  
  
     No **Gerenciador de Soluções**, clique com o botão direito em MFC02 e selecione **Definir como Projeto de Inicialização**.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     No menu **Depurar**, clique em **Iniciar sem depuração**.  
  
## Consulte também  
 [Hospedando um controle de usuário dos Windows Forms como uma exibição MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)