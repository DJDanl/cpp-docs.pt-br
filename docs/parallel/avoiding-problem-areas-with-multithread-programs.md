---
title: Evitando áreas de problema com programas Multithread | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- multithreading [C++], troubleshooting
- errors [C++], multithreaded programs
- threading [C++], troubleshooting
- troubleshooting [C++], multithreading
ms.assetid: 06cc231d-bb5a-409d-8bd3-676c9e2a8c5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5af4c1ca6a86b2cff457aee12e8337103ce7f42d
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686608"
---
# <a name="avoiding-problem-areas-with-multithread-programs"></a>Evitando áreas de problema com programas multithread
Há vários problemas que podem ocorrer ao criar, vincular ou executar um programa C multithread. Alguns dos problemas mais comuns são descritos na tabela a seguir. (Para obter uma discussão semelhante do ponto de vista do MFC, consulte [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md).)  
  
|Problema|Causa provável|  
|-------------|--------------------|  
|Você verá uma caixa de mensagem mostrando que seu programa causou uma violação de proteção.|Muitos erros de programação do Win32 causam violações de proteção. Uma causa comum de violações de proteção é a atribuição indireta de dados em ponteiros nulos. Porque isso resulta em seu programa tentar acessar a memória que não pertence a ele, uma violação de proteção é emitida.<br /><br /> É uma maneira fácil para detectar a causa de uma violação de proteção compilar seu programa com as informações de depuração e, em seguida, executá-lo por meio do depurador no ambiente do Visual C++. Quando ocorre a falha de proteção, o Windows transfere o controle para o depurador e o cursor é posicionado na linha que causou o problema.|  
|O programa gera diversos erros de compilação e de link.|Você pode eliminar muitos problemas potenciais, definindo o nível de aviso do compilador para um de seus valores mais altos e prestando atenção em mensagens de aviso. Usando as opções de nível de aviso de nível 4 ou nível 3, você pode detectar o uso de recursos de não-ANSI, protótipos de função ausente e conversões de dados não intencionais.|  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)