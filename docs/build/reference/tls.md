---
title: -TLS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /TLS
dev_langs:
- C++
helpviewer_keywords:
- /TLS dumpbin option
- -TLS dumpbin option
ms.assetid: 2b3f48f9-cac4-4351-b15c-2833b43bc709
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b5e510f406ceae7508f9b84f99e7ab397d22f114
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="tls"></a>/TLS
Exibe a estrutura IMAGE_TLS_DIRECTORY de um executável.  
  
## <a name="remarks"></a>Comentários  
 / O TLS exibe os campos da estrutura de TLS, bem como os endereços das funções de retorno de chamada de TLS.  
  
 Se um programa não usar o armazenamento local de thread, sua imagem não conterá uma estrutura TLS.  Consulte [thread](../../cpp/thread.md) para obter mais informações.  
  
 IMAGE_TLS_DIRECTORY é definido em Winnt. h.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de DUMPBIN](../../build/reference/dumpbin-options.md)