---
title: Opções de compilador Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
f1_keywords:
- _ATL_ALL_WARNINGS
- _ATL_APARTMENT_THREADED
- '_ATL_CSTRING_EXPLICIT_CONSTRUCTORS '
- _ATL_ENABLE_PTM_WARNING
- _ATL_FREE_THREADED
- _ATL_MULTI_THREADED
- _ATL_NO_AUTOMATIC_NAMESPACE
- _ATL_NO_COM_SUPPORT
- ATL_NO_VTABLE
- ATL_NOINLINE
- _ATL_SINGLE_THREADED
helpviewer_keywords:
- compiler options, macros
ms.assetid: a869adc6-b3de-4299-b040-9ae20b45f82c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e84c92e8bbf65ff3b8b54111bcce2306628edb1
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="compiler-options-macros"></a>Opções de compilador Macros
Essas macros controlam os recursos do compilador específico.  
  
|||  
|-|-|  
|[_ATL_ALL_WARNINGS](#_atl_all_warnings)|Um símbolo que permite que os erros em projetos foram convertidos de versões anteriores do ATL|  
|[ATL_APARTMENT_THREADED](#_atl_apartment_threaded)|Defina se um ou mais dos seus objetos usam apartment threading.|  
|[_ATL_CSTRING_EXPLICIT_CONSTRUCTORS](#_atl_cstring_explicit_constructors)|Faz com que determinados `CString` construtores explícitos, impedindo que qualquer conversão não intencional.|  
|[_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning)|Defina esta macro para usar a sintaxe de conformidade padrão C++, que gera o erro do compilador C4867 quando uma sintaxe padrão não é usada para inicializar um ponteiro para uma função de membro.|  
|[ATL_FREE_THREADED](#_atl_free_threaded)|Defina se um ou mais dos seus objetos de threading livre ou neutro de usar.|  
|[_ATL_MULTI_THREADED](#_atl_multi_threaded)|Um símbolo que indica o projeto terá objetos que são marcados como ambos, livre ou neutro. A macro [atl_free_threaded](#_atl_free_threaded) deve ser usado em vez disso.|  
|[_ATL_NO_AUTOMATIC_NAMESPACE](#_atl_no_automatic_namespace)|Um símbolo que impede o uso padrão do namespace como ATL.|  
|[_ATL_NO_COM_SUPPORT](#_atl_no_com_support)|Um símbolo que impede que o código relacionado ao COM sendo compilado com o seu projeto.|  
|[ATL_NO_VTABLE](#atl_no_vtable)|Um símbolo que impede que o ponteiro vtable está sendo inicializado no construtor da classe e o destruidor.|  
|[ATL_NOINLINE](#atl_noinline)|Um símbolo que indica uma função não deve ser embutido.|  
|[ATL_SINGLE_THREADED](#_atl_single_threaded)|Defina se todos os seus objetos de usam o modelo de threading único.|  
  
##  <a name="_atl_all_warnings"></a>  _ATL_ALL_WARNINGS  
 Um símbolo que permite que os erros em projetos foram convertidos de versões anteriores do ATL  
  
```
#define _ATL_ALL_WARNINGS
```  
  
### <a name="remarks"></a>Comentários  
 Antes de Visual C++ .NET 2002 ATL desabilitado muita avisos e deixou desativado para que eles nunca aparecem no código do usuário. Especificamente:  
  
-   Expressão condicional C4127 é constante  
  
-   Identificador' C4786': identificador foi truncado para 'número' caracteres as informações de depuração  
  
-   C4201 extensão não padrão usada: struct/union sem nome  
  
-   C4103 'filename': usado #pragma pack para alterar alinhamento  
  
-   C4291 'declaration': Nenhum operador delete correspondente encontrado; memória não será liberada se inicialização lançar uma exceção  
  
-   Identificador' C4268': 'const' dados static/globais inicializados com o construtor do padrão gerado pelo compilador preenche o objeto com zeros  
  
-   Código inacessível C4702  
  
 Em projetos foram convertidos de versões anteriores, esses avisos ainda estão desabilitados, os cabeçalhos de bibliotecas.  
  
 Adicionando a seguinte linha ao arquivo Stdafx. h antes de incluir cabeçalhos de bibliotecas, esse comportamento pode ser alterado.  
  
 [!code-cpp[NVC_ATL_Utilities#97](../../atl/codesnippet/cpp/compiler-options-macros_1.h)]  
  
 Se este `#define` é adicionado, os cabeçalhos ATL tenha o cuidado de preservar o estado desses avisos para que eles não estão desabilitados globalmente (ou se o usuário explicitamente desabilita avisos individuais, não para habilitá-los).  
  
 Novos projetos com este `#define` definido em Stdafx. h, por padrão.  
  
##  <a name="_atl_apartment_threaded"></a>  ATL_APARTMENT_THREADED  
 Defina se um ou mais dos seus objetos usam apartment threading.  
  
```
_ATL_APARTMENT_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Especifica apartment threading. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, o Assistente de objeto ATL simples](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.  
  
##  <a name="_atl_cstring_explicit_constructors"></a>  _ATL_CSTRING_EXPLICIT_CONSTRUCTORS  
 Faz com que determinados `CString` construtores explícitos, impedindo que qualquer conversão não intencional.  
  
```
_ATL_CSTRING_EXPLICIT_CONSTRUCTORS
```  
  
### <a name="remarks"></a>Comentários  
 Quando isso for definido, todos os construtores de CString que usam um único parâmetro são compilados com a palavra-chave explicit, que impede a conversões implícitas de argumentos de entrada. Isso significa, por exemplo, que quando Unicode é definida, se você tentar usar uma char * cadeia de caracteres como um argumento de construtor CString, compilador ocorrerá um erro. Use esta macro em situações em que você precisa impedir conversões implícitas entre tipos de cadeia de caracteres largos e estreitos.  
  
 Ao usar a macro t em todos os argumentos de cadeia de caracteres de construtor, você pode definir _ATL_CSTRING_EXPLICIT_CONSTRUCTORS e evitar erros de compilação, independentemente se Unicode estiver definido.  
  
##  <a name="_atl_enable_ptm_warning"></a>  _ATL_ENABLE_PTM_WARNING  
 Defina esta macro para forçar o uso da sintaxe de C++ ANSI compatíveis com o padrão de ponteiro para funções de membro. Usar esta macro fará com que o erro do compilador C4867 será gerado quando a sintaxe não padrão é usado para inicializar um ponteiro para uma função de membro.  
  
```
#define _ATL_ENABLE_PTM_WARNING
```  
  
### <a name="remarks"></a>Comentários  
 As bibliotecas ATL e MFC foram alteradas para que corresponda melhor conformidade de C++ padrão do compilador Visual C++. Acordo com o padrão ANSI C++, a sintaxe de um ponteiro para uma função de membro de classe deve ser `&CMyClass::MyFunc`.  
  
 Quando [_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning) não está definido (no caso padrão), ATL/MFC desabilita o erro C4867 em mapas de macro (especialmente mensagem mapeia) para que o código que foi criado em versões anteriores pode continuar a criar como antes. Se você definir **_ATL_ENABLE_PTM_WARNING**, seu código deve ser o padrão de C++ compatível.  
  
 No entanto, o formulário não-padrão foi preterido, para que seja necessário mover o código existente para sintaxe de conformidade padrão do C++. Por exemplo, o seguinte:  
  
 [!code-cpp[NVC_MFCListView#14](../../atl/reference/codesnippet/cpp/compiler-options-macros_2.cpp)]  
  
 Deve ser alterada para:  
  
 [!code-cpp[NVC_MFCListView#11](../../atl/reference/codesnippet/cpp/compiler-options-macros_3.cpp)]  
  
 Observe que para macros de mapa que adiciona o caractere '&', você não deve adicioná-lo novamente no seu código.  
  
##  <a name="_atl_free_threaded"></a>  ATL_FREE_THREADED  
 Defina se um ou mais dos seus objetos de threading livre ou neutro de usar.  
  
```
_ATL_FREE_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Especifica o thread livre. Thread livre equivale a um modelo de apartment com vários threads. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, o Assistente de objeto ATL simples](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.  
  
##  <a name="_atl_multi_threaded"></a>  _ATL_MULTI_THREADED  
 Um símbolo que indica o projeto terá objetos que são marcados como ambos, livre ou neutro.  
  
```
_ATL_MULTI_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Se este símbolo for definido, ATL extrairá no código que será sincronizado corretamente o acesso aos dados globais. Novo código deve usar a macro equivalente [atl_free_threaded](#_atl_free_threaded) em vez disso.  
  
##  <a name="_atl_no_automatic_namespace"></a>  _ATL_NO_AUTOMATIC_NAMESPACE  
 Um símbolo que impede o uso padrão do namespace como ATL.  
  
```
_ATL_NO_AUTOMATIC_NAMESPACE
```  
  
### <a name="remarks"></a>Comentários  
 Se este símbolo não for definido, incluindo atlbase irá realizar **usando namespace ATL** por padrão, o que pode levar a conflitos de nomenclatura. Para evitar isso, defina este símbolo.  
  
##  <a name="_atl_no_com_support"></a>  _ATL_NO_COM_SUPPORT  
 Um símbolo que impede que o código relacionado ao COM sendo compilado com o seu projeto.  
  
```
_ATL_NO_COM_SUPPORT```  
  
##  <a name="atl_no_vtable"></a>  ATL_NO_VTABLE  
 A symbol that prevents the vtable pointer from being initialized in the class's constructor and destructor.  
  
```
ATL_NO_VTABLE
```  
  
### Remarks  
 If the vtable pointer is prevented from being initialized in the class's constructor and destructor, the linker can eliminate the vtable and all of the functions to which it points. Expands to **__declspec(novtable)**.  
  
### Example  
 [!code-cpp[NVC_ATL_COM#53](../../atl/codesnippet/cpp/compiler-options-macros_4.h)]  
  
##  <a name="atl_noinline"></a>  ATL_NOINLINE  
 A symbol that indicates a function should not be inlined.  
  
```
    ATL_NOINLINE inline
    myfunction
 { ... }
```  
  
### Parameters  
 *myfunction*  
 The function that should not be inlined.  
  
### Remarks  
 Use this symbol if you want to ensure a function does not get inlined by the compiler, even though it must be declared as inline so that it can be placed in a header file. Expands to **__declspec(noinline)**.  
  
##  <a name="_atl_single_threaded"></a>  _ATL_SINGLE_THREADED  
 Define if all of your objects use the single threading model  
  
```
ATL_SINGLE_THREADED
```  
  
### Remarks  
 Specifies that the object always runs in the primary COM thread. See [Specifying the Project's Threading Model](../../atl/specifying-the-threading-model-for-a-project-atl.md) for other threading options, and [Options, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) for a description of the threading models available for an ATL object.  
  
## See Also  
 [Macros](../../atl/reference/atl-macros.md)
