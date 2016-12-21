---
title: "Classe de CDataRecoveryHandler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CDataRecoveryHandler"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDataRecoveryHandler"
ms.assetid: 7794802c-e583-4eba-90b9-2fed1a161f9c
caps.latest.revision: 18
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDataRecoveryHandler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CDataRecoveryHandler` autosaves documentos e restaurar\-los se um aplicativo é encerrado inesperado.  
  
## Sintaxe  
  
```  
class CDataRecoveryHandler : public CObject  
```  
  
## Membros  
  
### Construtores  
  
|||  
|-|-|  
|[CDataRecoveryHandler::CDataRecoveryHandler](../Topic/CDataRecoveryHandler::CDataRecoveryHandler.md)|Constrói um objeto de `CDataRecoveryHandler` .|  
  
### Métodos  
  
|||  
|-|-|  
|[CDataRecoveryHandler::AutosaveAllDocumentInfo](../Topic/CDataRecoveryHandler::AutosaveAllDocumentInfo.md)|Autosaves cada arquivo registrado com a classe de `CDataRecoveryHandler` .|  
|[CDataRecoveryHandler::AutosaveDocumentInfo](../Topic/CDataRecoveryHandler::AutosaveDocumentInfo.md)|Autosaves o documento especificado.|  
|[CDataRecoveryHandler::CreateDocumentInfo](../Topic/CDataRecoveryHandler::CreateDocumentInfo.md)|Adiciona um documento à lista de documentos abertos.|  
|[CDataRecoveryHandler::DeleteAllAutosavedFiles](../Topic/CDataRecoveryHandler::DeleteAllAutosavedFiles.md)|Exclui todos os arquivos autosaved atual.|  
|[CDataRecoveryHandler::DeleteAutosavedFile](../Topic/CDataRecoveryHandler::DeleteAutosavedFile.md)|Exclui o arquivo autosaved especificado.|  
|[CDataRecoveryHandler::GenerateAutosaveFileName](../Topic/CDataRecoveryHandler::GenerateAutosaveFileName.md)|Gera o nome de um arquivo de autosave associado com o nome de arquivo fornecido do documento.|  
|[CDataRecoveryHandler::GetAutosaveInterval](../Topic/CDataRecoveryHandler::GetAutosaveInterval.md)|Retorna o intervalo entre autosave tenta.|  
|[CDataRecoveryHandler::GetAutosavePath](../Topic/CDataRecoveryHandler::GetAutosavePath.md)|Retorna o caminho de arquivos autosaved.|  
|[CDataRecoveryHandler::GetDocumentListName](../Topic/CDataRecoveryHandler::GetDocumentListName.md)|Recupera o nome do documento de um objeto de `CDocument` .|  
|[CDataRecoveryHandler::GetNormalDocumentTitle](../Topic/CDataRecoveryHandler::GetNormalDocumentTitle.md)|Recupera o título normal para o documento especificado.|  
|[CDataRecoveryHandler::GetRecoveredDocumentTitle](../Topic/CDataRecoveryHandler::GetRecoveredDocumentTitle.md)|Cria e retorna o título para o documento recuperado.|  
|[CDataRecoveryHandler::GetRestartIdentifier](../Topic/CDataRecoveryHandler::GetRestartIdentifier.md)|Recupera o identificador exclusivo de reinicialização do aplicativo.|  
|[CDataRecoveryHandler::GetSaveDocumentInfoOnIdle](../Topic/CDataRecoveryHandler::GetSaveDocumentInfoOnIdle.md)|Indica se `CDataRecoveryHandler` executa um autosave no loop ocioso atual.|  
|[CDataRecoveryHandler::GetShutdownByRestartManager](../Topic/CDataRecoveryHandler::GetShutdownByRestartManager.md)|Indica se o gerenciador de reinicialização causou sair do aplicativo.|  
|[CDataRecoveryHandler::Initialize](../Topic/CDataRecoveryHandler::Initialize.md)|Inicializa `CDataRecoveryHandler`.|  
|[CDataRecoveryHandler::QueryRestoreAutosavedDocuments](../Topic/CDataRecoveryHandler::QueryRestoreAutosavedDocuments.md)|Exibe uma caixa de diálogo para o usuário para cada documento que `CDataRecoveryHandler` autosaved.  A caixa de diálogo determina se o usuário deseja restaurar o documento autosaved.|  
|[CDataRecoveryHandler::ReadOpenDocumentList](../Topic/CDataRecoveryHandler::ReadOpenDocumentList.md)|Carrega a lista de documento aberto do Registro.|  
|[CDataRecoveryHandler::RemoveDocumentInfo](../Topic/CDataRecoveryHandler::RemoveDocumentInfo.md)|Remove o documento fornecido na lista de documento aberto.|  
|[CDataRecoveryHandler::ReopenPreviousDocuments](../Topic/CDataRecoveryHandler::ReopenPreviousDocuments.md)|Abre anteriormente os documentos abertos.|  
|[CDataRecoveryHandler::RestoreAutosavedDocuments](../Topic/CDataRecoveryHandler::RestoreAutosavedDocuments.md)|Restaura os documentos autosaved com base na entrada do usuário.|  
|[CDataRecoveryHandler::SaveOpenDocumentList](../Topic/CDataRecoveryHandler::SaveOpenDocumentList.md)|Salva a lista atual de documentos abertos no Registro do Windows.|  
|[CDataRecoveryHandler::SetAutosaveInterval](../Topic/CDataRecoveryHandler::SetAutosaveInterval.md)|Define o tempo entre ciclos autosave em milissegundos.|  
|[CDataRecoveryHandler::SetAutosavePath](../Topic/CDataRecoveryHandler::SetAutosavePath.md)|Define o diretório onde os arquivos autosaved são armazenados.|  
|[CDataRecoveryHandler::SetRestartIdentifier](../Topic/CDataRecoveryHandler::SetRestartIdentifier.md)|Define o identificador exclusivo de configuração para essa instância de `CDataRecoveryHandler`.|  
|[CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](../Topic/CDataRecoveryHandler::SetSaveDocumentInfoOnIdle.md)|Define se `CDataRecoveryHandler` salva informações de documento aberto no Registro do Windows durante o ciclo ocioso atual.|  
|[CDataRecoveryHandler::SetShutdownByRestartManager](../Topic/CDataRecoveryHandler::SetShutdownByRestartManager.md)|Determina se a saída anterior do aplicativo foi causada pelo gerenciador de configuração.|  
|[CDataRecoveryHandler::UpdateDocumentInfo](../Topic/CDataRecoveryHandler::UpdateDocumentInfo.md)|Atualiza informações de um documento porque o usuário salvar.|  
  
### Membros de dados  
  
|||  
|-|-|  
|m\_bRestoringPreviousOpenDocs|Indica se o manipulador de recuperação de dados reabre anteriormente documentos abertos.|  
|m\_bSaveDocumentInfoOnIdle|Indica se o manipulador de recuperação de dados autosaves documentos no loop ocioso seguir.|  
|m\_bShutdownByRestartManager|Indica se o gerenciador de configuração causa sair do aplicativo.|  
|m\_dwRestartManagerSupportFlags|Sinalizadores que indicam que suporte o gerenciador de reinicialização fornece para o aplicativo.|  
|m\_lstAutosavesToDelete|Uma lista de arquivos autosaved que não foram excluídos enquanto os documentos originais são fechados.  Quando o aplicativo termina, o gerenciador de reinicialização experimenta de volta excluir os arquivos.|  
|m\_mapDocNameToAutosaveName|Um mapa de nomes do documento para nomes de arquivo autosaved.|  
|m\_mapDocNameToDocumentPtr|Um mapa de nomes do documento para ponteiros de [CDocument](../Topic/CDocument%20Class.md) .|  
|m\_mapDocNameToRestoreBool|Um mapa de nomes do documento para um parâmetro boolean que indica se restaurar o documento autosaved.|  
|m\_mapDocumentPtrToDocName|Um mapa de ponteiros de `CDocument` para nomes do documento.|  
|m\_mapDocumentPtrToDocTitle|Um mapa de ponteiros de `CDocument` aos títulos do documento.  Esses títulos são usados salvar arquivos.|  
|m\_nAutosaveInterval|O horário em milissegundos entre autosaves.|  
|m\_nTimerID|O identificador para o timer de autosave.|  
|m\_strAutosavePath|o local onde os documentos autosaved são armazenados.|  
|mais m\_strRestartIdentifier|A representação de cadeia de caracteres GUID para o gerenciador de configuração.|  
  
## Comentários  
 O gerenciador de reinicialização de `CDataRecoveryHandler` usa a classe para manter controle de todos os documentos abertos e para os autosave conforme necessário.  Para ativar autosave, use o método de [CDataRecoveryHandler::SetSaveDocumentInfoOnIdle](../Topic/CDataRecoveryHandler::SetSaveDocumentInfoOnIdle.md) .  Este método direciona `CDataRecoveryHandler` para executar um autosave no loop ocioso seguir.  O gerenciador de reinicialização chama `SetSaveDocumentInfoOnIdle` quando `CDataRecoveryHandler` deve executar um autosave.  
  
 Todos os métodos da classe de `CDataRecoveryHandler` são virtuais.  Substituir os métodos de essa classe para criar seu próprio manipulador personalizado de recuperação de dados.  A menos que você criar seu próprio gerenciador do manipulador ou de reinicialização de recuperação de dados, não criar uma instância de um CDataRecoveryHandler.  [Classe de CWinApp](../../mfc/reference/cwinapp-class.md) cria um objeto de `CDataRecoveryHandler` como se necessário.  
  
 Antes de usar um objeto de `CDataRecoveryHandler` , você deve chamar [CDataRecoveryHandler::Initialize](../Topic/CDataRecoveryHandler::Initialize.md).  
  
 Porque a classe de `CDataRecoveryHandler` é conectada próximo ao gerenciador de reinicialização, `CDataRecoveryHandler` depende do parâmetro global `m_dwRestartManagerSupportFlags`.  Este parâmetro determina quais permissões o gerenciador de configuração possui e como interagir com seu aplicativo.  Para abrir o gerenciador de configuração em um aplicativo existente, você precisa atribuir a `m_dwRestartManagerSupportFlags` o valor apropriado no construtor do aplicativo principal.  Para obter mais informações sobre como usar o gerenciador de reinicialização, consulte [Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md).  
  
## Requisitos  
 **Cabeçalho:** afxdatarecovery.h  
  
## Consulte também  
 [Classes](../Topic/MFC%20Classes.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Como adicionar suporte ao gerenciador de reinicialização](../../mfc/how-to-add-restart-manager-support.md)