---
title: Safe_cast (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- safe_cast
- safe_cast_cpp
- stdcli::language::safe_cast
dev_langs:
- C++
helpviewer_keywords:
- safe_cast keyword [C++]
ms.assetid: 4fa688bf-a8ec-49bc-a4c5-f48134efa4f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b09bbb831218c073b590233c572d5a5453659ed
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42595326"
---
# <a name="safecast-c-component-extensions"></a>safe_cast (Extensões de Componentes C++)

O **safe_cast** operação retorna a expressão especificada como o tipo especificado, se for bem-sucedido; caso contrário, lança `InvalidCastException`.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

(Não há nenhum comentário sobre este recurso de linguagem que se aplicam a todos os tempos de execução.)

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast<
type-id
>(
expression
)  
```

## <a name="windows-runtime"></a>Tempo de Execução do Windows

**Safe_cast** permite que você altere o tipo de uma expressão especificada. Em situações onde você totalmente espera que uma variável ou parâmetro ser conversível para um determinado tipo, você pode usar **safe_cast** sem uma **try-catch** bloco para detectar erros de programação durante o desenvolvimento. Para obter mais informações, consulte [conversão (C + + c++ /CX)](http://msdn.microsoft.com/library/windows/apps/hh755802.aspx).

### <a name="syntax"></a>Sintaxe

```cpp
[default]:: safe_cast<
type-id
>(
expression
)  
```

### <a name="parameters"></a>Parâmetros

*id do tipo*  
O tipo para converter *expressão* para. Um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência a um tipo de valor ou referência de rastreamento.

*Expressão*  
Uma expressão que é avaliada como um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência a um tipo de valor ou referência de rastreamento.

### <a name="remarks"></a>Comentários

**Safe_cast** lança `InvalidCastException` se não for possível converter *expressão* para o tipo especificado por *id do tipo*. Para capturar `InvalidCastException`, especifique o [/EH (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md) opção do compilador e use um **try/catch** instrução.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

O exemplo de código a seguir demonstra como usar **safe_cast** com o tempo de execução do Windows.

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

**Safe_cast** permite que você altere o tipo de uma expressão e gerar código MSIL verificável.

### <a name="syntax"></a>Sintaxe

```cpp
[cli]:: safe_cast<
type-id
>(
expression
)  
```

### <a name="parameters"></a>Parâmetros

*id do tipo*  
Um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência a um tipo de valor ou referência de rastreamento.

*Expressão*  
Uma expressão que é avaliada como um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência a um tipo de valor ou referência de rastreamento.

### <a name="remarks"></a>Comentários

A expressão `safe_cast<` *id do tipo*`>(`*expressão* `)` converte a expressão de operando em um objeto do tipo do id do tipo.

O compilador aceitará um [static_cast](../cpp/static-cast-operator.md) na maioria dos lugares que ele aceitará um **safe_cast**.  No entanto, **safe_cast** será garantidos para produzir MSIL verificável, where como um **static_cast** poderia produzir MSIL verificável.  Ver [código puro e verificável (C++ c++ CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md) e [Peverify.exe (ferramenta PEVerify)](/dotnet/framework/tools/peverify-exe-peverify-tool) para obter mais informações sobre código verificável.

Como o **static_cast**, **safe_cast** invoca conversões definidas pelo usuário.

Para obter mais informações sobre conversões, consulte [operadores de conversão](../cpp/casting-operators.md).

**Safe_cast** não se aplica uma **const_cast** (eliminar **const**).

**Safe_cast** está no namespace cli.  Ver [plataforma, padrão e cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) para obter mais informações.

Para obter mais informações sobre **safe_cast**, consulte:

- [Conversões C-Style com /clr (C + + / CLI)](../windows/c-style-casts-with-clr-cpp-cli.md)

- [Como usar safe_cast no C++/CLI](../dotnet/how-to-use-safe-cast-in-cpp-cli.md)  

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

Um exemplo de onde o compilador não aceitará um **static_cast** mas aceitará uma **safe_cast** é para conversões entre tipos de interface não relacionadas.  Com o **safe_cast**, o compilador não emitirá um erro de conversão e executará uma verificação em tempo de execução para ver se a conversão é possível

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

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)