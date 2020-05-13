---
title: Conceitos básicos em usar exceções gerenciadas
ms.date: 11/04/2016
helpviewer_keywords:
- try-catch exception handling, managed applications
- __finally keyword, managed exceptions
- exceptions, managed
- try-catch exception handling
- catch blocks
- throwing exceptions, managed exceptions
- Visual C++, handling managed exceptions
ms.assetid: 40ce8931-1ecc-491a-815f-733b23fcba35
ms.openlocfilehash: 6bc1e9c6d40599ae9a821179dcf56dbb7e21bf10
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372521"
---
# <a name="basic-concepts-in-using-managed-exceptions"></a>Conceitos básicos em usar exceções gerenciadas

Este tópico discute o tratamento de exceções em aplicativos gerenciados. Ou seja, um aplicativo que é compilado com a opção **/clr** compilador.

## <a name="in-this-topic"></a>Neste tópico

- [Lançar exceções sob /clr](#vcconbasicconceptsinusingmanagedexceptionsanchor1)

- [Try/Catch Blocks for CLR Extensions](#vcconbasicconceptsinusingmanagedexceptionsanchor2)

## <a name="remarks"></a>Comentários

Se você compilar com a opção **/clr,** você pode <xref:System.Exception> lidar com exceções CLR, bem como a classe padrão fornece muitos métodos úteis para processar exceções CLR e é recomendado como uma classe base para classes de exceção definidas pelo usuário.

A captura de tipos de exceção derivados de uma interface não é suportada em **/clr**. Além disso, o tempo de execução do idioma comum não permite que você pegue exceções de estouro de pilha; uma exceção de estouro de pilha encerrará o processo.

Para obter mais informações sobre diferenças no tratamento de exceções em aplicativos gerenciados e não gerenciados, consulte [Diferenças no comportamento de tratamento de exceções em extensões gerenciadas para C++](../dotnet/differences-in-exception-handling-behavior-under-clr.md).

## <a name="throwing-exceptions-under-clr"></a><a name="vcconbasicconceptsinusingmanagedexceptionsanchor1"></a>Lançar exceções sob /clr

A expressão de lançamento C++ é estendida para jogar uma alça para um tipo CLR. O exemplo a seguir cria um tipo de exceção personalizada e, em seguida, lança uma instância desse tipo:

```cpp
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

Um tipo de valor deve ser encaixotado antes de ser jogado:

```cpp
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

## <a name="trycatch-blocks-for-clr-extensions"></a><a name="vcconbasicconceptsinusingmanagedexceptionsanchor2"></a>Try/Catch Blocks for CLR Extensions

A mesma estrutura de bloco de**captura** **de tentativa**/pode ser usada para capturar exceções clr e nativas:

```cpp
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

### <a name="order-of-unwinding-for-c-objects"></a>Ordem de desenrolar para objetos C++

O desenrolar ocorre para quaisquer objetos C++ com destrutores que possam estar na pilha de tempo de execução entre a função de arremesso e a função de manuseio. Como os tipos CLR são alocados no heap, o desenrolar não se aplica a eles.

A ordem dos eventos para uma exceção lançada é a seguinte:

1. O tempo de execução caminha pela pilha procurando a cláusula de captura apropriada, ou no caso do SEH, um filtro exceto para SEH, para pegar a exceção. As cláusulas de captura são pesquisadas primeiro em ordem léxica e, em seguida, dinamicamente para baixo da pilha de chamadas.

1. Uma vez que o manipulador correto é encontrado, a pilha é desenrolada até esse ponto. Para cada chamada de função na pilha, seus objetos locais são destruídos e __finally blocos são executados, a partir da maioria aninhado para fora.

1. Uma vez que a pilha é desenrolada, a cláusula de captura é executada.

### <a name="catching-unmanaged-types"></a>Capturando tipos não gerenciados

Quando um tipo de objeto não gerenciado é jogado, <xref:System.Runtime.InteropServices.SEHException>ele é embrulhado com uma exceção do tipo . Ao procurar a cláusula de **captura** apropriada, existem duas possibilidades.

- Se um tipo C++ nativo for encontrado, a exceção será desembrulhada e comparada com o tipo encontrado. Esta comparação permite que um tipo C++ nativo seja pego da maneira normal.

- No entanto, se uma cláusula de **captura** do tipo **SEHException** ou qualquer uma de suas classes base for examinada primeiro, a cláusula interceptará a exceção. Portanto, você deve colocar todas as cláusulas de captura que capturam os tipos C++ nativos primeiro antes de quaisquer cláusulas de captura dos tipos CLR.

Observe que

```
catch(Object^)
```

e

```
catch(...)
```

ambos pegarão qualquer tipo de lança, incluindo exceções de SEH.

Se um tipo não gerenciado for pego por captura (Object^), ele não destruirá o objeto jogado.

Ao lançar ou capturar exceções não gerenciadas, recomendamos que você use a opção [/EHsc](../build/reference/eh-exception-handling-model.md) compilor em vez de **/EHs** ou **/EHa**.

## <a name="see-also"></a>Confira também

[Tratamento de Exceção](../extensions/exception-handling-cpp-component-extensions.md)<br/>
[safe_cast](../extensions/safe-cast-cpp-component-extensions.md)<br/>
[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)
