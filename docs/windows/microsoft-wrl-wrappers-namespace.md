---
title: Namespace Microsoft::WRL::wrappers | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers
dev_langs:
- C++
helpviewer_keywords:
- Wrappers namespace
ms.assetid: 36ac38c7-1fc3-42da-a879-5c68661dc9e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9667a3660f46db0a61991545108d66bf0cac9f38
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40017790"
---
# <a name="microsoftwrlwrappers-namespace"></a>Namespace Microsoft::WRL::Wrappers
Define os tipos de wrapper de recurso aquisição é a inicialização (RAII) que simplificam o gerenciamento de tempo de vida de objetos, cadeias de caracteres e identificadores.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
namespace Microsoft::WRL::Wrappers;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="typedefs"></a>Typedefs  
  
|Nome|Descrição|  
|----------|-----------------|  
|`FileHandle`|`HandleT<HandleTraits::FileHandleTraits>`|  
  
### <a name="classes"></a>Classes  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Classe CriticalSection](../windows/criticalsection-class.md)|Representa um objeto de seção crítica.|  
|[Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)|Representa um evento.|  
|[Classe HandleT](../windows/handlet-class.md)|Representa um identificador para um objeto.|  
|[Classe HString](../windows/hstring-class.md)|Fornece suporte para manipular identificadores de HSTRING.|  
|[Classe HStringReference](../windows/hstringreference-class.md)|Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.|  
|[Classe Mutex](../windows/mutex-class1.md)|Representa um objeto de sincronização que controla exclusivamente um recurso compartilhado.|  
|[Classe RoInitializeWrapper](../windows/roinitializewrapper-class.md)|Inicializa o tempo de execução do Windows.|  
|[Classe Semaphore](../windows/semaphore-class.md)|Representa um objeto de sincronização que controla um recurso compartilhado que pode dar suporte a um número limitado de usuários.|  
|[Classe SRWLock](../windows/srwlock-class.md)|Representa um bloqueio de leitor/gravador reduzido.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)