---
title: inject_statement
ms.date: 10/18/2018
f1_keywords:
- inject_statement
helpviewer_keywords:
- inject_statement attribute
ms.assetid: 07d6f0f4-d9fb-4e18-aa62-f235f142ff5e
ms.openlocfilehash: 237ca796028aad7aff55442eb2806fe400330a29
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59034281"
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