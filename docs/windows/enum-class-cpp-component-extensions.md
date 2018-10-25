---
title: classe Enum (C + + c++ /CLI e c++ /CLI CX) | Microsoft Docs
ms.custom: ''
ms.date: 10/12/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 8010fa8c-bad6-45b4-8214-b4db64d7ffe1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 7c63a043b8f1a91654c0b765632969b82725a3c0
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066156"
---
# <a name="enum-class--ccli-and-ccx"></a>classe Enum (C + + c++ /CLI e c++ /CLI CX)

Declara uma enumeração no escopo do namespace, que é um tipo definido pelo usuário que consiste em um conjunto de constantes nomeadas chamadas enumeradores.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="remarks"></a>Comentários

C + + c++ /CLI CX e C + + c++ /CLI suporte da CLI **classe enum pública** e **classe enum privada** que são semelhante do C++ padrão **classe enum** , mas com a adição de acessibilidade especificador. Sob **/clr**, o c++11 **classe enum** tipo é permitido, mas irá gerar um aviso C4472 que tem como objetivo garantir que você realmente deseja o tipo de enumeração do ISO e não a C + + c++ /CLI CX e C + + c++ /CLI tipo CLI. Para obter mais informações sobre o C++ padrão ISO **enum** palavra-chave, consulte [enumerações](../cpp/enumerations-cpp.md).

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="syntax"></a>Sintaxe

```cpp
      access
      enum class
      enumeration-identifier
      [:underlying-type] { enumerator-list } [var];
accessenum structenumeration-identifier[:underlying-type] { enumerator-list } [var];
```

### <a name="parameters"></a>Parâmetros

*access*<br/>
A acessibilidade de enumeração, que pode ser **pública** ou **privada**.

*Identificador de enumeração*<br/>
O nome da enumeração.

*tipo de base*<br/>
(Opcional) O tipo subjacente da enumeração.

(Opcional. Runtime do Windows somente) o tipo subjacente da enumeração, que pode ser **bool**, **char**, `char16`, `int16`, `uint16`, **int**, `uint32`, `int64`, ou `uint64`.

*lista de enumerador*<br/>
Uma lista delimitada por vírgulas de nomes de enumeradores.

O valor de cada enumerador é uma expressão de constante ou é definida implicitamente pelo compilador, ou explicitamente a notação *enumerador*`=`*expressão constante*. Por padrão, o valor do primeiro enumerador é zero, se ele é definido implicitamente. O valor de cada enumerador subsequente de implicitamente definido é o valor do enumerador anterior + 1.

*var*<br/>
(Opcional) O nome de uma variável do tipo de enumeração.

### <a name="remarks"></a>Comentários

Para obter mais informações e exemplos, consulte [Enums](https://msdn.microsoft.com/%20library/windows/apps/hh755820.aspx).

Observe que o compilador emite mensagens de erro se a expressão de constante que define o valor de um enumerador não pode ser representada pelo *tipo subjacente*.  No entanto, o compilador não relatará um erro para um valor que não é apropriado para o tipo subjacente. Por exemplo:

- Se *tipo subjacente* for numérico e um enumerador Especifica o valor máximo para esse tipo, o valor da próxima enumeratoin implicitamente definido não pode ser representado.

- Se *tipo subjacente* é **bool**, e mais de dois enumeradores são implicitamente definida, os enumeradores depois que as duas primeiras não podem ser representadas.

- Se *tipo subjacente* é `char16`e o valor de enumeração varia de 0xD800 0xDFFF, o valor pode ser representado. No entanto, o valor logicamente incorreto porque ele representa metade um Unicode de pares substitutos e não devem aparecer em isolamento.

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

*access*<br/>
A acessibilidade do enum. Pode ser **pública** ou **privada**.

*lista de enumerador*<br/>
Uma lista separada por vírgula dos identificadores (enumeradores) na enumeração.

*name*<br/>
O nome da enumeração. Enumerações gerenciadas anônimas não são permitidas.

*type*<br/>
(Opcional) O tipo subjacente dos *identificadores*. Isso pode ser qualquer tipo escalar, como as versões com ou sem sinal de **int**, **curto**, ou **longo**.  **bool** ou **char** também é permitido.

*var*<br/>
(Opcional) O nome de uma variável do tipo de enumeração.

### <a name="remarks"></a>Comentários

**classe Enum** e **enum struct** são declarações equivalentes.

Há dois tipos de enums: gerenciado ou C + + c++ /CLI CX e standard.

Gerenciada ou C + + c++ enum CX pode ser definido da seguinte maneira

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

Um enum padrão pode ser definido da seguinte maneira:

```cpp
enum day2 { sun, mon };
```

e é semanticamente equivalente a:

```cpp
static const int sun = 0;
static const int mon = 1;
```

Nomes de enumerador gerenciados (*identificadores*) não são injetados no escopo em que a enumeração for definida; todas as referências para os enumeradores devem ser totalmente qualificadas (*nome* `::` *identificador*).  Por esse motivo, você não pode definir um enum gerenciado anônimo.

Os enumeradores de um enum padrão fortemente são injetados no escopo delimitador.  Ou seja, se houver outro símbolo com o mesmo nome de um enumerador no escopo delimitador, o compilador gerará um erro.

No Visual Studio 2002 e Visual Studio 2003, enumeradores fraca foram inseridos (visível no escopo delimitador, a menos que não havia outro identificador com o mesmo nome).

Se um enum C++ padrão é definido (sem **classe** ou **struct**), compilando com `/clr` fará com que a enumeração a ser compilado como um enum gerenciado.  A enumeração ainda tem a semântica de uma enumeração não gerenciada.  Observe que o compilador injeta um atributo `Microsoft::VisualC::NativeEnumAttribute` para identificar a intenção do programador para o enum ser um enum nativo.  Outros compiladores simplesmente verá o enum padrão como um enum gerenciado.

A chamada, enum padrão compilado com `/clr` ficarão visíveis no assembly como um enum gerenciado e podem ser consumidos por qualquer outro compilador gerenciado.   No entanto, um enum padrão sem nome não será visível publicamente do assembly.

No Visual Studio 2002 e Visual Studio 2003, um enum padrão usado como o tipo em um parâmetro de função:

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

seria emitir o seguinte no MSIL para a assinatura de função:

```cpp
void f(int32);
```

No entanto, nas versões atuais do compilador, o padrão enum é emitido como um enum gerenciado com um [NativeEnumAttribute] e o seguinte no MSIL para a assinatura de função:

```cpp
void f(E)
```

Para obter mais informações sobre enums nativas, consulte [declarações de enumeração C++](../cpp/enumerations-cpp.md).

Para obter mais informações sobre enums CLR, consulte:

- [Tipo subjacente de um Enum](../dotnet/how-to-define-and-consume-enums-in-cpp-cli.md)

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

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)