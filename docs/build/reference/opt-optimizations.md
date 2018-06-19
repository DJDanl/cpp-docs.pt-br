---
title: /OPT (otimizações) | Microsoft Docs
ms.custom: ''
ms.date: 05/18/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.OptimizeReferences
- /opt
- VC.Project.VCLinkerTool.OptimizeForWindows98
- VC.Project.VCLinkerTool.EnableCOMDATFolding
- VC.Project.VCLinkerTool.OptimizeFolding
- VC.Project.VCLinkerTool.FoldingIterations
- VC.Project.VCLinkerTool.OptimizeFoldingIterations
dev_langs:
- C++
helpviewer_keywords:
- LINK tool [C++], controlling optimizations
- -OPT linker option
- linker [C++], optimizations
- OPT linker option
- optimization, linker
- /OPT linker option
ms.assetid: 8f229863-5f53-48a8-9478-243a647093ac
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc9f7f66b9bd0ee2c0da65d17eac33e1cbc8c316
ms.sourcegitcommit: da7b7533d1a4dc141cc0f09149e4e4196f2fe329
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2018
ms.locfileid: "34463099"
---
# <a name="opt-optimizations"></a>/OPT (Otimizações)

Controla as otimizações que o LINK executa durante uma compilação.

## <a name="syntax"></a>Sintaxe

> **/OPT:**{**REF** | **NOREF**}<br/>
> **/OPT:**{**ICF**[**=**_iterações_] | **NOICF**}<br/>
> **/OPT:**{**LBR** | **NOLBR**}

## <a name="arguments"></a>Arguments

**REF** &AMP;#124; **NOREF**

**/OPT: REF** elimina funções e os dados que nunca são referenciados; **/OPT: NOREF** mantém funções e os dados que nunca são consultados.

Quando /OPT: ref estiver habilitado, LINK remove sem referência de funções empacotadas e dados, conhecidos como *COMDATs*. Essa otimização é conhecida como eliminação COMDAT transitiva. O **/OPT: REF** opção também desabilita o vínculo incremental.

Funções embutidas e funções de membro definidas dentro de uma declaração de classe são sempre COMDATs. Todas as funções em um arquivo de objeto são feitas em COMDATs se ela é compilada usando o [/Gy](../../build/reference/gy-enable-function-level-linking.md) opção. Para colocar **const** dados COMDATs, você deve declará-la usando `__declspec(selectany)`. Para obter informações sobre como especificar dados para remoção ou partição, consulte [selectany](../../cpp/selectany.md).

Por padrão, **/OPT: REF** é habilitado pelo vinculador, a menos que **/OPT: NOREF** ou [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado. Para substituir esse padrão e manter COMDATs não referenciadas no programa, especifique **/OPT: NOREF**. Você pode usar o [/incluem](../../build/reference/include-force-symbol-references.md) opção para substituir a remoção de um símbolo específico.

Se [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado, o padrão para **/opt** é **NOREF**, e todas as funções são preservadas na imagem. Para substituir esse padrão e otimizar uma compilação de depuração, especifique **/OPT: REF**. Isso pode reduzir o tamanho de seu executável e pode ser que uma otimização útil mesmo em depuração cria. É recomendável que você também especifique **NOICF** para preservar idênticos cria funções na depuração. Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos.

**ICF**\[**=**_iterações_] &#124; **NOICF**

Use **ICF**\[**=**_iterações_] para realizar dobra COMDAT idêntica. COMDATs redundantes podem ser removido da saída do vinculador. Opcional *iterações* parâmetro especifica o número de vezes para percorrer os símbolos para duplicatas. O número de iterações padrão é 1. As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.

Por padrão, **/OPT: ICF** é habilitado pelo vinculador, a menos que **NOICF** ou [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado. Para substituir esse padrão e impedir que COMDATs dobrada no programa, especifique **NOICF**.

Em uma compilação de depuração, você deve especificar explicitamente **/OPT: ICF** para habilitar dobra COMDAT. No entanto, como **/OPT: ICF** pode mesclar dados idênticos ou funções, ele pode alterar os nomes de função que aparecem em rastreamentos de pilha. Ele também podem tornar impossível definir pontos de interrupção em certas funções ou examinar alguns dados no depurador e pode levá-lo em funções inesperadas quando você percorrer seu código. O comportamento do código é idêntico, mas a apresentação do depurador pode ser muito confusa. Portanto, não recomendamos que você use **/OPT: ICF** depuração compila a menos que as vantagens do código menor superam essas desvantagens.

> [!NOTE]
> Porque **/OPT: ICF** pode fazer com que o mesmo endereço a ser atribuído a diferentes funções ou os membros de dados somente leitura (ou seja, **const** quando compilado com o uso de variáveis **/Gy**), ele pode interromper um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](../../build/reference/gy-enable-function-level-linking.md).

**LBR** &AMP;#124; **NOLBR**

O **/OPT:LBR** e **/OPT:NOLBR** opções se aplicam somente a binários ARM. Como certas instruções de ramificação do processador ARM têm um intervalo limitado, se o vinculador detectar um salto para um endereço fora do intervalo, ele substituirá o endereço de destino da instrução de ramificação pelo endereço de uma “ilha” de códigos que contém uma instrução de ramificação que tem como alvo o destino real. Você pode usar **/OPT:LBR** para otimizar a detecção de instruções de branch longa e o posicionamento das Ilhas código intermediário para minimizar o tamanho geral do código. **/OPT:NOLBR** instrui o vinculador para gerar ilhas de código para obter instruções de ramificação longa conforme forem encontrados, sem a otimização.

Por padrão, o **/OPT:LBR** opção é definida ao vínculo incremental não está habilitado. Se você quiser um link não incremental, mas não as otimizações de ramificação longa, especifique **/OPT:NOLBR**. O **/OPT:LBR** opção desabilita o vínculo incremental.

## <a name="remarks"></a>Comentários

Quando usado na linha de comando, o vinculador o padrão é **LBR /OPT: REF, ICF,**. Se **/Debug** for especificado, o padrão é **NOLBR /OPT: NOREF, NOICR,**.

O **/opt** otimizações geralmente diminuir o tamanho da imagem e aumentar a velocidade de programa. Esses aprimoramentos podem ser significativas em programas maiores, por isso, eles são habilitados por padrão para compilações para venda.

Otimização de vinculador levar mais tempo no futuro, mas o código otimizado também salva a hora em que o vinculador tem menos realocações de correção e cria uma imagem final menor, e ele salva ainda mais tempo quando ele tem menos informações de depuração para processar e gravar no PDB. Quando a otimização é habilitada, ela pode resultar em um tempo mais rápido de link geral, como o pequeno custo adicional na análise pode ser mais de deslocamento no momento economia no vinculador passa sobre binários menores.

O **/opt** argumentos podem ser especificados juntos, separados por vírgulas. Por exemplo, em vez de **/OPT: REF NOICF**, você pode especificar **/OPT: REF, NOICF**.

Você pode usar o [/verbose](../../build/reference/verbose-print-progress-messages.md) opção de vinculador para ver as funções que foram removidas por **/OPT: REF** e as funções que são classificadas por **/OPT: ICF**.

O **/opt** argumentos geralmente são configurados para projetos criados usando o **novo projeto** caixa de diálogo no IDE do Visual Studio, e normalmente têm valores diferentes para depuração e configurações de versão. Se nenhum valor for definido para essas opções de vinculador em seu projeto, você pode obter os padrões de projeto, que podem ser diferentes dos valores padrão usados pelo vinculador na linha de comando.

### <a name="to-set-the-opticf-or-optref-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **otimização** página de propriedades.

1. Modifique uma destas propriedades:

   - **Habilitar dobra COMDAT**

   - **Referências**

### <a name="to-set-the-optlbr-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais**:

   `/opt:lbr` ou `/opt:nolbr`

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.

## <a name="see-also"></a>Consulte também

- [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)
- [Opções do vinculador](../../build/reference/linker-options.md)
