---
title: Classes parciais (C++ c++ /CX) | Microsoft Docs
ms.custom: ''
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 69d93575-636c-4564-8cca-6dfba0c7e328
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: dd1d5f7559b88505929153ae1852fc42171e5208
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43756841"
---
# <a name="partial-classes-ccx"></a>Classes parciais (C++/CX)
Uma classe parcial é uma construção que oferece suporte a cenários nos quais você está modificando uma parte da definição de uma classe e software de geração de código automático, por exemplo, o designer XAML, também está modificando código na mesma classe. Usando uma classe parcial, você pode impedir que o designer substitua o seu código. Em um projeto do Visual Studio, o modificador de `partial` é aplicado automaticamente ao arquivo gerado.  
  
## <a name="syntax"></a>Sintaxe  
 Para definir uma classe parcial, use a palavra-chave `partial` imediatamente antes da chave de classe do que de outra forma seria uma definição de classe normal. Uma palavra-chave como `partial ref class` é uma palavra-chave contextual que contém caracteres de espaço em branco. As construções a seguir oferecem suporte para as definições parciais.  
  
-   `class` ou `struct`  
  
-   `ref class` ou `ref struct`  
  
-   `value class` ou `value struct`  
  
-   `enum` ou `enum class`  
  
-   `ref interface`, `interface class`, `interface struct`ou `__interface`  
  
-   `union`  
  
 Este exemplo demonstra uma `ref class`parcial:  
  
 [!code-cpp[cx_partial#01](../cppcx/codesnippet/CPP/partialclassexample/class1.h#01)]  
  
## <a name="contents"></a>Conteúdo  
 Uma definição de classe parcial poderá conter tudo que a definição de classe completa pode conter se a palavra-chave `partial` tiver sido omitida. Com uma exceção, isso inclui qualquer construção válida, como classes base, membros de dados, funções de membro, enums, declarações amigáveis e atributos. E definições embutidas de membros de dados estáticos são permitidas.  
  
 A única exceção é a acessibilidade da classe. Por exemplo, a declaração `public partial class MyInvalidClass {/* ... */};` é um erro. Os especificadores de acesso usados em uma definição de classe parcial para MyInvalidClass não afetam a acessibilidade padrão em uma definição de classe parcial ou completa para MyInvalidClass.  
  
 O fragmento de código a seguir demonstra a acessibilidade. Na primeira classe parcial, `Method1` é público porque sua acessibilidade é pública. Na segunda classe parcial, `Method2` é particular porque a acessibilidade de classe padrão é particular.  
  
 [!code-cpp[cx_partial#02](../cppcx/codesnippet/CPP/partialclassexample/class1.h#02)]  
  
## <a name="declaration"></a>Declaração  
 Uma definição parcial de uma classe como *MyClass* é apenas uma declaração de MyClass. Ou seja, ele apresenta somente o nome *MyClass*. *MyClass* não pode ser usada de forma que exija uma definição de classe, por exemplo, sabendo o tamanho de *MyClass* ou usando uma base ou um membro de *MyClass*. A definição de*MyClass* é considerada somente quando o compilador encontra uma definição não parcial de *MyClass*.  
  
 O exemplo a seguir demonstra o comportamento da declaração de uma classe parcial. Após a declaração nº 1, *MyClass* poderá ser usado como se tivesse sido escrito como a declaração de encaminhamento, `ref class MyClass;`. A declaração 2 é equivalente à declaração 1. A declaration 3 é válida porque é uma declaração de encaminhamento a uma classe. Mas a declaração 4 não é válida porque  
  
 *MyClass* não está totalmente definida.  
  
 A declaração nº 5 não usa a palavra-chave `partial` e a declaração define totalmente *MyClass*. Portanto, a declaração 6 é válida.  
  
 [!code-cpp[Cx_partial#03](../cppcx/codesnippet/CPP/partialclassexample/class1.h#03)]  
  
## <a name="number-and-ordering"></a>Número e ordenação  
 Pode haver definições de classe zero ou mais parciais para cada definição completa de uma classe.  
  
 Cada definição parcial de uma classe deve preceder lexicalmente a única definição completa de uma classe, mas não tem de preceder declarações de encaminhamento da classe. Se não houver nenhuma definição completa da classe, as declarações parciais da classe somente poderão ser declarações de encaminhamento.  
  
 Todas as chaves de classe, como `class` e `struct` , devem coincidir. Por exemplo, é incorreto codificar `partial class X {}; struct X {};`.  
  
 O exemplo a seguir demonstra o número e a ordenação. A última declaração parcial falha porque a classe já está definida.  
  
 [!code-cpp[cx_partial#04](../cppcx/codesnippet/CPP/partialclassexample/class1.h#04)]  
  
## <a name="full-definition"></a>Definição completa  
 No ponto da definição completa da classe X, o comportamento será igual como se a definição de X tivesse declarado todas as classes base, membros etc. na ordem em que foram encontrados e definidos nas classes parciais. Ou seja, o conteúdo das classes parciais é tratado como se elas tivessem sido escritas no ponto da definição completa da classe e outras regras de pesquisa de nome e linguagem fossem aplicadas no ponto da definição completa da classe, como se o conteúdo das classes parciais fosse escrito no lugar  
  
 Os dois exemplos de código a seguir têm significado e o efeito idênticos. O primeiro exemplo usa uma classe parcial e o segundo exemplo não.  
  
 [!code-cpp[cx_partial#05](../cppcx/codesnippet/CPP/partialclassexample/class1.h#05)]  
  
 [!code-cpp[cx_partial#06](../cppcx/codesnippet/CPP/partialclassexample/class1.h#06)]  
  
## <a name="templates"></a>Modelos  
 Uma classe parcial não pode ser um modelo.  
  
## <a name="restrictions"></a>Restrições  
 Uma classe parcial não pode se estender além de uma unidade de conversão.  
  
 A palavra-chave `partial` tem suporte apenas em combinação com a palavra-chave `ref class` ou a palavra-chave `value class` .  
  
### <a name="examples"></a>Exemplos  
 O exemplo a seguir define a classe `Address` em dois arquivos de código. O designer modifica `Address.details.h` e você modifica `Address.h`. Somente a definição de classe no primeiro arquivo usa a palavra-chave `partial` .  
  
 [!code-cpp[cx_partial#07](../cppcx/codesnippet/CPP/partialclassexample/address.details.h#07)]  
  
 [!code-cpp[cx_partial#09](../cppcx/codesnippet/CPP/partialclassexample/address.h#09)]  
  
## <a name="see-also"></a>Consulte também  
 [Sistema de tipos](../cppcx/type-system-c-cx.md)   
 [Referência de linguagem do Visual C++](../cppcx/visual-c-language-reference-c-cx.md)   
 [Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)