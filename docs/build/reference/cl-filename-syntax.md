---
title: Sintaxe de nome de arquivo CL | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: cl
dev_langs: C++
helpviewer_keywords:
- syntax, compiler filename
- paths, CL compiler filename syntax
- cl.exe compiler, filename syntax
- extensions, specifying to compiler
- file names [C++], CL compiler
- file names [C++]
ms.assetid: 3ca72586-75be-4477-b323-a1be232e80d4
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 95cce7367eac5e4637d148b2c54cd5271f4f3026
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cl-filename-syntax"></a>Sintaxe do nome de arquivo CL
CL aceita arquivos com nomes que sigam as convenções de nomenclatura FAT, HPFS ou NTFS. Qualquer nome de arquivo pode incluir um caminho completo ou parcial. Um caminho completo inclui um nome de unidade e um ou mais nomes de diretório. CL aceita nomes de arquivos separados por barras invertidas (\\) ou barras (/). Nomes de arquivos que contêm espaços devem ser colocados entre aspas duplas. Um caminho parcial omite o nome da unidade, o qual é assumido por CL como a unidade atual. Se você não especificar um caminho, o CL pressupõe que o arquivo está no diretório atual.  
  
 A extensão de nome de arquivo determina como os arquivos serão processados. Os arquivos C e C++, que têm a extensão. c, .cxx ou .cpp, são compilados. Outros arquivos, incluindo arquivos .obj, bibliotecas (.lib) e arquivos de definição de módulo (.def) são passados para o vinculador sem terem sido processados.  
  
## <a name="see-also"></a>Consulte também  
 [Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)