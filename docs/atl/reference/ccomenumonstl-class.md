---
title: "Classe de CComEnumOnSTL | Microsoft Docs"
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
  - "CComEnumOnSTL"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComEnumOnSTL"
ms.assetid: befe1a44-7a00-4f28-9a2e-cc0fa526643c
caps.latest.revision: 21
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComEnumOnSTL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe define um objeto enumerator COM com base em uma coleção de STL.  
  
## Sintaxe  
  
```  
  
      template <  
   class Base,  
   const IID* piid,  
   class T,  
   class Copy,  
   class CollType,  
   class ThreadModel = CComObjectThreadModel  
>  
class ATL_NO_VTABLE CComEnumOnSTL :  
   public IEnumOnSTLImpl<Base, piid, T, Copy, CollType>,  
   public CComObjectRootEx< ThreadModel >  
```  
  
#### Parâmetros  
 `Base`  
 Uma interface de enumerador COM \([IEnumXXXX](https://msdn.microsoft.com/en-us/library/ms680089.aspx)\).  
  
 `piid`  
 Um ponteiro para o interface identificação da interface de enumeração.  
  
 `T`  
 O tipo de item exposto pela interface de enumeração.  
  
 `Copy`  
 Uma classe de [diretiva de impressão](../Topic/ATL%20Copy%20Policy%20Classes.md) .  
  
 `CollType`  
 Uma classe do contêiner de STL.  
  
## Comentários  
 `CComEnumOnSTL` define um objeto enumerator COM com base em uma coleção de STL.  Essa classe pode ser usada em seus próprios ou em conjunto com [ICollectionOnSTLImpl](../../atl/reference/icollectiononstlimpl-class.md).  As etapas típicas para usar essa classe são descritas abaixo.  Para obter mais informações, consulte [coleções e enumeradores de ATL](../../atl/atl-collections-and-enumerators.md).  
  
## Para usar esta classe com ICollectionOnSTLImpl:  
  
-   `typedef` uma especialização de essa classe.  
  
-   Use `typedef` como o argumento final do modelo em uma especialização de `ICollectionOnSTLImpl`.  
  
 [coleções e enumeradores de ATL](../../atl/atl-collections-and-enumerators.md) consulte para um exemplo.  
  
## Para usar esta classe independentemente de ICollectionOnSTLImpl:  
  
-   `typedef` uma especialização de essa classe.  
  
-   Use `typedef` como o argumento do modelo em uma especialização de `CComObject`.  
  
-   Crie uma instância de especialização de `CComObject` .  
  
-   Inicializar o objeto enumerator chamando [IEnumOnSTLImpl::Init](../Topic/IEnumOnSTLImpl::Init.md).  
  
-   Retornar a interface do enumerador para o cliente.  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 `Base`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)  
  
 `CComEnumOnSTL`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Exemplo  
 O código mostrado abaixo fornece uma função genérico para manipular a criação e a inicialização de um objeto enumerator:  
  
 [!code-cpp[NVC_ATL_COM#34](../../atl/codesnippet/CPP/ccomenumonstl-class_1.h)]  
  
 Essa função de modelo pode ser usada para implementar como mostrado a propriedade de `_NewEnum` de uma interface de coleção abaixo:  
  
 [!code-cpp[NVC_ATL_COM#35](../../atl/codesnippet/CPP/ccomenumonstl-class_2.h)]  
  
 Esse código cria `typedef` para `CComEnumOnSTL` que expõe um vetor de `CComVariant`s por meio da interface de **IEnumVariant** .  A classe de **CVariantCollection** especializa simplesmente **CreateSTLEnumerator** para trabalhar com objetos de enumerador de esse tipo.  
  
## Consulte também  
 [exemplo de ATLCollections: Demonstra ICollectionOnSTLImpl, CComEnumOnSTL, e classes personalizadas da diretiva de impressão](../../top/visual-cpp-samples.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [CComObjectThreadModel](../Topic/CComObjectThreadModel.md)   
 [Classe de IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)   
 [IEnumOnSTLImpl](../../atl/reference/ienumonstlimpl-class.md)