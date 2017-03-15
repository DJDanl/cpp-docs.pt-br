---
title: "safe_cast (C++ Component Extensions) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "safe_cast"
  - "safe_cast_cpp"
  - "stdcli::language::safe_cast"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "safe_cast keyword [C++]"
ms.assetid: 4fa688bf-a8ec-49bc-a4c5-f48134efa4f7
caps.latest.revision: 26
caps.handback.revision: 24
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# safe_cast (C++ Component Extensions)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `safe_cast` operação retorna a expressão especificada como o tipo especificado, se for bem\-sucedido; caso contrário, lança `InvalidCastException`.  
  
## Todos os Tempos de Execução  
 \(Não há nenhum comentários para esse recurso de linguagem que se aplicam a todos os tempos de execução.\)  
  
### Sintaxe  
  
```cpp  
  
[default]:: safe_cast<  
type-id  
>(  
expression  
)  
  
```  
  
### Parâmetros  
  
### Observações  
  
## [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)]  
 `safe_cast` permite que você altere o tipo de uma expressão especificada.  Em situações onde você totalmente esperar uma variável ou parâmetro a ser convertida para um determinado tipo, você pode usar safe\_cast sem um bloco try\-catch para detectar erros de programação durante o desenvolvimento.  Para obter mais informações, consulte [de conversão \(C\+\+ c\+\+ \/CX\)](http://msdn.microsoft.com/library/windows/apps/hh755802.aspx).  
  
### Sintaxe  
  
```cpp  
  
[default]:: safe_cast<  
type-id  
>(  
expression  
)  
  
```  
  
### Parâmetros  
 *id do tipo*  
 O tipo para converter *expressão* para.  Um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência de rastreamento para um tipo de valor ou referência.  
  
 *expressão*  
 Uma expressão que é avaliada como um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência de rastreamento para um tipo de valor ou referência.  
  
### Observações  
 `safe_cast` lança `InvalidCastException` se não puder converter *expressão* para o tipo especificado por *id do tipo*.  Para capturar `InvalidCastException`, especifique o [\/EH \(modelo de tratamento de exceções\)](../build/reference/eh-exception-handling-model.md) opção de compilador e use uma instrução try\/catch.  
  
### Requisitos  
 Opção do compilador: **\/ZW**  
  
### Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir demonstra como usar `safe_cast` com o [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)].  
  
```cpp#  
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
  
 **Saída**  
  
  **Detectada exceção esperada: InvalidCastException**   
## [!INCLUDE[clr_for_headings](../dotnet/includes/clr_for_headings_md.md)]  
 `safe_cast` permite que você altere o tipo de uma expressão e gerar código MSIL verificável.  
  
### Sintaxe  
  
```cpp  
  
[cli]:: safe_cast<  
type-id  
>(  
expression  
)  
  
```  
  
### Parâmetros  
 *id do tipo*  
 Um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência de rastreamento para um tipo de valor ou referência.  
  
 *expressão*  
 Uma expressão que é avaliada como um identificador para uma referência ou tipo de valor, um tipo de valor ou uma referência de rastreamento para um tipo de valor ou referência.  
  
### Observações  
 A expressão `safe_cast<`*id do tipo*`>(`*expressão*`)` converte a expressão de operando em um objeto do tipo do id do tipo.  
  
 O compilador aceitará um [static\_cast](../cpp/static-cast-operator.md) na maioria dos lugares aceitará um `safe_cast`.  No entanto, `safe_cast` é garantido para produzir MSIL verificável, enquanto um `static_cast` pode produzir MSIL não possa ser verificado.  Consulte [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md) e [Peverify.exe \(Ferramenta PEVerify\)](../Topic/Peverify.exe%20\(PEVerify%20Tool\).md) para obter mais informações sobre código verificável.  
  
 Como `static_cast`, `safe_cast` invoca conversões definidas pelo usuário.  
  
 Para obter mais informações sobre conversões, consulte [Operadores de conversão](../cpp/casting-operators.md).  
  
 `safe_cast` não se aplica uma **const\_cast** \(eliminar **const**\).  
  
 `safe_cast` está no namespace cli.  Consulte [Platform, default, and cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) para obter mais informações.  
  
 Para obter mais informações sobre **safe\_cas**t, consulte:  
  
-   [C\-Style Casts with \/clr \(C\+\+\/CLI\)](../windows/c-style-casts-with-clr-cpp-cli.md)  
  
-   [Como usar safe\_cast em C\+\+\/CLI](../Topic/How%20to:%20Use%20safe_cast%20in%20C++-CLI.md)  
  
-   [Como fazer downcast com safe\_cast](../misc/how-to-downcast-with-safe-cast.md)  
  
-   [Como usar safe\_cast e tipos genéricos](../misc/how-to-use-safe-cast-and-generic-types.md)  
  
-   [Como usar safe\_cast e conversões definidas pelo usuário](../misc/how-to-use-safe-cast-and-user-defined-conversions.md)  
  
-   [Como usar safe\_cast e conversão boxing](../Topic/How%20to:%20Use%20safe_cast%20and%20Boxing.md)  
  
-   [Como usar safe\_cast e conversão unboxing](../misc/how-to-use-safe-cast-and-unboxing.md)  
  
### Requisitos  
 Opção do compilador: **\/clr**  
  
### Exemplos  
 **Exemplo**  
  
 Um exemplo de onde o compilador não aceitará um `static_cast` mas aceitará um `safe_cast` para conversões entre tipos de interface não relacionadas.  Com `safe_cast`, o compilador não emitirá um erro de conversão e executará uma verificação em tempo de execução para ver se a conversão é possível  
  
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
  
 **Saída**  
  
  **Exceção esperada detectada**   
## Consulte também  
 [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md)