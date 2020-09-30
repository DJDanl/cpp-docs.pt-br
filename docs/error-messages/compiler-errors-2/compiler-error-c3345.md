---
title: Erro do compilador C3345
ms.date: 11/04/2016
f1_keywords:
- C3345
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
ms.openlocfilehash: 8682069fdf719f4e85d1d6f5107de1903e3ae071
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91504837"
---
# <a name="compiler-error-c3345"></a>Erro do compilador C3345

' identifier ': identificador inválido para nome de módulo

O *identificador* de um módulo contém um ou mais caracteres inaceitáveis. Um identificador será válido se o primeiro caractere for um caractere alfabético, sublinhado ou ANSI alto (0x80-FF) e qualquer caractere subsequente for um caractere ANSI alfanumérico, sublinhado ou alto.

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Verifique se o *identificador* não contém espaços em branco ou outros caracteres inaceitáveis.

## <a name="example"></a>Exemplo

O exemplo de código a seguir causa a mensagem de erro C3345 porque o `name` parâmetro do `module` atributo contém um espaço em branco.

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
[modulo](../../windows/attributes/module-cpp.md)
