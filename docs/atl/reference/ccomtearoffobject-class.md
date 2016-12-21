---
title: "Classe de CComTearOffObject | Microsoft Docs"
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
  - "ATL::CComTearOffObject<Base>"
  - "ATL::CComTearOffObject"
  - "ATL.CComTearOffObject"
  - "ATL.CComTearOffObject<Base>"
  - "CComTearOffObject"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComTearOffObject"
  - "interfaces - fora de rasgo"
  - "interfaces - fora de rasgo, ATL"
ms.assetid: d974b598-c6b2-42b1-8360-9190d9d0fbf3
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComTearOffObject
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa uma interface de rasgo \- fora.  
  
## Sintaxe  
  
```  
  
      template<  
   class Base   
>  
class CComTearOffObject :  
   public Base  
```  
  
#### Parâmetros  
 `Base`  
 Seus classe de rasgo \- desligado, derivados de `CComTearOffObjectBase` e interfaces você desejar que o objeto de rasgo \- fora ao suporte.  
  
 ATL implementa as interfaces de rasgo \- fora de duas fases — os métodos de `CComTearOffObjectBase` manipulam a contagem e `QueryInterface`de referência, quando `CComTearOffObject` implementar [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509).  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComTearOffObject::CComTearOffObject](../Topic/CComTearOffObject::CComTearOffObject.md)|o construtor.|  
|[CComTearOffObject::~CComTearOffObject](../Topic/CComTearOffObject::~CComTearOffObject.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComTearOffObject::AddRef](../Topic/CComTearOffObject::AddRef.md)|Sai contagem de referência para um objeto de `CComTearOffObject` .|  
|[CComTearOffObject::QueryInterface](../Topic/CComTearOffObject::QueryInterface.md)|Retorna um ponteiro para a interface solicitada em sua classe de rasgo \- fora ou na classe do proprietário.|  
|[CComTearOffObject::Release](../Topic/CComTearOffObject::Release.md)|Diminui a contagem de referência para um objeto de `CComTearOffObject` e destrói\-a.|  
  
### Métodos de CComTearOffObjectBase  
  
|||  
|-|-|  
|[CComTearOffObjectBase](../Topic/CComTearOffObject::CComTearOffObjectBase.md)|Construtor.|  
  
### Membros de dados de CComTearOffObjectBase  
  
|||  
|-|-|  
|[m\_pOwner](../Topic/CComTearOffObject::m_pOwner.md)|Um ponteiro para `CComObject` derivado da classe do proprietário.|  
  
## Comentários  
 `CComTearOffObject` implementa uma interface de rasgo \- fora como um objeto separado que é instanciado somente quando essa interface é consultada para.  O rasgo \- fora é excluído quando a contagem de referência se torna zero.  Normalmente, você cria uma interface de rasgo \- fora de uma interface que é usada com pouca freqüência, como o uso de um rasgo \- fora salva um ponteiro vtable em todas as instâncias do seu objeto principal.  
  
 Você deve derivar da classe que implementa o rasgo \- fora de `CComTearOffObjectBase` e qualquer interfaces você desejar que o objeto de rasgo \- fora ao suporte.  `CComTearOffObjectBase` templatized na classe do proprietário e no modelo de threads.  A classe do proprietário é a classe de objeto para um rasgo \- fora está sendo implementado.  Se você não especificar um modelo de threads, o modelo de segmento é usado.  
  
 Você deve criar um mapa COM para sua classe de rasgo \- fora.  Quando ATL cria uma instância do rasgo \- desligado, criará **CComTearOffObject\<CYourTearOffClass\>** ou **CComCachedTearOffObject\<CYourTearOffClass\>**.  
  
 Por exemplo, no exemplo de SINALIZADOR, a classe de `CBeeper2` é a classe de rasgo \- fora e a classe de `CBeeper` é a classe do proprietário:  
  
 [!code-cpp[NVC_ATL_COM#43](../../atl/codesnippet/CPP/ccomtearoffobject-class_1.h)]  
  
## Hierarquia de herança  
 `Base`  
  
 `CComTearOffObject`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComCachedTearOffObject](../../atl/reference/ccomcachedtearoffobject-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)