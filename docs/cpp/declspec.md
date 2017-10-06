---
title: declspec | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- __declspec_cpp
dev_langs:
- C++
helpviewer_keywords:
- __declspec keyword [C++]
ms.assetid: 832db681-e8e1-41ca-b78c-cd9d265cdb87
caps.latest.revision: 12
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: b29b6243611f1ca59a579869469c803d3735f9df
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="declspec"></a>__declspec
## <a name="microsoft-specific"></a>Específico da Microsoft  
 A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra-chave `__declspec`, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft listado abaixo. Exemplos de outros modificadores de classe de armazenamento incluem as palavras-chave `static` e `extern`. No entanto, essas palavras-chave fazem parte da especificação ANSI das linguagens C e C++ e, assim, não são abrangidas pela sintaxe de atributo estendido. A sintaxe de atributo estendido simplifica e padroniza extensões específicas da Microsoft para as linguagens C e C++.  
  
## <a name="grammar"></a>Gramática  
 *especificador de Decl*:  
 `__declspec (`  *estendido-decl-modificador-seq*  `)`  
  
 *extended-decl-modifier-seq*:  
 *extended-decl-modifier*opt  
  
 *modificador estendido de decl estendido-decl-modificador-seq*  
  
 *extended-decl-modifier*:  
 `align(` *#* `)`  
  
 `allocate("`*segname*`")`  
  
 `appdomain`  
  
 `code_seg("`*segname*`")`  
  
 `deprecated`  
  
 `dllimport`  
  
 `dllexport`  
  
 `jitintrinsic`  
  
 `naked`  
  
 `noalias`  
  
 `noinline`  
  
 `noreturn`  
  
 `nothrow`  
  
 `novtable`  
  
 `process`  
  
 `property(`{`get=`*get_func_name*&#124;`,put=` *put_func_name*}`)`  
  
 `restrict`  
  
 `safebuffers`  
  
 `selectany`  
  
 `thread`  
  
 `uuid("`*ComObjectGUID*`")`  
  
 O espaço em branco separa a sequência modificadora de declaração. Os exemplos aparecem nas seções posteriores.  
  
 Esses atributos de classe de armazenamento específicas da Microsoft oferece suporte a gramática de atributo estendido: [alinhar](../cpp/align-cpp.md), [alocar](../cpp/allocate.md), [appdomain](../cpp/appdomain.md), [code_seg](../cpp/code-seg-declspec.md), [preterido](../cpp/deprecated-cpp.md), [dllexport](../cpp/dllexport-dllimport.md), [dllimport](../cpp/dllexport-dllimport.md), [jitintrinsic](../cpp/jitintrinsic.md), [naked](../cpp/naked-cpp.md), [noalias](../cpp/noalias.md), [noinline](../cpp/noinline.md), [noreturn](../cpp/noreturn.md), [nothrow](../cpp/nothrow-cpp.md), [novtable](../cpp/novtable.md) , [processo](../cpp/process.md), [restringir](../cpp/restrict.md), [safebuffers](../cpp/safebuffers.md), [selectany](../cpp/selectany.md), e [thread](../cpp/thread.md). Ele também dá suporte a esses atributos de objeto COM: [propriedade](../cpp/property-cpp.md) e [uuid](../cpp/uuid-cpp.md).  
  
 Os atributos de classe de armazenamento `code_seg`, `dllexport`, `dllimport`, `naked`, `noalias`, `nothrow`, `property`, `restrict`, `selectany`, `thread` e `uuid` são propriedades somente da declaração do objeto ou da função aos quais são aplicadas. O atributo `thread` afeta somente dados e objetos. O atributo `naked` afeta somente funções. Os atributos `dllimport` e `dllexport` afetam funções, dados e objetos. Os atributos `property`, `selectany` e `uuid` afetam objetos COM.  
  
 As palavras-chave `__declspec` devem ser colocadas no início de uma declaração simples. O compilador ignora, sem aviso, qualquer palavra-chave `__declspec` colocada após * ou & e na frente do identificador de variável em uma declaração.  
  
 Um atributo `__declspec` especificado no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo. Por exemplo:  
  
```  
__declspec(dllimport) class X {} varX;  
```  
  
 Nesse caso, o atributo se aplica a `varX`. Um atributo `__declspec` colocado após a palavra-chave `class` ou `struct` se aplica ao tipo definido pelo usuário. Por exemplo:  
  
```  
class __declspec(dllimport) X {};  
```  
  
 Nesse caso, o atributo se aplica a `X`.  
  
 A diretriz geral para o uso do atributo `__declspec` para declarações simples é a seguinte:  
  
```  
  
decl-specifier-seq  
declarator-list;  
```  
  
 O *decl de especificador de seq* deve conter, em entre outras coisas, um tipo base (por exemplo, `int`, `float`, um `typedef`, ou um nome de classe), uma classe de armazenamento (por exemplo, `static`, `extern`), ou o `__declspec`extensão. O *lista de declaradores init* deve conter entre outras coisas, a parte de ponteiro de declarações. Por exemplo:  
  
```  
__declspec(selectany) int * pi1 = 0;   //OK, selectany & int both part of decl-specifier  
int __declspec(selectany) * pi2 = 0;   //OK, selectany & int both part of decl-specifier  
int * __declspec(selectany) pi3 = 0;   //ERROR, selectany is not part of a declarator  
```  
  
 O código a seguir declara uma variável local de thread inteiro e a inicializa com um valor:  
  
```  
// Example of the __declspec keyword  
__declspec( thread ) int tls_i = 1;  
```  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)
