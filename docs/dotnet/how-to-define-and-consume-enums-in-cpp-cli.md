---
title: Como definir e consumir enumerações em C++/CLI
ms.date: 11/04/2016
helpviewer_keywords:
- enum class, specifying underlying types
ms.assetid: df8f2b91-b9d2-4fab-9be4-b1d58b8bc570
ms.openlocfilehash: cf3bb23069b2692c0ca4ce270a5b8060195becf7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370170"
---
# <a name="how-to-define-and-consume-enums-in-ccli"></a>Como definir e consumir enumerações em C++/CLI

Este tópico discute enums em C++/CLI.

## <a name="specifying-the-underlying-type-of-an-enum"></a>Especificando o tipo subjacente de um enum

Por padrão, o tipo subjacente de `int`uma enumeração é .  No entanto, você pode especificar o `int`tipo `short` `long`a `__int32`ser `__int64`assinado ou formas não assinadas de , , , ou .  Também é possível usar `char`.

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

Não há conversão padrão entre um enum e um tipo integral; um gesso é necessário.

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

## <a name="operators-and-enums"></a>Operadores e enums

Os seguintes operadores são válidos em enums em C++/CLI:

|Operador|
|--------------|
|== == == \<  >  \<>=|
|+ -|
|&#124; ^ & ~|
|++ --|
|sizeof|

Os operadores &#124; ^ & ~ ++ - são definidos apenas para enumerações com tipos subjacentes integrais, sem incluir bool.  Ambos os operands devem ser do tipo de enumeração.

O compilador não faz verificação estática ou dinâmica do resultado de uma operação de enum; uma operação pode resultar em um valor que não esteja na faixa dos enumeradores válidos do enum.

> [!NOTE]
> C++11 introduz tipos de classe enum em código não gerenciado que são significativamente diferentes das classes de enum gerenciadas em C++/CLI. Em particular, o tipo de classe enum C++11 não suporta os mesmos operadores do tipo de classe enum gerenciado em C++/CLI, e o código fonte C++/CLI deve fornecer um especificador de acessibilidade em declarações de classe enum gerenciadas, a fim de distingui-las das declarações de classe enum não gerenciadas (C++11). Para obter mais informações sobre as classes enum em C++/CLI, C++/CX e C++11, consulte [enum class](../extensions/enum-class-cpp-component-extensions.md).

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

[enum class](../extensions/enum-class-cpp-component-extensions.md)
