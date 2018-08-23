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
ms.openlocfilehash: 49c5e624b437f39270fb880fe526d55e7ed83e5d
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42539931"
---
# <a name="avoiding-problem-areas-with-multithread-programs"></a>Evitando áreas de problema com programas multithread
Há vários problemas que podem ser encontradas em criar, vincular ou executar um programa C multithread. Alguns dos problemas mais comuns são descritos na tabela a seguir. (Para obter uma discussão semelhante do ponto de vista do MFC, consulte [Multithreading: dicas de programação](../parallel/multithreading-programming-tips.md).)  
  
|Problema|Causa provável|  
|-------------|--------------------|  
|Você verá uma caixa de mensagem mostrando que o seu programa causou uma violação de proteção.|Muitos erros de programação do Win32 causam violações de proteção. Uma causa comum de violações de proteção é a atribuição indireta de dados para ponteiros nulos. Porque isso resulta em seu programa tentar acessar a memória que não pertence a ele, uma violação de proteção é emitida.<br /><br /> Uma maneira fácil para detectar a causa de uma violação de proteção é compilar seu programa com informações de depuração e, em seguida, executá-lo por meio do depurador no ambiente do Visual C++. Quando ocorre a falha de proteção, o Windows transfere o controle para o depurador e o cursor é posicionado na linha que causou o problema.|  
|O programa gera muitos erros de compilação e link.|Você pode eliminar muitos problemas potenciais, definindo o nível de aviso do compilador para um dos seus valores mais altos e prestando atenção em mensagens de aviso. Ao usar o nível 3 ou opções de nível de aviso de nível 4, você pode detectar as conversões de dados não intencional, os protótipos de função ausente e uso de recursos de não-ANSI.|  
  
## <a name="see-also"></a>Consulte também  

[Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)