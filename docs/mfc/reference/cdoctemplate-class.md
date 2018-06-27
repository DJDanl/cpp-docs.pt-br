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
ms.openlocfilehash: 9a1ee27994a83206b576452d30b108f01c794353
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36957479"
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
|[CDocTemplate::AddDocument](#adddocument)|Adiciona um documento em um modelo.|  
|[CDocTemplate::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos associados a este modelo.|  
|[CDocTemplate::CreateNewDocument](#createnewdocument)|Cria um novo documento.|  
|[CDocTemplate::CreateNewFrame](#createnewframe)|Cria uma nova janela do quadro que contém um documento e o modo de exibição.|  
|[CDocTemplate::CreateOleFrame](#createoleframe)|Cria uma janela do quadro OLE habilitados.|  
|[CDocTemplate::CreatePreviewFrame](#createpreviewframe)|Cria um quadro filho usado para visualização avançada.|  
|[CDocTemplate::GetDocString](#getdocstring)|Recupera uma cadeia de caracteres associada ao tipo de documento.|  
|[CDocTemplate::GetFirstDocPosition](#getfirstdocposition)|Recupera a posição do primeiro documento associado a esse modelo.|  
|[CDocTemplate::GetNextDoc](#getnextdoc)|Recupera um documento e a posição de um.|  
|[CDocTemplate::InitialUpdateFrame](#initialupdateframe)|Inicializa a janela do quadro e, opcionalmente, torna visível.|  
|[CDocTemplate::LoadTemplate](#loadtemplate)|Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.|  
|[CDocTemplate::MatchDocType](#matchdoctype)|Determina o nível de confiança na correspondência entre um tipo de documento e este modelo.|  
|[CDocTemplate::OpenDocumentFile](#opendocumentfile)|Abre um arquivo especificado por um nome de caminho.|  
|[CDocTemplate::RemoveDocument](#removedocument)|Remove um documento de um modelo.|  
|[CDocTemplate::SaveAllModified](#saveallmodified)|Salva todos os documentos associados com esse modelo, que foram modificados.|  
|[CDocTemplate::SetContainerInfo](#setcontainerinfo)|Determina os recursos para contêineres OLE ao editar um item OLE no local.|  
|[CDocTemplate::SetDefaultTitle](#setdefaulttitle)|Exibe o título padrão na barra de título da janela do documento.|  
|[CDocTemplate::SetPreviewInfo](#setpreviewinfo)|Manipulador de visualização de configurações fora do processo.|  
|[CDocTemplate::SetServerInfo](#setserverinfo)|Determina os recursos e as classes de quando o documento de servidor é inserido ou editados no local.|  
  
## <a name="remarks"></a>Comentários  
 Você normalmente crie um ou mais modelos de documento na implementação do seu aplicativo `InitInstance` função. Um modelo de documento define as relações entre os três tipos de classes:  
  
-   Uma classe de documento, que derivam de `CDocument`.  
  
-   Uma classe de exibição, que exibe dados de classe de documento listado acima. Você pode derivar dessa classe de `CView`, `CScrollView`, `CFormView`, ou `CEditView`. (Você também pode usar `CEditView` diretamente.)  
  
-   Uma classe de janela de quadro, que contém a exibição. Para um aplicativo de interface (SDI) único documento, você derivar dessa classe de `CFrameWnd`. Para um aplicativo de interface MDI vários documentos, você derivar dessa classe de `CMDIChildWnd`. Se você não precisa personalizar o comportamento da janela do quadro, você pode usar `CFrameWnd` ou `CMDIChildWnd` diretamente sem derivando sua própria classe.  
  
 Seu aplicativo tem um modelo de documento para cada tipo de documento que ele suporta. Por exemplo, se seu aplicativo suporta planilhas e documentos de texto, o aplicativo tem dois objetos de modelo de documento. Cada modelo de documento é responsável por criar e gerenciar todos os documentos de seu tipo.  
  
 O modelo de documento armazena ponteiros para o `CRuntimeClass` objetos para o documento, exibição e classes de janela do quadro. Essas `CRuntimeClass` objetos são especificados durante a criação de um modelo de documento.  
  
 O modelo de documento contém a ID dos recursos usados com o tipo de documento (como menu, ícone ou recursos do acelerador de tabela). O modelo de documento também tem cadeias de caracteres que contém informações adicionais sobre o seu tipo de documento. Isso inclui o nome de tipo de documento (por exemplo, "planilha") e a extensão de arquivo (por exemplo, ". xls"). Opcionalmente, ele pode conter outras cadeias de caracteres usadas pela interface do usuário do aplicativo, o Gerenciador de arquivos do Windows e vinculação e suporte a incorporação de objetos (OLE).  
  
 Se seu aplicativo é um contêiner OLE e/ou servidor, o modelo de documento também define a ID do menu usado durante a ativação no local. Se seu aplicativo for um servidor OLE, o modelo de documento define a ID da barra de ferramentas e menus usados durante a ativação no local. Especifique esses recursos adicionais do OLE chamando `SetContainerInfo` e `SetServerInfo`.  
  
 Porque `CDocTemplate` é uma classe abstrata, você não pode usar a classe diretamente. Um aplicativo típico usa um dos dois `CDocTemplate`-derivado classes fornecidas pela biblioteca Microsoft Foundation Class: `CSingleDocTemplate`, que implementa o SDI, e `CMultiDocTemplate`, que implementa MDI. Consulte as classes para obter mais informações sobre como usar modelos de documento.  
  
 Se seu aplicativo requer um paradigma de interface do usuário que é bem diferente de SDI ou MDI, você pode derivar sua própria classe de `CDocTemplate`.  
  
 Para obter mais informações sobre `CDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDocTemplate`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
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
 Especifica a ID dos recursos usados com o tipo de documento. Isso pode incluir recursos de cadeia de caracteres, ícone, tabela de Aceleradores e menu.  
  
 O recurso de cadeia de caracteres consiste em subcadeias de caracteres até sete separadas pelo caractere '\n' (o caractere '\n' é necessário como um espaço reservado, se uma subcadeia de caracteres não está incluída; no entanto, não são necessários caracteres à direita de '\n'); Esses subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [GetDocString](#getdocstring). Esse recurso de cadeia de caracteres foi encontrado no arquivo de recurso do aplicativo. Por exemplo:  
  
 `// MYCALC.RC`  
  
 `STRINGTABLE PRELOAD DISCARDABLE`  
  
 `BEGIN`  
  
 `IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"`  
  
 `END`  
  
 Observe que a cadeia de caracteres começa com um caractere '\n'; Isso ocorre porque a primeira subcadeia de caracteres não é usada para aplicativos MDI e portanto não está incluída. Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira é exibida como uma única entrada no Editor de cadeia de caracteres, não como sete entradas separadas.  
  
 *pDocClass*  
 Aponta para o `CRuntimeClass` objeto da classe do documento. Essa classe é um `CDocument`-definir para representar documentos de classe derivada.  
  
 *pFrameClass*  
 Aponta para o `CRuntimeClass` objeto da classe de janela do quadro. Essa classe pode ser um `CFrameWnd`-classe derivada, ou pode ser `CFrameWnd` em si, se você quiser o comportamento padrão para a janela do quadro principal.  
  
 *pViewClass*  
 Aponta para o `CRuntimeClass` objeto da classe de exibição. Essa classe é um `CView`-definir para exibir seus documentos de classe derivada.  
  
### <a name="remarks"></a>Comentários  
 Use esta função de membro para construir um `CDocTemplate` objeto. Alocar dinamicamente um `CDocTemplate` de objeto e passá-lo para [CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) do `InitInstance` a função de membro da classe do aplicativo.  
  
##  <a name="closealldocuments"></a>  CDocTemplate::CloseAllDocuments  
 Chame essa função de membro para fechar todos os documentos abertos.  
  
```  
virtual void CloseAllDocuments(BOOL bEndSession);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bEndSession*  
 Não usado.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro normalmente é usada como parte do comando arquivo de saída. A implementação padrão Esta função chama o [CDocument::DeleteContents](../../mfc/reference/cdocument-class.md#deletecontents) a função de membro para excluir dados do documento e, em seguida, fecha a janelas de quadro para todas as exibições anexada ao documento.  
  
 Substitua essa função se você deseja exigir que o usuário executar a limpeza especial processamento antes que o documento é fechado. Por exemplo, se o documento representa um registro em um banco de dados, você talvez queira substituir essa função para fechar o banco de dados.  
  
##  <a name="createnewdocument"></a>  CDocTemplate::CreateNewDocument  
 Chame essa função de membro para criar um novo documento do tipo associado a este modelo de documento.  
  
```  
virtual CDocument* CreateNewDocument();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento recentemente criado, ou **nulo** se ocorrer um erro.  
  
##  <a name="createnewframe"></a>  CDocTemplate::CreateNewFrame  
 Cria uma nova janela do quadro que contém um documento e o modo de exibição.  
  
```  
virtual CFrameWnd* CreateNewFrame(
    CDocument* pDoc,  
    CFrameWnd* pOther);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDoc*  
 O documento ao qual a nova janela do quadro deve consultar. Pode ser **nulo**.  
  
 *pOther*  
 A janela do quadro no qual a nova janela do quadro é deve ser baseado. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a janela do quadro recém-criado, ou **nulo** se ocorrer um erro.  
  
### <a name="remarks"></a>Comentários  
 `CreateNewFrame` usa o `CRuntimeClass` objetos passados para o construtor para criar uma nova janela do quadro com um modo de exibição e o documento anexado. Se o *pDoc* parâmetro é **nulo**, a estrutura gera uma mensagem de rastreamento.  
  
 O *pOther* parâmetro é usado para implementar o comando nova janela. Ele fornece uma janela do quadro no qual a nova janela do quadro de modelo. A nova janela do quadro é normalmente criada invisível. Chame essa função para criar janelas de quadro fora a implementação de estrutura padrão de arquivo novo e abrir arquivo.  
  
##  <a name="createoleframe"></a>  CDocTemplate::CreateOleFrame  
 Cria uma janela do quadro OLE.  
  
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
 Um ponteiro para o documento ao qual a nova janela do quadro OLE deve consultar.  
  
 *bCreateView*  
 Determina se uma exibição é criada junto com o quadro.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma janela do quadro se bem-sucedido; Caso contrário, **nulo**.  
  
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
 Um índice da subcadeia de caracteres sejam recuperada da cadeia de caracteres que descreve o tipo de documento. Esse parâmetro pode ter um dos seguintes valores:  
  
- **CDocTemplate::windowTitle** nome que aparece no título da janela do aplicativo (por exemplo, "Microsoft Excel") da barra. Presente somente no modelo de documento para aplicativos SDI.  
  
- **CDocTemplate::docName** raiz para o nome do documento padrão (por exemplo, "Folha"). Esta raiz, mais um número, é usado o nome padrão de um novo documento desse tipo, sempre que o usuário escolhe o novo comando de menu Arquivo (por exemplo, "Planilha1" ou "Planilha2"). Se não for especificado, a opção "Sem título" é usado como o padrão.  
  
- **CDocTemplate::fileNewName** nome deste tipo de documento. Se o aplicativo dá suporte a mais de um tipo de documento, essa cadeia de caracteres é exibida na caixa de diálogo Novo arquivo (por exemplo, "planilha"). Se não for especificado, o tipo de documento é inacessível usando o comando novo arquivo.  
  
- **CDocTemplate::filterName** descrição de tipo de documento e um filtro curinga correspondente documentos desse tipo. Essa cadeia de caracteres é exibida na lista suspensa lista arquivos do tipo na caixa de diálogo Abrir arquivo (por exemplo, "planilhas (*.xls)"). Se não for especificado, o tipo de documento é inacessível usando o comando Abrir arquivo.  
  
- **CDocTemplate::filterExt** extensão para documentos desse tipo (por exemplo, ". xls"). Se não for especificado, o tipo de documento é inacessível usando o comando Abrir arquivo.  
  
- **CDocTemplate::regFileTypeId** identificador para o tipo de documento a ser armazenado no banco de dados de registro mantido pelo Windows. Essa cadeia de caracteres é apenas para uso interno (por exemplo, "ExcelWorksheet"). Se não for especificado, o tipo de documento não pode ser registrado com o Gerenciador de arquivos do Windows.  
  
- **CDocTemplate::regFileTypeName** nome do tipo de documento a ser armazenado no banco de dados de registro. Essa cadeia de caracteres pode ser exibida em caixas de diálogo de aplicativos que acessam o banco de dados do registro (por exemplo, "planilha do Microsoft Excel").  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a subcadeia de caracteres especificada foi encontrada; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar uma subcadeia de caracteres específica que descreve o tipo de documento. A cadeia de caracteres que contém esses subcadeias de caracteres é armazenada no modelo de documento e é derivada de uma cadeia de caracteres no arquivo de recurso para o aplicativo. O framework chama esta função para obter as cadeias de caracteres necessários para a interface do usuário do aplicativo. Se você tiver especificado uma extensão de nome de arquivo para documentos do aplicativo, o framework também chama essa função ao adicionar uma entrada para o banco de dados de registro do Windows; Isso permite que documentos para ser aberto do Gerenciador de arquivos do Windows.  
  
 Chamar essa função somente se você estiver derivando sua própria classe de `CDocTemplate`.  
  
##  <a name="getfirstdocposition"></a>  CDocTemplate::GetFirstDocPosition  
 Recupera a posição do primeiro documento associado a esse modelo.  
  
```  
virtual POSITION GetFirstDocPosition() const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **posição** valor que pode ser usado para iterar pela lista de documentos associados a este modelo de documento; ou **nulo** se a lista está vazia.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para obter a posição do primeiro documento na lista de documentos associados a este modelo. Use o **posição** valor como um argumento para [CDocTemplate::GetNextDoc](#getnextdoc) para iterar pela lista de documentos associados ao modelo.  
  
 [CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) e [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) ambos substituem essa função virtual pura. Qualquer classe que deriva de `CDocTemplate` também deve substituir esta função.  
  
##  <a name="getnextdoc"></a>  CDocTemplate::GetNextDoc  
 Recupera o elemento de lista, identificado pelo *rPos*, em seguida, define *rPos* para o **posição** valor da próxima entrada na lista.  
  
```  
virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o próximo documento na lista de documentos associados a este modelo.  
  
### <a name="parameters"></a>Parâmetros  
 *rPos*  
 Uma referência a um **posição** valor retornado por uma chamada anterior a [GetFirstDocPosition](#getfirstdocposition) ou `GetNextDoc`.  
  
### <a name="remarks"></a>Comentários  
 Se o elemento recuperado é o último na lista, em seguida, o novo valor de *rPos* é definido como **nulo**.  
  
 Você pode usar `GetNextDoc` em um loop de interação direta se estabelecer a posição inicial com uma chamada para [GetFirstDocPosition](#getfirstdocposition).  
  
 Você deve garantir que seu **posição** valor representa uma posição válida na lista. Se ele for inválido, declara a versão de depuração da biblioteca Microsoft Foundation Class.  
  
##  <a name="initialupdateframe"></a>  CDocTemplate::InitialUpdateFrame  
 Inicializa a janela do quadro e, opcionalmente, torna visível.  
  
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
 O documento ao qual o quadro está associado. Pode ser **nulo**.  
  
 *bMakeVisible*  
 Indica se o quadro deve se tornar visíveis e ativos.  
  
### <a name="remarks"></a>Comentários  
 Chamar **IntitialUpdateFrame** depois de criar um novo quadro com `CreateNewFrame`. Chamar essa função faz com que os modos de exibição na janela do quadro para receber seus `OnInitialUpdate` chamadas. Além disso, se não houve anteriormente um modo de exibição ativo, a primeira exibição da janela do quadro fica ativa; o modo de exibição principal é uma exibição com a identificação de filho de **AFX_IDW_PANE_FIRST**. Por fim, a janela do quadro é tornada visível se `bMakeVisible` for diferente de zero. Se *bMakeVisible* for zero, o foco atual e o estado visível da janela do quadro permanecerão inalterado.  
  
 Não é necessário chamar essa função ao usar a implementação da estrutura de arquivo novo e abrir arquivo.  
  
##  <a name="loadtemplate"></a>  CDocTemplate::LoadTemplate  
 Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.  
  
```  
virtual void LoadTemplate();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro é chamada pelo framework para carregar os recursos para um determinado `CDocTemplate` ou classe derivada. Normalmente ele é chamado durante a construção, exceto quando o modelo está sendo construído globalmente. Nesse caso, a chamada para `LoadTemplate` é atrasada até a [CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) é chamado.  
  
##  <a name="matchdoctype"></a>  CDocTemplate::MatchDocType  
 Determina o nível de confiança na correspondência entre um tipo de documento e este modelo.  
  
```  
virtual Confidence MatchDocType(
    LPCTSTR lpszPathName,  
    CDocument*& rpDocMatch);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszPathName*  
 Nome do caminho do arquivo cujo tipo seja determinado.  
  
 *rpDocMatch*  
 Ponteiro para um documento que é atribuído o documento correspondente, se o arquivo especificado por *lpszPathName* já está aberto.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor da **confiança** enumeração, que é definida da seguinte maneira:  
  
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
 Use esta função para determinar o tipo de modelo de documento a ser usado para abrir um arquivo. Se seu aplicativo dá suporte a vários tipos de arquivo, por exemplo, você pode usar essa função para determinar qual dos modelos de documento disponíveis é apropriado para um determinado arquivo chamando `MatchDocType` para cada modelo de ativar e escolhendo um modelo de acordo com o valor de confiança é retornado.  
  
 Se o arquivo especificado por *lpszPathName* já estiver aberto, essa função retorna **CDocTemplate::yesAlreadyOpen** e copia o arquivo **CDocument** objeto para o objeto em *rpDocMatch*.  
  
 Se o arquivo não estiver aberto, mas a extensão no *lpszPathName* coincide com a extensão especificada pela **CDocTemplate::filterExt**, essa função retorna **CDocTemplate::yesAttemptNative** e define *rpDocMatch* para **nulo**. Para obter mais informações sobre **CDocTemplate::filterExt**, consulte [CDocTemplate::GetDocString](#getdocstring).  
  
 Se nenhuma ocorrência for true, a função retorna **CDocTemplate::yesAttemptForeign**.  
  
 A implementação padrão não retornar **CDocTemplate::maybeAttemptForeign** ou **CDocTemplate::maybeAttemptNative**. Substituir essa função para implementar a lógica de correspondência de tipo apropriada para seu aplicativo, talvez usando esses dois valores da **confiança** enumeração.  
  
##  <a name="opendocumentfile"></a>  CDocTemplate::OpenDocumentFile  
 Abre um arquivo especificado por um caminho.  
  
```  
virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName) = 0;  
 
virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszPathName,  
    BOOL bAddToMRU) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *lpszPathName*  
 Ponteiro para o caminho do arquivo que contém o documento a ser aberto.  
  
 [in] *bAddToMRU*  
 `TRUE` indica que o documento é um dos arquivos mais recentes; `FALSE` indica que o documento não é um dos arquivos mais recentes.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o documento cujo arquivo é nomeado por *lpszPathName*; `NULL` se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Abre o arquivo cujo caminho é especificado pelo *lpszPathName*. Se *lpszPathName* é `NULL`, um novo arquivo que contém um documento do tipo associado a esse modelo é criado.  
  
##  <a name="removedocument"></a>  CDocTemplate::RemoveDocument  
 Remove o documento apontado pelo *pDoc* da lista de documentos associados a este modelo.  
  
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
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="setcontainerinfo"></a>  CDocTemplate::SetContainerInfo  
 Determina os recursos para contêineres OLE ao editar um item OLE no local.  
  
```  
void SetContainerInfo(UINT nIDOleInPlaceContainer);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDOleInPlaceContainer*  
 A ID dos recursos usados quando um objeto é ativado.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para definir os recursos a ser usado quando um objeto OLE é ativado no local. Esses recursos podem incluir menus e tabelas de teclas aceleradoras. Esta função geralmente é chamada [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) função do seu aplicativo.  
  
 O menu associado *nIDOleInPlaceContainer* contém separadores que permitem que o menu do item no local ativado para mesclar com o menu do aplicativo recipiente. Para obter mais informações sobre a mesclagem de menus do contêiner e de servidor, consulte o artigo [Menus e recursos OLE](../../mfc/menus-and-resources-ole.md).  
  
##  <a name="setdefaulttitle"></a>  CDocTemplate::SetDefaultTitle  
 Chame essa função para carregar o título do documento padrão e exibi-lo na barra de título do documento.  
  
```  
virtual void SetDefaultTitle(CDocument* pDocument) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDocument*  
 Ponteiro para o documento cujo título será definido.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações sobre o título padrão, consulte a descrição do **CDocTemplate::docName** na [CDocTemplate::GetDocString](#getdocstring).  
  
##  <a name="setserverinfo"></a>  CDocTemplate::SetServerInfo  
 Determina os recursos e as classes de quando o documento de servidor é inserido ou editados no local.  
  
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
 A ID dos recursos usados quando um objeto inserido está ativado no local.  
  
 *pOleFrameClass*  
 Ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura que contém informações de classe para o objeto de janela do quadro criado quando ocorre a ativação no local.  
  
 *pOleViewClass*  
 Ponteiro para um `CRuntimeClass` estrutura que contém informações de classe para o objeto de exibição criado quando ocorre a ativação no local.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função de membro para identificar recursos que serão usados pelo aplicativo de servidor quando o usuário solicita a ativação de um objeto inserido. Esses recursos consistem em menus e tabelas de teclas aceleradoras. Esta função geralmente é chamada `InitInstance` do seu aplicativo.  
  
 O menu associado *nIDOleInPlaceServer* contém separadores que permitem que o menu de servidor mesclar com o menu do contêiner. Para obter mais informações sobre a mesclagem de menus do contêiner e de servidor, consulte o artigo [Menus e recursos OLE](../../mfc/menus-and-resources-ole.md).  
  
##  <a name="createpreviewframe"></a>  CDocTemplate::CreatePreviewFrame  
 Cria um quadro filho usado para visualização avançada.  
  
```  
CFrameWnd* CreatePreviewFrame(
    CWnd* pParentWnd,  
    CDocument* pDoc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParentWnd*  
 Um ponteiro para uma janela pai (geralmente fornecido pelo Shell).  
  
 *pDoc*  
 Um ponteiro para um objeto de documento, cujo conteúdo será visualizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para uma `CFrameWnd` objeto, ou `NULL` se a criação falha.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setpreviewinfo"></a>  CDocTemplate::SetPreviewInfo  
 Define o limite de manipulador de visualização do processo.  
  
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
 Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução do modo de exibição visualização.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)   
 [Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)   
 [Classe CDocument](../../mfc/reference/cdocument-class.md)   
 [Classe CView](../../mfc/reference/cview-class.md)   
 [Classe CScrollView](../../mfc/reference/cscrollview-class.md)   
 [Classe CEditView](../../mfc/reference/ceditview-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)   
 [Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)   
 [Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
