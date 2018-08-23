---
title: namespace padrão | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 4712e9dc-57ba-43cc-811e-022e1dae4de8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 87510fe7eee6a8027e5375f82f2b6ce7bf74ec3c
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589728"
---
# <a name="default-namespace"></a>namespace padrão
O `default` namespace tem como escopo os tipos internos que são suportados pelo C + + c++ /CLI CX.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
namespace default;  
```  
  
### <a name="members"></a>Membros  
 Todos os tipos internos herdam os membros a seguir.  
  
|||  
|-|-|  
|[default::(type_name)::Equals](../cppcx/default-type-name-equals-method.md)|Determina se o objeto especificado é igual ao objeto atual.|  
|[default::(type_name)::GetHashCode](../cppcx/default-type-name-gethashcode-method.md)|Retorna o código hash para essa instância.|  
|[default::(type_name)::GetType](../cppcx/default-type-name-gettype-method.md)|Retorna uma cadeia de caracteres que representa o tipo atual.|  
|[default::(type_name)::ToString](../cppcx/default-type-name-tostring-method.md)|Retorna uma cadeia de caracteres que representa o tipo atual.|  
  
### <a name="built-in-types"></a>Tipos internos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`char16`|Um valor não numérico de 16 bits que representa um ponto de código Unicode (UTF-16).|  
|`float32`|Um número de ponto flutuante IEEE 754 de 32 bits.|  
|`float64`|Um número de ponto flutuante IEEE 754 de 64 bits.|  
|`int16`|Um inteiro de 16 bits com sinal.|  
|`int32`|Um inteiro com sinal de 32 bits.|  
|`int64`|Um inteiro com sinal de 64 bits.|  
|`int8`|Um valor numérico com sinal de 8 bits.|  
|`uint16`|Um inteiro de 16 bits sem sinal.|  
|`uint32`|Um inteiro sem sinal de 32 bits.|  
|`uint64`|Um inteiro sem sinal de 64 bits.|  
|`uint8`|Um valor numérico sem sinal de 8 bits.|  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** vccorlib.h  
  
## <a name="see-also"></a>Consulte também  
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)