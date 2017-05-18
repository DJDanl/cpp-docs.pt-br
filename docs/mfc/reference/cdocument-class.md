---
title: Classe CDocument | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- documents [C++], serialization
- files [C++], documents
- command handling, documents and
- documents [C++], document classes
- documents [C++], multiple views
- serialization [C++], documents and
- CDocument class
- command routing, documents and
- views [C++], document
- documents [C++], command routing
ms.assetid: e5a2891d-e1e1-4599-8c7e-afa9b4945446
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 4d64b95f77139d984b855e710f3951434e489dd5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdocument-class"></a>Classe CDocument
Fornece a funcionalidade básica para as classes de documento definido pelo usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDocument : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocument::CDocument](#cdocument)|Constrói um objeto `CDocument`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocument::AddView](#addview)|Anexa um modo de exibição ao documento.|  
|[CDocument::BeginReadChunks](#beginreadchunks)|Inicializa parte leitura.|  
|[CDocument::CanCloseFrame](#cancloseframe)|Avançado substituível; chamado antes de fechar uma janela de quadro exibindo neste documento.|  
|[CDocument::ClearChunkList](#clearchunklist)|Limpa a lista de bloco.|  
|[CDocument::ClearPathName](#clearpathname)|Limpa o caminho do objeto document.|  
|[CDocument::DeleteContents](#deletecontents)|Chamado para executar a limpeza do documento.|  
|[CDocument::FindChunk](#findchunk)|Procura por uma parte com o GUID especificado.|  
|[CDocument::GetAdapter](#getadapter)|Retorna um ponteiro para o objeto que implementa `IDocument` interface.|  
|[CDocument::GetDocTemplate](#getdoctemplate)|Retorna um ponteiro para o modelo de documento que descreve o tipo de documento.|  
|[CDocument::GetFile](#getfile)|Retorna um ponteiro para o estado desejado `CFile` objeto.|  
|[CDocument::GetFirstViewPosition](#getfirstviewposition)|Retorna a posição do primeiro na lista de modos de exibição; usado para iniciar a iteração.|  
|[CDocument::GetNextView](#getnextview)|Percorre a lista de modos de exibição associada ao documento.|  
|[CDocument::GetPathName](#getpathname)|Retorna o caminho do arquivo de dados do documento.|  
|[CDocument::GetThumbnail](#getthumbnail)|Chamado para criar um bitmap a ser usado pelo provedor de miniaturas para exibir a miniatura.|  
|[CDocument::GetTitle](#gettitle)|Retorna o título do documento.|  
|[CDocument::InitializeSearchContent](#initializesearchcontent)|Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.|  
|[CDocument::IsModified](#ismodified)|Indica se o documento foi modificado desde que foi salvo pela última vez.|  
|[CDocument::IsSearchAndOrganizeHandler](#issearchandorganizehandler)|Indica se esta instância do `CDocument` objeto foi criado para organizar de pesquisa < / manipulador.|  
|[CDocument::LoadDocumentFromStream](#loaddocumentfromstream)|Chamado para carregar dados de documento de fluxo.|  
|[CDocument::OnBeforeRichPreviewFontChanged](#onbeforerichpreviewfontchanged)|Chamado antes da visualização avançada de fonte é alterada.|  
|[CDocument::OnChangedViewList](#onchangedviewlist)|Chamado depois que uma exibição é adicionada ou removida do documento.|  
|[CDocument::OnCloseDocument](#onclosedocument)|Chamado para fechar o documento.|  
|[CDocument::OnCreatePreviewFrame](#oncreatepreviewframe)|Chamado pela estrutura quando ele precisa criar um quadro de visualização para visualização avançada.|  
|[CDocument::OnDocumentEvent](#ondocumentevent)|Chamado pela estrutura em resposta a um evento de documento.|  
|[CDocument::OnDrawThumbnail](#ondrawthumbnail)|Substitua esse método em uma classe derivada para desenhar o conteúdo da miniatura.|  
|[CDocument::OnLoadDocumentFromStream](#onloaddocumentfromstream)|Chamado pela estrutura quando ele precisa carregar os dados do documento de fluxo.|  
|[CDocument::OnNewDocument](#onnewdocument)|Chamado para criar um novo documento.|  
|[CDocument::OnOpenDocument](#onopendocument)|Chamado para abrir um documento existente.|  
|[CDocument::OnPreviewHandlerQueryFocus](#onpreviewhandlerqueryfocus)|Direciona o Gerenciador de visualização para retornar o HWND de chamar a função GetFocus.|  
|[CDocument::OnPreviewHandlerTranslateAccelerator](#onpreviewhandlertranslateaccelerator)|Direciona o Gerenciador de visualização para manipular um pressionamento de tecla passado acima da bomba de mensagens do processo no qual o Gerenciador de visualização está em execução.|  
|[CDocument::OnRichPreviewBackColorChanged](#onrichpreviewbackcolorchanged)|Chamado quando a cor de plano de fundo da visualização avançada foi alterado.|  
|[CDocument::OnRichPreviewFontChanged](#onrichpreviewfontchanged)|Chamado quando a fonte de visualização avançada foi alterado.|  
|[CDocument::OnRichPreviewSiteChanged](#onrichpreviewsitechanged)|Chamado quando o site de visualização avançada foi alterado.|  
|[CDocument::OnRichPreviewTextColorChanged](#onrichpreviewtextcolorchanged)|Chamado quando a cor do texto de visualização avançada foi alterado.|  
|[CDocument::OnSaveDocument](#onsavedocument)|Chamado para salvar o documento em disco.|  
|[CDocument::OnUnloadHandler](#onunloadhandler)|Chamado pela estrutura quando o Gerenciador de visualização está sendo descarregado.|  
|[CDocument::PreCloseFrame](#precloseframe)|Chamado antes de fechar a janela do quadro.|  
|[CDocument::ReadNextChunkValue](#readnextchunkvalue)|Lê o próximo valor de bloco.|  
|[CDocument::ReleaseFile](#releasefile)|Libera um arquivo para torná-lo disponível para uso por outros aplicativos.|  
|[CDocument::RemoveChunk](#removechunk)|Remove uma parte com o GUID especificado.|  
|[CDocument::RemoveView](#removeview)|Desconecta um modo de exibição do documento.|  
|[CDocument::ReportSaveLoadException](#reportsaveloadexception)|Avançado substituível; chamado quando um aberto ou operação de salvamento não pode ser concluída devido a uma exceção.|  
|[CDocument::SaveModified](#savemodified)|Avançado substituível; chamado para perguntar ao usuário se o documento deve ser salvo.|  
|[CDocument::SetChunkValue](#setchunkvalue)|Define um valor de bloco.|  
|[CDocument::SetModifiedFlag](#setmodifiedflag)|Define um sinalizador que indica que você modificou o documento desde que ele foi salvo pela última vez.|  
|[CDocument::SetPathName](#setpathname)|Define o caminho do arquivo de dados usado pelo documento.|  
|[CDocument::SetTitle](#settitle)|Define o título do documento.|  
|[CDocument::UpdateAllViews](#updateallviews)|Notifica todos os modos de documentam foi modificado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocument::OnFileSendMail](#onfilesendmail)|Envia uma mensagem de email com o documento anexado.|  
|[CDocument::OnUpdateFileSendMail](#onupdatefilesendmail)|Ativa o comando Enviar email se houver suporte para email.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocument::m_bGetThumbnailMode](#m_bgetthumbnailmode)|Especifica que `CDocument` objeto foi criado pelo dllhost para miniaturas. Devem ser verificados `CView::OnDraw`.|  
|[CDocument::m_bPreviewHandlerMode](#m_bpreviewhandlermode)|Especifica que `CDocument` foi criado por prevhost para `Rich Preview`. Devem ser verificados `CView::OnDraw`.|  
|[CDocument::m_bSearchMode](#m_bsearchmode)|Especifica que `CDocument` objeto foi criado pelo indexador ou outro aplicativo de pesquisa.|  
|[CDocument::m_clrRichPreviewBackColor](#m_clrrichpreviewbackcolor)|Especifica a cor de plano de fundo da janela de visualização avançada. Essa cor é definida pelo host.|  
|[CDocument::m_clrRichPreviewTextColor](#m_clrrichpreviewtextcolor)|Especifica a cor de primeiro plano da janela de visualização avançada. Essa cor é definida pelo host.|  
|[CDocument::m_lfRichPreviewFont](#m_lfrichpreviewfont)|Especifica a fonte do texto de janela de visualização avançada. Essas informações de fonte são definidas pelo host.|  
  
## <a name="remarks"></a>Comentários  
 Um documento representa a unidade de dados que o usuário normalmente abre com o comando Abrir arquivo e salva com o comando Salvar arquivo.  
  
 **CDocument** oferece suporte a operações padrão, como criar um documento, carregá-lo e salvá-lo. O framework manipula documentos usando a interface definida pelo **CDocument**.  
  
 Um aplicativo pode oferecer suporte a mais de um tipo de documento. Por exemplo, um aplicativo pode oferecer suporte a planilhas e documentos de texto. Cada tipo de documento tem um modelo de documento associado; o modelo de documento especifica quais recursos (por exemplo, acelerador, ícone ou menu Tabela) são usados para esse tipo de documento. Cada documento contém um ponteiro para seus associados `CDocTemplate` objeto.  
  
 Os usuários interagem com um documento por meio de [CView](../../mfc/reference/cview-class.md) objetos associados a ele. Uma exibição renderiza uma imagem do documento em uma janela de quadro e interpreta a entrada do usuário como operações no documento. Um documento pode ter várias exibições associadas a ele. Quando o usuário abre uma janela em um documento, o framework cria um modo de exibição e anexa-o ao documento. O modelo de documento especifica o tipo de exibição e o quadro de janela são usados para exibir cada tipo de documento.  
  
 Documentos são parte do padrão da estrutura roteamento de comando e, consequentemente, receber comandos de componentes de interface do usuário padrão (como o item de menu Salvar arquivo). Um documento recebe comandos encaminhados por view ativo. Se o documento não manipular um determinado comando, ele encaminha o comando para o modelo de documento que o gerencia.  
  
 Quando os dados do documento são modificados, cada um dos seus modos de exibição deve refletir essas modificações. **CDocument** fornece o [UpdateAllViews](#updateallviews) função membro notificar os modos de exibição de todas as alterações para os modos de exibição podem se redesenhar conforme necessário. A estrutura também avisa ao usuário para salvar um arquivo modificado antes de fechá-lo.  
  
 Para implementar os documentos em um aplicativo típico, faça o seguinte:  
  
-   Derivar uma classe de **CDocument** para cada tipo de documento.  
  
-   Adicione variáveis de membro para armazenar os dados de cada documento.  
  
-   Implementar funções de membro para ler e modificar os dados do documento. Modos de exibição do documento são os usuários mais importantes dessas funções de membro.  
  
-   Substituir o [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) a função de membro em sua classe de documento para gravar e ler os dados do documento em disco.  
  
 **CDocument** oferece suporte ao envio de seu documento por email se houver suporte mail (MAPI). Consulte os artigos [MAPI](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).  
  
 Para obter mais informações sobre **CDocument**, consulte [serialização](../../mfc/serialization-in-mfc.md), [tópicos da arquitetura de documento/exibição](../../mfc/document-view-architecture.md), e [criação de documento/exibição](../../mfc/document-view-creation.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDocument`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="addview"></a>CDocument::AddView  
 Chame essa função para anexar um modo de exibição para o documento.  
  
```  
void AddView(CView* pView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pView`  
 Aponta para o modo de exibição que está sendo adicionado.  
  
### <a name="remarks"></a>Comentários  
 Essa função adiciona o modo de exibição especificado à lista de modos de exibição associada ao documento; a função também define o ponteiro de documento do modo de exibição para este documento. O framework chama essa função ao anexar um objeto de exibição criado recentemente a um documento. Isso ocorre em resposta a um novo arquivo, abrir arquivo ou nova janela de comando ou quando uma janela separadora é dividida.  
  
 Chame essa função somente se você está criando e anexando um modo de exibição manualmente. Normalmente você permitirá que a estrutura de conectar os documentos e exibições, definindo uma [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para associar uma classe de documento, a classe de exibição e a classe de janela de quadro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocViewSDI&#12;](../../mfc/codesnippet/cpp/cdocument-class_1.cpp)]  
  
##  <a name="beginreadchunks"></a>CDocument::BeginReadChunks  
 Inicializa parte leitura.  
  
```  
virtual void BeginReadChunks ();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cancloseframe"></a>CDocument::CanCloseFrame  
 Chamado pela estrutura antes de uma janela de quadro exibindo o documento é fechada.  
  
```  
virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFrame`  
 Aponta para a janela do quadro de um modo de exibição anexado ao documento.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se ele é seguro fechar a janela de quadro; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão verifica se há outras janelas de quadro exibindo o documento. Se a janela de quadro especificado é a última que exibe o documento, a função solicita ao usuário para salvar o documento se ele tiver sido modificado. Substitua essa função se você quiser executar um processamento especial quando uma janela do quadro é fechada. Isso é uma avançada substituível.  
  
##  <a name="cdocument"></a>CDocument::CDocument  
 Constrói uma **CDocument** objeto.  
  
```  
CDocument();
```  
  
### <a name="remarks"></a>Comentários  
 A estrutura lida com a criação de documentos para você. Substituir o [OnNewDocument](#onnewdocument) a função de membro para executar a inicialização em uma base por documento; isso é particularmente importante em aplicativos de interface (SDI) único documento.  
  
##  <a name="clearchunklist"></a>CDocument::ClearChunkList  
 Limpa a lista de bloco.  
  
```  
virtual void ClearChunkList ();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="clearpathname"></a>CDocument::ClearPathName  
 Limpa o caminho do objeto document.  
  
```  
virtual void ClearPathName();
```  
  
### <a name="remarks"></a>Comentários  
 Limpando o caminho de um `CDocument` objeto faz com que o aplicativo avisar o usuário quando o documento é salvo em seguida. Isso faz com que uma **salvar** comando se comportam como uma **Salvar como** comando.  
  
##  <a name="deletecontents"></a>CDocument::DeleteContents  
 Chamado pela estrutura para excluir os dados do documento sem destruir o **CDocument** objeto propriamente dito.  
  
```  
virtual void DeleteContents();
```  
  
### <a name="remarks"></a>Comentários  
 Ele é chamado pouco antes do documento deve ser destruído. Ele também é chamado para garantir que um documento está vazio antes que ela é reutilizada. Isso é particularmente importante para um aplicativo SDI, que usa apenas um documento. o documento sejam reutilizado sempre que o usuário cria ou abrir outro documento. Chame essa função para implementar um comando semelhante que exclui todos os dados do documento ou "Editar Limpar tudo". A implementação padrão dessa função não faz nada. Substitua essa função para excluir os dados no documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#57;](../../mfc/codesnippet/cpp/cdocument-class_2.cpp)]  
  
##  <a name="findchunk"></a>CDocument::FindChunk  
 Procura por uma parte com um GUID especificado.  
  
```  
virtual POSITION FindChunk(
    REFCLSID guid,  
    DWORD pid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `guid`  
 Especifica o GUID de uma parte para localizar.  
  
 `pid`  
 Especifica um PID de uma parte para localizar.  
  
### <a name="return-value"></a>Valor de retorno  
 Posição na lista de bloco interno se for bem-sucedido. Caso contrário, `NULL`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getadapter"></a>CDocument::GetAdapter  
 Retorna um ponteiro para um objeto que implementa o `IDocument` interface.  
  
```  
virtual ATL::IDocument* GetAdapter();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um objeto que implementa o `IDocument` interface.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getdoctemplate"></a>CDocument::GetDocTemplate  
 Chame essa função para obter um ponteiro para o modelo de documento para esse tipo de documento.  
  
```  
CDocTemplate* GetDocTemplate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o modelo de documento para este tipo de documento, ou **nulo** se o documento não é gerenciado por um modelo de documento.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#58;](../../mfc/codesnippet/cpp/cdocument-class_3.cpp)]  
  
##  <a name="getfile"></a>CDocument::GetFile  
 Chame essa função de membro para obter um ponteiro para um `CFile` objeto.  
  
```  
virtual CFile* GetFile(
    LPCTSTR lpszFileName,  
    UINT nOpenFlags,  
    CFileException* pError);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszFileName`  
 Uma cadeia de caracteres que é o caminho para o arquivo desejado. O caminho pode ser relativo ou absoluto.  
  
 `pError`  
 Um ponteiro para um objeto de exceção de arquivo existente que indica o status de conclusão da operação.  
  
 `nOpenFlags`  
 Modo de compartilhamento e acesso. Especifica a ação a ser tomada ao abrir o arquivo. Você pode combinar as opções listadas no construtor CFile [CFile::CFile](../../mfc/reference/cfile-class.md#cfile) usando o OR bit a bit (|) operador. Permissão de acesso de um e um compartilhamento de opção são necessários; o **modeCreate** e **modeNoInherit** modos são opcionais.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CFile` objeto.  
  
##  <a name="getfirstviewposition"></a>CDocument::GetFirstViewPosition  
 Chame essa função para obter a posição da primeira exibição na lista de modos de exibição associada ao documento.  
  
```  
virtual POSITION GetFirstViewPosition() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A **posição** valor que pode ser usado para interação com o [GetNextView](#getnextview) função de membro.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#59;](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]  
  
##  <a name="getnextview"></a>CDocument::GetNextView  
 Chame essa função para iterar em todos os modos de exibição do documento.  
  
```  
virtual CView* GetNextView(POSITION& rPosition) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `rPosition`  
 Uma referência a um **posição** valor retornado por uma chamada anterior a `GetNextView` ou [GetFirstViewPosition](#getfirstviewposition) funções de membro. Esse valor não deve ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o modo de exibição identificado por `rPosition`.  
  
### <a name="remarks"></a>Comentários  
 A função retorna o modo identificado por `rPosition` e, em seguida, define `rPosition` para o **posição** valor da exibição seguinte na lista. Se o modo de exibição recuperado é o último na lista, em seguida, `rPosition` é definido como **nulo**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#59;](../../mfc/codesnippet/cpp/cdocument-class_4.cpp)]  
  
##  <a name="getpathname"></a>CDocument::GetPathName  
 Chame essa função para obter o caminho totalmente qualificado do arquivo de disco do documento.  
  
```  
const CString& GetPathName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Caminho totalmente qualificado do documento. Essa cadeia de caracteres está vazia se o documento não foi salvo ou não tem um arquivo de disco associado a ele.  
  
##  <a name="getthumbnail"></a>CDocument::GetThumbnail  
 Cria um bitmap a ser usado pelo provedor de miniaturas para exibir a miniatura.  
  
```  
virtual BOOL GetThumbnail(
    UINT cx,  
    HBITMAP* phbmp,  
    DWORD* pdwAlpha);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cx`  
 Especifica a largura e altura do bitmap.  
  
 `phbmp`  
 Contém um identificador para um bitmap, quando a função retorna com êxito.  
  
 `pdwAlpha`  
 Contém um valor de DWORD especificando o valor de canal alfa, quando a função retornar com êxito.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se um bitmap para a miniatura foi criado com êxito; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettitle"></a>CDocument::GetTitle  
 Chame essa função para obter o título do documento, que geralmente é derivado do nome de arquivo do documento.  
  
```  
const CString& GetTitle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O título do documento.  
  
##  <a name="initializesearchcontent"></a>CDocument::InitializeSearchContent  
 Chamado para inicializar o conteúdo de pesquisa para o manipulador de pesquisa.  
  
```  
virtual void InitializeSearchContent ();
```  
  
### <a name="remarks"></a>Comentários  
 Substitua esse método em uma classe derivada para inicializar o conteúdo de pesquisa. O conteúdo deve ser uma cadeia de caracteres com partes delimitadas por ";". Por exemplo, "ponto; retângulo; item de OLE".  
  
##  <a name="ismodified"></a>CDocument::IsModified  
 Chame essa função para determinar se o documento foi modificado desde que foi salvo pela última vez.  
  
```  
virtual BOOL IsModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento tiver sido modificado desde que ele foi salvo pela última vez; Caso contrário, 0.  
  
##  <a name="issearchandorganizehandler"></a>CDocument::IsSearchAndOrganizeHandler  
 Indica se esta instância do `CDocument` foi criado para o manipulador de organizar de pesquisa < /.  
  
```  
BOOL IsSearchAndOrganizeHandler() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se esta instância do `CDocument` foi criado para o manipulador de organizar < / de pesquisa.  
  
### <a name="remarks"></a>Comentários  
 No momento, essa função retorna `TRUE` somente para os gerenciadores de visualização de Rich implementados em um limite de servidor em processo. Você pode definir os sinalizadores adequados (m_bPreviewHandlerMode, m_bSearchMode, m_bGetThumbnailMode) no seu nível de aplicativo para fazer essa função retornar `TRUE`.  
  
##  <a name="loaddocumentfromstream"></a>CDocument::LoadDocumentFromStream  
 Chamado para carregar dados de documento de um fluxo.  
  
```  
virtual HRESULT LoadDocumentFromStream(
    IStream* pStream,  
    DWORD dwGrfMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 Um ponteiro para um fluxo. Esse fluxo é fornecido pelo Shell.  
  
 `dwGrfMode`  
 Modo de acesso ao fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se a operação de carregamento for bem-sucedido, caso contrário HRESULT com um código de erro.  
  
### <a name="remarks"></a>Comentários  
 Você pode substituir esse método em uma classe derivada para personalizar como carregar dados no fluxo.  
  
##  <a name="m_bgetthumbnailmode"></a>CDocument::m_bGetThumbnailMode  
 Especifica que o `CDocument` foi criado por dllhost para miniaturas. Devem ser verificados `CView::OnDraw`.  
  
```  
BOOL m_bGetThumbnailMode;  
```  
  
### <a name="remarks"></a>Comentários  
 `TRUE`indica que o documento foi criado pelo dllhost para miniaturas.  
  
##  <a name="m_bpreviewhandlermode"></a>CDocument::m_bPreviewHandlerMode  
 Especifica que o `CDocument` foi criado por prevhost para visualização avançada. Devem ser verificados `CView::OnDraw`.  
  
```  
BOOL m_bPreviewHandlerMode;  
```  
  
### <a name="remarks"></a>Comentários  
 `TRUE`indica que o documento foi criado por prevhost para visualização avançada.  
  
##  <a name="m_bsearchmode"></a>CDocument::m_bSearchMode  
 Especifica que o `CDocument` objeto foi criado pelo indexador ou por outro aplicativo de pesquisa.  
  
```  
BOOL m_bSearchMode;  
```  
  
### <a name="remarks"></a>Comentários  
 `TRUE`indica que o documento foi criado pelo indexador ou por outro aplicativo de pesquisa.  
  
##  <a name="m_clrrichpreviewbackcolor"></a>CDocument::m_clrRichPreviewBackColor  
 Especifica a cor de plano de fundo da janela de visualização avançada. Essa cor é definida pelo host.  
  
```  
COLORREF m_clrRichPreviewBackColor;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_clrrichpreviewtextcolor"></a>CDocument::m_clrRichPreviewTextColor  
 Especifica a cor de primeiro plano da janela de visualização avançada. Essa cor é definida pelo host.  
  
```  
COLORREF m_clrRichPreviewTextColor;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_lfrichpreviewfont"></a>CDocument::m_lfRichPreviewFont  
 Especifica a fonte do texto da janela de visualização avançada. Essas informações de fonte são definidas pelo host.  
  
```  
CFont m_lfRichPreviewFont;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onbeforerichpreviewfontchanged"></a>CDocument::OnBeforeRichPreviewFontChanged  
 Chamado antes que a visualização avançada de fonte é alterada.  
  
```  
virtual void OnBeforeRichPreviewFontChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onchangedviewlist"></a>CDocument::OnChangedViewList  
 Chamado pela estrutura depois de um modo de exibição é adicionado ou removido do documento.  
  
```  
virtual void OnChangedViewList();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função verifica se a última exibição está sendo removida e, em caso afirmativo, exclui o documento. Substitua essa função se você quiser executar um processamento especial quando o framework adiciona ou remove um modo de exibição. Por exemplo, se você quiser que um documento permaneça aberta, mesmo quando existem exibições anexadas a ele, substitua essa função.  
  
##  <a name="onclosedocument"></a>CDocument::OnCloseDocument  
 Chamado pela estrutura quando o documento é fechado, normalmente como parte do comando File Close.  
  
```  
virtual void OnCloseDocument();
```  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função destrói todos os quadros usados para exibir o documento, fecha o modo de exibição, limpa o conteúdo do documento e, em seguida, chama o [DeleteContents](#deletecontents) a função de membro para excluir os dados do documento.  
  
 Substitua essa função se você deseja executar a limpeza especial de processamento quando a estrutura de um documento é fechado. Por exemplo, se o documento representa um registro em um banco de dados, você talvez queira substituir essa função para fechar o banco de dados. Você deve chamar a versão da classe base dessa função de sua substituição.  
  
##  <a name="oncreatepreviewframe"></a>CDocument::OnCreatePreviewFrame  
 Chamado pela estrutura quando ele precisa criar um quadro de visualização para visualização avançada.  
  
```  
virtual BOOL OnCreatePreviewFrame();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `TRUE` se o quadro é criado com êxito; caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondocumentevent"></a>CDocument::OnDocumentEvent  
 Chamado pela estrutura em resposta a um evento de documento.  
  
```  
virtual void OnDocumentEvent(DocumentEvent deEvent);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `deEvent`  
 Um tipo de dados enumerado que descreve o tipo de evento.  
  
### <a name="remarks"></a>Comentários  
 Eventos de documento podem afetar várias classes. Esse método é responsável por manipular eventos de documento que afetam as classes que o [classe CDocument](../../mfc/reference/cdocument-class.md). Atualmente, a única classe que deve responder a eventos de documento é o [CDataRecoveryHandler classe](../../mfc/reference/cdatarecoveryhandler-class.md). O `CDocument` classe tem outros métodos substituíveis responsáveis por gerenciar o efeito sobre o `CDocument`.  
  
 A tabela a seguir lista os possíveis valores para `deEvent` e os eventos aos quais correspondem.  
  
|Valor|Evento correspondente|  
|-----------|-------------------------|  
|`onAfterNewDocument`|Um novo documento foi criado.|  
|`onAfterOpenDocument`|Um novo documento foi aberto.|  
|`onAfterSaveDocument`|O documento foi salvo.|  
|`onAfterCloseDocument`|O documento foi fechado.|  
  
##  <a name="ondrawthumbnail"></a>CDocument::OnDrawThumbnail  
 Substitua esse método em uma classe derivada para desenhar a miniatura.  
  
```  
virtual void OnDrawThumbnail(
    CDC& dc,  
    LPRECT lprcBounds);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 Uma referência a um contexto de dispositivo.  
  
 `lprcBounds`  
 Especifica um retângulo da área de onde a miniatura deve ser desenhada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onfilesendmail"></a>CDocument::OnFileSendMail  
 Envia uma mensagem por meio do host de correio residentes (se houver) com o documento como um anexo.  
  
```  
void OnFileSendMail();
```  
  
### <a name="remarks"></a>Comentários  
 `OnFileSendMail`chamadas [OnSaveDocument](#onsavedocument) para serializar (documentos sem título e modificados para um arquivo temporário, que é enviado por email Salvar). Se o documento não tiver sido modificado, um arquivo temporário não é necessário; o original é enviado. `OnFileSendMail`carrega MAPI32. DLL se ele ainda não tenha sido carregado.  
  
 Uma implementação especial da `OnFileSendMail` para [COleDocument](../../mfc/reference/coledocument-class.md) identificadores composta arquivos corretamente.  
  
 **CDocument** oferece suporte ao envio de seu documento por email se houver suporte mail (MAPI). Consulte os artigos [MAPI tópicos](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).  
  
##  <a name="onloaddocumentfromstream"></a>CDocument::OnLoadDocumentFromStream  
 Chamado pela estrutura quando ele precisa carregar os dados do documento de um fluxo.  
  
```  
virtual HRESULT OnLoadDocumentFromStream(
    IStream* pStream,  
    DWORD grfMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 Um ponteiro para um fluxo de entrada.  
  
 `grfMode`  
 Modo de acesso ao fluxo.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se a carga for bem-sucedida; Caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onnewdocument"></a>CDocument::OnNewDocument  
 Chamado pela estrutura como parte do comando novo arquivo.  
  
```  
virtual BOOL OnNewDocument();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento foi inicializado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função chama o [DeleteContents](#deletecontents) a função de membro para garantir que o documento está vazio e, em seguida, marca o novo documento como limpar. Substitua essa função para inicializar a estrutura de dados para um novo documento. Você deve chamar a versão da classe base dessa função de sua substituição.  
  
 Se o usuário escolher o comando novo arquivo em um aplicativo de SDI, a estrutura usa essa função para reinicializar o documento existente, em vez de criar um novo. Se o usuário escolher um novo arquivo em um aplicativo de interface MDI vários documentos, o framework cria um novo documento de cada vez e, em seguida, chama essa função para inicializá-lo. Você deve colocar o código de inicialização nessa função em vez de no construtor para o comando novo arquivo para ser eficaz em aplicativos SDI.  
  
 Observe que há casos onde `OnNewDocument` é chamado duas vezes. Isso ocorre quando o documento será inserido como um servidor de documento ActiveX. Primeiro, a função é chamada pelo `CreateInstance` método (expostos pelo `COleObjectFactory`-classe derivada) e uma segunda vez, o `InitNew` método (expostos pelo `COleServerDoc`-classe derivada).  
  
### <a name="example"></a>Exemplo  
 Os exemplos a seguir ilustram métodos alternativos de inicializar um objeto de documento.  
  
 [!code-cpp[NVC_MFCDocView&#60;](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#61;](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#62;](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]  
  
##  <a name="onopendocument"></a>CDocument::OnOpenDocument  
 Chamado pela estrutura como parte do comando Abrir arquivo.  
  
```  
virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 Aponta para o caminho do documento a ser aberto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento foi carregado com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função abre o arquivo especificado, chamadas de [DeleteContents](#deletecontents) chamadas de função de membro para garantir que o documento está vazio, [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) ler o arquivo de conteúdo e, em seguida, marca o documento como normal da. Substitua essa função se você quiser usar algo que não seja o mecanismo de arquivamento ou o mecanismo de arquivos. Por exemplo, você pode escrever um aplicativo onde documentos representam registros em um banco de dados em vez de arquivos separados.  
  
 Se o usuário escolher o comando Abrir arquivo em um aplicativo de SDI, a estrutura usa essa função para reinicializar existente **CDocument** objeto, em vez de criar um novo. Se o usuário escolher abrir arquivo em um aplicativo MDI, o framework cria uma nova **CDocument** objeto cada vez e, em seguida, chama essa função para inicializá-lo. Você deve colocar o código de inicialização nessa função em vez de no construtor para o comando Abrir arquivo para ser eficaz em aplicativos SDI.  
  
### <a name="example"></a>Exemplo  
 Os exemplos a seguir ilustram métodos alternativos de inicializar um objeto de documento.  
  
 [!code-cpp[NVC_MFCDocView&#60;](../../mfc/codesnippet/cpp/cdocument-class_5.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#61;](../../mfc/codesnippet/cpp/cdocument-class_6.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#62;](../../mfc/codesnippet/cpp/cdocument-class_7.cpp)]  
  
 [!code-cpp[NVC_MFCDocView&#63;](../../mfc/codesnippet/cpp/cdocument-class_8.cpp)]  
  
##  <a name="onpreviewhandlerqueryfocus"></a>CDocument::OnPreviewHandlerQueryFocus  
 Direciona o Gerenciador de visualização para retornar o HWND recuperados da chamada de `GetFocus` função.  
  
```  
virtual HRESULT OnPreviewHandlerQueryFocus(HWND* phwnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `phwnd`  
 [out] Quando este método retorna, contém um ponteiro para o HWND retornado ao chamar o `GetFocus` função de thread de primeiro plano do Gerenciador de visualização.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK se for bem-sucedida; ou um valor de erro caso contrário.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onpreviewhandlertranslateaccelerator"></a>CDocument::OnPreviewHandlerTranslateAccelerator  
 Direciona o Gerenciador de visualização para manipular um pressionamento de tecla passado acima da bomba de mensagens do processo no qual o Gerenciador de visualização está em execução.  
  
```  
virtual HRESULT OnPreviewHandlerTranslateAccelerator(MSG* pmsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pmsg`  
 [in] Um ponteiro para uma mensagem em janela.  
  
### <a name="return-value"></a>Valor de retorno  
 Se a mensagem de pressionamento de tecla pode ser processada pelo manipulador de visualização, o manipulador processa e retorna S_OK. Se o Gerenciador de visualização não puder processar a mensagem de pressionamento de tecla, ele oferece ao host por meio de `IPreviewHandlerFrame::TranslateAccelerator`. Se o host processa a mensagem, esse método retorna S_OK. Se o host não processa a mensagem, esse método retorna S_FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrichpreviewbackcolorchanged"></a>CDocument::OnRichPreviewBackColorChanged  
 Chamado quando a cor de plano de fundo da visualização avançada foi alterado.  
  
```  
virtual void OnRichPreviewBackColorChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrichpreviewfontchanged"></a>CDocument::OnRichPreviewFontChanged  
 Chamado quando a fonte de visualização avançada foi alterado.  
  
```  
virtual void OnRichPreviewFontChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrichpreviewsitechanged"></a>CDocument::OnRichPreviewSiteChanged  
 Chamado quando o site de visualização avançada foi alterado.  
  
```  
virtual void OnRichPreviewSiteChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrichpreviewtextcolorchanged"></a>CDocument::OnRichPreviewTextColorChanged  
 Chamado quando a cor do texto de visualização avançada foi alterado.  
  
```  
virtual void OnRichPreviewTextColorChanged();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onsavedocument"></a>CDocument::OnSaveDocument  
 Chamado pela estrutura como parte do comando arquivo salvar ou salvar como arquivo.  
  
```  
virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 Aponta para o caminho totalmente qualificado para o qual o arquivo deve ser salvo.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o documento foi salvo com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função abre o arquivo especificado, chamadas [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) para gravar os dados do documento para o arquivo e as marcas do documento como limpar. Substitua essa função se você quiser executar um processamento especial quando a estrutura salva um documento. Por exemplo, você pode escrever um aplicativo onde documentos representam registros em um banco de dados em vez de arquivos separados.  
  
##  <a name="onunloadhandler"></a>CDocument::OnUnloadHandler  
 Chamado pela estrutura quando o Gerenciador de visualização é descarregado.  
  
```  
virtual void OnUnloadHandler();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onupdatefilesendmail"></a>CDocument::OnUpdateFileSendMail  
 Permite que o **ID_FILE_SEND_MAIL** comando se há suporte a mail (MAPI).  
  
```  
void OnUpdateFileSendMail(CCmdUI* pCmdUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pCmdUI`  
 Um ponteiro para o [CCmdUI](../../mfc/reference/ccmdui-class.md) objeto associado a **ID_FILE_SEND_MAIL** comando.  
  
### <a name="remarks"></a>Comentários  
 Caso contrário, a função remove o **ID_FILE_SEND_MAIL** comando do menu, incluindo separadores acima ou abaixo do menu item conforme apropriado. MAPI estará habilitada se MAPI32. DLL está presente no caminho e, na seção [Mail] do WIN. O arquivo INI, MAPI =&1;. A maioria dos aplicativos colocar esse comando no menu arquivo.  
  
 **CDocument** oferece suporte ao envio de seu documento por email se houver suporte mail (MAPI). Consulte os artigos [MAPI tópicos](../../mfc/mapi.md) e [suporte a MAPI no MFC](../../mfc/mapi-support-in-mfc.md).  
  
##  <a name="precloseframe"></a>CDocument::PreCloseFrame  
 Essa função de membro é chamada pela estrutura antes que a janela do quadro é destruída.  
  
```  
virtual void PreCloseFrame(CFrameWnd* pFrame);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFrame`  
 Ponteiro para o [CFrameWnd](../../mfc/reference/cframewnd-class.md) que contém associado **CDocument** objeto.  
  
### <a name="remarks"></a>Comentários  
 Ele pode ser substituído para fornecer limpeza personalizada, mas não se esqueça de chamar a classe base.  
  
 O padrão de `PreCloseFrame` não faz nada **CDocument**. O **CDocument**-classes derivadas [COleDocument](../../mfc/reference/coledocument-class.md) e [CRichEditDoc](../../mfc/reference/cricheditdoc-class.md) usar essa função de membro.  
  
##  <a name="readnextchunkvalue"></a>CDocument::ReadNextChunkValue  
 Lê o próximo valor de bloco.  
  
```  
virtual BOOL ReadNextChunkValue(IFilterChunkValue** ppValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ppValue`  
 [out] Quando a função retornar, `ppValue` contém o valor que foi lido.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="releasefile"></a>CDocument::ReleaseFile  
 Essa função de membro é chamada pela estrutura para a versão de um arquivo, tornando-o disponível para uso por outros aplicativos.  
  
```  
virtual void ReleaseFile(
    CFile* pFile,  
    BOOL bAbort);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFile`  
 Um ponteiro para o objeto CFile seja liberado.  
  
 `bAbort`  
 Especifica se o arquivo deve ser liberado usando `CFile::Close` ou `CFile::Abort`. **FALSE** se o arquivo deve ser liberado usando [CFile::Close](../../mfc/reference/cfile-class.md#close); **TRUE** se o arquivo deve ser liberado usando [CFile::Abort](../../mfc/reference/cfile-class.md#abort).  
  
### <a name="remarks"></a>Comentários  
 Se `bAbort` é **TRUE**, `ReleaseFile` chamadas `CFile::Abort`, e o arquivo é liberado. `CFile::Abort`não gerará uma exceção.  
  
 Se `bAbort` é **FALSE**, `ReleaseFile` chamadas `CFile::Close` e o arquivo é liberado.  
  
 Substitua essa função de membro para exigir uma ação do usuário antes que o arquivo seja liberado.  
  
##  <a name="removechunk"></a>CDocument::RemoveChunk  
 Remove uma parte com o GUID especificado.  
  
```  
virtual void RemoveChunk(
    REFCLSID guid,  
    DWORD pid);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Guid`  
 Especifica o GUID de uma parte a ser removido.  
  
 `Pid`  
 Especifica o PID de um bloco a ser removido.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="removeview"></a>CDocument::RemoveView  
 Chame essa função para desanexar um modo de exibição de um documento.  
  
```  
void RemoveView(CView* pView);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pView`  
 Aponta para o modo de exibição que está sendo removido.  
  
### <a name="remarks"></a>Comentários  
 Esta função remove a exibição especificada na lista de modos de exibição associada ao documento; Ele também define o ponteiro de documento do modo de exibição de **nulo**. Essa função é chamada pela estrutura ao fechar uma janela de quadro ou um painel de uma janela separadora é fechado.  
  
 Chame essa função somente se você manualmente é desanexação de um modo de exibição. Normalmente você permitirá que o framework desanexar documentos e exibições, definindo uma [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) objeto para associar uma classe de documento, a classe de exibição e a classe de janela de quadro.  
  
 Consulte o exemplo em [adicionar exibição](#addview) para uma implementação de exemplo.  
  
##  <a name="reportsaveloadexception"></a>CDocument::ReportSaveLoadException  
 Chamado se uma exceção é lançada (normalmente um [CFileException](../../mfc/reference/cfileexception-class.md) ou [CArchiveException](../../mfc/reference/carchiveexception-class.md)) ao salvar ou carregar o documento.  
  
```  
virtual void ReportSaveLoadException(
    LPCTSTR lpszPathName,  
    CException* e,  
    BOOL bSaving,  
    UINT nIDPDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 Aponte para o nome do documento que estava sendo salvo ou carregado.  
  
 *e*  
 Aponta para a exceção foi lançada. Pode ser **nulo**.  
  
 *bSaving*  
 Sinalizador que indica qual operação estava em andamento. diferente de zero se o documento estava sendo salvo, 0 se o documento estava sendo carregado.  
  
 `nIDPDefault`  
 Identificador da mensagem de erro a ser exibido se a função não especificar um mais específico.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão examina o objeto de exceção e procura por uma mensagem de erro que descreve especificamente a causa. Se uma mensagem específica não for encontrada ou se *e* é **nulo**, a mensagem geral especificada pelo `nIDPDefault` parâmetro é usado. A função, em seguida, exibe uma caixa de mensagem que contém a mensagem de erro. Substitua essa função se você quiser fornecer mensagens de falha adicional e personalizado. Isso é uma avançada substituível.  
  
##  <a name="savemodified"></a>CDocument::SaveModified  
 Chamado pela estrutura antes que um documento modificado seja fechado.  
  
```  
virtual BOOL SaveModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se é seguro continuar e fechar o documento. 0 se o documento não deve ser fechado.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão dessa função exibe uma caixa de mensagem perguntando ao usuário se deseja salvar as alterações no documento, se nenhum tiver sido feita. Substitua essa função se seu programa requer um procedimento de solicitação diferente. Isso é uma avançada substituível.  
  
##  <a name="setchunkvalue"></a>CDocument::SetChunkValue  
 Define um valor de bloco.  
  
```  
virtual BOOL SetChunkValue (IFilterChunkValue* pValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pValue`  
 Especifica um valor de bloco para definir.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setmodifiedflag"></a>CDocument::SetModifiedFlag  
 Chame essa função depois de ter feito as modificações no documento.  
  
```  
virtual void SetModifiedFlag(BOOL bModified = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bModified`  
 Sinalizador que indica se o documento foi modificado.  
  
### <a name="remarks"></a>Comentários  
 Ao chamar essa função consistentemente, você garante que a estrutura solicita ao usuário para salvar as alterações antes de fechar um documento. Normalmente, você deve usar o valor padrão de **TRUE** para o `bModified` parâmetro. Para marcar um documento mais limpo (não modificado), chame essa função com um valor de **FALSE**.  
  
##  <a name="setpathname"></a>CDocument::SetPathName  
 Chame essa função para especificar o caminho totalmente qualificado do arquivo de disco do documento.  
  
```  
virtual void SetPathName(
    LPCTSTR lpszPathName,  
    BOOL bAddToMRU = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszPathName`  
 Aponta para a cadeia de caracteres a ser usado como o caminho para o documento.  
  
 `bAddToMRU`  
 Determina se o nome do arquivo é adicionado aos lista mais usados recentemente (MRU) arquivos. Se **verdadeiro,** o nome do arquivo é adicionado; se **FALSE**, ele não é adicionado.  
  
### <a name="remarks"></a>Comentários  
 Dependendo do valor de `bAddToMRU` o caminho é adicionado ou não adicionado à lista MRU mantida pelo aplicativo. Observe que alguns documentos não estão associados um arquivo de disco. Chame essa função somente se você está substituindo a implementação padrão para abrir e salvar arquivos usados pela estrutura.  
  
##  <a name="settitle"></a>CDocument::SetTitle  
 Chame essa função para especificar o título do documento (cadeia de caracteres exibida na barra de título de uma janela de quadro).  
  
```  
virtual void SetTitle(LPCTSTR lpszTitle);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszTitle`  
 Aponta para a cadeia de caracteres a ser usado como o título do documento.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função atualiza os títulos de todas as janelas de quadro que exibem o documento.  
  
##  <a name="updateallviews"></a>CDocument::UpdateAllViews  
 Chame essa função depois que o documento foi modificado.  
  
```  
void UpdateAllViews(
    CView* pSender,  
    LPARAM lHint = 0L,  
    CObject* pHint = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pSender`  
 Aponta para o modo de exibição que modificou o documento, ou **nulo** se todas as exibições serão atualizados.  
  
 `lHint`  
 Contém informações sobre a modificação.  
  
 `pHint`  
 Aponta para um objeto de armazenamento de informações sobre a modificação.  
  
### <a name="remarks"></a>Comentários  
 Você deve chamar essa função depois de chamar o [SetModifiedFlag](#setmodifiedflag) função de membro. Essa função informa cada exibição anexada ao documento, exceto para o modo especificado por `pSender`, que o documento foi modificado. Além disso, você normalmente chama essa função de sua classe de exibição depois que o usuário alterou o documento através de uma exibição.  
  
 Essa função chama o [CView::OnUpdate](../../mfc/reference/cview-class.md#onupdate) exibir a função de membro para cada um dos modos de exibição do documento exceto o envio, passando `pHint` e `lHint`. Use esses parâmetros para passar informações para os modos de exibição sobre as modificações feitas no documento. Você pode codificar usando informações `lHint` e/ou você pode definir um [CObject](../../mfc/reference/cobject-class.md)-classe para armazenar informações sobre as modificações e passe um objeto usando essa classe derivada `pHint`. Substituir o `CView::OnUpdate` função de membro em sua [CView](../../mfc/reference/cview-class.md)-classe para otimizar a atualização da exibição do modo de exibição com base nas informações passadas derivada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#64;](../../mfc/codesnippet/cpp/cdocument-class_9.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDIDOCVW](../../visual-cpp-samples.md)   
 [Exemplo MFC SNAPVW](../../visual-cpp-samples.md)   
 [Exemplo MFC NPP](../../visual-cpp-samples.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CDocTemplate](../../mfc/reference/cdoctemplate-class.md)

