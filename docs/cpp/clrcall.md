---
title: "__clrcall | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__clrcall"
  - "__clrcall_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __clrcall [C++]"
ms.assetid: 92096695-683a-40ed-bf65-0c8443572152
caps.latest.revision: 17
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __clrcall
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Especifica que uma função só pode ser chamada de um código gerenciado.  Use `__clrcall` para todas as funções virtuais que serão chamadas somente a partir do código gerenciado.  No entanto, essa convenção de chamada não pode ser usada para as funções que serão chamadas a partir do código nativo.  
  
 Use `__clrcall` para melhorar o desempenho ao chamar a partir de uma função gerenciada em uma função gerenciada virtual ou a partir da função gerenciada para a função gerenciada pelo ponteiro.  
  
 Os pontos de entrada são funções separadas geradas pelo compilador.  Se uma função tem pontos de entrada nativos e gerenciados, um deles será a função real com a implementação da função.  Outra função será uma função separada \(uma conversão\) que chamará a função real e deixará Common Language Runtime executar PInvoke.  Ao marcar uma função como `__clrcall`, você indica que a implementação da função deverá ser MSIL e que a função nativa do ponto de entrada não será gerada.  
  
 Ao colocar o endereço de uma função nativa se `__clrcall` se não for especificado, o compilador usará o ponto de entrada nativo.  `__clrcall` indica que a função é gerenciada e que não há necessidade de passar pela transição de gerenciada a nativa.  Nesse caso, o compilador usa o ponto de entrada gerenciado.  
  
 Quando **\/clr** \(não **\/clr:pure** ou **\/clr:safe**\) é usado e `__clrcall` não é usado, usar o endereço de uma função sempre retorna o endereço da função nativa do ponto de entrada.  Quando `__clrcall` é usado, a função nativa do ponto de entrada não é criada. Assim, você obtém o endereço da função gerenciada, não uma função de conversão do ponto de entrada.  Para obter mais informações, consulte [Conversão dupla](../Topic/Double%20Thunking%20\(C++\).md).  
  
 [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md) indica que todas as funções e ponteiros de função são `__clrcall` e o compilador não permitirá que uma função dentro de compiland seja marcada como algo diferente de `__clrcall`.  Quando **\/clr:pure** é usado, `__clrcall` só pode ser especificado em ponteiros da função e em declarações externas.  
  
 Você pode chamar diretamente as funções `__clrcall` de código C\+\+ existente que foi compilado usando **\/clr**, desde que essa função tenha uma implementação de MSIL.  as funções`__clrcall` não podem ser chamadas diretamente de funções que têm ASM integrado e chamam intrinisics específico da CPU, por exemplo, mesmo se essas funções forem compilados com **\/clr**.  
  
 os ponteiros da função`__clrcall` devem ser usados somente no domínio de aplicativo no qual foram criados.  Em vez de transmitir ponteiros da função `__clrcall` pelos domínios de aplicativo, use <xref:System.CrossAppDomainDelegate>.  Para obter mais informações, consulte [Domínios de aplicativo e Visual C\+\+](../dotnet/application-domains-and-visual-cpp.md).  
  
## Exemplo  
  
```  
// clrcall.cpp  
// compile with: /clr:oldSyntax /LD  
void __clrcall Test1( ) {}  
void (__clrcall *fpTest1)( ) = &Test1;  
```  
  
## Exemplo  
 Quando uma função é declarada com `__clrcall`, o código é gerado quando necessário; por exemplo, quando a função é chamada.  
  
```  
// clrcall2.cpp  
// compile with: /clr  
using namespace System;  
int __clrcall Func1() {  
   Console::WriteLine("in Func1");  
   return 0;  
}  
  
// Func1 hasn't been used at this point (code has not been generated),   
// so runtime returns the adddress of a stub to the function  
int (__clrcall *pf)() = &Func1;  
  
// code calls the function, code generated at difference address  
int i = pf();   // comment this line and comparison will pass  
  
int main() {  
   if (&Func1 == pf)  
      Console::WriteLine("&Func1 == pf, comparison succeeds");  
   else   
      Console::WriteLine("&Func1 != pf, comparison fails");  
  
   // even though comparison fails, stub and function call are correct  
   pf();  
   Func1();  
}  
```  
  
  **em Func1**  
**&Func1\! \= pf, falha na comparação**  
**em Func1**  
**em Func1**   
## Exemplo  
 O exemplo a seguir mostra que você pode definir um ponteiro de função de modo a declarar que o ponteiro de função será invocado apenas de códigos gerenciados.  Isso permite que o compilador chame diretamente a função gerenciada e evita o ponto de entrada nativo \(problema de duas conversões\).  
  
```  
// clrcall3.cpp  
// compile with: /clr  
void Test() {  
   System::Console::WriteLine("in Test");  
}  
  
int main() {  
   void (*pTest)() = &Test;  
   (*pTest)();  
  
   void (__clrcall *pTest2)() = &Test;  
   (*pTest2)();  
}  
```  
  
## Consulte também  
 [Passagem de argumento e convenções de nomenclatura](../Topic/Argument%20Passing%20and%20Naming%20Conventions.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)