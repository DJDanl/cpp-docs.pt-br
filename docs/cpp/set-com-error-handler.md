---
title: set_com_error_handler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- _set_com_error_handler function
ms.assetid: 49fe4fca-5e37-4d83-abaf-15be5ce37f94
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 626227fb9c5162e5b9fc72fc64348b75ecb27e44
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="setcomerrorhandler"></a>_set_com_error_handler
**Seção específica da Microsoft**  
  
 Substitui a função padrão que é usada para o tratamento de erros COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void __stdcall _set_com_error_handler(  
   void (__stdcall *pHandler)(  
      HRESULT hr,   
      IErrorInfo* perrinfo  
   )  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pHandler`  
 Ponteiro para a função de substituição.  
  
 `hr`  
 Informações de `HRESULT`.  
  
 `perrinfo`  
 Objeto `IErrorInfo`.  
  
## <a name="remarks"></a>Comentários  
 Por padrão, [com_raise_error](../cpp/com-raise-error.md) trata todos os erros de COM. Você pode alterar esse comportamento usando `_set_com_error_handler` para chamar sua própria função de tratamento de erros.  
  
 A função de substituição deve ter uma assinatura equivalente à de `_com_raise_error`.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
Exception raised: Unable to establish the connection!  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** comdef.h  
  
 **Lib:** se o **wchar_t é do tipo nativo** opção de compilador está ativada, use comsuppw.lib ou comsuppwd.lib. Se **wchar_t é do tipo nativo** está desativado, use comsupp.lib. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).  
  
## <a name="see-also"></a>Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
