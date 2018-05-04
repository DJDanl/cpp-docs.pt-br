---
title: Especificando um arquivo embutido | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, inline files
- inline files [C++], specifying NMAKE
- files [C++], inline
ms.assetid: 393eccfb-3fc9-4bac-a30c-8ac8d221cca3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2c0d85436aef5ed48c0a8787f8bce330bf6d3e96
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="specifying-an-inline-file"></a>Especificando um arquivo embutido
Especificar dois colchetes angulares (<<) no comando onde *filename* deve aparecer. Os colchetes não pode ser uma expansão de macro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
<<[filename]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o comando é executado, os colchetes são substituídos por *filename*, se especificado, ou por um nome exclusivo gerado NMAKE. Se especificado, *filename* devem seguir colchetes sem um espaço ou tabulação. Um caminho é permitido. Nenhuma extensão é necessário ou assumido. Se *filename* for especificado, o arquivo é criado no atual ou o diretório especificado, substituindo qualquer arquivo com esse nome; caso contrário, ele é criado no diretório TMP (ou o diretório atual, se a variável de ambiente TMP não é definido). Se um anterior *filename* é reutilizado, NMAKE substituirá o arquivo anterior.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)