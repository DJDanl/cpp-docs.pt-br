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
ms.openlocfilehash: 3b2d84af9be8e5c606cde8794b51e12207dcdec9
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78855675"
---
# <a name="cdoctemplate-class"></a>Classe CDocTemplate

Uma classe base abstrata que define a funcionalidade básica para modelos de documento.

## <a name="syntax"></a>Sintaxe

```
class CDocTemplate : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores protegidos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocTemplate::CDocTemplate](#cdoctemplate)|Constrói um objeto `CDocTemplate`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDocTemplate:: AddDocument](#adddocument)|Adiciona um documento a um modelo.|
|[CDocTemplate::CloseAllDocuments](#closealldocuments)|Fecha todos os documentos associados a este modelo.|
|[CDocTemplate::CreateNewDocument](#createnewdocument)|Cria um novo documento.|
|[CDocTemplate:: CreateNewFrame](#createnewframe)|Cria uma nova janela de quadro que contém um documento e uma exibição.|
|[CDocTemplate::CreateOleFrame](#createoleframe)|Cria uma janela de quadro habilitada para OLE.|
|[CDocTemplate::CreatePreviewFrame](#createpreviewframe)|Cria um quadro filho usado para visualização avançada.|
|[CDocTemplate::GetDocString](#getdocstring)|Recupera uma cadeia de caracteres associada ao tipo de documento.|
|[CDocTemplate::GetFirstDocPosition](#getfirstdocposition)|Recupera a posição do primeiro documento associado a este modelo.|
|[CDocTemplate::GetNextDoc](#getnextdoc)|Recupera um documento e a posição do próximo.|
|[CDocTemplate::InitialUpdateFrame](#initialupdateframe)|Inicializa a janela do quadro e, opcionalmente, a torna visível.|
|[CDocTemplate:: LoadTemplate](#loadtemplate)|Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.|
|[CDocTemplate::MatchDocType](#matchdoctype)|Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.|
|[CDocTemplate:: OpenDocumentfile](#opendocumentfile)|Abre um arquivo especificado por um nome de caminho.|
|[CDocTemplate::RemoveDocument](#removedocument)|Remove um documento de um modelo.|
|[CDocTemplate::SaveAllModified](#saveallmodified)|Salva todos os documentos associados a este modelo que foram modificados.|
|[CDocTemplate::SetContainerInfo](#setcontainerinfo)|Determina os recursos para contêineres OLE ao editar um item OLE no local.|
|[CDocTemplate::SetDefaultTitle](#setdefaulttitle)|Exibe o título padrão na barra de título da janela do documento.|
|[CDocTemplate::SetPreviewInfo](#setpreviewinfo)|Configurações fora do Gerenciador de visualização do processo.|
|[CDocTemplate::SetServerInfo](#setserverinfo)|Determina os recursos e as classes quando o documento do servidor é inserido ou editado in-loco.|

## <a name="remarks"></a>Comentários

Normalmente, você cria um ou mais modelos de documento na implementação da função `InitInstance` do seu aplicativo. Um modelo de documento define as relações entre três tipos de classes:

- Uma classe de documento, que você deriva de `CDocument`.

- Uma classe de exibição, que exibe dados da classe de documento listada acima. Você pode derivar essa classe de `CView`, `CScrollView`, `CFormView`ou `CEditView`. (Você também pode usar `CEditView` diretamente.)

- Uma classe de janela do quadro, que contém a exibição. Para um aplicativo SDI (interface de documento único), você deriva essa classe de `CFrameWnd`. Para um aplicativo de interface de vários documentos (MDI), você deriva essa classe de `CMDIChildWnd`. Se você não precisar personalizar o comportamento da janela do quadro, poderá usar `CFrameWnd` ou `CMDIChildWnd` diretamente sem derivar sua própria classe.

Seu aplicativo tem um modelo de documento para cada tipo de documento que ele suporta. Por exemplo, se seu aplicativo oferecer suporte a planilhas e documentos de texto, o aplicativo terá dois objetos de modelo de documento. Cada modelo de documento é responsável por criar e gerenciar todos os documentos de seu tipo.

O modelo de documento armazena ponteiros para os objetos `CRuntimeClass` para as classes de documento, exibição e janela de quadro. Esses `CRuntimeClass` objetos são especificados durante a construção de um modelo de documento.

O modelo de documento contém a ID dos recursos usados com o tipo de documento (como, por exemplo, os recursos de menu, ícone ou tabela de aceleração). O modelo de documento também tem cadeias de caracteres contendo informações adicionais sobre o tipo de documento. Isso inclui o nome do tipo de documento (por exemplo, "planilha") e a extensão de arquivo (por exemplo, ". xls"). Opcionalmente, ele pode conter outras cadeias de caracteres usadas pela interface do usuário do aplicativo, pelo Gerenciador de arquivos do Windows e pelo suporte OLE (vinculação e inserção de objetos).

Se seu aplicativo for um contêiner OLE e/ou servidor, o modelo de documento também definirá a ID do menu usado durante a ativação in-loco. Se seu aplicativo for um servidor OLE, o modelo de documento definirá a ID da barra de ferramentas e do menu usados durante a ativação in-loco. Você especifica esses recursos OLE adicionais chamando `SetContainerInfo` e `SetServerInfo`.

Como `CDocTemplate` é uma classe abstrata, você não pode usar a classe diretamente. Um aplicativo típico usa uma das duas classes derivadas de `CDocTemplate`fornecidas pelo biblioteca MFC: `CSingleDocTemplate`, que implementa SDI e `CMultiDocTemplate`, que implementa o MDI. Consulte essas classes para obter mais informações sobre como usar modelos de documento.

Se seu aplicativo exigir um paradigma de interface do usuário que seja fundamentalmente diferente do SDI ou do MDI, você poderá derivar sua própria classe de `CDocTemplate`.

Para obter mais informações sobre `CDocTemplate`, consulte [modelos de documento e o processo de criação de documento/exibição](../../mfc/document-templates-and-the-document-view-creation-process.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDocTemplate`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="adddocument"></a>CDocTemplate:: AddDocument

Use esta função para adicionar um documento a um modelo.

```
virtual void AddDocument(CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Um ponteiro para o documento a ser adicionado.

### <a name="remarks"></a>Comentários

As classes derivadas [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) e [CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) substituem essa função. Se você derivar sua própria classe de modelo de documento de `CDocTemplate`, sua classe derivada deverá substituir essa função.

##  <a name="cdoctemplate"></a>CDocTemplate::CDocTemplate

Constrói um objeto `CDocTemplate`.

```
CDocTemplate (
    UINT nIDResource,
    CRuntimeClass* pDocClass,
    CRuntimeClass* pFrameClass,
    CRuntimeClass* pViewClass);
```

### <a name="parameters"></a>Parâmetros

*nIDResource*<br/>
Especifica a ID dos recursos usados com o tipo de documento. Isso pode incluir o menu, ícone, tabela de aceleração e recursos de cadeia de caracteres.

O recurso de cadeia de caracteres consiste em até sete subcadeias de caracteres separadas pelo caractere "\n" (o caractere "\n" é necessário como um espaço reservado se uma subcadeia de caracteres não estiver incluída; no entanto, os caracteres "\n" à direita não são necessários); essas subcadeias de caracteres descrevem o tipo de documento. Para obter informações sobre as subcadeias de caracteres, consulte [GetDocString](#getdocstring). Esse recurso de cadeia de caracteres é encontrado no arquivo de recursos do aplicativo. Por exemplo:

```RC
// MYCALC.RC
STRINGTABLE PRELOAD DISCARDABLE
BEGIN
  IDR_SHEETTYPE "\nSheet\nWorksheet\nWorksheets (*.myc)\n.myc\n MyCalcSheet\nMyCalc Worksheet"
END
```

Observe que a cadeia de caracteres começa com um caractere ' \n '; Isso ocorre porque a primeira subcadeia de caracteres não é usada para aplicativos MDI e, portanto, não está incluída. Você pode editar essa cadeia de caracteres usando o editor de cadeia de caracteres; a cadeia de caracteres inteira aparece como uma única entrada no editor de cadeia de caracteres, não como sete entradas separadas.

*pDocClass*<br/>
Aponta para o objeto `CRuntimeClass` da classe Document. Essa classe é uma classe derivada de `CDocument`que você define para representar seus documentos.

*pFrameClass*<br/>
Aponta para o objeto `CRuntimeClass` da classe janela do quadro. Essa classe pode ser uma classe derivada de `CFrameWnd`ou pode ser `CFrameWnd` ela mesma se você quiser o comportamento padrão para a janela do quadro principal.

*pViewClass*<br/>
Aponta para o objeto `CRuntimeClass` da classe View. Essa classe é uma classe derivada de `CView`que você define para exibir seus documentos.

### <a name="remarks"></a>Comentários

Use essa função de membro para construir um objeto de `CDocTemplate`. Aloque dinamicamente um objeto `CDocTemplate` e passe-o para [CWinApp:: AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) da função membro `InitInstance` da sua classe de aplicativo.

##  <a name="closealldocuments"></a>CDocTemplate::CloseAllDocuments

Chame essa função de membro para fechar todos os documentos abertos.

```
virtual void CloseAllDocuments(BOOL bEndSession);
```

### <a name="parameters"></a>Parâmetros

*bEndSession*<br/>
Não usado.

### <a name="remarks"></a>Comentários

Essa função de membro normalmente é usada como parte do comando File Exit. A implementação padrão dessa função chama a função de membro [CDocument::D eletecontents](../../mfc/reference/cdocument-class.md#deletecontents) para excluir os dados do documento e fecha as janelas de quadros para todas as exibições anexadas ao documento.

Substitua essa função se desejar exigir que o usuário execute o processamento de limpeza especial antes que o documento seja fechado. Por exemplo, se o documento representar um registro em um banco de dados, talvez você queira substituir essa função para fechar o banco de dados.

##  <a name="createnewdocument"></a>CDocTemplate::CreateNewDocument

Chame essa função de membro para criar um novo documento do tipo associado a este modelo de documento.

```
virtual CDocument* CreateNewDocument();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento recém-criado ou NULL se ocorrer um erro.

##  <a name="createnewframe"></a>CDocTemplate:: CreateNewFrame

Cria uma nova janela de quadro que contém um documento e uma exibição.

```
virtual CFrameWnd* CreateNewFrame(
    CDocument* pDoc,
    CFrameWnd* pOther);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
O documento ao qual a janela do novo quadro deve se referir. Pode ser NULO.

*pOther*<br/>
A janela do quadro na qual a janela do novo quadro deve ser baseada. Pode ser NULO.

### <a name="return-value"></a>Valor retornado

Um ponteiro para a janela do quadro recém-criada, ou NULL se ocorrer um erro.

### <a name="remarks"></a>Comentários

`CreateNewFrame` usa os objetos `CRuntimeClass` passados para o construtor para criar uma nova janela de quadros com uma exibição e um documento anexados. Se o parâmetro *pDoc* for NULL, a estrutura produzirá uma mensagem de rastreamento.

O parâmetro *pother* é usado para implementar o novo comando Window. Ele fornece uma janela de quadro para modelar a nova janela do quadro. A janela novo quadro normalmente é criada como invisível. Chame essa função para criar janelas de quadros fora da implementação da estrutura padrão do arquivo novo e do arquivo aberto.

##  <a name="createoleframe"></a>CDocTemplate::CreateOleFrame

Cria uma janela de quadro OLE.

```
CFrameWnd* CreateOleFrame(
    CWnd* pParentWnd,
    CDocument* pDoc,
    BOOL bCreateView);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Um ponteiro para a janela pai do quadro.

*pDoc*<br/>
Um ponteiro para o documento ao qual a janela do novo quadro OLE deve se referir.

*bCreateView*<br/>
Determina se uma exibição é criada junto com o quadro.

### <a name="return-value"></a>Valor retornado

Um ponteiro para uma janela de quadro se for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se *bCreateView* for zero, um quadro vazio será criado.

##  <a name="getdocstring"></a>CDocTemplate::GetDocString

Recupera uma cadeia de caracteres associada ao tipo de documento.

```
virtual BOOL GetDocString(
    CString& rString,
    enum DocStringIndex index) const;
```

### <a name="parameters"></a>Parâmetros

*rString*<br/>
Uma referência a um objeto `CString` que conterá a cadeia de caracteres quando a função retornar.

*index*<br/>
Um índice da subcadeia de caracteres que está sendo recuperada da cadeia de caracteres que descreve o tipo de documento. Esse parâmetro pode ter um dos seguintes valores:

- `CDocTemplate::windowTitle` nome que aparece na barra de título da janela do aplicativo (por exemplo, "Microsoft Excel"). Presente somente no modelo de documento para aplicativos SDI.

- `CDocTemplate::docName` raiz do nome do documento padrão (por exemplo, "planilha"). Essa raiz, mais um número, é usada para o nome padrão de um novo documento desse tipo sempre que o usuário escolhe o comando novo no menu arquivo (por exemplo, "Plan1" ou "Planilha2"). Se não for especificado, "sem título" será usado como o padrão.

- `CDocTemplate::fileNewName` nome deste tipo de documento. Se o aplicativo oferecer suporte a mais de um tipo de documento, essa cadeia de caracteres será exibida na caixa de diálogo arquivo novo (por exemplo, "planilha"). Se não for especificado, o tipo de documento será inacessível usando o comando File New.

- `CDocTemplate::filterName` descrição do tipo de documento e um filtro curinga que correspondem a documentos desse tipo. Essa cadeia de caracteres é exibida na lista suspensa arquivos do tipo na caixa de diálogo abrir arquivo (por exemplo, "planilhas (*. xls)"). Se não for especificado, o tipo de documento será inacessível usando o comando File Open.

- `CDocTemplate::filterExt` extensão para documentos desse tipo (por exemplo, ". xls"). Se não for especificado, o tipo de documento será inacessível usando o comando File Open.

- `CDocTemplate::regFileTypeId` identificador para o tipo de documento a ser armazenado no banco de dados de registro mantido pelo Windows. Essa cadeia de caracteres é somente para uso interno (por exemplo, "ExcelWorksheet"). Se não for especificado, o tipo de documento não poderá ser registrado com o Gerenciador de arquivos do Windows.

- `CDocTemplate::regFileTypeName` nome do tipo de documento a ser armazenado no banco de dados de registro. Essa cadeia de caracteres pode ser exibida em caixas de diálogo de aplicativos que acessam o banco de dados de registro (por exemplo, "planilha do Microsoft Excel").

### <a name="return-value"></a>Valor retornado

Diferente de zero se a subcadeia de caracteres especificada foi encontrada; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função para recuperar uma subcadeia de caracteres específica que descreve o tipo de documento. A cadeia de caracteres que contém essas subcadeias de caracteres é armazenada no modelo de documento e derivada de uma cadeia de caracteres no arquivo de recursos para o aplicativo. A estrutura chama essa função para obter as cadeias de caracteres necessárias para a interface do usuário do aplicativo. Se você tiver especificado uma extensão de nome de arquivo para os documentos do seu aplicativo, a estrutura também chamará essa função ao adicionar uma entrada ao banco de dados de registro do Windows; Isso permite que os documentos sejam abertos do Gerenciador de arquivos do Windows.

Chame essa função somente se você estiver derivando sua própria classe de `CDocTemplate`.

##  <a name="getfirstdocposition"></a>CDocTemplate::GetFirstDocPosition

Recupera a posição do primeiro documento associado a este modelo.

```
virtual POSITION GetFirstDocPosition() const = 0;
```

### <a name="return-value"></a>Valor retornado

Um valor de posição que pode ser usado para iterar na lista de documentos associados a este modelo de documento; ou NULL se a lista estiver vazia.

### <a name="remarks"></a>Comentários

Use essa função para obter a posição do primeiro documento na lista de documentos associados a este modelo. Use o valor POSITION como um argumento para [CDocTemplate:: GetNextDoc](#getnextdoc) para iterar na lista de documentos associados ao modelo.

[CSingleDocTemplate](../../mfc/reference/csingledoctemplate-class.md) e [CMultiDocTemplate](../../mfc/reference/cmultidoctemplate-class.md) substituem essa função virtual pura. Qualquer classe derivada de `CDocTemplate` também deve substituir essa função.

##  <a name="getnextdoc"></a>CDocTemplate::GetNextDoc

Recupera o elemento de lista identificado por *RPOs*e, em seguida, define *RPOs* como o valor de posição da próxima entrada na lista.

```
virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o próximo documento na lista de documentos associados a este modelo.

### <a name="parameters"></a>Parâmetros

*rPos*<br/>
Uma referência a um valor de posição retornado por uma chamada anterior para [GetFirstDocPosition](#getfirstdocposition) ou `GetNextDoc`.

### <a name="remarks"></a>Comentários

Se o elemento recuperado for o último na lista, o novo valor de *RPOs* será definido como NULL.

Você pode usar `GetNextDoc` em um loop de iteração progressiva se estabelecer a posição inicial com uma chamada para [GetFirstDocPosition](#getfirstdocposition).

Você deve garantir que seu valor de posição represente uma posição válida na lista. Se for inválido, a versão de depuração do biblioteca MFC afirma.

##  <a name="initialupdateframe"></a>CDocTemplate::InitialUpdateFrame

Inicializa a janela do quadro e, opcionalmente, a torna visível.

```
virtual void InitialUpdateFrame(
    CFrameWnd* pFrame,
    CDocument* pDoc,
    BOOL bMakeVisible = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pFrame*<br/>
A janela do quadro que precisa da atualização inicial.

*pDoc*<br/>
O documento ao qual o quadro está associado. Pode ser NULO.

*bMakeVisible*<br/>
Indica se o quadro deve ficar visível e ativo.

### <a name="remarks"></a>Comentários

Chame `IntitialUpdateFrame` depois de criar um novo quadro com `CreateNewFrame`. Chamar essa função faz com que as exibições nessa janela de quadro recebam suas chamadas de `OnInitialUpdate`. Além disso, se não havia um modo de exibição ativo anteriormente, a exibição primária da janela do quadro será ativada; a exibição primária é uma exibição com uma ID filho de AFX_IDW_PANE_FIRST. Por fim, a janela do quadro ficará visível se *bMakeVisible* for diferente de zero. Se *bMakeVisible* for zero, o foco atual e o estado visível da janela do quadro permanecerão inalterados.

Não é necessário chamar essa função ao usar a implementação do arquivo novo e o arquivo aberto da estrutura.

##  <a name="loadtemplate"></a>CDocTemplate:: LoadTemplate

Carrega os recursos para um determinado `CDocTemplate` ou classe derivada.

```
virtual void LoadTemplate();
```

### <a name="remarks"></a>Comentários

Essa função de membro é chamada pelo Framework para carregar os recursos para um determinado `CDocTemplate` ou classe derivada. Normalmente, ele é chamado durante a construção, exceto quando o modelo está sendo construído globalmente. Nesse caso, a chamada para `LoadTemplate` é atrasada até que [CWinApp:: AddDocTemplate](../../mfc/reference/cwinapp-class.md#adddoctemplate) seja chamado.

##  <a name="matchdoctype"></a>CDocTemplate::MatchDocType

Determina o grau de confiança na correspondência entre um tipo de documento e este modelo.

```
virtual Confidence MatchDocType(
    LPCTSTR lpszPathName,
    CDocument*& rpDocMatch);
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
Nome do caminho do arquivo cujo tipo deve ser determinado.

*rpDocMatch*<br/>
Ponteiro para um documento ao qual o documento correspondente foi atribuído, se o arquivo especificado por *lpszPathName* já estiver aberto.

### <a name="return-value"></a>Valor retornado

Um valor da enumeração de **confiança** , que é definido da seguinte maneira:

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

Use essa função para determinar o tipo de modelo de documento a ser usado para abrir um arquivo. Se seu aplicativo dá suporte a vários tipos de arquivo, por exemplo, você pode usar essa função para determinar qual dos modelos de documento disponíveis é apropriado para um determinado arquivo chamando `MatchDocType` para cada modelo por vez e escolhendo um modelo de acordo com o valor de confiança retornado.

Se o arquivo especificado por *lpszPathName* já estiver aberto, essa função retornará `CDocTemplate::yesAlreadyOpen` e copiará o objeto `CDocument` do arquivo para o objeto em *rpDocMatch*.

Se o arquivo não estiver aberto, mas a extensão em *lpszPathName* corresponder à extensão especificada por `CDocTemplate::filterExt`, essa função retornará `CDocTemplate::yesAttemptNative` e definirá *rpDocMatch* como NULL. Para obter mais informações sobre `CDocTemplate::filterExt`, consulte [CDocTemplate:: GetDocString](#getdocstring).

Se nenhum caso for verdadeiro, a função retornará `CDocTemplate::yesAttemptForeign`.

A implementação padrão não retorna `CDocTemplate::maybeAttemptForeign` ou `CDocTemplate::maybeAttemptNative`. Substitua essa função para implementar a lógica de correspondência de tipo apropriada ao seu aplicativo, talvez usando esses dois valores da enumeração de **confiança** .

##  <a name="opendocumentfile"></a>CDocTemplate:: OpenDocumentfile

Abre um arquivo especificado por um caminho.

```
virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName) = 0;

virtual CDocument* OpenDocumentFile(
    LPCTSTR lpszPathName,
    BOOL bAddToMRU) = 0;
```

### <a name="parameters"></a>Parâmetros

*lpszPathName*<br/>
no Ponteiro para o caminho do arquivo que contém o documento a ser aberto.

*bAddToMRU*<br/>
no VERDADEIRO indica que o documento é um dos arquivos mais recentes; FALSE indica que o documento não é um dos arquivos mais recentes.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o documento cujo arquivo é nomeado por *lpszPathName*; NULO se não for bem-sucedido.

### <a name="remarks"></a>Comentários

Abre o arquivo cujo caminho é especificado por *lpszPathName*. Se *lpszPathName* for nulo, um novo arquivo que contém um documento do tipo associado a esse modelo será criado.

##  <a name="removedocument"></a>CDocTemplate::RemoveDocument

Remove o documento apontado por *pDoc* da lista de documentos associados a este modelo.

```
virtual void RemoveDocument(CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Ponteiro para o documento a ser removido.

### <a name="remarks"></a>Comentários

As classes derivadas `CMultiDocTemplate` e `CSingleDocTemplate` substituir essa função. Se você derivar sua própria classe de modelo de documento de `CDocTemplate`, sua classe derivada deverá substituir essa função.

##  <a name="saveallmodified"></a>CDocTemplate::SaveAllModified

Salva todos os documentos que foram modificados.

```
virtual BOOL SaveAllModified();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se for bem-sucedido; caso contrário, 0.

##  <a name="setcontainerinfo"></a>CDocTemplate::SetContainerInfo

Determina os recursos para contêineres OLE ao editar um item OLE no local.

```
void SetContainerInfo(UINT nIDOleInPlaceContainer);
```

### <a name="parameters"></a>Parâmetros

*nIDOleInPlaceContainer*<br/>
A ID dos recursos usados quando um objeto inserido é ativado.

### <a name="remarks"></a>Comentários

Chame essa função para definir os recursos a serem usados quando um objeto OLE for ativado no local. Esses recursos podem incluir menus e tabelas de acelerador. Essa função é geralmente chamada na função [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) do seu aplicativo.

O menu associado a *nIDOleInPlaceContainer* contém separadores que permitem que o menu do item ativado no local seja mesclado com o menu do aplicativo de contêiner. Para obter mais informações sobre como mesclar menus de servidor e contêiner, consulte o artigo [menus e recursos (OLE)](../../mfc/menus-and-resources-ole.md).

##  <a name="setdefaulttitle"></a>CDocTemplate::SetDefaultTitle

Chame essa função para carregar o título padrão do documento e exibi-lo na barra de título do documento.

```
virtual void SetDefaultTitle(CDocument* pDocument) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDocument*<br/>
Ponteiro para o documento cujo título deve ser definido.

### <a name="remarks"></a>Comentários

Para obter informações sobre o título padrão, consulte a descrição de `CDocTemplate::docName` em [CDocTemplate:: GetDocString](#getdocstring).

##  <a name="setserverinfo"></a>CDocTemplate::SetServerInfo

Determina os recursos e as classes quando o documento do servidor é inserido ou editado in-loco.

```
void SetServerInfo(
    UINT nIDOleEmbedding,
    UINT nIDOleInPlaceServer = 0,
    CRuntimeClass* pOleFrameClass = NULL,
    CRuntimeClass* pOleViewClass = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDOleEmbedding*<br/>
A ID dos recursos usados quando um objeto inserido é aberto em uma janela separada.

*nIDOleInPlaceServer*<br/>
A ID dos recursos usados quando um objeto inserido é ativado no local.

*pOleFrameClass*<br/>
Ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que contém informações de classe para o objeto de janela do quadro criado quando ocorre a ativação in-loco.

*pOleViewClass*<br/>
Ponteiro para uma estrutura de `CRuntimeClass` que contém informações de classe para o objeto de exibição criado quando ocorre a ativação in-loco.

### <a name="remarks"></a>Comentários

Chame essa função de membro para identificar os recursos que serão usados pelo aplicativo de servidor quando o usuário solicitar a ativação de um objeto inserido. Esses recursos consistem em menus e tabelas de acelerador. Essa função é geralmente chamada no `InitInstance` do seu aplicativo.

O menu associado a *nIDOleInPlaceServer* contém separadores que permitem que o menu do servidor seja mesclado com o menu do contêiner. Para obter mais informações sobre como mesclar menus de servidor e contêiner, consulte o artigo [menus e recursos (OLE)](../../mfc/menus-and-resources-ole.md).

##  <a name="createpreviewframe"></a>CDocTemplate::CreatePreviewFrame

Cria um quadro filho usado para visualização avançada.

```
CFrameWnd* CreatePreviewFrame(
    CWnd* pParentWnd,
    CDocument* pDoc);
```

### <a name="parameters"></a>Parâmetros

*pParentWnd*<br/>
Um ponteiro para uma janela pai (geralmente fornecido pelo shell).

*pDoc*<br/>
Um ponteiro para um objeto de documento, cujo conteúdo será visualizado.

### <a name="return-value"></a>Valor retornado

Um ponteiro válido para um objeto `CFrameWnd` ou NULL se a criação falhar.

### <a name="remarks"></a>Comentários

##  <a name="setpreviewinfo"></a>CDocTemplate::SetPreviewInfo

Configura o Gerenciador de visualização fora do processo.

```
void SetPreviewInfo(
    UINT nIDPreviewFrame,
    CRuntimeClass* pPreviewFrameClass = NULL,
    CRuntimeClass* pPreviewViewClass = NULL);
```

### <a name="parameters"></a>Parâmetros

*nIDPreviewFrame*<br/>
Especifica uma ID de recurso do quadro de visualização.

*pPreviewFrameClass*<br/>
Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução do quadro de visualização.

*pPreviewViewClass*<br/>
Especifica um ponteiro para uma estrutura de informações de classe de tempo de execução da exibição de visualização.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

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
