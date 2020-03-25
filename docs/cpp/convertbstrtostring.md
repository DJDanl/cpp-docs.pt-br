---
title: ConvertBSTRToString
ms.date: 11/04/2016
f1_keywords:
- ConvertBSTRToString
helpviewer_keywords:
- ConvertBSTRToString function
ms.assetid: ab6ce555-3d75-4e9c-9cb8-ada6d8ce43b1
ms.openlocfilehash: 1d0ad8727dd4d5ec06a45ec26c67dd3ad268f524
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189514"
---
# <a name="convertbstrtostring"></a>ConvertBSTRToString

**Seção específica da Microsoft**

Converte um valor `BSTR` em uma `char *`.

## <a name="syntax"></a>Sintaxe

```
char* __stdcall ConvertBSTRToString(BSTR pSrc);
```

#### <a name="parameters"></a>parâmetros

*pSrc*<br/>
Uma variável BSTR.

## <a name="remarks"></a>Comentários

**ConvertBSTRToString** aloca uma cadeia de caracteres que você deve excluir.

## <a name="example"></a>Exemplo

```cpp
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

**Cabeçalho:** \<fileutil. h >

**Lib:** comsuppw. lib ou comsuppwd. lib (consulte [/Zc: Wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)
