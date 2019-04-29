---
title: /FD (recompilação mínima de IDE)
ms.date: 04/08/2019
f1_keywords:
- /FD
helpviewer_keywords:
- /FD compiler option [C++]
- -FD compiler option [C++]
- FD compiler option [C++]
ms.assetid: 7ef21b8c-a448-4bb4-9585-a2a870028e17
ms.openlocfilehash: ac63b021dc0cb9ee5964af7fa2e168f710653979
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292868"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** seja exposto somente a usuários na [linha de comando](command-line-property-pages.md) página de propriedades de um C++ do projeto **páginas de propriedade** caixa de diálogo. Ele está disponível se e somente se o preteridos e desativado por padrão [/Gm (habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) opção não estiver selecionada. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposto na saída do `cl /?`.

Se você não habilitar preteridas **/Gm** opção no ambiente de desenvolvimento **/FD** é usado. **/FD** garante que o arquivo. IDB tem informações suficientes de dependência. **/FD** só é usada pelo ambiente de desenvolvimento, e ele não deve ser usado da linha de comando ou um script de compilação.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
