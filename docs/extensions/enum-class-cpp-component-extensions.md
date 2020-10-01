---
title: enum class  (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
ms.assetid: 8010fa8c-bad6-45b4-8214-b4db64d7ffe1
ms.openlocfilehash: 9acf93976b2f7751e85bf3ed0ddd2735c29e121c
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590310"
---
# <a name="enum-class--ccli-and-ccx"></a>enum class  (C++/CLI e C++/CX)

Declara uma enumeração no escopo do namespace, que é um tipo definido pelo usuário que consiste em um conjunto de constantes nomeadas chamadas de enumeradores.

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="remarks"></a>Comentários

C++/CX e C++/CLI são compatíveis com a **public enum class** e à **private enum class** que são semelhantes ao padrão C++ **enum class**, mas com a adição do especificador de acessibilidade. No **/clr**, o tipo **enum class** C++11 é permitido, mas vai gerar o aviso C4472, que se destina a garantir que você realmente deseja o tipo enum ISO e não o tipo C++/CX e C++/CLI. Para obter mais informações sobre a **`enum`** palavra-chave ISO Standard C++, consulte [enumerações](../cpp/enumerations-cpp.md).

## <a name="windows-runtime"></a>Windows Runtime

### <a name="syntax"></a>Sintaxe

```cpp
      access
      enum class
      enumeration-identifier
      [:underlying-type] { enumerator-list } [var];
accessenum structenumeration-identifier[:underlying-type] { enumerator-list } [var];
```

### <a name="parameters"></a>Parâmetros

*às*<br/>
A acessibilidade da enumeração, que pode ser **`public`** ou **`private`** .

*enumeration-identifier*<br/>
O nome da enumeração.

*tipo subjacente*<br/>
(Opcional) O tipo subjacente da enumeração.

(Opcional). Somente Windows Runtime) o tipo subjacente da enumeração, que pode ser,,,,,,, **`bool`** **`char`** `char16` `int16` `uint16` **`int`** `uint32` `int64` ou `uint64` .

*enumerador-lista*<br/>
Uma lista de nomes de enumeradores delimitada por vírgulas.

O valor de cada enumerador é uma expressão constante que é definida implicitamente pelo compilador ou explicitamente pela *enumerator* `=` *expressão constante*Notation, enumerador. Por padrão, o valor do primeiro enumerador é zero se estiver implicitamente definido. O valor de cada enumerador implicitamente definido subsequente é o valor do enumerador anterior + 1.

*var*<br/>
(Opcional) O nome de uma variável do tipo de enumeração.

### <a name="remarks"></a>Comentários

Saiba mais e obtenha exemplos em [Enumerações](../cppcx/enums-c-cx.md).

Observe que o compilador emite mensagens de erro se a expressão constante que define o valor de um enumerador não puder ser representada por *underlying-type*.  No entanto, o compilador não relata um erro para um valor que é inadequado para o tipo subjacente. Por exemplo:

- Se o *tipo subjacente* for numérico e um enumerador especificar o valor máximo para esse tipo, o valor da próxima Enumeração definida implicitamente não poderá ser representado.

- Se o *tipo subjacente* for **`bool`** e mais de dois enumeradores forem definidos implicitamente, os enumeradores após os dois primeiros não poderão ser representados.

- Se *underlying-type* for `char16`, e o valor de enumeração variar de 0xD800 a 0xDFFF, o valor poderá ser representado. No entanto, o valor estará logicamente incorreto, pois representa metade de um par alternativo Unicode e não deve aparecer no isolamento.

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="syntax"></a>Sintaxe

```cpp
      access
      enum class
      name [:type] { enumerator-list } var;
accessenum structname [:type] { enumerator-list } var;
```

### <a name="parameters"></a>Parâmetros

*às*<br/>
A acessibilidade do enum. Pode ser **`public`** ou **`private`** .

*enumerador-lista*<br/>
Uma lista delimitada por vírgulas dos identificadores (enumeradores) na enumeração.

*name*<br/>
O nome da enumeração. Enumerações gerenciadas anônimas não são permitidas.

*tipo*<br/>
(Opcional) O tipo subjacente dos *identifiers*. Pode ser qualquer tipo escalar, como versões assinadas ou não, **`int`** **`short`** ou **`long`** .  **`bool`** ou **`char`** também é permitido.

*var*<br/>
(Opcional) O nome de uma variável do tipo de enumeração.

### <a name="remarks"></a>Comentários

**enum class** e **enum struct** são declarações equivalentes.

Existem dois tipos de enumerações: gerenciada ou C++/CX e standard.

Uma enumeração gerenciada ou C++/CX pode ser definida da seguinte maneira,

```cpp
public enum class day {sun, mon };
```

e é semanticamente equivalente a:

```cpp
ref class day {
public:
   static const int sun = 0;
   static const int mon = 1;
};
```

Uma enumeração padrão pode ser definida da seguinte maneira:

```cpp
enum day2 { sun, mon };
```

e é semanticamente equivalente a:

```cpp
static const int sun = 0;
static const int mon = 1;
```

Nomes de enumeradores gerenciados (*identifiers*) não são injetados no escopo em que a enumeração está definida; todas as referências aos enumeradores devem ser totalmente qualificadas (*name*`::`*identifier*).  Por essa razão, não é possível definir uma enumeração gerenciada anônima.

Os enumeradores de uma enumeração padrão são fortemente injetados no escopo de inclusão.  Ou seja, se há outro símbolo com o mesmo nome que um enumerador no escopo delimitador, o compilador gera um erro.

No Visual Studio 2002 e Visual Studio 2003, os enumeradores foram injetados fracamente (visíveis no escopo delimitador, a menos que houvesse outro identificador com o mesmo nome).

Se um enum C++ padrão for definido (sem **`class`** ou **`struct`** ), compilar com `/clr` fará com que a enumeração seja compilada como uma enumeração gerenciada.  A enumeração ainda tem a semântica de uma enumeração não gerenciada.  Note que o compilador injeta um atributo `Microsoft::VisualC::NativeEnumAttribute` para identificar a intenção de um programador de que a enumeração seja uma enumeração nativa.  Outros compiladores simplesmente veem a enumeração padrão como uma enumeração gerenciada.

Uma enumeração padrão nomeada compilada com `/clr` fica visível no assembly como uma enumeração gerenciada e pode ser consumida por qualquer outro compilador gerenciado.   No entanto, uma enumeração padrão sem nome não fica visível publicamente a partir do assembly.

No Visual Studio 2002 e Visual Studio 2003, uma enumeração padrão usada como o tipo em um parâmetro de função:

```cpp
// mcppv2_enum.cpp
// compile with: /clr
enum E { a, b };
void f(E) {System::Console::WriteLine("hi");}

int main() {
   E myi = b;
   f(myi);
}
```

emitiria o seguinte no MSIL para a assinatura da função:

```cpp
void f(int32);
```

No entanto, nas versões atuais do compilador, a enumeração padrão é emitida como uma enumeração gerenciada com um [NativeEnumAttribute] e o seguinte no MSIL para a assinatura da função:

```cpp
void f(E)
```

Saiba mais sobre enumerações nativas em [Declarações de enumeração do C++](../cpp/enumerations-cpp.md).

Saiba mais sobre enumerações do CLR em:

- [Tipo subjacente de uma enumeração](../dotnet/how-to-define-and-consume-enums-in-cpp-cli.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

```cpp
// mcppv2_enum_2.cpp
// compile with: /clr
// managed enum
public enum class m { a, b };

// standard enum
public enum n { c, d };

// unnamed, standard enum
public enum { e, f } o;

int main()
{
   // consume managed enum
   m mym = m::b;
   System::Console::WriteLine("no automatic conversion to int: {0}", mym);
   System::Console::WriteLine("convert to int: {0}", (int)mym);

   // consume standard enum
   n myn = d;
   System::Console::WriteLine(myn);

   // consume standard, unnamed enum
   o = f;
   System::Console::WriteLine(o);
}
```

```Output
no automatic conversion to int: b

convert to int: 1

1

1
```

## <a name="see-also"></a>Confira também

[Extensões de componente para .NET e UWP](component-extensions-for-runtime-platforms.md)
