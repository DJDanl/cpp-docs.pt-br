---
title: __declspec | Microsoft Docs
ms.custom: ''
ms.date: 1/23/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- __declspec_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++]
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1b434ca991ef05bb90c3cbdc659cf8adc3381aa0
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43752898"
---
# <a name="declspec"></a>__declspec

**Seção específica da Microsoft**

A sintaxe de atributo estendido para especificar informações de classe de armazenamento utiliza o **declspec** palavra-chave, que especifica que uma instância de um determinado tipo deve ser armazenado com um atributo de classe de armazenamento específico da Microsoft listado abaixo. Exemplos de outros modificadores de classe de armazenamento do **estáticos** e **extern** palavras-chave. No entanto, essas palavras-chave fazem parte da especificação ANSI das linguagens C e C++ e, assim, não são abrangidas pela sintaxe de atributo estendido. A sintaxe de atributo estendido simplifica e padroniza extensões específicas da Microsoft para as linguagens C e C++.

## <a name="grammar"></a>Gramática

*decl-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__declspec (**  *extended-decl-modifier-seq*  **)**

*extended-decl-modifier-seq*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier* *extended-decl-modifier-seq*

*extended-decl-modifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**align(** *#* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**allocate("** *segname* **")**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**appdomain**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**code_seg("** *segname* **")**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Preterido**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllimport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllexport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**jitintrinsic**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**naked**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**noalias**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**noinline**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**noreturn**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**nothrow**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**novtable**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Processo**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**property(** { **get=**_get_func_name_ &#124; **,put=**_put_func_name_ } **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**restringir**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**safebuffers**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**selectany**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**spectre(nomitigation)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**thread**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**UUID ("** *ComObjectGUID* **")**

O espaço em branco separa a sequência modificadora de declaração. Os exemplos aparecem nas seções posteriores.

Gramática de atributo estendido dá suporte a esses atributos de classe de armazenamento específico da Microsoft: [alinhar](../cpp/align-cpp.md), [alocar](../cpp/allocate.md), [appdomain](../cpp/appdomain.md), [code_seg](../cpp/code-seg-declspec.md), [preterido](../cpp/deprecated-cpp.md), [dllexport](../cpp/dllexport-dllimport.md), [dllimport](../cpp/dllexport-dllimport.md), [jitintrinsic](../cpp/jitintrinsic.md), [naked](../cpp/naked-cpp.md), [noalias](../cpp/noalias.md), [noinline](../cpp/noinline.md), [noreturn](../cpp/noreturn.md), [nothrow](../cpp/nothrow-cpp.md), [novtable](../cpp/novtable.md) , [processo](../cpp/process.md), [restringir](../cpp/restrict.md), [safebuffers](../cpp/safebuffers.md), [selectany](../cpp/selectany.md), [spectre](../cpp/spectre.md), e [thread](../cpp/thread.md). Ele também dá suporte a esses atributos de objeto COM: [propriedade](../cpp/property-cpp.md) e [uuid](../cpp/uuid-cpp.md).

O **code_seg**, **dllexport**, **dllimport**, **naked**, **noalias**, **nothrow** , **propriedade**, **restringir**, **selectany**, **thread**, e **uuid**os atributos de classe de armazenamento são propriedades somente da declaração do objeto ou da função aos quais elas são aplicadas. O **thread** atributo afeta os dados e objetos apenas. O **naked** e **spectre** atributos afetam somente funções. O **dllimport** e **dllexport** atributos afetam funções, dados e objetos. O **propriedade**, **selectany**, e **uuid** atributos afetam objetos COM.

O **declspec** palavras-chave devem ser colocadas no início de uma declaração simples. O compilador ignora, sem aviso, qualquer **declspec** palavras-chave colocada após * ou & e na frente do identificador em uma declaração de variável.

Um **declspec** atributo especificado no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. Por exemplo:

```cpp
__declspec(dllimport) class X {} varX;
```

Nesse caso, o atributo se aplica a `varX`. Um **declspec** atributo colocado após o **classe** ou **struct** palavra-chave se aplica ao tipo definido pelo usuário. Por exemplo:

```cpp
class __declspec(dllimport) X {};
```

Nesse caso, o atributo se aplica a `X`.

A orientação geral para usar o **declspec** atributo para declarações simples é da seguinte maneira:

*decl-specifier-seq* *init-declarator-list*;

O *decl-specifier-seq* deve conter, em entre outras coisas, um tipo base (por exemplo, **int**, **float**, um **typedef**, ou um nome de classe), um classe de armazenamento (por exemplo, **estáticos**, **extern**), ou o **declspec** extensão. O *init-declarator-list* deve conter, em entre outras coisas, a parte das declarações do ponteiro. Por exemplo:

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

## <a name="see-also"></a>Consulte também
 [Palavras-chave](../cpp/keywords-cpp.md)  
 [Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)  