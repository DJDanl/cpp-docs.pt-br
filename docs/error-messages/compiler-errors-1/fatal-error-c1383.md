---
title: Erro fatal C1383 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1383
dev_langs:
- C++
helpviewer_keywords:
- C1383
ms.assetid: ca224d14-d687-4fd6-80c2-8b82f28924ea
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 98f6fe881b2cdc46d4d2848d6faf850381f54c7b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062183"
---
# <a name="fatal-error-c1383"></a>Erro fatal C1383

opção de compilador /GL é incompatível com a versão instalada do common language runtime

C1383 ocorre quando você estiver usando uma versão anterior do common language runtime com um compilador mais recente e, quando você compila com **/clr** e **/GL.**

Para resolver, não use **/GL** com **/clr** ou instale a versão do common language runtime fornecido com o compilador.

Para obter mais informações, consulte [/clr (compilação de tempo de execução de linguagem comum)](../../build/reference/clr-common-language-runtime-compilation.md) e [/GL (otimização de programa inteiro)](../../build/reference/gl-whole-program-optimization.md).