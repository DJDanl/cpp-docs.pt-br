---
title: Erro das Ferramentas de Vinculador LNK1106
ms.date: 11/04/2016
f1_keywords:
- LNK1106
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
ms.openlocfilehash: 091d4e173bfb2eff8ffee2b5c30647f4d5e3bc04
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80195364"
---
# <a name="linker-tools-error-lnk1106"></a>Erro das Ferramentas de Vinculador LNK1106

arquivo ou disco inválido cheio: não é possível buscar no local

A ferramenta não pôde ler ou gravar `location` em um arquivo mapeado para a memória.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Disco cheio.

   Libere espaço e vincule novamente.

1. Tentando vincular em uma rede.

   Algumas redes não dão suporte total aos arquivos mapeados por memória usados pelo vinculador. Tente vincular em seu disco local.

1. Bloco inadequado em seu disco.

   Embora o sistema operacional e o hardware do disco tenham detectado um erro desse tipo, talvez você queira executar um programa de verificação de disco.

1. Sem espaço de heap.

   Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.
