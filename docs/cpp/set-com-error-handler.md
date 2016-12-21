---
title: "_set_com_error_handler | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função _set_com_error_handler"
ms.assetid: 49fe4fca-5e37-4d83-abaf-15be5ce37f94
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _set_com_error_handler
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Substitui a função padrão que é usada para o tratamento de erros COM.  
  
## Sintaxe  
  
```  
void __stdcall _set_com_error_handler(  
   void (__stdcall *pHandler)(  
      HRESULT hr,   
      IErrorInfo* perrinfo  
   )  
);  
```  
  
#### Parâmetros  
 `pHandler`  
 Ponteiro para a função de substituição.  
  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 Objeto `IErrorInfo`.  
  
## Comentários  
 Por padrão, [\_com\_raise\_error](../cpp/com-raise-error.md) trata todos os erros COM.  Você pode alterar esse comportamento usando `_set_com_error_handler` para chamar sua própria função de tratamento de erros.  
  
 A função de substituição deve ter uma assinatura equivalente à de `_com_raise_error`.  
  
## Exemplo  
  
```  
// _set_com_error_handler.cpp  
// compile with /EHsc  
#include <stdio.h>  
#include <comdef.h>  
#include <comutil.h>  
  
// Importing ado dll to attempt to establish an ado connection.  
// Not related to _set_com_error_handler   
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "adoEOF")  
  
void __stdcall _My_com_raise_error(HRESULT hr, IErrorInfo* perrinfo)  
{  
   throw "Unable to establish the connection!";  
}  
  
int main()  
{  
   _set_com_error_handler(_My_com_raise_error);  
   _bstr_t bstrEmpty(L"");  
   _ConnectionPtr Connection = NULL;  
   try  
   {  
      Connection.CreateInstance(__uuidof(Connection));  
      Connection->Open(bstrEmpty, bstrEmpty, bstrEmpty, 0);   
   }  
   catch(char* errorMessage)  
   {  
      printf("Exception raised: %s\n", errorMessage);  
   }  
  
   return 0;  
}  
```  
  
  **Exceção gerada: Não é possível estabelecer a conexão\!**   
## Requisitos  
 **Cabeçalho:** comdef.h  
  
 **Bib:** se a opção do compilador “wchar\_t is Native Type” está ativada, use comsuppw.lib ou comsuppwd.lib.  Se “wchar\_t is Native Type” estiver desativado, use comsupp.lib.  Para obter mais informações, consulte [\/Zc:wchar\_t \(wchar\_t é do tipo nativo\)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
## Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)