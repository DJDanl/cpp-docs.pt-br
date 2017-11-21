---
title: "Definindo opções do compilador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- compiler options, setting
- cl.exe compiler, setting options
ms.assetid: 4b079f5b-0017-4124-aad6-0d2b58e427e0
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1148ddf14fba64763b3eb272173f226f35991a32
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="setting-compiler-options"></a>Definindo opções do compilador
As opções de compilador C e C++ podem ser definidas no ambiente de desenvolvimento ou na linha de comando.  
  
## <a name="in-the-development-environment"></a>No ambiente de desenvolvimento  
 Você pode definir opções do compilador para cada projeto na sua **páginas de propriedade** caixa de diálogo. No painel esquerdo, selecione **propriedades de configuração**, **C/C++** e, em seguida, escolha a categoria de opção de compilador. O tópico para cada opção de compilador descreve como ela pode ser definida e onde ela se encontra no ambiente de desenvolvimento. Consulte [opções do compilador](../../build/reference/compiler-options.md) para obter uma lista completa.  
  
## <a name="outside-the-development-environment"></a>Fora do ambiente de desenvolvimento  
 Você pode definir opções de compilador (CL.exe):  
  
-   [Na linha de comando](../../build/reference/compiler-command-line-syntax.md)  
  
-   [Nos arquivos de comando](../../build/reference/cl-command-files.md)  
  
-   [Na variável de ambiente CL](../../build/reference/cl-environment-variables.md)  
  
 As opções especificadas na variável de ambiente CL são usadas cada vez que você invoca o CL. Se um arquivo de comando é nomeado na variável de ambiente CL ou na linha de comando, as opções especificadas no arquivo de comando são usadas. Em vez da linha de comando ou da variável de ambiente CL, um arquivo de comando permite que você use várias linhas de opções e nomes de arquivo.  
  
 As opções de compilador são processadas “da esquerda para a direita” e, quando um conflito é detectado, a última opção (na extrema direita) vence. A variável de ambiente CL é processada antes da linha de comando. Então, nos conflitos entre o CL e a linha de comando, a linha de comando terá precedência.  
  
## <a name="additional-compiler-topics"></a>Tópicos adicionais de compilador  
  
-   [Compilação rápida](../../build/reference/fast-compilation.md)  
  
-   [CL invoca o vinculador](../../build/reference/cl-invokes-the-linker.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Opções do Compilador](../../build/reference/compiler-options.md)