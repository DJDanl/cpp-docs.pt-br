---
title: 'Como: definir e consumir enumerações no C++/CLI'
ms.date: 11/04/2016
helpviewer_keywords:
- enum class, specifying underlying types
ms.assetid: df8f2b91-b9d2-4fab-9be4-b1d58b8bc570
ms.openlocfilehash: f09bb6e9fac30b72c3c4e0682c3d90f2ea9f8760
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216408"
---
# <a name="how-to-define-and-consume-enums-in-ccli"></a>Como: definir e consumir enumerações no C++/CLI

Este tópico discute enums em C++/CLI.

## <a name="specifying-the-underlying-type-of-an-enum"></a>Especificando o tipo subjacente de uma enumeração

Por padrão, o tipo subjacente de uma enumeração é **`int`** .  No entanto, você pode especificar o tipo a ser assinado ou não assinado para formulários **`int`** , **`short`** , **`long`** , **`__int32`** ou **`__int64`** .  Você também pode usar o **`char`** .

```cpp
// mcppv2_enum_3.cpp
// compile with: /clr
public enum class day_char : char {sun, mon, tue, wed, thu, fri, sat};

int main() {
   // fully qualified names, enumerator not injected into scope
   day_char d = day_char::sun, e = day_char::mon;
   System::Console::WriteLine(d);
   char f = (char)d;
   System::Console::WriteLine(f);
   f = (char)e;
   System::Console::WriteLine(f);
   e = day_char::tue;
   f = (char)e;
   System::Console::WriteLine(f);
}
```

**Saída**

```Output
sun
0
1
2
```

## <a name="how-to-convert-between-managed-and-standard-enumerations"></a>Como converter entre enumerações gerenciadas e padrão

Não há conversão padrão entre uma enumeração e um tipo integral; uma conversão é necessária.

```cpp
// mcppv2_enum_4.cpp
// compile with: /clr
enum class day {sun, mon, tue, wed, thu, fri, sat};
enum {sun, mon, tue, wed, thu, fri, sat} day2; // unnamed std enum

int main() {
   day a = day::sun;
   day2 = sun;
   if ((int)a == day2)
   // or...
   // if (a == (day)day2)
      System::Console::WriteLine("a and day2 are the same");
   else
      System::Console::WriteLine("a and day2 are not the same");
}
```

**Saída**

```Output
a and day2 are the same
```

## <a name="operators-and-enums"></a>Operadores e enumerações

Os seguintes operadores são válidos em enums em C++/CLI:

|Operador|
|--------------|
|== != \< >\<= >=|
|+ -|
|&#124; ^ & ~|
|++ --|
|sizeof|

Operadores &#124; ^ & ~ + +--são definidos somente para enumerações com tipos subjacentes inteiros, não incluindo bool.  Ambos os operandos devem ser do tipo de enumeração.

O compilador não faz nenhuma verificação estática ou dinâmica do resultado de uma operação de enumeração; uma operação pode resultar em um valor que não está no intervalo dos enumeradores válidos do enum.

> [!NOTE]
> O C++ 11 introduz tipos de classe de enumeração em código não gerenciado, que são significativamente diferentes das classes de enumeração gerenciadas em C++/CLI. Em particular, o tipo de classe de enumeração C++ 11 não oferece suporte aos mesmos operadores que o tipo de classe enum gerenciado em C++/CLI, e o código-fonte C++/CLI deve fornecer um especificador de acessibilidade em declarações de classe de enumeração gerenciadas para diferenciá-las de declarações de classe enum não gerenciadas (C++ 11). Para obter mais informações sobre classes de enumeração em C++/CLI, C++/CX e C++ 11, consulte [classe de enumeração](../extensions/enum-class-cpp-component-extensions.md).

```cpp
// mcppv2_enum_5.cpp
// compile with: /clr
private enum class E { a, b } e, mask;
int main() {
   if ( e & mask )   // C2451 no E->bool conversion
      ;

   if ( ( e & mask ) != 0 )   // C3063 no operator!= (E, int)
      ;

   if ( ( e & mask ) != E() )   // OK
      ;
}
```

```cpp
// mcppv2_enum_6.cpp
// compile with: /clr
private enum class day : int {sun, mon};
enum : bool {sun = true, mon = false} day2;

int main() {
   day a = day::sun, b = day::mon;
   day2 = sun;

   System::Console::WriteLine(sizeof(a));
   System::Console::WriteLine(sizeof(day2));
   a++;
   System::Console::WriteLine(a == b);
}
```

**Saída**

```Output
4
1
True
```

## <a name="see-also"></a>Confira também

[Classe enum](../extensions/enum-class-cpp-component-extensions.md)
