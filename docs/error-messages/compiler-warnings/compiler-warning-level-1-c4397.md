---
title: Compilador aviso (nível 1) C4397
ms.date: 11/04/2016
f1_keywords:
- C4397
helpviewer_keywords:
- C4397
ms.assetid: 6346fdc2-dbbf-4fba-803a-32b0d0a707be
ms.openlocfilehash: 4ad690d78c1544adbe365a35ba3b5921c883631e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50498757"
---
# <a name="compiler-warning-level-1-c4397"></a>Compilador aviso (nível 1) C4397

DefaultCharSetAttribute é ignorado

<xref:System.Runtime.InteropServices.DefaultCharSetAttribute> é ignorado pelo compilador do Visual C++. Para especificar um conjunto de caracteres para a DLL, use a opção de CharSet do DllImport. Para obter mais informações, consulte [usando Interop do C++ (PInvoke implícito)](../../dotnet/using-cpp-interop-implicit-pinvoke.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4397.

```
// C4397.cpp
// compile with: /W1 /c /clr
using namespace System;
using namespace System::Runtime::InteropServices;

[module:DefaultCharSetAttribute(CharSet::Unicode)];   // C4397

[DllImport("kernel32", EntryPoint="CloseHandle", CharSet=CharSet::Unicode)]   // OK
extern "C" bool ImportDefault(IntPtr hObject);

public ref class MySettingVC {
public:
   void method() {
      ImportDefault(IntPtr::Zero);
   }
};

[StructLayout(LayoutKind::Explicit)]
public ref struct StructDefault1{};

public ref class ClassDefault1{};
```