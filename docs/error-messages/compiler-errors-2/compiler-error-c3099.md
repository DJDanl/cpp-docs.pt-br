---
title: Erro do compilador C3099
ms.date: 11/04/2016
f1_keywords:
- C3099
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
ms.openlocfilehash: 81f508c47c678d86f8f95303861b42f8a70daa57
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74750046"
---
# <a name="compiler-error-c3099"></a>Erro do compilador C3099

' palavra-chave ': use [System:: AttributeUsageAttribute] para atributos gerenciados; Use [Windows:: Foundation:: Metadata:: AttributeUsageAttribute] para atributos do WinRT

Use <xref:System.AttributeUsageAttribute> para declarar atributos **/CLR** . Use `Windows::Foundation::Metadata::AttributeUsageAttribute` para declarar Windows Runtime atributos.

Para obter mais informações sobre atributos/CLR, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md). Para obter os atributos com suporte no Windows Runtime, consulte [namespace Windows. Foundation. Metadata](/uwp/api/windows.foundation.metadata)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3099 e mostra como corrigi-lo.

```cpp
// C3099.cpp
// compile with: /clr /c
using namespace System;
[usage(10)]   // C3099
// try the following line instead
// [AttributeUsageAttribute(AttributeTargets::All)]
ref class A : Attribute {};
```
