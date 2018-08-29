---
title: Incluir arquivos para Multithreading | Microsoft Docs
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
ms.openlocfilehash: ec531c2c0eeac14a617a3e0e3b450cf467808165
ms.sourcegitcommit: f7703076b850c717c33d72fb0755fbb2215c5ddc
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/28/2018
ms.locfileid: "43130762"
---
# <a name="include-files-for-multithreading"></a>Incluir arquivos para multithread
Arquivos de inclusão padrão declarar funções de biblioteca de tempo de execução C como são implementadas nas bibliotecas. Se você usar o [otimização completa](../build/reference/ox-full-optimization.md) (/ Ox) ou [fastcall convenção de chamada](../build/reference/gd-gr-gv-gz-calling-convention.md) (/ Gr) opção, o compilador pressupõe que todas as funções devem ser chamadas usando o convenção de chamada de registro. As funções de biblioteca de tempo de execução foram compiladas usando a convenção de chamada do C e as declarações nos arquivos de inclusão padrão dizer ao compilador para gerar referências externas corretas para essas funções.  
  
## <a name="see-also"></a>Consulte também  

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)