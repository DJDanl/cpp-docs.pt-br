---
title: high_property_prefixes | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- high_property_prefixes
dev_langs:
- C++
helpviewer_keywords:
- high_property_prefixes attribute
ms.assetid: 91c6cc2b-19b6-4aba-8831-d9e5cccb58b5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e3932a7632b12120e722c5f375f4387e08f1853b
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49809051"
---
# <a name="highpropertyprefixes"></a>high_property_prefixes

**Específico do C++**

Especifica prefixos alternativos para três métodos da propriedade.

## <a name="syntax"></a>Sintaxe

```
high_property_prefixes("GetPrefix","PutPrefix","PutRefPrefix")
```

### <a name="parameters"></a>Parâmetros

*GetPrefix*<br/>
Prefixo a ser usado para o `propget` métodos.

*PutPrefix*<br/>
Prefixo a ser usado para o `propput` métodos.

*PutRefPrefix*<br/>
Prefixo a ser usado para o `propputref` métodos.

## <a name="remarks"></a>Comentários

Por padrão, tratamento de erros de alto nível `propget`, `propput`, e `propputref` métodos expostos pela funções membro nomeadas com prefixos `Get`, `Put`, e `PutRef`, respectivamente.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)