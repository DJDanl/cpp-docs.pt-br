---
title: Tipo Enum CLR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- scope, of CLR enum
- enum struct keyword [C++]
- enum class keyword [C++]
ms.assetid: 4541d952-97bb-4e35-a7f8-d14f5f6a6606
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 154904eb201f39852b57f253b97fba864084381a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="clr-enum-type"></a>Tipo enum CLR
A declaração e o comportamento de enums mudou de extensões gerenciadas para C++ para Visual C++.  
  
 A declaração de enum do Managed Extensions for precedida pelo `__value` palavra-chave. A ideia aqui é para distinguir o enum nativo de enum CLR que é derivado de `System::ValueType`, ao mesmo tempo, sugerindo uma funcionalidade semelhante. Por exemplo:  
  
```  
__value enum e1 { fail, pass };  
public __value enum e2 : unsigned short  {   
   not_ok = 1024,   
   maybe, ok = 2048   
};  
```  
  
 A nova sintaxe resolve o problema de distinguir nativo e o CLR enums ressaltando a natureza de classe do último em vez de suas raízes de tipo de valor. Como tal, o `__value` palavra-chave será descartado e substituídos por par de palavra-chave espaçadas de `enum class`. Isso proporciona uma simetria de pares de palavra-chave para as declarações de classes de interface, referência e valor:  
  
```  
enum class ec;  
value class vc;  
ref class rc;  
interface class ic;  
```  
  
 A conversão do par de enumeração `e1` e `e2` na nova sintaxe será semelhante ao seguinte:  
  
```  
enum class e1 { fail, pass };  
public enum class e2 : unsigned short {   
   not_ok = 1024,  
   maybe, ok = 2048   
};  
```  
  
 Além dessa alteração sintática pequena, o comportamento do tipo enum CLR foi alterado de várias maneiras:  
  
-   Não há suporte para a declaração de encaminhamento de um enum CLR. Não há nenhum mapeamento. Ele simplesmente será sinalizado como um erro de tempo de compilação.  
  
```  
__value enum status; // Managed Extensions: ok  
enum class status;   // new syntax: error  
```  
  
-   A resolução de sobrecarga entre os tipos internos de aritméticas e `Object` hierarquia de classe inverteu entre as versões de idioma de dois! Como um efeito colateral, o CLR enums implicitamente não são convertidos em tipos aritméticos.  
  
-   A nova sintaxe, um enum CLR mantém seu próprio escopo, que não é o caso em extensões gerenciadas. Anteriormente, os enumeradores eram visíveis no escopo contentor do enum. Agora, os enumeradores são encapsulados dentro do escopo do enum.  
  
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
  
 Para o programador de C++ nativo, o natural responder à pergunta de qual instância de sobrecarregados `f()` é invocado é de `f(int)`. Uma enumeração é uma constante de integral simbólica e participa de promoções integrais padrão que têm precedência nesse caso.  E, na verdade em extensões gerenciadas essa era a instância para o qual a chamada resolvido. Isso causou um número de surpresas - não quando usamos-los em um nativo C++ de espírito - mas precisávamos para interagir com a estrutura existente de BCL (Base Class Library), onde um `Enum` é uma classe indiretamente derivada de `Object`. No design de linguagem do Visual C++, a instância do `f()` invocado é de `f(Object^)`.  
  
 A maneira como o Visual C++ escolheu aplicar essa é não oferecer suporte a conversões implícitas entre um tipo de enum CLR e os tipos de aritméticos. Isso significa que nenhuma atribuição de um objeto de um tipo de enum CLR para um tipo aritmético exigirá uma conversão explícita. Portanto, por exemplo, dados  
  
```  
void f( int );  
```  
  
 como um método sobrecarregado não no Managed Extensions, a chamada  
  
```  
f( rslt ); // ok: Managed Extensions; error: new syntax  
```  
  
 é okey e o valor contido em `rslt` é implicitamente convertido em um valor inteiro. No Visual C++, essa chamada não compila. Para traduzi-lo corretamente, podemos deve inserir um operador de conversão:  
  
```  
f( safe_cast<int>( rslt )); // ok: new syntax  
```  
  
## <a name="the-scope-of-the-clr-enum-type"></a>O escopo do tipo Enum CLR  
 Uma das alterações entre as linguagens C e C++ foi a adição em C++ do escopo do recurso de estrutura. Em C, uma estrutura é apenas uma agregação sem suporte de uma interface ou um escopo associado de dados. Isso foi uma alteração radical no momento e foi um problema contenciosos para muitos novos usuários de C++ provenientes da linguagem C. Equivale a relação entre o nativo e enum CLR.  
  
 Nas extensões gerenciados, foi feita uma tentativa para definir levemente injetados nomes para os enumeradores de um enum CLR para simular a ausência de escopo de enum nativos. Isso não ser bem-sucedida. O problema é que isso faz com que os enumeradores despejar no namespace global, resultando em difíceis de gerenciar conflitos de nome. Na sintaxe de novo, podemos ter de acordo com os CLR em outros idiomas com suporte a escopos enum CLR.  
  
 Isso significa que qualquer uso não qualificado de um enumerador de um enum CLR não será reconhecido pela nova sintaxe. Vejamos um exemplo do mundo real.  
  
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
  
 Cada um dos três não qualificado usa os nomes de enumerador (`(1)`, `(2)`, e `(3)`) precisam ser qualificados na tradução para a nova sintaxe para que o código-fonte compilar. Aqui está uma tradução correta de código-fonte original:  
  
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
  
 Isso altera a estratégia de design entre um nativo e um enum CLR. Com um enum CLR mantendo um escopo associado no Visual C++, é necessário, nem eficaz para encapsular a declaração de enum dentro de uma classe. Esse idioma desenvolvidos por volta do horário cfront 2.0 em Bell Laboratories também para resolver o problema de poluição nome global.  
  
 Na versão beta original da nova biblioteca iostream por Jerry Schwarz na Bell Laboratories, a Jerry não encapsular todas as as enums associados definidos para a biblioteca e os enumeradores comuns, como `read`, `write`, `append`e assim por diante , tornou quase impossível para usuários compilar seu código existente. Uma solução seria desconfiguram os nomes, como `io_read`, `io_write`, etc. Uma segunda solução seria modificar o idioma, adicionando o escopo para um enum, mas isso não era for praticável de acordo no momento. A solução intermediária foi encapsular o enum dentro da classe ou classe hierarquia, onde o nome de marca e enumeradores de enum popular o escopo de classe delimitador.) Ou seja, a motivação para colocar enums nas classes de, pelo menos originalmente, não era filosóficas, mas uma resposta prática para o problema de poluição de espaço para nome global.  
  
 Com a enumeração do Visual C++, não é mais nenhum benefício interessante para encapsular um enum dentro de uma classe. Na verdade, se você observar o `System` namespaces, você verá que enumerações, classes e todas as interfaces habitam o mesmo espaço de declaração.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de valor e seus comportamentos (C + + CLI)](../dotnet/value-types-and-their-behaviors-cpp-cli.md)   
 [classe de enum](../windows/enum-class-cpp-component-extensions.md)