---
title: "Classe de CShellManager | Microsoft Docs"
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
  - "CShellManager"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CShellManager"
ms.assetid: f15c4c1a-6fae-487d-9913-9b7369b33da0
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CShellManager
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa vários métodos que permitem que você trabalhe com os ponteiros para listas identificador \(PIDLs\).  
  
## Sintaxe  
  
```  
class CShellManager : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CShellManager::CShellManager](../Topic/CShellManager::CShellManager.md)|Constrói um objeto de `CShellManager` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CShellManager::BrowseForFolder](../Topic/CShellManager::BrowseForFolder.md)|Exibe uma caixa de diálogo que permite que o usuário selecione uma pasta do shell.|  
|[CShellManager::ConcatenateItem](../Topic/CShellManager::ConcatenateItem.md)|Concatena dois PIDLs.|  
|[CShellManager::CopyItem](../Topic/CShellManager::CopyItem.md)|Cria um novo PIDL e copia\-lhe o PIDL fornecido.|  
|[CShellManager::CreateItem](../Topic/CShellManager::CreateItem.md)|Cria um novo PIDL de tamanho especificado.|  
|[CShellManager::FreeItem](../Topic/CShellManager::FreeItem.md)|Exclui o PIDL fornecido.|  
|[CShellManager::GetItemCount](../Topic/CShellManager::GetItemCount.md)|Retorna o número de itens em PIDL fornecido.|  
|[CShellManager::GetItemSize](../Topic/CShellManager::GetItemSize.md)|Retorna o tamanho de PIDL fornecido.|  
|[CShellManager::GetNextItem](../Topic/CShellManager::GetNextItem.md)|Retorna o próximo item de PIDL.|  
|[CShellManager::GetParentItem](../Topic/CShellManager::GetParentItem.md)|Recupera o item pai do item fornecido.|  
|[CShellManager::ItemFromPath](../Topic/CShellManager::ItemFromPath.md)|Recupera o PIDL para o item identificado pelo caminho fornecido.|  
  
## Comentários  
 Os métodos de `CShellManager` classe qualquer lidar com PIDLs.  Um PIDL é um identificador exclusivo para um objeto do shell.  
  
 Você não deve criar um objeto de `CShellManager` manualmente.  Será criado automaticamente pela estrutura do seu aplicativo.  Em o entanto, você deve chamar [CWinAppEx::InitShellManager](../Topic/CWinAppEx::InitShellManager.md) durante o processo de inicialização do aplicativo.  Para obter um ponteiro ao gerenciador do shell para seu aplicativo, chame [CWinAppEx::GetShellManager](../Topic/CWinAppEx::GetShellManager.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CShellManager](../../mfc/reference/cshellmanager-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxshellmanager.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)