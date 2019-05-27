---
title: classe ref e struct ref (C++/CLI e C++/CX)
ms.date: 05/16/2019
ms.topic: reference
f1_keywords:
- ref class
helpviewer_keywords:
- ref class keyword [C++]
- value class keyword [C++]
- value struct keyword [C++]
- ref struct keyword [C++]
ms.assetid: 5c360764-b229-49c6-9357-66213afbc372
ms.openlocfilehash: 9c993b134d6d359d0bc756f5e79d2f9cc137c9cf
ms.sourcegitcommit: bc1b14f29a02685f97c7ef5c098d16db6eaf369f
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/16/2019
ms.locfileid: "65788781"
---
# <a name="ref-class-and-ref-struct--ccli-and-ccx"></a>classe ref e struct ref (C++/CLI e C++/CX)

As extensões **classe ref** ou **struct ref** declaram uma classe ou struct cujo *tempo de vida do objeto* é administrado automaticamente. Quando o objeto não está mais acessível ou sai do escopo, a memória é liberada.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="syntax"></a>Sintaxe

```cpp
      class_access
      ref class
      name
      modifier :  inherit_accessbase_type {};
class_accessref structnamemodifier :  inherit_accessbase_type {};
class_accessvalue classnamemodifier :  inherit_accessbase_type {};
class_accessvalue structnamemodifier :  inherit_accessbase_type {};
```

### <a name="parameters"></a>Parâmetros

*class_access*<br/>
(Opcional) A acessibilidade da classe ou struct fora do assembly. Os valores possíveis são **public** e **private** (**private** é o padrão). As classes aninhadas ou structs não podem ter um especificador *class_access*.

*name*<br/>
O nome da classe ou struct.

*modifier*<br/>
(Opcional) [abstract](abstract-cpp-component-extensions.md) e [sealed](sealed-cpp-component-extensions.md) são os modificadores válidos.

*inherit_access*<br/>
(Opcional) A acessibilidade de *base_type*. A única acessibilidade permitida é **public** (**public** é o padrão).

*base_type*<br/>
(Opcional) Um tipo base. No entanto, um tipo de valor não pode atuar como um tipo base.

Saiba mais nas descrições de linguagem específicas desse parâmetro nas seções Windows Runtime e Common Language Runtime.

### <a name="remarks"></a>Comentários

A acessibilidade de membro padrão de um objeto declarado com **classe ref** ou **classe value** é **private**. E a acessibilidade de membro padrão de um objeto declarado com **struct ref** ou **struct value** é **public**.

Quando um tipo de referência herda de outro tipo de referência, as funções virtuais na classe base devem ser substituídas explicitamente (com [override](override-cpp-component-extensions.md)) ou ocultas (com [new (novo slot em vtable)](new-new-slot-in-vtable-cpp-component-extensions.md)). As funções de classe derivada também devem ser marcadas explicitamente como **virtual**.

Para detectar no tempo de compilação se um tipo é **classe ref** ou **struct ref**, ou **classe value** ou **struct value**, use `__is_ref_class (type)`, `__is_value_class (type)` ou `__is_simple_value_class (type)`. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

Saiba mais sobre classes e structs em

- [Como instanciar classes e structs](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md)

- [Semântica da pilha do C++ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md)

- [Classes, structs e uniões](../cpp/classes-and-structs-cpp.md)

- [Destruidores e finalizadores em Como definir e consumir classes e structs (C++/CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers)

- [Operadores definidos pelo usuário (C++/CLI)](../dotnet/user-defined-operators-cpp-cli.md)

- [Conversões definidas pelo usuário (C++/CLI)](../dotnet/user-defined-conversions-cpp-cli.md)

- [Como: encapsular a classe nativa a ser usada pelo C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)

- [Classes genéricas (C++/CLI)](generic-classes-cpp-cli.md)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

Confira [Classes e structs ref](../cppcx/ref-classes-and-structs-c-cx.md) e [Classes e structs value](https://msdn.microsoft.com/library/windows/apps/hh699861.aspx).

### <a name="parameters"></a>Parâmetros

*base_type*<br/>
(Opcional) Um tipo base. Uma **classe ref** ou uma **struct ref** pode herdar de zero ou mais interfaces e de zero ou um tipo **ref**. Uma **classe value** ou uma **struct value** só pode herdar de mais interfaces ou de nenhuma.

Quando você declara um objeto usando as palavras-chave **classe ref** ou **struct ref**, o objeto é acessado por um identificador para um objeto, ou seja, um ponteiro de contador de referência para o objeto. Quando a variável declarada sai do escopo, o compilador exclui automaticamente o objeto subjacente. Quando o objeto é usado como um parâmetro em uma chamada ou armazenado em uma variável, um identificador para o objeto é passado ou armazenado.

Quando você declara um objeto usando as palavras-chave **classe value** ou **struct value**, o tempo de vida do objeto declarado não é supervisionado. O objeto é como qualquer outra classe ou struct C++ padrão.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

A tabela a seguir lista as diferenças de sintaxe mostradas na seção **Todos os tempos de execução** que são específicas a C++/CLI.

### <a name="parameters"></a>Parâmetros

*base_type*<br/>
(Opcional) Um tipo base. Um **classe ref** ou **struct ref** pode herdar de nenhuma ou mais interfaces gerenciadas e de zero ou um tipo ref. Um **classe valuee** ou **struct value** só pode herdar de nenhuma ou mais interfaces gerenciadas.

As palavras-chave **classe ref** e **struct ref** dizem ao compilador que a classe ou struct deve ser alocada no heap. Quando o objeto é usado como um parâmetro em uma chamada ou armazenado em uma variável, uma referência ao objeto é passada ou armazenada.

As palavras-chave **classe value** e **struct value** informam ao compilador que o valor da classe ou struct alocada é passado para as funções ou armazenado em membros.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)