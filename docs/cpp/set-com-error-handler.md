---
title: _set_com_error_handler
ms.date: 11/04/2016
helpviewer_keywords:
- _set_com_error_handler function
ms.assetid: 49fe4fca-5e37-4d83-abaf-15be5ce37f94
ms.openlocfilehash: debad733f351c710ada342e29fa95a4d1ff03b7d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749797"
---
# <a name="_set_com_error_handler"></a>_set_com_error_handler

Substitui a função padrão que é usada para o tratamento de erros COM. **_set_com_error_handler** é específico da Microsoft.

## <a name="syntax"></a>Sintaxe

```cpp
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

*Hr*<br/>
Informações do HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

## <a name="remarks"></a>Comentários

Por padrão, [_com_raise_error](../cpp/com-raise-error.md) lida com todos os erros de COM. Você pode alterar esse comportamento usando **_set_com_error_handler** para chamar sua própria função de manipulação de erros.

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

**Cabeçalho:** \<comdef.h>

**Lib:** Se a opção de compilador **/Zc:wchar_t** for especificada (o padrão), use comsuppw.lib ou comsuppwd.lib. Se a opção **/Zc:wchar_t-** compilador for especificada, use comsupp.lib. Para obter mais informações, incluindo como definir essa opção no IDE, consulte [/Zc:wchar_t (wchar_t É o Tipo Nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md).

## <a name="see-also"></a>Confira também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
