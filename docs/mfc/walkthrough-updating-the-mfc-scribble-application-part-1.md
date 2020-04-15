---
title: 'Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)'
ms.date: 09/09/2019
helpviewer_keywords:
- examples [MFC], update existing application
- ribbon UI, porting to
- Office Fluent UI, porting to
- samples [MFC], update existing application
- MFC Feature Pack, update existing application
- walkthroughs [MFC], update existing application
ms.assetid: aa6330d3-6cfc-4c79-8fcb-0282263025f7
ms.openlocfilehash: 18803d2222c80b80ac2b1fde75b442ea1e9a89bb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360252"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-1"></a>Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 1)

Este passo a passo demonstra como modificar um aplicativo MFC existente para usar a interface do usuário Ribbon. O Visual Studio suporta tanto o Office 2007 Ribbon quanto o Windows 7 Scenic Ribbon. Para obter mais informações sobre a interface do usuário Ribbon, consulte [Ribbons](/windows/win32/uxguide/cmd-ribbons).

Este passo a passo modifica a clássica amostra de Scribble 1.0 MFC que permite usar o mouse para criar desenhos de linha. Esta parte do passo a passo mostra como modificar a amostra de Rabisco para que ela exiba uma barra de fita. [A parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md) adiciona mais botões à barra de fita.

## <a name="prerequisites"></a>Pré-requisitos

A [amostra De Rabiscar 1.0 MFC](https://download.microsoft.com/download/4/0/9/40946FEC-EE5C-48C2-8750-B0F8DA1C99A8/MFC/general/Scribble.zip.exe). Para obter ajuda na conversão para o Visual Studio 2017 ou posterior, consulte [Guia de Portação: MFC Scribble](../porting/porting-guide-mfc-scribble.md).

## <a name="sections"></a><a name="top"></a>Seções

Esta parte do passo a passo tem as seguintes seções:

- [Substituindo as Classes Base](#replaceclass)

- [Adicionando Bitmaps ao Projeto](#addbitmap)

- [Adicionando um recurso de fita ao projeto](#addribbon)

- [Criando uma instância da barra de fita](#createinstance)

- [Adicionando uma categoria de fita](#addcategory)

- [Definindo o visual do aplicativo](#setlook)

## <a name="replacing-the-base-classes"></a><a name="replaceclass"></a>Substituindo as Classes Base

Para converter um aplicativo que suporte um menu para um aplicativo que suporte uma fita, você deve derivar as classes de aplicativo, janela de quadro e barra de ferramentas de classes de base atualizadas. (Sugerimos que você não modifique a amostra original do Rabisco. Em vez disso, limpe o projeto Scribble, copie-o para outro diretório e, em seguida, modifique a cópia.)

### <a name="to-replace-the-base-classes-in-the-scribble-application"></a>Para substituir as classes de base no aplicativo Rabiscar

1. Em scribble.cpp, `CScribbleApp::InitInstance` verifique se inclui uma chamada para [AfxOleInit](../mfc/reference/ole-initialization.md#afxoleinit).

1. Adicione o seguinte código ao arquivo *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior):

    ```cpp
    #include <afxcontrolbars.h>
    ```

1. Em scribble.h, modifique `CScribbleApp` a definição para a classe para que ela seja derivada da [Classe CWinAppEx](../mfc/reference/cwinappex-class.md).

    ```cpp
    class CScribbleApp: public CWinAppEx
    ```

1. O Scribble 1.0 foi gravado quando os aplicativos do Windows usaram um arquivo de inicialização (.ini) para salvar dados de preferência do usuário. Em vez de um arquivo de inicialização, modifique o Scribble para armazenar as preferências do usuário no registro. Para definir a chave de registro e `CScribbleApp::InitInstance` a `LoadStdProfileSettings()` base, digite o seguinte código após a declaração.

    ```cpp
    SetRegistryKey(_T("MFCNext\\Samples\\Scribble2"));
    SetRegistryBase(_T("Settings"));
    ```

1. O quadro principal para um aplicativo de interface de documento `CMDIFrameWnd` múltiplo (MDI) não é mais derivado da classe. Em vez disso, é derivado da classe [CMDIFrameWndEx.](../mfc/reference/cmdiframewndex-class.md)

    Nos arquivos mainfrm.h e mainfrm.cpp, substitua todas as referências com `CMDIFrameWnd` `CMDIFrameWndEx`.

1. Nos arquivos childfrm.h e childfrm.cpp, substitua por `CMDIChildWnd` . `CMDIChildWndEx`

    No childfrm. arquivo h, `CSplitterWnd` `CSplitterWndEx`substituir por .

1. Modifique barras de ferramentas e barras de status para usar as novas classes De MFC.

    No arquivo mainfrm.h:

    1. Substitua `CToolBar` por `CMFCToolBar`.

    1. Substitua `CStatusBar` por `CMFCStatusBar`.

1. No arquivo mainfrm.cpp:

    1. Substitua `m_wndToolBar.SetBarStyle` por `m_wndToolBar.SetPaneStyle`

    1. Substitua `m_wndToolBar.GetBarStyle` por `m_wndToolBar.GetPaneStyle`

    1. Substitua `DockControlBar(&m_wndToolBar)` por `DockPane(&m_wndToolBar)`

1. No arquivo ipframe.cpp, comente as três linhas de código a seguir.

    ```cpp
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->DockPane(&m_wndToolBar);
    ```

1. Salve as alterações e, em seguida, construa e execute o aplicativo.

## <a name="adding-bitmaps-to-the-project"></a><a name="addbitmap"></a>Adicionando Bitmaps ao Projeto

Os próximos quatro passos deste passo a passo requerem recursos do bitmap. Você pode obter os bitmaps apropriados de várias maneiras:

- Use os [Editores de Recursos](../windows/resource-editors.md) para inventar seus próprios bitmaps. Ou use os editores de recursos para montar bitmaps a partir de imagens de gráficos de rede portáteis (.png) que estão incluídas no Visual Studio e podem ser baixadas da biblioteca de [imagens do Visual Studio](https://docs.microsoft.com/visualstudio/designers/the-visual-studio-image-library).

    No entanto, a interface de usuário **ribbon** requer que certos bitmaps suportem imagens transparentes. Os bitmaps transparentes usam pixels de 32 bits, onde 24 bits especificam os componentes vermelho, verde e azul da cor, e 8 bits definem um *canal alfa* que especifica a transparência da cor. Os editores de recursos atuais podem visualizar, mas não modificar bitmaps com pixels de 32 bits. Consequentemente, use um editor de imagens externo em vez dos editores de recursos para manipular bitmaps transparentes.

- Copie um arquivo de recurso apropriado de outro aplicativo para o seu projeto e, em seguida, importe bitmaps desse arquivo.

Este passo a passo copia arquivos de recursos do exemplo criado no [Passo a Passo: Criando um Aplicativo de Fita usando MFC](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).

### <a name="to-add-bitmaps-to-the-project"></a>Para adicionar bitmaps ao Projeto

1. Use o File Explorer para copiar os seguintes`res`arquivos .bmp do diretório de`res`recursos ( ) do exemplo Ribbon para o diretório de recursos ( ) do projeto Rabisco:

   1. Copie o main.bmp para o seu projeto Scribble.

   1. Copiar filesmall.bmp e filelarge.bmp para o seu projeto Scribble.

   1. Faça novas cópias dos arquivos filelarge.bmp e filesmall.bmp, mas salve as cópias no exemplo Ribbon. Renomeie as cópias homesmall.bmp e homelarge.bmp e, em seguida, mova as cópias para o seu projeto Scribble.

   1. Faça uma cópia do arquivo toolbar.bmp, mas salve a cópia no exemplo Ribbon. Renomeie os ícones do painel de cópia.bmp e, em seguida, mova a cópia para o projeto Scribble.

1. Importe o bitmap para um aplicativo MFC. Em **Resource View,** clique duas vezes no nó **scribble.rc,** clique duas vezes no nó **Bitmap** e clique em **Adicionar recurso**. Na caixa de diálogo que aparece, clique **em Importar**. Navegue `res` até o diretório, selecione o arquivo principal.bmp e clique em **Abrir**.

   O bitmap principal.bmp contém uma imagem 26x26. Alterar o ID do `IDB_RIBBON_MAIN`bitmap para .

1. Importe os bitmaps para o menu de arquivos anexado ao botão **Aplicativo.**

   1. Importe o arquivo filesmall.bmp, que contém onze imagens 16x16 (16x176). Alterar o ID do `IDB_RIBBON_FILESMALL`bitmap para .

   > [!NOTE]
   > Como precisamos apenas das primeiras oito imagens 16x16 (16x128), você pode, opcionalmente, cortar a largura do lado direito deste bitmap de 176 a 128.

   1. Importe o filelarge.bmp, que contém nove imagens 32x32 (32x288). Alterar o ID do `IDB_RIBBON_FILELARGE`bitmap para .

1. Importe os bitmaps para as categorias de fita e painéis. Cada guia na barra de fita é uma categoria, e consiste em um rótulo de texto e uma imagem opcional.

   1. Importe o bitmap homesmall.bmp, que contém onze imagens 16x16 para bitmaps de botões pequenos. Alterar o ID do `IDB_RIBBON_HOMESMALL`bitmap para .

   1. Importe o bitmap homelarge.bmp, que contém nove imagens 32x32 para bitmaps de botões grandes. Alterar o ID do `IDB_RIBBON_HOMELARGE`bitmap para .

1. Importar bitmaps para os painéis de fita redimensionados. Esses bitmaps, ou ícones de painel, são usados após uma operação de redimensionamento se a fita for muito pequena para exibir todo o painel.

   1. Importe o bitmap panelicons.bmp, que contém oito imagens 16x16. Na janela **Propriedades** do **Bitmap Editor,** ajuste a largura do bitmap para 64 (16x64). Alterar o ID do `IDB_PANEL_ICONS`bitmap para .

   > [!NOTE]
   > Como precisamos apenas das primeiras quatro imagens 16x16 (16x64), você pode, opcionalmente, cortar a largura do lado direito deste bitmap de 128 a 64.

## <a name="adding-a-ribbon-resource-to-the-project"></a><a name="addribbon"></a>Adicionando um recurso de fita ao projeto

Quando você converte um aplicativo que usa menus para um aplicativo que usa uma fita, você não precisa remover ou desativar os menus existentes. Basta criar um recurso de fita, adicionar botões de fita e, em seguida, associar os novos botões com os itens de menu existentes. Embora os menus não estejam mais visíveis, as mensagens da barra de fita são roteadas através dos menus e os atalhos do menu continuam funcionando.

Uma fita consiste no botão **Aplicativo,** que é o botão grande no lado superior esquerdo da fita, e uma ou mais guias de categoria. Cada guia de categoria contém um ou mais painéis que atuam como recipientes para botões e controles de fita. O procedimento a seguir mostra como criar um recurso de fita e, em seguida, personalizar o botão **Aplicativo.**

### <a name="to-add-a-ribbon-resource-to-the-project"></a>Para adicionar um recurso de fita ao projeto

1. Com o projeto Scribble selecionado no **Solution Explorer,** no menu **Projeto,** clique em **Adicionar recurso**.

1. Na caixa de diálogo **Adicionar recurso,** selecione **Fita** e clique em **Novo**.

   O Visual Studio cria um recurso de fita e o abre na exibição de design. O ID do `IDR_RIBBON1`recurso de fita é, que é exibido na **exibição de recursos**. A fita contém uma categoria e um painel.

1. Você pode personalizar o botão **Aplicativo** modificando suas propriedades. Os IDs de mensagem que são usados neste código já estão definidos no menu de Scribble 1.0.

1. Na exibição de design, clique no botão **Aplicativo** para exibir suas propriedades. Alterar os valores de `IDB_RIBBON_MAIN`propriedade da seguinte forma: **Imagem** para , `IDB_RIBBON_FILESMALL` **Prompt** to `File`, **Keys** to `f`, Large **Images** to `IDB_RIBBON_FILELARGE`, and Small **Images** to .

1. As modificações a seguir criam o menu que aparece quando o usuário clica no botão **Aplicativo.** Clique na elipse (**...**) ao lado **dos principais itens** para abrir o **Editor de Itens**.

   1. Com o **botão** **tipo item** selecionado, clique **em Adicionar** para adicionar um botão. Alterar **Caption** legenda `&New`para , `ID_FILE_NEW` **ID** para , `0` **Imagem** para `0`, Imagem **Grande** para .

   1. Clique **em Adicionar** para adicionar um botão. Alterar **Caption** legenda `&Save`para , `ID_FILE_SAVE` **ID** para , `2` **Imagem** para `2`, e Imagem **Grande** para .

   1. Clique **em Adicionar** para adicionar um botão. Alterar **Caption** legenda `Save &As`para , `ID_FILE_SAVE_AS` **ID** para , `3` **Imagem** para `3`, e Imagem **Grande** para .

   1. Clique **em Adicionar** para adicionar um botão. Alterar **Caption** legenda `&Print`para , `ID_FILE_PRINT` **ID** para , `4` **Imagem** para `4`, e Imagem **Grande** para .

   1. Alterar o **tipo de item** para **Separador** e, em seguida, clicar **em Adicionar**.

   1. Alterar o **tipo de item** para **botão**. Clique **em Adicionar** para adicionar um quinto botão. Alterar **Caption** legenda `&Close`para , `ID_FILE_CLOSE` **ID** para , `5` **Imagem** para `5`, e Imagem **Grande** para .

1. As seguintes modificações criam um submenu sob o botão **Imprimir** que você criou na etapa anterior.

   1. Clique no botão **Imprimir,** altere o tipo **de item** para **Rótulo**e clique **em Inserir**. Alterar **Caption** legenda `Preview and print the document`para .

   1. Clique no botão **Imprimir,** altere o tipo **de item** para **Botão**e clique **em Inserir**. Alterar **Caption** legenda `&Print`para , `ID_FILE_PRINT` **ID** para , `4` **Imagem** para `4`, e Imagem **Grande** para .

   1. Clique no botão **Imprimir** e clique **em Inserir** para adicionar um botão. Alterar **Caption** legenda `&Quick Print`para , `ID_FILE_PRINT_DIRECT` **ID** para , `7` **Imagem** para `7`, e Imagem **Grande** para .

   1. Clique no botão **Imprimir** e clique **em Inserir** para adicionar outro botão. Alterar **Caption** legenda `Print Pre&view`para , `ID_FILE_PRINT_PREVIEW` **ID** para , `6` **Imagem** para `6`, e Imagem **Grande** para .

   1. Você agora modificou os **itens principais.** Clique **em Fechar** para sair do Editor de **Itens**.

1. A modificação a seguir cria um botão de saída que aparece na parte inferior do menu do botão **Aplicativo.**

   1. Escolha a **guia Exibição de recursos** no Solution **Explorer**.
   1. Na janela **Propriedades,** clique na elipse (**...**) ao lado de **Button** para abrir o **Editor de Itens**.

   1. Com o **botão** **tipo item** selecionado, clique **em Adicionar** para adicionar um botão. Alterar **Caption** legenda `E&xit`para , `ID_APP_EXIT` **ID** para , **Imagem** para `8`.

   1. Você modificou os **botões.** Clique **em Fechar** para sair do Editor de **Itens**.

## <a name="creating-an-instance-of-the-ribbon-bar"></a><a name="createinstance"></a>Criando uma instância da barra de fita

As etapas a seguir mostram como criar uma instância da barra de fita quando a aplicação for iniciada. Para adicionar uma barra de fita a um aplicativo, declare a barra de fita no arquivo mainfrm.h. Em seguida, no arquivo mainfrm.cpp, escreva código para carregar o recurso de fita.

### <a name="to-create-an-instance-of-the-ribbon-bar"></a>Para criar uma instância da barra de fita

1. No arquivo mainfrm.h, adicione um membro de `CMainFrame`dados à seção protegida de , a definição de classe para o quadro principal. Este membro é para a barra de fita.

    ```cpp
    // Ribbon bar for the application
    CMFCRibbonBar m_wndRibbonBar;
    ```

2. No arquivo mainfrm.cpp, adicione o seguinte `return` código antes da `CMainFrame::OnCreate` declaração final no final da função. Ele cria uma instância da barra de fita.

    ```cpp
    // Create the ribbon bar
    if (!m_wndRibbonBar.Create(this))
    {
        return -1;   //Failed to create ribbon bar
    }
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);
    ```

## <a name="customizing-the-ribbon-resource"></a><a name="addcategory"></a>Personalização do recurso ribbon

Agora que você criou o botão **Aplicativo,** você pode adicionar elementos à fita.

> [!NOTE]
> Este passo a passo usa o mesmo ícone de painel para todos os painéis. No entanto, você pode usar outros índices de lista de imagens para exibir outros ícones.

### <a name="to-add-a-home-category-and-edit-panel"></a>Para adicionar uma categoria Home e painel Editar

1. O programa Scribble requer apenas uma categoria. Na exibição de design, na **Caixa de ferramentas**, clique duas vezes em **Categoria** para adicionar uma e exibir suas propriedades. Alterar os valores de `&Home`propriedade da `IDB_RIBBON_HOMELARGE`seguinte forma: **Legenda** para , **Imagens grandes** para , Pequenas **Imagens** para `IDB_RIBBON_HOMESMALL`.

1. Cada categoria de fita é organizada em painéis nomeados. Cada painel contém um conjunto de controles que completam operações relacionadas. Esta categoria tem um painel. Clique **em Painel**e, em seguida, **altere Legenda** para `Edit`.

1. Ao painel **Editar,** adicione um botão responsável pela limpeza do conteúdo do documento. O ID da mensagem para este `IDR_SCRIBBTYPE` botão já foi definido no recurso do menu. Especifique `Clear All` como o texto do botão e o índice do bitmap que decora o botão. Abra a **caixa de ferramentas**e arraste um **botão** para o painel **Editar.** Clique no botão e, `Clear All`em seguida, **altere Legenda** para `0`, **ID** para `ID_EDIT_CLEAR_ALL`, Índice de **imagem** para `0`, Índice de imagem **grande** para .

1. Salve as alterações e, em seguida, construa e execute o aplicativo. O aplicativo Scribble deve ser exibido, e deve ter uma barra de fita na parte superior da janela em vez de uma barra de menu. A barra de fita deve ter uma categoria, **Home**e **Home** deve ter um painel, **Editar**. Os botões de fita adicionados devem ser associados aos manipuladores de eventos existentes e os botões **Open**, **Close**, **Save,** **Print**e **Clear All** devem funcionar conforme o esperado.

## <a name="setting-the-look-of-the-application"></a><a name="setlook"></a>Definindo o visual do aplicativo

Um *gerenciador visual* é um objeto global que controla todos os desenhos para um aplicativo. Como o aplicativo Scribble original usa o estilo interface de usuário Office 2000 (UI), o aplicativo pode parecer antiquado. Você pode redefinir o aplicativo para usar o gerenciador visual do Office 2007 para que ele se assemelhe a um aplicativo do Office 2007.

### <a name="to-set-the-look-of-the-application"></a>Para definir o visual do aplicativo

1. Na `CMainFrame::OnCreate` função, digite o `return 0;` seguinte código antes da declaração para alterar o gerenciador visual padrão e o estilo.

    ```cpp
    // Set the default manager to Office 2007
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
    ```

1. Salve as alterações e, em seguida, construa e execute o aplicativo. A interface do motorista deve se assemelhar à interface do escritório 2007.

## <a name="next-steps"></a>Próximas etapas

Você modificou a clássica amostra de Scribble 1.0 MFC para usar o **Ribbon Designer**. Agora vá para a [Parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md).

## <a name="see-also"></a>Confira também

[Passo a passo](../mfc/walkthroughs-mfc.md)<br/>
[Instruções passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md)
