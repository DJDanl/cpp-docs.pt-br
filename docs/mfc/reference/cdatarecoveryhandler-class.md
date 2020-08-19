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
ms.openlocfilehash: c796f24ad37b3bae11314e2885bf25e25f85aba6
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561967"
---
# <a name="cdatarecoveryhandler-class"></a>Classe CDataRecoveryHandler

O `CDataRecoveryHandler` salva os documentos e os restaura se um aplicativo for encerrado inesperadamente.

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
|[CDataRecoveryHandler::AutosaveAllDocumentInfo](#autosavealldocumentinfo)|Salva o salvamento de cada arquivo registrado com a `CDataRecoveryHandler` classe.|
|[CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo)|Salva o documento especificado.|
|[CDataRecoveryHandler::CreateDocumentInfo](#createdocumentinfo)|Adiciona um documento à lista de documentos abertos.|
|[CDataRecoveryHandler::D eleteAllAutosavedFiles](#deleteallautosavedfiles)|Exclui todos os arquivos autosalvos atuais.|
|[CDataRecoveryHandler::D eleteAutosavedFile](#deleteautosavedfile)|Exclui o arquivo autosalvo especificado.|
|[CDataRecoveryHandler::GenerateAutosaveFileName](#generateautosavefilename)|Gera o nome de um arquivo de salvamento automático associado ao nome de arquivo de documento fornecido.|
|[CDataRecoveryHandler::GetAutosaveInterval](#getautosaveinterval)|Retorna o intervalo entre as tentativas de salvamento automático.|
|[CDataRecoveryHandler::GetAutosavePath](#getautosavepath)|Retorna o caminho dos arquivos salvos novamente.|
|[CDataRecoveryHandler::GetDocumentListName](#getdocumentlistname)|Recupera o nome do documento de um `CDocument` objeto.|
|[CDataRecoveryHandler::GetNormalDocumentTitle](#getnormaldocumenttitle)|Recupera o título normal do documento especificado.|
|[CDataRecoveryHandler::GetRecoveredDocumentTitle](#getrecovereddocumenttitle)|Cria e retorna o título do documento recuperado.|
|[CDataRecoveryHandler::GetRestartIdentifier](#getrestartidentifier)|Recupera o identificador de reinicialização exclusivo para o aplicativo.|
|[CDataRecoveryHandler::GetSaveDocumentInfoOnIdle](#getsavedocumentinfoonidle)|Indica se o `CDataRecoveryHandler` executa um salvamento automático no loop ocioso atual.|
|[CDataRecoveryHandler::GetShutdownByRestartManager](#getshutdownbyrestartmanager)|Indica se o Gerenciador de reinicialização fez com que o aplicativo fosse encerrado.|
|[CDataRecoveryHandler:: Initialize](#initialize)|Inicializa o `CDataRecoveryHandler`.|
|[CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments)|Exibe uma caixa de diálogo para o usuário de cada documento que o salvou com o `CDataRecoveryHandler` . A caixa de diálogo determina se o usuário deseja restaurar o documento salvo novamente.|
|[CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist)|Carrega a lista de documentos abertos do registro.|
|[CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo)|Remove o documento fornecido da lista de documentos abertos.|
|[CDataRecoveryHandler::ReopenPreviousDocuments](#reopenpreviousdocuments)|Abre os documentos abertos anteriormente.|
|[CDataRecoveryHandler::RestoreAutosavedDocuments](#restoreautosaveddocuments)|Restaura os documentos salvos novamente com base na entrada do usuário.|
|[CDataRecoveryHandler::SaveOpenDocumentList](#saveopendocumentlist)|Salva a lista atual de documentos abertos no registro do Windows.|
|[CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval)|Define o tempo entre os ciclos de salvamento automático em milissegundos.|
|[CDataRecoveryHandler::SetAutosavePath](#setautosavepath)|Define o diretório onde os arquivos salvos novamente são armazenados.|
|[CDataRecoveryHandler::SetRestartIdentifier](#setrestartidentifier)|Define o identificador de reinicialização exclusivo para esta instância do `CDataRecoveryHandler` .|
|[CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle)|Define se o `CDataRecoveryHandler` salva as informações do documento aberto no registro do Windows durante o ciclo de ociosidade atual.|
|[CDataRecoveryHandler::SetShutdownByRestartManager](#setshutdownbyrestartmanager)|Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.|
|[CDataRecoveryHandler::UpdateDocumentInfo](#updatedocumentinfo)|Atualiza as informações de um documento porque o usuário o salvou.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|m_bRestoringPreviousOpenDocs|Indica se o manipulador de recuperação de dados reabrirá documentos abertos anteriormente.|
|m_bSaveDocumentInfoOnIdle|Indica se o manipulador de recuperação de dados salva os documentos de novo no próximo loop ocioso.|
|m_bShutdownByRestartManager|Indica se o Gerenciador de reinicialização faz com que o aplicativo saia.|
|m_dwRestartManagerSupportFlags|Sinalizadores que indicam o suporte que o Gerenciador de reinicialização fornece para o aplicativo.|
|m_lstAutosavesToDelete|Uma lista de arquivos salvos novamente que não foram excluídos quando os documentos originais foram fechados. Quando o aplicativo é encerrado, o Gerenciador de reinicialização tenta excluir os arquivos novamente.|
|m_mapDocNameToAutosaveName|Um mapa dos nomes de documento para os nomes de arquivo salvos novamente.|
|m_mapDocNameToDocumentPtr|Um mapa dos nomes de documento para os ponteiros [CDocument](../../mfc/reference/cdocument-class.md) .|
|m_mapDocNameToRestoreBool|Um mapa dos nomes de documento para um parâmetro booliano que indica se o documento salvo por restauração deve ser restaurado.|
|m_mapDocumentPtrToDocName|Um mapa dos `CDocument` ponteiros para os nomes de documento.|
|m_mapDocumentPtrToDocTitle|Um mapa dos `CDocument` ponteiros para os títulos do documento. Esses títulos são usados para salvar arquivos.|
|m_nAutosaveInterval|Tempo em milissegundos entre as autosalvas.|
|m_nTimerID|O identificador do temporizador de salvamento automático.|
|m_strAutosavePath|O local onde os documentos salvos novamente são armazenados.|
|m_strRestartIdentifier|A representação de cadeia de caracteres de um GUID para o Gerenciador de reinicialização.|

## <a name="remarks"></a>Comentários

O Gerenciador de reinicialização usa a `CDataRecoveryHandler` classe para manter o controle de todos os documentos abertos e para o AutoSalvar conforme necessário. Para habilitar o salvamento automático, use o método [CDataRecoveryHandler:: SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle) . Esse método direciona o `CDataRecoveryHandler` para executar um salvamento automático no próximo loop ocioso. O Gerenciador de reinicialização chama `SetSaveDocumentInfoOnIdle` quando o `CDataRecoveryHandler` deve executar um salvamento automático.

Todos os métodos da `CDataRecoveryHandler` classe são virtuais. Substitua os métodos nesta classe para criar seu próprio manipulador de recuperação de dados personalizado. A menos que você crie seu próprio manipulador de recuperação de dados ou o Gerenciador de reinicialização, não crie uma instância de CDataRecoveryHandler. A [classe CWinApp](../../mfc/reference/cwinapp-class.md) cria um `CDataRecoveryHandler` objeto conforme necessário.

Antes de poder usar um `CDataRecoveryHandler` objeto, você deve chamar [CDataRecoveryHandler:: Initialize](#initialize).

Como a `CDataRecoveryHandler` classe está fortemente conectada ao Gerenciador de reinicialização, `CDataRecoveryHandler` depende do parâmetro global `m_dwRestartManagerSupportFlags` . Esse parâmetro determina quais permissões o Gerenciador de reinicialização tem e como ele interage com seu aplicativo. Para incorporar o Gerenciador de reinicialização em um aplicativo existente, você precisa atribuir `m_dwRestartManagerSupportFlags` o valor apropriado no construtor do aplicativo principal. Para obter mais informações sobre como usar o Gerenciador de reinicialização, consulte [como adicionar o suporte ao Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdatarecovery. h

## <a name="cdatarecoveryhandlerautosavealldocumentinfo"></a><a name="autosavealldocumentinfo"></a> CDataRecoveryHandler::AutosaveAllDocumentInfo

Salva o salvamento de cada arquivo registrado com a `CDataRecoveryHandler` classe.

```
virtual BOOL AutosaveAllDocumentInfo();
```

### <a name="return-value"></a>Valor retornado

TRUE se o `CDataRecoveryHandler` salvar todos os documentos; FALSE se algum documento não tiver sido salvo.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se não houver nenhum documento que deva ser salvo. Ele também retorna TRUE sem salvar nenhum documento se a recuperação do `CWinApp` ou do `CDocManager` para o aplicativo gerar um erro.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL devem ser definidos em `m_dwRestartManagerSupportFlags` . Para obter mais informações, consulte [como: Adicionar o suporte ao Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).

## <a name="cdatarecoveryhandlerautosavedocumentinfo"></a><a name="autosavedocumentinfo"></a> CDataRecoveryHandler::AutosaveDocumentInfo

Salva o documento especificado.

```
virtual BOOL AutosaveDocumentInfo(
    CDocument* pDocument,
    BOOL bResetModifiedFlag = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para o `CDocument` a ser salvo.

*bResetModifiedFlag*\
no VERDADEIRO indica que o `CDataRecoveryHandler` considera *pDocument* a ser modificado; FALSE indica que a estrutura considera *pDocument* como não modificado. Consulte a seção comentários para obter mais informações sobre o efeito desse sinalizador.

### <a name="return-value"></a>Valor retornado

TRUE se os sinalizadores apropriados forem definidos e *pDocument* for um `CDocument` objeto válido.

### <a name="remarks"></a>Comentários

Cada `CDocument` objeto tem um sinalizador que indica se ele foi alterado desde a última gravação. Use [CDocument:: IsModified](../../mfc/reference/cdocument-class.md#ismodified) para determinar o estado desse sinalizador. Se um `CDocument` não tiver sido alterado desde o último salvamento, o `AutosaveDocumentInfo` excluirá todos os arquivos salvos novamente para esse documento. Se um documento tiver sido alterado desde a última gravação, fechar ele solicitará que o usuário salve o documento antes de fechá-lo.

> [!NOTE]
> Usar *bResetModifiedFlag* para alterar o estado do documento para não modificado pode fazer com que o usuário perca dados não salvos. Se a estrutura considerar um documento não modificado, fechá-lo não solicitará que o usuário salve.

Esse método gera uma exceção com a macro [Assert](diagnostic-services.md#assert) se *pDocument* não for um `CDocument` objeto válido.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL devem ser definidas em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlercdatarecoveryhandler"></a><a name="cdatarecoveryhandler"></a> CDataRecoveryHandler::CDataRecoveryHandler

Constrói um objeto `CDataRecoveryHandler`.

```
CDataRecoveryHandler(
    DWORD dwRestartManagerSupportFlags,
    int nAutosaveInterval);
```

### <a name="parameters"></a>Parâmetros

*dwRestartManagerSupportFlags*\
no Indica quais opções do Gerenciador de reinicialização têm suporte.

*nAutosaveInterval*\
no O tempo entre as autosalvas. Esse parâmetro está em milissegundos.

### <a name="remarks"></a>Comentários

A estrutura do MFC cria automaticamente um `CDataRecoveryHandler` objeto para seu aplicativo quando você usa o assistente de **novo projeto** . A menos que você esteja Personalizando o comportamento de recuperação de dados ou o Gerenciador de reinicialização, não crie um `CDataRecoveryHandler` objeto.

## <a name="cdatarecoveryhandlercreatedocumentinfo"></a><a name="createdocumentinfo"></a> CDataRecoveryHandler::CreateDocumentInfo

Adiciona um documento à lista de documentos abertos.

```
virtual BOOL CreateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para um `CDocument` . Esse método cria as informações do documento para isso `CDocument` .

### <a name="return-value"></a>Valor retornado

A implementação padrão retorna TRUE.

### <a name="remarks"></a>Comentários

Esse método verifica se *pDocument* já está na lista de documentos antes de adicionar o documento. Se *pDocument* já estiver na lista, esse método excluirá o arquivo autosalvo associado ao *pDocument*.

Para usar esse método, AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART ou AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL devem ser definidas em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlerdeleteallautosavedfiles"></a><a name="deleteallautosavedfiles"></a> CDataRecoveryHandler::D eleteAllAutosavedFiles

Exclui todos os arquivos autosalvos atuais.

```
virtual BOOL DeleteAllAutosavedFiles();
```

### <a name="return-value"></a>Valor retornado

A implementação padrão sempre retorna TRUE.

## <a name="cdatarecoveryhandlerdeleteautosavedfile"></a><a name="deleteautosavedfile"></a> CDataRecoveryHandler::D eleteAutosavedFile

Exclui o arquivo autosalvo especificado.

```
virtual BOOL DeleteAutosavedFile(const CString& strAutosavedFile);
```

### <a name="parameters"></a>Parâmetros

*strAutosavedFile*\
no Uma cadeia de caracteres que contém o nome do arquivo salvo novamente.

### <a name="return-value"></a>Valor retornado

A implementação padrão sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Se esse método não puder excluir o arquivo salvo novamente, ele salvará o nome do arquivo em uma lista. O destruidor para o `CDataRecoveryHandler` tenta excluir cada arquivo autosalvo especificado na lista.

## <a name="cdatarecoveryhandlergenerateautosavefilename"></a><a name="generateautosavefilename"></a> CDataRecoveryHandler::GenerateAutosaveFileName

Gera o nome de um arquivo de salvamento automático associado ao nome de arquivo de documento fornecido.

```
virtual CString GenerateAutosaveFileName(const CString& strDocumentName) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentName*<br/>
no Uma cadeia de caracteres que contém o nome do documento. `GenerateAutosaveFileName` usa este nome de documento para gerar um nome de arquivo de salvamento automático correspondente.

### <a name="return-value"></a>Valor retornado

O nome do arquivo de salvamento automático gerado a partir de *strDocumentName*.

### <a name="remarks"></a>Comentários

Cada nome de documento tem um mapeamento um-para-um com um nome de arquivo de salvamento automático.

## <a name="cdatarecoveryhandlergetautosaveinterval"></a><a name="getautosaveinterval"></a> CDataRecoveryHandler::GetAutosaveInterval

Retorna o intervalo entre as tentativas de salvamento automático.

```
virtual int GetAutosaveInterval() const;
```

### <a name="return-value"></a>Valor retornado

O número de milissegundos entre as tentativas de salvamento automático.

## <a name="cdatarecoveryhandlergetautosavepath"></a><a name="getautosavepath"></a> CDataRecoveryHandler::GetAutosavePath

Retorna o caminho dos arquivos salvos novamente.

```
virtual CString GetAutosavePath() const;
```

### <a name="return-value"></a>Valor retornado

O local onde os documentos salvos novamente são armazenados.

## <a name="cdatarecoveryhandlergetdocumentlistname"></a><a name="getdocumentlistname"></a> CDataRecoveryHandler::GetDocumentListName

Recupera o nome do documento de um `CDocument` objeto.

```
virtual CString GetDocumentListName(CDocument* pDocument) const;
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para um `CDocument` . `GetDocumentListName` Recupera o nome do documento a partir deste `CDocument` .

### <a name="return-value"></a>Valor retornado

O nome do documento de *pDocument*.

### <a name="remarks"></a>Comentários

O `CDataRecoveryHandler` usa o nome do documento como a chave em *m_mapDocNameToAutosaveName*, *m_mapDocNameToDocumentPtr*e *m_mapDocNameToRestoreBool*. Esses parâmetros permitem `CDataRecoveryHandler` que o monitore `CDocument` objetos, o nome do arquivo de salvamento automático e as configurações de salvamento automático.

## <a name="cdatarecoveryhandlergetnormaldocumenttitle"></a><a name="getnormaldocumenttitle"></a> CDataRecoveryHandler::GetNormalDocumentTitle

Recupera o título normal do documento especificado.

```
virtual CString GetNormalDocumentTitle(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para um `CDocument` .

### <a name="return-value"></a>Valor retornado

O título normal do documento especificado.

### <a name="remarks"></a>Comentários

O título normal de um documento geralmente é o nome do arquivo do documento sem o caminho. Esse é o título no campo **nome do arquivo** da caixa de diálogo **salvar como** .

## <a name="cdatarecoveryhandlergetrecovereddocumenttitle"></a><a name="getrecovereddocumenttitle"></a> CDataRecoveryHandler::GetRecoveredDocumentTitle

Cria e retorna o título do documento recuperado.

```
virtual CString GetRecoveredDocumentTitle(const CString& strDocumentTitle) const;
```

### <a name="parameters"></a>Parâmetros

*strDocumentTitle*<br/>
no O título normal do documento.

### <a name="return-value"></a>Valor retornado

O título do documento recuperado.

### <a name="remarks"></a>Comentários

Por padrão, o título recuperado de um documento é o título normal com **[recuperado]** acrescentado a ele. O título recuperado é exibido para o usuário quando o `CDataRecoveryHandler` consulta o usuário para restaurar documentos salvos novamente.

## <a name="cdatarecoveryhandlergetrestartidentifier"></a><a name="getrestartidentifier"></a> CDataRecoveryHandler::GetRestartIdentifier

Recupera o identificador de reinicialização exclusivo para o aplicativo.

```
virtual CString GetRestartIdentifier() const;
```

### <a name="return-value"></a>Valor retornado

O identificador de reinicialização exclusivo.

### <a name="remarks"></a>Comentários

O identificador de reinicialização é exclusivo para cada execução do aplicativo.

O `CDataRecoveryHandler` armazena informações no registro sobre os documentos abertos no momento. Quando o Gerenciador de reinicialização sai de um aplicativo e o reinicia, ele fornece o identificador de reinicialização para o `CDataRecoveryHandler` . O `CDataRecoveryHandler` usa o identificador de reinicialização para recuperar a lista de documentos abertos anteriormente. Isso permite que o `CDataRecoveryHandler` Tente localizar e restaurar arquivos autosalvos.

## <a name="cdatarecoveryhandlergetsavedocumentinfoonidle"></a><a name="getsavedocumentinfoonidle"></a> CDataRecoveryHandler::GetSaveDocumentInfoOnIdle

Indica se o `CDataRecoveryHandler` executa um salvamento automático no loop ocioso atual.

```
virtual BOOL GetSaveDocumentInfoOnIdle() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica as `CDataRecoveryHandler` salvações simultâneas no loop ocioso atual; FALSE indica que ele não faz isso.

## <a name="cdatarecoveryhandlergetshutdownbyrestartmanager"></a><a name="getshutdownbyrestartmanager"></a> CDataRecoveryHandler::GetShutdownByRestartManager

Indica se o Gerenciador de reinicialização fez com que o aplicativo fosse encerrado.

```
virtual BOOL GetShutdownByRestartManager() const;
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que o Gerenciador de reinicialização fez com que o aplicativo fosse encerrado; FALSE indica que não foi.

## <a name="cdatarecoveryhandlerinitialize"></a><a name="initialize"></a> CDataRecoveryHandler:: Initialize

Inicializa o `CDataRecoveryHandler`.

```
virtual BOOL Initialize();
```

### <a name="return-value"></a>Valor retornado

TRUE se a inicialização for bem-sucedida; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O processo de inicialização carrega o caminho para armazenar arquivos de salvamento automático do registro. Se o `Initialize` método não puder localizar esse diretório ou se o caminho for NULL, `Initialize` falhará e retornará `FALSE` .

Use [CDataRecoveryHandler:: SetAutosavePath](#setautosavepath) para alterar o caminho do salvamento automático depois que o aplicativo inicializar o `CDataRecoveryHandler` .

O `Initialize` método também inicia um temporizador para monitorar quando ocorre o próximo salvamento automático. Use [CDataRecoveryHandler:: SetAutosaveInterval](#setautosaveinterval) para alterar o intervalo de salvamento automático depois que o aplicativo inicializar o `CDataRecoveryHandler` .

## <a name="cdatarecoveryhandlerqueryrestoreautosaveddocuments"></a><a name="queryrestoreautosaveddocuments"></a> CDataRecoveryHandler::QueryRestoreAutosavedDocuments

Exibe uma caixa de diálogo para o usuário de cada documento que o salvou com o `CDataRecoveryHandler` . A caixa de diálogo determina se o usuário deseja restaurar o documento salvo novamente.

```
virtual void QueryRestoreAutosavedDocuments();
```

### <a name="remarks"></a>Comentários

Se seu aplicativo for Unicode, esse método exibirá um [CTaskDialog](../../mfc/reference/ctaskdialog-class.md) para o usuário. Caso contrário, a estrutura usará [AfxMessageBox](../../mfc/reference/cstring-formatting-and-message-box-display.md#afxmessagebox) para consultar o usuário.

Depois `QueryRestoreAutosavedDocuments` que o reúne todas as respostas do usuário, ele armazena as informações na variável de membro *m_mapDocNameToRestoreBool*. Esse método não restaura os documentos salvos novamente.

## <a name="cdatarecoveryhandlerreadopendocumentlist"></a><a name="readopendocumentlist"></a> CDataRecoveryHandler::ReadOpenDocumentList

Carrega a lista de documentos abertos do registro.

```
virtual BOOL ReadOpenDocumentList();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO indica que `ReadOpenDocumentList` o carregou as informações de pelo menos um documento do registro; FALSE indica que nenhuma informação de documento foi carregada.

### <a name="remarks"></a>Comentários

Essa função carrega as informações de documento aberto do registro e as armazena na variável de membro *m_mapDocNameToAutosaveName*.

Depois `ReadOpenDocumentList` que o carrega todos os dados, ele exclui as informações do documento do registro.

## <a name="cdatarecoveryhandlerremovedocumentinfo"></a><a name="removedocumentinfo"></a> CDataRecoveryHandler::RemoveDocumentInfo

Remove o documento fornecido da lista de documentos abertos.

```
virtual BOOL RemoveDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para o documento a ser removido.

### <a name="return-value"></a>Valor retornado

TRUE se *pDocument* tiver sido removido da lista; FALSE se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando o usuário fecha um documento, a estrutura usa esse método para removê-lo da lista de documentos abertos.

Se `RemoveDocumentInfo` não for possível localizar *pDocument* na lista de documentos abertos, ele não fará nada e retornará true.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*.

## <a name="cdatarecoveryhandlerreopenpreviousdocuments"></a><a name="reopenpreviousdocuments"></a> CDataRecoveryHandler::ReopenPreviousDocuments

Abre os documentos abertos anteriormente.

```
virtual BOOL ReopenPreviousDocuments();
```

### <a name="return-value"></a>Valor retornado

TRUE se pelo menos um documento foi aberto; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método abre a gravação mais recente dos documentos abertos anteriormente. Se um documento não foi salvo ou autosalvo, `ReopenPreviousDocuments` o abre um documento em branco com base no modelo para esse tipo de arquivo.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*. Se esse parâmetro não for definido, `ReopenPreviousDocuments` não fará nada e retornará false.

Se não houver nenhum documento armazenado na lista de documentos abertos anteriormente, `ReopenPreviousDocuments` o não fará nada e retornará false.

## <a name="cdatarecoveryhandlerrestoreautosaveddocuments"></a><a name="restoreautosaveddocuments"></a> CDataRecoveryHandler::RestoreAutosavedDocuments

Restaura os documentos salvos novamente com base na entrada do usuário.

```
virtual BOOL RestoreAutosavedDocuments();
```

### <a name="return-value"></a>Valor retornado

TRUE se esse método restaurar com êxito os documentos.

### <a name="remarks"></a>Comentários

Esse método chama [CDataRecoveryHandler:: QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments) para determinar quais documentos o usuário deseja restaurar. Se um usuário decidir não restaurar um documento salvo automaticamente, `RestoreAutosavedDocuments` o excluirá o arquivo de salvamento automático. Caso contrário, `RestoreAutosavedDocuments` o substitui o documento aberto pela versão salva.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES ou AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES devem ser definidos em `m_dwRestartManagerSupportFlags` .

## <a name="cdatarecoveryhandlersaveopendocumentlist"></a><a name="saveopendocumentlist"></a> CDataRecoveryHandler::SaveOpenDocumentList

Salva a lista atual de documentos abertos no registro do Windows.

```
virtual BOOL SaveOpenDocumentList();
```

### <a name="return-value"></a>Valor retornado

TRUE se não houver nenhum documento aberto para salvar ou se eles tiverem sido salvos com êxito. FALSE se houver documentos a serem salvos no registro, mas eles não foram salvos porque ocorreu um erro.

### <a name="remarks"></a>Comentários

O Gerenciador de reinicialização chama `SaveOpenDocumentList` quando o aplicativo sai inesperadamente ou quando ele sai para uma atualização. Quando o aplicativo é reiniciado, ele usa [CDataRecoveryHandler:: ReadOpenDocumentList](#readopendocumentlist) para recuperar a lista de documentos abertos.

Esse método salva apenas a lista de documentos abertos. O método [CDataRecoveryHandler:: AutosaveDocumentInfo](#autosavedocumentinfo) é responsável por salvar os próprios documentos.

## <a name="cdatarecoveryhandlersetautosaveinterval"></a><a name="setautosaveinterval"></a> CDataRecoveryHandler::SetAutosaveInterval

Define o tempo entre os ciclos de salvamento automático em milissegundos.

```
Virtual void SetAutosaveInterval(int nAutosaveInterval);
```

### <a name="parameters"></a>Parâmetros

*nAutosaveInterval*<br/>
no O novo intervalo de salvamento automático em milissegundos.

## <a name="cdatarecoveryhandlersetautosavepath"></a><a name="setautosavepath"></a> CDataRecoveryHandler::SetAutosavePath

Define o diretório onde os arquivos salvos novamente são armazenados.

```
virtual void SetAutosavePath(const CString& strAutosavePath);
```

### <a name="parameters"></a>Parâmetros

*strAutosavePath*\
no O caminho em que os arquivos de salvamento automático são armazenados.

### <a name="remarks"></a>Comentários

A alteração do diretório de salvamento automático não move os arquivos autosalvos no momento.

## <a name="cdatarecoveryhandlersetrestartidentifier"></a><a name="setrestartidentifier"></a> CDataRecoveryHandler::SetRestartIdentifier

Define o identificador de reinicialização exclusivo para esta instância do `CDataRecoveryHandler` .

```
virtual void SetRestartIdentifier(const CString& strRestartIdentifier);
```

### <a name="parameters"></a>Parâmetros

*strRestartIdentifier*\
no O identificador exclusivo para o Gerenciador de reinicialização.

### <a name="remarks"></a>Comentários

O Gerenciador de reinicialização registra informações sobre os documentos abertos no registro. Essas informações são armazenadas com o identificador de reinicialização exclusivo como a chave. Como o identificador de reinicialização é exclusivo para cada instância de um aplicativo, várias instâncias de um aplicativo podem ser encerradas inesperadamente e o Gerenciador de reinicialização pode recuperar cada uma delas.

## <a name="cdatarecoveryhandlersetsavedocumentinfoonidle"></a><a name="setsavedocumentinfoonidle"></a> CDataRecoveryHandler::SetSaveDocumentInfoOnIdle

Define se o `CDataRecoveryHandler` salva as informações do documento aberto no registro do Windows durante o ciclo de ociosidade atual.

```
virtual void SetSaveDocumentInfoOnIdle(BOOL bSaveOnIdle);
```

### <a name="parameters"></a>Parâmetros

*bSaveOnIdle*\
no TRUE para salvar as informações do documento durante o ciclo ocioso atual; FALSE para não executar um salvamento.

## <a name="cdatarecoveryhandlersetshutdownbyrestartmanager"></a><a name="setshutdownbyrestartmanager"></a> CDataRecoveryHandler::SetShutdownByRestartManager

Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.

```
virtual void SetShutdownByRestartManager(BOOL bShutdownByRestartManager);
```

### <a name="parameters"></a>Parâmetros

*bShutdownByRestartManager*\
no TRUE para indicar que o Gerenciador de reinicialização fez com que o aplicativo fosse encerrado; FALSE para indicar que o aplicativo foi encerrado por outro motivo.

### <a name="remarks"></a>Comentários

A estrutura se comporta de forma diferente, dependendo se a saída anterior era inesperada ou se foi iniciada pelo Gerenciador de reinicialização.

## <a name="cdatarecoveryhandlerupdatedocumentinfo"></a><a name="updatedocumentinfo"></a> CDataRecoveryHandler::UpdateDocumentInfo

Atualiza as informações de um documento porque o usuário o salvou.

```
virtual BOOL UpdateDocumentInfo(CDocument* pDocument);
```

### <a name="parameters"></a>Parâmetros

*pDocument*\
no Um ponteiro para o documento salvo.

### <a name="return-value"></a>Valor retornado

TRUE se esse método tiver excluído o documento salvo novamente e atualizado as informações do documento; FALSE se ocorreu um erro.

### <a name="remarks"></a>Comentários

Quando um usuário salva um documento, o aplicativo remove o arquivo salvo novamente porque ele não é mais necessário. `UpdateDocumentInfo` exclui o arquivo salvo novamente chamando [CDataRecoveryHandler:: RemoveDocumentInfo](#removedocumentinfo). `UpdateDocumentInfo` em seguida, adiciona as informações de *pDocument* à lista de documentos abertos no momento porque `RemoveDocumentInfo` exclui essas informações, mas o documento salvo ainda está aberto.

Para usar esse método, AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES deve ser definido em *m_dwRestartManagerSupportFlags*.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Como: Adicionar o suporte do Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)
