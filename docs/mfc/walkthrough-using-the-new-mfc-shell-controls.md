---
title: 'Passo a passo: Usando os novos controles de Shell MFC'
ms.date: 09/20/2018
helpviewer_keywords:
- shell controls (MFC)
ms.assetid: f0015caa-199d-4aaf-9501-5a239fce9095
ms.openlocfilehash: ef0e4856a844503f8d13b7b6ed37318b76b6af69
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772144"
---
# <a name="walkthrough-using-the-new-mfc-shell-controls"></a>Passo a passo: Usando os novos controles de Shell MFC

Neste passo a passo, você criará um aplicativo que se parece com o Explorador de arquivos. Você cria uma janela que tem dois painéis. O painel à esquerda conterá uma [CMFCShellTreeCtrl](../mfc/reference/cmfcshelltreectrl-class.md) objeto que exibe sua área de trabalho em uma exibição hierárquica. Painel à direita conterá uma [CMFCShellListCtrl](../mfc/reference/cmfcshelllistctrl-class.md) que mostra os arquivos na pasta selecionada no painel esquerdo.

## <a name="prerequisites"></a>Pré-requisitos

Este passo a passo pressupõe que você configurou o Visual Studio para usar **configurações gerais de desenvolvimento**. Se você estiver usando uma configuração de desenvolvimento diferente, algumas janelas do Visual Studio que usamos neste passo a passo podem não ser exibidas por padrão.

### <a name="to-create-a-new-mfc-application-by-using-the-mfc-application-wizard"></a>Para criar um novo aplicativo do MFC usando o Assistente de aplicativo do MFC

1. Use o **Assistente de aplicativo MFC** para criar um novo aplicativo do MFC. Para executar o Assistente do **arquivo** menu, selecione **New**e, em seguida, selecione **projeto**. O **novo projeto** caixa de diálogo será exibida.

1. No **novo projeto** diálogo caixa, expanda o **Visual C++** nó no **tipos de projeto** painel e selecione **MFC**. Em seguida, nos **modelos** painel, selecione **aplicativo MFC**. Digite um nome para o projeto, como `MFCShellControls` e clique em **Okey**. Após **Assistente de aplicativo MFC** exibida, use as seguintes opções:

    1. Sobre o **tipo de aplicativo** painel, em **tipo de aplicativo**, desmarque o **documentos com guias** opção. Em seguida, selecione **único documento** e selecione **suporte de arquitetura de documento/exibição**. Sob **estilo de projeto**, selecione **Visual Studio**e para o **Estilo Visual e cores** lista suspensa lista, selecione **Office 2007 (tema azul)**.

    1. Sobre o **suporte de documento composto** painel, selecione **None**.

    1. Não faça nenhuma alteração para o **cadeias de caracteres de modelo de documento** painel.

    1. Sobre o **suporte do banco de dados** painel (Visual Studio 2015 e anteriores), selecione **None** porque o aplicativo não usa um banco de dados.

    1. No **recursos de Interface do usuário** painel, certifique-se a **usar uma barra de menus e barra de ferramentas** opção está selecionada. Deixe todas as outras opções como estão.

    1. Sobre o **recursos avançados** painel, em **recursos avançados**, selecione apenas **controles ActiveX** e **manifesto de controle comuns**. Sob **avançadas de painéis de quadros**, selecione apenas a **painel de navegação** opção. Isso fará com que o assistente criar o painel à esquerda da janela com um `CMFCShellTreeCtrl` já inseridos.

    1. Não vamos fazer nenhuma alteração para o **Classes geradas** painel, portanto, clique em **concluir** para criar o novo projeto do MFC.

1. Verifique se que o aplicativo foi criado com êxito pela criação e executá-lo. Para compilar o aplicativo, do **construir** menu, selecione **compilar solução**. Se o aplicativo for compilado com êxito, execute o aplicativo, selecionando **iniciar depuração** da **depurar** menu.

   O assistente cria automaticamente um aplicativo que tem uma barra de menus padrão, uma barra de ferramentas padrão, uma barra de status padrão e uma barra do Outlook à esquerda da janela com uma **pastas** modo de exibição e uma **calendário** exibição .

### <a name="to-add-the-shell-list-control-to-the-document-view"></a>Para adicionar o controle de lista do shell para o modo de exibição de documento

1. Nesta seção, você adicionará uma instância de `CMFCShellListCtrl` para o modo de exibição criado pelo assistente. Abra o arquivo de cabeçalho do modo de exibição clicando duas vezes **MFCShellControlsView.h** na **Gerenciador de soluções**.

   Localize o `#pragma once` diretiva na parte superior do arquivo de cabeçalho. Imediatamente sob ele adicione este código para incluir o arquivo de cabeçalho para `CMFCShellListCtrl`:

   ```cpp
   #include <afxShellListCtrl.h>
   ```

   Agora, adicione uma variável de membro do tipo `CMFCShellListCtrl`. Primeiro, localize o seguinte comentário no arquivo de cabeçalho:

   ```cpp
   // Generated message map functions
   ```

   Imediatamente acima desse comentário, adicione este código:

   ```cpp
   private:
   CMFCShellListCtrl m_wndList;
   ```

1. O **Assistente de aplicativo MFC** já criou um `CMFCShellTreeCtrl` do objeto no `CMainFrame` classe, mas um membro protegido. Vamos acessar o objeto mais tarde, portanto, crie um acessador para que ele agora. Abra o arquivo de cabeçalho MainFrm.h clicando duas vezes na **Gerenciador de soluções**. Localize o comentário a seguir:

   ```cpp
   // Attributes
   ```

   Imediatamente abaixo dela, adicione a seguinte declaração de método:

   ```cpp
   public:
       CMFCShellTreeCtrl& GetShellTreeCtrl();
   ```

   Em seguida, abra o arquivo de origem MainFrm.cpp clicando duas vezes na **Gerenciador de soluções**. Na parte inferior do arquivo, adicione a seguinte definição de método:

   ```cpp
   CMFCShellTreeCtrl& CMainFrame::GetShellTreeCtrl()
   {
        return m_wndTree;
   }
   ```

1. Agora podemos atualizar o `CMFCShellControlsView` classe para manipular o `WM_CREATE` mensagem do windows. Abra o **Class View** janela e selecione o `CMFCShellControlsView` classe. Clique com botão direito e selecione **propriedades**.

    Em seguida, nos **propriedades** janela, clique no **mensagens** ícone. Role para baixo até encontrar o `WM_CREATE` mensagem. Na lista suspensa lista ao lado `WM_CREATE`, selecione  **\<Add > OnCreate**. O comando cria um manipulador de mensagens para nós e atualiza automaticamente o mapa de mensagens do MFC.

   No `OnCreate` método, agora, vamos criar nossa `CMFCShellListCtrl` objeto. Encontre o `OnCreate` definição de método no MFCShellControlsView.cpp arquivo de origem e substitua sua implementação com o código a seguir:

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

1. Repita a etapa anterior, mas para o `WM_SIZE` mensagem. Ele fará com que a exibição de aplicativos seja redesenhado sempre que um usuário altera o tamanho da janela do aplicativo. Substitua a definição para o `OnSize` método com o código a seguir:

    ```cpp
    void CMFCShellControlsView::OnSize(UINT nType, int cx, int cy)
    {
        CView::OnSize(nType, cx, cy);

        m_wndList.SetWindowPos(NULL, -1, -1, cx, cy,
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
    }
    ```

1. A última etapa é conectar-se a `CMFCShellTreeCtrl` e `CMFCShellListCtrl` objetos usando o [CMFCShellTreeCtrl::SetRelatedList](../mfc/reference/cmfcshelltreectrl-class.md#setrelatedlist) método. Depois de chamar `CMFCShellTreeCtrl::SetRelatedList`, o `CMFCShellListCtrl` exibirá automaticamente o conteúdo do item selecionado no `CMFCShellTreeCtrl`. Podemos nos conectar os objetos na `OnActivateView` método, que é substituído no [CView::OnActivateView](../mfc/reference/cview-class.md#onactivateview).

   No arquivo de cabeçalho MFCShellControlsView.h, dentro de `CMFCShellControlsView` declaração de classe, adicione a seguinte declaração de método:

    ```cpp
    protected:
    virtual void OnActivateView(BOOL bActivate,
        CView* pActivateView,
        CView* pDeactiveView);
    ```

   Em seguida, adicione a definição do método ao arquivo de origem MFCShellControlsView.cpp:

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

   Porque estamos chamando métodos do `CMainFrame` classe, devemos adicionar um `#include` diretiva na parte superior do arquivo de origem MFCShellControlsView.cpp:

    ```cpp
    #include "MainFrm.h"
    ```

1. Verifique se que o aplicativo foi criado com êxito pela criação e executá-lo. Para compilar o aplicativo, do **construir** menu, selecione **compilar solução**. Se o aplicativo foi compilado com êxito, execute-o, selecionando **iniciar depuração** da **depurar** menu.

   Agora você deve ver os detalhes do item selecionado no `CMFCShellTreeCtrl` no painel de exibição. Quando você clica em um nó a `CMFCShellTreeCtrl`, o `CMFCShellListCtrl` será atualizado automaticamente. Da mesma forma, se você clicar duas vezes em uma pasta na `CMFCShellListCtrl`, o `CMFCShellTreeCtrl` devem ser atualizados automaticamente.

   Clique em qualquer item no controle de árvore ou no controle de lista. Obter o mesmo menu de contexto, como se você estivesse usando o real **Explorador de arquivos**.

## <a name="next-steps"></a>Próximas etapas

- O assistente criou uma barra do Outlook com ambos um **pastas** painel e um **calendário** painel. Provavelmente não faz sentido ter um **calendário** painel em um **Explorer** janela, portanto, remova esse painel agora.

- O `CMFCShellListCtrl` suporta a exibição de arquivos em modos diferentes, como **ícones grandes**, **ícones pequenos**, **lista**, e **detalhes**. Atualize seu aplicativo para implementar essa funcionalidade. Dica: consulte [exemplos do Visual C++](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)
