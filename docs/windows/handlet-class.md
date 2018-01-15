---
title: Classe HandleT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HandleT
dev_langs: C++
helpviewer_keywords: HandleT class
ms.assetid: 3822b32a-a426-4d94-a54d-919d4df60ee2
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0ff7261735149abb8db607c5fc0cd4aa837fdfd7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="handlet-class"></a>Classe HandleT
Representa um identificador para um objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   typename HandleTraits  
>  
class HandleT;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `HandleTraits`  
 Uma instância do [HandleTraits](../windows/handletraits-structure.md) estrutura que define as características de um identificador.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Traits`|Um sinônimo de `HandleTraits`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor HandleT::HandleT](../windows/handlet-handlet-constructor.md)|Inicializa uma nova instância da classe HandleT.|  
|[Destruidor HandleT::~HandleT](../windows/handlet-tilde-handlet-destructor.md)|Deinitializes uma instância da classe HandleT.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HandleT::Attach](../windows/handlet-attach-method.md)|Associa o identificador especificado ao objeto HandleT atual.|  
|[Método HandleT::Close](../windows/handlet-close-method.md)|Fecha o objeto HandleT atual.|  
|[Método HandleT::Detach](../windows/handlet-detach-method.md)|Desassocia o objeto HandleT atual de seu identificador subjacente.|  
|[Método HandleT::Get](../windows/handlet-get-method.md)|Obtém o valor do identificador subjacente.|  
|[Método HandleT::IsValid](../windows/handlet-isvalid-method.md)|Indica se o objeto HandleT atual representa um identificador.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HandleT::InternalClose](../windows/handlet-internalclose-method.md)|Fecha o objeto HandleT atual.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador HandleT::operator=](../windows/handlet-operator-assign-operator.md)|Move o valor do objeto HandleT especificado para o objeto HandleT atual.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados HandleT::handle_](../windows/handlet-handle-data-member.md)|Contém o identificador que é representado pelo objeto HandleT.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HandleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)