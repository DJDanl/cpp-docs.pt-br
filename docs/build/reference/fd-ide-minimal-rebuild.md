---
title: -FD (recompilação mínima de IDE) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /FD
dev_langs:
- C++
helpviewer_keywords:
- /FD compiler option [C++]
- -FD compiler option [C++]
- FD compiler option [C++]
ms.assetid: 7ef21b8c-a448-4bb4-9585-a2a870028e17
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 74fb35ec25bed808e2165498c00b65723aba5bac
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45702436"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** não é exposto a usuários, exceto em de [linha de comando](../../ide/command-line-property-pages.md) página de propriedades de um projeto de C++ **páginas de propriedades** caixa de diálogo se e somente se [/Gm (habilitar recompilação mínima)](../../build/reference/gm-enable-minimal-rebuild.md) também não está selecionado. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposto na saída do **cl /?**.

Se você não habilitar **/Gm** no ambiente de desenvolvimento **/FD** será usado. **/FD** garante que o arquivo. IDB tem informações suficientes de dependência. **/FD** só é usada pelo ambiente de desenvolvimento, e não deve ser usado da linha de comando ou um script de compilação.

## <a name="see-also"></a>Consulte também

[Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)