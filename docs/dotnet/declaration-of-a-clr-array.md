---
title: Declaração de uma matriz CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- array keyword [C++]
ms.assetid: 36a8883c-2663-43f0-a90c-28f27035e036
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c3de17bb293e10c4e1a2287ef12b934633b1fe21
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426452"
---
# <a name="declaration-of-a-clr-array"></a>Declaração de uma matriz CLR

A sintaxe para declarar, instanciar e inicializar uma matriz gerenciada foi alterado de extensões gerenciadas para C++ no Visual C++.

A declaração de um objeto de matriz CLR nas extensões gerenciadas era uma extensão da declaração de matriz padrão no qual um `__gc` palavra-chave foi colocado entre o nome do objeto array e sua dimensão preenchidos, possivelmente, vírgula, como no seguinte par de Exemplos:

```
void PrintValues( Object* myArr __gc[]);
void PrintValues( int myArr __gc[,,]);
```

Isso foi simplificado na nova sintaxe, em que podemos usar uma declaração de tipo de modelo semelhante a biblioteca padrão C++ `vector` declaração. O primeiro parâmetro indica o tipo de elemento. O segundo parâmetro especifica a dimensão de matriz (com um valor padrão de 1, várias dimensões de modo que apenas exigem um segundo argumento). O objeto de matriz em si é um identificador de acompanhamento e portanto deve ser fornecido um chapéu. Se o tipo de elemento também é um tipo de referência, ele também requer um hat. Por exemplo, o exemplo acima, quando expresso na nova sintaxe, terá a seguinte aparência:

```
void PrintValues( array<Object^>^ myArr );
void PrintValues( array<int,3>^ myArr );
```

Como um tipo de referência é um identificador de acompanhamento em vez de um objeto, é possível especificar uma matriz CLR como o tipo de retorno de uma função. (Por outro lado, não é possível especificar a matriz nativa como o tipo de retorno de uma função.) A sintaxe para fazer isso nas extensões gerenciadas foi um tanto não intuitivo. Por exemplo:

```
Int32 f() [];
int GetArray() __gc[];
```

No Visual C++, a declaração é muito mais simples. Por exemplo,

```
array<Int32>^ f();
array<int>^ GetArray();
```

Há suporte para a inicialização de forma abreviada de uma matriz gerenciada local ambas as versões da linguagem. Por exemplo:

```
int GetArray() __gc[] {
   int a1 __gc[] = { 1, 2, 3, 4, 5 };
   Object* myObjArray __gc[] = {
      __box(26), __box(27), __box(28), __box(29), __box(30)
   };
   return a1;
}
```

é simplificado consideravelmente na nova sintaxe (Observe que, como conversão boxing é implícita na nova sintaxe, o `__box` operador foi eliminado – veja [tipos de valor e seus comportamentos (C + + c++ CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md) para ver uma discussão):

```
array<int>^ GetArray() {
   array<int>^ a1 = {1,2,3,4,5};
   array<Object^>^ myObjArray = {26,27,28,29,30};
   return a1;
}
```

Como uma matriz é um tipo de referência do CLR, a declaração de cada objeto de matriz é um identificador de acompanhamento. Portanto, os objetos de matriz devem ser alocados no heap CLR. (A notação abreviada oculta a alocação de heap gerenciado.) Aqui está uma forma explícita de uma inicialização de objeto de matriz em extensões gerenciadas:

```
Object* myArray[] = new Object*[2];
String* myMat[,] = new String*[4,4];
```

Sob a nova sintaxe, o `new` expressão é substituída com `gcnew`. Os tamanhos da dimensão são passados como parâmetros para o `gcnew` expressão, da seguinte maneira:

```
array<Object^>^ myArray = gcnew array<Object^>(2);
array<String^,2>^ myMat = gcnew array<String^,2>(4,4);
```

Na nova sintaxe, uma lista de inicialização explícita pode seguir o `gcnew` expressão; isso não era suportado em extensões gerenciadas. Por exemplo:

```
// explicit initialization list following gcnew
// was not supported in Managed Extensions
array<Object^>^ myArray =
   gcnew array<Object^>(4){ 1, 1, 2, 3 };
```

## <a name="see-also"></a>Consulte também

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
[Matrizes](../windows/arrays-cpp-component-extensions.md)