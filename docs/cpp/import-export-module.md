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
description: Use declarações de importação e exportação para acessar e publicar tipos e funções definidas no módulo especificado.
ms.openlocfilehash: ae28bce8e06840cafa5c92521f6e9a62aa5bfde6
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301451"
---
# <a name="module-import-export"></a>module, import e export

As declarações **módulo**, **importar**e **Exportar** estão disponíveis no c++ 20 e exigem a opção de compilador [/experimental: module](../build/reference/experimental-module.md) juntamente com [/std: C + + mais recente](../build/reference/std-specify-language-standard-version.md). Para obter mais informações, consulte [visão geral dos C++módulos no ](modules-cpp.md).

## <a name="module"></a>module

Coloque uma declaração de **módulo** no início de um arquivo de implementação de módulo para especificar que o conteúdo do arquivo pertence ao módulo nomeado.

```cpp
module ModuleA;
```

## <a name="export"></a>export

Use uma declaração de **módulo de exportação** para o arquivo de interface principal do módulo, que deve ter a extensão **. IXX**:

```cpp
export module ModuleA;
```

Em um arquivo de interface, use o modificador de **exportação** em nomes que se destinam a fazer parte da interface pública:

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

Nomes não exportados não são visíveis para o código que importa o módulo:

```cpp
//MyProgram.cpp

import module ModuleA;

void main() {
  Bar::f(); // OK
  Bar::d(); // OK
  Bar::internal_f(); // Ill-formed: error C2065: 'internal_f': undeclared identifier
}
```

A palavra-chave **Export** pode não aparecer em um arquivo de implementação de módulo. Quando a **exportação** é aplicada a um nome de namespace, todos os nomes no namespace são exportados.

## <a name="import"></a>import

Use uma declaração de **importação** para tornar os nomes de um módulo visíveis em seu programa. A declaração de importação deve aparecer após a declaração de módulo e depois de qualquer #include diretivas, mas antes de qualquer declaração no arquivo.

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

Tanto a **importação** quanto o **módulo** são tratados como palavras-chave somente quando aparecem no início de uma linha lógica:

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

**Seção específica da Microsoft**

Na Microsoft C++, a **importação** e o **módulo** de tokens são sempre identificadores e nunca palavras-chave quando são usados como argumentos para uma macro.

### <a name="example"></a>Exemplo

```cpp
#define foo(…) __VA_ARGS__
foo(
import // Always an identifier, never a keyword
)
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Veja também

[Visão geral dos módulos noC++](modules-cpp.md)
