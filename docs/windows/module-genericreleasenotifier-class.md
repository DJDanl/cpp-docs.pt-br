---
title: "Classe Module::GenericReleaseNotifier | Microsoft Docs"
ms.custom: ""
ms.date: "12/10/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::Module::GenericReleaseNotifier"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe GenericReleaseNotifier"
ms.assetid: 244a8fbe-f89b-409b-aa65-db3e37f9b125
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe Module::GenericReleaseNotifier
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Invoca um manipulador de eventos quando o último objeto no módulo atual for lançado. O manipulador de eventos é especificado por em um lambda, functor ou ponteiro de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<  
   typename T  
>  
class GenericReleaseNotifier : public ReleaseNotifier;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do membro de dados que contém o local do manipulador de eventos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Module::GenericReleaseNotifier::GenericReleaseNotifier](../Topic/Module::GenericReleaseNotifier::GenericReleaseNotifier%20Constructor.md)|Inicializa uma nova instância da classe genericreleasenotifier.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Genericreleasenotifier:: método Invoke](../windows/module-genericreleasenotifier-invoke-method.md)|Chama o manipulador de eventos associado ao objeto genericreleasenotifier atual.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados Module::GenericReleaseNotifier::callback_](../windows/module-genericreleasenotifier-callback-data-member.md)|Mantém o lambda, functor ou manipulador de eventos de função de apontador associado ao objeto genericreleasenotifier atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ReleaseNotifier`  
  
 `GenericReleaseNotifier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe de módulo](../windows/module-class.md)