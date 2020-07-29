---
title: /Zc:throwingNew (Pressupor novos acionamentos de operador)
ms.date: 03/01/2018
f1_keywords:
- throwingNew
- /Zc:throwingNew
helpviewer_keywords:
- -Zc compiler options (C++)
- throwingNew
- Assume operator new Throws
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 20ff0101-9677-4d83-8c7b-8ec9ca49f04f
ms.openlocfilehash: 7593107a280995145d252efa76e0a88bddbd2275
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211860"
---
# <a name="zcthrowingnew-assume-operator-new-throws"></a>/Zc:throwingNew (Pressupor novos acionamentos de operador)

Quando a opção **/Zc: throwingNew** é especificada, o compilador otimiza as chamadas para `operator new` para ignorar verificações de um retorno de ponteiro nulo. Essa opção informa o compilador para assumir que todas as implementações vinculadas do `operator new` e dos alocadores personalizados estão em conformidade com o padrão C++ e geram uma falha de alocação. Por padrão, no Visual Studio, o compilador pessimistically gera verificações nulas (**/Zc: throwingNew-**) para essas chamadas, pois os usuários podem vincular a uma implementação sem lançamento `operator new` ou gravar rotinas de alocador personalizadas que retornam ponteiros nulos.

## <a name="syntax"></a>Sintaxe

> **/Zc: throwingNew**[ **-** ]

## <a name="remarks"></a>Comentários

Desde o ISO C++ 98, o padrão especificou que o [operador padrão novo](../../standard-library/new-operators.md#op_new) gera `std::bad_alloc` quando a alocação de memória falha. As versões do Visual C++ até o Visual Studio 6,0 retornaram um ponteiro nulo sobre uma falha de alocação. A partir do Visual Studio 2002, `operator new` está em conformidade com o padrão e gera em caso de falha. Para dar suporte a código que usa o estilo de alocação mais antigo, o Visual Studio fornece uma implementação vinculável de `operator new` no nothrownew. obj que retorna um ponteiro nulo em caso de falha. Por padrão, o compilador também gera verificações nulas defensivas para impedir que esses alocadores de estilo mais antigo causem uma falha imediata em caso de falha. A opção **/Zc: throwingNew** informa o compilador para deixar essas verificações nulas, supondo que todos os alocadores de memória vinculada estejam em conformidade com o padrão. Isso não se aplica a sobrecargas sem lançamento explícitos `operator new` , que são declaradas usando um parâmetro adicional do tipo `std::nothrow_t` e têm uma **`noexcept`** especificação explícita.

Conceitualmente, para criar um objeto na loja gratuita, o compilador gera código para alocar sua memória e, em seguida, invocar seu construtor para inicializar a memória. Como o compilador MSVC normalmente não pode determinar se esse código será vinculado a um alocador não compatível e não de lançamento, por padrão ele também gera uma verificação nula antes de chamar o construtor. Isso impede uma desreferência de ponteiro NULL na chamada de Construtor se uma alocação sem lançamento falhar. Na maioria dos casos, essas verificações são desnecessárias, porque os `operator new` alocadores padrão lançam em vez de retornar ponteiros nulos. As verificações também têm efeitos colaterais. Elas incharm o tamanho do código, inundam o Predictor da ramificação e impedem outras otimizações úteis do compilador, como a desvirtualização ou a propagação const do objeto inicializado. As verificações existem apenas para dar suporte a código que se vincula a *nothrownew. obj* ou tem implementações não compatíveis personalizadas `operator new` . Se você não usar não conformidade `operator new` , recomendamos que use **/Zc: throwingNew** para otimizar seu código.

A opção **/Zc: throwingNew** está desativada por padrão e não é afetada pela opção [/permissive-](permissive-standards-conformance.md) .

Se você compilar usando a geração de código de tempo de vinculação (LTCG), não será necessário especificar **/Zc: throwingNew**. Quando o código é compilado usando LTCG, o compilador pode detectar se a implementação padrão, em conformidade, `operator new` é usada. Nesse caso, o compilador deixa as verificações nulas automaticamente. O vinculador procura o sinalizador **/ThrowingNew** para saber se a implementação de `operator new` está em conformidade. Você pode especificar esse sinalizador para o vinculador, incluindo essa diretiva na fonte do seu operador personalizado nova implementação:

```cpp
#pragma comment(linker, "/ThrowingNew")
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. No menu suspenso **configuração** , escolha **todas as configurações**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: throwingNew** ou **/Zc: throwingNew-** e escolha **OK**.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
[noexcept (C++)](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar) (C++)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[término (exceção)](../../standard-library/exception-functions.md#terminate)<br/>
