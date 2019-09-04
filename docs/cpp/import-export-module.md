---
title: module, import e export
ms.date: 07/15/2019
f1_keywords:
- module_cpp
- import_cpp
- export_cpp
helpviewer_keywords:
- modules [C++]
- modules [C++], import
- modules [C++], export
description: Use a instrução de importação para acessar tipos e funções definidos no módulo especificado.
ms.openlocfilehash: ee1d50a76a3304359c0771aa0174968439f5faa4
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70273620"
---
# <a name="module-import-export"></a>module, import e export

As palavras-chave **módulo**, **importar**e **Exportar** estão disponíveis no c++ 20 e exigem a opção de compilador [/experimental: module](../build/reference/experimental-module.md) juntamente com [/std: C + + mais recente](../build/reference/std-specify-language-standard-version.md). Para obter mais informações, consulte [visão geral dos C++módulos no ](modules-cpp.md).

## <a name="module"></a>module

Use a instrução **Module** no início de um arquivo de implementação de módulo para especificar que o conteúdo do arquivo pertence ao módulo nomeado. 

```cpp
module ModuleA;
```

## <a name="export"></a>export

Use a instrução **Export Module** para o arquivo de interface principal do módulo, que deve ter a extensão **. IXX**:

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

A palavra-chave **Export** pode não aparecer em um arquivo de implementação de módulo. Quando o modificador de **exportação** é aplicado a um nome de namespace, todos os nomes no namespace são exportados.

## <a name="import"></a>import

Use a instrução de **importação** para tornar os nomes de um módulo visíveis em seu programa. A instrução import deve aparecer após a instrução Module e depois de qualquer #include diretivas, mas antes de qualquer declaração no arquivo.

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

## <a name="see-also"></a>Consulte também

[Visão geral dos módulos noC++](modules-cpp.md)
