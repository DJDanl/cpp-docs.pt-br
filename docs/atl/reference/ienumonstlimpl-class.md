---
title: "Classe de IEnumOnSTLImpl | Microsoft Docs"
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
  - "IEnumOnSTLImpl"
  - "ATL.IEnumOnSTLImpl"
  - "ATL::IEnumOnSTLImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de IEnumOnSTLImpl"
ms.assetid: 1789e77b-88b8-447d-a490-806b918912ce
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IEnumOnSTLImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe define uma interface de enumerador com base em uma coleção de STL.  
  
## Sintaxe  
  
```  
  
      template <  
   class Base,  
   const IID* piid,  
   class T,  
   class Copy,  
   class CollType  
>  
class ATL_NO_VTABLE IEnumOnSTLImpl :  
   public Base  
```  
  
#### Parâmetros  
 `Base`  
 Uma interface de enumerador COM \([IEnumXXXX](https://msdn.microsoft.com/en-us/library/ms680089.aspx)\).  
  
 `piid`  
 Um ponteiro para o interface identificação da interface de enumeração.  
  
 `T`  
 O tipo de item exposto pela interface de enumeração.  
  
 `Copy`  
 [classe de diretiva de impressão](../Topic/ATL%20Copy%20Policy%20Classes.md).  
  
 `CollType`  
 Uma classe do contêiner de STL.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IEnumOnSTLImpl::Clone](../Topic/IEnumOnSTLImpl::Clone.md)|A implementação de [IEnumXXXX::Clone](https://msdn.microsoft.com/en-us/library/ms690336.aspx).|  
|[IEnumOnSTLImpl::Init](../Topic/IEnumOnSTLImpl::Init.md)|Inicializa o enumerador.|  
|[IEnumOnSTLImpl::Next](../Topic/IEnumOnSTLImpl::Next.md)|A implementação de [IEnumXXXX::Next](https://msdn.microsoft.com/en-us/library/ms695273.aspx).|  
|[IEnumOnSTLImpl::Reset](../Topic/IEnumOnSTLImpl::Reset.md)|A implementação de [IEnumXXXX::Reset](https://msdn.microsoft.com/en-us/library/ms693414.aspx).|  
|[IEnumOnSTLImpl::Skip](../Topic/IEnumOnSTLImpl::Skip.md)|A implementação de [IEnumXXXX::Skip](https://msdn.microsoft.com/en-us/library/ms690392.aspx).|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[IEnumOnSTLImpl::m\_iter](../Topic/IEnumOnSTLImpl::m_iter.md)|O iterador que representa a posição atual do enumerador dentro da coleção.|  
|[IEnumOnSTLImpl::m\_pcollection](../Topic/IEnumOnSTLImpl::m_pcollection.md)|Um ponteiro para o contêiner de STL que contém os itens a serem enumerados.|  
|[IEnumOnSTLImpl::m\_spUnk](../Topic/IEnumOnSTLImpl::m_spUnk.md)|O ponteiro de **IUnknown** de objeto que fornece a coleção.|  
  
## Comentários  
 `IEnumOnSTLImpl` fornece a implementação para uma interface de enumerador COM onde os itens que estão sendo enumerados sejam armazenados em um contêiner STL\- correspondente.  Essa classe é análoga a classe de [CComEnumImpl](../../atl/reference/ccomenumimpl-class.md) , que fornece uma implementação de uma interface enumerator com base em uma matriz.  
  
> [!NOTE]
>  Consulte [CComEnumImpl::Init](../Topic/CComEnumImpl::Init.md) para obter detalhes sobre as diferenças entre `CComEnumImpl` adicionais e `IEnumOnSTLImpl`.  
  
 Normalmente, você *não* precisará criar sua própria classe de enumerador derivando de essa implementação da interface.  Se você desejar usar um enumerador ATL\- fornecido com base em um recipiente de STL, é mais comum criar uma instância de [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md), ou criar uma classe de coleção que retorna um enumerador derivando de [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md).  
  
 Em o entanto, se você precisar fornecer um enumerador personalizado \(por exemplo, um que expõe interfaces além da interface de enumerador\), você pode derivar da classe.  Em esta situação é provável que você precisará substituir o método de [clone](../Topic/IEnumOnSTLImpl::Clone.md) para fornecer sua própria implementação.  
  
## Hierarquia de herança  
 `Base`  
  
 `IEnumOnSTLImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)