---
title: "Classe de CDataPathProperty | Microsoft Docs"
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
  - "CDataPathProperty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], assíncrono"
  - "controles assíncronos [C++]"
  - "Classe de CDataPathProperty"
  - "Controladores OLE [C++], assíncrono"
ms.assetid: 1f96efdb-54e4-460b-862c-eba5d4103488
caps.latest.revision: 24
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDataPathProperty
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa uma propriedade do OLE controlador que pode ser carregada de forma assíncrona.  
  
## Sintaxe  
  
```  
class CDataPathProperty : public CAsyncMonikerFile  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDataPathProperty::CDataPathProperty](../Topic/CDataPathProperty::CDataPathProperty.md)|Constrói um objeto de `CDataPathProperty` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDataPathProperty::GetControl](../Topic/CDataPathProperty::GetControl.md)|Recupera o controlador OLE assíncrono associado ao objeto de `CDataPathProperty` .|  
|[CDataPathProperty::GetPath](../Topic/CDataPathProperty::GetPath.md)|Recupera o nome de caminho de propriedade.|  
|[CDataPathProperty::Open](../Topic/CDataPathProperty::Open.md)|Inicia a propriedade de carregamento assíncrono para o controle associado ActiveX \(OLE.\)|  
|[CDataPathProperty::ResetData](../Topic/CDataPathProperty::ResetData.md)|Chama `CAsyncMonikerFile::OnDataAvailable` para notificar o contêiner que propriedades de controle foram alterados.|  
|[CDataPathProperty::SetControl](../Topic/CDataPathProperty::SetControl.md)|Define o controle ActiveX \(OLE\) assíncrono associado com a propriedade.|  
|[CDataPathProperty::SetPath](../Topic/CDataPathProperty::SetPath.md)|Define o nome de caminho de propriedade.|  
  
## Comentários  
 As propriedades assíncronos são carregadas após inicialização síncrona.  
  
 a classe `CDataPathProperty` é derivada de **CAysncMonikerFile**.  Para implementar propriedades assíncrono em seus controladores OLE, derive uma classe de `CDataPathProperty`, e substitua [OnDataAvailable](../Topic/CAsyncMonikerFile::OnDataAvailable.md).  
  
 Para obter mais informações sobre como usar alcunhas assíncronos e controles ActiveX em aplicativos de Internet, consulte os seguintes artigos:  
  
-   [Primeiras etapas da Internet: Controles do ActiveX](../../mfc/activex-controls-on-the-internet.md)  
  
-   [Primeiras etapas da Internet: alcunhas assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../Topic/COleStreamFile%20Class.md)  
  
 [CMonikerFile](../Topic/CMonikerFile%20Class.md)  
  
 [CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)  
  
 `CDataPathProperty`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [O MFC prova a imagem](../../top/visual-cpp-samples.md)   
 [Classe de CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)