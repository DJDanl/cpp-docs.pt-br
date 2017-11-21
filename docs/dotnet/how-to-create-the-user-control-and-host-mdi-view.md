---
title: "Como: criar o controle de usuário e hospedar uma exibição MDI | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
helpviewer_keywords:
- MFC [C++], Windows Forms Controls
- Windows Forms [C++], MFC support
ms.assetid: 625b5821-f923-4701-aca0-c1a4ceca4f63
caps.latest.revision: "25"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 298a08689d6c4aa69d4a52af5fad965e3e353b5c
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-create-the-user-control-and-host-mdi-view"></a>Como criar o controle de usuário e hospedar uma exibição MDI
As etapas a seguir mostram como criar um controle de usuário do .NET Framework, criar o controle de usuário em uma biblioteca de classe de controle (especificamente, um projeto de biblioteca de controle do Windows) e, em seguida, compilar o projeto em um assembly. O controle, em seguida, pode ser consumido de um aplicativo MFC que usa as classes derivadas de [classe CView](../mfc/reference/cview-class.md) e [CWinFormsView classe](../mfc/reference/cwinformsview-class.md).  
  
 Para obter informações sobre como criar um controle de usuário do Windows Forms e criar uma biblioteca de classes de controle, consulte [como: controles de usuário de autor](/dotnet/framework/winforms/controls/how-to-author-composite-controls).  
  
> [!NOTE]
>  Em alguns casos, os controles de formulários do Windows, como um controle de grade de terceiros, podem não funcionar com segurança quando hospedados em um aplicativo MFC. Uma solução alternativa recomendada é colocar um controle de usuário do Windows Forms no aplicativo do MFC e posicionar o controle de grade de terceiro dentro do controle de usuário.  
  
 Este procedimento pressupõe que você criou um projeto de biblioteca de controles de formulários do Windows chamado WindowsFormsControlLibrary1, de acordo com o procedimento [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).  
  
### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC  
  
1.  Crie um projeto de aplicativo do MFC.  
  
     Sobre o **arquivo** menu, selecione **novo**e, em seguida, clique em **projeto**. No **Visual C++** pasta, selecione **aplicativo MFC**.  
  
     No **nome** , digite `MFC02` e altere o **solução** definindo como **adicionar à solução**. Clique em **OK**.  
  
     No **Assistente de aplicativo MFC**, aceite todos os padrões e, em seguida, clique em **concluir**. Isso cria um aplicativo MFC com uma Interface de múltiplos documentos.  
  
2.  Configure o projeto para suporte a Common Language Runtime (CLR).  
  
     Em **Solution Explorer**, com o botão direito do `MFC01` nó do projeto e selecione **propriedades** no menu de contexto. O **páginas de propriedade** caixa de diálogo é exibida.  
  
     Em **propriedades de configuração**, selecione **geral**. Sob o **padrões do projeto** seção, defina **suporte a Common Language Runtime** para **tempo de execução de linguagem comum suporte (/ clr)**.  
  
     Em **propriedades de configuração**, expanda **C/C++** e clique no **geral** nó. Definir **formato de informações de depuração** para **(/Zi) do banco de dados de programa**.  
  
     Clique o **geração de código** nó. Definir **habilitar recompilação mínima** para **não (/ Gm-)**. Também definir **verificações de tempo de execução básico** para **padrão**.  
  
     Clique em **Okey** para aplicar as alterações.  
  
3.  Em Stdafx. h, adicione a seguinte linha:  
  
    ```  
    #using <System.Windows.Forms.dll>  
    ```  
  
4.  Adicione uma referência para o controle de .NET.  
  
     Em **Solution Explorer**, com o botão direito do `MFC02` nó do projeto e selecione **adicionar**, **referências**. No **página de propriedades**, clique em **adicionar nova referência**, selecione WindowsFormsControlLibrary1 (sob o **projetos** guia) e clique em **Okey** . Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa será compilado; ele também copia WindowsFormsControlLibrary1.dll para o `MFC02` diretório do projeto para que o programa será executado.  
  
5.  Em Stdafx. h, encontre esta linha:  
  
    ```  
    #endif // _AFX_NO_AFXCMN_SUPPORT   
    ```  
  
     Adicione essas linhas acima dela:  
  
    ```  
    #include <afxwinforms.h>   // MFC Windows Forms support  
    ```  
  
6.  Modifique a classe de exibição para que ele herda de [CWinFormsView](../mfc/reference/cwinformsview-class.md).  
  
     No MFC02View.h, substitua [CView](../mfc/reference/cview-class.md) com [CWinFormsView](../mfc/reference/cwinformsview-class.md) para que o código aparece da seguinte maneira:  
  
    ```  
    class CMFC02View : public CWinFormsView  
    {  
    };  
    ```  
  
     Se você quiser adicionar modos de exibição adicionais ao seu aplicativo MDI, você precisará chamar [CWinApp::AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) para cada modo de exibição que você criar.  
  
7.  Modifique o arquivo MFC02View.cpp para alterar CView para CWinFormsView no mapa de mensagem e de macro IMPLEMENT_DYNCREATE e substitua o construtor vazio existente com o construtor mostrado abaixo:  
  
    ```  
    IMPLEMENT_DYNCREATE(CMFC02View, CWinFormsView)  
  
    CMFC02View::CMFC02View(): CWinFormsView(WindowsFormsControlLibrary1::UserControl1::typeid)   
    {  
    }  
    BEGIN_MESSAGE_MAP(CMFC02View, CWinFormsView)  
    //leave existing body as is  
    END_MESSAGE_MAP()  
    ```  
  
8.  Compile e execute o projeto.  
  
     Em **Solution Explorer**, MFC02 e selecione **definir como projeto de inicialização**.  
  
     No menu **Compilar**, clique em **Compilar Solução**.  
  
     Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
## <a name="see-also"></a>Consulte também  
 [Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)