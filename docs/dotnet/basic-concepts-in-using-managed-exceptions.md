---
title: "Conceitos básicos em usar exceções gerenciadas | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- try-catch exception handling, managed applications
- __finally keyword, managed exceptions
- exceptions, managed
- try-catch exception handling
- catch blocks
- throwing exceptions, managed exceptions
- Visual C++, handling managed exceptions
ms.assetid: 40ce8931-1ecc-491a-815f-733b23fcba35
caps.latest.revision: "21"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 530bf529faa3fc5c08ea850f8ae390e12d49ac14
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="basic-concepts-in-using-managed-exceptions"></a>Conceitos básicos em usar exceções gerenciadas
Este tópico discute a manipulação de exceções em aplicativos gerenciados. Ou seja, um aplicativo que é compilado com o **/clr** opção de compilador.  
  
## <a name="in-this-topic"></a>Neste tópico  
  
-   [Lançando exceções em /clr](#vcconbasicconceptsinusingmanagedexceptionsanchor1)  
  
-   [Blocos de Try/Catch para extensões CLR](#vcconbasicconceptsinusingmanagedexceptionsanchor2)  
  
## <a name="remarks"></a>Comentários  
 Se você compilar com o **/clr** opção, você pode manipular exceções de CLR, bem como padrão [tratamento de exceções C++](../cpp/cpp-exception-handling.md) e [tratamento estruturado de exceções](../cpp/structured-exception-handling-c-cpp.md) (SEH). Uma exceção CLR é qualquer exceção gerada por um tipo gerenciado. O [System:: Exception](https://msdn.microsoft.com/en-us/library/system.exception.aspx) classe fornece muitos métodos úteis para o processamento de exceções de CLR e é recomendada como uma classe base para classes de exceção definido pelo usuário.  
  
 Não há suporte para a captura de tipos de exceção derivados de uma interface em **/clr**. Além disso, o common language runtime não permite que você para capturar exceções de estouro de pilha; uma exceção de estouro de pilha, o processo será encerrado.  
  
 Para obter mais informações sobre as diferenças no tratamento de exceção em aplicativos gerenciados e não gerenciados, consulte [diferenças na exceção tratamento comportamento em extensões gerenciadas para C++](../dotnet/differences-in-exception-handling-behavior-under-clr.md).  
  
##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor1"></a>Lançando exceções em /clr  
 A expressão throw C++ é estendido para gerar um identificador para um tipo CLR. O exemplo a seguir cria um tipo de exceção personalizada e, em seguida, gera uma instância desse tipo:  
  
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
  
 Um tipo de valor deve ser boxed antes que está sendo gerada:  
  
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
  
##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor2"></a>Blocos de Try/Catch para extensões CLR  
 O mesmo **tente**/**catch** estrutura de bloco pode ser usada para capturar o CLR e exceções nativo:  
  
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
  
### <a name="output"></a>Saída  
  
```  
In 'catch(CMyClass& catchC)'  
2  
In 'catch(MyStruct^ catchException)'  
11  
```  
  
### <a name="order-of-unwinding-for-c-objects"></a>Ordem de desenrolamento para objetos de C++  
 Liberação ocorre para todos os objetos C++ com destruidores podem estar na pilha de tempo de execução entre a função sendo lançada e a função de manipulação. Como tipos CLR são alocados no heap, desenrolamento não se aplicam a eles.  
  
 A ordem de eventos para uma exceção lançada é da seguinte maneira:  
  
1.  O tempo de execução examina a pilha procurando para a cláusula catch apropriada ou, no caso de SEH, uma exceção filtro para SEH, para capturar a exceção. Catch cláusulas são pesquisadas primeiro na ordem lexical e, em seguida, dinamicamente para a pilha de chamadas.  
  
2.  Depois que o identificador correto for encontrado, a pilha é organizada para esse ponto. Para cada chamada de função na pilha, seus objetos locais são destruídos e Finally os blocos são executados, da maioria aninhados para fora.  
  
3.  Depois que a pilha é organizada, a cláusula catch é executada.  
  
### <a name="catching-unmanaged-types"></a>Captura de tipos não gerenciados  
 Quando um tipo de objeto não gerenciado é lançado, ele é empacotado com uma exceção do tipo [System::Runtime.InteropServices::SEHException](https://msdn.microsoft.com/en-us/library/system.runtime.interopservices.sehexception.aspx). Ao procurar apropriada **catch** cláusula, há duas possibilidades.  
  
-   Se for encontrado um tipo de C++ nativo, a exceção é aberta e comparada com o tipo encontrado. Essa comparação permite que um tipo de C++ nativo a ser detectada da maneira normal.  
  
-   No entanto, se um **catch** cláusula do tipo **SEHException** ou uma de suas classes base é examinado pela primeira vez, a cláusula deve interceptar a exceção. Portanto, você deve colocar todas as cláusulas catch que capturar tipos nativos do C++ primeiro antes de qualquer catch cláusulas de tipos CLR.  
  
 Observe que  
  
```  
catch(Object^)  
```  
  
 e  
  
```  
catch(...)  
```  
  
 ambos capturará qualquer tipo gerado, incluindo exceções SEH.  
  
 Se um tipo não gerenciado é capturado por catch(Object^), não destruirá o objeto descartado.  
  
 Ao lançar ou capturar exceções for gerenciada, recomendamos que você use o [/EHsc](../build/reference/eh-exception-handling-model.md) opção de compilador em vez de **/EHs** ou **/EHa**.  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções](../windows/exception-handling-cpp-component-extensions.md)   
 [Safe_cast](../windows/safe-cast-cpp-component-extensions.md)   
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)