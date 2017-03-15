---
title: "Instru&#231;&#245;es passo a passo: atualizando o aplicativo de rabisco MFC (parte 1) | Microsoft Docs"
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
  - "exemplos [C++], atualizar aplicativo existente"
  - "MFC Feature Pack, atualizar aplicativo existente"
  - "Interface de Usuário do Office Fluent, movimentando para"
  - "Interface de Usuário da faixa de opções, movimentando para"
  - "exemplos [C++], atualizar aplicativo existente"
  - "explicações passo a passo [C++], atualizar aplicativo existente"
ms.assetid: aa6330d3-6cfc-4c79-8fcb-0282263025f7
caps.latest.revision: 54
caps.handback.revision: 50
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este passo a passo demonstra como alterar um aplicativo existente MFC usar a interface do usuário da Faixa De Opções.  Visual Studio oferece suporte ao Office 2007 a Faixa De Opções e Windows 7 a Faixa De Opções cênico.  Para obter mais informações sobre a interface do usuário da Faixa De Opções, consulte [Fitas](http://go.microsoft.com/fwlink/?LinkId=129233) no site do MSDN.  
  
 Este passo a passo altera o garrancho clássico 1,0 MFC de exemplo que permite usar o mouse para criar um lápis desenhos.  Essa parte do passo a passo mostra como alterar o exemplo de garrancho de modo que exibe uma barra de fita.  [Parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md) adiciona mais botões na barra de fita.  
  
## Pré-requisitos  
 [Exemplos do Visual C\+\+](../top/visual-cpp-samples.md)  
  
 [Exemplos do Visual C\+\+](../top/visual-cpp-samples.md)  
  
##  <a name="top"></a> Seções  
 Essa parte do passo a passo tem as seguintes seções:  
  
-   [Substituindo as classes base](#replaceClass)  
  
-   [Adicionando bitmaps ao projeto](#addBitmap)  
  
-   [Adicionando um recurso da Faixa De Opções ao projeto](#addRibbon)  
  
-   [Criando uma instância da barra da Faixa De Opções](#createInstance)  
  
-   [Adicionando uma categoria da Faixa De Opções](#addCategory)  
  
-   [Definindo o aspecto de aplicativo](#setLook)  
  
##  <a name="replaceClass"></a> Substituindo as classes base  
 Para converter um aplicativo que da suporte a um menu com um aplicativo que oferece suporte a uma fita, você deve derivar o aplicativo, a janela do quadro, e as classes da barra de ferramentas das classes base atualizados. \(Nós sugerimos que você não modifique o exemplo original de garrancho; em vez disso, limpe o projeto de garrancho, copie\-o para outro diretório, e depois modificá\-lo a cópia.\)  
  
#### Para substituir as classes base no aplicativo de garrancho  
  
1.  Em scribble.cpp, verifique se `CScribbleApp::InitInstance` inclui uma chamada a [AfxOleInit](../Topic/AfxOleInit.md).  
  
2.  Adicione o seguinte código para o arquivo de stdafx.h.  
  
    ```  
    #include <afxcontrolbars.h>  
    ```  
  
3.  Em scribble.h, modifique a definição da classe de `CScribbleApp` de modo que seja derivada de [Classe de CWinAppEx](../mfc/reference/cwinappex-class.md).  
  
    ```  
    class CScribbleApp: public CWinAppEx  
    ```  
  
4.  O garrancho 1,0 foi escrita quando os aplicativos do Windows usaram um arquivo .ini de inicialização \(\) para salvar dados de preferências do usuário.  Em vez de um arquivo de inicialização, modifique o garrancho para armazenar preferências do usuário no Registro.  Para definir a chave do Registro e a base, digite o seguinte código em `CScribbleApp::InitInstance` depois da instrução de `LoadStdProfileSettings()` .  
  
    ```  
    SetRegistryKey(_T("MFCNext\\Samples\\Scribble2"));  
    SetRegistryBase(_T("Settings"));  
    ```  
  
5.  O quadro principal para um aplicativo \(MDI\) de interface de documentos já não é derivado da classe de `CMDIFrameWnd` .  Em vez disso, é derivado da classe de [CMDIFrameWndEx](../Topic/CMDIFrameWndEx%20Class.md) .  
  
     Nos arquivos de mainfrm.h e de mainfrm.cpp, substitua todas as referências a `CMDIFrameWnd` com `CMDIFrameWndEx`.  
  
6.  Nos arquivos de childfrm.h e de childfrm.cpp, substitua `CMDIChildWnd` com `CMDIChildWndEx`.  
  
     No childfrm. o arquivo de h, substitui `CSplitterWnd` com `CSplitterWndEx`.  
  
7.  Modifique as barras de ferramentas e barras de status para usar as novas classes MFC.  
  
     No arquivo de mainfrm.h:  
  
    1.  Substitua `CToolBar` com `CMFCToolBar`.  
  
    2.  Substitua `CStatusBar` com `CMFCStatusBar`.  
  
8.  No arquivo de mainfrm.cpp:  
  
    1.  Substituir `m_wndToolBar.SetBarStyle` com `m_wndToolBar.SetPaneStyle`  
  
    2.  Substituir `m_wndToolBar.GetBarStyle` com `m_wndToolBar.GetPaneStyle`  
  
    3.  Substituir `DockControlBar(&m_wndToolBar)` com `DockPane(&m_wndToolBar)`  
  
9. No arquivo de ipframe.cpp, comentam das três linhas de código.  
  
    ```  
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);  
    pWndFrame->EnableDocking(CBRS_ALIGN_ANY);  
    pWndFrame->DockPane(&m_wndToolBar);  
    ```  
  
10. Se você pretende estaticamente vincular seu aplicativo, adicione o seguinte código para o início do arquivo do recurso de projeto \(.rc\).  
  
    ```  
    #include "afxribbon.rc"  
    ```  
  
     O arquivo de afxribbon.rc contém os recursos necessários em tempo de execução.  [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md) inclui esse arquivo automaticamente quando você cria um aplicativo.  
  
11. Salvar as alterações e depois criar e executar o aplicativo.  
  
 \[[Seções](#top)\]  
  
##  <a name="addBitmap"></a> Adicionando bitmaps ao projeto  
 As quatro etapas deste passo a passo necessitarem de recursos de bitmap.  Você pode obter bitmaps apropriadas em muitas maneiras:  
  
-   Use [Editores de recursos](../mfc/resource-editors.md) para inventar seus próprios bitmaps.  Ou use os editores de recursos para montar bitmaps de imagens portáteis dos gráficos de rede \(.png\) que são incluídas em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  Essas imagens estão no diretório de `VS2008ImageLibrary`.  
  
     No entanto, a interface do usuário da Faixa De Opções requer que certos bitmaps dão suporte a imagens transparentes.  Os bitmaps transparentes usam os pixels de 32 bits, onde 24 bit especifica os componentes vermelho, verde e azul, color, e 8 bits definem *um canal alfa* que especifica a transparência da cor.  Os editores atuais do recurso podem exibir, mas não altere bitmaps com pixels de 32 bits.  Em virtude disso, use um editor de imagem externa em vez dos editores de recursos para manipular bitmaps transparentes.  
  
-   Copiar um arquivo de recurso apropriado de outro aplicativo ao seu projeto e importe bitmaps desse arquivo.  
  
 Este passo a passo copia arquivos de recurso de um aplicativo no diretório de Exemplos.  
  
#### Para adicionar bitmaps ao projeto  
  
1.  Use o gerenciador de Arquivos para copiar os seguintes arquivos .bmp de diretório de recursos \(\)`res`de exemplo de RibbonGadgets:  
  
    1.  Copiar main.bmp ao seu projeto de garrancho.  
  
    2.  Copiar filesmall.bmp e filelarge.bmp ao seu projeto de garrancho.  
  
    3.  Crie novas cópias dos arquivos de filelarge.bmp e de filesmall.bmp, mas salvar as cópias no exemplo de RibbonGadgets.  Renomear as cópias homesmall.bmp e homelarge.bmp e mover as cópias ao seu projeto de garrancho.  
  
    4.  Faça uma cópia do toolbar.bmp arquivo, mas salvar a cópia no exemplo de RibbonGadgets.  Renomeie a cópia panelicons.bmp e mover a cópia ao seu projeto de garrancho.  
  
2.  Importar o bitmap para um aplicativo de MFC.  Em **Modo de Exibição de Recurso**, clique duas vezes no nó de **scribble.rc** , clique duas vezes no nó de **Bitmap** , e clique em **Adicionar recurso**.  Na caixa de diálogo que aparece, clique em **Importar**.  Navegue até o diretório de `res` , selecione o arquivo de main.bmp, e clique em **Abrir**.  
  
     O bitmap de main.bmp contém uma imagem 26x26.  Alterar a ID de bitmap a IDB\_RIBBON\_MAIN.  
  
3.  Importar os bitmaps do menu arquivo anexado ao botão do aplicativo.  
  
    1.  Importar o arquivo de filesmall.bmp, que contém dez \(16x160 imagens 16x16\).  Como precisamos somente oito imagens 16x128 16x16 \(\), use **Modo de Exibição de Recurso** para alterar a largura do bitmap de 160 a 128.  Alterar a ID de bitmap a IDB\_RIBBON\_FILESMALL.  
  
    2.  Importar o filelarge.bmp, que contém oito \(\) 32x256 imagens 32x32.  Alterar a ID de bitmap a IDB\_RIBBON\_FILELARGE.  
  
4.  Importar os bitmaps para as categorias e os painéis de fita.  Cada guia na barra de fita é uma categoria, e consiste em um rótulo de texto e uma imagem opcional.  
  
    1.  Importar o bitmap de homesmall.bmp, que contém imagens oito 16x16 para bitmaps pequenos do botão.  Alterar a ID de bitmap a IDB\_RIBBON\_HOMESMALL.  
  
    2.  Importar o bitmap de homelarge.bmp, que contém imagens oito 32x32 para bitmaps grandes do botão.  Alterar a ID de bitmap a IDB\_RIBBON\_HOMELARGE.  
  
5.  Importar bitmaps para os painéis redimensionados de fita.  Esses bitmaps, ou os ícones do painel, são usados depois que uma operação de redimensionamento se a fita é muito pequena exibir o painel inteiro.  
  
    1.  Importar o bitmap de panelicons.bmp, que contém imagens oito 16x16.  Na janela de **Propriedades** de **Editor de Bitmap**, ajuste a largura de bitmap como 64 \(16x64\).  Alterar a ID de bitmap a IDB\_PANEL\_ICONS.  
  
 \[[Seções](#top)\]  
  
##  <a name="addRibbon"></a> Adicionando um recurso da Faixa De Opções ao projeto  
 Quando você converte um aplicativo que use menus a um aplicativo que usa uma fita, você não precisa remover ou desabilitar os menus existentes.  Em vez disso, você cria um recurso de fita, adiciona botões de fita, e associa os novos botões com os itens de menu existentes.  Embora os menus não sejam visíveis, as mensagens da barra de fita são roteadas através de menus.  Além disso, os atalhos de menu continuam a funcionar.  
  
 Uma fita consiste no botão do aplicativo, que é grande o botão no lado superior esquerdo da faixa de opções, e um ou vários guias de categoria.  Cada guia da categoria contém um ou mais painéis que atuam como contêineres dos botões e os controles de fita.  O procedimento a seguir mostra como criar um recurso de fita e personalizar no botão do aplicativo.  
  
#### Para adicionar um recurso de fita ao projeto  
  
1.  No menu de **Projeto** , clique **Adicionar Recurso**.  
  
2.  Na caixa de diálogo de **Adicionar Recurso** , **Faixa de Opções** selecione e clique em **Novo**.  
  
     Visual Studio cria um recurso de fita e abri\-lo no Modo Design.  A ID do recurso de fita é IDR\_RIBBON1, que é exibido em **Modo de Exibição de Recurso**.  A fita contém uma categoria e um painel.  
  
3.  Você pode personalizar o botão do aplicativo com a alteração de suas propriedades.  As IDs de mensagem que são usados neste código já estejam definidos no menu para o garrancho 1,0.  
  
4.  No Modo Design, clique no botão do aplicativo para exibir suas propriedades.  Valores de propriedade de alteração como segue: **Imagem** a `IDB_RIBBON_MAIN`, **Aviso** a `Arquivo`, **Chaves** a `f`, **Imagens Grandes** a `IDB_RIBBON_FILELARGE`, e **Imagens Pequenas** a `IDB_RIBBON_FILESMALL`.  
  
5.  As alterações a seguir criam o menu exibido quando o usuário clica no botão do aplicativo.  Clique nas reticências \(**...**\) ao lado de **Itens principais** para abrir **Editor de Itens**.  
  
    1.  Clique **Adicionar** para adicionar um botão.  Alteração **Legenda** a `&New`, **ID** a `ID_FILE_NEW`, **Imagem** a `0`, **Imagem Grande** a `0`.  
  
    2.  Clique **Adicionar** para adicionar um segundo botão.  Alteração **Legenda** a `&Save`, a **ID** a `ID_FILE_SAVE`, a **Imagem** a `2`, e a **Imagem Grande** a `2`.  
  
    3.  Clique **Adicionar** para adicionar um terceiro botão.  Alteração **Legenda** a `Salvar &Como`, a **ID** a `ID_FILE_SAVE_AS`, a **Imagem** a `3`, e a **Imagem Grande** a `3`.  
  
    4.  Clique **Adicionar** para adicionar um quarto botão.  Alteração **Legenda** a `&Print`, a **ID** a `ID_FILE_PRINT`, a **Imagem** a `4`, e a **Imagem Grande** a `4`.  
  
    5.  Alterar o tipo de **Item** a **Separador** e clique em **Adicionar**.  
  
    6.  Alterar o tipo de **Item** a **Botão**.  Clique para adicionar um **Adicionar** quinto botão.  Alteração **Legenda** a `&Close`, a **ID** a `ID_FILE_CLOSE`, a **Imagem** a `5`, e a **Imagem Grande** a `5`.  
  
6.  As alterações a seguir criam um submenu no botão de cópia que você criou na etapa anterior.  
  
    1.  Clique no botão de **Imprimir** , altere o tipo de **Item** a **Rótulo**, e clique em **Inserir**.  Alterar **Legenda** a `Visualizar e imprime o documento`.  
  
    2.  Clique no botão de **Imprimir** , altere o tipo de **Item** a **Botão**, e clique **Inserir**.  Alteração **Legenda** a `&Print`, a **ID** a `ID_FILE_PRINT`, a **Imagem** a `4`, e a **Imagem Grande** a `4`.  
  
    3.  Clique no botão de **Imprimir** e clique em **Inserir** para adicionar um botão.  Alteração **Legenda** a `&Quick Print`, a **ID** a `ID_FILE_PRINT_DIRECT`, a **Imagem** a `7`, e a **Imagem Grande** a `7`.  
  
    4.  Clique no botão de **Imprimir** e clique em **Inserir** para adicionar outro botão.  Alteração **Legenda** a `Cópia pre&exibição`, a **ID** a `ID_FILE_PRINT_PREVIEW`, a **Imagem** a `6`, e a **Imagem Grande** a`6`.  
  
    5.  Você agora foi **Itens principais**.  Clique em para sair **Fechar Editor de Itens**.  
  
7.  A seguinte alteração criar um botão de saída que aparece na parte inferior do menu do botão do aplicativo.  
  
    1.  Na janela de **Propriedades** , clique nas reticências \(**...**\) ao lado de **Botão** para abrir **Editor de Itens**.  
  
    2.  Clique **Adicionar** para adicionar um botão.  Alteração **Legenda** a `E&xit`, **ID** a `ID_APP_EXIT`, **Imagem** a`8`.  
  
 \[[Seções](#top)\]  
  
##  <a name="createInstance"></a> Criando uma instância da barra da Faixa De Opções  
 As seguintes etapas exibir como criar uma instância da barra de fita quando seus iniciar o aplicativo.  Para adicionar uma barra de fita a um aplicativo, declarar a barra de fita no arquivo de mainfrm.h.  Em seguida, no arquivo de mainfrm.cpp, grave o código para carregar o recurso de fita.  
  
#### Para criar uma instância da barra de fita  
  
1.  No arquivo de mainfrm.h, adicione um membro de dados protegida a seção de `CMainFrame`, a definição da classe para o quadro principal.  Esse membro representa a barra de fita.  
  
    ```  
    // Ribbon bar for the application  
    CMFCRibbonBar  m_wndRibbonBar;  
    ```  
  
2.  No arquivo de mainfrm.cpp, adicione o seguinte código antes que a instrução final de `return` no final da função de `CMainFrame::OnCreate` .  Cria uma instância da barra de fita.  
  
    ```  
    // Create the ribbon bar  
    if (!m_wndRibbonBar.Create(this))  
    {  
    return -1;   //Failed to create ribbon bar  
    }  
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);  
    ```  
  
 \[[Seções](#top)\]  
  
##  <a name="addCategory"></a> Personalizando o recurso da Faixa De Opções  
 Agora que você criou o botão do aplicativo, você pode adicionar elementos à fita.  
  
> [!NOTE]
>  Este passo a passo usa o mesmo ícone do painel para todos os painéis.  No entanto, você pode usar outros índices da lista de imagem para exibir outros ícones.  
  
#### Para adicionar uma categoria de início e um painel de edição  
  
1.  O programa de garrancho requer somente uma categoria.  No Modo Design, clique em **Categoria** para exibir suas propriedades.  Valores de propriedade de alteração como segue: **Legenda** a `&Home`, **Imagens Grandes** a `IDB_RIBBON_HOMELARGE`, **Imagens Pequenas** a `IDB_RIBBON_HOMESMALL`.  
  
2.  Cada categoria de fita é organizada nos painéis nomeados.  Cada painel contém um conjunto de controles que executam operações relacionadas.  Esta categoria tem um painel.  Clique em **Painel**, e altere **Legenda** a `Edição` e **Índice de imagens** a `0`.  
  
3.  No painel de **Editar** , adicione um botão que é responsável para limpar o conteúdo do documento.  O ID de mensagem para esse botão tiver sido definido no recurso no menu de IDR\_SCRIBBTYPE.  Especifique `Limpar tudo` porque o texto do botão e o índice de bitmap que decora o botão.  Abra **Caixa de Ferramentas**, e depois arraste **Botão** ao painel de **Editar** .  Clique no botão e altere **Legenda** a `Limpar tudo`, **ID** a `ID_EDIT_CLEAR_ALL`, **Índice de imagens** a `0`, **Índice da Imagem Grande** a `0`.  
  
4.  Salvar as alterações, e depois criar e executar o aplicativo.  O aplicativo de garrancho deve ser exibido, e deve ter uma barra de fita na parte superior da janela em vez de uma barra de menus.  A barra de fita deve ter uma categoria, **Início**, e **Início** deve ter um painel, **Editar**.  Os botões de fita que você adicionou devem ser associados aos manipuladores de eventos existentes, e o **Abrir**, **Fechar**, **Salvar**, **Imprimir**, e os botões de **Limpar Tudo** devem funcionar conforme o esperado.  
  
 \[[Seções](#top)\]  
  
##  <a name="setLook"></a> Definindo o aspecto de aplicativo  
 *Um gerenciador visual* é um objeto global que controla todo o desenho de um aplicativo.  Como o aplicativo original de garrancho usa o estilo de \(UI\) da interface do usuário do Office 2000, o aplicativo pode ficar desatualizado.  Você pode redefinir o aplicativo usar o gerenciador visual do Office 2007 de forma semelhante a um aplicativo do Office 2007.  
  
#### Para definir o aspecto de aplicativo  
  
1.  Na função de `CMainFrame::OnCreate` , digite o seguinte código para modificar o gerenciador e o estilo visual padrão.  
  
    ```  
    // Set the default manager to Office 2007   
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));  
    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);  
    ```  
  
2.  Salvar as alterações, e depois criar e executar o aplicativo.  O aplicativo interface do usuário deve ser semelhante ao do Office 2007 interface do usuário.  
  
 \[[Seções](#top)\]  
  
## Próximas etapas  
 Você alterou o exemplo clássico MFC de garrancho 1,0 para usar o designer da Faixa De Opções.  Vá agora a [Parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md).  
  
## Consulte também  
 [Explicações Passo\-a\-passo](../mfc/walkthroughs-mfc.md)   
 [Instruções passo a passo: atualizando o aplicativo de rabisco MFC \(parte 2\)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md)