---
title: Erro das Ferramentas de Vinculador LNK1106
ms.date: 11/04/2016
f1_keywords:
- LNK1106
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
ms.openlocfilehash: 7551e2f3f1efc90913981feb674f48aadb9ace51
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62255313"
---
# <a name="linker-tools-error-lnk1106"></a>Erro das Ferramentas de Vinculador LNK1106

arquivo inválido ou disco cheio: não é possível buscar para local

A ferramenta não foi possível ler ou gravar em `location` em um arquivo mapeado em memória.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Disco cheio.

   Libere espaço e vinculá-lo novamente.

1. Tentando vincular uma rede.

   Algumas redes não suportam totalmente os arquivos mapeados na memória usados pelo vinculador. Tente vincular em seu disco local.

1. Bloco inválido no disco.

   Embora o sistema operacional e hardware de disco devem ter detectado esse erro, você talvez queira executar um programa de verificação de disco.

1. Sem espaço de heap.

   Ver [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.