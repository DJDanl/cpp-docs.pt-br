---
title: "static_assert | Microsoft Docs"
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
  - "C2338"
  - "static_assert_cpp"
  - "static_assert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "declarações [C++], static_assert"
  - "Palavras-chave em C++, static_assert"
  - "C2338"
  - "static_assert"
ms.assetid: 28dd3668-e78c-4de8-ba68-552084743426
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# static_assert
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa uma asserção de software no tempo de compilação.  Se a expressão constante especificada for `false`, o compilador exibirá a mensagem especificada e a compilação falhará com o erro C2338; caso contrário, a declaração não terá efeito.  
  
## Sintaxe  
  
```  
static_assert(   
    constant-expression,   
    string-literal   
);  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`constant-expression`|Uma expressão constante integral que pode ser convertida em um valor booliano.<br /><br /> Se a expressão avaliada for zero \(false\), o parâmetro `string-literal` será exibido e a compilação falhará com um erro.  Se a expressão for diferente de zero \(true\), a declaração `static_assert` não terá efeito.|  
|`string-literal`|Uma mensagem que é exibida se o parâmetro `constant-expression` for zero.  A mensagem é uma cadeia de caracteres no [conjunto de caracteres de base](../c-language/ascii-character-set.md) do compilador; isto é, não [caracteres multibyte ou largos](../Topic/Multibyte%20and%20Wide%20Characters.md).|  
  
## Comentários  
 O parâmetro `constant-expression` de uma declaração `static_assert` representa uma *asserção de software*.  Uma asserção de software especifica uma condição que você espera ser verdadeira \(true\) em um ponto específico de seu programa.  Se a condição for true, a declaração `static_assert` não terá efeito.  Se a condição for false, a declaração falhará, e o compilador exibirá a mensagem no parâmetro `string-literal` e a compilação falhará com um erro.  
  
 A declaração `static_assert` testa uma asserção de software no tempo de compilação.  Ao contrário, a macro [Macro Assert, \_wassert de declaração](../c-runtime-library/reference/assert-macro-assert-wassert.md) testa uma asserção de software no tempo de execução e incorre em um custo de tempo de execução em espaço ou tempo.  A declaração `static_assert` é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos no parâmetro `constant-expression`.  
  
 O compilador examina a declaração `static_assert` para erros de sintaxe quando a declaração é encontrada.  O compilador avalia o parâmetro `constant-expression` imediatamente se ele não depende de um parâmetro de modelo.  Caso contrário, o compilador avalia o parâmetro `constant-expression` quando o modelo é instanciado.  Consequentemente, o compilador pode emitir uma mensagem de diagnóstico uma vez quando a declaração for encontrada e novamente quando o modelo for instanciado.  
  
 Você pode usar a palavra\-chave `static_assert` no escopo de namespace, classe ou bloco. \(A palavra\-chave `static_assert` é tecnicamente uma declaração, mesmo que não apresente o novo nome em seu programa, porque pode ser usado no escopo de namespace.\)  
  
## Descrição  
 No exemplo a seguir, a declaração `static_assert` tem um escopo de namespace.  Como o compilador conhece o tamanho do tipo `void *`, a expressão é avaliada imediatamente.  
  
## Exemplo  
  
```  
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");  
```  
  
## Descrição  
 No exemplo a seguir, a declaração `static_assert` tem escopo de classe.  O `static_assert` verifica que um parâmetro do modelo é um tipo de *dados antigos simples* \(POD\).  O compilador examina a declaração `static_assert` quando ele é declarado, mas não avalia o parâmetro `constant-expression` até que o modelo de classe `basic_string` seja instanciado em `main()`.  
  
## Exemplo  
  
```  
#include <type_traits>  
#include <iosfwd>  
namespace std {  
template <class CharT, class Traits = std::char_traits<CharT> >  
class basic_string {  
    static_assert(tr1::is_pod<CharT>::value,  
                  "Template argument CharT must be a POD type in class template basic_string");  
    // ...  
    };  
}  
struct NonPOD {  
    NonPOD(const NonPOD &) {}  
    virtual ~NonPOD() {}  
};  
int main()  
{  
    std::basic_string<char> bs;  
}  
```  
  
## Descrição  
 No exemplo a seguir, a declaração `static_assert` tem escopo de bloco.  O `static_assert` verifica se o tamanho da estrutura VMPage é igual ao tamanho da página da memória virtual do sistema.  
  
## Exemplo  
  
```  
#include <sys/param.h> // defines PAGESIZE  
class VMMClient {  
public:  
    struct VMPage { // ...   
           };  
    int check_pagesize() {  
    static_assert(sizeof(VMPage) == PAGESIZE,  
        "Struct VMPage must be the same size as a system virtual memory page.");  
    // ...  
    }  
// ...  
};  
```  
  
## Consulte também  
 [Asserção e mensagens fornecidas pelo usuário \(C\+\+\)](../cpp/assertion-and-user-supplied-messages-cpp.md)   
 [Diretiva \#error](../preprocessor/hash-error-directive-c-cpp.md)   
 [Macro Assert, \_wassert de declaração](../c-runtime-library/reference/assert-macro-assert-wassert.md)   
 [Modelos](../Topic/Templates%20\(C++\).md)   
 [Conjunto de caracteres ASCII](../c-language/ascii-character-set.md)   
 [Declarações](../misc/declarations.md)