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
ms.openlocfilehash: 190acd619224bdf22a5c8d35f541fa48b6664fe1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625753"
---
# <a name="handlers-for-standard-windows-messages"></a>Manipuladores para mensagens do Windows padrão

Os manipuladores padrão para mensagens padrão do Windows (**WM_**) são predefinidos na classe `CWnd` . A biblioteca de classes baseia os nomes para esses manipuladores no nome da mensagem. Por exemplo, o manipulador para a mensagem de **WM_PAINT** é declarado em `CWnd` como:

`afx_msg void OnPaint();`

A palavra-chave **afx_msg** sugere o efeito da palavra-chave **virtual** C++, diferenciando os manipuladores de outras `CWnd` funções de membro. No entanto, observe que essas funções não são realmente virtuais; em vez disso, eles são implementados por meio de mapas de mensagens. Os mapas de mensagens dependem exclusivamente das macros de pré-processador padrão, não de nenhuma extensão para a linguagem C++. A palavra-chave **afx_msg** é resolvida para o espaço em branco após o pré-processamento.

Para substituir um manipulador definido em uma classe base, basta definir uma função com o mesmo protótipo em sua classe derivada e criar uma entrada de mapa de mensagem para o manipulador. Seu manipulador "substitui" qualquer manipulador de mesmo nome em qualquer uma das classes base de sua classe.

Em alguns casos, o manipulador deve chamar o manipulador substituído na classe base para que as classes base e o Windows possam operar na mensagem. Onde você chama o manipulador de classe base em sua substituição depende das circunstâncias. Às vezes, você deve chamar o manipulador de classe base primeiro e, às vezes, durar. Às vezes, você chama o manipulador de classe base condicionalmente, se optar por não manipular a mensagem por conta própria. Às vezes, você deve chamar o manipulador de classe base e, em seguida, executar condicionalmente seu próprio código de manipulador, dependendo do valor ou do estado retornado pelo manipulador de classe base.

> [!CAUTION]
> Não é seguro modificar os argumentos passados para um manipulador se você pretende passá-los para um manipulador de classe base. Por exemplo, você pode estar tentado a modificar o argumento *nchar* do `OnChar` manipulador (para converter em maiúsculas, por exemplo). Esse comportamento é bastante obscuro, mas se você precisar realizar esse efeito, use a `CWnd` função de membro `SendMessage` em vez disso.

Como você determina a maneira apropriada de substituir uma determinada mensagem quando o [Assistente de classe](reference/mfc-class-wizard.md) grava o esqueleto da função do manipulador para uma determinada mensagem — um `OnCreate` manipulador para **WM_CREATE**, por exemplo, ele faz um esboço na forma da função de membro substituída recomendada. O exemplo a seguir recomenda que o manipulador chame primeiro o manipulador de classe base e continue somente na condição de que ele não retorna-1.

[!code-cpp[NVC_MFCMessageHandling#3](codesnippet/cpp/handlers-for-standard-windows-messages_1.cpp)]

Por convenção, os nomes desses manipuladores começam com o prefixo "on". Alguns desses manipuladores não usam argumentos, enquanto outros levam vários. Alguns também têm um tipo de retorno diferente de **void**. Os manipuladores padrão para todas as mensagens de **WM_** são documentados na *referência do MFC* como funções de membro da classe `CWnd` cujos nomes começam com "on". As declarações de função de membro no `CWnd` são prefixadas com **afx_msg**.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](declaring-message-handler-functions.md)
