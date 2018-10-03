---
title: auto_rename | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- auto_rename
dev_langs:
- C++
helpviewer_keywords:
- auto_rename attribute
ms.assetid: 1075f3ab-f6fc-4e04-8e22-ebe02695a567
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 52147dcf79c73e1f931a3e9b52241308def864c4
ms.sourcegitcommit: 1d9bd38cacbc783fccd3884b7b92062161c91c84
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/03/2018
ms.locfileid: "48234419"
---
# <a name="autorename"></a>auto_rename

**Específico do C++**

Renomeia palavras reservadas C++ com dois sublinhados (__) para o nome da variável para resolver possíveis conflitos de nome.

## <a name="syntax"></a>Sintaxe

```
auto_rename
```

## <a name="remarks"></a>Comentários

Esse atributo é usado para importar uma biblioteca de tipos que usa uma ou mais palavras reservadas C++ (palavras-chave ou macros) como nomes de variáveis.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)