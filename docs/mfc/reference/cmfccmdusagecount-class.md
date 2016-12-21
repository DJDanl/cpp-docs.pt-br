---
title: "Classe de CMFCCmdUsageCount | Microsoft Docs"
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
  - "CMFCCmdUsageCount"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CMFCCmdUsageCount"
ms.assetid: 9c33b783-37c0-43ea-9f31-3c75e246c841
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CMFCCmdUsageCount
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controla a contagem de uso de mensagens do windows, como quando o usuário seleciona um item de um menu.  
  
## Sintaxe  
  
```  
class CMFCCmdUsageCount : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCmdUsageCount::CMFCCmdUsageCount`|Construtor padrão.|  
|`CMFCCmdUsageCount::~CMFCCmdUsageCount`|Destruidor.|  
  
### Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|[CMFCCmdUsageCount::AddCmd](../Topic/CMFCCmdUsageCount::AddCmd.md)|Sai por um contador o que está associado com o comando dado.|  
|[CMFCCmdUsageCount::GetCount](../Topic/CMFCCmdUsageCount::GetCount.md)|Recupera a contagem de uso que está associada com a identificação determinada de comando|  
|[CMFCCmdUsageCount::HasEnoughInformation](../Topic/CMFCCmdUsageCount::HasEnoughInformation.md)|Determina se este objeto obteve a quantidade mínima de dados de rastreamento.|  
|[CMFCCmdUsageCount::IsFreqeuntlyUsedCmd](../Topic/CMFCCmdUsageCount::IsFreqeuntlyUsedCmd.md)|Determina se o comando dado é freqüentemente usado.|  
|[CMFCCmdUsageCount::Reset](../Topic/CMFCCmdUsageCount::Reset.md)|Limpa a contagem de uso de todos os comandos.|  
|[CMFCCmdUsageCount::Serialize](../Topic/CMFCCmdUsageCount::Serialize.md)|Este objeto ler de um arquivo ou neutro o grava em um arquivo neutro.  Overrides \( [CObject::Serialize](../Topic/CObject::Serialize.md).\)|  
|[CMFCCmdUsageCount::SetOptions](../Topic/CMFCCmdUsageCount::SetOptions.md)|Defina os valores de membros compartilhados de dados da classe de `CMFCCmdUsageCount` .|  
  
### Membros de dados  
  
|||  
|-|-|  
|Nome|Descrição|  
|`m_CmdUsage`|Um objeto de `CMap` que mapeia comandos para seu uso conta.|  
|`m_nMinUsagePercentage`|A porcentagem mínimo de uso para um comando é freqüentemente usado.|  
|`m_nStartCount`|O contador inicial que é usado para determinar se este objeto obteve a quantidade mínima de dados de rastreamento.|  
|`m_nTotalUsage`|A contagem de todos os comandos rastreadas.|  
  
### Comentários  
 A classe de `CMFCCmdUsageCount` mapeia cada identificador de mensagem numérico do windows a um contador inteiro de 32 bits sem sinal.  `CMFCToolBar` usar esta classe para exibir itens usados com freqüência da barra de ferramentas.  Para obter mais informações sobre o `CMFCToolBar`, consulte [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md).  
  
 Você pode persistir dados da classe de `CMFCCmdUsageCount` entre a execução do programa.  Use o método de [CMFCCmdUsageCount::Serialize](../Topic/CMFCCmdUsageCount::Serialize.md) para serializar os dados do membro da classe e o método de [CMFCCmdUsageCount::SetOptions](../Topic/CMFCCmdUsageCount::SetOptions.md) para definir dados compartilhados do membro.  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CMFCCmdUsageCount](../../mfc/reference/cmfccmdusagecount-class.md)  
  
## Requisitos  
 **Cabeçalho:** afxcmdusagecount.h  
  
## Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../Topic/MFC%20Classes.md)   
 [Classe de CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)