---
title: for each, in
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- cliext::foreach
- for
- each
- in
helpviewer_keywords:
- for each keyword [C++]
ms.assetid: 0c3a364b-2747-43f3-bb8d-b7d3b7023f79
ms.openlocfilehash: c5ee72e557c62e3db2eeb5dac4811133719183f6
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57746288"
---
# <a name="for-each-in"></a>for each, in

Itera por meio de uma matriz ou coleção. Essa palavra-chave não padrão está disponível em projetos em C++/CLI e nativos em C++. No entanto, seu uso não é recomendado. Considere o uso de um padrão [de instrução (C++) baseado em intervalo](../cpp/range-based-for-statement-cpp.md) em vez disso.

## <a name="all-runtimes"></a>Todos os Tempos de Execução

### <a name="syntax"></a>Sintaxe

> **para cada (** *tipo* *identificador* **na** *expressão* **) {**<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;*statements*<br/>
> **}**

### <a name="parameters"></a>Parâmetros

*type*<br/>
O tipo de `identifier`.

*identifier*<br/>
A variável de iteração que representa o elemento da coleção.  Quando `identifier` é um [operador de referência de acompanhamento](../windows/tracking-reference-operator-cpp-component-extensions.md), você pode modificar o elemento.

*Expressão*<br/>
Uma expressão ou coleção de matriz. O elemento de coleção deve permitir que o compilador converta-o no tipo `identifier`.

*statements*<br/>
Uma ou mais instruções a serem executadas.

### <a name="remarks"></a>Comentários

A instrução `for each` é usada para iterar por meio de uma coleção. Você pode alterar os elementos em uma coleção, mas não pode adicionar ou excluir elementos.

O *instruções* são executadas para cada elemento da matriz ou coleção. Após a iteração ter sido concluída para todos os elementos na coleção, o controle é transferido para a próxima instrução que segue o bloco `for each`.

`for each` e `in` estão [palavras-chave contextuais](../windows/context-sensitive-keywords-cpp-component-extensions.md).

Para saber mais:

- [Iterando na coleção da biblioteca padrão C++ usando for each](../dotnet/iterating-over-stl-collection-by-using-for-each.md)

- [Como: Iterar em matrizes com for each](../dotnet/how-to-iterate-over-arrays-with-for-each.md)

- [Como: Iterar em uma coleção genérica com for each](../dotnet/how-to-iterate-over-a-generic-collection-with-for-each.md)

- [Como: Iterar em uma coleção definida pelo usuário com for each](../dotnet/how-to-iterate-over-a-user-defined-collection-with-for-each.md)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

### <a name="requirements"></a>Requisitos

Opção do compilador: **/ZW**

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

**Saída**

```Output
abcd

Testing
```

## <a name="common-language-runtime"></a>Common Language Runtime

**Comentários**

A sintaxe CLR é igual a **todos os tempos de execução** sintaxe, exceto pelo seguinte:.

*Expressão*<br/>
Uma expressão de matriz gerenciada ou coleção. O elemento de coleção deve ser, de modo que o compilador poderá convertê-lo partir <xref:System.Object> para o *identificador* tipo.

*expressão* é avaliada como um tipo que implementa <xref:System.Collections.IEnumerable>, <xref:System.Collections.Generic.IEnumerable%601>, ou um tipo que define uma `GetEnumerator` método que retorna um tipo que implementa <xref:System.Collections.IEnumerator> ou declara todos os métodos que são definidos no `IEnumerator`.

### <a name="requirements"></a>Requisitos

Opção de compilador: **/clr**

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

**Saída**

```Output
abcd

Testing
```

## <a name="see-also"></a>Consulte também

[Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)
