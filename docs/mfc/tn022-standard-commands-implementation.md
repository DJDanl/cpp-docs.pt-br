---
title: 'TN022: Implementação de comandos padrão'
ms.date: 11/04/2016
f1_keywords:
- vc.commands
helpviewer_keywords:
- ID_PREV_PANE command [MFC]
- ID_APP_EXIT command [MFC]
- ID_NEXT_PANE command [MFC]
- ID_INDICATOR_REC command [MFC]
- ID_WINDOW_SPLIT command [MFC]
- ID_FILE_PRINT_PREVIEW command [MFC]
- ID_WINDOW_CASCADE command [MFC]
- ID_FILE_CLOSE command [MFC]
- ID_FILE_SAVE_COPY_AS command [MFC]
- ID_WINDOW_ARRANGE command [MFC]
- ID_EDIT_FIND command [MFC]
- ID_FILE_OPEN command [MFC]
- ID_FILE_PAGE_SETUP command [MFC]
- ID_OLE_VERB_FIRST command [MFC]
- ID_EDIT_UNDO command [MFC]
- ID_EDIT_CLEAR command [MFC]
- ID_INDICATOR_CAPS command [MFC]
- ID_HELP_INDEX command [MFC]
- commands [MFC], standard
- ID_FILE_PRINT_SETUP command [MFC]
- ID_DEFAULT_HELP command [MFC]
- ID_INDICATOR_SCRL command [MFC]
- ID_FILE_PRINT command [MFC]
- ID_INDICATOR_OVR command [MFC]
- ID_INDICATOR_KANA command [MFC]
- ID_EDIT_COPY command [MFC]
- ID_EDIT_REDO command [MFC]
- ID_EDIT_PASTE command [MFC]
- ID_OLE_INSERT_NEW command [MFC]
- ID_OLE_EDIT_LINKS command [MFC]
- ID_EDIT_PASTE_SPECIAL command [MFC]
- ID_INDICATOR_EXT command [MFC]
- ID_HELP_USING command [MFC]
- standard commands
- ID_VIEW_STATUS_BAR command [MFC]
- ID_FILE_SAVE_AS command [MFC]
- ID_EDIT_CLEAR_ALL command [MFC]
- ID_WINDOW_NEW command [MFC]
- ID_CONTEXT_HELP command [MFC]
- ID_EDIT_REPLACE command [MFC]
- ID_WINDOW_TILE_HORZ command [MFC]
- ID_APP_ABOUT command [MFC]
- TN022
- ID_VIEW_TOOLBAR command [MFC]
- ID_HELP command [MFC]
- ID_WINDOW_TILE_VERT command [MFC]
- ID_EDIT_CUT command [MFC]
- ID_FILE_UPDATE command [MFC]
- ID_EDIT_REPEAT command [MFC]
- ID_FILE_SAVE command [MFC]
- ID_EDIT_PASTE_LINK command [MFC]
- ID_EDIT_SELECT_ALL command [MFC]
- ID_FILE_NEW command [MFC]
- ID_INDICATOR_NUM command
ms.assetid: a7883b46-23f7-4870-ac3a-804aed9258b5
ms.openlocfilehash: 4c066521ba2b5be9ac24a8abaece42e57b8ad85f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279336"
---
# <a name="tn022-standard-commands-implementation"></a>TN022: Implementação de comandos padrão

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve as implementações de comando padrão fornecidas pelo MFC 2.0. Leia [21 de observação técnica](../mfc/tn021-command-and-message-routing.md) primeiro porque ele descreve os mecanismos usados para implementar muitos dos comandos padrão.

Essa descrição pressupõe conhecimento das arquiteturas MFC, APIs e prática de programação comuns. Documentado, bem como não documentada "implementação apenas" APIs são descritas. Isso não é um lugar para começar a aprender sobre os recursos do ou como programar no MFC. Consulte Visual C++ para obter mais informações gerais e para obter detalhes sobre as APIs documentadas.

## <a name="the-problem"></a>O problema

MFC define várias IDs de comando padrão no arquivo de cabeçalho AFXRES. H. Suporte do Framework para esses comandos varia de acordo. Noções básicas sobre onde e como as classes do framework lidar com esses comandos não apenas mostrará como o framework funciona internamente, mas fornecerá informações úteis sobre como personalizar as implementações padrão e ensinar a você algumas técnicas para implementar seus próprios manipuladores de comandos.

## <a name="contents-of-this-technical-note"></a>Conteúdo desta nota técnica

Cada ID de comando é descrita nas duas seções:

- Título: o nome simbólico do ID de comando (por exemplo, ID_FILE_SAVE) seguido pela finalidade do comando (por exemplo, "salva o documento atual") separados por dois-pontos.

- Um ou mais parágrafos que descreve quais classes devem implementam o comando e o que faz a implementação padrão

A maioria das implementações de comando padrão são prewired no mapa de mensagens de classe base da estrutura. Há algumas implementações de comando que exigem a fiação explícita em sua classe derivada. Elas são descritas em "Note". Se você escolher as opções certas em AppWizard, esses manipuladores padrão serão conectados no aplicativo de esqueleto gerado para você.

## <a name="naming-convention"></a>Convenção de nomenclatura

Comandos padrão seguem uma convenção de nomenclatura simple, recomendamos que você use, se possível. Comandos mais padrão estão localizados em locais padrão na barra de menus do aplicativo. O nome simbólico do comando começa com "ID _" seguido pelo nome do menu pop-up padrão, seguido do nome do item de menu. O nome simbólico está em letras maiusculas com quebras de palavras de sublinhado. Para os comandos que não têm nomes de item de menu padrão, um nome de comando lógico é definido começando com a ID do "_" (por exemplo, ID_NEXT_PANE).

Usamos o prefixo de "ID _" para indicar os comandos que são projetados para ser associado a itens de menu, botões de barra de ferramentas ou outros objetos de interface do usuário do comando. Manipulando comandos "ID _" de manipuladores de comandos devem usar os mecanismos de ON_COMMAND e ON_UPDATE_COMMAND_UI da arquitetura de comando do MFC.

É recomendável que você use o prefixo "IDM_" padrão para itens de menu que não seguem a arquitetura de comando e precisar de código específico do menu para habilitar e desabilitá-los. É claro o número específico de comandos de menu deve ser pequeno, pois seguindo a arquitetura de comando do MFC não apenas torna os manipuladores de comandos mais eficiente (já que eles funcionarão com barras de ferramentas), mas torna o código de manipulador de comando reutilizáveis.

## <a name="id-ranges"></a>Intervalos de ID

Consulte a [nota técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md) para obter mais detalhes sobre o uso de intervalos de ID no MFC.

Comandos padrão do MFC estão no intervalo 0xE000 para 0xEFFF. Por favor, não dependem dos valores específicos dessas IDs, pois eles estão sujeitos a alterações em versões futuras da biblioteca.

Seu aplicativo deve definir seus comandos no intervalo 0x8000 para 0xDFFF.

## <a name="standard-command-ids"></a>IDs de comando padrão

Para cada ID de comando, há uma sequência de prompt de linha de mensagem padrão que pode ser encontrada nos PROMPTS de arquivo. RC. A ID de cadeia de caracteres para o prompt menu deve ser da mesma maneira que a ID de comando.

- ID_FILE_NEW cria um documento novo ou está vazia.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnFileNew` implementa esse comando de forma diferente dependendo do número de modelos de documento no aplicativo. Se houver somente um `CDocTemplate`, `CWinApp::OnFileNew` criará um novo documento desse tipo, bem como a classe de quadro e o modo de exibição adequada.

   Se houver mais de um `CDocTemplate`, `CWinApp::OnFileNew` solicitará ao usuário uma caixa de diálogo (AFX_IDD_NEWTYPEDLG) permitindo que eles selecione qual tipo usar de documento. Selecionado `CDocTemplate` é usado para criar o documento.

   Uma personalização comuns de ID_FILE_NEW é fornecer uma opção diferente e mais opções de gráfica de tipos de documento. Nesse caso, você pode implementar seu próprio `CMyApp::OnFileNew` e coloque-o no seu mapa de mensagem, em vez de `CWinApp::OnFileNew`. Não é necessário chamar a implementação da classe base.

   Outra personalização comuns de ID_FILE_NEW é fornecer um comando separado para a criação de um documento de cada tipo. Nesse caso, você deve definir o novo comando IDs, por exemplo, ID_FILE_NEW_CHART e ID_FILE_NEW_SHEET.

- ID_FILE_OPEN abre um documento existente.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnFileOpen` tem uma implementação muito simple de chamar `CWinApp::DoPromptFileName` seguido por `CWinApp::OpenDocumentFile` com o nome de arquivo ou caminho do arquivo a ser aberto. O `CWinApp` rotina de implementação `DoPromptFileName` abre a caixa de diálogo FileOpen padrão e a preenche com as extensões de arquivo obtidas os modelos de documento atual.

   Uma personalização comuns de ID_FILE_OPEN é personalizar a caixa de diálogo FileOpen ou adicionar filtros de arquivo adicionais. A maneira recomendada para personalizá-lo é substituir a implementação padrão com sua própria caixa de diálogo FileOpen e chame `CWinApp::OpenDocumentFile` com o nome de arquivo ou caminho do documento. Não é necessário chamar a classe base.

- ID_FILE_CLOSE fecha o documento aberto no momento.

   `CDocument::OnFileClose` chamadas `CDocument::SaveModified` solicitar ao usuário para salvar o documento se ele tiver sido modificado e, em seguida, chama `OnCloseDocument`. Toda a lógica de fechamento, incluindo destruir o documento é feita na `OnCloseDocument` rotina.

    > [!NOTE]
    >  ID_FILE_CLOSE age Diferentemente de uma mensagem WM_CLOSE ou um comando do sistema SC_CLOSE enviadas para a janela de quadro de documentos. Fechar uma janela fechará o documento somente se for a última janela do quadro que mostra o documento. Fechando o documento com ID_FILE_CLOSE não apenas fechar o documento, mas será encerrado em todas as janelas de quadro que mostra o documento.

- ID_FILE_SAVE salva o documento atual.

   A implementação usa uma rotina auxiliar `CDocument::DoSave` que é usado para ambos `OnFileSave` e `OnFileSaveAs`. Se você salvar um documento que não tenha sido salvo antes (ou seja, ele não tem um nome de caminho, como no caso de FileNew) ou que foi lido de um documento somente leitura, o `OnFileSave` lógica atuará como o ID_FILE_SAVE_AS de comando e solicitar que o usuário forneça um novo nome de arquivo . O processo de abertura do arquivo e fazendo o salvamento é feito por meio da função virtual `OnSaveDocument`.

   Há duas razões comuns para personalizar ID_FILE_SAVE. Para documentos que não o salve, simplesmente remova os botões de barra de ferramentas e itens de menu ID_FILE_SAVE sua interface do usuário. Também Certifique-se de que você nunca sujos seu documento (ou seja, nunca chame `CDocument::SetModifiedFlag`) e a estrutura nunca fará com que o documento seja salvo. Para documentos que salvar em algum lugar diferente de um arquivo de disco, defina um novo comando para essa operação.

   No caso de um `COleServerDoc`, ID_FILE_SAVE é usado para salvar arquivo (para documentos normais) e a atualização do arquivo (para documentos incorporados).

   Se seus dados de documento são armazenados em arquivos de disco individual, mas você não quiser usar o padrão `CDocument` serializar a implementação, você deve substituir `CDocument::OnSaveDocument` em vez de `OnFileSave`.

- ID_FILE_SAVE_AS salva o documento atual com um nome de arquivo diferente.

   O `CDocument::OnFileSaveAs` implementação usa o mesmo `CDocument::DoSave` rotina auxiliar como `OnFileSave`. O `OnFileSaveAs` comando é tratado apenas como ID_FILE_SAVE se os documentos não tinham nenhum nome de arquivo antes de salvar. `COleServerDoc::OnFileSaveAs` implementa a lógica para salvar um arquivo de dados de documento normal ou salvar um documento do servidor que representa um objeto OLE inserido em algum outro aplicativo como um arquivo separado.

   Se você personalizar a lógica de ID_FILE_SAVE, você provavelmente desejará personalizar ID_FILE_SAVE_AS de maneira semelhante, ou a operação de "Salvar como" pode não se aplicar ao documento. Você pode remover o item de menu na barra de menus se não for necessária.

- ID_FILE_SAVE_COPY_AS salva um documento de cópia atual com um novo nome.

   O `COleServerDoc::OnFileSaveCopyAs` implementação é muito semelhante ao `CDocument::OnFileSaveAs`, exceto que o objeto de documento não está "anexado" no arquivo subjacente depois de salvar. Ou seja, se o documento na memória foi "modificado" antes de salvar, ela é ainda "modificada". Além disso, esse comando não tem nenhum efeito sobre o nome do caminho ou o título armazenado no documento.

- ID_FILE_UPDATE notifica o contêiner para salvar um documento incorporado.

   O `COleServerDoc::OnUpdateDocument` implementação simplesmente notifiies o contêiner que a inserção deve ser salvos. O contêiner, em seguida, chama o OLE APIs apropriadas para salvar o objeto inserido.

- ID_FILE_PAGE_SETUP invoca uma caixa de diálogo de instalação/layout de página específica do aplicativo.

   Atualmente, há um padrão para essa caixa de diálogo e a estrutura não tem nenhuma implementação padrão desse comando.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_FILE_PRINT_SETUP invocar a caixa de diálogo Configurar impressão padrão.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   Esse comando invoca a caixa de diálogo de configuração de impressão padrão que permite ao usuário personalizar a impressora e imprimir as configurações para pelo menos neste documento ou no máximo todos os documentos neste aplicativo. Você deve usar o painel de controle para alterar as configurações de impressora padrão para todo o sistema.

   `CWinApp::OnFilePrintSetup` tem uma implementação muito simples criar um `CPrintDialog` objeto e chamar o `CWinApp::DoPrintDialog` função de implementação. Isso define a configuração da impressora padrão aplicativo.

   A necessidade comum para personalizar esse comando é permitir configurações de impressora por documento, que devem ser armazenadas com o documento quando salvo. Para fazer isso, você deve adicionar um manipulador de mapa de mensagem em seu `CDocument` classe que cria um `CPrintDialog` de objeto, inicializa-o com os atributos de impressora apropriado (geralmente *hDevMode* e *hDevNames*), chame o `CPrintDialog::DoModal`e salvar as configurações de impressora alterados. Para uma implementação robusta, você deve examinar a implementação de `CWinApp::DoPrintDialog` para detectar erros e `CWinApp::UpdatePrinterSelection` para lidar com padrões pertinentes e controle de alterações de impressora em todo o sistema.

- Impressão padrão do ID_FILE_PRINT do documento atual

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CView`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   Este comando imprime o documento atual ou, mais corretamente, inicia o processo de impressão, que envolve invocar a caixa de diálogo de impressa padrão e executando o mecanismo de impressão.

   `CView::OnFilePrint` implementa esse comando e o loop principal de impressão. Ele chama virtual `CView::OnPreparePrinting` ao prompt do usuário com a caixa de diálogo de impressão. Em seguida, prepara a controlador de domínio de saída para ir para a impressora, abre a caixa de diálogo de progresso impressão (AFX_IDD_PRINTDLG) e envia o `StartDoc` escape para a impressora. `CView::OnFilePrint` também contém o loop principal de impressão orientada por página. Para cada página, ele chama o virtual `CView::OnPrepareDC` seguido por um `StartPage` escape e chamando virtual `CView::OnPrint` para essa página. Ao concluir, o virtual `CView::OnEndPrinting` é chamado, e a impressão caixa de diálogo de progresso é fechada.

   A arquitetura de impressão MFC foi projetada para conectar-se de muitas maneiras diferentes para impressão e visualização de impressão. Normalmente você encontrará os vários `CView` funções substituíveis adequadas para as tarefas de impressão orientada por página. Somente no caso de um aplicativo que usa a impressora para a saída de página não orientada, você deve encontrar a necessidade de substituir a implementação de ID_FILE_PRINT.

- Insira ID_FILE_PRINT_PREVIEW o modo de visualização de impressão para o documento atual.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CView`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CView::OnFilePrintPreview` Inicia o modo de visualização de impressão chamando a função auxiliar documentadas `CView::DoPrintPreview`. `CView::DoPrintPreview` é o mecanismo principal para o loop de visualização de impressão, assim como `OnFilePrint` é o mecanismo principal para o loop de impressão.

   A operação de visualização de impressão pode ser personalizada em uma variedade de formas, passando parâmetros diferentes para `DoPrintPreview`. Consulte a [30 de observação técnica](../mfc/tn030-customizing-printing-and-print-preview.md), que discute alguns dos detalhes de visualização de impressão e como personalizá-lo.

- ID_FILE_MRU_FILE1... FILE16 Um intervalo de IDs de comando para o arquivo MRU **lista**.

   `CWinApp::OnUpdateRecentFileMenu` é um manipulador de interface do usuário de comando de atualização que é um dos usos mais avançados do mecanismo de ON_UPDATE_COMMAND_UI. Em seu recurso de menu, você só precisa definir um item de menu único com ID ID_FILE_MRU_FILE1. Esse item de menu permanece inicialmente desabilitado.

   Como o MRU da lista cresce, menu mais itens são adicionados à lista. O padrão `CWinApp` implementação padrão é o limite padrão de quatro arquivos usados mais recentemente. Você pode alterar o padrão chamando `CWinApp::LoadStdProfileSettings` com um valor maior ou menor. A lista MRU é armazenada na caixa de diálogo. Arquivo INI. A lista é carregada em seu aplicativo `InitInstance` funcionar se você chamar `LoadStdProfileSettings`e é salvo quando seu aplicativo é encerrado. O manipulador de interface do usuário de comando de atualização MRU também irá converter caminhos absolutos para caminhos relativos para exibição no menu arquivo.

   `CWinApp::OnOpenRecentFile` é o manipulador ON_COMMAND que executa o comando real. Ele simplesmente obtém o nome do arquivo na lista MRU e chamadas `CWinApp::OpenDocumentFile`, que faz todo o trabalho de abertura do arquivo e atualizar a lista MRU.

   Não é recomendável a personalização desse manipulador de comando.

- ID_EDIT_CLEAR limpa a seleção atual

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando usando `CEdit::Clear`. O comando é desabilitado se não houver nenhuma seleção atual.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_CLEAR_ALL limpa todo o documento.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando. Consulte o exemplo de Tutorial do MFC [RABISCO](../visual-cpp-samples.md) para um exemplo de implementação.

- ID_EDIT_COPY copia a seleção atual na área de transferência.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, que copia o texto selecionado atualmente na área de transferência como CF_TEXT usando `CEdit::Copy`. O comando é desabilitado se não houver nenhuma seleção atual.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_CUT Recorta a seleção atual na área de transferência.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, o que reduz o texto selecionado atualmente na área de transferência como CF_TEXT usando `CEdit::Cut`. O comando é desabilitado se não houver nenhuma seleção atual.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- A operação de localização, ID_EDIT_FIND começa abre a caixa de diálogo sem janela restrita.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, que chama a função de auxiliar de implementação `OnEditFindReplace` usar e armazenar as configurações anteriores de localizar/substituir em variáveis de implementação privada. O `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo sem janela restrita para avisar o usuário.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_PASTE insere o conteúdo da área de transferência atual.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, que copia os dados da área de transferência atuais substituindo o texto selecionado usando `CEdit::Paste`. O comando é desativado se não houver nenhuma **CF_TEXT** na área de transferência.

   `COleClientDoc` apenas fornece um manipulador de interface do usuário de comando de atualização para este comando. Se a área de transferência não contiver um item OLE incorporável/objeto, o comando será desabilitado. Você é responsável por escrever o manipulador para o comando real para fazer a colagem real. Se seu aplicativo OLE também pode colar com outros formatos, você deverá fornecer seu próprio manipulador de interface do usuário do comando atualização em seu modo de exibição ou o documento (ou seja, em algum lugar antes `COleClientDoc` no roteamento de destino de comando).

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

   Para substituir a implementação padrão do OLE, use `COleClientItem::CanPaste`.

- ID_EDIT_PASTE_LINK insere um link de conteúdo da área de transferência atual.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `COleDocument` apenas fornece um manipulador de interface do usuário de comando de atualização para este comando. Se a área de transferência não contiver o item/objeto OLE vinculável, o comando será desabilitado. Você é responsável por escrever o manipulador para o comando real para fazer a colagem real. Se seu aplicativo OLE também pode colar com outros formatos, você deverá fornecer seu próprio manipulador de interface do usuário do comando atualização em seu modo de exibição ou o documento (ou seja, em algum lugar antes `COleDocument` no roteamento de destino de comando).

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

   Para substituir a implementação padrão do OLE, use `COleClientItem::CanPasteLink`.

- ID_EDIT_PASTE_SPECIAL insere o conteúdo atual da área de transferência com opções.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada. MFC não oferece essa caixa de diálogo.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_REPEAT repete a última operação.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando para repetir a última operação de localização. As variáveis de implementação privada para a última localização são usadas. O comando será desabilitado se uma localização não pode ser tentada.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- A operação de substituição começa ID_EDIT_REPLACE abre a caixa de diálogo sem janela restrita replace.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, que chama a função de auxiliar de implementação `OnEditFindReplace` usar e armazenar as configurações anteriores de localizar/substituir em variáveis de implementação privada. O `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo sem janela restrita que solicita ao usuário.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_SELECT_ALL seleciona o documento inteiro.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, que seleciona todo o texto no documento. O comando é desabilitado se não houver nenhum texto a ser selecionado.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_UNDO desfaz a última operação.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   `CEditView` Fornece uma implementação desse comando, usando `CEdit::Undo`. O comando será desabilitado se `CEdit::CanUndo` retorna FALSE.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_EDIT_REDO Refaz a última operação.

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para cada `CView`-classe derivada.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- ID_WINDOW_NEW abre outra janela do documento ativo.

   `CMDIFrameWnd::OnWindowNew` implementa esse recurso eficiente, usando o modelo de documento do documento atual para criar outro quadro que contém o outro modo de exibição do documento atual.

   Como a maioria dos vários documentos (interface MDI) comandos do menu janela, o comando é desabilitado se não houver nenhuma janela filho da MDI ativa.

   Não é recomendável a personalização desse manipulador de comando. Se você desejar fornecer um comando que cria exibições adicionais ou janelas de quadro, provavelmente será melhor inventar seu próprio comando. Você pode clonar o código de `CMDIFrameWnd::OnWindowNew` e modificá-lo para as classes específicas de quadro e o modo de exibição de acordo com sua preferência.

- ID_WINDOW_ARRANGE organiza os ícones na parte inferior de uma janela MDI.

   `CMDIFrameWnd` implementa esse comando MDI padrão em uma função auxiliar de implementação `OnMDIWindowCmd`. Esse auxiliar mapeia as IDs de comando para mensagens do Windows MDI e, portanto, pode compartilhar um monte de código.

   Como a maioria dos comandos de menu janela MDI, o comando é desabilitado se não houver nenhuma janela filho da MDI ativa.

   Não é recomendável a personalização desse manipulador de comando.

- Windows ID_WINDOW_CASCADE cascatas para que se sobreponham.

   `CMDIFrameWnd` implementa esse comando MDI padrão em uma função auxiliar de implementação `OnMDIWindowCmd`. Esse auxiliar mapeia as IDs de comando para mensagens do Windows MDI e, portanto, pode compartilhar um monte de código.

   Como a maioria dos comandos de menu janela MDI, o comando é desabilitado se não houver nenhuma janela filho da MDI ativa.

   Não é recomendável a personalização desse manipulador de comando.

- Windows ID_WINDOW_TILE_HORZ lado a lado horizontalmente.

   Esse comando é implementado em `CMDIFrameWnd` como ID_WINDOW_CASCADE, exceto uma mensagem diferente do Windows do MDI é usada para a operação.

   Você deve escolher a orientação de bloco padrão para seu aplicativo. Você pode fazer isso alterando a ID do item de menu janela "Bloco" ID_WINDOW_TILE_HORZ ou ID_WINDOW_TILE_VERT.

- Windows ID_WINDOW_TILE_VERT lado a lado verticalmente.

   Esse comando é implementado em `CMDIFrameWnd` como ID_WINDOW_CASCADE, exceto uma mensagem diferente do Windows do MDI é usada para a operação.

   Você deve escolher a orientação de bloco padrão para seu aplicativo. Você pode fazer isso alterando a ID do item de menu janela "Bloco" ID_WINDOW_TILE_HORZ ou ID_WINDOW_TILE_VERT.

- Interface ID_WINDOW_SPLIT teclado ao divisor.

   `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, esse comando delegará para a função de implementação `CSplitterWnd::DoKeyboardSplit`. Isso colocará o divisor em um modo que permitirá que os usuários de teclado dividir ou reverter uma janela separadora.

   Esse comando estará desabilitado se o modo de exibição não está em um divisor.

   Não é recomendável a personalização desse manipulador de comando.

- ID_APP_ABOUT invoca a caixa de diálogo sobre.

   Não há nenhuma implementação padrão para a caixa de sobre do aplicativo. Aplicativo criado por AppWizard padrão criará uma classe de caixa de diálogo personalizada para seu aplicativo e usá-lo como sua caixa sobre. O AppWizard também irá escrever o manipulador de comandos trivial que lida com esse comando e invoca a caixa de diálogo.

   Quase sempre você irá implementar esse comando.

- ID_APP_EXIT sair do aplicativo.

   `CWinApp::OnAppExit` lida com esse comando, enviando uma mensagem WM_CLOSE à janela principal do aplicativo. O padrão de desligamento do aplicativo (solicitar arquivos sujos e assim por diante) é tratado pelos `CFrameWnd` implementação.

   Não é recomendável a personalização desse manipulador de comando. Substituindo `CWinApp::SaveAllModified` ou o `CFrameWnd` fechar lógica é recomendado.

   Se você optar por implementar esse comando, é recomendável que você use essa ID de comando.

- Tópicos de ID_HELP_INDEX lista ajuda do. Arquivo HLP.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnHelpIndex` lida com esse comando chamando trivialmente `CWinApp::WinHelp`.

   Não é recomendável a personalização desse manipulador de comando.

- ID_HELP_USING exibe ajuda sobre como usar a Ajuda.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnHelpUsing` lida com esse comando chamando trivialmente `CWinApp::WinHelp`.

   Não é recomendável a personalização desse manipulador de comando.

- Modo de ID_CONTEXT_HELP entra SHIFT-F1 Ajuda.

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnContextHelp` lida com esse comando pela definição do cursor do modo de Ajuda, inserindo um loop restrito e esperar que o usuário selecione uma janela para obter ajuda sobre. Consulte a [nota técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação de Ajuda do MFC.

   Não é recomendável a personalização desse manipulador de comando.

- ID_HELP oferece ajuda no contexto atual

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   `CWinApp::OnHelp` lida com esse comando, obtendo o contexto da Ajuda correto para o contexto atual do aplicativo. Ele lida com a Ajuda de F1 simples, ajuda nas caixas de mensagem e assim por diante. Consulte a [nota técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre o MFC implementação da Ajuda.

   Não é recomendável a personalização desse manipulador de comando.

- ID_DEFAULT_HELP exibe a Ajuda padrão contexto

    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado de mapa de mensagens da classe para habilitar essa funcionalidade.

   Geralmente, esse comando é mapeado para `CWinApp::OnHelpIndex`.

   Um manipulador de comandos diferente pode ser fornecido se uma distinção entre ajuda padrão e o índice da Ajuda é desejada.

- ID_NEXT_PANE vai para o próximo painel

   `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, esse comando delegará para a função de implementação `CSplitterWnd::OnNextPaneCmd`. Isso moverá o modo de exibição ativo para o próximo painel no divisor de.

   Esse comando estará desabilitado se o modo de exibição não está em um divisor ou não há nenhum próximo painel para ir para.

   Não é recomendável a personalização desse manipulador de comando.

- ID_PREV_PANE vai para o painel anterior

   `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, esse comando delegará para a função de implementação `CSplitterWnd::OnNextPaneCmd`. Isso moverá o modo de exibição ativo para o painel anterior no divisor de.

   Esse comando estará desabilitado se o modo de exibição não está em um divisor ou não há nenhum painel anterior para ir para.

   Não é recomendável a personalização desse manipulador de comando.

- ID_OLE_INSERT_NEW insere um novo objeto OLE

   Atualmente, não há nenhuma implementação padrão para esse comando. Você deve implementar isso para sua `CView`-derivado da classe para inserir um novo item/objeto OLE na seleção atual.

   Todos os aplicativos de cliente OLE devem implementar esse comando. O AppWizard, com a opção OLE, criará uma implementação esqueleto de `OnInsertObject` em sua classe de exibição que você precisará concluir.

   Consulte a amostra OLE do MFC [OCLIENT](../visual-cpp-samples.md) exemplo para uma implementação completa desse comando.

- Links ID_OLE_EDIT_LINKS edita OLE

   `COleDocument` lida com esse comando usando a implementação fornecida pelo MFC da caixa de diálogo de links OLE padrão. A implementação dessa caixa de diálogo é acessada por meio de `COleLinksDialog` classe. Se o documento atual não contém todos os links, o comando está desabilitado.

   Não é recomendável a personalização desse manipulador de comando.

- ID_OLE_VERB_FIRST... ÚLTIMO intervalo de uma ID para verbos OLE

   `COleDocument` usa esse intervalo de IDs de comando para os verbos com suporte do item OLE selecionado no momento/objeto. Isso deve ser um intervalo, uma vez que um determinado tipo de objeto do item OLE pode dar suporte a zero ou mais verbos personalizados. No menu do seu aplicativo, você deve ter um item de menu com a ID de ID_OLE_VERB_FIRST. Quando o programa é executado, o menu será atualizado com a descrição do verbo de menu apropriado (ou um menu pop-up com verbos muitos). O gerenciamento do menu OLE é tratado pelo `AfxOleSetEditMenu`, feito no manipulador de atualização de comando da interface do usuário para esse comando.

   Não há nenhum manipulador de comando explícito para lidar com cada uma ID de comando nesse intervalo. `COleDocument::OnCmdMsg` é substituído para interceptar todas as IDs de comando nesse intervalo, transformá-los em números de base zero de verbo e iniciar o servidor para esse verbo (usando `COleClientItem::DoVerb`).

   Personalização ou outro uso desse intervalo de ID de comando não é recomendado.

- Ativa e ID_VIEW_TOOLBAR desativa a barra de ferramentas

   `CFrameWnd` lida com esse comando e o manipulador de comando de atualização da interface do usuário para alternar o estado de visibilidade da barra de ferramentas. A barra de ferramentas deve ser uma janela filho do quadro com a janela filho da ID de AFX_IDW_TOOLBAR. O manipulador de comandos, na verdade, alterna a visibilidade da janela de ferramentas. `CFrameWnd::RecalcLayout` é usado para redesenhar a janela do quadro com a barra de ferramentas em seu estado novo. O manipulador de interface do usuário do comando de atualização verifica o item de menu quando a barra de ferramentas está visível.

   Não é recomendável a personalização desse manipulador de comando. Se você quiser adicionar barras de ferramentas, você desejará clonar e modifique o manipulador de comandos e o manipulador de interface do usuário do comando de atualização para este comando.

- ID_VIEW_STATUS_BAR alterna a barra de status ativado e desativado

   Esse comando é implementado no `CFrameWnd` assim ID_VIEW_TOOLBAR, exceto uma janela filho diferente da ID (AFX_IDW_STATUS_BAR) é usado.

## <a name="update-only-command-handlers"></a>Manipuladores de comando Update-Only

Várias IDs de comando padrão são usadas como indicadores em barras de status. Eles usam o mesmo comando de atualização de interface do usuário do mecanismo de tratamento para exibir seu estado atual de visual durante o tempo ocioso do aplicativo. Uma vez que eles não podem ser selecionados pelo usuário (ou seja, não é possível enviar um painel da barra de status), em seguida, ele não faz sentido ter um manipulador ON_COMMAND para essas IDs de comando.

- ID_INDICATOR_CAPS : Indicador de bloqueio de limite.

- ID_INDICATOR_NUM : Indicador de bloqueio NUM.

- ID_INDICATOR_SCRL: Indicador de bloqueio SCRL.

- ID_INDICATOR_KANA : Indicador (aplicável apenas aos sistemas japonês) de bloqueio de KANA.

Todos os três seguintes são implementadas no `CFrameWnd::OnUpdateKeyIndicator`, um auxiliar de implementação que usa a ID de comando para mapear para a chave Virtual apropriada. Uma implementação comum habilita ou desabilita (para painéis de status desabilitados não = nenhum texto) a `CCmdUI` objeto dependendo se a chave Virtual apropriado está bloqueada no momento.

Não é recomendável a personalização desse manipulador de comando.

- ID_INDICATOR_EXT: Selecionar indicador estendido.

- ID_INDICATOR_OVR: Indicador de sobreposição.

- ID_INDICATOR_REC : Indicador de gravação.

Atualmente, não há nenhuma implementação padrão para esses indicadores.

Se você optar por implementar esses indicadores, recomendamos que você use essas IDs de indicador e manter a ordenação dos indicadores na barra de status (ou seja, nesta ordem: EXT, CAP, NUM, SCRL, SE, REC).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
