---
title: "/Fe (nomear arquivo EXE) | Microsoft Docs"
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
  - "/fe"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /Fe (C++)"
  - "arquivos executáveis, renomeando"
  - "Opção de compilador Fe [C++]"
  - "Opção de compilador -Fe [C++]"
  - "Opção de compilador renomear arquivo [C++]"
ms.assetid: 49f594fd-5e94-45fe-a1bf-7c9f2abb6437
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Fe (nomear arquivo EXE)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica um nome e um diretório para o arquivo ou a DLL criado pelo compilador.  
  
## Sintaxe  
  
```  
/Fepathname  
```  
  
## Comentários  
 Sem esta opção, o compilador da ao arquivo um nome padrão usando o nome de base do primeiro arquivo de origem ou do objeto especificado na linha de comando e a extensão .exe ou .dll.  
  
 Se você especificar[\/c \(compilar sem vinculação\)](../../build/reference/c-compile-without-linking.md), para construir sem vincular, **\/Fe** não tem nenhum efeito.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na páginade propriedades de **Geral**.  
  
4.  Modifique a propriedade de **Arquivo de Saída** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.  
  
## Exemplo  
 A linha de comando a seguir cria e vincular todos os arquivos de origem de C no diretório atual.  O arquivo executável resultante é denominado e PROCESS.exe criado no diretório C:\\BIN.  
  
```  
CL /FeC:\BIN\PROCESS *.C  
```  
  
## Exemplo  
 A linha de comando a seguir cria um arquivo executável em `C:\BIN` com o mesmo nome de base que o primeiro arquivo de origem ou de objeto:  
  
```  
CL /FeC:\BIN\ *.C  
```  
  
## Consulte também  
 [Opções do arquivo de saída \(\/F\)](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Especificando o nome de caminho](../Topic/Specifying%20the%20Pathname.md)