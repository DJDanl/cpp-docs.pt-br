---
title: -Qpar (Paralelizador automático) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.EnableParallelCodeGeneration
dev_langs:
- C++
ms.assetid: 33ecf49d-c0d5-4f34-bce3-84ff03f38918
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 430bf1ebc79008d97435ecbcb3b15cf19dda5f8d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
 [Programação paralela em código nativo](http://go.microsoft.com/fwlink/p/?linkid=263662)