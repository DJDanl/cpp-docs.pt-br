---
title: "/J (o tipo char padr&#227;o n&#227;o &#233; assinado) | Microsoft Docs"
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
  - "VC.Project.VCCLCompilerTool.DefaultCharIsUnsigned"
  - "VC.Project.VCCLWCECompilerTool.DefaultCharIsUnsigned"
  - "/j"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /J (C++)"
  - "tipo de dados char"
  - "o tipo char padrão não é assinado"
  - "padrões, tipo char"
  - "Opção de compilador J [C++]"
  - "Opção de compilador -J [C++]"
ms.assetid: 50973667-6638-491e-9c41-bff73acae19f
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /J (o tipo char padr&#227;o n&#227;o &#233; assinado)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tipo padrão de `char` de `signed char` a `unsigned char`, e o tipo de `char` zero é estendido quando é alargado a um tipo de `int` .  
  
## Sintaxe  
  
```  
/J  
```  
  
## Comentários  
 Se um valor de `char` é declarado explicitamente como `signed`, a opção de **\/J** não afeta o, e o valor sinal\- é estendido quando é alargado a um tipo de `int` .  
  
 A opção de **\/J** define `_CHAR_UNSIGNED`, que é usada com `#ifndef` no arquivo de LIMITS.h para definir o intervalo do tipo padrão de `char` .  
  
 ANSI C e C\+\+ 2.0 não requer uma implementação específica do tipo de `char` .  Essa opção é útil quando você está trabalhando com dados de caractere que serão convertidos se houver em um idioma diferente do inglês.  
  
> [!NOTE]
>  Se você usar esta opção do compilador com ATL\/MFC, um erro pode ser gerado.  Embora você pode desabilitar esse erro definindo `_ATL_ALLOW_CHAR_UNSIGNED`, essa solução alternativa não tem suporte e não pode funcionar sempre.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Em **Gerenciador de Soluções**, abra o menu de atalho do projeto e escolha **Propriedades**.  
  
2.  Na caixa de diálogo de **Páginas de Propriedades** de projeto, no painel esquerdo em **Propriedades de Configuração**, expanda **C\/C\+\+** e selecione **Linha de Comando**.  
  
3.  No painel de **Opções Adicionais** , especifique a opção do compilador de **\/J** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DefaultCharIsUnsigned%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md)