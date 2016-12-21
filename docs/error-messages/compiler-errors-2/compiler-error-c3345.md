---
title: "C3345 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C3345"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3345"
ms.assetid: 1dda4c79-73bb-441b-b939-746154c3afba
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3345 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': identificador inválido para o nome do módulo  
  
 O *identificador* para um módulo contém um ou mais caracteres inválidos. Um identificador é válido se o primeiro caractere é um caractere de sublinhado em ordem alfabética, ou alto de caracteres ANSI \(0x80 FF\) e qualquer caractere subsequente é um alfanuméricos, sublinhados ou caractere ANSI alto.  
  
### Para corrigir este erro  
  
1.  Certifique\-se de que *identificador* não contém espaços em branco ou outros caracteres inválidos.  
  
## Exemplo  
 O exemplo de código a seguir faz com que a mensagem de erro C3345 porque o `name` parâmetro o `module` atributo contém um espaço em branco.  
  
```  
// cpp_attr_name_module.cpp // compile with: /LD /link /OPT:NOREF #include <atlbase.h> #include <atlcom.h> #include <atlwin.h> #include <atltypes.h> #include <atlctl.h> #include <atlhost.h> #include <atlplus.h> // C3345 expected [module(dll, name="My Library", version="1.2", helpfile="MyHelpFile")] // Try the following line instead //[module(dll, name="MyLibrary", version="1.2", helpfile="MyHelpFile")] // Module attribute now applies to this class class CMyClass { public: BOOL WINAPI DllMain(DWORD dwReason, LPVOID lpReserved) { // add your own code here return __super::DllMain(dwReason, lpReserved); } };  
```  
  
## Consulte também  
 [iscsym](../../c-runtime-library/reference/iscsym-functions.md)   
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [module](../../windows/module-cpp.md)