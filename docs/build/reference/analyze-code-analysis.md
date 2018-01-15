---
title: "-Analisar (análise de código) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.EnablePREfast
- /analyze
- VC.Project.VCCLCompilerTool.PREfastAdditionalOptions
- VC.Project.VCCLCompilerTool.PREfastAdditionalPlugins
dev_langs: C++
helpviewer_keywords:
- /analyze compiler option [C++]
- -analyze compiler option [C++]
- analyze compiler option [C++]
ms.assetid: 81da536a-e030-4bd4-be18-383927597d08
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ba76ddd10866e414d9817f628c7a1aec019964de
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="analyze-code-analysis"></a>/analyze (Análise do código)
Habilita opções de análise e controle de código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/analyze[-][:WX-][:log filename][:quiet][:stacksize number][:max_paths number][:only]  
```  
  
## <a name="arguments"></a>Arguments  
 /analyze  
 Ativa a análise no modo padrão. Saída de análise vai para o **saída** janela como outras mensagens de erro. Use **/ANALYZE -** desativar explicitamente a análise.  
  
 /analyze:WX-  
 Especificando **/ANALYZE: WX -** significa que os avisos da análise de código não é tratadas como erros quando você compila usando **/WX**. Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../../build/reference/compiler-option-warning-level.md).  
  
 /analyze:log `filename`  
 Os resultados detalhados do analisador são gravados como XML no arquivo que é especificado por `filename`.  
  
 /analyze:quiet  
 Desativa a saída de analisador para o **saída** janela.  
  
 /analyze:stacksize `number`  
 O `number` parâmetro que é usado com esta opção especifica o tamanho, em bytes, do quadro de pilha para qual aviso [C6262](/visualstudio/code-quality/c6262) é gerado. Se esse parâmetro não for especificado, o tamanho do quadro da pilha será de 16 KB por padrão.  
  
 /analyze:max_paths `number`  
 O parâmetro `number` que é usado com essa opção especifica o número máximo de caminhos de códigos a serem analisados. Se esse parâmetro não for especificado, o número será 256 por padrão. Valores maiores executam uma verificação mais completa, mas a análise pode demorar mais.  
  
 /analyze:only  
 Normalmente, o compilador gera o código e faz mais verificação de sintaxe depois de executar o analisador. O **/ANALYZE: somente** opção desativa essa passagem de geração de código; isso torna a análise mais rápida, mas os erros de compilação e avisos que podem ter sido descobertos pela fase de geração de código do compilador não são emitidos. Se o programa não estiver livre de erros de geração de código, os resultados da análise poderão não ser confiáveis; consequentemente, recomendamos que você use essa opção apenas se o código já tiver passado na verificação da sintaxe de geração de código sem erros.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [análise de código para visão geral do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-overview) e [análise de código para avisos do C/C++](/visualstudio/code-quality/code-analysis-for-c-cpp-warnings).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **análise de código** nó.  
  
4.  Selecione o **geral** página de propriedades.  
  
5.  Modificar um ou mais do **análise de código** propriedades.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnablePREfast%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)