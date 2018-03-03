---
title: -RAWDATA | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /rawdata
dev_langs:
- C++
helpviewer_keywords:
- RAWDATA dumpbin option
- raw data
- -RAWDATA dumpbin option
- /RAWDATA dumpbin option
ms.assetid: 41cba845-5e1f-415e-9fe4-604a52235983
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 475ec5a827a1453a6f9474762d5be41299fc87e4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rawdata"></a>/RAWDATA
```  
/RAWDATA[:{1|2|4|8|NONE[,number]]  
```  
  
## <a name="remarks"></a>Comentários  
 Esta opção exibe o conteúdo bruto de cada seção no arquivo. Os argumentos de controlam o formato de exibição, conforme mostrado abaixo:  
  
|Argumento|Resultado|  
|--------------|------------|  
|1|O padrão. Conteúdo é exibido em bytes hexadecimais e também como caracteres ASCII se eles têm uma representação impressa.|  
|2|Conteúdo é exibido como valores hexadecimais de 2 bytes.|  
|4|Conteúdo é exibido como valores hexadecimais de 4 bytes.|  
|8|Conteúdo é exibido como valores hexadecimais de 8 bytes.|  
|NENHUM|Dados brutos são suprimidos. Esse argumento é útil para controlar a saída de/ALL.|  
|*Número*|Linhas exibidas são definidas para uma largura que contém `number` valores por linha.|  
  
 Somente o [/HEADERS](../../build/reference/headers.md) opção DUMPBIN está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)