---
title: /ZC:throwingNew (lança novos pressupor operador) | Microsoft Docs
ms.custom: ''
ms.date: 03/01/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- throwingNew
- /Zc:throwingNew
dev_langs:
- C++
helpviewer_keywords:
- -Zc compiler options (C++)
- throwingNew
- Assume operator new Throws
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 20ff0101-9677-4d83-8c7b-8ec9ca49f04f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f446e5c71e88be86c31e5a83ca7d23f611683af4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zcthrowingnew-assume-operator-new-throws"></a>/ZC:throwingNew (lança novos pressupor operador)

Quando o **/Zc:throwingNew** opção for especificada, o compilador otimiza a chamadas para `operator new` para ignorar a procura um retorno de ponteiro nulo. Essa opção informa ao compilador para assumir que vinculados implementações de `operator new` e alocadores personalizados está de acordo com o padrão do C++ e lançam em caso de falha de alocação. Por padrão no Visual Studio, o compilador gera pessimistically verificações nulas (**/Zc:throwingNew-**) para essas chamadas, pois os usuários podem vincular com uma implementação de não lançamento de `operator new` ou gravar rotinas de alocador personalizado que retornam ponteiros nulos.

## <a name="syntax"></a>Sintaxe

> **/Zc:throwingNew**[**-**]

## <a name="remarks"></a>Comentários

Desde o ISO C + + 98, o padrão tiver especificado que o padrão [operador novo](../../standard-library/new-operators.md#op_new) lança `std::bad_alloc` quando ocorre falha na alocação de memória. Versões do Visual C++ para Visual Studio 6.0 retornou um ponteiro nulo em uma falha de alocação. A partir do Visual Studio 2002, `operator new` está em conformidade com o padrão e lança em caso de falha. Para dar suporte a código que usa o estilo de alocação mais antigo, o Visual Studio fornece uma implementação linkable de `operator new` em nothrownew.obj que retorna um ponteiro nulo em caso de falha. Por padrão, o compilador gera também defesa verificações nulas para impedir que esses alocadores de estilo antigo causando uma falha imediata em caso de falha. O **/Zc:throwingNew** opção informa ao compilador para deixar essas verificações nulas, na suposição de que todos os vinculados memória alocadores de acordo com o padrão. Isso não se aplica a explícita não lançam `operator new` sobrecargas, que são declaradas usando um parâmetro adicional do tipo `std::nothrow_t` e tiver um explícita `noexcept` especificação.

Conceitualmente, para criar um objeto de armazenamento livre, o compilador gera código para alocar a memória e, em seguida, chamar seu construtor para inicializar a memória. Porque o compilador do Visual C++, normalmente não é possível determinar se esse código será vinculado um alocador de não conformidade, não lançar, por padrão ela também gera uma verificação de nulos antes de chamar o construtor. Isso impede que um ponteiro nulo desreferência na chamada de construtor, se uma alocação de não lançamento falhar. Na maioria dos casos, essas verificações são desnecessárias, porque o padrão `operator new` alocadores throw em vez de retornar os ponteiros nulos. As verificações também tem efeitos colaterais da ruim. Eles inchar o tamanho de código, eles inundam o indicador de ramificação e eles inibem outras otimizações de compilador útil como devirtualization ou const propagação fora do objeto inicializado. As verificações existem somente ao código de suporte que vincula a *nothrownew.obj* ou tiver personalizado não conformes `operator new` implementações. Se você não usar não conformes `operator new`, recomendamos que você use **/Zc:throwingNew** para otimizar seu código.

O **/Zc:throwingNew** opção é desativada por padrão e não é afetada pelo [/ permissivo-](permissive-standards-conformance.md) opção.

Se você compila usando a geração de código para link-time (/ltcg), você não precisa especificar **/Zc:throwingNew**. Quando seu código é compilado usando LTCG, o compilador pode detectar se o padrão, conforme `operator new` implementação é usada. Nesse caso, o compilador omite as verificações nulas automaticamente. O vinculador procura o **/ThrowingNew** sinalizador para informar se a implementação de `operator new` está de acordo. Você pode especificar esse sinalizador para o vinculador, incluindo essa diretiva na fonte para a implementação do novo operador personalizado:

```cpp
#pragma comment(linker, "/ThrowingNew")
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Do **configuração** menu suspenso, escolha **todas as configurações de**.

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:throwingNew** ou **/Zc:throwingNew-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[noexcept (C++)](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar) (C++)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[encerrar (exceção)](../../standard-library/exception-functions.md#terminate)<br/>
