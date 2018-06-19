---
title: Classe CriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::CriticalSection
dev_langs:
- C++
helpviewer_keywords:
- CriticalSection class
ms.assetid: f2e0a024-71a3-4f6b-99ea-d93a4a608ac4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8b5eda8fb22f72bd1f50801f9993b9bd7a864d35
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33871504"
---
# <a name="criticalsection-class"></a>Classe CriticalSection
Representa um objeto de seção crítica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CriticalSection;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="constructor"></a>Construtor  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor CriticalSection::CriticalSection](../windows/criticalsection-criticalsection-constructor.md)|Inicializa um objeto de sincronização que é semelhante a um objeto mutex, mas pode ser usado por apenas os segmentos de um único processo.|  
|[Destruidor CriticalSection::~CriticalSection](../windows/criticalsection-tilde-criticalsection-destructor.md)|Deinitializes e destrói o objeto CriticalSection atual.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método CriticalSection::TryLock](../windows/criticalsection-trylock-method.md)|As tentativas de inserir uma seção crítica sem bloqueio. Se a chamada for bem-sucedida, o thread de chamada se apropria de seção crítica.|  
|[Método CriticalSection::Lock](../windows/criticalsection-lock-method.md)|Esperas de propriedade do objeto especificado de seção crítica. A função retorna quando o thread de chamada é concedido a propriedade.|  
|[Método CriticalSection::IsValid](../windows/criticalsection-isvalid-method.md)|Indica se a seção crítica atual é válida.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados CriticalSection::cs_](../windows/criticalsection-cs-data-member.md)|Declara um membro de dados da seção crítica.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CriticalSection`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)