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
ms.openlocfilehash: 7ce1a2ec08e49e047aee5248bda0094d9e392614
ms.sourcegitcommit: ced5ff1431ffbd25b20d106901955532723bd188
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/16/2020
ms.locfileid: "92135509"
---
# <a name="implementing-a-window-with-cwindowimpl"></a>Implementando uma janela com CWindowImpl

Para implementar uma janela, derive uma classe de `CWindowImpl` . Na classe derivada, declare um mapa de mensagens e as funções do manipulador de mensagens. Agora você pode usar sua classe de três maneiras diferentes:

- [Criar uma janela com base em uma nova classe do Windows](#_atl_creating_a_window_based_on_a_new_windows_class)

- [Superclasse de uma classe do Windows existente](#_atl_superclassing_an_existing_windows_class)

- [Subclasse de uma janela existente](#_atl_subclassing_an_existing_window)

## <a name="creating-a-window-based-on-a-new-windows-class"></a><a name="_atl_creating_a_window_based_on_a_new_windows_class"></a> Criando uma janela com base em uma nova classe do Windows

`CWindowImpl` contém a macro [DECLARE_WND_CLASS](reference/window-class-macros.md#declare_wnd_class) para declarar informações de classe do Windows. Essa macro implementa a `GetWndClassInfo` função, que usa [CWndClassInfo](../atl/reference/cwndclassinfo-class.md) para definir as informações de uma nova classe do Windows. Quando `CWindowImpl::Create` é chamado, essa classe do Windows é registrada e uma nova janela é criada.

> [!NOTE]
> `CWindowImpl` passa NULL para a `DECLARE_WND_CLASS` macro, o que significa que a ATL irá gerar um nome de classe do Windows. Para especificar seu próprio nome, passe uma cadeia de caracteres para DECLARE_WND_CLASS em sua `CWindowImpl` classe derivada.

## <a name="example-implement-a-window"></a>Exemplo: implementar uma janela

Veja a seguir um exemplo de uma classe que implementa uma janela com base em uma nova classe do Windows:

[!code-cpp[NVC_ATL_Windowing#64](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_1.h)]

Para criar uma janela, crie uma instância do `CMyWindow` e, em seguida, chame o `Create` método.

> [!NOTE]
> Para substituir as informações padrão da classe do Windows, implemente o `GetWndClassInfo` método em sua classe derivada definindo os `CWndClassInfo` Membros com os valores apropriados.

## <a name="superclassing-an-existing-windows-class"></a><a name="_atl_superclassing_an_existing_windows_class"></a> Superclasse de uma classe existente do Windows

A macro [DECLARE_WND_SUPERCLASS](reference/window-class-macros.md#declare_wnd_superclass) permite que você crie uma janela que subclassea uma classe existente do Windows. Especifique essa macro na `CWindowImpl` classe derivada. Como qualquer outra janela da ATL, as mensagens são tratadas por um mapa de mensagens.

Quando você usar DECLARE_WND_SUPERCLASS, uma nova classe do Windows será registrada. Essa nova classe será igual à classe existente que você especificar, mas substituirá o procedimento de janela por `CWindowImpl::WindowProc` (ou pela função que substitui esse método).

## <a name="example-superclass-the-edit-class"></a>Exemplo: superclasse a classe de edição

Veja a seguir um exemplo de uma classe que faz a superclasse da classe de edição padrão:

[!code-cpp[NVC_ATL_Windowing#65](../atl/codesnippet/cpp/implementing-a-window-with-cwindowimpl_2.h)]

Para criar a janela de edição de superclasse, crie uma instância do `CMyEdit` e, em seguida, chame o `Create` método.

## <a name="subclassing-an-existing-window"></a><a name="_atl_subclassing_an_existing_window"></a> Subclasse de uma janela existente

Para subclasse de uma janela existente, derive uma classe de `CWindowImpl` e declare um mapa de mensagens, como nos dois casos anteriores. No entanto, observe que você não especifica nenhuma informação de classe do Windows, já que você criará uma subclasse de uma janela já existente.

Em vez de chamar `Create` , chamar `SubclassWindow` e passar o identificador para a janela existente que você deseja subclasse. Depois que a janela for subclasse, ela usará `CWindowImpl::WindowProc` (ou sua função que substitui esse método) para direcionar mensagens para o mapa de mensagens. Para desanexar uma janela de uma subclasse do seu objeto, chame `UnsubclassWindow` . O procedimento da janela original da janela será então restaurado.

## <a name="see-also"></a>Confira também

[Implementando uma janela](../atl/implementing-a-window.md)
