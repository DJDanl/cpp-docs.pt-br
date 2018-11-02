---
title: Erro do compilador C3099
ms.date: 11/04/2016
f1_keywords:
- C3099
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
ms.openlocfilehash: e9a76fa2e0dc5602a88324cfd2fef85457ad7e99
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512106"
---
# <a name="compiler-error-c3099"></a>Erro do compilador C3099

'palavra-chave': use [System::AttributeUsageAttribute] para atributos gerenciados. Use [Windows::Foundation::Metadata::AttributeUsageAttribute] para atributos de WinRT

Use <xref:System.AttributeUsageAttribute> declarar **/clr** atributos. Use `Windows::Foundation::Metadata::AttributeUsageAttribute` declarar atributos de tempo de execução do Windows.

Para obter mais informações sobre atributos /CLR, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para atributos com suporte em tempo de execução do Windows, consulte [namespace do Windows](https://msdn.microsoft.com/library/windows/apps/windows.foundation.metadata.aspx)

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3099 e mostra como corrigi-lo.

```
// C3099.cpp
// compile with: /clr /c
using namespace System;
[usage(10)]   // C3099
// try the following line instead
// [AttributeUsageAttribute(AttributeTargets::All)]
ref class A : Attribute {};
```