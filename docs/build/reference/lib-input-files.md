---
title: Arquivos de entrada LIB
ms.date: 11/04/2016
helpviewer_keywords:
- input files, LIB
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
ms.openlocfilehash: de81f79eecf3fc73c02894747f4b97cb107cf892
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328224"
---
# <a name="lib-input-files"></a>Arquivos de entrada LIB

Os arquivos de entrada esperados pela LIB dependem do modo em que ele está sendo usado, como mostrado na tabela a seguir.

|Mode|Entrada|
|----------|-----------|
|Padrão (construir ou modificar uma biblioteca)|Arquivos de objeto COFF (.obj), bibliotecas COFF (.lib), arquivos de objeto de objeto de 32 bits (OMF) (.obj)|
|Extraindo um membro com /EXTRACT|Biblioteca COFF (.lib)|
|Construindo um arquivo de exportação e biblioteca de importação com /DEF|Arquivo de definição de módulo (.def), arquivos de objeto COFF (.obj), bibliotecas COFF (.lib), arquivos de objeto OMF de 32 bits (.obj)|

> [!NOTE]
> Bibliotecas OMF criadas pela versão de 16 bits do LIB não podem ser usadas como entrada para a versão de 32 bits do LIB.

## <a name="see-also"></a>Confira também

[Visão geral de LIB](overview-of-lib.md)
