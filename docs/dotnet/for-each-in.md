---
title: for each, in
description: C++/CLI para cada, na descrição e nos exemplos da instrução.
ms.date: 09/25/2020
ms.topic: reference
f1_keywords:
- cliext::foreach
- for
- each
- in
helpviewer_keywords:
- for each keyword [C++]
ms.assetid: 0c3a364b-2747-43f3-bb8d-b7d3b7023f79
ms.openlocfilehash: 7f228a773dfcbe791e26ea3e1bd8cfba7f3ab028
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91413913"
---
# <a name="for-each-in"></a>for each, in

Itera por meio de uma matriz ou coleção. Essa palavra-chave não padrão está disponível em projetos em C++/CLI e nativos em C++. No entanto, seu uso não é recomendado. Considere o uso de um [C++ (baseado em intervalo para instrução)](../cpp/range-based-for-statement-cpp.md) padrão.

## <a name="all-runtimes"></a>Todos os Runtimes

### <a name="syntax"></a>Syntax

> **para cada (** *type* *identificador* **de tipo na** *expressão* **) {**\
> &nbsp;&nbsp;&nbsp;&nbsp;*instruções*\
> **}**

### <a name="parameters"></a>Parâmetros

*tipo*<br/>
O tipo de `identifier`.

*ID*<br/>
A variável de iteração que representa o elemento da coleção.  Quando `identifier` é um [operador de referência de rastreamento](../extensions/tracking-reference-operator-cpp-component-extensions.md), você pode modificar o elemento.

*expressão*<br/>
Uma expressão ou coleção de matriz. O elemento de coleção deve permitir que o compilador converta-o no tipo `identifier`.

*instruções*<br/>
Uma ou mais instruções a serem executadas.

### <a name="remarks"></a>Comentários

A instrução `for each` é usada para iterar por meio de uma coleção. Você pode modificar elementos em uma coleção, mas não pode adicionar ou excluir elementos.

As *instruções* são executadas para cada elemento na matriz ou coleção. Após a iteração ter sido concluída para todos os elementos na coleção, o controle é transferido para a próxima instrução que segue o bloco `for each`.

`for each` e `in` são [palavras-chave sensíveis ao contexto](../extensions/context-sensitive-keywords-cpp-component-extensions.md).

## <a name="windows-runtime"></a>Windows Runtime

### <a name="requirements"></a>Requisitos

Opção do compilador: **/zw**

### <a name="example"></a>Exemplo

Este exemplo mostra como usar `for each` para iterar por meio de uma cadeia de caracteres.

```cpp
// for_each_string1.cpp
// compile with: /ZW
#include <stdio.h>
using namespace Platform;

ref struct MyClass {
   property String^ MyStringProperty;
};

int main() {
   String^ MyString = ref new String("abcd");

   for each ( char c in MyString )
      wprintf("%c", c);

   wprintf("/n");

   MyClass^ x = ref new MyClass();
   x->MyStringProperty = "Testing";

   for each( char c in x->MyStringProperty )
      wprintf("%c", c);
}
```

```Output
abcd

Testing
```

## <a name="common-language-runtime"></a>Common Language Runtime

### <a name="remarks"></a>Comentários

A sintaxe do CLR é igual à sintaxe de **todos os tempos de execução** , exceto da seguinte maneira.

*expressão*<br/>
Uma expressão de matriz gerenciada ou coleção. O elemento de coleção deve ser de modo que o compilador possa convertê-lo de <xref:System.Object> para o tipo de *identificador* .

a *expressão* é avaliada como um tipo que implementa <xref:System.Collections.IEnumerable> , <xref:System.Collections.Generic.IEnumerable%601> ou um tipo que define um `GetEnumerator` método que retorna um tipo que implementa <xref:System.Collections.IEnumerator> ou declara todos os métodos definidos no `IEnumerator` .

### <a name="requirements"></a>Requisitos

Opção do compilador: **/clr**

### <a name="example"></a>Exemplo

Este exemplo mostra como usar `for each` para iterar por meio de uma cadeia de caracteres.

```cpp
// for_each_string2.cpp
// compile with: /clr
using namespace System;

ref struct MyClass {
   property String ^ MyStringProperty;
};

int main() {
   String ^ MyString = gcnew String("abcd");

   for each ( Char c in MyString )
      Console::Write(c);

   Console::WriteLine();

   MyClass ^ x = gcnew MyClass();
   x->MyStringProperty = "Testing";

   for each( Char c in x->MyStringProperty )
      Console::Write(c);
}
```

```Output
abcd

Testing
```

## <a name="see-also"></a>Confira também

[Extensões de componente para plataformas de tempo de execução](../extensions/component-extensions-for-runtime-platforms.md)\
[Instrução for com base em intervalo (C++)](../cpp/range-based-for-statement-cpp.md)
