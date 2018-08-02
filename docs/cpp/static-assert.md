---
title: static_assert | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- static_assert_cpp
dev_langs:
- C++
helpviewer_keywords:
- C++ keywords, static_assert
- C2338
- assertions [C++], static_assert
- static_assert
ms.assetid: 28dd3668-e78c-4de8-ba68-552084743426
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6fa9b8fb7fe85aca21e90195534f33201bee59fc
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39464928"
---
# <a name="staticassert"></a>static_assert
Testa uma asserção de software no tempo de compilação. Se a expressão constante especificada for FALSE, o compilador exibirá a mensagem especificada, se uma for fornecida, e a compilação falhará com o erro C2338; Caso contrário, a declaração não tem efeito.  
  
## <a name="syntax"></a>Sintaxe  
  
```   
static_assert( constant-expression, string-literal );  

**Visual Studio 2017 and later:**
static_assert( constant-expression ); 
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*constant-expression*|Uma expressão constante integral que pode ser convertida em um valor booliano.<br /><br /> Se a expressão avaliada for zero (false), o *literal de cadeia de caracteres* parâmetro é exibido e a compilação falhará com um erro. Se a expressão for diferente de zero (verdadeiro), o **static_assert** declaração não tem nenhum efeito.|  
|*string-literal*|Uma mensagem que será exibida se o *expressão-constante* parâmetro for zero. A mensagem é uma cadeia de caracteres na [conjunto de caracteres de base](../c-language/ascii-character-set.md) de compilador; isto é, não [caracteres multibyte ou largos](../c-language/multibyte-and-wide-characters.md).|  
  
## <a name="remarks"></a>Comentários  
 O *expressão-constante* parâmetro de uma **static_assert** declaração representa uma *asserção de software*. Uma asserção de software especifica uma condição que você espera ser verdadeira (true) em um ponto específico de seu programa. Se a condição for true, o **static_assert** declaração não tem nenhum efeito. Se a condição for falsa, a asserção falhará, o compilador exibirá a mensagem na *literal de cadeia de caracteres* parâmetro e a compilação falhará com um erro. No Visual Studio 2017 e versões posteriores, o parâmetro de cadeia de caracteres literal é opcional. 
  
 O **static_assert** declaração testa uma asserção de software no tempo de compilação. Em contraste, o [assert Macro, Assert, wassert](../c-runtime-library/reference/assert-macro-assert-wassert.md) macro testa uma asserção de software no tempo de execução e incorre em um custo de tempo de execução em espaço ou tempo. O **static_assert** declaração é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos na *expressão de constante* parâmetro.  
  
 O compilador examina a **static_assert** declaração para erros de sintaxe quando a declaração é encontrada. O compilador avalia a *expressão-constante* parâmetro imediatamente se ele não depende de um parâmetro de modelo. Caso contrário, o compilador avalia a *expressão-constante* parâmetro quando o modelo é instanciado. Consequentemente, o compilador pode emitir uma mensagem de diagnóstico uma vez quando a declaração for encontrada e novamente quando o modelo for instanciado.  
  
 Você pode usar o **static_assert** palavra-chave no namespace, classe ou no escopo de bloco. (O **static_assert** palavra-chave é tecnicamente uma declaração, mesmo que ele apresente o novo nome para o programa, porque ele pode ser usado no escopo do namespace.)  
  
## <a name="description"></a>Descrição  
 No exemplo a seguir, o **static_assert** declaração tem escopo de namespace. Como o compilador conhece o tamanho do tipo `void *`, a expressão é avaliada imediatamente.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");  
```  
  
## <a name="description"></a>Descrição  
 No exemplo a seguir, o **static_assert** declaração tem escopo de classe. O **static_assert** verifica se um parâmetro de modelo é um *dados antigos simples* tipo (POD). O compilador examina a **static_assert** declaração quando ele é declarado, mas não avalia a *expressão de constante* parâmetro até que o `basic_string` modelo de classe é instanciado no `main()`.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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
 No exemplo a seguir, o **static_assert** declaração tem escopo de bloco. O **static_assert** verifica se o tamanho da estrutura VMPage é igual a memória virtual pagesize do sistema.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
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