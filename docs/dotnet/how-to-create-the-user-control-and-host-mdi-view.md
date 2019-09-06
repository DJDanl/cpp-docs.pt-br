---
title: 'Como: Criar o controle de usuário e a exibição de MDI do host'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms Controls
- Windows Forms [C++], MFC support
ms.assetid: 625b5821-f923-4701-aca0-c1a4ceca4f63
ms.openlocfilehash: 634dd9c1ad2ce9199cec0dfa7ef067bd45f242f6
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "70311632"
---
# <a name="how-to-create-the-user-control-and-host-mdi-view"></a>Como: Criar o controle de usuário e a exibição de MDI do host

As etapas a seguir mostram como criar um controle de usuário .NET Framework, criar o controle de usuário em uma biblioteca de classes de controle (especificamente, um projeto de biblioteca de controle do Windows) e, em seguida, compilar o projeto em um assembly. O controle pode então ser consumido de um aplicativo MFC que usa classes derivadas da classe [cvisualização](../mfc/reference/cview-class.md) e da [classe CWinFormsView](../mfc/reference/cwinformsview-class.md).

Para obter informações sobre como criar um controle de usuário de Windows Forms e autorar uma biblioteca de [classes de controle, consulte Como: Criar controles](/dotnet/framework/winforms/controls/how-to-author-composite-controls)de usuário.

> [!NOTE]
>  Em alguns casos, Windows Forms controles, como um controle de grade de terceiros, podem não se comportar de forma confiável quando hospedados em um aplicativo MFC. Uma solução alternativa recomendada é posicionar um controle de usuário Windows Forms no aplicativo MFC e posicionar o controle de grade de terceiros dentro do controle de usuário.

Este procedimento pressupõe que você criou um projeto de biblioteca de controles de Windows Forms chamado WindowsFormsControlLibrary1, de acordo [com o procedimento em como: Crie o controle de usuário e o host em uma](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md)caixa de diálogo.

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo host do MFC

1. Crie um projeto de aplicativo do MFC.

   No menu **arquivo** , selecione **novo**e, em seguida, clique em **projeto**. Na pasta **Visual C++**  , selecione **aplicativo MFC**.

   Na caixa **nome** , insira `MFC02` e altere a configuração da **solução** para **Adicionar à solução**. Clique em **OK**.

   No **Assistente de aplicativo do MFC**, aceite todos os padrões e clique em **concluir**. Isso cria um aplicativo MFC com uma interface de vários documentos.

1. Configure o projeto para o suporte do CLR (Common Language Runtime).

   Em **Gerenciador de soluções**, clique com o botão `MFC01` direito do mouse no nó do projeto e selecione **Propriedades** no menu de contexto. A caixa de diálogo **páginas de propriedades** é exibida.

   Em **Propriedades de configuração**, selecione **geral**. Na seção **padrões do projeto** , defina **suporte a Common Language Runtime** para **/CLR (Common Language Runtime support)** .

   Em **Propriedades de configuração**, expanda **C/C++**  e clique no nó **geral** . Defina o **formato de informações de depuração** para o banco de **dados do programa (/Zi)** .

   Clique no nó **geração de código** . Defina **habilitar recompilação mínima** como **não (/GM-)** . Além disso, defina as **verificações de tempo de execução básicas** como **padrão**.

   Clique em **OK** para aplicar suas alterações.

1. Em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior), adicione a seguinte linha:

    ```
    #using <System.Windows.Forms.dll>
    ```

1. Adicione uma referência ao controle .NET.

   Em **Gerenciador de soluções**, clique com o botão `MFC02` direito do mouse no nó do projeto e selecione **Adicionar**, **referências**. Na **página de propriedades**, clique em **Adicionar nova referência**, selecione WindowsFormsControlLibrary1 (na guia **projetos** ) e clique em **OK**. Isso adiciona uma referência na forma de uma opção de compilador [/Fu](../build/reference/fu-name-forced-hash-using-file.md) para que o programa seja compilado; Ele também copia WindowsFormsControlLibrary1. dll no `MFC02` diretório do projeto para que o programa seja executado.

1. Em stdafx. h, localize esta linha:

    ```
    #endif // _AFX_NO_AFXCMN_SUPPORT
    ```

   Adicione estas linhas acima dela:

    ```
    #include <afxwinforms.h>   // MFC Windows Forms support
    ```

1. Modifique a classe View de forma que ela herde de [CWinFormsView](../mfc/reference/cwinformsview-class.md).

   Em MFC02View. h, substitua [cvisualização](../mfc/reference/cview-class.md) por [CWinFormsView](../mfc/reference/cwinformsview-class.md) para que o código seja exibido da seguinte maneira:

    ```
    class CMFC02View : public CWinFormsView
    {
    };
    ```

   Se você quiser adicionar exibições adicionais ao aplicativo MDI, será necessário chamar [CWinApp:: AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) para cada exibição que criar.

1. Modifique o arquivo MFC02View. cpp para alterar Cvisualização para CWinFormsView na macro IMPLEMENT_DYNCREATE e no mapa de mensagens e substitua o construtor vazio existente pelo construtor mostrado abaixo:

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

   Em **Gerenciador de soluções**, clique com o botão direito do mouse em MFC02 e selecione **definir como projeto de inicialização**.

   No menu **Compilar**, clique em **Compilar Solução**.

   No menu **depurar** , clique em **Iniciar sem Depurar**.

## <a name="see-also"></a>Consulte também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)
