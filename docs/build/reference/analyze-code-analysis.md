---
title: "/analyze (An&#225;lise do c&#243;digo) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.EnablePREfast"
  - "/analyze"
  - "VC.Project.VCCLCompilerTool.PREfastAdditionalOptions"
  - "VC.Project.VCCLCompilerTool.PREfastAdditionalPlugins"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção /analyze do compilador [C++]"
  - "Opção analyze do compilador [C++]"
  - "Opção -analyze do compilador [C++]"
ms.assetid: 81da536a-e030-4bd4-be18-383927597d08
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /analyze (An&#225;lise do c&#243;digo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita opções de análise e controle de código.  
  
## Sintaxe  
  
```  
/analyze[-][:WX-][:log filename][:quiet][:stacksize number][:max_paths number][:only]  
```  
  
## Argumentos  
 \/analyze  
 Ativa a análise no modo padrão.  O resultado da análise vai para a janela **Saída** como as outras mensagens de erro.  Use **\/analyze\-** para desativar explicitamente a análise.  
  
 \/analyze:WX\-  
 Especificar **\/analyze:WX\-** significa que os avisos de análise de código não são tratados como erros quando você compila usando **\/WX**.  Para obter mais informações, consulte [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../../build/reference/compiler-option-warning-level.md).  
  
 \/analyze:log `filename`  
 Os resultados detalhados do analisador são gravados como XML no arquivo que é especificado por `filename`.  
  
 \/analyze:quiet  
 Desativa a saída do analisador para a janela **Saída**.  
  
 \/analyze:stacksize `number`  
 O parâmetro `number` usado com essa opção especifica o tamanho, em bytes, do quadro da pilha para o qual o aviso [C6262](../Topic/C6262.md) é gerado.  Se esse parâmetro não for especificado, o tamanho do quadro da pilha será de 16 KB por padrão.  
  
 \/analyze:max\_paths `number`  
 O parâmetro `number` que é usado com essa opção especifica o número máximo de caminhos de códigos a serem analisados.  Se esse parâmetro não for especificado, o número será 256 por padrão.  Valores maiores executam uma verificação mais completa, mas a análise pode demorar mais.  
  
 \/analyze:only  
 Normalmente, o compilador gera o código e faz mais verificação de sintaxe depois de executar o analisador.  A opção **\/analyze:only** desativa a aprovação da geração de código; isso torna a análise mais rápida, mas os erros e avisos de compilação que podem ter sido identificados pela aprovação da geração de código do compilador não serão emitidos.  Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis; consequentemente, recomendamos que você use essa opção apenas se o código já tiver passado na verificação da sintaxe de geração de código sem erros.  
  
## Comentários  
 Para obter mais informações, consulte [Análise de código para visão geral do C\/C\+\+](../Topic/Code%20Analysis%20for%20C-C++%20Overview.md) e [Análise de código para avisos do C\/C\+\+](../Topic/Code%20Analysis%20for%20C-C++%20Warnings.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Análise de Código**.  
  
4.  Selecione a página de propriedades **Geral**.  
  
5.  Modifique uma ou mais propriedades de **Análise de Código**.  
  
### Para definir essa opção do compilador via programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)