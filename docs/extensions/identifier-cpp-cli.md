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
ms.openlocfilehash: 395f1443f4eef16d9eea44c23a6e3288daf03d14
ms.sourcegitcommit: c4528a7424d35039454f17778baf1b5f98fbbee7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/01/2020
ms.locfileid: "76912837"
---
# <a name="__identifier-ccli"></a>__identifier (C++/CLI)

Permite o uso de palavras-chave C++ como identificadores.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

```cpp
__identifier(C++_keyword)
```

### <a name="remarks"></a>Comentários

O uso da palavra-chave **__identifier** para identificadores que não são palavras-chave é permitido, mas fortemente desaconselhado por questões de estilo.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos do

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

**Exemplo**

No exemplo a seguir, uma classe chamada **template** é criada em C# e distribuída como uma DLL. No programa C++/CLI que usa a classe **template**, a palavra-chave **__identifier** esconde o fato de que **template** é uma palavra-chave padrão C++.

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

### <a name="requirements"></a>Requisitos do

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

No exemplo a seguir, uma classe chamada **template** é criada em C# e distribuída como uma DLL. No programa C++/CLI que usa a classe **template**, a palavra-chave **__identifier** esconde o fato de que **template** é uma palavra-chave padrão C++.

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

## <a name="see-also"></a>Veja também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)<br/>
[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)