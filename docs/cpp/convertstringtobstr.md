---
title: ConvertStringToBSTR
ms.date: 11/04/2016
f1_keywords:
- ConvertStringToBSTR
helpviewer_keywords:
- ConvertStringToBSTR function
ms.assetid: 071f9b3b-9643-4e06-a1e5-de96ed15bab2
ms.openlocfilehash: 5e7d8abd29033fc88dae1e83fcc6467fb0ace46f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154614"
---
# <a name="convertstringtobstr"></a>ConvertStringToBSTR

**Seção específica da Microsoft**

Converte um valor `char *` em uma `BSTR`.

## <a name="syntax"></a>Sintaxe

```
BSTR __stdcall ConvertStringToBSTR(const char* pSrc)
```

#### <a name="parameters"></a>Parâmetros

*pSrc*<br/>
Um `char *` variável.

## <a name="example"></a>Exemplo

```cpp
// ConvertStringToBSTR.cpp
#include <comutil.h>
#include <stdio.h>

#pragma comment(lib, "comsuppw.lib")
#pragma comment(lib, "kernel32.lib")

int main() {
   char* lpszText = "Test";
   printf_s("char * text: %s\n", lpszText);

   BSTR bstrText = _com_util::ConvertStringToBSTR(lpszText);
   wprintf_s(L"BSTR text: %s\n", bstrText);

   SysFreeString(bstrText);
}
```

```Output
char * text: Test
BSTR text: Test
```

**Fim da seção específica da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<comutil. h >

**Lib:** comsuppw. lib ou comsuppwd (consulte [/ZC: wchar_t (wchar_t Is Native Type)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Consulte também

[Funções globais COM do compilador](../cpp/compiler-com-global-functions.md)