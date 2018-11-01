---
title: Aviso do compilador C4335
ms.date: 11/04/2016
f1_keywords:
- C4335
helpviewer_keywords:
- C4335
ms.assetid: e66467ad-a10b-4438-8c7c-e8e8d11d39bb
ms.openlocfilehash: 43c2f5d9092cdbad14e429349bd7d04e236b75e4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447275"
---
# <a name="compiler-warning-c4335"></a>Aviso do compilador C4335

Formato de arquivo Mac detectado: converta o arquivo de origem para o formato DOS ou UNIX

O caractere de terminação de linha da primeira linha de um arquivo de origem é o estilo de Macintosh ('\r') em vez de UNIX ('\n') ou DOS ('\r\n').

Esse aviso é emitido sempre que um erro.  Ver [aviso](../../preprocessor/warning.md) pragma para obter informações sobre como desabilitar esse aviso.  Além disso, esse aviso será emitido somente uma vez por compiland. Portanto, se houver vários `#include` diretivas que especificam os arquivos no formato Macintosh, C4335 só serão emitidos uma vez.

Uma maneira de gerar arquivos no formato Macintosh é usando o **opções avançadas de salvamento** (na **arquivo** menu) no Visual Studio.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4335.

```
// C4335 expected
#include "c4335.h"   // assume both include files are in Macintosh format
#include "c4335_2.h"
```