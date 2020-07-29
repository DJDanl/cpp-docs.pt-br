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
ms.openlocfilehash: 874c4b974348d1bef8c8c3837f46c1c27d6d304b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215186"
---
# <a name="opt-optimizations"></a>/OPT (Otimizações)

Controla as otimizações que o LINK executa durante uma compilação.

## <a name="syntax"></a>Sintaxe

> **/OPT:**{**ref**  |  **NOREF**} \
> **/OPT:**{**ICF**[ **=** _iterações_] | **NOICF**} \
> **/OPT:**{**LBR**  |  **NOLBR**}

## <a name="arguments"></a>Argumentos

**REF** &#124; **NOREF**

**/OPT: REF** elimina funções e dados que nunca são referenciados; **/OPT: NOREF** mantém funções e dados que nunca são referenciados.

Quando/OPT: REF está habilitado, o LINK remove dados e funções empacotados não referenciados, conhecidos como *COMDATs*. Essa otimização é conhecida como eliminação COMDAT transitiva. A opção **/OPT: REF** também desabilita a vinculação incremental.

Funções embutidas e funções de membro definidas dentro de uma declaração de classe são sempre COMDATs. Todas as funções em um arquivo de objeto serão feitas em COMDATs se ele for compilado usando a opção [/GY](gy-enable-function-level-linking.md) . Para inserir **`const`** dados em COMDATs, você deve declará-lo usando `__declspec(selectany)` . Para obter informações sobre como especificar dados para remoção ou dobramento, consulte [selectany](../../cpp/selectany.md).

Por padrão, **/OPT: REF** é habilitado pelo vinculador, a menos que **/OPT: NOREF** ou [/debug](debug-generate-debug-info.md) seja especificado. Para substituir esse padrão e manter COMDATs não referenciados no programa, especifique **/OPT: NOREF**. Você pode usar a opção [/include](include-force-symbol-references.md) para substituir a remoção de um símbolo específico.

Se [/debug](debug-generate-debug-info.md) for especificado, o padrão para **/opt** será **NOREF**e todas as funções serão preservadas na imagem. Para substituir esse padrão e otimizar uma compilação de depuração, especifique **/OPT: REF**. Isso pode reduzir o tamanho do seu executável e pode ser uma otimização útil mesmo em compilações de depuração. É recomendável que você também especifique **/OPT: NOICF** para preservar funções idênticas em compilações de depuração. Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos.

**ICF** \[ ICF **=** _iterações_] &#124; **NOICF**

Use **ICF**as \[ **=** _iterações_do ICF] para executar o dobramento COMDAT idêntico. COMDATs redundantes podem ser removido da saída do vinculador. O parâmetro de *iterações* opcionais especifica o número de vezes para atravessar os símbolos para duplicatas. O número padrão de iterações é 1. As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.

Por padrão, **/OPT: ICF** é habilitado pelo vinculador, a menos que **/OPT: NOICF** ou [/debug](debug-generate-debug-info.md) seja especificado. Para substituir esse padrão e impedir que COMDATs sejam dobrados no programa, especifique **/OPT: NOICF**.

Em uma compilação de depuração, você deve especificar explicitamente **/OPT: ICF** para habilitar o dobramento COMDAT. No entanto, como **/OPT: ICF** pode mesclar dados ou funções idênticas, ele pode alterar os nomes de função que aparecem em rastreamentos de pilha. Ele também pode tornar impossível definir pontos de interrupção em determinadas funções ou examinar alguns dados no depurador e pode levá-lo a funções inesperadas ao percorrer seu código de forma única. O comportamento do código é idêntico, mas a apresentação do depurador pode ser muito confusa. Portanto, não recomendamos que você use **/OPT: ICF** em compilações de depuração, a menos que as vantagens de um código menor superem essas desvantagens.

> [!NOTE]
> Como **/OPT: ICF** pode fazer com que o mesmo endereço seja atribuído a funções diferentes ou membros de dados somente leitura (ou seja, **`const`** variáveis quando compilados usando **/GY**), ele pode interromper um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](gy-enable-function-level-linking.md).

**LBR** &#124; **NOLBR**

As opções **/OPT: LBR** e **/OPT: NOLBR** se aplicam somente a binários ARM. Como certas instruções da ramificação do processador ARM têm um intervalo limitado, se o vinculador detectar um salto para um endereço fora do intervalo, ele substituirá o endereço de destino da instrução da ramificação pelo endereço de uma "ilha" de código que contém uma instrução de ramificação direcionada ao destino real. Você pode usar **/OPT: LBR** para otimizar a detecção de instruções de Branch longa e o posicionamento de ilhas de código intermediário para minimizar o tamanho geral do código. **/OPT: NOLBR** instrui o vinculador a gerar ilhas de código para obter instruções de Branch longa, pois elas são encontradas, sem otimização.

Por padrão, a opção **/OPT: LBR** é definida quando a vinculação incremental não está habilitada. Se você quiser um link não incremental, mas não as otimizações de ramificação longas, especifique **/OPT: NOLBR**. A opção **/OPT: LBR** desabilita a vinculação incremental.

## <a name="remarks"></a>Comentários

Quando usado na linha de comando, o vinculador usa como padrão **/OPT: REF, ICF, LBR**. Se **/debug** for especificado, o padrão será **/OPT: NOREF, NOICF, NOLBR**.

As otimizações **/opt** geralmente diminuem o tamanho da imagem e aumentam a velocidade do programa. Esses aprimoramentos podem ser substanciais em programas maiores, que é o motivo pelo qual eles são habilitados por padrão para compilações de varejo.

A otimização do vinculador leva um tempo extra até o início, mas o código otimizado também economiza tempo quando o vinculador tem menos relocações para corrigir e cria uma imagem final menor e economiza ainda mais tempo quando tem menos informações de depuração para processar e gravar no PDB. Quando a otimização está habilitada, ela pode resultar em um tempo de link mais rápido geral, pois o pequeno custo adicional na análise pode ser maior do que o deslocamento pela economia de tempo no vinculador em binários menores.

Os argumentos **/opt** podem ser especificados juntos, separados por vírgulas. Por exemplo, em vez de **/OPT: REF/OPT: NOICF**, você pode especificar **/OPT: REF, NOICF**.

Você pode usar a opção de vinculador [/Verbose](verbose-print-progress-messages.md) para ver as funções que são removidas por **/OPT: REF** e as funções que são dobradas por **/OPT: ICF**.

Os argumentos **/opt** geralmente são definidos para projetos criados usando a caixa de diálogo **novo projeto** no IDE do Visual Studio e geralmente têm valores diferentes para configurações de depuração e versão. Se nenhum valor for definido para essas opções de vinculador em seu projeto, você poderá obter os padrões do projeto, que podem ser diferentes dos valores padrão usados pelo vinculador na linha de comando.

### <a name="to-set-the-opticf-or-optref-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade otimização do**vinculador**de propriedades de configuração  >  **Optimization** .

1. Modifique uma destas propriedades:

   - **Habilitar Dobra COMDAT**

   - **Referências**

### <a name="to-set-the-optlbr-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade da linha de comando do**vinculador**de propriedades de configuração  >  **Command Line** .

1. Insira a opção em **Opções adicionais**:

   `/opt:lbr` ou `/opt:nolbr`

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.

## <a name="see-also"></a>Confira também

- [Referência de vinculador MSVC](linking.md)
- [Opções do vinculador MSVC](linker-options.md)
