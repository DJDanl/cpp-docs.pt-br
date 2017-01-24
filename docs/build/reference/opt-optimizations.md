---
title: "/OPT (Otimiza&#231;&#245;es) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCLinkerTool.OptimizeReferences"
  - "/opt"
  - "VC.Project.VCLinkerTool.OptimizeForWindows98"
  - "VC.Project.VCLinkerTool.EnableCOMDATFolding"
  - "VC.Project.VCLinkerTool.OptimizeFolding"
  - "VC.Project.VCLinkerTool.FoldingIterations"
  - "VC.Project.VCLinkerTool.OptimizeFoldingIterations"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /OPT"
  - "ferramenta LINK [C++], controlando otimizações"
  - "vinculador [C++], otimizações"
  - "opção de vinculador OPT"
  - "opção de vinculador -OPT"
  - "otimização, vinculador"
ms.assetid: 8f229863-5f53-48a8-9478-243a647093ac
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /OPT (Otimiza&#231;&#245;es)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Controla as otimizações que o LINK executa durante uma compilação.  
  
## Sintaxe  
  
```  
/OPT:{REF | NOREF}  
/OPT:{ICF[=iterations] | NOICF}  
/OPT:{LBR | NOLBR}  
```  
  
## Argumentos  
 **REF** &#124; **NOREF**  
 **\/OPT:REF** elimina as funções e os dados que nunca são referenciados; **\/OPT:NOREF** mantém as funções e os dados que nunca são referenciados.  
  
 Quando \/OFT:REF é habilitado, o LINK remove as funções e os dados empacotados não referenciados.  Um objeto contém funções e dados empacotados \(COMDATs\) se tiver sido compilado usando a opção [\/Gy](../../build/reference/gy-enable-function-level-linking.md).  Essa otimização é conhecida como eliminação COMDAT transitiva.  Por padrão, **\/OPT:REF** é habilitado em compilações sem depuração.  Para substituir esse padrão e manter COMDATs não referenciados no programa, especifique **\/OPT:NOREF**.  Você pode usar a opção [\/INCLUDE](../../build/reference/include-force-symbol-references.md) para substituir a remoção de um símbolo específico.  
  
 Quando **\/OPT:REF** é habilitado explicitamente ou por padrão, um formato delimitado de **\/OPT:ICF** que somente dobra funções idênticas é habilitado.  Se você quiser **\/OPT:REF**, mas não **\/OPT:ICF**, especifique **\/OPT:REF,NOICF** ou **\/OPT:NOICF**.  
  
 Se [\/DEBUG](../../build/reference/debug-generate-debug-info.md) for especificado, o padrão para **\/OPT** será **NOREF**, e todas as funções serão preservadas na imagem.  Para substituir esse padrão e otimizar uma compilação de depuração, especifique **\/OPT:REF**.  Como **\/OPT:REF** implica **\/OPT:ICF**, recomendamos que você também especifique **\/OPT:NOICF** para preservar funções idênticas em compilações de depuração.  Isso facilitará a leitura de rastreamentos da pilha e a definição de pontos de interrupção em funções que seriam combinadas em outros casos.  A opção **\/OPT:REF** desativa a vinculação incremental.  
  
 Você precisa marcar explicitamente dados `const` como COMDAT; use [\_\_declspec \(selectany\)](../../cpp/selectany.md).  
  
 Especificar **\/OPT:ICF** não habilita a opção **\/OPT:REF**.  
  
 **ICF\[\=**  `iterations` **\] &#124; NOICF**  
 Use **\/OPT:ICF\[\=**`iterations`**\]** para realizar dobra COMDAT idêntica.  COMDATs redundantes podem ser removido da saída do vinculador.  O parâmetro opcional `iterations` especifica o número de vezes a percorrer os símbolos em busca de duplicatas.  O número de iterações padrão é dois.  As iterações adicionais podem encontrar mais duplicatas que são descobertas com a dobra na iteração anterior.  
  
 O vinculador se comporta de modo diferente quando **\/OPT:REF** é especificado – e **ICF** é aplicado por padrão – do que quando **\/OPT:REF,ICF** é especificado explicitamente.  O formulário de **ICF** que é habilitado com **\/OPT:REF** isoladamente não dobra dados somente leitura – inclui .rdata, .pdata e .xdata.  Portanto, menos funções são dobradas quando as imagens são geradas para o [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], pois as funções nesses módulos são mais dependentes de dados somente leitura, por exemplo, .pdata e .xdata.  Para obter o comportamento de dobra **ICF** completo, especifique explicitamente **\/OPT:ICF**.  
  
 Para colocar funções em COMDATs, você usa a opção do compilador **\/Gy**; para colocar dados `const`, você os declara `__declspec(selectany)`.  Para obter informações sobre como especificar dados para dobra, consulte [selectany](../../cpp/selectany.md).  
  
 Por padrão, **ICF** é ativado quando **REF** é ativado.  Para substituir esse padrão se **REF** for especificado, use **NOICF**.  Quando **\/OPT:REF** não é especificado em uma compilação de depuração, você deve especificar **\/OPT:ICF** explicitamente para habilitar para dobra COMDAT.  No entanto, como **\/OPT:ICF** pode mesclar dados ou funções idênticas, ele pode alterar os nomes de funções que aparecem em rastreamentos de pilha.  Também pode tornar impossível a definição de pontos de interrupção em determinadas funções ou o exame de alguns dados no depurador, e levar você a funções inesperadas ao criar o código em etapa única.  Portanto, não recomendamos que você use **\/OPT:ICF** em compilações de depuração a menos que as vantagens do código menor superem essas desvantagens.  
  
> [!NOTE]
>  Como **\/OPT:ICF** pode fazer com que o mesmo endereço seja atribuído a funções diferentes ou membros de dados somente leitura \(variáveis `const` compiladas usando **\/Gy**\), isso pode interromper um programa que depende de endereços exclusivos para funções ou membros de dados somente leitura.  Para obter mais informações, consulte [\/Gy \(habilitar vinculação do nível de função\)](../../build/reference/gy-enable-function-level-linking.md).  
  
 **LBR** &#124; **NOLBR**  
 As opções **\/OPT:LBR** e **\/OPT:NOLBR** se aplicam somente a binários ARM.  Como certas instruções de ramificação do processador ARM têm um intervalo limitado, se o vinculador detectar um salto para um endereço fora do intervalo, ele substituirá o endereço de destino da instrução de ramificação pelo endereço de uma “ilha” de códigos que contém uma instrução de ramificação que tem como alvo o destino real.  Você pode usar **\/OPT:LBR** para otimizar a detecção de instruções de ramificação longas e de posicionamento de ilhas de códigos intermediários para minimizar o tamanho total do código.  **\/OPT:NOLBR** instrui o vinculador a gerar ilhas de códigos para instruções de ramificação longas à medida que são encontradas, sem otimização.  
  
 Por padrão, a opção **\/OPT:LBR** é definida quando o vínculo incremental não está habilitado.  Se você quiser um vínculo não incremental, mas não otimizações de ramificação longas, especifique **\/OPT:NOLBR**.  A opção **\/OPT:LBR** desativa a vinculação incremental.  
  
## Comentários  
 Geralmente, as otimizações reduzem o tamanho da imagem e aumentam a velocidade do programa a um custo de aumento do tempo de vinculação.  
  
 Você pode usar a opção [\/VERBOSE](../../build/reference/verbose-print-progress-messages.md) para ver as funções que são removidas por **\/OPT:REF** e as funções que são dobradas por **\/OPT:ICF**.  
  
### Para definir a opção do vinculador OPT:ICF ou OPT:REF no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No painel esquerdo, expanda **Propriedades de Configuração**, **Vinculador**, **Otimização**.  
  
3.  Modifique uma destas propriedades:  
  
    -   **Habilitar Dobra COMDAT**  
  
    -   **Referências**  
  
### Para definir a opção do vinculador OPT:LBR no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Configurando as propriedades do projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **Vinculador**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Insira a opção em **Opções Adicionais**:  
  
     `/opt:lbr`  
  
### Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte as propriedades <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EnableCOMDATFolding%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OptimizeReferences%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)