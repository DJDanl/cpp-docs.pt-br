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
ms.openlocfilehash: 702324c3300ff23bb60113529a681e3b8fa99354
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81331614"
---
# <a name="compiler-options-macros"></a>Macros de opções de compilador

Essas macros controlam recursos específicos do compilador.

|||
|-|-|
|[_ATL_ALL_WARNINGS](#_atl_all_warnings)|Um símbolo que permite erros em projetos convertidos de versões anteriores do ATL.|
|[_ATL_APARTMENT_THREADED](#_atl_apartment_threaded)|Defina se um ou mais de seus objetos usam rosca de apartamento.|
|[_ATL_CSTRING_EXPLICIT_CONSTRUCTORS](#_atl_cstring_explicit_constructors)|Torna `CString` certos construtores explícitos, impedindo quaisquer conversões não intencionais.|
|[_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning)|Defina esta macro para usar a sintaxe padrão C++, que gera o erro do compilador C4867 quando uma sintaxe não padrão é usada para inicializar um ponteiro para uma função de membro.|
|[_ATL_FREE_THREADED](#_atl_free_threaded)|Defina se um ou mais de seus objetos usam rosca livre ou neutra.|
|[_ATL_MULTI_THREADED](#_atl_multi_threaded)|Um símbolo que indica o projeto terá objetos marcados como Ambos, Livres ou Neutros. Em vez disso, as [_ATL_FREE_THREADED](#_atl_free_threaded) macro devem ser utilizadas.|
|[_ATL_NO_AUTOMATIC_NAMESPACE](#_atl_no_automatic_namespace)|Um símbolo que impede o uso padrão do namespace como ATL.|
|[_ATL_NO_COM_SUPPORT](#_atl_no_com_support)|Um símbolo que impede que o código relacionado ao COM seja compilado com seu projeto.|
|[Atl_no_vtable](#atl_no_vtable)|Um símbolo que impede que o ponteiro vtable seja inicializado no construtor e destruidor da classe.|
|[ATL_NOINLINE](#atl_noinline)|Um símbolo que indique uma função não deve ser inforrado.|
|[_ATL_SINGLE_THREADED](#_atl_single_threaded)|Defina se todos os seus objetos usam o modelo de rosca única.|

## <a name="_atl_all_warnings"></a><a name="_atl_all_warnings"></a>_ATL_ALL_WARNINGS

Um símbolo que permite erros em projetos convertidos de versões anteriores do ATL.

```
#define _ATL_ALL_WARNINGS
```

### <a name="remarks"></a>Comentários

Antes do Visual C++ .NET 2002, a ATL desativou muitos avisos e os deixou desativados para que eles nunca aparecessem no código do usuário. Especificamente:

- A expressão condicional c4127 é constante

- C4786 'identificador' : identificador foi truncado para caracteres 'número' nas informações de depuração

- Extensão não padrão C4201 usada: struct/union sem nome

- C4103 'filename' : usado #pragma pacote para alterar o alinhamento

- 'Declaração' C4291: não foi encontrada exclusão do operador correspondente; memória não será liberada se a inicialização lança uma exceção

- 'Identificador' C4268: dados estáticos/globais 'const' inicializados com construtor padrão gerado pelo compilador preenche o objeto com zeros

- Código c4702 inalcançável

Em projetos convertidos de versões anteriores, esses avisos ainda são desativados pelos cabeçalhos das bibliotecas.

Adicionando a seguinte linha ao arquivo *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior) antes de incluir cabeçalhos de bibliotecas, esse comportamento pode ser alterado.

[!code-cpp[NVC_ATL_Utilities#97](../../atl/codesnippet/cpp/compiler-options-macros_1.h)]

Se `#define` isso for adicionado, os cabeçalhos ATL terão o cuidado de preservar o estado desses avisos para que não sejam desativados globalmente (ou se o usuário desativar explicitamente avisos individuais, não para habilitá-los).

Novos projetos `#define` têm esse conjunto em *pch.h* (*stdafx.h* no Visual Studio 2017 e anteriormente) por padrão.

## <a name="_atl_apartment_threaded"></a><a name="_atl_apartment_threaded"></a>_ATL_APARTMENT_THREADED

Defina se um ou mais de seus objetos usam rosca de apartamento.

```
_ATL_APARTMENT_THREADED
```

### <a name="remarks"></a>Comentários

Especifica a rosca do apartamento. Consulte [Especificando o modelo de rosca do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de rosca e [opções, ASSISTENTE DE OBJETO SIMPLES ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de rosca disponíveis para um objeto ATL.

## <a name="_atl_cstring_explicit_constructors"></a><a name="_atl_cstring_explicit_constructors"></a>_ATL_CSTRING_EXPLICIT_CONSTRUCTORS

Torna `CString` certos construtores explícitos, impedindo quaisquer conversões não intencionais.

```
_ATL_CSTRING_EXPLICIT_CONSTRUCTORS
```

### <a name="remarks"></a>Comentários

Quando este construtor é definido, todos os construtores CString que tomam um único parâmetro são compilados com a palavra-chave explícita, que impede conversões implícitas de argumentos de entrada. Isso significa, por exemplo, que quando _UNICODE for definido, se você tentar usar uma seqüência de caracteres char* como argumento de construtor CString, um erro do compilador resultará. Use esta macro em situações onde você precisa evitar conversões implícitas entre tipos estreitos e de cadeias largas.

Ao usar a _T macro em todos os argumentos de string do construtor, você pode definir _ATL_CSTRING_EXPLICIT_CONSTRUCTORS e evitar compilar erros, independentemente de _UNICODE ser definida.

## <a name="_atl_enable_ptm_warning"></a><a name="_atl_enable_ptm_warning"></a>_ATL_ENABLE_PTM_WARNING

Defina esta macro para forçar o uso da sintaxe padrão ANSI C++ para ponteiro para funções de membro. O uso dessa macro fará com que o erro do compilador C4867 seja gerado quando a sintaxe não padrão for usada para inicializar um ponteiro para uma função de membro.

```
#define _ATL_ENABLE_PTM_WARNING
```

### <a name="remarks"></a>Comentários

As bibliotecas ATL e MFC foram alteradas para coincidir com a conformidade padrão c++ do compilador Microsoft C++. De acordo com o padrão ANSI C++, a sintaxe `&CMyClass::MyFunc`de um ponteiro para uma função de membro de classe deve ser .

Quando [_ATL_ENABLE_PTM_WARNING](#_atl_enable_ptm_warning) não é definido (o caso padrão), o ATL/MFC desativa o erro C4867 em mapas macro (notadamente mapas de mensagens) para que o código criado em versões anteriores possa continuar a ser construído como antes. Se você definir **_ATL_ENABLE_PTM_WARNING,** seu código deve ser compatível com o padrão C++.

No entanto, a forma não padrão foi preterida. Você precisa mover o código existente para a sintaxe padrão C++. Por exemplo, o código a seguir:

[!code-cpp[NVC_MFCListView#14](../../atl/reference/codesnippet/cpp/compiler-options-macros_2.cpp)]

Deve ser alterado para:

[!code-cpp[NVC_MFCListView#11](../../atl/reference/codesnippet/cpp/compiler-options-macros_3.cpp)]

Para macros de mapa, adicione o caractere ampersand '&'. Você não deve adicionar o personagem novamente em seu código.

## <a name="_atl_free_threaded"></a><a name="_atl_free_threaded"></a>_ATL_FREE_THREADED

Defina se um ou mais de seus objetos usam rosca livre ou neutra.

```
_ATL_FREE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica rosca livre. A rosca livre é equivalente a um modelo de apartamento multithread. Consulte [Especificando o modelo de rosca do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de rosca e [opções, ASSISTENTE DE OBJETO SIMPLES ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de rosca disponíveis para um objeto ATL.

## <a name="_atl_multi_threaded"></a><a name="_atl_multi_threaded"></a>_ATL_MULTI_THREADED

Um símbolo que indica o projeto terá objetos marcados como Ambos, Livres ou Neutros.

```
_ATL_MULTI_THREADED
```

### <a name="remarks"></a>Comentários

Se este símbolo for definido, a ATL puxará um código que sincronizará corretamente o acesso aos dados globais. Em vez disso, o novo código deve usar o [_ATL_FREE_THREADED](#_atl_free_threaded) macro equivalente.

## <a name="_atl_no_automatic_namespace"></a><a name="_atl_no_automatic_namespace"></a>_ATL_NO_AUTOMATIC_NAMESPACE

Um símbolo que impede o uso padrão do namespace como ATL.

```
_ATL_NO_AUTOMATIC_NAMESPACE
```

### <a name="remarks"></a>Comentários

Se esse símbolo não for definido, inclusive atlbase.h será realizado **usando o namespace ATL** por padrão, o que pode levar a conflitos de nomeação. Para evitar isso, defina este símbolo.

## <a name="_atl_no_com_support"></a><a name="_atl_no_com_support"></a>_ATL_NO_COM_SUPPORT

Um símbolo que impede que o código relacionado ao COM seja compilado com seu projeto.

```
_ATL_NO_COM_SUPPORT
```

## <a name="atl_no_vtable"></a><a name="atl_no_vtable"></a>Atl_no_vtable

Um símbolo que impede que o ponteiro vtable seja inicializado no construtor e destruidor da classe.

```
ATL_NO_VTABLE
```

### <a name="remarks"></a>Comentários

Se o ponteiro vtable for impedido de ser inicializado no construtor e destructor da classe, o linker pode eliminar o vtable e todas as funções para as quais ele aponta. Expande-se para **__declspec(novtable)**.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#53](../../atl/codesnippet/cpp/compiler-options-macros_4.h)]

## <a name="atl_noinline"></a><a name="atl_noinline"></a>ATL_NOINLINE

Um símbolo que indica uma função não deve ser inforrado.

```
    ATL_NOINLINE inline
    myfunction()
    {
    ...
    }
```

### <a name="parameters"></a>Parâmetros

*Myfunction*<br/>
A função que não deve ser inforrada.

### <a name="remarks"></a>Comentários

Use este símbolo se quiser garantir que uma função não seja inforrada pelo compilador, mesmo que ela deva ser declarada como inline para que possa ser colocada em um arquivo de cabeçalho. Expande-se para **__declspec(noinline)**.

## <a name="_atl_single_threaded"></a><a name="_atl_single_threaded"></a>_ATL_SINGLE_THREADED

Defina se todos os seus objetos usam o modelo de rosca única

```
_ATL_SINGLE_THREADED
```

### <a name="remarks"></a>Comentários

Especifica que o objeto é sempre executado no segmento COM principal. Consulte [Especificando o modelo de rosca do projeto](../../atl/specifying-the-threading-model-for-a-project-atl.md) para outras opções de rosca e [opções, ASSISTENTE DE OBJETO SIMPLES ATL](../../atl/reference/options-atl-simple-object-wizard.md) para obter uma descrição dos modelos de rosca disponíveis para um objeto ATL.

## <a name="see-also"></a>Confira também

[Macros](../../atl/reference/atl-macros.md)
