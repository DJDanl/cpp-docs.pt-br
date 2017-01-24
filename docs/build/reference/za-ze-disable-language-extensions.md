---
title: "-Za, - Ze (desabilitar extens&#245;es de linguagem) | Microsoft Docs"
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
  - "VC.Project.VCCLWCECompilerTool.DisableLanguageExtensions"
  - "/za"
  - "/ze"
  - "VC.Project.VCCLCompilerTool.DisableLanguageExtensions"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador -Za [C++]"
  - "Opção de compilador Za [C++]"
  - "extensões de linguagem, desabilitando no compilador"
  - "Opção de compilador -Ze [C++]"
  - "extensões de linguagem"
  - "habilitar extensões de linguagem"
  - "Opção de compilador /Za (C++)"
  - "Opção de compilador /Ze (C++)"
  - "Opção de compilador Desabilitar Extensões de Linguagem"
  - "Opção de compilador Ze [C++]"
ms.assetid: 65e49258-7161-4289-a176-7c5c0656b1a2
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Za, /Ze (desabilitar extens&#245;es de linguagem)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O **\/Za** opção de compilador emitirá um erro para construções de linguagem que não são compatíveis com C89 ANSI ou ISO C\+\+ 11. O **\/Ze** opção de compilador, que é ativado por padrão, permite que extensões da Microsoft.  
  
## Sintaxe  
  
```  
/Za  
/Ze  
```  
  
## Comentários  
  
> [!NOTE]
>  O **\/Ze** opção é preterida como seu comportamento é ativado por padrão. Recomendamos que você use o [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md) Opções do compilador para controlar recursos de extensão de idioma específico. Para obter uma lista de opções preteridas do compilador, consulte o **preteridos e removidos opções do compilador** seção [Opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).  
  
 O [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)] compilador oferece uma série de recursos além daqueles especificados nos padrões ANSI C89, ISO C99 ou ISO C\+\+. Esses recursos são conhecidos coletivamente como extensões da Microsoft para C e C\+\+. Essas extensões estão disponíveis por padrão e não está disponível quando o **\/Za** opção é especificada. Para obter mais informações sobre extensões específicas, consulte [Extensões da Microsoft para C e C\+\+](../../build/reference/microsoft-extensions-to-c-and-cpp.md).  
  
 Recomendamos que você desabilite extensões de linguagem, especificando o **\/Za** opção se você planeja portar seu programa para outros ambientes. Quando **\/Za** for especificado, o compilador trata Microsoft estendido palavras\-chave como identificadores simples, desativa as extensões do Microsoft e define automaticamente o `__STDC__` macro predefinida para programas em C.  
  
 Outras opções do compilador usadas com **\/Za** podem afetar como o compilador garante a conformidade com os padrões. Por exemplo, **\/Za** e [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md) pode resultar em comportamento de promoção de tipo de ponto flutuante que não estão de acordo com a ISO C99 ou C \+ \+ 11 padrões.  
  
 Para obter maneiras especificar as configurações de comportamento específico em conformidade com padrões, consulte o [\/Zc](../../build/reference/zc-conformance.md) opção de compilador.  
  
 Para obter mais informações sobre problemas de conformidade com [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)], consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  No painel de navegação, escolha **Propriedades de configuração**, **C\/C\+\+**, **idioma**.  
  
3.  Modificar o **Desabilitar extensões de linguagem** propriedade.  
  
### Para definir essa opção de compilador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableLanguageExtensions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)