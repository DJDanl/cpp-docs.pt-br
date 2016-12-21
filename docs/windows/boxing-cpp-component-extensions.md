---
title: "Boxing  (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "boxing, Visual C++"
ms.assetid: b5fd2c98-c578-4f83-8257-6dd663478665
caps.latest.revision: 27
caps.handback.revision: 25
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Boxing  (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O compilador do Visual C\+\+ pode converter tipos de valor em objetos em um processo chamado *conversão boxing*, e converter objetos em tipos de valor em um processo chamado *unboxing*.  
  
## Todos os Tempos de Execução  
 \(Não há nenhum comentários para esse recurso de linguagem que se aplicam a todos os tempos de execução.\)  
  
## Tempo de Execução do Windows  
 [!INCLUDE[cppwrt_short](../Token/cppwrt_short_md.md)] oferece suporte a uma sintaxe abreviada para tipos de valor de conversão boxing e unboxing tipos de referência.  Um tipo de valor é convertido quando ele é atribuído a uma variável do tipo `Object`.  Um `Object` variável é não demarcado quando ele é atribuído a uma variável de tipo de valor e o tipo não demarcado é especificado entre parênteses; ou seja, quando a variável de objeto é convertida em um tipo de valor.  
  
```  
  
Platform::Object^ object_variable  = value_variable;  
value_variable = (value_type) object_variable;  
  
```  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
### Exemplos  
 O seguinte código caixas de exemplo e unboxes um `DateTime` valor.  Primeiro, o exemplo obtém um valor de data e hora que representa a data e hora atuais e o atribui a uma variável DateTime.  Em seguida, a data e hora é convertida, atribuindo a ela uma variável de objeto.  Por fim, o valor demarcado é convertido, atribuindo a ela a outra variável DateTime.  
  
 Para testar o exemplo, crie um projeto BlankApplication, substitua o método BlankPage::OnNavigatedTo\(\) e, em seguida, especifique os pontos de interrupção no colchete de fechamento e a atribuição à variável str1.  Quando o exemplo alcança o colchete de fechamento, examine str1.  
  
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
  
 Para obter mais informações, consulte [conversão Boxing \(C\+\+ c\+\+ \/CX\)](http://msdn.microsoft.com/library/windows/apps/hh969554.aspx).  
  
## Common Language Runtime  
 O compilador do Visual C\+\+ agora caixas valor tipos para <xref:System.Object>.  Isso é possível por causa de uma conversão definida pelo compilador para converter tipos de valores <xref:System.Object>.  
  
 Conversões boxing e unboxing habilitar tipos de valor a serem tratados como objetos.  Tipos de valor, incluindo tipos de estrutura e os tipos internos como int, podem ser convertidos para e do tipo <xref:System.Object>.  
  
 Para obter mais informações, consulte:  
  
-   [Como fazer uma conversão boxing de solicitação explícita](../Topic/How%20to:%20Explicitly%20Request%20Boxing.md)  
  
-   [Como usar gcnew para criar tipos de valor e usar conversão boxing implícita](../dotnet/how-to-use-gcnew-to-create-value-types-and-use-implicit-boxing.md)  
  
-   [Como converter](../dotnet/how-to-unbox.md)  
  
-   [Conversões padrão e conversão boxing implícita](../dotnet/standard-conversions-and-implicit-boxing.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 A exemplo a seguir mostra como implícitas boxing funciona.  
  
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
  
  **1**  
 **xx \= 10**  
 **em um**  
 **Classe V passado usando conversão boxing implícita**  
 **Classe V passados com conversão boxing forçada**  
 **Funções de interface**  
 **em func1\(V2^\)**  
 **em func2\(System::ValueType^\)**  
 **em func2\(System::ValueType^\)**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)