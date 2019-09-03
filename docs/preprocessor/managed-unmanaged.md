---
title: Pragmas managed, unmanaged
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.unmanaged
- managed_CPP
- unmanaged_CPP
- vc-pragma.managed
helpviewer_keywords:
- managed pragma
- pragmas, unmanaged
- pragmas, managed
- unmanaged pragma
ms.assetid: f072ddcc-e1ec-408a-8ce1-326ddb60e4a4
ms.openlocfilehash: 4c13155d1c84966a593df11baf525a0c3539f02c
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218813"
---
# <a name="managed-unmanaged-pragmas"></a>Pragmas managed, unmanaged

Habilite o controle de nível de função para compilar funções como gerenciadas ou não gerenciadas.

## <a name="syntax"></a>Sintaxe

> **#pragma gerenciado**\
> **#pragma não gerenciado**\
> **#pragma gerenciado (** [ **Push,** ] { **on** | **off** } **)** \
> **#pragma gerenciado (pop)**

## <a name="remarks"></a>Comentários

A opção de compilador [/CLR](../build/reference/clr-common-language-runtime-compilation.md) fornece controle de nível de módulo para a compilação de funções como gerenciadas ou não gerenciadas.

Uma função não gerenciada será compilada para a plataforma nativa. A execução dessa parte do programa será passada para a plataforma nativa pelo Common Language Runtime.

As funções são criadas como gerenciadas por padrão quando `/clr` é usado.

Ao aplicar estes pragmas:

- Adicione o pragma que precede uma função, mas não dentro de um corpo de função.

- Adicione as instruções pragma `#include` After. Não use esses pragmas antes `#include` de instruções.

O compilador ignora os pragmas **gerenciados** e **não gerenciados** se `/clr` não for usado na compilação.

Quando uma função de modelo é instanciada, o estado de pragma quando o modelo é definido determina se ele é gerenciado ou não gerenciado.

Para obter mais informações, consulte [inicialização de assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md).

## <a name="example"></a>Exemplo

```cpp
// pragma_directives_managed_unmanaged.cpp
// compile with: /clr
#include <stdio.h>

// func1 is managed
void func1() {
   System::Console::WriteLine("In managed function.");
}

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

// func2 is unmanaged
void func2() {
   printf("In unmanaged function.\n");
}

// #pragma managed
#pragma managed(pop)

// main is managed
int main() {
   func1();
   func2();
}
```

```Output
In managed function.
In unmanaged function.
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
