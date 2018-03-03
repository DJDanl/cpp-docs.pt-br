---
title: -TLS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /TLS
dev_langs:
- C++
helpviewer_keywords:
- /TLS dumpbin option
- -TLS dumpbin option
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5adf246e343a16abebdc584589e9633b195444ea
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tls"></a>/TLS
Exibe a estrutura IMAGE_TLS_DIRECTORY de um executável.  
  
## <a name="remarks"></a>Comentários  
 / O TLS exibe os campos da estrutura de TLS, bem como os endereços das funções de retorno de chamada de TLS.  
  
 Se um programa não usar o armazenamento local de thread, sua imagem não conterá uma estrutura TLS.  Consulte [thread](../../cpp/thread.md) para obter mais informações.  
  
 IMAGE_TLS_DIRECTORY é definido em Winnt. h.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)