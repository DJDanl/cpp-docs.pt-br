---
title: _crtDbgFlag | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _crtDbgFlag
- crtDbgFlag
dev_langs:
- C++
helpviewer_keywords:
- memory allocation, tracking flag
- crtDbgFlag constant
- _crtDbgFlag constant
- debug heap, tracking memory on
- debug heap, control flags
- enable memory allocation tracking flag
- memory, tracking on the debug heap
ms.assetid: 9e7adb47-8ab9-4e19-81d5-e2f237979973
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6d9900d42a5bae3c7a613028a7ae4ffe4bdc0333
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46044906"
---
# <a name="crtdbgflag"></a>_crtDbgFlag

O sinalizador **_crtDbgFlag** é composto por cinco campos de bits que controlam como rastrear, verificar, relatar e despejar as alocações de memória da versão de depuração do heap. Os campos de bits do sinalizador são definidos pela função [_CrtSetDbgFlag](../c-runtime-library/reference/crtsetdbgflag.md). Esse sinalizador e seus campos de bits são declarados em Crtdbg.h. Esse sinalizador só fica disponível quando o sinalizador [_DEBUG](../c-runtime-library/debug.md) é definido no aplicativo.

Para saber mais sobre como usar esse sinalizador com outras funções de depuração, consulte [Funções de Relatório do Estado Heap](/visualstudio/debugger/crt-debug-heap-details).

## <a name="see-also"></a>Consulte também

[Sinalizadores de controle](../c-runtime-library/control-flags.md)