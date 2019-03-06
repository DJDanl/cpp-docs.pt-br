---
title: Sintaxe do nome de arquivo CL
ms.date: 11/04/2016
f1_keywords:
- cl
helpviewer_keywords:
- syntax, compiler filename
- paths, CL compiler filename syntax
- cl.exe compiler, filename syntax
- extensions, specifying to compiler
- file names [C++], CL compiler
- file names [C++]
ms.assetid: 3ca72586-75be-4477-b323-a1be232e80d4
ms.openlocfilehash: d2dd51370fd346c4cd7dad7bb97bfa76a9f759d9
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57420720"
---
# <a name="cl-filename-syntax"></a>Sintaxe do nome de arquivo CL

CL aceita arquivos com nomes que sigam as convenções de nomenclatura FAT, HPFS ou NTFS. Qualquer nome de arquivo pode incluir um caminho completo ou parcial. Um caminho completo inclui um nome de unidade e um ou mais nomes de diretório. CL aceita nomes de arquivos separados por barras invertidas (\\) ou barras (/). Nomes de arquivos que contêm espaços devem ser colocados entre aspas duplas. Um caminho parcial omite o nome da unidade, o qual é assumido por CL como a unidade atual. Se você não especificar um caminho, o CL pressupõe que o arquivo está no diretório atual.

A extensão de nome de arquivo determina como os arquivos serão processados. Os arquivos C e C++, que têm a extensão. c, .cxx ou .cpp, são compilados. Outros arquivos, incluindo arquivos .obj, bibliotecas (.lib) e arquivos de definição de módulo (.def) são passados para o vinculador sem terem sido processados.

## <a name="see-also"></a>Consulte também

[Sintaxe de linha de comando do compilador](../../build/reference/compiler-command-line-syntax.md)
