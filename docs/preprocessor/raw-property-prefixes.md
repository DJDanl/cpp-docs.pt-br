---
title: raw_property_prefixes
ms.date: 10/18/2018
f1_keywords:
- raw_property_prefixes
helpviewer_keywords:
- raw_property_prefixes attribute
ms.assetid: 03a0f48c-c460-4175-a762-9f7f8d84b12f
ms.openlocfilehash: 23250b524fdaa2181c8e28229ccec680ffdae715
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59033249"
---
# <a name="rawpropertyprefixes"></a>raw_property_prefixes

**Específico do C++**

Especifica prefixos alternativos para três métodos da propriedade.

## <a name="syntax"></a>Sintaxe

```
raw_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")
```

### <a name="parameters"></a>Parâmetros

*GetPrefix*<br/>
Prefixo a ser usado para o `propget` métodos.

*PutPrefix*<br/>
Prefixo a ser usado para o `propput` métodos.

*PutRefPrefix*<br/>
Prefixo a ser usado para o `propputref` métodos.

## <a name="remarks"></a>Comentários

Por padrão, de baixo nível `propget`, `propput`, e `propputref` métodos são expostos por funções de membro nomeadas com prefixos de **get _**, **Put _**, e **PUTREF _** respectivamente. Esses prefixos são compatíveis com os nomes usados nos arquivos de cabeçalho gerados pelo MIDL.

**FIM de Específico do C++**

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)