---
title: "__declspec | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__declspec_cpp"
  - "__declspec"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++]"
ms.assetid: 832db681-e8e1-41ca-b78c-cd9d265cdb87
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __declspec
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 A sintaxe de atributo estendido para a especificação de informações de classe de armazenamento usa a palavra\-chave `__declspec`, que especifica que uma instância de um determinado tipo deve ser armazenada com um atributo de classe de armazenamento específico da Microsoft listado abaixo.  Exemplos de outros modificadores de classe de armazenamento incluem as palavras\-chave `static` e `extern`.  No entanto, essas palavras\-chave fazem parte da especificação ANSI das linguagens C e C\+\+ e, assim, não são abrangidas pela sintaxe de atributo estendido.  A sintaxe de atributo estendido simplifica e padroniza extensões específicas da Microsoft para as linguagens C e C\+\+.  
  
## Gramática  
 *decl\-specifier*:  
 `__declspec (`  *extended\-decl\-modifier\-seq*  `)`  
  
 *extended\-decl\-modifier\-seq*:  
 *extended\-decl\-modifier* opt  
  
 *extended\-decl\-modifier extended\-decl\-modifier\-seq*  
  
 *extended\-decl\-modifier*:  
 `align(` *\#* `)`  
  
 `allocate("` *segname* `")`  
  
 `appdomain`  
  
 `code_seg("` *segname* `")`  
  
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
  
 `property(`{`get=`*get\_func\_name*&#124;`,put=`*put\_func\_name*}`)`  
  
 `restrict`  
  
 `safebuffers`  
  
 `selectany`  
  
 `thread`  
  
 `uuid("` *ComObjectGUID* `")`  
  
 O espaço em branco separa a sequência modificadora de declaração.  Os exemplos aparecem nas seções posteriores.  
  
 A gramática do atributo estendido oferece suporte a estes atributos de classe de armazenamento específicos da Microsoft: [align](../cpp/align-cpp.md), [allocate](../Topic/allocate.md), [appdomain](../Topic/appdomain.md), [code\_seg](../cpp/code-seg-declspec.md), [deprecated](../cpp/deprecated-cpp.md), [dllexport](../cpp/dllexport-dllimport.md), [dllimport](../cpp/dllexport-dllimport.md), [jitintrinsic](../cpp/jitintrinsic.md), [naked](../Topic/naked%20\(C++\).md), [noalias](../cpp/noalias.md), [noinline](../cpp/noinline.md), [noreturn](../cpp/noreturn.md), [nothrow](../Topic/nothrow%20\(C++\).md), [novtable](../cpp/novtable.md), [process](../cpp/process.md), [restrict](../cpp/restrict.md), [safebuffers](../Topic/safebuffers.md), [selectany](../cpp/selectany.md) e [thread](../cpp/thread.md).  Ela também oferece suporte a estes atributos de objeto COM: [property](../cpp/property-cpp.md) e [uuid](../cpp/uuid-cpp.md).  
  
 Os atributos de classe de armazenamento `code_seg`, `dllexport`, `dllimport`, `naked`, `noalias`, `nothrow`, `property`, `restrict`, `selectany`, `thread` e `uuid` são propriedades somente da declaração do objeto ou da função aos quais são aplicadas.  O atributo `thread` afeta somente dados e objetos.  O atributo `naked` afeta somente funções.  Os atributos `dllimport` e `dllexport` afetam funções, dados e objetos.  Os atributos `property`, `selectany` e `uuid` afetam objetos COM.  
  
 As palavras\-chave `__declspec` devem ser colocadas no início de uma declaração simples.  O compilador ignora, sem aviso, qualquer palavra\-chave `__declspec` colocada após \* ou & e na frente do identificador de variável em uma declaração.  
  
 Um atributo `__declspec` especificado no início de uma declaração de tipo definido pelo usuário se aplica à variável desse tipo.  Por exemplo:  
  
```  
__declspec(dllimport) class X {} varX;  
```  
  
 Nesse caso, o atributo se aplica a `varX`.  Um atributo `__declspec` colocado após a palavra\-chave `class` ou `struct` se aplica ao tipo definido pelo usuário.  Por exemplo:  
  
```  
class __declspec(dllimport) X {};  
```  
  
 Nesse caso, o atributo se aplica a `X`.  
  
 A diretriz geral para o uso do atributo `__declspec` para declarações simples é a seguinte:  
  
```  
  
decl-specifier-seq declarator-list;  
```  
  
 *decl\-specifier\-seq* deve conter, entre outras coisas, um tipo base \(por exemplo,  `int`, `float`, um `typedef` ou um nome de classe\), uma classe de armazenamento \(por exemplo,  `static`, `extern`\) ou a extensão `__declspec`.  *init\-declarator\-list* deve conter, entre outras coisas, a parte do ponteiro de declarações.  Por exemplo:  
  
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
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)