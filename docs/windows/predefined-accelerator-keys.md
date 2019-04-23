---
title: Teclas de aceleração (C++)
ms.date: 02/14/2019
f1_keywords:
- vc.editors.accelerator
helpviewer_keywords:
- accelerator keys
- keyboard shortcuts
- keyboard shortcuts [C++], predefined
- menus [C++], shortcut keys
- keyboard shortcuts [C++], menu association
ms.assetid: f234c5f2-4ec3-4c9e-834a-b5dd297625b9
ms.openlocfilehash: bb407538f254df5f187ff91b85a8eaa753a52287
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59027501"
---
# <a name="accelerator-keys-c"></a>Teclas de aceleração (C++)

## <a name="predefined-accelerator-keys"></a>Teclas de aceleração predefinidas

Há um número de teclas de aceleração predefinidas que podem ser parte de um projeto de aplicativo do Windows. Algumas dessas chaves virtuais são para o ambiente do Windows. Outros dão suporte a navegador ou aplicativos Unicode. Você pode usar qualquer uma dessas chaves em qualquer acelerador.

|Chave|Descrição|
|---------|-----------------|
|VK_ACCEPT|(IME para) aceitar|
|VK_BROWSER_BACK|(Windows) Navegador, **volta** chave|
|VK_BROWSER_FAVORITES|(Windows) Navegador, **Favoritos** chave|
|VK_BROWSER_FORWARD|(Windows) Navegador, **Forward** chave|
|VK_BROWSER_HOME|(Windows) Navegador, **inicie** e **Home** chave|
|VK_BROWSER_REFRESH|(Windows) Navegador, **Refresh** chave|
|VK_BROWSER_SEARCH|(Windows) Navegador, **pesquisa** chave|
|VK_BROWSER_STOP|(Windows) Navegador, **parar** chave|
|VK_CONVERT|Convert (IME)|
|VK_FINAL|Modo final do IME)|
|VK_HANGUEL|(IME) Modo Hanguel (mantida para compatibilidade, use VK_HANGUL)|
|VK_HANGUL|(IME) Modo Hangul|
|VK_HANJA|(IME) Modo de hanja|
|VK_JUNJA|(IME) Modo de Junja|
|VK_KANA|(IME) Modo de kana|
|VK_KANJI|(IME) Modo de kanji|
|VK_LAUNCH_APP1|(Windows) **Iniciar aplicativo 1** chave|
|VK_LAUNCH_APP2|(Windows) **Iniciar aplicativo 2** chave|
|VK_LAUNCH_MAIL|(Windows) **Iniciar email** chave|
|VK_LAUNCH_MEDIA_SELECT|(Windows) **Selecionar mídia** chave|
|VK_LCONTROL|**Ctrl esquerda** chave|
|VK_LMENU|**Menu da esquerda** chave|
|VK_LSHIFT|**Shift esquerda** chave|
|VK_MEDIA_NEXT_TRACK|(Windows) **Next Track** chave|
|VK_MEDIA_PLAY_PAUSE|(Windows) **Reproduzir/Pausar mídia** chave|
|VK_MEDIA_PREV_TRACK|(Windows) **Previous Track** chave|
|VK_MEDIA_STOP|(Windows) **Parar mídia** chave|
|VK_MODECHANGE|Solicitação de alteração do modo IME)|
|VK_NONCONVERT|Sem conversão do IME)|
|VK_OEM_1|(Windows) Para o teclado padrão dos EUA, o **;:** chave|
|VK_OEM_102|(Windows) A tecla de colchete angular ou a tecla de barra invertida no teclado de 102 teclas RT|
|VK_OEM_2|(Windows) Para o teclado padrão dos EUA, o **/?** key|
|VK_OEM_3|(Windows) Para o teclado padrão dos EUA, o **`~** chave|
|VK_OEM_4|(Windows) Para o teclado padrão dos EUA, o **[{** chave|
|VK_OEM_5|(Windows) Para o teclado padrão dos EUA, o **\\ &#124;** chave|
|VK_OEM_6|(Windows) Para o teclado padrão dos EUA, o **]}** chave|
|VK_OEM_7|(Windows) Para o teclado padrão dos EUA, a chave ' aspas/double-aspas simples'|
|VK_OEM_COMMA|(Windows) Para qualquer país/região, o **,** chave|
|VK_OEM_MINUS|(Windows) Para qualquer país/região, o **-** chave|
|VK_OEM_PERIOD|(Windows) Para qualquer país/região, o **.** key|
|VK_OEM_PLUS|(Windows) Para qualquer país/região, o **+** chave|
|VK_PACKET|(Windows) Usado para passar caracteres Unicode como se fossem pressionamentos de tecla.|
|VK_RCONTROL|**Ctrl direita** chave|
|VK_RMENU|**Menu direito** chave|
|VK_RSHIFT|**Shift direita** chave|
|VK_SLEEP|**Computador em suspensão** chave|
|VK_VOLUME_DOWN|(Windows) **Diminuir volume** chave|
|VK_VOLUME_MUTE|(Windows) **Mudo** chave|
|VK_VOLUME_UP|(Windows) **2&gt;aumentar** chave|
|VK_XBUTTON1|(Windows) **X1** botão do mouse|
|VK_XBUTTON2|(Windows) **X2** botão do mouse|

## <a name="accelerator-key-association"></a>Associação de chave de acelerador

Muitas vezes, você deseja um item de menu e uma combinação de teclado para emitir o mesmo comando do programa. Faça essa ação, atribuindo o mesmo identificador de recurso (ID) para o item de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você então editar a legenda do item de menu para mostrar o nome do acelerador. Para obter mais informações sobre itens de menu e teclas de aceleração, consulte [comandos de Menu](../windows/associating-a-menu-command-with-an-accelerator-key.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de aceleradores](../windows/accelerator-editor.md)<br/>