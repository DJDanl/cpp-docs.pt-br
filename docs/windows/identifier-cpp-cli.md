---
title: Identifier (c + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- __identifier
- __identifier_cpp
dev_langs:
- C++
helpviewer_keywords:
- __identifier keyword [C++]
ms.assetid: 348428af-afa7-4ff3-b571-acf874301cf2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d578c820660d99e6fa217a14181330d258ab081b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613316"
---
# <a name="identifier-ccli"></a>__identifier (C++/CLI)

Permite o uso de palavras-chave do Visual C++ como identificadores.

## <a name="all-platforms"></a>Todas as Plataformas

### <a name="syntax"></a>Sintaxe

```cpp
__identifier(
Visual_C++_keyword
)  
```

### <a name="remarks"></a>Comentários

Usar o **Identifier** palavra-chave para identificadores que não são palavras-chave é permitida, mas altamente recomendado como uma questão de estilo.

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

**Exemplo**

No exemplo a seguir, uma classe chamada **modelo** é criado em c# e distribuído como uma DLL. No programa Visual C++ que usa o **modelo** classe, o **Identifier** palavra-chave oculta o fato de que **modelo** é uma palavra-chave C++ padrão.

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

No exemplo a seguir, uma classe chamada **modelo** é criado em c# e distribuído como uma DLL. No programa Visual C++ que usa o **modelo** classe, o **Identifier** palavra-chave oculta o fato de que **modelo** é uma palavra-chave C++ padrão.

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

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)  
[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)