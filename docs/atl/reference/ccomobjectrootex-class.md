---
title: "Classe de CComObjectRootEx | Microsoft Docs"
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
  - "ATL.CComObjectRootEx"
  - "ATL::CComObjectRootEx<ThreadModel>"
  - "CComObjectRootEx"
  - "ATL::CComObjectRootEx"
  - "ATL.CComObjectRootEx<ThreadModel>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "contagem de referência"
ms.assetid: 894a3d7c-2daf-4fd0-8fa4-e6a05bcfb631
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComObjectRootEx
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciamento de contagem de referência de objeto de forma para objetos nonaggregated e agregados.  
  
## Sintaxe  
  
```  
  
      template<  
   class ThreadModel   
>  
class CComObjectRootEx : public CComObjectRootBase  
```  
  
#### Parâmetros  
 `ThreadModel`  
 A classe cujos métodos implementam o modelo de threads desejado.  Você pode escolher explicitamente o modelo de threads definindo `ThreadModel` a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md), a [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), ou a [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md).  Você pode aceitar o modelo de threads do servidor `ThreadModel` definindo a [CComObjectThreadModel](../Topic/CComObjectThreadModel.md) ou a [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md).  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[CComObjectRootEx](../Topic/CComObjectRootEx::CComObjectRootEx.md)|Construtor.|  
|[InternalAddRef](../Topic/CComObjectRootEx::InternalAddRef.md)|Sai contagem de referência para um objeto nonaggregated.|  
|[InternalRelease](../Topic/CComObjectRootEx::InternalRelease.md)|Diminui a contagem de referência para um objeto nonaggregated.|  
|[Bloquear](../Topic/CComObjectRootEx::Lock.md)|Se o modelo de segmentos são multithread, obtenha a propriedade de um objeto de seção crítica.|  
|[Unlock](../Topic/CComObjectRootEx::Unlock.md)|Se o modelo de segmentos são multithread, libera a propriedade de um objeto de seção crítica.|  
  
### Métodos de CComObjectRootBase  
  
|||  
|-|-|  
|[FinalConstruct](../Topic/CComObjectRootEx::FinalConstruct.md)|Substituição em sua classe para executar algumas inicialização exigida pelo seu objeto.|  
|[FinalRelease](../Topic/CComObjectRootEx::FinalRelease.md)|Substituição em sua classe para executar qualquer limpeza exigida pelo seu objeto.|  
|[OuterAddRef](../Topic/CComObjectRootEx::OuterAddRef.md)|Sai contagem de referência para um objeto agregado.|  
|[OuterQueryInterface](../Topic/CComObjectRootEx::OuterQueryInterface.md)|Delegados a **IUnknown** externa de um objeto agregado.|  
|[OuterRelease](../Topic/CComObjectRootEx::OuterRelease.md)|Diminui a contagem de referência para um objeto agregado.|  
  
### Funções estáticas  
  
|||  
|-|-|  
|[InternalQueryInterface](../Topic/CComObjectRootEx::InternalQueryInterface.md)|Delegados a **IUnknown** de um objeto nonaggregated.|  
|[ObjectMain](../Topic/CComObjectRootEx::ObjectMain.md)|Chamado durante a inicialização e o término do módulo para classes derivadas listados no mapa do objeto.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_dwRef](../Topic/CComObjectRootEx::m_dwRef.md)|Com `m_pOuterUnknown`, parte de uma união.  Usado quando o objeto não é agregado para armazenar a contagem de referência de `AddRef` e de **Versão**.|  
|[m\_pOuterUnknown](../Topic/CComObjectRootEx::m_pOuterUnknown.md)|Com `m_dwRef`, parte de uma união.  Usado quando o objeto está agregado armazenar um ponteiro para o desconhecido externo.|  
  
## Comentários  
 As alças de`CComObjectRootEx` manipula o gerenciamento de contagem de referência para objetos nonaggregated e agregados.  Ele contém a contagem de referência de objeto se o objeto não está sendo agregado, e mantém o ponteiro ao desconhecido externo se o objeto está sendo agregado.  Para objetos agregados, os métodos de `CComObjectRootEx` podem ser usados para manipular a falha do objeto interno para a compilação, e para proteger o objeto externo de exclusão quando as interfaces são liberadas internas ou o objeto interno é excluído.  
  
 Uma classe que implementa um servidor de `CComObjectRootEx` COM deve herdar de ou de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md).  
  
 Se sua definição de classe especifica a macro de [DECLARE\_POLY\_AGGREGATABLE](../Topic/DECLARE_POLY_AGGREGATABLE.md) , ATL cria uma instância de **CComPolyObject\<CYourClass\>** quando **IClassFactory::CreateInstance** é chamado.  Durante a criação, o valor de desconhecido externo é verificado.  Se é **NULO**, **IUnknown** é implementado para um objeto nonaggregated.  Se o não externo não é **NULO**, **IUnknown** é implementado para um objeto agregado.  
  
 Se a classe não especifica a macro de `DECLARE_POLY_AGGREGATABLE` , ATL cria uma instância de **CAggComObject\<CYourClass\>** para objetos agregados ou uma instância de **CComObject\<CYourClass\>** para objetos nonaggregated.  
  
 A vantagem de usar `CComPolyObject` é que você evita ter `CComAggObject` e `CComObject` em seu módulo para manipular o caso agregados e nonaggregated.  Identificadores únicos de objeto de `CComPolyObject` ambos os casos.  Portanto, somente uma cópia de vtable e uma cópia das funções existem no seu módulo.  Se seu vtable é grande, isso pode reduzir significativamente o tamanho do módulo.  Em o entanto, se seu vtable é pequeno, usar `CComPolyObject` pode resultar em um tamanho maior um pouco de módulo porque não é otimizado para um objeto agregado ou nonaggregated, como é `CComAggObject` e `CComObject`.  
  
 Se o objeto é agregado, [IUnknown](http://msdn.microsoft.com/library/windows/desktop/ms680509) é implementado por `CComAggObject` ou por `CComPolyObject`.  Essas classes representante `QueryInterface`, `AddRef`, e chamadas de **Versão** a `OuterQueryInterface`, a `OuterAddRef`, e a `OuterRelease` de `CComObjectRootEx` para encaminhar ao desconhecido externo.  Normalmente, você substitui `CComObjectRootEx::FinalConstruct` em sua classe para criar todos os objetos agregados, e substitui `CComObjectRootEx::FinalRelease` para liberar quaisquer objetos agregados.  
  
 Se o objeto não é agregado, **IUnknown** é implementado por `CComObject` ou por `CComPolyObject`.  Em esse caso, chamadas a `QueryInterface`, `AddRef`, e **Versão** são delegados a `InternalQueryInterface`, a `InternalAddRef`, e a `InternalRelease` de `CComObjectRootEx` para executar operações reais.  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe de CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe de CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)