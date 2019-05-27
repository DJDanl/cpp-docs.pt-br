---
title: /Qspectre
ms.date: 10/12/2018
f1_keywords:
- /Qspectre
helpviewer_keywords:
- /Qspectre
ms.openlocfilehash: e44416a44a9f772c17bc734d26c62ff87be775c8
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837413"
---
# <a name="qspectre"></a>/Qspectre

Especifica a geração do compilador de instruções para atenuar algumas vulnerabilidades de segurança da variante 1 de Espectro.

## <a name="syntax"></a>Sintaxe

> **/Qspectre**

## <a name="remarks"></a>Comentários

A opção **/Qspectre** está disponível no Visual Studio 2017 versão 15.5.5 e posterior, bem como no Visual Studio 2015 Atualização 3 por meio da [KB 4338871](https://support.microsoft.com/help/4338871/visual-studio-2015-update-3-spectre-variant-1-toolset-qspectre). Ela faz com que o compilador insira instruções para atenuar algumas [vulnerabilidades de segurança de Espectro](https://spectreattack.com/spectre.pdf). Essas vulnerabilidades, chamadas *ataques de temporização de execução especulativa*, afetam muitos sistemas operacionais e processadores modernos, incluindo processadores da Intel, da AMD e da ARM.

A opção **/Qspectre** está desativada por padrão.

Em sua versão inicial, a opção **/Qspectre** só funcionava no código otimizado. No Visual Studio 2017 versão 15.7 e posterior, há suporte para a opção **/Qspectre** em todos os níveis de otimização.

As bibliotecas do Microsoft Visual C++ também estão disponíveis em versões de mitigação de Espectro. As bibliotecas atenuadas para Espectro para o Visual Studio 2017 e posterior podem ser baixadas no Instalador do Visual Studio. Elas são encontradas na guia **Componentes Individuais** em **Compiladores, ferramentas de build e tempos de execução** e têm "Bibliotecas para Espectro" no nome. As bibliotecas DLL e de tempo de execução estáticas com a mitigação habilitada estão disponíveis para um subconjunto dos tempos de execução do Visual C++: Código de inicialização do VC++, vcruntime140, msvcp140, concrt140 e vcamp140. As DLLs são compatíveis apenas com a implantação local do aplicativo; o conteúdo das Bibliotecas de Tempo de Execução do Visual C++ 2017 e posterior não foi modificado. Instale também as bibliotecas atenuadas para Espectro para o MFC e a ATL, encontradas na guia **Componentes Individuais** em **SDKs, bibliotecas e estruturas**.

### <a name="applicability"></a>Aplicabilidade

Se o código opera em dados que cruzam um limite de confiança, recomendamos que você use a opção **/Qspectre** para recompilar e reimplantar o código a fim de atenuar esse problema o mais rápido possível. Exemplos de código que operam nos dados que cruzam um limite de confiança incluem o código que carrega uma entrada não confiável que pode afetar a execução, por exemplo, o código que faz chamadas de procedimento remoto, analisa uma entrada ou arquivos não confiáveis ou usa outras interfaces locais de IPC (comunicação entre processos). As técnicas padrão de área restrita podem não ser suficientes. Você deve investigar as áreas restritas cuidadosamente antes de decidir se o código não cruza um limite de confiança.

### <a name="availability"></a>Disponibilidade

A opção **/Qspectre** está disponível no Visual Studio 2017 versão 15.5.5 e em todas as atualizações nos compiladores do Microsoft MSVC feitas em 23 de janeiro de 2018 ou após essa data. Use o Instalador do Visual Studio para atualizar o compilador e instalar as bibliotecas atenuadas para Espectro como componentes individuais. A opção **/Qspectre** também está disponível no Visual Studio 2015 Atualização 3 por meio de um patch. Para obter mais informações, confira [KB 4338871](https://support.microsoft.com/help/4338871).

Todas as versões do Visual Studio 2017 versão 15.5 e todas as Versões Prévias do Visual Studio 2017 versão 15.6 incluem uma opção não documentada, **/d2guardspecload**, que é equivalente ao comportamento inicial de **/Qspectre**. Use **/d2guardspecload** para aplicar as mesmas mitigações ao código nessas versões do compilador. Atualize o build para usar **/Qspectre** nos compiladores que dão suporte à opção; a opção **/Qspectre** também pode dar suporte a novas mitigações em versões posteriores do compilador.

### <a name="effect"></a>Efeito

A opção **/Qspectre** produz um código para atenuar a variante 1 de Espectro, Bypass de Verificação de Limites, [CVE-2017-5753](https://nvd.nist.gov/vuln/detail/CVE-2017-5753). Ela funciona pela inserção de instruções que funcionam como uma barreira para a execução especulativa de código. As instruções específicas usadas para atenuar a especulação do processador dependem do processador e de sua microarquitetura e podem ser alteradas em versões futuras do compilador.

Quando a opção **/Qspectre** é habilitada, o compilador tenta identificar as instâncias em que a execução especulativa pode ignorar as verificações de limites e insere as instruções de barreira. É importante observar que há limites para a análise que podem ser executados por um compilador para identificar instâncias da variante 1. Dessa forma, não há nenhuma garantia de que todas as possíveis instâncias da variante 1 sejam instrumentadas em **/Qspectre**.

### <a name="performance-impact"></a>Impacto no desempenho

O impacto no desempenho de **/Qspectre** foi considerado insignificante em várias bases de código muito grandes, mas não há nenhuma garantia de que o desempenho do código em **/Qspectre** permanecerá inalterado. Você deve submeter o código a benchmark para determinar o efeito da opção no desempenho. Se você souber que a mitigação não será necessária em um bloco ou um loop crítico para o desempenho, a mitigação poderá ser desabilitada seletivamente pelo uso de uma diretiva [__declspec(spectre(nomitigation))](../../cpp/spectre.md). Essa diretiva não está disponível nos compiladores que só dão suporte à opção **/d2guardspecload**.

### <a name="required-libraries"></a>Bibliotecas necessárias

A opção do compilador **/Qspectre** gera um código que vincula implicitamente versões das bibliotecas de tempo de execução que foram compiladas para fornecer mitigações de Espectro. Essas bibliotecas são componentes opcionais que precisam ser instalados usando o Instalador do Visual Studio:

- Versão do MSVC *números_de_versão* Bibliotecas para Espectro \[(x86 e x64) | (ARM) | (ARM64)]
- ATL do Visual C++ para \[(x86/x64) | ARM | ARM64] com Mitigações de Espectro
- MFC do Visual C++ para \[x86/x64 | ARM | ARM64] com Mitigações de Espectro

Se você compilar o código usando **/Qspectre** e essas bibliotecas não forem instaladas, o sistema de build relatará o **aviso MSB8038: A mitigação de Espectro está habilitada, mas não foram encontradas bibliotecas atenuadas para Espectro**. Se houver falha de build no código MFC ou ATL e o vinculador relatar um erro, como **erro fatal LNK1104: não é possível abrir o arquivo 'oldnames.lib'**, essas bibliotecas ausentes poderão ser a causa disso.

### <a name="additional-information"></a>Informações adicionais

Para obter mais detalhes, confira o [Microsoft Security Advisory ADV180002 oficial, Diretrizes para mitigação das vulnerabilidades de ataques de temporização de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002). As diretrizes também estão disponível na Intel, [Mitigações de ataques de temporização de execução especulativa](https://software.intel.com/sites/default/files/managed/c5/63/336996-Speculative-Execution-Side-Channel-Mitigations.pdf), e na ARM, [Ataques de temporização de especulação de cache](https://developer.arm.com/-/media/Files/pdf/Cache_Speculation_Side-channels.pdf). Para obter uma visão específica do Windows das mitigações de Espectro e Meltdown, confira [Noções básicas sobre o impacto no desempenho das mitigações de Espectro e Meltdown em sistemas Windows](https://cloudblogs.microsoft.com/microsoftsecure/2018/01/09/understanding-the-performance-impact-of-spectre-and-meltdown-mitigations-on-windows-systems/) no blog do Microsoft Secure. Para obter uma visão geral da vulnerabilidade de Espectro resolvida pelas mitigações do MSVC, confira [Mitigações de Espectro no MSVC](https://blogs.msdn.microsoft.com/vcblog/2018/01/15/spectre-mitigations-in-msvc./) no blog da equipe do Visual C++.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++** > **Linha de Comando**.

1. Insira a opção do compilador **/Qspectre** na caixa **Opções Adicionais**. Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
