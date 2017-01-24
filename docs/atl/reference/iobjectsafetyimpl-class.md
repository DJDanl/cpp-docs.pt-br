---
title: "Classe de IObjectSafetyImpl | Microsoft Docs"
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
  - "IObjectSafetyImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [ATL], seguro"
  - "IObjectSafety, Implementação de ATL"
  - "Classe de IObjectSafetyImpl"
  - "com segurança para o script e a inicialização (controles)"
ms.assetid: 64e32082-d910-4a8a-a5bf-ebed9145359d
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IObjectSafetyImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece uma implementação padrão de interface de `IObjectSafety` para permitir que um cliente recupere e definir níveis de segurança de um objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
  
      template <class   
      T  
      , DWORD   
      dwSupportedSafety  
      >  
class IObjectSafetyImpl  
```  
  
#### Parâmetros  
 `T`  
 Sua classe, derivada de `IObjectSafetyImpl`.  
  
 *dwSupportedSafety*  
 Especifica as opções de segurança suportados para o controle.  Pode ser um dos seguintes valores:  
  
-   **INTERFACESAFE\_FOR\_UNTRUSTED\_CALLER** a interface identificada pelo parâmetro `riid` de [SetInterfaceSafetyOptions](../Topic/IObjectSafetyImpl::SetInterfaceSafetyOptions.md) deve ser feito seguro para o script.  
  
-   **INTERFACESAFE\_FOR\_UNTRUSTED\_DATA** a interface identificada pelo parâmetro `riid` de `SetInterfaceSafetyOptions` deve ser feito seguro para dados não confiáveis durante a inicialização.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IObjectSafetyImpl::GetInterfaceSafetyOptions](../Topic/IObjectSafetyImpl::GetInterfaceSafetyOptions.md)|Recupera as opções de segurança suportados pelo objeto, bem como as opções de segurança definidas no momento para o objeto.|  
|[IObjectSafetyImpl::SetInterfaceSafetyOptions](../Topic/IObjectSafetyImpl::SetInterfaceSafetyOptions.md)|Faz com segurança do objeto para inicialização ou script.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[IObjectSafetyImpl::m\_dwCurrentSafety](../Topic/IObjectSafetyImpl::m_dwCurrentSafety.md)|Armazena o nível de segurança atual do objeto.|  
  
## Comentários  
 a classe `IObjectSafetyImpl` fornece uma implementação padrão de `IObjectSafety`.  A interface de `IObjectSafety` permite que um cliente recupere e definir níveis de segurança de um objeto.  Por exemplo, um navegador da web pode chamar **IObjectSafety::SetInterfaceSafetyOptions** para fazer um cofre do controle para inicialização ou o cofre para o script.  
  
 Observe que usa a macro de [IMPLEMENTED\_CATEGORY](../Topic/IMPLEMENTED_CATEGORY.md) com **CATID\_SafeForScripting** e as categorias componentes de **CATID\_SafeForInitializing** fornecem uma maneira alternativa para especificar que um componente é seguro.  
  
 **Artigos relacionados** [tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md)  
  
## Hierarquia de herança  
 `IObjectSafety`  
  
 `IObjectSafetyImpl`  
  
## Requisitos  
 **Cabeçalho:** atlctl.h  
  
## Consulte também  
 [IObjectSafety Interface](https://msdn.microsoft.com/en-us/library/aa768224.aspx)   
 [Visão geral de classe](../../atl/atl-class-overview.md)