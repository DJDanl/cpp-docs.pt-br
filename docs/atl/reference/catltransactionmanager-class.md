---
title: "Classe de CAtlTransactionManager | Microsoft Docs"
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
  - "CAtlTransactionManager"
  - "atltransactionmanager/ATL::CAtlTransactionManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlTransactionManager"
ms.assetid: b01732dc-1d16-4b42-bfac-b137fca2b740
caps.latest.revision: 25
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlTransactionManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A classe de CAtlTransactionManager fornece um wrapper funções de \(KTM\) do gerenciador de transações kernel.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
class CAtlTransactionManager;  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlTransactionManager::~CAtlTransactionManager](../Topic/CAtlTransactionManager::~CAtlTransactionManager.md)|Destruidor de CAtlTransactionManager.|  
|[CAtlTransactionManager::CAtlTransactionManager](../Topic/CAtlTransactionManager::CAtlTransactionManager.md)|Construtor de CAtlTransactionManager.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlTransactionManager::Close](../Topic/CAtlTransactionManager::Close.md)|Fecha a um identificador de transação.|  
|[CAtlTransactionManager::Commit](../Topic/CAtlTransactionManager::Commit.md)|Solicitações que a transação é confirmada.|  
|[CAtlTransactionManager::Create](../Topic/CAtlTransactionManager::Create.md)|Cria o identificador de transação.|  
|[CAtlTransactionManager::CreateFile](../Topic/CAtlTransactionManager::CreateFile.md)|Cria ou abre um arquivo, um fluxo de arquivos, ou diretório como uma operação transacionada.|  
|[CAtlTransactionManager::DeleteFile](../Topic/CAtlTransactionManager::DeleteFile.md)|Excluir um arquivo existente como uma operação transacionada.|  
|[CAtlTransactionManager::FindFirstFile](../Topic/CAtlTransactionManager::FindFirstFile.md)|Procura por um diretório ou subdiretório um arquivo como uma operação transacionada.|  
|[CAtlTransactionManager::GetFileAttributes](../Topic/CAtlTransactionManager::GetFileAttributes.md)|Recupera os atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|  
|[CAtlTransactionManager::GetFileAttributesEx](../Topic/CAtlTransactionManager::GetFileAttributesEx.md)|Recupera os atributos do sistema de arquivos para um arquivo ou diretório especificado como uma operação transacionada.|  
|[CAtlTransactionManager::GetHandle](../Topic/CAtlTransactionManager::GetHandle.md)|Retorna o identificador de transação.|  
|[CAtlTransactionManager::IsFallback](../Topic/CAtlTransactionManager::IsFallback.md)|Determina se as chamadas de fallback estão habilitados.|  
|[CAtlTransactionManager::MoveFile](../Topic/CAtlTransactionManager::MoveFile.md)|Mover um arquivo ou diretório existente, incluindo seus filhos, como uma operação transacionada.|  
|[CAtlTransactionManager::RegCreateKeyEx](../Topic/CAtlTransactionManager::RegCreateKeyEx.md)|Cria a chave de Registro especificada e associá\-la com uma transação.  Se a chave já existir, a função abra\-o.|  
|[CAtlTransactionManager::RegDeleteKey](../Topic/CAtlTransactionManager::RegDeleteKey.md)|Excluir uma subchave e seus valores de exibição plataforma específica de Registro especificada como uma operação transacionada.|  
|[CAtlTransactionManager::RegOpenKeyEx](../Topic/CAtlTransactionManager::RegOpenKeyEx.md)|Abre a chave de Registro especificada e associá\-la com uma transação.|  
|[CAtlTransactionManager::Rollback](../Topic/CAtlTransactionManager::Rollback.md)|Solicitações que a transação é revertida.|  
|[CAtlTransactionManager::SetFileAttributes](../Topic/CAtlTransactionManager::SetFileAttributes.md)|Defina os atributos para um arquivo ou diretório como uma operação transacionada.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlTransactionManager::m\_bFallback](../Topic/CAtlTransactionManager::m_bFallback.md)|`TRUE` se a reserva é suportado; `FALSE` caso contrário.|  
|[CAtlTransactionManager::m\_hTransaction](../Topic/CAtlTransactionManager::m_hTransaction.md)|O identificador de transação.|  
  
## Comentários  
  
## Hierarquia de herança  
 [ATL::CAtlTransactionManager](../../atl/reference/catltransactionmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** atltransactionmanager.h  
  
## Consulte também  
 [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md)