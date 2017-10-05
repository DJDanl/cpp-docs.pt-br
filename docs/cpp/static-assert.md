---
title: static_assert | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- C2338
- static_assert_cpp
- static_assert
dev_langs:
- C++
helpviewer_keywords:
- C++ keywords, static_assert
- C2338
- assertions [C++], static_assert
- static_assert
ms.assetid: 28dd3668-e78c-4de8-ba68-552084743426
caps.latest.revision: 9
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
ms.openlocfilehash: 1428d890fe079c7ac1fce175686e9776f9c21746
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="staticassert"></a>static_assert
Testa uma asserção de software no tempo de compilação. Se a expressão de constante especificada é `false`, o compilador exibe a mensagem especificada, se houver e a compilação falha com erro C2338; caso contrário, a declaração não tem nenhum efeito.  
  
## <a name="syntax"></a>Sintaxe  
  
```   
static_assert( constant-expression, string-literal );  

**Visual Studio 2017 and later:**
static_assert( constant-expression ); 
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`constant-expression`|Uma expressão constante integral que pode ser convertida em um valor booliano.<br /><br /> Se a expressão avaliada for zero (false), o parâmetro `string-literal` será exibido e a compilação falhará com um erro. Se a expressão for diferente de zero (true), a declaração `static_assert` não terá efeito.|  
|`string-literal`|Uma mensagem que é exibida se o parâmetro `constant-expression` for zero. A mensagem é uma cadeia de caracteres a [basear o conjunto de caracteres](../c-language/ascii-character-set.md) do compilador; não [caracteres multibyte ou amplas](../c-language/multibyte-and-wide-characters.md).|  
  
## <a name="remarks"></a>Comentários  
 O `constant-expression` parâmetro de um `static_assert` declaração representa uma *asserção de software*. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se a condição for true, a declaração `static_assert` não terá efeito. Se a condição for false, a declaração falhará, e o compilador exibirá a mensagem no parâmetro `string-literal` e a compilação falhará com um erro. No Visual Studio de 2017 e posterior, o parâmetro de cadeia de caracteres literal é opcional. 
  
 A declaração `static_assert` testa uma asserção de software no tempo de compilação. Em contraste, o [assert Macro Assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro testa uma asserção de software em tempo de execução e incorre em um custo de tempo de execução na hora ou espaço. A declaração `static_assert` é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos no parâmetro `constant-expression`.  
  
 O compilador examina a declaração `static_assert` para erros de sintaxe quando a declaração é encontrada. O compilador avalia o parâmetro `constant-expression` imediatamente se ele não depende de um parâmetro de modelo. Caso contrário, o compilador avalia o parâmetro `constant-expression` quando o modelo é instanciado. Consequentemente, o compilador pode emitir uma mensagem de diagnóstico uma vez quando a declaração for encontrada e novamente quando o modelo for instanciado.  
  
 Você pode usar a palavra-chave `static_assert` no escopo de namespace, classe ou bloco. (A palavra-chave `static_assert` é tecnicamente uma declaração, mesmo que não apresente o novo nome em seu programa, porque pode ser usado no escopo de namespace.)  
  
## <a name="description"></a>Descrição  
 No exemplo a seguir, a declaração `static_assert` tem um escopo de namespace. Como o compilador conhece o tamanho do tipo `void *`, a expressão é avaliada imediatamente.  
  
## <a name="example"></a>Exemplo  
  
```  
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");  
```  
  
## <a name="description"></a>Descrição  
 No exemplo a seguir, a declaração `static_assert` tem escopo de classe. O `static_assert` verifica se um parâmetro de modelo é um *dados antigos simples* tipo (POD). O compilador examina a declaração `static_assert` quando ele é declarado, mas não avalia o parâmetro `constant-expression` até que o modelo de classe `basic_string` seja instanciado em `main()`.  
  
## <a name="example"></a>Exemplo  
  
```  
#include <type_traits>  
#include <iosfwd>  
namespace std {  
template <class CharT, class Traits = std::char_traits<CharT> >  
class basic_string {  
    static_assert(std::is_pod<CharT>::value,  
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
  
## <a name="description"></a>Descrição  
 No exemplo a seguir, a declaração `static_assert` tem escopo de bloco. O `static_assert` verifica se o tamanho da estrutura VMPage é igual ao tamanho da página da memória virtual do sistema.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Asserção e mensagens fornecidas pelo usuário (C++)](../cpp/assertion-and-user-supplied-messages-cpp.md)   
 [#error diretiva (C/C++)](../preprocessor/hash-error-directive-c-cpp.md)   
 [assert Macro, _assert, _wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md)   
 [Modelos](../cpp/templates-cpp.md)   
 [Conjunto de caracteres ASCII](../c-language/ascii-character-set.md)   
 [Declarações e definições](declarations-and-definitions-cpp.md)
