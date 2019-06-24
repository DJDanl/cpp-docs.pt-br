---
title: /Qspectre
ms.date: 10/12/2018
f1_keywords:
- /Qspectre
helpviewer_keywords:
- /Qspectre
ms.openlocfilehash: e0d3af50015b77af297cbee22f439cd17d803de9
ms.sourcegitcommit: 6cf0c67acce633b07ff31b56cebd5de3218fd733
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/24/2019
ms.locfileid: "67344156"
---
# <a name="qspectre"></a>/Qspectre

Especifica a geração do compilador de instruções para atenuar algumas vulnerabilidades de segurança da variante 1 de Espectro.

## <a name="syntax"></a>Sintaxe

> **/Qspectre**

## <a name="remarks"></a>Comentários

A opção **/Qspectre** está disponível no Visual Studio 2017 versão 15.5.5 e posterior, bem como no Visual Studio 2015 Atualização 3 por meio da [KB 4338871](https://support.microsoft.com/help/4338871/visual-studio-2015-update-3-spectre-variant-1-toolset-qspectre). Ela faz com que o compilador insira instruções para atenuar algumas [vulnerabilidades de segurança de Espectro](https://spectreattack.com/spectre.pdf). Essas vulnerabilidades são chamadas *ataques de canal lateral de execução especulativa*. Elas afetam vários sistemas operacionais e processadores modernos, incluindo processadores da Intel, AMD e ARM.

A opção **/Qspectre** está desativada por padrão.

Em sua versão inicial, a opção **/Qspectre** só funcionava no código otimizado. No Visual Studio 2017 versão 15.7 e posterior, há suporte para a opção **/Qspectre** em todos os níveis de otimização.

As bibliotecas do Microsoft Visual C++ também estão disponíveis em versões de mitigação de Espectro. As bibliotecas atenuadas para Espectro para o Visual Studio 2017 e posterior podem ser baixadas no Instalador do Visual Studio. Encontradas na **componentes individuais** guia sob **compiladores, ferramentas de build e tempos de execução**, e ter "Bibliotecas para Spectre" no nome. As bibliotecas DLL e de tempo de execução estáticas com a mitigação habilitada estão disponíveis para um subconjunto dos tempos de execução do Visual C++: Código de inicialização do VC++, vcruntime140, msvcp140, concrt140 e vcamp140. As DLLs têm suporte para implantação de aplicativo local apenas. O conteúdo do Visual C++ 2017 e posterior tempo de execução de bibliotecas redistribuíveis ainda não foi modificado.

Você também pode instalar bibliotecas atenuadas de espectro para MFC e ATL. Eles são encontrados na **componentes individuais** guia sob **SDKs, bibliotecas e estruturas**.

### <a name="applicability"></a>Aplicabilidade

Se seu código opera em dados que cruza um limite de confiança, em seguida, é recomendável usar o **/Qspectre** opção recompilar e reimplantar o código para atenuar esse problema assim que possível. Um exemplo de código, é o código que carrega a entrada não confiável que pode afetar a execução. Por exemplo, o código que faz o procedimento remoto chama, analisa os arquivos ou entradas não confiáveis ou usa outras interfaces de local de comunicação entre processos (IPC). As técnicas padrão de área restrita podem não ser suficientes. Investigar suas áreas de segurança cuidadosamente antes de decidir que seu código não cruze um limite de confiança.

### <a name="availability"></a>Disponibilidade

O **/Qspectre** opção está disponível no Visual Studio 2017 versão 15.5.5 e em todas as atualizações para a Microsoft C++ compiladores (MSVC) feitos em ou após 23 de janeiro de 2018. Use o Instalador do Visual Studio para atualizar o compilador e instalar as bibliotecas atenuadas para Espectro como componentes individuais. A opção **/Qspectre** também está disponível no Visual Studio 2015 Atualização 3 por meio de um patch. Para obter mais informações, confira [KB 4338871](https://support.microsoft.com/help/4338871).

Todas as versões do Visual Studio 2017 versão 15.5 e todas as versões prévias do Visual Studio 2017 versão 15.6. incluir uma opção de não documentada **/d2guardspecload**. É equivalente ao comportamento de inicial **/Qspectre**. Use **/d2guardspecload** para aplicar as mesmas mitigações ao código nessas versões do compilador. É recomendável que você atualize sua compilação para usar **/Qspectre** nos compiladores que dão suporte a opção. O **/Qspectre** opção também pode oferecer suporte atenuações de novo nas versões posteriores do compilador.

### <a name="effect"></a>Efeito

A opção **/Qspectre** produz um código para atenuar a variante 1 de Espectro, Bypass de Verificação de Limites, [CVE-2017-5753](https://nvd.nist.gov/vuln/detail/CVE-2017-5753). Ela funciona pela inserção de instruções que funcionam como uma barreira para a execução especulativa de código. As instruções específicas usadas para atenuar a especulação do processador dependem do processador e de sua microarquitetura e podem ser alteradas em versões futuras do compilador.

Quando você habilita o **/Qspectre** opção, o compilador tenta identificar instâncias em que a execução especulativa pode ignorar verificações de limites. Isso é onde ele insere as instruções de barreira. É importante estar ciente dos limites para a análise de um compilador pode fazer para identificar instâncias da variante 1. Como tal, não há nenhuma garantia de que todas as instâncias possíveis de variante 1 são instrumentadas sob **/Qspectre**.

### <a name="performance-impact"></a>Impacto no desempenho

O impacto de desempenho **/Qspectre** parecia ser insignificante em várias bases de código dimensionável. No entanto, não há nenhuma garantia de que o desempenho do seu código sob **/Qspectre** permanecerá inalterado. Você deve submeter o código a benchmark para determinar o efeito da opção no desempenho. Se você souber que não é necessário que a atenuação em um bloco de desempenho crítico ou de um loop, você pode desabilitar seletivamente a atenuação através do uso de um [__declspec(spectre(nomitigation))](../../cpp/spectre.md) diretiva. Essa diretiva não está disponível nos compiladores que dão suporte apenas a **/d2guardspecload** opção.

### <a name="required-libraries"></a>Bibliotecas necessárias

O **/Qspectre** opção de compilador gera código que vincula-se versões das bibliotecas de tempo de execução criadas para fornecer mitigações implicitamente. Essas bibliotecas são componentes opcionais que precisam ser instalados usando o Instalador do Visual Studio:

- Versão do MSVC *números_de_versão* Bibliotecas para Espectro \[(x86 e x64) | (ARM) | (ARM64)]
- ATL do Visual C++ para \[(x86/x64) | ARM | ARM64] com Mitigações de Espectro
- MFC do Visual C++ para \[x86/x64 | ARM | ARM64] com Mitigações de Espectro

Se você compilar seu código usando **/Qspectre** e essas bibliotecas não são instalados, os relatórios do sistema de compilação **aviso MSB8038: A mitigação de Espectro está habilitada, mas não foram encontradas bibliotecas atenuadas para Espectro**. Se seu código MFC ou ATL apresentou falha na criação e o vinculador relata um erro, como **erro fatal LNK1104: não é possível abrir o arquivo 'oldnames. lib'** , essas bibliotecas ausentes podem ser a causa.

### <a name="additional-information"></a>Informações adicionais

Para obter mais informações, consulte oficial [Microsoft Security Advisory ADV180002, orientações para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002). As diretrizes também estão disponível na Intel, [Mitigações de ataques de temporização de execução especulativa](https://software.intel.com/sites/default/files/managed/c5/63/336996-Speculative-Execution-Side-Channel-Mitigations.pdf), e na ARM, [Ataques de temporização de especulação de cache](https://developer.arm.com/-/media/Files/pdf/Cache_Speculation_Side-channels.pdf). Para obter uma visão específica do Windows mitigações de Spectre e Meltdown, consulte [Noções básicas sobre o impacto no desempenho mitigações de Spectre e Meltdown em sistemas Windows](https://www.microsoft.com/security/blog/2018/01/09/understanding-the-performance-impact-of-spectre-and-meltdown-mitigations-on-windows-systems/). Para uma visão geral de vulnerabilidades do Spectre endereçado pelas atenuações MSVC, consulte [mitigações em MSVC](https://devblogs.microsoft.com/cppblog/spectre-mitigations-in-msvc./) sobre o C++ Blog da equipe.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Insira a opção do compilador **/Qspectre** na caixa **Opções Adicionais**. Escolha **OK** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
