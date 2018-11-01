---
title: '/ZC: throwingnew (pressupor novos acionamentos de operador)'
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
ms.openlocfilehash: 782cb55d30bfb11f55a0074a5c3245dd389323ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50561220"
---
# <a name="zcthrowingnew-assume-operator-new-throws"></a>/ZC: throwingnew (pressupor novos acionamentos de operador)

Quando o **/ZC: throwingnew** opção for especificada, o compilador otimiza o chamadas para `operator new` para ignorar as verificações para um ponteiro nulo retornado. Essa opção informa ao compilador para assumir que todos os vinculados a implementações de `operator new` e alocadores personalizados estão em conformidade com o padrão C++ e lançar em caso de falha de alocação. Por padrão no Visual Studio, o compilador gera pessimista verificações nulas (**/Zc:throwingNew-**) para essas chamadas, pois os usuários podem vincular com uma implementação de não lançamento de `operator new` ou gravar rotinas de alocador personalizado que retornam ponteiros nulos.

## <a name="syntax"></a>Sintaxe

> **/Zc:throwingNew**[**-**]

## <a name="remarks"></a>Comentários

Desde o ISO c++98, o padrão tiver especificado que o padrão [operador new](../../standard-library/new-operators.md#op_new) lança `std::bad_alloc` quando ocorrer falha de alocação de memória. Versões do Visual C++ para Visual Studio 6.0 retornou um ponteiro nulo em uma falha de alocação. A partir do Visual Studio 2002, `operator new` está em conformidade com o padrão e gerará em caso de falha. Para dar suporte a código que usa o estilo de alocação mais antigo, o Visual Studio fornece uma implementação vinculável de `operator new` em nothrownew que retorna um ponteiro nulo em caso de falha. Por padrão, o compilador também gera defensivas verificações nulas para impedir que um desses alocadores de estilo antigo causando uma falha imediata em caso de falha. O **/ZC: throwingnew** opção instrui o compilador a omitir essas verificações de null, na suposição de que todos os vinculados memória alocadores de acordo com o padrão. Isso não se aplica a explícita não lançamento `operator new` sobrecargas, que são declaradas usando um parâmetro adicional do tipo `std::nothrow_t` e ter uma explícita `noexcept` especificação.

Conceitualmente, para criar um objeto no repositório livre, o compilador gera código para alocar a memória e, em seguida, para invocar o construtor para inicializar a memória. Porque o compilador do Visual C++, normalmente não pode determinar se esse código será vinculado a um alocador não conformes, sem lançamento, por padrão ele também gera uma verificação nula antes de chamar o construtor. Isso impede que um ponteiro nulo na chamada do construtor de desreferência se uma alocação de não lançamento falhar. Na maioria dos casos, essas verificações são desnecessárias, pois o padrão `operator new` alocadores throw em vez de retornar ponteiros nulos. As verificações também tem uma pena efeito colateral. Eles inchar o tamanho do código, eles inundam o indicador de ramificação e inibem a outras otimizações do compilador úteis como devirtualization ou propagação const fora do objeto inicializado. As verificações existem somente ao código de suporte que vincula *nothrownew* ou tiver personalizado não conformes `operator new` implementações. Se você não usar não conformes `operator new`, é recomendável que você use **/ZC: throwingnew** para otimizar seu código.

O **/ZC: throwingnew** opção é desativada por padrão e não é afetada pela [/permissive--](permissive-standards-conformance.md) opção.

Se você compilar usando a geração de código para link-time (LTCG), você não precisará especificar **/ZC: throwingnew**. Quando seu código é compilado usando a LTCG, o compilador pode detectar se o padrão, em conformidade com `operator new` implementação é usada. Nesse caso, o compilador deixa de fora as verificações nulas automaticamente. O vinculador procura o **/ThrowingNew** sinalizador para informar se a implementação de `operator new` está de acordo com. Você pode especificar esse sinalizador para o vinculador incluindo essa diretiva na fonte de sua nova implementação do operador personalizado:

```cpp
#pragma comment(linker, "/ThrowingNew")
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Dos **Configuration** menu suspenso, escolha **todas as configurações de**.

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: throwingnew** ou **/Zc:throwingNew-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[noexcept (C++)](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar) (C++)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[encerrar (exceção)](../../standard-library/exception-functions.md#terminate)<br/>
