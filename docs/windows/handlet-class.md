---
title: Classe HandleT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT
dev_langs:
- C++
helpviewer_keywords:
- HandleT class
ms.assetid: 3822b32a-a426-4d94-a54d-919d4df60ee2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a34b66a6e2c901ddbfb3005a0bdb8fd686317af0
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39641499"
---
# <a name="handlet-class"></a>Classe HandleT
Representa um identificador para um objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template <  
   typename HandleTraits  
>  
class HandleT;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *HandleTraits*  
 Uma instância das [HandleTraits](../windows/handletraits-structure.md) estrutura que define as características comuns de um identificador.  
  
## <a name="members"></a>Membros  
  
### <a name="public-typedefs"></a>Typedefs públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`Traits`|Um sinônimo de `HandleTraits`.|  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor HandleT::HandleT](../windows/handlet-handlet-constructor.md)|Inicializa uma nova instância dos **HandleT** classe.|  
|[Destruidor HandleT::~HandleT](../windows/handlet-tilde-handlet-destructor.md)|Realiza o desligamento de uma instância das **HandleT** classe.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HandleT::Attach](../windows/handlet-attach-method.md)|Associa o identificador especificado com o atual **HandleT** objeto.|  
|[Método HandleT::Close](../windows/handlet-close-method.md)|Fecha o atual **HandleT** objeto.|  
|[Método HandleT::Detach](../windows/handlet-detach-method.md)|Desassocia o atual **HandleT** objeto a partir de seu identificador subjacente.|  
|[Método HandleT::Get](../windows/handlet-get-method.md)|Obtém o valor do identificador subjacente.|  
|[Método HandleT::IsValid](../windows/handlet-isvalid-method.md)|Indica se o atual **HandleT** objeto representa um identificador.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Método HandleT::InternalClose](../windows/handlet-internalclose-method.md)|Fecha o atual **HandleT** objeto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador HandleT::operator=](../windows/handlet-operator-assign-operator.md)|Move o valor de especificado **HandleT** objeto atual **HandleT** objeto.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Membro de dados HandleT::handle_](../windows/handlet-handle-data-member.md)|Contém o identificador que é representado pela **HandleT** objeto.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HandleT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)