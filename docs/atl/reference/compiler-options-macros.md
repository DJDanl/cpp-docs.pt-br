---
title: "Opções de compilador Macros | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- compiler options, macros
ms.assetid: a869adc6-b3de-4299-b040-9ae20b45f82c
caps.latest.revision: 17
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: dbce962873194c1bdcb063537247650cff568e35
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-options-macros"></a>Opções de compilador Macros
Essas macros controlam recursos específicos do compilador.  
  
|||  
|-|-|  
|[_ATL_ALL_WARNINGS](#_atl_all_warnings)|Um símbolo que permite que os erros em projetos convertidos de versões anteriores do ATL.|  
|[ATL_APARTMENT_THREADED](#_atl_apartment_threaded)|Defina se um ou mais dos seus objetos usam apartment threading.|  
|[_ATL_CSTRING_EXPLICIT_CONSTRUCTORS](#_atl_cstring_explicit_constructors)|Faz com que determinados `CString` construtores explícitos, impedindo que qualquer conversões não intencionais.|  
|[_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning)|Defina esta macro para usar a sintaxe de conformidade padrão C++, que gera o erro do compilador C4867 quando uma sintaxe padrão não é usada para inicializar um ponteiro para uma função de membro.|  
|[ATL_FREE_THREADED](#_atl_free_threaded)|Defina se um ou mais dos seus objetos usam o threading livre ou neutro.|  
|[_ATL_MULTI_THREADED](#_atl_multi_threaded)|Um símbolo que indica o projeto terá objetos marcados como ambos, livre ou neutro. A macro [atl_free_threaded](#_atl_free_threaded) deve ser usada em vez disso.|  
|[_ATL_NO_AUTOMATIC_NAMESPACE](#_atl_no_automatic_namespace)|Um símbolo que impede o uso padrão do namespace como ATL.|  
|[_ATL_NO_COM_SUPPORT](#_atl_no_com_support)|Um símbolo que impede que o código relacionado COM sendo compilado com o seu projeto.|  
|[ATL_NO_VTABLE](#atl_no_vtable)|Um símbolo que impede que o ponteiro vtable está sendo inicializada no construtor e destruidor da classe.|  
|[ATL_NOINLINE](#atl_noinline)|Um símbolo que indica uma função não deve ser embutido.|  
|[ATL_SINGLE_THREADED](#_atl_single_threaded)|Defina se todos os seus objetos usam o modelo de threading único.|  
  
##  <a name="_atl_all_warnings"></a>_ATL_ALL_WARNINGS  
 Um símbolo que permite que os erros em projetos convertidos de versões anteriores do ATL.  
  
```
#define _ATL_ALL_WARNINGS
```  
  
### <a name="remarks"></a>Comentários  
 Antes do Visual C++ .NET 2002, ATL desabilitado muitos avisos e deixou desativado de modo que eles nunca aparecem no código do usuário. Especificamente:  
  
-   Expressão condicional C4127 é constante  
  
-   C4786 'identifier': identificador foi truncado para caracteres 'number' nas informações de depuração  
  
-   C4201 extensão não padrão usada: estrutura/União sem nome  
  
-   C4103 'filename': usado #pragma pack para alterar o alinhamento  
  
-   Declaração' C4291': Nenhum operador delete correspondente encontrado; memória não será liberada se a inicialização lança uma exceção  
  
-   C4268 'identifier': '' estático/global dados inicializados com o construtor de padrão gerado pelo compilador preenche o objeto com zeros  
  
-   Código inacessível C4702  
  
 Em projetos convertidos de versões anteriores, esses avisos ainda estão desabilitados por cabeçalhos de bibliotecas.  
  
 Adicionando a seguinte linha ao arquivo Stdafx. h antes de incluir cabeçalhos de bibliotecas, esse comportamento pode ser alterado.  
  
 [!code-cpp[NVC_ATL_Utilities&#97;](../../atl/codesnippet/cpp/compiler-options-macros_1.h)]  
  
 Se este `#define` é adicionado, os cabeçalhos ATL tenha o cuidado de preservar o estado desses avisos, para que eles não estão desabilitados globalmente (ou se o usuário explicitamente desativa avisos individuais, não para habilitá-los).  
  
 Novos projetos gerados com o Visual C++ .NET 2002 terão essa `#define` definidos no Stdafx. h por padrão.  
  
##  <a name="_atl_apartment_threaded"></a>ATL_APARTMENT_THREADED  
 Defina se um ou mais dos seus objetos usam apartment threading.  
  
```
_ATL_APARTMENT_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Especifica apartment threading. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.  
  
##  <a name="_atl_cstring_explicit_constructors"></a>_ATL_CSTRING_EXPLICIT_CONSTRUCTORS  
 Faz com que determinados `CString` construtores explícitos, impedindo que qualquer conversões não intencionais.  
  
```
_ATL_CSTRING_EXPLICIT_CONSTRUCTORS
```  
  
### <a name="remarks"></a>Comentários  
 Quando isso é definido, todos os construtores de CString que usam um único parâmetro são compilados com a palavra-chave explicit, que impede que as conversões implícitas de argumentos de entrada. Isso significa, por exemplo, que quando Unicode estiver definido, se você tentar usar uma char * cadeia de caracteres como argumento de construtor CString, um erro do compilador resulta. Use esta macro em situações onde você precisa impedir conversões implícitas entre tipos de cadeia de caracteres estreita e grande.  
  
 Usando a macro t em todos os argumentos de cadeia de caracteres de construtor, você pode definir _ATL_CSTRING_EXPLICIT_CONSTRUCTORS e evitar erros de compilação, independentemente se Unicode estiver definido.  
  
##  <a name="_atl_enable_ptm_warning"></a>_ATL_ENABLE_PTM_WARNING  
 Defina esta macro para forçar o uso da sintaxe compatível com o padrão ANSI C++ de ponteiro para funções de membro. Usar essa macro causará o erro do compilador C4867 seja gerado quando a sintaxe não-padrão é usado para inicializar um ponteiro para uma função de membro.  
  
```
#define _ATL_ENABLE_PTM_WARNING
```  
  
### <a name="remarks"></a>Comentários  
 As bibliotecas MFC e ATL foram alteradas para corresponder melhor conformidade de C++ padrão do compilador do Visual C++. Segundo o padrão ANSI C++, a sintaxe de um ponteiro para uma função de membro de classe deve ser `&CMyClass::MyFunc`.  
  
 Quando [_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning) não está definido (caso padrão), ATL/MFC desabilita o erro C4867 em mapas de macro (notavelmente mensagem mapeia) para que o código que foi criado em versões anteriores pode continuar a compilação como antes. Se você definir **_ATL_ENABLE_PTM_WARNING**, seu código deve ser o padrão de C++ compatível.  
  
 No entanto, o formulário não-padrão foi substituído, então você precisa mover o código existente para sintaxe de conformidade padrão C++. Por exemplo, o seguinte:  
  
 [!code-cpp[NVC_MFCListView&#14;](../../atl/reference/codesnippet/cpp/compiler-options-macros_2.cpp)]  
  
 Deve ser alterada para:  
  
 [!code-cpp[NVC_MFCListView n º&11;](../../atl/reference/codesnippet/cpp/compiler-options-macros_3.cpp)]  
  
 Observe que para as macros de mapa que adicionam o caractere '< /', você não deve adicioná-lo novamente no seu código.  
  
##  <a name="_atl_free_threaded"></a>ATL_FREE_THREADED  
 Defina se um ou mais dos seus objetos usam o threading livre ou neutro.  
  
```
_ATL_FREE_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Especifica o thread livre. Thread livre equivale a um modelo de apartment com vários threads. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.  
  
##  <a name="_atl_multi_threaded"></a>_ATL_MULTI_THREADED  
 Um símbolo que indica o projeto terá objetos marcados como ambos, livre ou neutro.  
  
```
_ATL_MULTI_THREADED
```  
  
### <a name="remarks"></a>Comentários  
 Se esse símbolo é definido, ATL efetuará a recepção no código que serão sincronizados corretamente o acesso aos dados globais. Novo código deve usar a macro equivalente [atl_free_threaded](#_atl_free_threaded) em vez disso.  
  
##  <a name="_atl_no_automatic_namespace"></a>_ATL_NO_AUTOMATIC_NAMESPACE  
 Um símbolo que impede o uso padrão do namespace como ATL.  
  
```
_ATL_NO_AUTOMATIC_NAMESPACE
```  
  
### <a name="remarks"></a>Comentários  
 Se esse símbolo não for definido, incluindo atlbase. h irá executar **usando o namespace ATL** por padrão, o que pode levar a conflitos de nomenclatura. Para evitar isso, defina esse símbolo.  
  
##  <a name="_atl_no_com_support"></a>_ATL_NO_COM_SUPPORT  
 Um símbolo que impede que o código relacionado COM sendo compilado com o seu projeto.  
  
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

