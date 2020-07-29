---
title: __declspec
ms.date: 03/21/2019
f1_keywords:
- __declspec_cpp
- __declspec
- _declspec
helpviewer_keywords:
- __declspec keyword [C++]
ms.openlocfilehash: 945202beca6c5deb525bd19886b947331f6f3ac3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228941"
---
# `__declspec`

**Específico da Microsoft**

A sintaxe de atributo estendido para especificar informações de classe de armazenamento usa a **`__declspec`** palavra-chave, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft listado abaixo. Exemplos de outros modificadores de classe de armazenamento incluem **`static`** as **`extern`** palavras-chave e. No entanto, essas palavras-chave fazem parte da especificação ANSI das linguagens C e C++ e, assim, não são abrangidas pela sintaxe de atributo estendido. A sintaxe de atributo estendido simplifica e padroniza extensões específicas da Microsoft para as linguagens C e C++.

## <a name="grammar"></a>Gramática

*especificador de decl*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__declspec (`**  *Extended-decl-Modifier-Seq*  **`)`**

*Extended-decl-Modifier-Seq*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Extended-decl-Modifier* *Extended-decl-Modifier-Seq*

*Extended-decl-Modifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`align(`** *#* **`)`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`allocate("`***segname***`")`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`allocator`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`appdomain`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`code_seg("`***segname***`")`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`deprecated`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllimport`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllexport`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`jitintrinsic`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`naked`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`noalias`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`noinline`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`noreturn`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`nothrow`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`novtable`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`process`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`property(`**{ **`get=`** _get_func_name_ &#124; **`,put=`** _put_func_name_ }**`)`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`restrict`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`safebuffers`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`selectany`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`spectre(nomitigation)`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`thread`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`uuid("`***ComObjectGUID***`")`**

O espaço em branco separa a sequência modificadora de declaração. Os exemplos aparecem nas seções posteriores.

A gramática de atributo estendido dá suporte a esses atributos de classe de armazenamento específicos da Microsoft:,,,,,,, [`align`](../cpp/align-cpp.md) [`allocate`](../cpp/allocate.md) [`allocator`](../cpp/allocator.md) [`appdomain`](../cpp/appdomain.md) [`code_seg`](../cpp/code-seg-declspec.md) [`deprecated`](../cpp/deprecated-cpp.md) [`dllexport`](../cpp/dllexport-dllimport.md) [`dllimport`](../cpp/dllexport-dllimport.md) , [`jitintrinsic`](../cpp/jitintrinsic.md) , [`naked`](../cpp/naked-cpp.md) , [`noalias`](../cpp/noalias.md) , [`noinline`](../cpp/noinline.md) , [`noreturn`](../cpp/noreturn.md) , [`nothrow`](../cpp/nothrow-cpp.md) , [`novtable`](../cpp/novtable.md) ,, [`process`](../cpp/process.md) [`restrict`](../cpp/restrict.md) , [`safebuffers`](../cpp/safebuffers.md) ,, [`selectany`](../cpp/selectany.md) [`spectre`](../cpp/spectre.md) e [`thread`](../cpp/thread.md) . Ele também dá suporte a esses atributos de objeto COM: [`property`](../cpp/property-cpp.md) e [`uuid`](../cpp/uuid-cpp.md) .

Os atributos,,,,,,,,, **`code_seg`** **`dllexport`** e de **`dllimport`** **`naked`** **`noalias`** **`nothrow`** **`property`** **`restrict`** **`selectany`** **`thread`** **`uuid`** classe de armazenamento são propriedades somente da declaração do objeto ou da função à qual eles são aplicados. O **`thread`** atributo afeta somente dados e objetos. Os **`naked`** **`spectre`** atributos e afetam apenas funções. Os **`dllimport`** **`dllexport`** atributos e afetam funções, dados e objetos. Os **`property`** **`selectany`** atributos, e **UU'ID** afetam objetos com.

Para compatibilidade com versões anteriores, **`_declspec`** é um sinônimo para **`__declspec`** , a menos que a opção do compilador [/za \( desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

As **`__declspec`** palavras-chave devem ser colocadas no início de uma declaração simples. O compilador ignora, sem aviso, quaisquer **`__declspec`** palavras-chave colocadas após * ou & e na frente do identificador de variável em uma declaração.

Um **`__declspec`** atributo especificado no início de uma declaração de tipo definida pelo usuário se aplica à variável desse tipo. Por exemplo:

```cpp
__declspec(dllimport) class X {} varX;
```

Nesse caso, o atributo se aplica a `varX`. Um **`__declspec`** atributo colocado após a **`class`** **`struct`** palavra-chave ou se aplica ao tipo definido pelo usuário. Por exemplo:

```cpp
class __declspec(dllimport) X {};
```

Nesse caso, o atributo se aplica a `X`.

A diretriz geral para usar o **`__declspec`** atributo para declarações simples é a seguinte:

*decl-especificador-Seq* *init-declarator-List*;

O *decl-especificador-Seq* deve conter, entre outras coisas, um tipo base (por exemplo,, **`int`** **`float`** a **`typedef`** , ou um nome de classe), uma classe de armazenamento (por exemplo **`static`** , **`extern`** ) ou a **`__declspec`** extensão. A *lista init-declarator* deve conter, entre outras coisas, a parte do ponteiro das declarações. Por exemplo:

```cpp
__declspec(selectany) int * pi1 = 0;   //Recommended, selectany & int both part of decl-specifier
int __declspec(selectany) * pi2 = 0;   //OK, selectany & int both part of decl-specifier
int * __declspec(selectany) pi3 = 0;   //ERROR, selectany is not part of a declarator
```

O código a seguir declara uma variável local de thread inteiro e a inicializa com um valor:

```cpp
// Example of the __declspec keyword
__declspec( thread ) int tls_i = 1;
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)
