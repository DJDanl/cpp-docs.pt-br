---
title: Teclas de aceleração (C++)
ms.date: 02/14/2019
helpviewer_keywords:
- accelerator keys
- keyboard shortcuts
- keyboard shortcuts [C++], predefined
- menus [C++], shortcut keys
- keyboard shortcuts [C++], menu association
ms.assetid: f234c5f2-4ec3-4c9e-834a-b5dd297625b9
ms.openlocfilehash: beb4e878138da3dc2905c86e18fedc658d7ceecf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80215144"
---
# <a name="accelerator-keys-c"></a>Teclas de aceleração (C++)

## <a name="predefined-accelerator-keys"></a>Teclas de aceleração predefinidas

Há várias chaves de aceleração predefinidas que podem fazer parte de um projeto de aplicativo do Windows. Algumas dessas chaves virtuais são para o ambiente do Windows. Outros oferecem suporte a aplicativos de navegador ou Unicode. Você pode usar qualquer uma dessas chaves em qualquer acelerador.

|Chave|DESCRIÇÃO|
|---------|-----------------|
|VK_ACCEPT|(IME) aceitar|
|VK_BROWSER_BACK|Windows Navegador, chave de **fundo**|
|VK_BROWSER_FAVORITES|Windows Navegador, chave de **favoritos**|
|VK_BROWSER_FORWARD|Windows Navegador, chave de **encaminhamento**|
|VK_BROWSER_HOME|Windows Navegador, **início** e chave **inicial**|
|VK_BROWSER_REFRESH|Windows Navegador, **Atualizar** chave|
|VK_BROWSER_SEARCH|Windows Navegador, chave de **pesquisa**|
|VK_BROWSER_STOP|Windows Navegador, **parar** chave|
|VK_CONVERT|(IME) converter|
|VK_FINAL|(IME) modo final|
|VK_HANGUEL|IMEs Modo Hanguel (mantido para compatibilidade, use VK_HANGUL)|
|VK_HANGUL|IMEs Modo Hangul|
|VK_HANJA|IMEs Modo Hanja|
|VK_JUNJA|IMEs Modo de Junja|
|VK_KANA|IMEs Modo Kana|
|VK_KANJI|IMEs Modo kanji|
|VK_LAUNCH_APP1|Windows **Iniciar chave do aplicativo 1**|
|VK_LAUNCH_APP2|Windows **Iniciar chave do aplicativo 2**|
|VK_LAUNCH_MAIL|Windows **Iniciar** chave de email|
|VK_LAUNCH_MEDIA_SELECT|Windows **Selecionar** chave de mídia|
|VK_LCONTROL|Tecla **CTRL esquerda**|
|VK_LMENU|Tecla de **menu à esquerda**|
|VK_LSHIFT|Tecla **SHIFT esquerda**|
|VK_MEDIA_NEXT_TRACK|Windows **Próxima** chave de faixa|
|VK_MEDIA_PLAY_PAUSE|Windows **Reproduzir/pausar** chave de mídia|
|VK_MEDIA_PREV_TRACK|Windows Chave de **faixa anterior**|
|VK_MEDIA_STOP|Windows **Parar** chave de mídia|
|VK_MODECHANGE|Solicitação de alteração do modo (IME)|
|VK_NONCONVERT|(IME) não convertido|
|VK_OEM_1|Windows Para o teclado padrão dos EUA, a chave **;:**|
|VK_OEM_102|Windows A tecla de colchete angular ou a tecla de barra invertida no teclado RT 102-Key|
|VK_OEM_2|Windows Para o teclado padrão dos EUA, a **/?** chave|
|VK_OEM_3|Windows Para o teclado padrão dos EUA, a chave de **`~**|
|VK_OEM_4|Windows Para o teclado padrão dos EUA, a **[{** Key|
|VK_OEM_5|Windows Para o teclado padrão dos EUA, a chave de **\\&#124;**|
|VK_OEM_6|Windows Para o teclado padrão dos EUA, a chave **]}**|
|VK_OEM_7|Windows Para o teclado padrão dos EUA, a chave ' aspa simples/aspas duplas '|
|VK_OEM_COMMA|Windows Para qualquer país/região **, a chave**|
|VK_OEM_MINUS|Windows Para qualquer país/região, a chave de **-**|
|VK_OEM_PERIOD|Windows Para qualquer país/região, o **.** chave|
|VK_OEM_PLUS|Windows Para qualquer país/região, a chave de **+**|
|VK_PACKET|Windows Usado para passar caracteres Unicode como se eles estivessem pressionamentos de teclas.|
|VK_RCONTROL|Tecla **Ctrl direita**|
|VK_RMENU|Tecla de **menu à direita**|
|VK_RSHIFT|Tecla **SHIFT direita**|
|VK_SLEEP|Chave de **suspensão do computador**|
|VK_VOLUME_DOWN|Windows Chave de **volume inativo**|
|VK_VOLUME_MUTE|Windows Chave de **mudo do volume**|
|VK_VOLUME_UP|Windows Chave **de volume para cima**|
|VK_XBUTTON1|Windows Botão do mouse **X1**|
|VK_XBUTTON2|Windows **X2** botão do mouse|

## <a name="accelerator-key-association"></a>Associação de chave de aceleração

Muitas vezes, você deseja que um item de menu e uma combinação de teclado emitam o mesmo comando de programa. Você faz essa ação atribuindo o mesmo identificador de recurso (ID) ao item de menu e a uma entrada na tabela de acelerador do aplicativo. Em seguida, edite a legenda do item de menu para mostrar o nome do acelerador. Para obter mais informações sobre itens de menu e teclas de aceleração, consulte [comandos de menu](../windows/associating-a-menu-command-with-an-accelerator-key.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Confira também

[Editor de aceleradores](../windows/accelerator-editor.md)<br/>
