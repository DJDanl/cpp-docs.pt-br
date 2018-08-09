---
title: no_injected_text | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.no_injected_text
dev_langs:
- C++
helpviewer_keywords:
- no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: fc0dcba6597b6b8a3b37c240bf1c4a58f30b6b23
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40020337"
---
# <a name="noinjectedtext"></a>no_injected_text
Impede que o compilador injetando código como resultado do uso do atributo.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
[ no_injected_text(  
   boolean  
) ];  
```  
  
### <a name="parameters"></a>Parâmetros  
 *booliano* (opcional)  
 **Verdadeiro** se você não quiser que nenhum código injetado, **falso** para permitir que o código injetado. **True** é o padrão.  
  
## <a name="remarks"></a>Comentários  
 O uso mais comum do **no_injected_text** atributo C++ é a [/Fx](../build/reference/fx-merge-injected-code.md) opção de compilador, que insere os **no_injected_text** atributo no arquivo. mrg.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   