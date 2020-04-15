---
title: /OPT (Otimizações)
ms.date: 05/18/2018
f1_keywords:
- VC.Project.VCLinkerTool.OptimizeReferences
- /opt
- VC.Project.VCLinkerTool.OptimizeForWindows98
- VC.Project.VCLinkerTool.EnableCOMDATFolding
- VC.Project.VCLinkerTool.OptimizeFolding
- VC.Project.VCLinkerTool.FoldingIterations
- VC.Project.VCLinkerTool.OptimizeFoldingIterations
helpviewer_keywords:
- LINK tool [C++], controlling optimizations
- -OPT linker option
- linker [C++], optimizations
- OPT linker option
- optimization, linker
- /OPT linker option
ms.assetid: 8f229863-5f53-48a8-9478-243a647093ac
ms.openlocfilehash: b25db4d6c260c3c6751de293aa2a82df8aa05e7e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336216"
---
# <a name="opt-optimizations"></a>/OPT (Otimizações)

Controla as otimizações que o LINK executa durante uma compilação.

## <a name="syntax"></a>Sintaxe

> **/OPT:**{**REF** | **NOREF**}<br/>
> **/OPT:**{**ICF**[**=**_iterações_] | **NOICF**}<br/>
> **/OPT:**{**LBR** | **NOLBR**}

## <a name="arguments"></a>Argumentos

**REF** &#124; **NOREF**

**/OPT:REF** elimina funções e dados que nunca são referenciados; **/OPT:NOREF** mantém funções e dados que nunca são referenciados.

Quando /OPT:REF está ativado, o LINK remove funções e dados embalados não referenciados, conhecidos como *COMDATs*. Essa otimização é conhecida como eliminação COMDAT transitiva. A opção **/OPT:REF** também desativa a vinculação incremental.

Funções delineadas e funções de membro definidas dentro de uma declaração de classe são sempre COMDATs. Todas as funções em um arquivo de objeto são transformadas em COMDATs se for compilado usando a opção [/Gy.](gy-enable-function-level-linking.md) Para colocar dados **const** em COMDATs, `__declspec(selectany)`você deve declará-los usando . Para obter informações sobre como especificar dados para remoção ou dobrável, consulte [selectany](../../cpp/selectany.md).

Por padrão, **/OPT:REF** é habilitado pelo linker a menos que **/OPT:NOREF** ou [/DEBUG](debug-generate-debug-info.md) seja especificado. Para substituir esse padrão e manter COMDATs não referenciados no programa, especifique **/OPT:NOREF**. Você pode usar a opção [/INCLUDE](include-force-symbol-references.md) para substituir a remoção de um símbolo específico.

Se [/DEBUG](debug-generate-debug-info.md) for especificado, o padrão para **/OPT** é **NOREF**, e todas as funções são preservadas na imagem. Para substituir esse padrão e otimizar uma compilação de depuração, especifique **/OPT:REF**. Isso pode reduzir o tamanho do seu executável, e pode ser uma otimização útil mesmo em compilações de depurações. Recomendamos que você também especifique **/OPT:NOICF** para preservar funções idênticas em compilações de depuração. Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos.

**Iterações ICF**\[**=**_iterations_] &#124; **NOICF**

Use_iterações_ **ICF**\[**=**] para executar a dobra comda comda idêntica. COMDATs redundantes podem ser removido da saída do vinculador. O parâmetro *de iterações* opcionais especifica o número de vezes para atravessar os símbolos para duplicatas. O número padrão de iterações é 1. As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.

Por padrão, **/OPT:ICF** é habilitado pelo linker a menos que **/OPT:NOICF** ou [/DEBUG](debug-generate-debug-info.md) seja especificado. Para substituir esse padrão e evitar que os COMDATs sejam dobrados no programa, especifique **/OPT:NOICF**.

Em uma compilação de depuração, você deve especificar explicitamente **/OPT:ICF** para ativar a dobra COMDAT. No entanto, como **/OPT:ICF** pode mesclar dados ou funções idênticas, ele pode alterar os nomes de função que aparecem em traços de pilha. Também pode tornar impossível definir pontos de interrupção em determinadas funções ou examinar alguns dados no depurador, e pode levá-lo a funções inesperadas quando você passa por seu código. O comportamento do código é idêntico, mas a apresentação do depurador pode ser muito confusa. Portanto, não recomendamos que você use **/OPT:ICF** em compilações de depuração, a menos que as vantagens do código menor superem essas desvantagens.

> [!NOTE]
> Porque **/OPT:ICF** pode fazer com que o mesmo endereço seja atribuído a diferentes funções ou membros de dados somente leitura (ou seja, variáveis **const** quando compilados usando **/Gy),** ele pode quebrar um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](gy-enable-function-level-linking.md).

**LBR** &#124; **NOLBR**

As opções **/OPT:LBR** e **/OPT:NOLBR** aplicam-se apenas aos binários ARM. Como certas instruções do ramo do processador ARM têm um alcance limitado, se o linker detectar um salto para um endereço fora de alcance, ele substitui o endereço de destino da instrução de ramificação pelo endereço de uma "ilha" de código que contém uma instrução de ramo que tem como alvo o destino real. Você pode usar **/OPT:LBR** para otimizar a detecção de instruções de ramo longo e a colocação de ilhas de código intermediárias para minimizar o tamanho geral do código. **/OPT:NOLBR** instrui o linker a gerar ilhas de código para instruções de ramificação longa como são encontradas, sem otimização.

Por padrão, a opção **/OPT:LBR** é definida quando o link incremental não está ativado. Se você quiser um link não incremental, mas não otimizações de ramificações longas, especifique **/OPT:NOLBR**. A opção **/OPT:LBR** desativa a vinculação incremental.

## <a name="remarks"></a>Comentários

Quando usado na linha de comando, o linker é padrão para **/OPT:REF, ICF,LBR**. Se **/DEBUG** for especificado, o padrão será **/OPT:NOREF, NOICF,NOLBR**.

As **otimizações /OPT** geralmente diminuem o tamanho da imagem e aumentam a velocidade do programa. Essas melhorias podem ser substanciais em programas maiores, e é por isso que eles são habilitados por padrão para compilações de varejo.

A otimização do linker leva tempo extra até a frente, mas o código otimizado também economiza tempo quando o linker tem menos relocações para corrigir e cria uma imagem final menor, e economiza ainda mais tempo quando tem menos informações de depuração para processar e gravar no PDB. Quando a otimização é ativada, pode resultar em um tempo de link mais rápido no geral, já que o pequeno custo adicional na análise pode ser mais do que compensado pela economia de tempo no linker passa por binários menores.

Os argumentos **/OPT** podem ser especificados em conjunto, separados por commas. Por exemplo, em vez de **/OPT:REF /OPT:NOICF**, você pode especificar **/OPT:REF,NOICF**.

Você pode usar a opção [linker /VERBOSE](verbose-print-progress-messages.md) para ver as funções removidas por **/OPT:REF** e as funções dobradas por **/OPT:ICF**.

Os argumentos **/OPT** são frequentemente definidos para projetos criados usando a caixa de diálogo **Novo Projeto** no Visual Studio IDE, e geralmente têm valores diferentes para configurações de depuração e lançamento. Se nenhum valor for definido para essas opções de linker em seu projeto, então você poderá obter os padrões do projeto, que podem ser diferentes dos valores padrão usados pelo linker na linha de comando.

### <a name="to-set-the-opticf-or-optref-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de > **propriedade Otimização** do > **Linker**de propriedades de **configuração.**

1. Modifique uma destas propriedades:

   - **Habilitar Dobra COMDAT**

   - **Referências**

### <a name="to-set-the-optlbr-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade **Configuração Propriedades** > **linker's** > **command line.**

1. Insira a opção em **Opções Adicionais**:

   `/opt:lbr` ou `/opt:nolbr`

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções de vinculador MSVC](linker-options.md)
