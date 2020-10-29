---
title: 'Instruções passo a passo: usando os novos controles de shell MFC'
ms.date: 04/25/2019
helpviewer_keywords:
- shell controls (MFC)
ms.assetid: f0015caa-199d-4aaf-9501-5a239fce9095
ms.openlocfilehash: 0d8db9044a64305bd7bb9ef6fe10de9ecef1ce51
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924750"
---
# <a name="walkthrough-using-the-new-mfc-shell-controls"></a>Instruções passo a passo: usando os novos controles de shell MFC

Neste tutorial, você criará um aplicativo que se assemelha ao explorador de arquivos. Você criará uma janela que tem dois painéis. O painel esquerdo conterá um objeto [CMFCShellTreeCtrl](../mfc/reference/cmfcshelltreectrl-class.md) que exibe a área de trabalho em uma exibição hierárquica. O painel direito conterá um [CMFCShellListCtrl](../mfc/reference/cmfcshelllistctrl-class.md) que mostra os arquivos na pasta selecionada no painel esquerdo.

## <a name="prerequisites"></a>Pré-requisitos

- No Visual Studio 2017 e posterior, o suporte do MFC é um componente opcional. Para instalá-lo, abra o Instalador do Visual Studio no menu Iniciar do Windows. Localize a versão do Visual Studio que você está usando e escolha o botão **Modificar** . Verifique se o bloco **desenvolvimento de área de trabalho com C++** está marcado. Em **componentes opcionais** , verifique o botão **suporte do MFC** .

- Este tutorial pressupõe que você configurou o Visual Studio para usar **configurações de desenvolvimento gerais** . Se você estiver usando uma configuração de desenvolvimento diferente, algumas janelas do Visual Studio que usamos neste passo a passos podem não ser exibidas por padrão.

## <a name="to-create-a-new-mfc-application-by-using-the-mfc-application-wizard"></a>Para criar um novo aplicativo MFC usando o assistente de aplicativo MFC

Essas etapas variam de acordo com a versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="msvc-160"

### <a name="to-create-an-mfc-project-in-visual-studio-2019"></a>Para criar um projeto do MFC no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto** .

1. Na caixa de pesquisa na parte superior, digite **MFC** e, em seguida, escolha **aplicativo MFC** na lista de resultados.

1. Clique em **Próximo** . Na próxima página, insira um nome para o projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

   Depois que o **Assistente de aplicativo do MFC** for exibido, use as seguintes opções:

   1. Escolha o **tipo de aplicativo** à esquerda. Em seguida, selecione **documento único** e selecione **suporte à arquitetura de documento/exibição** . Em **estilo do projeto** , **selecione Visual Studio** e, na lista suspensa **estilo visual e cores** , selecione **Office 2007 (tema azul)** .

   1. No painel de **suporte de documento composto** , selecione **nenhum** .

   1. Não faça nenhuma alteração no painel **Propriedades do modelo de documento** .

   1. No painel **recursos da interface do usuário** , verifique se a opção **usar uma barra de menus e uma barra de ferramentas** está selecionada. Deixe todas as outras opções como estão.

   1. No painel **recursos avançados** , selecione **controles ActiveX** , **manifesto de controle comum** e a opção **painel de navegação** . Deixe tudo o mais como está. A opção do **painel de navegação** fará com que o assistente crie o painel à esquerda da janela com um `CMFCShellTreeCtrl` já incorporado.

   1. Não vamos fazer nenhuma alteração no painel **classes geradas** , portanto, clique em **concluir** para criar seu novo projeto MFC.

::: moniker-end

::: moniker range="<=msvc-150"

### <a name="to-create-an-mfc-project-in-visual-studio-2017-or-earlier"></a>Para criar um projeto do MFC no Visual Studio 2017 ou anterior

1. Use o **Assistente de aplicativo MFC** para criar um novo aplicativo MFC. Para executar o assistente, no menu **arquivo** , selecione **novo** e, em seguida, selecione **projeto** . A caixa de diálogo **novo projeto** será exibida.

1. Na caixa de diálogo **novo projeto** , expanda o nó **Visual C++** no painel **tipos de projeto** e selecione **MFC** . Em seguida, no painel **modelos** , selecione **aplicativo MFC** . Digite um nome para o projeto, como `MFCShellControls` e clique em **OK** .

   Depois que o **Assistente de aplicativo do MFC** for exibido, use as seguintes opções:

   1. No painel **tipo de aplicativo** , em **tipo de aplicativo** , desmarque a opção **documentos com guias** . Em seguida, selecione **documento único** e selecione **suporte à arquitetura de documento/exibição** . Em **estilo do projeto** , **selecione Visual Studio** e, na lista suspensa **estilo visual e cores** , selecione **Office 2007 (tema azul)** .

   1. No painel de **suporte de documento composto** , selecione **nenhum** .

   1. Não faça nenhuma alteração no painel de **cadeias de caracteres do modelo de documento** .

   1. No painel de **suporte do banco de dados** (Visual Studio 2015 e mais antigo), selecione **nenhum** porque o aplicativo não usa um banco de dados.

   1. No painel **recursos da interface do usuário** , verifique se a opção **usar uma barra de menus e uma barra de ferramentas** está selecionada. Deixe todas as outras opções como estão.

   1. No painel **recursos avançados** , em **recursos avançados** , selecione somente **controles ActiveX** e **manifesto de controle comum** . Em **painéis de quadro avançados** , selecione apenas a opção **painel de navegação** . Isso fará com que o assistente crie o painel à esquerda da janela com um `CMFCShellTreeCtrl` já incorporado.

   1. Não vamos fazer nenhuma alteração no painel **classes geradas** , portanto, clique em **concluir** para criar seu novo projeto MFC.

::: moniker-end

Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , selecione **Compilar solução** . Se o aplicativo for compilado com êxito, execute o aplicativo selecionando **Iniciar Depuração** no menu **depurar** .

O assistente cria automaticamente um aplicativo que tem uma barra de menus padrão, uma barra de ferramentas padrão, uma barra de status padrão e uma barra do Outlook à esquerda da janela com uma exibição de **pastas** e uma exibição de **calendário** .

### <a name="to-add-the-shell-list-control-to-the-document-view"></a>Para adicionar o controle de lista de Shell ao modo de exibição de documento

1. Nesta seção, você adicionará uma instância do `CMFCShellListCtrl` à exibição que o assistente criou. Abra o arquivo de cabeçalho de exibição clicando duas vezes em **MFCShellControlsView. h** na **Gerenciador de soluções** .

   Localize a `#pragma once` diretiva próxima à parte superior do arquivo de cabeçalho. Imediatamente abaixo dele, adicione este código para incluir o arquivo de cabeçalho para `CMFCShellListCtrl` :

   ```cpp
   #include <afxShellListCtrl.h>
   ```

   Agora, adicione uma variável de membro do tipo `CMFCShellListCtrl` . Primeiro, localize o seguinte comentário no arquivo de cabeçalho:

   ```cpp
   // Generated message map functions
   ```

   Imediatamente acima desse comentário, adicione este código:

   ```cpp
   private:
   CMFCShellListCtrl m_wndList;
   ```

1. O **Assistente de aplicativo do MFC** já criou um `CMFCShellTreeCtrl` objeto na `CMainFrame` classe, mas é um membro protegido. Acessaremos o objeto mais tarde, portanto, crie um acessador para ele agora mesmo. Abra o arquivo de cabeçalho MainFrm. h clicando duas vezes nele no **Gerenciador de soluções** . Localize o comentário a seguir:

   ```cpp
   // Attributes
   ```

   Imediatamente abaixo dele, adicione a seguinte declaração de método:

   ```cpp
   public:
       CMFCShellTreeCtrl& GetShellTreeCtrl();
   ```

   Em seguida, abra o arquivo de origem MainFrm. cpp clicando duas vezes nele no **Gerenciador de soluções** . Na parte inferior desse arquivo, adicione a seguinte definição de método:

   ```cpp
   CMFCShellTreeCtrl& CMainFrame::GetShellTreeCtrl()
   {
        return m_wndTree;
   }
   ```

1. Agora, atualizamos a `CMFCShellControlsView` classe para manipular a `WM_CREATE` mensagem do Windows. Abra a janela **modo de exibição de classe** e selecione a `CMFCShellControlsView` classe. Clique com o botão direito do mouse e selecione **Propriedades** .

   Em seguida, no [Assistente de classe](reference/mfc-class-wizard.md), clique na guia **mensagens** . Role para baixo até encontrar a `WM_CREATE` mensagem. Na lista suspensa ao lado de `WM_CREATE` , selecione **\<Add> OnCreate** . O comando cria um manipulador de mensagens para nós e atualiza automaticamente o mapa de mensagens do MFC.

   No `OnCreate` método, agora criaremos nosso `CMFCShellListCtrl` objeto. Localize a `OnCreate` definição do método no arquivo de origem MFCShellControlsView. cpp e substitua sua implementação pelo código a seguir:

    ```cpp
    int CMFCShellControlsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        if (CView::OnCreate(lpCreateStruct) == -1)
            return -1;

        CRect rectDummy (0, 0, 0, 0);

        m_wndList.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT,
            rectDummy, this, 1);

        return 0;
    }
    ```

1. Repita a etapa anterior, mas para a `WM_SIZE` mensagem. Isso fará com que a exibição dos aplicativos seja redesenhada sempre que um usuário alterar o tamanho da janela do aplicativo. Substitua a definição do `OnSize` método pelo seguinte código:

    ```cpp
    void CMFCShellControlsView::OnSize(UINT nType, int cx, int cy)
    {
        CView::OnSize(nType, cx, cy);

        m_wndList.SetWindowPos(NULL, -1, -1, cx, cy,
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    }
    ```

1. A última etapa é conectar os `CMFCShellTreeCtrl` objetos e `CMFCShellListCtrl` usando o método [CMFCShellTreeCtrl:: setrelacionadolist](../mfc/reference/cmfcshelltreectrl-class.md#setrelatedlist) . Depois de chamar `CMFCShellTreeCtrl::SetRelatedList` , o `CMFCShellListCtrl` exibirá automaticamente o conteúdo do item selecionado no `CMFCShellTreeCtrl` . Conectamos os objetos no `OnActivateView` método, que é substituído de [cvisualização:: OnActivateView](../mfc/reference/cview-class.md#onactivateview).

   No arquivo de cabeçalho MFCShellControlsView. h, dentro da `CMFCShellControlsView` declaração de classe, adicione a seguinte declaração de método:

    ```cpp
    protected:
    virtual void OnActivateView(BOOL bActivate,
        CView* pActivateView,
        CView* pDeactiveView);
    ```

   Em seguida, adicione a definição para o método ao arquivo de origem MFCShellControlsView. cpp:

    ```cpp
    void CMFCShellControlsView::OnActivateView(BOOL bActivate,
        CView* pActivateView,
        CView* pDeactiveView)
    {
        if (bActivate&& AfxGetMainWnd() != NULL)
        {
            ((CMainFrame*)AfxGetMainWnd())->GetShellTreeCtrl().SetRelatedList(&m_wndList);
        }

        CView::OnActivateView(bActivate,
            pActivateView,
            pDeactiveView);
    }
    ```

   Como estamos chamando métodos da `CMainFrame` classe, devemos adicionar uma `#include` diretiva na parte superior do arquivo de origem MFCShellControlsView. cpp:

    ```cpp
    #include "MainFrm.h"
    ```

1. Verifique se o aplicativo foi criado com êxito criando-o e executando-o. Para criar o aplicativo, no menu **Compilar** , selecione **Compilar solução** . Se o aplicativo for compilado com êxito, execute-o selecionando **Iniciar Depuração** no menu **depurar** .

   Agora você deve ver os detalhes do item selecionado no `CMFCShellTreeCtrl` painel exibição. Quando você clica em um nó no `CMFCShellTreeCtrl` , o `CMFCShellListCtrl` será atualizado automaticamente. Da mesma forma, se você clicar duas vezes em uma pasta no `CMFCShellListCtrl` , o `CMFCShellTreeCtrl` deverá ser atualizado automaticamente.

   Clique com o botão direito do mouse em qualquer item no controle de árvore ou no controle de lista. Você Obtém o mesmo menu de contexto como se estivesse usando o **Explorador de arquivos** real.

## <a name="next-steps"></a>Próximas etapas

- O assistente criou uma barra do Outlook com um painel de **pastas** e um painel de **calendário** . Provavelmente não faz sentido ter um painel de **calendário** em uma janela do **Explorer** ; portanto, remova esse painel agora.

- O `CMFCShellListCtrl` oferece suporte à exibição de arquivos em modos diferentes, como **ícones grandes** , **ícones pequenos** , **lista** e **detalhes** . Atualize seu aplicativo para implementar essa funcionalidade. Dica: consulte [exemplos de Visual C++](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Veja também

[Passo a passo](../mfc/walkthroughs-mfc.md)
