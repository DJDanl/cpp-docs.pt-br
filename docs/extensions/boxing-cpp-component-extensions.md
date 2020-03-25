---
title: Conversão boxing (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- boxing, C++
ms.assetid: b5fd2c98-c578-4f83-8257-6dd663478665
ms.openlocfilehash: 709754e8609406f635444937af93488060167ba9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80172601"
---
# <a name="boxing--ccli-and-ccx"></a>Conversão boxing (C++/CLI e C++/CX)

A conversão de tipos de valor em objetos é chamada de *boxing*, e a conversão de objetos em tipos de valor é chamada de *unboxing*.

## <a name="all-runtimes"></a>Todos os Runtimes

(Não há comentários para esse recurso de linguagem que se apliquem a todos os runtimes.)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

C++/CX é compatível com uma sintaxe abreviada para tipos de valor boxing e tipos de referência unboxing. Um tipo de valor é convertido quando é atribuído a uma variável do tipo `Object`. Uma variável `Object` ​​é desconvertida quando é atribuída a uma variável de tipo de valor e o tipo não convertido é especificado entre parênteses; isto é, quando a variável de objeto é convertida em um tipo de valor.

```cpp
  Platform::Object^
  object_variable  = value_variable;
value_variable = (value_type) object_variable;
```

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

As caixas de exemplo de código a seguir fazem e desfazem a conversão de um valor `DateTime`. Primeiro, o exemplo obtém um valor `DateTime` que representa a data e a hora atuais e atribui a uma variável `DateTime`. Em seguida, `DateTime` é convertido atribuindo-o a uma variável `Object`. Finalmente, o valor convertido é desconvertido, atribuindo-o a outra variável `DateTime`.

Para testar o exemplo, crie um projeto `BlankApplication`, substitua o método `BlankPage::OnNavigatedTo()` e especifique os pontos de interrupção no colchete de fechamento e na atribuição para a variável `str1`. Quando o exemplo atingir o colchete de fechamento, examine `str1`.

```cpp
void BlankPage::OnNavigatedTo(NavigationEventArgs^ e)
{
    using namespace Windows::Globalization::DateTimeFormatting;

    Windows::Foundation::DateTime dt, dtAnother;
    Platform::Object^ obj1;

    Windows::Globalization::Calendar^ c =
        ref new Windows::Globalization::Calendar;
    c->SetToNow();
    dt = c->GetDateTime();
    auto dtf = ref new DateTimeFormatter(
                           YearFormat::Full,
                           MonthFormat::Numeric,
                           DayFormat::Default,
                           DayOfWeekFormat::None);
    String^ str1 = dtf->Format(dt);
    OutputDebugString(str1->Data());
    OutputDebugString(L"\r\n");

    // Box the value type and assign to a reference type.
    obj1 = dt;
    // Unbox the reference type and assign to a value type.
    dtAnother = (Windows::Foundation::DateTime) obj1;

    // Format the DateTime for display.
    String^ str2 = dtf->Format(dtAnother);
    OutputDebugString(str2->Data());
}
```

Saiba mais em [Conversão boxing (C++/CX)](../cppcx/boxing-c-cx.md).

## <a name="common-language-runtime"></a>Common Language Runtime

O compilador converte tipos de valor para <xref:System.Object>. Isso é possível devido a uma conversão definida pelo compilador para converter tipos de valor em <xref:System.Object>.

Operações de boxing e unboxing permitem que tipos de valor sejam tratados como objetos. Tipos de valor, incluindo tipos struct e tipos internos, como int, podem ser convertidos para e do tipo <xref:System.Object>.

Para obter mais informações, consulte:

- [Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)

- [Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)

- [Como reverter uma conversão boxing](../dotnet/how-to-unbox.md)

- [Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

A amostra a seguir mostra como funciona a conversão boxing.

```cpp
// vcmcppv2_explicit_boxing2.cpp
// compile with: /clr
using namespace System;

ref class A {
public:
   void func(System::Object^ o){Console::WriteLine("in A");}
};

value class V {};

interface struct IFace {
   void func();
};

value class V1 : public IFace {
public:
   virtual void func() {
      Console::WriteLine("Interface function");
   }
};

value struct V2 {
   // conversion operator to System::Object
   static operator System::Object^(V2 v2) {
      Console::WriteLine("operator System::Object^");
      return (V2^)v2;
   }
};

void func1(System::Object^){Console::WriteLine("in void func1(System::Object^)");}
void func1(V2^){Console::WriteLine("in func1(V2^)");}

void func2(System::ValueType^){Console::WriteLine("in func2(System::ValueType^)");}
void func2(System::Object^){Console::WriteLine("in func2(System::Object^)");}

int main() {
   // example 1 simple implicit boxing
   Int32^ bi = 1;
   Console::WriteLine(bi);

   // example 2 calling a member with implicit boxing
   Int32 n = 10;
   Console::WriteLine("xx = {0}", n.ToString());

   // example 3 implicit boxing for function calls
   A^ a = gcnew A;
   a->func(n);

   // example 4 implicit boxing for WriteLine function call
   V v;
   Console::WriteLine("Class {0} passed using implicit boxing", v);
   Console::WriteLine("Class {0} passed with forced boxing", (V^)(v));   // force boxing

   // example 5 casting to a base with implicit boxing
   V1 v1;
   IFace ^ iface = v1;
   iface->func();

   // example 6 user-defined conversion preferred over implicit boxing for function-call parameter matching
   V2 v2;
   func1(v2);   // user defined conversion from V2 to System::Object preferred over implicit boxing
                // Will call void func1(System::Object^);

   func2(v2);   // OK: Calls "static V2::operator System::Object^(V2 v2)"
   func2((V2^)v2);   // Using explicit boxing: calls func2(System::ValueType^)
}
```

```Output
1

xx = 10

in A

Class V passed using implicit boxing

Class V passed with forced boxing

Interface function

in func1(V2^)

in func2(System::ValueType^)

in func2(System::ValueType^)
```

## <a name="see-also"></a>Confira também

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)
