---
title: 'TN022: Implementação de comandos de padrão | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.commands
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dea42f4bd33281e65696791677bdd81a921a59e6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33385519"
---
# <a name="tn022-standard-commands-implementation"></a>TN022: implementação de comandos padrão
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve as implementações de comando padrão fornecidas pelo MFC 2.0. Leitura [21 de observação técnica](../mfc/tn021-command-and-message-routing.md) primeiro porque ele descreve os mecanismos usados para implementar a muitos dos comandos padrão.  
  
 Essa descrição pressupõe conhecimento do MFC arquiteturas, APIs e prática de programação comum. Documentadas, bem como não documentada "implementação somente" APIs são descritas. Isso não é um lugar para começar a aprender sobre os recursos do ou como programar em MFC. Consulte Visual C++ para obter mais informações e para obter detalhes sobre as APIs documentadas.  
  
## <a name="the-problem"></a>O problema  
 MFC define muitas IDs de comando padrão no arquivo de cabeçalho AFXRES. H. Suporte do Framework para esses comandos varia. Noções básicas sobre onde e como as classes do framework lidar com esses comandos não só mostrará como o framework funciona internamente, mas fornece informações úteis sobre como personalizar as implementações padrão e ensinar a você algumas técnicas para implementar seus próprios manipuladores de comandos.  
  
## <a name="contents-of-this-technical-note"></a>Conteúdo desta nota técnica  
 Cada ID de comando é descrita em duas seções:  
  
-   Título: o nome simbólico da ID de comando (por exemplo, **ID_FILE_SAVE**) seguido a finalidade do comando (por exemplo, "salva o documento atual") separado por dois-pontos.  
  
-   Um ou mais parágrafos que descreve quais classes implementam o comando e o que faz a implementação padrão  
  
 A maioria das implementações de comando padrão são prewired no mapa de mensagem de classe base da estrutura. Há algumas implementações de comando que exigem a fiação explícita em sua classe derivada. Elas são descritas em "Note". Se você escolher as opções corretas na AppWizard, esses manipuladores padrão serão conectados no aplicativo de esqueleto gerado para você.  
  
## <a name="naming-convention"></a>Convenção de nomenclatura  
 Comandos padrão seguem uma convenção de nomenclatura simple, recomendamos que você use, se possível. Comandos mais padrão estão localizados em locais padrão na barra de menus do aplicativo. O nome simbólico do comando começa com "ID _" seguido pelo nome do menu pop-up padrão, seguido do nome do item de menu. O nome simbólico está em letras maiusculas com quebras de palavras de sublinhado. Para comandos que não têm nomes de itens de menu padrão, um nome de comando lógico é definido começando com ID "_" (por exemplo, **ID_NEXT_PANE**).  
  
 Usamos o prefixo de "ID _" para indicar os comandos que são projetados para ser associado a itens de menu, botões da barra de ferramentas ou outros objetos de interface do usuário do comando. Manipuladores de comandos manipulando comandos "ID _" devem usar o `ON_COMMAND` e `ON_UPDATE_COMMAND_UI` mecanismos de classes de arquitetura de comando.  
  
 Recomendamos que você use o prefixo "IDM_" padrão de itens de menu que não seguem a arquitetura de comando e precisar de código específico do menu para habilitar e desabilitá-las. É claro o número de comandos específicos do menu deve ser pequeno porque a arquitetura do MFC comando a seguir não apenas torna os manipuladores de comando mais eficiente (já que eles funcionarão com barras de ferramentas), mas faz com que o código de manipulador de comando reutilizável.  
  
## <a name="id-ranges"></a>Intervalos de ID  
 Consulte [20 de observação técnica](../mfc/tn020-id-naming-and-numbering-conventions.md) para obter mais detalhes sobre o uso de intervalos de ID em MFC.  
  
 Comandos padrão do MFC estão no intervalo 0xE000 para 0xEFFF. Não confie nos valores específicos dessas IDs porque eles estão sujeitos a alterações em versões futuras da biblioteca.  
  
 Seu aplicativo deve definir seus comandos no intervalo 0x8000 a 0xDFFF.  
  
## <a name="standard-command-ids"></a>IDs de comando padrão  
 Para cada ID de comando, há uma sequência de prompt de linha de mensagem padrão que pode ser encontrada nos PROMPTS de arquivo. RC. A ID de cadeia de caracteres para o prompt menu deve ser o mesmo para a ID de comando.  
  
-   ID_FILE_NEW cria um documento novo ou está vazia.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnFileNew` implementa esse comando de maneira diferente dependendo do número de modelos de documento no aplicativo. Se houver apenas um `CDocTemplate`, `CWinApp::OnFileNew` criará um novo documento desse tipo, bem como a classe de quadro e exibição correta.  
  
     Se houver mais de um `CDocTemplate`, `CWinApp::OnFileNew` solicitará ao usuário uma caixa de diálogo (**AFX_IDD_NEWTYPEDLG**) permitindo que eles selecione que tipo de documento a ser usado. Selecionado `CDocTemplate` é usado para criar o documento.  
  
     Uma personalização comuns de `ID_FILE_NEW` é fornecer um diferente e mais opções de gráfica de tipos de documento. Nesse caso você pode implementar seu próprio **CMyApp::OnFileNew** e colocá-lo em seu mapa de mensagem em vez de `CWinApp::OnFileNew`. Não é necessário para chamar a implementação da classe base.  
  
     Outra personalização comuns de `ID_FILE_NEW` é fornecer um comando separado para a criação de um documento de cada tipo. Nesse caso, você deve definir novo comando IDs, por exemplo, ID_FILE_NEW_CHART e ID_FILE_NEW_SHEET.  
  
-   ID_FILE_OPEN abre um documento existente.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnFileOpen` tem uma implementação muito simple de chamada **CWinApp::DoPromptFileName** seguido `CWinApp::OpenDocumentFile` com o nome de arquivo ou caminho do arquivo a ser aberto. O `CWinApp` rotina de implementação **DoPromptFileName** abre a caixa de diálogo FileOpen padrão e a preenche com as extensões de arquivo obtidas dos modelos de documento atual.  
  
     Uma personalização comuns de `ID_FILE_OPEN` para personalizar a caixa de diálogo FileOpen ou adicionar filtros de arquivo adicionais. É a maneira recomendada para personalizá-la substituir a implementação padrão com sua própria caixa de diálogo FileOpen e chamada `CWinApp::OpenDocumentFile` com o nome de arquivo ou caminho do documento. Não é necessário para chamar a classe base.  
  
-   ID_FILE_CLOSE fecha o documento aberto no momento.  
  
     **CDocument::OnFileClose** chamadas `CDocument::SaveModified` para solicitar ao usuário para salvar o documento se ele tiver sido modificado e, em seguida, chama `OnCloseDocument`. Toda a lógica de fechamento, incluindo destruir o documento, é feita na `OnCloseDocument` rotina.  
  
    > [!NOTE]
    >  **ID_FILE_CLOSE** age de forma diferente de um `WM_CLOSE` mensagem ou um **SC_CLOSE** comando de sistema enviado para a janela do quadro de documentos. Fechar uma janela fechará o documento somente se for a última janela do quadro mostrando o documento. Fechar o documento com **ID_FILE_CLOSE** não apenas feche o documento, mas será encerrado em todas as janelas de quadro mostrando o documento.  
  
-   ID_FILE_SAVE salva o documento atual.  
  
     A implementação usa uma rotina auxiliar **CDocument::DoSave** que é usado para **OnFileSave** e **OnFileSaveAs**. Se você salvar um documento que ainda não foi salvo antes (ou seja, ele não tem um nome de caminho, como no caso de FileNew) ou que foi lido de um documento somente leitura, o **OnFileSave** lógica atuará como o **ID_FILE_SAVE_AS** comando e peça ao usuário para fornecer um novo nome de arquivo. O processo de abertura do arquivo e fazendo a gravação é feito por meio da função virtual `OnSaveDocument`.  
  
     Há duas razões comuns para personalizar **ID_FILE_SAVE**. Para documentos que não salvam, basta remover o **ID_FILE_SAVE** itens de menu e botões de barra de ferramentas de interface do usuário. Também, certifique-se de que você nunca sujas seu documento (isto é, nunca chamar `CDocument::SetModifiedFlag`) e a estrutura nunca fará com que o documento seja salvo. Para documentos que salvar em algum lugar que não seja um arquivo de disco, defina um novo comando para essa operação.  
  
     No caso de um `COleServerDoc`, **ID_FILE_SAVE** é usado para salvar arquivo (para documentos normais) e atualização do arquivo (para documentos inseridos).  
  
     Se seus dados de documento são armazenados em arquivos de disco individuais, mas você não quiser usar o padrão **CDocument** serializar implementação, você deve substituir `CDocument::OnSaveDocument` em vez de **OnFileSave**.  
  
-   ID_FILE_SAVE_AS salva o documento atual com um nome de arquivo diferente.  
  
     O **CDocument::OnFileSaveAs** implementação usa a mesma **CDocument::DoSave** rotina auxiliar como **OnFileSave**. O **OnFileSaveAs** comando é tratado como **ID_FILE_SAVE** se os documentos não tinham nenhum nome de arquivo antes de salvar. **COleServerDoc::OnFileSaveAs** implementa a lógica para salvar um arquivo de dados de documento normal ou salvar um documento do servidor que representa um objeto OLE incorporada em outro aplicativo como um arquivo separado.  
  
     Se você personalizar a lógica de **ID_FILE_SAVE**, você provavelmente desejará personalizar **ID_FILE_SAVE_AS** não podem ser aplicadas de forma semelhante ou a operação de "Salvar como" para o documento. Você pode remover o item de menu da barra de menu se não for necessário.  
  
-   ID_FILE_SAVE_COPY_AS salva um documento atual cópia com um novo nome.  
  
     O **COleServerDoc::OnFileSaveCopyAs** implementação é muito semelhante à **CDocument::OnFileSaveAs**, exceto que o objeto de documento não está "anexado" para o arquivo subjacente depois de salvar. Ou seja, se o documento na memória foi "modificado" antes de salvar, ela é ainda "modificada". Além disso, esse comando não tem efeito sobre o nome do caminho ou o título armazenado no documento.  
  
-   ID_FILE_UPDATE notifica o contêiner para salvar um documento incorporado.  
  
     O `COleServerDoc::OnUpdateDocument` implementação simplesmente notifiies o contêiner que a inserção deve ser salvo. O contêiner chama o apropriado OLE APIs para salvar o objeto inserido.  
  
-   ID_FILE_PAGE_SETUP invoca uma caixa de diálogo de instalação/layout de página específica do aplicativo.  
  
     Atualmente, há um padrão para essa caixa de diálogo e o framework não tem nenhuma implementação padrão desse comando.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_FILE_PRINT_SETUP invocar a caixa de diálogo Configurar impressão padrão.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     Esse comando invoca a caixa de diálogo de configuração de impressão padrão que permite ao usuário personalizar a impressora e imprimir as configurações para pelo menos neste documento ou no máximo todos os documentos neste aplicativo. Você deve usar o painel de controle para alterar as configurações de impressora padrão para todo o sistema.  
  
     `CWinApp::OnFilePrintSetup` tem uma implementação muito simple criar um `CPrintDialog` objeto e chamar o **CWinApp::DoPrintDialog** função de implementação. Isso define a configuração de impressora do padrão de aplicativo.  
  
     A necessidade comum para personalizar esse comando é permitir configurações de impressora de cada documento, que devem ser armazenadas com o documento quando salvo. Para fazer isso, você deve adicionar um manipulador de mapa de mensagem em seu **CDocument** classe cria um `CPrintDialog` de objeto, inicializa com os atributos de impressora apropriadas (geralmente **hDevMode** e **hDevNames**), chame o **CPrintDialog::DoModal,** e salve as configurações de impressora alterada. Para uma implementação robusta, você deve examinar a implementação de **CWinApp::DoPrintDialog** para detectar erros e **CWinApp::UpdatePrinterSelection** para lidar com padrões sensíveis e controle de alterações de impressora de todo o sistema.  
  
-   Impressão ID_FILE_PRINT padrão do documento atual  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CView`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     Este comando imprime o documento atual ou mais corretamente, inicia o processo de impressão, que envolve invocar a caixa de diálogo de impressão padrão e executar o mecanismo de impressão.  
  
     **CView::OnFilePrint** implementa esse comando e o loop principal de impressão. Ele chama virtual `CView::OnPreparePrinting` ao prompt do usuário com a caixa de diálogo de impressão. Em seguida, prepara a controlador de domínio de saída para ir para a impressora, exibe a caixa de diálogo de progresso impressão (**AFX_IDD_PRINTDLG**) e envia o `StartDoc` escape para a impressora. **CView::OnFilePrint** também contém o loop de impressão orientado a página principal. Para cada página, ele chama virtual `CView::OnPrepareDC` seguido por um `StartPage` escape e chamando virtual `CView::OnPrint` para a página. Quando concluir, o virtual `CView::OnEndPrinting` é chamado, e a caixa de diálogo de progresso impressão está fechada.  
  
     A arquitetura de impressão do MFC foi projetada para conectar-se de várias maneiras diferentes para impressão e visualização de impressão. Normalmente você encontrará as várias `CView` funções substituíveis adequadas para as tarefas de impressão orientada por página. No caso de um aplicativo que usa a impressora para a página não orientadas a saída, você deve considerar a necessidade de substituir o **ID_FILE_PRINT** implementação.  
  
-   ID_FILE_PRINT_PREVIEW inserir o modo de visualização de impressão para o documento atual.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CView`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     **CView::OnFilePrintPreview** inicia o modo de visualização de impressão chamando a função auxiliar documentadas **CView::DoPrintPreview**. **CView::DoPrintPreview** é o mecanismo principal para o loop de visualização de impressão, assim como **OnFilePrint** é o mecanismo principal para o loop de impressão.  
  
     A operação de visualização de impressão pode ser personalizada de várias maneiras, passando parâmetros diferentes para **DoPrintPreview**. Consulte [30 de observação técnica](../mfc/tn030-customizing-printing-and-print-preview.md), que discute alguns dos detalhes da visualização de impressão e como personalizá-lo.  
  
-   **ID_FILE_MRU_FILE1**... **FILE16** um intervalo de IDs de comando para o arquivo MRU `list`.  
  
     **CWinApp::OnUpdateRecentFileMenu** é um manipulador de interface do usuário de comando de atualização que é um dos usos mais avançados do `ON_UPDATE_COMMAND_UI` mecanismo. Em seu recurso de menu, você só precisa definir um item de menu único com ID **ID_FILE_MRU_FILE1**. Esse item de menu permanece inicialmente desabilitado.  
  
     Como o MRU lista aumenta, mais menu itens são adicionados à lista. O padrão `CWinApp` implementação padrão é o limite padrão de quatro arquivos usados mais recentemente. Você pode alterar o padrão chamando `CWinApp::LoadStdProfileSettings` com um valor maior ou menor. A lista MRU é armazenada do aplicativo. Arquivo INI. A lista é carregada em seu aplicativo `InitInstance` funcionar se você chamar `LoadStdProfileSettings`e é salvo quando seu aplicativo será encerrado. O manipulador de interface do usuário de comando de atualização MRU também converterá caminhos absolutos para caminhos relativos para exibição no menu arquivo.  
  
     **CWinApp::OnOpenRecentFile** é o `ON_COMMAND` manipulador que executa o comando. Ele simplesmente obtém o nome do arquivo na lista MRU e chamadas `CWinApp::OpenDocumentFile`, que faz todo o trabalho de abrir o arquivo e atualizar a lista MRU.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_EDIT_CLEAR limpa a seleção atual  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação de usar esse comando `CEdit::Clear`. O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_CLEAR_ALL limpa todo o documento.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando. Consulte o exemplo do Tutorial do MFC [RABISCO](../visual-cpp-samples.md) para um exemplo de implementação.  
  
-   ID_EDIT_COPY copia a seleção atual na área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, que copia o texto atualmente selecionado na área de transferência como CF_TEXT usando `CEdit::Copy`. O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_CUT Recorta a seleção atual na área de transferência.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, o que reduz o texto atualmente selecionado na área de transferência como CF_TEXT usando `CEdit::Cut`. O comando é desabilitado se não houver nenhuma seleção atual.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   A operação de pesquisa começa ID_EDIT_FIND abre a caixa de diálogo sem janela restrita.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, que chama a função auxiliar de implementação **OnEditFindReplace** usar e armazenar as configurações anteriores de localizar/substituir em variáveis de implementação privada. O `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo sem janela restrita para avisar o usuário.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_PASTE insere o conteúdo da área de transferência atual.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, que copia dados da área de transferência atuais, substituindo o texto selecionado usando `CEdit::Paste`. O comando é desabilitado se não houver nenhum **CF_TEXT** na área de transferência.  
  
     **COleClientDoc** apenas fornece um manipulador de interface do usuário de comando de atualização para este comando. Se a área de transferência não contém um item OLE inserível/objeto, o comando será desabilitado. Você é responsável por gravar o manipulador para o comando fazer a colagem real. Se seu aplicativo OLE também pode colar com outros formatos, você deve fornecer seu próprio manipulador de interface do usuário do comando de atualização no documento ou modo de exibição (isto é, em algum lugar antes **COleClientDoc** no comando destino roteamento).  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
     Para substituir a implementação padrão de OLE, use `COleClientItem::CanPaste`.  
  
-   ID_EDIT_PASTE_LINK insere um link do conteúdo da área de transferência atual.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `COleDocument` apenas fornece um manipulador de interface do usuário de comando de atualização para este comando. Se a área de transferência não contém o item/objeto OLE linkable, o comando será desabilitado. Você é responsável por gravar o manipulador para o comando fazer a colagem real. Se seu aplicativo OLE também pode colar com outros formatos, você deve fornecer seu próprio manipulador de interface do usuário do comando de atualização no documento ou modo de exibição (isto é, em algum lugar antes `COleDocument` no comando destino roteamento).  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
     Para substituir a implementação padrão de OLE, use `COleClientItem::CanPasteLink`.  
  
-   ID_EDIT_PASTE_SPECIAL insere o conteúdo atual da área de transferência com opções.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada. MFC não fornecer essa caixa de diálogo.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_REPEAT repete a última operação.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando para repetir a última operação de localização. As variáveis de implementação privada para a última pesquisa são usadas. O comando será desabilitado se uma localização não pode ser tentada.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   A operação de substituição, ID_EDIT_REPLACE começa abre a caixa de diálogo sem janela restrita substituir.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, que chama a função auxiliar de implementação **OnEditFindReplace** usar e armazenar as configurações anteriores de localizar/substituir em variáveis de implementação privada. O `CFindReplaceDialog` classe é usada para gerenciar a caixa de diálogo sem janela restrita que solicita ao usuário.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_SELECT_ALL seleciona todo o documento.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, que seleciona todo o texto do documento. O comando é desabilitado se não houver nenhum texto para selecionar.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_UNDO desfaz a última operação.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     `CEditView` Fornece uma implementação desse comando, usando `CEdit::Undo`. O comando será desabilitado se `CEdit::CanUndo` retorna FALSE.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_EDIT_REDO Refaz a última operação.  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para cada `CView`-classe derivada.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   ID_WINDOW_NEW abre outra janela do documento ativo.  
  
     **CMDIFrameWnd::OnWindowNew** implementa esse recurso eficiente, usando o modelo de documento do documento atual para criar outro quadro que contém outro modo de exibição do documento atual.  
  
     Como a maioria dos vários documentos MDI (interface) comandos do menu janela, o comando é desabilitado se não houver nenhuma janela de filho MDI ativo.  
  
     Personalização deste manipulador de comando não é recomendada. Se você desejar fornecer um comando que cria exibições adicionais ou janelas com moldura, provavelmente será melhor criação seu próprio comando. Você pode clonar o código de **CMDIFrameWnd::OnWindowNew** e modificá-lo para as classes específicas de quadro e o modo de exibição de sua preferência.  
  
-   ID_WINDOW_ARRANGE organiza os ícones na parte inferior de uma janela MDI.  
  
     `CMDIFrameWnd` implementa esse comando MDI padrão em uma função auxiliar de implementação **OnMDIWindowCmd**. Este auxiliar mapeia IDs de comando para mensagens de janelas MDI e pode, portanto, compartilham muitos códigos.  
  
     Como a maioria dos comandos do menu janela MDI, o comando é desabilitado se não houver nenhuma janela de filho MDI ativo.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   Windows ID_WINDOW_CASCADE cascatas para que elas se sobreponham.  
  
     `CMDIFrameWnd` implementa esse comando MDI padrão em uma função auxiliar de implementação **OnMDIWindowCmd**. Este auxiliar mapeia IDs de comando para mensagens de janelas MDI e pode, portanto, compartilham muitos códigos.  
  
     Como a maioria dos comandos do menu janela MDI, o comando é desabilitado se não houver nenhuma janela de filho MDI ativo.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   Windows ID_WINDOW_TILE_HORZ lado a lado horizontalmente.  
  
     Esse comando é implementado em `CMDIFrameWnd` como **ID_WINDOW_CASCADE**, exceto uma mensagem de janelas MDI diferente é usada para a operação.  
  
     Você deve escolher a orientação de bloco padrão para seu aplicativo. Você pode fazer isso alterando a ID do item de menu janela "Bloco" como **ID_WINDOW_TILE_HORZ** ou **ID_WINDOW_TILE_VERT**.  
  
-   Windows ID_WINDOW_TILE_VERT blocos verticalmente.  
  
     Esse comando é implementado em `CMDIFrameWnd` como **ID_WINDOW_CASCADE**, exceto uma mensagem de janelas MDI diferente é usada para a operação.  
  
     Você deve escolher a orientação de bloco padrão para seu aplicativo. Você pode fazer isso alterando a ID do item de menu janela "Bloco" como **ID_WINDOW_TILE_HORZ** ou **ID_WINDOW_TILE_VERT**.  
  
-   Interface ID_WINDOW_SPLIT teclado divisor.  
  
     `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, este comando delegará para a função de implementação `CSplitterWnd::DoKeyboardSplit`. Isso colocará o separador em um modo que permitirá que os usuários de teclado dividir ou remova a divisão de uma janela separadora.  
  
     Este comando será desabilitado se o modo de exibição não está em um divisor.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_APP_ABOUT invoca a caixa de diálogo sobre.  
  
     Não há nenhuma implementação padrão para a caixa sobre do aplicativo. Aplicativo criado AppWizard padrão será criar uma classe de caixa de diálogo personalizada para seu aplicativo e usá-la como sua caixa sobre. AppWizard também gravará o manipulador de comando simples que lida com este comando e chama a caixa de diálogo.  
  
     Você quase sempre implementar esse comando.  
  
-   ID_APP_EXIT sair do aplicativo.  
  
     **CWinApp::OnAppExit** trata esse comando enviando um `WM_CLOSE` mensagem para a janela principal do aplicativo. O padrão de desligamento do aplicativo (solicite sujos arquivos e assim por diante) é tratado pelo `CFrameWnd` implementação.  
  
     Personalização deste manipulador de comando não é recomendada. Substituindo `CWinApp::SaveAllModified` ou `CFrameWnd` fechar lógica é recomendado.  
  
     Se você optar por implementar esse comando, é recomendável que usar essa ID de comando.  
  
-   Tópicos da Ajuda do ID_HELP_INDEX lista de. Arquivo HLP.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelpIndex` trata esse comando chamando facilmente `CWinApp::WinHelp`.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_HELP_USING exibe ajuda sobre como usar a Ajuda.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelpUsing` trata esse comando chamando facilmente `CWinApp::WinHelp`.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   Modo de ajuda ID_CONTEXT_HELP entra SHIFT-F1.  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnContextHelp` lida com este comando definição do cursor do modo de Ajuda, inserindo um loop modal e aguardando o usuário selecione uma janela para obter ajuda sobre. Consulte [28 de observação técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre a implementação de Ajuda do MFC.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_HELP fornece ajuda sobre o contexto atual  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     `CWinApp::OnHelp` lida com este comando obtendo o contexto da Ajuda correto para o contexto atual do aplicativo. Manipula simples ajuda de F1, ajuda nas caixas de mensagem e assim por diante. Consulte [28 de observação técnica](../mfc/tn028-context-sensitive-help-support.md) para obter mais detalhes sobre o MFC implementação da Ajuda.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_DEFAULT_HELP exibe a Ajuda padrão contexto  
  
    > [!NOTE]
    >  Você deve se conectar a esta opção para sua `CWinApp`-derivado mapa de mensagem da classe para habilitar essa funcionalidade.  
  
     Este comando geralmente é mapeado para `CWinApp::OnHelpIndex`.  
  
     Um manipulador de comandos diferentes pode ser fornecido se uma distinção entre ajuda padrão e o índice da Ajuda é desejada.  
  
-   ID_NEXT_PANE vai para o próximo painel  
  
     `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, este comando delegará para a função de implementação **CSplitterWnd::OnNextPaneCmd**. Isso moverá o modo de exibição ativo para o próximo painel no separador.  
  
     Este comando será desabilitado se o modo de exibição não está em um divisor ou não há nenhum painel Avançar para ir para.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_PREV_PANE vai para o painel anterior  
  
     `CView` lida com esse comando para o `CSplitterWnd` implementação. Se a exibição for parte de uma janela separadora, este comando delegará para a função de implementação **CSplitterWnd::OnNextPaneCmd**. Isso moverá o modo de exibição ativo para o painel anterior no separador.  
  
     Este comando será desabilitado se o modo de exibição não está em um divisor ou não há nenhum painel anterior para ir para.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_OLE_INSERT_NEW insere um novo objeto OLE  
  
     Atualmente não há nenhuma implementação padrão desse comando. Você deve implementar isso para sua `CView`-derivado da classe para inserir um novo item/objeto OLE na seleção atual.  
  
     Todos os aplicativos de cliente OLE devem implementar esse comando. AppWizard, com a opção OLE, criará uma implementação esqueleto de **OnInsertObject** na sua classe de exibição que você terá que completar.  
  
     Consulte o exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) exemplo de uma implementação completa deste comando.  
  
-   Links ID_OLE_EDIT_LINKS edita OLE  
  
     `COleDocument` trata esse comando usando a implementação fornecida pelo MFC da caixa de diálogo de links OLE padrão. A implementação desta caixa de diálogo é acessada por meio de `COleLinksDialog` classe. Se o documento atual não contém todos os links, o comando está desabilitado.  
  
     Personalização deste manipulador de comando não é recomendada.  
  
-   ID_OLE_VERB_FIRST... ÚLTIMO intervalo de uma ID de verbos OLE  
  
     `COleDocument` usa esse intervalo de ID de comando para os verbos que o item OLE selecionado no momento/objeto oferece suportados. Isso deve ser um intervalo, desde que um determinado tipo de objeto do item OLE pode dar suporte a zero ou mais verbos personalizados. No menu do aplicativo, você deve ter um item de menu com a ID de **ID_OLE_VERB_FIRST**. Quando o programa é executado, o menu será atualizado com a descrição do verbo de menu apropriado (ou o menu pop-up com muitos verbos). O gerenciamento do menu OLE é tratado pelo `AfxOleSetEditMenu`, do manipulador de interface do usuário do comando de atualização para este comando.  
  
     Não há nenhum manipulador de comando explícito para tratamento de cada ID de comando nesse intervalo. **COleDocument::OnCmdMsg** é substituído para interceptar todas as IDs de comando nesse intervalo, ligá-los em números com base em zero verbo e iniciar o servidor para o verbo (usando `COleClientItem::DoVerb`).  
  
     Personalização ou outro uso desse intervalo de ID de comando não é recomendado.  
  
-   Ativa e ID_VIEW_TOOLBAR desativa a barra de ferramentas  
  
     `CFrameWnd` lida com este comando e o manipulador de comando de atualização da interface do usuário para alternar o estado de visibilidade da barra de ferramentas. A barra de ferramentas deve ser uma janela filho do quadro com a ID de janela filho de `AFX_IDW_TOOLBAR`. O manipulador de comandos, na verdade, alterna a visibilidade da janela de ferramentas. `CFrameWnd::RecalcLayout` é usado para redesenhar a janela do quadro com a barra de ferramentas em seu novo estado. O manipulador de interface do usuário do comando de atualização verifica o item de menu quando a barra de ferramentas está visível.  
  
     Personalização deste manipulador de comando não é recomendada. Se você quiser adicionar barras de ferramentas, você desejará clonar e modificar o manipulador de comandos e o manipulador de interface do usuário do comando de atualização para este comando.  
  
-   Ativa e ID_VIEW_STATUS_BAR desativa a barra de status  
  
     Esse comando é implementado em `CFrameWnd` como **ID_VIEW_TOOLBAR**, exceto uma ID de janela filho diferente (**AFX_IDW_STATUS_BAR**) é usado.  
  
## <a name="update-only-command-handlers"></a>Manipuladores de comandos somente de atualização  
 Várias IDs de comando padrão são usados como indicadores em barras de status. Esses usam a mesma interface de usuário do comando de atualização do mecanismo de tratamento para exibir o estado visual atual durante o tempo ocioso do aplicativo. Desde que eles não podem ser selecionados pelo usuário (ou seja, não é possível enviar um painel da barra de status), em seguida, não faz sentido ter um `ON_COMMAND` manipulador para esses IDs de comando.  
  
-   **ID_INDICATOR_CAPS** : indicador de bloqueio de limite.  
  
-   **ID_INDICATOR_NUM** : indicador de bloqueio NUM.  
  
-   **ID_INDICATOR_SCRL** : indicador de bloqueio SCRL.  
  
-   **ID_INDICATOR_KANA** : indicador de bloqueio KANA (aplicável apenas aos sistemas japonês).  
  
 Todos os três seguintes são implementadas no **CFrameWnd::OnUpdateKeyIndicator**, um auxiliar de implementação que usa a ID de comando para mapear para a chave Virtual apropriado. Uma implementação comum habilita ou desabilita (para painéis de status desabilitados não = nenhum texto) de `CCmdUI` objeto dependendo se a chave Virtual apropriado está bloqueada no momento.  
  
 Personalização deste manipulador de comando não é recomendada.  
  
-   **ID_INDICATOR_EXT: EXT**encerrada selecionar indicador.  
  
-   **ID_INDICATOR_OVR: Obter informações sobre**e**R**strike indicador.  
  
-   **ID_INDICATOR_REC: REC**indicador ording.  
  
 Atualmente não há nenhuma implementação padrão para esses indicadores.  
  
 Se você optar por implementar esses indicadores, recomendamos que você use essas IDs de indicador e manter a ordenação dos indicadores na barra de status (ou seja, nesta ordem: EXT, CAP, NUM, SCRL, se, REC).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

