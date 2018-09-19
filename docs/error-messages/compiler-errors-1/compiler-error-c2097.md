---
title: Erro do compilador C2097 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2097
dev_langs:
- C++
helpviewer_keywords:
- C2097
ms.assetid: 7e5b2fd4-f61c-4b8a-b265-93e987a04bd3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2da955f5382a1ebacdb507a69ed02627b11462e5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46021857"
---
# <a name="compiler-error-c2097"></a>Erro do compilador C2097

inicialização inválida

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Inicialização de uma variável usando um valor não constante.

1. Inicialização de um endereço curto com um endereço longo.

1. Inicialização de um local estrutura, união ou matriz com uma expressão não constante ao compilar com **/Za**.

1. Inicialização com uma expressão que contém um operador de vírgula.

1. Inicialização com uma expressão que é não constante nem simbólico.