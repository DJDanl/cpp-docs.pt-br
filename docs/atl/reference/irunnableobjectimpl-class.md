---
title: "Classe de IRunnableObjectImpl | Microsoft Docs"
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
  - "IRunnableObjectImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "contêiner, controles em execução"
  - "controles [ATL], executando"
  - "controles [C++], execução do recipiente em ATL"
  - "IRunnableObject, Implementação de ATL"
  - "Classe de IRunnableObjectImpl"
ms.assetid: 305c7c3b-889e-49dd-aca1-34379c1b9931
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IRunnableObjectImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa **IUnknown** e fornece uma implementação padrão de interface de [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) .  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template< class   
      T  
      >  
class IRunnableObjectImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IRunnableObjectImpl`.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IRunnableObjectImpl::GetRunningClass](../Topic/IRunnableObjectImpl::GetRunningClass.md)|Retorna o CLSID do controle em execução.  A implementação de ATL define o CLSID a `GUID_NULL` e retorna **E\_UNEXPECTED**.|  
|[IRunnableObjectImpl::IsRunning](../Topic/IRunnableObjectImpl::IsRunning.md)|Determina se o controle está sendo executado.  a implementação de ATL retorna **Verdadeiro**.|  
|[IRunnableObjectImpl::LockRunning](../Topic/IRunnableObjectImpl::LockRunning.md)|Bloqueia o controle no estado em execução.  a implementação de ATL retorna `S_OK`.|  
|[IRunnableObjectImpl::Run](../Topic/IRunnableObjectImpl::Run.md)|Força o controle para executar.  a implementação de ATL retorna `S_OK`.|  
|[IRunnableObjectImpl::SetContainedObject](../Topic/IRunnableObjectImpl::SetContainedObject.md)|Indica que o controle está inserido.  a implementação de ATL retorna `S_OK`.|  
  
## Comentários  
 A interface de [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) permite que um contêiner para determinar se um controle está sendo executado, força para executar, ou bloquear\-lo no estado em execução.  A classe `IRunnableObjectImpl` fornece uma implementação padrão de esta interface e implementa **IUnknown** enviar informações para o dispositivo de despejo em compilações de depuração.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IRunnableObject`  
  
 `IRunnableObjectImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)