---
title: "Conceitos b&#225;sicos em usar exce&#231;&#245;es gerenciadas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __finally, exceções gerenciadas"
  - "blocos catch"
  - "exceções, gerenciadas"
  - "lançando exceções, exceções gerenciadas"
  - "tratamento de exceções de try-catch"
  - "tratamento de exceções de try-catch, aplicativos gerenciados"
  - "Visual C++, tratando exceções gerenciadas"
ms.assetid: 40ce8931-1ecc-491a-815f-733b23fcba35
caps.latest.revision: 21
caps.handback.revision: 21
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Conceitos b&#225;sicos em usar exce&#231;&#245;es gerenciadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute a manipulação de exceção nos aplicativos gerenciados.  Isto é, um aplicativo que foi criado com a opção do compilador de **\/clr** .  
  
## Neste tópico  
  
-   [Lançando exceções em \/clr](#vcconbasicconceptsinusingmanagedexceptionsanchor1)  
  
-   [Blocos try\/catch para extensões de CLR](#vcconbasicconceptsinusingmanagedexceptionsanchor2)  
  
## Comentários  
 Se você compila com a opção de **\/clr** , você pode tratar exceções de CLR bem como [Manipulação de exceção C\+\+](../cpp/cpp-exception-handling.md) padrão e [manipulação de exceção estruturado](../cpp/structured-exception-handling-c-cpp.md) \(ELA\).  Uma exceção de CLR é qualquer exceção gerada por um tipo gerenciado.  A classe de [System::Exception](https://msdn.microsoft.com/en-us/library/system.exception.aspx) fornece vários métodos úteis para processar exceções de CLR e é recomendada por uma classe base para classes definidos pelo usuário da exceção.  
  
 Capturar os tipos de exceção derivados de uma interface não tem suporte em **\/clr**.  Além disso, Common Language Runtime não permite capturar exceções de estouro de pilhas; uma exceção de estouro de pilha encerrará o processo.  
  
 Para obter mais informações sobre as diferenças na manipulação de exceção em aplicativos gerenciados e não gerenciados, consulte [Diferenças no comportamento de manipulação de exceção em extensões gerenciadas para C\+\+](../dotnet/differences-in-exception-handling-behavior-under-clr.md).  
  
##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor1"></a> Lançando exceções em \/clr  
 A expressão do lançamento do C\+\+ é estendida para gerar um identificador para um tipo CLR.  O exemplo a seguir cria um tipo de exceção personalizada e lançará em uma instância desse tipo:  
  
```  
// clr_exception_handling.cpp  
// compile with: /clr /c  
ref struct MyStruct: public System::Exception {  
public:  
   int i;  
};  
  
void GlobalFunction() {  
   MyStruct^ pMyStruct = gcnew MyStruct;  
   throw pMyStruct;  
}  
```  
  
 Um tipo de valor deve ser encaixotado antes de ser gerado:  
  
```  
// clr_exception_handling_2.cpp  
// compile with: /clr /c  
value struct MyValueStruct {  
   int i;  
};  
  
void GlobalFunction() {  
   MyValueStruct v = {11};  
   throw (MyValueStruct ^)v;  
}  
```  
  
##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor2"></a> Blocos try\/catch para extensões de CLR  
 A mesma estrutura **try**\/bloco de**catch** pode ser usado para capturar exceções e CLR nativos:  
  
```  
// clr_exception_handling_3.cpp  
// compile with: /clr  
using namespace System;  
ref struct MyStruct : public Exception {  
public:  
   int i;  
};  
  
struct CMyClass {  
public:  
   double d;  
};  
  
void GlobalFunction() {  
   MyStruct^ pMyStruct = gcnew MyStruct;  
   pMyStruct->i = 11;  
   throw pMyStruct;  
}  
  
void GlobalFunction2() {  
   CMyClass c = {2.0};  
   throw c;  
}  
  
int main() {  
   for ( int i = 1; i >= 0; --i ) {  
      try {  
         if ( i == 1 )  
            GlobalFunction2();  
         if ( i == 0 )  
            GlobalFunction();  
      }  
      catch ( CMyClass& catchC ) {  
         Console::WriteLine( "In 'catch(CMyClass& catchC)'" );  
         Console::WriteLine( catchC.d );  
      }  
      catch ( MyStruct^ catchException ) {  
         Console::WriteLine( "In 'catch(MyStruct^ catchException)'" );  
         Console::WriteLine( catchException->i );  
      }  
   }  
}  
```  
  
### Saída  
  
```  
In 'catch(CMyClass& catchC)'  
2  
In 'catch(MyStruct^ catchException)'  
11  
```  
  
### Ordem de desenrolamento para objetos C\+\+  
 Desenrolar ocorre para todos os objetos C\+\+ com destruidores que podem estar na pilha de tempo de execução entre a função de reprodução e a função de tratamento.  Como os tipos CLR são atribuídos no heap, desenrolando não se aplicam a eles.  
  
 A ordem de eventos para uma exceção gerada é a seguinte:  
  
1.  O tempo de execução mostra a pilha que procura a cláusula adequada de captura ou, no caso de ELA, exceto o filtro para ELA, para capturar a exceção.  As cláusulas de captura são pesquisadas primeiro na ordem léxica, e depois dinamicamente abaixo da pilha de chamadas.  
  
2.  Uma vez que o manipulador correto está localizado, a pilha é distribuída depois a aquele ponto.  Para cada chamada de função na pilha, seus objetos locais destructed os blocos e são executados \_\_finally, da mais aninhado out.  
  
3.  A pilha é distribuída depois uma vez, a cláusula de captura é executada.  
  
### Capturando tipos não gerenciado  
 Quando um tipo de objeto não gerenciado é gerado, está envolvido com uma exceção do tipo [System::Runtime.InteropServices::SEHException](https://msdn.microsoft.com/en-us/library/system.runtime.interopservices.sehexception.aspx).  Ao procurar pela cláusula adequada de **catch** , há duas possibilidades.  
  
-   Se um tipo de C\+\+ nativo está localizado, a exceção será desempacotada e comparada ao tipo localizado.  Essa comparação permite que um tipo de C\+\+ nativo é capturado de maneira normal.  
  
-   Porém, se uma cláusula de **catch** do tipo **SEHException** ou qualquer uma de suas classes base é verificada primeiro, a cláusula interceptará a exceção.  Em virtude disso, você deve colocar as cláusulas de captura que capturam tipos de C\+\+ nativo antes das cláusulas de captura de tipos CLR.  
  
 Observe que  
  
```  
catch(Object^)  
```  
  
 e  
  
```  
catch(...)  
```  
  
 ambos capturarão qualquer tipo gerado incluir ELA exceções.  
  
 Se um tipo gerenciado não é capturado pela captura Object^ \(\), não destruirá o objeto lançado.  
  
 Ao gerar ou ao capturar exceções não gerenciado, recomendamos que você use a opção do compilador de [\/EHsc](../build/reference/eh-exception-handling-model.md) em vez de **\/EHs** ou de **\/EHa**.  
  
## Consulte também  
 [Exception Handling](../windows/exception-handling-cpp-component-extensions.md)   
 [safe\_cast](../windows/safe-cast-cpp-component-extensions.md)   
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)