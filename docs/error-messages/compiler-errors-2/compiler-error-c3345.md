---
title: Erro do compilador C3345
ms.date: 11/04/2016
f1_keywords:
- C3345
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
ms.openlocfilehash: eb1d15a12bfebbf44f7335a848d68c367c285586
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62300590"
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
[module](../../windows/module-cpp.md)