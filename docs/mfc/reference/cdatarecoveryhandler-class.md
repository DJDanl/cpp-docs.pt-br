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
ms.openlocfilehash: bdfcbea6c345235358384691388afcdbbd2d0a42
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321939"
---
# <a name="cdatarecoveryhandler-class"></a>Classe CDataRecoveryHandler

O `CDataRecoveryHandler` automático salva documentos e os restaura se um aplicativo sair inesperadamente.

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
|[CDataRecoveryHandler::Save automáticoAllDocumentInfo](#autosavealldocumentinfo)|Salva automaticamente cada arquivo registrado `CDataRecoveryHandler` na classe.|
|[CDataRecoveryHandler::Salvamento automáticoDocumentInfo](#autosavedocumentinfo)|Salva automaticamente o documento especificado.|
|[CDataRecoveryHandler::CreateDocumentInfo](#createdocumentinfo)|Adiciona um documento à lista de documentos abertos.|
|[CDataRecoveryHandler::DeleteAllAutosavedFiles](#deleteallautosavedfiles)|Exclui todos os arquivos salvos automaticamente atuais.|
|[CDataRecoveryHandler::DeleteAutosavedFile](#deleteautosavedfile)|Exclui o arquivo salvo automaticamente especificado.|
|[CDataRecoveryHandler::GerarsalvamentoautomáticoNome de arquivo](#generateautosavefilename)|Gera o nome de um arquivo de salvamento automático associado ao nome do arquivo do documento fornecido.|
|[CDataRecoveryHandler::GetAutosaveInterval](#getautosaveinterval)|Retorna o intervalo entre tentativas de salvamento automático.|
|[CDataRecoveryHandler::GetAutosavePath](#getautosavepath)|Retorna o caminho dos arquivos salvos automaticamente.|
|[CDataRecoveryHandler::GetDocumentListName](#getdocumentlistname)|Recupera o nome do `CDocument` documento de um objeto.|
|[CDataRecoveryHandler::GetNormalDocumentTitle](#getnormaldocumenttitle)|Recupera o título normal para o documento especificado.|
|[CDataRecoveryHandler::GetRecoveredDocumentTitle](#getrecovereddocumenttitle)|Cria e devolve o título para o documento recuperado.|
|[CDataRecoveryHandler::GetRestartIdentifier](#getrestartidentifier)|Recupera o identificador de reinicialização exclusivo para o aplicativo.|
|[CDataRecoveryHandler::GetSaveDocumentInfoOnIdle](#getsavedocumentinfoonidle)|Indica se `CDataRecoveryHandler` o executa um salvamento automático no loop ocioso atual.|
|[CDataRecoveryHandler::GetShutdownByRestartManager](#getshutdownbyrestartmanager)|Indica se o gerenciador de reinicialização fez com que o aplicativo saísse.|
|[CDataRecoveryHandler::Inicializar](#initialize)|Inicializa o `CDataRecoveryHandler`.|
|[CDataRecoveryHandler::ConsultaRestaurandodocumentosalvo automaticamente](#queryrestoreautosaveddocuments)|Exibe uma caixa de diálogo para `CDataRecoveryHandler` o usuário para cada documento que o salvos automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salvo automaticamente.|
|[CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist)|Carrega a lista de documentos abertos do registro.|
|[CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo)|Remove o documento fornecido da lista de documentos abertos.|
|[CDataRecoveryHandler::Reaberturadocumentos anteriores](#reopenpreviousdocuments)|Abre os documentos abertos anteriormente.|
|[CDataRecoveryHandler::Restaurardocumentos com salvos automáticos](#restoreautosaveddocuments)|Restaura os documentos salvos automaticamente com base na entrada do usuário.|
|[CDataRecoveryHandler::SaveOpenDocumentList](#saveopendocumentlist)|Salva a lista atual de documentos abertos no registro do Windows.|
|[CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval)|Define o tempo entre ciclos de salvamento automático em milissegundos.|
|[CDataRecoveryHandler::SetAutosavePath](#setautosavepath)|Define o diretório onde os arquivos salvos automáticos são armazenados.|
|[CDataRecoveryHandler::SetRestartIdentifier](#setrestartidentifier)|Define o identificador de reinicialização exclusivo para esta instância do `CDataRecoveryHandler`.|
|[CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle)|Define se `CDataRecoveryHandler` o salvo as informações do documento aberto no registro do Windows durante o ciclo ocioso atual.|
|[CDataRecoveryHandler::SetShutdownByRestartManager](#setshutdownbyrestartmanager)|Define se a saída anterior do aplicativo foi causada pelo gerenciador de reinicialização.|
|[CDataRecoveryHandler::UpdateDocumentInfo](#updatedocumentinfo)|Atualiza as informações de um documento porque o usuário a salvou.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|m_bRestoringPreviousOpenDocs|Indica se o manipulador de recuperação de dados reabre documentos abertos anteriormente.|
|m_bSaveDocumentInfoOnIdle|Indica se o manipulador de recuperação de dados salva automaticamente documentos no próximo loop ocioso.|
|m_bShutdownByRestartManager|Indica se o gerenciador de reinicialização faz com que o aplicativo saia.|
|m_dwRestartManagerSupportFlags|Sinalizadores que indicam o suporte que o gerenciador de reinicialização fornece para o aplicativo.|
|m_lstAutosavesToDelete|Uma lista de arquivos salvos automaticamente que não foram excluídos quando os documentos originais foram fechados. Quando o aplicativo sai, o gerenciador de reinicialização tenta excluir os arquivos.|
|m_mapDocNameToAutosaveName|Um mapa dos nomes dos documentos para os nomes dos arquivos salvos automaticamente.|
|m_mapDocNameToDocumentPtr|Um mapa dos nomes dos documentos para os ponteiros [cdocument.](../../mfc/reference/cdocument-class.md)|
|m_mapDocNameToRestoreBool|Um mapa dos nomes do documento para um parâmetro booleano que indica se deve restaurar o documento salvo automaticamente.|
|m_mapDocumentPtrToDocName|Um mapa `CDocument` dos ponteiros para os nomes dos documentos.|
|m_mapDocumentPtrToDocTitle|Um mapa `CDocument` dos ponteiros para os títulos do documento. Esses títulos são usados para salvar arquivos.|
|m_nAutosaveInterval|Tempo em milissegundos entre salvamentos automáticos.|
|m_nTimerID|O identificador do temporizador de salvamento automático.|
|m_strAutosavePath|O local onde os documentos salvos automáticos são armazenados.|
|m_strRestartIdentifier|A representação de string de um GUID para o gerenciador de reinicialização.|

## <a name="remarks"></a>Comentários

O gerenciador `CDataRecoveryHandler` de reinicialização usa a classe para acompanhar todos os documentos abertos e salvá-los automaticamente conforme necessário. Para habilitar o salvamento automático, use o método [CDataRecoveryHandler::SetSaveDocumentInfoOnIdle.](#setsavedocumentinfoonidle) Este método direciona `CDataRecoveryHandler` o para executar um salvamento automático no próximo loop ocioso. O gerenciador `SetSaveDocumentInfoOnIdle` de `CDataRecoveryHandler` reinicialização é chamada quando deve executar um salvamento automático.

Todos os métodos `CDataRecoveryHandler` da classe são virtuais. Substituir os métodos desta classe para criar seu próprio manipulador personalizado de recuperação de dados. A menos que você crie seu próprio manipulador de recuperação de dados ou gerenciador de reinicialização, não instanciar um CDataRecoveryHandler. A [Classe CWinApp](../../mfc/reference/cwinapp-class.md) cria um `CDataRecoveryHandler` objeto conforme necessário.

Antes de usar `CDataRecoveryHandler` um objeto, você deve chamar [CDataRecoveryHandler::Initialize](#initialize).

Como `CDataRecoveryHandler` a classe está intimamente ligada `CDataRecoveryHandler` ao gerenciador de `m_dwRestartManagerSupportFlags`reinicialização, depende do parâmetro global . Este parâmetro determina quais permissões o gerenciador de reinicialização tem e como ele interage com seu aplicativo. Para incorporar o gerenciador de reinicialização em `m_dwRestartManagerSupportFlags` um aplicativo existente, você tem que atribuir o valor apropriado no construtor do seu aplicativo principal. Para obter mais informações sobre como usar o gerenciador de reinicialização, consulte [Como: Adicionar suporte ao Gerenciador de Reinicialização](../../mfc/how-to-add-restart-manager-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdatarecovery.h

## <a name="cdatarecoveryhandlerautosavealldocumentinfo"></a><a name="autosavealldocumentinfo"></a>CDataRecoveryHandler::Save automáticoAllDocumentInfo

Salva automaticamente cada arquivo registrado `CDataRecoveryHandler` na classe.

```
virtual BOOL AutosaveAllDocumentInfo();
```

### <a name="return-value"></a>Valor retornado

VERDADE se `CDataRecoveryHandler` os documentos salvos; FALSO se algum documento não foi salvo.

### <a name="remarks"></a>Comentários

Este método retorna TRUE se não houver documentos que devem ser salvos. Ele também retorna TRUE sem salvar `CWinApp` `CDocManager` quaisquer documentos se recuperar o ou para o aplicativo gera um erro.

Para utilizar este método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou `m_dwRestartManagerSupportFlags`AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL devem ser definidos em . Para obter mais informações, consulte [Como: Adicionar suporte ao Restart Manager](../../mfc/how-to-add-restart-manager-support.md).

## <a name="cdatarecoveryhandlerautosavedocumentinfo"></a><a name="autosavedocumentinfo"></a>CDataRecoveryHandler::Salvamento automáticoDocumentInfo

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
|*pDocument*|[em] Um ponteiro `CDocument` para salvar.|
|*bResetModifiedFlag*|[em] TRUE indica `CDataRecoveryHandler` que o *documento considera pDocument* a ser modificado; FALSE indica que o framework considera *pDocument* não modificado. Consulte a seção Observações para obter mais informações sobre o efeito desta bandeira.|

### <a name="return-value"></a>Valor retornado

TRUE se os sinalizadores apropriados forem definidos e *pDocumento* for um objeto válido. `CDocument`

### <a name="remarks"></a>Comentários

Cada `CDocument` objeto tem uma bandeira que indica se ele mudou desde a última salvação. Use [CDocument::IsModified](../../mfc/reference/cdocument-class.md#ismodified) para determinar o estado desta bandeira. Se `CDocument` a não tiver sido `AutosaveDocumentInfo` alterada desde a última salvação, excluirá quaisquer arquivos salvos automaticamente para esse documento. Se um documento foi alterado desde a última salvação, o fechamento solicita ao usuário que salve o documento antes de fechar.

> [!NOTE]
> O uso *do bResetModifiedFlag* para alterar o estado do documento para não modificado pode fazer com que o usuário perca dados não salvos. Se o framework considerar um documento não modificado, o fechamento não solicitará que o usuário salve.

Este método lança uma exceção com a macro `CDocument` [ASSERT](diagnostic-services.md#assert) se *pDocument* não for um objeto válido.

Para utilizar este método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL devem ser definidos em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlercdatarecoveryhandler"></a><a name="cdatarecoveryhandler"></a>CDataRecoveryHandler::CDataRecoveryHandler

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
|*dwRestartManagerSupportFlags*|[em] Indica quais opções do gerenciador de reinicialização são suportadas.|
|*nAutosaveInterval*|[em] O tempo entre autosaves. Este parâmetro é em milissegundos.|

### <a name="remarks"></a>Comentários

A estrutura Do MFC `CDataRecoveryHandler` cria automaticamente um objeto para o aplicativo quando você usa o assistente **Novo Projeto.** A menos que você esteja personalizando o comportamento de recuperação `CDataRecoveryHandler` de dados ou o gerenciador de reinicialização, você não deve criar um objeto.

## <a name="cdatarecoveryhandlercreatedocumentinfo"></a><a name="createdocumentinfo"></a>CDataRecoveryHandler::CreateDocumentInfo

Adiciona um documento à lista de documentos abertos.

```
virtual BOOL CreateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[em] Um ponteiro `CDocument`para um. Este método cria as `CDocument`informações do documento para isso.|

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Este método verifica se *pDocument* já está na lista de documentos antes de adicionar o documento. Se *pDocument* já estiver na lista, este método excluirá o arquivo salvo automaticamente associado ao *pDocument*.

Para utilizar este método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL devem ser definidos em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlerdeleteallautosavedfiles"></a><a name="deleteallautosavedfiles"></a>CDataRecoveryHandler::DeleteAllAutosavedFiles

Exclui todos os arquivos salvos automaticamente atuais.

```
virtual BOOL DeleteAllAutosavedFiles();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão sempre retorna TRUE.

## <a name="cdatarecoveryhandlerdeleteautosavedfile"></a><a name="deleteautosavedfile"></a>CDataRecoveryHandler::DeleteAutosavedFile

Exclui o arquivo salvo automaticamente especificado.

```
virtual BOOL DeleteAutosavedFile(const CString& strAutosavedFile);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strAutosavedFile*|[em] Uma seqüência que contém o nome do arquivo salvo automaticamente.|

### <a name="return-value"></a>Valor retornado

A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Se este método não puder excluir o arquivo salvo automaticamente, ele salvará o nome do arquivo em uma lista. O destruidor para as `CDataRecoveryHandler` tentativas de excluir cada arquivo salvo automaticamente especificado nessa lista.

## <a name="cdatarecoveryhandlergenerateautosavefilename"></a><a name="generateautosavefilename"></a>CDataRecoveryHandler::GerarsalvamentoautomáticoNome de arquivo

Gera o nome de um arquivo de salvamento automático associado ao nome do arquivo do documento fornecido.

```
virtual CString GenerateAutosaveFileName(const CString& strDocumentName) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentName*<br/>
[em] Uma seqüência que contém o nome do documento. `GenerateAutosaveFileName`usa este nome do documento para gerar um nome de arquivo de salvamento automático correspondente.

### <a name="return-value"></a>Valor retornado

O nome do arquivo de salvamento automático gerado a partir de *strDocumentName*.

### <a name="remarks"></a>Comentários

Cada nome do documento tem um mapeamento de um para um com um nome de arquivo de salvamento automático.

## <a name="cdatarecoveryhandlergetautosaveinterval"></a><a name="getautosaveinterval"></a>CDataRecoveryHandler::GetAutosaveInterval

Retorna o intervalo entre tentativas de salvamento automático.

```
virtual int GetAutosaveInterval() const;
```

### <a name="return-value"></a>Valor retornado

O número de milissegundos entre tentativas de salvamento automático.

## <a name="cdatarecoveryhandlergetautosavepath"></a><a name="getautosavepath"></a>CDataRecoveryHandler::GetAutosavePath

Retorna o caminho dos arquivos salvos automaticamente.

```
virtual CString GetAutosavePath() const;
```

### <a name="return-value"></a>Valor retornado

O local onde os documentos salvos automáticos são armazenados.

## <a name="cdatarecoveryhandlergetdocumentlistname"></a><a name="getdocumentlistname"></a>CDataRecoveryHandler::GetDocumentListName

Recupera o nome do `CDocument` documento de um objeto.

```
virtual CString GetDocumentListName(CDocument* pDocument) const;
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[em] Um ponteiro `CDocument`para um. `GetDocumentListName`recupera o nome do `CDocument`documento a partir disso .|

### <a name="return-value"></a>Valor retornado

O nome do documento de *pDocument*.

### <a name="remarks"></a>Comentários

O `CDataRecoveryHandler` uso do nome do documento como chave em *m_mapDocNameToAutosaveName,* *m_mapDocNameToDocumentPtr*e *m_mapDocNameToRestoreBool*. Esses parâmetros `CDataRecoveryHandler` permitem `CDocument` monitorar objetos, o nome do arquivo de salvamento automático e as configurações de salvamento automático.

## <a name="cdatarecoveryhandlergetnormaldocumenttitle"></a><a name="getnormaldocumenttitle"></a>CDataRecoveryHandler::GetNormalDocumentTitle

Recupera o título normal para o documento especificado.

```
virtual CString GetNormalDocumentTitle(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[em] Um ponteiro `CDocument`para um.|

### <a name="return-value"></a>Valor retornado

O título normal para o documento especificado.

### <a name="remarks"></a>Comentários

O título normal de um documento é geralmente o nome do arquivo do documento sem o caminho. Este é o título no campo **Nome do arquivo** da caixa de diálogo Salvar **como.**

## <a name="cdatarecoveryhandlergetrecovereddocumenttitle"></a><a name="getrecovereddocumenttitle"></a>CDataRecoveryHandler::GetRecoveredDocumentTitle

Cria e devolve o título para o documento recuperado.

```
virtual CString GetRecoveredDocumentTitle(const CString& strDocumentTitle) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentTitle*<br/>
[em] O título normal para o documento.

### <a name="return-value"></a>Valor retornado

O título do documento recuperado.

### <a name="remarks"></a>Comentários

Por padrão, o título recuperado de um documento é o título normal com **[recuperado]** anexado a ele. O título recuperado é exibido ao `CDataRecoveryHandler` usuário quando o usuário consulta para restaurar documentos salvos automaticamente.

## <a name="cdatarecoveryhandlergetrestartidentifier"></a><a name="getrestartidentifier"></a>CDataRecoveryHandler::GetRestartIdentifier

Recupera o identificador de reinicialização exclusivo para o aplicativo.

```
virtual CString GetRestartIdentifier() const;
```

### <a name="return-value"></a>Valor retornado

O identificador de reinicialização exclusivo.

### <a name="remarks"></a>Comentários

O identificador de reinicialização é único para cada execução do aplicativo.

As `CDataRecoveryHandler` informações guardam no registro sobre os documentos atualmente abertos. Quando o gerenciador de reinicialização sai de um aplicativo e `CDataRecoveryHandler`o reinicia, ele fornece o identificador de reinicialização para o . O `CDataRecoveryHandler` uso do identificador de reinicialização para recuperar a lista de documentos abertos anteriormente. Isso permite `CDataRecoveryHandler` que você tente encontrar e restaurar arquivos salvos automaticamente.

## <a name="cdatarecoveryhandlergetsavedocumentinfoonidle"></a><a name="getsavedocumentinfoonidle"></a>CDataRecoveryHandler::GetSaveDocumentInfoOnIdle

Indica se `CDataRecoveryHandler` o executa um salvamento automático no loop ocioso atual.

```
virtual BOOL GetSaveDocumentInfoOnIdle() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica `CDataRecoveryHandler` os salvamentos automáticos no loop ocioso atual; FALSE indica que não.

## <a name="cdatarecoveryhandlergetshutdownbyrestartmanager"></a><a name="getshutdownbyrestartmanager"></a>CDataRecoveryHandler::GetShutdownByRestartManager

Indica se o gerenciador de reinicialização fez com que o aplicativo saísse.

```
virtual BOOL GetShutdownByRestartManager() const;
```

### <a name="return-value"></a>Valor retornado

TRUE indica que o gerenciador de reinicialização fez com que o aplicativo saísse; FALSE indica que não.

## <a name="cdatarecoveryhandlerinitialize"></a><a name="initialize"></a>CDataRecoveryHandler::Inicializar

Inicializa o `CDataRecoveryHandler`.

```
virtual BOOL Initialize();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se a inicialização for bem sucedida; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O processo de inicialização carrega o caminho para armazenar arquivos de salvamento automático do registro. Se `Initialize` o método não conseguir encontrar este diretório `Initialize` ou `FALSE`se o caminho for NULO, falhará e retornará .

Use [CDataRecoveryHandler::SetAutosavePath](#setautosavepath) para alterar o caminho de salvamento `CDataRecoveryHandler`automático após a inicialização do aplicativo .

O `Initialize` método também inicia um temporizador para monitorar quando o próximo salvamento automático ocorrer. Use [CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval) para alterar o intervalo de salvamento `CDataRecoveryHandler`automático após a inicialização do aplicativo .

## <a name="cdatarecoveryhandlerqueryrestoreautosaveddocuments"></a><a name="queryrestoreautosaveddocuments"></a>CDataRecoveryHandler::ConsultaRestaurandodocumentosalvo automaticamente

Exibe uma caixa de diálogo para `CDataRecoveryHandler` o usuário para cada documento que o salvos automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salvo automaticamente.

```
virtual void QueryRestoreAutosavedDocuments();
```

### <a name="remarks"></a>Comentários

Se o aplicativo for Unicode, este método exibirá um [CTaskDialog](../../mfc/reference/ctaskdialog-class.md) para o usuário. Caso contrário, a estrutura usa [a AfxMessageBox](../../mfc/reference/cstring-formatting-and-message-box-display.md#afxmessagebox) para consultar o usuário.

Depois `QueryRestoreAutosavedDocuments` de reunir todas as respostas do usuário, ele armazena as informações na variável *membro m_mapDocNameToRestoreBool*. Este método não restaura os documentos salvos automaticamente.

## <a name="cdatarecoveryhandlerreadopendocumentlist"></a><a name="readopendocumentlist"></a>CDataRecoveryHandler::ReadOpenDocumentList

Carrega a lista de documentos abertos do registro.

```
virtual BOOL ReadOpenDocumentList();
```

### <a name="return-value"></a>Valor retornado

True indica `ReadOpenDocumentList` que carregou as informações para pelo menos um documento do registro; Falso indica que nenhuma informação do documento foi carregada.

### <a name="remarks"></a>Comentários

Esta função carrega as informações do documento aberto do registro e armazena-as na variável *membro m_mapDocNameToAutosaveName*.

Depois `ReadOpenDocumentList` de carregar todos os dados, ele exclui as informações do documento do registro.

## <a name="cdatarecoveryhandlerremovedocumentinfo"></a><a name="removedocumentinfo"></a>CDataRecoveryHandler::RemoveDocumentInfo

Remove o documento fornecido da lista de documentos abertos.

```
virtual BOOL RemoveDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[em] Um ponteiro para o documento para remover.|

### <a name="return-value"></a>Valor retornado

TRUE se *pDocument* foi removido da lista; FALSO se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando o usuário fecha um documento, a estrutura usa esse método para removê-lo da lista de documentos abertos.

Se `RemoveDocumentInfo` não conseguir encontrar *pDocument* na lista de documentos abertos, ele não faz nada e retorna TRUE.

Para utilizar este método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES devem ser definidos em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlerreopenpreviousdocuments"></a><a name="reopenpreviousdocuments"></a>CDataRecoveryHandler::Reaberturadocumentos anteriores

Abre os documentos abertos anteriormente.

```
virtual BOOL ReopenPreviousDocuments();
```

### <a name="return-value"></a>Valor retornado

VERDADE se pelo menos um documento foi aberto; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método abre a salvação mais recente dos documentos abertos anteriormente. Se um documento não foi `ReopenPreviousDocuments` salvo ou salvo automaticamente, abrirá um documento em branco com base no modelo para esse tipo de arquivo.

Para utilizar este método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES devem ser definidos em *m_dwRestartManagerSupportFlags*. Se este parâmetro não `ReopenPreviousDocuments` estiver definido, não faça nada e devolva FALSO.

Se não houver documentos armazenados na lista `ReopenPreviousDocuments` de documentos abertos anteriormente, não faz nada e retorna FALSO.

## <a name="cdatarecoveryhandlerrestoreautosaveddocuments"></a><a name="restoreautosaveddocuments"></a>CDataRecoveryHandler::Restaurardocumentos com salvos automáticos

Restaura os documentos salvos automaticamente com base na entrada do usuário.

```
virtual BOOL RestoreAutosavedDocuments();
```

### <a name="return-value"></a>Valor retornado

TRUE se este método restaurar os documentos com sucesso.

### <a name="remarks"></a>Comentários

Este método chama [CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments) para determinar quais documentos o usuário deseja restaurar. Se um usuário decidir não restaurar um `RestoreAutosavedDocuments` documento salvo automaticamente, excluirá o arquivo de salvamento automático. Caso contrário, `RestoreAutosavedDocuments` substitui o documento aberto pela versão salva automaticamente.

Para usar este método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES ou `m_dwRestartManagerSupportFlags`AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES devem ser definidos em .

## <a name="cdatarecoveryhandlersaveopendocumentlist"></a><a name="saveopendocumentlist"></a>CDataRecoveryHandler::SaveOpenDocumentList

Salva a lista atual de documentos abertos no registro do Windows.

```
virtual BOOL SaveOpenDocumentList();
```

### <a name="return-value"></a>Valor retornado

TRUE se não houver documentos abertos para salvar ou se eles foram salvos com sucesso. FALSO se houver documentos para salvar no registro, mas eles não foram salvos porque ocorreu um erro.

### <a name="remarks"></a>Comentários

O gerenciador `SaveOpenDocumentList` de reinicialização liga quando o aplicativo sai inesperadamente ou quando ele sai para um upgrade. Quando o aplicativo é reiniciado, ele usa [CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist) para recuperar a lista de documentos abertos.

Este método salva apenas a lista de documentos abertos. O método [CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo) é responsável por salvar os documentos em si.

## <a name="cdatarecoveryhandlersetautosaveinterval"></a><a name="setautosaveinterval"></a>CDataRecoveryHandler::SetAutosaveInterval

Define o tempo entre ciclos de salvamento automático em milissegundos.

```
Virtual void SetAutosaveInterval(int nAutosaveInterval);
```

### <a name="parameters"></a>Parâmetros

*nAutosaveInterval*<br/>
[em] O novo intervalo de salvamento automático em milissegundos.

## <a name="cdatarecoveryhandlersetautosavepath"></a><a name="setautosavepath"></a>CDataRecoveryHandler::SetAutosavePath

Define o diretório onde os arquivos salvos automáticos são armazenados.

```
virtual void SetAutosavePath(const CString& strAutosavePath);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strAutosavePath*|[em] O caminho onde os arquivos de salvamento automático são armazenados.|

### <a name="remarks"></a>Comentários

Alterar o diretório de salvamento automático não move arquivos salvos automaticamente no momento.

## <a name="cdatarecoveryhandlersetrestartidentifier"></a><a name="setrestartidentifier"></a>CDataRecoveryHandler::SetRestartIdentifier

Define o identificador de reinicialização exclusivo para esta instância do `CDataRecoveryHandler`.

```
virtual void SetRestartIdentifier(const CString& strRestartIdentifier);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*strRestartIdentifier*|[em] O identificador exclusivo para o gerenciador de reinicialização.|

### <a name="remarks"></a>Comentários

O gerenciador de reinicialização registra informações sobre os documentos abertos no registro. Essas informações são armazenadas com o identificador de reinicialização exclusivo como a chave. Como o identificador de reinicialização é único para cada instância de um aplicativo, várias instâncias de um aplicativo podem sair inesperadamente e o gerenciador de reinicialização pode recuperar cada um deles.

## <a name="cdatarecoveryhandlersetsavedocumentinfoonidle"></a><a name="setsavedocumentinfoonidle"></a>CDataRecoveryHandler::SetSaveDocumentInfoOnIdle

Define se `CDataRecoveryHandler` o salvo as informações do documento aberto no registro do Windows durante o ciclo ocioso atual.

```
virtual void SetSaveDocumentInfoOnIdle(BOOL bSaveOnIdle);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bSaveOnIdle*|[em] TRUE para salvar informações do documento durante o ciclo ocioso atual; FALSO para não realizar um salvamento.|

## <a name="cdatarecoveryhandlersetshutdownbyrestartmanager"></a><a name="setshutdownbyrestartmanager"></a>CDataRecoveryHandler::SetShutdownByRestartManager

Define se a saída anterior do aplicativo foi causada pelo gerenciador de reinicialização.

```
virtual void SetShutdownByRestartManager(BOOL bShutdownByRestartManager);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*bShutdownByRestartManager*|[em] VERDADE para indicar que o gerenciador de reinicialização fez com que o aplicativo saísse; FALSO para indicar que o aplicativo saiu por outro motivo.|

### <a name="remarks"></a>Comentários

O quadro se comporta de forma diferente com base em se a saída anterior foi inesperada ou se foi iniciada pelo gerenciador de reinicialização.

## <a name="cdatarecoveryhandlerupdatedocumentinfo"></a><a name="updatedocumentinfo"></a>CDataRecoveryHandler::UpdateDocumentInfo

Atualiza as informações de um documento porque o usuário a salvou.

```
virtual BOOL UpdateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pDocument*|[em] Um ponteiro para o documento salvo.|

### <a name="return-value"></a>Valor retornado

TRUE se este método excluísse o documento salvo automaticamente e atualizasse as informações do documento; FALSO se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando um usuário salva um documento, o aplicativo remove o arquivo salvo automaticamente porque ele não é mais necessário. `UpdateDocumentInfo`exclui o arquivo salvo automaticamente chamando [CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo). `UpdateDocumentInfo`em seguida, adiciona as informações do *pDocument* `RemoveDocumentInfo` à lista de documentos abertos atualmente porque exclui essas informações, mas o documento salvo ainda está aberto.

Para utilizar este método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES devem ser definidos em *m_dwRestartManagerSupportFlags*.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)
