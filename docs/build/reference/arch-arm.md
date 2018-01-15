---
title: -arch (ARM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 4f1406ff-f174-487c-a126-8ab06cf447c1
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 468401bcee2d627149175d022c420b8bb905c4ed
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="arch-arm"></a>/arch (ARM)
Especifica a arquitetura para a geração de código no ARM. Consulte também [/arch (x86)](../../build/reference/arch-x86.md) e [/arch (x64)](../../build/reference/arch-x64.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/arch:[ARMv7VE|VFPv4]  
```  
  
## <a name="arguments"></a>Arguments  
 **/arch:ARMv7VE**  
 Habilita o uso de instruções de Extensões de Virtualização ARMv7VE.  
  
 **/arch:VFPv4**  
 Habilita o uso de instruções ARM VFPv4. Se essa opção não for especificada, VFPv3 é o padrão.  
  
## <a name="remarks"></a>Comentários  
 O `_M_ARM_FP` macro (ARM) indica que, se houver, **/arch** opção de compilador foi usada. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).  
  
 Quando você usa [/clr](../../build/reference/clr-common-language-runtime-compilation.md) para compilar, **/arch** não tem nenhum efeito na geração de código para funções gerenciadas. **/arch** somente afeta a geração de código para funções nativas.  
  
### <a name="to-set-the-archarmv7ve-or-archvfpv4-compiler-option-in-visual-studio"></a>Para definir a opção do compilador /arch:ARMv7VE ou /arch:VFPv4 no Visual Studio  
  
1.  Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  No **opções adicionais** caixa, adicione `/arch:ARMv7VE` ou `/arch:VFPv4`.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableEnhancedInstructionSet%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/arch (arquitetura mínima de CPU)](../../build/reference/arch-minimum-cpu-architecture.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)