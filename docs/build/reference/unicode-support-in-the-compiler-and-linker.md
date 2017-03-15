---
title: "Suporte Unicode no compilador e vinculador | Microsoft Docs"
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
  - "VC.Project.VCLinkerTool.UseUnicodeResponseFiles"
  - "VC.Project.VCLibrarianTool.UseUnicodeResponseFiles"
  - "VC.Project.VCCLCompilerTool.UseUnicodeResponseFiles"
  - "VC.Project.VCXDCMakeTool.UseUnicodeResponseFiles"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Unicode, Visual C++"
ms.assetid: acc1d322-56b9-4696-a30e-2af891a4e288
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Suporte Unicode no compilador e vinculador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve o suporte a Unicode nas ferramentas de compilação do Visual C\+\+.  
  
 Nomes de arquivos  
 Os nomes de arquivo especificados na linha de comando ou em diretivas de compilador \(como \#include\) agora podem conter caracteres Unicode.  
  
 Arquivos de código fonte  
 Os caracteres Unicode agora são tem suporte em identificadores, macros, cadeia de caracteres literais e em comentários.  Os nomes de caracteres universais também tem suporte agora.  
  
 Unicode pode ser inserido em um arquivo de código\-fonte nas codificações:  
  
-   Endian UTF\-16 pequeno com ou sem a marca de ordem de byte \(BOM\)  
  
-   Endian UTF\-16 grande com ou sem BOM  
  
-   UTF\-8 com BOM  
  
 Saída  
 Durante a compilação, o compilador terá como saída de diagnóstico o console no UTF\-16.  Os caracteres que podem ser exibidos no console dependem das propriedades da janela do console.  A saída do compilador redirecionada para um arquivo está na página de código atual do console ANSI.  
  
 Arquivos de resposta de vinculador e arquivos.DEF  
 Arquivos de resposta e arquivos DEF podem ser UTF\-16 com uma Marca de Pedido de Bytes ou ANSI.  Anteriormente somente ANSI tinha suporte.  
  
 despejos de .asm e .cod  
 os despejos de .asm e .cod estão em ANSI por padrão para compatibilidade com MASM.  Use \/FAu para a saída UTF\-8.  Observe que se você especificar \/FAs, a origem misturada será diretamente impressa e poderá parecer truncada, por exemplo se o código\-fonte for UTF\-8 e se você não especificou \/FAsu.  
  
 Você pode habilitar nomes de arquivo Unicode no ambiente de desenvolvimento \(consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md)\) selecionando a ferramenta apropriada e selecionando a propriedade **Ativar arquivos de resposta Unicode**, que é ativada por padrão.  Um motivo para alterar essa opção padrão é quando você modifica o ambiente de desenvolvimento para usar um compilador que não tenha suporte a Unicode.  
  
## Consulte também  
 [Compilando na linha de comando](../Topic/Building%20on%20the%20Command%20Line.md)