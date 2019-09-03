---
title: auto_inline pragma
ms.date: 08/29/2019
f1_keywords:
- auto_inline_CPP
- vc-pragma.auto_inline
helpviewer_keywords:
- pragmas, auto_inline
- auto_inline pragma
ms.assetid: f7624cd1-be76-429a-881c-65c9040acf43
ms.openlocfilehash: 59cda8cb73196215318c9570a5c067786284afaa
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216307"
---
# <a name="auto_inline-pragma"></a>auto_inline pragma

Exclui todas as funções definidas dentro do intervalo em que o limite é especificado de ser considerado candidatos para a expansão embutida automática.

## <a name="syntax"></a>Sintaxe

> **#pragma auto_inline (** [ **on** | **off** }] **)**

## <a name="remarks"></a>Comentários

Para usar o pragma **auto_inline** , coloque-o antes e imediatamente após, não dentro, uma definição de função. O pragma entra em vigor assim que a primeira definição de função após o pragma ser visto.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
