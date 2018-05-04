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
ms.openlocfilehash: 18e31955b131e4ca22d23013565e53f83493275d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fd-ide-minimal-rebuild"></a>/FD (recompilação mínima de IDE)
**/FD** não é exposto a usuários, exceto de [linha de comando](../../ide/command-line-property-pages.md) página de propriedades de um projeto de C++ **páginas de propriedade** caixa de diálogo se e somente se [/GM (habilitar mínimo recriar)demanual](../../build/reference/gm-enable-minimal-rebuild.md) também não está selecionado. **/FD** não tem nenhum efeito diferente do ambiente de desenvolvimento. **/FD** não é exposta na saída de **cl /?**.  
  
 Se você não habilitar **/GM manual** no ambiente de desenvolvimento, **/FD** será usado. **/FD** garante que o arquivo .idb tem informações suficientes de dependência. **/FD** só é usado pelo ambiente de desenvolvimento, e não deve ser usado da linha de comando ou um script de compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)