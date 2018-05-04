---
title: Arquivos de saída LIB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- Lib
dev_langs:
- C++
helpviewer_keywords:
- output files, LIB
ms.assetid: e73d2f9b-a42d-402b-b7e3-3a94bebb317e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e8caa26685d6132cbc1ffd8a2467f8615bffd42f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="lib-output-files"></a>Arquivos de saída LIB
Os arquivos de saída produzidos por LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.  
  
|Modo|Saída|  
|----------|------------|  
|Padrão (Criando ou modificando uma biblioteca)|Biblioteca COFF (. lib)|  
|Extraindo um membro com /EXTRACT|Arquivo de objeto (. obj)|  
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Importar biblioteca (. lib) e um arquivo de exportação (. Exp)|  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral de LIB](../../build/reference/overview-of-lib.md)