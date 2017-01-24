---
title: "Op&#231;&#245;es do assistente, componente da p&#225;gina de ATL Active Server | Microsoft Docs"
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
  - "vc.codewiz.class.atl.asp.options"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente do componente da página de ATL Active Server, options"
ms.assetid: 54f34e26-53c7-4456-9675-cb86e356bde0
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Op&#231;&#245;es do assistente, componente da p&#225;gina de ATL Active Server
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente componente da página de ATL Active Server para criar para suporte gerado e a eficiência de erro para o objeto.  
  
 Para obter mais informações sobre projetos de ATL e classes de ATL COM [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md), consulte.  
  
 **Threading model**  
 Indica o método para gerenciar segmentos.  Por padrão, o projeto usa **Apartment** threads.  
  
 Consulte [Especificando o modelo de segmentação do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para mais informações.  
  
|Opção|Descrição|  
|-----------|---------------|  
|`Single`|Especifica que o objeto único o modelo.  Em o único modelo de threads, um objeto sempre executa no segmento principal COM.  Consulte [Construção de thread única](http://msdn.microsoft.com/library/windows/desktop/ms680112) e [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) para mais informações.|  
|**Apartment**|Especifica que o objeto usa o Apartment threads.  Equivalente para escolher o compartimento de segmento.  Cada objeto de um componente de apartamento\- é atribuído um compartimento para o segmento, durante a vida útil do objeto; no entanto, vários segmentos podem ser usados para vários objetos.  Cada apartment é vinculado a um determinado segmento e tem uma mensagem bomba do windows \(padrão\).<br /><br /> Consulte [Construção de thread única](http://msdn.microsoft.com/library/windows/desktop/ms680112) para mais informações.|  
|**Ambos**|Especifica que o objeto pode usar o apartment ou livre segmentação, dependendo do tipo de um segmento é criado.|  
|**Livre**|Especifica que o objeto liberam segmentação.  Segmentação livre é equivalente a um modelo multithread apartment.  Consulte [Construção multisegmentados](http://msdn.microsoft.com/library/windows/desktop/ms693421) para mais informações.|  
|**Neutro** \(somente Windows 2000\)|Especifica que o objeto siga as diretrizes para construção de vários segmentos, mas pode executar em qualquer tipo de segmento.|  
  
 **Aggregation**  
 Indica se o objeto [agregado](http://msdn.microsoft.com/library/windows/desktop/ms686558).  O objeto agregado escolher que interfaces para expor os clientes, e interfaces são expostos como se o objeto agregado os implementou.  Os clientes do objeto agregado se comunicam somente com o objeto agregado.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Sim**|Especifica que o objeto pode ser agregado.  a opção.|  
|**Não**|Especifica que o objeto não é agregado.|  
|**Somente**|Especifica que o objeto deve ser agregado.|  
  
 **Suporte**  
 \(Descrição do elemento a ser adicionada\)  
  
|Opção|Descrição|  
|-----------|---------------|  
|**ISupportErrorInfo**|Cria suporte para a interface de [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) assim que o objeto pode retornar informações de erro para o cliente.|  
|**Pontos de conexão**|Permite pontos de conexão para o objeto fazendo a classe de objeto derivam de [IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md).|  
|**o empacotador de segmentação livre**|Cria um objeto de segmentação livre de marshaler para ponteiros da interface de empacotar forma eficiente entre segmentos no mesmo processo.  Disponível para o objeto especificando **Ambos** ou **Livre** como o modelo.|  
  
## Consulte também  
 [Assistente do componente da página de ATL Active Server](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente da página de ATL Active Server](../../atl/reference/adding-an-atl-active-server-page-component.md)