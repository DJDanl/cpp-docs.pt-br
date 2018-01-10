---
title: "Opções do compilador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- cl.exe compiler
- IPF Visual C++ compiler
- Itanium Visual C++ compiler
- compiler options, C++
- x64 Visual C++ compiler
ms.assetid: ed3376c8-bef4-4c9a-80e9-3b5da232644c
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c433abea04ff81c69fe1b73569ea7e043e6e81ac
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-options"></a>Opção de compilador
cl.exe é uma ferramenta que controla os compiladores do Microsoft C e C++ e o vinculador. cl.exe pode ser executado apenas em sistemas operacionais que dão suporte ao Microsoft Visual Studio.  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta apenas o [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] prompt de comando. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
 Os compiladores produzem arquivos de objeto (. obj) do formato de arquivo de objeto comum (COFF). O vinculador produz arquivos executáveis (.exe) ou bibliotecas de vínculo dinâmico (DLLs).  
  
 Observe que todas as opções de compilador diferenciam maiusculas de minúsculas.  
  
 Para compilar sem vinculação, use [/c](../../build/reference/c-compile-without-linking.md).  
  
## <a name="finding-an-option"></a>Localizando uma opção  
 Para localizar uma opção de compilador específica, consulte uma das listas a seguir:  
  
-   [Opções do Compilador Listadas em Ordem Alfabética](../../build/reference/compiler-options-listed-alphabetically.md)  
  
-   [Opções de Compilador Listadas por Categoria](../../build/reference/compiler-options-listed-by-category.md)  
  
## <a name="specifying-options"></a>Especificando opções  
 O tópico de cada opção de compilador discute como ele pode ser definido no ambiente de desenvolvimento. Para obter informações sobre como especificar opções fora do ambiente de desenvolvimento, consulte:  
  
-   [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)  
  
-   [Arquivos de comando de CL](../../build/reference/cl-command-files.md)  
  
-   [Variáveis de ambiente de CL](../../build/reference/cl-environment-variables.md)  
  
## <a name="related-build-tools"></a>Ferramentas de compilação relacionados  
 Use [NMAKE](../../build/nmake-reference.md) para criar o arquivo de saída.  
  
 Use [BSCMAKE](../../build/reference/bscmake-reference.md) para dar suporte a navegação de classe.  
  
 [Opções do vinculador](../../build/reference/linker-options.md) também afetam como o programa é criado.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Compilação rápida](../../build/reference/fast-compilation.md)   
 [CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)