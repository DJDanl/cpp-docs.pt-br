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
ms.openlocfilehash: 9a136caf3a1d22151cb9cfd48e1cd3f999ab51ec
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370497"
---
# <a name="handlers-for-standard-windows-messages"></a>Manipuladores para mensagens do Windows padrão

Os manipuladores padrão para mensagens padrão do `CWnd`Windows **(WM_)** são predefinidos na classe . A biblioteca de classe baseia nomes desses manipuladores no nome da mensagem. Por exemplo, o **WM_PAINT** manipulador da mensagem `CWnd` WM_PAINT é declarado como:

`afx_msg void OnPaint();`

A **palavra-chave afx_msg** sugere o efeito da palavra-chave **virtual** C++ distinguindo os manipuladores de outras `CWnd` funções de membro. Observe, no entanto, que essas funções não são realmente virtuais; em vez disso, são implementados através de mapas de mensagens. Os mapas de mensagens dependem apenas de macros padrão de pré-processador, não de quaisquer extensões para o idioma C++. A **palavra-chave afx_msg** resolve para o espaço branco após o pré-processamento.

Para substituir um manipulador definido em uma classe base, basta definir uma função com o mesmo protótipo em sua classe derivada e fazer uma entrada de mapa de mensagem para o manipulador. Seu manipulador "substitui" qualquer manipulador com o mesmo nome em qualquer uma das classes de base da sua classe.

Em alguns casos, o manipulador deve chamar o manipulador substituído na classe base para que as classes base(es) e o Windows possam operar na mensagem. Onde você chama o manipulador da classe base em sua substituição depende das circunstâncias. Às vezes você deve chamar o manipulador de classe base primeiro e às vezes durar. Às vezes, você chama o manipulador de classe base condicionalmente, se você optar por não lidar com a mensagem você mesmo. Às vezes, você deve chamar o manipulador de classe base e, em seguida, executar condicionalmente o seu próprio código de manipulador, dependendo do valor ou estado retornado pelo manipulador de classe base.

> [!CAUTION]
> Não é seguro modificar os argumentos passados para um manipulador se você pretende passá-los para um manipulador de classe base. Por exemplo, você pode ser tentado a modificar `OnChar` o argumento *nChar* do manipulador (para converter em maiúsculas, por exemplo). Esse comportamento é bastante obscuro, mas se você precisar `CWnd` realizar `SendMessage` esse efeito, use a função do membro em vez disso.

Como você determina a maneira adequada de substituir uma determinada mensagem Quando o [Assistente](reference/mfc-class-wizard.md) de `OnCreate` Classe escreve o esqueleto da função do manipulador para uma determinada mensagem — um manipulador para **WM_CREATE**, por exemplo — ele esboça na forma da função de membro substituído recomendada. O exemplo a seguir recomenda que o manipulador primeiro ligue para o manipulador da classe base e proceda apenas com a condição de que ele não retorne -1.

[!code-cpp[NVC_MFCMessageHandling#3](../mfc/codesnippet/cpp/handlers-for-standard-windows-messages_1.cpp)]

Por convenção, os nomes desses manipuladores começam com o prefixo "On". Alguns desses manipuladores não aceitam argumentos, enquanto outros tomam vários. Alguns também têm um tipo de retorno diferente do **vazio**. Os manipuladores padrão de todas as mensagens **WM_** estão documentados `CWnd` no *MFC Reference* como funções de membro da classe cujos nomes começam com "On". As declarações de `CWnd` função do membro são prefixadas com **afx_msg**.

## <a name="see-also"></a>Confira também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
