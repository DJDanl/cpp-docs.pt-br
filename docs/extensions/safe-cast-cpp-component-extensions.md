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
ms.openlocfilehash: 42e141caed720aa29cf918a2bdf69d9a2c4203dc
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311954"
---
# <a name="safe_cast-ccli-and-ccx"></a>safe_cast (C++/CLI e C++/CX)

A operação **safe_cast** retorna a expressão especificada como o tipo especificado, se bem-sucedida; caso contrário, lança `InvalidCastException`.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há comentários para esse recurso de linguagem que se apliquem a todos os tempos de execução.)

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast< type-id >( expression )
```

## <a name="windows-runtime"></a>Tempo de Execução do Windows

**safe_cast** permite alterar o tipo de uma expressão especificada. Em situações em que você espera que uma variável ou parâmetro seja conversível em um determinado tipo, é possível usar **safe_cast** sem um bloco **try-catch** para detectar erros de programação durante o desenvolvimento. Saiba mais em [Conversão (C++/CX)](../cppcx/casting-c-cx.md).

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast< type-id >( expression )
```

### <a name="parameters"></a>Parâmetros

*type-id*<br/>
O tipo para o qual converter a *expression*. Um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

*expression*<br/>
Uma expressão que avalia um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

### <a name="remarks"></a>Comentários

**safe_cast** lança `InvalidCastException` se não é possível converter *expression* para o tipo especificado por *type-id*. Para capturar `InvalidCastException`, especifique a opção do compilador [/EH (modelo de tratamento de exceções)](../build/reference/eh-exception-handling-model.md) e use uma instrução **try/catch**.

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

### <a name="parameters"></a>Parâmetros

*type-id*<br/>
Um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

*expression*<br/>
Uma expressão que avalia um identificador para um tipo de referência ou de valor, um tipo de valor ou uma referência de acompanhamento para um tipo de referência ou de valor.

### <a name="remarks"></a>Comentários

A expressão `safe_cast<`*type-id*`>(`*expression*`)` converte o operando *expression* em um objeto do tipo *type-id*.

O compilador aceitará um [static_cast](../cpp/static-cast-operator.md) na maioria dos lugares que aceitará um **safe_cast**.  No entanto, **safe_cast** tem a garantia de produzir um MSIL verificável, mas um **static_cast** poderia produzir um MSIL não verificável.  Consulte [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md) e [Peverify.exe (Ferramenta PEVerify)](/dotnet/framework/tools/peverify-exe-peverify-tool) para saber mais sobre código verificável.

Assim como **static_cast**, **safe_cast** chama conversões definidas pelo usuário.

Saiba mais sobre conversões em [Operadores de conversão](../cpp/casting-operators.md).

**safe_cast** não se aplica a **const_cast** (conversão de **const**).

**safe_cast** está no namespace da CLI.  Saiba mais em [Namespaces da CLI, de plataforma e padrão](platform-default-and-cli-namespaces-cpp-component-extensions.md).

Saiba mais sobre **safe_cast** em:

- [Conversões C-Style com /clr (C++/CLI)](c-style-casts-with-clr-cpp-cli.md)

- [Como: usar safe_cast no C++/CLI](../dotnet/how-to-use-safe-cast-in-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

Um exemplo de onde o compilador não aceitará **static_cast**, mas aceitará **safe_cast** está nas conversões entre tipos de interface não relacionados.  Com **safe_cast**, o compilador não emitirá um erro de conversão e executará uma verificação em tempo de execução para ver se a conversão é possível.

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
