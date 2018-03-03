---
title: -CGTHREADS (compilador de Threads) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- /CGTHREADS linker option
- -CGTHREADS linker option
- CGTHREADS linker option
ms.assetid: 4b52cfdb-3702-470b-9580-fabeb1417488
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 542e35ecbb5e56ae0d13861b9885936f3b47c9da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cgthreads-compiler-threads"></a>/CGTHREADS (threads compiladoras)
Defina quantos threads cl.exe devem ser usados na otimização e na geração de códigos quando a geração de código vínculo-tempo for especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/CGTHREADS:[1-8]  
```  
  
## <a name="arguments"></a>Arguments  
 número  
 O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.  
  
## <a name="remarks"></a>Comentários  
 O **/CGTHREADS** opção especifica o número máximo de threads cl.exe usa em paralelo para as fases de geração de código e de otimização da compilação ao tempo de vinculação de geração de código ([/LTCG](../../build/reference/ltcg-link-time-code-generation.md)) é especificado. Por padrão, cl.exe usa quatro threads, como se **/CGTHREADS:4** foram especificadas. Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação.  
  
 É possível especificar diversos níveis de paralelismo para uma compilação. A opção msbuild.exe **/maxcpucount** Especifica o número de processos do MSBuild que podem ser executados em paralelo. O [/MP (compilar com vários processos)](../../build/reference/mp-build-with-multiple-processes.md) sinalizador do compilador Especifica o número de processos cl.exe simultaneamente compilar os arquivos de origem. O [/cgthreads](../../build/reference/cgthreads-code-generation-threads.md) opção de compilador Especifica o número de threads usados por cada processo cl.exe. Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente. Para obter mais informações sobre como criar projetos em paralelo, consulte [criando vários projetos paralelamente](/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **propriedades de configuração**, **vinculador** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir **/CGTHREADS:**`number`, onde `number` é um valor de 1 a 8 e, em seguida, escolha **Okey**.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)