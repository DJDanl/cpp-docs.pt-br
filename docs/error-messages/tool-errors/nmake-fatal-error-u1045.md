---
title: Erro fatal U1045 (NMAKE)
ms.date: 08/11/2019
f1_keywords:
- U1045
helpviewer_keywords:
- U1045
ms.assetid: dc70d162-14b9-4107-9237-7514044d72e3
ms.openlocfilehash: bdc28bcf02aea791a346a0a74915707fef551b8b
ms.sourcegitcommit: db1ed91fa7451ade91c3fb76bc7a2b857f8a5eef
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2019
ms.locfileid: "68980538"
---
# <a name="nmake-fatal-error-u1045"></a>Erro fatal U1045 (NMAKE)

> falha na geração: *mensagem*

Um programa ou comando chamado por NMAKE falhou por motivo na *mensagem*. Quando o NMAKE chama outro programa, por exemplo, o compilador ou vinculador, a chamada pode falhar. Ou, um erro pode ser retornado pelo programa chamado. Essa mensagem é usada para relatar o erro.

Para corrigir esse problema, primeiro determine a causa do erro. Você pode usar os comandos relatados pela opção NMAKE [/n](../../build/reference/running-nmake.md#nmake-options) para verificar as configurações de ambiente e repetir as ações feitas pelo NMAKE na linha de comando.
