---
title: / JMC (depuração apenas meu código)
ms.date: 08/20/2018
f1_keywords:
- /JMC
helpviewer_keywords:
- /JMC compiler option [C++]
- Just my code [C++]
- -JMC compiler option [C++]
- User code, debugging
- JMC compiler option [C++]
ms.openlocfilehash: d1950ff4a973ddbd23ff902ba4afb0d45dacb0e5
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417756"
---
# <a name="jmc-just-my-code-debugging"></a>/ JMC (depuração apenas meu código)

Especifica o suporte do compilador nativos *Just My Code* depuração no depurador do Visual Studio. Essa opção oferece suporte para as configurações do usuário que permitem que o Visual Studio execute step over no sistema, do framework, biblioteca e outras chamadas de não usuário e recolhe essas chamadas na janela de pilha de chamadas. O **/JMC** opção do compilador está disponível a partir do Visual Studio 2017 versão 15,8.

## <a name="syntax"></a>Sintaxe

> **/JMC**\[**-**]

## <a name="remarks"></a>Comentários

O Visual Studio [Just My Code](/visualstudio/debugger/just-my-code) configurações especificam se o depurador do Visual Studio as etapas de sistema, do framework, biblioteca e outras chamadas de não usuário. O **/JMC** opção de compilador habilita o suporte para depuração apenas meu código em seu código C++ nativo. Quando **/JMC** é habilitada, o compilador insere chamadas para uma função auxiliar, `__CheckForDebuggerJustMyCode`, no prólogo da função. A função auxiliar fornece ganchos que dão suporte a operações de etapa de apenas meu código de depurador do Visual Studio. Para habilitar apenas meu código no depurador do Visual Studio, na barra de menus, escolha **ferramentas** > **opções**e, em seguida, defina a opção no **depuração**  >  **Gerais** > **habilitar apenas meu código**.

O **/JMC** opção requer que seu código contém links para C Runtime Library (CRT), que fornece o `__CheckForDebuggerJustMyCode` função auxiliar. Se seu projeto não vincular ao CRT, você poderá ver o erro de vinculador **LNK2019: unresolved símbolo externo __CheckForDebuggerJustMyCode**. Para resolver esse erro, vincular ao CRT ou desabilitar a **/JMC** opção.

Por padrão, o **/JMC** opção de compilador está desativada. No entanto, a partir do Visual Studio 2017 versão 15,8 essa opção está habilitado na maioria dos modelos de projeto do Visual Studio. Para desabilitar explicitamente essa opção, use o **/JMC-** opção na linha de comando. No Visual Studio, abra a caixa de diálogo de páginas de propriedades do projeto e altere o **apenas meu código de depuração de suporte** propriedade no **propriedades de configuração** > **deC/C++**  >  **Gerais** a página de propriedades **não**.

Para obter mais informações, consulte [C++ Just My Code](/visualstudio/debugger/just-my-code#BKMK_C___Just_My_Code) na [Especifique se deseja depurar somente código do usuário usando o Just My Code no Visual Studio](/visualstudio/debugger/just-my-code)e o post do Blog da equipe do Visual C++ [anunciando C++ Just My Code Passo a passo no Visual Studio](https://blogs.msdn.microsoft.com/vcblog/2018/06/29/announcing-jmc-stepping-in-visual-studio/).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

1. Modificar a **apenas meu código de depuração de suporte** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
