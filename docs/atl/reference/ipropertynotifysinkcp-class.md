---
title: "Classe de IPropertyNotifySinkCP | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "IPropertyNotifySinkCP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pontos de conexão [C++], gerenciando"
  - "Classe de IPropertyNotifySinkCP"
  - "dissipadores, notificação de alterações"
ms.assetid: 1b41445e-bc88-4fa6-bb62-d68aacec2bd5
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IPropertyNotifySinkCP
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe expõe a interface de [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) como uma interface de saída em um objeto ajustável.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      , class  
      CDV   
      = CComDynamicUnkArray >  
class IPropertyNotifySinkCP :   
public IConnectionPointImpl< T, &IID_IPropertyNotifySink, CDV>  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IPropertyNotifySinkCP`.  
  
 `CDV`  
 Uma classe que gerencia as conexões entre um ponto de conexão e seus dissipadores.  o valor padrão é [CComDynamicUnkArray](../Topic/CComDynamicUnkArray%20Class.md), que permite conexões ilimitados.  Você também pode usar [CComUnkArray](../../atl/reference/ccomunkarray-class.md), que especifica um número fixo de conexões.  
  
## Comentários  
 `IPropertyNotifySinkCP` herda todos os métodos através da sua classe base, [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md).  
  
 A interface de [IPropertyNotifySink](http://msdn.microsoft.com/library/windows/desktop/ms692638) permite que um objeto do coletor receba notificações sobre alterações de propriedade.  A classe `IPropertyNotifySinkCP` esta interface expõe como uma interface de saída em um objeto ajustável.  O cliente deve implementar métodos de `IPropertyNotifySink` no coletor.  
  
 Derivado da classe de `IPropertyNotifySinkCP` quando você deseja criar um ponto de conexão que representa a interface de `IPropertyNotifySink` .  
  
 Para obter mais informações sobre como usar pontos de conexão em ATL, consulte o artigo [pontos de conexão](../../atl/atl-connection-points.md).  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md)   
 [Classe de IConnectionPointContainerImpl](../Topic/IConnectionPointContainerImpl%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)