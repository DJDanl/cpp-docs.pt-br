---
title: "Classe de CComEnumImpl | Microsoft Docs"
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
  - "ATL.CComEnumImpl"
  - "ATL::CComEnumImpl"
  - "CComEnumImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComEnumImpl"
ms.assetid: cc0d8e76-e608-46db-87cd-4c7161fe32d2
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComEnumImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece a implementação de uma interface de enumerador COM onde os itens que estão sendo enumerados sejam armazenados em uma matriz.  
  
## Sintaxe  
  
```  
  
      template <  
   class Base,  
   const IID* piid,  
   class T,  
   class Copy  
>  
class ATL_NO_VTABLE CComEnumImpl :   
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
 [copie a classe da diretiva](../Topic/ATL%20Copy%20Policy%20Classes.md)homogêneo.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComEnumImpl::CComEnumImpl](../Topic/CComEnumImpl::CComEnumImpl.md)|o construtor.|  
|[CComEnumImpl::~CComEnumImpl](../Topic/CComEnumImpl::~CComEnumImpl.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComEnumImpl::Clone](../Topic/CComEnumImpl::Clone.md)|A implementação de [IEnumXXXX::Clone](https://msdn.microsoft.com/en-us/library/ms690336.aspx).|  
|[CComEnumImpl::Init](../Topic/CComEnumImpl::Init.md)|Inicializa o enumerador.|  
|[CComEnumImpl::Next](../Topic/CComEnumImpl::Next.md)|A implementação de [IEnumXXXX::Next](https://msdn.microsoft.com/en-us/library/ms695273.aspx).|  
|[CComEnumImpl::Reset](../Topic/CComEnumImpl::Reset.md)|A implementação de [IEnumXXXX::Reset](https://msdn.microsoft.com/en-us/library/ms693414.aspx).|  
|[CComEnumImpl::Skip](../Topic/CComEnumImpl::Skip.md)|A implementação de [IEnumXXXX::Skip](https://msdn.microsoft.com/en-us/library/ms690392.aspx).|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComEnumImpl::m\_begin](../Topic/CComEnumImpl::m_begin.md)|Um ponteiro para o primeiro item na matriz.|  
|[CComEnumImpl::m\_dwFlags](../Topic/CComEnumImpl::m_dwFlags.md)|Sinalizadores de impressão passados com `Init`.|  
|[CComEnumImpl::m\_end](../Topic/CComEnumImpl::m_end.md)|Um ponteiro para o local apenas além do último item na matriz.|  
|[CComEnumImpl::m\_iter](../Topic/CComEnumImpl::m_iter.md)|Um ponteiro para o item atual na matriz.|  
|[CComEnumImpl::m\_spUnk](../Topic/CComEnumImpl::m_spUnk.md)|O ponteiro de **IUnknown** de objeto que fornece a coleção sendo enumerada.|  
  
## Comentários  
 `CComEnumImpl` fornece a implementação para uma interface de enumerador COM onde os itens que estão sendo enumerados sejam armazenados em uma matriz.  Essa classe é análoga a classe de `IEnumOnSTLImpl` , que fornece uma implementação de uma interface enumerator com base em um recipiente de STL.  
  
> [!NOTE]
>  Para obter detalhes sobre as diferenças entre `CComEnumImpl` adicionais e `IEnumOnSTLImpl`, consulte [CComEnumImpl::Init](../Topic/CComEnumImpl::Init.md).  
  
 Normalmente, você *não* precisará criar sua própria classe de enumerador derivando de essa implementação da interface.  Se você desejar usar um enumerador ATL\- fornecido com base em uma matriz, é mais comum criar uma instância de [CComEnum](../../atl/reference/ccomenum-class.md).  
  
 Em o entanto, se você precisar fornecer um enumerador personalizado \(por exemplo, um que expõe interfaces além da interface de enumerador\), você pode derivar da classe.  Em esta situação, é provável que você precisará substituir o método de [CComEnumImpl::Clone](../Topic/CComEnumImpl::Clone.md) para fornecer sua própria implementação.  
  
 Para obter mais informações, consulte [coleções e enumeradores de ATL](../../atl/atl-collections-and-enumerators.md).  
  
## Hierarquia de herança  
 `Base`  
  
 `CComEnumImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Classe de IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)   
 [Classe de CComEnum](../../atl/reference/ccomenum-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)