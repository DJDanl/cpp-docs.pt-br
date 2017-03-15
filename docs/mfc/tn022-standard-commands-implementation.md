---
title: "TN022: implementa&#231;&#227;o de comandos padr&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.commands"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "comandos, padrão"
  - "Comando ID_APP_ABOUT"
  - "Comando ID_APP_EXIT"
  - "Comando ID_CONTEXT_HELP"
  - "Comando ID_DEFAULT_HELP"
  - "Comando ID_EDIT_CLEAR"
  - "Comando ID_EDIT_CLEAR_ALL"
  - "Comando ID_EDIT_COPY"
  - "Comando ID_EDIT_CUT"
  - "Comando ID_EDIT_FIND"
  - "Comando ID_EDIT_PASTE"
  - "Comando ID_EDIT_PASTE_LINK"
  - "Comando ID_EDIT_PASTE_SPECIAL"
  - "Comando ID_EDIT_REDO"
  - "Comando ID_EDIT_REPEAT"
  - "Comando ID_EDIT_REPLACE"
  - "Comando ID_EDIT_SELECT_ALL"
  - "Comando ID_EDIT_UNDO"
  - "Comando ID_FILE_CLOSE"
  - "Comando ID_FILE_NEW"
  - "Comando ID_FILE_OPEN"
  - "Comando ID_FILE_PAGE_SETUP"
  - "Comando ID_FILE_PRINT"
  - "Comando ID_FILE_PRINT_PREVIEW"
  - "Comando ID_FILE_PRINT_SETUP"
  - "Comando ID_FILE_SAVE"
  - "Comando ID_FILE_SAVE_AS"
  - "Comando ID_FILE_SAVE_COPY_AS"
  - "Comando ID_FILE_UPDATE"
  - "Comando ID_HELP"
  - "Comando ID_HELP_INDEX"
  - "Comando ID_HELP_USING"
  - "Comando ID_INDICATOR_CAPS"
  - "Comando ID_INDICATOR_EXT"
  - "Comando ID_INDICATOR_KANA"
  - "Comando ID_INDICATOR_NUM"
  - "Comando ID_INDICATOR_OVR"
  - "Comando ID_INDICATOR_REC"
  - "Comando ID_INDICATOR_SCRL"
  - "Comando ID_NEXT_PANE"
  - "Comando ID_OLE_EDIT_LINKS"
  - "Comando ID_OLE_INSERT_NEW"
  - "Comando ID_OLE_VERB_FIRST"
  - "Comando ID_PREV_PANE"
  - "Comando ID_VIEW_STATUS_BAR"
  - "Comando ID_VIEW_TOOLBAR"
  - "Comando ID_WINDOW_ARRANGE"
  - "Comando ID_WINDOW_CASCADE"
  - "Comando ID_WINDOW_NEW"
  - "Comando ID_WINDOW_SPLIT"
  - "Comando ID_WINDOW_TILE_HORZ"
  - "Comando ID_WINDOW_TILE_VERT"
  - "comandos padrão"
  - "TN022"
ms.assetid: a7883b46-23f7-4870-ac3a-804aed9258b5
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN022: implementa&#231;&#227;o de comandos padr&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve as implementações de comando padrão fornecidas por MFC 2.0.  Ler [Observação 21 técnica](../mfc/tn021-command-and-message-routing.md) primeiro porque descreve os mecanismos usados para implementar muitos dos comandos padrão.  
  
 Essa descrição assume o conhecimento das arquiteturas MFC, das APIs e, na prática comum de programação.  “Das APIs documentados bem como não documentados implementação apenas” são descritos.  Isso não é um local para iniciar saber mais sobre os recursos do ou como programar MFC no.  Consulte o Visual C\+\+ para obter mais informações gerais e para obter detalhes de APIs documentados.  
  
## O problema  
 Define vários IDs MFC O padrão do comando no arquivo de cabeçalho. AFXRES.H.  O suporte à estrutura para esses comandos varia.  Entender onde e como as classes da estrutura desses comandos ele não só mostrarão como a estrutura trabalhar internamente mas fornecerá informações úteis sobre como personalizar as implementações padrão e ensinar\-lhe algumas técnicas para implementar seus próprios manipuladores de comando.  
  
## Conteúdo dessa técnica observação  
 Cada ID do comando é descrito em duas seções:  
  
-   O título: o nome simbólico de ID de comando \(por exemplo, **ID\_FILE\_SAVE**\) seguido por finalidade de comando \(por exemplo, “salva o documento atual”\) separados por dois\-pontos.  
  
-   Um ou vários parágrafos que descrevem quais classes implementam o comando, e o que faz a implementação padrão  
  
 A maioria de implementações padrão de comando são prewired da mensagem da classe base da estrutura.  Há algumas implementações de comando que exigem a fiação explícita em sua classe derivada.  Esses são descritos na “observação”.  Se você escolher as opções corretas em AppWizard, esses manipuladores padrão serão conectados para você no aplicativo do esqueleto gerado.  
  
## Convenção de nomenclatura  
 Os comandos padrão seguem uma convenção de nomenclatura simples que é recomendável o uso se possível.  A maioria de comandos padrão são localizados em locais padrão na barra de menus de um aplicativo.  O nome simbólico de início do comando com “ID\_” seguido pelo nome do menu pop\-up padrão, seguido pelo nome do item de menu.  O nome simbólico está em maiúscula com palavra\- quebras de sublinhado.  Para comandos que não têm padrão o item de menu nomeação, um nome de comando lógico é definido iniciar com “ID\_” \(por exemplo, **ID\_NEXT\_PANE**\).  
  
 Usamos o prefixo “ID\_” para indicar os comandos que são criados para serem associados aos itens de menu, os botões da barra de ferramentas, ou a outro objetos de interface do usuário do comando.  Os manipuladores de comando que manipulam comandos de “ID\_” devem usar `ON_COMMAND` e os mecanismos de `ON_UPDATE_COMMAND_UI` MFC comando a arquitetura.  
  
 Nós recomendamos que você use o prefixo padrão de “IDM\_” para os itens de menu que não obedecem a arquitetura de comando e não precisam do código menu\- específico de habilitar e desabilitar.  É o número de comandos específicos do menu deverá ser pequeno desde o seguinte comando do que MFC a arquitetura não apenas manipuladores de comando mais avançadas \(desde que trabalharão com barras de ferramentas\) mas faz o código do manipulador de comando reutilizável.  
  
## Intervalos de ID  
 Consulte os [Observação 20 técnica](../mfc/tn020-id-naming-and-numbering-conventions.md) para obter mais detalhes sobre uso de intervalos da ID em MFC.  
  
 Os comandos padrão de MFC caem no intervalo 0xE000 a 0xEFFF.  \(Em inglês\) não confie nos valores específicos dessas IDs desde que estão sujeitos a alteração em versões futuras de biblioteca.  
  
 Seu aplicativo deve definir os comandos no intervalo 0x8000 a 0xDFFF.  
  
## IDs de comando padrão  
 Para cada ID de comando, há uma linha de mensagem padrão cadeia de caracteres de aviso que pode ser localizada no arquivo PROMPTS.RC.  A ID da cadeia de caracteres para esse aviso de menu deverá ser o mesmo da ID de comando  
  
-   ID\_FILE\_NEW cria um novo\/esvazia o documento.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnFileNew` implementa esse comando de modo diferente dependendo do número de modelos do documento no aplicativo.  Se houver apenas um `CDocTemplate`, `CWinApp::OnFileNew` criará um novo documento desse tipo, bem como a classe adequada do quadro e exibição.  
  
     Se houver mais de um `CDocTemplate`, `CWinApp::OnFileNew` solicitará que o usuário com uma caixa de diálogo \(**AFX\_IDD\_NEWTYPEDLG**\) que permite que os selecione o tipo de documento a ser usado.  `CDocTemplate` selecionado é usado para criar o documento.  
  
     A personalização comuns de `ID_FILE_NEW` é fornecer uma opção diferente e mais gráfico de tipos de documento.  Nesse caso você pode implementar seu próprio **CMyApp::OnFileNew** e colocá\-lo em seu mapa de mensagem em vez de `CWinApp::OnFileNew`.  Não há necessidade de chamar a implementação da classe base.  
  
     Outra personalização comuns de `ID_FILE_NEW` é fornecer um comando separadamente para criar um documento de cada tipo.  Nesse caso você deve definir novas IDs de comando, por exemplo ID\_FILE\_NEW\_CHART e ID\_FILE\_NEW\_SHEET.  
  
-   ID\_FILE\_OPEN abrir um documento existente.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnFileOpen` tiver uma implementação muito simples de chamar **CWinApp::DoPromptFileName** seguido por `CWinApp::OpenDocumentFile` com o nome do arquivo ou do caminho do arquivo para abrir o.  A implementação **DoPromptFileName** rotina de `CWinApp` abre a caixa de diálogo padrão de FileOpen e acrescenta as extensões de arquivo obtidas modelos de documento atual.  
  
     A personalização comuns de `ID_FILE_OPEN` é personalizar a caixa de diálogo de FileOpen ou adicionar filtros de arquivo adicionais.  A maneira recomendada de personalização é substituir a implementação padrão com sua própria caixa de diálogo de FileOpen, e chama `CWinApp::OpenDocumentFile` com o nome de arquivo ou path de documento.  Não há necessidade de chamar a classe base.  
  
-   ID\_FILE\_CLOSE fecha atualmente o documento aberto.  
  
     **CDocument::OnFileClose** chama `CDocument::SaveModified` para solicitar o usuário para salvar o documento se foi alterado e chame `OnCloseDocument`.  Qualquer lógica de fechamento, incluindo destruindo o documento, é feita na rotina de `OnCloseDocument` .  
  
    > [!NOTE]
    >  Os atos de**ID\_FILE\_CLOSE** diferentemente de uma mensagem de `WM_CLOSE` ou de um comando do sistema de **SC\_CLOSE** enviadas à janela do quadro de documentos.  Fechar uma janela fechará o documento apenas se essa é a janela do último tableau que mostra o documento.  Feche o documento com **ID\_FILE\_CLOSE** não fechará apenas o documento mas fechará para baixo todas as janelas do tableau que mostram o documento.  
  
-   ID\_FILE\_SAVE salva o documento atual.  
  
     A implementação usa um auxiliar **CDocument::DoSave** rotina que é usado para **OnFileSave** e **OnFileSaveAs**.  Se você salvar um documento de que não foi salvo antes \(isto é, não tiver um nome de caminho, como no caso de FileNew\) ou de que esteve ler de um documento somente leitura, a lógica de **OnFileSave** atuará como o comando de **ID\_FILE\_SAVE\_AS** e solicitará que o usuário forneça um nome de arquivo novo.  O processamento real de abrir o arquivo e de fazer a gravação é feito com a função virtual `OnSaveDocument`.  
  
     Há duas razões comuns personalizar **ID\_FILE\_SAVE**.  Para documentos que não salvar, basta remover itens de menu e os botões da barra de ferramentas de **ID\_FILE\_SAVE** da interface do usuário.  Também verifique se você nunca sujo o documento \(ou seja, nunca chama `CDocument::SetModifiedFlag`\) e a estrutura nunca fará com que o documento a ser salvo.  Para documentos que salvá\-la em algum lugar diferente de um arquivo de disco, defina um novo comando para essa operação.  
  
     No caso de `COleServerDoc`, **ID\_FILE\_SAVE** é usado para salvar do arquivo \(para documentos normais\) e a atualização do arquivo \(para documentos inseridos\).  
  
     Se os dados de documento são armazenados em arquivos de disco individuais, mas você não quiser usar **CDocument** padrão serializa a implementação, você deve substituir `CDocument::OnSaveDocument` em vez de **OnFileSave**.  
  
-   ID\_FILE\_SAVE\_AS salva o documento atual em um nome de arquivo diferente.  
  
     A implementação de **CDocument::OnFileSaveAs** usa a mesma rotina de auxiliar de **CDocument::DoSave** que **OnFileSave**.  O comando de **OnFileSaveAs** é tratado como **ID\_FILE\_SAVE** se os documentos não tinham nenhum nome de arquivo antes de salvar.  **COleServerDoc::OnFileSaveAs** implementa a lógica para salvar um arquivo de dados de documento normal ou para salvar um documento de servidor que representa um objeto OLE inserido em algum outro aplicativo como um arquivo separado.  
  
     Se você personaliza a lógica de **ID\_FILE\_SAVE**, provavelmente vai querer personalizar de maneira semelhante **ID\_FILE\_SAVE\_AS** ou a operação “salvar como” não pode se aplicar ao documento.  Você pode remover o item de menu da barra de menus se não é necessária.  
  
-   ID\_FILE\_SAVE\_COPY\_AS a uma cópia salva o documento atual em um novo nome.  
  
     A implementação de **COleServerDoc::OnFileSaveCopyAs** é bem semelhante a **CDocument::OnFileSaveAs**, exceto que o objeto de documento não é “” anexado ao arquivo subjacente depois de salvar.  Ou seja, se o documento de memória “esteve alterado” antes de salvar, ele ainda for alterada “”.  Além disso, esse comando não tem nenhum efeito no nome ou no título de caminho armazenado no documento.  
  
-   ID\_FILE\_UPDATE notifica o contêiner para salvar um documento inserido.  
  
     `COleServerDoc::OnUpdateDocument` de implementação dos notifiies somente o contêiner que a inserção será salva.  O contêiner chama nas APIs OLE DB apropriados para salvar o objeto inserido.  
  
-   ID\_FILE\_PAGE\_SETUP invoca uma caixa de diálogo de aplicativo específico de configuração\/layout de página.  
  
     Atualmente não há nenhum padrão para esta caixa de diálogo, e a estrutura não tem nenhuma implementação padrão desse comando.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_FILE\_PRINT\_SETUP invoca a caixa de diálogo padrão da configuração de cópia.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     Este comando invoca a caixa de diálogo padrão da configuração de cópia que permite que o usuário ajusta as configurações da impressora e de impressão no mínimo esse documento ou no máximo todos os documentos nesse aplicativo.  Você deve usar o painel de controle para alterar as configurações da impressora padrão para todo o sistema.  
  
     `CWinApp::OnFilePrintSetup` tiver uma implementação muito simples que cria um objeto de `CPrintDialog` e que chama a função da implementação de **CWinApp::DoPrintDialog** .  Isso define a configuração da impressora padrão do aplicativo.  
  
     A necessidade comum para personalizar esse comando é permitir as configurações da impressora do documento, que devem ser armazenadas com o documento quando salvas.  Para fazer isso que você deve adicionar um manipulador retornadas mapa em sua classe de **CDocument** que cria um objeto de `CPrintDialog` , inicializa o com os atributos apropriados da impressora \(normalmente **hDevMode** e **hDevNames**\), chama **CPrintDialog::DoModal,** e salvar as configurações alteradas da impressora.  Para uma implementação robusto, você deve ter a implementação de **CWinApp::DoPrintDialog** para detectar erros e **CWinApp::UpdatePrinterSelection** para tratar as opções sensatos e controlar a impressora em qualquer sistema é alterado.  
  
-   Impressão padrão de ID\_FILE\_PRINT do documento atual  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CView`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     Este comando imprime o documento atual, ou mais corretamente, o inicia o processo de impressão, que envolve chamar a caixa de diálogo e a execução padrão da cópia o mecanismo de cópia.  
  
     **CView::OnFilePrint** implementa esse comando e o loop principal de cópia.  Chama `CView::OnPreparePrinting` virtual do prompt do usuário com a caixa de diálogo de impressão.  Prepara a DC. de saída para ir para a impressora, abre a caixa de diálogo progresso de impressão \(**AFX\_IDD\_PRINTDLG**\), e envia o escape de `StartDoc` para a impressora.  **CView::OnFilePrint** também contém o loop orientado main de cópia.  Para cada página, chama `CView::OnPrepareDC` virtual e um vazamento de `StartPage` e chamar `CView::OnPrint` virtual nessa página.  Quando terminar, `CView::OnEndPrinting` virtual é chamado e, na caixa de diálogo progresso de impressão é fechada.  
  
     A arquitetura de impressão MFC é criada para conectar em muitas maneiras diferentes para imprimir e visualização de impressão.  Você encontrará normalmente as várias funções substituível de `CView` suficientes para todas as tarefas imprimindo página distribuídas.  Apenas no caso de um aplicativo que usa a impressora para não página orientou saída, se você encontrar a necessidade de substituir a implementação de **ID\_FILE\_PRINT** .  
  
-   ID\_FILE\_PRINT\_PREVIEW entram no modo de visualização de impressão para o documento atual.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CView`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     **CView::OnFilePrintPreview** inicia o modo de visualização de impressão chamando a função de **CView::DoPrintPreview**auxiliar.  **CView::DoPrintPreview** é o mecanismo principal para o loop de visualização de impressão, assim como **OnFilePrint** é o mecanismo principal para o loop de impressão.  
  
     A operação de visualização de impressão pode ser personalizada de várias maneiras passando parâmetros diferentes a **DoPrintPreview**.  Consulte os [Observação 30 técnica](../mfc/tn030-customizing-printing-and-print-preview.md), que abordam algum dos detalhes de visualização de impressão e personalizar como o.  
  
-   Intervalo de**ID\_FILE\_MRU\_FILE1**…**FILE16** A de IDs de comando para Arquivo MRU `list`.  
  
     **CWinApp::OnUpdateRecentFileMenu** é um manipulador de interface de usuário do comando de atualização que é um dos usos mais avançados do mecanismo de `ON_UPDATE_COMMAND_UI` .  No recurso no menu, você só precisa definir um único item de menu com ID **ID\_FILE\_MRU\_FILE1**.  O qual o item de menu permanece inicialmente desabilitado.  
  
     Como a lista de MRU aumenta, mais itens de menu serão adicionados à lista.  A implementação de `CWinApp` do padrão usa como padrão o limite padrão dos quatro arquivos usados recentemente.  Você pode alterar a opção `CWinApp::LoadStdProfileSettings` chamando com um valor maior ou menor.  A lista de MRU é armazenada no arquivo .ini do aplicativo.  A lista é carregada na função de `InitInstance` do seu aplicativo se você chamar `LoadStdProfileSettings`, e salva quando seu aplicativo.  O manipulador de interface de usuário do comando de atualização do MRU também converterá caminhos absolutos para caminhos relativos para a exibição no menu arquivo.  
  
     **CWinApp::OnOpenRecentFile** é o manipulador de `ON_COMMAND` que executa o comando real.  Obtém apenas o nome de arquivo da lista de MRU e chama `CWinApp::OpenDocumentFile`, que executa qualquer trabalho de abrir o arquivo e atualizar a lista de MRU.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_EDIT\_CLEAR desmarcar a seleção atual  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando que usa `CEdit::Clear`.  O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_CLEAR\_ALL limpa o documento inteiro.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  Consulte o exemplo [GARRANCHO](../top/visual-cpp-samples.md) do tutorial de MFC para uma implementação de exemplo.  
  
-   ID\_EDIT\_COPY copia a seleção atual na área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que copia o texto selecionado à área de transferência como CF\_TEXT usando `CEdit::Copy`.  O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_CUT diminuísse a seleção atual na área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que diminuísse o texto selecionado à área de transferência como CF\_TEXT usando `CEdit::Cut`.  O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_FIND inicia a operação de localização, abre a caixa de diálogo modeless de localização.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que chama a função **OnEditFindReplace** auxiliares de implementação para usar e para armazenar o localizar anterior\/substitua variáveis de implementação das configurações em particular.  A classe de `CFindReplaceDialog` é usada para gerenciar a caixa de diálogo modeless para solicitar o usuário.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_PASTE insere o conteúdo atual da área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que copia os dados atuais da área de transferência que substitui o texto selecionado usando `CEdit::Paste`.  O comando é desabilitado se não houver nenhum **CF\_TEXT** na área de transferência.  
  
     **COleClientDoc** fornece apenas um manipulador de interface de usuário do comando de atualização desse comando.  Se a área de transferência não contém um item e inserível objeto OLE, o comando será desabilitado.  Você é responsável para escrever o manipulador para que o comando real faça colar real.  Se seu aplicativo OLE também pode colar outros formatos, você deve fornecer seu próprio manipulador de interface de usuário do comando de atualização do documento ou exibição \(isto é, em algum lugar antes de **COleClientDoc** no roteamento de destino de comando\).  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
     Para substituir a implementação OLE padrão, use `COleClientItem::CanPaste`.  
  
-   ID\_EDIT\_PASTE\_LINK insere um link de conteúdo atual da área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `COleDocument` fornece apenas um manipulador de interface de usuário do comando de atualização desse comando.  Se a área de transferência não contém o item\/objeto OLE enlaçáveis, o comando será desabilitado.  Você é responsável para escrever o manipulador para que o comando real faça colar real.  Se seu aplicativo OLE também pode colar outros formatos, você deve fornecer seu próprio manipulador de interface de usuário do comando de atualização do documento ou exibição \(isto é, em algum lugar antes de `COleDocument` no roteamento de destino de comando\).  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
     Para substituir a implementação OLE padrão, use `COleClientItem::CanPasteLink`.  
  
-   ID\_EDIT\_PASTE\_SPECIAL insere o conteúdo atual da área de transferência com as opções.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  O MFC não fornecer essa caixa de diálogo.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_REPEAT repete a última operação.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando repita a última operação de localização.  As variáveis particulares de implementação do localizar o último são usados.  O comando é desabilitado se achar não pode ser tentado.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_REPLACE inicia a operação de substituição, abre o modeless substitui a caixa de diálogo.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que chama a função **OnEditFindReplace** auxiliares de implementação para usar e para armazenar o localizar anterior\/substitua variáveis de implementação das configurações em particular.  A classe de `CFindReplaceDialog` é usada para gerenciar a caixa de diálogo modeless que solicita ao usuário.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_SELECT\_ALL seleciona o documento inteiro.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, que seleciona todo o texto do documento.  O comando é desabilitado se não houver nenhum texto para selecionar.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_UNDO desfazer a última operação.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     `CEditView` fornece uma implementação desse comando, usando `CEdit::Undo`.  O comando é desabilitado se `CEdit::CanUndo` retornará FALSE.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_EDIT\_REDO na operação refazer a última vez.  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para cada `CView`\- classe derivada.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_WINDOW\_NEW abrir outra janela no documento ativo.  
  
     **CMDIFrameWnd::OnWindowNew** implementa esse recurso avançado usando o modelo de documento do documento atual para criar outro quadro que contém outra exibição do documento atual.  
  
     Como a maioria dos comandos de menu na janela de \(MDI\) interface de documentos, o comando será desabilitado se não houver nenhuma janela ativa filho MDI.  
  
     A personalização do manipulador do comando não é recomendada.  Se você quiser fornecer um comando que criar exibições adicionais ou janelas do quadro, provavelmente estará mais em melhor situação inventando seu próprio comando.  É possível clonar o código de **CMDIFrameWnd::OnWindowNew** e modificá\-lo a classes específicas do quadro e exibição de seu gosto.  
  
-   ID\_WINDOW\_ARRANGE organiza os ícones da parte inferior da janela de documentos.  
  
     `CMDIFrameWnd` implementa este comando padrão MDI em uma função **OnMDIWindowCmd**auxiliares de implementação.  Este auxiliar mapeia IDs de comando a mensagens do windows MDI e em virtude disso pode compartilhar muito código.  
  
     Como a maioria dos comandos de menu na janela de documentos, o comando será desabilitado se não houver nenhuma janela ativa filho MDI.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_WINDOW\_CASCADE conecta o windows para que se sobrepõem.  
  
     `CMDIFrameWnd` implementa este comando padrão MDI em uma função **OnMDIWindowCmd**auxiliares de implementação.  Este auxiliar mapeia IDs de comando a mensagens do windows MDI e em virtude disso pode compartilhar muito código.  
  
     Como a maioria dos comandos de menu na janela de documentos, o comando será desabilitado se não houver nenhuma janela ativa filho MDI.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   Janelas de peças de ID\_WINDOW\_TILE\_HORZ horizontalmente.  
  
     Este comando é implementado em `CMDIFrameWnd` exatamente como **ID\_WINDOW\_CASCADE**, a não ser que uma mensagem diferente do windows MDI será usada para a operação.  
  
     Você deve escolher a orientação lado a lado padrão para seu aplicativo.  Você pode fazer isso alterando a ID do item de menu “quadro de janela” a **ID\_WINDOW\_TILE\_HORZ** ou a **ID\_WINDOW\_TILE\_VERT**.  
  
-   Janelas de peças de ID\_WINDOW\_TILE\_VERT verticalmente.  
  
     Este comando é implementado em `CMDIFrameWnd` exatamente como **ID\_WINDOW\_CASCADE**, a não ser que uma mensagem diferente do windows MDI será usada para a operação.  
  
     Você deve escolher a orientação lado a lado padrão para seu aplicativo.  Você pode fazer isso alterando a ID do item de menu “quadro de janela” a **ID\_WINDOW\_TILE\_HORZ** ou a **ID\_WINDOW\_TILE\_VERT**.  
  
-   Interface de teclado de ID\_WINDOW\_SPLIT o separador.  
  
     `CView` trata esse comando para a implementação de `CSplitterWnd` .  Se a exibição é parte de uma janela do divisor, este comando delegará à função `CSplitterWnd::DoKeyboardSplit`de implementação.  Isso colocará o separador em um modo que permite que os usuários do teclado ou se divide o unsplit uma janela do separador.  
  
     Este comando será desabilitado se a exibição não está em um separador.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_APP\_ABOUT invoca aproximadamente a caixa de diálogo.  
  
     Não há nenhuma implementação padrão para um aplicativo na caixa.  O aplicativo AppWizard\- criado padrão criará uma classe personalizada da caixa de diálogo para seu aplicativo e usá\-lo como sua aproximadamente a caixa.  AppWizard também escreverá o manipulador trivial de comando que trata esse comando e invoca a caixa de diálogo.  
  
     Você implementará quase sempre este comando.  
  
-   Saída de ID\_APP\_EXIT o aplicativo.  
  
     **CWinApp::OnAppExit** trata esse comando enviando uma mensagem de `WM_CLOSE` a janela principal do aplicativo.  Fechar padrão do aplicativo \(alerta para arquivos incorretos e assim por diante\) é tratado pela implementação de `CFrameWnd` .  
  
     A personalização do manipulador do comando não é recomendada.  Substituir `CWinApp::SaveAllModified` ou `CFrameWnd` que fecha a lógica é recomendado.  
  
     Se você optar por implementar este comando, é recomendável usar essa ID de comando  
  
-   ID\_HELP\_INDEX lista os tópicos da Ajuda do arquivo de .HLP.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelpIndex` trata esse comando de `CWinApp::WinHelp`chamando.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   Vídeos de ID\_HELP\_USING ajudam sobre como usar a ajuda.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelpUsing` trata esse comando de `CWinApp::WinHelp`chamando.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_CONTEXT\_HELP passa para o modo de ajuda SHIFT\-F1.  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnContextHelp` trata esse comando definindo o cursor do modo da ajuda, inserindo um loop modal e aguardando o usuário para selecionar uma janela para obter informações sobre a ajuda.  Consulte os [Observação 28 técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação da ajuda MFC.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_HELP da ajuda no contexto atual  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelp` trata esse comando obtendo o contexto direito da ajuda para o contexto atual do aplicativo.  Isso controla a ajuda F1 ajuda simples, na caixa de mensagem e assim por diante.  Consulte os [Observação 28 técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação da ajuda MFC.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   Ajuda da opção de vídeos de ID\_DEFAULT\_HELP para o contexto  
  
    > [!NOTE]
    >  Você deve se conectar a esse seu `CWinApp`\- mapa derivado da mensagem da classe para habilitar essa funcionalidade.  
  
     Este comando é mapeado geralmente a `CWinApp::OnHelpIndex`.  
  
     Um manipulador diferente do comando pode ser fornecido se uma distinção entre a ajuda padrão e o índice da ajuda for desejada.  
  
-   ID\_NEXT\_PANE avança para o próximo painel  
  
     `CView` trata esse comando para a implementação de `CSplitterWnd` .  Se a exibição é parte de uma janela do divisor, este comando delegará à função **CSplitterWnd::OnNextPaneCmd**de implementação.  Isso será movido a exibição ativa para o próximo painel no separador.  
  
     Este comando será desabilitado se a exibição não está em um separador ou se não houver nenhum o próximo painel para a qual ir.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_PREV\_PANE vai para o painel anterior  
  
     `CView` trata esse comando para a implementação de `CSplitterWnd` .  Se a exibição é parte de uma janela do divisor, este comando delegará à função **CSplitterWnd::OnNextPaneCmd**de implementação.  Isso será movido a exibição ativa para o painel anterior do separador.  
  
     Este comando será desabilitado se a exibição não está em um separador ou se não houver nenhum o painel anterior para ir para.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   ID\_OLE\_INSERT\_NEW insere um novo objeto OLE  
  
     Atualmente não há nenhuma implementação padrão desse comando.  Você deve implementar este para o `CView`\- classe derivada para inserir um novo item\/objeto OLE na seleção atual.  
  
     Todos os aplicativos cliente OLE devem implementar este comando.  AppWizard, com a opção OLE, criará uma implementação do esqueleto de **OnInsertObject** em sua classe da exibição que você precisará concluir.  
  
     Consulte o exemplo de [OCLIENT](../top/visual-cpp-samples.md) de exemplo MFC OLE para uma implementação completo desse comando.  
  
-   ID\_OLE\_EDIT\_LINKS editar os links com OLE DB  
  
     `COleDocument` trata esse comando usando MFC\- forneceu a implementação da caixa de diálogo OLE padrão de links.  A implementação dessa caixa de diálogo for acessada pela classe de `COleLinksDialog` .  Se o documento atual não contém nenhum links, o comando está desabilitado.  
  
     A personalização do manipulador do comando não é recomendada.  
  
-   LAST de ID\_OLE\_VERB\_FIRST… um intervalo de ID de verbos OLE  
  
     `COleDocument` usa esse intervalo de ID de comando para os verbos aceitos pelo item\/objeto OLE atualmente selecionados.  Isso deve ser um intervalo desde que um item\/tipo de objeto OLE dados pode dar suporte a zero ou mais verbos personalizados.  No menu do seu aplicativo, você deve ter um item de menu usando a ID de **ID\_OLE\_VERB\_FIRST**.  Quando o programa for executado, o menu será atualizado com a descrição apropriado do verbo de menu \(ou menu pop\-up com muitos verbos\).  O gerenciamento de menu OLE é tratado por `AfxOleSetEditMenu`, armazenado no manipulador de interface de usuário do comando de atualização desse comando.  
  
     Não há nenhum explícito manipulador de comando para tratar cada um de ID do comando nesse intervalo.  **COleDocument::OnCmdMsg** é substituído para interceptar todos os IDs de comando nesse intervalo, para transformá\-los em números com base em zero do verbo, e para iniciar o servidor para aquele verbo \(usando `COleClientItem::DoVerb`\).  
  
     A personalização ou outro uso desse intervalo de ID do comando não são recomendados.  
  
-   \/desativar ID\_VIEW\_TOOLBAR ativa a barra de ferramentas ativa e desativa  
  
     `CFrameWnd` trata esse comando e o manipulador de interface de usuário de atualização comando ativar \/desativar o estado visível na barra de ferramentas.  A barra de ferramentas deve ser uma janela filho do quadro com a ID da janela filho de `AFX_IDW_TOOLBAR`.  O manipulador de comando ativa \/desativar na verdade a visibilidade da janela da barra de ferramentas.  `CFrameWnd::RecalcLayout` é usado para o novo desenho a janela do quadro com a barra de ferramentas no novo estado.  O manipulador de interface de usuário de atualização comando verifica o item de menu quando a barra de ferramentas é visível.  
  
     A personalização do manipulador do comando não é recomendada.  Se você deseja adicionar barras de ferramentas adicionais, você desejará clonar e alterar o manipulador de comando e o manipulador de interface de usuário de atualização comando para este comando.  
  
-   \/desativar ID\_VIEW\_STATUS\_BAR ativa a barra de status ativa e desativa  
  
     Este comando é implementado em `CFrameWnd` exatamente como **ID\_VIEW\_TOOLBAR**, a não ser que um ID diferente da janela filho \(**AFX\_IDW\_STATUS\_BAR**\) é usado.  
  
## Manipuladores de comando UPDATE Somente  
 Vários IDs de comando padrão são usados como indicadores nas barras de status.  Esses usam o mesmo atualização comando interface do usuário que trata o mecanismo para exibir o estado atual visual durante o tempo ocioso de aplicativo.  Desde que não podem ser selecionados pelo usuário \(ou seja, você não pode enviar um painel barra de status\), então não faz nenhuma sentido ter um manipulador de `ON_COMMAND` para essas IDs de comando.  
  
-   **ID\_INDICATOR\_CAPS** : Indicador de bloqueio de CAP.  
  
-   **ID\_INDICATOR\_NUM** : Indicador de bloqueio NUMERIC.  
  
-   **ID\_INDICATOR\_SCRL** : Indicador de bloqueio de SCRL.  
  
-   **ID\_INDICATOR\_KANA** : Indicador de bloqueio de KANA \(aplicável somente a sistemas japoneses\).  
  
 Todos os três dessas são implementadas em **CFrameWnd::OnUpdateKeyIndicator**, um auxiliar de implementação que usa o ID de comando para mapear para a chave virtual apropriado.  Uma implementação comuns habilita ou desabilita \(para os painéis de status desabilitado \= nenhum texto\) o objeto de `CCmdUI` dependendo se a chave virtual apropriada será bloqueada.  
  
 A personalização do manipulador do comando não é recomendada.  
  
-   **ID\_INDICATOR\_EXT : EXT**terminou o indicador selecione.  
  
-   Indicador de greve de**ID\_INDICATOR\_OVR : OV**e**R**.  
  
-   **ID\_INDICATOR\_REC : REC**que ording o medidor.  
  
 Atualmente não há nenhuma implementação padrão para esses indicadores.  
  
 Se você optar por implementar esses indicadores, recomendaremos usar essa ID de indicador e manutenção da ordenação dos indicadores na barra de status \(ou seja, nesta ordem: EXT, CAP, NUMERIC, SCRL, OVR, REC\).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)