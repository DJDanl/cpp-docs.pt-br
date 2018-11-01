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
ms.openlocfilehash: b63b7f6fe83c7761846d1d0c70de8b1665ad2f22
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641032"
---
# <a name="identifier-ccli"></a>__identifier (C++/CLI)

Permite o uso de palavras-chave C++ como identificadores.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

```cpp
__identifier(C++_keyword)
```

### <a name="remarks"></a>Comentários

Usar o **Identifier** palavra-chave para identificadores que não são palavras-chave é permitida, mas altamente recomendado como uma questão de estilo.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

**Exemplo**

No exemplo a seguir, uma classe chamada **modelo** é criado em c# e distribuído como uma DLL. No C + c++ /CLI programa que usa o **modelo** classe, o **Identifier** palavra-chave oculta o fato de que **modelo** é uma palavra-chave C++ padrão.

```cs
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

O **Identifier** palavra-chave é válida com o `/clr` opção de compilador.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

No exemplo a seguir, uma classe chamada **modelo** é criado em c# e distribuído como uma DLL. No C + c++ /CLI programa que usa o **modelo** classe, o **Identifier** palavra-chave oculta o fato de que **modelo** é uma palavra-chave C++ padrão.

```cs
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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)<br/>
[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)