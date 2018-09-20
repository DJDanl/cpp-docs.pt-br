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
ms.openlocfilehash: 474602ce51ff9eb84f54d7580104f641d9b5b2a7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396188"
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)

**/FD** não é exposto a usuários, exceto em de [linha de comando](../../ide/command-line-property-pages.md) página de propriedades de um projeto de C++ **páginas de propriedades** caixa de diálogo se e somente se [/Gm (habilitar recompilação mínima)](../../build/reference/gm-enable-minimal-rebuild.md) também não está selecionado. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposto na saída do **cl /?**.

Se você não habilitar **/Gm** no ambiente de desenvolvimento **/FD** será usado. **/FD** garante que o arquivo. IDB tem informações suficientes de dependência. **/FD** só é usada pelo ambiente de desenvolvimento, e não deve ser usado da linha de comando ou um script de compilação.

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)