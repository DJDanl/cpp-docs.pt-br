---
title: "-Qpar (Paralelizador automático) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: VC.Project.VCCLCompilerTool.EnableParallelCodeGeneration
dev_langs: C++
ms.assetid: 33ecf49d-c0d5-4f34-bce3-84ff03f38918
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 82f33d178799f56465f0d1a9794dacad7c01c77a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="qpar-auto-parallelizer"></a>/Qpar (paralelizador automático)
Permite que o [Paralelizador automático](../../parallel/auto-parallelization-and-auto-vectorization.md) recurso do compilador automaticamente paralelizar loops em seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qpar  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o compilador automaticamente parallelizes loops em código, ela espalha computação em vários núcleos de processador. Um loop é paralelizado somente se o compilador determina que é permitido fazer isso e esse paralelização podem melhorar o desempenho.  
  
 O `#pragma loop()` diretivas estão disponíveis para ajudar o otimizador paralelizar loops específicos. Para obter mais informações, consulte [loop](../../preprocessor/loop.md).  
  
 Para obter informações sobre como habilitar as mensagens de saída para o paralelizador automático, consulte [/Qpar-report (nível de emissão de relatórios do Paralelizador automático)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md).  
  
### <a name="to-set-the-qpar-compiler-option-in-visual-studio"></a>Para definir a opção de compilador /Qpar no Visual Studio  
  
1.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**.  
  
2.  No **páginas de propriedade** caixa de diálogo **C/C++**, selecione **linha de comando**.  
  
3.  No **opções adicionais** , digite `/Qpar`.  
  
### <a name="to-set-the-qpar-compiler-option-programmatically"></a>Para definir a opção de compilador /Qpar programaticamente  
  
-   Use o exemplo de código em <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [/Qpar-Report (nível de Paralelizador automático relatórios)](../../build/reference/qpar-report-auto-parallelizer-reporting-level.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [#pragma loop()](../../preprocessor/loop.md)   
 [Programação paralela em código nativo](http://go.microsoft.com/fwlink/?LinkId=263662)