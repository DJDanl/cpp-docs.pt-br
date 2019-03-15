---
title: Arquivos de entrada LIB
ms.date: 11/04/2016
f1_keywords:
- Lib
helpviewer_keywords:
- input files, LIB
ms.assetid: e1236f0d-cd90-446b-b900-f311f456085c
ms.openlocfilehash: 648871464dbc99972b8ca40579046347727e81cf
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57808125"
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

[Visão geral de LIB](overview-of-lib.md)
