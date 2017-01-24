---
title: "Classe de CAtlTemporaryFile | Microsoft Docs"
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
  - "CAtlTemporaryFile"
  - "ATL.CAtlTemporaryFile"
  - "ATL::CAtlTemporaryFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlTemporaryFile"
ms.assetid: 05f0f2a5-94f6-4594-8dae-b114292ff5f9
caps.latest.revision: 18
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlTemporaryFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para a criação e uso de um arquivo temporário.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
class CAtlTemporaryFile  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlTemporaryFile::CAtlTemporaryFile](../Topic/CAtlTemporaryFile::CAtlTemporaryFile.md)|o construtor.|  
|[CAtlTemporaryFile::~CAtlTemporaryFile](../Topic/CAtlTemporaryFile::~CAtlTemporaryFile.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAtlTemporaryFile::Close](../Topic/CAtlTemporaryFile::Close.md)|Chamar esse método para fechar um arquivo temporário para excluir e seu conteúdo ou guardar no nome de arquivo especificado.|  
|[CAtlTemporaryFile::Create](../Topic/CAtlTemporaryFile::Create.md)|Chamar esse método para criar um arquivo temporário.|  
|[CAtlTemporaryFile::Flush](../Topic/CAtlTemporaryFile::Flush.md)|Chamar esse método para forçar quaisquer dados que permanecem no buffer do arquivo a ser escrito no arquivo temporário.|  
|[CAtlTemporaryFile::GetPosition](../Topic/CAtlTemporaryFile::GetPosition.md)|Chamar esse método para obter a posição do ponteiro do arquivo atual.|  
|[CAtlTemporaryFile::GetSize](../Topic/CAtlTemporaryFile::GetSize.md)|Chamar esse método para obter o tamanho em bytes do arquivo temporário.|  
|[CAtlTemporaryFile::HandsOff](../Topic/CAtlTemporaryFile::HandsOff.md)|Chamar esse método para desassocia o arquivo do objeto de `CAtlTemporaryFile` .|  
|[CAtlTemporaryFile::HandsOn](../Topic/CAtlTemporaryFile::HandsOn.md)|Chamar esse método para abrir um arquivo temporário existente e para posicionar o ponteiro no final do arquivo.|  
|[CAtlTemporaryFile::LockRange](../Topic/CAtlTemporaryFile::LockRange.md)|Chamar esse método para bloquear uma região no arquivo para impedir que outros processos acessem o.|  
|[CAtlTemporaryFile::Read](../Topic/CAtlTemporaryFile::Read.md)|Chamar esse método para ler dados de arquivo temporário começando na posição indicada pelo ponteiro do arquivo.|  
|[CAtlTemporaryFile::Seek](../Topic/CAtlTemporaryFile::Seek.md)|Chamar esse método para mover o ponteiro do arquivo temporário.|  
|[CAtlTemporaryFile::SetSize](../Topic/CAtlTemporaryFile::SetSize.md)|Chamar esse método para definir o tamanho do arquivo temporário.|  
|[CAtlTemporaryFile::TempFileName](../Topic/CAtlTemporaryFile::TempFileName.md)|Chamar este método para retornar o nome do arquivo temporário.|  
|[CAtlTemporaryFile::UnlockRange](../Topic/CAtlTemporaryFile::UnlockRange.md)|Chamar esse método para desbloquear uma região de arquivo temporário.|  
|[CAtlTemporaryFile::Write](../Topic/CAtlTemporaryFile::Write.md)|Chamar esse método para gravar dados para o arquivo temporário começando na posição indicada pelo ponteiro do arquivo.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[ALÇA de CAtlTemporaryFile::operator](../Topic/CAtlTemporaryFile::operator%20HANDLE.md)|Retorna um identificador para o arquivo temporário.|  
  
## Comentários  
 `CAtlTemporaryFile` torna fácil criar e usar um arquivo temporário.  O arquivo é chamado automaticamente, aberto, fechado, e excluído.  Se o conteúdo do arquivo são necessárias após o arquivo está fechado, podem ser salvos para um novo arquivo com um nome especificado.  
  
## Requisitos  
 **Cabeçalho:** atlfile.h  
  
## Exemplo  
 Consulte o exemplo para [CAtlTemporaryFile::CAtlTemporaryFile](../Topic/CAtlTemporaryFile::CAtlTemporaryFile.md).  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CAtlFile](../../atl/reference/catlfile-class.md)