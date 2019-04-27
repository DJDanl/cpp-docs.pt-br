---
title: Aviso A4012 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A4012
helpviewer_keywords:
- A4012
ms.assetid: 842b1259-9679-4eeb-a02d-672a583a94e5
ms.openlocfilehash: f58d1f420d4acc848eaf04f93c01205dd1205468
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62201334"
---
# <a name="ml-warning-a4012"></a>Aviso A4012 (ML)

**informações de número de linha para o segmento sem classe 'CODE'**

Havia instruções em um segmento que não tem um nome de classe que termina com "Código". O assembler não gerou informações do CodeView para essas instruções.

CodeView não é possível processar os módulos com o código em segmentos com nomes de classe que não terminam com "Código".

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>