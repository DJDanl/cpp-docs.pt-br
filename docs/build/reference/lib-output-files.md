---
title: Arquivos de saída LIB
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- output files, LIB
ms.assetid: e73d2f9b-a42d-402b-b7e3-3a94bebb317e
ms.openlocfilehash: bc505a9a946f564425513dad8107fd962eb054b9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562877"
---
# <a name="lib-output-files"></a>Arquivos de saída LIB

Os arquivos de saída produzidos pelo LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.

|Modo|Saída|
|----------|------------|
|Padrão (Criando ou modificando uma biblioteca)|Biblioteca COFF (. lib)|
|Extraindo um membro com /EXTRACT|Arquivo de objeto (. obj)|
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Importar biblioteca (. lib) e um arquivo de exportação (. Exp)|

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](../../build/reference/overview-of-lib.md)