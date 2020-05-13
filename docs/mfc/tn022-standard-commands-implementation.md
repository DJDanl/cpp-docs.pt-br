---
title: 'TN022: implementação de comandos padrão'
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
ms.openlocfilehash: 5c7041f40c7e30592f642d29d9d02812a9596864
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370390"
---
# <a name="tn022-standard-commands-implementation"></a>TN022: implementação de comandos padrão

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve as implementações de comando padrão fornecidas pelo MFC 2.0. Leia [a Nota Técnica 21](../mfc/tn021-command-and-message-routing.md) primeiro porque descreve os mecanismos usados para implementar muitos dos comandos padrão.

Esta descrição assume o conhecimento das arquiteturas MFC, APIs e prática de programação comum. São descritas APIs documentadas e não documentadas "somente de implementação". Este não é um lugar para começar a aprender sobre os recursos ou como programar em MFC. Consulte o Visual C++ para obter informações mais gerais e para obter detalhes de APIs documentadas.

## <a name="the-problem"></a>O problema

O MFC define muitos IDs de comando padrão no arquivo de cabeçalho AFXRES. H. O suporte-quadro para esses comandos varia. Entender onde e como as classes-estrutura lidam com esses comandos não só mostrará como a estrutura funciona internamente, mas fornecerá informações úteis sobre como personalizar as implementações padrão e ensinar-lhe algumas técnicas para implementar seus próprios manipuladores de comando.

## <a name="contents-of-this-technical-note"></a>Conteúdo desta Nota Técnica

Cada ID de comando é descrito em duas seções:

- O título: o nome simbólico do comando ID (por exemplo, ID_FILE_SAVE) seguido pelo propósito do comando (por exemplo, "salva o documento atual") separado por um cólon.

- Um ou mais parágrafos descrevendo quais classes implementam o comando e o que a implementação padrão faz

A maioria das implementações de comando padrão são pré-conectadas no mapa de mensagens de classe base do framework. Existem algumas implementações de comando que requerem fiação explícita em sua classe derivada. Estes são descritos em "Nota". Se você escolheu as opções certas no AppWizard, esses manipuladores padrão serão conectados para você no aplicativo esqueleto gerado.

## <a name="naming-convention"></a>Convenção de nomenclatura

Os comandos padrão seguem uma convenção de nomeação simples que recomendamos que você use, se possível. A maioria dos comandos padrão estão localizados em lugares padrão na barra de menus de um aplicativo. O nome simbólico do comando começa com "ID_" seguido do nome padrão do menu pop-up, seguido pelo nome do item do menu. O nome simbólico está em maiúsculas com quebras de palavras sublinhadas. Para comandos que não possuem nomes de item de menu padrão, um nome de comando lógico é definido a partir de "ID_" (por exemplo, ID_NEXT_PANE).

Usamos o prefixo "ID_" para indicar comandos projetados para serem vinculados a itens de menu, botões de barra de ferramentas ou outros objetos de interface de usuário de comando. Os manipuladores de comando que lidam com comandos "ID_" devem usar os mecanismos ON_COMMAND e ON_UPDATE_COMMAND_UI da arquitetura de comando MFC.

Recomendamos que você use o prefixo padrão "IDM_" para itens de menu que não seguem a arquitetura de comando e precisam de código específico do menu para habilitá-los e desativá-los. É claro que o número de comandos específicos do menu deve ser pequeno, uma vez que seguir a arquitetura de comando SMFC não só torna os manipuladores de comandomais poderosos (já que eles trabalharão com barras de ferramentas), mas torna o código do manipulador de comandoreutilizável.

## <a name="id-ranges"></a>Faixas de ID

Consulte a [Nota Técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md) para obter mais detalhes sobre o uso de faixas de ID em MFC.

Os comandos padrão MFC caem na faixa 0xE000 a 0xEFFF. Por favor, não confie nos valores específicos desses IDs, uma vez que eles estão sujeitos a alterações em versões futuras da biblioteca.

Sua aplicação deve definir seus comandos na faixa 0x8000 a 0xDFFF.

## <a name="standard-command-ids"></a>IDs de comando padrão

Para cada ID de comando, há uma seqüência de prompt de linha de mensagem padrão que pode ser encontrada no arquivo PROMPTS. Rc. O ID de seqüência para esse prompt de menu deve ser o mesmo do ID de comando.

- ID_FILE_NEW Cria um documento novo/vazio.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnFileNew`implementa este comando de forma diferente, dependendo do número de modelos de documento no aplicativo. Se houver apenas `CDocTemplate` `CWinApp::OnFileNew` um, criará um novo documento desse tipo, bem como a classe de quadro e visualização adequada.

   Se houver mais `CDocTemplate`de `CWinApp::OnFileNew` um , solicitará ao usuário uma caixa de diálogo (AFX_IDD_NEWTYPEDLG) permitindo que ele selecione qual tipo de documento usar. O `CDocTemplate` selecionado é usado para criar o documento.

   Uma personalização comum de ID_FILE_NEW é fornecer uma escolha diferente e mais gráfica dos tipos de documentos. Neste caso, você pode `CMyApp::OnFileNew` implementar o seu próprio `CWinApp::OnFileNew`e colocá-lo em seu mapa de mensagem em vez de . Não há necessidade de chamar a implementação da classe base.

   Outra personalização comum de ID_FILE_NEW é fornecer um comando separado para a criação de um documento de cada tipo. Neste caso, você deve definir novos IDs de comando, por exemplo, ID_FILE_NEW_CHART e ID_FILE_NEW_SHEET.

- ID_FILE_OPEN Abre um documento existente.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnFileOpen`tem uma implementação `CWinApp::DoPromptFileName` muito `CWinApp::OpenDocumentFile` simples de chamada seguida com o arquivo ou nome do caminho do arquivo para abrir. A `CWinApp` rotina `DoPromptFileName` de implementação traz à tona a caixa de diálogo FileOpen padrão e preenche-a com as extensões de arquivo obtidas dos modelos atuais do documento.

   Uma personalização comum de ID_FILE_OPEN é personalizar a caixa de diálogo FileOpen ou adicionar filtros de arquivo adicionais. A maneira recomendada de personalizá-lo é substituir a implementação `CWinApp::OpenDocumentFile` padrão por sua própria caixa de diálogo FileOpen e ligar com o nome do arquivo ou do caminho do documento. Não há necessidade de chamar a classe base.

- ID_FILE_CLOSE fecha o documento atualmente aberto.

   `CDocument::OnFileClose`chamadas `CDocument::SaveModified` para solicitar ao usuário para salvar o documento `OnCloseDocument`se ele foi modificado e, em seguida, chamadas . Toda a lógica de fechamento, incluindo a `OnCloseDocument` destruição do documento, é feita na rotina.

    > [!NOTE]
    >  ID_FILE_CLOSE age de forma diferente de uma mensagem de WM_CLOSE ou de um comando de sistema de SC_CLOSE enviado para a janela de quadro de documentos. Fechar uma janela só fechará o documento se essa for a última janela do quadro mostrando o documento. Fechar o documento com ID_FILE_CLOSE não só fechará o documento como fechará todas as janelas do quadro mostrando o documento.

- ID_FILE_SAVE Salva o documento atual.

   A implementação utiliza `CDocument::DoSave` uma rotina auxiliar `OnFileSave` `OnFileSaveAs`que é usada para ambos e . Se você salvar um documento que não tenha sido salvo antes (ou seja, ele não tem um nome de caminho, `OnFileSave` como no caso do FileNew) ou que foi lido a partir de um documento somente leitura, a lógica agirá como o comando ID_FILE_SAVE_AS e pedirá ao usuário para fornecer um novo nome de arquivo. O processo real de abrir o arquivo e fazer `OnSaveDocument`a poupança é feito através da função virtual.

   Há duas razões comuns para personalizar ID_FILE_SAVE. Para documentos que não salvam, basta remover os itens do menu ID_FILE_SAVE e botões da barra de ferramentas da interface do usuário. Certifique-se também de que você nunca sujar seu documento (ou seja, nunca ligar) `CDocument::SetModifiedFlag`e a estrutura nunca fará com que o documento seja salvo. Para documentos que sejam exceto em outro lugar que não um arquivo de disco, defina um novo comando para essa operação.

   No caso de `COleServerDoc`um , ID_FILE_SAVE é usado tanto para salvamento de arquivos (para documentos normais) quanto para atualização de arquivo (para documentos incorporados).

   Se os dados do documento forem armazenados em arquivos de `CDocument` disco individuais, mas `CDocument::OnSaveDocument` você `OnFileSave`não quiser usar a implementação serialize padrão, você deve substituir em vez de .

- ID_FILE_SAVE_AS Salva o documento atual com um nome de arquivo diferente.

   A `CDocument::OnFileSaveAs` implementação `CDocument::DoSave` utiliza a `OnFileSave`mesma rotina auxiliar que . O `OnFileSaveAs` comando é tratado da mesmo ID_FILE_SAVE se os documentos não tivessem o nome do arquivo antes da salvação. `COleServerDoc::OnFileSaveAs`implementa a lógica para salvar um arquivo de dados de documento normal ou salvar um documento de servidor representando um objeto OLE incorporado em algum outro aplicativo como um arquivo separado.

   Se você personalizar a lógica de ID_FILE_SAVE, provavelmente você vai querer personalizar ID_FILE_SAVE_AS de forma semelhante ou a operação de "Save As" pode não se aplicar ao seu documento. Você pode remover o item do menu da barra de menu se não for necessário.

- ID_FILE_SAVE_COPY_AS Salva um documento atual de cópia com um novo nome.

   A `COleServerDoc::OnFileSaveCopyAs` implementação é `CDocument::OnFileSaveAs`muito semelhante, exceto que o objeto do documento não está "anexado" ao arquivo subjacente após a salvação. Ou seja, se o documento na memória foi "modificado" antes do salvamento, ele ainda é "modificado". Além disso, este comando não tem efeito sobre o nome do caminho ou título armazenado no documento.

- ID_FILE_UPDATE Notifica o contêiner para salvar um documento incorporado.

   A `COleServerDoc::OnUpdateDocument` implementação simplesmente notifica o contêiner de que a incorporação deve ser salva. Em seguida, o contêiner chama as APIs OLE apropriadas para salvar o objeto incorporado.

- ID_FILE_PAGE_SETUP Invoca uma configuração/diálogo de layout de página específica do aplicativo.

   Atualmente não há um padrão para este diálogo, e o framework não tem implementação padrão deste comando.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_FILE_PRINT_SETUP Invocar a caixa de diálogo configuração de impressão padrão.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   Este comando invoca a caixa de diálogo de configuração de impressão padrão que permite ao usuário personalizar as configurações de impressora e impressão para pelo menos este documento ou, no máximo, todos os documentos deste aplicativo. Você deve usar o Painel de Controle para alterar as configurações padrão da impressora para todo o sistema.

   `CWinApp::OnFilePrintSetup`tem uma implementação `CPrintDialog` muito simples `CWinApp::DoPrintDialog` criando um objeto e chamando a função de implementação. Isso define a configuração da impressora padrão do aplicativo.

   A necessidade comum de personalizar este comando é permitir as configurações da impressora por documento, que devem ser armazenadas com o documento quando salvas. Para fazer isso, você deve adicionar `CDocument` um manipulador `CPrintDialog` de mapa de mensagem em sua classe que cria um objeto, inicializá-lo com os atributos de impressora apropriados (geralmente *hDevMode* e *hDevNames),* chamar o `CPrintDialog::DoModal`e salvar as configurações da impressora alteradas. Para uma implementação robusta, você `CWinApp::DoPrintDialog` deve olhar para `CWinApp::UpdatePrinterSelection` a implementação de erros de detecção e para lidar com padrões sensíveis e rastrear alterações de impressora em todo o sistema.

- impressão padrão ID_FILE_PRINT do documento atual

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CView`classe derivada para habilitar essa funcionalidade.

   Este comando imprime o documento atual, ou mais corretamente, inicia o processo de impressão, que envolve invocar a caixa de diálogo de impressão padrão e executar o mecanismo de impressão.

   `CView::OnFilePrint`implementa este comando e o loop de impressão principal. Ele chama `CView::OnPreparePrinting` o virtual para solicitar o usuário com a caixa de diálogo de impressão. Em seguida, ele prepara a saída DC para ir para a impressora, traz a caixa de diálogo de progresso de impressão (AFX_IDD_PRINTDLG) e envia a `StartDoc` fuga para a impressora. `CView::OnFilePrint`também contém o loop de impressão orientado à página principal. Para cada página, ele `CView::OnPrepareDC` chama `StartPage` o virtual seguido `CView::OnPrint` de uma fuga e chamando o virtual para essa página. Quando concluído, `CView::OnEndPrinting` o virtual é chamado e a caixa de diálogo de progresso de impressão é fechada.

   A arquitetura de impressão MFC foi projetada para enganchar de muitas maneiras diferentes para impressão e visualização de impressão. Você normalmente encontrará `CView` as várias funções superridíveis adequadas para quaisquer tarefas de impressão orientadas a páginas. Somente no caso de um aplicativo que usa a impressora para saída orientada a não-página, caso você encontre a necessidade de substituir a implementação ID_FILE_PRINT.

- ID_FILE_PRINT_PREVIEW Digite o modo de visualização de impressão para o documento atual.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CView`classe derivada para habilitar essa funcionalidade.

   `CView::OnFilePrintPreview`inicia o modo de visualização de `CView::DoPrintPreview`impressão chamando a função de ajudante documentada . `CView::DoPrintPreview`é o motor principal para o `OnFilePrint` loop de visualização de impressão, assim como é o motor principal para o loop de impressão.

   A operação de visualização de impressão pode ser personalizada `DoPrintPreview`de várias maneiras, passando diferentes parâmetros para . Consulte a [Nota Técnica 30,](../mfc/tn030-customizing-printing-and-print-preview.md)que discute alguns detalhes da visualização de impressão e como personalizá-la.

- ID_FILE_MRU_FILE1... FILE16 Uma gama de IDs de comando para a **lista**File MRU .

   `CWinApp::OnUpdateRecentFileMenu`é um manipulador de ia de comando de atualização que é um dos usos mais avançados do mecanismo ON_UPDATE_COMMAND_UI. No recurso do menu, você só precisa definir um único item do menu com id ID_FILE_MRU_FILE1. Esse item do menu permanece inicialmente desativado.

   À medida que a lista mru cresce, mais itens do menu são adicionados à lista. A `CWinApp` implementação padrão é padrão para o limite padrão dos quatro arquivos usados mais recentemente. Você pode alterar o `CWinApp::LoadStdProfileSettings` padrão ligando com um valor maior ou menor. A lista MRU é armazenada na do aplicativo . Arquivo INI. A lista é carregada na `InitInstance` função do `LoadStdProfileSettings`aplicativo se você ligar e é salva quando o aplicativo sai. O manipulador de ui de atualização mru também converterá caminhos absolutos para caminhos relativos para exibição no menu do arquivo.

   `CWinApp::OnOpenRecentFile`é o manipulador ON_COMMAND que executa o comando real. Ele simplesmente obtém o nome do `CWinApp::OpenDocumentFile`arquivo da lista mru e chamadas , que faz todo o trabalho de abrir o arquivo e atualizar a lista MRU.

   A personalização deste manipulador de comandos não é recomendada.

- ID_EDIT_CLEAR limpa a seleção atual

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação `CEdit::Clear`deste comando usando . O comando é desativado se não houver seleção atual.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_CLEAR_ALL limpa todo o documento.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando. Consulte a amostra de Tutorial do MFC [SCRIBBLE](../overview/visual-cpp-samples.md) para obter um exemplo de implementação.

- ID_EDIT_COPY Copia a seleção atual para a Área de Transferência.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que copia o texto selecionado `CEdit::Copy`na área de transferência como CF_TEXT usando . O comando é desativado se não houver seleção atual.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_CUT Corta a seleção atual para a Área de Transferência.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que corta o texto selecionado `CEdit::Cut`na área de transferência como CF_TEXT usando . O comando é desativado se não houver seleção atual.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_FIND Começa a operação encontrar, traz à tona a modelagem encontrar diálogo.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que `OnEditFindReplace` chama a função de ajudante de implementação para usar e armazenar as configurações anteriores de encontrar/substituir em variáveis de implementação privadas. A `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo modeless para solicitar o usuário.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_PASTE Insere o conteúdo atual da área de transferência.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que copia os dados `CEdit::Paste`atuais da Área de Transferência substituindo o texto selecionado usando . O comando é desativado se não houver **CF_TEXT** na Área de Transferência.

   `COleClientDoc`apenas fornece um manipulador de ui de comando de atualização para este comando. Se a Área de Transferência não contiver um item/objeto OLE incorporável, o comando será desativado. Você é responsável por escrever o manipulador para o comando real para fazer a colagem real. Se o aplicativo OLE também puder colar outros formatos, você deve fornecer seu próprio manipulador de `COleClientDoc` interface do usuário de comando de atualização na sua exibição ou documento (ou seja, em algum lugar antes no roteamento de destino de comando).

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

   Para substituir a implementação padrão `COleClientItem::CanPaste`do OLE, use .

- ID_EDIT_PASTE_LINK Insere um link do conteúdo atual da área de transferência.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `COleDocument`apenas fornece um manipulador de ui de comando de atualização para este comando. Se a Área de Transferência não contiver item/objeto OLE vinculável, o comando será desativado. Você é responsável por escrever o manipulador para o comando real para fazer a colagem real. Se o aplicativo OLE também puder colar outros formatos, você deve fornecer seu próprio manipulador de `COleDocument` interface do usuário de comando de atualização na sua exibição ou documento (ou seja, em algum lugar antes no roteamento de destino de comando).

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

   Para substituir a implementação padrão `COleClientItem::CanPasteLink`do OLE, use .

- ID_EDIT_PASTE_SPECIAL Insere o conteúdo atual da área de transferência com opções.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada. O MFC não fornece este diálogo.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_REPEAT repete a última operação.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando para repetir a última operação de encontrar. As variáveis de implementação privada para o último achado são utilizadas. O comando é desativado se um achado não puder ser tentado.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_REPLACE Inicia a operação de substituição, traz a modeless a substituir o diálogo.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que `OnEditFindReplace` chama a função de ajudante de implementação para usar e armazenar as configurações anteriores de encontrar/substituir em variáveis de implementação privadas. A `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo modeless que solicita ao usuário.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_SELECT_ALL Seleciona o documento inteiro.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste comando, que seleciona todo o texto no documento. O comando é desativado se não houver texto para selecionar.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_UNDO desfaz a última operação.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   `CEditView`fornece uma implementação deste `CEdit::Undo`comando, usando . O comando é `CEdit::CanUndo` desativado se retornar FALSO.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_EDIT_REDO refaz a última operação.

   Atualmente não há implementação padrão para este comando. Você deve implementar `CView`isso para cada classe derivada.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_WINDOW_NEW Abre outra janela no documento ativo.

   `CMDIFrameWnd::OnWindowNew`implementa esse recurso poderoso usando o modelo de documento do documento atual para criar outro quadro contendo outra visão do documento atual.

   Como a maioria dos comandos de menu de janela de interface de documento múltiplo (MDI), o comando será desativado se não houver uma janela de criança MDI ativa.

   A personalização deste manipulador de comandos não é recomendada. Se você deseja fornecer um comando que crie visualizações adicionais ou janelas de quadro, provavelmente será melhor inventar seu próprio comando. Você pode clonar `CMDIFrameWnd::OnWindowNew` o código e modificá-lo para o quadro específico e visualizar classes de seu gosto.

- ID_WINDOW_ARRANGE Organize ícones na parte inferior de uma janela MDI.

   `CMDIFrameWnd`implementa este comando MDI padrão em `OnMDIWindowCmd`uma função auxiliar de implementação . Este ajudante mapeia iDs de comando para mensagens MDI Windows e, portanto, pode compartilhar um monte de código.

   Como a maioria dos comandos do menu de janela mdi, o comando é desativado se não houver janela de criança MDI ativa.

   A personalização deste manipulador de comandos não é recomendada.

- ID_WINDOW_CASCADE cascades janelas para que eles se sobreponham.

   `CMDIFrameWnd`implementa este comando MDI padrão em `OnMDIWindowCmd`uma função auxiliar de implementação . Este ajudante mapeia iDs de comando para mensagens MDI Windows e, portanto, pode compartilhar um monte de código.

   Como a maioria dos comandos do menu de janela mdi, o comando é desativado se não houver janela de criança MDI ativa.

   A personalização deste manipulador de comandos não é recomendada.

- ID_WINDOW_TILE_HORZ janelas de telhas horizontalmente.

   Este comando é `CMDIFrameWnd` implementado em apenas ID_WINDOW_CASCADE, exceto que uma mensagem Diferente do Windows MDI é usada para a operação.

   Você deve escolher a orientação padrão de azulejo para sua aplicação. Você pode fazer isso alterando o ID para o item do menu "Tile" da janela para ID_WINDOW_TILE_HORZ ou ID_WINDOW_TILE_VERT.

- ID_WINDOW_TILE_VERT as janelas de telhas verticalmente.

   Este comando é `CMDIFrameWnd` implementado em apenas ID_WINDOW_CASCADE, exceto que uma mensagem Diferente do Windows MDI é usada para a operação.

   Você deve escolher a orientação padrão de azulejo para sua aplicação. Você pode fazer isso alterando o ID para o item do menu "Tile" da janela para ID_WINDOW_TILE_HORZ ou ID_WINDOW_TILE_VERT.

- ID_WINDOW_SPLIT interface do teclado para divisor.

   `CView`lida com este `CSplitterWnd` comando para a implementação. Se a exibição for parte de uma janela de `CSplitterWnd::DoKeyboardSplit`divisor, este comando será delegado para a função de implementação . Isso colocará o divisor em um modo que permitirá que os usuários do teclado dividam ou desdividem uma janela de divisor.

   Este comando é desativado se a exibição não estiver em um divisor.

   A personalização deste manipulador de comandos não é recomendada.

- ID_APP_ABOUT Invoca a caixa de diálogo Sobre.

   Não há implementação padrão para a caixa Sobre um aplicativo. O aplicativo criado pelo AppWizard padrão criará uma classe de diálogo personalizada para o seu aplicativo e o usará como sua caixa Sobre. O AppWizard também escreverá o manipulador de comando trivial que lida com este comando e invoca a caixa de diálogo.

   Você quase sempre implementará este comando.

- ID_APP_EXIT Sair do aplicativo.

   `CWinApp::OnAppExit`lida com este comando enviando uma mensagem WM_CLOSE para a janela principal do aplicativo. O desligamento padrão do aplicativo (solicitando arquivos sujos e assim `CFrameWnd` por diante) é tratado pela implementação.

   A personalização deste manipulador de comandos não é recomendada. Recomenda-se a substituição `CWinApp::SaveAllModified` ou a `CFrameWnd` lógica de fechamento.

   Se você optar por implementar este comando, recomendamos que você use este ID de comando.

- ID_HELP_INDEX lista tópicos de ajuda de . Arquivo HLP.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnHelpIndex`lida com este comando `CWinApp::WinHelp`chamando trivialmente .

   A personalização deste manipulador de comandos não é recomendada.

- ID_HELP_USING Exibe ajuda em como usar a Ajuda.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnHelpUsing`lida com este comando `CWinApp::WinHelp`chamando trivialmente .

   A personalização deste manipulador de comandos não é recomendada.

- ID_CONTEXT_HELP entra no modo de ajuda SHIFT-F1.

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnContextHelp`manipula este comando definindo o cursor do modo de ajuda, digitando um loop modal e esperando que o usuário selecione uma janela para obter ajuda. Consulte a [Nota Técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação da Ajuda MFC.

   A personalização deste manipulador de comandos não é recomendada.

- ID_HELP ajuda no contexto atual

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   `CWinApp::OnHelp`lida com este comando, obtendo o contexto de ajuda certo para o contexto atual do aplicativo. Isso lida com simples ajuda de F1, ajuda em caixas de mensagens e assim por diante. Consulte a [Nota Técnica 28](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação da ajuda do MFC.

   A personalização deste manipulador de comandos não é recomendada.

- ID_DEFAULT_HELP exibe ajuda padrão para contexto

    > [!NOTE]
    >  Você deve conectá-lo ao mapa de mensagens da sua `CWinApp`classe derivada para habilitar essa funcionalidade.

   Este comando é geralmente `CWinApp::OnHelpIndex`mapeado para .

   Um manipulador de comando diferente pode ser fornecido se uma distinção entre ajuda padrão e o índice de ajuda for desejada.

- ID_NEXT_PANE Vai para o próximo painel

   `CView`lida com este `CSplitterWnd` comando para a implementação. Se a exibição for parte de uma janela de `CSplitterWnd::OnNextPaneCmd`divisor, este comando será delegado para a função de implementação . Isso moverá a visão ativa para o próximo painel no divisor.

   Este comando é desativado se a exibição não estiver em um divisor ou não houver um próximo painel para ir.

   A personalização deste manipulador de comandos não é recomendada.

- ID_PREV_PANE Vai para o painel anterior

   `CView`lida com este `CSplitterWnd` comando para a implementação. Se a exibição for parte de uma janela de `CSplitterWnd::OnNextPaneCmd`divisor, este comando será delegado para a função de implementação . Isso moverá a exibição ativa para o painel anterior no divisor.

   Este comando é desativado se a exibição não estiver em um divisor ou não houver um painel anterior para ir.

   A personalização deste manipulador de comandos não é recomendada.

- ID_OLE_INSERT_NEW Insere um novo objeto OLE

   Atualmente não há implementação padrão para este comando. Você deve implementá-lo para sua `CView`classe derivada para inserir um novo item/objeto OLE na seleção atual.

   Todos os aplicativos clientes OLE devem implementar este comando. O AppWizard, com a opção OLE, `OnInsertObject` criará uma implementação de esqueleto na sua classe de visualização que você terá que completar.

   Consulte o exemplo oCLIENT de amostra [MFC](../overview/visual-cpp-samples.md) OLE para uma implementação completa deste comando.

- ID_OLE_EDIT_LINKS edições de links OLE

   `COleDocument`lida com este comando usando a implementação fornecida pelo MFC da caixa de diálogo de links OLE padrão. A implementação deste diálogo é `COleLinksDialog` acessada através da classe. Se o documento atual não contiver nenhum link, o comando será desativado.

   A personalização deste manipulador de comandos não é recomendada.

- ID_OLE_VERB_FIRST... ÚLTIMA faixa de ID para verbos OLE

   `COleDocument`usa este intervalo de ID de comando para os verbos suportados pelo item/objeto OLE atualmente selecionado. Este deve ser um intervalo, uma vez que um determinado tipo de item/objeto OLE pode suportar verbos zero ou mais personalizados. No menu do seu aplicativo, você deve ter um item de menu com o ID de ID_OLE_VERB_FIRST. Quando o programa for executado, o menu será atualizado com a descrição do verbo do menu apropriado (ou menu pop-up com muitos verbos). O gerenciamento do menu OLE `AfxOleSetEditMenu`é tratado por , feito no manipulador de ida de ui de comando de atualização para este comando.

   Não há manipuladores de comando explícitos para manusear cada um dos ID de comando neste intervalo. `COleDocument::OnCmdMsg`é substituído para prender todos os IDs de comando nesta faixa, transformá-los em números verbos baseados em zero e iniciar o servidor para esse verbo (usando `COleClientItem::DoVerb`).

   A personalização ou outro uso deste intervalo de ID de comando não é recomendado.

- ID_VIEW_TOOLBAR alterna a barra de ferramentas ligado e desligado

   `CFrameWnd`lida com este comando e o manipulador de ui de comando de atualização para alternar o estado visível da barra de ferramentas. A barra de ferramentas deve ser uma janela infantil do quadro com o ID da janela da criança de AFX_IDW_TOOLBAR. O manipulador de comando realmente alterna a visibilidade da janela da barra de ferramentas. `CFrameWnd::RecalcLayout`é usado para redesenhar a janela do quadro com a barra de ferramentas em seu novo estado. O manipulador de ia de comando de atualização verifica o item do menu quando a barra de ferramentas está visível.

   A personalização deste manipulador de comandos não é recomendada. Se você deseja adicionar barras de ferramentas adicionais, você vai querer clonar e modificar o manipulador de comando e o manipulador de iu de comando de atualização para este comando.

- ID_VIEW_STATUS_BAR Alterna a barra de status ligado e desligado

   Este comando é `CFrameWnd` implementado em apenas ID_VIEW_TOOLBAR, exceto que um ID de janela de criança diferente (AFX_IDW_STATUS_BAR) é usado.

## <a name="update-only-command-handlers"></a>Manipuladores de comando somente para atualização

Vários IDs de comando padrão são usados como indicadores em barras de status. Estes usam o mesmo mecanismo de manipulação de interface do rei do comando de atualização para exibir seu estado visual atual durante o tempo ocioso do aplicativo. Uma vez que eles não podem ser selecionados pelo usuário (ou seja, você não pode empurrar um painel de barra de status), então não faz sentido ter um manipulador de ON_COMMAND para esses IDs de comando.

- ID_INDICATOR_CAPS : Indicador de bloqueio de CAP.

- ID_INDICATOR_NUM : Indicador de bloqueio NUM.

- ID_INDICATOR_SCRL : Indicador de bloqueio SCRL.

- ID_INDICATOR_KANA : indicador de bloqueio KANA (aplicável apenas aos sistemas japoneses).

Todos os três são `CFrameWnd::OnUpdateKeyIndicator`implementados em , um ajudante de implementação que usa o ID de comando para mapear para a Chave Virtual apropriada. Uma implementação comum habilita ou desativa (para `CCmdUI` painéis de status desativados = sem texto) o objeto, dependendo se a Chave Virtual apropriada está bloqueada no momento.

A personalização deste manipulador de comandos não é recomendada.

- ID_INDICATOR_EXT : Indicador de seleção EXTended.

- ID_INDICATOR_OVR : Indicador OVeRstrike.

- ID_INDICATOR_REC : Indicador RECording.

Atualmente não há uma implementação padrão para esses indicadores.

Se você optar por implementar esses indicadores, recomendamos que você use esses IDs indicadores e mantenha a encomenda dos indicadores em sua barra de status (ou seja, nesta ordem: EXT, CAP, NUM, SCRL, OVR, REC).

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
