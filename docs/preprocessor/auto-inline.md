---
title: auto_inline | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- auto_inline_CPP
- vc-pragma.auto_inline
dev_langs:
- C++
helpviewer_keywords:
- pragmas, auto_inline
- auto_inline pragma
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cc2fb4cb870ff1dca2f0b55e9aad20741ffb8220
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50083172"
---
# <a name="autoinline"></a>auto_inline
Exclui quaisquer funções definidas dentro do intervalo em que **desativar** é especificado seja considerado como candidatos para a expansão embutida automática.

## <a name="syntax"></a>Sintaxe

```
#pragma auto_inline( [{on | off}] )
```

## <a name="remarks"></a>Comentários

Para usar o **auto_inline** pragma, coloque-o imediatamente antes e depois (não in) uma definição de função. O pragma entra em vigor na primeira definição de função, após a consideração do pragma.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)