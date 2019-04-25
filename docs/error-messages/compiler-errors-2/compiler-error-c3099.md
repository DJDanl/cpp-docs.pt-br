---
title: Erro do compilador C3099
ms.date: 11/04/2016
f1_keywords:
- C3099
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
ms.openlocfilehash: 0f3eac1c232ef159d220a347d6b6dc3aed2fdd9a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62324773"
---
# <a name="compiler-error-c3099"></a>Erro do compilador C3099

'palavra-chave': use [System::AttributeUsageAttribute] para atributos gerenciados. Use [Windows::Foundation::Metadata::AttributeUsageAttribute] para atributos de WinRT

Use <xref:System.AttributeUsageAttribute> declarar **/clr** atributos. Use `Windows::Foundation::Metadata::AttributeUsageAttribute` declarar atributos de tempo de execução do Windows.

Para obter mais informações sobre atributos /CLR, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md). Para atributos com suporte em tempo de execução do Windows, consulte [namespace do Windows](/uwp/api/windows.foundation.metadata)

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