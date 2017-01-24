---
title: "Classe de CAtlFileMappingBase | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "ATL.CAtlFileMappingBase"
  - "ATL::CAtlFileMappingBase"
  - "CAtlFileMappingBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlFileMappingBase"
ms.assetid: be555723-2790-4f57-a8fb-be4d68460775
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlFileMappingBase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um arquivo memória mapeado.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CAtlFileMappingBase  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFileMappingBase::CAtlFileMappingBase](../Topic/CAtlFileMappingBase::CAtlFileMappingBase.md)|o construtor.|  
|[CAtlFileMappingBase::~CAtlFileMappingBase](../Topic/CAtlFileMappingBase::~CAtlFileMappingBase.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFileMappingBase::CopyFrom](../Topic/CAtlFileMappingBase::CopyFrom.md)|Chamar esse método para copiar de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::GetData](../Topic/CAtlFileMappingBase::GetData.md)|Chamar esse método para obter dados de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::GetHandle](../Topic/CAtlFileMappingBase::GetHandle.md)|Chamar este método para retornar o identificador de arquivo.|  
|[CAtlFileMappingBase::GetMappingSize](../Topic/CAtlFileMappingBase::GetMappingSize.md)|Chamar esse método para obter o tamanho de mapeamento de um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::MapFile](../Topic/CAtlFileMappingBase::MapFile.md)|Chamar esse método para criar um objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::MapSharedMem](../Topic/CAtlFileMappingBase::MapSharedMem.md)|Chamar esse método para criar um objeto de mapeamento de arquivo que permite acesso completo a todos os processos.|  
|[CAtlFileMappingBase::OpenMapping](../Topic/CAtlFileMappingBase::OpenMapping.md)|Chamar este método para retornar um identificador para o objeto de mapeamento de arquivo.|  
|[CAtlFileMappingBase::Unmap](../Topic/CAtlFileMappingBase::Unmap.md)|Chamar esse método para unmap um objeto de mapeamento de arquivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlFileMappingBase::operator \=](../Topic/CAtlFileMappingBase::operator%20=.md)|Defina o objeto atual de mapeamento de arquivo para outro objeto de mapeamento de arquivo.|  
  
## Comentários  
 O mapeamento de arquivo é associação de conteúdo de um arquivo com uma parte do espaço de endereço virtual de um processo.  Essa classe fornece métodos para criar o mapeamento de arquivo objetos que programas de licença para acessar e facilmente compartilhar dados.  
  
 Para obter mais informações, consulte [mapeamento de arquivo](http://msdn.microsoft.com/library/windows/desktop/aa366556) em [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## Requisitos  
 **Cabeçalho:** atlfile.h  
  
## Consulte também  
 [Classe de CAtlFileMapping](../Topic/CAtlFileMapping%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)