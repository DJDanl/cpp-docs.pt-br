---
title: inject_statement | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- inject_statement
dev_langs:
- C++
helpviewer_keywords:
- inject_statement attribute
ms.assetid: 07d6f0f4-d9fb-4e18-aa62-f235f142ff5e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 27b35c10e9e1953dc45dee1caf61d2e58c38d02d
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808637"
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