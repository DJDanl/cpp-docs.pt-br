---
title: inject_statement
ms.date: 10/18/2018
f1_keywords:
- inject_statement
helpviewer_keywords:
- inject_statement attribute
ms.assetid: 07d6f0f4-d9fb-4e18-aa62-f235f142ff5e
ms.openlocfilehash: cf7d06eddb5ae6d08f57fb82613d97c7dcc36074
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50566706"
---
# <a name="injectstatement"></a>inject_statement

**Específico do C++**

Insere seu argumento como texto de origem no cabeçalho da biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```
inject_statement("source_text")
```

### <a name="parameters"></a>Parâmetros

*source_text*<br/>
Texto de origem a ser inserido no arquivo de cabeçalho da biblioteca de tipos.

## <a name="remarks"></a>Comentários

O texto é colocado no início da declaração do namespace que envolve o conteúdo da biblioteca de tipos no arquivo de cabeçalho.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)