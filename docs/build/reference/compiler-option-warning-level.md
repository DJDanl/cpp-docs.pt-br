---
title: "-w,-W0,-W1, - W2,-W3, - W4,-S1,-w2,-w3,-w4,-parede, -wd,-, -wo, -Wv, - WX (n&#237;vel de aviso) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.DisableSpecificWarnings"
  - "VC.Project.VCCLCompilerTool.WarningLevel"
  - "VC.Project.VCCLWCECompilerTool.DisableSpecificWarnings"
  - "VC.Project.VCCLCompilerTool.WarnAsError"
  - "VC.Project.VCCLWCECompilerTool.WarnAsError"
  - "/wx"
  - "VC.Project.VCCLWCECompilerTool.WarningLevel"
  - "/wall"
  - "VC.Project.VCCLCompilerTool.TreatSpecificWarningsAsErrors"
  - "/Wv"
  - "/w0"
  - "/w1"
  - "/w2"
  - "/w3"
  - "/w4"
  - "/wd"
  - "/we"
  - "/wo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /W1 (C++)"
  - "Opção de compilador w [C++]"
  - "opção do compilador -wo [C++]"
  - "Opção de compilador Nível de Aviso"
  - "Opção de compilador W1 [C++]"
  - "Opção de compilador -we [C++]"
  - "Opção de compilador /WX (C++)"
  - "Opção de compilador -wd [C++]"
  - "Opção de compilador WX [C++]"
  - "opção do compilador wo [C++]"
  - "Opção de compilador Wall [C++]"
  - "Opção de compilador /w"
  - "Opção de compilador W2 [C++]"
  - "Opção de compilador -W2 [C++]"
  - "Opção de compilador wd [C++]"
  - "Opção de compilador /we (C++)"
  - "Opção de compilador we [C++]"
  - "Opção de compilador -W1 [C++]"
  - "Opção de compilador -W4 [C++]"
  - "Opção de compilador -Wall [C++]"
  - "Opção de compilador /Wall (C++)"
  - "Opção de compilador -W0 [C++]"
  - "Opção de compilador W0 [C++]"
  - "Opção de compilador -WX [C++]"
  - "Opção de compilador /wo (C++)"
  - "Opção de compilador W4 [C++]"
  - "Opção de compilador W3 [C++]"
  - "Opção de compilador /wd (C++)"
  - "opção de compilador erros como avisos"
  - "Opção de compilador /W3 (C++)"
  - "Opção de compilador /W0 (C++)"
  - "Opção de compilador /W4 (C++)"
  - "Opção de compilador -W3 [C++]"
  - "Opção de compilador -w [C++]"
  - "Opção de compilador /W2 (C++)"
  - "Opção de compilador /wv [C++]"
ms.assetid: d6bc7bf5-c754-4879-909c-8e3a67e2629f
caps.latest.revision: 21
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /, /wo, /Wv, /WX (n&#237;vel de aviso)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica como o compilador gera avisos para uma determinada compilação.  
  
## Sintaxe  
  
```  
/w  
/W0  
/W1  
/W2  
/W3  
/W4  
/Wall  
/Wv[<version>]  
/WX  
/w1<warning>   
/w2<warning>   
/w3<warning>   
/w4<warning>   
/wd<warning>   
/we<warning>   
/wo<warning>  
```  
  
## Comentários  
 As opções de aviso especificam quais avisos do compilador para exibição e o comportamento de aviso para a compilação inteira.  
  
 As opções de aviso e argumentos relacionados são descritos na tabela a seguir:  
  
|Opção|Descrição|  
|-----------|---------------|  
|**\/w**|Desabilita todos os avisos do compilador.|  
|**\/ W0**<br /><br /> **\/ W1**<br /><br /> **\/ W2**<br /><br /> **\/ W3**<br /><br /> **\/ S4**|Especifica o nível de avisos para ser gerado pelo compilador. Os níveis de aviso válido variam de 0 a 4:<br /><br /> -   **\/W0** desabilita todos os avisos.<br />-   **\/W1** exibe avisos de nível 1 \(grave\).**\/W1** é a configuração padrão.<br />-   **\/W2** exibe nível 1 e avisos de nível 2 \(significativos\).<br />-   **\/W3** monitores de nível 1, nível 2 e avisos de nível 3 \(qualidade de produção\).<br />-   **\/W4** exibe nível 1, nível 2 e avisos de nível 3, e todos os de nível 4 avisos \(informativos\) que não são desativados por padrão. É recomendável que você use esta opção somente para fornecer avisos lint\-like. No entanto, para um novo projeto, talvez seja melhor usar **\/W4** em todas as compilações; Isso garantirá que os defeitos possíveis para encontrar código menor.|  
|**\/ Parede**|Exibe todos os avisos são exibidos por **\/W4** e todos os outros avisos que **\/W4** não inclui — por exemplo, os avisos são desativados por padrão. Para obter mais informações, consulte [compilador avisos que está desativada por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md).|  
|**\/WV** `version`|Desabilitar avisos introduzidos em versões do compilador mais recentes que `version`. Você pode usar essa opção para determinar se há novos avisos no código compilado sem avisos ao usar uma versão mais antiga do compilador e removê\-los da sua compilação. O parâmetro opcional `version` assume a forma `nn`\[.`mm`\[.`bbbbb`\]\] onde `nn` é o número de versão principal, `mm` é o número de versão secundária opcional, e `bbbbb` é o número de compilação opcional do compilador. Por exemplo, use `/Wv17.00.00000` para desativar avisos introduzidos no Visual C\+\+ 2012 e versões posteriores. Por padrão, **\/Wv** usa o número de versão atual do compilador e sem avisos estão desabilitados.|  
|**\/WX**|Trata todos os avisos do compilador como erros. Para um novo projeto, talvez seja melhor usar **\/WX** em todas as compilações; resolver todos os avisos garante os menor número defeitos de código da localizar possíveis.<br /><br /> O vinculador também tem um **\/WX** opção. Para obter mais informações, consulte [\/WX \(tratar avisos do vinculador como erros\)](../../build/reference/wx-treat-linker-warnings-as-errors.md).|  
|**\/W1** `n`<br /><br /> **\/w2** `n`<br /><br /> **\/w3** `n`<br /><br /> **\/W4** `n`|Define o nível de aviso para o número de aviso especificado pelo `n`. Isso lhe permite alterar o comportamento do compilador para que o aviso quando um nível de aviso específico é definido. Você pode usar essas opções em combinação com outras opções de aviso para aplicar suas própria codificação padrões para avisos, em vez dos valores padrão fornecidos pelo Visual Studio.<br /><br /> Por exemplo, `/w34326` faz com que C4326 seja gerado como um aviso de nível 3, em vez de nível 1. Se você compilar usando ambos os `/w34326` opção e o `/W2` opção aviso C4326 não é gerado.|  
|**\/WD** `n`|Desabilita o aviso do compilador que é especificado pelo `n`.<br /><br /> Por exemplo, `/wd4326` desabilita C4326 de aviso do compilador.|  
|**\/We** `n`|Trata o aviso do compilador que é especificado pelo `n` como um erro.<br /><br /> Por exemplo, `/we4326` faz com que o número de aviso C4326 deve ser tratado como um erro pelo compilador.|  
|**\/WO** `n`|Relatórios de aviso de compilador que é especificado pelo `n` apenas uma vez.<br /><br /> Por exemplo, `/wo4326` faz com que o aviso C4326 a serem relatados e apenas uma vez, na primeira vez que ela for encontrada pelo compilador.|  
  
 Se você usar qualquer uma das opções de aviso quando você criar um cabeçalho pré\-compilado usando o [\/Yc](../../build/reference/yc-create-precompiled-header-file.md) opção, qualquer uso do cabeçalho pré\-compilado usando o [\/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção faz com que as mesmas opções de aviso estar em vigor novamente. Você pode substituir as opções de aviso definidas no cabeçalho pré\-compilado usando outra opção de aviso na linha de comando.  
  
 Você pode usar um [\#pragma aviso](../../preprocessor/warning.md) diretiva para controlar o nível de aviso que é relatado em tempo de compilação nos arquivos de origem específico.  
  
 Diretivas de aviso pragma no código\-fonte não são afetadas pelo **\/w** opção.  
  
 O [documentação de erros de compilação](../../error-messages/compiler-errors-1/c-cpp-build-errors.md) descreve os avisos e os níveis de aviso e indica por que determinadas instruções podem não ser compilados como você deseja.  
  
### Para definir a opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione **C\/C\+\+**.  
  
3.  Sobre o **geral** propriedade, modifique o **nível de aviso** ou **tratar avisos como erros** propriedades.  
  
4.  Sobre o **Avançado** propriedade, modifique o **desabilitar avisos específicos** propriedade.  
  
5.  Para as opções restantes, no **linha de comando** propriedade página, digite a opção de compilador no **Opções adicionais** caixa.  
  
### Para definir a opção de compilador por meio de programação  
  
-   See <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarningLevel%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarnAsError%2A>, <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableSpecificWarnings%2A>, and <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)