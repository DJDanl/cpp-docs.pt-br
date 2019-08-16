---
title: Aviso de programação MBCS geral
ms.date: 11/04/2016
helpviewer_keywords:
- MBCS [C++], dialog box fonts
- MS Shell Dlg
- MBCS [C++], programming
- dialog boxes [C++], fonts
ms.assetid: 7b541235-f3e5-4af0-b2c2-a0112cd5fbfb
ms.openlocfilehash: 887387220105614eb3257f008ec601a6fc0adc18
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491181"
---
# <a name="general-mbcs-programming-advice"></a>Aviso de programação MBCS geral

Use as seguintes dicas:

- Para flexibilidade, use macros de tempo de execução `_tcschr` , `_tcscpy` como e quando possível. Para obter mais informações, consulte Mapeamentos de [texto genérico em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

- Use a função de tempo `_getmbcp` de execução C para obter informações sobre a página de código atual.

- Não reutilize recursos de cadeia de caracteres. Dependendo do idioma de destino, uma determinada cadeia de caracteres pode ter um significado diferente quando traduzida. Por exemplo, "File" no menu principal do aplicativo pode ser convertido de forma diferente da cadeia de caracteres "File" em uma caixa de diálogo. Se você precisar usar mais de uma cadeia de caracteres com o mesmo nome, use IDs de cadeia de caracteres diferentes para cada uma.

- Talvez você queira descobrir se o aplicativo está em execução em um sistema operacional habilitado para MBCS. Para fazer isso, defina um sinalizador na inicialização do programa; Não confie em chamadas à API.

- Ao criar caixas de diálogo, permita aproximadamente 30% de espaço extra no final dos controles de texto estático para tradução MBCS.

- Tenha cuidado ao selecionar fontes para seu aplicativo, pois algumas fontes não estão disponíveis em todos os sistemas.

- Ao selecionar a fonte para caixas de diálogo, use [MS Shell Dlg](/windows/win32/Intl/using-ms-shell-dlg-and-ms-shell-dlg-2) em vez de MS Sans Serif ou Helvetica. O MS Shell Dlg é substituído pela fonte correta pelo sistema antes da criação da caixa de diálogo. Usar o MS Shell Dlg garante que qualquer alteração no sistema operacional para lidar com essa fonte estará disponível automaticamente. (O MFC substitui o MS Shell Dlg pelo DEFAULT_GUI_FONT ou a fonte do sistema no Windows 95, no Windows 98 e no Windows NT 4, pois esses sistemas não lidam com o MS Shell Dlg corretamente.)

- Ao criar seu aplicativo, decida quais cadeias de caracteres podem ser localizadas. Em caso de dúvida, suponha que uma determinada cadeia de caracteres será localizada. Como tal, não misture as cadeias de caracteres que podem ser localizadas com aquelas que não podem.

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)
