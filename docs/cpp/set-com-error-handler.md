---
title: _set_com_error_handler
ms.date: 11/04/2016
helpviewer_keywords:
- _set_com_error_handler function
ms.assetid: 49fe4fca-5e37-4d83-abaf-15be5ce37f94
ms.openlocfilehash: 226dce24de68edd66ca68c43e41ce0cb5b8a1b48
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857288"
---
# <a name="_set_com_error_handler"></a>_set_com_error_handler

Substitui a função padrão que é usada para o tratamento de erros COM. **_set_com_error_handler** é específica da Microsoft.

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

*Human*<br/>
Informações de HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

## <a name="remarks"></a>Comentários

Por padrão, o [_com_raise_error](../cpp/com-raise-error.md) manipula todos os erros de com. Você pode alterar esse comportamento usando **_set_com_error_handler** para chamar sua própria função de tratamento de erros.

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

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** \<comdef. h >

**Lib:** Se a opção de compilador **/Zc: wchar_t** for especificada (o padrão), use comsuppw. lib ou comsuppwd. lib. Se a opção **/Zc: wchar_t-** Compiler for especificada, use comsupp. lib. Para obter mais informações, incluindo como definir essa opção no IDE, consulte [/Zc: wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="see-also"></a>Consulte também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
