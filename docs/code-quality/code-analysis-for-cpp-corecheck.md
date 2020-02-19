---
title: C++Referência do verificador de diretrizes principais
ms.date: 03/22/2018
ms.topic: reference
helpviewer_keywords:
- code analysis, C++ core check
ms.assetid: f1429463-136e-41ed-8a75-a8dbf0b4fd89
ms.openlocfilehash: 3fe8f1795416bd05ce2c8cc622664a3ff1d6c749
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418833"
---
# <a name="c-core-guidelines-checker-reference"></a>C++Referência do verificador de diretrizes principais

Esta seção lista avisos de verificação de diretrizes de principal do C++. Para obter informações sobre a análise de código, consulte [/Analyze (análise de código)](/cpp/build/reference/analyze-code-analysis) e [início rápido: análiseC++de código para C/](../code-quality/quick-start-code-analysis-for-c-cpp.md).

> [!NOTE]
> Alguns avisos pertencem a mais de um grupo, e nem todos os avisos têm um tópico de referência completa.

## <a name="owner_pointer-group"></a>Grupo OWNER_POINTER

[C26402 DONT_HEAP_ALLOCATE_MOVABLE_RESULT](C26402.md)\
Retorne um objeto com escopo em vez de um heap alocado se ele tiver um construtor de movimentação. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26403 RESET_OR_DELETE_OWNER](C26403.md)\
Redefinir ou excluir explicitamente um proprietário\<T > ponteiro '*variável*'. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26404 DONT_DELETE_INVALID](C26404.md)\
Não exclua um proprietário\<T > que possa estar em estado inválido. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26405 DONT_ASSIGN_TO_VALID](C26405.md)\
Não atribua a um proprietário\<T > que possa estar em um estado válido. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26406 DONT_ASSIGN_RAW_TO_OWNER](C26406.md)\
Não atribua um ponteiro bruto a um proprietário\<T >. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26407 DONT_HEAP_ALLOCATE_UNNECESSARILY](C26407.md)\
Prefira objetos com escopo, não aloque heap desnecessariamente. Consulte [ C++ as diretrizes básicas R. 5](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-scoped).

[C26429 USE_NOTNULL](C26429.md)\
O símbolo '*Symbol*' nunca é testado quanto à nulidade, pode ser marcado como NOT_NULL. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

[C26430 TEST_ON_ALL_PATHS](C26430.md)\
O símbolo '*Symbol*' não é testado para nullness em todos os caminhos. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

[C26431 DONT_TEST_NOTNULL](C26431.md)\
O tipo de expressão '*expr*' já é GSL:: NOT_NULL. Não teste-o para nullness. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

## <a name="raw_pointer-group"></a>RAW_POINTER Group

[C26400 NO_RAW_POINTER_ASSIGNMENT](c26400.md)\
Não atribua o resultado de uma alocação ou uma chamada de função com um proprietário\<T > valor de retorno a um ponteiro bruto; em vez disso, use o proprietário\<T >. Consulte [ C++ as diretrizes básicas I. 11](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Ri-raw).

[C26401 DONT_DELETE_NON_OWNER](c26401.md)\
Não exclua um ponteiro bruto que não seja um proprietário\<T >. Consulte [ C++ as diretrizes básicas I. 11](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Ri-raw).

[C26402 DONT_HEAP_ALLOCATE_MOVABLE_RESULT](C26402.md)\
Retorne um objeto com escopo em vez de um heap alocado se ele tiver um construtor de movimentação. Consulte [ C++ as diretrizes básicas R. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-ptr).

[C26408 NO_MALLOC_FREE](C26408.md)\
Evite malloc () e Free (), prefira a versão nothrow de New com Delete. Consulte [ C++ as diretrizes básicas R. 10](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-mallocfree).

[C26409 NO_NEW_DELETE](C26409.md)\
Evite chamar New e Delete explicitamente e, em vez disso, use a > T:: make_unique\<. Consulte [ C++ as diretrizes básicas R. 11](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-newdelete).

[C26429 USE_NOTNULL](C26429.md)\
O símbolo '*Symbol*' nunca é testado quanto à nulidade, pode ser marcado como NOT_NULL. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

[C26430 TEST_ON_ALL_PATHS](C26430.md)\
O símbolo '*Symbol*' não é testado para nullness em todos os caminhos. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

[C26431 DONT_TEST_NOTNULL](C26431.md)\
O tipo de expressão '*expr*' já é GSL:: NOT_NULL. Não teste-o para nullness. Consulte [ C++ as diretrizes básicas F. 23](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f23-use-a-not_nullt-to-indicate-that-null-is-not-a-valid-value).

[C26481 NO_POINTER_ARITHMETIC](C26481.md)\
Não use aritmética de ponteiro. Use o span. Consulte [ C++ limites de diretrizes principais. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds).

[C26485 NO_ARRAY_TO_POINTER_DECAY](C26485.md)\
Expression '*expr*': nenhuma matriz para ponteiro decaimento. Consulte [ C++ limites de diretrizes principais. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds).

## <a name="unique_pointer-group"></a>UNIQUE_POINTER Group

[C26410 NO_REF_TO_CONST_UNIQUE_PTR](C26410.md)\
O parâmetro '*Parameter*' é uma referência a `const` ponteiro exclusivo, use const t * ou const t & em vez disso. Consulte [ C++ as diretrizes básicas R. 32](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-uniqueptrparam).

[C26411 NO_REF_TO_UNIQUE_PTR](C26411.md)\
O parâmetro '*Parameter*' é uma referência ao ponteiro exclusivo e nunca é reatribuído ou redefinido, use t * ou t & em vez disso. Consulte [ C++ as diretrizes básicas R. 33](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-reseat).

[C26414 RESET_LOCAL_SMART_PTR](C26414.md)\
Mover, copiar, reatribuir ou redefinir um ponteiro inteligente local '*Symbol*'. Consulte [ C++ as diretrizes básicas R. 5](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-scoped).

[C26415 SMART_PTR_NOT_NEEDED](C26415.md)\
O parâmetro de ponteiro inteligente '*Symbol*' é usado somente para acessar o ponteiro contido. Use T * ou T & em vez disso. Consulte [ C++ as diretrizes básicas R. 30](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-smartptrparam).

## <a name="shared_pointer-group"></a>SHARED_POINTER Group

[C26414 RESET_LOCAL_SMART_PTR](C26414.md)\
Mover, copiar, reatribuir ou redefinir um ponteiro inteligente local '*Symbol*'. Consulte [ C++ as diretrizes básicas R. 5](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-scoped).

[C26415 SMART_PTR_NOT_NEEDED](C26415.md)\
O parâmetro de ponteiro inteligente '*Symbol*' é usado somente para acessar o ponteiro contido. Use T * ou T & em vez disso. Consulte [ C++ as diretrizes básicas R. 30](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-smartptrparam).

[C26416 NO_RVALUE_REF_SHARED_PTR](C26416.md)\
O parâmetro de ponteiro compartilhado '*Symbol*' é passado por referência de rvalue. Passe por valor. Consulte [ C++ as diretrizes básicas R. 34](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-sharedptrparam-owner).

[C26417 NO_LVALUE_REF_SHARED_PTR](C26417.md)\
O parâmetro de ponteiro compartilhado '*Symbol*' é passado por referência e não redefinido ou reatribuído. Use T * ou T & em vez disso. Consulte [ C++ as diretrizes básicas R. 35](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-sharedptrparam).

[C26418 NO_VALUE_OR_CONST_REF_SHARED_PTR](C26418.md)\
O parâmetro de ponteiro compartilhado '*Symbol*' não é copiado ou movido. Use T * ou T & em vez disso. Consulte [ C++ as diretrizes básicas R. 36](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rr-sharedptrparam-const).

## <a name="declaration-group"></a>DECLARAÇÃO de grupo

[C26426 NO_GLOBAL_INIT_CALLS](C26426.md)\
O inicializador global chama uma função não constexpr '*Symbol*'. Consulte [ C++ as diretrizes básicas I. 22](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#i22-avoid-complex-initialization-of-global-objects).

[C26427 NO_GLOBAL_INIT_EXTERNS](C26427.md)\
O inicializador global acessa o objeto externo '*Symbol*'. Consulte [ C++ as diretrizes básicas I. 22](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#i22-avoid-complex-initialization-of-global-objects).

[C26444 NO_UNNAMED_RAII_OBJECTS](c26444.md)\
Evite objetos sem nome com construção e destruição personalizadas. Consulte [es. 84: não (tente) declarar uma variável local sem nome](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).

## <a name="class-group"></a>Grupo de classe

[C26432 DEFINE_OR_DELETE_SPECIAL_OPS](C26432.md)\
Se você definir ou excluir qualquer operação padrão no tipo '*Symbol*', defina ou exclua todas elas. Consulte [ C++ as diretrizes principais C. 21](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-default-operation-define-or-delete-them-all).

[C26433 OVERRIDE_EXPLICITLY](c26433.md)\
A função '*Symbol*' deve ser marcada com ' override '. Consulte [C. 128: as funções virtuais devem especificar exatamente uma das virtual, Override ou final](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c128-virtual-functions-should-specify-exactly-one-of-virtual-override-or-final).

[C26434 DONT_HIDE_METHODS](C26434.md)\
A função '*symbol_1*' oculta uma função não virtual '*symbol_2*'. Consulte [ C++ as diretrizes básicas C. 128](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c128-virtual-functions-should-specify-exactly-one-of-virtual-override-or-final).

[C26435 SINGLE_VIRTUAL_SPECIFICATION](c26435.md)\
A função '*Symbol*' deve especificar exatamente um dos ' virtual ', ' override ' ou ' final '. Consulte [C. 128: as funções virtuais devem especificar exatamente uma das virtual, Override ou final](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).

[C26436 NEED_VIRTUAL_DTOR](C26436.md)\
O tipo '*Symbol*' com uma função virtual precisa de um destruidor virtual público ou não virtual protegido. Consulte [ C++ as diretrizes básicas C. 35](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c35-a-base-class-destructor-should-be-either-public-and-virtual-or-protected-and-nonvirtual).

[C26443 NO_EXPLICIT_DTOR_OVERRIDE](c26443.md)\
O destruidor de substituição não deve usar especificadores ' override ' ou ' virtual ' explícitos. Consulte [C. 128: as funções virtuais devem especificar exatamente uma das virtual, Override ou final](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).

## <a name="style-group"></a>Grupo de estilo

[C26438 NO_GOTO](C26438.md)\
Evite `goto`. Consulte [ C++ as diretrizes principais es. 76](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es76-avoid-goto).

## <a name="function-group"></a>Grupo de funções

[C26439 SPECIAL_NOEXCEPT](C26439.md)\
Esse tipo de função pode não gerar. Declare-o `noexcept`. Consulte [ C++ as diretrizes básicas F. 6](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f6-if-your-function-may-not-throw-declare-it-noexcept).

[C26440 DECLARE_NOEXCEPT](C26440.md)\
A função '*Symbol*' pode ser declarada `noexcept`. Consulte [ C++ as diretrizes básicas F. 6](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f6-if-your-function-may-not-throw-declare-it-noexcept).

[C26447 DONT_THROW_IN_NOEXCEPT](c26447.md)\
A função é declarada **noexcept** , mas chama uma função que pode gerar exceções.
Consulte [ C++ as principais diretrizes: F. 6: se sua função não puder ser lançada, declare-a sem Except](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#f6-if-your-function-may-not-throw-declare-it-noexcept).

## <a name="concurrency-group"></a>Grupo de SIMULTANEIDADE

[C26441 NO_UNNAMED_GUARDS](C26441.md)\
Os objetos de proteção devem ser nomeados. Consulte [ C++ as diretrizes básicas CP. 44](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#cp44-remember-to-name-your-lock_guards-and-unique_locks).

## <a name="const-group"></a>Grupo de CONST

[C26460 USE_CONST_REFERENCE_ARGUMENTS](c26460.md)\
O argumento de referência '*Argument*' para a função '*Function*' pode ser marcado como `const`. Consulte [ C++ as principais diretrizes con. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rconst-ref).

[C26461 USE_CONST_POINTER_ARGUMENTS](c26461.md): \
O argumento de ponteiro '*Argument*' da função '*Function*' pode ser marcado como um ponteiro para `const`. Consulte [ C++ as principais diretrizes con. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rconst-ref).

[C26462 USE_CONST_POINTER_FOR_VARIABLE](c26462.md)\
O valor apontado por '*variável*' é atribuído apenas uma vez, marque-o como um ponteiro para `const`. Consulte [ C++ as diretrizes básicas con. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con4-use-const-to-define-objects-with-values-that-do-not-change-after-construction).

[C26463 USE_CONST_FOR_ELEMENTS](c26463.md)\
Os elementos da matriz '*array*' são atribuídos apenas uma vez, marque os elementos `const`. Consulte [ C++ as diretrizes básicas con. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con4-use-const-to-define-objects-with-values-that-do-not-change-after-construction).

[C26464 USE_CONST_POINTER_FOR_ELEMENTS](c26464.md)\
Os valores apontados por elementos da matriz '*array*' são atribuídos apenas uma vez, marque os elementos como ponteiro para `const`. Consulte [ C++ as diretrizes básicas con. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con4-use-const-to-define-objects-with-values-that-do-not-change-after-construction).

[C26496 USE_CONST_FOR_VARIABLE](c26496.md)\
A variável '*Variable*' é atribuída apenas uma vez, marque-a como `const`. Consulte [ C++ as diretrizes básicas con. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con4-use-const-to-define-objects-with-values-that-do-not-change-after-construction).

[C26497 USE_CONSTEXPR_FOR_FUNCTION](c26497.md)\
Essa *função* de função pode ser marcada `constexpr` se a avaliação do tempo de compilação for desejada. Consulte [ C++ as diretrizes básicas F. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rf-constexpr).

[C26498 USE_CONSTEXPR_FOR_FUNCTIONCALL](c26498.md)\
Essa *função* de chamada de função pode usar `constexpr` se a avaliação de tempo de compilação for desejada. Consulte [ C++ as principais diretrizes con. 5](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rconst-constexpr).

## <a name="type-group"></a>TIPO de grupo

[C26437 DONT_SLICE](C26437.md)\
Não fatiar. Consulte [ C++ as diretrizes principais es. 63](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es63-dont-slice).

[C26465 NO_CONST_CAST_UNNECESSARY](c26465.md)\
Não use `const_cast` para converter `const`. `const_cast` não é necessário; a constante ou a volatilidade não está sendo removida por essa conversão. Consulte [ C++ diretrizes básicas tipo. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-constcast).

[C26466 NO_STATIC_DOWNCAST_POLYMORPHIC](c26466.md)\
Não use `static_cast` downcasts. Uma conversão de um tipo polimórfico deve usar dynamic_cast. Consulte [ C++ diretrizes básicas tipo. 2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-downcast).

[C26471 NO_REINTERPRET_CAST_FROM_VOID_PTR](c26471.md)\
Não use `reinterpret_cast`. Uma conversão de void * pode usar `static_cast`. Consulte [ C++ diretrizes básicas tipo. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-reinterpretcast).

[C26472 NO_CASTS_FOR_ARITHMETIC_CONVERSION](C26472.md)\
Não use um `static_cast` para conversões aritméticas. Use a inicialização de chaves, GSL:: narrow_cast ou GSL:: Narrow. Consulte [ C++ diretrizes básicas tipo. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-reinterpretcast).

[C26473 NO_IDENTITY_CAST](C26473.md)\
Não converta os tipos de ponteiro nos quais o tipo de origem e o tipo de destino são os mesmos. Consulte [ C++ diretrizes básicas tipo. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-reinterpretcast).

[C26474 NO_IMPLICIT_CAST](C26474.md)\
Não converta entre tipos de ponteiro quando a conversão puder ser implícita. Consulte [ C++ diretrizes básicas tipo. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Pro-type-reinterpretcast).

[C26475 NO_FUNCTION_STYLE_CASTS](C26475.md)\
Não use o estilo de função C-casts. Consulte [ C++ as diretrizes básicas es. 49](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es49-if-you-must-use-a-cast-use-a-named-cast).

[C26490 NO_REINTERPRET_CAST](c26490.md)\
Não use `reinterpret_cast`. Consulte [ C++ diretrizes básicas tipo. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

[C26491 NO_STATIC_DOWNCAST](c26490.md)\
Não use `static_cast` downcasts. Consulte [ C++ diretrizes básicas tipo. 2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

[C26492 NO_CONST_CAST](c26492.md)\
Não use `const_cast` para converter `const`. Consulte [ C++ diretrizes básicas tipo. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

[C26493 NO_CSTYLE_CAST](c26493.md)\
Não use conversões de estilo C. Consulte [ C++ diretrizes básicas tipo. 4](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

[C26494 VAR_USE_BEFORE_INIT](c26494.md)\
A variável '*Variable*' não foi inicializada. Sempre inicialize um objeto. Consulte [ C++ diretrizes básicas tipo. 5](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

[C26495 MEMBER_UNINIT](c26495.md)\
A variável '*Variable*' não foi inicializada. Sempre inicialize uma variável de membro. Consulte [ C++ diretrizes básicas tipo. 6](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-type).

## <a name="bounds-group"></a>Grupo de limites

[C26446 USE_GSL_AT](c26446.md)\
Prefira usar `gsl::at()` em vez do operador subscrito desmarcado. Consulte [ C++ as principais diretrizes: limites. 4: não use funções e tipos de biblioteca padrão que não são associados-verificados](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#probounds-bounds-safety-profile).

[C26481 NO_POINTER_ARITHMETIC](C26481.md)\
Não use aritmética de ponteiro. Use o span. Consulte [ C++ limites de diretrizes principais. 1](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds)

[C26482 NO_DYNAMIC_ARRAY_INDEXING](c26482.md)\
Indexe somente em matrizes usando expressões de constante. Consulte [ C++ limites de diretrizes principais. 2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds)

[C26483 STATIC_INDEX_OUT_OF_RANGE](c26483.md)\
O *valor* do valor está fora dos limites (0, *associado*) da variável '*Variable*'. Somente indexe em matrizes que usam expressões de constante que estão dentro dos limites da matriz. Consulte [ C++ limites de diretrizes principais. 2](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds)

[C26485 NO_ARRAY_TO_POINTER_DECAY](C26485.md)\
Expression '*expr*': nenhuma matriz para ponteiro decaimento. Consulte [ C++ limites das diretrizes principais. 3](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-bounds)

## <a name="gsl-group"></a>Grupo de GSL

[C26445 NO_SPAN_REF](c26445.md)\
Uma referência a `gsl::span` ou `std::string_view` pode ser uma indicação de um problema de tempo de vida.
Consulte [ C++ as principais diretrizes GSL. View: views](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#gslview-views)

[C26446 USE_GSL_AT](c26446.md)\
Prefira usar `gsl::at()` em vez do operador subscrito desmarcado. Consulte [ C++ as principais diretrizes: limites. 4: não use funções e tipos de biblioteca padrão que não são associados-verificados](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#probounds-bounds-safety-profile).

[C26448 USE_GSL_FINALLY](c26448.md)\
Considere o uso de `gsl::finally` se a ação final for pretendida. Consulte [ C++ as principais diretrizes: GSL. util: Utilities](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#SS-utilities).

[C26449 NO_SPAN_FROM_TEMPORARY](c26449.md)\
`gsl::span` ou `std::string_view` criados a partir de um temporário serão inválidos quando o temporário for invalidado. Consulte [ C++ as principais diretrizes: GSL. View: views](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#gslview-views).

## <a name="deprecated-warnings"></a>Avisos preteridos

Os avisos a seguir estão presentes em um conjunto de regra experimental antecipada do verificador de diretrizes de núcleo, mas agora são preteridos e podem ser ignorados com segurança. Os avisos são substituídos por avisos da lista acima.

- 26412 DEREF_INVALID_POINTER
- 26413 DEREF_NULLPTR
- 26420 ASSIGN_NONOWNER_TO_EXPLICIT_OWNER
- 26421 ASSIGN_VALID_OWNER
- 26422 VALID_OWNER_LEAVING_SCOPE
- 26423 ALLOCATION_NOT_ASSIGNED_TO_OWNER
- 26424 VALID_ALLOCATION_LEAVING_SCOPE
- 26425 ASSIGNING_TO_STATIC
- 26499 NO_LIFETIME_TRACKING

## <a name="see-also"></a>Confira também

[Usando os C++ verificadores de diretrizes principais](using-the-cpp-core-guidelines-checkers.md)
