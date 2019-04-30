---
title: Assemblies amigáveis (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- friend assemblies, Visual C++
ms.assetid: 8d55fee0-b7c2-4fbe-a23b-dfe424dc71cd
ms.openlocfilehash: e469556a773ffcdbf50e53d94022c0b6b7abf869
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404423"
---
# <a name="friend-assemblies-c"></a>Assemblies amigáveis (C++)

Para tempos de execução aplicáveis, os *assemblies amigáveis* tipos que estão no escopo de namespace ou escopo global em um componente de assembly acessível a um ou mais assemblies de cliente ou netmodules torna o recurso de linguagem.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

**Comentários**

(Esse recurso de linguagem é sem suporte em todos os tempos de execução.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

**Comentários**

(Esse recurso de linguagem é sem suporte em tempo de execução do Windows.)

### <a name="requirements"></a>Requisitos

Opção do compilador: **/ZW**

## <a name="common-language-runtime"></a>Common Language Runtime

**Comentários**

#### <a name="to-make-types-at-namespace-scope-or-global-scope-in-an-assembly-component-accessible-to-a-client-assembly-or-netmodule"></a>Para disponibilizar tipos no escopo de namespace ou escopo global em um componente de assembly para um assembly de cliente ou um. netmodule

1. No componente, especificar um atributo de assembly <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute>e passe o nome do assembly de cliente ou. netmodule que acessará tipos no escopo de namespace ou escopo global no componente.  Você pode especificar vários assemblies de cliente ou netmodules especificando atributos adicionais.

1. No assembly de cliente ou. netmodule, quando você referenciar o assembly do componente por meio `#using`, passe o `as_friend` atributo.  Se você especificar o `as_friend` atributo para um assembly que não especifica `InternalsVisibleToAttribute`, será gerada uma exceção de tempo de execução se você tentar acessar um tipo no escopo de namespace ou escopo global no componente.

Um erro de compilação ocorrerá se o assembly que contém o <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> atributo não tem um nome forte, mas o assembly de cliente que usa o `as_friend` atributo faz.

Embora tipos em escopo global e de escopo de namespace podem ser um assembly de cliente ou um. netmodule, acessibilidade de membro ainda está em vigor.  Por exemplo, você não pode acessar um membro privado.

Acesso a todos os tipos em um assembly deve ser concedido explicitamente.  Por exemplo, o assembly C não tem acesso a todos os tipos em um assembly se o assembly C faz referência ao assembly B e o assembly B tem acesso a todos os tipos no assembly A.

Para obter informações sobre como assinar — ou seja, como dar um nome forte para — um assembly que é criado usando o Visual C++ compilador, consulte [Assemblies com nome forte (assinatura de Assembly) (C++/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).

Como uma alternativa para usar o recurso de assemblies de amigo, você pode usar <xref:System.Security.Permissions.StrongNameIdentityPermission> para restringir o acesso aos tipos individuais.

### <a name="requirements"></a>Requisitos

Opção de compilador: **/clr**

### <a name="examples"></a>Exemplos

O exemplo de código a seguir define um componente que especifica um assembly de cliente que tenha acesso aos tipos no componente.

```cpp
// friend_assemblies.cpp
// compile by using: /clr /LD
using namespace System::Runtime::CompilerServices;
using namespace System;
// an assembly attribute, not bound to a type
[assembly:InternalsVisibleTo("friend_assemblies_2")];

ref class Class1 {
public:
   void Test_Public() {
      Console::WriteLine("Class1::Test_Public");
   }
};
```

O exemplo de código a seguir acessa um tipo particular no componente.

```cpp
// friend_assemblies_2.cpp
// compile by using: /clr
#using "friend_assemblies.dll" as_friend

int main() {
   Class1 ^ a = gcnew Class1;
   a->Test_Public();
}
```

```Output
Class1::Test_Public
```

O exemplo de código a seguir define um componente, mas não especifica um assembly de cliente que terão acesso aos tipos no componente.

Observe que o componente está vinculado por meio **/OPT: noref**. Isso garante que os tipos privados são emitidos nos metadados do componente, que não é necessário quando o `InternalsVisibleTo` atributo estiver presente. Para obter mais informações, consulte [/OPT (otimizações)](../build/reference/opt-optimizations.md).

```cpp
// friend_assemblies_3.cpp
// compile by using: /clr /LD /link /opt:noref
using namespace System;

ref class Class1 {
public:
   void Test_Public() {
      Console::WriteLine("Class1::Test_Public");
   }
};
```

O exemplo de código a seguir define um cliente que tenta acessar um tipo particular em um componente que não dá acesso aos seus tipos privados. Devido ao comportamento de tempo de execução, se você quiser capturar a exceção, você deve tentar acessar um tipo privado em uma função auxiliar.

```cpp
// friend_assemblies_4.cpp
// compile by using: /clr
#using "friend_assemblies_3.dll" as_friend
using namespace System;

void Test() {
   Class1 ^ a = gcnew Class1;
}

int main() {
   // to catch this kind of exception, use a helper function
   try {
      Test();
   }
   catch(MethodAccessException ^ e) {
      Console::WriteLine("caught an exception");
   }
}
```

```Output
caught an exception
```

O exemplo de código a seguir mostra como criar um componente de nome forte que especifica um assembly de cliente que terão acesso aos tipos no componente.

```cpp
// friend_assemblies_5.cpp
// compile by using: /clr /LD /link /keyfile:friend_assemblies.snk
using namespace System::Runtime::CompilerServices;
using namespace System;
// an assembly attribute, not bound to a type

[assembly:InternalsVisibleTo("friend_assemblies_6, PublicKey=00240000048000009400000006020000002400005253413100040000010001000bf45d77fd991f3bff0ef51af48a12d35699e04616f27ba561195a69ebd3449c345389dc9603d65be8cd1987bc7ea48bdda35ac7d57d3d82c666b7fc1a5b79836d139ef0ac8c4e715434211660f481612771a9f7059b9b742c3d8af00e01716ed4b872e6f1be0e94863eb5745224f0deaba5b137624d7049b6f2d87fba639fc5")];

private ref class Class1 {
public:
   void Test_Public() {
      Console::WriteLine("Class1::Test_Public");
   }
};
```

Observe que o componente deve especificar sua chave pública. Sugerimos que você execute os seguintes comandos em sequência em um prompt de comando para criar um par de chaves e obter a chave pública:

**sn -d friend_assemblies.snk**

**sn -k friend_assemblies.snk**

**sn -i friend_assemblies.snk friend_assemblies.snk**

**sn -pc friend_assemblies.snk key.publickey**

**sn - tp key.publickey**

O exemplo de código a seguir acessa um tipo particular no componente de nome forte.

```cpp
// friend_assemblies_6.cpp
// compile by using: /clr /link /keyfile:friend_assemblies.snk
#using "friend_assemblies_5.dll" as_friend

int main() {
   Class1 ^ a = gcnew Class1;
   a->Test_Public();
}
```

```Output
Class1::Test_Public
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md)
