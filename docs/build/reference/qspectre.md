---
title: /Qspectre | Microsoft Docs
ms.custom: ''
ms.date: 1/23/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
f1_keywords:
- /Qspectre
helpviewer_keywords:
- /Qspectre
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6a74c6c7c2ee7aab175d7e136e5cf02a8d9f8bfc
ms.sourcegitcommit: bad2441d1930275ff506d44759d283d94cccd1c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2018
ms.locfileid: "39375871"
---
# <a name="qspectre"></a>/Qspectre

Especifica a geração de compilador de instruções para atenuar as vulnerabilidades de segurança de variante 1 determinados espectro.

## <a name="syntax"></a>Sintaxe

> **/Qspectre**

## <a name="remarks"></a>Comentários

O **/Qspectre** opção faz com que o compilador a inserir instruções para atenuar certos [vulnerabilidades de segurança do Spectre](https://spectreattack.com/spectre.pdf). Essas vulnerabilidades, chamadas *ataques de canal lateral de execução especulativa*, afetar muitos sistemas operacionais e processadores modernos, incluindo processadores da Intel, AMD e ARM.

O **/Qspectre** opção está desativada por padrão.

Em sua versão inicial, o **/Qspectre** opção funciona apenas em código otimizado. Você deve certificar-se de compilar seu código com qualquer uma das opções de otimização (por exemplo, [/O2 ou/O1](o1-o2-minimize-size-maximize-speed.md) , mas não [/Od](od-disable-debug.md)) para garantir que a atenuação é aplicada. Da mesma forma, inspecione qualquer código que usa [#pragma otimizar ("stg", off)](../../preprocessor/optimize.md).

### <a name="applicability"></a>Aplicabilidade

Se seu código opera em dados que cruza um limite de confiança, é recomendável que você use o **/Qspectre** opção recompilar e reimplantar o código para atenuar esse problema assim que possível. Exemplos de código que opera nos dados que cruza um limite de confiança incluem o código que carrega a entrada não confiável que pode afetar a execução, por exemplo, o código que faz o procedimento remoto chama, analisa os arquivos ou entradas não confiáveis ou usa outro processo entre locais interfaces de comunicação entre processos (IPC). Técnicas de áreas de segurança padrão podem não ser suficientes. Você deve investigar suas áreas de segurança cuidadosamente antes de decidir que seu código não cruza um limite de confiança.

### <a name="availability"></a>Disponibilidade

O **/Qspectre** opção está disponível no Visual Studio 2017 versão 15.5.5 e todas as atualizações para os compiladores do Microsoft Visual C++ (MSVC) feitas em ou após 23 de janeiro de 2018.

Todas as versões do Visual Studio 2017 versão 15.5 e todas as versões prévias do Visual Studio versão 15.6 já incluem uma opção não documentada, **/d2guardspecload**, que é equivalente ao comportamento inicial de **/Qspectre**. Você pode usar **/d2guardspecload** para aplicar as atenuações mesmas ao seu código nessas versões do compilador. Atualize sua compilação para usar **/Qspectre** nos compiladores que dão suporte à opção; a **/Qspectre** opção também pode oferecer suporte atenuações de novo nas versões posteriores do compilador.

### <a name="effect"></a>Efeito

O **/Qspectre** opção produz código para reduzir a variante de fantasma 1, ignorar verificação dos limites, [CVE 2017-5753](https://nvd.nist.gov/vuln/detail/CVE-2017-5753). Ele funciona através da inserção de instruções que agem como uma barreira de execução especulativa de código. As instruções específicas usadas para atenuar especulação processador dependem do processador e sua arquitetura de micro e podem mudar em futuras versões do compilador.

Quando o **/Qspectre** opção é habilitada, o compilador tenta identificar instâncias em que a execução especulativa pode ignorar as verificações de limites e insere as instruções de barreira. É importante observar que há limites para a análise que pode ser executadas por um compilador para identificar instâncias da variante 1. Como tal, não há nenhuma garantia de que todas as instâncias possíveis de variante 1 são instrumentadas sob **/Qspectre**.

### <a name="performance-impact"></a>Impacto de desempenho

O impacto de desempenho **/Qspectre** foi visto ser insignificante em várias bases de código muito grandes, mas não há nenhuma garantia que o desempenho do seu código em **/Qspectre** permanecerá inalterado. Você deve avaliar o desempenho de seu código para determinar o efeito da opção no desempenho. Se você souber que a atenuação não será necessária em um bloco de desempenho crítico ou de um loop, a mitigação pode ser seletivamente desabilitada pelo uso de um [__declspec(spectre(nomitigation))](../../cpp/spectre.md) diretiva. Essa diretiva não está disponível nos compiladores que dão suporte apenas a **/d2guardspecload** opção.

### <a name="required-libraries"></a>Bibliotecas necessárias

O **/Qspectre** opção de compilador gera código que vincula-se versões das bibliotecas de tempo de execução que foram criadas para fornecer mitigações implicitamente. Essas bibliotecas são componentes opcionais que devem ser instalados usando o instalador do Visual Studio:

- VC + + 2017 versão *número_da_versão* Libs para Spectre (x86 e x64)
- ATL do Visual C++ (x86/x64) com mitigações de Spectre
- MFC do Visual C++ para x86/x64 com mitigações de Spectre

Se você compilar seu código usando **/Qspectre** e essas bibliotecas não são instalados, os relatórios do sistema de compilação **aviso MSB8038: mitigação do Spectre está habilitada, mas não foram encontradas bibliotecas atenuadas do Spectre**. Se seu código MFC ou ATL apresentou falha na criação e o vinculador relata um erro, como **erro fatal LNK1104: não é possível abrir o arquivo 'oldnames. lib'**, essas bibliotecas ausentes podem ser a causa.

### <a name="additional-information"></a>Informações adicionais

Para obter mais detalhes, consulte oficial [Microsoft Security Advisory ADV180002, orientações para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002). Diretrizes também estão disponível da Intel, [atenuações de canal de lado execução especulativa](https://software.intel.com/sites/default/files/managed/c5/63/336996-Speculative-Execution-Side-Channel-Mitigations.pdf)e ARM, [canais do lado do Cache especulação](https://developer.arm.com/-/media/Files/pdf/Cache_Speculation_Side-channels.pdf). Para obter uma visão específica do Windows mitigações de Spectre e Meltdown, consulte [Noções básicas sobre o impacto no desempenho mitigações de Spectre e Meltdown em sistemas Windows](https://cloudblogs.microsoft.com/microsoftsecure/2018/01/09/understanding-the-performance-impact-of-spectre-and-meltdown-mitigations-on-windows-systems/) no blog do Microsoft Secure. Para uma visão geral de vulnerabilidade do Spectre endereçada pelas atenuações MSVC, consulte [mitigações em MSVC](https://blogs.msdn.microsoft.com/vcblog/2018/01/15/spectre-mitigations-in-msvc./) no Blog da equipe do Visual C++.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira o **/Qspectre** opção de compilador na **opções adicionais** caixa. Escolher **Okey** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
