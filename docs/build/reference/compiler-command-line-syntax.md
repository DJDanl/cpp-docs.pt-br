---
title: Sintaxe de linha de comando do compilador | Microsoft Docs
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
- syntax, CL compiler command line
- cl.exe compiler, command-line syntax
ms.assetid: acba2c1c-0803-4a3a-af25-63e849b930a2
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7fb89aca1990d44d7ef62ea76788b38e8ffa1d6d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-command-line-syntax"></a>Sintaxe da linha de comando do compilador
A linha de comando CL usa a seguinte sintaxe:  
  
```  
CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]  
```  
  
 A tabela a seguir descreve a entrada para o comando CL.  
  
|Entrada|Significado|  
|-----------|-------------|  
|*opção*|Um ou mais [opções CL](../../build/reference/compiler-options.md). Observe que todas as opções se aplicam a todos os arquivos de origem especificado. Opções são especificadas por uma barra invertida (/) ou um traço (-). Se uma opção tem um argumento, documentos de descrição da opção se um espaço é permitido entre a opção e os argumentos. Os nomes de opções (exceto para a opção /HELP) diferenciam maiusculas de minúsculas. Consulte [ordem de opções CL](../../build/reference/order-of-cl-options.md) para obter mais informações.|  
|`file`|O nome de um ou mais arquivos de origem, arquivos. obj ou bibliotecas. CL compila arquivos de origem e passa os nomes dos arquivos. obj e bibliotecas para o vinculador. Consulte [sintaxe de nome de arquivo CL](../../build/reference/cl-filename-syntax.md) para obter mais informações.|  
|*lib*|Um ou mais nomes de biblioteca. CL passa esses nomes para o vinculador.|  
|*arquivo de comando*|Um arquivo que contém várias opções e os nomes de arquivos. Consulte [arquivos de comando CL](../../build/reference/cl-command-files.md) para obter mais informações.|  
|*Escolha o link*|Um ou mais [opções do vinculador](../../build/reference/linker-options.md). CL passa essas opções para o vinculador.|  
  
 Você pode especificar qualquer número de opções, nomes de arquivo e nomes de biblioteca, como o número de caracteres na linha de comando não exceder 1024, o limite determinado pelo sistema operacional.  
  
 Para obter informações sobre o valor de retorno de cl.exe, consulte [o valor de retorno de cl.exe](../../build/reference/return-value-of-cl-exe.md) .  
  
> [!NOTE]
>  Não há garantia de que o limite de entrada de linha de comando de 1024 caracteres permanecem os mesmos em versões futuras do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)   
 [Opções do Compilador](../../build/reference/compiler-options.md)