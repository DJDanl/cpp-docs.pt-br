---
title: Macros de opções de compilador
ms.date: 08/19/2019
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
ms.openlocfilehash: 90b80aaa34456677f2d7c2dd5717ae6837f4523f
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833563"
---
# <a name="compiler-options-macros"></a>Macros de opções de compilador

Essas macros controlam recursos específicos do compilador.

|Macro|Descrição|
|-|-|
|[_ATL_ALL_WARNINGS](#_atl_all_warnings)|Um símbolo que habilita erros em projetos convertidos de versões anteriores do ATL.|
|[_ATL_APARTMENT_THREADED](#_atl_apartment_threaded)|Defina se um ou mais dos seus objetos usam Threading Apartment.|
|[_ATL_CSTRING_EXPLICIT_CONSTRUCTORS](#_atl_cstring_explicit_constructors)|Torna determinados `CString` construtores explícitos, evitando qualquer conversões não intencional.|
|[_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning)|Defina essa macro para usar a sintaxe compatível com C++ Standard, que gera o erro do compilador C4867 quando uma sintaxe não padrão é usada para inicializar um ponteiro para uma função membro.|
|[_ATL_FREE_THREADED](#_atl_free_threaded)|Defina se um ou mais dos seus objetos usam Threading gratuito ou neutro.|
|[_ATL_MULTI_THREADED](#_atl_multi_threaded)|Um símbolo que indica que o projeto terá objetos marcados como ambos, gratuitos ou neutros. Em vez disso, a macro [_ATL_FREE_THREADED](#_atl_free_threaded) deve ser usada.|
|[_ATL_NO_AUTOMATIC_NAMESPACE](#_atl_no_automatic_namespace)|Um símbolo que impede o uso padrão do namespace como ATL.|
|[_ATL_NO_COM_SUPPORT](#_atl_no_com_support)|Um símbolo que impede que o código relacionado com seja compilado com seu projeto.|
|[ATL_NO_VTABLE](#atl_no_vtable)|Um símbolo que impede que o ponteiro vtable seja inicializado no construtor e no destruidor da classe.|
|[ATL_NOINLINE](#atl_noinline)|Um símbolo que indica que uma função não deve ser embutida.|
|[_ATL_SINGLE_THREADED](#_atl_single_threaded)|Defina se todos os seus objetos usam o modelo de Threading único.|

## <a name="_atl_all_warnings"></a><a name="_atl_all_warnings"></a> _ATL_ALL_WARNINGS

Um símbolo que habilita erros em projetos convertidos de versões anteriores do ATL.

```
#define _ATL_ALL_WARNINGS
```

### <a name="remarks"></a>Comentários

Antes de Visual C++ o .NET 2002, a ATL desabilitou muitos avisos e os deixou desabilitados para que nunca sejam mostrados no código do usuário. Especificamente:

- A expressão condicional C4127 é constante

- C4786 ' identifier ': o identificador foi truncado para ' Number ' caracteres nas informações de depuração

- Extensão não padrão C4201 usada: sem nome struct/Union

- C4103 ' FileName ': pacote de #pragma usado para alterar o alinhamento

- C4291 ' declaração ': nenhuma exclusão de operador correspondente encontrada; a memória não será liberada se a inicialização lançar uma exceção

- C4268 ' identifier ': os dados estáticos/globais ' const ' inicializados com o construtor padrão gerado pelo compilador preenche o objeto com zeros

- Código inacessível do C4702

Em projetos convertidos de versões anteriores, esses avisos ainda são desabilitados pelos cabeçalhos de bibliotecas.

Ao adicionar a linha a seguir ao arquivo *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior) antes de incluir os cabeçalhos de bibliotecas, esse comportamento pode ser alterado.

[!code-cpp[NVC_ATL_Utilities#97](../../atl/codesnippet/cpp/compiler-options-macros_1.h)]

Se isso `#define` for adicionado, os cabeçalhos de ATL terão cuidado para preservar o estado desses avisos para que eles não sejam desabilitados globalmente (ou se o usuário desabilitar explicitamente os avisos individuais, não para habilitá-los).

Os novos projetos têm esse `#define` conjunto em *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior) por padrão.

## <a name="_atl_apartment_threaded"></a><a name="_atl_apartment_threaded"></a> _ATL_APARTMENT_THREADED

Defina se um ou mais dos seus objetos usam Threading Apartment.

```
_ATL_APARTMENT_THREADED
```

### <a name="remarks"></a>Comentários

Especifica Threading de apartamento. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de Threading, e [Opções, assistente de objeto simples do ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de Threading disponíveis para um objeto ATL.

## <a name="_atl_cstring_explicit_constructors"></a><a name="_atl_cstring_explicit_constructors"></a> _ATL_CSTRING_EXPLICIT_CONSTRUCTORS

Torna determinados `CString` construtores explícitos, evitando qualquer conversões não intencional.

```
_ATL_CSTRING_EXPLICIT_CONSTRUCTORS
```

### <a name="remarks"></a>Comentários

Quando esse construtor é definido, todos os construtores de CString que usam um único parâmetro são compilados com a palavra-chave Explicit, o que impede conversões implícitas de argumentos de entrada. Isso significa, por exemplo, que, quando _UNICODE for definido, se você tentar usar uma cadeia de caracteres Char * como um argumento de Construtor CString, ocorrerá um erro de compilador. Use essa macro em situações em que você precisa impedir conversões implícitas entre tipos de cadeia de caracteres estreitos e largos.

Usando a macro _T em todos os argumentos de cadeia de caracteres do Construtor, você pode definir _ATL_CSTRING_EXPLICIT_CONSTRUCTORS e evitar erros de compilação, independentemente de _UNICODE ser definido.

## <a name="_atl_enable_ptm_warning"></a><a name="_atl_enable_ptm_warning"></a> _ATL_ENABLE_PTM_WARNING

Defina essa macro para forçar o uso da sintaxe compatível com o padrão ANSI C++ para ponteiro para funções membro. Usar essa macro fará com que o erro do compilador C4867 seja gerado quando a sintaxe não padrão for usada para inicializar um ponteiro para uma função de membro.

```
#define _ATL_ENABLE_PTM_WARNING
```

### <a name="remarks"></a>Comentários

As bibliotecas ATL e MFC foram alteradas para coincidir com a conformidade com C++ padrão aprimorada do compilador do Microsoft C++. De acordo com o padrão ANSI C++, a sintaxe de um ponteiro para uma função de membro de classe deve ser `&CMyClass::MyFunc` .

Quando [_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning) não é definido (o caso padrão), o ATL/MFC desabilita o erro C4867 nos mapas de macro (especialmente mapas de mensagens) para que o código criado em versões anteriores possa continuar a compilar como antes. Se você definir **_ATL_ENABLE_PTM_WARNING**, seu código deverá ser compatível com C++ Standard.

No entanto, o formulário não padrão foi preterido. Você precisa mover o código existente para a sintaxe compatível com C++ Standard. Por exemplo, o código a seguir:

[!code-cpp[NVC_MFCListView#14](../../atl/reference/codesnippet/cpp/compiler-options-macros_2.cpp)]

Deve ser alterado para:

[!code-cpp[NVC_MFCListView#11](../../atl/reference/codesnippet/cpp/compiler-options-macros_3.cpp)]

Para macros de mapa, adicione o caractere "&" e comercialmente. Você não deve adicionar o caractere novamente no seu código.

## <a name="_atl_free_threaded"></a><a name="_atl_free_threaded"></a> _ATL_FREE_THREADED

Defina se um ou mais dos seus objetos usam Threading gratuito ou neutro.

```
_ATL_FREE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica Threading livre. O Threading gratuito é equivalente a um modelo de apartamento multithread. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de Threading, e [Opções, assistente de objeto simples do ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de Threading disponíveis para um objeto ATL.

## <a name="_atl_multi_threaded"></a><a name="_atl_multi_threaded"></a> _ATL_MULTI_THREADED

Um símbolo que indica que o projeto terá objetos marcados como ambos, gratuitos ou neutros.

```
_ATL_MULTI_THREADED
```

### <a name="remarks"></a>Comentários

Se esse símbolo for definido, o ATL receberá o código que sincronizará corretamente o acesso aos dados globais. O novo código deve usar a macro equivalente [_ATL_FREE_THREADED](#_atl_free_threaded) em vez disso.

## <a name="_atl_no_automatic_namespace"></a><a name="_atl_no_automatic_namespace"></a> _ATL_NO_AUTOMATIC_NAMESPACE

Um símbolo que impede o uso padrão do namespace como ATL.

```
_ATL_NO_AUTOMATIC_NAMESPACE
```

### <a name="remarks"></a>Comentários

Se esse símbolo não estiver definido, incluindo atlbase. h, **usará o namespace ATL** por padrão, o que pode levar a conflitos de nomenclatura. Para evitar isso, defina esse símbolo.

## <a name="_atl_no_com_support"></a><a name="_atl_no_com_support"></a> _ATL_NO_COM_SUPPORT

Um símbolo que impede que o código relacionado com seja compilado com seu projeto.

```
_ATL_NO_COM_SUPPORT
```

## <a name="atl_no_vtable"></a><a name="atl_no_vtable"></a> ATL_NO_VTABLE

Um símbolo que impede que o ponteiro vtable seja inicializado no construtor e no destruidor da classe.

```
ATL_NO_VTABLE
```

### <a name="remarks"></a>Comentários

Se o ponteiro vtable for impedido de ser inicializado no construtor e no destruidor da classe, o vinculador poderá eliminar a vtable e todas as funções para as quais ele aponta. Expande para **`__declspec(novtable)`** .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#53](../../atl/codesnippet/cpp/compiler-options-macros_4.h)]

## <a name="atl_noinline"></a><a name="atl_noinline"></a> ATL_NOINLINE

Um símbolo que indica que uma função não deve ser embutida.

```
    ATL_NOINLINE inline
    myfunction()
    {
    ...
    }
```

### <a name="parameters"></a>parâmetros

*MyFunction*<br/>
A função que não deve ser embutida.

### <a name="remarks"></a>Comentários

Use esse símbolo se você quiser garantir que uma função não seja embutida no compilador, mesmo que ela deva ser declarada como inline para que possa ser colocada em um arquivo de cabeçalho. Expande para **`__declspec(noinline)`** .

## <a name="_atl_single_threaded"></a><a name="_atl_single_threaded"></a> _ATL_SINGLE_THREADED

Definir se todos os seus objetos usam o modelo de Threading único

```
_ATL_SINGLE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica que o objeto sempre é executado no thread COM primário. Consulte [especificando o modelo de Threading do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de Threading, e [Opções, assistente de objeto simples do ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de Threading disponíveis para um objeto ATL.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
