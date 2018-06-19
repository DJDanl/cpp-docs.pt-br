---
title: Incluir arquivos para multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- threading [C++], include files
- include files, multithreading
- multithreading [C++], include files
ms.assetid: 98d764f9-71f4-4da5-8f3a-8d2d26e96799
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 62b94f4a7a394b78cb7c6f23275709e4aeacc774
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33685795"
---
# <a name="include-files-for-multithreading"></a>Incluir arquivos para multithread
Arquivos de inclusão padrão declarar funções da biblioteca de tempo de execução C como eles são implementados nas bibliotecas. Se você usar o [otimização total](../build/reference/ox-full-optimization.md) (/ Ox) ou [fastcall convenção de chamada](../build/reference/gd-gr-gv-gz-calling-convention.md) (/ Gr) opção, o compilador assumirá que todas as funções devem ser chamadas usando o registro de convenção de chamada. As funções de biblioteca de tempo de execução foram compiladas usando a convenção de chamada de C, e as declarações nos arquivos de inclusão padrão diz ao compilador para gerar referências externas corretas para essas funções.  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)