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
ms.openlocfilehash: 2d87ff67000fb5b70c0a5c965638875e6f50b22c
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856755"
---
# <a name="cdocument-class"></a>Classe CDocument

Fornece a funcionalidade básica para classes de documento definidas pelo usuário.

## <a name="syntax"></a>Sintaxe

```
class CDocument : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocument:: CDocument](#cdocument)|Constrói um objeto `CDocument`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocument:: AddView](#addview)|Anexa uma exibição ao documento.|
|[CDocument:: BeginReadChunks](#beginreadchunks)|Inicializa a leitura da parte.|
|[CDocument:: CanCloseFrame](#cancloseframe)|Resubstituível avançado; chamado antes de fechar uma janela do quadro exibindo este documento.|
|[CDocument:: ClearChunkList](#clearchunklist)|Limpa a lista de partes.|
|[CDocument:: ClearPathName](#clearpathname)|Limpa o caminho do objeto de documento.|
|[CDocument::D eleteContents](#deletecontents)|Chamado para executar a limpeza do documento.|
|[CDocument:: FindChunk](#findchunk)|Procura uma parte com GUID especificado.|
|[CDocument:: getadapter](#getadapter)|Retorna um ponteiro para objeto que implementa `IDocument` interface.|
|[CDocument:: GetDocTemplate](#getdoctemplate)|Retorna um ponteiro para o modelo de documento que descreve o tipo do documento.|
|[CDocument:: GetFile](#getfile)|Retorna um ponteiro para o objeto de `CFile` desejado.|
|[CDocument:: GetFirstViewPosition](#getfirstviewposition)|Retorna a posição do primeiro na lista de exibições; usado para iniciar a iteração.|
|[CDocument:: GetNextView](#getnextview)|Itera na lista de exibições associadas ao documento.|
|[CDocument:: GetPathName](#getpathname)|Retorna o caminho do arquivo de dados do documento.|
|[CDocument:: GetThumbnail](#getthumbnail)|Chamado para criar um bitmap a ser usado pelo provedor de miniatura para exibir a miniatura.|
|[CDocument:: getTitle](#gettitle)|Retorna o título do documento.|
|[CDocument:: InitializeSearchContent](#initializesearchcontent)|Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.|
|[CDocument:: IsModified](#ismodified)|Indica se o documento foi modificado desde que foi salvo pela última vez.|
|[CDocument:: IsSearchAndOrganizeHandler](#issearchandorganizehandler)|Informa se esta instância do objeto `CDocument` foi criada para o manipulador de organização de & de pesquisa.|
|[CDocument:: LoadDocumentFromStream](#loaddocumentfromstream)|Chamado para carregar dados de documento do fluxo.|
|[CDocument:: OnBeforeRichPreviewFontChanged](#onbeforerichpreviewfontchanged)|Chamado antes da alteração da fonte de visualização avançada.|
|[CDocument:: OnChangedViewList](#onchangedviewlist)|Chamado depois que uma exibição é adicionada ou removida do documento.|
|[CDocument:: OnCloseDocument](#onclosedocument)|Chamado para fechar o documento.|
|[CDocument:: OnCreatePreviewFrame](#oncreatepreviewframe)|Chamado pelo Framework quando ele precisa criar um quadro de visualização para visualização avançada.|
|[CDocument:: OnDocumentEvent](#ondocumentevent)|Chamado pelo Framework em resposta a um evento de documento.|
|[CDocument:: OnDrawThumbnail](#ondrawthumbnail)|Substitua esse método em uma classe derivada para desenhar o conteúdo de miniatura.|
|[CDocument:: OnLoadDocumentFromStream](#onloaddocumentfromstream)|Chamado pelo Framework quando ele precisa carregar os dados do documento do fluxo.|
|[CDocument:: OnNewDocument](#onnewdocument)|Chamado para criar um novo documento.|
|[CDocument:: OnOpenDocument](#onopendocument)|Chamado para abrir um documento existente.|
|[CDocument:: OnPreviewHandlerQueryFocus](#onpreviewhandlerqueryfocus)|Direciona o Gerenciador de visualização para retornar o HWND de chamar a função GetFocus.|
|[CDocument:: OnPreviewHandlerTranslateAccelerator](#onpreviewhandlertranslateaccelerator)|Direciona o Gerenciador de visualização para manipular um pressionamento de tecla passado da bomba de mensagem do processo no qual o Gerenciador de visualização está em execução.|
|[CDocument:: OnRichPreviewBackColorChanged](#onrichpreviewbackcolorchanged)|Chamado quando a cor de fundo da visualização avançada é alterada.|
|[CDocument:: OnRichPreviewFontChanged](#onrichpreviewfontchanged)|Chamado quando a fonte da visualização avançada é alterada.|
|[CDocument:: OnRichPreviewSiteChanged](#onrichpreviewsitechanged)|Chamado quando o site de visualização avançada é alterado.|
|[CDocument:: OnRichPreviewTextColorChanged](#onrichpreviewtextcolorchanged)|Chamado quando a cor do texto de visualização avançada é alterada.|
|[CDocument:: OnSaveDocument](#onsavedocument)|Chamado para salvar o documento em disco.|
|[CDocument:: OnUnloadHandler](#onunloadhandler)|Chamado pelo Framework quando o Gerenciador de visualização está sendo descarregado.|
|[CDocument::P reCloseFrame](#precloseframe)|Chamado antes da janela do quadro ser fechada.|
|[CDocument:: ReadNextChunkValue](#readnextchunkvalue)|Lê o valor da próxima parte.|
|[CDocument:: ReleaseFile](#releasefile)|Libera um arquivo para torná-lo disponível para uso por outros aplicativos.|
|[CDocument:: RemoveChunk](#removechunk)|Remove uma parte com GUID especificado.|
|[CDocument:: RemoveView](#removeview)|Desanexa uma exibição do documento.|
|[CDocument:: ReportSaveLoadException](#reportsaveloadexception)|Resubstituível avançado; chamado quando uma operação abrir ou salvar não pode ser concluída devido a uma exceção.|
|[CDocument:: SaveModified](#savemodified)|Resubstituível avançado; chamado para perguntar ao usuário se o documento deve ser salvo.|
|[CDocument:: setchunkvalue](#setchunkvalue)|Define um valor de parte.|
|[CDocument:: SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica que você modificou o documento desde que ele foi salvo pela última vez.|
|[CDocument:: setpathname](#setpathname)|Define o caminho do arquivo de dados usado pelo documento.|
|[CDocument:: SetTitle](#settitle)|Define o título do documento.|
|[CDocument:: UpdateAllViews](#updateallviews)|Notifica todas as exibições que o documento foi modificado.|

### <a name="protected-methods"></a>Métodos protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocument:: OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|
|[CDocument:: OnUpdateFileSendMail](#onupdatefilesendmail)|Habilita o comando enviar email se o suporte a email estiver presente.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocument:: m_bGetThumbnailMode](#m_bgetthumbnailmode)|Especifica que `CDocument` objeto foi criado pelo Dllhost para miniaturas. Deve ser feito o check-in `CView::OnDraw`.|
|[CDocument:: m_bPreviewHandlerMode](#m_bpreviewhandlermode)|Especifica que `CDocument` objeto foi criado pelo prevhost para `Rich Preview`. Deve ser feito o check-in `CView::OnDraw`.|
|[CDocument:: m_bSearchMode](#m_bsearchmode)|Especifica que `CDocument` objeto foi criado pelo indexador ou outro aplicativo de pesquisa.|
|[CDocument:: m_clrRichPreviewBackColor](#m_clrrichpreviewbackcolor)|Especifica a cor do plano de fundo da janela de visualização rica. Essa cor é definida pelo host.|
|[CDocument:: m_clrRichPreviewTextColor](#m_clrrichpreviewtextcolor)|Especifica a cor de primeiro plano da janela de visualização rica. Essa cor é definida pelo host.|
|[CDocument:: m_lfRichPreviewFont](#m_lfrichpreviewfont)|Especifica a fonte do texto para a janela de visualização avançada. Essas informações de fonte são definidas pelo host.|

## <a name="remarks"></a>Comentários

Um documento representa a unidade de dados que o usuário normalmente abre com o comando File Open e salva com o comando File Save.

o `CDocument` dá suporte a operações padrão, como criar um documento, carregá-lo e salvá-lo. A estrutura manipula documentos usando a interface definida por `CDocument`.

Um aplicativo pode dar suporte a mais de um tipo de documento; por exemplo, um aplicativo pode dar suporte a planilhas e documentos de texto. Cada tipo de documento tem um modelo de documento associado; o modelo de documento especifica quais recursos (por exemplo, menu, ícone ou tabela de aceleração) são usados para esse tipo de documento. Cada documento contém um ponteiro para seu objeto `CDocTemplate` associado.

Os usuários interagem com um documento por meio dos objetos [cvisualização](../../mfc/reference/cview-class.md) associados a ele. Uma exibição renderiza uma imagem do documento em uma janela do quadro e interpreta a entrada do usuário como operações no documento. Um documento pode ter várias exibições associadas a ele. Quando o usuário abre uma janela em um documento, a estrutura cria uma exibição e a anexa ao documento. O modelo de documento especifica que tipo de exibição e janela de quadro são usados para exibir cada tipo de documento.

Os documentos fazem parte do roteamento de comandos padrão da estrutura e, consequentemente, recebem comandos de componentes padrão da interface do usuário (como o item de menu salvar arquivo). Um documento recebe comandos encaminhados pelo modo de exibição ativo. Se o documento não tratar de um determinado comando, ele encaminhará o comando para o modelo de documento que o gerencia.

Quando os dados de um documento são modificados, cada uma de suas exibições deve refletir essas modificações. `CDocument` fornece a função de membro [UpdateAllViews](#updateallviews) para que você notifique as exibições dessas alterações, para que as exibições possam ser redesenhadas conforme necessário. A estrutura também solicita que o usuário salve um arquivo modificado antes de fechá-lo.

Para implementar documentos em um aplicativo típico, você deve fazer o seguinte:

- Derive uma classe de `CDocument` para cada tipo de documento.

- Adicione variáveis de membro para armazenar os dados de cada documento.

- Implemente funções de membro para ler e modificar os dados do documento. As exibições do documento são os usuários mais importantes dessas funções de membro.

- Substitua a função de membro [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) em sua classe de documento para gravar e ler os dados do documento de e para o disco.

`CDocument` dá suporte ao envio de seu documento por email se o MAPI (suporte de email) estiver presente. Consulte os artigos suporte [MAPI](../../mfc/mapi.md) e [MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

Para obter mais informações sobre `CDocument`, consulte Tópicos de arquitetura de [serialização](../../mfc/serialization-in-mfc.md), [documento/exibição](../../mfc/document-view-architecture.md)e [criação de documento/exibição](../../mfc/document-view-creation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDocument`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="addview"></a>CDocument:: AddView

Chame essa função para anexar uma exibição ao documento.

```
void AddView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pView*<br/>
Aponta para a exibição que está sendo adicionada.

### <a name="remarks"></a>Comentários

Essa função adiciona a exibição especificada à lista de exibições associadas ao documento; a função também define o ponteiro de documento da exibição para este documento. A estrutura chama essa função ao anexar um objeto de exibição recém-criado a um documento; Isso ocorre em resposta a um comando novo arquivo, abrir arquivo ou nova janela ou quando uma janela divisora é dividida.

Chame essa função somente se você estiver criando e anexando manualmente uma exibição. Em geral, você permitirá que o Framework Conecte documentos e exibições definindo um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para associar uma classe de documento, uma classe de exibição e uma classe de janela de quadro.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocViewSDI#12](../../mfc/codesnippet/cpp/cdocument-class_1.cpp)]

##  <a name="beginreadchunks"></a>CDocument:: BeginReadChunks

Inicializa a leitura da parte.

```
virtual void BeginReadChunks ();
```

### <a name="remarks"></a>Comentários

##  <a name="cancloseframe"></a>CDocument:: CanCloseFrame

Chamado pelo Framework antes que uma janela do quadro exibindo o documento seja fechada.

```
virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Aponta para a janela do quadro de uma exibição anexada ao documento.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for seguro fechar a janela do quadro; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão verifica se há outras janelas de quadros exibindo o documento. Se a janela do quadro especificado for a última que exibe o documento, a função solicitará que o usuário salve o documento se ele tiver sido modificado. Substitua essa função se desejar executar processamento especial quando uma janela de quadro for fechada. Esse é um substituível avançado.

##  <a name="cdocument"></a>CDocument:: CDocument

Constrói um objeto `CDocument`.

```
CDocument();
```

### <a name="remarks"></a>Comentários

A estrutura manipula a criação de documentos para você. Substituir a função de membro [OnNewDocument](#onnewdocument) para executar a inicialização por documento; Isso é particularmente importante em aplicativos de SDI (interface de documento único).

##  <a name="clearchunklist"></a>CDocument:: ClearChunkList

Limpa a lista de partes.

```
virtual void ClearChunkList ();
```

### <a name="remarks"></a>Comentários

##  <a name="clearpathname"></a>CDocument:: ClearPathName

Limpa o caminho do objeto de documento.

```
virtual void ClearPathName();
```

### <a name="remarks"></a>Comentários

Limpar o caminho de um objeto de `CDocument` faz com que o aplicativo solicite o usuário quando o documento for salvo em seguida. Isso faz com que um comando **salvar** se comporte como um comando **salvar como** .

##  <a name="deletecontents"></a>CDocument::D eleteContents

Chamado pelo Framework para excluir os dados do documento sem destruir o objeto `CDocument` em si.

```
virtual void DeleteContents();
```

### <a name="remarks"></a>Comentários

Ele é chamado logo antes de o documento ser destruído. Ele também é chamado para garantir que um documento esteja vazio antes de ser reutilizado. Isso é particularmente importante para um aplicativo SDI, que usa apenas um documento; o documento é reutilizado sempre que o usuário cria ou abre outro documento. Chame essa função para implementar um comando "Editar limpar tudo" ou semelhante que exclua todos os dados do documento. A implementação padrão dessa função não faz nada. Substitua essa função para excluir os dados em seu documento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#57](../../mfc/codesnippet/cpp/cdocument-class_2.cpp)]

##  <a name="findchunk"></a>CDocument:: FindChunk

Procura uma parte com um GUID especificado.

```
virtual POSITION FindChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*guid*<br/>
Especifica o GUID de uma parte a ser localizada.

*pid*<br/>
Especifica um PID de uma parte a ser localizada.

### <a name="return-value"></a>Valor retornado

Posição na lista de partes interna se for bem-sucedida. Caso contrário, NULL.

### <a name="remarks"></a>Comentários

##  <a name="getadapter"></a>CDocument:: getadapter

Retorna um ponteiro para um objeto que implementa a interface `IDocument`.

```
virtual ATL::IDocument* GetAdapter();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto que implementa a interface `IDocument`.

### <a name="remarks"></a>Comentários

##  <a name="getdoctemplate"></a>CDocument:: GetDocTemplate

Chame essa função para obter um ponteiro para o modelo de documento para este tipo de documento.

```
CDocTemplate* GetDocTemplate() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o modelo de documento para este tipo de documento, ou NULL se o documento não for gerenciado por um modelo de documento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#58](../../mfc/codesnippet/cpp/cdocument-class_3.cpp)]

##  <a name="getfile"></a>CDocument:: GetFile

Chame essa função de membro para obter um ponteiro para um objeto `CFile`.

```
virtual CFile* GetFile(
    LPCTSTR lpszFileName,
    UINT nOpenFlags,
    CFileException* pError);
```

### <a name="parameters"></a>Parâmetros

*lpszFileName*<br/>
Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.

*pError*<br/>
Um ponteiro para um objeto de exceção de arquivo existente que indica o status de conclusão da operação.

*nOpenFlags*<br/>
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções listadas no construtor de testcfile [::](../../mfc/reference/cfile-class.md#cfile) refigurar usando o&#124;operador OR (bit) or (). Uma permissão de acesso e uma opção de compartilhamento são necessárias; os modos `modeCreate` e `modeNoInherit` são opcionais.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CFile`.

##  <a name="getfirstviewposition"></a>CDocument:: GetFirstViewPosition

Chame essa função para obter a posição da primeira exibição na lista de exibições associadas ao documento.

```
virtual POSITION GetFirstViewPosition() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para iteração com a função de membro [GetNextView](#getnextview) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

##  <a name="getnextview"></a>CDocument:: GetNextView

Chame essa função para iterar em todas as exibições do documento.

```
virtual CView* GetNextView(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*rPosition*<br/>
Uma referência a um valor de posição retornado por uma chamada anterior para as funções de membro `GetNextView` ou [GetFirstViewPosition](#getfirstviewposition) . Esse valor não deve ser nulo.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a exibição identificada por *rPosition*.

### <a name="remarks"></a>Comentários

A função retorna a exibição identificada por *rPosition* e, em seguida, define *rPosition* como o valor de posição da próxima exibição na lista. Se a exibição recuperada for a última na lista, *rPosition* será definido como NULL.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

##  <a name="getpathname"></a>CDocument:: GetPathName

Chame essa função para obter o caminho totalmente qualificado do arquivo de disco do documento.

```
const CString& GetPathName() const;
```

### <a name="return-value"></a>Valor retornado

O caminho totalmente qualificado do documento. Essa cadeia de caracteres estará vazia se o documento não tiver sido salvo ou não tiver um arquivo de disco associado a ele.

##  <a name="getthumbnail"></a>CDocument:: GetThumbnail

Cria um bitmap a ser usado pelo provedor de miniatura para exibir a miniatura.

```
virtual BOOL GetThumbnail(
    UINT cx,
    HBITMAP* phbmp,
    DWORD* pdwAlpha);
```

### <a name="parameters"></a>Parâmetros

*CX*<br/>
Especifica a largura e a altura do bitmap.

*phbmp*<br/>
Contém um identificador para um bitmap, quando a função retorna com êxito.

*pdwAlpha*<br/>
Contém um DWORD especificando o valor do canal alfa, quando a função retorna com êxito.

### <a name="return-value"></a>Valor retornado

Retornará TRUE se um bitmap para a miniatura tiver sido criado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="gettitle"></a>CDocument:: getTitle

Chame essa função para obter o título do documento, que geralmente é derivado do nome de arquivo do documento.

```
const CString& GetTitle() const;
```

### <a name="return-value"></a>Valor retornado

O título do documento.

##  <a name="initializesearchcontent"></a>CDocument:: InitializeSearchContent

Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.

```
virtual void InitializeSearchContent ();
```

### <a name="remarks"></a>Comentários

Substitua esse método em uma classe derivada para inicializar o conteúdo de pesquisa. O conteúdo deve ser uma cadeia de caracteres com partes delimitadas por ";". Por exemplo, "Point; nele item OLE ".

##  <a name="ismodified"></a>CDocument:: IsModified

Chame essa função para determinar se o documento foi modificado desde que foi salvo pela última vez.

```
virtual BOOL IsModified();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento tiver sido modificado desde que foi salvo pela última vez; caso contrário, 0.

##  <a name="issearchandorganizehandler"></a>CDocument:: IsSearchAndOrganizeHandler

Informa se esta instância do `CDocument` foi criada para o manipulador de organização de & de pesquisa.

```
BOOL IsSearchAndOrganizeHandler() const;
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se esta instância do `CDocument` tiver sido criada para o manipulador de organização de & de pesquisa.

### <a name="remarks"></a>Comentários

Atualmente, essa função retorna TRUE somente para manipuladores de visualização avançados implementados em um servidor fora do processo. Você pode definir os sinalizadores apropriados (m_bPreviewHandlerMode, m_bSearchMode, m_bGetThumbnailMode) no nível do aplicativo para fazer com que essa função retorne TRUE.

##  <a name="loaddocumentfromstream"></a>CDocument:: LoadDocumentFromStream

Chamado para carregar dados de documento de um fluxo.

```
virtual HRESULT LoadDocumentFromStream(
    IStream* pStream,
    DWORD dwGrfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um fluxo. Esse fluxo é fornecido pelo shell.

*dwGrfMode*<br/>
Modo de acesso ao fluxo.

### <a name="return-value"></a>Valor retornado

S_OK se a operação de carregamento tiver sucesso, caso contrário, HRESULT com um código de erro.

### <a name="remarks"></a>Comentários

Você pode substituir esse método em uma classe derivada para personalizar como carregar dados do fluxo.

##  <a name="m_bgetthumbnailmode"></a>CDocument:: m_bGetThumbnailMode

Especifica que o objeto de `CDocument` foi criado pelo Dllhost para miniaturas. Deve ser feito o check-in `CView::OnDraw`.

```
BOOL m_bGetThumbnailMode;
```

### <a name="remarks"></a>Comentários

`TRUE` indica que o documento foi criado pelo Dllhost para miniaturas.

##  <a name="m_bpreviewhandlermode"></a>CDocument:: m_bPreviewHandlerMode

Especifica que o objeto `CDocument` foi criado pelo prevhost para visualização avançada. Deve ser feito o check-in `CView::OnDraw`.

```
BOOL m_bPreviewHandlerMode;
```

### <a name="remarks"></a>Comentários

VERDADEIRO indica que o documento foi criado pelo prevhost para visualização avançada.

##  <a name="m_bsearchmode"></a>CDocument:: m_bSearchMode

Especifica que o objeto de `CDocument` foi criado pelo indexador ou por outro aplicativo de pesquisa.

```
BOOL m_bSearchMode;
```

### <a name="remarks"></a>Comentários

`TRUE` indica que o documento foi criado pelo indexador ou por outro aplicativo de pesquisa.

##  <a name="m_clrrichpreviewbackcolor"></a>CDocument:: m_clrRichPreviewBackColor

Especifica a cor do plano de fundo da janela de visualização avançada. Essa cor é definida pelo host.

```
COLORREF m_clrRichPreviewBackColor;
```

### <a name="remarks"></a>Comentários

##  <a name="m_clrrichpreviewtextcolor"></a>CDocument:: m_clrRichPreviewTextColor

Especifica a cor de primeiro plano da janela de visualização avançada. Essa cor é definida pelo host.

```
COLORREF m_clrRichPreviewTextColor;
```

### <a name="remarks"></a>Comentários

##  <a name="m_lfrichpreviewfont"></a>CDocument:: m_lfRichPreviewFont

Especifica a fonte do texto para a janela de visualização avançada. Essas informações de fonte são definidas pelo host.

```
CFont m_lfRichPreviewFont;
```

### <a name="remarks"></a>Comentários

##  <a name="onbeforerichpreviewfontchanged"></a>CDocument:: OnBeforeRichPreviewFontChanged

Chamado antes da alteração da fonte de visualização avançada.

```
virtual void OnBeforeRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onchangedviewlist"></a>CDocument:: OnChangedViewList

Chamado pelo Framework depois que uma exibição é adicionada ou removida do documento.

```
virtual void OnChangedViewList();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função verifica se a última exibição está sendo removida e, em caso afirmativo, exclui o documento. Substitua essa função se desejar executar processamento especial quando a estrutura adicionar ou remover uma exibição. Por exemplo, se você quiser que um documento permaneça aberto mesmo quando não houver exibições anexadas a ele, substitua essa função.

##  <a name="onclosedocument"></a>CDocument:: OnCloseDocument

Chamado pelo Framework quando o documento é fechado, normalmente como parte do comando File Close.

```
virtual void OnCloseDocument();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função destrói todos os quadros usados para exibir o documento, fecha o modo de exibição, limpa o conteúdo do documento e, em seguida, chama a função de membro [DeleteContents](#deletecontents) para excluir os dados do documento.

Substitua essa função se você quiser executar o processamento de limpeza especial quando a estrutura fechar um documento. Por exemplo, se o documento representar um registro em um banco de dados, talvez você queira substituir essa função para fechar o banco de dados. Você deve chamar a versão da classe base dessa função a partir de sua substituição.

##  <a name="oncreatepreviewframe"></a>CDocument:: OnCreatePreviewFrame

Chamado pelo Framework quando ele precisa criar um quadro de visualização para visualização avançada.

```
virtual BOOL OnCreatePreviewFrame();
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se o quadro for criado com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ondocumentevent"></a>CDocument:: OnDocumentEvent

Chamado pelo Framework em resposta a um evento de documento.

```
virtual void OnDocumentEvent(DocumentEvent deEvent);
```

### <a name="parameters"></a>Parâmetros

*desigual*<br/>
no Um tipo de dados enumerado que descreve o tipo de evento.

### <a name="remarks"></a>Comentários

Os eventos de documento podem afetar várias classes. Esse método é responsável por manipular eventos de documento que afetam classes diferentes da [classe CDocument](../../mfc/reference/cdocument-class.md). Atualmente, a única classe que deve responder a eventos de documento é a [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md). A classe `CDocument` tem outros métodos substituíveis responsáveis por lidar com o efeito na `CDocument`.

A tabela a seguir lista os valores possíveis para deevent *e os* eventos aos quais eles correspondem.

|{1&gt;Valor&lt;1}|Evento correspondente|
|-----------|-------------------------|
|`onAfterNewDocument`|Um novo documento foi criado.|
|`onAfterOpenDocument`|Um novo documento foi aberto.|
|`onAfterSaveDocument`|O documento foi salvo.|
|`onAfterCloseDocument`|O documento foi fechado.|

##  <a name="ondrawthumbnail"></a>CDocument:: OnDrawThumbnail

Substitua esse método em uma classe derivada para desenhar a miniatura.

```
virtual void OnDrawThumbnail(
    CDC& dc,
    LPRECT lprcBounds);
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
Uma referência a um contexto de dispositivo.

*lprcBounds*<br/>
Especifica um retângulo delimitador da área onde a miniatura deve ser desenhada.

### <a name="remarks"></a>Comentários

##  <a name="onfilesendmail"></a>CDocument:: OnFileSendMail

Envia uma mensagem por meio do host de email residente (se houver) com o documento como um anexo.

```
void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail` chama [OnSaveDocument](#onsavedocument) para serializar (salvar) documentos sem título e modificados em um arquivo temporário, que é enviado por email. Se o documento não tiver sido modificado, um arquivo temporário não será necessário; o original é enviado. `OnFileSendMail` carrega MAPI32. DLL se ainda não tiver sido carregado.

Uma implementação especial de `OnFileSendMail` para [COleDocument](../../mfc/reference/coledocument-class.md) trata os arquivos compostos corretamente.

`CDocument` dá suporte ao envio de seu documento por email se o MAPI (suporte de email) estiver presente. Consulte os artigos [MAPI tópicos](../../mfc/mapi.md) e [suporte MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

##  <a name="onloaddocumentfromstream"></a>CDocument:: OnLoadDocumentFromStream

Chamado pelo Framework quando ele precisa carregar os dados do documento de um fluxo.

```
virtual HRESULT OnLoadDocumentFromStream(
    IStream* pStream,
    DWORD grfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um fluxo de entrada.

*grfMode*<br/>
Modo de acesso ao fluxo.

### <a name="return-value"></a>Valor retornado

S_OK se a carga for bem-sucedida; caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

##  <a name="onnewdocument"></a>CDocument:: OnNewDocument

Chamado pelo Framework como parte do comando arquivo novo.

```
virtual BOOL OnNewDocument();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento foi inicializado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama a função de membro [DeleteContents](#deletecontents) para garantir que o documento esteja vazio e, em seguida, marca o novo documento como limpo. Substitua essa função para inicializar a estrutura de dados para um novo documento. Você deve chamar a versão da classe base dessa função a partir de sua substituição.

Se o usuário escolher o comando File New em um aplicativo SDI, a estrutura usará essa função para reinicializar o documento existente, em vez de criar um novo. Se o usuário escolher arquivo novo em um aplicativo de interface de vários documentos (MDI), a estrutura criará um novo documento a cada vez e chamará essa função para inicializá-lo. Você deve posicionar o código de inicialização nessa função em vez de no construtor para que o comando File New seja eficaz em aplicativos SDI.

Observe que há casos em que `OnNewDocument` é chamado duas vezes. Isso ocorre quando o documento é inserido como um servidor de documentos ActiveX. A função é chamada primeiro pelo método de `CreateInstance` (exposto pela classe derivada de `COleObjectFactory`) e uma segunda vez pelo método de `InitNew` (exposto pela classe derivada de `COleServerDoc`).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Os exemplos a seguir ilustram métodos alternativos de inicializar um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

##  <a name="onopendocument"></a>CDocument:: OnOpenDocument

Chamado pelo Framework como parte do comando File Open.

```
virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para o caminho do documento a ser aberto.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento foi carregado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função abre o arquivo especificado, chama a função de membro [DeleteContents](#deletecontents) para garantir que o documento esteja vazio, chama [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) para ler o conteúdo do arquivo e marca o documento como limpo. Substitua essa função se desejar usar algo diferente do mecanismo de arquivamento ou do mecanismo de arquivo. Por exemplo, você pode escrever um aplicativo em que os documentos representam registros em um banco de dados em vez de arquivos separados.

Se o usuário escolher o comando File Open em um aplicativo SDI, a estrutura usará essa função para reinicializar o objeto `CDocument` existente, em vez de criar um novo. Se o usuário escolher o arquivo aberto em um aplicativo MDI, a estrutura construirá um novo `CDocument` objeto a cada vez e, em seguida, chamará essa função para inicializá-la. Você deve posicionar o código de inicialização nessa função em vez de no construtor para que o comando File Open seja eficaz em aplicativos SDI.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Os exemplos a seguir ilustram métodos alternativos de inicializar um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

[!code-cpp[NVC_MFCDocView#63](../../mfc/codesnippet/cpp/cdocument-class_8.cpp)]

##  <a name="onpreviewhandlerqueryfocus"></a>CDocument:: OnPreviewHandlerQueryFocus

Direciona o Gerenciador de visualização para retornar o HWND recuperado da chamada à função `GetFocus`.

```
virtual HRESULT OnPreviewHandlerQueryFocus(HWND* phwnd);
```

### <a name="parameters"></a>Parâmetros

*phwnd*<br/>
fora Quando esse método retorna, contém um ponteiro para o HWND retornado da chamada da função `GetFocus` do thread de primeiro plano do Gerenciador de visualização.

### <a name="return-value"></a>Valor retornado

Retorna S_OK se obtiver êxito; ou um valor de erro, caso contrário.

### <a name="remarks"></a>Comentários

##  <a name="onpreviewhandlertranslateaccelerator"></a>CDocument:: OnPreviewHandlerTranslateAccelerator

Direciona o Gerenciador de visualização para manipular um pressionamento de tecla passado da bomba de mensagem do processo no qual o Gerenciador de visualização está em execução.

```
virtual HRESULT OnPreviewHandlerTranslateAccelerator(MSG* pmsg);
```

### <a name="parameters"></a>Parâmetros

*pmsg*<br/>
no Um ponteiro para uma mensagem de janela.

### <a name="return-value"></a>Valor retornado

Se a mensagem de pressionamento de tecla puder ser processada pelo Gerenciador de visualização, o manipulador a processará e retornará S_OK. Se o Gerenciador de visualização não puder processar a mensagem de pressionamento de tecla, ele a oferecerá ao host por meio de `IPreviewHandlerFrame::TranslateAccelerator`. Se o host processar a mensagem, esse método retornará S_OK. Se o host não processar a mensagem, esse método retornará S_FALSE.

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewbackcolorchanged"></a>CDocument:: OnRichPreviewBackColorChanged

Chamado quando a cor do plano de fundo da visualização avançada é alterada.

```
virtual void OnRichPreviewBackColorChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewfontchanged"></a>CDocument:: OnRichPreviewFontChanged

Chamado quando a fonte da visualização avançada é alterada.

```
virtual void OnRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewsitechanged"></a>CDocument:: OnRichPreviewSiteChanged

Chamado quando o site de visualização avançada é alterado.

```
virtual void OnRichPreviewSiteChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewtextcolorchanged"></a>CDocument:: OnRichPreviewTextColorChanged

Chamado quando a cor do texto de visualização avançada é alterada.

```
virtual void OnRichPreviewTextColorChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onsavedocument"></a>CDocument:: OnSaveDocument

Chamado pelo Framework como parte do comando File Save ou File Save as.

```
virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para o caminho totalmente qualificado para o qual o arquivo deve ser salvo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o documento foi salvo com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função abre o arquivo especificado, chama [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) para gravar os dados do documento no arquivo e marca o documento como limpo. Substitua essa função se desejar executar processamento especial quando a estrutura salvar um documento. Por exemplo, você pode escrever um aplicativo em que os documentos representam registros em um banco de dados em vez de arquivos separados.

##  <a name="onunloadhandler"></a>CDocument:: OnUnloadHandler

Chamado pelo Framework quando o Gerenciador de visualização é descarregado.

```
virtual void OnUnloadHandler();
```

### <a name="remarks"></a>Comentários

##  <a name="onupdatefilesendmail"></a>CDocument:: OnUpdateFileSendMail

Habilita o comando ID_FILE_SEND_MAIL se o suporte a email (MAPI) estiver presente.

```
void OnUpdateFileSendMail(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para o objeto [CCmdUI](../../mfc/reference/ccmdui-class.md) associado ao comando ID_FILE_SEND_MAIL.

### <a name="remarks"></a>Comentários

Caso contrário, a função remove o comando ID_FILE_SEND_MAIL do menu, incluindo separadores acima ou abaixo do item de menu, conforme apropriado. O MAPI é habilitado se MAPI32. DLL está presente no caminho e, na seção [mail] do WIN. Arquivo INI, MAPI = 1. A maioria dos aplicativos colocou esse comando no menu arquivo.

`CDocument` dá suporte ao envio de seu documento por email se o MAPI (suporte de email) estiver presente. Consulte os artigos [MAPI tópicos](../../mfc/mapi.md) e [suporte MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

##  <a name="precloseframe"></a>CDocument::P reCloseFrame

Essa função de membro é chamada pelo Framework antes que a janela do quadro seja destruída.

```
virtual void PreCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) que contém o objeto `CDocument` associado.

### <a name="remarks"></a>Comentários

Ele pode ser substituído para fornecer uma limpeza personalizada, mas certifique-se de chamar também a classe base.

O padrão de `PreCloseFrame` não faz nada no `CDocument`. As classes derivadas de `CDocument`[COleDocument](../../mfc/reference/coledocument-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) usam essa função de membro.

##  <a name="readnextchunkvalue"></a>CDocument:: ReadNextChunkValue

Lê o próximo valor de parte.

```
virtual BOOL ReadNextChunkValue(IFilterChunkValue** ppValue);
```

### <a name="parameters"></a>Parâmetros

*ppValue*<br/>
fora Quando a função retorna, *ppValue* contém o valor que foi lido.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="releasefile"></a>CDocument:: ReleaseFile

Essa função de membro é chamada pelo Framework para liberar um arquivo, tornando-o disponível para uso por outros aplicativos.

```
virtual void ReleaseFile(
    CFile* pFile,
    BOOL bAbort);
```

### <a name="parameters"></a>Parâmetros

*pFile*<br/>
Um ponteiro para o objeto de testcfile a ser liberado.

*bAbort*<br/>
Especifica se o arquivo deve ser liberado usando `CFile::Close` ou `CFile::Abort`. FALSE se o arquivo for liberado usando [testcfile:: Close](../../mfc/reference/cfile-class.md#close); TRUE se o arquivo for liberado usando [testcfile:: Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="remarks"></a>Comentários

Se *bAbort* for TRUE, `ReleaseFile` chamará `CFile::Abort`e o arquivo será liberado. `CFile::Abort` não lançará uma exceção.

Se *bAbort* for FALSE, `ReleaseFile` chamará `CFile::Close` e o arquivo será liberado.

Substitua essa função de membro para exigir uma ação do usuário antes de o arquivo ser liberado.

##  <a name="removechunk"></a>CDocument:: RemoveChunk

Remove uma parte com o GUID especificado.

```
virtual void RemoveChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*Guid*<br/>
Especifica o GUID de uma parte a ser removida.

*Pessoal*<br/>
Especifica o PID de uma parte a ser removida.

### <a name="remarks"></a>Comentários

##  <a name="removeview"></a>CDocument:: RemoveView

Chame essa função para desanexar uma exibição de um documento.

```
void RemoveView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pView*<br/>
Aponta para a exibição que está sendo removida.

### <a name="remarks"></a>Comentários

Essa função remove a exibição especificada da lista de exibições associadas ao documento; Ele também define o ponteiro do documento da exibição como nulo. Essa função é chamada pela estrutura quando uma janela do quadro é fechada ou um painel de uma janela de Splitter é fechado.

Chame essa função somente se você estiver desanexando um modo de exibição manualmente. Normalmente, você permitirá que a estrutura desanexe documentos e exibições definindo um objeto [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para associar uma classe de documento, uma classe de exibição e um quadro de janela de quadros.

Consulte o exemplo em [AddView](#addview) para obter uma implementação de exemplo.

##  <a name="reportsaveloadexception"></a>CDocument:: ReportSaveLoadException

Chamado se uma exceção for lançada (normalmente um [CFileException](../../mfc/reference/cfileexception-class.md) ou [CArchiveException](../../mfc/reference/carchiveexception-class.md)) ao salvar ou carregar o documento.

```
virtual void ReportSaveLoadException(
    LPCTSTR lpszPathName,
    CException* e,
    BOOL bSaving,
    UINT nIDPDefault);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para o nome do documento que estava sendo salvo ou carregado.

*e*<br/>
Aponta para a exceção que foi lançada. Pode ser NULL.

*bSaving*<br/>
Sinalizador indicando qual operação estava em andamento; diferente de zero se o documento estava sendo salvo, 0 se o documento estava sendo carregado.

*nIDPDefault*<br/>
Identificador da mensagem de erro a ser exibida se a função não especificar uma outra mais específica.

### <a name="remarks"></a>Comentários

A implementação padrão examina o objeto de exceção e procura uma mensagem de erro que descreva especificamente a causa. Se uma mensagem específica não for encontrada ou se *e* for NULL, a mensagem geral especificada pelo parâmetro *nIDPDefault* será usada. A função exibe uma caixa de mensagem que contém a mensagem de erro. Substitua essa função se desejar fornecer mensagens de falha adicionais personalizadas. Esse é um substituível avançado.

##  <a name="savemodified"></a>CDocument:: SaveModified

Chamado pelo Framework antes que um documento modificado seja fechado.

```
virtual BOOL SaveModified();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for seguro continuar e fechar o documento; 0 se o documento não deve ser fechado.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função exibe uma caixa de mensagem perguntando ao usuário se deseja salvar as alterações no documento, se alguma tiver sido feita. Substitua essa função se o programa exigir um procedimento de solicitação diferente. Esse é um substituível avançado.

##  <a name="setchunkvalue"></a>CDocument:: setchunkvalue

Define um valor de parte.

```
virtual BOOL SetChunkValue (IFilterChunkValue* pValue);
```

### <a name="parameters"></a>Parâmetros

*Valores*<br/>
Especifica um valor de parte a ser definido.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="setmodifiedflag"></a>CDocument:: SetModifiedFlag

Chame essa função depois de fazer modificações no documento.

```
virtual void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModified*<br/>
Sinalizador que indica se o documento foi modificado.

### <a name="remarks"></a>Comentários

Ao chamar essa função de forma consistente, você garante que a estrutura solicite que o usuário salve as alterações antes de fechar um documento. Normalmente, você deve usar o valor padrão de TRUE para o parâmetro *bModified* . Para marcar um documento como limpo (não modificado), chame essa função com um valor de FALSE.

##  <a name="setpathname"></a>CDocument:: setpathname

Chame essa função para especificar o caminho totalmente qualificado do arquivo de disco do documento.

```
virtual void SetPathName(
    LPCTSTR lpszPathName,
    BOOL bAddToMRU = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para a cadeia de caracteres a ser usada como o caminho para o documento.

*bAddToMRU*<br/>
Determina se o nome de arquivo é adicionado à lista de arquivos MRU (usados mais recentemente). Se for TRUE, o nome do arquivo será adicionado; Se for FALSE, ele não será adicionado.

### <a name="remarks"></a>Comentários

Dependendo do valor de *bAddToMRU* , o caminho é adicionado ou não adicionado à lista MRU mantida pelo aplicativo. Observe que alguns documentos não estão associados a um arquivo de disco. Chame essa função somente se você estiver substituindo a implementação padrão para abrir e salvar arquivos usados pela estrutura.

##  <a name="settitle"></a>CDocument:: SetTitle

Chame essa função para especificar o título do documento (a cadeia de caracteres exibida na barra de título de uma janela do quadro).

```
virtual void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Aponta para a cadeia de caracteres a ser usada como o título do documento.

### <a name="remarks"></a>Comentários

Chamar essa função atualiza os títulos de todas as janelas de quadros que exibem o documento.

##  <a name="updateallviews"></a>CDocument:: UpdateAllViews

Chame essa função depois que o documento tiver sido modificado.

```
void UpdateAllViews(
    CView* pSender,
    LPARAM lHint = 0L,
    CObject* pHint = NULL);
```

### <a name="parameters"></a>Parâmetros

*pSender*<br/>
Aponta para a exibição que modificou o documento, ou NULL se todas as exibições forem atualizadas.

*lHint*<br/>
Contém informações sobre a modificação.

*pHint*<br/>
Aponta para um objeto que armazena informações sobre a modificação.

### <a name="remarks"></a>Comentários

Você deve chamar essa função depois de chamar a função de membro [SetModifiedFlag](#setmodifiedflag) . Essa função informa cada exibição anexada ao documento, exceto para a exibição especificada por *pSender*, que o documento foi modificado. Normalmente, você chama essa função da classe View depois que o usuário altera o documento por meio de uma exibição.

Essa função chama a função de membro [cvisualização:: OnUpdate](../../mfc/reference/cview-class.md#onupdate) para cada uma das exibições do documento, exceto o modo de exibição de envio, passando *pHint* e *lHint*. Use esses parâmetros para passar informações para as exibições sobre as modificações feitas no documento. Você pode codificar informações usando *lHint* e/ou pode definir uma classe derivada de [CObject](../../mfc/reference/cobject-class.md)para armazenar informações sobre as modificações e passar um objeto dessa classe usando *pHint*. Substitua a função de membro `CView::OnUpdate` em sua classe derivada de [cvisualização](../../mfc/reference/cview-class.md)para otimizar a atualização da exibição do modo de exibição com base nas informações passadas.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDocView#64](../../mfc/codesnippet/cpp/cdocument-class_9.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de MDIDOCVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SNAPVW do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de NPP do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)
