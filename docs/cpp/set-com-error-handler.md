---
title: _set_com_error_handler
ms.date: 11/04/2016
helpviewer_keywords:
- _set_com_error_handler function
ms.assetid: 49fe4fca-5e37-4d83-abaf-15be5ce37f94
ms.openlocfilehash: 7c7c9d572dcb8e1323df003e15e44adc8491c058
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50567785"
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

*pHandler*<br/>
Ponteiro para a função de substituição.

*hr*<br/>
Informações de HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

## <a name="remarks"></a>Comentários

Por padrão, [com_raise_error](../cpp/com-raise-error.md) lida com todos os erros COM. Você pode alterar esse comportamento usando **set_com_error_handler** para chamar sua própria função de tratamento de erros.

A função de substituição deve ter uma assinatura equivalente à de `_com_raise_error`.

## <a name="example"></a>Exemplo

```cpp
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

**Cabeçalho:** \<comdef >

**Lib:** se o **wchar_t is Native Type** opção de compilador está ativada, use comsuppw. lib ou comsuppwd. Se **wchar_t is Native Type** estiver desativado, use comsupp. Para obter mais informações, consulte [/Zc:wchar_t (wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="see-also"></a>Consulte também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)