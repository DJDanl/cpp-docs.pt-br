---
title: /FD (recompilação mínima de IDE)
ms.date: 04/08/2019
helpviewer_keywords:
- /FD compiler option [C++]
- -FD compiler option [C++]
- FD compiler option [C++]
ms.assetid: 7ef21b8c-a448-4bb4-9585-a2a870028e17
ms.openlocfilehash: 896adcb97a259e6714cf23241424841456371491
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439810"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** é exposto apenas aos usuários na página de propriedades de [linha](command-line-property-pages.md) de comando C++ da caixa de diálogo **páginas de propriedades** de um projeto. Ele estará disponível se e somente se a opção/GM preterida e desativada [(habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) não estiver selecionada. **/FD** não tem nenhum efeito além do ambiente de desenvolvimento. **/FD** não é exposto na saída de `cl /?`.

Se você não habilitar a opção **/GM** preterida no ambiente de desenvolvimento, **/FD** será usado. O **/FD** garante que o arquivo. idb tenha informações de dependência suficientes. **/FD** é usado apenas pelo ambiente de desenvolvimento e não deve ser usado na linha de comando ou em um script de compilação.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
