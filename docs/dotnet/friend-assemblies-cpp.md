---
title: Assemblies amigáveis (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- friend assemblies, Visual C++
ms.assetid: 8d55fee0-b7c2-4fbe-a23b-dfe424dc71cd
ms.openlocfilehash: a42caaf07f6ec0c71f63d6a0df8a79fff6f737e6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221439"
---
# <a name="friend-assemblies-c"></a>Assemblies amigáveis (C++)

Para tempos de execução aplicáveis, o recurso de linguagem *Friend Assemblies* torna os tipos que estão no escopo de namespace ou escopo global em um componente de assembly acessível a um ou mais assemblies de cliente ou. netmodules.

## <a name="all-runtimes"></a>Todos os Runtimes

**Comentários**

(Esse recurso de idioma não tem suporte em todos os tempos de execução.)

## <a name="windows-runtime"></a>Windows Runtime

**Comentários**

(Esse recurso de linguagem não é compatível com o Windows Runtime.)

### <a name="requirements"></a>Requisitos

Opção do compilador: **/zw**

## <a name="common-language-runtime"></a>Common Language Runtime

**Comentários**

#### <a name="to-make-types-at-namespace-scope-or-global-scope-in-an-assembly-component-accessible-to-a-client-assembly-or-netmodule"></a>Para tornar tipos no escopo de namespace ou escopo global em um componente de assembly acessível para um assembly de cliente ou. netmodule

1. No componente, especifique um atributo de assembly <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> e passe o nome do assembly de cliente ou. netmodule que acessará os tipos no escopo de namespace ou escopo global no componente.  Você pode especificar vários assemblies de cliente ou. netmodules especificando atributos adicionais.

1. No assembly de cliente ou. netmodule, quando você faz referência ao assembly de componente usando `#using` , passe o **`as_friend`** atributo.  Se você especificar o **`as_friend`** atributo para um assembly que não é especificado `InternalsVisibleToAttribute` , uma exceção de tempo de execução será gerada se você tentar acessar um tipo no escopo de namespace ou escopo global no componente.

Um erro de compilação ocorrerá se o assembly que contém o <xref:System.Runtime.CompilerServices.InternalsVisibleToAttribute> atributo não tiver um nome forte, mas o assembly de cliente que usa o **`as_friend`** atributo.

Embora os tipos no escopo do namespace e no escopo global possam ser conhecidos por um assembly de cliente ou. netmodule, a acessibilidade do membro ainda está em vigor.  Por exemplo, você não pode acessar um membro privado.

O acesso a todos os tipos em um assembly deve ser concedido explicitamente.  Por exemplo, o assembly C não tem acesso a todos os tipos no assembly A se o assembly C referenciar o assembly B e o assembly B tiver acesso a todos os tipos no assembly A.

Para obter informações sobre como assinar, ou seja, como dar um nome forte para — um assembly criado usando o compilador do Microsoft C++, consulte [assemblies de nome forte (assinatura de assembly) (C++/CLI)](../dotnet/strong-name-assemblies-assembly-signing-cpp-cli.md).

Como alternativa ao uso do recurso Friend Assemblies, você pode usar o <xref:System.Security.Permissions.StrongNameIdentityPermission> para restringir o acesso a tipos individuais.

### <a name="requirements"></a>Requisitos

Opção do compilador: **/clr**

### <a name="examples"></a>Exemplos

O exemplo de código a seguir define um componente que especifica um assembly de cliente que tem acesso aos tipos no componente.

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

O próximo exemplo de código acessa um tipo particular no componente.

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

O exemplo de código a seguir define um componente, mas não especifica um assembly de cliente que terá acesso aos tipos no componente.

Observe que o componente está vinculado usando **/OPT: NOREF**. Isso garante que os tipos privados sejam emitidos nos metadados do componente, o que não é necessário quando o `InternalsVisibleTo` atributo está presente. Para obter mais informações, consulte [/opt (otimizations)](../build/reference/opt-optimizations.md).

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

O exemplo de código a seguir define um cliente que tenta acessar um tipo particular em um componente que não dá acesso a seus tipos privados. Devido ao comportamento do tempo de execução, se você quiser capturar a exceção, você deve tentar acessar um tipo privado em uma função auxiliar.

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

O exemplo de código a seguir mostra como criar um componente de nome forte que especifica um assembly de cliente que terá acesso aos tipos no componente.

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

Observe que o componente deve especificar sua chave pública. Sugerimos que você execute os seguintes comandos sequencialmente em um prompt de comando para criar um par de chaves e obter a chave pública:

**SN-d friend_assemblies. SNK**

**SN-k friend_assemblies. SNK**

**sn-i friend_assemblies. SNK friend_assemblies. SNK**

**SN-PC friend_assemblies. SNK Key. PublicKey**

**SN-TP chave. PublicKey**

O próximo exemplo de código acessa um tipo privado no componente de nome forte.

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

## <a name="see-also"></a>Confira também

[Extensões de componentes para plataformas de runtime](../extensions/component-extensions-for-runtime-platforms.md)
