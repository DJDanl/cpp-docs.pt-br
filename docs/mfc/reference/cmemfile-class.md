---
title: "Classe de CMemFile | Microsoft Docs"
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
  - "CMemFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMemFile"
  - "arquivos de memória"
  - "arquivos temporários, arquivos de memória"
ms.assetid: 20e86515-e465-4f73-b2ea-e49789d63165
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMemFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

[CFile](../../mfc/reference/cfile-class.md)\- classe derivada que suporta arquivos de memória.  
  
## Sintaxe  
  
```  
class CMemFile : public CFile  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemFile::CMemFile](../Topic/CMemFile::CMemFile.md)|Constrói um objeto do arquivo de memória.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemFile::Attach](../Topic/CMemFile::Attach.md)|Anexa um bloco de memória `CMemFile`.|  
|[CMemFile::Detach](../Topic/CMemFile::Detach.md)|Dispara o bloco de memória de `CMemFile` e retorna um ponteiro ao bloco de memória desanexado.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CMemFile::Alloc](../Topic/CMemFile::Alloc.md)|Substituição para alterar o comportamento de alocação de memória.|  
|[CMemFile::Free](../Topic/CMemFile::Free.md)|Substituição para alterar o comportamento de desalocação de memória.|  
|[CMemFile::GrowFile](../Topic/CMemFile::GrowFile.md)|Substituição para alterar o comportamento ao crescer um arquivo.|  
|[CMemFile::Memcpy](../Topic/CMemFile::Memcpy.md)|Substituição para alterar o comportamento de impressão de memória quando ler e gravar arquivos.|  
|[CMemFile::Realloc](../Topic/CMemFile::Realloc.md)|Substituição para alterar o comportamento de realocação de memória.|  
  
## Comentários  
 Esses arquivos de memória se comportam como arquivos de disco exceto pelo fato de que o arquivo é armazenado na memória RAM em vez de no disco.  Um arquivo de memória é útil para armazenamento temporário rápido ou para transferir bytes crua ou objetos serializados entre processos independentes.  
  
 Os objetos de`CMemFile` podem automaticamente atribuia sua própria memória ou você pode anexar seu próprio bloco de memória para o objeto de `CMemFile` chamando [Anexar](../Topic/CMemFile::Attach.md).  Em ambos os casos, a memória aumentarem do arquivo é alocada memória automaticamente em `nGrowBytes`\- incrementos dimensionados se `nGrowBytes` não é zero.  
  
 O bloco de memória será excluído automaticamente em cima da destruição do objeto de `CMemFile` se a memória alocada foi originalmente pelo objeto de `CMemFile` ; caso contrário, você é responsável desalocar a memória que você tiver anexado ao objeto.  
  
 Você pode acessar o bloco de memória através do ponteiro fornecido quando você dispara o do objeto de `CMemFile` chamando [Desanexar](../Topic/CMemFile::Detach.md).  
  
 O uso mais comum de `CMemFile` é criar um objeto de `CMemFile` e usá\-lo chamando funções de membro de [CFile](../../mfc/reference/cfile-class.md) .  Observe que cria `CMemFile` abrir automaticamente: você não chama [CFile::Open](../Topic/CFile::Open.md), que é usado somente para arquivos em disco.  Porque `CMemFile` não usa um arquivo em disco, o membro `CFile::m_hFile` de dados não é usado e não tem significado.  
  
 As funções de membro [Duplicate](../Topic/CFile::Duplicate.md), [LockRange](../Topic/CFile::LockRange.md), e [UnlockRange](../Topic/CFile::UnlockRange.md) de `CFile` não são implementadas para `CMemFile`.  Se você chamar essas funções em `CMemFile` objeto, você [CNotSupportedException](../../mfc/reference/cnotsupportedexception-class.md)obterão.  
  
 `CMemFile` usa as funções de biblioteca [malloc](../../c-runtime-library/reference/malloc.md), [realloc](../../c-runtime-library/reference/realloc.md), e [livre](../../c-runtime-library/reference/free.md) de tempo de execução para atribuir, realocar, a memória; e desalocar e o tipo intrínseco [memcpy](../../c-runtime-library/reference/memcpy-wmemcpy.md) para bloquear a memória de impressão ao ler e gravar.  Se você gostaria de alterar esse comportamento ou comportamento quando `CMemFile` cresce um arquivo, derive sua própria classe de `CMemFile` e substituir as funções apropriadas.  
  
 Para obter mais informações sobre `CMemFile`, consulte os artigos [Arquivos no MFC](../../mfc/files-in-mfc.md) e [gerenciamento de memória \(MFC\)](../../mfc/memory-management.md) consulte e [Manipular de Arquivo](../../c-runtime-library/file-handling.md)*na referência da biblioteca em tempo de execução*.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 `CMemFile`  
  
## Requisitos  
 **Cabeçalho:** afx.h  
  
## Consulte também  
 [Classe de CFile](../../mfc/reference/cfile-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)