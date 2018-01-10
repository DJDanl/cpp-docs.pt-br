---
title: "Referência EDITBIN | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: editbin
dev_langs: C++
helpviewer_keywords:
- binary data, editing
- object files, modifying
- EDITBIN program
- COFF files, editing
ms.assetid: efdda03b-3dfc-4d31-90e6-caf5b3977914
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e0ff9c0c58498361764dcc1b6c454c9b629d9bed
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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