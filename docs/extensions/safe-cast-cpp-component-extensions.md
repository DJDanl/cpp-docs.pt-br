---
title: safe_cast (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- safe_cast
- safe_cast_cpp
- stdcli::language::safe_cast
helpviewer_keywords:
- safe_cast keyword [C++]
ms.assetid: 4fa688bf-a8ec-49bc-a4c5-f48134efa4f7
ms.openlocfilehash: 2eb09680ef6e7d1ee90b62eee8c8971fb4963212
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225118"
---
# <a name="safe_cast-ccli-and-ccx"></a>safe_cast (C++/CLI e C++/CX)

A operação **safe_cast** retorna a expressão especificada como o tipo especificado, se bem-sucedida; caso contrário, lança `InvalidCastException`.

## <a name="all-runtimes"></a>Todos os Runtimes

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast< type-id >( expression )
```

## <a name="windows-runtime"></a>Windows Runtime

**safe_cast** permite alterar o tipo de uma expressão especificada. Em situações em que você espera que uma variável ou parâmetro seja conversível em um determinado tipo, é possível usar **safe_cast** sem um bloco **try-catch** para detectar erros de programação durante o desenvolvimento. Saiba mais em [Conversão (C++/CX)](../cppcx/casting-c-cx.md).

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast< type-id >( expression )
```

### <a name="parameters"></a>parâmetros

*ID do tipo*<br/>
O tipo para o qual converter a *expression*. Um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

*expressão*<br/>
Uma expressão que avalia um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

### <a name="remarks"></a>Comentários

**safe_cast** gera `InvalidCastException` se não é possível converter a *expressão* para o tipo especificado por *ID de tipo*. Para detectar `InvalidCastException` , especifique a opção de compilador [/eh (modelo de tratamento de exceções)](../build/reference/eh-exception-handling-model.md) e use uma instrução **try/catch** .

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra como usar **safe_cast** com o Windows Runtime.

```cpp
// safe_cast_ZW.cpp
// compile with: /ZW /EHsc

using namespace default;
using namespace Platform;

interface class I1 {};
interface class I2 {};
interface class I3 {};

ref class X : public I1, public I2 {};

int main(Array<String^>^ args) {
   I1^ i1 = ref new X;
   I2^ i2 = safe_cast<I2^>(i1);   // OK, I1 and I2 have common type: X
   // I2^ i3 = static_cast<I2^>(i1);   C2440 use safe_cast instead
   try {
      I3^ i4 = safe_cast<I3^>(i1);   // Fails because i1 is not derived from I3.
   }
   catch(InvalidCastException^ ic) {
   wprintf(L"Caught expected exception: %s\n", ic->Message);
   }
}
```

```Output
Caught expected exception: InvalidCastException
```

## <a name="common-language-runtime"></a>Common Language Runtime

**safe_cast** permite que você altere o tipo de uma expressão e gere o código MSIL verificável.

### <a name="syntax"></a>Sintaxe

```cpp
[cli]:: safe_cast< type-id >( expression )
```

### <a name="parameters"></a>parâmetros

*ID do tipo*<br/>
Um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

*expressão*<br/>
Uma expressão que avalia um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

### <a name="remarks"></a>Comentários

A expressão do `safe_cast<` *tipo Expression-ID* `>(` *expression* `)` converte a *expressão* do operando em um objeto do tipo *Type-ID*.

O compilador aceitará um [static_cast](../cpp/static-cast-operator.md) na maioria dos lugares que aceitará um **safe_cast**.  No entanto, a **safe_cast** é garantida para produzir MSIL verificável, onde **`static_cast`** pode produzir MSIL não verificável.  Consulte [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md) e [Peverify.exe (Ferramenta PEVerify)](/dotnet/framework/tools/peverify-exe-peverify-tool) para saber mais sobre código verificável.

Como **`static_cast`** , **safe_cast** invoca conversões definidas pelo usuário.

Saiba mais sobre conversões em [Operadores de conversão](../cpp/casting-operators.md).

**safe_cast** não aplica uma **`const_cast`** (conversão **`const`** ).

**safe_cast** está no namespace da CLI.  Saiba mais em [Namespaces da CLI, de plataforma e padrão](platform-default-and-cli-namespaces-cpp-component-extensions.md).

Saiba mais sobre **safe_cast** em:

- [Conversões de Estilo C-Style com /clr (C++/CLI)](c-style-casts-with-clr-cpp-cli.md)

- [Como: usar safe_cast no C++/CLI](../dotnet/how-to-use-safe-cast-in-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

Um exemplo de onde o compilador não aceitará um **`static_cast`** , mas aceitará uma **safe_cast** é para conversões entre tipos de interface não relacionados.  Com **safe_cast**, o compilador não emitirá um erro de conversão e executará uma verificação em runtime para ver se a conversão é possível.

```cpp
// safe_cast.cpp
// compile with: /clr
using namespace System;

interface class I1 {};
interface class I2 {};
interface class I3 {};

ref class X : public I1, public I2 {};

int main() {
   I1^ i1 = gcnew X;
   I2^ i2 = safe_cast<I2^>(i1);   // OK, I1 and I2 have common type: X
   // I2^ i3 = static_cast<I2^>(i1);   C2440 use safe_cast instead
   try {
      I3^ i4 = safe_cast<I3^>(i1);   // fail at runtime, no common type
   }
   catch(InvalidCastException^) {
      Console::WriteLine("Caught expected exception");
   }
}
```

```Output
Caught expected exception
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
