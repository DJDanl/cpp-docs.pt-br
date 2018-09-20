---
title: Tipo Enum CLR | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- scope, of CLR enum
- enum struct keyword [C++]
- enum class keyword [C++]
ms.assetid: 4541d952-97bb-4e35-a7f8-d14f5f6a6606
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a39c451bcff7b5b3b1d7dd9f0d3925616b9d6aab
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436216"
---
# <a name="clr-enum-type"></a>Tipo enum CLR

A declaração e o comportamento de enums mudou de extensões gerenciadas para C++ para Visual C++.

A declaração de enumeração de Managed Extensions é precedida pelo `__value` palavra-chave. A ideia aqui é distinguir o enum nativo de enum CLR que é derivado de `System::ValueType`, ao mesmo tempo, sugerindo uma funcionalidade semelhante. Por exemplo:

```
__value enum e1 { fail, pass };
public __value enum e2 : unsigned short  {
   not_ok = 1024,
   maybe, ok = 2048
};
```

A nova sintaxe do resolve o problema de fazer a distinção nativo e enums CLR, enfatizando a natureza de classe do último em vez de suas raízes de tipo de valor. Como tal, o `__value` palavra-chave será descartado e substituídos por par de palavra-chave espaçados de `enum class`. Isso fornece uma simetria de pares de palavra-chave para as declarações da referência, valor e classes de interface:

```
enum class ec;
value class vc;
ref class rc;
interface class ic;
```

A tradução do par de enumeração `e1` e `e2` na nova sintaxe será semelhante ao seguinte:

```
enum class e1 { fail, pass };
public enum class e2 : unsigned short {
   not_ok = 1024,
   maybe, ok = 2048
};
```

Além dessa pequena alteração sintática, o comportamento do tipo enum CLR foi alterado de várias maneiras:

- Não há suporte para a declaração de encaminhamento de um enum de CLR. Não há nenhum mapeamento. Ele simplesmente é sinalizado como um erro de tempo de compilação.

```
__value enum status; // Managed Extensions: ok
enum class status;   // new syntax: error
```

- A resolução de sobrecarga entre os tipos aritméticos internos e o `Object` hierarquia de classe inverteu entre as versões de idioma de dois! Como um efeito colateral, enums CLR não é mais implicitamente são convertidos para tipos aritméticos.

- Na nova sintaxe, um enum de CLR mantém seu próprio escopo, que não é o caso nas extensões gerenciadas. Anteriormente, os enumeradores eram visíveis no escopo contentor do enum. Agora, os enumeradores são encapsulados dentro do escopo do enum.

## <a name="clr-enums-are-a-kind-of-object"></a>Enumerações de CLR são um tipo de objeto

Considere o fragmento de código a seguir:

```
__value enum status { fail, pass };

void f( Object* ){ Console::WriteLine("f(Object)\n"); }
void f( int ){ Console::WriteLine("f(int)\n"); }

int main()
{
   status rslt = fail;

   f( rslt ); // which f is invoked?
}
```

Para o programador de C++ nativo, natural de resposta à pergunta de qual instância do sobrecarregado `f()` é invocado é o de `f(int)`. Uma enumeração é uma constante integral simbólica e participa de promoções de integral padrão que têm precedência nesse caso.  E, na verdade nas extensões gerenciadas, isso era a instância à qual a chamada resolve. Isso causou um número de surpresas - não quando usamos-los em um nativo C++ de espírito - mas precisávamos para interagir com a estrutura existente de BCL (Base Class Library), em que um `Enum` é uma classe indiretamente derivada de `Object`. No design de linguagem do Visual C++, a instância do `f()` invocado é de `f(Object^)`.

A maneira como o Visual C++ foi escolhido para impor isso é não oferecer suporte a conversões implícitas entre um tipo de enum CLR e os tipos aritméticos. Isso significa que qualquer atribuição de um objeto de um tipo de enum CLR para um tipo aritmético exigirá uma conversão explícita. Então, por exemplo, como

```
void f( int );
```

como um método sobrecarregado não nas extensões gerenciadas, a chamada

```
f( rslt ); // ok: Managed Extensions; error: new syntax
```

é okey e o valor contido dentro de `rslt` é implicitamente convertido em um valor inteiro. No Visual C++, essa chamada falha na compilação. Para convertê-lo corretamente, podemos deve inserir um operador de conversão:

```
f( safe_cast<int>( rslt )); // ok: new syntax
```

## <a name="the-scope-of-the-clr-enum-type"></a>O escopo do tipo Enum CLR

Uma das alterações entre as linguagens C e C++ era a adição em C++ do escopo em que o recurso de struct. Em C, um struct é apenas uma agregação sem suporte de uma interface ou um escopo associado de dados. Isso foi uma grande alteração radical no momento e foi um problema contenciosos para muitos novos usuários de C++ provenientes da linguagem C. A relação entre o nativo e enum CLR é análoga.

Nas extensões gerenciadas, foi feita uma tentativa para definir nomes sem rigidez injetados para enumeradores de um enum CLR para simular a ausência de escopo dentro do enum nativo. Isso não provou bem-sucedida. O problema é que isso faz com que os enumeradores para vazam para o namespace global, resultando em difíceis de gerenciar conflitos de nome. Na nova sintaxe, podemos ter de acordo com os CLR em outros idiomas que dão suporte a escopos de dentro do enum CLR.

Isso significa que qualquer uso não qualificado de um enumerador de um enum CLR não será reconhecido pela nova sintaxe. Vamos examinar um exemplo do mundo real.

```
// Managed Extensions supporting weak injection
__gc class XDCMake {
public:
   __value enum _recognizerEnum {
      UNDEFINED,
      OPTION_USAGE,
      XDC0001_ERR_PATH_DOES_NOT_EXIST = 1,
      XDC0002_ERR_CANNOT_WRITE_TO = 2,
      XDC0003_ERR_INCLUDE_TAGS_NOT_SUPPORTED = 3,
      XDC0004_WRN_XML_LOAD_FAILURE = 4,
      XDC0006_WRN_NONEXISTENT_FILES = 6,
   };

   ListDictionary* optionList;
   ListDictionary* itagList;

   XDCMake() {
      optionList = new ListDictionary;

      // here are the problems...
      optionList->Add(S"?", __box(OPTION_USAGE)); // (1)
      optionList->Add(S"help", __box(OPTION_USAGE)); // (2)

      itagList = new ListDictionary;
      itagList->Add(S"returns",
         __box(XDC0004_WRN_XML_LOAD_FAILURE)); // (3)
   }
};
```

Cada um dos três não qualificado usa os nomes do enumerador (`(1)`, `(2)`, e `(3)`) precisará ser qualificado na tradução para a nova sintaxe para que o código-fonte compilar. Aqui está uma tradução correta do código-fonte original:

```
ref class XDCMake {
public:
   enum class _recognizerEnum {
      UNDEFINED, OPTION_USAGE,
      XDC0001_ERR_PATH_DOES_NOT_EXIST = 1,
      XDC0002_ERR_CANNOT_WRITE_TO = 2,
      XDC0003_ERR_INCLUDE_TAGS_NOT_SUPPORTED = 3,
      XDC0004_WRN_XML_LOAD_FAILURE = 4,
      XDC0006_WRN_NONEXISTENT_FILES = 6
   };

   ListDictionary^ optionList;
   ListDictionary^ itagList;

   XDCMake() {
      optionList = gcnew ListDictionary;
      optionList->Add("?",_recognizerEnum::OPTION_USAGE); // (1)
      optionList->Add("help",_recognizerEnum::OPTION_USAGE); //(2)
      itagList = gcnew ListDictionary;
      itagList->Add( "returns",
         _recognizerEnum::XDC0004_WRN_XML_LOAD_FAILURE); //(3)
   }
};
```

Isso altera a estratégia de design entre um nativo e um enum de CLR. Com um enum CLR mantém um escopo associado no Visual C++, ele não é necessário nem eficiente encapsular a declaração de enum dentro de uma classe. Essa linguagem evoluiu na época do 2.0 de cfront da Bell Laboratories também para resolver o problema de poluição nome global.

Na versão beta original da nova biblioteca iostream por Jerry Schwarz na Bell Laboratories, a sua empresa não encapsular todos os as enums associadas definidas para a biblioteca e os enumeradores comuns, como `read`, `write`, `append`e assim por diante , tornou quase impossível para usuários compilar seu código existente. Uma solução seria desconfiguram os nomes, como `io_read`, `io_write`, etc. Uma segunda solução seria modificar o idioma, adicionando o escopo a uma enum, mas isso não era for praticável de acordo no momento. A solução intermediária era encapsular o enum dentro da classe ou classe hierarquia, em que o nome da marca e os enumeradores do enum popular o escopo delimitador de classe.) Ou seja, a motivação para o posicionamento de enumerações nas classes de, pelo menos originalmente, não era filosófico, mas uma resposta prática para o problema de poluição de espaço para nome global.

Com enum Visual C++, não há nenhum benefício atraente para encapsular uma enum dentro de uma classe. Na verdade, se você examinar o `System` namespaces, você verá que enumerações, classes e todas as interfaces habitam o mesmo espaço de declaração.

## <a name="see-also"></a>Consulte também

[Tipos de valor e seus comportamentos (C++/CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)<br/>
[classe de enum](../windows/enum-class-cpp-component-extensions.md)