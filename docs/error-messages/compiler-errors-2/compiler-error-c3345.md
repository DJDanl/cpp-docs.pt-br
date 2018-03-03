---
title: C3345 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3345
dev_langs:
- C++
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ca51e90d8c0cbb1806cc0b042d9c3ae2480a9729
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
 [módulo](../../windows/module-cpp.md)