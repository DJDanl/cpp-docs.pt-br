---
title: "Classe IAccessorImpl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IAccessorImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe IAccessorImpl"
ms.assetid: 768606da-8b71-417c-a62c-88069ce7730d
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IAccessorImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação da interface de [IAccessor](https://msdn.microsoft.com/en-us/library/ms719672.aspx) .  
  
## Sintaxe  
  
```  
template <  
   class T,   
   class BindType = ATLBINDINGS,   
   class BindingVector = CAtlMap <   
      HACCESSOR hAccessor,   
      BindType* pBindingsStructure   
   >   
>  
class ATL_NO_VTABLE IAccessorImpl : public IAccessorImplBase<BindType>  
```  
  
#### Parâmetros  
 `T`  
 A classe de objeto de conjunto de linhas ou do comando.  
  
 `BindType`  
 Unidade de armazenamento de informações de associação.  O padrão é a estrutura de **ATLBINDINGS** \(consulte atldb.h\).  
  
 `BindingVector`  
 Unidade de armazenamento de informações da coluna.  A opção é [CAtlMap](../../atl/reference/catlmap-class.md) onde o elemento chave é um valor de **HACCESSOR** e o elemento de valor é um ponteiro para uma estrutura de `BindType` .  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)|O construtor.|  
  
### Métodos da interface  
  
|||  
|-|-|  
|[AddRefAccessor](../../data/oledb/iaccessorimpl-addrefaccessor.md)|Adiciona uma contagem de referência a um acessador existente.|  
|[CreateAccessor](../../data/oledb/iaccessorimpl-createaccessor.md)|Cria um acessador de um conjunto de associações.|  
|[GetBindings](../Topic/IAccessorImpl::GetBindings.md)|Retorna as associações em um acessador.|  
|[ReleaseAccessor](../../data/oledb/iaccessorimpl-releaseaccessor.md)|Libera um acessador.|  
  
## Comentários  
 Isso é obrigatório em conjuntos de linhas e em comandos.  Provedores OLE DB requer implementar **HACCESSOR**, que é uma marca a uma matriz de estruturas de [DBBINDING](https://msdn.microsoft.com/en-us/library/ms716845.aspx) .  **HACCESSOR**s é fornecido por `IAccessorImpl` endereços de estruturas de `BindType` .  Por padrão, `BindType` é definido como **ATLBINDINGS** na definição de modelo de `IAccessorImpl` .  `BindType` fornece um mecanismo usado por `IAccessorImpl` para controlar o número de elementos na matriz de **DBBINDING** bem como uma contagem de referência e sinalizadores de acessador.  
  
## Requisitos  
 **Header:** atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)