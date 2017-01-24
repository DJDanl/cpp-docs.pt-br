---
title: "/GL (otimiza&#231;&#227;o de todo o programa) | Microsoft Docs"
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
  - "/gl"
  - "VC.Project.VCCLWCECompilerTool.WholeProgramOptimization"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /GL (C++)"
  - "Opção de compilador GL [C++]"
  - "Opção de compilador -GL [C++]"
  - "otimizações de programa total e compilador C++"
ms.assetid: 09d51e2d-9728-4bd0-b5dc-3b8284aca1d1
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GL (otimiza&#231;&#227;o de todo o programa)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilita a otimização do programa inteiro.  
  
## Sintaxe  
  
```  
/GL[-]  
```  
  
## Comentários  
 A otimização de programa inteira permite que o compilador executa otimizações com informações sobre todos os módulos do programa.  Sem otimização de programa inteira, as otimizações são executadas na base de módulo \(compiland\).  
  
 A otimização de programa inteira é por padrão e deve ser explicitamente habilitada.  No entanto, também é possível desabilitar explicitamente com **\/GL\-**.  
  
 Com informações sobre todos os módulos, o compilador pode:  
  
-   Otimizar o uso dos registros nos limites da função.  
  
-   Faça um trabalho melhores do controle de alterações nos dados globais, permitindo a redução no número de cargas e de repositório.  
  
-   Faça um trabalho de melhores possível controlar o conjunto de itens alterados por um ponteiro eliminam, reduzindo os números de cargas e de repositório.  
  
-   Uma função embutida em um módulo mesmo quando a função é definida em outro módulo.  
  
 os arquivos de .obj gerados com **\/GL** não estarão disponíveis em utilitários do vinculador como [EDITBIN](../Topic/EDITBIN%20Reference.md) e [DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
 Se você criar seu programa com **\/GL** e [\/c](../../build/reference/c-compile-without-linking.md), você deve usar a opção do vinculador de \/LTCG criar o arquivo de saída.  
  
 [\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) não pode ser usado com **\/GL**  
  
 O formato dos arquivos gerados com **\/GL** na versão atual não pode ser legível por versões subsequentes do Visual C\+\+.  Você não precisa enviar um arquivo de .lib entendido dos arquivos de .obj que foram gerados com **\/GL** a menos que você está disposto enviar cópias do arquivo de .lib para todas as versões do Visual C\+\+ que você espera que os usuários se usar, agora e no futuro.  
  
 os arquivos de .obj gerados com **\/GL** e os arquivos de cabeçalho pré\-compilados não devem ser usados para criar um arquivo de .lib a menos que o arquivo de .lib é vinculado no mesmo computador que gerou o arquivo de **\/GL** .obj.  Informações do arquivo de cabeçalho pré\-compilado do arquivo de .obj será necessária no tempo de link.  
  
 Para obter mais informações sobre as otimizações disponíveis com e as limitações de otimização do programa inteira, consulte [\/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  **\/GL** também faz a otimização orientada perfil disponível; consulte \/LTCG.  Ao criar para o perfil guiou otimizações e se desejar que a função da ordenação das otimizações guiadas perfil, você deve criar [\/Gy](../../build/reference/gy-enable-function-level-linking.md) ou com um padrão do compilador que implica \/Gy.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Consulte [\/LTCG \(geração de código do tempo de vinculação\)](../../build/reference/ltcg-link-time-code-generation.md) para obter informações sobre como especificar **\/GL** no ambiente de desenvolvimento.  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WholeProgramOptimization%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)