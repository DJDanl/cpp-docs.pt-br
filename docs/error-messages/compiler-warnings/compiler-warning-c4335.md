---
title: Aviso do compilador C4335
ms.date: 11/04/2016
f1_keywords:
- C4335
helpviewer_keywords:
- C4335
ms.assetid: e66467ad-a10b-4438-8c7c-e8e8d11d39bb
ms.openlocfilehash: ccb00118d0c6895eee84976bb01472ea2f98353d
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627129"
---
# <a name="compiler-warning-c4335"></a>Aviso do compilador C4335

Formato de arquivo Mac detectado: Converta o arquivo de origem para o formato DOS ou UNIX

O caractere de terminação de linha da primeira linha de um arquivo de origem é o estilo do Macintosh (' \r ') em oposição ao UNIX (' \n ') ou ao DOS (' \r\n ').

Esse aviso é sempre emitido como um erro.  Consulte pragma de [aviso](../../preprocessor/warning.md) para obter informações sobre como desabilitar este aviso.  Além disso, esse aviso é emitido apenas uma vez por compiland. Portanto, se houver várias diretivas `#include` que especificam arquivos no formato Macintosh, o C4335 será emitido apenas uma vez.

Uma maneira de gerar arquivos no formato Macintosh é usando as **Opções avançadas de salvamento** (no menu **arquivo** ) no Visual Studio.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4335.

```cpp
// C4335 expected
#include "c4335.h"   // assume both include files are in Macintosh format
#include "c4335_2.h"
```
