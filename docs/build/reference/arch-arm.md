---
title: "/arch (ARM) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 4f1406ff-f174-487c-a126-8ab06cf447c1
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /arch (ARM)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica a arquitetura para a geração de código no ARM.  Consulte também [\/arch \(x86\)](../../build/reference/arch-x86.md) e [\/arch \(x64\)](../../build/reference/arch-x64.md).  
  
## Sintaxe  
  
```  
/arch:[ARMv7VE|VFPv4]  
```  
  
## Arguments  
 **\/arch:ARMv7VE**  
 Habilita o uso de instruções de Extensões de Virtualização ARMv7VE.  
  
 **\/arch:VFPv4**  
 Habilita o uso de instruções ARM VFPv4.  Se essa opção não for especificada, VFPv3 é o padrão.  
  
## Comentários  
 A macro `_M_ARM_FP` macro \(apenas para ARM\) indica qual, se houver alguma, opção do compilador **\/arch** foi usada.  Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 Ao usar [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **\/arch** não tem efeito sobre a geração de código para funções gerenciadas.  A opção **\/arch** afeta somente a geração de código de funções nativas.  
  
### Para definir a opção do compilador \/arch:ARMv7VE ou \/arch:VFPv4 no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Na caixa **Opções adicionais**, adicione `/arch:ARMv7VE` ou `/arch:VFPv4`.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.  
  
## Consulte também  
 [\/arch \(arquitetura mínima de CPU\)](../../build/reference/arch-minimum-cpu-architecture.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)