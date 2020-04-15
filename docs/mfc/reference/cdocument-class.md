---
title: Classe CDocument
ms.date: 11/04/2016
f1_keywords:
- CDocument
- AFXWIN/CDocument
- AFXWIN/CDocument::CDocument
- AFXWIN/CDocument::AddView
- AFXWIN/CDocument::BeginReadChunks
- AFXWIN/CDocument::CanCloseFrame
- AFXWIN/CDocument::ClearChunkList
- AFXWIN/CDocument::ClearPathName
- AFXWIN/CDocument::DeleteContents
- AFXWIN/CDocument::FindChunk
- AFXWIN/CDocument::GetAdapter
- AFXWIN/CDocument::GetDocTemplate
- AFXWIN/CDocument::GetFile
- AFXWIN/CDocument::GetFirstViewPosition
- AFXWIN/CDocument::GetNextView
- AFXWIN/CDocument::GetPathName
- AFXWIN/CDocument::GetThumbnail
- AFXWIN/CDocument::GetTitle
- AFXWIN/CDocument::InitializeSearchContent
- AFXWIN/CDocument::IsModified
- AFXWIN/CDocument::IsSearchAndOrganizeHandler
- AFXWIN/CDocument::LoadDocumentFromStream
- AFXWIN/CDocument::OnBeforeRichPreviewFontChanged
- AFXWIN/CDocument::OnChangedViewList
- AFXWIN/CDocument::OnCloseDocument
- AFXWIN/CDocument::OnCreatePreviewFrame
- AFXWIN/CDocument::OnDocumentEvent
- AFXWIN/CDocument::OnDrawThumbnail
- AFXWIN/CDocument::OnLoadDocumentFromStream
- AFXWIN/CDocument::OnNewDocument
- AFXWIN/CDocument::OnOpenDocument
- AFXWIN/CDocument::OnPreviewHandlerQueryFocus
- AFXWIN/CDocument::OnPreviewHandlerTranslateAccelerator
- AFXWIN/CDocument::OnRichPreviewBackColorChanged
- AFXWIN/CDocument::OnRichPreviewFontChanged
- AFXWIN/CDocument::OnRichPreviewSiteChanged
- AFXWIN/CDocument::OnRichPreviewTextColorChanged
- AFXWIN/CDocument::OnSaveDocument
- AFXWIN/CDocument::OnUnloadHandler
- AFXWIN/CDocument::PreCloseFrame
- AFXWIN/CDocument::ReadNextChunkValue
- AFXWIN/CDocument::ReleaseFile
- AFXWIN/CDocument::RemoveChunk
- AFXWIN/CDocument::RemoveView
- AFXWIN/CDocument::ReportSaveLoadException
- AFXWIN/CDocument::SaveModified
- AFXWIN/CDocument::SetChunkValue
- AFXWIN/CDocument::SetModifiedFlag
- AFXWIN/CDocument::SetPathName
- AFXWIN/CDocument::SetTitle
- AFXWIN/CDocument::UpdateAllViews
- AFXWIN/CDocument::OnFileSendMail
- AFXWIN/CDocument::OnUpdateFileSendMail
- AFXWIN/CDocument::m_bGetThumbnailMode
- AFXWIN/CDocument::m_bPreviewHandlerMode
- AFXWIN/CDocument::m_bSearchMode
- AFXWIN/CDocument::m_clrRichPreviewBackColor
- AFXWIN/CDocument::m_clrRichPreviewTextColor
- AFXWIN/CDocument::m_lfRichPreviewFont
helpviewer_keywords:
- CDocument [MFC], CDocument
- CDocument [MFC], AddView
- CDocument [MFC], BeginReadChunks
- CDocument [MFC], CanCloseFrame
- CDocument [MFC], ClearChunkList
- CDocument [MFC], ClearPathName
- CDocument [MFC], DeleteContents
- CDocument [MFC], FindChunk
- CDocument [MFC], GetAdapter
- CDocument [MFC], GetDocTemplate
- CDocument [MFC], GetFile
- CDocument [MFC], GetFirstViewPosition
- CDocument [MFC], GetNextView
- CDocument [MFC], GetPathName
- CDocument [MFC], GetThumbnail
- CDocument [MFC], GetTitle
- CDocument [MFC], InitializeSearchContent
- CDocument [MFC], IsModified
- CDocument [MFC], IsSearchAndOrganizeHandler
- CDocument [MFC], LoadDocumentFromStream
- CDocument [MFC], OnBeforeRichPreviewFontChanged
- CDocument [MFC], OnChangedViewList
- CDocument [MFC], OnCloseDocument
- CDocument [MFC], OnCreatePreviewFrame
- CDocument [MFC], OnDocumentEvent
- CDocument [MFC], OnDrawThumbnail
- CDocument [MFC], OnLoadDocumentFromStream
- CDocument [MFC], OnNewDocument
- CDocument [MFC], OnOpenDocument
- CDocument [MFC], OnPreviewHandlerQueryFocus
- CDocument [MFC], OnPreviewHandlerTranslateAccelerator
- CDocument [MFC], OnRichPreviewBackColorChanged
- CDocument [MFC], OnRichPreviewFontChanged
- CDocument [MFC], OnRichPreviewSiteChanged
- CDocument [MFC], OnRichPreviewTextColorChanged
- CDocument [MFC], OnSaveDocument
- CDocument [MFC], OnUnloadHandler
- CDocument [MFC], PreCloseFrame
- CDocument [MFC], ReadNextChunkValue
- CDocument [MFC], ReleaseFile
- CDocument [MFC], RemoveChunk
- CDocument [MFC], RemoveView
- CDocument [MFC], ReportSaveLoadException
- CDocument [MFC], SaveModified
- CDocument [MFC], SetChunkValue
- CDocument [MFC], SetModifiedFlag
- CDocument [MFC], SetPathName
- CDocument [MFC], SetTitle
- CDocument [MFC], UpdateAllViews
- CDocument [MFC], OnFileSendMail
- CDocument [MFC], OnUpdateFileSendMail
- CDocument [MFC], m_bGetThumbnailMode
- CDocument [MFC], m_bPreviewHandlerMode
- CDocument [MFC], m_bSearchMode
- CDocument [MFC], m_clrRichPreviewBackColor
- CDocument [MFC], m_clrRichPreviewTextColor
- CDocument [MFC], m_lfRichPreviewFont
ms.assetid: e5a2891d-e1e1-4599-8c7e-afa9b4945446
ms.openlocfilehash: 2f8ba8d0b35bd72efa8f8d63dbefd689e645d768
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374045"
---
# <a name="cdocument-class"></a>Classe CDocument

Fornece a funcionalidade básica para classes de documentos definidas pelo usuário.

## <a name="syntax"></a>Sintaxe

```
class CDocument : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::CDocument](#cdocument)|Constrói um objeto `CDocument`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::AddView](#addview)|Anexa uma exibição ao documento.|
|[CDocument::BeginReadChunks](#beginreadchunks)|Inicializa a leitura de pedaços.|
|[CDocument::CanCloseFrame](#cancloseframe)|Superável avançado; chamado antes de fechar uma janela de quadro visualizando este documento.|
|[CDocument::ClearChunkList](#clearchunklist)|Limpa a lista de pedaços.|
|[CDocument::ClearPathName](#clearpathname)|Limpa o caminho do objeto do documento.|
|[CDocument::DeleteContents](#deletecontents)|Chamado para realizar a limpeza do documento.|
|[CDocument::FindChunk](#findchunk)|Procura um pedaço com GUID especificado.|
|[CDocument::GetAdapter](#getadapter)|Retorna um ponteiro para `IDocument` a interface de implementação de objetos.|
|[CDocument::GetDocTemplate](#getdoctemplate)|Retorna um ponteiro para o modelo de documento que descreve o tipo do documento.|
|[CDocument::GetFile](#getfile)|Retorna um ponteiro para `CFile` o objeto desejado.|
|[CDocument::GetFirstViewPosition](#getfirstviewposition)|Retorna a posição do primeiro na lista de visualizações; usado para começar a iteração.|
|[CDocument::GetNextView](#getnextview)|Iterates através da lista de visualizações associadas ao documento.|
|[CDocument::GetPathName](#getpathname)|Retorna o caminho do arquivo de dados do documento.|
|[CDocument::GetThumbnail](#getthumbnail)|Chamado para criar um bitmap a ser usado pelo provedor de miniaturas para exibir miniatura.|
|[CDocument::GetTitle](#gettitle)|Retorna o título do documento.|
|[CDocument::InitializeSearchContent](#initializesearchcontent)|Chamado para inicializar o conteúdo da pesquisa para o Manipulador de Pesquisa.|
|[documento C::IsModified](#ismodified)|Indica se o documento foi modificado desde a última vez que foi salvo.|
|[cdocument::issearchandorganizehandler](#issearchandorganizehandler)|Informa se essa `CDocument` instância do objeto foi criada para o manipulador Search & Organize.|
|[CDocument::LoadDocumentFromStream](#loaddocumentfromstream)|Chamado para carregar dados de documentos do fluxo.|
|[cDocument::OnbeforeRichPreviewFontChanged](#onbeforerichpreviewfontchanged)|Chamado antes que a fonte Rich Preview seja alterada.|
|[cDocument::OnChangedExibilist](#onchangedviewlist)|Chamado depois que uma exibição é adicionada ou removida do documento.|
|[CDocument::OnCloseDocument](#onclosedocument)|Chamado para fechar o documento.|
|[cDocument::OnCreatePreviewFrame](#oncreatepreviewframe)|Chamado pela estrutura quando precisa criar um quadro de visualização para Rich Preview.|
|[CDocument::OnDocumentEvent](#ondocumentevent)|Chamado pelo quadro em resposta a um evento documental.|
|[CDocument::OnDrawThumbnail](#ondrawthumbnail)|Anular este método em uma classe derivada para desenhar conteúdo de miniatura.|
|[cDocument::OnloadDocumentFromStream](#onloaddocumentfromstream)|Chamado pela estrutura quando precisa carregar os dados do documento a partir do fluxo.|
|[CDocument::OnNewDocument](#onnewdocument)|Chamado para criar um novo documento.|
|[CDocument::OnOpenDocument](#onopendocument)|Chamado para abrir um documento existente.|
|[CDocument::OnPreviewHandlerQueryFocus](#onpreviewhandlerqueryfocus)|Orienta o manipulador de visualização a retornar o HWND de chamar a função GetFocus.|
|[cDocument::OnPreviewHandlerTranslateAccelerator](#onpreviewhandlertranslateaccelerator)|Direciona o manipulador de visualização para lidar com um pressionamento de teclas passado da bomba de mensagem do processo em que o manipulador de visualização está sendo executado.|
|[cdocument::OnrichPreviewBackColorChanged](#onrichpreviewbackcolorchanged)|Chamado quando a cor de fundo do Rich Preview mudou.|
|[cDocument::OnrichPreviewFontChanged](#onrichpreviewfontchanged)|Chamado quando a fonte Rich Preview foi alterada.|
|[CDocument::OnrichPreviewsiteAlterado](#onrichpreviewsitechanged)|Chamado quando o site Rich Preview mudou.|
|[CDocument::OnrichPreviewTextColorAlterado](#onrichpreviewtextcolorchanged)|Chamado quando a cor do texto rich preview foi alterada.|
|[cdocument::OnSaveDocument](#onsavedocument)|Chamado para salvar o documento em disco.|
|[cDocument::OnUnloadHandler](#onunloadhandler)|Chamado pela estrutura quando o manipulador de visualização está sendo descarregado.|
|[CDocument::PreCloseFrame](#precloseframe)|Chamado antes que a janela da moldura seja fechada.|
|[cDocument::ReadNextChunkValue](#readnextchunkvalue)|Leia o próximo valor do pedaço.|
|[CDocument::ReleaseFile](#releasefile)|Libera um arquivo para torná-lo disponível para uso por outros aplicativos.|
|[cDocument::RemoveChunk](#removechunk)|Remove um pedaço com GUID especificado.|
|[CDocument::RemoveView](#removeview)|Destaca uma visão do documento.|
|[CDocument::RelatórioEconomiadeeconomiadecarregamentodesexcedesdes](#reportsaveloadexception)|Superável avançado; chamado quando uma operação aberta ou de salvamento não pode ser concluída por causa de uma exceção.|
|[cdocument::SaveModified](#savemodified)|Superável avançado; chamado para perguntar ao usuário se o documento deve ser salvo.|
|[CDocument::SetChunkValue](#setchunkvalue)|Define um valor de pedaço.|
|[cDocument::SetModifiedFlag](#setmodifiedflag)|Define uma bandeira indicando que você modificou o documento desde que foi salvo pela última vez.|
|[CDocument::Set's's](#setpathname)|Define o caminho do arquivo de dados usado pelo documento.|
|[CDocument::SetTitle](#settitle)|Define o título do documento.|
|[CDocument::UpdateAllViews](#updateallviews)|Notifica todas as opiniões de que o documento foi modificado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[cdocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de e-mail com o documento anexado.|
|[cdocument::OnUpdateFileSendMail](#onupdatefilesendmail)|Habilita o comando Enviar e-mail se houver suporte por e-mail.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::m_bGetThumbnailMode](#m_bgetthumbnailmode)|Especifica que `CDocument` o objeto foi criado por dllhost para miniaturas. Deve ser `CView::OnDraw`verificado.|
|[CDocument::m_bPreviewHandlerMode](#m_bpreviewhandlermode)|Especifica que `CDocument` o objeto foi criado `Rich Preview`pelo prevhost para . Deve ser `CView::OnDraw`verificado.|
|[CDocument::m_bSearchMode](#m_bsearchmode)|Especifica que `CDocument` o objeto foi criado por indexador ou outro aplicativo de pesquisa.|
|[CDocument::m_clrRichPreviewBackColor](#m_clrrichpreviewbackcolor)|Especifica a cor de fundo da janela Rich Preview. Esta cor é definida pelo host.|
|[CDocument::m_clrRichPreviewTextColor](#m_clrrichpreviewtextcolor)|Especifica a cor do primeiro plano da janela Rich Preview. Esta cor é definida pelo host.|
|[CDocument::m_lfRichPreviewFont](#m_lfrichpreviewfont)|Especifica a fonte de texto para a janela Rich Preview. Essas informações da fonte são definidas pelo host.|

## <a name="remarks"></a>Comentários

Um documento representa a unidade de dados que o usuário normalmente abre com o comando File Open e salva com o comando 'Salvar arquivos'.

`CDocument`suporta operações padrão, como criar um documento, carregá-lo e salvá-lo. A estrutura manipula documentos usando `CDocument`a interface definida por .

Um aplicativo pode suportar mais de um tipo de documento; por exemplo, um aplicativo pode suportar planilhas e documentos de texto. Cada tipo de documento possui um modelo de documento associado; o modelo de documento especifica quais recursos (por exemplo, menu, ícone ou tabela do acelerador) são usados para esse tipo de documento. Cada documento contém um `CDocTemplate` ponteiro para seu objeto associado.

Os usuários interagem com um documento através dos objetos [CView](../../mfc/reference/cview-class.md) associados a ele. Uma visualização renderiza uma imagem do documento em uma janela de quadro e interpreta a entrada do usuário como operações no documento. Um documento pode ter vários pontos de vista associados a ele. Quando o usuário abre uma janela em um documento, a estrutura cria uma exibição e a anexa ao documento. O modelo do documento especifica que tipo de exibição e janela de quadro são usadas para exibir cada tipo de documento.

Os documentos fazem parte do roteamento padrão de comandos da estrutura e, consequentemente, recebem comandos de componentes padrão da interface do usuário (como o item do menu Salvar arquivos). Um documento recebe comandos encaminhados pela exibição ativa. Se o documento não manusear um determinado comando, ele encaminha o comando para o modelo de documento que o gerencia.

Quando os dados de um documento são modificados, cada uma de suas opiniões deve refletir essas modificações. `CDocument`fornece a função de membro [UpdateAllViews](#updateallviews) para que você notifique as visualizações de tais alterações, para que as visualizações possam se repintar conforme necessário. A estrutura também solicita ao usuário que salve um arquivo modificado antes de fechá-lo.

Para implementar documentos em um aplicativo típico, você deve fazer o seguinte:

- Obtenha uma `CDocument` aula para cada tipo de documento.

- Adicione variáveis de membro para armazenar os dados de cada documento.

- Implementar funções de membro para leitura e modificação dos dados do documento. As opiniões do documento são os usuários mais importantes dessas funções de membro.

- Substituir a função [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) member na classe de documentos para gravar e ler os dados do documento de e para o disco.

`CDocument`suporta o envio do seu documento via correio se o suporte de e-mail (MAPI) estiver presente. Consulte os artigos [MAPI](../../mfc/mapi.md) e [MAPI Support em MFC](../../mfc/mapi-support-in-mfc.md).

Para obter `CDocument`mais informações sobre , consulte [Serialização,](../../mfc/serialization-in-mfc.md) [Tópicos de arquitetura de documentos/visualização](../../mfc/document-view-architecture.md)e [criação de documentos/visualizações](../../mfc/document-view-creation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDocument`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cdocumentaddview"></a><a name="addview"></a>CDocument::AddView

Chame esta função para anexar uma exibição ao documento.

```
void AddView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pVer*<br/>
Aponta para a visão a ser adicionada.

### <a name="remarks"></a>Comentários

Esta função adiciona a exibição especificada à lista de visualizações associadas ao documento; a função também define o ponteiro do documento da exibição para este documento. O framework chama essa função ao anexar um objeto de exibição recém-criado a um documento; isso ocorre em resposta a um comando File New, File Open ou New Window ou quando uma janela de divisor é dividida.

Chame esta função somente se você estiver criando e anexando manualmente uma exibição. Normalmente, você permitirá que a estrutura conecte documentos e visualizações definindo um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para associar uma classe de documentos, exibir classe e classe de janela de quadro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#12](../../mfc/codesnippet/cpp/cdocument-class_1.cpp)]

## <a name="cdocumentbeginreadchunks"></a><a name="beginreadchunks"></a>CDocument::BeginReadChunks

Inicializa a leitura de pedaços.

```
virtual void BeginReadChunks ();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentcancloseframe"></a><a name="cancloseframe"></a>CDocument::CanCloseFrame

Chamado pela estrutura antes que uma janela de quadro exibindo o documento seja fechada.

```
virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Aponta para a janela de quadro de uma exibição anexada ao documento.

### <a name="return-value"></a>Valor retornado

Não zero se for seguro fechar a janela do quadro; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão verifica se há outras janelas de quadro exibindo o documento. Se a janela de quadro especificada for a última que exibe o documento, a função solicitará ao usuário que salve o documento se ele tiver sido modificado. Anular esta função se você quiser realizar um processamento especial quando uma janela de quadro estiver fechada. Este é um avançado super-rididável.

## <a name="cdocumentcdocument"></a><a name="cdocument"></a>CDocument::CDocument

Constrói um objeto `CDocument`.

```
CDocument();
```

### <a name="remarks"></a>Comentários

A estrutura lida com a criação de documentos para você. Substituir a função de membro [OnNewDocument](#onnewdocument) para executar a inicialização por documento; isso é particularmente importante em aplicativos de interface de documento único (SDI).

## <a name="cdocumentclearchunklist"></a><a name="clearchunklist"></a>CDocument::ClearChunkList

Limpa a lista de pedaços.

```
virtual void ClearChunkList ();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentclearpathname"></a><a name="clearpathname"></a>CDocument::ClearPathName

Limpa o caminho do objeto do documento.

```
virtual void ClearPathName();
```

### <a name="remarks"></a>Comentários

A limpeza do `CDocument` caminho de um objeto faz com que o aplicativo instile o usuário quando o documento for salvo em seguida. Isso faz **com que um comando Save** se comporte como um comando Save **As.**

## <a name="cdocumentdeletecontents"></a><a name="deletecontents"></a>CDocument::DeleteContents

Chamado pela estrutura para excluir os dados do `CDocument` documento sem destruir o objeto em si.

```
virtual void DeleteContents();
```

### <a name="remarks"></a>Comentários

É chamado pouco antes do documento ser destruído. Também é chamado para garantir que um documento esteja vazio antes de ser reutilizado. Isso é particularmente importante para um aplicativo SDI, que usa apenas um documento; o documento é reutilizado sempre que o usuário cria ou abre outro documento. Chame esta função para implementar um comando "Editar limpar tudo" ou semelhante que exclui todos os dados do documento. A implementação padrão desta função não faz nada. Anular esta função para excluir os dados em seu documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#57](../../mfc/codesnippet/cpp/cdocument-class_2.cpp)]

## <a name="cdocumentfindchunk"></a><a name="findchunk"></a>CDocument::FindChunk

Procura um pedaço com um GUID especificado.

```
virtual POSITION FindChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*Guid*<br/>
Especifica o GUID de um pedaço a ser encontrado.

*Pid*<br/>
Especifica um PID de um pedaço a ser encontrado.

### <a name="return-value"></a>Valor retornado

Posição na lista de blocos internos se for bem sucedida. Caso contrário, NULO.

### <a name="remarks"></a>Comentários

## <a name="cdocumentgetadapter"></a><a name="getadapter"></a>CDocument::GetAdapter

Retorna um ponteiro para um `IDocument` objeto que implementa a interface.

```
virtual ATL::IDocument* GetAdapter();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um `IDocument` objeto que implementa a interface.

### <a name="remarks"></a>Comentários

## <a name="cdocumentgetdoctemplate"></a><a name="getdoctemplate"></a>CDocument::GetDocTemplate

Ligue para esta função para obter um ponteiro para o modelo de documento para este tipo de documento.

```
CDocTemplate* GetDocTemplate() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o modelo de documento para este tipo de documento ou NULL se o documento não for gerenciado por um modelo de documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#58](../../mfc/codesnippet/cpp/cdocument-class_3.cpp)]

## <a name="cdocumentgetfile"></a><a name="getfile"></a>CDocument::GetFile

Chame esta função de membro `CFile` para obter um ponteiro para um objeto.

```
virtual CFile* GetFile(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CFileException* pError);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma seqüência que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que indica o status de conclusão da operação.

*nOpenFlags*<br/>
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar opções listadas no cFile construtor [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) usando o operador bitwise OR (&#124;). Uma permissão de acesso e uma opção de compartilhamento são necessárias; os `modeCreate` `modeNoInherit` modos e modos são opcionais.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CFile`.

## <a name="cdocumentgetfirstviewposition"></a><a name="getfirstviewposition"></a>CDocument::GetFirstViewPosition

Chame esta função para obter a posição da primeira visualização na lista de visualizações associadas ao documento.

```
virtual POSITION GetFirstViewPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor DE POSIÇÃO que pode ser usado para iteração com a função de membro [GetNextView.](#getnextview)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

## <a name="cdocumentgetnextview"></a><a name="getnextview"></a>CDocument::GetNextView

Chame essa função para iterar através de todas as opiniões do documento.

```
virtual CView* GetNextView(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*Rposition*<br/>
Uma referência a um valor DE POSIÇÃO `GetNextView` retornado por uma chamada anterior para as funções do membro [getFirstViewPosition.](#getfirstviewposition) Este valor não deve ser NULO.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a exibição identificada por *rPosition*.

### <a name="remarks"></a>Comentários

A função retorna a exibição identificada por *rPosição* e, em seguida, define *rPosição* para o valor DE POSIÇÃO da próxima exibição na lista. Se a exibição recuperada for a última da lista, *rPosição* será definida como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

## <a name="cdocumentgetpathname"></a><a name="getpathname"></a>CDocument::GetPathName

Chame esta função para obter o caminho totalmente qualificado do arquivo de disco do documento.

```
const CString& GetPathName() const;
```

### <a name="return-value"></a>Valor retornado

O documento é totalmente qualificado. Esta seqüência está vazia se o documento não tiver sido salvo ou não tiver um arquivo de disco associado a ele.

## <a name="cdocumentgetthumbnail"></a><a name="getthumbnail"></a>CDocument::GetThumbnail

Cria um bitmap a ser usado pelo provedor de miniaturas para exibir a miniatura.

```
virtual BOOL GetThumbnail(
    UINT cx,
    HBITMAP* phbmp,
    DWORD* pdwAlpha);
```

### <a name="parameters"></a>Parâmetros

*Cx*<br/>
Especifica a largura e a altura do bitmap.

*phbmp*<br/>
Contém uma alça para um bitmap, quando a função retorna com sucesso.

*pdwAlpha*<br/>
Contém um DWORD especificando o valor do canal alfa, quando a função retorna com sucesso.

### <a name="return-value"></a>Valor retornado

Retorna TRUE se um bitmap para a miniatura foi criado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cdocumentgettitle"></a><a name="gettitle"></a>CDocument::GetTitle

Ligue para esta função para obter o título do documento, que geralmente é derivado do nome de arquivo do documento.

```
const CString& GetTitle() const;
```

### <a name="return-value"></a>Valor retornado

O título do documento.

## <a name="cdocumentinitializesearchcontent"></a><a name="initializesearchcontent"></a>CDocument::InitializeSearchContent

Chamado para inicializar o conteúdo da pesquisa para o Manipulador de Pesquisa.

```
virtual void InitializeSearchContent ();
```

### <a name="remarks"></a>Comentários

Substituir este método em uma classe derivada para inicializar o conteúdo da pesquisa. O conteúdo deve ser uma seqüência com peças delimitadas por ";". Por exemplo, "ponto; retângulo; item ole".

## <a name="cdocumentismodified"></a><a name="ismodified"></a>documento C::IsModified

Ligue para esta função para determinar se o documento foi modificado desde que foi salvo pela última vez.

```
virtual BOOL IsModified();
```

### <a name="return-value"></a>Valor retornado

Não zero se o documento foi modificado desde a última vez que foi salvo; caso contrário, 0.

## <a name="cdocumentissearchandorganizehandler"></a><a name="issearchandorganizehandler"></a>cdocument::issearchandorganizehandler

Informa se essa `CDocument` instância foi criada para o manipulador Search & Organize.

```
BOOL IsSearchAndOrganizeHandler() const;
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se `CDocument` esta instância de foi criada para o manipulador Search & Organize.

### <a name="remarks"></a>Comentários

Atualmente, essa função retorna TRUE apenas para manipuladores Rich Preview implementados em um servidor fora do processo. Você pode definir as bandeiras apropriadas (m_bPreviewHandlerMode, m_bSearchMode, m_bGetThumbnailMode) no nível de aplicação para fazer com que essa função retorne TRUE.

## <a name="cdocumentloaddocumentfromstream"></a><a name="loaddocumentfromstream"></a>CDocument::LoadDocumentFromStream

Chamado para carregar dados de documentos de um fluxo.

```
virtual HRESULT LoadDocumentFromStream(
    IStream* pStream,
    DWORD dwGrfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um córrego. Este fluxo é fornecido pela Shell.

*dwGrfMode*<br/>
Modo de acesso ao fluxo.

### <a name="return-value"></a>Valor retornado

S_OK se a operação de carga for bem sucedida, caso contrário HRESULT com um código de erro.

### <a name="remarks"></a>Comentários

Você pode substituir este método em uma classe derivada para personalizar como carregar dados do fluxo.

## <a name="cdocumentm_bgetthumbnailmode"></a><a name="m_bgetthumbnailmode"></a>CDocument::m_bGetThumbnailMode

Especifica que `CDocument` o objeto foi criado por dllhost para miniaturas. Deve ser `CView::OnDraw`verificado.

```
BOOL m_bGetThumbnailMode;
```

### <a name="remarks"></a>Comentários

`TRUE`indica que o documento foi criado por dllhost para miniaturas.

## <a name="cdocumentm_bpreviewhandlermode"></a><a name="m_bpreviewhandlermode"></a>CDocument::m_bPreviewHandlerMode

Especifica que `CDocument` o objeto foi criado pelo prevhost para Visualização Rica. Deve ser `CView::OnDraw`verificado.

```
BOOL m_bPreviewHandlerMode;
```

### <a name="remarks"></a>Comentários

TRUE indica que o documento foi criado pelo prevhost para Rich Preview.

## <a name="cdocumentm_bsearchmode"></a><a name="m_bsearchmode"></a>CDocument::m_bSearchMode

Especifica que `CDocument` o objeto foi criado por indexador ou por outro aplicativo de pesquisa.

```
BOOL m_bSearchMode;
```

### <a name="remarks"></a>Comentários

`TRUE`indica que o documento foi criado por indexador ou por outro aplicativo de pesquisa.

## <a name="cdocumentm_clrrichpreviewbackcolor"></a><a name="m_clrrichpreviewbackcolor"></a>CDocument::m_clrRichPreviewBackColor

Especifica a cor de fundo da janela 'Visualização'. Esta cor é definida pelo host.

```
COLORREF m_clrRichPreviewBackColor;
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentm_clrrichpreviewtextcolor"></a><a name="m_clrrichpreviewtextcolor"></a>CDocument::m_clrRichPreviewTextColor

Especifica a cor do primeiro plano da janela 'Visualização' de rich. Esta cor é definida pelo host.

```
COLORREF m_clrRichPreviewTextColor;
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentm_lfrichpreviewfont"></a><a name="m_lfrichpreviewfont"></a>CDocument::m_lfRichPreviewFont

Especifica a fonte de texto para a janela 'Visualização'. Essas informações da fonte são definidas pelo host.

```
CFont m_lfRichPreviewFont;
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonbeforerichpreviewfontchanged"></a><a name="onbeforerichpreviewfontchanged"></a>cDocument::OnbeforeRichPreviewFontChanged

Chamado antes que a fonte Rich Preview seja alterada.

```
virtual void OnBeforeRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonchangedviewlist"></a><a name="onchangedviewlist"></a>cDocument::OnChangedExibilist

Chamado pelo framework depois que uma exibição é adicionada ou removida do documento.

```
virtual void OnChangedViewList();
```

### <a name="remarks"></a>Comentários

A implementação padrão desta função verifica se a última exibição está sendo removida e, se for o caso, exclui o documento. Anular essa função se você quiser realizar um processamento especial quando a estrutura adicionar ou remover uma exibição. Por exemplo, se você quiser que um documento permaneça aberto mesmo quando não houver exibições anexadas a ele, anule essa função.

## <a name="cdocumentonclosedocument"></a><a name="onclosedocument"></a>CDocument::OnCloseDocument

Chamado pelo framework quando o documento é fechado, normalmente como parte do comando File Close.

```
virtual void OnCloseDocument();
```

### <a name="remarks"></a>Comentários

A implementação padrão desta função destrói todos os quadros usados para visualizar o documento, fecha a exibição, limpa o conteúdo do documento e, em seguida, chama a função de membro [DeleteContents](#deletecontents) para excluir os dados do documento.

Anular essa função se você quiser realizar um processamento especial de limpeza quando a estrutura fechar um documento. Por exemplo, se o documento representa um registro em um banco de dados, você pode querer substituir essa função para fechar o banco de dados. Você deve chamar a versão de classe base desta função a partir de sua substituição.

## <a name="cdocumentoncreatepreviewframe"></a><a name="oncreatepreviewframe"></a>cDocument::OnCreatePreviewFrame

Chamado pela estrutura quando precisa criar um quadro de visualização para Rich Preview.

```
virtual BOOL OnCreatePreviewFrame();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o quadro for criado com sucesso; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

## <a name="cdocumentondocumentevent"></a><a name="ondocumentevent"></a>CDocument::OnDocumentEvent

Chamado pelo quadro em resposta a um evento documental.

```
virtual void OnDocumentEvent(DocumentEvent deEvent);
```

### <a name="parameters"></a>Parâmetros

*deEvent*<br/>
[em] Um tipo de dados enumerado que descreve o tipo de evento.

### <a name="remarks"></a>Comentários

Eventos de documentos podem afetar várias classes. Este método é responsável por lidar com eventos documentais que afetam classes diferentes da [Classe CDocument](../../mfc/reference/cdocument-class.md). Atualmente, a única classe que deve responder a eventos de documentos é a [Classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md). A `CDocument` classe possui outros métodos substituíníveis responsáveis por `CDocument`lidar com o efeito sobre o .

A tabela a seguir lista os possíveis valores para *deSevento* e os eventos a que correspondem.

|Valor|Evento Correspondente|
|-----------|-------------------------|
|`onAfterNewDocument`|Um novo documento foi criado.|
|`onAfterOpenDocument`|Um novo documento foi aberto.|
|`onAfterSaveDocument`|O documento foi salvo.|
|`onAfterCloseDocument`|O documento foi fechado.|

## <a name="cdocumentondrawthumbnail"></a><a name="ondrawthumbnail"></a>CDocument::OnDrawThumbnail

Anular este método em uma classe derivada para desenhar a miniatura.

```
virtual void OnDrawThumbnail(
    CDC& dc,
    LPRECT lprcBounds);
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
Uma referência a um contexto de dispositivo.

*lprcBounds*<br/>
Especifica um retângulo delimitador da área onde a miniatura deve ser desenhada.

### <a name="remarks"></a>Comentários

## <a name="cdocumentonfilesendmail"></a><a name="onfilesendmail"></a>cdocument::OnFileSendMail

Envia uma mensagem através do host de correio residente (se houver) com o documento como anexo.

```
void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail`chama [o OnSaveDocument](#onsavedocument) para serializar (salvar) documentos sem título e modificados para um arquivo temporário, que é então enviado via correio eletrônico. Se o documento não tiver sido modificado, um arquivo temporário não será necessário; o original é enviado. `OnFileSendMail`cargas MAPI32. DLL se ainda não tiver sido carregado.

Uma implementação `OnFileSendMail` especial do [COleDocument](../../mfc/reference/coledocument-class.md) lida com arquivos compostos corretamente.

`CDocument`suporta o envio do seu documento via correio se o suporte de e-mail (MAPI) estiver presente. Veja os artigos [MAPI Topics](../../mfc/mapi.md) e [MAPI Support in MFC](../../mfc/mapi-support-in-mfc.md).

## <a name="cdocumentonloaddocumentfromstream"></a><a name="onloaddocumentfromstream"></a>cDocument::OnloadDocumentFromStream

Chamado pela estrutura quando precisa carregar os dados do documento de um fluxo.

```
virtual HRESULT OnLoadDocumentFromStream(
    IStream* pStream,
    DWORD grfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um fluxo de entrada.

*Grfmode*<br/>
Modo de acesso ao fluxo.

### <a name="return-value"></a>Valor retornado

S_OK se a carga for bem sucedida; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

## <a name="cdocumentonnewdocument"></a><a name="onnewdocument"></a>CDocument::OnNewDocument

Chamado pela estrutura como parte do comando File New.

```
virtual BOOL OnNewDocument();
```

### <a name="return-value"></a>Valor retornado

Não zero se o documento foi inicializado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão desta função chama a função de membro [DeleteContents](#deletecontents) para garantir que o documento esteja vazio e, em seguida, marca o novo documento como limpo. Substituir essa função para inicializar a estrutura de dados de um novo documento. Você deve chamar a versão de classe base desta função a partir de sua substituição.

Se o usuário escolher o comando Arquivo Novo em um aplicativo SDI, a estrutura usará essa função para reinicializar o documento existente, em vez de criar um novo. Se o usuário escolher O Arquivo Novo em um aplicativo de interface de documento múltiplo (MDI), a estrutura criará um novo documento a cada vez e, em seguida, chamará essa função para inicializá-lo. Você deve colocar seu código de inicialização nesta função em vez de no construtor para que o comando File New seja eficaz em aplicativos SDI.

Note que há `OnNewDocument` casos em que é chamado duas vezes. Isso ocorre quando o documento é incorporado como um Servidor de Documentos ActiveX. A função é primeiramente chamada pelo `CreateInstance` `COleObjectFactory`método (exposto pela classe derivada) e uma segunda vez pelo `InitNew` método (exposto pela classe `COleServerDoc`derivada).

### <a name="example"></a>Exemplo

Os exemplos a seguir ilustram métodos alternativos de inicialização de um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

## <a name="cdocumentonopendocument"></a><a name="onopendocument"></a>CDocument::OnOpenDocument

Chamado pela estrutura como parte do comando File Open.

```
virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
Aponta para o caminho do documento a ser aberto.

### <a name="return-value"></a>Valor retornado

Não zero se o documento foi carregado com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão desta função abre o arquivo especificado, chama a função de membro [DeleteContents](#deletecontents) para garantir que o documento esteja vazio, chama [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para ler o conteúdo do arquivo e, em seguida, marca o documento como limpo. Anular esta função se você quiser usar algo diferente do mecanismo de arquivo ou do mecanismo de arquivo. Por exemplo, você pode escrever um aplicativo onde documentos representam registros em um banco de dados em vez de arquivos separados.

Se o usuário escolher o comando Abrir arquivos em um aplicativo SDI, a `CDocument` estrutura usará essa função para reinicializar o objeto existente, em vez de criar um novo. Se o usuário escolher Abrir arquivo em um aplicativo MDI, a estrutura construirá um novo `CDocument` objeto a cada vez e, em seguida, chamará essa função para inicializá-lo. Você deve colocar seu código de inicialização nesta função em vez de no construtor para que o comando File Open seja eficaz em aplicativos SDI.

### <a name="example"></a>Exemplo

Os exemplos a seguir ilustram métodos alternativos de inicialização de um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

[!code-cpp[NVC_MFCDocView#63](../../mfc/codesnippet/cpp/cdocument-class_8.cpp)]

## <a name="cdocumentonpreviewhandlerqueryfocus"></a><a name="onpreviewhandlerqueryfocus"></a>CDocument::OnPreviewHandlerQueryFocus

Orienta o manipulador de visualização a retornar o `GetFocus` HWND recuperado ao chamar a função.

```
virtual HRESULT OnPreviewHandlerQueryFocus(HWND* phwnd);
```

### <a name="parameters"></a>Parâmetros

*phwnd*<br/>
[fora] Quando este método retorna, contém um ponteiro para o `GetFocus` HWND retornado de chamar a função a partir do segmento de primeiro plano do manipulador de visualização.

### <a name="return-value"></a>Valor retornado

Os retornos S_OK se forem bem sucedidos; ou um valor de erro de outra forma.

### <a name="remarks"></a>Comentários

## <a name="cdocumentonpreviewhandlertranslateaccelerator"></a><a name="onpreviewhandlertranslateaccelerator"></a>cDocument::OnPreviewHandlerTranslateAccelerator

Direciona o manipulador de visualização para lidar com um pressionamento de teclas passado da bomba de mensagem do processo em que o manipulador de visualização está sendo executado.

```
virtual HRESULT OnPreviewHandlerTranslateAccelerator(MSG* pmsg);
```

### <a name="parameters"></a>Parâmetros

*pmsg*<br/>
[em] Um ponteiro para uma mensagem de janela.

### <a name="return-value"></a>Valor retornado

Se a mensagem de tecla for processada pelo manipulador de visualização, o manipulador a processa e retorna S_OK. Se o manipulador de visualização não puder processar a `IPreviewHandlerFrame::TranslateAccelerator`mensagem de digitação, ela a oferecerá ao host via . Se o host processa a mensagem, esse método retorna S_OK. Se o host não processar a mensagem, este método volta S_FALSE.

### <a name="remarks"></a>Comentários

## <a name="cdocumentonrichpreviewbackcolorchanged"></a><a name="onrichpreviewbackcolorchanged"></a>cdocument::OnrichPreviewBackColorChanged

Chamado quando a cor de fundo do Rich Preview mudou.

```
virtual void OnRichPreviewBackColorChanged();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonrichpreviewfontchanged"></a><a name="onrichpreviewfontchanged"></a>cDocument::OnrichPreviewFontChanged

Chamado quando a fonte Rich Preview foi alterada.

```
virtual void OnRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonrichpreviewsitechanged"></a><a name="onrichpreviewsitechanged"></a>CDocument::OnrichPreviewsiteAlterado

Chamado quando o site Rich Preview mudou.

```
virtual void OnRichPreviewSiteChanged();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonrichpreviewtextcolorchanged"></a><a name="onrichpreviewtextcolorchanged"></a>CDocument::OnrichPreviewTextColorAlterado

Chamado quando a cor do texto Rich Preview foi alterada.

```
virtual void OnRichPreviewTextColorChanged();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonsavedocument"></a><a name="onsavedocument"></a>cdocument::OnSaveDocument

Chamado pela estrutura como parte do comando Salvar ou Salvar arquivos como: 'Salvar arquivos'.

```
virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
Aponta para o caminho totalmente qualificado para o qual o arquivo deve ser salvo.

### <a name="return-value"></a>Valor retornado

Não zero se o documento foi salvo com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão desta função abre o arquivo especificado, chama [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para gravar os dados do documento no arquivo e, em seguida, marca o documento como limpo. Anular essa função se você quiser realizar um processamento especial quando a estrutura salvar um documento. Por exemplo, você pode escrever um aplicativo onde documentos representam registros em um banco de dados em vez de arquivos separados.

## <a name="cdocumentonunloadhandler"></a><a name="onunloadhandler"></a>cDocument::OnUnloadHandler

Chamado pela estrutura quando o manipulador de visualização é descarregado.

```
virtual void OnUnloadHandler();
```

### <a name="remarks"></a>Comentários

## <a name="cdocumentonupdatefilesendmail"></a><a name="onupdatefilesendmail"></a>cdocument::OnUpdateFileSendMail

Habilita o comando ID_FILE_SEND_MAIL se o suporte de e-mail (MAPI) estiver presente.

```
void OnUpdateFileSendMail(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para o objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) associado ao comando ID_FILE_SEND_MAIL.

### <a name="remarks"></a>Comentários

Caso contrário, a função remove o comando ID_FILE_SEND_MAIL do menu, incluindo separadores acima ou abaixo do item do menu conforme apropriado. Mapi está habilitado se MAPI32. DLL está presente no caminho e, na seção [Correio] do WIN. Arquivo INI, MAPI=1. A maioria dos aplicativos coloca este comando no menu Arquivo.

`CDocument`suporta o envio do seu documento via correio se o suporte de e-mail (MAPI) estiver presente. Veja os artigos [MAPI Topics](../../mfc/mapi.md) e [MAPI Support in MFC](../../mfc/mapi-support-in-mfc.md).

## <a name="cdocumentprecloseframe"></a><a name="precloseframe"></a>CDocument::PreCloseFrame

Esta função de membro é chamada pela estrutura antes que a janela do quadro seja destruída.

```
virtual void PreCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) `CDocument` que contém o objeto associado.

### <a name="remarks"></a>Comentários

Ele pode ser substituído para fornecer limpeza personalizada, mas certifique-se de chamar a classe base também.

O padrão `PreCloseFrame` de `CDocument`não faz nada em . As `CDocument`classes derivadas [COleDocument](../../mfc/reference/coledocument-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) usam essa função de membro.

## <a name="cdocumentreadnextchunkvalue"></a><a name="readnextchunkvalue"></a>cDocument::ReadNextChunkValue

Lê o próximo valor em pedaços.

```
virtual BOOL ReadNextChunkValue(IFilterChunkValue** ppValue);
```

### <a name="parameters"></a>Parâmetros

*Ppvalue*<br/>
[fora] Quando a função retorna, *ppValue* contém o valor lido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cdocumentreleasefile"></a><a name="releasefile"></a>CDocument::ReleaseFile

Esta função de membro é chamada pela estrutura para liberar um arquivo, tornando-o disponível para uso por outros aplicativos.

```
virtual void ReleaseFile(
    CFile* pFile,
    BOOL bAbort);
```

### <a name="parameters"></a>Parâmetros

*Pfile*<br/>
Um ponteiro para o objeto CFile a ser liberado.

*bAbort*<br/>
Especifica se o arquivo deve ser `CFile::Close` liberado `CFile::Abort`usando ou . FALSO se o arquivo for liberado usando [CFile::Close](../../mfc/reference/cfile-class.md#close); TRUE se o arquivo for liberado usando [CFile:::Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="remarks"></a>Comentários

Se *bAbort* for `ReleaseFile` `CFile::Abort`TRUE, chamadas e o arquivo será liberado. `CFile::Abort`não vai jogar uma exceção.

Se *bAbort* for `ReleaseFile` `CFile::Close` FALSO, chamadas e o arquivo será liberado.

Substituir essa função de membro para exigir uma ação do usuário antes que o arquivo seja liberado.

## <a name="cdocumentremovechunk"></a><a name="removechunk"></a>cDocument::RemoveChunk

Remove um pedaço com o GUID especificado.

```
virtual void RemoveChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*Guid*<br/>
Especifica o GUID de um pedaço a ser removido.

*Pid*<br/>
Especifica o PID de um pedaço a ser removido.

### <a name="remarks"></a>Comentários

## <a name="cdocumentremoveview"></a><a name="removeview"></a>CDocument::RemoveView

Chame esta função para desvincular uma exibição de um documento.

```
void RemoveView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pVer*<br/>
Aponta para a vista sendo removida.

### <a name="remarks"></a>Comentários

Esta função remove a exibição especificada da lista de visualizações associadas ao documento; ele também define o ponteiro do documento da exibição como NULO. Esta função é chamada pela estrutura quando uma janela de quadro é fechada ou um painel de uma janela de divisor é fechado.

Chame esta função somente se você estiver desvinculando manualmente uma exibição. Normalmente, você permitirá que a estrutura desconecte documentos e exibições definindo um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para associar uma classe de documentos, exibir classe e classe de janela de quadro.

Consulte o exemplo no [AddView](#addview) para obter uma implementação de amostra.

## <a name="cdocumentreportsaveloadexception"></a><a name="reportsaveloadexception"></a>CDocument::RelatórioEconomiadeeconomiadecarregamentodesexcedesdes

Chamado se uma exceção for lançada (tipicamente um [CFileException](../../mfc/reference/cfileexception-class.md) ou [CArchiveException](../../mfc/reference/carchiveexception-class.md)) enquanto salva ou carrega o documento.

```
virtual void ReportSaveLoadException(
    LPCTSTR lpszPathName,
    CException* e,
    BOOL bSaving,
    UINT nIDPDefault);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
Aponta para o nome do documento que estava sendo salvo ou carregado.

*e*<br/>
Aponta para a exceção que foi lançada. Pode ser NULO.

*bSaving*<br/>
Bandeira indicando que operação estava em andamento; não zero se o documento estava sendo salvo, 0 se o documento estava sendo carregado.

*nIDPDefault*<br/>
Identificador da mensagem de erro a ser exibida se a função não especificar uma mais específica.

### <a name="remarks"></a>Comentários

A implementação padrão examina o objeto de exceção e procura uma mensagem de erro que descreve especificamente a causa. Se uma mensagem específica não for encontrada ou se *e* for NULL, a mensagem geral especificada pelo parâmetro *nIDPDefault* será usada. Em seguida, a função exibe uma caixa de mensagem contendo a mensagem de erro. Anular esta função se você quiser fornecer mensagens de falha adicionais e personalizadas. Este é um avançado super-rididável.

## <a name="cdocumentsavemodified"></a><a name="savemodified"></a>cdocument::SaveModified

Chamado pelo quadro antes de um documento modificado deve ser fechado.

```
virtual BOOL SaveModified();
```

### <a name="return-value"></a>Valor retornado

Não zero se for seguro continuar e fechar o documento; 0 se o documento não for fechado.

### <a name="remarks"></a>Comentários

A implementação padrão desta função exibe uma caixa de mensagem perguntando ao usuário se deve salvar as alterações no documento, se alguma foi feita. Anular esta função se o seu programa exigir um procedimento de solicitação diferente. Este é um avançado super-rididável.

## <a name="cdocumentsetchunkvalue"></a><a name="setchunkvalue"></a>CDocument::SetChunkValue

Define um valor de pedaço.

```
virtual BOOL SetChunkValue (IFilterChunkValue* pValue);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Especifica um valor de pedaço a ser definido.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

## <a name="cdocumentsetmodifiedflag"></a><a name="setmodifiedflag"></a>cDocument::SetModifiedFlag

Ligue para esta função depois de ter feito qualquer modificação no documento.

```
virtual void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModificado*<br/>
Bandeira indicando se o documento foi modificado.

### <a name="remarks"></a>Comentários

Ao chamar essa função de forma consistente, você garante que a estrutura solicita ao usuário que salve alterações antes de fechar um documento. Normalmente, você deve usar o valor padrão de TRUE para o parâmetro *bModified.* Para marcar um documento como limpo (não modificado), chame esta função com um valor de FALSE.

## <a name="cdocumentsetpathname"></a><a name="setpathname"></a>CDocument::Set's's

Chame esta função para especificar o caminho totalmente qualificado do arquivo de disco do documento.

```
virtual void SetPathName(
    LPCTSTR lpszPathName,
    BOOL bAddToMRU = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
Aponta para a string a ser usada como o caminho para o documento.

*bAddToMRU*<br/>
Determina se o nome do arquivo é adicionado à lista de arquivos mais recentemente usada (MRU). Se TRUE, o nome do arquivo será adicionado; se FALSO, ele não é adicionado.

### <a name="remarks"></a>Comentários

Dependendo do valor de *bAddToMRU,* o caminho é adicionado, ou não, à lista MRU mantida pelo aplicativo. Observe que alguns documentos não estão associados a um arquivo de disco. Chame esta função somente se você estiver substituindo a implementação padrão para abrir e salvar arquivos usados pela estrutura.

## <a name="cdocumentsettitle"></a><a name="settitle"></a>CDocument::SetTitle

Chame esta função para especificar o título do documento (a seqüência exibida na barra de título de uma janela de quadro).

```
virtual void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Aponta para a string a ser usada como título do documento.

### <a name="remarks"></a>Comentários

Chamar essa função atualiza os títulos de todas as janelas de quadro sustil que exibem o documento.

## <a name="cdocumentupdateallviews"></a><a name="updateallviews"></a>CDocument::UpdateAllViews

Ligue para esta função depois que o documento tiver sido modificado.

```
void UpdateAllViews(
    CView* pSender,
    LPARAM lHint = 0L,
    CObject* pHint = NULL);
```

### <a name="parameters"></a>Parâmetros

*Psender*<br/>
Aponta para a visão que modificou o documento, ou NULL se todas as visualizações forem atualizadas.

*Lhint*<br/>
Contém informações sobre a modificação.

*Phint*<br/>
Aponta para um objeto que armazena informações sobre a modificação.

### <a name="remarks"></a>Comentários

Você deve chamar esta função depois de chamar a função de membro [SetModifiedFlag.](#setmodifiedflag) Esta função informa cada exibição anexada ao documento, exceto a exibição especificada pelo *pSender,* que o documento foi modificado. Você normalmente chama essa função de sua classe de exibição depois que o usuário alterou o documento através de uma exibição.

Esta função chama a função [cView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) para cada uma das visualizações do documento, exceto a exibição de envio, passando *pHint* e *lHint*. Use esses parâmetros para passar informações às opiniões sobre as modificações feitas no documento. Você pode codificar informações usando *lHint* e/ou você pode definir uma classe derivada do [CObject](../../mfc/reference/cobject-class.md)para armazenar informações sobre as modificações e passar um objeto dessa classe usando *pHint*. Substituir a `CView::OnUpdate` função de membro em sua classe derivada do [CView](../../mfc/reference/cview-class.md)para otimizar a atualização do visor da exibição com base nas informações passadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#64](../../mfc/codesnippet/cpp/cdocument-class_9.cpp)]

## <a name="see-also"></a>Confira também

[MFC Amostra MDIDOCVW](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC SNAPVW](../../overview/visual-cpp-samples.md)<br/>
[Amostra De MFC NPP](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)
