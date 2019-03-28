---
title: Classe CDataRecoveryHandler
ms.date: 03/27/2019
f1_keywords:
- CDataRecoveryHandler
- AFXDATARECOVERY/CDataRecoveryHandler
- AFXDATARECOVERY/CDataRecoveryHandler::CDataRecoveryHandler
- AFXDATARECOVERY/CDataRecoveryHandler::AutosaveAllDocumentInfo
- AFXDATARECOVERY/CDataRecoveryHandler::AutosaveDocumentInfo
- AFXDATARECOVERY/CDataRecoveryHandler::CreateDocumentInfo
- AFXDATARECOVERY/CDataRecoveryHandler::DeleteAllAutosavedFiles
- AFXDATARECOVERY/CDataRecoveryHandler::DeleteAutosavedFile
- AFXDATARECOVERY/CDataRecoveryHandler::GenerateAutosaveFileName
- AFXDATARECOVERY/CDataRecoveryHandler::GetAutosaveInterval
- AFXDATARECOVERY/CDataRecoveryHandler::GetAutosavePath
- AFXDATARECOVERY/CDataRecoveryHandler::GetDocumentListName
- AFXDATARECOVERY/CDataRecoveryHandler::GetNormalDocumentTitle
- AFXDATARECOVERY/CDataRecoveryHandler::GetRecoveredDocumentTitle
- AFXDATARECOVERY/CDataRecoveryHandler::GetRestartIdentifier
- AFXDATARECOVERY/CDataRecoveryHandler::GetSaveDocumentInfoOnIdle
- AFXDATARECOVERY/CDataRecoveryHandler::GetShutdownByRestartManager
- AFXDATARECOVERY/CDataRecoveryHandler::Initialize
- AFXDATARECOVERY/CDataRecoveryHandler::QueryRestoreAutosavedDocuments
- AFXDATARECOVERY/CDataRecoveryHandler::ReadOpenDocumentList
- AFXDATARECOVERY/CDataRecoveryHandler::RemoveDocumentInfo
- AFXDATARECOVERY/CDataRecoveryHandler::ReopenPreviousDocuments
- AFXDATARECOVERY/CDataRecoveryHandler::RestoreAutosavedDocuments
- AFXDATARECOVERY/CDataRecoveryHandler::SaveOpenDocumentList
- AFXDATARECOVERY/CDataRecoveryHandler::SetAutosaveInterval
- AFXDATARECOVERY/CDataRecoveryHandler::SetAutosavePath
- AFXDATARECOVERY/CDataRecoveryHandler::SetRestartIdentifier
- AFXDATARECOVERY/CDataRecoveryHandler::SetSaveDocumentInfoOnIdle
- AFXDATARECOVERY/CDataRecoveryHandler::SetShutdownByRestartManager
- AFXDATARECOVERY/CDataRecoveryHandler::UpdateDocumentInfo
helpviewer_keywords:
- CDataRecoveryHandler [MFC], CDataRecoveryHandler
- CDataRecoveryHandler [MFC], AutosaveAllDocumentInfo
- CDataRecoveryHandler [MFC], AutosaveDocumentInfo
- CDataRecoveryHandler [MFC], CreateDocumentInfo
- CDataRecoveryHandler [MFC], DeleteAllAutosavedFiles
- CDataRecoveryHandler [MFC], DeleteAutosavedFile
- CDataRecoveryHandler [MFC], GenerateAutosaveFileName
- CDataRecoveryHandler [MFC], GetAutosaveInterval
- CDataRecoveryHandler [MFC], GetAutosavePath
- CDataRecoveryHandler [MFC], GetDocumentListName
- CDataRecoveryHandler [MFC], GetNormalDocumentTitle
- CDataRecoveryHandler [MFC], GetRecoveredDocumentTitle
- CDataRecoveryHandler [MFC], GetRestartIdentifier
- CDataRecoveryHandler [MFC], GetSaveDocumentInfoOnIdle
- CDataRecoveryHandler [MFC], GetShutdownByRestartManager
- CDataRecoveryHandler [MFC], Initialize
- CDataRecoveryHandler [MFC], QueryRestoreAutosavedDocuments
- CDataRecoveryHandler [MFC], ReadOpenDocumentList
- CDataRecoveryHandler [MFC], RemoveDocumentInfo
- CDataRecoveryHandler [MFC], ReopenPreviousDocuments
- CDataRecoveryHandler [MFC], RestoreAutosavedDocuments
- CDataRecoveryHandler [MFC], SaveOpenDocumentList
- CDataRecoveryHandler [MFC], SetAutosaveInterval
- CDataRecoveryHandler [MFC], SetAutosavePath
- CDataRecoveryHandler [MFC], SetRestartIdentifier
- CDataRecoveryHandler [MFC], SetSaveDocumentInfoOnIdle
- CDataRecoveryHandler [MFC], SetShutdownByRestartManager
- CDataRecoveryHandler [MFC], UpdateDocumentInfo
ms.assetid: 7794802c-e583-4eba-90b9-2fed1a161f9c
ms.openlocfilehash: 5c5836a11dbf9e05db5b56e0bc5c062dd1617b2f
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565851"
---
# <a name="cdatarecoveryhandler-class"></a>Classe CDataRecoveryHandler

O `CDataRecoveryHandler` salva automaticamente documentos e restaura-os se um aplicativo encerra inesperadamente.

## <a name="syntax"></a>Sintaxe

```
class CDataRecoveryHandler : public CObject
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|||
|-|-|
|[CDataRecoveryHandler::CDataRecoveryHandler](#cdatarecoveryhandler)|Constrói um objeto `CDataRecoveryHandler`.|

### <a name="methods"></a>Métodos

|||
|-|-|
|[CDataRecoveryHandler::AutosaveAllDocumentInfo](#autosavealldocumentinfo)|Salva automaticamente cada arquivo registrado com o `CDataRecoveryHandler` classe.|
|[CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo)|Salva automaticamente o documento especificado.|
|[CDataRecoveryHandler::CreateDocumentInfo](#createdocumentinfo)|Adiciona um documento à lista de documentos abertos.|
|[CDataRecoveryHandler::DeleteAllAutosavedFiles](#deleteallautosavedfiles)|Exclui todos os arquivos atuais salva automaticamente.|
|[CDataRecoveryHandler::DeleteAutosavedFile](#deleteautosavedfile)|Exclui o arquivo salvo automaticamente especificado.|
|[CDataRecoveryHandler::GenerateAutosaveFileName](#generateautosavefilename)|Gera o nome de um arquivo de salvamento automático associado com o nome de arquivo do documento fornecido.|
|[CDataRecoveryHandler::GetAutosaveInterval](#getautosaveinterval)|Retorna o intervalo entre tentativas de salvamento automático.|
|[CDataRecoveryHandler::GetAutosavePath](#getautosavepath)|Retorna o caminho dos arquivos salva automaticamente.|
|[CDataRecoveryHandler::GetDocumentListName](#getdocumentlistname)|Recupera o nome do documento de um `CDocument` objeto.|
|[CDataRecoveryHandler::GetNormalDocumentTitle](#getnormaldocumenttitle)|Recupera o cargo normal para o documento especificado.|
|[CDataRecoveryHandler::GetRecoveredDocumentTitle](#getrecovereddocumenttitle)|Cria e retorna o título do documento recuperado.|
|[CDataRecoveryHandler::GetRestartIdentifier](#getrestartidentifier)|Recupera o identificador exclusivo de reinício para o aplicativo.|
|[CDataRecoveryHandler::GetSaveDocumentInfoOnIdle](#getsavedocumentinfoonidle)|Indica se o `CDataRecoveryHandler` executa uma gravação automática no loop ocioso atual.|
|[CDataRecoveryHandler::GetShutdownByRestartManager](#getshutdownbyrestartmanager)|Indica se o Gerenciador de reinicialização causou o aplicativo seja encerrado.|
|[CDataRecoveryHandler::Initialize](#initialize)|Inicializa o `CDataRecoveryHandler`.|
|[CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments)|Exibe uma caixa de diálogo para o usuário para cada documento que o `CDataRecoveryHandler` salva automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salvo automaticamente.|
|[CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist)|Carrega a lista de documentos abertos do registro.|
|[CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo)|Remove o documento fornecido da lista de documentos abertos.|
|[CDataRecoveryHandler::ReopenPreviousDocuments](#reopenpreviousdocuments)|Abre os documentos abertos anteriormente.|
|[CDataRecoveryHandler::RestoreAutosavedDocuments](#restoreautosaveddocuments)|Restaura os documentos salva automaticamente com base na entrada do usuário.|
|[CDataRecoveryHandler::SaveOpenDocumentList](#saveopendocumentlist)|Salva a lista atual de documentos abertos no registro do Windows.|
|[CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval)|Define o tempo entre os ciclos de salvamento automático em milissegundos.|
|[CDataRecoveryHandler::SetAutosavePath](#setautosavepath)|Define o diretório onde salva automaticamente arquivos estão armazenados.|
|[CDataRecoveryHandler::SetRestartIdentifier](#setrestartidentifier)|Define o identificador exclusivo de reinicialização para esta instância da `CDataRecoveryHandler`.|
|[CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle)|Define se o `CDataRecoveryHandler` salva as informações de documento aberto no registro do Windows durante o ciclo de ociosidade atual.|
|[CDataRecoveryHandler::SetShutdownByRestartManager](#setshutdownbyrestartmanager)|Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.|
|[CDataRecoveryHandler::UpdateDocumentInfo](#updatedocumentinfo)|Atualiza as informações de um documento porque ele está sendo salvo por usuário.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|m_bRestoringPreviousOpenDocs|Indica se o manipulador de recuperação de dados reabre documentos anteriormente abertos.|
|m_bSaveDocumentInfoOnIdle|Indica se o manipulador de recuperação de dados salva automaticamente documentos no próximo loop ocioso.|
|m_bShutdownByRestartManager|Indica se o Gerenciador de reinicialização faz com que o aplicativo seja encerrado.|
|m_dwRestartManagerSupportFlags|Fornecem sinalizadores que indicam o que suportam o Gerenciador de reinicialização para o aplicativo.|
|m_lstAutosavesToDelete|Uma lista de arquivos de salva automaticamente que não foram excluídos quando os documentos originais foram fechados. Quando o aplicativo é fechado, as tentativas do Gerenciador de reinicialização excluindo os arquivos.|
|m_mapDocNameToAutosaveName|Um mapa dos nomes de documento para os nomes de arquivo salva automaticamente.|
|m_mapDocNameToDocumentPtr|Um mapa dos nomes de documento para o [CDocument](../../mfc/reference/cdocument-class.md) ponteiros.|
|m_mapDocNameToRestoreBool|Um mapa dos nomes de documento para um parâmetro booliano que indica se é necessário restaurar o documento salvo automaticamente.|
|m_mapDocumentPtrToDocName|Um mapa do `CDocument` ponteiros para os nomes de documento.|
|m_mapDocumentPtrToDocTitle|Um mapa do `CDocument` ponteiros para os títulos do documento. Esses títulos são usados para salvar arquivos.|
|m_nAutosaveInterval|Tempo em milissegundos entre salva automaticamente.|
|m_nTimerID|O identificador para o temporizador de salvamento automático.|
|m_strAutosavePath|O local onde os salva automaticamente os documentos são armazenados.|
|m_strRestartIdentifier|A representação de cadeia de caracteres de um GUID para o Gerenciador de reinicialização.|

## <a name="remarks"></a>Comentários

O Gerenciador de reinicialização usa o `CDataRecoveryHandler` classe para manter controle de todos os documentos abertos e salvamento automático-los conforme necessário. Para habilitar o salvamento automático, use o [CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle) método. Este método direciona o `CDataRecoveryHandler` para executar uma gravação automática no próximo loop ocioso. As chamadas de Gerenciador de reinicialização `SetSaveDocumentInfoOnIdle` quando o `CDataRecoveryHandler` deve executar um salvamento automático.

Todos os métodos do `CDataRecoveryHandler` classe são virtuais. Substitua os métodos nessa classe para criar seu próprio manipulador de recuperação de dados personalizados. A menos que você cria seu próprio manipulador de recuperação de dados ou Gerenciador de reinicialização, não é instanciado um CDataRecoveryHandler. O [classe CWinApp](../../mfc/reference/cwinapp-class.md) cria um `CDataRecoveryHandler` objeto conforme ele é necessário.

Antes de poder usar um `CDataRecoveryHandler` do objeto, você deve chamar [CDataRecoveryHandler::Initialize](#initialize).

Porque o `CDataRecoveryHandler` classe intimamente está conectado para o Gerenciador de reinicialização `CDataRecoveryHandler` depende o parâmetro global `m_dwRestartManagerSupportFlags`. Esse parâmetro determina quais permissões que tem o Gerenciador de reinicialização e como ele interage com seu aplicativo. Para incorporar o Gerenciador de reinicialização em um aplicativo existente, você precisa atribuir `m_dwRestartManagerSupportFlags` o valor apropriado no construtor do aplicativo principal. Para obter mais informações sobre como usar o Gerenciador de reinicialização, consulte [como: adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdatarecovery.h

##  <a name="autosavealldocumentinfo"></a>  CDataRecoveryHandler::AutosaveAllDocumentInfo

Salva automaticamente cada arquivo registrado com o `CDataRecoveryHandler` classe.

```
virtual BOOL AutosaveAllDocumentInfo();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o `CDataRecoveryHandler` salva todos os documentos; FALSE se qualquer documento não foi salvo.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se houver documentos não devem ser salvas. Ele também retorna TRUE sem salvar todos os documentos se recuperando os `CWinApp` ou `CDocManager` para o aplicativo gera um erro.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL deve ser definido `m_dwRestartManagerSupportFlags`. Para obter mais informações, confira [Como: adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).

##  <a name="autosavedocumentinfo"></a>  CDataRecoveryHandler::AutosaveDocumentInfo

Salva automaticamente o documento especificado.

```
virtual BOOL AutosaveDocumentInfo(
    CDocument* pDocument,
    BOOL bResetModifiedFlag = TRUE);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para o `CDocument` para salvar.|
|*bResetModifiedFlag*|[in] TRUE indica que o `CDataRecoveryHandler` considera *pDocument* a ser modificada; FALSE indica que a estrutura considera *pDocument* ser não modificado. Consulte a seção de comentários para obter mais informações sobre o efeito desse sinalizador.|

### <a name="return-value"></a>Valor de retorno

TRUE se os sinalizadores adequados estão definidos e *pDocument* é válida `CDocument` objeto.

### <a name="remarks"></a>Comentários

Cada `CDocument` objeto tem um sinalizador que indica se ele foi alterado desde a última gravação. Use [CDocument::IsModified](../../mfc/reference/cdocument-class.md#ismodified) para determinar o estado desse sinalizador. Se um `CDocument` não foi alterado desde a última gravação, `AutosaveDocumentInfo` exclui todos os arquivos para o documento salvo automaticamente. Se um documento foi alterado desde o último salvamento, fechá-la solicita ao usuário para salvar o documento antes de ser fechado.

> [!NOTE]
>  Usando o *bResetModifiedFlag* alterar o estado do documento para não modificado pode fazer com que o usuário perder dados não salvos. Se a estrutura considera um documento sem modificações, fechá-la não solicita ao usuário salvar.

Esse método gera uma exceção com o [ASSERT](diagnostic-services.md#assert) macro se *pDocument* não é válido `CDocument` objeto.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL deve ser definido *m_dwRestartManagerSupportFlags*.

##  <a name="cdatarecoveryhandler"></a>  CDataRecoveryHandler::CDataRecoveryHandler

Constrói um objeto `CDataRecoveryHandler`.

```
CDataRecoveryHandler(
    DWORD dwRestartManagerSupportFlags,
    int nAutosaveInterval);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*dwRestartManagerSupportFlags*|[in] Indica quais opções do Gerenciador de reinicialização de têm suporte.|
|*nAutosaveInterval*|[in] O tempo entre salva automaticamente. Esse parâmetro é em milissegundos.|

### <a name="remarks"></a>Comentários

Estrutura MFC cria automaticamente um `CDataRecoveryHandler` objeto para o seu aplicativo ao usar o **novo projeto** assistente. A menos que você estiver personalizando o comportamento de recuperação de dados ou o Gerenciador de reinicialização, você não deve criar um `CDataRecoveryHandler` objeto.

##  <a name="createdocumentinfo"></a>  CDataRecoveryHandler::CreateDocumentInfo

Adiciona um documento à lista de documentos abertos.

```
virtual BOOL CreateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para um `CDocument`. Esse método cria as informações de documento para este `CDocument`.|

### <a name="return-value"></a>Valor de retorno

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Esse método verifica se *pDocument* já está na lista de documentos antes de adicionar o documento. Se *pDocument* já está na lista, esse método exclui o arquivo salvo automaticamente associado *pDocument*.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL deve ser definido *m_dwRestartManagerSupportFlags*.

##  <a name="deleteallautosavedfiles"></a>  CDataRecoveryHandler::DeleteAllAutosavedFiles

Exclui todos os arquivos atuais salva automaticamente.

```
virtual BOOL DeleteAllAutosavedFiles();
```

### <a name="return-value"></a>Valor de retorno

A implementação padrão sempre retorna TRUE.

##  <a name="deleteautosavedfile"></a>  CDataRecoveryHandler::DeleteAutosavedFile

Exclui o arquivo salvo automaticamente especificado.

```
virtual BOOL DeleteAutosavedFile(const CString& strAutosavedFile);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strAutosavedFile*|[in] Uma cadeia de caracteres que contém o nome de arquivo salva automaticamente.|

### <a name="return-value"></a>Valor de retorno

A implementação padrão sempre retornar TRUE.

### <a name="remarks"></a>Comentários

Se esse método não é possível excluir o arquivo salva automaticamente, ele salva o nome do arquivo em uma lista. O destruidor para a `CDataRecoveryHandler` tenta excluir cada arquivo salva automaticamente especificado nessa lista.

##  <a name="generateautosavefilename"></a>  CDataRecoveryHandler::GenerateAutosaveFileName

Gera o nome de um arquivo de salvamento automático associado com o nome de arquivo do documento fornecido.

```
virtual CString GenerateAutosaveFileName(const CString& strDocumentName) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentName*<br/>
[in] Uma cadeia de caracteres que contém o nome do documento. `GenerateAutosaveFileName` usa esse nome de documento para gerar um nome de arquivo de salvamento automático correspondente.

### <a name="return-value"></a>Valor de retorno

O nome do arquivo de salvamento automático gerado a partir *strDocumentName*.

### <a name="remarks"></a>Comentários

Nome de cada documento tem um mapeamento um para um com um nome de arquivo de salvamento automático.

##  <a name="getautosaveinterval"></a>  CDataRecoveryHandler::GetAutosaveInterval

Retorna o intervalo entre tentativas de salvamento automático.

```
virtual int GetAutosaveInterval() const;
```

### <a name="return-value"></a>Valor de retorno

O número de milissegundos entre o salvamento automático tenta.

##  <a name="getautosavepath"></a>  CDataRecoveryHandler::GetAutosavePath

Retorna o caminho dos arquivos salva automaticamente.

```
virtual CString GetAutosavePath() const;
```

### <a name="return-value"></a>Valor de retorno

O local onde os salva automaticamente os documentos são armazenados.

##  <a name="getdocumentlistname"></a>  CDataRecoveryHandler::GetDocumentListName

Recupera o nome do documento de um `CDocument` objeto.

```
virtual CString GetDocumentListName(CDocument* pDocument) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para um `CDocument`. `GetDocumentListName` recupera o nome do documento deste `CDocument`.|

### <a name="return-value"></a>Valor de retorno

O nome do documento de *pDocument*.

### <a name="remarks"></a>Comentários

O `CDataRecoveryHandler` usa o nome do documento como a chave em *m_mapDocNameToAutosaveName*, *m_mapDocNameToDocumentPtr*, e *m_mapDocNameToRestoreBool*. Esses parâmetros permitem a `CDataRecoveryHandler` para monitorar `CDocument` objetos, o nome do arquivo de salvamento automático e as configurações de salvamento automático.

##  <a name="getnormaldocumenttitle"></a>  CDataRecoveryHandler::GetNormalDocumentTitle

Recupera o cargo normal para o documento especificado.

```
virtual CString GetNormalDocumentTitle(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para um `CDocument`.|

### <a name="return-value"></a>Valor de retorno

O título normal para o documento especificado.

### <a name="remarks"></a>Comentários

O título normal de um documento geralmente é o nome do arquivo do documento sem o caminho. Este é o título na **nome do arquivo** campo da **Salvar como** caixa de diálogo.

##  <a name="getrecovereddocumenttitle"></a>  CDataRecoveryHandler::GetRecoveredDocumentTitle

Cria e retorna o título do documento recuperado.

```
virtual CString GetRecoveredDocumentTitle(const CString& strDocumentTitle) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentTitle*<br/>
[in] O título normal para o documento.

### <a name="return-value"></a>Valor de retorno

O título do documento recuperado.

### <a name="remarks"></a>Comentários

Por padrão, o título recuperado de um documento é o título normal com **[Recuperado]** anexado a ele. O título recuperado é exibido ao usuário quando o `CDataRecoveryHandler` consulta o usuário para restaurar salva automaticamente documentos.

##  <a name="getrestartidentifier"></a>  CDataRecoveryHandler::GetRestartIdentifier

Recupera o identificador exclusivo de reinício para o aplicativo.

```
virtual CString GetRestartIdentifier() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador exclusivo de reinicialização.

### <a name="remarks"></a>Comentários

O identificador de reinicialização é exclusivo para cada execução do aplicativo.

O `CDataRecoveryHandler` armazena informações no registro sobre os documentos abertos. Quando o Gerenciador de reinicialização sai de um aplicativo e reiniciá-lo, ele fornece o identificador de reinício para o `CDataRecoveryHandler`. O `CDataRecoveryHandler` usa o identificador de reinicialização para recuperar a lista de documentos abertos anteriormente. Isso permite que o `CDataRecoveryHandler` para tentar localizar e restaurar arquivos salva automaticamente.

##  <a name="getsavedocumentinfoonidle"></a>  CDataRecoveryHandler::GetSaveDocumentInfoOnIdle

Indica se o `CDataRecoveryHandler` executa uma gravação automática no loop ocioso atual.

```
virtual BOOL GetSaveDocumentInfoOnIdle() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE indica o `CDataRecoveryHandler` salva automaticamente no loop ocioso atual; FALSE indica que não.

##  <a name="getshutdownbyrestartmanager"></a>  CDataRecoveryHandler::GetShutdownByRestartManager

Indica se o Gerenciador de reinicialização causou o aplicativo seja encerrado.

```
virtual BOOL GetShutdownByRestartManager() const;
```

### <a name="return-value"></a>Valor de retorno

TRUE indica que o Gerenciador de reinicialização causou o aplicativo seja encerrado; FALSE indica que não funcionou.

##  <a name="initialize"></a>  CDataRecoveryHandler::Initialize

Inicializa o `CDataRecoveryHandler`.

```
virtual BOOL Initialize();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a inicialização for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O processo de inicialização carrega o caminho para armazenar arquivos de salvamento automático do registro. Se o `Initialize` método não é possível localizar esse diretório ou se o caminho for NULL, `Initialize` falhará e retornará `FALSE`.

Use [CDataRecoveryHandler::SetAutosavePath](#setautosavepath) para alterar o caminho de salvamento automático, depois que o aplicativo é inicializado a `CDataRecoveryHandler`.

O `Initialize` método também inicia um cronômetro para monitorar quando ocorre o salvamento automático de Avançar. Use [CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval) para alterar o intervalo de salvamento automático, depois que o aplicativo é inicializado a `CDataRecoveryHandler`.

##  <a name="queryrestoreautosaveddocuments"></a>  CDataRecoveryHandler::QueryRestoreAutosavedDocuments

Exibe uma caixa de diálogo para o usuário para cada documento que o `CDataRecoveryHandler` salva automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salvo automaticamente.

```
virtual void QueryRestoreAutosavedDocuments();
```

### <a name="remarks"></a>Comentários

Se seu aplicativo for Unicode, esse método exibe uma [CTaskDialog](../../mfc/reference/ctaskdialog-class.md) ao usuário. Caso contrário, a estrutura usa [AfxMessageBox](../../mfc/reference/cstring-formatting-and-message-box-display.md#afxmessagebox) para consultar o usuário.

Após `QueryRestoreAutosavedDocuments` reúne todas as respostas do usuário, ele armazena as informações na variável de membro *m_mapDocNameToRestoreBool*. Esse método não restaura os documentos salva automaticamente.

##  <a name="readopendocumentlist"></a>  CDataRecoveryHandler::ReadOpenDocumentList

Carrega a lista de documentos abertos do registro.

```
virtual BOOL ReadOpenDocumentList();
```

### <a name="return-value"></a>Valor de retorno

VERDADEIRO indica que `ReadOpenDocumentList` carregado as informações de pelo menos um documento do registro; FALSE indica que nenhuma informação de documento foi carregada.

### <a name="remarks"></a>Comentários

Essa função carrega as informações de documento aberto do registro e o armazena na variável de membro *m_mapDocNameToAutosaveName*.

Depois de `ReadOpenDocumentList` carrega todos os dados, ele exclui as informações do documento do registro.

##  <a name="removedocumentinfo"></a>  CDataRecoveryHandler::RemoveDocumentInfo

Remove o documento fornecido da lista de documentos abertos.

```
virtual BOOL RemoveDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para o documento a ser removido.|

### <a name="return-value"></a>Valor de retorno

TRUE se *pDocument* foi removido da lista; FALSE se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando o usuário fecha um documento, a estrutura usa esse método para removê-lo da lista de documentos abertos.

Se `RemoveDocumentInfo` não é possível encontrar *pDocument* na lista de documentos abertos, ele não faz nada e retorna TRUE.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*.

##  <a name="reopenpreviousdocuments"></a>  CDataRecoveryHandler::ReopenPreviousDocuments

Abre os documentos abertos anteriormente.

```
virtual BOOL ReopenPreviousDocuments();
```

### <a name="return-value"></a>Valor de retorno

TRUE se pelo menos um documento foi aberto; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método abre o salvamento mais recente dos documentos abertos anteriormente. Se um documento não foi salvo ou salva automaticamente, `ReopenPreviousDocuments` abre um documento em branco baseado no modelo para esse tipo de arquivo.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*. Se esse parâmetro não for definido, `ReopenPreviousDocuments` não faz nada e retornará FALSE.

Se não houver nenhum documento armazenado na lista de documentos anteriormente abertos, `ReopenPreviousDocuments` não faz nada e retornará FALSE.

##  <a name="restoreautosaveddocuments"></a>  CDataRecoveryHandler::RestoreAutosavedDocuments

Restaura os documentos salva automaticamente com base na entrada do usuário.

```
virtual BOOL RestoreAutosavedDocuments();
```

### <a name="return-value"></a>Valor de retorno

TRUE se este método restaura com êxito os documentos.

### <a name="remarks"></a>Comentários

Este método chama [CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments) determinar que documenta o usuário deseja restaurar. Se um usuário decidir não restaurar de um documento salvo automaticamente, `RestoreAutosavedDocuments` exclui o arquivo de salvamento automático. Caso contrário, `RestoreAutosavedDocuments` substitui o documento aberto com a versão salva automaticamente.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES ou AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES deve ser definido `m_dwRestartManagerSupportFlags`.

##  <a name="saveopendocumentlist"></a>  CDataRecoveryHandler::SaveOpenDocumentList

Salva a lista atual de documentos abertos no registro do Windows.

```
virtual BOOL SaveOpenDocumentList();
```

### <a name="return-value"></a>Valor de retorno

TRUE se não houver nenhum documento aberto para salvar ou se eles foram salvas com êxito. FALSE se houver documentos para salvar no registro, mas não foram salvas porque ocorreu um erro.

### <a name="remarks"></a>Comentários

As chamadas de Gerenciador de reinicialização `SaveOpenDocumentList` quando o aplicativo for encerrado inesperadamente ou quando ele sai para uma atualização. Quando o aplicativo for reiniciado, ele usa [CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist) para recuperar a lista de documentos abertos.

Esse método salva apenas a lista de documentos abertos. O método [CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo) é responsável por salvar os documentos em si.

##  <a name="setautosaveinterval"></a>  CDataRecoveryHandler::SetAutosaveInterval

Define o tempo entre os ciclos de salvamento automático em milissegundos.

```
Virtual void SetAutosaveInterval(int nAutosaveInterval);
```

### <a name="parameters"></a>Parâmetros

*nAutosaveInterval*<br/>
[in] O novo intervalo de salvamento automático em milissegundos.

##  <a name="setautosavepath"></a>  CDataRecoveryHandler::SetAutosavePath

Define o diretório onde salva automaticamente arquivos estão armazenados.

```
virtual void SetAutosavePath(const CString& strAutosavePath);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strAutosavePath*|[in] O caminho onde os arquivos de salvamento automático são armazenados.|

### <a name="remarks"></a>Comentários

Alterar o diretório de salvamento automático não move atualmente salva automaticamente arquivos.

##  <a name="setrestartidentifier"></a>  CDataRecoveryHandler::SetRestartIdentifier

Define o identificador exclusivo de reinicialização para esta instância da `CDataRecoveryHandler`.

```
virtual void SetRestartIdentifier(const CString& strRestartIdentifier);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strRestartIdentifier*|[in] O identificador exclusivo para o Gerenciador de reinicialização.|

### <a name="remarks"></a>Comentários

O Gerenciador de reinicialização registra informações sobre os documentos abertos no registro. Essas informações são armazenadas com o identificador exclusivo de reinicialização como a chave. Como o identificador de reinicialização é exclusivo para cada instância de um aplicativo, várias instâncias de um aplicativo podem fechar inesperadamente e o Gerenciador de reinicialização pode recuperar cada um deles.

##  <a name="setsavedocumentinfoonidle"></a>  CDataRecoveryHandler::SetSaveDocumentInfoOnIdle

Define se o `CDataRecoveryHandler` salva as informações de documento aberto no registro do Windows durante o ciclo de ociosidade atual.

```
virtual void SetSaveDocumentInfoOnIdle(BOOL bSaveOnIdle);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bSaveOnIdle*|[in] TRUE para salvar as informações do documento durante o ciclo atual ocioso; FALSO para não realizar uma operação Salvar.|

##  <a name="setshutdownbyrestartmanager"></a>  CDataRecoveryHandler::SetShutdownByRestartManager

Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.

```
virtual void SetShutdownByRestartManager(BOOL bShutdownByRestartManager);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bShutdownByRestartManager*|[in] TRUE para indicar que o Gerenciador de reinicialização causado o aplicativo seja encerrado; FALSE para indicar que o aplicativo seja encerrado por outro motivo.|

### <a name="remarks"></a>Comentários

A estrutura se comporta de forma diferente com base em se a saída anterior era esperada ou se ele foi iniciado pelo Gerenciador de reinicialização.

##  <a name="updatedocumentinfo"></a>  CDataRecoveryHandler::UpdateDocumentInfo

Atualiza as informações de um documento porque ele está sendo salvo por usuário.

```
virtual BOOL UpdateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[in] Um ponteiro para o documento salvo.|

### <a name="return-value"></a>Valor de retorno

TRUE se este método excluído do documento salva automaticamente e atualizou as informações do documento; FALSE se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando um usuário salva um documento, o aplicativo remove o arquivo salvo automaticamente porque ele não for mais necessário. `UpdateDocumentInfo` Exclui o arquivo salvo automaticamente chamando [CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo). `UpdateDocumentInfo` em seguida, adiciona as informações da *pDocument* à lista de atualmente documentos abertos porque `RemoveDocumentInfo` exclui essa informação, mas o salvo documento ainda está aberto.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Como: Adicionar suporte ao Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)
