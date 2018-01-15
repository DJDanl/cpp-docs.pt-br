---
title: Mutex Class1 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::Mutex
dev_langs: C++
helpviewer_keywords: Mutex class
ms.assetid: 682a0963-721c-46a2-8871-000e9997505b
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c0e849d1fee7eca67f3b5765d31b54e0660eaa25
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mutex-class1"></a>Mutex Class1
Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class Mutex : public HandleT<HandleTraits::MutexTraits>  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|**SyncLock**|Um sinônimo para uma classe que dá suporte a bloqueios síncronos.|  
  
### <a name="public-constructor"></a>Construtor público  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor Mutex::Mutex](../windows/mutex-mutex-constructor.md)|Inicializa uma nova instância da classe Mutex.|  
  
### <a name="public-members"></a>Membros públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método Mutex::Lock](../windows/mutex-lock-method.md)|Aguarda até que o objeto atual ou o objeto de Mutex associado com o identificador especificado, libera o mutex ou o intervalo de tempo limite especificado tiver decorrido.|  
  
### <a name="public-operator"></a>Operador público  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador Mutex::operator=](../windows/mutex-operator-assign-operator.md)|Atribui (move) o Mutex especificado do objeto para o objeto de Mutex atual.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `Mutex`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)