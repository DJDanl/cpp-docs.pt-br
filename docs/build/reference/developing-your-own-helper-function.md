---
title: Desenvolvendo a função auxiliar própria
ms.date: 11/04/2016
helpviewer_keywords:
- helper functions
ms.assetid: a845429d-68b1-4e14-aa88-f3f5343bd490
ms.openlocfilehash: 73b4a8180345dd6f7dc26f4243f6e63eda80e4af
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820125"
---
# <a name="developing-your-own-helper-function"></a>Desenvolvendo a função auxiliar própria

Você talvez queira fornecer sua própria versão da rotina para fazer processamento específico com base nos nomes da DLL ou importações. Há duas maneiras de fazer isso: codificação de sua preferência, possivelmente com base no código fornecido, ou simplesmente vinculando a versão fornecida usando os ganchos de notificação detalhados anteriormente.

## <a name="code-your-own"></a>Codificar sua própria

Isso é bastante simple, pois, essencialmente, você pode usar o código fornecido como uma diretriz para a nova. Obviamente, ele deve seguir as convenções de chamada e se ela retornar para as conversões geradas pelo vinculador, ele deve retornar um ponteiro de função apropriada. Uma vez em seu código, você pode fazer praticamente tudo o que você deseja para satisfazer a chamada ou tirar proveito da chamada.

## <a name="use-the-start-processing-notification-hook"></a>Usar o início de gancho de notificação de processamento

Provavelmente será mais fácil simplesmente fornecer um ponteiro para uma função de gancho de notificação fornecido pelo usuário que recebe os mesmos valores que o auxiliar de padrão em dliStartProcessing a notificação. Nesse ponto, a função de gancho pode essencialmente se tornar a nova função de auxiliar, como um retorno bem-sucedido para o auxiliar padrão vai ignorar tudo ainda mais processamento no auxiliar de padrão.

## <a name="see-also"></a>Consulte também

[Suporte do vinculador para DLLs carregadas com atraso](linker-support-for-delay-loaded-dlls.md)
