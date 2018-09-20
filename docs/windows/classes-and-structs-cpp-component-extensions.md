---
title: Classes e Structs (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- ref class keyword [C++]
- value class keyword [C++]
- value struct keyword [C++]
- ref struct keyword [C++]
ms.assetid: 5c360764-b229-49c6-9357-66213afbc372
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 60e388e18e6d3607dac1946c3fd9a511e948afd4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448370"
---
# <a name="classes-and-structs--c-component-extensions"></a>Classes e Estruturas (Extensões de Componentes C++)

Declara uma classe ou struct cujos *tempo de vida do objeto* é administrado automaticamente. Quando o objeto não está mais acessível ou sai do escopo, o Visual C++ descarta automaticamente a memória alocada para o objeto.

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
(Opcional) A acessibilidade de classe ou struct fora do assembly. Os valores possíveis são **pública** e **privada** (**privada** é o padrão). Classes aninhadas ou structs não podem ter uma *class_access* especificador.

*name*<br/>
O nome da classe ou struct.

*Modificador*<br/>
(Opcional) [abstrata](../windows/abstract-cpp-component-extensions.md) e [lacrado](../windows/sealed-cpp-component-extensions.md) são os modificadores válidos.

*inherit_access*<br/>
(Opcional) A acessibilidade de *base_type*. É a única acessibilidade permitida **pública** (**público** é o padrão).

*base_type*<br/>
(Opcional) Um tipo base. No entanto, um tipo de valor não pode atuar como um tipo base.

Para obter mais informações, consulte as descrições de idioma específico desse parâmetro em tempo de execução do Windows e Runtimesections de linguagem comum.

### <a name="remarks"></a>Comentários

A acessibilidade de membro padrão de um objeto declarado com **classe ref** ou **classe de valor** está **privada**. E a acessibilidade de membro padrão de um objeto declarado com **ref struct** ou **valor&lt;1** está **público**.

Quando um tipo de referência herda de outro tipo de referência, as funções virtuais na classe base devem ser substituídas explicitamente (com [substituir](../windows/override-cpp-component-extensions.md)) ou oculto (com [novo (novo slot em vtable)](../windows/new-new-slot-in-vtable-cpp-component-extensions.md)). As funções de classe derivada também devem ser marcadas explicitamente como **virtual**.

Para detectar no tempo de compilação se um tipo é um **classe ref** ou **ref struct**, ou uma **classe de valor** ou **struct de valor**, use `__is_ref_class (type)`, `__is_value_class (type)`, ou `__is_simple_value_class (type)`. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).

Para obter mais informações sobre classes e structs, consulte

- [Criando uma instância de Classes e Structs](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md)

- [Semântica da pilha do C++ para tipos de referência](../dotnet/cpp-stack-semantics-for-reference-types.md)

- [Classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md)

- [Destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + / CLI)](../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers)

- [Operadores definidos pelo usuário (C++/CLI)](../dotnet/user-defined-operators-cpp-cli.md)

- [Conversões definidas pelo usuário (C++/CLI)](../dotnet/user-defined-conversions-cpp-cli.md)

- [Como encapsular a classe nativa a ser usada por C#](../dotnet/how-to-wrap-native-class-for-use-by-csharp.md)

- [Classes genéricas (C++/CLI)](../windows/generic-classes-cpp-cli.md)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="remarks"></a>Comentários

Ver [classes e estruturas Ref](../cppcx/ref-classes-and-structs-c-cx.md) e [classes e estruturas de valor](https://msdn.microsoft.com/library/windows/apps/hh699861.aspx).

### <a name="parameters"></a>Parâmetros

*base_type*<br/>
(Opcional) Um tipo base. Um **classe ref** ou **ref struct** pode herdar de zero ou mais interfaces e zero ou uma **ref** tipos. Um **classe de valor** ou **struct de valor** só pode herdar de zero ou mais interfaces.

Quando você declarar um objeto usando o **classe ref** ou **ref struct** palavras-chave, o objeto é acessado por um identificador para um objeto, ou seja, um ponteiro de contador de referência para o objeto. Quando a variável declarada sai do escopo, o compilador exclui automaticamente o objeto subjacente. Quando o objeto é usado como um parâmetro em uma chamada ou é armazenado em uma variável, um identificador para o objeto é passado, na verdade, ou armazenado.

Quando você declarar um objeto usando o **classe de valor** ou **struct de valor** palavras-chave, o tempo de vida do objeto do objeto declarado não é supervisionado. O objeto é como qualquer outra classe C++ padrão ou struct.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

A tabela a seguir lista as diferenças de sintaxe mostrada na **todos os tempos de execução** seção são específicas para C + + c++ CLI.

### <a name="parameters"></a>Parâmetros

*base_type*<br/>
(Opcional) Um tipo base. Um **classe ref** ou **ref struct** pode herdar de zero ou mais gerenciados interfaces e zero ou tipos de uma ref. Um **classe de valor** ou **struct de valor** só pode herdar de zero ou mais interfaces gerenciadas.

O **classe ref** e **ref struct** palavras-chave dizer ao compilador que a classe ou estrutura deve ser alocado no heap. Quando o objeto é usado como um parâmetro em uma chamada ou é armazenado em uma variável, uma referência ao objeto é passada, na verdade, ou armazenada.

O **classe de valor** e **struct de valor** palavras-chave informa ao compilador que o valor de alocado de classe ou estrutura é passado para as funções ou armazenado em membros.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)