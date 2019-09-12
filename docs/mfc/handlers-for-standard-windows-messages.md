---
title: Manipuladores para mensagens do Windows padrão
ms.date: 11/04/2016
f1_keywords:
- afx_msg
helpviewer_keywords:
- Windows messages [MFC], handlers
- message handling [MFC], Windows message handlers
- handler functions, standard Windows messages
- functions [MFC], handler
- messages [MFC], Windows
ms.assetid: 19412a8b-2c38-4502-81da-13c823c7e36c
ms.openlocfilehash: 4f512c3b9a7fce5cddd582fa774742d2b1ac0967
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907435"
---
# <a name="handlers-for-standard-windows-messages"></a>Manipuladores para mensagens do Windows padrão

Os manipuladores padrão para**WM_** (mensagens padrão do Windows) são predefinidos na classe `CWnd`. A biblioteca de classes baseia os nomes para esses manipuladores no nome da mensagem. Por exemplo, o manipulador para a mensagem **WM_PAINT** é declarado em `CWnd` como:

`afx_msg void OnPaint();`

A palavra-chave **afx_msg** sugere o efeito C++ da palavra-chave **virtual** , diferenciando os manipuladores de outras `CWnd` funções de membro. No entanto, observe que essas funções não são realmente virtuais; em vez disso, eles são implementados por meio de mapas de mensagens. Os mapas de mensagens dependem exclusivamente das macros de pré-processador padrão, não de quaisquer extensões C++ para a linguagem. A palavra-chave **afx_msg** é resolvida para o espaço em branco após o pré-processamento.

Para substituir um manipulador definido em uma classe base, basta definir uma função com o mesmo protótipo em sua classe derivada e criar uma entrada de mapa de mensagem para o manipulador. Seu manipulador "substitui" qualquer manipulador de mesmo nome em qualquer uma das classes base de sua classe.

Em alguns casos, o manipulador deve chamar o manipulador substituído na classe base para que as classes base e o Windows possam operar na mensagem. Onde você chama o manipulador de classe base em sua substituição depende das circunstâncias. Às vezes, você deve chamar o manipulador de classe base primeiro e, às vezes, durar. Às vezes, você chama o manipulador de classe base condicionalmente, se optar por não manipular a mensagem por conta própria. Às vezes, você deve chamar o manipulador de classe base e, em seguida, executar condicionalmente seu próprio código de manipulador, dependendo do valor ou do estado retornado pelo manipulador de classe base.

> [!CAUTION]
>  Não é seguro modificar os argumentos passados para um manipulador se você pretende passá-los para um manipulador de classe base. Por exemplo, você pode estar tentado a modificar o argumento *nchar* do `OnChar` manipulador (para converter em maiúsculas, por exemplo). Esse comportamento é bastante obscuro, mas se você precisar realizar esse efeito, use a função `CWnd` `SendMessage` de membro em vez disso.

Como você determina a maneira apropriada de substituir uma determinada mensagem quando o [Assistente de classe](reference/mfc-class-wizard.md) grava o esqueleto da função do manipulador para uma determinada mensagem — um `OnCreate` manipulador para **WM_CREATE**, por exemplo, ele faz um esboço na forma do recomendado função de membro substituída. O exemplo a seguir recomenda que o manipulador chame primeiro o manipulador de classe base e continue somente na condição de que ele não retorna-1.

[!code-cpp[NVC_MFCMessageHandling#3](../mfc/codesnippet/cpp/handlers-for-standard-windows-messages_1.cpp)]

Por convenção, os nomes desses manipuladores começam com o prefixo "on". Alguns desses manipuladores não usam argumentos, enquanto outros levam vários. Alguns também têm um tipo de retorno diferente de **void**. Os manipuladores padrão para todas as mensagens **WM_** são documentados na *referência do MFC* como funções de `CWnd` membro de classe cujos nomes começam com "on". As declarações de função de `CWnd` membro no são prefixadas com **afx_msg**.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
