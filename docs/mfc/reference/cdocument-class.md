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
ms.openlocfilehash: b7358c2206c15660b9ffb283802283ee71e57f03
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57299069"
---
# <a name="cdocument-class"></a>Classe CDocument

Fornece a funcionalidade básica para classes de documento definido pelo usuário.

## <a name="syntax"></a>Sintaxe

```
class CDocument : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::CDocument](#cdocument)|Constrói um objeto `CDocument`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::AddView](#addview)|Anexa um modo de exibição ao documento.|
|[CDocument::BeginReadChunks](#beginreadchunks)|Inicializa dividir a leitura.|
|[CDocument::CanCloseFrame](#cancloseframe)|Advanced substituível; chamado antes de fechar uma janela de quadro exibindo neste documento.|
|[CDocument::ClearChunkList](#clearchunklist)|Limpa a lista de partes.|
|[CDocument::ClearPathName](#clearpathname)|Limpa o caminho do objeto document.|
|[CDocument::DeleteContents](#deletecontents)|Chamado para executar a limpeza do documento.|
|[CDocument::FindChunk](#findchunk)|Procura por uma parte com o GUID especificado.|
|[CDocument::GetAdapter](#getadapter)|Retorna um ponteiro para objeto que implementa `IDocument` interface.|
|[CDocument::GetDocTemplate](#getdoctemplate)|Retorna um ponteiro para o modelo de documento que descreve o tipo do documento.|
|[CDocument::GetFile](#getfile)|Retorna um ponteiro para o estado desejado `CFile` objeto.|
|[CDocument::GetFirstViewPosition](#getfirstviewposition)|Retorna a posição do primeiro na lista de modos de exibição; usado para começar a iteração.|
|[CDocument::GetNextView](#getnextview)|Itera através da lista de modos de exibição associado ao documento.|
|[CDocument::GetPathName](#getpathname)|Retorna o caminho do arquivo de dados do documento.|
|[CDocument::GetThumbnail](#getthumbnail)|Chamado para criar um bitmap a ser usado pelo provedor de miniaturas para exibir a miniatura.|
|[CDocument::GetTitle](#gettitle)|Retorna o título do documento.|
|[CDocument::InitializeSearchContent](#initializesearchcontent)|Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.|
|[CDocument::IsModified](#ismodified)|Indica se o documento foi modificado desde que foi salvo pela última vez.|
|[CDocument::IsSearchAndOrganizeHandler](#issearchandorganizehandler)|Indica se esta instância do `CDocument` objeto foi criado para organizar e pesquisa do manipulador.|
|[CDocument::LoadDocumentFromStream](#loaddocumentfromstream)|Chamado para carregar dados de documento de fluxo.|
|[CDocument::OnBeforeRichPreviewFontChanged](#onbeforerichpreviewfontchanged)|Chamado antes da visualização avançada de fonte é alterada.|
|[CDocument::OnChangedViewList](#onchangedviewlist)|Chamado depois que uma exibição é adicionada ou removida do documento.|
|[CDocument::OnCloseDocument](#onclosedocument)|Chamado para fechar o documento.|
|[CDocument::OnCreatePreviewFrame](#oncreatepreviewframe)|Chamado pelo framework quando ele precisa criar um quadro de visualização para visualização avançada.|
|[CDocument::OnDocumentEvent](#ondocumentevent)|Chamado pelo framework em resposta a um evento de documento.|
|[CDocument::OnDrawThumbnail](#ondrawthumbnail)|Substitua este método em uma classe derivada para desenhar o conteúdo da miniatura.|
|[CDocument::OnLoadDocumentFromStream](#onloaddocumentfromstream)|Chamado pelo framework quando ele precisa carregar os dados do documento de fluxo.|
|[CDocument::OnNewDocument](#onnewdocument)|Chamado para criar um novo documento.|
|[CDocument::OnOpenDocument](#onopendocument)|Chamado para abrir um documento existente.|
|[CDocument::OnPreviewHandlerQueryFocus](#onpreviewhandlerqueryfocus)|Direciona o Gerenciador de visualização que retorne o HWND de chamar a função GetFocus.|
|[CDocument::OnPreviewHandlerTranslateAccelerator](#onpreviewhandlertranslateaccelerator)|Direciona o Gerenciador de visualização para lidar com um pressionamento de tecla passado acima da bomba de mensagens do processo no qual o Gerenciador de visualização está em execução.|
|[CDocument::OnRichPreviewBackColorChanged](#onrichpreviewbackcolorchanged)|Chamado quando a cor do plano de fundo de visualização avançada foi alterado.|
|[CDocument::OnRichPreviewFontChanged](#onrichpreviewfontchanged)|Chamado quando a fonte de visualização avançada foi alterado.|
|[CDocument::OnRichPreviewSiteChanged](#onrichpreviewsitechanged)|Chamado quando o site de visualização avançada foi alterado.|
|[CDocument::OnRichPreviewTextColorChanged](#onrichpreviewtextcolorchanged)|Chamado quando a cor do texto de visualização avançada foi alterado.|
|[CDocument::OnSaveDocument](#onsavedocument)|Chamado para salvar o documento no disco.|
|[CDocument::OnUnloadHandler](#onunloadhandler)|Chamado pelo framework quando o Gerenciador de visualização está sendo descarregado.|
|[CDocument::PreCloseFrame](#precloseframe)|Chamado antes que a janela do quadro está fechada.|
|[CDocument::ReadNextChunkValue](#readnextchunkvalue)|Lê o próximo valor de bloco.|
|[CDocument::ReleaseFile](#releasefile)|Libera um arquivo para torná-lo disponível para uso por outros aplicativos.|
|[CDocument::RemoveChunk](#removechunk)|Remove uma parte com o GUID especificado.|
|[CDocument::RemoveView](#removeview)|Desanexa um modo de exibição do documento.|
|[CDocument::ReportSaveLoadException](#reportsaveloadexception)|Advanced substituível; chamado quando um aberto ou operação de salvamento não pode ser concluída devido a uma exceção.|
|[CDocument::SaveModified](#savemodified)|Advanced substituível; chamado para perguntar ao usuário se o documento deve ser salvo.|
|[CDocument::SetChunkValue](#setchunkvalue)|Define um valor de bloco.|
|[CDocument::SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica que você modificou o documento, pois ele foi salvo pela última vez.|
|[CDocument::SetPathName](#setpathname)|Define o caminho do arquivo de dados usado pelo documento.|
|[CDocument::SetTitle](#settitle)|Define o título do documento.|
|[CDocument::UpdateAllViews](#updateallviews)|Notifica todos os modos de documento foi modificado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|
|[CDocument::OnUpdateFileSendMail](#onupdatefilesendmail)|Permite que o comando Enviar email se houver suporte para email.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocument::m_bGetThumbnailMode](#m_bgetthumbnailmode)|Especifica que `CDocument` objeto foi criado por dllhost para miniaturas. Devem ser verificadas em `CView::OnDraw`.|
|[CDocument::m_bPreviewHandlerMode](#m_bpreviewhandlermode)|Especifica que `CDocument` objeto foi criado por prevhost para `Rich Preview`. Devem ser verificadas em `CView::OnDraw`.|
|[CDocument::m_bSearchMode](#m_bsearchmode)|Especifica que `CDocument` objeto foi criado pelo indexador ou outro aplicativo de pesquisa.|
|[CDocument::m_clrRichPreviewBackColor](#m_clrrichpreviewbackcolor)|Especifica a cor do plano de fundo da janela de visualização avançada. Essa cor é definida pelo host.|
|[CDocument::m_clrRichPreviewTextColor](#m_clrrichpreviewtextcolor)|Especifica a cor de primeiro plano da janela de visualização avançada. Essa cor é definida pelo host.|
|[CDocument::m_lfRichPreviewFont](#m_lfrichpreviewfont)|Especifica a fonte do texto de janela de visualização avançada. Essas informações de fonte são definidas pelo host.|

## <a name="remarks"></a>Comentários

Um documento representa a unidade de dados que o usuário geralmente é aberta com o comando Abrir arquivo e salva com o comando Salvar do arquivo.

`CDocument` dá suporte a operações padrão, como criação de um documento, carregá-la e salvá-lo. O framework manipula documentos usando a interface definida por `CDocument`.

Um aplicativo pode dar suporte a mais de um tipo de documento. Por exemplo, um aplicativo pode oferecer suporte a planilhas e documentos de texto. Cada tipo de documento tem um modelo de documento associado; o modelo de documento especifica quais recursos (por exemplo, tabela de menu, ícone ou acelerador) são usados para esse tipo de documento. Cada documento contém um ponteiro para seus associados `CDocTemplate` objeto.

Os usuários interagem com um documento por meio de [CView](../../mfc/reference/cview-class.md) (s) associado a ele. Um modo de exibição renderiza uma imagem do documento em uma janela de quadro e interpreta a entrada do usuário como operações no documento. Um documento pode ter várias exibições associadas a ele. Quando o usuário abre uma janela em um documento, o framework cria uma exibição e anexa-o ao documento. O modelo de documento especifica qual tipo de exibição e o quadro de janela são usados para exibir cada tipo de documento.

Documentos fazem parte do padrão da estrutura de roteamento de comando e, consequentemente, recebem comandos de componentes de interface do usuário padrão (como o item de menu Salvar arquivo). Um documento recebe comandos encaminhados pelo modo de exibição ativo. Se o documento não lidar com um determinado comando, ele encaminha o comando para o modelo de documento que o gerencia.

Quando os dados de um documento são modificados, cada um dos seus modos de exibição deve refletir essas modificações. `CDocument` fornece o [UpdateAllViews](#updateallviews) a função de membro para notificar os modos de exibição de tais alterações, portanto, os modos de exibição podem se redesenhar conforme necessário. A estrutura também solicita ao usuário salvar um arquivo modificado antes de fechá-lo.

Para implementar os documentos em um aplicativo típico, faça o seguinte:

- Derive uma classe de `CDocument` para cada tipo de documento.

- Adicione variáveis de membro para armazenar dados de cada documento.

- Implementar funções de membro para leitura e modificação de dados do documento. Modos de exibição do documento são os usuários mais importantes dessas funções de membro.

- Substituir a [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) a função de membro em sua classe de documento para gravar e ler os dados do documento para e do disco.

`CDocument` oferece suporte ao envio seu documento por email se houver suporte mail (MAPI). Consulte os artigos [MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

Para obter mais informações sobre `CDocument`, consulte [serialização](../../mfc/serialization-in-mfc.md), [tópicos de arquitetura de documento/exibição](../../mfc/document-view-architecture.md), e [criação de documento/exibição](../../mfc/document-view-creation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDocument`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="addview"></a>  CDocument::AddView

Chame essa função para anexar um modo de exibição ao documento.

```
void AddView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pView*<br/>
Aponta para o modo de exibição que está sendo adicionado.

### <a name="remarks"></a>Comentários

Essa função adiciona a exibição especificada à lista de modos de exibição associado ao documento; a função também define o ponteiro de documento do modo de exibição para este documento. O framework chama essa função ao anexar um objeto de exibição criado recentemente a um documento. Isso ocorre em resposta a um comando novo arquivo, abrir arquivo ou uma nova janela ou quando uma janela separadora é dividida.

Chame essa função somente se você está criando e anexando uma exibição manualmente. Normalmente você permitirá que a estrutura de conectar os documentos e exibições com a definição de um [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para associar uma classe de documento, a classe de exibição e a classe de janela do quadro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocViewSDI#12](../../mfc/codesnippet/cpp/cdocument-class_1.cpp)]

##  <a name="beginreadchunks"></a>  CDocument::BeginReadChunks

Inicializa dividir a leitura.

```
virtual void BeginReadChunks ();
```

### <a name="remarks"></a>Comentários

##  <a name="cancloseframe"></a>  CDocument::CanCloseFrame

Chamado pelo framework antes de uma janela de quadro exibindo o documento é fechada.

```
virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Aponta para a janela do quadro de uma exibição anexados ao documento.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se é seguro fechar a janela do quadro; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão verifica se há outras janelas com moldura exibindo o documento. Se a janela do quadro especificado é o último que exibe o documento, a função solicita ao usuário para salvar o documento se ele tiver sido modificado. Substitua essa função se você quiser executar o processamento especial quando uma janela de quadro está fechada. Isso é um avançado substituível.

##  <a name="cdocument"></a>  CDocument::CDocument

Constrói um objeto `CDocument`.

```
CDocument();
```

### <a name="remarks"></a>Comentários

A estrutura manipula a criação de documentos para você. Substituir a [OnNewDocument](#onnewdocument) a função de membro para executar a inicialização em uma base por documento; isso é particularmente importante em aplicativos de interface (SDI) único documento.

##  <a name="clearchunklist"></a>  CDocument::ClearChunkList

Limpa a lista de partes.

```
virtual void ClearChunkList ();
```

### <a name="remarks"></a>Comentários

##  <a name="clearpathname"></a>  CDocument::ClearPathName

Limpa o caminho do objeto document.

```
virtual void ClearPathName();
```

### <a name="remarks"></a>Comentários

Limpar o caminho de um `CDocument` objeto faz com que o aplicativo solicitar ao usuário quando o documento é salvo em seguida. Isso faz com que um **salve** comando se comportam como um **Salvar como** comando.

##  <a name="deletecontents"></a>  CDocument::DeleteContents

Chamado pelo framework para excluir os dados do documento sem destruir o `CDocument` objeto propriamente dito.

```
virtual void DeleteContents();
```

### <a name="remarks"></a>Comentários

Ele é chamado antes do documento é a ser destruído. Ele também é chamado para garantir que um documento está vazio antes que ele será reutilizado. Isso é particularmente importante para um aplicativo SDI, que usa apenas um documento; o documento é reutilizado sempre que o usuário cria ou abre outro documento. Chame essa função para implementar um comando semelhante que exclui todos os dados do documento ou "Editar Limpar tudo". A implementação padrão dessa função não faz nada. Substitua essa função para excluir os dados em seu documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#57](../../mfc/codesnippet/cpp/cdocument-class_2.cpp)]

##  <a name="findchunk"></a>  CDocument::FindChunk

Procura por uma parte com um GUID especificado.

```
virtual POSITION FindChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*guid*<br/>
Especifica o GUID de uma parte para localizar.

*pid*<br/>
Especifica um PID de uma parte para localizar.

### <a name="return-value"></a>Valor de retorno

Posição na lista de partes internas se for bem-sucedido. Caso contrário, nulo.

### <a name="remarks"></a>Comentários

##  <a name="getadapter"></a>  CDocument::GetAdapter

Retorna um ponteiro para um objeto que implementa o `IDocument` interface.

```
virtual ATL::IDocument* GetAdapter();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um objeto que implementa o `IDocument` interface.

### <a name="remarks"></a>Comentários

##  <a name="getdoctemplate"></a>  CDocument::GetDocTemplate

Chame essa função para obter um ponteiro para o modelo de documento para este tipo de documento.

```
CDocTemplate* GetDocTemplate() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o modelo de documento para esse tipo de documento, ou nulo se o documento não for gerenciado por um modelo de documento.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#58](../../mfc/codesnippet/cpp/cdocument-class_3.cpp)]

##  <a name="getfile"></a>  CDocument::GetFile

Chame essa função de membro para obter um ponteiro para um `CFile` objeto.

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
Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções listadas no construtor CFile [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) usando o OR bit a bit (&#124;) operador. Permissão de acesso de um e um compartilhamento de opção são necessários; o `modeCreate` e `modeNoInherit` modos são opcionais.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CFile` objeto.

##  <a name="getfirstviewposition"></a>  CDocument::GetFirstViewPosition

Chame essa função para obter a posição da primeira exibição na lista de modos de exibição associado ao documento.

```
virtual POSITION GetFirstViewPosition() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor da posição que pode ser usado para iteração com os [GetNextView](#getnextview) função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

##  <a name="getnextview"></a>  CDocument::GetNextView

Chame essa função para iterar em todos os modos de exibição do documento.

```
virtual CView* GetNextView(POSITION& rPosition) const;
```

### <a name="parameters"></a>Parâmetros

*rPosition*<br/>
Uma referência a um valor posição retornada por uma chamada anterior para o `GetNextView` ou [GetFirstViewPosition](#getfirstviewposition) funções de membro. Esse valor não deve ser NULL.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o modo de exibição identificado pelo *rPosition*.

### <a name="remarks"></a>Comentários

A função retorna o modo de exibição identificado pelo *rPosition* e, em seguida, define *rPosition* para o valor da posição da exibição seguinte na lista. Se o modo de exibição recuperado é o último na lista, em seguida, *rPosition* é definido como NULL.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#59](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]

##  <a name="getpathname"></a>  CDocument::GetPathName

Chame essa função para obter o caminho totalmente qualificado do arquivo de disco do documento.

```
const CString& GetPathName() const;
```

### <a name="return-value"></a>Valor de retorno

O caminho do documento totalmente qualificado. Essa cadeia de caracteres está vazia, se o documento não foi salvo ou não tem um arquivo de disco associado a ele.

##  <a name="getthumbnail"></a>  CDocument::GetThumbnail

Cria um bitmap a ser usado pelo provedor de miniatura para exibir a miniatura.

```
virtual BOOL GetThumbnail(
    UINT cx,
    HBITMAP* phbmp,
    DWORD* pdwAlpha);
```

### <a name="parameters"></a>Parâmetros

*cx*<br/>
Especifica a largura e altura do bitmap.

*phbmp*<br/>
Contém um identificador para um bitmap, quando a função retorna com êxito.

*pdwAlpha*<br/>
Contém um valor de DWORD especificando o valor de canal alfa, quando a função retorna com êxito.

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se um bitmap para a miniatura foi criado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="gettitle"></a>  CDocument::GetTitle

Chame essa função para obter o título do documento, que geralmente é derivado do nome do arquivo do documento.

```
const CString& GetTitle() const;
```

### <a name="return-value"></a>Valor de retorno

O título do documento.

##  <a name="initializesearchcontent"></a>  CDocument::InitializeSearchContent

Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.

```
virtual void InitializeSearchContent ();
```

### <a name="remarks"></a>Comentários

Substitua este método em uma classe derivada para inicializar o conteúdo de pesquisa. O conteúdo deve ser uma cadeia de caracteres com partes delimitadas por ";". Por exemplo, "ponto; retângulo; item OLE".

##  <a name="ismodified"></a>  CDocument::IsModified

Chame essa função para determinar se o documento foi modificado desde que foi salvo pela última vez.

```
virtual BOOL IsModified();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento tiver sido modificado desde que foi salvo pela última vez; Caso contrário, 0.

##  <a name="issearchandorganizehandler"></a>  CDocument::IsSearchAndOrganizeHandler

Indica se esta instância do `CDocument` foi criado para o manipulador de pesquisa e organizar.

```
BOOL IsSearchAndOrganizeHandler() const;
```

### <a name="return-value"></a>Valor de retorno

Retorna TRUE se esta instância de `CDocument` foi criado para o manipulador de pesquisa e organizar.

### <a name="remarks"></a>Comentários

Atualmente, essa função retorna TRUE somente para os gerenciadores de visualização de Rich implementados em um fora do servidor de processo. Você pode definir os sinalizadores adequados (m_bPreviewHandlerMode, m_bSearchMode, m_bGetThumbnailMode) no seu nível de aplicativo para tornar essa função retornar TRUE.

##  <a name="loaddocumentfromstream"></a>  CDocument::LoadDocumentFromStream

Chamado para carregar dados de documento de um fluxo.

```
virtual HRESULT LoadDocumentFromStream(
    IStream* pStream,
    DWORD dwGrfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um fluxo. Esse fluxo é fornecido pelo Shell.

*dwGrfMode*<br/>
Modo de acesso no fluxo.

### <a name="return-value"></a>Valor de retorno

S_OK se a operação de carregamento for bem-sucedida, caso contrário, HRESULT com um código de erro.

### <a name="remarks"></a>Comentários

Você pode substituir esse método em uma classe derivada para personalizar como carregar dados do fluxo.

##  <a name="m_bgetthumbnailmode"></a>  CDocument::m_bGetThumbnailMode

Especifica que o `CDocument` objeto foi criado por dllhost para miniaturas. Devem ser verificadas em `CView::OnDraw`.

```
BOOL m_bGetThumbnailMode;
```

### <a name="remarks"></a>Comentários

`TRUE` indica que o documento foi criado pelo dllhost para miniaturas.

##  <a name="m_bpreviewhandlermode"></a>  CDocument::m_bPreviewHandlerMode

Especifica que o `CDocument` objeto foi criado por prevhost para visualização avançada. Devem ser verificadas em `CView::OnDraw`.

```
BOOL m_bPreviewHandlerMode;
```

### <a name="remarks"></a>Comentários

TRUE indica que o documento foi criado pelo prevhost para visualização avançada.

##  <a name="m_bsearchmode"></a>  CDocument::m_bSearchMode

Especifica que o `CDocument` objeto foi criado pelo indexador ou por outro aplicativo de pesquisa.

```
BOOL m_bSearchMode;
```

### <a name="remarks"></a>Comentários

`TRUE` indica que o documento foi criado pelo indexador ou por outro aplicativo de pesquisa.

##  <a name="m_clrrichpreviewbackcolor"></a>  CDocument::m_clrRichPreviewBackColor

Especifica a cor do plano de fundo da janela de visualização avançada. Essa cor é definida pelo host.

```
COLORREF m_clrRichPreviewBackColor;
```

### <a name="remarks"></a>Comentários

##  <a name="m_clrrichpreviewtextcolor"></a>  CDocument::m_clrRichPreviewTextColor

Especifica a cor de primeiro plano da janela de visualização avançada. Essa cor é definida pelo host.

```
COLORREF m_clrRichPreviewTextColor;
```

### <a name="remarks"></a>Comentários

##  <a name="m_lfrichpreviewfont"></a>  CDocument::m_lfRichPreviewFont

Especifica a fonte do texto para a janela de visualização avançada. Essas informações de fonte são definidas pelo host.

```
CFont m_lfRichPreviewFont;
```

### <a name="remarks"></a>Comentários

##  <a name="onbeforerichpreviewfontchanged"></a>  CDocument::OnBeforeRichPreviewFontChanged

Chamado antes que a fonte de visualização avançada é alterada.

```
virtual void OnBeforeRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onchangedviewlist"></a>  CDocument::OnChangedViewList

Chamado pelo framework depois que um modo de exibição é adicionado ou removido do documento.

```
virtual void OnChangedViewList();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função verifica se a última exibição está sendo removida e, nesse caso, exclui o documento. Substitua essa função se você quiser executar o processamento especial quando o framework adiciona ou remove um modo de exibição. Por exemplo, se você quiser um documento para permanecer aberto, mesmo quando não houver nenhuma exibição anexada a ele, substitua essa função.

##  <a name="onclosedocument"></a>  CDocument::OnCloseDocument

Chamado pelo framework quando o documento é fechado, normalmente como parte do comando File Close.

```
virtual void OnCloseDocument();
```

### <a name="remarks"></a>Comentários

A implementação padrão dessa função destrói todos os quadros usados para exibir o documento, fecha a exibição, limpa o conteúdo do documento e, em seguida, chama o [DeleteContents](#deletecontents) a função de membro para excluir o documento dados.

Substitua essa função se você quiser executar o processamento de limpeza especial quando a estrutura de um documento é fechado. Por exemplo, se o documento representa um registro em um banco de dados, você talvez queira substituir essa função para fechar o banco de dados. Você deve chamar a versão da classe base dessa função de sua substituição.

##  <a name="oncreatepreviewframe"></a>  CDocument::OnCreatePreviewFrame

Chamado pelo framework quando ele precisa criar um quadro de visualização para visualização avançada.

```
virtual BOOL OnCreatePreviewFrame();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o quadro for criado com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

##  <a name="ondocumentevent"></a>  CDocument::OnDocumentEvent

Chamado pelo framework em resposta a um evento de documento.

```
virtual void OnDocumentEvent(DocumentEvent deEvent);
```

### <a name="parameters"></a>Parâmetros

*deEvent*<br/>
[in] Um tipo de dados enumerado que descreve o tipo de evento.

### <a name="remarks"></a>Comentários

Eventos de documento podem afetar várias classes. Esse método é responsável por manipular eventos de documento que afetam as classes que o [classe CDocument](../../mfc/reference/cdocument-class.md). Atualmente, a única classe que deve responder a eventos de documento é o [classe CDataRecoveryHandler](../../mfc/reference/cdatarecoveryhandler-class.md). O `CDocument` classe tem outros métodos substituíveis responsáveis por manipular o efeito sobre o `CDocument`.

A tabela a seguir lista os possíveis valores para *deEvent* e que eles correspondem aos eventos.

|Valor|Evento correspondente|
|-----------|-------------------------|
|`onAfterNewDocument`|Um novo documento foi criado.|
|`onAfterOpenDocument`|Um novo documento foi aberto.|
|`onAfterSaveDocument`|O documento foi salvo.|
|`onAfterCloseDocument`|O documento foi fechado.|

##  <a name="ondrawthumbnail"></a>  CDocument::OnDrawThumbnail

Substitua este método em uma classe derivada para desenhar a miniatura.

```
virtual void OnDrawThumbnail(
    CDC& dc,
    LPRECT lprcBounds);
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
Uma referência a um contexto de dispositivo.

*lprcBounds*<br/>
Especifica um retângulo delimitador da área em que a miniatura deve ser desenhada.

### <a name="remarks"></a>Comentários

##  <a name="onfilesendmail"></a>  CDocument::OnFileSendMail

Envia uma mensagem por meio do host de correio residentes (se houver) com o documento como um anexo.

```
void OnFileSendMail();
```

### <a name="remarks"></a>Comentários

`OnFileSendMail` chamadas [OnSaveDocument](#onsavedocument) para serializar (os documentos sem título e modificados em um arquivo temporário, que é enviada por meio de emails Salvar). Se o documento não tiver sido modificado, um arquivo temporário não é necessária; original é enviada. `OnFileSendMail` carrega MAPI32. DLL se ele ainda não tenha sido carregado.

Uma implementação especial da `OnFileSendMail` para [COleDocument](../../mfc/reference/coledocument-class.md) identificadores composta arquivos corretamente.

`CDocument` oferece suporte ao envio seu documento por email se houver suporte mail (MAPI). Consulte os artigos [tópicos MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

##  <a name="onloaddocumentfromstream"></a>  CDocument::OnLoadDocumentFromStream

Chamado pelo framework quando ele precisa carregar os dados do documento de um fluxo.

```
virtual HRESULT OnLoadDocumentFromStream(
    IStream* pStream,
    DWORD grfMode);
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um fluxo de entrada.

*grfMode*<br/>
Modo de acesso no fluxo.

### <a name="return-value"></a>Valor de retorno

S_OK se a carga for bem-sucedida; Caso contrário, um código de erro.

### <a name="remarks"></a>Comentários

##  <a name="onnewdocument"></a>  CDocument::OnNewDocument

Chamado pelo framework como parte do comando arquivo-novo.

```
virtual BOOL OnNewDocument();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento foi inicializado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função chama o [DeleteContents](#deletecontents) a função de membro para garantir que o documento está vazio e, em seguida, marca o novo documento como limpas. Substitua essa função para inicializar a estrutura de dados para um novo documento. Você deve chamar a versão da classe base dessa função de sua substituição.

Se o usuário escolhe o comando novo arquivo em um aplicativo SDI, a estrutura usa essa função para reinicializar o documento existente, em vez de criar um novo. Se o usuário escolhe um novo arquivo em um aplicativo de interface MDI vários documentos, o framework cria um novo documento de cada vez e, em seguida, chama esta função para inicializá-lo. Você deve colocar o código de inicialização nessa função, em vez de no construtor para o comando novo arquivo para ser eficaz em aplicativos SDI.

Observe que há casos onde `OnNewDocument` é chamado duas vezes. Isso ocorre quando o documento é inserido como um servidor de documento ActiveX. A função é chamada pela primeira vez pela `CreateInstance` método (exposto pelo `COleObjectFactory`-classe derivada) e uma segunda vez pela `InitNew` método (exposto pelo `COleServerDoc`-classe derivada).

### <a name="example"></a>Exemplo

Os exemplos a seguir ilustram os métodos alternativos de inicializar um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

##  <a name="onopendocument"></a>  CDocument::OnOpenDocument

Chamado pelo framework como parte do comando Abrir arquivo.

```
virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para o caminho do documento a ser aberto.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento foi carregado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função abre o arquivo especificado, chamadas a [DeleteContents](#deletecontents) função de membro para garantir que o documento está vazio, chama [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para ler o arquivo conteúdo e, em seguida, marca o documento como limpas. Substitua essa função se você quiser usar algo diferente do mecanismo de arquivamento ou o mecanismo de arquivo. Por exemplo, você pode escrever um aplicativo em que os documentos representam registros em um banco de dados em vez de arquivos separados.

Se o usuário escolhe o comando Abrir arquivo em um aplicativo SDI, a estrutura usa essa função para reinicializar existente `CDocument` objeto, em vez de criar um novo. Se o usuário optar por abrir arquivo em um aplicativo MDI, o framework constrói um novo `CDocument` objeto cada vez e, em seguida, chama essa função para inicializá-lo. Você deve colocar o código de inicialização nessa função, em vez de no construtor para o comando Abrir arquivo para ser eficaz em aplicativos SDI.

### <a name="example"></a>Exemplo

Os exemplos a seguir ilustram os métodos alternativos de inicializar um objeto de documento.

[!code-cpp[NVC_MFCDocView#60](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]

[!code-cpp[NVC_MFCDocView#61](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]

[!code-cpp[NVC_MFCDocView#62](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]

[!code-cpp[NVC_MFCDocView#63](../../mfc/codesnippet/cpp/cdocument-class_8.cpp)]

##  <a name="onpreviewhandlerqueryfocus"></a>  CDocument::OnPreviewHandlerQueryFocus

Direciona o Gerenciador de visualização para retornar o HWND recuperados da chamada a `GetFocus` função.

```
virtual HRESULT OnPreviewHandlerQueryFocus(HWND* phwnd);
```

### <a name="parameters"></a>Parâmetros

*phwnd*<br/>
[out] Quando este método retorna, contém um ponteiro para o HWND retornado ao chamar o `GetFocus` função do thread de primeiro plano do Gerenciador de visualização.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK se bem-sucedido; ou um valor de erro caso contrário.

### <a name="remarks"></a>Comentários

##  <a name="onpreviewhandlertranslateaccelerator"></a>  CDocument::OnPreviewHandlerTranslateAccelerator

Direciona o Gerenciador de visualização para lidar com um pressionamento de tecla passado acima da bomba de mensagens do processo no qual o Gerenciador de visualização está em execução.

```
virtual HRESULT OnPreviewHandlerTranslateAccelerator(MSG* pmsg);
```

### <a name="parameters"></a>Parâmetros

*pmsg*<br/>
[in] Um ponteiro para uma mensagem da janela.

### <a name="return-value"></a>Valor de retorno

Se a mensagem de pressionamento de tecla pode ser processada pelo Gerenciador de visualização, o manipulador processa e retorna S_OK. Se o Gerenciador de visualização não é possível processar a mensagem de pressionamento de tecla, ele oferece para o host por meio de `IPreviewHandlerFrame::TranslateAccelerator`. Se o host processa a mensagem, esse método retorna S_OK. Se o host não processa a mensagem, esse método retorna S_FALSE.

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewbackcolorchanged"></a>  CDocument::OnRichPreviewBackColorChanged

Chamado quando a cor de plano de fundo de visualização avançada foi alterado.

```
virtual void OnRichPreviewBackColorChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewfontchanged"></a>  CDocument::OnRichPreviewFontChanged

Chamado quando a fonte de visualização avançada foi alterado.

```
virtual void OnRichPreviewFontChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewsitechanged"></a>  CDocument::OnRichPreviewSiteChanged

Chamado quando o site de visualização avançada foi alterado.

```
virtual void OnRichPreviewSiteChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onrichpreviewtextcolorchanged"></a>  CDocument::OnRichPreviewTextColorChanged

Chamado quando a cor do texto de visualização avançada foi alterado.

```
virtual void OnRichPreviewTextColorChanged();
```

### <a name="remarks"></a>Comentários

##  <a name="onsavedocument"></a>  CDocument::OnSaveDocument

Chamado pelo framework como parte do comando arquivo salvar ou salvar como arquivo.

```
virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para o caminho totalmente qualificado para o qual o arquivo deve ser salvo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o documento foi salvo com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função abre o arquivo especificado, chamadas [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para gravar os dados do documento para o arquivo e, em seguida, as marcas o documento como limpar. Substitua essa função se você quiser executar o processamento especial quando a estrutura salva um documento. Por exemplo, você pode escrever um aplicativo em que os documentos representam registros em um banco de dados em vez de arquivos separados.

##  <a name="onunloadhandler"></a>  CDocument::OnUnloadHandler

Chamado pelo framework quando o Gerenciador de visualização é descarregado.

```
virtual void OnUnloadHandler();
```

### <a name="remarks"></a>Comentários

##  <a name="onupdatefilesendmail"></a>  CDocument::OnUpdateFileSendMail

Permite que o comando ID_FILE_SEND_MAIL se há suporte a mail (MAPI).

```
void OnUpdateFileSendMail(CCmdUI* pCmdUI);
```

### <a name="parameters"></a>Parâmetros

*pCmdUI*<br/>
Um ponteiro para o [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto associado com o comando ID_FILE_SEND_MAIL.

### <a name="remarks"></a>Comentários

Caso contrário, a função remove o comando ID_FILE_SEND_MAIL no menu, incluindo separadores acima ou abaixo do item de menu conforme apropriado. MAPI estará habilitada se MAPI32. DLL está presente no caminho e, na seção [Mail] do WIN. O arquivo INI, MAPI = 1. A maioria dos aplicativos colocar esse comando no menu arquivo.

`CDocument` oferece suporte ao envio seu documento por email se houver suporte mail (MAPI). Consulte os artigos [tópicos MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).

##  <a name="precloseframe"></a>  CDocument::PreCloseFrame

Essa função membro é chamada pelo framework antes que a janela do quadro é destruída.

```
virtual void PreCloseFrame(CFrameWnd* pFrame);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
Ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) que contém associado `CDocument` objeto.

### <a name="remarks"></a>Comentários

Ele pode ser substituído para fornecer limpeza personalizada, mas não se esqueça de chamar a classe base.

O padrão de `PreCloseFrame` não faz nada `CDocument`. O `CDocument`-as classes derivadas [COleDocument](../../mfc/reference/coledocument-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) usar essa função de membro.

##  <a name="readnextchunkvalue"></a>  CDocument::ReadNextChunkValue

Lê o próximo valor de bloco.

```
virtual BOOL ReadNextChunkValue(IFilterChunkValue** ppValue);
```

### <a name="parameters"></a>Parâmetros

*ppValue*<br/>
[out] Quando a função retorna, *ppValue* contém o valor que foi lido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="releasefile"></a>  CDocument::ReleaseFile

Essa função membro é chamada pelo framework para um arquivo, tornando-o disponível para uso por outros aplicativos de versão.

```
virtual void ReleaseFile(
    CFile* pFile,
    BOOL bAbort);
```

### <a name="parameters"></a>Parâmetros

*pFile*<br/>
Um ponteiro para o objeto CFile seja liberado.

*bAbort*<br/>
Especifica se o arquivo deve ser liberado usando o `CFile::Close` ou `CFile::Abort`. FALSE se o arquivo deve ser liberada usando [CFile::Close](../../mfc/reference/cfile-class.md#close); TRUE se o arquivo deve ser liberada usando [CFile::Abort](../../mfc/reference/cfile-class.md#abort).

### <a name="remarks"></a>Comentários

Se *bAbort* for TRUE, `ReleaseFile` chamadas `CFile::Abort`, e o arquivo é liberado. `CFile::Abort` não lançará uma exceção.

Se *bAbort* é FALSE, o `ReleaseFile` chamadas `CFile::Close` e o arquivo é liberado.

Substitua essa função de membro para exigir uma ação do usuário antes de liberar o arquivo.

##  <a name="removechunk"></a>  CDocument::RemoveChunk

Remove uma parte com o GUID especificado.

```
virtual void RemoveChunk(
    REFCLSID guid,
    DWORD pid);
```

### <a name="parameters"></a>Parâmetros

*Guid*<br/>
Especifica o GUID de uma parte a ser removido.

*Pid*<br/>
Especifica o PID de uma parte a ser removido.

### <a name="remarks"></a>Comentários

##  <a name="removeview"></a>  CDocument::RemoveView

Chame essa função para desanexar um modo de exibição de um documento.

```
void RemoveView(CView* pView);
```

### <a name="parameters"></a>Parâmetros

*pView*<br/>
Aponta para o modo de exibição que está sendo removido.

### <a name="remarks"></a>Comentários

Essa função remove a exibição especificada da lista de modos de exibição associado ao documento; Ele também define o ponteiro de documento do modo de exibição como NULL. Essa função é chamada pelo framework quando uma janela de quadro está fechada ou um painel de uma janela separadora é fechado.

Chame essa função somente se você manualmente é desanexação de um modo de exibição. Normalmente você permitirá que a estrutura de desanexar os documentos e exibições com a definição de um [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para associar uma classe de documento, a classe de exibição e a classe de janela do quadro.

Veja o exemplo na [Adicionarexibicao](#addview) para uma implementação de exemplo.

##  <a name="reportsaveloadexception"></a>  CDocument::ReportSaveLoadException

Chamado se uma exceção será gerada (normalmente um [CFileException](../../mfc/reference/cfileexception-class.md) ou [CArchiveException](../../mfc/reference/carchiveexception-class.md)) ao salvar ou carregar o documento.

```
virtual void ReportSaveLoadException(
    LPCTSTR lpszPathName,
    CException* e,
    BOOL bSaving,
    UINT nIDPDefault);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponte para o nome do documento que estava sendo salvo ou carregado.

*e*<br/>
Aponta para a exceção que foi gerada. Pode ser NULL.

*bSaving*<br/>
Sinalizador que indica qual operação estava em andamento; diferente de zero se o documento estava sendo salvo, 0 se o documento estava sendo carregado.

*nIDPDefault*<br/>
Identificador da mensagem de erro a ser exibida se a função não especifica uma mais específica.

### <a name="remarks"></a>Comentários

A implementação padrão examina o objeto de exceção e procura por uma mensagem de erro que descreve especificamente a causa. Se uma mensagem específica não for encontrada ou se *eletrônico* for NULL, a mensagem geral especificada pelo *nIDPDefault* parâmetro é usado. A função, em seguida, exibe uma caixa de mensagem que contém a mensagem de erro. Substitua essa função se você quiser fornecer mensagens de falha adicional e personalizado. Isso é um avançado substituível.

##  <a name="savemodified"></a>  CDocument::SaveModified

Chamado pelo framework antes de um documento modificado está a ser fechado.

```
virtual BOOL SaveModified();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se é seguro continuar e fechar o documento. 0 se o documento não deve ser fechado.

### <a name="remarks"></a>Comentários

A implementação padrão dessa função exibe uma caixa de mensagem solicitando que o usuário se deseja salvar as alterações no documento, se nenhum tiver sido feita. Substitua essa função se seu programa exigir um procedimento de indicação diferente. Isso é um avançado substituível.

##  <a name="setchunkvalue"></a>  CDocument::SetChunkValue

Define um valor de bloco.

```
virtual BOOL SetChunkValue (IFilterChunkValue* pValue);
```

### <a name="parameters"></a>Parâmetros

*pValue*<br/>
Especifica um valor de bloco definido.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

##  <a name="setmodifiedflag"></a>  CDocument::SetModifiedFlag

Chame essa função após você ter feito as modificações ao documento.

```
virtual void SetModifiedFlag(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModified*<br/>
Sinalizador que indica se o documento foi modificado.

### <a name="remarks"></a>Comentários

Ao chamar essa função de forma consistente, você garante que o framework solicita que o usuário salve as alterações antes de fechar um documento. Normalmente, você deve usar o valor padrão de TRUE para o *bModified* parâmetro. Para marcar um documento mais limpo (não modificado), chame essa função com um valor de FALSE.

##  <a name="setpathname"></a>  CDocument::SetPathName

Chame essa função para especificar o caminho totalmente qualificado do arquivo de disco do documento.

```
virtual void SetPathName(
    LPCTSTR lpszPathName,
    BOOL bAddToMRU = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Aponta para a cadeia de caracteres a ser usado como o caminho para o documento.

*bAddToMRU*<br/>
Determina se o nome do arquivo é adicionado à lista mais usados recentemente (MRU) arquivos. Se for TRUE, o nome do arquivo é adicionado; Se for FALSE, ele não é adicionado.

### <a name="remarks"></a>Comentários

Dependendo do valor de *bAddToMRU* o caminho é adicionado ou não adicionado à lista MRU mantida pelo aplicativo. Observe que alguns documentos não estão associados um arquivo de disco. Chame essa função somente se você está substituindo a implementação padrão para abrir e salvar arquivos usados pela estrutura.

##  <a name="settitle"></a>  CDocument::SetTitle

Chame essa função para especificar o título do documento (cadeia de caracteres exibida na barra de título de uma janela de quadro).

```
virtual void SetTitle(LPCTSTR lpszTitle);
```

### <a name="parameters"></a>Parâmetros

*lpszTitle*<br/>
Aponta para a cadeia de caracteres a ser usado como o título do documento.

### <a name="remarks"></a>Comentários

Chamar essa função atualiza os títulos de todas as janelas de quadro que exibem o documento.

##  <a name="updateallviews"></a>  CDocument::UpdateAllViews

Chame essa função depois que o documento foi modificado.

```
void UpdateAllViews(
    CView* pSender,
    LPARAM lHint = 0L,
    CObject* pHint = NULL);
```

### <a name="parameters"></a>Parâmetros

*pSender*<br/>
Aponta para o modo de exibição que modificou o documento, ou nulo se todas as exibições serão atualizados.

*lHint*<br/>
Contém informações sobre a modificação.

*pHint*<br/>
Aponta para um objeto que armazena informações sobre a modificação.

### <a name="remarks"></a>Comentários

Você deve chamar essa função depois de chamar o [SetModifiedFlag](#setmodifiedflag) função de membro. Essa função informa cada exibição anexada ao documento, exceto para o modo especificado por *pSender*, que o documento foi modificado. Além disso, você normalmente chama essa função de sua classe de exibição depois que o usuário alterou o documento por meio de um modo de exibição.

Essa função chama o [CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) exibir a função de membro para cada um dos modos de exibição do documento, exceto o envio, passando *pHint* e *lHint*. Use esses parâmetros para passar informações para os modos de exibição sobre as modificações feitas no documento. Você pode codificar informações usando *lHint* e/ou você pode definir um [CObject](../../mfc/reference/cobject-class.md)-classe para armazenar informações sobre as modificações e passar um objeto do que o uso de classe derivada *pHint*. Substituir a `CView::OnUpdate` função de membro em seu [CView](../../mfc/reference/cview-class.md)-derivado da classe para otimizar a atualização de exibição do modo de exibição com base nas informações passadas.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#64](../../mfc/codesnippet/cpp/cdocument-class_9.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)<br/>
[Exemplo MFC SNAPVW](../../visual-cpp-samples.md)<br/>
[Exemplo MFC NPP](../../visual-cpp-samples.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)
