---
title: 'Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 1) | Microsoft Docs'
ms.custom: ''
ms.date: 06/28/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- examples [MFC], update existing application
- ribbon UI, porting to
- Office Fluent UI, porting to
- samples [MFC], update existing application
- MFC Feature Pack, update existing application
- walkthroughs [MFC], update existing application
ms.assetid: aa6330d3-6cfc-4c79-8fcb-0282263025f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 916c6ccbdaa9512f1ee0a23a59b866678005180a
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122847"
---
# <a name="walkthrough-updating-the-mfc-scribble-application-part-1"></a>Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 1)

Este passo a passo demonstra como modificar um aplicativo MFC existente para usar a interface do usuário da faixa de opções. Visual Studio oferece suporte a faixa de opções do Office 2007 e Windows 7 clip faixa de opções. Para obter mais informações sobre a interface do usuário da faixa de opções, consulte [faixas de opções](http://go.microsoft.com/fwlink/p/?linkid=129233) no site do MSDN.

Este passo a passo modifica o exemplo clássico de rabisco MFC de 1.0 que permite que você use o mouse para criar desenhos de linha. Esta parte do passo a passo mostra como modificar o exemplo de rabisco para que ele exibe uma barra de faixa de opções. [Parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md) adiciona mais botões de barra de faixa de opções.

## <a name="prerequisites"></a>Pré-requisitos

[Exemplos do Visual C++](../visual-cpp-samples.md)

[Exemplos do Visual C++](../visual-cpp-samples.md)

##  <a name="top"></a> Seções

Esta parte do passo a passo tem as seguintes seções:

- [Substituindo as Classes Base](#replaceclass)

- [Adicionando Bitmaps para o projeto](#addbitmap)

- [Adicionar um recurso de faixa de opções ao projeto](#addribbon)

- [Criar uma instância da barra de faixa de opções](#createinstance)

- [Adicionando uma categoria de faixa de opções](#addcategory)

- [Definir a aparência do aplicativo](#setlook)

##  <a name="replaceclass"></a> Substituindo as Classes Base

Para converter um aplicativo que oferece suporte a um menu para um aplicativo que oferece suporte a uma faixa de opções, o aplicativo, a janela do quadro e a classes da barra de ferramentas deve ser derivado de classes base atualizados. (Recomendamos que você não modificar o exemplo de rabisco original; em vez disso, limpe o projeto rabisco, copiá-lo para outro diretório e, em seguida, modifique a cópia.)

### <a name="to-replace-the-base-classes-in-the-scribble-application"></a>Para substituir as classes base do aplicativo de rabisco

1. No scribble.cpp, verifique `CScribbleApp::InitInstance` inclui uma chamada para [AfxOleInit](../mfc/reference/ole-initialization.md#afxoleinit).

2. Adicione o seguinte código ao arquivo Stdafx. h.

    ```cpp
    #include <afxcontrolbars.h>
    ```

3. Em scribble.h, modifique a definição para o `CScribbleApp` de classe para que ele é derivado do [CWinAppEx classe](../mfc/reference/cwinappex-class.md).

    ```cpp
    class CScribbleApp: public CWinAppEx
    ```

4. Rabisco 1.0 foi gravado quando aplicativos do Windows usado um arquivo de inicialização (. ini) para salvar os dados de preferência do usuário. Em vez de um arquivo de inicialização, modificar Rabisco para armazenar as preferências do usuário no registro. Para definir a chave do registro e a base, digite o seguinte código em `CScribbleApp::InitInstance` depois que o `LoadStdProfileSettings()` instrução.

    ```cpp
    SetRegistryKey(_T("MFCNext\\Samples\\Scribble2"));
    SetRegistryBase(_T("Settings"));
    ```

5. O quadro principal para um aplicativo de interface MDI vários documentos não deriva de `CMDIFrameWnd` classe. Em vez disso, ele é derivado de [CMDIFrameWndEx](../mfc/reference/cmdiframewndex-class.md) classe.

     Nos arquivos mainfrm.h e mainfrm.cpp, substitua todas as referências a `CMDIFrameWnd` com `CMDIFrameWndEx`.

6. Substitua os arquivos childfrm.h e childfrm.cpp, `CMDIChildWnd` com `CMDIChildWndEx`.

     Em childfrm. arquivo h, substitua `CSplitterWnd` com `CSplitterWndEx`.

7. Modificar as barras de ferramentas e barras de status para usar as novas classes do MFC.

     No arquivo mainfrm.h:

    1. Substitua `CToolBar` por `CMFCToolBar`.

    2. Substitua `CStatusBar` por `CMFCStatusBar`.

8. No arquivo mainfrm.cpp:

    1. Substituir `m_wndToolBar.SetBarStyle` com `m_wndToolBar.SetPaneStyle`

    2. Substituir `m_wndToolBar.GetBarStyle` com `m_wndToolBar.GetPaneStyle`

    3. Substituir `DockControlBar(&m_wndToolBar)` com `DockPane(&m_wndToolBar)`

9. No arquivo ipframe.cpp, comente as três linhas de código a seguir.

    ```cpp
    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->EnableDocking(CBRS_ALIGN_ANY);
    pWndFrame->DockPane(&m_wndToolBar);
    ```

10. Se você pretende vincule estaticamente o seu aplicativo, adicione o seguinte código ao início do arquivo de recurso (. rc) do projeto.

    ```cpp
    #include "afxribbon.rc"
    ```

     O arquivo afxribbon.rc contém recursos que são necessários em tempo de execução. O [Assistente de aplicativo MFC](../mfc/reference/mfc-application-wizard.md) inclui esse arquivo automaticamente quando você cria um aplicativo.

11. Salvar as alterações e, em seguida, compilar e executar o aplicativo.

[[Seções](#top)]

##  <a name="addbitmap"></a> Adicionando Bitmaps para o projeto

As quatro etapas deste passo a passo exigem recursos do bitmap. Você pode obter bitmaps apropriado de várias maneiras:

- Use o [editores de recursos](../windows/resource-editors.md) para seus próprios bitmaps de estoque. Ou use os editores de recursos para montar os bitmaps de imagens PNG rede portátil incluídas com [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]. Essas imagens são no `VS2008ImageLibrary` directory.

     No entanto, a interface do usuário da faixa de opções requer que certas bitmaps suporte imagens transparentes. Bitmaps transparentes usar pixels de 32 bits, em que 24 bits especifique os componentes vermelhos, verdes e azuis da cor e defina os 8 bits um *canal alfa* que especifica a transparência da cor. Os editores de recursos atual podem exibir, mas não modificar bitmaps com pixels de 32 bits. Consequentemente, use um editor de imagem externa em vez dos editores de recursos para manipular bitmaps transparentes.

- Copiar um arquivo de recurso apropriado de outro aplicativo para seu projeto e, em seguida, importe bitmaps desse arquivo.

Este passo a passo copia arquivos de recursos de um aplicativo no diretório de exemplos.

### <a name="to-add-bitmaps-to-the-project"></a>Para adicionar bitmaps ao projeto

1. Use o Explorador de arquivos para copiar os seguintes arquivos. bmp do diretório de recursos (`res`) do exemplo RibbonGadgets:

   1. Copie o main.bmp ao seu projeto de rabisco.

   2. Copiar filesmall.bmp e filelarge.bmp ao seu projeto de rabisco.

   3. Fazer novas cópias dos arquivos filelarge.bmp e filesmall.bmp, mas salvar as cópias no exemplo RibbonGadgets. Renomeie a cópias homesmall.bmp e homelarge.bmp e mova as cópias ao seu projeto de rabisco.

   4. Faça uma cópia do arquivo toolbar.bmp, mas salvar a cópia no exemplo RibbonGadgets. Renomeie a cópia panelicons.bmp e, em seguida, transferir a cópia para o seu projeto de rabisco.

2. Importe o bitmap para um aplicativo do MFC. Em **exibição recursos**, clique duas vezes o **scribble.rc** nó, clique duas vezes no **Bitmap** nó e, em seguida, clique **adicionar recurso**. Na caixa de diálogo que aparece, clique em **importação**. Navegue até o `res` diretório, selecione o arquivo main.bmp e, em seguida, clique em **abrir**.

   O bitmap main.bmp contém uma imagem de 26 x 26. Altere a identificação do bitmap para IDB_RIBBON_MAIN.

3. Importe os bitmaps do menu arquivo que é anexado ao botão de aplicativo.

   1. Importar o arquivo filesmall.bmp, que contém 16 x 16 (16 x 160) dez imagens. Como precisamos apenas oito 16x16 imagens (16 x 128), use o **exibição recursos** para alterar a largura do que o bitmap de 160 para 128. Altere a identificação do bitmap para IDB_RIBBON_FILESMALL.

   2. Importar filelarge.bmp, que contém oito 32 x 32 (32 x 256) imagens. Altere a identificação do bitmap para IDB_RIBBON_FILELARGE.

4. Importe os bitmaps para as categorias de faixa de opções e painéis. Cada guia na barra de faixa de opções é uma categoria e consiste em um rótulo de texto e uma imagem opcional.

   1. Importe o bitmap homesmall.bmp, que contém oito 16 x 16 imagens para os bitmaps de botão pequeno. Altere a identificação do bitmap para IDB_RIBBON_HOMESMALL.

   2. Importe o bitmap homelarge.bmp, que contém oito 32 x 32 imagens para os bitmaps de botão grande. Altere a identificação do bitmap para IDB_RIBBON_HOMELARGE.

5. Importar bitmaps para os painéis de faixa de opções redimensionado. Esses bitmaps ou ícones do painel, são usados após uma operação de redimensionamento se a faixa de opções é muito pequena para exibir o painel inteiro.

   1. Importe o bitmap panelicons.bmp, que contém oito 16 x 16 imagens. No **propriedades** janela do **Editor de Bitmap**, ajuste a largura do bitmap para 64 (16 x 64). Altere a identificação do bitmap para IDB_PANEL_ICONS.

[[Seções](#top)]

##  <a name="addribbon"></a> Adicionar um recurso de faixa de opções ao projeto

Quando você converte um aplicativo que usa um aplicativo que usa uma faixa de opções de menus, você não precisa remover ou desabilitar os menus existentes. Em vez disso, crie um recurso de faixa de opções, adicionar botões de faixa de opções e, em seguida, associar os novos botões com os itens de menu existente. Embora os menus não estiverem visíveis, as mensagens da barra de faixa de opções são roteadas através de menus. Além disso, os atalhos do menu continuam a trabalhar.

Uma faixa de opções consiste no botão do aplicativo, que é o botão grande no lado superior esquerdo da faixa de opções, e uma ou mais guias de categoria. Cada guia categoria contém um ou mais painéis que atuam como contêineres para controles e botões da faixa de opções. O procedimento a seguir mostra como criar um recurso de faixa de opções e, em seguida, personalizar o botão do aplicativo.

### <a name="to-add-a-ribbon-resource-to-the-project"></a>Para adicionar um recurso de faixa de opções ao projeto

1. Sobre o **projeto** menu, clique em **adicionar recurso**.

2. No **adicionar recurso** caixa de diálogo, selecione **faixa de opções** e, em seguida, clique em **novo**.

   Visual Studio cria um recurso de faixa de opções e abre-o no modo de exibição de design. A ID de recurso da faixa de opções é IDR_RIBBON1, que é exibido em **exibição recursos**. A faixa de opções contém uma categoria e um painel.

3. Você pode personalizar o botão do aplicativo por meio de modificação de suas propriedades. As IDs de mensagem que são usadas neste código já estão definidas no menu para Rabisco 1.0.

4. No modo design, clique no botão de aplicativo para exibir suas propriedades. Alterar valores de propriedade da seguinte maneira: **imagem** para `IDB_RIBBON_MAIN`, **Prompt** para `File`, **chaves** para `f`, **imagens grandes** para `IDB_RIBBON_FILELARGE`, e **imagens pequenas** para `IDB_RIBBON_FILESMALL`.

5. As modificações a seguir criar um menu que aparece quando o usuário clica no botão do aplicativo. Clique no botão de reticências (**...** ) ao lado de **principal itens** para abrir o **itens Editor**.

   1. Clique em **adicionar** para adicionar um botão. Alterar **legenda** para `&New`, **ID** para `ID_FILE_NEW`, **imagem** para `0`, **imagem grande** para `0`.

   2. Clique em **adicionar** para adicionar um segundo botão. Alterar **legenda** para `&Save`, **ID** para `ID_FILE_SAVE`, **imagem** para `2`, e **imagem grande** para `2`.

   3. Clique em **adicionar** para adicionar um botão de terceiro. Alterar **legenda** para `Save &As`, **ID** para `ID_FILE_SAVE_AS`, **imagem** para `3`, e **imagem grande** para `3`.

   4. Clique em **adicionar** para adicionar um quarto botão. Alterar **legenda** para `&Print`, **ID** para `ID_FILE_PRINT`, **imagem** para `4`, e **imagem grande** para `4`.

   5. Alterar o **Item** tipo **separador** e, em seguida, clique em **adicionar**.

   6. Alterar o **Item** tipo **botão**. Clique em **adicionar** para adicionar um quinto botão. Alterar **legenda** para `&Close`, **ID** para `ID_FILE_CLOSE`, **imagem** para `5`, e **imagem grande** para `5`.

6. As modificações a seguir cria um submenu sob o botão de impressão que você criou na etapa anterior.

   1. Clique o **impressão** botão, altere o **Item** tipo **rótulo**e, em seguida, clique em **inserir**. Alterar **legenda** para `Preview and print the document`.

   2. Clique o **impressão** botão, altere o **Item** tipo **botão**e clique em **inserir**. Alterar **legenda** para `&Print`, **ID** para `ID_FILE_PRINT`, **imagem** para `4`, e **imagem grande** para `4`.

   3. Clique o **impressão** botão e, em seguida, clique em **inserir** para adicionar um botão. Alterar **legenda** para `&Quick Print`, **ID** para `ID_FILE_PRINT_DIRECT`, **imagem** para `7`, e **imagem grande** para `7`.

   4. Clique o **impressão** botão e, em seguida, clique em **inserir** para adicionar outro botão. Alterar **legenda** para `Print Pre&view`, **ID** para `ID_FILE_PRINT_PREVIEW`, **imagem** para `6`, e **imagem grande** para `6`.

   5. Agora você modificou o **itens principal**. Clique em **fechar** para sair do **itens Editor**.

7. A modificação a seguir cria um botão de saída que aparece na parte inferior do menu do botão do aplicativo.

   1. No **propriedades** janela, clique no botão de reticências (**...** ) ao lado de **botão** para abrir o **itens Editor**.

   2. Clique em **adicionar** para adicionar um botão. Alterar **legenda** para `E&xit`, **ID** para `ID_APP_EXIT`, **imagem** para `8`.

[[Seções](#top)]

##  <a name="createinstance"></a> Criar uma instância da barra de faixa de opções

As etapas a seguir mostram como criar uma instância da barra de faixa de opções quando seu aplicativo é iniciado. Para adicionar uma barra de faixa de opções para um aplicativo, declare a barra da faixa de opções no arquivo mainfrm.h. Em seguida, no arquivo mainfrm.cpp, escreva código para carregar o recurso de faixa de opções.

### <a name="to-create-an-instance-of-the-ribbon-bar"></a>Para criar uma instância da barra de faixa de opções

1. No arquivo mainfrm.h, adicionar um membro de dados para a seção protegida de `CMainFrame`, a definição de classe para o quadro principal. Este membro representa a barra de faixa de opções.

    ```cpp
    // Ribbon bar for the application
    CMFCRibbonBar m_wndRibbonBar;
    ```

2. No arquivo mainfrm.cpp, adicione o código a seguir antes do último `return` instrução no final de `CMainFrame::OnCreate` função. Isso cria uma instância da barra de faixa de opções.

    ```cpp
    // Create the ribbon bar
    if (!m_wndRibbonBar.Create(this))
    {
        return -1;   //Failed to create ribbon bar
    }
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);
    ```

[[Seções](#top)]

##  <a name="addcategory"></a> Personalizando o recurso de faixa de opções

Agora que você criou o botão do aplicativo, você pode adicionar elementos à faixa de opções.

> [!NOTE]
> Este passo a passo usa o mesmo ícone de painel para todos os painéis. No entanto, você pode usar outros índices de lista de imagem para exibir outros ícones.

### <a name="to-add-a-home-category-and-edit-panel"></a>Para adicionar uma categoria de Home e editar o painel

1. O programa de rabisco requer somente uma categoria. No modo design, clique em **categoria** para exibir suas propriedades. Alterar valores de propriedade da seguinte maneira: **legenda** para `&Home`, **imagens grandes** para `IDB_RIBBON_HOMELARGE`, **imagens pequenas** para `IDB_RIBBON_HOMESMALL`.

2. Cada categoria de faixa de opções é organizada em painéis nomeadas. Cada painel contém um conjunto de controles que executam operações relacionadas. Esta categoria tem um painel. Clique em **painel**e, em seguida, alterar **legenda** para `Edit` e **índice de imagem** para `0`.

3. Para o **editar** painel, adicione um botão que é responsável por limpar o conteúdo do documento. A ID da mensagem para este botão já foi definida no recurso de menu IDR_SCRIBBTYPE. Especifique `Clear All` como o texto do botão e o índice do bitmap que decora o botão. Abra o **caixa de ferramentas**e, em seguida, arraste um **botão** para o **editar** painel. Clique no botão e, em seguida, alterar **legenda** para `Clear All`, **ID** para `ID_EDIT_CLEAR_ALL`, **índice de imagem** para `0`, **índice da imagem grande**  para `0`.

4. Salvar as alterações e, em seguida, compilar e executar o aplicativo. O aplicativo de rabisco deve ser exibido, e ele deve ter uma barra de faixa de opções na parte superior da janela, em vez de uma barra de menus. A barra de faixa de opções deve ter uma categoria, **início**, e **início** devem ter um painel, **editar**. Os botões da faixa de opções que você adicionou devem ser associados com os manipuladores de eventos existentes e o **abrir**, **fechar**, **salvar**, **impressão**, e **Limpar tudo** botões devem funcionar conforme o esperado.

[[Seções](#top)]

##  <a name="setlook"></a> Definir a aparência do aplicativo

Um *manager visual* é um objeto global que controla todos os desenhos de um aplicativo. Como o aplicativo de rabisco original usa o estilo de interface do usuário de usuário do Office 2000, o aplicativo pode parecer antigo. Você pode redefinir o aplicativo para usar o Gerenciador de visual do Office 2007 para que ele é semelhante a um aplicativo do Office 2007.

### <a name="to-set-the-look-of-the-application"></a>Para definir a aparência do aplicativo

1. No `CMainFrame::OnCreate` de função, digite o código a seguir para alterar o estilo e o Gerenciador de visual padrão.

    ```cpp
    // Set the default manager to Office 2007
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
    CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
    ```

2. Salvar as alterações e, em seguida, compilar e executar o aplicativo. O interface do usuário do aplicativo deve se parecer com a interface do usuário do Office 2007.

[[Seções](#top)]

## <a name="next-steps"></a>Próximas etapas

Você modificou o exemplo de rabisco MFC de 1.0 clássico para usar o Designer de faixa de opções. Agora vá para [parte 2](../mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md).

## <a name="see-also"></a>Consulte também

[Explicações Passo a Passo](../mfc/walkthroughs-mfc.md)  
[Explicação passo a passo: atualizando o aplicativo de rabisco MFC (parte 2)] (.. / mfc/walkthrough-updating-the-mfc-scribble-application-part-2.md)  
