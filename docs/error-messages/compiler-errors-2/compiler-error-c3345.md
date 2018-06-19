---
title: C3345 de erro do compilador | Microsoft Docs
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
ms.openlocfilehash: 3e6b3a021d9c747e4ec30278d8a22bde899cb39a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33254229"
---
# <a name="compiler-error-c3345"></a>C3345 de erro do compilador
'Identificador': identificador inválido para o nome do módulo  
  
 O *identificador* para um módulo contém um ou mais caracteres inválidos. Um identificador é válido se o primeiro caractere é um caractere de sublinhado em ordem alfabética, ou alta de caracteres ANSI (0x80 FF) e qualquer caractere subsequente é um caractere alfanumérico, sublinhado ou alta de caracteres ANSI.  
  
### <a name="to-correct-this-error"></a>Para corrigir este erro  
  
1.  Certifique-se de que *identificador* não contém espaços em branco ou outros caracteres inválidos.  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir faz com que a mensagem de erro C3345 porque o `name` parâmetro o `module` atributo contém um espaço em branco.  
  
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
 [iscsym](../../c-runtime-library/reference/iscsym-functions.md)   
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Módulo](../../windows/module-cpp.md)