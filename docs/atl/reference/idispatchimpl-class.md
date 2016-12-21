---
title: "Classe de IDispatchImpl | Microsoft Docs"
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
  - "IDispatchImpl"
  - "ATL.IDispatchImpl"
  - "ATL::IDispatchImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces duais, classes"
  - "Suporte da classe de IDispatch em ATL"
  - "Classe de IDispatchImpl"
ms.assetid: 8108eb36-1228-4127-a203-3ab5ba488892
caps.latest.revision: 27
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de IDispatchImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece uma implementação padrão para a parte de `IDispatch` de uma interface dupla.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## Sintaxe  
  
```  
template<  
   class T,  
   const IID* piid= &__uuidof(T),  
   const GUID* plibid = &CAtlModule::m_libid,  
   WORD wMajor = 1,  
   WORD wMinor = 0,  
   class tihclass = CComTypeInfoHolder   
>   
class ATL_NO_VTABLE IDispatchImpl :  
   public T  
```  
  
#### Parâmetros  
 \[in\] `T`  
 Uma interface dupla.  
  
 \[in\] `piid`  
 Um ponteiro para o IID de `T`.  
  
 \[in\] `plibid`  
 Um ponteiro para o LIBID da biblioteca de tipos que contém informações sobre a interface.  Por padrão, a biblioteca de tipos no nível de servidor é passada.  
  
 \[in\] `wMajor`  
 A versão principal de biblioteca de tipo.  Por padrão, o valor é 1.  
  
 \[in\] `wMinor`  
 A versão secundária de biblioteca de tipo.  Por padrão, o valor é 0.  
  
 \[in\] `tihclass`  
 A classe usada para gerenciar informações de tipo para `T`.  Por padrão, o valor é `CComTypeInfoHolder`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispatchImpl::IDispatchImpl](../Topic/IDispatchImpl::IDispatchImpl.md)|o construtor.  Chama `AddRef` protegido na variável de membro que gerencia informações de tipo para a interface dupla.  O destrutor chama `Release`.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[IDispatchImpl::GetIDsOfNames](../Topic/IDispatchImpl::GetIDsOfNames.md)|Mapeia um conjunto de nomes a um conjunto correspondente de identificadores de distribuição.|  
|[IDispatchImpl::GetTypeInfo](../Topic/IDispatchImpl::GetTypeInfo.md)|Recupera informações de tipo para a interface dupla.|  
|[IDispatchImpl::GetTypeInfoCount](../Topic/IDispatchImpl::GetTypeInfoCount.md)|Determina se houver informações de tipo para a interface dupla.|  
|[IDispatchImpl::Invoke](../Topic/IDispatchImpl::Invoke.md)|Fornece acesso a métodos e propriedades expostas pela interface dupla.|  
  
## Comentários  
 `IDispatchImpl` fornece uma implementação padrão para a parte de `IDispatch` de qualquer interface dupla em um objeto.  Uma interface dupla deriva de `IDispatch` e usar somente tipos compatíveis Automação\-.  Como um dispinterface, uma interface dupla suporta associação inicial e associação tardia; no entanto, uma interface dupla também suporta associação vtable.  
  
 O exemplo a seguir mostra uma implementação típica de `IDispatchImpl`.  
  
 [!code-cpp[NVC_ATL_COM#47](../../atl/codesnippet/CPP/idispatchimpl-class_1.h)]  
  
 Por padrão, a classe de `IDispatchImpl` pesquisa informações de tipo para `T` no Registro.  Para implementar uma interface desregistrado, você pode usar a classe de `IDispatchImpl` sem acessar o Registro usando um número de versão predefinido.  Se você criar um objeto de `IDispatchImpl` que tem 0xFFFF como o valor para `wMajor` e 0xFFFF como o valor para `wMinor`, a classe de `IDispatchImpl` recupera a biblioteca de tipos de arquivo .dll em vez do Registro.  
  
 `IDispatchImpl` contém um membro estático do tipo `CComTypeInfoHolder` que gerencia informações de tipo para a interface dupla.  Se você tiver vários objetos que implementam a mesma interface dupla, somente uma instância de `CComTypeInfoHolder` é usada.  
  
## Hierarquia de herança  
 `T`  
  
 `IDispatchImpl`  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)