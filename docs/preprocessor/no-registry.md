---
title: no_registry
ms.date: 10/18/2018
f1_keywords:
- no_registry
helpviewer_keywords:
- no_registry attribute
ms.assetid: d30de4e2-551c-428c-98fd-951330d578d3
ms.openlocfilehash: 2a0fd9a761f765aa9562ab18c095f683b80c7987
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59023419"
---
# <a name="noregistry"></a>no_registry

**no_registry** informa o compilador não procurar no registro por bibliotecas de tipos importados com `#import`.

## <a name="syntax"></a>Sintaxe

```
#import filename no_registry
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Uma biblioteca de tipos.

## <a name="remarks"></a>Comentários

Se uma biblioteca de tipos referenciados não for encontrada em diretórios de inclusão, a compilação falhará mesmo se a biblioteca de tipos está no registro.  **no_registry** propaga para outras bibliotecas de tipo importadas implicitamente com `auto_search`.

O compilador nunca pesquisará o registro por bibliotecas do tipo que são especificadas pelo nome do arquivo e passadas diretamente a `#import`.

Quando `auto_search` for especificado, adicional `#import`s será gerado com o **no_registry** configuração do inicial `#import` (se inicial `#import` diretiva foi **no_registry** , uma `auto_search`-gerado `#import` também está **no_registry**.)

**no_registry** é útil se você quiser importar nas bibliotecas de tipo referenciado sem o risco do compilador encontrar uma versão mais antiga do arquivo no registro. **no_registry** também é útil se a biblioteca de tipos não está registrada.

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)