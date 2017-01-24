---
title: "Classe de CCachedDataPathProperty | Microsoft Docs"
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
  - "CCachedDataPathProperty"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles ActiveX [C++], assíncrono"
  - "controles assíncronos [C++]"
  - "Classe de CCachedDataPathProperty"
  - "a memória arquivos [C++]"
  - "Controladores OLE [C++], assíncrono"
ms.assetid: 0d81356b-4fe5-43f6-aed2-2eb5a5485706
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CCachedDataPathProperty
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa um controlador do OLE que a propriedade transferiu de forma assíncrona e armazenado em um arquivo de memória.  
  
## Sintaxe  
  
```  
class CCachedDataPathProperty : public CDataPathProperty  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCachedDataPathProperty::CCachedDataPathProperty](../Topic/CCachedDataPathProperty::CCachedDataPathProperty.md)|Constrói um objeto de `CCachedDataPathProperty` .|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CCachedDataPathProperty::m\_Cache](../Topic/CCachedDataPathProperty::m_Cache.md)|Objeto de`CMemFile` para armazenar em cache os dados.|  
  
## Comentários  
 Um arquivo é armazenado na memória RAM em vez de no disco e é útil para transfere temporárias rápidas.  
  
 Junto com **CAysncMonikerFile** e `CDataPathProperty`, `CCachedDataPathProperty` fornece a funcionalidade para uso de alcunhas assíncronos controladores no OLE.  Com objetos de `CCachedDataPathProperty` , você pode transferir dados de forma assíncrona de um URL ou da fonte e armazená\-las em um arquivo de memória através da variável de chaves pública de `m_Cache` .  Todos os dados são armazenados no arquivo de memória, e não há necessidade de substituir [OnDataAvailable](../Topic/CAsyncMonikerFile::OnDataAvailable.md) a menos que você deseja ter para notificações e responder.  Por exemplo, se você estiver transferindo um arquivo grande .gif e deseja notificar seu controle que mais chegaram dados e devem se redesenho, substituição `OnDataAvailable` para fazer a notificação.  
  
 a classe `CCachedDataPathProperty` é derivada de `CDataPathProperty`.  
  
 Para obter mais informações sobre como usar alcunhas assíncronos e controles ActiveX em aplicativos de Internet, consulte os seguintes tópicos:  
  
-   [Primeiras etapas da Internet: Controles do ActiveX](../../mfc/activex-controls-on-the-internet.md)  
  
-   [Primeiras etapas da Internet: alcunhas assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CFile](../../mfc/reference/cfile-class.md)  
  
 [COleStreamFile](../Topic/COleStreamFile%20Class.md)  
  
 [CMonikerFile](../Topic/CMonikerFile%20Class.md)  
  
 [CAsyncMonikerFile](../../mfc/reference/casyncmonikerfile-class.md)  
  
 [CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)  
  
 `CCachedDataPathProperty`  
  
## Requisitos  
 **Cabeçalho:** afxctl.h  
  
## Consulte também  
 [Classe de CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)