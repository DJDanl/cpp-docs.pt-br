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
ms.openlocfilehash: cf241d4e599ad58c2e39680d8ed4e4e250b42b18
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988545"
---
# <a name="basic-concepts-in-using-managed-exceptions"></a>Conceitos básicos em usar exceções gerenciadas

Este tópico discute a manipulação de exceções em aplicativos gerenciados. Ou seja, um aplicativo que é compilado com a opção de compilador **/CLR** .

## <a name="in-this-topic"></a>{1&gt;Neste tópico&lt;1}

- [Gerando exceções em/CLR](#vcconbasicconceptsinusingmanagedexceptionsanchor1)

- [Blocos try/catch para extensões CLR](#vcconbasicconceptsinusingmanagedexceptionsanchor2)

## <a name="remarks"></a>Comentários

Se você compilar com a opção **/CLR** , você pode manipular exceções CLR, bem como a classe de <xref:System.Exception> padrão fornece muitos métodos úteis para processar exceções CLR e é recomendado como uma classe base para classes de exceção definidas pelo usuário.

Não há suporte para a captura de tipos de exceção derivados de uma interface em **/CLR**. Além disso, o Common Language Runtime não permite capturar exceções de estouro de pilha; uma exceção de estouro de pilha encerrará o processo.

Para obter mais informações sobre as diferenças no tratamento de exceções em aplicativos gerenciados e não gerenciados, consulte [diferenças no comportamento de tratamento C++de exceções em extensões gerenciadas para ](../dotnet/differences-in-exception-handling-behavior-under-clr.md)o.

##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor1"></a>Gerando exceções em/CLR

A C++ expressão throw é estendida para lançar um identificador para um tipo CLR. O exemplo a seguir cria um tipo de exceção personalizada e, em seguida, gera uma instância desse tipo:

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

Um tipo de valor deve estar em caixa antes de ser gerado:

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

##  <a name="vcconbasicconceptsinusingmanagedexceptionsanchor2"></a>Blocos try/catch para extensões CLR

O mesmo **teste**/estrutura de bloco **Catch** pode ser usado para capturar as exceções nativas e CLR:

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

### <a name="order-of-unwinding-for-c-objects"></a>Ordem de liberação de C++ objetos

O desenrolamento ocorre para C++ todos os objetos com destruidores que podem estar na pilha de tempo de execução entre a função de lançamento e a função de manipulação. Como os tipos CLR são alocados no heap, o desenrolamento não se aplica a eles.

A ordem dos eventos de uma exceção gerada é a seguinte:

1. O tempo de execução percorre a pilha procurando a cláusula catch apropriada ou, no caso de SEH, um filtro Except para SEH, para capturar a exceção. As cláusulas catch são pesquisadas primeiro na ordem léxica e, em seguida, dinamicamente na pilha de chamadas.

1. Depois que o manipulador correto for encontrado, a pilha será rebobinada para esse ponto. Para cada chamada de função na pilha, seus objetos locais são destruidos e __finally blocos são executados, da mais aninhada para fora.

1. Depois que a pilha é rebobinada, a cláusula catch é executada.

### <a name="catching-unmanaged-types"></a>Capturando tipos não gerenciados

Quando um tipo de objeto não gerenciado é gerado, ele é encapsulado com uma exceção do tipo <xref:System.Runtime.InteropServices.SEHException>. Ao pesquisar a cláusula **Catch** apropriada, há duas possibilidades.

- Se um tipo C++ nativo for encontrado, a exceção será desencapsulada e comparada ao tipo encontrado. Essa comparação permite que um C++ tipo nativo seja detectado da maneira normal.

- No entanto, se uma cláusula **Catch** do tipo **SEHException** ou qualquer uma de suas classes base for examinada primeiro, a cláusula interceptará a exceção. Portanto, você deve posicionar todas as cláusulas catch que C++ capturam tipos nativos primeiro antes de qualquer cláusula catch de tipos CLR.

Observe que

```
catch(Object^)
```

e

```
catch(...)
```

ambos capturarão qualquer tipo gerado, incluindo Exceções SEH.

Se um tipo não gerenciado for capturado por catch (Object ^), ele não destruirá o objeto gerado.

Ao lançar ou capturar exceções não gerenciadas, recomendamos que você use a opção de compilador [/EHsc](../build/reference/eh-exception-handling-model.md) em vez de **o/EHS** ou **/EHA**.

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../extensions/exception-handling-cpp-component-extensions.md)<br/>
[safe_cast](../extensions/safe-cast-cpp-component-extensions.md)<br/>
[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)
