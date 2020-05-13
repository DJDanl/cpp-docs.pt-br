---
title: Implementando uma janela com CWindowImpl
ms.date: 11/04/2016
helpviewer_keywords:
- ATL, windows
- windows [C++], subclassing
- windows [C++], superclassing
- windows [C++], ATL
- subclassing ATL window classes
- superclassing, ATL
ms.assetid: 3fc40550-f1d6-4702-8b7c-4cf682b6a855
ms.openlocfilehash: e5fdbf15ddd7edc69f0667a9b7e08c7c5e531a5e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319456"
---
# <a name="implementing-a-window-with-cwindowimpl"></a>Implementando uma janela com CWindowImpl

Para implementar uma janela, `CWindowImpl`obtenha uma classe de . Em sua classe derivada, declare um mapa de mensagem e as funções do manipulador de mensagens. Agora você pode usar sua classe de três maneiras diferentes:

- [Crie uma janela com base em uma nova classe windows](#_atl_creating_a_window_based_on_a_new_windows_class)

- [Superclass uma classe Windows existente](#_atl_superclassing_an_existing_windows_class)

- [Subclasse uma janela existente](#_atl_subclassing_an_existing_window)

## <a name="creating-a-window-based-on-a-new-windows-class"></a><a name="_atl_creating_a_window_based_on_a_new_windows_class"></a>Criando uma janela com base em uma nova classe do Windows

`CWindowImpl`contém a [DECLARE_WND_CLASS](reference/window-class-macros.md#declare_wnd_class) macro para declarar as informações da classe Windows. Essa macro implementa a `GetWndClassInfo` função, que usa o [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) para definir as informações de uma nova classe Windows. Quando `CWindowImpl::Create` é chamado, esta classe do Windows é registrada e uma nova janela é criada.

> [!NOTE]
> `CWindowImpl`passa NULL `DECLARE_WND_CLASS` para a macro, o que significa que atl irá gerar um nome de classe Windows. Para especificar seu próprio nome, passe `CWindowImpl`uma string para DECLARE_WND_CLASS em sua classe derivada.

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe que implementa uma janela com base em uma nova classe windows:

[!code-cpp[NVC_ATL_Windowing#64](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_1.h)]

Para criar uma janela, `CMyWindow` crie uma `Create` instância e, em seguida, chame o método.

> [!NOTE]
> Para substituir as informações padrão da `GetWndClassInfo` classe Windows, implemente `CWndClassInfo` o método em sua classe derivada definindo os membros para os valores apropriados.

## <a name="superclassing-an-existing-windows-class"></a><a name="_atl_superclassing_an_existing_windows_class"></a>Superclassificação de uma classe windows existente

A [macro DECLARE_WND_SUPERCLASS](reference/window-class-macros.md#declare_wnd_superclass) permite criar uma janela que superclasses uma classe Windows existente. Especifique `CWindowImpl`esta macro em sua classe derivada. Como qualquer outra janela ATL, as mensagens são tratadas por um mapa de mensagens.

Quando você usar DECLARE_WND_SUPERCLASS, uma nova classe do Windows será registrada. Esta nova classe será a mesma que a classe existente especificada, mas substituirá o procedimento de janela por `CWindowImpl::WindowProc` (ou com sua função que substitui este método).

## <a name="example"></a>Exemplo

A seguir está um exemplo de uma classe que superclassifica a classe de edição padrão:

[!code-cpp[NVC_ATL_Windowing#65](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_2.h)]

Para criar a janela Editar superclassificada, `CMyEdit` crie uma `Create` instância e, em seguida, chame o método.

## <a name="subclassing-an-existing-window"></a><a name="_atl_subclassing_an_existing_window"></a>Subclassificando uma janela existente

Para subclassificar uma janela existente, `CWindowImpl` obtenha uma classe e declare um mapa de mensagem, como nos dois casos anteriores. Observe, no entanto, que você não especifica nenhuma informação de classe do Windows, uma vez que você subclasse uma janela já existente.

Em vez `Create`de `SubclassWindow` ligar, ligue e passe a alça para a janela existente que deseja subclasse. Uma vez que a janela é `CWindowImpl::WindowProc` subclassificada, ela usará (ou sua função que substitui esse método) para direcionar mensagens para o mapa da mensagem. Para desprender uma janela subclassificada `UnsubclassWindow`do seu objeto, ligue . O procedimento original da janela da janela será então restaurado.

## <a name="see-also"></a>Confira também

[Implementando uma janela](../atl/implementing-a-window.md)
