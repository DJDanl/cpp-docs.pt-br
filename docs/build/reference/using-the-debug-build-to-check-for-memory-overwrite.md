---
title: Usando a compilação de depuração para verificação de substituição de memória | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- memory, overwrites
ms.assetid: 1345eb4d-24ba-4595-b1cc-2da66986311e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c89242a63484eaccd0330eddac28c4e543ec61b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="using-the-debug-build-to-check-for-memory-overwrite"></a>Usando o build de depuração para verificar a substituição de memória
Para usar a compilação de depuração para verificar a substituição de memória, primeiro você deve recompilar o projeto para depuração. Em seguida, vá para o início do seu aplicativo `InitInstance` de função e adicione a seguinte linha:  
  
```  
afxMemDF |= checkAlwaysMemDF;  
```  
  
 O alocador de memória de depuração coloca bytes de proteção ao redor de todas as alocações de memória. No entanto, esses proteger bytes não faça nada, a menos que você verifique se eles foram alterados (o que poderia indicar uma substituição de memória). Caso contrário, isso apenas fornece um buffer que pode, na verdade, permitem que você tenha imediatamente com uma substituição de memória.  
  
 Ativando o `checkAlwaysMemDF`, forçará MFC para fazer uma chamada para o `AfxCheckMemory` funcionar sempre que uma chamada para **novo** ou **excluir** é feita. Se uma substituição de memória foi detectada, ele irá gerar uma mensagem de rastreamento é semelhante ao seguinte:  
  
```  
Damage Occurred! Block=0x5533  
```  
  
 Se você vir uma dessas mensagens, você precisa depurar seu código para determinar onde ocorreu o dano. Para isolar mais precisamente onde ocorreu a substituição de memória, você pode fazer chamadas explícitas a `AfxCheckMemory` por conta própria. Por exemplo:  
  
```  
ASSERT(AfxCheckMemory());  
    DoABunchOfStuff();  
    ASSERT(AfxCheckMemory());  
```  
  
 Se a primeira declaração for bem-sucedida e o outro falha, isso significa que a substituição de memória deve ter ocorreu na função entre as duas chamadas.  
  
 Dependendo da natureza de seu aplicativo, você pode descobrir que `afxMemDF` faz com que o programa seja executado muito lentamente para testar o mesmo. O `afxMemDF` variável faz `AfxCheckMemory` para ser chamado para cada chamada para novas e excluir. Nesse caso, você deve dispersão seus próprios chamadas para `AfxCheckMemory`(), como mostrado acima e tente isolar a memória substituir dessa maneira.  
  
## <a name="see-also"></a>Consulte também  
 [Corrigindo problemas do build de versão](../../build/reference/fixing-release-build-problems.md)