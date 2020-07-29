---
title: 'Walkthrough: atualizando o aplicativo de rabisco do MFC (parte 1)'
ms.date: 09/09/2019
helpviewer_keywords:
- examples [MFC], update existing application
- ribbon UI, porting to
- Office Fluent UI, porting to
- samples [MFC], update existing application
- MFC Feature Pack, update existing application
- walkthroughs [MFC], update existing application
ms.assetid: aa6330d3-6cfc-4c79-8fcb-0282263025f7
ms.openlocfilehash: 9fc2903180a055c18c6f3779b1da55ee347d2535
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230422"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-1"></a>Walkthrough: atualizando o aplicativo de rabisco do MFC (parte 1)

Este tutorial demonstra como modificar um aplicativo MFC existente para usar a interface do usuário da faixa de faixas. O Visual Studio dá suporte à faixa de opções Office 2007 e à faixa de opções deslumbrante do Windows 7. Para obter mais informações sobre a interface do usuário da faixa de faixas, consulte [Ribbons](/windows/win32/uxguide/cmd-ribbons).

Este passo a passos modifica o exemplo do MFC de rabisco 1,0 do Classic que permite usar o mouse para criar desenhos de linha. Esta parte do guia de explicação mostra como modificar o exemplo de rabisco para que ele exiba uma barra de faixa de uma. A [parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md) adiciona mais botões à barra da faixa de faixas.

## <a name="prerequisites"></a>Pré-requisitos

O [exemplo do MFC do rabisco 1,0](https://download.microsoft.com/download/4/0/9/40946FEC-EE5C-48C2-8750-B0F8DA1C99A8/MFC/general/Scribble.zip.exe). Para obter ajuda sobre como converter para o Visual Studio 2017 ou posterior, consulte [Guia de portabilidade: rabisco do MFC](../porting/porting-guide-mfc-scribble.md).

## <a name="sections"></a><a name="top"></a>As

Esta parte do passo a passos tem as seguintes seções:

- [Substituindo as classes base](#replaceclass)

- [Adicionando bitmaps ao projeto](#addbitmap)

- [Adicionando um recurso de faixa de uma ao projeto](#addribbon)

- [Criando uma instância da barra da faixa de faixas](#createinstance)

- [Adicionando uma categoria da faixa de faixas](#addcategory)

- [Configurando a aparência do aplicativo](#setlook)

## <a name="replacing-the-base-classes"></a><a name="replaceclass"></a>Substituindo as classes base

Para converter um aplicativo que dá suporte a um menu para um aplicativo que dá suporte a uma faixa de ferramentas, você deve derivar as classes de aplicativo, janela de quadro e barra de barras de classes base atualizadas. (Sugerimos que você não modifique o exemplo de rabisco original. Em vez disso, limpe o projeto de rabisco, copie-o para outro diretório e, em seguida, modifique a cópia.)

### <a name="to-replace-the-base-classes-in-the-scribble-application"></a>Para substituir as classes base no aplicativo rabiscar

1. Em rabisco. cpp, verifique se `CScribbleApp::InitInstance` o inclui uma chamada para [AfxOleInit](../mfc/reference/ole-initialization.md#afxoleinit).

1. Adicione o código a seguir ao arquivo *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior):

    ```cpp
    #include <afxcontrolbars.h>
    ```

1. Em rabisco. h, modifique a definição da `CScribbleApp` classe para que ela seja derivada da [classe CWinAppEx](../mfc/reference/cwinappex-class.md).

    ```cpp
    class CScribbleApp: public CWinAppEx
    ```

1. O rabisco 1,0 foi escrito quando os aplicativos do Windows usavam um arquivo de inicialização (. ini) para salvar os dados de preferência do usuário. Em vez de um arquivo de inicialização, modifique rabisco para armazenar as preferências do usuário no registro. Para definir a chave e a base do registro, digite o seguinte código em `CScribbleApp::InitInstance` após a `LoadStdProfileSettings()` instrução.

    ```cpp
    SetRegistryKey(_T("MFCNext\\Samples\\Scribble2"));
    SetRegistryBase(_T("Settings"));
    ```

1. O quadro principal para um aplicativo de interface de vários documentos (MDI) não é mais derivado da `CMDIFrameWnd` classe. Em vez disso, ele é derivado da classe [CMDIFrameWndEx](../mfc/reference/cmdiframewndex-class.md) .

    Nos arquivos mainfrm. h e mainfrm. cpp, substitua todas as referências a `CMDIFrameWnd` por `CMDIFrameWndEx` .

1. Nos arquivos childfrm. h e childfrm. cpp, substitua `CMDIChildWnd` por `CMDIChildWndEx` .

    No childfrm. arquivo h, substitua `CSplitterWnd` por `CSplitterWndEx` .

1. Modifique barras de ferramentas e barras de status para usar as novas classes do MFC.

    No arquivo MainFrm. h:

    1. Substitua `CToolBar` por `CMFCToolBar`.

    1. Substitua `CStatusBar` por `CMFCStatusBar`.

1. No arquivo MainFrm. cpp:

    1. Substitua `m_wndToolBar.SetBarStyle` por `m_wndToolBar.SetPaneStyle`

    1. Substitua `m_wndToolBar.GetBarStyle` por `m_wndToolBar.GetPaneStyle`

    1. Substitua `DockControlBar(&m_wndToolBar)` por `DockPane(&m_wndToolBar)`

1. No arquivo ipframe. cpp, comente as três linhas de código a seguir.

    ```cpp
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->DockPane(&m_wndToolBar);
    ```

1. Salve as alterações e, em seguida, compile e execute o aplicativo.

## <a name="adding-bitmaps-to-the-project"></a><a name="addbitmap"></a>Adicionando bitmaps ao projeto

As próximas quatro etapas deste passo a passos exigem recursos de bitmap. Você pode obter os bitmaps apropriados de várias maneiras:

- Use os [editores de recursos](../windows/resource-editors.md) para inventar seus próprios bitmaps. Ou use os editores de recursos para montar bitmaps das imagens do Portable Network Graphics (. png) que estão incluídas com o Visual Studio e que podem ser baixadas na [biblioteca de imagens do Visual Studio](https://docs.microsoft.com/visualstudio/designers/the-visual-studio-image-library).

    No entanto, a interface do usuário da **faixa de faixas** requer que determinados bitmaps suportem imagens transparentes. Os bitmaps transparentes usam pixels de 32 bits, em que 24 bits especificam os componentes vermelho, verde e azul da cor, e 8 bits definem um *canal alfa* que especifica a transparência da cor. Os editores de recursos atuais podem exibir, mas não modificar bitmaps com pixels de 32 bits. Consequentemente, use um editor de imagem externa em vez dos editores de recursos para manipular bitmaps transparentes.

- Copie um arquivo de recurso apropriado de outro aplicativo para o seu projeto e importe os bitmaps desse arquivo.

Este passo a passos copia arquivos de recursos do exemplo criado em [passo a passos: Criando um aplicativo de faixa de faixas usando MFC](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).

### <a name="to-add-bitmaps-to-the-project"></a>Para adicionar bitmaps ao projeto

1. Use o explorador de arquivos para copiar os seguintes arquivos. bmp do diretório de recursos ( `res` ) do exemplo da faixa de opções para o diretório de recursos ( `res` ) do projeto de rabisco:

   1. Copie main.bmp para seu projeto de rabisco.

   1. Copie filesmall.bmp e filelarge.bmp para seu projeto de rabisco.

   1. Faça novas cópias dos arquivos de filelarge.bmp e filesmall.bmp, mas salve as cópias no exemplo da faixa de forma. Renomeie as cópias homesmall.bmp e homelarge.bmp e, em seguida, mova as cópias para o seu projeto de rabisco.

   1. Faça uma cópia do arquivo de toolbar.bmp, mas salve a cópia no exemplo da faixa de medida. Renomeie a cópia panelicons.bmp e, em seguida, mova a cópia para o seu projeto de rabisco.

1. Importe o bitmap para um aplicativo MFC. Em **modo de exibição de recursos**, clique duas vezes no nó **rabisco. rc** , clique duas vezes no nó do **bitmap** e, em seguida, clique em **Adicionar recurso**. Na caixa de diálogo que aparece, clique em **importar**. Navegue até o `res` diretório, selecione o arquivo de main.bmp e, em seguida, clique em **abrir**.

   O bitmap main.bmp contém uma imagem 26x26. Altere a ID do bitmap para `IDB_RIBBON_MAIN` .

1. Importe os bitmaps para o menu de arquivo que está anexado ao botão do **aplicativo** .

   1. Importe o arquivo de filesmall.bmp, que contém onze imagens de 16x16 (16x176). Altere a ID do bitmap para `IDB_RIBBON_FILESMALL` .

   > [!NOTE]
   > Como precisamos apenas das oito primeiras imagens 16x16 (16x128), você pode, opcionalmente, cortar a largura do lado direito desse bitmap de 176 para 128.

   1. Importe o filelarge.bmp, que contém nove 32x32 (32x288) imagens. Altere a ID do bitmap para `IDB_RIBBON_FILELARGE` .

1. Importe os bitmaps para as categorias e painéis da faixa de mapa. Cada guia na barra de faixa de faixas é uma categoria e consiste em um rótulo de texto e uma imagem opcional.

   1. Importe o bitmap homesmall.bmp, que contém onze imagens de 16x16 para pequenos bitmaps de botão. Altere a ID do bitmap para `IDB_RIBBON_HOMESMALL` .

   1. Importe o bitmap de homelarge.bmp, que contém as imagens de nove 32x32 para bitmaps de botão grande. Altere a ID do bitmap para `IDB_RIBBON_HOMELARGE` .

1. Importe bitmaps para os painéis de faixa de faixas redimensionados. Esses bitmaps ou ícones de painel serão usados após uma operação de redimensionamento se a faixa de faixas for muito pequena para exibir o painel inteiro.

   1. Importe o bitmap panelicons.bmp, que contém oito imagens 16x16. Na janela **Propriedades** do editor de **bitmap**, ajuste a largura do bitmap para 64 (16X64). Altere a ID do bitmap para `IDB_PANEL_ICONS` .

   > [!NOTE]
   > Como precisamos apenas das primeiras quatro imagens de 16x16 (16X64), você pode, opcionalmente, cortar a largura do lado direito desse bitmap de 128 para 64.

## <a name="adding-a-ribbon-resource-to-the-project"></a><a name="addribbon"></a>Adicionando um recurso de faixa de uma ao projeto

Quando você converte um aplicativo que usa menus para um aplicativo que usa uma faixa de faixas, não é necessário remover ou desabilitar os menus existentes. Basta criar um recurso da faixa de forma, adicionar botões da faixa de medida e associar os novos botões aos itens de menu existentes. Embora os menus não fiquem mais visíveis, as mensagens da barra da faixa de faixas são roteadas pelos menus e atalhos de menu continuam funcionando.

Uma faixa consiste no botão do **aplicativo** , que é o botão grande no lado superior esquerdo da faixa de bits e uma ou mais guias de categoria. Cada guia de categoria contém um ou mais painéis que atuam como contêineres para botões e controles da faixa de e. O procedimento a seguir mostra como criar um recurso da faixa de opções e, em seguida, personalizar o botão do **aplicativo** .

### <a name="to-add-a-ribbon-resource-to-the-project"></a>Para adicionar um recurso da faixa de faixas ao projeto

1. Com o projeto de rabisco selecionado em **Gerenciador de soluções**, no menu **projeto** , clique em **Adicionar recurso**.

1. Na caixa de diálogo **Adicionar recurso** , selecione **faixa** de opções e clique em **novo**.

   O Visual Studio cria um recurso de faixa de e abre-o no modo de exibição de design. A ID de recurso da faixa de medida é `IDR_RIBBON1` , que é exibida em **modo de exibição de recursos**. A faixa de faixas contém uma categoria e um painel.

1. Você pode personalizar o botão do **aplicativo** modificando suas propriedades. As IDs de mensagem que são usadas neste código já estão definidas no menu para o rabisco 1,0.

1. Na exibição Design, clique no botão **aplicativo** para exibir suas propriedades. Altere os valores de propriedade da seguinte maneira: **imagem** para `IDB_RIBBON_MAIN` , **solicitar** `File` , **chaves** para `f` , **imagens grandes** `IDB_RIBBON_FILELARGE` e **imagens pequenas** para `IDB_RIBBON_FILESMALL` .

1. As modificações a seguir criam o menu que aparece quando o usuário clica no botão do **aplicativo** . Clique nas reticências (**...**) ao lado de **itens principais** para abrir o **Editor de itens**.

   1. Com o **botão** tipo de **Item** selecionado, clique em **Adicionar** para adicionar um botão. Altere a **legenda** para `&New` , **ID** para, `ID_FILE_NEW` **imagem** para `0` , **imagem grande** para `0` .

   1. Clique em **Adicionar** para adicionar um botão. Altere a **legenda** para `&Save` , **ID** para, `ID_FILE_SAVE` **imagem** para `2` e **imagem grande** para `2` .

   1. Clique em **Adicionar** para adicionar um botão. Altere a **legenda** para `Save &As` , **ID** para, `ID_FILE_SAVE_AS` **imagem** para `3` e **imagem grande** para `3` .

   1. Clique em **Adicionar** para adicionar um botão. Altere a **legenda** para `&Print` , **ID** para, `ID_FILE_PRINT` **imagem** para `4` e **imagem grande** para `4` .

   1. Altere o tipo de **Item** para **separador** e clique em **Adicionar**.

   1. Altere o tipo de **Item** para **botão**. Clique em **Adicionar** para adicionar um quinto botão. Altere a **legenda** para `&Close` , **ID** para, `ID_FILE_CLOSE` **imagem** para `5` e **imagem grande** para `5` .

1. As modificações a seguir criam um submenu sob o botão **Imprimir** que você criou na etapa anterior.

   1. Clique no botão **Imprimir** , altere o tipo de **Item** para **rótulo**e, em seguida, clique em **Inserir**. Altere a **legenda** para `Preview and print the document` .

   1. Clique no botão **Imprimir** , altere o tipo de **Item** para **botão**e clique em **Inserir**. Altere a **legenda** para `&Print` , **ID** para, `ID_FILE_PRINT` **imagem** para `4` e **imagem grande** para `4` .

   1. Clique no botão **Imprimir** e, em seguida, clique em **Inserir** para adicionar um botão. Altere a **legenda** para `&Quick Print` , **ID** para, `ID_FILE_PRINT_DIRECT` **imagem** para `7` e **imagem grande** para `7` .

   1. Clique no botão **Imprimir** e, em seguida, clique em **Inserir** para adicionar outro botão. Altere a **legenda** para `Print Pre&view` , **ID** para, `ID_FILE_PRINT_PREVIEW` **imagem** para `6` e **imagem grande** para `6` .

   1. Agora você modificou os **itens principais**. Clique em **fechar** para sair do **Editor de itens**.

1. A modificação a seguir cria um botão sair que aparece na parte inferior do menu do botão do **aplicativo** .

   1. Escolha a guia **modo de exibição de recursos** em **Gerenciador de soluções**.
   1. Na janela **Propriedades** , clique nas reticências (**...**) ao lado do **botão** para abrir o **Editor de itens**.

   1. Com o **botão** tipo de **Item** selecionado, clique em **Adicionar** para adicionar um botão. Altere a **legenda** para `E&xit` , **ID** para `ID_APP_EXIT` , **imagem** para `8` .

   1. Você modificou os **botões**. Clique em **fechar** para sair do **Editor de itens**.

## <a name="creating-an-instance-of-the-ribbon-bar"></a><a name="createinstance"></a>Criando uma instância da barra da faixa de faixas

As etapas a seguir mostram como criar uma instância da barra da faixa de opções quando seu aplicativo é iniciado. Para adicionar uma barra de faixa de faixas a um aplicativo, declare a barra da faixa de faixas no arquivo MainFrm. h. Em seguida, no arquivo MainFrm. cpp, escreva o código para carregar o recurso da faixa de faixas.

### <a name="to-create-an-instance-of-the-ribbon-bar"></a>Para criar uma instância da barra da faixa de faixas

1. No arquivo MainFrm. h, adicione um membro de dados à seção protegida de `CMainFrame` , a definição de classe do quadro principal. Este membro é para a barra da faixa de faixas.

    ```cpp
    // Ribbon bar for the application
    CMFCRibbonBar m_wndRibbonBar;
    ```

2. No arquivo MainFrm. cpp, adicione o código a seguir antes da **`return`** instrução final no final da `CMainFrame::OnCreate` função. Ele cria uma instância da barra da faixa de faixas.

    ```cpp
    // Create the ribbon bar
    if (!m_wndRibbonBar.Create(this))
    {
        return -1;   //Failed to create ribbon bar
    }
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);
    ```

## <a name="customizing-the-ribbon-resource"></a><a name="addcategory"></a>Personalizando o recurso da faixa de faixas

Agora que você criou o botão **aplicativo** , é possível adicionar elementos à faixa de faixas.

> [!NOTE]
> Este tutorial usa o mesmo ícone de painel para todos os painéis. No entanto, você pode usar outros índices de lista de imagens para exibir outros ícones.

### <a name="to-add-a-home-category-and-edit-panel"></a>Para adicionar uma categoria inicial e um painel de edição

1. O programa de rabisco requer apenas uma categoria. Na exibição Design, na caixa de **ferramentas**, clique duas vezes em **categoria** para adicionar uma e exibir suas propriedades. Altere os valores de propriedade da seguinte maneira: **legenda** para `&Home` , **imagens grandes** para `IDB_RIBBON_HOMELARGE` , **imagens pequenas** para `IDB_RIBBON_HOMESMALL` .

1. Cada categoria da faixa de faixas é organizada em painéis nomeados. Cada painel contém um conjunto de controles que concluem as operações relacionadas. Esta categoria tem um painel. Clique em **painel**e, em seguida, altere a **legenda** para `Edit` .

1. Para o painel de **edição** , adicione um botão responsável por limpar o conteúdo do documento. A ID da mensagem para este botão já foi definida no `IDR_SCRIBBTYPE` recurso de menu. Especifique `Clear All` como o texto do botão e o índice do bitmap que decora o botão. Abra a **caixa de ferramentas**e arraste um **botão** para o painel **Editar** . Clique no botão e altere a **legenda** para `Clear All` , **ID** para `ID_EDIT_CLEAR_ALL` , **índice de imagem** para `0` , índice de **imagem grande** para `0` .

1. Salve as alterações e, em seguida, compile e execute o aplicativo. O aplicativo de rabisco deve ser exibido e deve ter uma barra de faixa de faixas na parte superior da janela, em vez de uma barra de menus. A barra da faixa de faixas deve ter uma categoria, **página inicial**e **casa** deve ter um painel, **Editar**. Os botões da faixa de faixas que você adicionou devem ser associados aos manipuladores de eventos existentes e os botões **abrir**, **fechar**, **salvar**, **Imprimir**e **limpar todos** devem funcionar conforme o esperado.

## <a name="setting-the-look-of-the-application"></a><a name="setlook"></a>Configurando a aparência do aplicativo

Um *Gerenciador visual* é um objeto global que controla todo o desenho de um aplicativo. Como o aplicativo Rabisco original usa o estilo de interface do usuário do Office 2000, o aplicativo pode parecer antigo. Você pode redefinir o aplicativo para usar o Gerenciador visual do Office 2007 para que seja semelhante a um aplicativo do Office 2007.

### <a name="to-set-the-look-of-the-application"></a>Para definir a aparência do aplicativo

1. Na `CMainFrame::OnCreate` função, digite o código a seguir antes da `return 0;` instrução para alterar o Gerenciador visual e o estilo padrão.

    ```cpp
    // Set the default manager to Office 2007
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
    ```

1. Salve as alterações e, em seguida, compile e execute o aplicativo. A interface do usuário do aplicativo deve ser semelhante à interface do usuário do Office 2007.

## <a name="next-steps"></a>Próximas etapas

Você modificou o exemplo do MFC do Rabisco 1,0 do Classic para usar o **Designer de faixa de faixas**. Agora, vá para a [parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md).

## <a name="see-also"></a>Confira também

[Passo a passo](../mfc/walkthroughs-mfc.md)<br/>
[Walkthrough: atualizando o aplicativo de rabisco do MFC (parte 2)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md)
