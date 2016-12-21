---
title: "/arch (x64) | Microsoft Docs"
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
ms.assetid: ecda22bf-5bed-43f4-99fb-88aedd83d9d8
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /arch (x64)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica a arquitetura da geração de código em x64.  Consulte também [\/arch \(x86\)](../../build/reference/arch-x86.md) e [\/arch \(ARM\)](../../build/reference/arch-arm.md).  
  
## Sintaxe  
  
```  
/arch:[AVX|AVX2]  
```  
  
## Argumentos  
 **\/arch:AVX**  
 Habilita o uso de instruções Intel Advanced Vector Extensions.  
  
 **\/arch:AVX2**  
 Habilita o uso de instruções Intel Advanced Vector Extensions 2.  
  
## Comentários  
 A opção **\/arch** afeta somente a geração de código de funções nativas.  Ao usar [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **\/arch** não tem efeito sobre a geração de código para funções gerenciadas.  
  
 O símbolo do pré\-processador `__AVX__` é definido quando a opção do compilador **\/arch:AVX** é especificada.  O símbolo do pré\-processador `__AVX2__` é definido quando a opção do compilador **\/arch:AVX2** é especificada.  Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  A opção **\/arch:AVX2** foi introduzida na Atualização 2 do Visual Studio 2013, versão 12.0.34567.1.  
  
### Para definir a opção do compilador \/arch:AVX ou \/arch:AVX2 no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione a pasta **Propriedades de Configuração**, **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Geração de Código**.  
  
4.  No **Habilitar conjunto de instruções de aprimorada** suspensa caixa, escolha **Advanced Vector Extensions \(\/ \/arch: AVX\)** ou **Advanced Vector Extensions 2 \(\/ \/arch: AVX2\)**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.  
  
## Consulte também  
 [\/arch \(arquitetura mínima de CPU\)](../../build/reference/arch-minimum-cpu-architecture.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)