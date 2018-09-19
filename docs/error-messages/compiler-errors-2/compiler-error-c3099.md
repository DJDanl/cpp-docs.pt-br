---
title: Erro do compilador C3099 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3099
dev_langs:
- C++
helpviewer_keywords:
- C3099
ms.assetid: b3dded0f-76c9-42c1-991b-532eb8619661
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c5f11e049965fb7374a2294e813502d1279f9f26
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46067402"
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