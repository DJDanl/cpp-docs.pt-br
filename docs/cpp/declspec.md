---
title: '{1&gt;__declspec&lt;1}'
ms.date: 03/21/2019
f1_keywords:
- __declspec_cpp
- __declspec
- _declspec
helpviewer_keywords:
- __declspec keyword [C++]
ms.openlocfilehash: e0c99ea9379aa6e29096250e8bd36ce3d4f183e8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180219"
---
# <a name="__declspec"></a>{1&gt;__declspec&lt;1}

**Seção específica da Microsoft**

A sintaxe de atributo estendido para especificar informações de classe de armazenamento usa a palavra-chave **__declspec** , que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft listado abaixo. Exemplos de outros modificadores de classe de armazenamento incluem as palavras-chave **static** e **extern** . No entanto, essas palavras-chave fazem parte da especificação ANSI das linguagens C e C++ e, assim, não são abrangidas pela sintaxe de atributo estendido. A sintaxe de atributo estendido simplifica e padroniza extensões específicas da Microsoft para as linguagens C e C++.

## <a name="grammar"></a>Gramática

*especificador de decl*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__declspec (** *Extended-decl-Modifier-Seq* **)**

*extended-decl-modifier-seq*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Extended-decl-modificador* *-decl-Modifier-Seq*

*extended-decl-modifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**alinhar (** *#* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**alocar ("** *segname* **")**<br/>
&nbsp;&nbsp;&nbsp;**alocador** &nbsp;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**AppDomain**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**code_seg ("** *segname* **")**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**preterida**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllimport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllexport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**jitintrinsic**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**naked**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**noalias**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;não **embutido**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**noreturn**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**nothrow**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**novtable**<br/>
&nbsp;&nbsp;&nbsp;**processo** de &nbsp;<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Propriedade (** { **Get =** _get_func_name_ &#124; **, put =** _put_func_name_ } **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**restringir**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**safebuffers**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**selectany**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Spectre (nomitigation)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**thread**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**UUID ("** *ComObjectGUID* **")**

O espaço em branco separa a sequência modificadora de declaração. Os exemplos aparecem nas seções posteriores.

A gramática de atributo estendido dá suporte a esses atributos de classe de armazenamento específicos da Microsoft: [align](../cpp/align-cpp.md), [ALLOCATE](../cpp/allocate.md), [alocador](../cpp/allocator.md), [AppDomain](../cpp/appdomain.md), [code_seg](../cpp/code-seg-declspec.md), [preterido](../cpp/deprecated-cpp.md), [dllexport](../cpp/dllexport-dllimport.md), [DllImport](../cpp/dllexport-dllimport.md), [jitintrinsic](../cpp/jitintrinsic.md), [Naked](../cpp/naked-cpp.md), [noalias](../cpp/noalias.md), sem [linha](../cpp/noinline.md), [noretorno](../cpp/noreturn.md), [nothrow](../cpp/nothrow-cpp.md), [novtable](../cpp/novtable.md), [process](../cpp/process.md), [restrict](../cpp/restrict.md), [safebuffers](../cpp/safebuffers.md), [selectany](../cpp/selectany.md), [ Spectre](../cpp/spectre.md)e [thread](../cpp/thread.md). Ele também dá suporte a esses atributos de objeto COM: [Property](../cpp/property-cpp.md) e [UUID](../cpp/uuid-cpp.md).

Os atributos de classe de armazenamento **code_seg**, **dllexport**, **DllImport**, **Naked**, **noalias**, **nothrow**, **Property**, **restrict**, **selectany**, **thread**e **UUID** são propriedades somente da declaração do objeto ou da função à qual eles são aplicados. O atributo **thread** afeta somente os dados e os objetos. Os atributos **Naked** e **Spectre** afetam apenas funções. Os atributos **DllImport** e **dllexport** afetam funções, dados e objetos. Os atributos **Property**, **selectany**e **UUID** afetam objetos com.

Para compatibilidade com versões anteriores, **_declspec** é um sinônimo para **__declspec** , a menos que a opção de compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

As palavras-chave **__declspec** devem ser colocadas no início de uma declaração simples. O compilador ignora, sem aviso, quaisquer **__declspec** palavras-chave colocadas após * ou & e na frente do identificador de variável em uma declaração.

Um atributo **__declspec** especificado no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. Por exemplo:

```cpp
__declspec(dllimport) class X {} varX;
```

Nesse caso, o atributo se aplica a `varX`. Um atributo **__declspec** colocado após a palavra-chave **Class** ou **struct** se aplica ao tipo definido pelo usuário. Por exemplo:

```cpp
class __declspec(dllimport) X {};
```

Nesse caso, o atributo se aplica a `X`.

A diretriz geral para usar o atributo **__declspec** para declarações simples é a seguinte:

*decl-especificador-Seq* *init-declarator-List*;

O *decl-especificador-Seq* deve conter, entre outras coisas, um tipo base (por exemplo, **int**, **float**, um **typedef**ou um nome de classe), uma classe de armazenamento (por exemplo, **estática**, **externa**) ou a extensão **__declspec** . A *lista init-declarator* deve conter, entre outras coisas, a parte do ponteiro das declarações. Por exemplo:

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

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)
