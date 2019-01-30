---
title: Teclas de aceleração (C++)
ms.date: 11/04/2016
f1_keywords:
- vc.editors.accelerator
helpviewer_keywords:
- accelerator keys
- keyboard shortcuts
- keyboard shortcuts [C++], predefined
- menus [C++], shortcut keys
- keyboard shortcuts [C++], menu association
ms.assetid: f234c5f2-4ec3-4c9e-834a-b5dd297625b9
ms.openlocfilehash: 1e87d80b8995760eecda34334dab702480bd9669
ms.sourcegitcommit: 5beace7dcc6bf0e8b8cc96a930e7424f9daa05cb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2019
ms.locfileid: "55232117"
---
# <a name="accelerator-keys-c"></a>Teclas de aceleração (C++)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="predefined-accelerator-keys"></a>Teclas de aceleração predefinidas

Há um número de teclas de aceleração predefinidas que podem ser parte de um projeto de aplicativo do Windows. Algumas dessas chaves virtuais são para o ambiente do Windows. Outros navegadores de suporte ou aplicativos Unicode. Você pode usar qualquer uma dessas chaves em qualquer acelerador.

|Chave|Descrição|
|---------|-----------------|
|VK_ACCEPT|Aceitação do IME|
|VK_BROWSER_BACK|Windows: Tecla Voltar do navegador|
|VK_BROWSER_FAVORITES|Windows: Tecla Favoritos do navegador|
|VK_BROWSER_FORWARD|Windows: Tecla Avançar do navegador|
|VK_BROWSER_HOME|Windows: Chave de início do navegador e página inicial|
|VK_BROWSER_REFRESH|Windows: Tecla atualizar do navegador|
|VK_BROWSER_SEARCH|Windows: Chave de pesquisa do navegador|
|VK_BROWSER_STOP|Windows: Tecla parar do navegador|
|VK_CONVERT|Conversão do IME|
|VK_FINAL|Modo final do IME|
|VK_HANGUEL|Modo IME Hanguel (mantida para compatibilidade, use VK_HANGUL)|
|VK_HANGUL|Modo IME Hangul|
|VK_HANJA|Modo IME Hanja|
|VK_JUNJA|Modo IME Junja|
|VK_KANA|Modo IME Kana|
|VK_KANJI|Modo IME Kanji|
|VK_LAUNCH_APP1|Windows: Iniciar aplicativo 1 chave|
|VK_LAUNCH_APP2|Windows: Iniciar aplicativo 2 chave|
|VK_LAUNCH_MAIL|Windows: Tecla de email de início|
|VK_LAUNCH_MEDIA_SELECT|Windows: Selecione a chave de mídia|
|VK_LCONTROL|Chave de controle da esquerda|
|VK_LMENU|Tecla de MENU à esquerda|
|VK_LSHIFT|Tecla SHIFT esquerda|
|VK_MEDIA_NEXT_TRACK|Windows: Próxima chave de faixa|
|VK_MEDIA_PLAY_PAUSE|Windows: Tecla Reproduzir/Pausar mídia|
|VK_MEDIA_PREV_TRACK|Windows: Chave de faixa anterior|
|VK_MEDIA_STOP|Windows: Parar a chave de mídia|
|VK_MODECHANGE|Solicitação de alteração do modo IME|
|VK_NONCONVERT|Sem conversão do IME|
|VK_OEM_1|Windows: Para o teclado padrão dos EUA, o ';:' chave|
|VK_OEM_102|Windows: A tecla de colchete angular ou a tecla de barra invertida no teclado de 102 teclas RT|
|VK_OEM_2|Windows: Para o teclado padrão dos EUA, o '/'? key|
|VK_OEM_3|Windows: Para o teclado padrão dos EUA, o ' ~' chave|
|VK_OEM_4|Windows: Para o teclado padrão dos EUA, o ' [{' chave|
|VK_OEM_5|Windows: Para o teclado padrão dos EUA, o '\\&#124;' chave|
|VK_OEM_6|Windows: Para o teclado padrão dos EUA, o ']}' chave|
|VK_OEM_7|Windows: Para o teclado padrão dos EUA, a chave ' aspas/double-aspas simples'|
|VK_OEM_COMMA|Windows: Para qualquer país/região, a chave ''|
|VK_OEM_MINUS|Windows: Para qualquer país/região, o '-' chave|
|VK_OEM_PERIOD|Windows: Para qualquer país/região, o '.' chave|
|VK_OEM_PLUS|Windows: Para qualquer país/região, a chave '+'|
|VK_PACKET|Windows: Usado para passar caracteres Unicode como se fossem pressionamentos de tecla.|
|VK_RCONTROL|Chave de controle à direita|
|VK_RMENU|Tecla de MENU à direita|
|VK_RSHIFT|Tecla SHIFT direita|
|VK_SLEEP|Tecla de suspensão do computador|
|VK_VOLUME_DOWN|Windows: Tecla abaixar volume|
|VK_VOLUME_MUTE|Windows: Tecla ativar mudo|
|VK_VOLUME_UP|Windows: Tecla aumentar volume|
|VK_XBUTTON1|Windows: Botão do mouse x1|
|VK_XBUTTON2|Windows: Botão do mouse X2|

## <a name="associating-an-accelerator-key-with-a-menu-item"></a>Associando uma tecla de aceleração a um item de menu

Muitas vezes, você deseja um item de menu e uma combinação de teclado para emitir o mesmo comando do programa. Você pode fazer isso atribuindo o mesmo identificador de recurso (ID) para o item de menu e uma entrada na tabela de Aceleradores do seu aplicativo. Você então editar a legenda do item de menu para mostrar o nome do acelerador. Para obter mais informações sobre itens de menu e teclas de aceleração, consulte [associando um Item de Menu uma tecla aceleradora](../windows/associating-a-menu-command-with-an-accelerator-key.md).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de aceleradores](../windows/accelerator-editor.md)<br/>
[Editores de recursos](../windows/resource-editors.md)
