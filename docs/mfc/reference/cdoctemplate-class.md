---
title: Classe CDocTemplate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDocTemplate
- AFXWIN/CDocTemplate
- AFXWIN/CDocTemplate::CDocTemplate
- AFXWIN/CDocTemplate::AddDocument
- AFXWIN/CDocTemplate::CloseAllDocuments
- AFXWIN/CDocTemplate::CreateNewDocument
- AFXWIN/CDocTemplate::CreateNewFrame
- AFXWIN/CDocTemplate::CreateOleFrame
- AFXWIN/CDocTemplate::CreatePreviewFrame
- AFXWIN/CDocTemplate::GetDocString
- AFXWIN/CDocTemplate::GetFirstDocPosition
- AFXWIN/CDocTemplate::GetNextDoc
- AFXWIN/CDocTemplate::InitialUpdateFrame
- AFXWIN/CDocTemplate::LoadTemplate
- AFXWIN/CDocTemplate::MatchDocType
- AFXWIN/CDocTemplate::OpenDocumentFile
- AFXWIN/CDocTemplate::RemoveDocument
- AFXWIN/CDocTemplate::SaveAllModified
- AFXWIN/CDocTemplate::SetContainerInfo
- AFXWIN/CDocTemplate::SetDefaultTitle
- AFXWIN/CDocTemplate::SetPreviewInfo
- AFXWIN/CDocTemplate::SetServerInfo
dev_langs:
- C++
helpviewer_keywords:
- CDocTemplate [MFC], CDocTemplate
- CDocTemplate [MFC], AddDocument
- CDocTemplate [MFC], CloseAllDocuments
- CDocTemplate [MFC], CreateNewDocument
- CDocTemplate [MFC], CreateNewFrame
- CDocTemplate [MFC], CreateOleFrame
- CDocTemplate [MFC], CreatePreviewFrame
- CDocTemplate [MFC], GetDocString
- CDocTemplate [MFC], GetFirstDocPosition
- CDocTemplate [MFC], GetNextDoc
- CDocTemplate [MFC], InitialUpdateFrame
- CDocTemplate [MFC], LoadTemplate
- CDocTemplate [MFC], MatchDocType
- CDocTemplate [MFC], OpenDocumentFile
- CDocTemplate [MFC], RemoveDocument
- CDocTemplate [MFC], SaveAllModified
- CDocTemplate [MFC], SetContainerInfo
- CDocTemplate [MFC], SetDefaultTitle
- CDocTemplate [MFC], SetPreviewInfo
- CDocTemplate [MFC], SetServerInfo
ms.assetid: 14b41a1f-bf9d-4eac-b6a8-4c54ffcc77f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd7e80d3c01cf84080ba2b5851da99584122ec4c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46023937"
---
# <a name="cdoctemplate-class"></a>Classe CDocTemplate
Uma classe base abstrata que define a funcionalidade básica para modelos de documento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDocTemplate : public CCmdTarget  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocTemplate::CDocTemplate](#cdoctemplate)|Constrói um objeto `CDocTemplate`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocTemplate::AddDocument](#adddocument)|Adiciona um documento a um modelo.|  
|[CDocTemplate::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos associados com este modelo.|  
|[CDocTemplate::CreateNewDocument](#createnewdocument)|Cria um novo documento.|  
|[CDocTemplate::CreateNewFrame](#createnewframe)|Cria uma nova janela de quadro que contém um documento e o modo de exibição.|  
|[CDocTemplate::CreateOleFrame](#createoleframe)|Cria uma janela do quadro OLE habilitados.|  
|[CDocTemplate::CreatePreviewFrame](#createpreviewframe)|Cria um quadro filho usado para visualização avançada.|  
|[CDocTemplate::GetDocString](#getdocstring)|Recupera uma cadeia de caracteres associada ao tipo de documento.|  
|[CDocTemplate::GetFirstDocPosition](#getfirstdocposition)|Recupera a posição do primeiro documento associado a esse modelo.|  
|[CDocTemplate::GetNextDoc](#getnextdoc)|Recupera um documento e a posição do próximo.|  
|[CDocTemplate::InitialUpdateFrame](#initialupdateframe)|Inicializa a janela do quadro e, opcionalmente, se torna visível.|  
|[CDocTemplate::LoadTemplate](#loadtemplate)|Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.|  
|[CDocTemplate::MatchDocType](#matchdoctype)|Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.|  
|[CDocTemplate::OpenDocumentFile](#opendocumentfile)|Abre um arquivo especificado por um nome de caminho.|  
|[CDocTemplate::RemoveDocument](#removedocument)|Remove um documento de um modelo.|  
|[CDocTemplate::SaveAllModified](#saveallmodified)|Salva todos os documentos associados com esse modelo, que foram modificados.|  
|[CDocTemplate::SetContainerInfo](#setcontainerinfo)|Determina os recursos para contêineres OLE ao editar um item OLE no local.|  
|[CDocTemplate::SetDefaultTitle](#setdefaulttitle)|Exibe o título padrão na barra de título da janela do documento.|  
|[CDocTemplate::SetPreviewInfo](#setpreviewinfo)|Gerenciador de visualização de configurações fora do processo.|  
|[CDocTemplate::SetServerInfo](#setserverinfo)|Determina os recursos e classes quando o documento de servidor é inserido ou editados in-loco.|  
  
## <a name="remarks"></a>Comentários  
 Você normalmente cria um ou mais modelos de documento na implementação do seu aplicativo `InitInstance` função. Um modelo de documento define as relações entre os três tipos de classes:  
  
-   Uma classe de documento, que derivam de `CDocument`.  
  
-   Uma classe de exibição, que exibe dados de classe de documento listada acima. Você pode derivar desta classe de `CView`, `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)  
  
-   Uma classe de janela de quadro, que contém a exibição. Para um aplicativo de interface (SDI) único documento, você derivar desta classe de `CFrameWnd`. Para um aplicativo de interface MDI vários documentos, você derive essa classe de `CMDIChildWnd`. Se você não precisar personalizar o comportamento da janela do quadro, você pode usar `CFrameWnd` ou `CMDIChildWnd` diretamente sem sua própria classe.  
  
 Seu aplicativo tem um modelo de documento para cada tipo de documento que ela dá suporte. Por exemplo, se seu aplicativo dá suporte a planilhas e documentos de texto, o aplicativo tem dois objetos de modelo de documento. Cada modelo de documento é responsável por criar e gerenciar todos os documentos de seu tipo.  
  
 O modelo de documento armazena ponteiros para o `CRuntimeClass` objetos para o documento, exibição e classes de janela do quadro. Eles `CRuntimeClass` objetos são especificados ao construir um modelo de documento.  
  
 O modelo de documento contém a ID dos recursos usados com o tipo de documento (por exemplo, menu, ícone ou recursos do acelerador de tabela). O modelo de documento também tem cadeias de caracteres que contém informações adicionais sobre o seu tipo de documento. Isso inclui o nome do tipo de documento (por exemplo, "planilha") e a extensão de arquivo (por exemplo, ". xls"). Opcionalmente, ele pode conter outras cadeias de caracteres usadas pela interface do usuário do aplicativo, o Gerenciador de arquivos do Windows e vinculação e incorporação de objetos (OLE) suporte.  
  
 Se seu aplicativo for um contêiner OLE e/ou servidor, o modelo de documento também define a ID do menu usada durante a ativação in-loco. Se seu aplicativo for um servidor OLE, o modelo de documento define a ID da barra de ferramentas e menus usados durante a ativação in-loco. Especifique estes recursos adicionais do OLE, chamando `SetContainerInfo` e `SetServerInfo`.  
  
 Porque `CDocTemplate` é uma classe abstrata, você não pode usar a classe diretamente. Um aplicativo típico usa um dos dois `CDocTemplate`-classes fornecidas pela biblioteca de classes Microsoft Foundation derivadas: `CSingleDocTemplate`, que implementa o SDI, e `CMultiDocTemplate`, que implementa MDI. Consulte essas classes para obter mais informações sobre como usar modelos de documento.  
  
 Se seu aplicativo requer um paradigma de interface do usuário que é fundamentalmente diferente de SDI ou MDI, você pode derivar sua própria classe de `CDocTemplate`.  
  
 Para obter mais informações sobre `CDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDocTemplate`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="adddocument"></a>  CDocTemplate::AddDocument  
 Use esta função para adicionar um documento a um modelo.  
  
```  
virtual void AddDocument(CDocument* pDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDoc*  
 Um ponteiro para o documento a ser adicionado.  
  
### <a name="remarks"></a>Comentários  
 As classes derivadas [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) e [CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) substituem essa função. Se você derivar sua própria classe de modelo de documento de `CDocTemplate`, sua classe derivada deve substituir esta função.  
  
##  <a name="cdoctemplate"></a>  CDocTemplate::CDocTemplate  
 Constrói um objeto `CDocTemplate`.  
  
```  
CDocTemplate (
    UINT nIDResource,  
    CRuntimeClass* pDocClass,  
    CRuntimeClass* pFrameClass,  
    CRuntimeClass* pViewClass);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDResource*  
 Especifica a identificação dos recursos usados com o tipo de documento. Isso pode incluir recursos de cadeia de caracteres, ícone, tabela de Aceleradores e menu.  
  
 O recurso de cadeia de caracteres consiste em subcadeias de caracteres até sete separadas pelo caractere '\n' (o caractere '\n' é necessário como um espaço reservado, se uma subcadeia de caracteres não for incluída; no entanto, não são necessários de caracteres à direita de '\n'); Esses subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [GetDocString](#getdocstring). Esse recurso de cadeia de caracteres for encontrado no arquivo de recurso do aplicativo. Por exemplo:  

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

 Observe que a cadeia de caracteres começa com um caractere '\n'; Isso ocorre porque a primeira subcadeia de caracteres não é usada para aplicativos MDI e portanto, não está incluída. Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibido como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.  
  
 *pDocClass*  
 Aponta para o `CRuntimeClass` objeto da classe do documento. Essa classe é um `CDocument`-derivado da classe que você define para representar seus documentos.  
  
 *pFrameClass*  
 Aponta para o `CRuntimeClass` objeto da classe de janela do quadro. Essa classe pode ser um `CFrameWnd`-classe derivada, ou pode ser `CFrameWnd` em si, se você quiser o comportamento padrão para a janela do quadro principal.  
  
 *pViewClass*  
 Aponta para o `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-derivado da classe que você define para exibir seus documentos.  
  
### <a name="remarks"></a>Comentários  
 Use essa função de membro para construir um `CDocTemplate` objeto. Alocar dinamicamente um `CDocTemplate` do objeto e passá-lo para [CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) da `InitInstance` função de membro de sua classe de aplicativo.  
  
##  <a name="closealldocuments"></a>  CDocTemplate::CloseAllDocuments  
 Chame essa função de membro para fechar todos os documentos abertos.  
  
```  
virtual void CloseAllDocuments(BOOL bEndSession);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bEndSession*  
 Não usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro normalmente é usada como parte do comando de saída de arquivo. A implementação padrão dessa função chama o [CDocument::DeleteContents](../../mfc/reference/cdocument-class.md#deletecontents) a função de membro para excluir dados do documento e, em seguida, fecha as janelas de quadro para todas as exibições são anexadas ao documento.  
  
 Substitua essa função se você quiser exigir que o usuário executar o processamento de limpeza especial antes do documento é fechado. Por exemplo, se o documento representa um registro em um banco de dados, você talvez queira substituir essa função para fechar o banco de dados.  
  
##  <a name="createnewdocument"></a>  CDocTemplate::CreateNewDocument  
 Chame essa função de membro para criar um novo documento do tipo associado com esse modelo de documento.  
  
```  
virtual CDocument* CreateNewDocument();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento recém-criado ou nulo se ocorrer um erro.  
  
##  <a name="createnewframe"></a>  CDocTemplate::CreateNewFrame  
 Cria uma nova janela de quadro que contém um documento e o modo de exibição.  
  
```  
virtual CFrameWnd* CreateNewFrame(
    CDocument* pDoc,  
    CFrameWnd* pOther);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDoc*  
 O documento ao qual a nova janela de quadro deve se referir. Pode ser NULL.  
  
 *pOther*  
 A janela do quadro no qual a nova janela de quadro deve ser baseada. Pode ser NULL.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela do quadro recém-criado ou nulo se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 `CreateNewFrame` usa o `CRuntimeClass` objetos passados para o construtor para criar uma nova janela de quadro com um modo de exibição e o documento anexado. Se o *pDoc* parâmetro for NULL, a estrutura gera uma mensagem de rastreamento.  
  
 O *pOther* parâmetro é usado para implementar o comando nova janela. Ele fornece uma janela do quadro no qual a nova janela do quadro de modelo. A nova janela do quadro é geralmente criada invisível. Chame essa função para criar janelas de quadro fora a implementação de estrutura padrão do novo arquivo e abrir arquivo.  
  
##  <a name="createoleframe"></a>  CDocTemplate::CreateOleFrame  
 Cria uma janela de quadro do OLE.  
  
```  
CFrameWnd* CreateOleFrame(
    CWnd* pParentWnd,  
    CDocument* pDoc,  
    BOOL bCreateView);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Um ponteiro para a janela do pai do quadro.  
  
 *pDoc*  
 Um ponteiro para o documento ao qual a nova janela de quadro OLE deve consultar.  
  
 *bCreateView*  
 Determina se um modo de exibição é criado junto com o quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma janela do quadro se bem-sucedido; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Se *bCreateView* for zero, um quadro vazio é criado.  
  
##  <a name="getdocstring"></a>  CDocTemplate::GetDocString  
 Recupera uma cadeia de caracteres associada ao tipo de documento.  
  
```  
virtual BOOL GetDocString(
    CString& rString,  
    enum DocStringIndex index) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *rString*  
 Uma referência a um `CString` objeto que contém a cadeia de caracteres quando a função retorna.  
  
 *index*  
 Um índice da subcadeia de caracteres que está sendo recuperado da cadeia de caracteres que descreve o tipo de documento. Esse parâmetro pode ter um dos seguintes valores:  
  
- `CDocTemplate::windowTitle` Nome que aparece no título da janela do aplicativo (por exemplo, "Microsoft Excel") da barra. Presente somente no modelo de documento para aplicativos SDI.  
  
- `CDocTemplate::docName` Raiz para o nome do documento padrão (por exemplo, "Folha"). Essa raiz, mais um número, é usado para o nome padrão de um novo documento desse tipo, sempre que o usuário escolhe o comando novo no menu Arquivo (por exemplo, "Planilha1" ou "Planilha2"). Se não for especificado, a opção "Sem título" é usado como o padrão.  
  
- `CDocTemplate::fileNewName` Nome desse tipo de documento. Se o aplicativo dá suporte a mais de um tipo de documento, essa cadeia de caracteres será exibida na caixa de diálogo Novo arquivo (por exemplo, "planilha"). Se não for especificado, o tipo de documento é inacessível usando o comando novo arquivo.  
  
- `CDocTemplate::filterName` Descrição do tipo de documento e uma correspondência de documentos desse tipo de filtro de curinga. Essa cadeia de caracteres é exibida na lista suspensa lista arquivos do tipo na caixa de diálogo Abrir arquivo (por exemplo, "planilhas (*. xls)"). Se não for especificado, o tipo de documento é inacessível usando o comando Abrir arquivo.  
  
- `CDocTemplate::filterExt` Extensão para documentos desse tipo (por exemplo, ". xls"). Se não for especificado, o tipo de documento é inacessível usando o comando Abrir arquivo.  
  
- `CDocTemplate::regFileTypeId` Identificador para o tipo de documento a ser armazenado no banco de dados de registro mantido pelo Windows. Essa cadeia de caracteres é apenas para uso interno (por exemplo, "ExcelWorksheet"). Se não for especificado, o tipo de documento não pode ser registrado com o Gerenciador de arquivos do Windows.  
  
- `CDocTemplate::regFileTypeName` Nome do tipo de documento a ser armazenado no banco de dados de registro. Essa cadeia de caracteres pode ser exibida nas caixas de diálogo de aplicativos que acessam o banco de dados do registro (por exemplo, "planilha do Microsoft Excel").  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a subcadeia de caracteres especificada foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar uma subcadeia de caracteres específica que descreve o tipo de documento. A cadeia de caracteres que contém esses subcadeias de caracteres é armazenada no modelo de documento e é derivada de uma cadeia de caracteres no arquivo de recurso para o aplicativo. O framework chama essa função para obter as cadeias de caracteres necessária para a interface do usuário do aplicativo. Se você tiver especificado uma extensão de nome de arquivo para documentos do seu aplicativo, a estrutura também chama essa função ao adicionar uma entrada para o banco de dados de registro do Windows; Isso permite que os documentos a ser aberto do Gerenciador de arquivos do Windows.  
  
 Chame essa função somente se você estiver derivando sua própria classe de `CDocTemplate`.  
  
##  <a name="getfirstdocposition"></a>  CDocTemplate::GetFirstDocPosition  
 Recupera a posição do primeiro documento associado a esse modelo.  
  
```  
virtual POSITION GetFirstDocPosition() const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor de posição que pode ser usado para iterar na lista de documentos associados a esse modelo de documento; ou nulo se a lista estiver vazia.  
  
### <a name="remarks"></a>Comentários  
 Use essa função para obter a posição do primeiro documento na lista de documentos associados a esse modelo. Use o valor da posição como um argumento para [CDocTemplate::GetNextDoc](#getnextdoc) para iterar a lista de documentos associados ao modelo.  
  
 [CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) e [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) ambos substituem essa função virtual pura. Qualquer classe que derivam de `CDocTemplate` também deve substituir essa função.  
  
##  <a name="getnextdoc"></a>  CDocTemplate::GetNextDoc  
 Recupera o elemento de lista, identificado pelo *rPos*, em seguida, define *rPos* para o valor da posição da próxima entrada na lista.  
  
```  
virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo documento na lista de documentos associados a esse modelo.  
  
### <a name="parameters"></a>Parâmetros  
 *rPos*  
 Uma referência a um valor de posição retornado por uma chamada anterior a [GetFirstDocPosition](#getfirstdocposition) ou `GetNextDoc`.  
  
### <a name="remarks"></a>Comentários  
 Se o elemento recuperado é o último na lista, em seguida, o novo valor da *rPos* é definido como NULL.  
  
 Você pode usar `GetNextDoc` em um loop de iteração, se você estabelecer a posição inicial com uma chamada para [GetFirstDocPosition](#getfirstdocposition).  
  
 Você deve garantir que o valor da posição representa uma posição válida na lista. Se ele for inválido, a versão de depuração da biblioteca de classes Microsoft Foundation declara.  
  
##  <a name="initialupdateframe"></a>  CDocTemplate::InitialUpdateFrame  
 Inicializa a janela do quadro e, opcionalmente, se torna visível.  
  
```  
virtual void InitialUpdateFrame(
    CFrameWnd* pFrame,  
    CDocument* pDoc,  
    BOOL bMakeVisible = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pFrame*  
 A janela do quadro que precisa de atualização inicial.  
  
 *pDoc*  
 O documento ao qual o quadro está associado. Pode ser NULL.  
  
 *bMakeVisible*  
 Indica se o quadro ficará visível e Active Directory.  
  
### <a name="remarks"></a>Comentários  
 Chame `IntitialUpdateFrame` depois de criar um novo quadro com `CreateNewFrame`. Chamar essa função faz com que os modos de exibição nessa janela de quadro para receber seus `OnInitialUpdate` chamadas. Além disso, se não havia anteriormente um modo de exibição ativo, o modo de exibição principal da janela do quadro ficará ativo; o modo de exibição primário é uma exibição com uma ID de AFX_IDW_PANE_FIRST filho. Por fim, a janela do quadro se torna visível se *bMakeVisible* for diferente de zero. Se *bMakeVisible* for zero, o foco atual e o estado visível da janela do quadro permanecerão inalterado.  
  
 Não é necessário chamar essa função ao usar a implementação da estrutura de arquivo novo e abrir arquivo.  
  
##  <a name="loadtemplate"></a>  CDocTemplate::LoadTemplate  
 Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.  
  
```  
virtual void LoadTemplate();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro é chamada pelo framework para carregar os recursos para um determinado `CDocTemplate` ou classe derivada. Normalmente é chamado durante a construção, exceto quando o modelo está sendo construído globalmente. Nesse caso, a chamada para `LoadTemplate` deve ser atrasada até [CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) é chamado.  
  
##  <a name="matchdoctype"></a>  CDocTemplate::MatchDocType  
 Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.  
  
```  
virtual Confidence MatchDocType(
    LPCTSTR lpszPathName,  
    CDocument*& rpDocMatch);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszPathName*  
 Nome do caminho do arquivo cujo tipo deve ser determinada.  
  
 *rpDocMatch*  
 Ponteiro para um documento que é atribuído o documento correspondente, se o arquivo especificado por *lpszPathName* já está aberto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor a partir de **confiança** enumeração, que é definida da seguinte maneira:  
  
```  
enum Confidence  
    {  
    noAttempt,
    maybeAttemptForeign,
    maybeAttemptNative,
    yesAttemptForeign,
    yesAttemptNative,
    yesAlreadyOpen
    };  
```  
  
### <a name="remarks"></a>Comentários  
 Use essa função para determinar o tipo de modelo de documento a ser usado para abrir um arquivo. Se seu aplicativo dá suporte a vários tipos de arquivo, por exemplo, você pode usar essa função para determinar qual dos modelos de documento disponíveis é apropriado para um determinado arquivo chamando `MatchDocType` para cada modelo no turno e escolhendo um modelo de acordo com a o valor de confiança é retornado.  
  
 Se o arquivo especificado por *lpszPathName* já está aberto, essa função retorna `CDocTemplate::yesAlreadyOpen` e copia o arquivo `CDocument` o objeto para o objeto no *rpDocMatch*.  
  
 Se o arquivo não estiver aberto, mas a extensão em *lpszPathName* coincide com a extensão especificada por `CDocTemplate::filterExt`, essa função retorna `CDocTemplate::yesAttemptNative` e define *rpDocMatch* como NULL. Para obter mais informações sobre `CDocTemplate::filterExt`, consulte [CDocTemplate::GetDocString](#getdocstring).  
  
 Se nenhum dos casos for verdadeiro, a função retorna `CDocTemplate::yesAttemptForeign`.  
  
 A implementação padrão não retorna `CDocTemplate::maybeAttemptForeign` ou `CDocTemplate::maybeAttemptNative`. Substituir essa função para implementar a lógica de correspondência de tipo apropriada para seu aplicativo, talvez usando esses dois valores da **confiança** enumeração.  
  
##  <a name="opendocumentfile"></a>  CDocTemplate::OpenDocumentFile  
 Abre um arquivo especificado por um caminho.  
  
```  
virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName) = 0;  
 
virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszPathName,  
    BOOL bAddToMRU) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
*lpszPathName*<br/>
[in] Ponteiro para o caminho do arquivo que contém o documento a ser aberto.  
  
*bAddToMRU*<br/>
[in] TRUE indica que o documento é um dos arquivos mais recentes; FALSE indica que o documento não é um dos arquivos mais recentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento cujo arquivo é nomeado pelo *lpszPathName*; NULL se não for bem-sucedido.  
  
### <a name="remarks"></a>Comentários  
 Abre o arquivo cujo caminho é especificado pelo *lpszPathName*. Se *lpszPathName* for NULL, um novo arquivo que contém um documento do tipo associado com esse modelo é criado.  
  
##  <a name="removedocument"></a>  CDocTemplate::RemoveDocument  
 Remove o documento apontado por *pDoc* da lista de documentos associados a esse modelo.  
  
```  
virtual void RemoveDocument(CDocument* pDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDoc*  
 Ponteiro para o documento a ser removido.  
  
### <a name="remarks"></a>Comentários  
 As classes derivadas `CMultiDocTemplate` e `CSingleDocTemplate` substituem essa função. Se você derivar sua própria classe de modelo de documento de `CDocTemplate`, sua classe derivada deve substituir esta função.  
  
##  <a name="saveallmodified"></a>  CDocTemplate::SaveAllModified  
 Salva todos os documentos que foram modificados.  
  
```  
virtual BOOL SaveAllModified();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
##  <a name="setcontainerinfo"></a>  CDocTemplate::SetContainerInfo  
 Determina os recursos para contêineres OLE ao editar um item OLE no local.  
  
```  
void SetContainerInfo(UINT nIDOleInPlaceContainer);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDOleInPlaceContainer*  
 A ID dos recursos usados quando um objeto inserido é ativado.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir os recursos a serem usados quando um objeto OLE é ativado no local. Esses recursos podem incluir menus e tabelas de aceleradores. Geralmente, essa função é chamada [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) função do seu aplicativo.  
  
 O menu associado *nIDOleInPlaceContainer* contém separadores que permitem que o menu do item no local ativado para mesclar com o menu do aplicativo recipiente. Para obter mais informações sobre a mesclagem de menus do servidor e um contêiner, consulte o artigo [Menus e recursos (OLE)](../../mfc/menus-and-resources-ole.md).  
  
##  <a name="setdefaulttitle"></a>  CDocTemplate::SetDefaultTitle  
 Chame essa função para carregar o título do documento padrão e exibi-lo na barra de título do documento.  
  
```  
virtual void SetDefaultTitle(CDocument* pDocument) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDocument*  
 Ponteiro para o documento cujo título deve ser definido.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações sobre o título padrão, consulte a descrição da `CDocTemplate::docName` na [CDocTemplate::GetDocString](#getdocstring).  
  
##  <a name="setserverinfo"></a>  CDocTemplate::SetServerInfo  
 Determina os recursos e classes quando o documento de servidor é inserido ou editados in-loco.  
  
```  
void SetServerInfo(
    UINT nIDOleEmbedding,  
    UINT nIDOleInPlaceServer = 0,  
    CRuntimeClass* pOleFrameClass = NULL,  
    CRuntimeClass* pOleViewClass = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDOleEmbedding*  
 A ID dos recursos usados quando um objeto inserido é aberto em uma janela separada.  
  
 *nIDOleInPlaceServer*  
 A ID dos recursos usados quando um objeto inserido é ativado no local.  
  
 *pOleFrameClass*  
 Ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que contém informações de classe para o objeto de janela de quadro criado quando ocorre a ativação in-loco.  
  
 *pOleViewClass*  
 Ponteiro para um `CRuntimeClass` estrutura que contém informações de classe para o objeto de exibição criado quando ocorre a ativação in-loco.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para identificar recursos que serão usados pelo aplicativo de servidor quando o usuário solicita a ativação de um objeto inserido. Esses recursos consistem em menus e tabelas de aceleradores. Geralmente, essa função é chamada `InitInstance` do seu aplicativo.  
  
 O menu associado *nIDOleInPlaceServer* contém separadores que permitem que o menu de servidor mesclar com o menu do contêiner. Para obter mais informações sobre a mesclagem de menus do servidor e um contêiner, consulte o artigo [Menus e recursos (OLE)](../../mfc/menus-and-resources-ole.md).  
  
##  <a name="createpreviewframe"></a>  CDocTemplate::CreatePreviewFrame  
 Cria um quadro filho usado para visualização avançada.  
  
```  
CFrameWnd* CreatePreviewFrame(
    CWnd* pParentWnd,  
    CDocument* pDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Um ponteiro para uma janela pai (normalmente fornecido pelo Shell).  
  
 *pDoc*  
 Um ponteiro para um objeto de documento, cujo conteúdo será visualizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para um `CFrameWnd` do objeto ou nulo se a criação falhar.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpreviewinfo"></a>  CDocTemplate::SetPreviewInfo  
 Define o limite do Gerenciador de visualização do processo.  
  
```  
void SetPreviewInfo(
    UINT nIDPreviewFrame,  
    CRuntimeClass* pPreviewFrameClass = NULL,  
    CRuntimeClass* pPreviewViewClass = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDPreviewFrame*  
 Especifica uma ID de recurso do quadro de visualização.  
  
 *pPreviewFrameClass*  
 Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução do quadro de visualização.  
  
 *pPreviewViewClass*  
 Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução do modo de exibição de visualização.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)   
 [Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CScrollView](../../mfc/reference/cscrollview-class.md)   
 [Classe CEditView](../../mfc/reference/ceditview-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
