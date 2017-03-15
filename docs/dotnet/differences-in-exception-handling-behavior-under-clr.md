---
title: "Diferen&#231;as no comportamento do tratamento de exce&#231;&#245;es em /CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro EXCEPTION_CONTINUE_EXECUTION"
  - "Função set_se_translator"
ms.assetid: 2e7e8daf-d019-44b0-a51c-62d7aaa89104
caps.latest.revision: 20
caps.handback.revision: 20
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Diferen&#231;as no comportamento do tratamento de exce&#231;&#245;es em /CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[Conceitos básicos de usar exceções gerenciadas](../dotnet/basic-concepts-in-using-managed-exceptions.md) discute a manipulação de exceção nos aplicativos gerenciados.  Neste tópico, as diferenças de comportamento padrão de manipulação de exceção e algumas restrições são abordadas em detalhes.  Para obter mais informações, consulte [A função de \_set\_se\_translator](../c-runtime-library/reference/set-se-translator.md).  
  
##  <a name="vcconjumpingoutofafinallyblock"></a> Ignorar finalmente de um bloco  
 No código nativo C\/C\+\+, ignorar de um bloco de**finally** do que usa a manipulação de exceção estruturado \(SEH\) é permitido embora gerencia um aviso.  Em [\/clr](../build/reference/clr-common-language-runtime-compilation.md), ignorar de um bloco de **finally** causa um erro:  
  
```  
// clr_exception_handling_4.cpp  
// compile with: /clr  
int main() {  
   try {}  
   finally {  
      return 0;   // also fails with goto, break, continue  
    }  
}   // C3276  
```  
  
##  <a name="vcconraisingexceptionswithinanexceptionfilter"></a> Aumentando exceções em um filtro de exceção  
 Quando uma exceção é gerada durante o processamento de [filtro de exceção](../cpp/writing-an-exception-filter.md) no código gerenciado, a exceção será capturada e tratada como se retornar 0 do filtro.  
  
 Isto está em contraste com o comportamento em código nativo onde uma exceção aninhada é emitido, o campo de **ExceptionRecord** na estrutura de **EXCEPTION\_RECORD** \(como retornado por [GetExceptionInformation](http://msdn.microsoft.com/library/windows/desktop/ms679357)\) é definido, e conjuntos de campos de **ExceptionFlags** o bit 0x10.  O exemplo a seguir ilustra a diferença no comportamento:  
  
```  
// clr_exception_handling_5.cpp  
#include <windows.h>  
#include <stdio.h>  
#include <assert.h>  
  
#ifndef false  
#define false 0  
#endif  
  
int *p;  
  
int filter(PEXCEPTION_POINTERS ExceptionPointers) {  
   PEXCEPTION_RECORD ExceptionRecord =   
                     ExceptionPointers->ExceptionRecord;  
  
   if ((ExceptionRecord->ExceptionFlags & 0x10) == 0) {  
      // not a nested exception, throw one  
      *p = 0; // throw another AV  
   }  
   else {  
      printf("Caught a nested exception\n");  
      return 1;  
    }  
  
   assert(false);  
  
   return 0;  
}  
  
void f(void) {  
   __try {  
      *p = 0;   // throw an AV  
   }  
   __except(filter(GetExceptionInformation())) {  
      printf_s("We should execute this handler if "  
                 "compiled to native\n");  
    }  
}  
  
int main() {  
   __try {  
      f();  
   }  
   __except(1) {  
      printf_s("The handler in main caught the "  
               "exception\n");  
    }  
}  
```  
  
### Saída  
  
```  
Caught a nested exception  
We should execute this handler if compiled to native  
```  
  
##  <a name="vccondisassociatedrethrows"></a> Lança novamente dissociado  
 **\/clr** não oferece suporte a rethrowing uma exceção fora de um manipulador de captura \(conhecido como um lançar novamente dissociado\).  As exceções desse tipo são tratadas como um lançar novamente padrão do C\+\+.  Se um lançar novamente dissociado for encontrado quando há uma exceção gerenciada ativa, a exceção será envolvida a exceção e no rethrown c. criando  As exceções desse tipo só podem ser capturadas como uma exceção do tipo [System::SEHException](https://msdn.microsoft.com/en-us/library/system.runtime.interopservices.sehexception.aspx).  
  
 O exemplo a seguir demonstra um rethrown gerenciado de exceção como a exceção c: criando  
  
```  
// clr_exception_handling_6.cpp  
// compile with: /clr  
using namespace System;  
#include <assert.h>  
#include <stdio.h>  
  
void rethrow( void ) {  
   // This rethrow is a dissasociated rethrow.  
   // The exception would be masked as SEHException.  
   throw;  
}  
  
int main() {  
   try {  
      try {  
         throw gcnew ApplicationException;  
      }  
      catch ( ApplicationException^ ) {  
         rethrow();  
         // If the call to rethrow() is replaced with  
         // a throw statement within the catch handler,  
         // the rethrow would be a managed rethrow and  
         // the exception type would remain   
         // System::ApplicationException  
      }  
   }  
  
    catch ( ApplicationException^ ) {  
      assert( false );  
  
      // This will not be executed since the exception  
      // will be masked as SEHException.  
    }  
   catch ( Runtime::InteropServices::SEHException^ ) {  
      printf_s("caught an SEH Exception\n" );  
    }  
}  
```  
  
### Saída  
  
```  
caught an SEH Exception  
```  
  
##  <a name="vcconexceptionfiltersandexception_continue_execution"></a> Filtros de exceção e EXCEPTION\_CONTINUE\_EXECUTION  
 Se um filtro retorna `EXCEPTION_CONTINUE_EXECUTION` em um aplicativo gerenciado, será tratado como se o filtro `EXCEPTION_CONTINUE_SEARCH`retornado.  Para obter mais informações sobre essas constantes, consulte [tentativa\-exceto a instrução](../cpp/try-except-statement.md).  
  
 O exemplo a seguir demonstra essa diferença:  
  
```  
// clr_exception_handling_7.cpp  
#include <windows.h>  
#include <stdio.h>  
#include <assert.h>  
  
int main() {  
   int Counter = 0;  
   __try {  
      __try  {  
         Counter -= 1;  
         RaiseException (0xe0000000|'seh',  
                         0, 0, 0);  
         Counter -= 2;  
      }  
      __except (Counter) {  
         // Counter is negative,  
         // indicating "CONTINUE EXECUTE"  
         Counter -= 1;  
      }  
    }  
    __except(1) {  
      Counter -= 100;  
   }  
  
   printf_s("Counter=%d\n", Counter);  
}  
```  
  
### Saída  
  
```  
Counter=-3  
```  
  
##  <a name="vcconthe_set_se_translatorfunction"></a> A função de \_set\_se\_translator  
 A função de tradutor, definido por uma chamada a `_set_se_translator`, captura mantê\-las afeta apenas em código não gerenciado.  O exemplo a seguir demonstra esta limitação:  
  
```  
// clr_exception_handling_8.cpp  
// compile with: /clr /EHa  
#include <iostream>  
#include <windows.h>  
#include <eh.h>  
#pragma warning (disable: 4101)  
using namespace std;  
using namespace System;  
  
#define MYEXCEPTION_CODE 0xe0000101  
  
class CMyException {  
public:  
   unsigned int m_ErrorCode;  
   EXCEPTION_POINTERS * m_pExp;  
  
   CMyException() : m_ErrorCode( 0 ), m_pExp( NULL ) {}  
  
   CMyException( unsigned int i, EXCEPTION_POINTERS * pExp )  
         : m_ErrorCode( i ), m_pExp( pExp ) {}  
  
   CMyException( CMyException& c ) : m_ErrorCode( c.m_ErrorCode ),  
                                      m_pExp( c.m_pExp ) {}  
  
   friend ostream& operator <<   
                 ( ostream& out, const CMyException& inst ) {  
      return out <<  "CMyException[\n" <<    
             "Error Code: " << inst.m_ErrorCode <<  "]";  
    }  
};  
  
#pragma unmanaged   
void my_trans_func( unsigned int u, PEXCEPTION_POINTERS pExp ) {  
   cout <<  "In my_trans_func.\n";  
   throw CMyException( u, pExp );  
}  
  
#pragma managed   
void managed_func() {  
   try  {  
      RaiseException( MYEXCEPTION_CODE, 0, 0, 0 );  
   }  
   catch ( CMyException x ) {}  
   catch ( ... ) {  
      printf_s("This is invoked since "  
               "_set_se_translator is not "  
               "supported when /clr is used\n" );  
    }  
}  
  
#pragma unmanaged   
void unmanaged_func() {  
   try  {  
      RaiseException( MYEXCEPTION_CODE,   
                      0, 0, 0 );  
   }  
   catch ( CMyException x ) {  
      printf("Caught an SEH exception with "  
             "exception code: %x\n", x.m_ErrorCode );  
    }  
    catch ( ... ) {}  
}  
  
// #pragma managed   
int main( int argc, char ** argv ) {  
   _set_se_translator( my_trans_func );  
  
   // It does not matter whether the translator function  
   // is registered in managed or unmanaged code  
   managed_func();  
   unmanaged_func();  
}  
```  
  
### Saída  
  
```  
This is invoked since _set_se_translator is not supported when /clr is used  
In my_trans_func.  
Caught an SEH exception with exception code: e0000101  
```  
  
## Consulte também  
 [Exception Handling](../windows/exception-handling-cpp-component-extensions.md)   
 [safe\_cast](../windows/safe-cast-cpp-component-extensions.md)   
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)