---
title: "Classe de COleTemplateServer | Microsoft Docs"
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
  - "COleTemplateServer"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Servidores de automação [C++], implementando"
  - "Classe de COleTemplateServer"
  - "contêineres de link [C++]"
  - "Contêiner VELHOS de link"
  - "Os aplicativos de servidor VELHOS, Classe de COleTemplateServer"
  - "Os aplicativos de servidor VELHOS, gerenciando documentos de servidor"
  - "servidores, O OLE"
  - "edição visual, servidores"
ms.assetid: 47a2887d-8162-4993-a842-a784177c7f5c
caps.latest.revision: 23
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de COleTemplateServer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado para servidores visuais VELHOS de edição, servidores de automação, e contêiner de link \(aplicativos que links de suporte a incorporações\).  
  
## Sintaxe  
  
```  
class COleTemplateServer : public COleObjectFactory  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleTemplateServer::COleTemplateServer](../Topic/COleTemplateServer::COleTemplateServer.md)|Constrói um objeto de `COleTemplateServer` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[COleTemplateServer::ConnectTemplate](../Topic/COleTemplateServer::ConnectTemplate.md)|Conecta um modelo de documento ao objeto subjacente de `COleObjectFactory` .|  
|[COleTemplateServer::Unregister](../Topic/COleTemplateServer::Unregister.md)|Desregistre o modelo associado do documento.|  
|[COleTemplateServer::UpdateRegistry](../Topic/COleTemplateServer::UpdateRegistry.md)|Registra o tipo de documento com o Registro do sistema OLE.|  
  
## Comentários  
 Essa classe é derivada da classe; [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)em geral, você pode usar `COleTemplateServer` diretamente em vez de derivar sua própria classe.  `COleTemplateServer` usa um objeto de [CDocTemplate](../../mfc/reference/cdoctemplate-class.md) para gerenciar os documentos do servidor.  Use `COleTemplateServer` ao implementar um servidor completo, isto é, um servidor que pode ser executado como um aplicativo autônomo.  Servidores completos são normalmente aplicativos de \(MDI\) de interface de documentos múltiplos, embora os aplicativos de \(SDI\) de interface do documento único são suportados.  Um objeto de `COleTemplateServer` é necessário para cada tipo de documento de servidor suporte de um aplicativo; isto é, se seu aplicativo para servidores oferece suporte ambas as planilhas e elementos gráficos, você deve ter dois objetos de `COleTemplateServer` .  
  
 `COleTemplateServer` substitui a função de membro de `OnCreateInstance` definida por `COleObjectFactory`.  Essa função de membro é chamada pela estrutura para criar o objeto de C\+\+ do tipo apropriado.  
  
 Para obter mais informações sobre servidores, consulte o artigo [servidores: implementando um servidor](../../mfc/servers-implementing-a-server.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 [CCmdTarget](../Topic/CCmdTarget%20Class.md)  
  
 [COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)  
  
 `COleTemplateServer`  
  
## Requisitos  
 **Cabeçalho:** afxdisp.h  
  
## Consulte também  
 [Exemplo HIERSVR MFC](../../top/visual-cpp-samples.md)   
 [Classe de COleObjectFactory](../../mfc/reference/coleobjectfactory-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de COleServerDoc](../Topic/COleServerDoc%20Class.md)   
 [Classe de COleServerItem](../../mfc/reference/coleserveritem-class.md)