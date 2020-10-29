---
title: /Qspectre
ms.date: 09/06/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.SpectreMitigation
helpviewer_keywords:
- /Qspectre
ms.openlocfilehash: a4872d18fed4523e235aee70839f1e482d78f345
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919105"
---
# <a name="qspectre"></a>/Qspectre

Especifica a geração do compilador de instruções para atenuar algumas vulnerabilidades de segurança da variante 1 de Espectro.

## <a name="syntax"></a>Syntax

> **/Qspectre**

## <a name="remarks"></a>Comentários

A opção **/Qspectre** está disponível no Visual Studio 2017 versão 15.5.5 e posterior, bem como no Visual Studio 2015 Atualização 3 por meio da [KB 4338871](https://support.microsoft.com/help/4338871/visual-studio-2015-update-3-spectre-variant-1-toolset-qspectre). Ela faz com que o compilador insira instruções para atenuar algumas [vulnerabilidades de segurança de Espectro](https://spectreattack.com/spectre.pdf). Essas vulnerabilidades são chamadas *de ataques de canal lateral de execução especulativa* . Eles afetam muitos sistemas operacionais e processadores modernos, incluindo processadores da Intel, AMD e ARM.

A opção **/Qspectre** está desativada por padrão.

Em sua versão inicial, a opção **/Qspectre** só funcionava no código otimizado. No Visual Studio 2017 versão 15.7 e posterior, há suporte para a opção **/Qspectre** em todos os níveis de otimização.

As bibliotecas do Microsoft Visual C++ também estão disponíveis em versões de mitigação de Espectro. As bibliotecas atenuadas para Espectro para o Visual Studio 2017 e posterior podem ser baixadas no Instalador do Visual Studio. Eles são encontrados na guia **componentes individuais** em **compiladores, ferramentas de compilação e tempos de execução** e têm "bibliotecas para Spectre" no nome. As bibliotecas de tempo de execução estática e DLL com mitigação habilitada estão disponíveis para um subconjunto dos Visual C++ runtimes: código de inicialização do VC + +, vcruntime140, msvcp140, concrt140 e vcamp140. As DLLs têm suporte somente para implantação local do aplicativo. O conteúdo do Visual C++ 2017 e bibliotecas de tempo de execução posteriores redistribuíveis não foi modificado.

Você também pode instalar bibliotecas com mitigação Spectre para MFC e ATL. Eles são encontrados na guia **componentes individuais** em **SDKs, bibliotecas e estruturas** .

> [!NOTE]
> Não há versões de bibliotecas Spectre para aplicativos ou componentes do UWP (Universal Windows). A implantação de aplicativo local dessas bibliotecas não é possível.

### <a name="applicability"></a>Aplicabilidade

Se o seu código operar em dados que cruzam um limite de confiança, recomendamos que você use a opção **/Qspectre** para recompilar e reimplantar seu código para atenuar esse problema assim que possível. Um exemplo desse código é o código que carrega a entrada não confiável que pode afetar a execução. Por exemplo, o código que faz chamadas de procedimento remotos, analisa arquivos ou entradas não confiáveis ou usa outras interfaces de IPC (comunicação entre processos) locais. As técnicas padrão de área restrita podem não ser suficientes. Investigue suas áreas restritas cuidadosamente antes de decidir que seu código não cruza um limite de confiança.

### <a name="availability"></a>Disponibilidade

A opção **/Qspectre** está disponível no Visual Studio 2017 versão 15.5.5 e em todas as atualizações para compiladores do Microsoft C++ (MSVC) feitas em ou após 23 de janeiro de 2018. Use o Instalador do Visual Studio para atualizar o compilador e instalar as bibliotecas atenuadas para Espectro como componentes individuais. A opção **/Qspectre** também está disponível no Visual Studio 2015 Atualização 3 por meio de um patch. Para obter mais informações, confira [KB 4338871](https://support.microsoft.com/help/4338871).

Todas as versões do Visual Studio 2017 versão 15,5 e todas as visualizações do Visual Studio 2017 versão 15,6. inclua uma opção não documentada, **/d2guardspecload** . É equivalente ao comportamento inicial de **/Qspectre** . Use **/d2guardspecload** para aplicar as mesmas mitigações ao código nessas versões do compilador. Recomendamos que você atualize sua compilação para usar o **/Qspectre** em compiladores que dão suporte à opção. A opção **/Qspectre** também pode oferecer suporte a novas atenuações em versões posteriores do compilador.

### <a name="effect"></a>Efeito

A opção **/Qspectre** produz um código para atenuar a variante 1 de Espectro, Bypass de Verificação de Limites, [CVE-2017-5753](https://nvd.nist.gov/vuln/detail/CVE-2017-5753). Ela funciona pela inserção de instruções que funcionam como uma barreira para a execução especulativa de código. As instruções específicas usadas para atenuar a especulação do processador dependem do processador e de sua microarquitetura e podem ser alteradas em versões futuras do compilador.

Quando você habilita a opção **/Qspectre** , o compilador tenta identificar instâncias em que a execução especulativa pode ignorar as verificações de limites. É aí que insere as instruções de barreira. É importante estar ciente dos limites para a análise que um compilador pode fazer para identificar instâncias da variante 1. Como tal, não há nenhuma garantia de que todas as instâncias possíveis da variante 1 sejam instrumentadas em **/Qspectre** .

### <a name="performance-impact"></a>Impacto sobre o desempenho

O impacto no desempenho do **/Qspectre** parecia ser insignificante em várias bases de código dimensionáveis. No entanto, não há nenhuma garantia de que o desempenho do seu código em **/Qspectre** permaneça inalterado. Você deve submeter o código a benchmark para determinar o efeito da opção no desempenho. Se você souber que a mitigação não é necessária em um bloco ou loop de desempenho crítico, poderá desabilitar seletivamente a mitigação usando uma diretiva [__declspec (Spectre (nomitigation))](../../cpp/spectre.md) . Essa diretiva não está disponível em compiladores que dão suporte apenas à opção **/d2guardspecload** .

### <a name="required-libraries"></a>Bibliotecas necessárias

A opção de compilador **/Qspectre** gera um código que vincula implicitamente versões das bibliotecas de tempo de execução criadas para fornecer atenuações de Spectre. Essas bibliotecas são componentes opcionais que precisam ser instalados usando o Instalador do Visual Studio:

- Versão do MSVC *números_de_versão* Bibliotecas para Espectro \[(x86 e x64) | (ARM) | (ARM64)]
- ATL do Visual C++ para \[(x86/x64) | ARM | ARM64] com Mitigações de Espectro
- MFC do Visual C++ para \[x86/x64 | ARM | ARM64] com Mitigações de Espectro

Se você criar seu código usando o **/Qspectre** e essas bibliotecas não estiverem instaladas, o sistema de compilação relatará o **aviso MSB8038: a mitigação de Spectre será habilitada, mas as bibliotecas atenuadas do Spectre não serão encontradas** . Se o seu MFC ou código ATL não for compilado e o vinculador relatar um erro como **erro fatal LNK1104: não é possível abrir o arquivo ' OLDNAMES. lib '** , essas bibliotecas ausentes podem ser a causa.

### <a name="additional-information"></a>Informações adicionais

Para obter mais informações, consulte o Official [Microsoft Security Advisory ADV180002, orientação para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002). As diretrizes também estão disponível na Intel, [Mitigações de ataques de temporização de execução especulativa](https://software.intel.com/sites/default/files/managed/c5/63/336996-Speculative-Execution-Side-Channel-Mitigations.pdf), e na ARM, [Ataques de temporização de especulação de cache](https://developer.arm.com/-/media/Files/pdf/Cache_Speculation_Side-channels.pdf). Para obter uma visão geral específica do Windows das mitigações Spectre e Meltdown, consulte [noções básicas sobre o impacto no desempenho de mitigações de Spectre e de Meltdown em sistemas Windows](https://www.microsoft.com/security/blog/2018/01/09/understanding-the-performance-impact-of-spectre-and-meltdown-mitigations-on-windows-systems/). Para obter uma visão geral das vulnerabilidades do Spectre abordadas pelas atenuações do MSVC, consulte [mitigações do Spectre no MSVC](https://devblogs.microsoft.com/cppblog/spectre-mitigations-in-msvc./) no blog da equipe do C++.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

::: moniker range="msvc-160"

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração** de > geração de código **C/C++** > **Code Generation** .

1. Selecione um novo valor para a propriedade de **mitigação Spectre** . Escolha **OK** para aplicar a alteração.

::: moniker-end

::: moniker range="<=msvc-150"

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades de Configuração** > **C/C++** > **Linha de Comando** .

1. Insira a opção do compilador **/Qspectre** na caixa **Opções Adicionais** . Escolha **OK** para aplicar a alteração.

::: moniker-end

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Veja também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de Command-Line do compilador MSVC](compiler-command-line-syntax.md)
