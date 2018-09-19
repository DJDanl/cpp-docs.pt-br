---
title: Erro do compilador C3345 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3345
dev_langs:
- C++
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 191c2184d14f991ab62f439b492c7fd7f4a00be5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46118941"
---
# <a name="compiler-error-c3345"></a>Erro do compilador C3345

'identifier': identificador inválido para o nome do módulo

O *identificador* para um módulo contém um ou mais caracteres inválidos. Um identificador é válido se o primeiro caractere for um caractere de sublinhado em ordem alfabética, ou caractere ANSI (0x80 FF) alto e qualquer caractere subsequente é um valor alfanumérico, sublinhado ou caractere ANSI alto.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Certifique-se de que *identificador* não contém espaços em branco ou outros caracteres inaceitáveis.

## <a name="example"></a>Exemplo

O exemplo de código a seguir faz com que a mensagem de erro C3345 porque o `name` parâmetro do `module` atributo contém um espaço em branco.

```
// cpp_attr_name_module.cpp
// compile with: /LD /link /OPT:NOREF
#include <atlbase.h>
#include <atlcom.h>
#include <atlwin.h>
#include <atltypes.h>
#include <atlctl.h>
#include <atlhost.h>
#include <atlplus.h>

// C3345 expected
[module(dll, name="My Library", version="1.2", helpfile="MyHelpFile")]
// Try the following line instead
//[module(dll, name="MyLibrary", version="1.2", helpfile="MyHelpFile")]
// Module attribute now applies to this class
class CMyClass {
public:
BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) {
   // add your own code here
   return __super::DllMain(dwReason, lpReserved);
   }
};
```

## <a name="see-also"></a>Consulte também

[__iscsym](../../c-runtime-library/reference/iscsym-functions.md)<br/>
[Classificação de caracteres](../../c-runtime-library/character-classification.md)<br/>
[módulo](../../windows/module-cpp.md)