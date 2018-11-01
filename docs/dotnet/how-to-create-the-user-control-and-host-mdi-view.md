---
title: Como criar o controle de usuário e hospedar uma exibição MDI
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms Controls
- Windows Forms [C++], MFC support
ms.assetid: 625b5821-f923-4701-aca0-c1a4ceca4f63
ms.openlocfilehash: c2705ef1938684d8521316436fccaae367629584
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509116"
---
# <a name="how-to-create-the-user-control-and-host-mdi-view"></a>Como criar o controle de usuário e hospedar uma exibição MDI

As etapas a seguir mostram como criar um controle de usuário do .NET Framework, criar o controle de usuário em uma biblioteca de classe de controle (especificamente, um projeto de biblioteca de controle do Windows) e, em seguida, compile o projeto em um assembly. O controle, em seguida, pode ser consumido de um aplicativo do MFC que usa classes derivadas [classe CView](../mfc/reference/cview-class.md) e [classe CWinFormsView](../mfc/reference/cwinformsview-class.md).

Para obter informações sobre como criar um controle de usuário do Windows Forms e criar uma biblioteca de classe de controle, consulte [como: criar controles de usuário](/dotnet/framework/winforms/controls/how-to-author-composite-controls).

> [!NOTE]
>  Em alguns casos, controles de formulários do Windows, como um controle de grade de terceiros, talvez não se comportar confiavelmente quando hospedados em um aplicativo MFC. Uma solução alternativa recomendada é colocar um controle de usuário do Windows Forms no aplicativo MFC e colocar o controle de grade de terceiros dentro do controle de usuário.

Este procedimento pressupõe que você criou um projeto de biblioteca de controles do Windows Forms denominado WindowsFormsControlLibrary1, de acordo com o procedimento [como: criar o controle de usuário e o Host em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host do MFC

1. Crie um projeto de aplicativo do MFC.

   Sobre o **arquivo** menu, selecione **New**e, em seguida, clique em **projeto**. No **Visual C++** pasta e selecione **aplicativo MFC**.

   No **nome** , digite `MFC02` e altere o **solução** definindo como **adicionar à solução**. Clique em **OK**.

   No **Assistente de aplicativo MFC**, aceite todos os padrões e, em seguida, clique em **concluir**. Isso cria um aplicativo MFC com uma Interface de documentos múltiplos.

1. Configure o projeto para o suporte de tempo de execução de linguagem comum (CLR).

   Na **Gerenciador de soluções**, com o botão direito do `MFC01` nó do projeto e selecione **propriedades** no menu de contexto. O **páginas de propriedade** caixa de diálogo é exibida.

   Sob **propriedades de configuração**, selecione **geral**. Sob o **padrões de projeto** seção, defina **suporte do Common Language Runtime** para **suporte a Common Language Runtime (/ clr)**.

   Sob **propriedades de configuração**, expanda **C/C++** e clique no **geral** nó. Definir **formato de informações de depuração** à **programa (/Zi) do banco de dados**.

   Clique o **geração de código** nó. Definir **habilitar recompilação mínima** à **não (/ Gm-)**. Também defina **verificações básicas de tempo de execução** à **padrão**.

   Clique em **Okey** para aplicar suas alterações.

1. Em Stdafx. h, adicione a seguinte linha:

    ```
    #using <System.Windows.Forms.dll>
    ```

1. Adicione uma referência ao controle .NET.

   No **Gerenciador de soluções**, clique com botão direito do `MFC02` nó do projeto e selecione **adicionar**, **referências**. No **página de propriedades**, clique em **adicionar nova referência**, selecione WindowsFormsControlLibrary1 (sob o **projetos** guia) e clique em **Okey** . Isso adiciona uma referência na forma de um [/FU](../build/reference/fu-name-forced-hash-using-file.md) opção de compilador para que o programa compilará; também copia WindowsFormsControlLibrary1.dll para o `MFC02` diretório do projeto para que o programa será executado.

1. Em Stdafx. h, localize esta linha:

    ```
    #endif // _AFX_NO_AFXCMN_SUPPORT
    ```

   Adicione estas linhas acima dela:

    ```
    #include <afxwinforms.h>   // MFC Windows Forms support
    ```

1. Modifique a classe de exibição para que ele herda [CWinFormsView](../mfc/reference/cwinformsview-class.md).

   Em MFC02View.h, substitua [CView](../mfc/reference/cview-class.md) com [CWinFormsView](../mfc/reference/cwinformsview-class.md) para que o código aparece da seguinte maneira:

    ```
    class CMFC02View : public CWinFormsView
    {
    };
    ```

   Se você quiser adicionar exibições adicionais ao seu aplicativo MDI, você precisará chamar [CWinApp::AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) para cada modo de exibição que você cria.

1. Modifique o arquivo MFC02View.cpp para alterar CView para CWinFormsView no mapa de macro e mensagem IMPLEMENT_DYNCREATE e substitua o construtor vazio existente pelo construtor mostrado abaixo:

    ```
    IMPLEMENT_DYNCREATE(CMFC02View, CWinFormsView)

    CMFC02View::CMFC02View(): CWinFormsView(WindowsFormsControlLibrary1::UserControl1::typeid)
    {
    }
    BEGIN_MESSAGE_MAP(CMFC02View, CWinFormsView)
    //leave existing body as is
    END_MESSAGE_MAP()
    ```

1. Compile e execute o projeto.

   Na **Gerenciador de soluções**, clique com botão direito MFC02 e selecione **definir como projeto de inicialização**.

   No menu **Compilar**, clique em **Compilar Solução**.

   Sobre o **Debug** menu, clique em **iniciar sem depuração**.

## <a name="see-also"></a>Consulte também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)