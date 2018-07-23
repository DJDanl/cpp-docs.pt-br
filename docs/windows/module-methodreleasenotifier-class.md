---
title: Classe methodreleasenotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::MethodReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- MethodReleaseNotifier class
ms.assetid: 5c2902be-964b-488f-9f1c-adf504995cbc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 217e58f73130922d45f0d303e1e91858e8c2272f
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33880814"
---
# <a name="modulemethodreleasenotifier-class"></a>Classe Module::MethodReleaseNotifier
Invoca um manipulador de eventos quando o último objeto no módulo atual é liberado. O manipulador de eventos é especificado por um objeto e seus membros de ponteiro para um método.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename T>  
class MethodReleaseNotifier : public ReleaseNotifier;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 O tipo do objeto cuja função de membro é o manipulador de eventos.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier](../windows/module-methodreleasenotifier-methodreleasenotifier-constructor.md)|Inicializa uma nova instância da classe methodreleasenotifier.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Module::MethodReleaseNotifier::Invoke](../windows/module-methodreleasenotifier-invoke-method.md)|Chama o manipulador de eventos associado ao objeto methodreleasenotifier atual.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados Module::MethodReleaseNotifier::method_](../windows/module-methodreleasenotifier-method-data-member.md)|Contém um ponteiro para o manipulador de eventos para o objeto methodreleasenotifier atual.|  
|[Membro de dados Module::MethodReleaseNotifier::object_](../windows/module-methodreleasenotifier-object-data-member.md)|Contém um ponteiro para o objeto cuja função de membro é o manipulador de eventos para o objeto methodreleasenotifier atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `ReleaseNotifier`  
  
 `MethodReleaseNotifier`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)