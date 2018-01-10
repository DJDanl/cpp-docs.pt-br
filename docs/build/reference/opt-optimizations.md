---
title: "-OPT (otimizações) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCLinkerTool.OptimizeReferences
- /opt
- VC.Project.VCLinkerTool.OptimizeForWindows98
- VC.Project.VCLinkerTool.EnableCOMDATFolding
- VC.Project.VCLinkerTool.OptimizeFolding
- VC.Project.VCLinkerTool.FoldingIterations
- VC.Project.VCLinkerTool.OptimizeFoldingIterations
dev_langs: C++
helpviewer_keywords:
- LINK tool [C++], controlling optimizations
- -OPT linker option
- linker [C++], optimizations
- OPT linker option
- optimization, linker
- /OPT linker option
ms.assetid: 8f229863-5f53-48a8-9478-243a647093ac
caps.latest.revision: "23"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 86427dbf1ac6c3404daa36d2e02786aa80ed6453
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="opt-optimizations"></a>/OPT (Otimizações)
Controla as otimizações que o LINK executa durante uma compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/OPT:{REF | NOREF}  
/OPT:{ICF[=iterations] | NOICF}  
/OPT:{LBR | NOLBR}  
```  
  
## <a name="arguments"></a>Arguments  
 **REF** &#124; **NOREF**  
 **/OPT: REF** elimina funções e os dados que nunca são referenciados; **/OPT: NOREF** mantém funções e os dados que nunca são consultados.  
  
 Quando /OFT:REF é habilitado, o LINK remove as funções e os dados empacotados não referenciados. Um objeto contém funções empacotadas e os dados (COMDATs) se ele foi compilado usando o [/Gy](../../build/reference/gy-enable-function-level-linking.md) opção. Essa otimização é conhecida como eliminação COMDAT transitiva. Por padrão, **/OPT: REF** está habilitado em compilações de depuração não. Para substituir esse padrão e manter COMDATs não referenciadas no programa, especifique **/OPT: NOREF**. Você pode usar o [/incluem](../../build/reference/include-force-symbol-references.md) opção para substituir a remoção de um símbolo específico.  
  
 Quando **/OPT: REF** está habilitado ou explicitamente por padrão, uma forma limitada de **/OPT: ICF** está habilitado que dobra somente funções idênticas. Se você quiser **/OPT: REF** mas não **/OPT: ICF**, você deve especificar **/OPT: REF, NOICF** ou **NOICF**.  
  
 Se [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado, o padrão para **/opt** é **NOREF**, e todas as funções são preservadas na imagem. Para substituir esse padrão e otimizar uma compilação de depuração, especifique **/OPT: REF**. Porque **/OPT: REF** implica **/OPT: ICF**, recomendamos que você também especifique **NOICF** para preservar funções idênticas em compilações de depuração. Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos. O **/OPT: REF** opção desabilita o vínculo incremental.  
  
 É necessário marcar explicitamente `const` dados como um COMDAT; use [__declspec(selectany)](../../cpp/selectany.md).  
  
 Especificando **/OPT: ICF** não habilita o **/OPT: REF** opção.  
  
 **ICF [=** `iterations` **] &#124; NOICF**   
 Use **/OPT: ICF [=**`iterations`**]** para realizar dobra COMDAT idêntica. COMDATs redundantes podem ser removido da saída do vinculador. O parâmetro opcional `iterations` especifica o número de vezes a percorrer os símbolos em busca de duplicatas. O número de iterações padrão é dois. As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.  
  
 O vinculador tem um comportamento diferente quando **/OPT: REF** especificado — e **ICF** está em vigor por padrão — do que quando **/OPT: REF, ICF** sejam especificadas explicitamente. A forma de **ICF** habilitado com **/OPT: REF** sozinho não dobra dados somente leitura – isso inclui RDATA. pData e .xdata. Portanto, menos funções são dobradas quando as imagens são geradas para o [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)], pois as funções nesses módulos são mais dependentes de dados somente leitura, por exemplo, .pdata e .xdata. Para obter completo **ICF** dobra o comportamento, especifique explicitamente **/OPT: ICF**.  
  
 Para colocar funções na COMDATs, você deve usar o **/Gy** opção de compilador; colocar `const` dados, declare- `__declspec(selectany)`. Para obter informações sobre como especificar dados de partição, consulte [selectany](../../cpp/selectany.md).  
  
 Por padrão, **ICF** é se **REF** está em. Para substituir esse padrão se **REF** é especificado, use **NOICF**. Quando **/OPT: REF** não for especificado em uma compilação de depuração, você deve especificar explicitamente **/OPT: ICF** para habilitar dobra COMDAT. No entanto, como **/OPT: ICF** pode mesclar dados idênticos ou funções, ele pode alterar os nomes de função que aparecem em rastreamentos de pilha. Também pode tornar impossível a definição de pontos de interrupção em determinadas funções ou o exame de alguns dados no depurador, e levar você a funções inesperadas ao criar o código em etapa única. Portanto, não recomendamos que você use **/OPT: ICF** depuração compila a menos que as vantagens do código menor superam essas desvantagens.  
  
> [!NOTE]
>  Porque **/OPT: ICF** pode fazer com que o mesmo endereço a ser atribuído a diferentes funções ou os membros de dados somente leitura (`const` variáveis compilados usando **/Gy**), ele pode interromper um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura. Para obter mais informações, consulte [/Gy (habilitar vinculação em nível de função)](../../build/reference/gy-enable-function-level-linking.md).  
  
 **LBR** &#124; **NOLBR**  
 O **/OPT:LBR** e **/OPT:NOLBR** opções se aplicam somente a binários ARM. Como certas instruções de ramificação do processador ARM têm um intervalo limitado, se o vinculador detectar um salto para um endereço fora do intervalo, ele substituirá o endereço de destino da instrução de ramificação pelo endereço de uma “ilha” de códigos que contém uma instrução de ramificação que tem como alvo o destino real. Você pode usar **/OPT:LBR** para otimizar a detecção de instruções de branch longa e o posicionamento das Ilhas código intermediário para minimizar o tamanho geral do código. **/OPT:NOLBR** instrui o vinculador para gerar ilhas de código para obter instruções de ramificação longa conforme forem encontrados, sem a otimização.  
  
 Por padrão, o **/OPT:LBR** opção é definida ao vínculo incremental não está habilitado. Se você quiser um link não incremental, mas não as otimizações de ramificação longa, especifique **/OPT:NOLBR**. O **/OPT:LBR** opção desabilita o vínculo incremental.  
  
## <a name="remarks"></a>Comentários  
 Geralmente, as otimizações reduzem o tamanho da imagem e aumentam a velocidade do programa a um custo de aumento do tempo de vinculação.  
  
 Você pode usar o [/verbose](../../build/reference/verbose-print-progress-messages.md) para ver as funções que são removidas por **/OPT: REF** e as funções que são classificadas por **/OPT: ICF**.  
  
### <a name="to-set-the-opticf-or-optref-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, expanda **propriedades de configuração**, **vinculador**, **otimização**.  
  
3.  Modifique uma destas propriedades:  
  
    -   **Habilitar dobra COMDAT**  
  
    -   **Referências**  
  
### <a name="to-set-the-optlbr-linker-option-in-the-visual-studio-development-environment"></a>Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Insira a opção no **opções adicionais**:  
  
     `/opt:lbr`  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)