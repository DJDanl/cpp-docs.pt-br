---
title: -Qsafe_fp_loads | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 2b2ce52d-ba57-4bd3-a739-47a7f8bfaba9
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a9e572c8a4d353aaee4e82e8c7bdc3f719475c03
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="qsafefploads"></a>/Qsafe_fp_loads
Requer as instruções de movimentação de inteiro para valores de ponto flutuante e desabilita determinadas otimizações de carregamento de ponto flutuante.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qsafe_fp_loads  
```  
  
## <a name="remarks"></a>Comentários  
 **/Qsafe_fp_loads** só está disponível nos compiladores de destino x86; ele não está disponível nos compiladores que x64 ou ARM de destino.  
  
 **/Qsafe_fp_loads** força o compilador para usar instruções de movimentação de inteiro em vez de instruções de ponto flutuante de movimentação para mover dados entre a memória e MMX registra. Essa opção também desabilita a otimização de carga de registro para valores de ponto flutuante que pode ser carregado em vários caminhos de controle quando o valor pode causar uma exceção ao carregar — por exemplo, um valor de NaN.  
  
 Essa opção é substituída por [/fp: exceto](../../build/reference/fp-specify-floating-point-behavior.md). **/Qsafe_fp_loads** Especifica um subconjunto do comportamento do compilador que é especificado pelo **/fp: exceto**.  
  
 **/Qsafe_fp_loads** é incompatível com [/clr](../../build/reference/clr-common-language-runtime-compilation.md) e [Fast](../../build/reference/fp-specify-floating-point-behavior.md). Para obter mais informações sobre as opções de compilador de ponto flutuante, consulte [/fp (Especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)