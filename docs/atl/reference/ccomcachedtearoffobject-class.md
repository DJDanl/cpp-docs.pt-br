---
title: "Classe de CComCachedTearOffObject | Microsoft Docs"
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
  - "ATL::CComCachedTearOffObject"
  - "ATL.CComCachedTearOffObject"
  - "ATL.CComCachedTearOffObject<contained>"
  - "CComCachedTearOffObject"
  - "ATL::CComCachedTearOffObject<contained>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "cache, Objetos armazenados em cache ATL - fora de rasgo"
  - "Classe de CComCachedTearOffObject"
ms.assetid: ae19507d-a1de-4dbc-a988-da9f75a50c95
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComCachedTearOffObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) para uma interface de rasgo \- fora.  
  
## Sintaxe  
  
```  
  
      template <  
   class contained  
>  
class CComCachedTearOffObject : public IUnknown,  
   public CComObjectRootEx< contained::_ThreadModel::ThreadModelNoCS >  
```  
  
#### Parâmetros  
 `contained`  
 Seus classe de rasgo \- desligado, derivados de `CComTearOffObjectBase` e interfaces você desejar que o objeto de rasgo \- fora ao suporte.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCachedTearOffObject::CComCachedTearOffObject](../Topic/CComCachedTearOffObject::CComCachedTearOffObject.md)|o construtor.|  
|[CComCachedTearOffObject:: ~ CComCachedTearOffObject](../Topic/CComCachedTearOffObject::~CComCachedTearOffObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCachedTearOffObject::AddRef](../Topic/CComCachedTearOffObject::AddRef.md)|Sai contagem de referência para um objeto de `CComCachedTearOffObject` .|  
|[CComCachedTearOffObject::FinalConstruct](../Topic/CComCachedTearOffObject::FinalConstruct.md)|`m_contained::FinalConstruct` \(chama o método de classes de rasgo \- fora\).|  
|[CComCachedTearOffObject::FinalRelease](../Topic/CComCachedTearOffObject::FinalRelease.md)|`m_contained::FinalRelease` \(chama o método de classes de rasgo \- fora\).|  
|[CComCachedTearOffObject::QueryInterface](../Topic/CComCachedTearOffObject::QueryInterface.md)|Retorna um ponteiro para `IUnknown` do objeto de `CComCachedTearOffObject` , ou para a interface solicitada em sua classe de rasgo \- fora \(a classe `contained`\).|  
|[CComCachedTearOffObject::Release](../Topic/CComCachedTearOffObject::Release.md)|Diminui a contagem de referência para um objeto de `CComCachedTearOffObject` e destrói\-a se a contagem de referência é 0.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComCachedTearOffObject::m\_contained](../Topic/CComCachedTearOffObject::m_contained.md)|Um objeto de `CComContainedObject` derivado da classe de rasgo \- fora \(a classe `contained`\).|  
  
## Comentários  
 Implementa [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) de`CComCachedTearOffObject` para uma interface de rasgo \- fora.  Essa classe é diferente de `CComTearOffObject` que `CComCachedTearOffObject` tem seu próprio **IUnknown**, separado de **IUnknown** do objeto do proprietário \(o proprietário é o objeto para que o rasgo \- fora está sendo criado.\)  `CComCachedTearOffObject` mantém sua própria contagem de referência em seu **IUnknown** e exclui\-se uma vez que a contagem de referência é zero.  Em o entanto, se você vir para algumas de suas interfaces de rasgo \- desligado, contagem de referência de **IUnknown** do objeto do proprietário. será incrementada  
  
 Se o objeto de `CComCachedTearOffObject` que implementa o rasgo \- fora é instanciada já, e a interface de rasgo \- fora é consultada para novamente, o mesmo objeto de `CComCachedTearOffObject` está reutilizado.  Por outro lado, se uma interface de rasgo \- fora implementada por `CComTearOffObject` é consultada novamente para através do objeto do proprietário, outro `CComTearOffObject` será instanciado.  
  
 A classe do proprietário deve implementar `FinalRelease` e chamar **Versão** em **IUnknown** armazenado em cache para `CComCachedTearOffObject`, que decrescerão a contagem de referência.  Isso fará com que `FinalRelease` de `CComCachedTearOffObject` a ser chamado e excluirá o rasgo \- fora.  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 `IUnknown`  
  
 `CComCachedTearOffObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComTearOffObject](../../atl/reference/ccomtearoffobject-class.md)   
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)