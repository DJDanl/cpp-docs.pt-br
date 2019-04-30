---
title: Aviso de programação MBCS geral
ms.date: 11/04/2016
helpviewer_keywords:
- MBCS [C++], dialog box fonts
- MS Shell Dlg
- MBCS [C++], programming
- dialog boxes [C++], fonts
ms.assetid: 7b541235-f3e5-4af0-b2c2-a0112cd5fbfb
ms.openlocfilehash: 31c17d6d6dee49f75f5cd8f84aa0690e649aa509
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410662"
---
# <a name="general-mbcs-programming-advice"></a>Aviso de programação MBCS geral

Use as dicas a seguir:

- Para obter flexibilidade, usar macros de tempo de execução, como `_tcschr` e `_tcscpy` quando possível. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

- Use o tempo de execução C `_getmbcp` função para obter informações sobre a página de código atual.

- Não reutilize os recursos de cadeia de caracteres. Dependendo do idioma de destino, uma determinada cadeia de caracteres pode ter um significado diferente quando convertido. Por exemplo, menu principal do "File" na caixa de diálogo poderia traduzir de forma diferente da cadeia de caracteres "File" em uma caixa de diálogo. Se você precisar usar mais de uma cadeia de caracteres com o mesmo nome, use as IDs de cadeia de caracteres diferente para cada.

- Você talvez queira descobrir se seu aplicativo está em execução em um sistema de operacional habilitado para MBCS. Para fazer isso, defina um sinalizador na inicialização do programa; Não confie em chamadas de API.

- Durante a criação de caixas de diálogo, permitir aproximadamente 30% de espaço extra no final dos controles de texto estático para a conversão de MBCS.

- Tenha cuidado ao selecionar fontes para seu aplicativo, pois algumas fontes não estão disponíveis em todos os sistemas.

- Ao selecionar a fonte para caixas de diálogo, use [MS Shell Dlg](/windows/desktop/Intl/using-ms-shell-dlg-and-ms-shell-dlg-2) em vez de MS Sans Serif ou Helvetica. MS Shell Dlg é substituído com a fonte correta pelo sistema antes de criar a caixa de diálogo. Usar o MS Shell Dlg garante que as alterações no sistema operacional para lidar com essa fonte automaticamente estarão disponíveis. (MFC substitui MS Shell Dlg com o DEFAULT_GUI_FONT ou a fonte do sistema no Windows 95, Windows 98 e Windows NT 4 porque esses sistemas não tratam MS Shell Dlg corretamente.)

- Ao projetar seu aplicativo, decida quais cadeias de caracteres podem ser localizadas. Em caso de dúvida, suponha que qualquer cadeia de caracteres fornecida será localizada. Como tal, não misture cadeias de caracteres que podem ser localizadas com aquelas que não é possível.

## <a name="see-also"></a>Consulte também

[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)<br/>
[Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)
