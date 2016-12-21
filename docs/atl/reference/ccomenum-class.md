---
title: "Classe de CComEnum | Microsoft Docs"
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
  - "CComEnum"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComEnum"
ms.assetid: bff7dd7b-eb6e-4d6e-96ed-2706e66c8b3b
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComEnum
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe define um objeto enumerator COM com base em uma matriz.  
  
## Sintaxe  
  
```  
  
      template <  
   class Base,  
   const IID* piid,  
   class T,  
   class Copy,  
   class ThreadModel = CcomObjectThreadModel  
>  
class ATL_NO_VTABLE CComEnum :  
   public CComEnumImpl<Base, piid, T, Copy>,  
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
 [copie a classe da diretiva](../Topic/ATL%20Copy%20Policy%20Classes.md)homogêneo.  
  
 `ThreadModel`  
 O modelo de threads da classe.  Este parâmetro tem como padrão o modelo de threads do objeto global usado em seu projeto.  
  
## Comentários  
 `CComEnum` define um objeto enumerator COM com base em uma matriz.  Essa classe é análogo a [CComEnumOnSTL](../../atl/reference/ccomenumonstl-class.md) que implementa um enumerador baseia\-se em um recipiente de STL.  As etapas típicas para usar essa classe são descritas abaixo.  Para obter mais informações, consulte [coleções e enumeradores de ATL](../../atl/atl-collections-and-enumerators.md).  
  
## Para usar esta classe:  
  
-   `typedef` uma especialização de essa classe.  
  
-   Use `typedef` como o argumento do modelo em uma especialização de `CComObject`.  
  
-   Crie uma instância de especialização de `CComObject` .  
  
-   Inicializar o objeto enumerator chamando [CComEnumImpl::Init](../Topic/CComEnumImpl::Init.md).  
  
-   Retornar a interface do enumerador para o cliente.  
  
## Hierarquia de herança  
 `CComObjectRootBase`  
  
 `Base`  
  
 [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)  
  
 [CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)  
  
 `CComEnum`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Exemplo  
 O código mostrado abaixo fornece uma função reutilizável para criar e inicializar um objeto enumerator.  
  
 [!code-cpp[NVC_ATL_COM#32](../../atl/codesnippet/CPP/ccomenum-class_1.h)]  
  
 Essa função de modelo pode ser usada para implementar como mostrado a propriedade de `_NewEnum` de uma interface de coleção abaixo:  
  
 [!code-cpp[NVC_ATL_COM#33](../../atl/codesnippet/CPP/ccomenum-class_2.h)]  
  
 Esse código cria `typedef` para `CComEnum` que expõe um vetor de **VARIANT**s através da interface de **IEnumVariant** .  A classe de **CVariantArrayCollection** especializa simplesmente **CreateEnumerator** para trabalhar com objetos de enumerador de esse tipo e passa os argumentos necessários.  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [CComObjectThreadModel](../Topic/CComObjectThreadModel.md)   
 [Classe de CComEnumImpl](../../atl/reference/ccomenumimpl-class.md)   
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)