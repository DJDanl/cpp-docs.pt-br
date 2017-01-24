---
title: "_get_purecall_handler, set_purecall_handler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_set_purecall_handler"
  - "_set_purecall_handler_m"
  - "_get_purecall_handler"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_set_purecall_handler"
  - "_set_purecall_handler_m"
  - "set_purecall_handler_m"
  - "set_purecall_handler"
  - "stdlib/_set_purecall_handler"
  - "stdlib/_get_purecall_handler"
  - "_get_purecall_handler"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _set_purecall_handler"
  - "Função set_purecall_handler"
  - "purecall_handler"
  - "Função set_purecall_handler_m"
  - "_purecall_handler"
  - "Função _set_purecall_handler_m"
  - "função _get_purecall_handler"
ms.assetid: 2759b878-8afa-4129-86e7-72afc2153d9c
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _get_purecall_handler, set_purecall_handler
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém ou define o manipulador de erro para uma chamada de função virtual pura.  
  
## Sintaxe  
  
```  
typedef void (__cdecl* _purecall_handler)(void);  
  
_purecall_handler __cdecl _get_purecall_handler(void);  
  
_purecall_handler __cdecl _set_purecall_handler(   
   _purecall_handler function  
);  
```  
  
#### Parâmetros  
 `function`  
 A função a ser chamada quando uma função virtual pura é chamada. Um `_purecall_handler` função deve ter um tipo de retorno void.  
  
## Valor de retorno  
 Anterior `_purecall_handler`. Retorna `nullptr` não se houvesse nenhum manipulador anterior.  
  
## Comentários  
 O `_get_purecall_handler` e `_set_purecall_handler` funções são específicas da Microsoft e se aplicam somente ao código C\+\+.  
  
 Uma chamada para uma função virtual pura é um erro porque ele tem nenhuma implementação. Por padrão, o compilador gera código para invocar uma função de manipulador de erro quando uma função virtual pura é chamada, que encerra o programa. Você pode instalar sua própria função de manipulador de erro para chamadas de função virtual pura, para capturá\-las para depuração ou para fins de relatório. Para usar seu próprio manipulador de erro, crie uma função que tem o `_purecall_handler` assinatura, use `_set_purecall_handler` para torná\-lo o manipulador atual.  
  
 Porque há apenas um `_purecall_handler` para cada processo, quando você chama `_set_purecall_handler` \-lo imediatamente afeta todos os threads. O último chamador em qualquer thread define o manipulador.  
  
 Para restaurar o comportamento padrão, chamar `_set_purecall_handler` usando um `nullptr` argumento.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_get_purecall_handler`, `_set_purecall_handler`|\< cstdlib \> ou \< stdlib. h \>|  
  
 Para informações sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// _set_purecall_handler.cpp  
// compile with: /W1  
#include <tchar.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
class CDerived;  
class CBase  
{  
public:  
   CBase(CDerived *derived): m_pDerived(derived) {};  
   ~CBase();  
   virtual void function(void) = 0;  
  
   CDerived * m_pDerived;  
};  
  
class CDerived : public CBase  
{  
public:  
   CDerived() : CBase(this) {};   // C4355  
   virtual void function(void) {};  
};  
  
CBase::~CBase()  
{  
   m_pDerived -> function();  
}  
  
void myPurecallHandler(void)  
{  
   printf("In _purecall_handler.");  
   exit(0);  
}  
  
int _tmain(int argc, _TCHAR* argv[])  
{  
   _set_purecall_handler(myPurecallHandler);  
   CDerived myDerived;  
}  
```  
  
```Output  
Em _purecall_handler.  
```  
  
## Consulte também  
 [Tratamento de erros](../../c-runtime-library/error-handling-crt.md)   
 [\_purecall](../Topic/_purecall.md)