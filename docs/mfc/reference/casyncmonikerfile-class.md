---
title: "Classe de CAsyncMonikerFile | Microsoft Docs"
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
  - "CAsyncMonikerFile"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], assíncrono"
  - "controles assíncronos [C++]"
  - "Classe de CAsyncMonikerFile"
  - "Interface de IMoniker, associação"
  - "alcunhas [C++], MFC"
  - "Controladores OLE [C++], assíncrono"
ms.assetid: 17378b66-a49a-4b67-88e3-7756ad26a2fc
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAsyncMonikerFile
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece a funcionalidade para uso de alcunhas assíncrono em controles ActiveX \(anteriormente controladores OLE.\)  
  
## Sintaxe  
  
```  
class CAsyncMonikerFile : public CMonikerFile  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAsyncMonikerFile::CAsyncMonikerFile](../Topic/CAsyncMonikerFile::CAsyncMonikerFile.md)|Constrói um objeto de `CAsyncMonikerFile` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAsyncMonikerFile::Close](../Topic/CAsyncMonikerFile::Close.md)|Fecha e libera quaisquer recursos.|  
|[CAsyncMonikerFile::GetBinding](../Topic/CAsyncMonikerFile::GetBinding.md)|Recupera um ponteiro para a associação de transferência assíncrono.|  
|[CAsyncMonikerFile::GetFormatEtc](../Topic/CAsyncMonikerFile::GetFormatEtc.md)|Recupera o formato de dados no fluxo.|  
|[CAsyncMonikerFile::Open](../Topic/CAsyncMonikerFile::Open.md)|Abre um arquivo de forma assíncrona.|  
  
### Métodos protegidos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAsyncMonikerFile::CreateBindStatusCallback](../Topic/CAsyncMonikerFile::CreateBindStatusCallback.md)|Cria um objeto COM que implementa `IBindStatusCallback`.|  
|[CAsyncMonikerFile::GetBindInfo](../Topic/CAsyncMonikerFile::GetBindInfo.md)|Chamado pela biblioteca do sistema OLE para solicitar informações sobre o tipo da para ser criado.|  
|[CAsyncMonikerFile::GetPriority](../Topic/CAsyncMonikerFile::GetPriority.md)|Chamado pela biblioteca do sistema OLE para obter a prioridade da associação.|  
|[CAsyncMonikerFile::OnDataAvailable](../Topic/CAsyncMonikerFile::OnDataAvailable.md)|Para fornecer dados chamado como se torna disponível para o cliente durante operações assíncronas bind.|  
|[CAsyncMonikerFile::OnLowResource](../Topic/CAsyncMonikerFile::OnLowResource.md)|Chamado quando os recursos sejam baixo.|  
|[CAsyncMonikerFile::OnProgress](../Topic/CAsyncMonikerFile::OnProgress.md)|Chamado para indicar o progresso no processo de transferência de dados.|  
|[CAsyncMonikerFile::OnStartBinding](../Topic/CAsyncMonikerFile::OnStartBinding.md)|Associar é chamado quando iniciar anterior.|  
|[CAsyncMonikerFile::OnStopBinding](../Topic/CAsyncMonikerFile::OnStopBinding.md)|Chamado quando a transferência assíncrono é interrompida.|  
  
## Comentários  
 Derivado de [CMonikerFile](../Topic/CMonikerFile%20Class.md), que por sua vez é derivado de [COleStreamFile](../Topic/COleStreamFile%20Class.md), `CAsyncMonikerFile` usa a interface de [IMoniker](http://msdn.microsoft.com/library/windows/desktop/ms679705) para acessar de qualquer forma assíncrona fluxo de dados, incluindo arquivos de carregamento de forma assíncrona de um URL.  Os arquivos podem ser propriedades de datapath de controles ActiveX.  
  
 As alcunhas assíncronos são usadas principalmente em aplicativos e controles ActiveX internet para fornecer uma interface do usuário responde durante a transferências de arquivos.  Como um exemplo de isso é o uso de [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md) fornecer propriedades assíncronas para controles ActiveX.  O objeto de `CDataPathProperty` conseguirá repetidamente um retorno de chamada para indicar a disponibilidade de novos dados durante um processo longo de troca de propriedade.  
  
 Para obter mais informações sobre como usar alcunhas assíncronos e controles ActiveX em aplicativos de Internet, consulte os seguintes artigos:  
  
-   [Primeiras etapas da Internet: alcunhas assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)  
  
-   [Primeiras etapas da Internet: Controles do ActiveX](../../mfc/activex-controls-on-the-internet.md)  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../Topic/COleStreamFile%20Class.md)  
  
 [CMonikerFile](../Topic/CMonikerFile%20Class.md)  
  
 `CAsyncMonikerFile`  
  
## Requisitos  
 **Cabeçalho:** afxole.h  
  
## Consulte também  
 [Classe de CMonikerFile](../Topic/CMonikerFile%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMonikerFile](../Topic/CMonikerFile%20Class.md)   
 [Classe de CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)   
 [Asynchronous Versus Synchronous Monikers](http://msdn.microsoft.com/library/windows/desktop/ms687193)