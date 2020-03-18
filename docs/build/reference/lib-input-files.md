---
title: Arquivos de entrada LIB
ms.date: 11/04/2016
helpviewer_keywords:
- input files, LIB
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
ms.openlocfilehash: 209ba04ea43116b39f28b0790b7a1e2b3fb5ccd7
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439459"
---
# <a name="lib-input-files"></a>Arquivos de entrada LIB

Os arquivos de entrada esperados por LIB dependem do modo no qual ele está sendo usado, conforme mostrado na tabela a seguir.

|Modo|Entrada|
|----------|-----------|
|Padrão (criando ou modificando uma biblioteca)|Arquivos de objeto COFF (. obj), bibliotecas COFF (. lib), arquivos de OMF (objeto de formato de modelo de objeto) de 32 bits (. obj)|
|Extraindo um membro com/EXTRACT|Biblioteca COFF (. lib)|
|Criando um arquivo de exportação e uma biblioteca de importação com/DEF|Arquivo de definição de módulo (. def), arquivos de objeto COFF (. obj), bibliotecas COFF (. lib), arquivos de objeto OMF (. obj) de 32 bits|

> [!NOTE]
>  Bibliotecas OMF criadas pela versão de 16 bits da LIB não podem ser usadas como entrada para a versão de 32 bits de LIB.

## <a name="see-also"></a>Consulte também

[Visão geral de LIB](overview-of-lib.md)
