---
title: "Classe de CAtlFile | Microsoft Docs"
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
  - "CAtlFile"
  - "ATL::CAtlFile"
  - "ATL.CAtlFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlFile"
ms.assetid: 93ed160b-af2a-448c-9cbe-e5fa46c199bb
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece melhor um wrapper em torno de arquivo tratamento API do windows.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CAtlFile : public CHandle  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFile::CAtlFile](../Topic/CAtlFile::CAtlFile.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFile::Create](../Topic/CAtlFile::Create.md)|Chamar esse método para criar ou abrir um arquivo.|  
|[CAtlFile::Flush](../Topic/CAtlFile::Flush.md)|Chamar esse método para limpar os buffers para o arquivo e para causar todos os dados armazenados em buffer a serem gravados no arquivo.|  
|[CAtlFile::GetOverlappedResult](../Topic/CAtlFile::GetOverlappedResult.md)|Chamar esse método para obter os resultados de uma operação sobrepostos no arquivo.|  
|[CAtlFile::GetPosition](../Topic/CAtlFile::GetPosition.md)|Chamar esse método para obter a posição do ponteiro do arquivo atual do arquivo.|  
|[CAtlFile::GetSize](../Topic/CAtlFile::GetSize.md)|Chamar esse método para obter o tamanho em bytes do arquivo.|  
|[CAtlFile::LockRange](../Topic/CAtlFile::LockRange.md)|Chamar esse método para bloquear uma região no arquivo para impedir que outros processos acessem o.|  
|[CAtlFile::Read](../Topic/CAtlFile::Read.md)|Chamar esse método para ler dados de um arquivo que começa na posição indicada pelo ponteiro do arquivo.|  
|[CAtlFile::Seek](../Topic/CAtlFile::Seek.md)|Chamar esse método para mover o ponteiro do arquivo.|  
|[CAtlFile::SetSize](../Topic/CAtlFile::SetSize.md)|Chamar esse método para definir o tamanho do arquivo.|  
|[CAtlFile::UnlockRange](../Topic/CAtlFile::UnlockRange.md)|Chamar esse método para desbloquear uma região de arquivo.|  
|[CAtlFile::Write](../Topic/CAtlFile::Write.md)|Chamar esse método para gravar dados para o arquivo que começa na posição indicada pelo ponteiro do arquivo.|  
  
### Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFile::m\_pTM](../Topic/CAtlFile::m_pTM.md)|Ponteiro para o objeto de `CAtlTransactionManager`|  
  
## Comentários  
 Use esta classe quando as necessidades de arquivo tratamento são relativamente simples, mas mais abstração do windows API que fornecem são necessárias, sem incluir MFC dependências.  
  
## Hierarquia de herança  
 [CHandle](../../atl/reference/chandle-class.md)  
  
 `CAtlFile`  
  
## Requisitos  
 **Cabeçalho:** atlfile.h  
  
## Consulte também  
 [Exemplo de famoso](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CHandle](../../atl/reference/chandle-class.md)