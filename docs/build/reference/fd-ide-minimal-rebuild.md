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
ms.openlocfilehash: 0685df0baf14685bd24b8390dd58b382ae5ac506
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422046"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** não é exposto a usuários, exceto em de [linha de comando](../../ide/command-line-property-pages.md) página de propriedades de um projeto de C++ **páginas de propriedades** caixa de diálogo se e somente se [/Gm (habilitar recompilação mínima)](../../build/reference/gm-enable-minimal-rebuild.md) também não está selecionado. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposto na saída do **cl /?**.

Se você não habilitar **/Gm** no ambiente de desenvolvimento **/FD** será usado. **/FD** garante que o arquivo. IDB tem informações suficientes de dependência. **/FD** só é usada pelo ambiente de desenvolvimento, e não deve ser usado da linha de comando ou um script de compilação.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
