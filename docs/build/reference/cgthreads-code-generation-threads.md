---
title: "-cgthreads (Threads de geração de código) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /cgthreads
dev_langs: C++
helpviewer_keywords:
- /cgthreads compiler option (C++)
- -cgthreads compiler option (C++)
- cgthreads compiler option (C++)
- cgthreads
ms.assetid: 64bc768c-6caa-4baf-9dea-7cfa1ffb01c2
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 846e59b0c1303e70e4ed38b43e4869f1f044f64f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cgthreads-code-generation-threads"></a>/cgthreads (threads geradoras de código)
Define o número de threads cl.exe usados para otimização e geração de código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/cgthreads[1-8]  
```  
  
## <a name="arguments"></a>Arguments  
 número  
 O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.  
  
## <a name="remarks"></a>Comentários  
 O **/cgthreads** opção especifica o número máximo de threads cl.exe usa em paralelo para a otimização e código de fases de geração de compilação. Observe que não pode haver nenhum espaço entre **/cgthreads** e `number` argumento. Por padrão, cl.exe usa quatro threads, como se **/cgthreads4** foram especificadas. Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação. Essa opção é especialmente útil quando ele é combinado com [/GL (otimização de programa total)](../../build/reference/gl-whole-program-optimization.md).  
  
 É possível especificar diversos níveis de paralelismo para uma compilação. A opção msbuild.exe **/maxcpucount** Especifica o número de processos do MSBuild que podem ser executados em paralelo. O [/MP (compilar com vários processos)](../../build/reference/mp-build-with-multiple-processes.md) sinalizador do compilador Especifica o número de processos cl.exe simultaneamente compilar os arquivos de origem. O **/cgthreads** opção especifica o número de threads usados por cada processo cl.exe. Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente. Para obter mais informações sobre como criar projetos em paralelo, consulte [criando vários projetos paralelamente](/visualstudio/msbuild/building-multiple-projects-in-parallel-with-msbuild).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **propriedades de configuração**, **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir **/cgthreads**`N`, onde `N` é um valor de 1 a 8 e, em seguida, selecione **Okey**.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)