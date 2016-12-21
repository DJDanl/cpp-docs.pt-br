---
title: "Op&#231;&#245;es, assistente simples de objeto de ATL | Microsoft Docs"
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
  - "vc.codewiz.class.atl.simple.options"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente simples de objeto de ATL, options"
ms.assetid: 125fe179-942d-4181-8b82-33e92e1fd779
caps.latest.revision: 14
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Op&#231;&#245;es, assistente simples de objeto de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente simples de objeto de ATL o design para suporte gerado e a eficiência de erro para o objeto.  
  
 Para obter mais informações sobre projetos de ATL e classes de ATL COM [Componentes da área de trabalho COM ATL](../../atl/atl-com-desktop-components.md), consulte.  
  
 **Threading model**  
 Indica o método para gerenciar segmentos.  Por padrão, o projeto usa **Apartment** threads.  
  
 Consulte [Especificando o modelo de segmentação do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para mais informações.  
  
|Opção|Descrição|  
|-----------|---------------|  
|`Single`|Especifica que o objeto sempre executa no segmento principal COM.  Consulte [Construção de thread única](http://msdn.microsoft.com/library/windows/desktop/ms680112) e [InprocServer32](http://msdn.microsoft.com/library/windows/desktop/ms682390) para mais informações.|  
|**Apartment**|Especifica que o objeto usa o Apartment threads.  Equivalente para escolher o compartimento de segmento.  Cada objeto de um componente de apartamento\- é atribuído um compartimento para o segmento, durante a vida útil do objeto; no entanto, vários segmentos podem ser usados para vários objetos.  Cada apartment é vinculado a um determinado segmento e tem uma mensagem bomba do windows \(padrão\).<br /><br /> Consulte [Construção de thread única](http://msdn.microsoft.com/library/windows/desktop/ms680112) para mais informações.|  
|**Ambos**|Especifica que o objeto pode usar o apartment ou livre segmentação, dependendo do tipo de um segmento é criado.|  
|**Livre**|Especifica que o objeto liberam segmentação.  Segmentação livre é equivalente a um modelo multithread apartment.  Consulte [Construção multisegmentados](http://msdn.microsoft.com/library/windows/desktop/ms693421) para mais informações.|  
|**Neutro** Windows 2000 \(somente\)|Especifica que o objeto siga as diretrizes para construção de vários segmentos, mas pode executar em qualquer tipo de segmento.|  
  
 **Aggregation**  
 Indica se o objeto [agregado](http://msdn.microsoft.com/library/windows/desktop/ms686558).  O objeto agregado escolher que interfaces para expor os clientes, e interfaces são expostos como se o objeto agregado os implementou.  Os clientes do objeto agregado se comunicam somente com o objeto agregado.  
  
|Opção|Descrição|  
|-----------|---------------|  
|Sim|Especifica que o objeto pode ser agregado.  a opção.|  
|Não|Especifica que o objeto não é agregado.|  
|Somente|Especifica que o objeto deve ser agregado.|  
  
 **Interface**  
 Indica que o tipo de interface que o objeto suporta.  Por padrão, o objeto suporta uma interface dupla.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Double**|Especifica que o objeto suporta uma interface dupla \(o vtable tem funções personalizados de interface mais métodos de `IDispatch` de associação tardia\).  Permite que clientes e [Controladores de automação](../../mfc/automation-clients.md) COM acessem o objeto.  a opção.|  
|**Personalizado**|Especifica que o objeto suporta uma interface \(o vtable tem funções personalizados de interface\).  Uma interface pode ser mais rápido do que uma interface dupla, especialmente através dos limites de processo.<br /><br /> -   **Automation compatible** permite que os controladores de automação de acessar um objeto que tenha suporte personalizado de interface.|  
  
 **Suporte**  
 Indica suporte adicional para o objeto.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**ISupportErrorInfo**|Cria suporte para a interface de [ISupportErrorInfo](../../atl/reference/isupporterrorinfoimpl-class.md) assim que o objeto pode retornar informações de erro para o cliente.|  
|**Pontos de conexão**|Permite pontos de conexão para o objeto fazendo a classe de objeto derivam de [IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md).|  
|**o empacotador de segmentação livre**|Cria um objeto de segmentação livre de marshaler para ponteiros da interface de empacotar forma eficiente entre segmentos no mesmo processo.  Disponível para **Ambos** objeto especificando como o modelo.|  
|**IObjectWithSite \(suporte do objeto de IE\)**|Implementa [IObjectWithSiteImpl](../../atl/reference/iobjectwithsiteimpl-class.md), que fornece uma maneira simples para oferecer suporte a comunicação entre um objeto e seu site em um contêiner.|  
  
## Consulte também  
 [Assistente simples de objeto de ATL](../../atl/reference/atl-simple-object-wizard.md)   
 [Objeto simples de ATL](../../atl/reference/adding-an-atl-simple-object.md)   
 [Problemas de threads em processo do servidor](http://msdn.microsoft.com/library/windows/desktop/ms687205)