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
ms.openlocfilehash: 84e12a8f4ca0ce6384bc60b2fa01bfaf7824c864
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50585413"
---
# <a name="handlers-for-standard-windows-messages"></a>Manipuladores para mensagens do Windows padrão

Padrão de manipuladores para mensagens padrão do Windows (**WM _**) são predefinidos na classe `CWnd`. A biblioteca de classes bases de nomes para esses manipuladores no nome da mensagem. Por exemplo, o manipulador para o **WM_PAINT** mensagem é declarada em `CWnd` como:

`afx_msg void OnPaint();`

O **afx_msg** palavra-chave sugere o efeito do C++ **virtual** palavra-chave por distinção entre os manipuladores de outros `CWnd` funções de membro. No entanto, observe que essas funções não são realmente virtuais; em vez disso, eles são implementados por meio de mapas de mensagem. Mapas de mensagem dependem exclusivamente em macros de pré-processador padrão, não em qualquer extensões para a linguagem C++. O **afx_msg** palavra-chave é resolvido para o espaço em branco após o pré-processamento.

Para substituir um manipulador definido em uma classe base, defina uma função com o mesmo protótipo em sua classe derivada e para fazer uma entrada de mapa de mensagem para o manipulador. Seu manipulador "substitui" qualquer manipulador de mesmo nome em qualquer uma das classes base da sua classe.

Em alguns casos, seu manipulador deve chamar o manipulador substituído na classe base para que as classes base e o Windows podem operar na mensagem. Onde você chama o manipulador de classe base em sua substituição depende das circunstâncias. Às vezes, você deve chamar o manipulador de classe base primeiro e, às vezes, a última. Às vezes você chamar o manipulador de classe base condicionalmente, se você optar por não manipular a mensagem por conta própria. Às vezes, você deve chamar o manipulador de classe base e executar condicionalmente seu próprio código do manipulador, dependendo do valor ou estado retornado pelo manipulador de classe base.

> [!CAUTION]
>  Não é seguro modificar os argumentos passados para um manipulador, se você pretende passá-los para um manipulador de classe base. Por exemplo, você pode ficar tentado a modificar o *nChar* argumento do `OnChar` manipulador (para converter em maiusculas, por exemplo). Esse comportamento é razoavelmente obscuro, mas se você precisar realizar esse efeito, use o `CWnd` função de membro `SendMessage` em vez disso.

Como é possível determinar o modo adequado para substituir uma mensagem específica quando a janela Propriedades grava o esqueleto da função de manipulador para uma determinada mensagem — uma `OnCreate` manipulador **WM_CREATE**, por exemplo — ele esboça na forma de a função de membro substituído recomendada. O exemplo a seguir recomenda que o manipulador de primeiro chamar o manipulador de classe base e prosseguir somente sob condição de que ele não retorna -1.

[!code-cpp[NVC_MFCMessageHandling#3](../mfc/codesnippet/cpp/handlers-for-standard-windows-messages_1.cpp)]

Por convenção, os nomes desses manipuladores começam com o prefixo "On". Alguns desses manipuladores não aceitam argumentos, enquanto outras usam vários. Alguns também têm um tipo de retorno diferente de **void**. Os manipuladores padrão para todos os **WM _** mensagens estão documentadas na *referência da MFC* como funções de membro da classe `CWnd` cujos nomes começam com "Ligado". As declarações de função de membro na `CWnd` têm o prefixo **afx_msg**.

## <a name="see-also"></a>Consulte também

[Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)
