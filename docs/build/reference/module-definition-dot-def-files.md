---
title: "Definição de módulo (. Arquivos def) | Microsoft Docs"
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
- def files
- module definition files
- .def files
ms.assetid: 08c0bc28-c5d2-47aa-9624-7fc68bcaa4d8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 49f5eb5b75bad22b59cb4fbb98554bbfd44d13b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="module-definition-def-files"></a>Arquivos de definição do módulo (.Def)
Arquivos de definição de módulo (. def) fornecem o vinculador com informações sobre exportações, atributos e outras informações sobre o programa a ser vinculado. Um arquivo. def é mais útil ao criar uma DLL. Porque há [opções do vinculador](../../build/reference/linker-options.md) que pode ser usado em vez de instruções de definição de módulo, arquivos. def geralmente não são necessários. Você também pode usar [dllexport](../../build/exporting-from-a-dll-using-declspec-dllexport.md) como uma maneira de especificar as funções exportadas.  
  
 Você pode chamar um arquivo. def durante a fase de vinculador com o [/DEF (especificar arquivo de definição de módulo)](../../build/reference/def-specify-module-definition-file.md) opção de vinculador.  
  
 Se você estiver criando um arquivo .exe com nenhuma exportação, o uso de um arquivo. def tornará seu carregamento maior e mais lento do arquivo de saída.  
  
 Para obter um exemplo, consulte [exportando a partir de uma DLL usando arquivos de definição](../../build/exporting-from-a-dll-using-def-files.md).  
  
 Consulte as seções a seguir para obter mais informações:  
  
-   [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)  
  
-   [EXPORTS](../../build/reference/exports.md)  
  
-   [HEAPSIZE](../../build/reference/heapsize.md)  
  
-   [LIBRARY](../../build/reference/library.md)  
  
-   [NOME](../../build/reference/name-c-cpp.md)  
  
-   [SEÇÕES](../../build/reference/sections-c-cpp.md)  
  
-   [STACKSIZE](../../build/reference/stacksize.md)  
  
-   [STUB](../../build/reference/stub.md)  
  
-   [VERSÃO](../../build/reference/version-c-cpp.md)  
  
-   [Palavras reservadas](../../build/reference/reserved-words.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)  