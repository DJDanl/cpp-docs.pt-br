---
title: Implementando uma janela com CWindowImpl
ms.date: 11/04/2016
f1_keywords:
- CWindowImpl
helpviewer_keywords:
- ATL, windows
- windows [C++], subclassing
- windows [C++], superclassing
- windows [C++], ATL
- subclassing ATL window classes
- superclassing, ATL
ms.assetid: 3fc40550-f1d6-4702-8b7c-4cf682b6a855
ms.openlocfilehash: f9286598184cfb12c415de637fccc07011369fd5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50501953"
---
# <a name="implementing-a-window-with-cwindowimpl"></a>Implementando uma janela com CWindowImpl

Para implementar uma janela, derive uma classe de `CWindowImpl`. Em sua classe derivada, declare um mapa de mensagem e as funções do manipulador de mensagem. Agora você pode usar a classe de três maneiras diferentes:

- [Criar uma janela com base em uma nova classe do Windows](#_atl_creating_a_window_based_on_a_new_windows_class)

- [Superclasse uma classe existente do Windows](#_atl_superclassing_an_existing_windows_class)

- [Subclasse uma janela existente](#_atl_subclassing_an_existing_window)

##  <a name="_atl_creating_a_window_based_on_a_new_windows_class"></a> Criar uma janela com base em uma nova classe do Windows

`CWindowImpl` contém o [DECLARE_WND_CLASS](reference/window-class-macros.md#declare_wnd_class) macro para declarar as informações de classe do Windows. Essa macro implementa o `GetWndClassInfo` função, que usa [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) para definir as informações de uma nova classe do Windows. Quando `CWindowImpl::Create` é chamado, esse Windows classe é registrada e uma nova janela é criada.

> [!NOTE]
>  `CWindowImpl` passa nulo para o `DECLARE_WND_CLASS` macro, o que significa que o ATL irá gerar um nome de classe do Windows. Para especificar seu próprio nome, passar uma cadeia de caracteres para DECLARE_WND_CLASS no seu `CWindowImpl`-classe derivada.

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe que implementa uma janela com base em uma nova classe do Windows:

[!code-cpp[NVC_ATL_Windowing#64](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_1.h)]

Para criar uma janela, crie uma instância do `CMyWindow` e, em seguida, chamar o `Create` método.

> [!NOTE]
>  Para substituir as informações de classe do Windows padrão, implementar o `GetWndClassInfo` método em sua classe derivada, definindo o `CWndClassInfo` membros para os valores apropriados.

##  <a name="_atl_superclassing_an_existing_windows_class"></a> Superclassing uma classe existente do Windows

O [DECLARE_WND_SUPERCLASS](reference/window-class-macros.md#declare_wnd_superclass) macro permite que você crie esse superclassificar um Windows existente de uma janela de classe. Especifique esta macro em seu `CWindowImpl`-classe derivada. Como qualquer outra janela da ATL, as mensagens são manipuladas por um mapa de mensagem.

Quando você usa DECLARE_WND_SUPERCLASS, uma nova classe do Windows será registrada. Essa nova classe será o mesmo que a classe existente que você especificar, mas substituirá o procedimento de janela com `CWindowImpl::WindowProc` (ou com a função que substitui esse método).

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe que a edição standard superclassificar classe:

[!code-cpp[NVC_ATL_Windowing#65](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_2.h)]

Para criar a janela de edição de superclasse, crie uma instância do `CMyEdit` e, em seguida, chamar o `Create` método.

##  <a name="_atl_subclassing_an_existing_window"></a> Criando subclasses de uma janela existente

A subclasse uma janela existente, derive uma classe de `CWindowImpl` e declarar um mapa de mensagem, como em dois casos anteriores. No entanto, observe que você não especificar qualquer informação de classe do Windows, uma vez que você irá subclasse uma janela já existente.

Em vez de chamar `Create`, chame `SubclassWindow` e passá-lo o identificador para a janela existente que deseja subclasse. Depois que a janela é uma subclasse, ele usará `CWindowImpl::WindowProc` (ou a função que substitui esse método) para direcionar mensagens para o mapa da mensagem. Para desanexar uma janela de subclasse do seu objeto, chame `UnsubclassWindow`. O procedimento de janela original da janela, em seguida, será restaurado.

## <a name="see-also"></a>Consulte também

[Implementando uma janela](../atl/implementing-a-window.md)

