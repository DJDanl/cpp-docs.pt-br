---
title: Classes parciais (C++/CX)
description: Como declarar e usar classes parciais em C++/CX.
ms.date: 12/30/2016
ms.assetid: 69d93575-636c-4564-8cca-6dfba0c7e328
ms.openlocfilehash: 70225069c948a50b38ac3642113cf940c86cf8da
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609069"
---
# <a name="partial-classes-ccx"></a>Classes parciais (C++/CX)

Uma classe parcial é uma construção que oferece suporte a cenários nos quais você está modificando uma parte da definição de uma classe e software de geração de código automático, por exemplo, o designer XAML, também está modificando código na mesma classe. Usando uma classe parcial, você pode impedir que o designer substitua o seu código. Em um projeto do Visual Studio, o **`partial`** modificador é aplicado automaticamente ao arquivo gerado.

## <a name="syntax"></a>Sintaxe

Para definir uma classe parcial, use a **`partial`** palavra-chave imediatamente antes da chave de classe do que, caso contrário, seria uma definição de classe normal. Uma palavra-chave como **`partial ref class`** é uma palavra-chave contextual que contém caracteres de espaço em branco. As construções a seguir oferecem suporte para as definições parciais.

- **`class`** or **`struct`**

- **`ref class`** or **`ref struct`**

- **`value class`** or **`value struct`**

- **`enum`** or **`enum class`**

- **`ref interface`**, **`interface class`** , **`interface struct`** ou **`__interface`**

- **`union`**

Este exemplo demonstra um parcial **`ref class`** :

[!code-cpp[cx_partial#01](../cppcx/codesnippet/CPP/partialclassexample/class1.h#01)]

## <a name="contents"></a>Sumário

Uma definição de classe parcial pode conter qualquer coisa que a definição de classe completa possa conter se a **`partial`** palavra-chave tiver sido omitida. Com uma exceção, isso inclui qualquer construção válida, como classes base, membros de dados, funções de membro, enums, declarações amigáveis e atributos. E definições embutidas de membros de dados estáticos são permitidas.

A única exceção é a acessibilidade da classe. Por exemplo, a declaração `public partial class MyInvalidClass {/* ... */};` é um erro. Os especificadores de acesso usados em uma definição de classe parcial para MyInvalidClass não afetam a acessibilidade padrão em uma definição de classe parcial ou completa para MyInvalidClass.

O fragmento de código a seguir demonstra a acessibilidade. Na primeira classe parcial, `Method1` é público porque sua acessibilidade é pública. Na segunda classe parcial, `Method2` é particular porque a acessibilidade de classe padrão é particular.

[!code-cpp[cx_partial#02](../cppcx/codesnippet/CPP/partialclassexample/class1.h#02)]

## <a name="declaration"></a>Declaração

Uma definição parcial de uma classe como `MyClass` é apenas uma declaração de MyClass. Ou seja, ele só apresenta o nome `MyClass` . `MyClass` Não pode ser usado de uma maneira que exija uma definição de classe, por exemplo, saber o tamanho `MyClass` ou usar uma base ou membro de `MyClass` . `MyClass` é considerado para ser definido somente quando o compilador encontra uma definição não parcial de `MyClass` .

O exemplo a seguir demonstra o comportamento da declaração de uma classe parcial. Após a declaração #1, `MyClass` pode ser usado como se fosse escrito como a declaração de encaminhamento, `ref class MyClass;` . A declaração 2 é equivalente à declaração 1. A declaration 3 é válida porque é uma declaração de encaminhamento a uma classe. Mas a declaração 4 não é válida porque

`MyClass` não está totalmente definida.

A declaração #5 não usa a **`partial`** palavra-chave e a declaração define totalmente `MyClass` . Portanto, a declaração 6 é válida.

[!code-cpp[Cx_partial#03](../cppcx/codesnippet/CPP/partialclassexample/class1.h#03)]

## <a name="number-and-ordering"></a>Número e ordenação

Pode haver definições de classe zero ou mais parciais para cada definição completa de uma classe.

Cada definição de classe parcial de uma classe deve preceder lexicalmente uma definição completa dessa classe, mas não precisa preceder as declarações de encaminhamento da classe. Se não houver nenhuma definição completa da classe, as declarações parciais da classe somente poderão ser declarações de encaminhamento.

Todas as chaves de classe, como **`class`** e **`struct`** devem corresponder. Por exemplo, é incorreto codificar `partial class X {}; struct X {};`.

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

A **`partial`** palavra-chave tem suporte apenas em combinação com a **`ref class`** palavra-chave ou a **`value class`** palavra-chave.

### <a name="examples"></a>Exemplos

O exemplo a seguir define a classe `Address` em dois arquivos de código. O designer modifica `Address.details.h` e você modifica `Address.h`. Somente a definição de classe no primeiro arquivo usa a **`partial`** palavra-chave.

[!code-cpp[cx_partial#07](../cppcx/codesnippet/CPP/partialclassexample/address.details.h#07)]

[!code-cpp[cx_partial#09](../cppcx/codesnippet/CPP/partialclassexample/address.h#09)]

## <a name="see-also"></a>Confira também

[Sistema de tipo](../cppcx/type-system-c-cx.md)<br/>
[Referência de linguagem do C++/CX](../cppcx/visual-c-language-reference-c-cx.md)<br/>
[Referência de namespaces](../cppcx/namespaces-reference-c-cx.md)
