---
title: ConvertBSTRToString | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: ConvertBSTRToString
dev_langs: C++
helpviewer_keywords: ConvertBSTRToString function
ms.assetid: ab6ce555-3d75-4e9c-9cb8-ada6d8ce43b1
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a7f3463e34c17bcde4f64b89e1ae083228317293
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="convertbstrtostring"></a>ConvertBSTRToString
**Seção específica da Microsoft**  
  
 Converte um `BSTR` valor para um **char \*** .  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      char* __stdcall ConvertBSTRToString(  
   BSTR pSrc  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pSrc`  
 Uma variável BSTR.  
  
## <a name="remarks"></a>Comentários  
 `ConvertBSTRToString` aloca uma cadeia de caracteres que você deve excluir.  
  
## <a name="example"></a>Exemplo  
  
```  
// ConvertBSTRToString.cpp  
#include <comutil.h>  
#include <stdio.h>  
  
#pragma comment(lib, "comsuppw.lib")  
  
int main() {  
   BSTR bstrText = ::SysAllocString(L"Test");  
   wprintf_s(L"BSTR text: %s\n", bstrText);  
  
   char* lpszText2 = _com_util::ConvertBSTRToString(bstrText);  
   printf_s("char * text: %s\n", lpszText2);  
  
   SysFreeString(bstrText);  
   delete[] lpszText2;  
}  
```  
  
```Output  
BSTR text: Test  
char * text: Test  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<comutil.h >.  
  
 **Lib:** comsuppw.lib ou comsuppwd.lib (consulte [/ZC: (wchar_t é do tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)  
  
## <a name="see-also"></a>Consulte também  
 [Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)