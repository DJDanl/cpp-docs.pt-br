---
title: 'Instruções passo a passo: usando os novos controles de shell MFC'
ms.date: 04/25/2019
helpviewer_keywords:
- shell controls (MFC)
ms.assetid: f0015caa-199d-4aaf-9501-5a239fce9095
ms.openlocfilehash: 5786fbbf7ec9f31e7d895a96dae27b8fc95abda1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360221"
---
# <a name="walkthrough-using-the-new-mfc-shell-controls"></a>Instruções passo a passo: usando os novos controles de shell MFC

Neste passo a passo, você criará um aplicativo que se assemelha ao File Explorer. Você vai criar uma janela que tem dois painéis. O painel esquerdo segurará um objeto [CMFCShellTreeCtrl](../mfc/reference/cmfcshelltreectrl-class.md) que exibe sua Área de Trabalho em uma exibição hierárquica. O painel direito segurará um [CMFCShellListCtrl](../mfc/reference/cmfcshelllistctrl-class.md) que mostra os arquivos na pasta selecionada no painel esquerdo.

## <a name="prerequisites"></a>Pré-requisitos

- No Visual Studio 2017 e posterior, o suporte ao MFC é um componente opcional. Para instalá-lo, abra o Visual Studio Installer no menu Iniciar do Windows. Encontre a versão do Visual Studio que você está usando e escolha o botão **Modificar.** Certifique-se de que o desenvolvimento da área de trabalho com azulejo **C++** seja verificado. Em **Componentes Opcionais,** verifique o botão **de suporte MFC.**

- Este passo a passo assume que você criou o Visual Studio para usar **configurações de desenvolvimento geral**. Se você estiver usando uma configuração de desenvolvimento diferente, algumas janelas do Visual Studio que usamos neste passo a passo podem não ser exibidas por padrão.

## <a name="to-create-a-new-mfc-application-by-using-the-mfc-application-wizard"></a>Para criar um novo aplicativo MFC usando o Assistente de Aplicativo Do MFC

Essas etapas variam dependendo da versão do Visual Studio que você está usando. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-an-mfc-project-in-visual-studio-2019"></a>Para criar um projeto de MFC no Visual Studio 2019

1. No menu principal, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um projeto**.

1. Na caixa de pesquisa na parte superior, digite **MFC** e escolha o **Aplicativo MFC** na lista de resultados.

1. Clique em **Próximo**. Na página seguinte, digite um nome para o projeto e especifique o local do projeto se desejar.

1. Escolha o botão **Criar** para criar o projeto.

   Após as exibições **do MFC Application Wizard,** use as seguintes opções:

   1. Escolha **Tipo de aplicativo** à esquerda. Em seguida, selecione **Um documento** e selecione Suporte à **arquitetura Document/View**. No **estilo Project,** selecione **Visual Studio,** e no **estilo visual e as cores** abaixo da lista selecionam **Office 2007 (tema azul)**.

   1. No painel **de suporte a documentos compostos,** selecione **Nenhum**.

   1. Não faça alterações no painel **Propriedades do Modelo de Documento.**

   1. No painel Recursos de Interface do **Usuário,** certifique-se de que **a opção Use uma barra de menu e barra de ferramentas** esteja selecionada. Deixe todas as outras opções como estão.

   1. No painel **Recursos Avançados,** selecione **controles ActiveX,** **Manifesto de Controle Comum**e opção **painel de navegação.** Deixe tudo como está. A opção **Painel de Navegação** fará com que o assistente crie `CMFCShellTreeCtrl` o painel à esquerda da janela com um já incorporado.

   1. Não vamos fazer nenhuma alteração no painel **'Classes** geradas', então clique **em Terminar** para criar seu novo projeto de MFC.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-an-mfc-project-in-visual-studio-2017-or-earlier"></a>Para criar um projeto de MFC no Visual Studio 2017 ou anterior

1. Use o **Assistente de Aplicativo Do MFC** para criar um novo aplicativo MFC. Para executar o assistente, no menu **Arquivo,** selecione **Novo**e selecione **Projeto**. A caixa de diálogo **Novo Projeto** será exibida.

1. Na caixa de diálogo **Novo Projeto,** expanda o nó **Visual C++** no painel **de tipos de projeto** e selecione **MFC**. Em seguida, no painel **Modelos,** selecione **MFC Application**. Digite um nome para `MFCShellControls` o projeto, como e clique em **OK**.

   Após as exibições **do MFC Application Wizard,** use as seguintes opções:

   1. No painel **Tipo de aplicativo,** em **Tipo de aplicativo,** limpe a opção **Documentos guiados.** Em seguida, selecione **Um documento** e selecione **Suporte à arquitetura Document/View**. No **estilo Project,** selecione **Visual Studio,** e no **estilo visual e as cores** abaixo da lista selecionam **Office 2007 (tema azul)**.

   1. No painel **de suporte a documentos compostos,** selecione **Nenhum**.

   1. Não faça alterações no painel **Strings do Modelo de Documento.**

   1. No painel de suporte ao **banco de dados** (Visual Studio 2015 e mais antigo), selecione **Nenhum** porque o aplicativo não usa um banco de dados.

   1. No painel Recursos de Interface do **Usuário,** certifique-se de que **a opção Use uma barra de menu e barra de ferramentas** esteja selecionada. Deixe todas as outras opções como estão.

   1. No painel **Recursos Avançados,** em **Recursos Avançados,** selecione apenas **controles ActiveX** e **Manifesto de Controle Comum**. Em **Painéis de quadro avançados,** selecione apenas a opção **Painel de navegação.** Isso fará com que o assistente crie o painel `CMFCShellTreeCtrl` à esquerda da janela com um já incorporado.

   1. Não vamos fazer nenhuma alteração no painel **'Classes** geradas', então clique **em Terminar** para criar seu novo projeto de MFC.

::: moniker-end

Verifique se o aplicativo foi criado com sucesso, construindo e executando-o. Para construir o aplicativo, a partir do menu **Build** selecione **Build Solution**. Se o aplicativo for criado com sucesso, execute o aplicativo selecionando **Iniciar depuração** no menu **Depuração.**

O assistente cria automaticamente um aplicativo que tem uma barra de menu padrão, uma barra de ferramentas padrão, uma barra de status padrão e uma barra do Outlook à esquerda da janela com uma exibição **de Pastas** e uma exibição **de calendário.**

### <a name="to-add-the-shell-list-control-to-the-document-view"></a>Para adicionar o controle da lista shell à exibição do documento

1. Nesta seção, você adicionará `CMFCShellListCtrl` uma instância à exibição que o assistente criou. Abra o arquivo de cabeçalho de exibição clicando duas vezes em **MFCShellControlsView.h** no **Solution Explorer**.

   Localize `#pragma once` a diretiva perto da parte superior do arquivo de cabeçalho. Imediatamente abaixo, adicione este código para `CMFCShellListCtrl`incluir o arquivo de cabeçalho para:

   ```cpp
   #include <afxShellListCtrl.h>
   ```

   Agora adicione uma variável `CMFCShellListCtrl`de membro do tipo . Primeiro, localize o seguinte comentário no arquivo de cabeçalho:

   ```cpp
   // Generated message map functions
   ```

   Imediatamente acima desse comentário, adicione este código:

   ```cpp
   private:
   CMFCShellListCtrl m_wndList;
   ```

1. O **MFC Application Wizard** `CMFCShellTreeCtrl` já criou `CMainFrame` um objeto na classe, mas é um membro protegido. Vamos acessar o objeto mais tarde, então crie um acessório para ele agora. Abra o arquivo de cabeçalho MainFrm.h clicando duas vezes no **Solution Explorer**. Localize o seguinte comentário:

   ```cpp
   // Attributes
   ```

   Imediatamente sob ela, adicione a seguinte declaração de método:

   ```cpp
   public:
       CMFCShellTreeCtrl& GetShellTreeCtrl();
   ```

   Em seguida, abra o arquivo de origem MainFrm.cpp clicando duas vezes no **Solution Explorer**. Na parte inferior desse arquivo, adicione a seguinte definição de método:

   ```cpp
   CMFCShellTreeCtrl& CMainFrame::GetShellTreeCtrl()
   {
        return m_wndTree;
   }
   ```

1. Agora atualizamos `CMFCShellControlsView` a classe `WM_CREATE` para lidar com a mensagem do Windows. Abra a janela **'Exibição de classe'** e selecione a `CMFCShellControlsView` classe. Clique com o botão direito do mouse e selecione **Propriedades**.

   Em seguida, no [Assistente de Classe,](reference/mfc-class-wizard.md)clique na `WM_CREATE` guia **Mensagens.** Role para baixo até encontrar a mensagem. Na lista de paradas `WM_CREATE`ao lado de , ** \<selecione Adicionar> OnCreate**. O comando cria um manipulador de mensagens para nós e atualiza automaticamente o mapa de mensagens do MFC.

   No `OnCreate` método, agora vamos criar `CMFCShellListCtrl` nosso objeto. Encontre `OnCreate` a definição do método no arquivo-fonte MFCShellControlsView.cpp e substitua sua implementação pelo seguinte código:

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

1. Repita o passo anterior, mas para a `WM_SIZE` mensagem. Isso fará com que a exibição de aplicativos seja redesenhada sempre que um usuário altera o tamanho da janela do aplicativo. Substitua a `OnSize` definição para o método pelo seguinte código:

    ```cpp
    void CMFCShellControlsView::OnSize(UINT nType, int cx, int cy)
    {
        CView::OnSize(nType, cx, cy);

        m_wndList.SetWindowPos(NULL, -1, -1, cx, cy,
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    }
    ```

1. A última etapa é `CMFCShellTreeCtrl` `CMFCShellListCtrl` conectar os objetos usando o método [CMFCShellTreeCtrl::SetRelatedList.](../mfc/reference/cmfcshelltreectrl-class.md#setrelatedlist) Após a `CMFCShellTreeCtrl::SetRelatedList`chamada, a `CMFCShellListCtrl` exposição exibirá automaticamente o `CMFCShellTreeCtrl`conteúdo do item selecionado no . Conectamos os objetos no `OnActivateView` método, que é substituído por [CView::OnActivateView](../mfc/reference/cview-class.md#onactivateview).

   No arquivo de cabeçalho MFCShellControlsView.h, dentro da declaração de `CMFCShellControlsView` classe, adicione a seguinte declaração de método:

    ```cpp
    protected:
    virtual void OnActivateView(BOOL bActivate,
        CView* pActivateView,
        CView* pDeactiveView);
    ```

   Em seguida, adicione a definição para o método ao arquivo de origem MFCShellControlsView.cpp:

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

   Como estamos chamando métodos `CMainFrame` da classe, `#include` devemos adicionar uma diretiva na parte superior do arquivo de origem MFCShellControlsView.cpp:

    ```cpp
    #include "MainFrm.h"
    ```

1. Verifique se o aplicativo foi criado com sucesso, construindo e executando-o. Para construir o aplicativo, a partir do menu **Build** selecione **Build Solution**. Se o aplicativo for criado com sucesso, execute-o selecionando **Iniciar depuração** no menu **Depuração.**

   Agora você deve ver os detalhes `CMFCShellTreeCtrl` do item selecionado no painel de exibição. Quando você clica em `CMFCShellTreeCtrl`um `CMFCShellListCtrl` nó no , o será atualizado automaticamente. Da mesma forma, se você clicar `CMFCShellListCtrl`duas `CMFCShellTreeCtrl` vezes em uma pasta no , o deve ser atualizado automaticamente.

   Clique com o botão direito do mouse em qualquer item no controle da árvore ou no controle da lista. Você tem o mesmo menu de contexto como se estivesse usando o explorador **de arquivos**real .

## <a name="next-steps"></a>Próximas etapas

- O assistente criou uma barra do Outlook com um painel **de pastas** e um painel **calendário.** Provavelmente não faz sentido ter um painel **de calendário** em uma janela **do Explorer,** então remova esse painel agora.

- O `CMFCShellListCtrl` suporte é a visualização de arquivos em diferentes modos, como **Ícones Grandes,** **Pequenos Ícones,** **Lista**e **Detalhes**. Atualize seu aplicativo para implementar essa funcionalidade. Dica: consulte [Imagens C++ Amostras](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Confira também

[Passo a passo](../mfc/walkthroughs-mfc.md)
