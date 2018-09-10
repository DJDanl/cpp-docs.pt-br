---
title: Predefinidas teclas de aceleração (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.editors.accelerator
dev_langs:
- C++
helpviewer_keywords:
- accelerator keys
- keyboard shortcuts
- keyboard shortcuts [C++], predefined
ms.assetid: f234c5f2-4ec3-4c9e-834a-b5dd297625b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e6498e0b0722b5de28b5569c5f3565b0f033ea9
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315672"
---
# <a name="predefined-accelerator-keys-c"></a>Teclas de aceleração predefinidas (C++)

Há um número de teclas de aceleração predefinidas que podem ser parte de um projeto de aplicativo do Windows. Algumas dessas chaves virtuais são para o ambiente do Windows. Outros navegadores de suporte ou aplicativos Unicode. Você pode usar qualquer uma dessas chaves em qualquer acelerador.

|Chave|Descrição|
|---------|-----------------|
|VK_ACCEPT|Aceitação do IME|
|VK_BROWSER_BACK|Windows: Chave de voltar do navegador|
|VK_BROWSER_FAVORITES|Windows: Tecla de favoritos do navegador|
|VK_BROWSER_FORWARD|Windows: Tecla Avançar do navegador|
|VK_BROWSER_HOME|Windows: Chave de início do navegador e página inicial|
|VK_BROWSER_REFRESH|Windows: Chave de atualizar o navegador|
|VK_BROWSER_SEARCH|Windows: Chave de pesquisa do navegador|
|VK_BROWSER_STOP|Windows: Chave de parar do navegador|
|VK_CONVERT|Conversão do IME|
|VK_FINAL|Modo final do IME|
|VK_HANGUEL|Modo IME Hanguel (mantida para compatibilidade, use VK_HANGUL)|
|VK_HANGUL|Modo IME Hangul|
|VK_HANJA|Modo IME Hanja|
|VK_JUNJA|Modo IME Junja|
|VK_KANA|Modo IME Kana|
|VK_KANJI|Modo IME Kanji|
|VK_LAUNCH_APP1|Windows: Chave Iniciar aplicativo 1|
|VK_LAUNCH_APP2|Windows: Chave Iniciar aplicativo 2|
|VK_LAUNCH_MAIL|Windows: Tecla de email de início|
|VK_LAUNCH_MEDIA_SELECT|Windows: Selecione a chave de mídia|
|VK_LCONTROL|Chave de controle da esquerda|
|VK_LMENU|Tecla de MENU à esquerda|
|VK_LSHIFT|Tecla SHIFT esquerda|
|VK_MEDIA_NEXT_TRACK|Windows: Próxima chave de controle|
|VK_MEDIA_PLAY_PAUSE|Windows: Chave de Reproduzir/Pausar mídia|
|VK_MEDIA_PREV_TRACK|Windows: Chave de faixa anterior|
|VK_MEDIA_STOP|Windows: Chave de mídia de parada|
|VK_MODECHANGE|Solicitação de alteração do modo IME|
|VK_NONCONVERT|Sem conversão do IME|
|VK_OEM_1|Windows: para o teclado padrão dos EUA, o ';:' chave|
|VK_OEM_102|Windows: Ambos o colchete angular chave ou a tecla de barra invertida no teclado de 102 teclas RT|
|VK_OEM_2|Windows: para o teclado padrão dos EUA, o '/'? key|
|VK_OEM_3|Windows: para o teclado padrão dos EUA, o ' ~' chave|
|VK_OEM_4|Windows: para o teclado padrão dos EUA, o ' [{' chave|
|VK_OEM_5|Windows: para o teclado padrão dos EUA, o '\\&#124;' chave|
|VK_OEM_6|Windows: para o teclado padrão dos EUA, o ']}' chave|
|VK_OEM_7|Windows: para o teclado padrão dos EUA, a chave ' aspas/double-aspas simples'|
|VK_OEM_COMMA|Windows: para qualquer país/região, a chave ''|
|VK_OEM_MINUS|Windows: para qualquer país/região, o '-' chave|
|VK_OEM_PERIOD|Windows: para qualquer país/região, o '.' chave|
|VK_OEM_PLUS|Windows: para qualquer país/região, a chave '+'|
|VK_PACKET|Windows: Usado para passar caracteres Unicode como se fossem pressionamentos de tecla.|
|VK_RCONTROL|Chave de controle à direita|
|VK_RMENU|Tecla de MENU à direita|
|VK_RSHIFT|Tecla SHIFT direita|
|VK_SLEEP|Tecla de suspensão do computador|
|VK_VOLUME_DOWN|Windows: Tecla abaixar Volume|
|VK_VOLUME_MUTE|Windows: Tecla ativar mudo do Volume|
|VK_VOLUME_UP|Windows: Tecla Aumentar Volume|
|VK_XBUTTON1|Windows: Botão do mouse X1|
|VK_XBUTTON2|Windows: Botão do mouse X2|

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editor de aceleradores](../windows/accelerator-editor.md)  
[Editores de recursos](../windows/resource-editors.md)