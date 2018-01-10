---
title: -arch (x64) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: ecda22bf-5bed-43f4-99fb-88aedd83d9d8
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 27a453601988c22ed03ae9cb267480d88d6a1cc0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="arch-x64"></a>/arch (x64)
Especifica a arquitetura da geração de código em x64. Consulte também [/arch (x86)](../../build/reference/arch-x86.md) e [/arch (ARM)](../../build/reference/arch-arm.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/arch:[AVX|AVX2]  
```  
  
## <a name="arguments"></a>Arguments  
 **/arch: avx**  
 Habilita o uso de instruções Intel Advanced Vector Extensions.  
  
 **/arch: avx2**  
 Habilita o uso de instruções Intel Advanced Vector Extensions 2.  
  
## <a name="remarks"></a>Comentários  
 **/arch** somente afeta a geração de código para funções nativas. Quando você usa [/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **/arch** não tem nenhum efeito na geração de código para funções gerenciadas.  
  
 O `__AVX__` símbolo do pré-processador é definido quando o **/arch: avx** opção de compilador é especificada. O `__AVX2__` símbolo do pré-processador é definido quando o **/arch: avx2** opção de compilador é especificada. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md). O **/arch: avx2** opção foi introduzida no Visual Studio 2013 Update 2, versão 12.0.34567.1.  
  
### <a name="to-set-the-archavx-or-archavx2-compiler-option-in-visual-studio"></a>Para definir a opção do compilador /arch:AVX ou /arch:AVX2 no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **propriedades de configuração**, **C/C++** pasta.  
  
3.  Selecione o **geração de código** página de propriedades.  
  
4.  No **habilitar aprimorado do conjunto de instruções** suspensa caixa, escolha **Advanced Vector Extensions (/ /arch: AVX)** ou **Advanced Vector Extensions 2 (/ /arch: AVX2)**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)