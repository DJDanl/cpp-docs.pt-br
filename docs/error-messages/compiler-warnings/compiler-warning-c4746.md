---
title: Aviso do compilador C4746 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
ms.assetid: 5e79ab46-6031-499a-a986-716c866b6c0e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5e6abce7ebbcdc41effed05ccf54337e3976c34e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46054853"
---
# <a name="compiler-warning-c4746"></a>Aviso do compilador C4746

acesso volátil de '\<expression >' está sujeito a /volatile: [iso&#124;ms] definindo; considere o uso de funções intrínsecas do iso_volatile_load/store.

C4746 é emitido sempre que uma variável volátil é acessada diretamente. Ele se destina a ajudar os desenvolvedores a identificar os locais de código que são afetados pelo modelo volátil específico no momento especificado (que pode ser controlado com o [/volatile](../../build/reference/volatile-volatile-keyword-interpretation.md) opção de compilador). Em particular, ele pode ser útil localizar as barreiras de memória de hardware geradas pelo compilador quando /volatile: MS é usada.

Os intrínsecos iso_volatile_load/store podem ser usados para acessar explicitamente a memória volátil sem ser afetado pelo modelo volátil. Usar esses intrínsecos não disparará C4746.

Esse aviso é desativado por padrão. Ver [compilador avisos que são desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.