---
title: 'Hora atual: Classes de uso geral'
ms.date: 11/04/2016
helpviewer_keywords:
- time, setting current
- current time, CTime object
- procedures, getting current time
- initializing objects, with the current time
- time, getting current
ms.assetid: c39e6775-6a92-4b27-95a7-5c86ed371d8a
ms.openlocfilehash: e883a47243feb7ad1555748ffdda9b8ae9594644
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539250"
---
# <a name="current-time-general-purpose-classes"></a>Hora atual: Classes de uso geral

O procedimento a seguir mostra como criar um `CTime` do objeto e inicializá-lo com a hora atual.

### <a name="to-get-the-current-time"></a>Para obter a hora atual

1. Alocar um `CTime` do objeto, da seguinte maneira:

   [!code-cpp[NVC_ATLMFC_Utilities#171](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_1.cpp)]

   > [!NOTE]
   > Não inicializado `CTime` objetos não são inicializados em uma hora válida.

1. Chamar o `CTime::GetCurrentTime` função para obter a hora atual do sistema operacional. Essa função retorna um `CTime` objeto que pode ser usado para definir o valor de `CTime`, da seguinte maneira:

   [!code-cpp[NVC_ATLMFC_Utilities#172](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_2.cpp)]

   Uma vez que `GetCurrentTime` é uma função de membro estático do `CTime` classe, você deve qualificar seu nome com o nome da classe e o operador de resolução de escopo (`::`), `CTime::GetCurrentTime()`.

Obviamente, as duas etapas descritas anteriormente podem ser combinadas em uma única instrução do programa da seguinte maneira:

[!code-cpp[NVC_ATLMFC_Utilities#173](../atl-mfc-shared/codesnippet/cpp/current-time-general-purpose-classes_3.cpp)]
