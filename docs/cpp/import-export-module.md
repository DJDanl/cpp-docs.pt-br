---
title: module, import e export
ms.date: 12/12/2019
f1_keywords:
- module_cpp
- import_cpp
- export_cpp
helpviewer_keywords:
- modules [C++]
- modules [C++], import
- modules [C++], export
description: Use declarações de importação e exportação para acessar e publicar tipos e funções definidos no módulo especificado.
ms.openlocfilehash: a765e9a406660d3c945ef3d70754178b0648458c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374110"
---
# <a name="module-import-export"></a>module, import e export

As declarações **de módulo,** **importação**e **exportação** estão disponíveis em C++20 e requerem o interruptor de compilação [/experimental:module](../build/reference/experimental-module.md) juntamente com [/std:c++mais recente](../build/reference/std-specify-language-standard-version.md). Para obter mais informações, consulte [Visão geral dos módulos em C++](modules-cpp.md).

## <a name="module"></a>module

Coloque uma declaração de **módulo** no início de um arquivo de implementação do módulo para especificar que o conteúdo do arquivo pertence ao módulo nomeado.

```cpp
module ModuleA;
```

## <a name="export"></a>exportar

Use uma declaração **de módulo de exportação** para o arquivo de interface principal do módulo, que deve ter extensão **.ixx**:

```cpp
export module ModuleA;
```

Em um arquivo de interface, use o modificador **de exportação** em nomes destinados a fazer parte da interface pública:

```cpp
// ModuleA.ixx

export module ModuleA;

namespace Bar
{
   export int f();
   export double d();
   double internal_f(); // not exported
}
```

Os nomes não exportados não são visíveis para o código que importa o módulo:

```cpp
//MyProgram.cpp

import module ModuleA;

int main() {
  Bar::f(); // OK
  Bar::d(); // OK
  Bar::internal_f(); // Ill-formed: error C2065: 'internal_f': undeclared identifier
}
```

A **palavra-chave de exportação** pode não aparecer em um arquivo de implementação do módulo. Quando **a exportação** é aplicada a um nome namespace, todos os nomes no namespace são exportados.

## <a name="import"></a>importar

Use uma declaração **de importação** para tornar os nomes de um módulo visíveis em seu programa. A declaração de importação deve aparecer após a declaração do módulo e após quaisquer #include diretrizes, mas antes de quaisquer declarações no arquivo.

```cpp
module ModuleA;

#include "custom-lib.h"
import std.core;
import std.regex;
import ModuleB;

// begin declarations here:
template <class T>
class Baz
{...};
```

## <a name="remarks"></a>Comentários

Tanto **a importação** quanto o **módulo** são tratados como palavras-chave apenas quando aparecem no início de uma linha lógica:

```cpp

// OK:
module ;
module module-name
import :
import <
import "
import module-name
export module ;
export module module-name
export import :
export import <
export import "
export import module-name

// Error:
int i; module ;
```

**Específico da Microsoft**

No Microsoft C++, a **importação** e o **módulo** dos tokens são sempre identificadores e nunca palavras-chave quando são usados como argumentos para uma macro.

### <a name="example"></a>Exemplo

```cpp
#define foo(…) __VA_ARGS__
foo(
import // Always an identifier, never a keyword
)
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte Também

[Visão geral dos módulos no C++](modules-cpp.md)
