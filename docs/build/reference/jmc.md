---
title: /JMC (depuração Apenas Meu Código)
ms.date: 08/20/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.SupportJustMyCode
helpviewer_keywords:
- /JMC compiler option [C++]
- Just my code [C++]
- -JMC compiler option [C++]
- User code, debugging
- JMC compiler option [C++]
ms.openlocfilehash: 7b22a754f9f49564cd7f76c7d1989cd562f70874
ms.sourcegitcommit: 31a443c9998cf5cfbaff00fcf815b133f55b2426
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/14/2020
ms.locfileid: "86373873"
---
# <a name="jmc-just-my-code-debugging"></a>/JMC (depuração Apenas Meu Código)

Especifica o suporte do compilador para a depuração de *apenas meu código* nativa no depurador do Visual Studio. Essa opção dá suporte às configurações de usuário que permitem que o Visual Studio Percorra o sistema, a estrutura, a biblioteca e outras chamadas não do usuário e recolha essas chamadas na janela pilha de chamadas. A opção de compilador **/JMC** está disponível a partir do Visual Studio 2017 versão 15,8.

## <a name="syntax"></a>Syntax

> **/JMC** \[ **-** ]

## <a name="remarks"></a>Comentários

As configurações de [apenas meu código](/visualstudio/debugger/just-my-code) do Visual Studio especificam se o depurador do Visual Studio percorre o sistema, a estrutura, a biblioteca e outras chamadas que não são do usuário. A opção de compilador **/JMC** habilita o suporte para depuração de apenas meu código em seu código C++ nativo. Quando **/JMC** está habilitado, o compilador insere chamadas para uma função auxiliar, `__CheckForDebuggerJustMyCode` , no prólogo da função. A função auxiliar fornece ganchos que dão suporte ao depurador do Visual Studio Apenas Meu Código operações de etapa. Para habilitar apenas meu código no depurador do Visual Studio, na barra de menus, escolha **ferramentas**  >  **Opções**e, em seguida, defina a opção em **depuração**  >  **geral**  >  **habilitar apenas meu código**.

A opção **/JMC** requer que seu código seja vinculado à biblioteca de tempo de execução C (CRT), que fornece a `__CheckForDebuggerJustMyCode` função auxiliar. Se o seu projeto não vincular ao CRT, você poderá ver o erro do vinculador **LNK2019: símbolo externo não resolvido __CheckForDebuggerJustMyCode**. Para resolver esse erro, vincule ao CRT ou desabilite a opção **/JMC** .

Por padrão, a opção de compilador **/JMC** é off. No entanto, a partir do Visual Studio 2017 versão 15,8 essa opção é habilitada na maioria dos modelos de projeto do Visual Studio. Para desabilitar explicitamente essa opção, use a opção **/JMC-** na linha de comando. No Visual Studio, abra a caixa de diálogo páginas de propriedades do projeto e altere a propriedade **suporte apenas meu código depuração** na página de **Configuration Properties**  >  Propriedade geral**C/C++** propriedades  >  **General** de configuração para **não**.

Para obter mais informações, consulte [C++ apenas meu código](/visualstudio/debugger/just-my-code#BKMK_C___Just_My_Code) em [especificar se deseja depurar apenas o código do usuário usando apenas meu código no Visual Studio](/visualstudio/debugger/just-my-code)e a postagem do Blog da equipe do Visual C++ [anunciando o C++ apenas meu código stepping no Visual Studio](https://devblogs.microsoft.com/cppblog/announcing-jmc-stepping-in-visual-studio/).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade geral**C/C++** Propriedades de configuração  >  **General** .

1. Modifique a propriedade de **depuração de apenas meu código de suporte** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
