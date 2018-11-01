---
title: Arquivos de entrada LIB
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- input files, LIB
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
ms.openlocfilehash: 885d03e74c7acff54e527c2dbad38de055913b5f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50503279"
---
# <a name="lib-input-files"></a>Arquivos de entrada LIB

Os arquivos de entrada esperados pelo LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.

|Modo|Entrada|
|----------|-----------|
|Padrão (Criando ou modificando uma biblioteca)|Arquivos de objeto (. obj) de COFF, bibliotecas COFF (. lib), arquivos de objeto (. obj) de formato de modelo de objeto (OMF) de 32 bits|
|Extraindo um membro com /EXTRACT|Biblioteca COFF (. lib)|
|Criar uma exportação de arquivo e importar biblioteca com /DEF|Arquivo de definição de módulo (. def), arquivos de objeto (. obj) de COFF, bibliotecas COFF (. lib), arquivos de objeto (. obj) de OMF de 32 bits|

> [!NOTE]
>  Bibliotecas OMF criadas pela versão de 16 bits de LIB não podem ser usadas como entrada para a versão de 32 bits do LIB.

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](../../build/reference/overview-of-lib.md)