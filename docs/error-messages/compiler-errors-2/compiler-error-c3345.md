---
title: C3345 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3345
dev_langs:
- C++
helpviewer_keywords:
- C3345
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 5d936081f4e8371a1f6f1a1810c30df28627914b
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3345"></a>C3345 de erro do compilador
'identifier': identificador inválido para o nome do módulo  
  
 O *identificador* para um módulo contém um ou mais caracteres inválidos. Um identificador é válido se o primeiro caractere é um caractere de sublinhado em ordem alfabética, ou alto de caracteres ANSI (0x80 FF) e qualquer caractere subsequente é um alfanuméricos, sublinhados ou caractere ANSI alto.  
  
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
