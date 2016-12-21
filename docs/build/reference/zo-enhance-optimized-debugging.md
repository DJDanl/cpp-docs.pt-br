---
title: "/Zo (Enhance Optimized Debugging) | Microsoft Docs"
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
  - "-Zo"
  - "/Zo"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Zo [C++]"
  - "Opção de compilador Zo [C++]"
  - "Opção de compilador -Zo [C++]"
ms.assetid: eea8d89a-7fe0-4fe1-86b2-7689bbebbd7f
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zo (Enhance Optimized Debugging)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Gere informações de depuração avançadas para código otimizado em compilações sem depuração.  
  
## Sintaxe  
  
```cpp  
/Zo[-]  
```  
  
## Comentários  
 O **\/Zo** comutador de compilador gera informações de depuração avançadas para código otimizado.  Otimização pode usar registros de variáveis locais, reordenar o código, vetorizar loops e chamadas de função embutida.  Essas otimizações podem obscurecer a relação entre o código\-fonte e o código de objeto compilado.  O **\/Zo** opção faz com que o compilador gerar informações de depuração adicionais para variáveis locais e funções embutidas.  Usá\-lo para ver as variáveis no **Autos**, **locais**, e **inspeção** otimização de windows quando você percorre o código no depurador do Visual Studio.  Ele também permite que os rastreamentos de pilha Mostrar funções embutidas no depurador WinDBG.  Depurar compilações desativaram as otimizações \([\/Od](../../build/reference/od-disable-debug.md)\) não é necessário para as informações de depuração adicionais geradas quando **\/Zo** for especificado.  Use o **\/Zo** switch para configurações de versão de depuração com a otimização ativada.  Para obter mais informações sobre opções de otimização, consulte [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md).  O **\/Zo** opção é habilitada por padrão no Visual Studio de 2015 quando você especificar informações de depuração com **\/Zi** ou **\/Z7**.  Especifique **\/Zo\-** explicitamente desativar essa opção de compilador.  
  
 O **\/Zo** switch está disponível no Visual Studio 2013 atualização 3 e substitui o antigo não documentado **\/d2Zi\+** Alternar.  
  
### Para definir a opção de compilador \/zo \* no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **Propriedades de Configuração**, **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modificar o **Opções adicionais** propriedade incluir `/zo *` e, em seguida, escolha **OK**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [\/O opções \(otimizar código\)](../../build/reference/o-options-optimize-code.md)   
 [\/Z7, \/Zi, \/ZI \(depurar formato de informações\)](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)   
 [Editar e continuar](../Topic/Edit%20and%20Continue.md)