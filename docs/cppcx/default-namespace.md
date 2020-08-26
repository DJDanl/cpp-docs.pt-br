---
title: namespace padrão
ms.date: 12/30/2016
ms.assetid: 4712e9dc-57ba-43cc-811e-022e1dae4de8
ms.openlocfilehash: 5696730bcef08ad11be4a2b689e95eb3c13e11eb
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845699"
---
# <a name="default-namespace"></a>namespace padrão

Os `default` escopos de namespace são os tipos internos com suporte no C++/CX.

## <a name="syntax"></a>Sintaxe

```
namespace default;
```

### <a name="members"></a>Membros

Todos os tipos internos herdam os membros a seguir.

| Nome | Descrição |
|--|--|
| [default::(type_name)::Equals](../cppcx/default-type-name-equals-method.md) | Determina se o objeto especificado é igual ao objeto atual. |
| [default::(type_name)::GetHashCode](../cppcx/default-type-name-gethashcode-method.md) | Retorna o código hash para a instância. |
| [default::(type_name)::GetType](../cppcx/default-type-name-gettype-method.md) | Retorna uma cadeia de caracteres que representa o tipo atual. |
| [default::(type_name)::ToString](../cppcx/default-type-name-tostring-method.md) | Retorna uma cadeia de caracteres que representa o tipo atual. |

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
|`uint16`|Um inteiro sem sinal de 16 bits.|
|`uint32`|Um inteiro sem sinal de 32 bits.|
|`uint64`|Um inteiro sem sinal de 64 bits.|
|`uint8`|Um valor numérico sem sinal de 8 bits.|

### <a name="requirements"></a>Requisitos

**Cabeçalho:** vccorlib.h

## <a name="see-also"></a>Confira também

[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)
