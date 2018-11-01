---
title: Macros de opções do compilador
ms.date: 11/04/2016
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
ms.openlocfilehash: d0da6ebcb178735fc25c656241fe23497d941ab6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50631147"
---
# <a name="compiler-options-macros"></a>Macros de opções do compilador

Essas macros controlam os recursos de compilador específica.

|||
|-|-|
|[_ATL_ALL_WARNINGS](#_atl_all_warnings)|Um símbolo que habilita os erros em projetos convertidos de versões anteriores do ATL.|
|[ATL_APARTMENT_THREADED](#_atl_apartment_threaded)|Defina se um ou mais dos seus objetos usam apartamento de threading.|
|[_ATL_CSTRING_EXPLICIT_CONSTRUCTORS](#_atl_cstring_explicit_constructors)|Faz com que determinados `CString` construtores explícitos, impedindo que as conversões não intencionais.|
|[_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning)|Defina essa macro para usar a sintaxe de conformidade padrão C++, que gera o erro do compilador C4867 quando uma sintaxe padrão não é usada para inicializar um ponteiro para uma função de membro.|
|[ATL_FREE_THREADED](#_atl_free_threaded)|Defina se um ou mais dos seus objetos usam threading livre ou neutra.|
|[_ATL_MULTI_THREADED](#_atl_multi_threaded)|Um símbolo que indica o projeto terá objetos que são marcados como "ambas", gratuito ou neutra. A macro [atl_free_threaded](#_atl_free_threaded) deve ser usado em vez disso.|
|[_ATL_NO_AUTOMATIC_NAMESPACE](#_atl_no_automatic_namespace)|Um símbolo que impede o uso do padrão de namespace como ATL.|
|[_ATL_NO_COM_SUPPORT](#_atl_no_com_support)|Um símbolo que impede que o código relacionado ao COM que está sendo compilado com o seu projeto.|
|[ATL_NO_VTABLE](#atl_no_vtable)|Um símbolo que impede que o ponteiro vtable que está sendo inicializado no construtor e o destruidor da classe.|
|[ATL_NOINLINE](#atl_noinline)|Um símbolo que indica uma função não deve ser embutido.|
|[ATL_SINGLE_THREADED](#_atl_single_threaded)|Defina se todos os seus objetos usam o modelo de threading único.|

##  <a name="_atl_all_warnings"></a>  _ATL_ALL_WARNINGS

Um símbolo que habilita os erros em projetos convertidos de versões anteriores do ATL.

```
#define _ATL_ALL_WARNINGS
```

### <a name="remarks"></a>Comentários

Antes do Visual C++ .NET 2002, o ATL desabilitado muitos avisos e deixou desativada para que eles nunca aparecem no código do usuário. Especificamente:

- C4127 de expressão condicional é constante

- C4786 'identifier': identificador foi truncado para caracteres 'number' nas informações de depuração

- Extensão não padrão de C4201 usada: struct/union sem nome

- C4103 'filename': usado #pragma pack para alterar o alinhamento

- C4291 'declaração': Nenhum operador delete encontrado; memória não será liberada se inicialização lançar uma exceção

- C4268 'identifier': 'const' dados estático/global inicializados com o construtor de padrão gerado pelo compilador preenche o objeto com zeros

- Código inacessível de C4702

Em projetos convertidos de versões anteriores, esses avisos ainda estão desabilitados por cabeçalhos de bibliotecas.

Adicionando a seguinte linha ao arquivo Stdafx. h antes de incluir cabeçalhos de bibliotecas, esse comportamento pode ser alterado.

[!code-cpp[NVC_ATL_Utilities#97](../../atl/codesnippet/cpp/compiler-options-macros_1.h)]

Se este `#define` é adicionado, os cabeçalhos ATL tenha o cuidado de preservar o estado desses avisos, para que eles não estão desabilitados globalmente (ou se o usuário explicitamente desabilita avisos individuais, não para habilitá-los).

Novos projetos tem isso `#define` definido em Stdafx. h, por padrão.

##  <a name="_atl_apartment_threaded"></a>  ATL_APARTMENT_THREADED

Defina se um ou mais dos seus objetos usam apartamento de threading.

```
_ATL_APARTMENT_THREADED
```

### <a name="remarks"></a>Comentários

Especifica o apartment threading. Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.

##  <a name="_atl_cstring_explicit_constructors"></a>  _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

Faz com que determinados `CString` construtores explícitos, impedindo que as conversões não intencionais.

```
_ATL_CSTRING_EXPLICIT_CONSTRUCTORS
```

### <a name="remarks"></a>Comentários

Quando isso for definido, todos os construtores CString que utilizam um parâmetro único são compilados com a palavra-chave explícita, que impede que as conversões implícitas de argumentos de entrada. Isso significa, por exemplo, que quando Unicode estiver definido, se você tentar usar uma char * cadeia de caracteres como um argumento do construtor CString, um erro do compilador resultará. Use este macro em situações em que você precisa evitar conversões implícitas entre tipos de cadeia de caracteres estreitos e largos.

Usando a macro t em todos os argumentos de cadeia de caracteres do construtor, você pode definir _ATL_CSTRING_EXPLICIT_CONSTRUCTORS e evitar erros de compilação, independentemente se Unicode estiver definido.

##  <a name="_atl_enable_ptm_warning"></a>  _ATL_ENABLE_PTM_WARNING

Defina essa macro para forçar o uso da sintaxe de C++ ANSI compatíveis com o padrão de ponteiro para funções de membro. Usar essa macro fará com que o erro do compilador C4867 ser gerada quando a sintaxe não padrão é usada para inicializar um ponteiro para uma função de membro.

```
#define _ATL_ENABLE_PTM_WARNING
```

### <a name="remarks"></a>Comentários

As bibliotecas ATL e MFC foram alteradas para corresponder melhor conformidade de C++ padrão do compilador Visual C++. Segundo o padrão ANSI C++, a sintaxe de um ponteiro para uma função de membro de classe deve ser `&CMyClass::MyFunc`.

Quando [_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning) não está definido (o caso padrão), ATL/MFC desabilita o erro C4867 em mapas de macro (particularmente mensagem mapeia) para que o código que foi criado em versões anteriores pode continuar a compilação como antes. Se você definir **_ATL_ENABLE_PTM_WARNING**, seu código deve ser o padrão de C++ em conformidade.

No entanto, o formulário não-padrão foi preterido, portanto, você precisará mover o código existente para sintaxe de conformidade padrão C++. Por exemplo, o seguinte:

[!code-cpp[NVC_MFCListView#14](../../atl/reference/codesnippet/cpp/compiler-options-macros_2.cpp)]

Deve ser alterada para:

[!code-cpp[NVC_MFCListView#11](../../atl/reference/codesnippet/cpp/compiler-options-macros_3.cpp)]

Observe que para as macros de mapa que adiciona o caractere '&', você deve não adicioná-lo novamente no seu código.

##  <a name="_atl_free_threaded"></a>  ATL_FREE_THREADED

Defina se um ou mais dos seus objetos usam threading livre ou neutra.

```
_ATL_FREE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica o threading livre. Threading livre é equivalente a um modelo de apartment com vários threads. Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.

##  <a name="_atl_multi_threaded"></a>  _ATL_MULTI_THREADED

Um símbolo que indica o projeto terá objetos que são marcados como "ambas", gratuito ou neutra.

```
_ATL_MULTI_THREADED
```

### <a name="remarks"></a>Comentários

Se esse símbolo é definido, o ATL efetuará pull no código que será sincronizado corretamente o acesso aos dados globais. Novo código deve usar a macro equivalente [atl_free_threaded](#_atl_free_threaded) em vez disso.

##  <a name="_atl_no_automatic_namespace"></a>  _ATL_NO_AUTOMATIC_NAMESPACE

Um símbolo que impede o uso do padrão de namespace como ATL.

```
_ATL_NO_AUTOMATIC_NAMESPACE
```

### <a name="remarks"></a>Comentários

Se esse símbolo não estiver definido, executará uma incluindo atlbase. h **usando o namespace ATL** por padrão, o que pode levar a conflitos de nomenclatura. Para evitar isso, defina esse símbolo.

##  <a name="_atl_no_com_support"></a>  _ATL_NO_COM_SUPPORT

Um símbolo que impede que o código relacionado ao COM que está sendo compilado com o seu projeto.

```
_ATL_NO_COM_SUPPORT
```

##  <a name="atl_no_vtable"></a>  ATL_NO_VTABLE

Um símbolo que impede que o ponteiro vtable que está sendo inicializado no construtor e o destruidor da classe.

```
ATL_NO_VTABLE
```

### <a name="remarks"></a>Comentários

Se o ponteiro vtable é impedido de sendo inicializada no construtor da classe e o destruidor, o vinculador pode eliminar a vtable e todas as funções para o qual ele aponta. Expande para **novtable**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#53](../../atl/codesnippet/cpp/compiler-options-macros_4.h)]

##  <a name="atl_noinline"></a>  ATL_NOINLINE

Um símbolo que indica uma função não deve ser embutido.

```
    ATL_NOINLINE inline
    myfunction()
    {
    ...
    }
```

### <a name="parameters"></a>Parâmetros

*myFunction*<br/>
A função que não deve ser embutida.

### <a name="remarks"></a>Comentários

Se você quiser garantir que uma função de não serem embutida pelo compilador, mesmo que ele deve ser declarado como embutido para que ele pode ser colocado em um arquivo de cabeçalho, use este símbolo. Expande para **{1&gt;__declspec(noinline)&lt;1**.

##  <a name="_atl_single_threaded"></a>  ATL_SINGLE_THREADED

Defina se todos os seus objetos usam o modelo de threading único

```
_ATL_SINGLE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica que o objeto sempre é executado no thread COM primário. Ver [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções, de threading e [opções, ATL Simple Object Wizard](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição de threading de modelos disponíveis para um objeto ATL.

## <a name="see-also"></a>Consulte também

[Macros](../../atl/reference/atl-macros.md)
