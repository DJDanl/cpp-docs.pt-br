---
title: "/QIfist (suprimir _ftol) | Microsoft Docs"
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
  - "/qifist"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador QIfist [C++]"
  - "Opção de compilador -QIfist [C++]"
  - "Opção de compilador /QIfist (C++)"
ms.assetid: 1afd32a5-f658-4b66-85f4-e0ce4cb955bd
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /QIfist (suprimir _ftol)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suprime a chamada da função `_ftol` auxiliar quando uma conversão de um tipo de ponto flutuante a um tipo integral é necessária.  
  
## Sintaxe  
  
```  
/QIfist  
```  
  
## Comentários  
  
> [!NOTE]
>  **\/QIfist** está disponível somente no compilador que se destinam x86; essa opção de compilador não está disponível nos compiladores que têm o orARM de [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] .  
  
 Além de converter de um tipo de ponto flutuante o tipo integral, a função de `_ftol` assegura que o modo de arredondamento de unidade de ponto flutuante \(FPU\) está para zero \(truncam\), definindo os bits 10 e 11 do word de controle.  Isso garante que a conversão de um tipo de ponto flutuante a um tipo integral ocorre como descrito pelo padrão ANSI C \(a parte fracionária do número é descartada\).  Ao usar **\/QIfist**, essa garantia não se aplica.  O modo de arredondamento terá um de quatro conforme documentado nos manuais de referência Intel:  
  
-   Arredondar para o mais próximo \(mesmo se número equidistante\)  
  
-   Arredondar para o infinito negativo  
  
-   Arredondar para o infinito positivo  
  
-   Arredondar para zero  
  
 Você pode usar a função de tempo de execução de [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md) C para alterar o comportamento de arredondamento de FPU.  O modo de arredondamento padrão de FPU é “arredondar para o mais próximo.” Usar **\/QIfist** pode melhorar o desempenho de seu aplicativo, mas não sem o risco.  Você deve testar completamente as partes do código que são sensíveis a arredondar modos antes de usar o código compilado com **\/QIfist** em ambientes de produção.  
  
 [\/arch \(x86\)](../../build/reference/arch-x86.md) e **\/QIfist** não podem ser usados no mesmo compiland.  
  
> [!NOTE]
>  **\/QIfist** não é aplicado por padrão como os bits de arredondamento também afetam o ponto flutuante até o ponto flutuante que se arredonda \(que ocorre após cada cálculo\) portanto, quando você definir os sinalizadores para o c \- estilo 2.0 \(zero\) para que se arredonda, seus cálculos de ponto flutuante pode ser diferente.  **\/QIfist** não deverá ser usado se seu código depende do comportamento esperado de truncar a parte fracionária do número de ponto flutuante.  Se você não tiver certeza, não use **\/QIfist**.  
  
 **\/QIfist** é substituído.  O compilador feitas melhorias significativas em float a velocidade de conversão int.  Para obter mais informações, consulte [Deprecated Compiler Options in Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/Q Opções \(operações de nível baixo\)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)