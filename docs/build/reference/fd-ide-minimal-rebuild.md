---
title: /FD (recompilação mínima de IDE)
ms.date: 11/04/2016
f1_keywords:
- /FD
helpviewer_keywords:
- /FD compiler option [C++]
- -FD compiler option [C++]
- FD compiler option [C++]
ms.assetid: 7ef21b8c-a448-4bb4-9585-a2a870028e17
ms.openlocfilehash: 323a0045ab11f23ab996d5179a135d0eb4184f20
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57817433"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** não é exposto a usuários, exceto em de [linha de comando](command-line-property-pages.md) página de propriedades de um projeto de C++ **páginas de propriedades** caixa de diálogo se e somente se [/Gm (habilitar recompilação mínima)](gm-enable-minimal-rebuild.md) também não está selecionado. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposto na saída do **cl /?**.

Se você não habilitar **/Gm** no ambiente de desenvolvimento **/FD** será usado. **/FD** garante que o arquivo. IDB tem informações suficientes de dependência. **/FD** só é usada pelo ambiente de desenvolvimento, e não deve ser usado da linha de comando ou um script de compilação.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
