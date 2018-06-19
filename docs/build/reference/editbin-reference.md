---
title: Referência EDITBIN | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- editbin
dev_langs:
- C++
helpviewer_keywords:
- binary data, editing
- object files, modifying
- EDITBIN program
- COFF files, editing
ms.assetid: efdda03b-3dfc-4d31-90e6-caf5b3977914
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c20191fdb133fe09ed4f6a462cd777098acd5f05
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32372302"
---
# <a name="editbin-reference"></a>Referência de EDITBIN
O Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE) modifica os arquivos binários do formato de arquivo de objeto comum (COFF). Você pode usar EDITBIN para modificar arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLL).  
  
> [!NOTE]
>  Você pode iniciar essa ferramenta apenas o [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] prompt de comando. Você não pode iniciá-lo em um prompt de comando do sistema ou no Explorador de arquivos.  
  
 EDITBIN não está disponível para uso em arquivos produzidos com o [/GL](../../build/reference/gl-whole-program-optimization.md) opção de compilador. Modificações em arquivos binários produzidos com /GL precisará ser obtida recompilar e vinculando.  
  
-   [Linha de comando EDITBIN](../../build/reference/editbin-command-line.md)  
  
-   [Opções EDITBIN](../../build/reference/editbin-options.md)  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)