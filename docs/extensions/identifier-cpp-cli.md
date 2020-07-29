---
title: __identifier (C++/CLI)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- __identifier
- __identifier_cpp
helpviewer_keywords:
- __identifier keyword [C++]
ms.assetid: 348428af-afa7-4ff3-b571-acf874301cf2
ms.openlocfilehash: 5f95e9fc55acd33705b855c7c4f0ef268d4776a0
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219684"
---
# <a name="__identifier-ccli"></a>__identifier (C++/CLI)

Permite o uso de palavras-chave C++ como identificadores.

## <a name="all-platforms"></a>Todas as plataformas

### <a name="syntax"></a>Sintaxe

```cpp
__identifier(C++_keyword)
```

### <a name="remarks"></a>Comentários

O uso da palavra-chave **__identifier** para identificadores que não são palavras-chave é permitido, mas fortemente desaconselhado por questões de estilo.

## <a name="windows-runtime"></a>Windows Runtime

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

**Exemplo**

No exemplo a seguir, uma classe chamada `template` é criada em C# e distribuída como uma dll. No programa C++/CLI que usa a `template` classe, a **`__identifier`** palavra-chave oculta o fato que `template` é uma palavra-chave C++ padrão.

```csharp
// identifier_template.cs
// compile with: /target:library
public class template {
   public void Run() { }
}
```

```cpp
// keyword__identifier.cpp
// compile with: /ZW
#using <identifier_template.dll>
int main() {
   __identifier(template)^ pTemplate = ref new __identifier(template)();
   pTemplate->Run();
}
```

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

A palavra-chave **__identifier** é válida com a opção do compilador `/clr`.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

No exemplo a seguir, uma classe chamada `template` é criada em C# e distribuída como uma dll. No programa C++/CLI que usa a `template` classe, a **`__identifier`** palavra-chave oculta o fato que `template` é uma palavra-chave C++ padrão.

```csharp
// identifier_template.cs
// compile with: /target:library
public class template {
   public void Run() { }
}
```

```cpp
// keyword__identifier.cpp
// compile with: /clr
#using <identifier_template.dll>

int main() {
   __identifier(template) ^pTemplate = gcnew __identifier(template)();
   pTemplate->Run();
}
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
