---
title: Estrutura de uma biblioteca | Microsoft Docs
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
- libraries, structure
ms.assetid: a5fda8e8-4a1b-4499-9095-0df935262ce4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1630636b0de552712f67bc43b5182f991b10ef0b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="structure-of-a-library"></a>Estrutura de uma biblioteca
Uma biblioteca contém objetos COFF. Os objetos em uma biblioteca contêm funções e os dados que podem ser referenciados externamente por outros objetos em um programa. Um objeto em uma biblioteca é chamado como um membro da biblioteca.  
  
 Você pode obter informações adicionais sobre o conteúdo de uma biblioteca, executando a ferramenta DUMPBIN com a opção /LINKERMEMBER. Para obter mais informações sobre essa opção, consulte [referência de DUMPBIN](../../build/reference/dumpbin-reference.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)