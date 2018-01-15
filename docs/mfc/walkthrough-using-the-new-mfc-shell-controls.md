---
title: 'Passo a passo: Usando o MFC novos controles de Shell | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: shell controls (MFC)
ms.assetid: f0015caa-199d-4aaf-9501-5a239fce9095
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: be882671da836f7d96f4c726753d6235735f363d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-using-the-new-mfc-shell-controls"></a>Instruções passo a passo: usando os novos controles de shell MFC
Este passo a passo, você criará um aplicativo que se parece com o Explorador de arquivos. Você criará uma janela que contém dois painéis. O painel esquerdo conterá um [CMFCShellTreeCtrl](../mfc/reference/cmfcshelltreectrl-class.md) objeto que exibe sua área de trabalho em uma exibição hierárquica. O painel à direita conterá um [CMFCShellListCtrl](../mfc/reference/cmfcshelllistctrl-class.md) que mostra os arquivos na pasta selecionada no painel esquerdo.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Este passo a passo pressupõe que você configurou o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] usar **configurações gerais de desenvolvimento**. Se você estiver usando uma configuração diferente de desenvolvimento, alguns [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] windows que usamos neste passo a passo não podem ser exibidos por padrão.  
  
### <a name="to-create-a-new-mfc-application-by-using-the-mfc-application-wizard"></a>Para criar um novo aplicativo do MFC usando o Assistente de aplicativo MFC  
  
1.  Use o **Assistente de aplicativo MFC** para criar um novo aplicativo do MFC. Para executar o assistente, a partir de **arquivo** menu, selecione **novo**e, em seguida, selecione **projeto**. O **novo projeto** caixa de diálogo será exibida.  
  
2.  No **novo projeto** caixa de diálogo caixa, expanda o **Visual C++** nó o **tipos de projeto** painel e selecione **MFC**. Em seguida, no **modelos** painel, selecione **aplicativo MFC**. Digite um nome para o projeto, como `MFCShellControls` e clique em **Okey**. O **Assistente de aplicativo MFC** será exibido.  
  
3.  No **Assistente de aplicativo MFC** caixa de diálogo, clique em **próximo**. O **tipo de aplicativo** painel será exibido.  
  
4.  Sobre o **tipo de aplicativo** painel, em **tipo de aplicativo**, desmarque o **documentos com guias** opção. Em seguida, selecione **único documento** e selecione **suporte para a arquitetura de documento/exibição**. Em **estilo de projeto**, selecione **Visual Studio**e o **cores e o estilo Visual** suspensa lista, selecione **Office 2007 (tema azul)**. Deixe todas as outras opções como estão. Clique em **próximo** para exibir o **suporte a documentos compostos** painel.  
  
5.  Sobre o **suporte a documentos compostos** painel, selecione **nenhum**. Clique em **próximo** para exibir o **cadeias de caracteres de modelo de documento** painel.  
  
6.  Não faça nenhuma alteração de **cadeias de caracteres de modelo de documento** painel. Clique em **próximo** para exibir o **suporte do banco de dados** painel.  
  
7.  Sobre o **suporte do banco de dados** painel, selecione **nenhum** porque este aplicativo não usa um banco de dados. Clique em **próximo** para exibir o **recursos de Interface do usuário** painel.  
  
8.  No **recursos de Interface do usuário** painel, verifique se o **usam uma barra de menu e barra de ferramentas** opção é selecionada. Deixe todas as outras opções como estão. Clique em **próximo** para exibir o **recursos avançados** painel.  
  
9. Sobre o **recursos avançados** painel, em **recursos avançados**, selecione apenas **controles ActiveX** e **manifesto comuns de controle**. Em **avançado painéis de quadros**, selecione apenas o **painel de navegação** opção. Isso fará com que o Assistente para criar o painel à esquerda da janela com um `CMFCShellTreeCtrl` já inseridos. Clique em **próximo** para exibir o **Classes geradas pelo** painel.  
  
10. Não vamos fazer alterações para o **Classes geradas pelo** painel. Portanto, clique em **concluir** para criar o novo projeto do MFC.  
  
11. Verifique se que o aplicativo foi criado com êxito ao criar e executá-lo. Para criar o aplicativo, do **criar** menu, selecione **compilar solução**. Se o aplicativo foi criado com êxito, execute o aplicativo selecionando **iniciar depuração** do **depurar** menu.  
  
     O assistente cria automaticamente um aplicativo que tem uma barra de menus padrão, uma barra de ferramentas padrão, uma barra de status padrão e uma barra do Outlook à esquerda da janela com um **pastas** exibição e um **calendário** exibição .  
  
### <a name="to-add-the-shell-list-control-to-the-document-view"></a>Para adicionar o controle de lista do shell para o modo de exibição de documento  
  
1.  Nesta seção, você irá adicionar uma instância de `CMFCShellListCtrl` para o modo de exibição que o assistente criou. Abra o arquivo de cabeçalho do modo de exibição clicando duas vezes MFCShellControlsView.h no **Gerenciador de soluções**.  
  
     Localize o `#pragma once` diretiva na parte superior do arquivo de cabeçalho. Imediatamente sob ele adicione este código para incluir o arquivo de cabeçalho para `CMFCShellListCtrl`:  
  
 ```  
    #include <afxShellListCtrl.h>  
 ```  
  
     Agora, adicione uma variável de membro de tipo `CMFCShellListCtrl`. Primeiro, localize o seguinte comentário no arquivo de cabeçalho:  
  
 ' ' * / / Funções de mapa de mensagem geradas  
 ```  
  
     Immediately above that comment add this code:  
  
 ```  
    particular: CMFCShellListCtrl m_wndList;  
 ```  
  
2.  The **MFC Application Wizard** already created a `CMFCShellTreeCtrl` object in the `CMainFrame` class, but it is a protected member. We will access this object later. Therefore, create an accessor for it now. Open the MainFrm.h header file by double-clicking it in the **Solution Explorer**. Locate the following comment:  
  
 ``` *// Attributes  
 ```  
  
     Imediatamente abaixo dela, adicione a declaração de método a seguir:  
  
 ```  
    public: 
    CMFCShellTreeCtrl& GetShellTreeCtrl();

 ```  
  
     Em seguida, abra o arquivo de origem MainFrm.cpp clicando duas vezes no **Gerenciador de soluções**. Na parte inferior do arquivo, adicione a seguinte definição de método:  
  
 ```  
    CMFCShellTreeCtrl& CMainFrame::GetShellTreeCtrl()  
 {  
    return m_wndTree;  
 }  
 ```  
  
3.  Agora podemos atualizar o `CMFCShellControlsView` classe para manipular o **WM_CREATE** mensagem do windows. Abra o arquivo de cabeçalho MFCShellControlsView.h e clique nesta linha de código:  
  
 ```  
    class CMFCShellControlsView : public CView  
 ```  
  
     Em seguida, no **propriedades** janela, clique no **mensagens** ícone. Role para baixo até encontrar o **WM_CREATE** mensagem. Na lista suspensa lista ao lado **WM_CREATE**, selecione  **\<Adicionar > OnCreate**. Isso cria um manipulador de mensagens para nós e atualiza automaticamente o mapa de mensagens do MFC.  
  
     No `OnCreate` método agora, vamos criar nossa `CMFCShellListCtrl` objeto. Localizar o `OnCreate` definição de método no MFCShellControlsView.cpp arquivo de origem e substitua sua implementação com o código a seguir:  
  
 ```  
    int CMFCShellControlsView::OnCreate(LPCREATESTRUCT lpCreateStruct)  
 {  
    if (CView::OnCreate(lpCreateStruct) == -1)  
    return -1;  
 
    CRect rectDummy (0,
    0,
    0,
    0);

    m_wndList.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT,  
    rectDummy,
    this,
    1);

 
    return 0;  
 }  
 ```  
  
4.  Repita a etapa anterior, mas para o **WM_SIZE** mensagem. Isso fará com que a exibição de aplicativos para ser redesenhado sempre que um usuário altera o tamanho da janela do aplicativo. Substitua a definição para o `OnSize` método com o código a seguir:  
  
 ```  
    void CMFCShellControlsView::OnSize(UINT nType,
    int cx,
    int cy)  
 {  
    CView::OnSize(nType,
    cx,
    cy);

    m_wndList.SetWindowPos(NULL, -1, -1,
    cx,
    cy,  
    SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

 }  
 ```  
  
5.  A última etapa é conectar-se a `CMFCShellTreeCtrl` e `CMFCShellListCtrl` objetos usando o [CMFCShellTreeCtrl::SetRelatedList](../mfc/reference/cmfcshelltreectrl-class.md#setrelatedlist) método. Depois de chamar esse método, o `CMFCShellListCtrl` exibirá automaticamente o conteúdo do item selecionado no `CMFCShellTreeCtrl`. Faremos isso `OnActivateView` método, que é substituído de [CView::OnActivateView](../mfc/reference/cview-class.md#onactivateview).  
  
     No arquivo de cabeçalho MFCShellControlsView.h, dentro de `CMFCShellControlsView` declaração de classe, adicione a declaração de método a seguir:  
  
 ```  
    protected: 
    virtual void OnActivateView(BOOL bActivate,  
    CView* pActivateView,  
    CView* pDeactiveView);

 ```  
  
     Em seguida, adicione a definição para esse método para o arquivo de origem MFCShellControlsView.cpp:  
  
 ```  
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
  
     Porque estamos ligando para métodos de `CMainFrame` classe, devemos adicionar um `#include` diretiva na parte superior do arquivo de origem MFCShellControlsView.cpp:  
  
 ```  
    #include "MainFrm.h"  
 ```  
  
6.  Verifique se que o aplicativo foi criado com êxito ao criar e executá-lo. Para criar o aplicativo, do **criar** menu, selecione **compilar solução**. Se o aplicativo foi criado com êxito, execute-o selecionando **iniciar depuração** do **depurar** menu.  
  
     Agora você deve ver os detalhes do item selecionado no `CMFCShellTreeCtrl` no painel de exibição. Quando você clica em um nó de `CMFCShellTreeCtrl`, o `CMFCShellListCtrl` será atualizado automaticamente. Da mesma forma, se você clicar duas vezes em uma pasta de `CMFCShellListCtrl`, o `CMFCShellTreeCtrl` devem ser atualizados automaticamente.  
  
     À direita, clique em qualquer item no controle de árvore ou na lista de controle. Observe que você obtenha o mesmo menu de contexto, como se estivesse usando o Explorador de arquivos real.  
  
## <a name="next-steps"></a>Próximas etapas  
  
-   O assistente criou uma barra do Outlook com ambos um **pastas** painel e um **calendário** painel. Provavelmente não faz sentido ter um **calendário** painel em uma janela do Explorer. Portanto, remova esse painel agora.  
  
-   O `CMFCShellListCtrl` oferece suporte à exibição de arquivos em diferentes modos, como **ícones grandes**, **ícones pequenos**, **lista**, e **detalhes**. Atualize seu aplicativo para implementar essa funcionalidade. Dica: consulte [amostras do Visual C++](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)

