---
title: "/GZ (habilitar verifica&#231;&#227;o do erro de tempo de execu&#231;&#227;o do quadro da pilha) | Microsoft Docs"
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
  - "/gz"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador /GZ (C++)"
  - "depurar compilações, obter erros de compilação de lançamento"
  - "Opção de compilador GZ [C++]"
  - "Opção de compilador -GZ [C++]"
  - "erros de compilação de lançamento"
ms.assetid: b3efeeff-d5e3-4057-91c9-f6fc73d0270c
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /GZ (habilitar verifica&#231;&#227;o do erro de tempo de execu&#231;&#227;o do quadro da pilha)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa as mesmas operações que a opção de [\/RTC \(verificações de erro de tempo de execução\)](../../build/reference/rtc-run-time-error-checks.md) .  Preterido.  
  
## Sintaxe  
  
```  
/GZ  
```  
  
## Comentários  
 **\/GZ** é apenas para uso em uma construção nonoptimized \(de[\/Od \(desabilitar\)](../../build/reference/od-disable-debug.md)\).  
  
 **\/GZ** é substituído; use [\/RTC \(verificações de erro de tempo de execução\)](../../build/reference/rtc-run-time-error-checks.md) em vez disso.  Para obter mais informações, consulte [Deprecated Compiler Options in Visual C\+\+ 2005](http://msdn.microsoft.com/pt-br/aa59fce3-50b8-4f66-9aeb-ce09a7a84cce).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Clique na pasta **C\/C\+\+**.  
  
3.  Clique na página de propriedades de **Linha de Comando**.  
  
4.  Digite a opção do compilador na caixa de **Opções Adicionais** .  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)