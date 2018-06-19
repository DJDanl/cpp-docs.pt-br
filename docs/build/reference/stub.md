---
title: STUB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- STUB
dev_langs:
- C++
helpviewer_keywords:
- STUB .def file statement
ms.assetid: 0a3b9643-19ed-47e9-8173-ee16bc8ed056
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 385e073f877a938a3b73fa79036d27cf50c1e4ec
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32375195"
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