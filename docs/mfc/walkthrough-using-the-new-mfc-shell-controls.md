---
title: "Instru&#231;&#245;es passo a passo: usando os novos controles de shell MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles de shell (MFC)"
ms.assetid: f0015caa-199d-4aaf-9501-5a239fce9095
caps.latest.revision: 14
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: usando os novos controles de shell MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Neste passo a passo, você criará um aplicativo semelhante ao Explorador de Arquivos.  Você criará uma janela que contém dois painéis.  O painel esquerdo conterá um objeto de [CMFCShellTreeCtrl](../mfc/reference/cmfcshelltreectrl-class.md) que exibe seu Área De Trabalho em uma exibição hierárquica.  O painel direito conterá [CMFCShellListCtrl](../mfc/reference/cmfcshelllistctrl-class.md) que mostra os arquivos da pasta selecionada no painel esquerdo.  
  
## Pré-requisitos  
 Este passo a passo pressupõe que você configurou [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para usar **Configurações Gerais de Desenvolvimento**.  Se você estiver usando uma configuração diferente de desenvolvimento, algumas janelas de [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] que usamos neste passo a passo não podem ser exibidas por padrão.  
  
### Para criar um novo aplicativo MFC usando o assistente de aplicativo MFC  
  
1.  Use **Assistente para Aplicativo do MFC** para criar um novo aplicativo MFC.  Para executar o assistente, no menu **Novo**de **Arquivo** , selecione e selecione **Projeto**.  A caixa de diálogo de **Novo Projeto** será exibida.  
  
2.  Na caixa de diálogo de **Novo Projeto** , expanda o nó de **Visual C\+\+** no painel de **Tipos de projeto** e selecione **MFC**.  Em seguida, no painel de **Modelos** , **Aplicativo do MFC**selecione.  Digite um nome para o projeto do, como `MFCShellControls` e clique em **OK**.  **Assistente para Aplicativo do MFC** Será exibido.  
  
3.  Na caixa de diálogo de **Assistente para Aplicativo do MFC** , clique **Avançar**.  O painel de **Tipo de Aplicativo** será exibido.  
  
4.  No painel de **Tipo de Aplicativo** , em **Tipo de Aplicativo**, desmarque a opção de **Documentos com guias** .  Em seguida, **Único documento** selecione e **Suporte à arquitetura do documento\/exibição**selecione.  Em **Estilo de projeto**, **Visual Studio**selecione, e de **Estilo e cores visuais** remove a lista para baixo **Office 2007 \(tema azul\)**selecione.  Deixe todas as outras opções são como.  Clique em **Avançar** para exibir o painel de **Suporte composto do documento** .  
  
5.  No painel de **Suporte composto do documento** , **Nenhum**selecione.  Clique em **Avançar** para exibir o painel de **Cadeias de caracteres de modelo de documento** .  
  
6.  Não faça as alterações no painel de **Cadeias de caracteres de modelo de documento** .  Clique em **Avançar** para exibir o painel de **Suporte de base de dados** .  
  
7.  No painel de **Suporte de base de dados** , **Nenhum** selecione como esse aplicativo não usa um base de dados.  Clique em **Avançar** para exibir o painel de **Recursos de interface do usuário** .  
  
8.  No painel de **Recursos de interface do usuário** , verifique se a opção de **Use uma barra de menus e uma barra de ferramentas** está selecionada.  Deixe todas as outras opções são como.  Clique em **Avançar** para exibir o painel de **Recursos Avançados** .  
  
9. No painel de **Recursos Avançados** , em **Recursos Avançados**, selecione somente **Controles ActiveX** e **Manifesto de controle comuns**.  Em **Painéis do quadro Avançado**, selecione somente a opção de **Painel de Navegação** .  Isso fará com que o assistente crie o painel à esquerda da janela com `CMFCShellTreeCtrl` já inserido.  Clique em **Avançar** para exibir o painel de **Classes geradas** .  
  
10. Nós estamos não vai fazer modificações ao painel de **Classes geradas** .  Consequentemente, clique em **Concluir** para criar seu novo projeto MFC.  
  
11. Verifique se o aplicativo foi criado com êxito criando e executando o.  Para criar o aplicativo, selecione no menu **Compilar solução**de **Compilar** .  Se o aplicativo compila com êxito, execute o aplicativo **Iniciar Depuração** selecionando no menu de **Depurar** .  
  
     O assistente cria automaticamente um aplicativo que tem uma barra de menus padrão, uma barra de ferramentas padrão, uma barra de status padrão, e uma barra do Outlook à esquerda da janela com uma exibição de **Pastas** e uma exibição de **Calendário** .  
  
### Para adicionar a lista de shell controle para a exibição do documento  
  
1.  Nesta seção, você adicionará uma instância de `CMFCShellListCtrl` para exibir o que o assistente criou.  Abra o arquivo de cabeçalho da exibição clicando duas vezes em MFCShellControlsView.h em **Gerenciador de Soluções**.  
  
     Localize a política de `#pragma once` na parte superior do arquivo de cabeçalho.  Imediatamente abaixo deles adicionar esse código para incluir o arquivo de cabeçalho para `CMFCShellListCtrl`:  
  
    ```  
    #include <afxShellListCtrl.h>  
    ```  
  
     Agora adicione uma variável de membro do tipo `CMFCShellListCtrl`.  Primeiro, localize o seguinte comentário no arquivo de cabeçalho:  
  
    ```  
    // Generated message map functions  
    ```  
  
     Imediatamente acima desse comentário adicionar esse código:  
  
    ```  
    private:  
        CMFCShellListCtrl m_wndList;  
    ```  
  
2.  **Assistente para Aplicativo do MFC** Já criou um objeto de `CMFCShellTreeCtrl` na classe de `CMainFrame` , mas é um membro protegido.  Nós acessaremos esse objeto posterior.  Consequentemente, crie um acessador para ele agora.  Abra o arquivo de cabeçalho de MainFrm.h clicando duas vezes no **Gerenciador de Soluções**.  Localize o seguinte comentário:  
  
    ```  
    // Attributes  
    ```  
  
     Imediatamente abaixo deles, adicione a declaração de método seguinte:  
  
    ```  
    public:  
        CMFCShellTreeCtrl& GetShellTreeCtrl();  
    ```  
  
     Em seguida, abra o arquivo de origem de MainFrm.cpp clicando duas vezes no **Gerenciador de Soluções**.  Na parte inferior desse arquivo, adicione a definição do método seguinte:  
  
    ```  
    CMFCShellTreeCtrl& CMainFrame::GetShellTreeCtrl()  
    {  
        return m_wndTree;  
    }  
    ```  
  
3.  Agora é atualizamos a classe de `CMFCShellControlsView` para tratar a mensagem do windows de **WM\_CREATE** .  Abra o arquivo de cabeçalho de MFCShellControlsView.h e clique em nessa linha de código:  
  
    ```  
    class CMFCShellControlsView : public CView  
    ```  
  
     Em seguida, na janela de **Propriedades** , clique no ícone de **Mensagens** .  Role para baixo até encontrar a mensagem de **WM\_CREATE** .  Remova da lista para baixo ao lado de **WM\_CREATE**, **\<Adicionar\> OnCreate**selecione.  Isso cria um manipulador de mensagens para nós e atualiza automaticamente o mapa da mensagem MFC.  
  
     No método de `OnCreate` criaremos agora nosso objeto de `CMFCShellListCtrl` .  Localizar a definição do método de `OnCreate` no arquivo de origem de MFCShellControlsView.cpp, e substitua a implementação pelo seguinte código:  
  
    ```  
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
  
4.  Repita a etapa anterior mas para a mensagem de **WM\_SIZE** .  Isso causará a exibição de aplicativos a ser redesenhada sempre que um usuário altera o tamanho da janela do aplicativo.  Substitua a definição para o método de `OnSize` pelo seguinte código:  
  
    ```  
    void CMFCShellControlsView::OnSize(UINT nType, int cx, int cy)  
    {  
        CView::OnSize(nType, cx, cy);  
        m_wndList.SetWindowPos(NULL, -1, -1, cx, cy,  
            SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);  
    }  
    ```  
  
5.  A última etapa é conectar os objetos de `CMFCShellTreeCtrl` e de `CMFCShellListCtrl` usando o método de [CMFCShellTreeCtrl::SetRelatedList](../Topic/CMFCShellTreeCtrl::SetRelatedList.md) .  Depois que você chama esse método, `CMFCShellListCtrl` exibirá automaticamente o conteúdo do item selecionado em `CMFCShellTreeCtrl`.  Nós faremos o método de `OnActivateView` , que é substituído de [CView::OnActivateView](../Topic/CView::OnActivateView.md).  
  
     No arquivo de cabeçalho de MFCShellControlsView.h, na declaração de classe de `CMFCShellControlsView` , adicione a declaração de método seguinte:  
  
    ```  
    protected:  
        virtual void OnActivateView(BOOL bActivate,  
            CView* pActivateView,  
            CView* pDeactiveView);  
    ```  
  
     Em seguida, adicione a definição deste método no arquivo de origem de MFCShellControlsView.cpp:  
  
    ```  
    void CMFCShellControlsView::OnActivateView(BOOL bActivate,  
        CView* pActivateView,  
        CView* pDeactiveView)   
    {  
        if (bActivate && AfxGetMainWnd() != NULL)  
        {  
            ((CMainFrame*)AfxGetMainWnd())->GetShellTreeCtrl().SetRelatedList(&m_wndList);  
        }  
  
        CView::OnActivateView(bActivate, pActivateView, pDeactiveView);  
    }  
    ```  
  
     Como estamos chamando os métodos de `CMainFrame` classificação, nós devem adicionar uma política de `#include` na parte superior do arquivo de origem de MFCShellControlsView.cpp:  
  
    ```  
    #include "MainFrm.h"  
    ```  
  
6.  Verifique se o aplicativo foi criado com êxito criando e executando o.  Para criar o aplicativo, selecione no menu **Compilar solução**de **Compilar** .  Se o aplicativo compila com êxito, execute\-o **Iniciar Depuração** selecionando no menu de **Depurar** .  
  
     Você deve ver os detalhes do item selecionado em `CMFCShellTreeCtrl` no painel de exibição.  Quando você clicar em um nó em `CMFCShellTreeCtrl`, `CMFCShellListCtrl` será atualizado automaticamente.  Também, se você clicar duas vezes em uma pasta em `CMFCShellListCtrl`, `CMFCShellTreeCtrl` deve ser atualizado automaticamente.  
  
     Clique com o botão direito do mouse em qualquer item no controle de árvore ou no controle da lista.  Observe que você obtém o mesmo menu de contexto como se você estiver usando o pesquisador de Arquivos real.  
  
## Próximas etapas  
  
-   O assistente criou uma barra do Outlook com um painel de **Pastas** e um painel de **Calendário** .  Provavelmente não faz sentido ter um painel de **Calendário** em uma janela do Explorer.  Consequentemente, remova esse painel agora.  
  
-   `CMFCShellListCtrl` oferece suporte a arquivos de exibição nos modos diferentes, como **Ícones Grandes**, **Ícones Pequenos**, **Lista**, e **Detalhes**.  Atualizar seu aplicativo implementar essa funcionalidade.  Dica: consulte [Exemplos do Visual C\+\+](../top/visual-cpp-samples.md).  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)