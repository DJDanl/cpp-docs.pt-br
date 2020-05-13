---
title: Como criar o controle de usuário e hospedar uma exibição MDI
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], Windows Forms Controls
- Windows Forms [C++], MFC support
ms.assetid: 625b5821-f923-4701-aca0-c1a4ceca4f63
ms.openlocfilehash: 72501ba32d3b8b9a5c5fd8dd0c56f0628642b147
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374462"
---
# <a name="how-to-create-the-user-control-and-host-mdi-view"></a>Como criar o controle de usuário e hospedar uma exibição MDI

As etapas a seguir mostram como criar um controle de usuário do .NET Framework, autorizar o controle do usuário em uma biblioteca de classes de controle (especificamente, um projeto da Biblioteca de Controle do Windows) e, em seguida, compilar o projeto em uma montagem. O controle pode então ser consumido a partir de um aplicativo MFC que usa classes derivadas de [CView Class](../mfc/reference/cview-class.md) e [CWinFormsView Class](../mfc/reference/cwinformsview-class.md).

Para obter informações sobre como criar um controle de usuário do Windows Forms e criar uma biblioteca de classes de controle, consulte [Como: Controles do Usuário Autor](/dotnet/framework/winforms/controls/how-to-author-composite-controls).

> [!NOTE]
> Em alguns casos, os controles do Windows Forms, como um controle de grade de terceiros, podem não se comportar de forma confiável quando hospedados em um aplicativo MFC. Uma solução recomendada é colocar um Controle de Usuário do Windows Forms no aplicativo MFC e colocar o controle de grade de terceiros dentro do controle do Usuário.

Esse procedimento pressupõe que você criou um projeto de Biblioteca de Controles de Formulários do Windows chamado WindowsFormsControlLibrary1, conforme o procedimento em [Como: Criar o Controle do Usuário e hospedar em uma caixa de diálogo](../dotnet/how-to-create-the-user-control-and-host-in-a-dialog-box.md).

### <a name="to-create-the-mfc-host-application"></a>Para criar o aplicativo de host MFC

1. Crie um projeto de aplicativo MFC.

   No **menu Arquivo,** selecione **Novo**e clique em **Projeto**. Na pasta **Visual C++,** selecione **MFC Application**.

   Na **caixa Nome,** digite `MFC02` e altere a **configuração solução** para adicionar à **solução**. Clique em **OK**.

   No **Assistente de Aplicativo MFC,** aceite todos os padrões e clique **em Concluir**. Isso cria um aplicativo MFC com uma interface de documento múltipla.

1. Configure o projeto para suporte ao CLR (Common Language Runtime).

   No **Solution Explorer,** clique `MFC01` com o botão direito do mouse no nó do projeto e selecione **Propriedades** no menu de contexto. A caixa de diálogo **Páginas** de propriedade é exibida.

   Em **Propriedades de configuração,** selecione **Geral**. Na seção **Padrão de projeto,** defina o **suporte ao tempo de execução do idioma comum** **(/clr)**.

   Em **Propriedades de configuração,** expanda **C/C++** e clique no nó **Geral.** Definir **o formato de informações de depuração** para o banco de dados do programa **(/Zi)**.

   Clique no nó **Geração** de Código. Defina **ativar a reconstrução mínima** para não **(/Gm-)**. Também defina **as verificações básicas de tempo de execução** **como padrão**.

   Clique em **OK** para aplicar suas alterações.

1. Em *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior), adicione a seguinte linha:

    ```
    #using <System.Windows.Forms.dll>
    ```

1. Adicione uma referência ao controle .NET.

   No **Solution Explorer,** clique `MFC02` com o botão direito do mouse no nó do projeto e **selecione Adicionar**, **Referências**. Na **página de propriedades,** clique em **Adicionar nova referência,** selecione WindowsFormsControlLibrary1 (na guia **Projetos)** e clique em **OK**. Isso adiciona uma referência na forma de uma opção de compilador [/FU](../build/reference/fu-name-forced-hash-using-file.md) para que o programa seja compilado; ele também copia o WindowsFormsControlLibrary1.dll no diretório do `MFC02` projeto para que o programa seja executado.

1. Em stdafx.h, encontre esta linha:

    ```
    #endif // _AFX_NO_AFXCMN_SUPPORT
    ```

   Adicione estas linhas acima:

    ```
    #include <afxwinforms.h>   // MFC Windows Forms support
    ```

1. Modifique a classe de exibição para que ela herde do [CWinFormsView](../mfc/reference/cwinformsview-class.md).

   No MFC02View.h, substitua [o CView por](../mfc/reference/cview-class.md) [CWinFormsView](../mfc/reference/cwinformsview-class.md) para que o código seja exibido da seguinte forma:

    ```
    class CMFC02View : public CWinFormsView
    {
    };
    ```

   Se você quiser adicionar visualizações adicionais ao seu aplicativo MDI, você precisará chamar [CWinApp::AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) para cada exibição criada.

1. Modifique o arquivo MFC02View.cpp para alterar o CView para CWinFormsVer no mapa de IMPLEMENT_DYNCREATE macro e mensagem e substitua o construtor vazio existente pelo construtor mostrado abaixo:

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

   No **Solution Explorer,** clique com o botão direito do mouse em MFC02 e selecione **Set as StartUp Project**.

   No menu **Compilar**, clique em **Compilar Solução**.

   No menu **Debug,** clique em **Iniciar sem depuração**.

## <a name="see-also"></a>Confira também

[Hospedando um controle de usuário do Windows Forms como uma exibição do MFC](../dotnet/hosting-a-windows-forms-user-control-as-an-mfc-view.md)
