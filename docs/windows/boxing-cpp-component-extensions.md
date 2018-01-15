---
title: "Conversão boxing (extensões de componentes C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords: boxing, Visual C++
ms.assetid: b5fd2c98-c578-4f83-8257-6dd663478665
caps.latest.revision: "27"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 15fa5471280935c54cdb936af378634e2b60cacd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="boxing--c-component-extensions"></a>Conversão boxing (Extensões de Componentes C++)
O compilador do Visual C++ pode converter tipos de valor em objetos em um processo chamado *boxing*e converter objetos em tipos de valor em um processo chamado *unboxing*.  
  
## <a name="all-runtimes"></a>Todos os Tempos de Execução  
 (Não há nenhum comentários para esse recurso de idioma que se aplicam a todos os tempos de execução).  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 C + + CX dá suporte a uma sintaxe abreviada para tipos de valor de boxing e unboxing tipos de referência. Um tipo de valor é convertido quando ele é atribuído a uma variável do tipo `Object`. Um `Object` variável estiver não demarcado quando ele é atribuído a uma variável de tipo de valor e o tipo não demarcado é especificado em parênteses; ou seja, quando a variável de objeto é convertida em um tipo de valor.  
  
```  
  
  Platform::Object^  
  object_variable  = value_variable;  
value_variable = (value_type) object_variable;  
  
```  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
### <a name="examples"></a>Exemplos  
 O seguinte código caixas de exemplo e unboxes um `DateTime` valor. Primeiro, o exemplo obtém um valor DateTime que representa a data e hora atuais e o atribui a uma variável de data e hora. Em seguida, a data e hora é demarcada atribuindo-a uma variável de objeto. Por fim, o valor demarcado é desencaixotado atribuindo a ele a outra variável de data e hora.  
  
 Para testar o exemplo, crie um projeto BlankApplication, substitua o método BlankPage::OnNavigatedTo() e, em seguida, especifique os pontos de interrupção no colchete de fechamento e a atribuição à variável str1. Quando o exemplo atinge o colchete de fechamento, examine str1.  
  
```  
  
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
  
 Para obter mais informações, consulte [conversão Boxing (C + + CX)](http://msdn.microsoft.com/library/windows/apps/hh969554.aspx).  
  
## <a name="common-language-runtime"></a>Common Language Runtime  
 O compilador do Visual C++ agora caixas valor tipos para <xref:System.Object>.  Isso é possível devido a uma conversão definida pelo compilador para converter tipos de valores <xref:System.Object>.  
  
 Conversões boxing e unboxing habilitar tipos de valor a serem tratados como objetos. Tipos de valor, incluindo tipos de estrutura e os tipos internos, como int, podem ser convertidos para e do tipo <xref:System.Object>.  
  
 Para obter mais informações, consulte:  
  
-   [Como solicitar uma conversão boxing explicitamente](../dotnet/how-to-explicitly-request-boxing.md)  
  
-   [Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)  
  
-   [Como reverter uma conversão boxing](../dotnet/how-to-unbox.md)  
  
-   [Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 A exemplo a seguir mostra como implícita de conversão boxing funciona.  
  
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
  
 **Saída**  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)