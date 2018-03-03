---
title: Classe CDataRecoveryHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 35ede62ddb5fcfbc32fec37322985d40fffbbe44
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdatarecoveryhandler-class"></a>Classe CDataRecoveryHandler
O `CDataRecoveryHandler` salve documentos e restaura-as se um aplicativo termina inesperadamente.  
  
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
|[CDataRecoveryHandler::AutosaveAllDocumentInfo](#autosavealldocumentinfo)|Salve cada arquivo registrado com o `CDataRecoveryHandler` classe.|  
|[CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo)|Salve o documento especificado.|  
|[CDataRecoveryHandler::CreateDocumentInfo](#createdocumentinfo)|Adiciona um documento à lista de documentos abertos.|  
|[CDataRecoveryHandler::DeleteAllAutosavedFiles](#deleteallautosavedfiles)|Exclui todos os arquivos atuais salva automaticamente.|  
|[CDataRecoveryHandler::DeleteAutosavedFile](#deleteautosavedfile)|Exclui o arquivo salva automaticamente especificado.|  
|[CDataRecoveryHandler::GenerateAutosaveFileName](#generateautosavefilename)|Gera o nome de um arquivo de salvamento automático associado com o nome de arquivo do documento fornecido.|  
|[CDataRecoveryHandler::GetAutosaveInterval](#getautosaveinterval)|Retorna o intervalo entre tentativas de salvamento automático.|  
|[CDataRecoveryHandler::GetAutosavePath](#getautosavepath)|Retorna o caminho dos arquivos salva automaticamente.|  
|[CDataRecoveryHandler::GetDocumentListName](#getdocumentlistname)|Recupera o nome do documento de um `CDocument` objeto.|  
|[CDataRecoveryHandler::GetNormalDocumentTitle](#getnormaldocumenttitle)|Recupera o título normal para o documento especificado.|  
|[CDataRecoveryHandler::GetRecoveredDocumentTitle](#getrecovereddocumenttitle)|Cria e retorna o título do documento recuperado.|  
|[CDataRecoveryHandler::GetRestartIdentifier](#getrestartidentifier)|Recupera o identificador exclusivo de reinicialização do aplicativo.|  
|[CDataRecoveryHandler::GetSaveDocumentInfoOnIdle](#getsavedocumentinfoonidle)|Indica se o `CDataRecoveryHandler` executa uma gravação automática em loop ocioso atual.|  
|[CDataRecoveryHandler::GetShutdownByRestartManager](#getshutdownbyrestartmanager)|Indica se o Gerenciador de reinicialização fez com que o aplicativo Sair.|  
|[CDataRecoveryHandler::Initialize](#initialize)|Inicializa o `CDataRecoveryHandler`.|  
|[CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments)|Exibe uma caixa de diálogo para o usuário para cada documento que a `CDataRecoveryHandler` salva automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salva automaticamente.|  
|[CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist)|Carrega a lista de documentos abertos no registro.|  
|[CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo)|Remove o documento fornecido da lista de documentos abertos.|  
|[CDataRecoveryHandler::ReopenPreviousDocuments](#reopenpreviousdocuments)|Abre os documentos abertos anteriormente.|  
|[CDataRecoveryHandler::RestoreAutosavedDocuments](#restoreautosaveddocuments)|Restaura os documentos salva automaticamente com base na entrada do usuário.|  
|[CDataRecoveryHandler::SaveOpenDocumentList](#saveopendocumentlist)|Salva a lista atual de documentos abertos no registro do Windows.|  
|[CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval)|Define o tempo entre os ciclos de salvamento automático em milissegundos.|  
|[CDataRecoveryHandler::SetAutosavePath](#setautosavepath)|Define o diretório onde salva automaticamente arquivos estão armazenados.|  
|[CDataRecoveryHandler::SetRestartIdentifier](#setrestartidentifier)|Define o identificador exclusivo de reinicialização para esta instância do `CDataRecoveryHandler`.|  
|[CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle)|Define se o `CDataRecoveryHandler` salva as informações do documento aberto no registro do Windows durante o ciclo de ociosidade atual.|  
|[CDataRecoveryHandler::SetShutdownByRestartManager](#setshutdownbyrestartmanager)|Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.|  
|[CDataRecoveryHandler::UpdateDocumentInfo](#updatedocumentinfo)|Atualiza as informações de um documento porque o usuário salvá-lo.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|m_bRestoringPreviousOpenDocs|Indica se o manipulador de recuperação de dados é reaberto documentos abertos anteriormente.|  
|m_bSaveDocumentInfoOnIdle|Indica se o salve de manipulador de recuperação de dados de documentos no próximo loop ocioso.|  
|m_bShutdownByRestartManager|Indica se o Gerenciador de reinicialização faz com que o aplicativo Sair.|  
|m_dwRestartManagerSupportFlags|Fornecem os sinalizadores que indicam que suporte o Gerenciador de reinicialização do aplicativo.|  
|m_lstAutosavesToDelete|Uma lista de arquivos salva automaticamente que não foram excluídos quando os documentos originais foram fechados. Quando o aplicativo termina, as tentativas de Gerenciador de reinicialização excluindo os arquivos.|  
|m_mapDocNameToAutosaveName|Um mapa dos nomes de documento para os nomes de arquivo salva automaticamente.|  
|m_mapDocNameToDocumentPtr|Um mapa dos nomes de documento para o [CDocument](../../mfc/reference/cdocument-class.md) ponteiros.|  
|m_mapDocNameToRestoreBool|Um mapa dos nomes de documento para um parâmetro booliano que indica se deve restaurar o documento salva automaticamente.|  
|m_mapDocumentPtrToDocName|Um mapa do `CDocument` ponteiros para os nomes de documento.|  
|m_mapDocumentPtrToDocTitle|Um mapa do `CDocument` ponteiros para os títulos do documento. Esses títulos são usados para salvar os arquivos.|  
|m_nAutosaveInterval|Tempo em milissegundos, entre salve.|  
|m_nTimerID|O identificador para o timer de salvamento automático.|  
|m_strAutosavePath|O local de armazenamento de documentos salva automaticamente.|  
|m_strRestartIdentifier|A representação de cadeia de caracteres de um GUID para o Gerenciador de reinicialização.|  
  
## <a name="remarks"></a>Comentários  
 O Gerenciador de reinicialização usa o `CDataRecoveryHandler` classe para manter o controle de todos os documentos abertos e salvamento automático-los conforme necessário. Para habilitar o salvamento automático, use o [CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](#setsavedocumentinfoonidle) método. Este método direciona o `CDataRecoveryHandler` para executar um salvamento automático no próximo loop ocioso. As chamadas de Gerenciador de reinicialização `SetSaveDocumentInfoOnIdle` quando o `CDataRecoveryHandler` devem executar um salvamento automático.  
  
 Todos os métodos do `CDataRecoveryHandler` classe são virtuais. Substitua os métodos dessa classe para criar seu próprio manipulador de recuperação de dados personalizados. A menos que você cria seu próprio manipulador de recuperação de dados ou Gerenciador de reinicialização, não criar uma instância de um CDataRecoveryHandler. O [classe CWinApp](../../mfc/reference/cwinapp-class.md) cria um `CDataRecoveryHandler` objeto conforme necessário.  
  
 Antes de usar um `CDataRecoveryHandler` do objeto, você deve chamar [CDataRecoveryHandler::Initialize](#initialize).  
  
 Porque o `CDataRecoveryHandler` classe está conectada em conjunto para o Gerenciador de reinicialização, `CDataRecoveryHandler` depende do parâmetro global `m_dwRestartManagerSupportFlags`. Esse parâmetro determina quais permissões o Gerenciador de reinicialização tem e como ele interage com seu aplicativo. Para incorporar o Gerenciador de reinicialização para um aplicativo existente, você precisa atribuir `m_dwRestartManagerSupportFlags` o valor apropriado no construtor do aplicativo principal. Para obter mais informações sobre como usar o Gerenciador de reinicialização, consulte [como: adicionar suporte de Gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdatarecovery.h  
  
##  <a name="autosavealldocumentinfo"></a>CDataRecoveryHandler::AutosaveAllDocumentInfo  
 Salve cada arquivo registrado com o `CDataRecoveryHandler` classe.  
  
```  
virtual BOOL AutosaveAllDocumentInfo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o `CDataRecoveryHandler` salva todos os documentos; `FALSE` se qualquer documento não foi salvo.  
  
### <a name="remarks"></a>Comentários  
 Este método retorna `TRUE` se não houver documentos não devem ser salvas. Ele também retorna `TRUE` sem salvar todos os documentos se recuperando o `CWinApp` ou `CDocManager` para o aplicativo gera um erro.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART` ou `AFX_RESTART_MANAGER_AUTOSAVE_AT_INTERVAL` deve ser definido em `m_dwRestartManagerSupportFlags`. Consulte [m_dwRestartManagerSupportFlags](#m_dwrestartmanagersupportflags) para obter mais informações.  
  
##  <a name="autosavedocumentinfo"></a>CDataRecoveryHandler::AutosaveDocumentInfo  
 Salve o documento especificado.  
  
```  
virtual BOOL AutosaveDocumentInfo(
    CDocument* pDocument,  
    BOOL bResetModifiedFlag = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para o `CDocument` para salvar.|  
|[in] `bResetModifiedFlag`|`TRUE`indica que o `CDataRecoveryHandler` considera `pDocument` a ser modificada; `FALSE` indica que a estrutura considera `pDocument` ser modificados. Consulte a seção de comentários para obter mais informações sobre o efeito do sinalizador.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se os sinalizadores apropriados são definidos e `pDocument` é válido `CDocument` objeto.  
  
### <a name="remarks"></a>Comentários  
 Cada `CDocument` objeto tem um sinalizador que indica se ele foi alterado desde a última gravação. Use [CDocument::IsModified](../../mfc/reference/cdocument-class.md#ismodified) para determinar o estado do sinalizador. Se um `CDocument` não foi alterado desde a última gravação, `AutosaveDocumentInfo` exclui todos os arquivos salva automaticamente para o documento. Se um documento foi alterado desde o último salvamento, fechá-lo solicita que o usuário salve o documento antes de fechar.  
  
> [!NOTE]
>  Usando `bResetModifiedFlag` alterar o estado do documento para não modificado pode fazer com que o usuário perder dados não salvos. Se a estrutura considera um documento sem modificações, fechá-lo não solicita ao usuário para salvar.  
  
 Esse método lançará uma exceção com o [ASSERT](diagnostic-services.md#assert) macro se `pDocument` não é válido `CDocument` objeto.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART` ou `AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL` deve ser definido em `m_dwRestartManagerSupportFlags`.   
  
##  <a name="cdatarecoveryhandler"></a>CDataRecoveryHandler::CDataRecoveryHandler  
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
|[in] `dwRestartManagerSupportFlags`|Indica quais opções do Gerenciador de reinicialização são suportadas.|  
|[in] `nAutosaveInterval`|O tempo entre a salve. Esse parâmetro é em milissegundos.|  
  
### <a name="remarks"></a>Comentários  
 A estrutura MFC cria automaticamente um `CDataRecoveryHandler` objeto para seu aplicativo quando você usa o **novo projeto** assistente. A menos que você estiver personalizando o comportamento de recuperação de dados ou o Gerenciador de reinicialização, você não deve criar um `CDataRecoveryHandler` objeto.  
  
  
##  <a name="createdocumentinfo"></a>CDataRecoveryHandler::CreateDocumentInfo  
 Adiciona um documento à lista de documentos abertos.  
  
```  
virtual BOOL CreateDocumentInfo(CDocument* pDocument);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para um `CDocument`. Esse método cria as informações do documento para este `CDocument`.|  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão retorna `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Este método verifica se `pDocument` já está na lista de documentos antes de adicionar o documento. Se `pDocument` já está na lista, este método exclui o arquivo salva automaticamente associado `pDocument`.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_AUTOSAVE_AT_RESTART` ou `AFX_RESTARTMANAGER_AUTOSAVE_AT_INTERVAL` deve ser definido em `m_dwRestartManagerSupportFlags`. 
  
##  <a name="deleteallautosavedfiles"></a>CDataRecoveryHandler::DeleteAllAutosavedFiles  
 Exclui todos os arquivos atuais salva automaticamente.  
  
```  
virtual BOOL DeleteAllAutosavedFiles();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão sempre retorna `TRUE`.  
  
##  <a name="deleteautosavedfile"></a>CDataRecoveryHandler::DeleteAutosavedFile  
 Exclui o arquivo salva automaticamente especificado.  
  
```  
virtual BOOL DeleteAutosavedFile(const CString& strAutosavedFile);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `strAutosavedFile`|Uma cadeia de caracteres que contém o nome de arquivo salva automaticamente.|  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação padrão sempre retornam `TRUE`.  
  
### <a name="remarks"></a>Comentários  
 Se esse método não é possível excluir o arquivo salva automaticamente, ele salva o nome do arquivo em uma lista. O destruidor para o `CDataRecoveryHandler` tenta excluir cada arquivo salva automaticamente especificado na lista.  
  
##  <a name="generateautosavefilename"></a>CDataRecoveryHandler::GenerateAutosaveFileName  
 Gera o nome de um arquivo de salvamento automático associado com o nome de arquivo do documento fornecido.  
  
```  
virtual CString GenerateAutosaveFileName(const CString& strDocumentName) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strDocumentName`  
 Uma cadeia de caracteres que contém o nome do documento. `GenerateAutosaveFileName`usa esse nome de documento para gerar um nome de arquivo de salvamento automático correspondente.  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do arquivo de salvamento automático gerado a partir de `strDocumentName`.  
  
### <a name="remarks"></a>Comentários  
 Nome de cada documento tem um mapeamento um para um com um nome de arquivo de salvamento automático.  
  
##  <a name="getautosaveinterval"></a>CDataRecoveryHandler::GetAutosaveInterval  
 Retorna o intervalo entre tentativas de salvamento automático.  
  
```  
virtual int GetAutosaveInterval() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de milissegundos entre o salvamento automático tenta.  
  
##  <a name="getautosavepath"></a>CDataRecoveryHandler::GetAutosavePath  
 Retorna o caminho dos arquivos salva automaticamente.  
  
```  
virtual CString GetAutosavePath() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O local de armazenamento de documentos salva automaticamente.  
  
##  <a name="getdocumentlistname"></a>CDataRecoveryHandler::GetDocumentListName  
 Recupera o nome do documento de um `CDocument` objeto.  
  
```  
virtual CString GetDocumentListName(CDocument* pDocument) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para um `CDocument`. `GetDocumentListName`recupera o nome do documento neste `CDocument`.|  
  
### <a name="return-value"></a>Valor de retorno  
 O nome do documento de `pDocument`.  
  
### <a name="remarks"></a>Comentários  
 O `CDataRecoveryHandler` usa o nome do documento como a chave em `m_mapDocNameToAutosaveName`, `m_mapDocNameToDocumentPtr`, e `m_mapDocNameToRestoreBool`. Esses parâmetros permitem a `CDataRecoveryHandler` para monitorar `CDocument` objetos, o nome do arquivo de salvamento automático e as configurações de salvamento automático.  
  
##  <a name="getnormaldocumenttitle"></a>CDataRecoveryHandler::GetNormalDocumentTitle  
 Recupera o título normal para o documento especificado.  
  
```  
virtual CString GetNormalDocumentTitle(CDocument* pDocument);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para um `CDocument`.|  
  
### <a name="return-value"></a>Valor de retorno  
 O título normal para o documento especificado.  
  
### <a name="remarks"></a>Comentários  
 O título normal de um documento geralmente é o nome do arquivo do documento sem o caminho. Este é o título no **nome de arquivo** campo o **Salvar como** caixa de diálogo.  
  
##  <a name="getrecovereddocumenttitle"></a>CDataRecoveryHandler::GetRecoveredDocumentTitle  
 Cria e retorna o título do documento recuperado.  
  
```  
virtual CString GetRecoveredDocumentTitle(const CString& strDocumentTitle) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strDocumentTitle`  
 O título normal para o documento.  
  
### <a name="return-value"></a>Valor de retorno  
 O título do documento recuperado.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, o título recuperado de um documento é o título normal com **[Recuperado]** anexadas a ele. O título recuperado é exibido ao usuário quando o `CDataRecoveryHandler` consulta o usuário para restaurar documentos salva automaticamente.  
  
##  <a name="getrestartidentifier"></a>CDataRecoveryHandler::GetRestartIdentifier  
 Recupera o identificador exclusivo de reinicialização do aplicativo.  
  
```  
virtual CString GetRestartIdentifier() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador exclusivo de reinicialização.  
  
### <a name="remarks"></a>Comentários  
 O identificador de reinicialização é exclusivo para cada execução do aplicativo.  
  
 O `CDataRecoveryHandler` armazena informações no registro sobre os documentos abertos. Quando o Gerenciador de reinicialização sai de um aplicativo e o reinicia, ele fornece o identificador de reinício para o `CDataRecoveryHandler`. O `CDataRecoveryHandler` usa o identificador de reinicialização para recuperar a lista de documentos abertos anteriormente. Isso permite que o `CDataRecoveryHandler` para tentar localizar e restaurar arquivos salva automaticamente.  
  
##  <a name="getsavedocumentinfoonidle"></a>CDataRecoveryHandler::GetSaveDocumentInfoOnIdle  
 Indica se o `CDataRecoveryHandler` executa uma gravação automática em loop ocioso atual.  
  
```  
virtual BOOL GetSaveDocumentInfoOnIdle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica o `CDataRecoveryHandler` salve no loop ocioso atual; `FALSE` indica que não.  
  
##  <a name="getshutdownbyrestartmanager"></a>CDataRecoveryHandler::GetShutdownByRestartManager  
 Indica se o Gerenciador de reinicialização fez com que o aplicativo Sair.  
  
```  
virtual BOOL GetShutdownByRestartManager() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que o Gerenciador de reinicialização fez com que o aplicativo Sair; `FALSE` indica não funcionou.  
  
##  <a name="initialize"></a>CDataRecoveryHandler::Initialize  
 Inicializa o `CDataRecoveryHandler`.  
  
```  
virtual BOOL Initialize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a inicialização for bem-sucedida; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 O processo de inicialização carrega o caminho para armazenar arquivos de salvamento automático do registro. Se o `Initialize` método não é possível encontrar este diretório ou se o caminho é `NULL`, `Initialize` falhará e retornará `FALSE`.  
  
 Use [CDataRecoveryHandler::SetAutosavePath](#setautosavepath) para alterar o caminho de salvamento automático depois que seu aplicativo inicializa o `CDataRecoveryHandler`.  
  
 O `Initialize` método também inicia um temporizador para monitorar quando ocorre o salvamento automático Avançar. Use [CDataRecoveryHandler::SetAutosaveInterval](#setautosaveinterval) para alterar o intervalo de salvamento automático depois que seu aplicativo inicializa o `CDataRecoveryHandler`.  
  
##  <a name="queryrestoreautosaveddocuments"></a>CDataRecoveryHandler::QueryRestoreAutosavedDocuments  
 Exibe uma caixa de diálogo para o usuário para cada documento que a `CDataRecoveryHandler` salva automaticamente. A caixa de diálogo determina se o usuário deseja restaurar o documento salva automaticamente.  
  
```  
virtual void QueryRestoreAutosavedDocuments();
```  
  
### <a name="remarks"></a>Comentários  
 Se seu aplicativo for Unicode, esse método exibirá uma [CTaskDialog](../../mfc/reference/ctaskdialog-class.md) para o usuário. Caso contrário, a estrutura usa [AfxMessageBox](../../mfc/reference/cstring-formatting-and-message-box-display.md#afxmessagebox) para consultar o usuário.  
  
 Depois de `QueryRestoreAutosavedDocuments` reúne todas as respostas do usuário, ele armazena as informações na variável de membro `m_mapDocNameToRestoreBool`. Esse método não restaura os documentos salva automaticamente.  
  
##  <a name="readopendocumentlist"></a>CDataRecoveryHandler::ReadOpenDocumentList  
 Carrega a lista de documentos abertos no registro.  
  
```  
virtual BOOL ReadOpenDocumentList();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`indica que `ReadOpenDocumentList` carregar as informações de pelo menos um documento do registro. `FALSE` indica que nenhuma informação de documento foi carregada.  
  
### <a name="remarks"></a>Comentários  
 Essa função carrega as informações do documento aberto do registro e o armazena na variável de membro `m_mapDocNameToAutosaveName`.  
  
 Depois de `ReadOpenDocumentList` carrega todos os dados, ele exclui as informações do documento do registro.  
  
##  <a name="removedocumentinfo"></a>CDataRecoveryHandler::RemoveDocumentInfo  
 Remove o documento fornecido da lista de documentos abertos.  
  
```  
virtual BOOL RemoveDocumentInfo(CDocument* pDocument);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para o documento a ser removido.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se `pDocument` foi removido da lista; `FALSE` se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário fecha um documento, a estrutura usa esse método para removê-lo da lista de documentos abertos.  
  
 Se `RemoveDocumentInfo` não é possível localizar `pDocument` na lista de documentos abertos, ele não faz nada e retorna `TRUE`.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES` deve ser definido em `m_dwRestartManagerSupportFlags`.   
  
##  <a name="reopenpreviousdocuments"></a>CDataRecoveryHandler::ReopenPreviousDocuments  
 Abre os documentos abertos anteriormente.  
  
```  
virtual BOOL ReopenPreviousDocuments();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se pelo menos um documento for aberto; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 Este método abre o salvamento mais recente dos documentos abertos anteriormente. Se um documento não foi salvo ou salva automaticamente, `ReopenPreviousDocuments` abre um documento em branco baseado no modelo para esse tipo de arquivo.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES` deve ser definido em `m_dwRestartManagerSupportFlags`. Se esse parâmetro não for definido, `ReopenPreviousDocuments` não faz nada e retorna `FALSE`.  
  
 Se não há documentos armazenados na lista de documentos abertos anteriormente `ReopenPreviousDocuments` não faz nada e retorna `FALSE`.  
  
##  <a name="restoreautosaveddocuments"></a>CDataRecoveryHandler::RestoreAutosavedDocuments  
 Restaura os documentos salva automaticamente com base na entrada do usuário.  
  
```  
virtual BOOL RestoreAutosavedDocuments();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método com êxito restaura os documentos.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [CDataRecoveryHandler::QueryRestoreAutosavedDocuments](#queryrestoreautosaveddocuments) determinar quais documentos que o usuário deseja restaurar. Se um usuário decidir não restaurar um documento, e salva automaticamente `RestoreAutosavedDocuments` exclui o arquivo de salvamento automático. Caso contrário, `RestoreAutosavedDocuments` substitui o documento aberto com a versão salva automaticamente.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES` ou `AFX_RESTART_MANAGER_RESTORE_AUTOSAVED_FILES` deve ser definido em `m_dwRestartManagerSupportFlags`.   
  
##  <a name="saveopendocumentlist"></a>CDataRecoveryHandler::SaveOpenDocumentList  
 Salva a lista atual de documentos abertos no registro do Windows.  
  
```  
virtual BOOL SaveOpenDocumentList();
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se não houver nenhum documentos abertos para salvar ou se eles foram salvas com êxito. `FALSE`Se houver documentos para salvar o registro, mas não foram salvas porque ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 As chamadas de Gerenciador de reinicialização `SaveOpenDocumentList` quando o aplicativo termina inesperadamente ou quando ele sai de uma atualização. Quando o aplicativo for reiniciado, ele usa [CDataRecoveryHandler::ReadOpenDocumentList](#readopendocumentlist) para recuperar a lista de documentos abertos.  
  
 Esse método salva apenas a lista de documentos abertos. O método [CDataRecoveryHandler::AutosaveDocumentInfo](#autosavedocumentinfo) é responsável por salvar os documentos em si.  
  
##  <a name="setautosaveinterval"></a>CDataRecoveryHandler::SetAutosaveInterval  
 Define o tempo entre os ciclos de salvamento automático em milissegundos.  
  
```  
Virtual void SetAutosaveInterval(int nAutosaveInterval);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nAutosaveInterval`  
 O novo intervalo de salvamento automático em milissegundos.  
  
##  <a name="setautosavepath"></a>CDataRecoveryHandler::SetAutosavePath  
 Define o diretório onde salva automaticamente arquivos estão armazenados.  
  
```  
virtual void SetAutosavePath(const CString& strAutosavePath);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `strAutosavePath`|O caminho onde os arquivos de salvamento automático são armazenados.|  
  
### <a name="remarks"></a>Comentários  
 Alterar o diretório de salvamento automático não move atualmente salva automaticamente arquivos.  
  
##  <a name="setrestartidentifier"></a>CDataRecoveryHandler::SetRestartIdentifier  
 Define o identificador exclusivo de reinicialização para esta instância do `CDataRecoveryHandler`.  
  
```  
virtual void SetRestartIdentifier(const CString& strRestartIdentifier);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `strRestartIdentifier`|O identificador exclusivo para o Gerenciador de reinicialização.|  
  
### <a name="remarks"></a>Comentários  
 O Gerenciador de reinicialização registra informações sobre os documentos abertos no registro. Essa informação é armazenada com o identificador exclusivo de reinicialização como a chave. Como o identificador de reinicialização é exclusivo para cada instância de um aplicativo, várias instâncias de um aplicativo podem ser encerrado inesperadamente e o Gerenciador de reinicialização pode recuperar cada um deles.  
  
##  <a name="setsavedocumentinfoonidle"></a>CDataRecoveryHandler::SetSaveDocumentInfoOnIdle  
 Define se o `CDataRecoveryHandler` salva as informações do documento aberto no registro do Windows durante o ciclo de ociosidade atual.  
  
```  
virtual void SetSaveDocumentInfoOnIdle(BOOL bSaveOnIdle);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `bSaveOnIdle`|`TRUE`Para salvar as informações do documento durante o ciclo de ociosidade atual; `FALSE to not perform a save`.|  
  
##  <a name="setshutdownbyrestartmanager"></a>CDataRecoveryHandler::SetShutdownByRestartManager  
 Define se a saída anterior do aplicativo foi causada pelo Gerenciador de reinicialização.  
  
```  
virtual void SetShutdownByRestartManager(BOOL bShutdownByRestartManager);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `bShutdownByRestartManager`|`TRUE`para indicar que o Gerenciador de reinicialização fez com que o aplicativo Sair; `FALSE` para indicar que o aplicativo foi encerrado por outro motivo.|  
  
### <a name="remarks"></a>Comentários  
 A estrutura se comporta de maneira diferente com base em se a saída anterior era esperada ou se ele foi iniciado pelo Gerenciador de reinicialização.  
  
##  <a name="updatedocumentinfo"></a>CDataRecoveryHandler::UpdateDocumentInfo  
 Atualiza as informações de um documento porque o usuário salvá-lo.  
  
```  
virtual BOOL UpdateDocumentInfo(CDocument* pDocument);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `pDocument`|Um ponteiro para o documento salvo.|  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se esse método excluído o documento salva automaticamente e atualizar as informações do documento; `FALSE` se ocorreu um erro.  
  
### <a name="remarks"></a>Comentários  
 Quando um usuário salva um documento, o aplicativo remove o arquivo salva automaticamente porque ele não é mais necessário. `UpdateDocumentInfo`Exclui o arquivo salva automaticamente chamando [CDataRecoveryHandler::RemoveDocumentInfo](#removedocumentinfo). `UpdateDocumentInfo`em seguida, adiciona as informações de `pDocument` à lista de atualmente documentos abertos porque `RemoveDocumentInfo` exclui essas informações, mas o salvo documento ainda está aberto.  
  
 Para usar esse método, `AFX_RESTART_MANAGER_REOPEN_PREVIOUS_FILES` deve ser definido em `m_dwRestartManagerSupportFlags`.   
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)

