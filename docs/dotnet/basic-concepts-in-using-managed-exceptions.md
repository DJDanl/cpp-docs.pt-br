---
title: Conceitos básicos em usar exceções gerenciadas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- try-catch exception handling, managed applications
- __finally keyword, managed exceptions
- exceptions, managed
- try-catch exception handling
- catch blocks
- throwing exceptions, managed exceptions
- Visual C++, handling managed exceptions
ms.assetid: 40ce8931-1ecc-491a-815f-733b23fcba35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: cb94b262967723b9d0ed1c177c9ca7996b30f83a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448306"
---
# <a name="basic-concepts-in-using-managed-exceptions"></a>Conceitos básicos em usar exceções gerenciadas

Este tópico aborda o tratamento de exceções em aplicativos gerenciados. Ou seja, um aplicativo que é compilado com o **/clr** opção de compilador.

## <a name="in-this-topic"></a>Neste tópico

- [Lançando exceções em /clr](#vcconbasicconceptsinusingmanagedexceptionsanchor1)

- [Blocos de Try/Catch para extensões CLR](#vcconbasicconceptsinusingmanagedexceptionsanchor2)

## <a name="remarks"></a>Comentários

Se você compilar com o **/clr** opção, você pode tratar exceções de CLR, bem como standard [tratamento de exceções C++](../cpp/cpp-exception-handling.md) e [manipulação de exceção estruturada](../cpp/structured-exception-handling-c-cpp.md) (SEH). Uma exceção do CLR é qualquer exceção gerada por um tipo gerenciado. O [System:: Exception](https://msdn.microsoft.com/library/system.exception.aspx) classe fornece vários métodos úteis para o processamento de exceções de CLR e é recomendada como uma classe base para classes de exceção definidas pelo usuário.

Não há suporte para capturar tipos de exceção derivados de uma interface em **/clr**. Além disso, o common language runtime não permite que você para capturar exceções de estouro de pilha; uma exceção de estouro de pilha, o processo será encerrado.

Para obter mais informações sobre as diferenças no tratamento de exceções em aplicativos gerenciados e não gerenciados, consulte [diferenças na exceção tratamento comportamento em extensões gerenciadas para C++](../dotnet/differences-in-exception-handling-behavior-under-clr.md).

##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor1"></a> Lançando exceções em /clr

A expressão de lançamento do C++ é estendida para lançar um identificador para um tipo CLR. O exemplo a seguir cria um tipo de exceção personalizada e, em seguida, gera uma instância desse tipo:

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

Um tipo de valor deve ser boxed antes que está sendo lançada:

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

##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor2"></a> Blocos de Try/Catch para extensões CLR

O mesmo **tente**/**catch** estrutura de bloco pode ser usada para capturar o CLR e exceções nativas:

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

### <a name="order-of-unwinding-for-c-objects"></a>Ordem de desenrolamento para objetos C++

Desenrolar ocorre para todos os objetos C++ com destruidores que podem estar na pilha de tempo de execução entre a função gerando e a função de manipulação. Porque os tipos CLR são alocados no heap, o desenrolamento não é aplicável a eles.

A ordem de eventos para uma exceção lançada é da seguinte maneira:

1. O runtime percorre a pilha procurando para a cláusula catch apropriada ou, no caso de SEH, uma, exceto o filtro para SEH, para capturar a exceção. Cláusulas catch são pesquisadas primeiro em ordem léxica e, em seguida, dinamicamente para baixo da pilha de chamadas.

1. Depois que o manipulador correto for encontrado, a pilha é desenrolada para esse ponto. Para cada chamada de função na pilha, seus objetos locais são destruídos e Finally blocos são executados, da maioria aninhados para fora.

1. Depois que a pilha é liberada, a cláusula catch é executada.

### <a name="catching-unmanaged-types"></a>Capturando tipos não gerenciados

Quando um tipo de objeto não gerenciado é lançado, ela é empacotada com uma exceção do tipo [System::Runtime.InteropServices::SEHException](https://msdn.microsoft.com/library/system.runtime.interopservices.sehexception.aspx). Ao procurar apropriado **catch** cláusula, há duas possibilidades.

- Se for encontrado um tipo nativo do C++, a exceção é desempacotada e em comparação com o tipo encontrado. Essa comparação permite que um tipo nativo do C++ ser capturada da maneira normal.

- No entanto, se um **catch** cláusula do tipo **SEHException** ou qualquer uma das suas classes base é examinado pela primeira vez, a cláusula será interceptar a exceção. Portanto, você deve colocar todas as cláusulas catch que capturar tipos nativos do C++ primeiro antes de quaisquer cláusulas de tipos CLR de catch.

Observe que

```
catch(Object^)
```

e

```
catch(...)
```

ambos irá capturar qualquer tipo lançado, incluindo exceções SEH.

Se um tipo não gerenciado é capturado por catch(Object^), ele será destrói o objeto gerado.

Ao gerar ou capturar exceções for gerenciada, é recomendável que você use o [/EHsc](../build/reference/eh-exception-handling-model.md) opção de compilador em vez de **/EHs** ou **/EHa**.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../windows/exception-handling-cpp-component-extensions.md)<br/>
[Safe_cast](../windows/safe-cast-cpp-component-extensions.md)<br/>
[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)