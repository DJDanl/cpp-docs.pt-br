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
ms.openlocfilehash: fb59b861bc46c93a3f5fa1b6c6b8d1b73ddefc66
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818291"
---
# <a name="opt-optimizations"></a>/OPT (Otimizações)

Controla as otimizações que o LINK executa durante uma compilação.

## <a name="syntax"></a>Sintaxe

> **/OPT:**{**REF** | **NOREF**}<br/>
> **/OPT:**{**ICF**[**=**_iterações_] | **NOICF**}<br/>
> **/OPT:**{**LBR** | **NOLBR**}

## <a name="arguments"></a>Arguments

**REF** &#124; **NOREF**

**/OPT: REF** elimina as funções e dados nunca são referenciados; **/OPT: NOREF** mantém as funções e dados que nunca são referenciados.

Quando /OPT: REF é habilitado, o LINK remove as funções empacotadas e dados, conhecidos como *COMDATs*. Essa otimização é conhecida como eliminação COMDAT transitiva. O **/OPT: REF** opção também desabilita a vinculação incremental.

Funções embutidas e funções de membro definidas dentro de uma declaração de classe são sempre COMDATs. Todas as funções em um arquivo de objeto são transformadas em COMDATs se ele for compilado usando o [/Gy](gy-enable-function-level-linking.md) opção. Para colocar **const** dados em COMDATs, você deve declará-la usando `__declspec(selectany)`. Para obter informações sobre como especificar dados para remoção ou dobra, consulte [selectany](../../cpp/selectany.md).

Por padrão, **/OPT: REF** está habilitada pelo vinculador, a menos que **/OPT: NOREF** ou [/Debug](debug-generate-debug-info.md) for especificado. Para substituir esse padrão e manter COMDATs não referenciados no programa, especifique **/OPT: NOREF**. Você pode usar o [/include](include-force-symbol-references.md) opção para substituir a remoção de um símbolo específico.

Se [/Debug](debug-generate-debug-info.md) for especificado, o padrão para **/opt** está **NOREF**, e todas as funções serão preservadas na imagem. Para substituir esse padrão e otimizar uma compilação de depuração, especifique **/OPT: REF**. Isso pode reduzir o tamanho de seu executável e pode ser que uma otimização útil mesmo em depuração se baseia. É recomendável que você também especifique **/OPT: NOICF** preservar idênticos cria funções na depuração. Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos.

**ICF**\[**=**_iterations_] &#124; **NOICF**

Use **ICF**\[**=**_iterações_] para realizar dobra COMDAT idêntica. COMDATs redundantes podem ser removido da saída do vinculador. Opcional *iterações* parâmetro especifica o número de vezes para percorrer os símbolos em busca de duplicatas. O número de iterações padrão é 1. As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.

Por padrão, **/OPT: ICF** está habilitada pelo vinculador, a menos que **/OPT: NOICF** ou [/Debug](debug-generate-debug-info.md) for especificado. Para substituir esse padrão e impedir que COMDATs dobrada no programa, especifique **/OPT: NOICF**.

Em uma compilação de depuração, você deve especificar explicitamente **/OPT: ICF** para habilitar dobra COMDAT. No entanto, porque **/OPT: ICF** pode mesclar dados ou funções idênticas, ele pode alterar os nomes de função que aparecem em rastreamentos de pilha. Ele pode também tornar impossível definir pontos de interrupção em determinadas funções ou para examinar alguns dados no depurador e pode levar a funções inesperadas quando você percorrer seu código. O comportamento do código é idêntico, mas a apresentação do depurador pode ser muito confusa. Portanto, recomendamos que você use **/OPT: ICF** em compilações de depuração, a menos que as vantagens do código menor superem essas desvantagens.

> [!NOTE]
> Porque **/OPT: ICF** pode fazer com que o mesmo endereço seja atribuído a diferentes funções ou membros de dados somente leitura (ou seja, **const** variáveis quando compilado usando **/Gy**), ele pode interromper um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](gy-enable-function-level-linking.md).

**LBR** &#124; **NOLBR**

O **/OPT: lbr** e **/OPT:NOLBR** opções se aplicam somente a binários ARM. Como certas instruções de ramificação do processador ARM têm um intervalo limitado, se o vinculador detectar um salto para um endereço fora do intervalo, ele substituirá o endereço de destino da instrução de ramificação pelo endereço de uma “ilha” de códigos que contém uma instrução de ramificação que tem como alvo o destino real. Você pode usar **/OPT: lbr** para otimizar a detecção de instruções de ramificação longas e o posicionamento de ilhas de códigos intermediários para minimizar o tamanho total do código. **/OPT:NOLBR** instrui o vinculador a gerar ilhas de códigos para obter instruções de ramificação longas que são encontrados sem otimização.

Por padrão, o **/OPT: lbr** opção é definida quando o vínculo incremental não está habilitado. Se você quiser um vínculo não incremental, mas não otimizações de ramificação longas, especifique **/OPT:NOLBR**. O **/OPT: lbr** opção desabilita a vinculação incremental.

## <a name="remarks"></a>Comentários

Quando usado na linha de comando, o vinculador usa como padrão **/OPT: REF, ICF, LBR**. Se **/Debug** for especificado, o padrão é **/OPT: NOREF, NOICF, NOLBR**.

O **/opt** otimizações de geralmente diminuir o tamanho da imagem e aumentar a velocidade do programa. Esses aprimoramentos podem ser significativas em programas maiores, por isso, elas são habilitadas por padrão para compilações para venda.

Otimização do vinculador levar mais tempo com antecedência, mas o código otimizado também economiza tempo quando o vinculador tem menos realocações correção e cria uma imagem final menor, e ele economiza tempo ainda mais quando ele tem menos informações de depuração para processar e gravar no PDB. Quando a otimização estiver habilitada, ela pode resultar em um tempo de vinculação mais rápido em geral, como o custo adicional pequeno na análise pode ser mais do que compensou no momento em economia no vinculador passa sobre menores binários.

O **/opt** argumentos podem ser especificados juntos, separados por vírgulas. Por exemplo, em vez de **/OPT: REF, /OPT: NOICF**, você pode especificar **/OPT: REF, NOICF**.

Você pode usar o [/verbose](verbose-print-progress-messages.md) opção de vinculador para ver as funções que são removidas por **/OPT: REF** e as funções que são dobradas por **/OPT: ICF**.

O **/opt** argumentos geralmente são configurados para projetos criados usando o **novo projeto** caixa de diálogo no IDE do Visual Studio, e geralmente têm valores diferentes para depuração e configurações de versão. Se nenhum valor for definido para essas opções de vinculador em seu projeto, você pode obter os padrões de projeto, que podem ser diferentes dos valores padrão usados pelo vinculador na linha de comando.

### <a name="to-set-the-opticf-or-optref-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. Modifique uma destas propriedades:

   - **Habilitar dobra COMDAT**

   - **Referências**

### <a name="to-set-the-optlbr-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais**:

   `/opt:lbr` ou `/opt:nolbr`

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.

## <a name="see-also"></a>Consulte também

- [Referência de vinculador MSVC](linking.md)
- [Opções do vinculador MSVC](linker-options.md)
