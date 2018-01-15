---
title: Classe HStringReference | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HStringReference
dev_langs: C++
ms.assetid: 9bf823b1-17eb-4ac4-8c5d-27d27c7a4150
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 97900bd44dfdcede187b20b181c64d235eac60fc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringreference-class"></a>Classe HStringReference
Representa um HSTRING que é criado a partir de uma cadeia de caracteres existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
class HStringReference;  
```  
  
## <a name="remarks"></a>Comentários  
 O tempo de vida do buffer em HSTRING o novo backup não é gerenciado pelo Windows Runtime. O chamador aloca uma cadeia de caracteres de origem no quadro de pilha para evitar uma alocação de heap e para eliminar o risco de vazamento de memória. Além disso, o chamador deve garantir a cadeia de caracteres de origem permanece inalterada durante o tempo de vida do HSTRING anexado. Para obter mais informações, consulte [WindowsCreateStringReference função](http://msdn.microsoft.com/en-us/0361bb7e-da49-4289-a93e-de7aab8712ac).  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Construtor HStringReference::HStringReference](../windows/hstringreference-hstringreference-constructor.md)|Inicializa uma nova instância da classe HStringReference.|  
  
### <a name="members"></a>Membros  
  
|Membro|Descrição|  
|------------|-----------------|  
|[Método HStringReference::CopyTo](../windows/hstringreference-copyto-method.md)|Copia o HStringReference atual objeto para um objeto HSTRING.|  
|[Método HStringReference::Get](../windows/hstringreference-get-method.md)|Recupera o valor do identificador HSTRING subjacente.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Operador HStringReference::Operator=](../windows/hstringreference-operator-assign-operator.md)|Move o valor de outro objeto HStringReference ao objeto HStringReference atual.|  
|[Operador HStringReference::Operator==](../windows/hstringreference-operator-equality-operator.md)|Indica se os dois parâmetros são iguais.|  
|[Operador HStringReference::Operator!=](../windows/hstringreference-operator-inequality-operator.md)|Indica se os dois parâmetros não são iguais.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `HStringReference`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Wrappers](../windows/microsoft-wrl-wrappers-namespace.md)