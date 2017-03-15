---
title: "/Yd (colocar informa&#231;&#245;es de depura&#231;&#227;o no arquivo de projeto) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/yd"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Yd (C++)"
  - "depurando [C++], arquivos de informações de depuração"
  - "Opção de compilador Yd [C++]"
  - "Opção de compilador -Yd [C++]"
ms.assetid: c5a699fe-65ce-461e-964c-7f5eb2a8320a
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Yd (colocar informa&#231;&#245;es de depura&#231;&#227;o no arquivo de projeto)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Os ritmos exibe informações de depuração em todos os arquivos criados de objeto de um arquivo de cabeçalho .pch pré\-compilado \(\) quando usados com as opções de [\/Yc](../../build/reference/yc-create-precompiled-header-file.md) e de [\/Z7](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) .  Preterido.  
  
## Sintaxe  
  
```  
/Yd  
```  
  
## Comentários  
 **\/Yd** é substituído; [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] agora oferece suporte aos objetos de vários que gravam em um único arquivo .pdb, use **\/Zi** em vez disso.  Para obter mais informações, consulte [Deprecated Compiler Options in Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
 A menos que você precise distribuir uma biblioteca que contém informações de depuração, use a opção de [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) em vez de **\/Z7** e **\/Yd**.  
  
 Armazenar informações de depuração completo em cada arquivo de .obj é necessário para distribuir apenas as bibliotecas que contêm informações de depuração.  Retarda\-se a criação e requer espaço em disco considerável.  Quando **\/Yc** e **\/Z7** são usados sem **\/Yd**, as informações de depuração comuns das lojas do compilador no primeiro arquivo de .obj criou do arquivo de .pch.  O compilador não insere essas informações nos arquivos de .obj criados posteriormente do arquivo de .pch; insere referências cruzadas às informações.  Não importando quantos arquivos de .obj usam o arquivo de .pch, somente um arquivo de .obj contém informações de depuração comuns.  
  
 Embora esse comportamento padrão resulta em uma construção mais rápida hora e reduzir as demandas de espaço, ele é indesejável se uma pequena alteração exige recriar o arquivo de .obj que contém informações de depuração comuns.  Nesse caso, o compilador deve recriar todos os arquivos de .obj que contêm referências cruzadas para o arquivo original .obj.  Além disso, se um arquivo de .pch comum é usado por projetos diferentes, a confiança em referências cruzadas em um único arquivo de .obj é difícil.  
  
 Para obter mais informações sobre cabeçalhos pré\-compilados, consulte:  
  
-   [\/Y \(cabeçalhos pré\-compilados\)](../../build/reference/y-precompiled-headers.md)  
  
-   [Criando arquivos de cabeçalho pré\-compilados](../../build/reference/creating-precompiled-header-files.md)  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção de compilador na caixa **Opções Adicionais**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Exemplos  
 Suponha que você tenha dois arquivos de base, F.cpp e G.cpp, que contém cada dessas instruções de **\#include** :  
  
```  
#include "windows.h"  
#include "etc.h"  
```  
  
 O comando a seguir cria o arquivo de cabeçalho pré\-compilado ETC.pch e o arquivo de objeto F.obj:  
  
```  
CL /YcETC.H /Z7 F.CPP  
```  
  
 O arquivo de objeto F.obj inclui o tipo e as informações do símbolo para WINDOWS.h e ETC.h \(e alguns outros arquivos de cabeçalho que inclua\).  Agora você pode usar o cabeçalho pré\-compilado ETC.pch para criar o arquivo de origem G.cpp:  
  
```  
CL /YuETC.H /Z7 G.CPP  
```  
  
 O arquivo de objeto G.obj não inclui informações de depuração para o cabeçalho pré\-compilado mas somente as referências que informações no arquivo de F.obj.  Observe que você deve vincular ao arquivo de F.obj.  
  
 Se o cabeçalho pré\-compilado não foi criado com **\/Z7**, você ainda pode usá\-lo nas compilações posteriores usando **\/Z7**.  No entanto, as informações de depuração é colocada no arquivo do objeto atual, e símbolos locais para as funções e tipos definidos no cabeçalho pré\-compilado não estão disponíveis para o depurador.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)