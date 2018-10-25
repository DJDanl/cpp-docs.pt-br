---
title: Erro das LNK1106 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1106
dev_langs:
- C++
helpviewer_keywords:
- LNK1106
ms.assetid: 528f7e65-04be-4966-b8af-9276837c7cda
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ce6a8b2ef9ac807e48cff42186453666cebda5ee
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055978"
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