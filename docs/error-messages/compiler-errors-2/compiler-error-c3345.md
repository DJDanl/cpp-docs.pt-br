---
title: Erro do compilador C3345
ms.date: 11/04/2016
f1_keywords:
- C3345
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
ms.openlocfilehash: e6962e5c127a92acc5dfdad580c7bc89fa134751
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74753439"
---
# <a name="compiler-error-c3345"></a>Erro do compilador C3345

' identifier ': identificador inválido para nome de módulo

O *identificador* de um módulo contém um ou mais caracteres inaceitáveis. Um identificador será válido se o primeiro caractere for um caractere alfabético, sublinhado ou ANSI alto (0x80-FF) e qualquer caractere subsequente for um caractere ANSI alfanumérico, sublinhado ou alto.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

1. Verifique se o *identificador* não contém espaços em branco ou outros caracteres inaceitáveis.

## <a name="example"></a>Exemplo

O exemplo de código a seguir causa a mensagem de erro C3345 porque o parâmetro `name` do atributo `module` contém um espaço em branco.

```cpp
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
[module](../../windows/module-cpp.md)
