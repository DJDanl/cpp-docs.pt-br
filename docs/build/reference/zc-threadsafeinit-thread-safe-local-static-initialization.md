---
title: '/ZC: threadsafeinit (thread-safe inicialização estática de Local)'
ms.date: 03/14/2018
f1_keywords:
- threadSafeInit
- /Zc:threadSafeInit
helpviewer_keywords:
- -Zc compiler options (C++)
- threadSafeInit
- Thread-safe Local Static Initialization
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: a0fc4b34-2cf0-45a7-a642-b8afc4ca19f2
ms.openlocfilehash: 92a1bfa5ec3bab2814397d51e35e617b7666c706
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57808333"
---
# <a name="zcthreadsafeinit-thread-safe-local-static-initialization"></a>/ZC: threadsafeinit (thread-safe inicialização estática de Local)

O **/ZC: threadsafeinit** opção de compilador informa ao compilador para inicializar as variáveis locais estáticas (escopo da função) de uma maneira thread-safe, eliminando a necessidade de sincronização manual. Somente a inicialização é thread-safe. Uso e a modificação de variáveis locais estáticas por vários threads devem ainda ser sincronizados manualmente. Essa opção está disponível a partir do Visual Studio 2015. Por padrão, o Visual Studio habilita essa opção.

## <a name="syntax"></a>Sintaxe

> **/Zc:threadSafeInit**[**-**]

## <a name="remarks"></a>Comentários

No c++11 standard, variáveis de escopo de bloco com estática ou duração de armazenamento de thread deve ser inicializada do zero antes que qualquer outra inicialização ocorra. A inicialização ocorre quando o controle passa pela primeira vez por meio da declaração da variável. Se uma exceção é lançada durante a inicialização, a variável é considerada não inicializado e a inicialização é tentada novamente o próximo controle de tempo se passa por meio da declaração. Se o controle insere a declaração simultaneamente com a inicialização, os blocos de execução simultânea, enquanto a inicialização é concluída. O comportamento será indefinido se o controle entra novamente recursivamente a declaração durante a inicialização. Por padrão, o Visual Studio, iniciando no Visual Studio 2015 implementa esse comportamento padrão. Esse comportamento pode ser especificado explicitamente, definindo a **/ZC: threadsafeinit** opção de compilador.

O **/ZC: threadsafeinit** opção de compilador é ativado por padrão. O [/permissive--](permissive-standards-conformance.md) opção não afeta **/ZC: threadsafeinit**.

Inicialização de thread-safe de variáveis locais estáticas depende do código implementado na biblioteca de tempo de execução do C Universal (UCRT). Para evitar uma dependência no UCRT, ou para preservar o comportamento de inicialização de thread seguro de versões do Visual Studio antes do Visual Studio 2015, use o **/Zc:threadSafeInit-** opção. Se você souber que acesso thread-safe não é necessária, use esta opção para gerar código um pouco menores e mais rápido em torno de declarações local estáticos.

As variáveis locais estáticas thread-safe usam armazenamento local de thread (TLS) internamente para fornecer execução eficiente quando estático já foi inicializado. A implementação desse recurso depende de funções de suporte do sistema operacional Windows no Windows Vista e sistemas operacionais posteriores. Windows XP, Windows Server 2003 e sistemas operacionais mais antigos não tem esse suporte, portanto, não recebem a vantagem de eficiência. Esses sistemas operacionais também tem um limite inferior no número de seções TLS que pode ser carregado. Excedendo os TLS limite seção pode causar uma falha. Se esse for um problema em seu código, especialmente no código que deve ser executado em sistemas operacionais mais antigos, use **/Zc:threadSafeInit-** para desabilitar o código de inicialização thread-safe.

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Dos **configurações** menu suspenso, escolha **todas as configurações de**.

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: threadsafeinit** ou **/Zc:threadSafeInit-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
