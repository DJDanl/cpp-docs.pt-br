---
title: Mutex Class1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Mutex
dev_langs:
- C++
helpviewer_keywords:
- Mutex class
ms.assetid: 682a0963-721c-46a2-8871-000e9997505b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9a9e9674dd8ac5aa7d444a77df66c1aff4a70299
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878405"
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