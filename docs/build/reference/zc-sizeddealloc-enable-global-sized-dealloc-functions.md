---
title: '/ZC: sizeddealloc (habilitar Global funções desalocação de tamanho)'
ms.date: 03/06/2018
f1_keywords:
- sizedDealloc
- /Zc:sizedDealloc
helpviewer_keywords:
- -Zc compiler options (C++)
- sizedDealloc
- Enable Global Sized Deallocation Functions
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 3a73ace0-4d36-420a-b699-0ca6fc0dd134
ms.openlocfilehash: dc381058c6a2ef84542be1d3cdd00c410aa51c2f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809292"
---
# <a name="zcsizeddealloc-enable-global-sized-deallocation-functions"></a>/ZC: sizeddealloc (habilitar Global funções desalocação de tamanho)

O **/ZC: sizeddealloc** opção de compilador informa ao compilador para chamar preferencialmente global `operator delete` ou `operator delete[]` funções que têm um segundo parâmetro do tipo `size_t` quando o tamanho do objeto está disponível. Essas funções podem usar o `size_t` parâmetro para otimizar o desempenho de desalocador.

## <a name="syntax"></a>Sintaxe

> **/Zc:sizedDealloc**[**-**]

## <a name="remarks"></a>Comentários

No c++11 standard, você pode definir funções de membro estático `operator delete` e `operator delete[]` que usam um segundo, `size_t` parâmetro. Normalmente, eles são usados em combinação com [operador new](../../cpp/new-operator-cpp.md) funções para implementar mais eficiente alocadores e deallocators para o objeto. No entanto, o c++11 não definiu um conjunto equivalente de funções de desalocação no escopo global. No C++ 11, global funções de desalocação de que tem um segundo parâmetro do tipo `size_t` são consideradas funções delete de posicionamento. Eles devem ser chamados explicitamente passando um argumento de tamanho.

O padrão c++14 altera o comportamento do compilador. Quando você define global `operator delete` e `operator delete[]` que levam um segundo parâmetro do tipo `size_t`, o compilador prefere chamar essas funções quando as versões de escopo do membro não são invocadas e o tamanho do objeto está disponível. O compilador passa o argumento de tamanho implicitamente. As versões de argumento único são chamadas quando o compilador não pode determinar o tamanho do objeto que está sendo desalocado. Caso contrário, as regras comuns para escolher a versão da função de desalocação invocar ainda se aplicam. Chamadas para as funções globais podem ser especificadas explicitamente acrescentando o operador de resolução de escopo (`::`) para a chamada de função de desalocação.

Por padrão, o Visual C++ a partir do Visual Studio 2015 implementa esse padrão comportamento do c++14. Você pode especificar isso explicitamente, definindo a **/ZC: sizeddealloc** opção de compilador. Isso representa um potencialmente interrompendo alteração. Use o **/Zc:sizedDealloc-** opção para preservar o comportamento antigo, por exemplo, quando seu código define os operadores de delete de posicionamento que usam um segundo parâmetro do tipo `size_t`. As implementações de biblioteca do Visual Studio padrão das funções de desalocação globais que têm o segundo parâmetro do tipo `size_t` chamar as versões de único parâmetro. Se seu código fornece o único parâmetro único global exclusão de operador e operador delete [], as implementações da biblioteca padrão das funções de desalocação dimensionada global invocam funções globais.

O **/ZC: sizeddealloc** opção de compilador é ativado por padrão. O [/permissive--](permissive-standards-conformance.md) opção não afeta **/ZC: sizeddealloc**.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Dos **configurações** menu suspenso, escolha **todas as configurações de**.

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: sizeddealloc** ou **/Zc:sizedDealloc-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
