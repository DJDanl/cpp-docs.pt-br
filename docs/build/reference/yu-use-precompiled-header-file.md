---
title: "/Yu (usar arquivo de cabe&#231;alho pr&#233;-compilado) | Microsoft Docs"
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
  - "/yu"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .pch, usar existente"
  - "Opção de compilador /Yu (C++)"
  - "arquivos PCH, usar existente"
  - "arquivos de cabeçalho pré-compilado, usar existente"
  - "Opção de compilador Yu [C++]"
  - "Opção de compilador -Yu [C++]"
ms.assetid: 24f1bd0e-b624-4296-a17e-d4b53e374e1f
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Yu (usar arquivo de cabe&#231;alho pr&#233;-compilado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instrui o compilador para usar um arquivo de cabeçalho pré\-compilado existente \(.pch\) na compilação atual.  
  
## Sintaxe  
  
```  
/Yu[filename]  
```  
  
## Arguments  
 *filename*  
 O nome de um arquivo de cabeçalho, que está incluído no arquivo de origem usando uma política de pré\-processador de **\#include** .  
  
## Comentários  
 O nome do arquivo incluir deve ser o mesmo para a opção de **\/Yc** que cria o cabeçalho pré\-compilado e qualquer opção subsequente de **\/Yu** que indicam o uso do cabeçalho pré\-compilado.  
  
 Para **\/Yc**, `filename` especifica o ponto em que o precompilation para; o compilador precompiles todo o código embora `filename` e nomeia o cabeçalho pré\-compilado resultante usando o nome de arquivo e de incluir uma extensão de .pch.  
  
 O arquivo de .pch deve ter sido criado usando **\/Yc**.  
  
 O compilador trata qualquer código que ocorre antes que o arquivo de .h como pré\-compilado.  Ignora apenas além da política de **\#include** ao associada ao arquivo de .h, use o código contido no arquivo de .pch, e depois criará todo o código após `filename`.  
  
 Na linha de comando, nenhum espaço é permitido entre **\/Yu** e `filename`.  
  
 Quando você especifica a opção de **\/Yu** sem um nome de arquivo, o programa de origem deve conter um pragma que especifica o nome do arquivo de cabeçalho pré\-compilado, o arquivo de [hdrstop de \#pragma](../../preprocessor/hdrstop.md) de .pch.  Nesse caso, o compilador usará o cabeçalho pré\-compilado \(arquivo de .pch\) nomeada por [\/Fp \(nomear arquivo .Pch\)](../Topic/-Fp%20\(Name%20.Pch%20File\).md).  O compilador salta para o local do pragma, restaura o estado criado a partir do arquivo de cabeçalho pré\-compilado especificado pelo pragma, e depois criará somente o código que segue o pragma.  Se **\#pragma hdrstop** não especificar um nome de arquivo, o compilador procura um arquivo com um nome derivado do nome de arquivo de origem por uma extensão de .pch.  Você também pode usar a opção de **\/Fp** especificar um arquivo diferente de .pch.  
  
 Se você especificar a opção de **\/Yu** sem um nome de arquivo e uma falha especificar um pragma de **hdrstop** , será gerada uma mensagem de erro e a compilação é bem\-sucedida.  
  
 Se **\/Yc**`filename` e as opções de **\/Yu**`filename` ocorrem na mesma linha de comando e ambos fazem referência ao mesmo nome de arquivo, **\/Yc**`filename` prevalece, precompiling todo o código até e incluindo o arquivo chamado.  Esse recurso simplifica a gravação de makefiles.  
  
 Como os arquivos de .pch contêm informações sobre o ambiente do computador bem como informações de endereço de memória sobre o programa, você só deve usar um arquivo de pch no computador em que foi criado.  
  
 Para obter mais informações sobre cabeçalhos pré\-compilados, consulte:  
  
-   [\/Y \(cabeçalhos pré\-compilados\)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Especifique [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md) em um arquivo .cpp em seu projeto.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
3.  Clique na pasta **C\/C\+\+**.  
  
4.  Clique na página de propriedades de **Cabeçalhos Pré\-Compilados** .  
  
5.  Modifique a propriedade de **Criar\/uso com PCH Arquivo** ou a propriedade de **Cabeçalho pré\-compilado criar\/uso** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderThrough%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>.  
  
## Exemplos  
 Se o seguinte código:  
  
```  
#include <afxwin.h>   // Include header for class library  
#include "resource.h" // Include resource definitions  
#include "myapp.h"    // Include information specific to this app  
...  
```  
  
 é compilado com a linha de comando `CL /YuMYAPP.H PROG.CPP`, o compilador não processa os três incluem o código pré\-compilada de instruções mas de MYAPP.pch, economizando assim o tempo envolvidos neles todos os três arquivos \(e para alguns arquivos que podem incluir\).  
  
 Você pode usar a opção de [\/Fp \(nomear arquivo .Pch\)](../Topic/-Fp%20\(Name%20.Pch%20File\).md) com a opção de **\/Yu** especifique o nome do arquivo de .pch se o nome for diferente do argumento de nome de arquivo a **\/Yc** ou o nome de arquivo de origem, como a seguir:  
  
```  
CL /YuMYAPP.H /FpMYPCH.pch PROG.CPP  
```  
  
 Esse comando especifica um arquivo de cabeçalho pré\-compilado nomeada MYPCH.pch.  O compilador usa seu conteúdo para restaurar o estado pré\-compilado de todos os arquivos de cabeçalho até e incluindo MYAPP.h.  O compilador compilará o código que ocorre após a instrução de MYAPP.h **include** .  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)