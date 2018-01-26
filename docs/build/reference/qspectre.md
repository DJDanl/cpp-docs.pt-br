---
title: /Qspectre | Microsoft Docs
ms.custom: 
ms.date: 1/23/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
f1_keywords: /Qspectre
helpviewer_keywords: /Qspectre
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b114239ad57b484c9290fbe1cc2f0ae18cb565ec
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="qspectre"></a>/ Qspectre

Especifica a geração de compilador de instruções para atenuar vulnerabilidades de segurança determinados Spectre variante 1.

## <a name="syntax"></a>Sintaxe

> **/Qspectre**

## <a name="remarks"></a>Comentários

O **/Qspectre** opção faz com que o compilador para inserir instruções para atenuar certos [vulnerabilidades de segurança Spectre](https://spectreattack.com/spectre.pdf). Essas vulnerabilidades, chamadas *ataques de canal lateral execução especulativa*, afetam muitos sistemas operacionais e processadores modernos, incluindo os processadores da Intel, AMD e ARM.

O **/Qspectre** opção está desativada por padrão.

Na versão inicial, o **/Qspectre** opção só funciona em código otimizado. Verifique se a compilar seu código com qualquer uma das opções de otimização (por exemplo, [/O2 ou /O1](o1-o2-minimize-size-maximize-speed.md) mas não [/Od](od-disable-debug.md)) para certificar-se de que a mitigação é aplicada. Inspecionar da mesma forma, qualquer código que use [#pragma otimizar ("stg", off)](../../preprocessor/optimize.md).

### <a name="applicability"></a>Aplicabilidade

Se seu código opera em dados que cruza um limite de confiança, recomendamos que você use o **/Qspectre** opção recompilar e reimplantar o seu código para atenuar esse problema assim que possível. Exemplos de código que opera em dados que cruza um limite de confiança que carrega a entrada não confiável que pode afetar a execução de código, por exemplo, o código que faz o procedimento remoto chama, analisa a entrada não confiável ou arquivos ou usa outro processo entre locais interfaces IPC (comunicação). Técnicas de modo seguro padrão podem não ser suficientes. Você deve investigar as áreas restritas cuidadosamente antes de decidir que seu código não se cruza um limite de confiança.

### <a name="availability"></a>Disponibilidade

O **/Qspectre** opção está disponível na versão do Visual Studio de 2017 15.5.5 e todas as atualizações para compiladores do Microsoft Visual C++ (MSVC) feitas em ou depois de 23 de janeiro de 2018.

Todas as versões do Visual Studio de 2017 versão 15.5 e todas as visualizações do Visual Studio versão 15.6 já incluem uma opção não documentada, **/d2guardspecload**, que é equivalente ao comportamento inicial de **/Qspectre**. Você pode usar **/d2guardspecload** para aplicar as atenuações mesmo ao seu código nessas versões do compilador. Atualize sua compilação para usar **/Qspectre** de compiladores que oferece suporte à opção; o **/Qspectre** opção também pode oferecer suporte atenuações novo em versões posteriores do compilador.

### <a name="effect"></a>Efeito

O **/Qspectre** opção gera código para reduzir a variante de fantasma 1, ignorar verificar limites, [CVE-2017-5753](https://nvd.nist.gov/vuln/detail/CVE-2017-5753). Ele funciona por inserção de instruções que agem como uma barreira de execução de código especulativo. As instruções específicas usadas para atenuar especulação processador dependem do processador e sua arquitetura micro e podem mudar em versões futuras do compilador.

Quando o **/Qspectre** opção é habilitada, o compilador tenta identificar instâncias em que a execução especulativa pode ignorar verificações de limites e insere as instruções de barreira. É importante observar que há limites para a análise que pode ser executadas por um compilador para identificar instâncias da variante 1. Como tal, não há nenhuma garantia de que todas as instâncias possíveis variante 1 são instrumentadas em **/Qspectre**.

### <a name="performance-impact"></a>Impacto de desempenho

O impacto do desempenho **/Qspectre** foi visto ser insignificante no várias bases de código muito grande, mas não há nenhuma garantia que o desempenho do seu código em **/Qspectre** permanece intacto. Você deve avaliar o desempenho de seu código para determinar o efeito da opção de desempenho. Se você souber que a mitigação não é necessário em um bloco de desempenho crítico ou de um loop, a atenuação pode ser desabilitada seletivamente por uso de um [__declspec(spectre(nomitigation))](../../cpp/spectre.md) diretiva. Essa diretiva não está disponível em compiladores que suportam apenas o **/d2guardspecload** opção.

### <a name="additional-information"></a>Informações adicionais

Para obter mais detalhes, consulte o oficial [Microsoft Security Advisory ADV180002, orientações para atenuar as vulnerabilidades de canal lateral de execução especulativa](https://portal.msrc.microsoft.com/en-US/security-guidance/advisory/ADV180002). Guia também está disponível no Intel, [especulativo reduções de canal do lado de execução](https://software.intel.com/sites/default/files/managed/c5/63/336996-Speculative-Execution-Side-Channel-Mitigations.pdf)e ARM, [canais do Cache especulação lado](https://developer.arm.com/-/media/Files/pdf/Cache_Speculation_Side-channels.pdf). Para obter uma visão específica do Windows atenuantes Spectre e sobrecarga, consulte [compreensão do impacto do desempenho de atenuantes Spectre e sobrecarga em sistemas Windows](https://cloudblogs.microsoft.com/microsoftsecure/2018/01/09/understanding-the-performance-impact-of-spectre-and-meltdown-mitigations-on-windows-systems/) no blog do Microsoft Secure. Para obter uma visão geral de vulnerabilidade Spectre abrange as atenuações MSVC, consulte [atenuações Spectre em MSVC](https://blogs.msdn.microsoft.com/vcblog/2018/01/15/spectre-mitigations-in-msvc./) no Blog da equipe do Visual C++.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira o **/Qspectre** opção de compilador no **opções adicionais** caixa. Escolha **Okey** para aplicar a alteração.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções /Q (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
