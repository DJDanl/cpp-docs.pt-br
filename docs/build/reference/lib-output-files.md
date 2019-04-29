---
title: Arquivos de saída LIB
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- output files, LIB
ms.assetid: e73d2f9b-a42d-402b-b7e3-3a94bebb317e
ms.openlocfilehash: d7a6352665f12307bfa54025a32f9f7b84311dac
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62269694"
---
# <a name="lib-output-files"></a>Arquivos de saída LIB

Os arquivos de saída produzidos pelo LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.

|Modo|Saída|
|----------|------------|
|Padrão (Criando ou modificando uma biblioteca)|Biblioteca COFF (. lib)|
|Extraindo um membro com /EXTRACT|Arquivo de objeto (. obj)|
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Importar biblioteca (. lib) e um arquivo de exportação (. Exp)|

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](overview-of-lib.md)
