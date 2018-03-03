---
title: STUB | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- STUB
dev_langs:
- C++
helpviewer_keywords:
- STUB .def file statement
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 58430f8211f8859b65103b53d1f98a173c4635ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="stub"></a>STUB
Quando usado em um arquivo de definição de módulo que cria um driver de dispositivo virtual (VxD), permite que você especifique um nome de arquivo que contém uma estrutura IMAGE_DOS_HEADER (definida em WINNT. H) a ser usado no driver de dispositivo virtual (VxD), em vez do cabeçalho padrão.  
  
```  
STUB:filename  
```  
  
## <a name="remarks"></a>Comentários  
 Uma maneira equivalente para especificar *filename* é com o [/STUB](../../build/reference/stub-ms-dos-stub-file-name.md) opção de vinculador.  
  
 STUB é válido em um arquivo de definição de módulo somente ao compilar um VxD.  
  
## <a name="see-also"></a>Consulte também  
 [Regras para instruções de definição do módulo](../../build/reference/rules-for-module-definition-statements.md)