---
title: Classe CDocTemplate
ms.date: 11/04/2016
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
ms.openlocfilehash: 69b94a4188804f47c950ca31fb5cba80d85176e9
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753304"
---
# <a name="cdoctemplate-class"></a>Classe CDocTemplate

Uma classe base abstrata que define a funcionalidade básica para modelos de documentos.

## <a name="syntax"></a>Sintaxe

```
class CDocTemplate : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocTemplate::CDocTemplate](#cdoctemplate)|Constrói um objeto `CDocTemplate`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocTemplate::AddDocument](#adddocument)|Adiciona um documento a um modelo.|
|[CDocTemplate::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos associados a este modelo.|
|[CDocTemplate::CreateNewDocument](#createnewdocument)|Cria um novo documento.|
|[CDocTemplate::CreateNewFrame](#createnewframe)|Cria uma nova janela de quadro contendo um documento e exibição.|
|[CDocTemplate::CreateOleFrame](#createoleframe)|Cria uma janela de quadro habilitada para OLE.|
|[CDocTemplate::CreatePreviewFrame](#createpreviewframe)|Cria um quadro de criança usado para o Rich Preview.|
|[CDocTemplate::GetDocString](#getdocstring)|Recupera uma seqüência associada ao tipo de documento.|
|[CDocTemplate::GetFirstDocPosition](#getfirstdocposition)|Recupera a posição do primeiro documento associado a este modelo.|
|[CDocTemplate::GetNextDoc](#getnextdoc)|Recupera um documento e a posição do próximo.|
|[CDocTemplate::InitialUpdateFrame](#initialupdateframe)|Inicializa a janela do quadro e, opcionalmente, a torna visível.|
|[CDocTemplate::'Modelo de carga](#loadtemplate)|Carrega os recursos para `CDocTemplate` uma determinada ou derivada classe.|
|[CDocTemplate::MatchDocType](#matchdoctype)|Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.|
|[CDocTemplate::OpenDocumentFile](#opendocumentfile)|Abre um arquivo especificado por um nome de caminho.|
|[CDocTemplate::RemoveDocument](#removedocument)|Remove um documento de um modelo.|
|[CDocTemplate::SaveAllModified](#saveallmodified)|Salva todos os documentos associados a este modelo que foram modificados.|
|[CDocTemplate::SetContainerInfo](#setcontainerinfo)|Determina os recursos para contêineres OLE ao editar um item OLE no local.|
|[CDocTemplate::SetDefaultTitle](#setdefaulttitle)|Exibe o título padrão na barra de título da janela do documento.|
|[CDocTemplate::SetPreviewInfo](#setpreviewinfo)|Configurações fora do manipulador de visualização de processo.|
|[CDocTemplate::SetServerInfo](#setserverinfo)|Determina os recursos e as classes quando o documento do servidor é incorporado ou editado no local.|

## <a name="remarks"></a>Comentários

Você geralmente cria um ou mais modelos de `InitInstance` documento na implementação da função do aplicativo. Um modelo de documento define as relações entre três tipos de classes:

- Uma classe de documentos, `CDocument`da qual você deriva.

- Uma classe de exibição, que exibe dados da classe de documento listada acima. Você pode derivar `CView` `CScrollView`esta `CFormView`classe `CEditView`de, ou . (Você também `CEditView` pode usar diretamente.)

- Uma classe de janela de quadro, que contém a vista. Para um único aplicativo de interface de documento `CFrameWnd`(SDI), você deriva esta classe de . Para um aplicativo de interface de documento múltiplo `CMDIChildWnd`(MDI), você deriva essa classe de . Se você não precisar personalizar o comportamento da janela `CFrameWnd` do `CMDIChildWnd` quadro, você pode usar ou diretamente sem obter sua própria classe.

Seu aplicativo tem um modelo de documento para cada tipo de documento que ele suporta. Por exemplo, se o aplicativo suportar planilhas e documentos de texto, o aplicativo tem dois objetos de modelo de documento. Cada modelo de documento é responsável pela criação e gerenciamento de todos os documentos do seu tipo.

O modelo de documento `CRuntimeClass` armazena ponteiros para os objetos para as classes de document, exibição e janela de quadro. Esses `CRuntimeClass` objetos são especificados ao construir um modelo de documento.

O modelo do documento contém o ID dos recursos utilizados com o tipo de documento (como menu, ícone ou recursos de tabela do acelerador). O modelo do documento também possui strings contendo informações adicionais sobre seu tipo de documento. Estes incluem o nome do tipo de documento (por exemplo, "Planilha") e a extensão de arquivo (por exemplo, ".xls"). Opcionalmente, ele pode conter outras strings usadas pela interface de usuário do aplicativo, o Gerenciador de Arquivos do Windows e o suporte a Vinculação e Incorporação de Objetos (OLE).

Se o aplicativo for um contêiner OLE e/ou servidor, o modelo de documento também definirá o ID do menu usado durante a ativação no local. Se o aplicativo for um servidor OLE, o modelo de documento definirá o ID da barra de ferramentas e o menu usado durante a ativação no local. Você especifica esses recursos adicionais de OLE ligando `SetContainerInfo` e `SetServerInfo`.

Por `CDocTemplate` ser uma aula abstrata, você não pode usar a classe diretamente. Um aplicativo típico usa `CDocTemplate`uma das duas classes derivadas fornecidas `CSingleDocTemplate`pela Microsoft Foundation Class `CMultiDocTemplate`Library: , que implementa o SDI e , que implementa o MDI. Consulte essas classes para obter mais informações sobre o uso de modelos de documentos.

Se o seu aplicativo requer um paradigma de interface de usuário que é fundamentalmente diferente do SDI ou MDI, você pode derivar sua própria classe de `CDocTemplate`.

Para obter `CDocTemplate`mais informações, consulte [Modelos de documentos e o processo de criação de documentos/visualização.](../../mfc/document-templates-and-the-document-view-creation-process.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDocTemplate`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cdoctemplateadddocument"></a><a name="adddocument"></a>CDocTemplate::AddDocument

Use esta função para adicionar um documento a um modelo.

```
virtual void AddDocument(CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Um ponteiro para o documento a ser adicionado.

### <a name="remarks"></a>Comentários

As classes derivadas [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) e [CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) anulam essa função. Se você derivar sua própria `CDocTemplate`classe de modelo de documento, sua classe derivada deve substituir essa função.

## <a name="cdoctemplatecdoctemplate"></a><a name="cdoctemplate"></a>CDocTemplate::CDocTemplate

Constrói um objeto `CDocTemplate`.

```
CDocTemplate (
    UINT nIDResource,
    CRuntimeClass* pDocClass,
    CRuntimeClass* pFrameClass,
    CRuntimeClass* pViewClass);
```

### <a name="parameters"></a>Parâmetros

*Nidresource*<br/>
Especifica o ID dos recursos utilizados com o tipo de documento. Isso pode incluir menu, ícone, tabela de acelerador e recursos de string.

O recurso de seqüência consiste em até sete substringões separadas pelo caractere '\n' (o caractere '\n' é necessário como titular de lugar se uma substring não estiver incluída; no entanto, caracteres '\n' não são necessários); essas substrings descrevem o tipo de documento. Para obter informações sobre as substrings, consulte [GetDocString](#getdocstring). Esse recurso de string é encontrado no arquivo de recursos do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

Observe que a seqüência começa com um caractere '\n'; isso porque a primeira substring não é usada para aplicações MDI e, portanto, não está incluída. Você pode editar esta seqüência usando o editor de seqüência; toda a seqüência aparece como uma única entrada no Editor de cordas, não como sete entradas separadas.

*pDocClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de documentos. Esta classe `CDocument`é uma classe derivada que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe da janela do quadro. Esta classe pode `CFrameWnd`ser uma classe derivada, ou pode ser `CFrameWnd` ela mesma se você quiser comportamento padrão para a janela do quadro principal.

*pViewClass*<br/>
Aponta para `CRuntimeClass` o objeto da classe de exibição. Esta classe `CView`é uma classe derivada que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Use esta função de `CDocTemplate` membro para construir um objeto. Aloque `CDocTemplate` dinamicamente um objeto e passe-o para `InitInstance` [CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) da função membro da sua classe de aplicativo.

## <a name="cdoctemplateclosealldocuments"></a><a name="closealldocuments"></a>CDocTemplate::CloseAllDocuments

Ligue para esta função de membro para fechar todos os documentos abertos.

```
virtual void CloseAllDocuments(BOOL bEndSession);
```

### <a name="parameters"></a>Parâmetros

*bEndSession*<br/>
Não usado.

### <a name="remarks"></a>Comentários

Esta função de membro é normalmente usada como parte do comando File Exit. A implementação padrão desta função chama a função [membro CDocument::DeleteContents](../../mfc/reference/cdocument-class.md#deletecontents) para excluir os dados do documento e, em seguida, fecha as janelas do quadro para todas as visualizações anexadas ao documento.

Anular esta função se você quiser exigir que o usuário realize um processamento especial de limpeza antes que o documento seja fechado. Por exemplo, se o documento representa um registro em um banco de dados, você pode querer substituir essa função para fechar o banco de dados.

## <a name="cdoctemplatecreatenewdocument"></a><a name="createnewdocument"></a>CDocTemplate::CreateNewDocument

Chame esta função de membro para criar um novo documento do tipo associado a este modelo de documento.

```
virtual CDocument* CreateNewDocument();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento recém-criado ou NULL se ocorrer um erro.

## <a name="cdoctemplatecreatenewframe"></a><a name="createnewframe"></a>CDocTemplate::CreateNewFrame

Cria uma nova janela de quadro contendo um documento e exibição.

```
virtual CFrameWnd* CreateNewFrame(
    CDocument* pDoc,
    CFrameWnd* pOther);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
O documento ao qual a nova janela de quadro deve ser encaminhado. Pode ser NULL.

*Pother*<br/>
A janela de quadro na qual a nova janela do quadro deve ser baseada. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela de quadro recém-criada ou NULL se ocorrer um erro.

### <a name="remarks"></a>Comentários

`CreateNewFrame`usa `CRuntimeClass` os objetos passados ao construtor para criar uma nova janela de quadro com uma exibição e documento anexados. Se o parâmetro *pDoc* for NULL, o framework produzirá uma mensagem TRACE.

O *parâmetro pOutro* parâmetro é usado para implementar o comando Janela Nova. Ele fornece uma janela de quadro na qual modelar a nova janela do quadro. A nova janela de quadro satisfaz-se normalmente invisível. Chame esta função para criar janelas de quadro fora da implementação padrão da estrutura padrão de Arquivo Novo e Abertura de Arquivos.

## <a name="cdoctemplatecreateoleframe"></a><a name="createoleframe"></a>CDocTemplate::CreateOleFrame

Cria uma janela de quadro OLE.

```
CFrameWnd* CreateOleFrame(
    CWnd* pParentWnd,
    CDocument* pDoc,
    BOOL bCreateView);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Um ponteiro para a janela dos pais do quadro.

*pDoc*<br/>
Um ponteiro para o documento ao qual a nova janela de quadro OLE deve se referir.

*bCreateView*<br/>
Determina se uma exibição é criada junto com o quadro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma janela de quadro se for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se *bCreateView* for zero, um quadro vazio será criado.

## <a name="cdoctemplategetdocstring"></a><a name="getdocstring"></a>CDocTemplate::GetDocString

Recupera uma seqüência associada ao tipo de documento.

```
virtual BOOL GetDocString(
    CString& rString,
    enum DocStringIndex index) const;
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência `CString` a um objeto que conterá a seqüência quando a função retornar.

*Índice*<br/>
Um índice da substring sendo recuperado da seqüência que descreve o tipo de documento. Esse parâmetro pode ter um dos seguintes valores:

- `CDocTemplate::windowTitle`Nome que aparece na barra de título da janela do aplicativo (por exemplo, "Microsoft Excel"). Presente apenas no modelo de documento para aplicações SDI.

- `CDocTemplate::docName`Raiz para o nome do documento padrão (por exemplo, "Folha"). Essa raiz, mais um número, é usada para o nome padrão de um novo documento desse tipo sempre que o usuário escolhe o comando Novo no menu Arquivo (por exemplo, "Folha1" ou "Folha2"). Se não especificado, "Untitled" é usado como padrão.

- `CDocTemplate::fileNewName`Nome deste tipo de documento. Se o aplicativo suportar mais de um tipo de documento, essa seqüência será exibida na caixa de diálogo Arquivo Novo (por exemplo, "Planilha de trabalho"). Se não for especificado, o tipo de documento fica inacessível usando o comando Arquivo Novo.

- `CDocTemplate::filterName`Descrição do tipo de documento e um filtro curinga que corresponda a documentos deste tipo. Essa seqüência é exibida na lista de arquivos de lista suspensa de tipo na caixa de diálogo Abrir arquivos (por exemplo, "Planilhas (*.xls)"). Se não for especificado, o tipo de documento fica inacessível usando o comando File Open.

- `CDocTemplate::filterExt`Extensão para documentos desse tipo (por exemplo, ".xls"). Se não for especificado, o tipo de documento fica inacessível usando o comando File Open.

- `CDocTemplate::regFileTypeId`Identificador para o tipo de documento a ser armazenado no banco de dados de registro mantido pelo Windows. Esta seqüência é apenas para uso interno (por exemplo, "ExcelWorksheet"). Se não especificado, o tipo de documento não pode ser registrado no Gerenciador de Arquivos do Windows.

- `CDocTemplate::regFileTypeName`Nome do tipo de documento a ser armazenado no banco de dados de registro. Essa seqüência pode ser exibida em caixas de diálogo de aplicativos que acessam o banco de dados de registro (por exemplo, "Planilha de Trabalho do Microsoft Excel").

### <a name="return-value"></a>Valor retornado

Não zero se a substring especificada foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função para recuperar uma substring específica descrevendo o tipo de documento. A seqüência que contém essas substrings é armazenada no modelo do documento e é derivada de uma seqüência no arquivo de recursos para o aplicativo. A estrutura chama essa função para obter as strings que precisa para a interface de usuário do aplicativo. Se você tiver especificado uma extensão de nome de arquivo para os documentos do seu aplicativo, o framework também chamará essa função ao adicionar uma entrada ao banco de dados de registro do Windows; isso permite que documentos sejam abertos a partir do Gerenciador de Arquivos do Windows.

Chame esta função somente se você estiver `CDocTemplate`derivando sua própria classe de .

## <a name="cdoctemplategetfirstdocposition"></a><a name="getfirstdocposition"></a>CDocTemplate::GetFirstDocPosition

Recupera a posição do primeiro documento associado a este modelo.

```
virtual POSITION GetFirstDocPosition() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um valor de POSIÇÃO que pode ser usado para iterar através da lista de documentos associados a este modelo de documento; ou NULO se a lista estiver vazia.

### <a name="remarks"></a>Comentários

Use esta função para obter a posição do primeiro documento na lista de documentos associados a este modelo. Use o valor DE POSIÇÃO como argumento para [CDocTemplate::GetNextDoc](#getnextdoc) para iterar através da lista de documentos associados ao modelo.

[CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) e [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) ambos anulam essa função virtual pura. Qualquer classe da `CDocTemplate` sua origem também deve substituir esta função.

## <a name="cdoctemplategetnextdoc"></a><a name="getnextdoc"></a>CDocTemplate::GetNextDoc

Recupera o elemento de lista identificado por *rPos*e, em seguida, define *rPos* para o valor DE POSIÇÃO da próxima entrada na lista.

```
virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo documento na lista de documentos associados a este modelo.

### <a name="parameters"></a>Parâmetros

*rPos*<br/>
Uma referência a um valor DE POSIÇÃO retornado por `GetNextDoc`uma chamada anterior para [GetFirstDocPosition](#getfirstdocposition) ou .

### <a name="remarks"></a>Comentários

Se o elemento recuperado for o último da lista, então o novo valor dos *rPos* será definido como NULL.

Você pode `GetNextDoc` usar em um loop de iteração para frente se estabelecer a posição inicial com uma chamada para [GetFirstDocPosition](#getfirstdocposition).

Você deve garantir que o valor de POSIÇÃO represente uma posição válida na lista. Se for inválido, a versão Debug da Biblioteca de Classes da Microsoft Foundation afirma.

## <a name="cdoctemplateinitialupdateframe"></a><a name="initialupdateframe"></a>CDocTemplate::InitialUpdateFrame

Inicializa a janela do quadro e, opcionalmente, a torna visível.

```
virtual void InitialUpdateFrame(
    CFrameWnd* pFrame,
    CDocument* pDoc,
    BOOL bMakeVisible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
A janela de quadro que precisa da atualização inicial.

*pDoc*<br/>
O documento ao qual o quadro está associado. Pode ser NULL.

*Bmakevisible*<br/>
Indica se o quadro deve se tornar visível e ativo.

### <a name="remarks"></a>Comentários

Ligue `IntitialUpdateFrame` depois de criar `CreateNewFrame`um novo quadro com . Chamar essa função faz com que as `OnInitialUpdate` visualizações na janela do quadro recebam suas chamadas. Além disso, se não houvesse uma visualização ativa anteriormente, a visão primária da janela do quadro é ativa; a visão primária é uma visão com uma id infantil de AFX_IDW_PANE_FIRST. Finalmente, a janela do quadro é tornada visível se *bMakeVisible* não for zero. Se *bMakeVisible* for zero, o foco atual e o estado visível da janela do quadro permanecerão inalterados.

Não é necessário chamar essa função ao usar a implementação do Arquivo Novo e Arquivo Aberto.

## <a name="cdoctemplateloadtemplate"></a><a name="loadtemplate"></a>CDocTemplate::'Modelo de carga

Carrega os recursos para `CDocTemplate` uma determinada ou derivada classe.

```
virtual void LoadTemplate();
```

### <a name="remarks"></a>Comentários

Esta função membro é chamada pela estrutura para `CDocTemplate` carregar os recursos para uma determinada ou derivada classe. Normalmente é chamado durante a construção, exceto quando o modelo está sendo construído globalmente. Nesse caso, a `LoadTemplate` chamada é adiada até [que CWinApp::AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) seja chamado.

## <a name="cdoctemplatematchdoctype"></a><a name="matchdoctype"></a>CDocTemplate::MatchDocType

Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.

```
virtual Confidence MatchDocType(
    LPCTSTR lpszPathName,
    CDocument*& rpDocMatch);
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
Nome do caminho do arquivo cujo tipo deve ser determinado.

*Rpdocmatch*<br/>
Ponteiro para um documento atribuído ao documento correspondente, se o arquivo especificado pelo *lpszPathName* já estiver aberto.

### <a name="return-value"></a>Valor retornado

Um valor da enumeração **confiança,** que é definido da seguinte forma:

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

Use esta função para determinar o tipo de modelo de documento a ser usado para abrir um arquivo. Se o seu aplicativo suportar vários tipos de arquivo, por exemplo, você pode usar essa função `MatchDocType` para determinar qual dos modelos de documento disponíveis é apropriado para um determinado arquivo, chamando para cada modelo por sua vez, e escolhendo um modelo de acordo com o valor de confiança devolvido.

Se o arquivo especificado pelo *lpszPathName* já `CDocTemplate::yesAlreadyOpen` estiver aberto, `CDocument` essa função será retornada e copiao o objeto do arquivo no objeto em *rpDocMatch*.

Se o arquivo não estiver aberto, mas a extensão no `CDocTemplate::filterExt` *lpszPathName* corresponde à extensão especificada por , esta função retorna `CDocTemplate::yesAttemptNative` e define *rpDocMatch* para NULL. Para obter `CDocTemplate::filterExt`mais informações, consulte [CDocTemplate::GetDocString](#getdocstring).

Se nenhum dos casos for `CDocTemplate::yesAttemptForeign`verdade, a função retorna.

A implementação padrão `CDocTemplate::maybeAttemptForeign` `CDocTemplate::maybeAttemptNative`não retorna ou . Substituir essa função para implementar uma lógica de correspondência de tipo apropriada à sua aplicação, talvez usando esses dois valores da enumeração **Confiança.**

## <a name="cdoctemplateopendocumentfile"></a><a name="opendocumentfile"></a>CDocTemplate::OpenDocumentFile

Abre um arquivo especificado por um caminho.

```
virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName) = 0;

virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszPathName,
    BOOL bAddToMRU) = 0;
```

### <a name="parameters"></a>Parâmetros

*Lpszpathname*<br/>
[em] Ponteiro para o caminho do arquivo que contém o documento a ser aberto.

*bAddToMRU*<br/>
[em] TRUE indica que o documento é um dos arquivos mais recentes; FALSE indica que o documento não é um dos arquivos mais recentes.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento cujo arquivo é nomeado por *lpszPathName*; NULO se não tiver sucesso.

### <a name="remarks"></a>Comentários

Abre o arquivo cujo caminho é especificado por *lpszPathName*. Se *lpszPathName* for NULL, um novo arquivo que contém um documento do tipo associado a este modelo será criado.

## <a name="cdoctemplateremovedocument"></a><a name="removedocument"></a>CDocTemplate::RemoveDocument

Remove o documento apontado pelo *pDoc* da lista de documentos associados a este modelo.

```
virtual void RemoveDocument(CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Ponteiro para o documento a ser removido.

### <a name="remarks"></a>Comentários

As classes `CMultiDocTemplate` derivadas e `CSingleDocTemplate` anular esta função. Se você derivar sua própria `CDocTemplate`classe de modelo de documento, sua classe derivada deve substituir essa função.

## <a name="cdoctemplatesaveallmodified"></a><a name="saveallmodified"></a>CDocTemplate::SaveAllModified

Salva todos os documentos que foram modificados.

```
virtual BOOL SaveAllModified();
```

### <a name="return-value"></a>Valor retornado

Não-zero se bem sucedido; caso contrário, 0.

## <a name="cdoctemplatesetcontainerinfo"></a><a name="setcontainerinfo"></a>CDocTemplate::SetContainerInfo

Determina os recursos para contêineres OLE ao editar um item OLE no local.

```cpp
void SetContainerInfo(UINT nIDOleInPlaceContainer);
```

### <a name="parameters"></a>Parâmetros

*nIDOleInPlaceContainer*<br/>
O ID dos recursos usados quando um objeto incorporado é ativado.

### <a name="remarks"></a>Comentários

Chame esta função para definir os recursos a serem usados quando um objeto OLE estiver ativado no local. Esses recursos podem incluir menus e tabelas de acelerador. Essa função é geralmente chamada na função [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) do seu aplicativo.

O menu associado ao *nIDOleInPlaceContainer* contém separadores que permitem que o menu do item ativado no local se funda com o menu do aplicativo de contêiner. Para obter mais informações sobre a fusão de menus de servidor e contêiner, consulte o artigo [Menus e Recursos (OLE)](../../mfc/menus-and-resources-ole.md).

## <a name="cdoctemplatesetdefaulttitle"></a><a name="setdefaulttitle"></a>CDocTemplate::SetDefaultTitle

Chame esta função para carregar o título padrão do documento e exibi-lo na barra de título do documento.

```
virtual void SetDefaultTitle(CDocument* pDocument) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDocument*<br/>
Ponteiro para o documento cujo título deve ser definido.

### <a name="remarks"></a>Comentários

Para obter informações sobre o título `CDocTemplate::docName` padrão, consulte a descrição de [em CDocTemplate::GetDocString](#getdocstring).

## <a name="cdoctemplatesetserverinfo"></a><a name="setserverinfo"></a>CDocTemplate::SetServerInfo

Determina os recursos e as classes quando o documento do servidor é incorporado ou editado no local.

```cpp
void SetServerInfo(
    UINT nIDOleEmbedding,
    UINT nIDOleInPlaceServer = 0,
    CRuntimeClass* pOleFrameClass = NULL,
    CRuntimeClass* pOleViewClass = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDOleEmbedding*<br/>
O ID dos recursos usados quando um objeto incorporado é aberto em uma janela separada.

*nIDOleInPlaceServer*<br/>
O ID dos recursos usados quando um objeto incorporado é ativado no local.

*pOleFrameClass*<br/>
Ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) contendo informações de classe para o objeto da janela do quadro criado quando ocorre ativação no local.

*pOleViewClass*<br/>
Ponteiro para `CRuntimeClass` uma estrutura contendo informações de classe para o objeto de exibição criado quando ocorre ativação no local.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para identificar recursos que serão usados pelo aplicativo do servidor quando o usuário solicitar a ativação de um objeto incorporado. Esses recursos consistem em menus e tabelas de acelerador. Esta função é geralmente `InitInstance` chamada na sua aplicação.

O menu associado ao *nIDOleInPlaceServer* contém separadores que permitem que o menu do servidor se funda com o menu do contêiner. Para obter mais informações sobre a fusão de menus de servidor e contêiner, consulte o artigo [Menus e Recursos (OLE)](../../mfc/menus-and-resources-ole.md).

## <a name="cdoctemplatecreatepreviewframe"></a><a name="createpreviewframe"></a>CDocTemplate::CreatePreviewFrame

Cria um quadro de criança usado para o Rich Preview.

```
CFrameWnd* CreatePreviewFrame(
    CWnd* pParentWnd,
    CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*Pparentwnd*<br/>
Um ponteiro para uma janela pai (geralmente fornecido pela Shell).

*pDoc*<br/>
Um ponteiro para um objeto de documento, cujo conteúdo será visualizado.

### <a name="return-value"></a>Valor retornado

Um ponteiro válido `CFrameWnd` para um objeto ou NULL se a criação falhar.

### <a name="remarks"></a>Comentários

## <a name="cdoctemplatesetpreviewinfo"></a><a name="setpreviewinfo"></a>CDocTemplate::SetPreviewInfo

Configura o manipulador de visualização fora do processo.

```cpp
void SetPreviewInfo(
    UINT nIDPreviewFrame,
    CRuntimeClass* pPreviewFrameClass = NULL,
    CRuntimeClass* pPreviewViewClass = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDPreviewFrame*<br/>
Especifica um ID de recurso do quadro de visualização.

*pPreviewFrameClass*<br/>
Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução do quadro de visualização.

*pPreviewViewClass*<br/>
Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução da exibição de visualização.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md)<br/>
[Classe CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md)<br/>
[Classe CDocument](../../mfc/reference/cdocument-class.md)<br/>
[Classe CView](../../mfc/reference/cview-class.md)<br/>
[Classe CScrollView](../../mfc/reference/cscrollview-class.md)<br/>
[Classe CEditView](../../mfc/reference/ceditview-class.md)<br/>
[Classe CFormView](../../mfc/reference/cformview-class.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Classe CMDIChildWnd](../../mfc/reference/cmdichildwnd-class.md)
